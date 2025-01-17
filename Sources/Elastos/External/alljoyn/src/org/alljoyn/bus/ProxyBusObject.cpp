//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include "org/alljoyn/bus/CBusAttachment.h"
#include "org/alljoyn/bus/InterfaceDescription.h"
#include "org/alljoyn/bus/MsgArg.h"
#include "org/alljoyn/bus/Globals.h"
#include "org/alljoyn/bus/CVariant.h"
#include "org/alljoyn/bus/NativeBusAttachment.h"
#include "org/alljoyn/bus/NativeProxyBusObject.h"
#include "org/alljoyn/bus/ProxyBusObject.h"
#include <elastos/core/AutoLock.h>
#include <elastos/core/StringBuilder.h>
#include <elastos/core/StringUtils.h>
#include <elastos/utility/logging/Logger.h>

using Elastos::Core::AutoLock;
using Elastos::Core::StringBuilder;
using Elastos::Core::StringUtils;
using Elastos::Core::IClassLoader;
using Elastos::Core::Reflect::CProxyFactory;
using Elastos::Core::Reflect::IProxyFactory;
using Elastos::Core::Reflect::EIID_IInvocationHandler;
using Elastos::Utility::Logging::Logger;

namespace Org {
namespace Alljoyn {
namespace Bus {

static const Boolean DEBUG = FALSE;

//=============================================================
// ProxyBusObject::Handler::Invocation
//=============================================================
ProxyBusObject::Handler::Invocation::Invocation(
    /* [in] */ IMethodInfo* method)
    : mMethod(method)
    , mIsMethod(FALSE)
    , mIsGet(FALSE)
{
    AutoPtr<IAnnotationInfo> ainfo;
    method->GetAnnotation(Globals::Annotation_BusProperty, (IAnnotationInfo**)&ainfo);
    if (ainfo != NULL) {
        String methodName;
        method->GetName(&methodName);
        mIsGet = methodName.StartWith("Get");
        mOutSig = InterfaceDescription::GetPropertySig(method);
    }
    else {
        mIsMethod = TRUE;
        mOutSig = InterfaceDescription::GetOutSig(method);
        mInputSig = InterfaceDescription::GetInputSig(method);
    }
    AutoPtr<IInterfaceInfo> iinfo;
    method->GetDeclaringInterface((IInterfaceInfo**)&iinfo);
    mInterfaceName = InterfaceDescription::GetName(iinfo);
    mMethodName = InterfaceDescription::GetName(method);
    // TODO:
    // this.genericReturnType = method.getGenericReturnType();
    // this.returnType = method.getReturnType();
}

//=============================================================
// ProxyBusObject::Handler
//=============================================================
CAR_INTERFACE_IMPL(ProxyBusObject::Handler, Object, IInvocationHandler)

ProxyBusObject::Handler::Handler(
    /* [in] */ ProxyBusObject* host)
    : mHost(host)
{}

ECode ProxyBusObject::Handler::Invoke(
    /* [in] */ IInterface* proxy,
    /* [in] */ IMethodInfo* method,
    /* [in] */ IArgumentList* args)
{
    AutoPtr<Invocation> invocation;
    String methodName;
    method->GetName(&methodName);
    if (DEBUG) {
        Logger::I(TAG, " >> ProxyBusObject::Handler::Invoke: %s", methodName.string());
    }

    AutoPtr< List< AutoPtr<Invocation> > > invocationList;
    HashMap<String, AutoPtr< List< AutoPtr<Invocation> > > >::Iterator it =
            mInvocationCache.Find(methodName);
    if (it != mInvocationCache.End()) {
        invocationList = it->mSecond;
    }
    if (invocationList != NULL) {
        if (invocationList->GetSize() == 1) {
            invocation = invocationList->GetFront();
        }
        else {
            List< AutoPtr<Invocation> >::Iterator it;
            for (it = invocationList->Begin(); it != invocationList->End(); ++it) {
                if (method == (*it)->mMethod) {
                    invocation = (*it);
                    break;
                }
            }
            if (invocation == NULL) {
                invocation = new Invocation(method);
                invocationList->PushBack(invocation);
            }
        }
    }
    else {
        invocationList = new List< AutoPtr<Invocation> >();
        IProxy* prx = IProxy::Probe(proxy);
        Int32 N;
        prx->GetInterfaceCount(&N);
        AutoPtr< ArrayOf<IInterfaceInfo*> > infos = ArrayOf<IInterfaceInfo*>::Alloc(N);
        prx->GetAllInterfaceInfos(infos);
        for (Int32 i = 0; i < N; i++) {
            Int32 count;
            (*infos)[i]->GetMethodCount(&count);
            AutoPtr< ArrayOf<IMethodInfo*> > mInfos = ArrayOf<IMethodInfo*>::Alloc(count);
            (*infos)[i]->GetAllMethodInfos(mInfos);
            for (Int32 j = 0; j < count; j++) {
                IMethodInfo* m = (*mInfos)[j];
                String name;
                m->GetName(&name);
                if (methodName.Equals(name)) {
                    AutoPtr<Invocation> in = new Invocation(m);
                    invocationList->PushBack(in);
                    if (method == in->mMethod) {
                        invocation = in;
                    }
                }
            }
        }
        if (invocation == NULL) {
            // String signature;
            // method->GetSignature(&signature);
            // if (methodName.Equals("ToString") && signature.Equals("(LElastos/String;*)E")) {
            //     return ProxyToString(proxy);
            // }
            // else if (methodName.Equals("Equals") && signature.Equals("(LIInterface;*Elastos/String;*Z)E")) {
            //     return proxy == args[0];
            // }
            // else if (methodName.Equals("GetHashCode") && signature.Equals("(I32*)E")) {
            //     return System.identityHashCode(proxy);
            // }
            // else {
            //     throw new BusException("No such method: " + method);
            // }
            assert(0 && "TODO");
        }
        mInvocationCache[methodName] = invocationList;
    }

    ECode ec = NOERROR;
    if (invocation->mIsMethod) {
        ec = mHost->MethodCall(
            mHost->mBus,
            invocation->mInterfaceName,
            invocation->mMethodName,
            invocation->mInputSig,
            // invocation->mGenericReturnType,
            method,
            args,
            mHost->mReplyTimeoutMsecs,
            mHost->mFlags);
    }
    else {
        if (invocation->mIsGet) {
            ec = mHost->GetProperty(
                mHost->mBus,
                invocation->mInterfaceName,
                invocation->mMethodName,
                invocation->mOutSig,
                method,
                args);
        }
        else {
            ec = mHost->SetProperty(
                mHost->mBus,
                invocation->mInterfaceName,
                invocation->mMethodName,
                invocation->mOutSig,
                method,
                args);
        }
    }

    return ec;
}


//=============================================================
// ProxyBusObject
//=============================================================
const String ProxyBusObject::TAG("ProxyBusObject");

const Int32 ProxyBusObject::AUTO_START;
const Int32 ProxyBusObject::ENCRYPTED;

CAR_INTERFACE_IMPL(ProxyBusObject, Object, IProxyBusObject)

ECode ProxyBusObject::constructor(
    /* [in] */ CBusAttachment* busAttachment,
    /* [in] */ const String& busName,
    /* [in] */ const String& objPath,
    /* [in] */ Int32 sessionId,
    /* [in] */ ArrayOf<IInterfaceInfo*>* busInterfaces)
{
    return constructor(busAttachment, busName, objPath, sessionId, busInterfaces, FALSE);
}

ECode ProxyBusObject::constructor(
    /* [in] */ CBusAttachment* busAttachment,
    /* [in] */ const String& busName,
    /* [in] */ const String& objPath,
    /* [in] */ Int32 sessionId,
    /* [in] */ ArrayOf<IInterfaceInfo*>* busInterfaces,
    /* [in] */ Boolean secure)
{
    mBus = busAttachment;
    mBusName = busName;
    mObjPath = objPath;
    mFlags = 0;
    Create(busAttachment, busName, objPath, sessionId, secure);
    mReplyTimeoutMsecs = 25000;
    AutoPtr<IInterface> loader;
    (*busInterfaces)[0]->GetClassLoader((IInterface**)&loader);
    AutoPtr<IInvocationHandler> handler = new Handler(this);
    AutoPtr<IProxyFactory> pf;
    CProxyFactory::AcquireSingleton((IProxyFactory**)&pf);
    pf->NewProxyInstance(IClassLoader::Probe(loader), busInterfaces, handler, (IInterface**)&mProxy);
    // try {
    //     busConnectionLost =
    //         getClass().getDeclaredMethod("busConnectionLost", String.class);
    //     busConnectionLost.setAccessible(true);
    // } catch (NoSuchMethodException ex) {
    //     /* This will not happen */
    // }
    return NOERROR;
}

void ProxyBusObject::Create(
    /* [in] */ CBusAttachment* busAttachment,
    /* [in] */ const String& busName,
    /* [in] */ const String& objPath,
    /* [in] */ Int32 sessionId,
    /* [in] */ Boolean secure)
{
    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(busAttachment->mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "Create(): NULL bus pointer");
        return;
    }

    NativeProxyBusObject* npbo = new NativeProxyBusObject(this, busPtr,
            busName.string(), objPath.string(), sessionId, secure);
    assert(npbo != NULL);

    mHandle = reinterpret_cast<Int64>(npbo);
}

void ProxyBusObject::Destroy()
{
    NativeProxyBusObject* proxyBusObject =  reinterpret_cast<NativeProxyBusObject*>(mHandle);
    if (proxyBusObject == NULL) {
        Logger::D(TAG, "Destroy(): Already destroyed. Returning.");
        return;
    }

    NativeBusAttachment* busPtr = proxyBusObject->mBusPtr;
    delete proxyBusObject;
    busPtr->DecRef();
    mHandle = 0;
}

ECode ProxyBusObject::AddInterface(
    /* [in] */ const String& name)
{
    if (!name.IsNull()) {
        IProxy* prx = IProxy::Probe(mProxy);
        Int32 N;
        prx->GetInterfaceCount(&N);
        AutoPtr< ArrayOf<IInterfaceInfo*> > infos = ArrayOf<IInterfaceInfo*>::Alloc(N);
        prx->GetAllInterfaceInfos(infos);
        for (Int32 i = 0; i < N; i++) {
            IInterfaceInfo* intf = (*infos)[i];
            if (name.Equals(InterfaceDescription::GetName(intf))) {
                AutoPtr<InterfaceDescription> desc = new InterfaceDescription();
                return desc->Create(mBus, intf);
            }
        }
    }
    return E_STATUS_BUS_NO_SUCH_INTERFACE;
}

/*
 * if the interface security policy is Required return true,
 * if the interface security policy is off return false
 * otherwise return the object security.
 */
static inline Boolean SecurityApplies(
    /* [in] */ const NativeProxyBusObject* obj,
    /* [in] */ const ajn::InterfaceDescription* ifc)
{
    ajn::InterfaceSecurityPolicy ifcSec = ifc->GetSecurityPolicy();
    if (ifcSec == ajn::AJ_IFC_SECURITY_REQUIRED) {
        return TRUE;
    }
    else if (ifcSec == ajn::AJ_IFC_SECURITY_OFF) {
        return FALSE;
    }
    else {
        return obj->IsSecure();
    }
}

ECode ProxyBusObject::MethodCall(
    /* [in] */ CBusAttachment* busAttachment,
    /* [in] */ const String& interfaceName,
    /* [in] */ const String& methodName,
    /* [in] */ const String& inputSig,
    // Type outType,
    /* [in] */ IMethodInfo* method,
    /* [in] */ IArgumentList* carArgs,
    /* [in] */ Int32 replyTimeoutMsecs,
    /* [in] */ Int32 flags)
{
    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(busAttachment->mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "MethodCall(): NULL bus pointer");
        return E_STATUS_FAIL;
    }

    ECode ec = NOERROR;

    busPtr->mBaProxyLock.Lock();

    ajn::Message replyMsg(*busPtr);

    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);
    assert(proxyBusObj != NULL);

    const ajn::InterfaceDescription::Member* member = NULL;

    const ajn::InterfaceDescription* intf = proxyBusObj->GetInterface(interfaceName.string());
    if (!intf) {
        ec = AddInterface(busPtr, interfaceName);
        if (FAILED(ec)) {
            Logger::E(TAG, "MethodCall(): Exception, failed to GetInterface %s", interfaceName.string());
            busPtr->mBaProxyLock.Unlock();
            return ec;
        }
        intf = proxyBusObj->GetInterface(interfaceName.string());
        assert(intf);
    }

    member = intf->GetMember(methodName.string());
    if (!member) {
        Logger::E(TAG, "MethodCall(): Exception");
        busPtr->mBaProxyLock.Unlock();
        return E_STATUS_BUS_INTERFACE_NO_SUCH_MEMBER;
    }

    busPtr->mBaProxyLock.Unlock();

    ajn::MsgArg args;
    QStatus status;
    const ajn::MsgArg* replyArgs;
    size_t numReplyArgs;

    if (DEBUG) {
        Logger::I(TAG, " >> MarshalIn: inputSig: '%s'", inputSig.string());
    }

    ec = MsgArg::MarshalIn((Int64)&args, inputSig, method, carArgs);
    if (FAILED(ec)) {
        Logger::E(TAG, "MethodCall(): Marshal failure");
        return E_STATUS_FAIL;
    }
    if (DEBUG) {
        Logger::I(TAG, " >> MethodCall() with MsgArg: '%s'", args.ToString().c_str());
    }

    /*
     * If we call any method on the org.freedesktop.DBus.Properties interface
     *    - org.freedesktop.DBus.Properties.Get(ssv)
     *    - org.freedesktop.DBus.Properties.Set(ssv)
     *    - org.freedesktop.DBus.Properties.GetAll(sa{sv})
     * If the properties are part of an encrypted interface then the they must
     * also be encrypted.  The first parameter of Get, Set, and GetAll is the
     * interface name that the property belongs to.
     *    - this code reads the interface name from the Properties method call
     *    - tries to Get the InterfaceDescription from the proxyBusObj based on
     *      the interface name
     *    - Checks the InterfaceDescription to see if it has Security Annotation
     *      or object security
     *    - if security is set change the security flag to for the property
     *      method so the properties are encrypted.
     *    - if it is unable to get the InterfaceDescription it will check the
     *      security of the ProxyObject.
     *    - Failure to find a security indication will result the properties
     *      methods being used without encryption.
     */
    if (!interfaceName.IsNull()) {     //if interfaceName.c_str() is null strcmp is undefined behavior
        if (strcmp(interfaceName.string(), ajn::org::freedesktop::DBus::Properties::InterfaceName) == 0) {
            char* interface_name;
            /* the fist member of the struct is the interface name*/
            args.v_struct.members[0].Get("s", &interface_name);
            const ajn::InterfaceDescription* ifac_with_property = proxyBusObj->GetInterface(interface_name);
            /*
             * If the object or the property interface is secure method call
             * must be encrypted.
             */
            if (ifac_with_property == NULL) {
                if (proxyBusObj->IsSecure()) {
                    flags |= ajn::ALLJOYN_FLAG_ENCRYPTED;
                }
            }
            else if (SecurityApplies(proxyBusObj, ifac_with_property)) {
                flags |= ajn::ALLJOYN_FLAG_ENCRYPTED;
            }
        }
    }
    qcc::String val;
    if (member->GetAnnotation(ajn::org::freedesktop::DBus::AnnotateNoReply, val) && val == "true") {
        status = proxyBusObj->MethodCallAsync(*member, NULL, NULL, args.v_struct.members,
                                              args.v_struct.numMembers, NULL, replyTimeoutMsecs, flags);
        if (ER_OK != status) {
            Logger::E(TAG, "MethodCall(): Exception");
            ec = status;
        }
    }
    else {
        status = proxyBusObj->MethodCall(*member, args.v_struct.members, args.v_struct.numMembers,
                                         replyMsg, replyTimeoutMsecs, flags);
        if (ER_OK == status) {
            replyMsg->GetArgs(numReplyArgs, replyArgs);
            if (numReplyArgs > 1) {
                ajn::MsgArg structArg(ajn::ALLJOYN_STRUCT);
                structArg.v_struct.numMembers = numReplyArgs;
                structArg.v_struct.members = new ajn::MsgArg[numReplyArgs];
                for (size_t i = 0; i < numReplyArgs; ++i) {
                    structArg.v_struct.members[i] = replyArgs[i];
                }
                structArg.SetOwnershipFlags(ajn::MsgArg::OwnsArgs);
                MsgArg::UnmarshalOut((Int64)&structArg, method, carArgs);
            }
            else if (numReplyArgs > 0) {
                MsgArg::UnmarshalOut((Int64)&replyArgs[0], method, carArgs);
            }
        }
        else if (ER_BUS_REPLY_IS_ERROR_MESSAGE == status) {
            qcc::String errorMessage;
            const char* errorName = replyMsg->GetErrorName(&errorMessage);
            if (errorName) {
                if (!strcmp("org.alljoyn.bus.BusException", errorName)) {
                    Logger::E(TAG, "MethodCall(): %s", errorMessage.c_str());
                }
                else {
                    Logger::E(TAG, "MethodCall(): %s", errorMessage.c_str());
                }
            }
            else {
                Logger::E(TAG, "MethodCall(): Exception");
            }
            ec = E_STATUS_FAIL;
        }
        else {
            Logger::E(TAG, "MethodCall(): Exception");
            ec = E_STATUS_FAIL;
        }
    }

    return ec;
}

ECode ProxyBusObject::SetProperty(
    /* [in] */ IInterfaceInfo* iface,
    /* [in] */ const String& propertyName,
    /* [in] */ IVariant* value)
{
    String signature;
    value->GetSignature(&signature);
    AutoPtr<IInterface> v;
    value->GetObject((IInterface**)&v);

    assert(0 && "TODO");
    // return SetProperty(mBus,
    //     InterfaceDescription::GetName(iface),
    //     propertyName,
    //     signature, value.GetValue());
    return NOERROR;
}

ECode ProxyBusObject::SetProperty(
    /* [in] */ CBusAttachment* busAttachment,
    /* [in] */ const String& interfaceName,
    /* [in] */ const String& propertyName,
    /* [in] */ const String& signature,
    /* [in] */ IMethodInfo* method,
    /* [in] */ IArgumentList* args)
{
    if (DEBUG) {
        Logger::I(TAG, " >> SetProperty: interface: %s, property: %s, signature: %s",
            interfaceName.string(), propertyName.string(), signature.string());
    }

    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(mBus->mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "MethodCall(): NULL bus pointer");
        return E_STATUS_FAIL;
    }

    ECode ec = NOERROR;

    /*
     * This part of the binding and on down lower is fundamentally single
     * threaded.  We want to eventually support multiple overlapping synchronous
     * calls, but we do not support this now.
     *
     * It might sound reasonable for a user of the bindings to get around this
     * limitation by spinning up a bunch of threads to make overlapping set
     * property calls.  Since these calls will be coming in here to be
     * dispatched, We have to actively prevent this from happening for now.
     *
     * It's a bit of a blunt instrument, but we acquire a common method call lock
     * in the underlying bus attachment before allowing any method call on a
     * proxy bus object to proceed.
     */
    AutoLock lock(busPtr->mBaProxyLock);

    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);

    const ajn::InterfaceDescription* intf = proxyBusObj->GetInterface(interfaceName.string());
    if (!intf) {
        ec = AddInterface(busPtr, interfaceName);
        if (FAILED(ec)) {
            Logger::E(TAG, "GetProperty(): Exception, failed to GetInterface %s", interfaceName.string());
            busPtr->mBaProxyLock.Unlock();
            return ec;
        }
        intf = proxyBusObj->GetInterface(interfaceName.string());
        assert(intf);
    }

    ajn::MsgArg arg;
    ec = MsgArg::GetInputPropery((Int64)&arg, signature, method, args);
    if (FAILED(ec)) {
        Logger::E(TAG, "SetProperty(): GetInputPropery Exception, ec= %08x", ec);
        return ec;
    }

    if (DEBUG) {
        Logger::I(TAG, " >> SetProperty with MsgArg: %s, signature: %s",
            arg.ToString().c_str(), arg.Signature().c_str());
    }

    ec = proxyBusObj->SetProperty(interfaceName.string(), propertyName.string(), arg);
    if (FAILED(ec)) {
        Logger::E(TAG, "SetProperty(): SetProperty Exception, ec= %08x", ec);
    }

    return ec;
}

ECode ProxyBusObject::GetProperty(
    /* [in] */ IInterfaceInfo* iface,
    /* [in] */ const String& propertyName,
    /* [out] */ IVariant** value)
{
    return GetProperty(InterfaceDescription::GetName(iface), propertyName, value);
}

ECode ProxyBusObject::GetProperty(
    /* [in] */ const String& interfaceName,
    /* [in] */ const String& propertyName,
    /* [out] */ IVariant** result)
{
    VALIDATE_NOT_NULL(result)
    *result = NULL;

    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(mBus->mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "MethodCall(): NULL bus pointer");
        return E_STATUS_FAIL;
    }

    ECode ec = NOERROR;

    /*
     * This part of the binding and on down lower is fundamentally single
     * threaded.  We want to eventually support multiple overlapping synchronous
     * calls, but we do not support this now.
     *
     * It might sound reasonable for a user of the bindings to get around this
     * limitation by spinning up a bunch of threads to make overlapping get
     * property calls.  Since these calls will be coming in here to be
     * dispatched, We have to actively prevent this from happening for now.
     *
     * It's a bit of a blunt instrument, but we acquire a common method call lock
     * in the underlying bus attachment before allowing any method call on a
     * proxy bus object to proceed.
    */
    AutoLock lock(busPtr->mBaProxyLock);

    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);

    const ajn::InterfaceDescription* intf = proxyBusObj->GetInterface(interfaceName.string());
    if (!intf) {
        ec = AddInterface(busPtr, interfaceName);
        if (FAILED(ec)) {
            Logger::E(TAG, "GetProperty(): Exception, failed to GetInterface %s", interfaceName.string());
            busPtr->mBaProxyLock.Unlock();
            return ec;
        }
        intf = proxyBusObj->GetInterface(interfaceName.string());
        assert(intf);
    }

    ajn::MsgArg value;
    ec = proxyBusObj->GetProperty(interfaceName.string(), propertyName.string(), value);
    if (FAILED(ec)) {
        Logger::E(TAG, "GetProperty() Exception, interface: %s, property: %s", interfaceName.string(), propertyName.string());
        return ec;
    }

    AutoPtr<IVariant> v;
    ec = MsgArg::Unmarshal((Int64)&value, (IVariant**)&v);
    if (FAILED(ec)) {
        Logger::E(TAG, "GetProperty(): Unmarshal Exception");
        return ec;
    }

    *result = v;
    REFCOUNT_ADD(*result)
    return NOERROR;
}

ECode ProxyBusObject::GetProperty(
    /* [in] */ CBusAttachment* busAttachment,
    /* [in] */ const String& interfaceName,
    /* [in] */ const String& propertyName,
    /* [in] */ const String& signature,
    /* [in] */ IMethodInfo* method,
    /* [in] */ IArgumentList* args)
{
    if (DEBUG) {
        Logger::I(TAG, " >> GetProperty: interface: %s, property: %s", interfaceName.string(), propertyName.string());
    }

    ECode ec = NOERROR;

    AutoPtr<IVariant> variant;
    FAIL_RETURN(GetProperty(interfaceName, propertyName, (IVariant**)&variant))
    if (DEBUG) {
        Logger::I(TAG, " >> GetProperty: variant: %s", TO_CSTR(variant));
    }

    Boolean isNull = FALSE;
    args->IsOutputArgumentNullPtr(0, &isNull);
    if (!isNull) {
        ec = MsgArg::AssignOutputPropery(signature, method, args, variant);
        if (FAILED(ec)) {
            Logger::E(TAG, "AssignOutputPropery: Exception! ec=%08x", ec);
        }
    }

    return ec;
}

ECode ProxyBusObject::GetAllProperties(
    /* [in] */ IInterfaceInfo* iface,
    /* [out] */ IMap** map)  //Map<String, Variant>
{
    VALIDATE_NOT_NULL(map)
    *map = NULL;

    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);
    assert(proxyBusObj != NULL);

    assert(0 && "TODO");
    //returnType = org.alljoyn.bus.ifaces.Properties.class.getMethod("GetAll", String.class).getGenericReturnType();
    // return proxyBusObj->GetAllProperties(InterfaceDescription::GetName(iface), returnType, map);

    // String interfaceName(InterfaceDescription::GetName(iface));
    // Logger::I(TAG, " >> GetAllProperties: interface: %s", interfaceName.string());

    // /*
    //  * This part of the binding and on down lower is fundamentally single
    //  * threaded.  We want to eventually support multiple overlapping synchronous
    //  * calls, but we do not support this now.
    //  *
    //  * It might sound reasonable for a user of the bindings to get around this
    //  * limitation by spinning up a bunch of threads to make overlapping get
    //  * property calls.  Since these calls will be coming in here to be
    //  * dispatched, We have to actively prevent this from happening for now.
    //  *
    //  * It's a bit of a blunt instrument, but we acquire a common method call lock
    //  * in the underlying bus attachment before allowing any method call on a
    //  * proxy bus object to proceed.
    //  */
    // AutoLock lock(mBusPtr->mBaProxyLock);

    // AutoPtr<IProxyBusObject> pbo;
    // mPbo->Resolve(EIID_IProxyBusObject, (IInterface**)&pbo);
    // if (!pbo) {
    //     Logger::E(TAG, "RegisterPropertiesChangedListener(): Can't get new local reference to ProxyBusObject");
    //     return E_STATUS_FAIL;
    // }

    ECode status = NOERROR;
    // if (!ImplementsInterface(interfaceName.string())) {
    //     status = AddInterface(pbo, mBusPtr, interfaceName);
    //     if (status != E_STATUS_OK) {
    //         Logger::E(TAG, "GetAllProperties(): AddInterfaceStatus Exception");
    //         return status;
    //     }
    // }

    // ajn::MsgArg value;
    // status = GetAllProperties(interfaceName.string(), value);
    // if (status == E_STATUS_OK) {
    //     assert(0 && "TODO");
    //     // status = Org::Alljoyn::Bus::MsgArg::Unmarshal((Int64)&value, outtype, (PVoid)map);
    //     if (FAILED(status)) {
    //         Logger::E(TAG, "GetAllProperties(): Unmarshal Exception");
    //     }
    // }
    // else {
    //     Logger::E(TAG, "GetAllProperties(): ajn::GetAllProperties Exception");
    // }
    return status;
}

ECode ProxyBusObject::EnablePropertyCaching()
{
    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);
    if (proxyBusObj == NULL) {
        Logger::E(TAG, "EnablePropertyCaching(): NULL ProxyBusObject pointer");
        return FALSE;
    }

    proxyBusObj->EnablePropertyCaching();
    return NOERROR;
}

ECode ProxyBusObject::ReleaseResources()
{
    Destroy();
    return NOERROR;
}

ECode ProxyBusObject::GetBusName(
    /* [out] */ String* busName)
{
    VALIDATE_NOT_NULL(busName)
    *busName = mBusName;
    return NOERROR;
}

ECode ProxyBusObject::GetObjPath(
    /* [out] */ String* objPath)
{
    VALIDATE_NOT_NULL(objPath)
    *objPath = mObjPath;
    return NOERROR;
}

ECode ProxyBusObject::GetInterface(
    /* [in] */ const InterfaceID& iid,
    /* [out] */ IInterface** intf)
{
    VALIDATE_NOT_NULL(intf);
    *intf = mProxy->Probe(iid);
    REFCOUNT_ADD(*intf);
    return NOERROR;
}

ECode ProxyBusObject::SetReplyTimeout(
    /* [in] */ Int32 timeoutMsecs)
{
    mReplyTimeoutMsecs = timeoutMsecs;
    return NOERROR;
}

ECode ProxyBusObject::SetAutoStart(
    /* [in] */ Boolean autoStart)
{
    mFlags = autoStart ? mFlags | AUTO_START : mFlags & ~AUTO_START;
    return NOERROR;
}

ECode ProxyBusObject::IsSecure(
    /* [out] */ Boolean* isSecure)
{
    VALIDATE_NOT_NULL(isSecure)
    *isSecure = IsProxyBusObjectSecure();;
    return NOERROR;
}

Boolean ProxyBusObject::IsProxyBusObjectSecure()
{
    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);
    if (proxyBusObj == NULL) {
        Logger::E(TAG, "IsProxyBusObjectSecure(): NULL ProxyBusObject pointer");
        return FALSE;
    }
    return proxyBusObj->IsSecure();
}

ECode ProxyBusObject::RegisterPropertiesChangedListener(
    /* [in] */ const String& iface,
    /* [in] */ ArrayOf<String>* properties,
    /* [in] */ IPropertiesChangedListener* listener)
{
    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);
    if (proxyBusObj == NULL) {
        Logger::E(TAG, "RegisterPropertiesChangedListener(): NULL ProxyBusObject pointer");
        return FALSE;
    }
    return proxyBusObj->RegisterPropertiesChangedListener(iface, properties, listener);
}

ECode ProxyBusObject::UnregisterPropertiesChangedListener(
    /* [in] */ const String& iface,
    /* [in] */ IPropertiesChangedListener* listener)
{
    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);
    if (proxyBusObj == NULL) {
        Logger::E(TAG, "UnregisterPropertiesChangedListener(): NULL ProxyBusObject pointer");
        return FALSE;
    }
    return proxyBusObj->UnregisterPropertiesChangedListener(iface, listener);
}

ECode ProxyBusObject::AddInterface(
    /* [in] */ NativeBusAttachment* busPtr,
    /* [in] */ const String& name)
{
    NativeProxyBusObject* proxyBusObj = reinterpret_cast<NativeProxyBusObject*>(mHandle);
    assert(proxyBusObj != NULL);

    ECode ec = AddInterface(name);
    if (ec != (ECode)E_STATUS_OK) {
        Logger::E(TAG, "AddInterface(): Exception");
        return ec;
    }

    if (busPtr == NULL) {
        Logger::E(TAG, "AddInterface(): NULL bus pointer");
        return E_STATUS_FAIL;
    }

    const ajn::InterfaceDescription* intf = busPtr->GetInterface(name.string());
    assert(intf);

    ec = proxyBusObj->AddInterface(*intf);
    return ec;
}

ECode ProxyBusObject::ToString(
    /* [out] */ String* str)
{
    VALIDATE_NOT_NULL(str)
    StringBuilder sb("ProxyBusObject{");
    sb += StringUtils::ToHexString((Int32)this);
    sb += ", busname:";
    sb += mBusName;
    sb += ", objPath:";
    sb += mObjPath;
    sb += "}";
    *str = sb.ToString();
    return NOERROR;

}

} // namespace Bus
} // namespace Alljoyn
} // namespace Org


#include "org/alljoyn/bus/BusListener.h"
#include "org/alljoyn/bus/CBusAttachment.h"
#include "org/alljoyn/bus/InterfaceDescription.h"
#include "org/alljoyn/bus/NativeBusAttachment.h"
#include "org/alljoyn/bus/NativeBusListener.h"
#include "org/alljoyn/bus/NativeSessionPortListener.h"
#include "org/alljoyn/bus/SessionPortListener.h"
#include <elastos/core/AutoLock.h>
#include <elastos/utility/logging/Logger.h>

using Org::Alljoyn::Bus::Ifaces::EIID_IDBusProxyObj;
using Elastos::Core::AutoLock;
using Elastos::Utility::CArrayList;
using Elastos::Utility::CHashSet;
using Elastos::Utility::IList;
using Elastos::Utility::Concurrent::CExecutors;
using Elastos::Utility::Concurrent::IExecutors;
using Elastos::Utility::Logging::Logger;

namespace Org {
namespace Alljoyn {
namespace Bus {

extern void GlobalInitialize();

//============================================================================
// CBusAttachment::AuthListenerInternal
//============================================================================
const Int32 CBusAttachment::AuthListenerInternal::PASSWORD;
const Int32 CBusAttachment::AuthListenerInternal::USER_NAME;
const Int32 CBusAttachment::AuthListenerInternal::CERT_CHAIN;
const Int32 CBusAttachment::AuthListenerInternal::PRIVATE_KEY;
const Int32 CBusAttachment::AuthListenerInternal::LOGON_ENTRY;
const Int32 CBusAttachment::AuthListenerInternal::EXPIRATION;
const Int32 CBusAttachment::AuthListenerInternal::NEW_PASSWORD;
const Int32 CBusAttachment::AuthListenerInternal::ONE_TIME_PWD;


//============================================================================
// CBusAttachment
//============================================================================
const Int32 CBusAttachment::DEFAULT_CONCURRENCY = 4;
const String CBusAttachment::TAG("CBusAttachment");

CAR_INTERFACE_IMPL(CBusAttachment, Object, IBusAttachment);

CAR_OBJECT_IMPL(CBusAttachment);

CBusAttachment::CBusAttachment()
    : mIsShared(FALSE)
    , mIsConnected(FALSE)
{
    GlobalInitialize();
}

/**
 * Constructs a BusAttachment.
 *
 * @param applicationName the name of the application
 * @param policy if this attachment is allowed to receive messages from
 *               remote devices
 * @param concurrency The maximum number of concurrent method and signal
 *                    handlers locally executing.
 */
ECode CBusAttachment::constructor(
    /* [in] */ const String& applicationName,
    /* [in] */ RemoteMessage policy,
    /* [in] */ Int32 concurrency)
{
    mAllowRemoteMessages = (policy == RemoteMessage_Receive);
    mBusAuthListener = new AuthListenerInternal();
    Create(applicationName, mAllowRemoteMessages, concurrency);

    /*
     * Create a separate dbus bus object (dbusbo) and interface so we get at
     * it and can quickly release its resources when we're done with it.
     * The corresponding interface (dbus) is what we give the clients.
     */
    AutoPtr< ArrayOf<InterfaceID> > busInterfaces = ArrayOf<InterfaceID>::Alloc(1);
    (*busInterfaces)[0] = EIID_IDBusProxyObj;
    mDbusbo = new ProxyBusObject();
    mDbusbo->constructor(this, String("org.freedesktop.DBus"), String("/org/freedesktop/DBus"), SESSION_ID_ANY,
            busInterfaces);
    mDbusbo->GetInterface(EIID_IDBusProxyObj, (IInterface**)&mDbus);
    AutoPtr<IExecutors> executors;
    CExecutors::AcquireSingleton((IExecutors**)&executors);
    executors->NewSingleThreadExecutor((IExecutorService**)&mExecutor);
    CHashSet::New((ISet**)&mRegisteredAboutListeners);
    return NOERROR;
}

/**
 * Constructs a BusAttachment.
 *
 * @param applicationName the name of the application
 * @param policy if this attachment is allowed to receive messages
 *               from remote devices
 */
ECode CBusAttachment::constructor(
    /* [in] */ const String& applicationName,
    /* [in] */ RemoteMessage policy)
{
    return constructor(applicationName, policy, DEFAULT_CONCURRENCY);
}

/**
 * Construct a BusAttachment that will only communicate on the local device.
 *
 * @param applicationName the name of the application
 */
ECode CBusAttachment::constructor(
    /* [in] */ const String& applicationName)
{
    return constructor(applicationName, RemoteMessage_Ignore, DEFAULT_CONCURRENCY);
}

void CBusAttachment::Create(
    /* [in] */ const String& applicationName,
    /* [in] */ Boolean allowRemoteMessages,
    /* [in] */ Int32 concurrency)
{
    NativeBusAttachment* busPtr = new NativeBusAttachment(applicationName.string(), allowRemoteMessages, concurrency);
    assert(busPtr != NULL);

    mHandle = reinterpret_cast<Int64>(busPtr);
}

ECode CBusAttachment::RegisterBusObject(
    /* [in] */ const String& objPath,
    /* [in] */ IBusObject* busObj,
    /* [in] */ ArrayOf<IInterfaceDescription*>* busInterfaces,
    /* [in] */ Boolean secure,
    /* [in] */ const String& languageTag,
    /* [in] */ const String& description,
    /* [in] */ ITranslator* dt)
{
    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "RegisterBusObject(): NULL bus pointer");
        return ER_FAIL;
    }

    QStatus status = busPtr->RegisterBusObject(objPath.string(), busObj,
            busInterfaces, secure, languageTag, description, dt);
    if (status != ER_OK) {
        Logger::E(TAG, "RegisterBusObject(): Exception");
    }
    return status;
}


ECode CBusAttachment::EmitChangedSignal(
    /* [in] */ IBusObject* busObject,
    /* [in] */ const String& ifcName,
    /* [in] */ const String& propName,
    /* [in] */ IInterface* val,
    /* [in] */ Int32 sessionId)
{
    return NOERROR;
}

ECode CBusAttachment::RequestName(
    /* [in] */ const String& name,
    /* [in] */ Int32 flags)
{
    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "RequestName(): NULL bus pointer");
        return ER_FAIL;
    }

    QStatus status = busPtr->RequestName(name.string(), flags);
    if (status != ER_OK) {
        Logger::E(TAG, "RequestName(): Exception(0x%08x)", status);
    }

    return status;
}

ECode CBusAttachment::ReleaseName(
    /* [in] */ const String& name)
{
    return NOERROR;
}

ECode CBusAttachment::AddMatch(
    /* [in] */ const String& rule)
{
    return NOERROR;
}

ECode CBusAttachment::RemoveMatch(
    /* [in] */ const String& rule)
{
    return NOERROR;
}

ECode CBusAttachment::AdvertiseName(
    /* [in] */ const String& name,
    /* [in] */ Int16 transports)
{
    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "AdvertiseName(): NULL bus pointer");
        return ER_FAIL;
    }

    QStatus status = busPtr->AdvertiseName(name.string(), transports);
    if (status != ER_OK) {
        Logger::E(TAG, "AdvertiseName(): Exception(0x%08x)", status);
    }

    return status;
}

ECode CBusAttachment::CancelAdvertiseName(
    /* [in] */ const String& name,
    /* [in] */ Int16 transports)
{
    return NOERROR;
}

ECode CBusAttachment::FindAdvertisedName(
    /* [in] */ const String& namePrefix)
{
    return NOERROR;
}

ECode CBusAttachment::FindAdvertisedNameByTransport(
    /* [in] */ const String& namePrefix,
    /* [in] */ Int16 transports)
{
    return NOERROR;
}

ECode CBusAttachment::CancelFindAdvertisedName(
    /* [in] */ const String& namePrefix)
{
    return NOERROR;
}

ECode CBusAttachment::CancelFindAdvertisedNameByTransport(
    /* [in] */ const String& namePrefix,
    /* [in] */ Int16 transports)
{
    return NOERROR;
}

ECode CBusAttachment::BindSessionPort(
    /* [in] */ IMutableInteger16Value* _sessionPort,
    /* [in] */ ISessionOpts* opts,
    /* [in] */ ISessionPortListener* _listener)
{
    ajn::SessionPort sessionPort;
    Int16 value;
    _sessionPort->GetValue(&value);
    sessionPort = value;

    ajn::SessionOpts sessionOpts;
    Byte traffic;
    opts->GetTraffic(&traffic);
    sessionOpts.traffic = static_cast<ajn::SessionOpts::TrafficType>(traffic);

    Boolean isMultipoint;
    opts->IsMultipoint(&isMultipoint);
    sessionOpts.isMultipoint = isMultipoint;

    Byte proximity;
    opts->GetProximity(&proximity);
    sessionOpts.proximity = proximity;

    Int16 transports;
    opts->GetTransports(&transports);
    sessionOpts.transports = transports;

    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "BindSessionPort(): Exception or NULL bus pointer");
        return NOERROR;
    }

    NativeSessionPortListener* listener = reinterpret_cast<NativeSessionPortListener*>(((SessionPortListener*)_listener)->mHandle);
    assert(listener);

    QStatus status = busPtr->BindSessionPort(sessionPort, sessionOpts, *listener);

    if (status == ER_OK) {
        AutoLock lock(busPtr->mBaCommonLock);

        busPtr->mSessionPortListenerMap[sessionPort] = _listener;
    }
    else {
        Logger::E(TAG, "BindSessionPort(): Exception(0x%08x)", status);
        return status;
    }

    _sessionPort->SetValue(sessionPort);

    return NOERROR;
}

ECode CBusAttachment::SetDescriptionTranslator(
    /* [in] */ ITranslator* translator)
{
    return NOERROR;
}

ECode CBusAttachment::UnbindSessionPort(
    /* [in] */ Int16 sessionPort)
{
    return NOERROR;
}

ECode CBusAttachment::JoinSession(
    /* [in] */ const String& sessionHost,
    /* [in] */ Int16 sessionPort,
    /* [in] */ IMutableInteger32Value* sessionId,
    /* [in] */ ISessionOpts* opts,
    /* [in] */ ISessionListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::JoinSession(
    /* [in] */ const String& sessionHost,
    /* [in] */ Int16 sessionPort,
    /* [in] */ ISessionOpts* opts,
    /* [in] */ ISessionListener* listener,
    /* [in] */ IOnJoinSessionListener* onJoinSession,
    /* [in] */ IInterface* context)
{
    return NOERROR;
}

ECode CBusAttachment::LeaveSession(
    /* [in] */ Int32 sessionId)
{
    return NOERROR;
}

ECode CBusAttachment::LeaveHostedSession(
    /* [in] */ Int32 sessionId)
{
    return NOERROR;
}

ECode CBusAttachment::LeaveJoinedSession(
    /* [in] */ Int32 sessionId)
{
    return NOERROR;
}

ECode CBusAttachment::RemoveSessionMember(
    /* [in] */ Int32 sessionId,
    /* [in] */ const String& sessionMemberName)
{
    return NOERROR;
}

ECode CBusAttachment::SetSessionListener(
    /* [in] */ Int32 sessionId,
    /* [in] */ ISessionListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::SetJoinedSessionListener(
    /* [in] */ Int32 sessionId,
    /* [in] */ ISessionListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::SetHostedSessionListener(
    /* [in] */ Int32 sessionId,
    /* [in] */ ISessionListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::GetSessionFd(
    /* [in] */ Int32 sessionId,
    /* [in] */ IMutableInteger32Value* sockFd)
{
    return NOERROR;
}

ECode CBusAttachment::SetLinkTimeout(
    /* [in] */ Int32 sessionId,
    /* [in] */ IMutableInteger32Value* linkTimeout)
{
    return NOERROR;
}

ECode CBusAttachment::GetPeerGUID(
    /* [in] */ const String& name,
    /* [in] */ IMutableStringValue* guid)
{
    return NOERROR;
}

ECode CBusAttachment::Ping(
    /* [in] */ const String& name,
    /* [in] */ Int32 timeout)
{
    return NOERROR;
}

ECode CBusAttachment::PingAsync(
    /* [in] */ const String& name,
    /* [in] */ Int32 timeout,
    /* [in] */ IOnPingListener* onPing,
    /* [in] */ IInterface* context)
{
    return NOERROR;
}

ECode CBusAttachment::Ping(
    /* [in] */ const String& name,
    /* [in] */ Int32 timeout,
    /* [in] */ IOnPingListener* onPing,
    /* [in] */ IInterface* context)
{
    return NOERROR;
}

ECode CBusAttachment::SetDaemonDebug(
    /* [in] */ const String& moduleName,
    /* [in] */ Int32 level)
{
    return NOERROR;
}

ECode CBusAttachment::SetLogLevels(
    /* [in] */ const String& logEnv)
{
    return NOERROR;
}

ECode CBusAttachment::SetDebugLevel(
    /* [in] */ const String& moduleName,
    /* [in] */ Int32 level)
{
    return NOERROR;
}

ECode CBusAttachment::UseOSLogging(
    /* [in] */ Boolean useOSLog)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterAboutListener(
    /* [in] */ IAboutListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::UnregisterAboutListener(
    /* [in] */ IAboutListener* listener)
{
    return NOERROR;
}

// @BusSignalHandler(iface = "org.alljoyn.About", signal = "Announce")
// public void announce(short version, short port, AboutObjectDescription[] objectDescriptions, Map<String, Variant> aboutData);

// public Status setAnnounceFlag(BusObject busObject, Class<?> intf, boolean isAnnounced);

ECode CBusAttachment::SetAnnounceFlag(
    /* [in] */ IBusObject* busObject,
    /* [in] */ const String& ifcName,
    /* [in] */ Boolean isAnnounced)
{
    return NOERROR;
}

ECode CBusAttachment::WhoImplements(
    /* [in] */ ArrayOf<String>* interfaces)
{
    return NOERROR;
}

ECode CBusAttachment::CancelWhoImplements(
    /* [in] */ ArrayOf<String>* interfaces)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterBusListener(
    /* [in] */ IBusListener* listener)
{
    if (listener == NULL) return NOERROR;

    NativeBusAttachment* busPtr = reinterpret_cast<NativeBusAttachment*>(mHandle);
    if (busPtr == NULL) {
        Logger::E(TAG, "RegisterBusListener(): Exception or NULL bus pointer");
        return NOERROR;
    }

    {
        AutoLock lock(busPtr->mBaCommonLock);

        busPtr->mBusListeners.PushBack(listener);
    }

    NativeBusListener* ntListener = reinterpret_cast<NativeBusListener*>(((BusListener*)listener)->mHandle);

    assert(ntListener);
    ntListener->Setup(this);

    busPtr->RegisterBusListener(*ntListener);
    return NOERROR;
}

ECode CBusAttachment::UnregisterBusListener(
    /* [in] */ IBusListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::ReleaseResources()
{
    return NOERROR;
}

ECode CBusAttachment::Connect()
{
    return NOERROR;
}

ECode CBusAttachment::IsConnected(
    /* [out] */ Boolean* connected)
{
    return NOERROR;
}

ECode CBusAttachment::Disconnect()
{
    return NOERROR;
}

ECode CBusAttachment::RegisterBusObject(
    /* [in] */ IBusObject* busObj,
    /* [in] */ const String& objPath)
{
    return RegisterBusObject(busObj, objPath, FALSE, String(NULL), String(NULL), NULL);
}

ECode CBusAttachment::RegisterBusObject(
    /* [in] */ IBusObject* busObj,
    /* [in] */ const String& objPath,
    /* [in] */ Boolean secure)
{
    return RegisterBusObject(busObj, objPath, secure, String(NULL), String(NULL), NULL);
}

ECode CBusAttachment::RegisterBusObject(
    /* [in] */ IBusObject* busObj,
    /* [in] */ const String& objPath,
    /* [in] */ Boolean secure,
    /* [in] */ const String& languageTag,
    /* [in] */ const String& description)
{
    return RegisterBusObject(busObj, objPath, secure, languageTag, description, NULL);
}

ECode CBusAttachment::RegisterBusObject(
    /* [in] */ IBusObject* busObj,
    /* [in] */ const String& objPath,
    /* [in] */ Boolean secure,
    /* [in] */ const String& languageTag,
    /* [in] */ const String& description,
    /* [in] */ ITranslator* dt)
{
    // try {
    AutoPtr<IList> descs;
    CArrayList::New((IList**)&descs);
    AutoPtr<IClassInfo> clsInfo;
    CObject::ReflectClassInfo(busObj, (IClassInfo**)&clsInfo);
    Int32 count;
    clsInfo->GetInterfaceCount(&count);
    AutoPtr< ArrayOf<IInterfaceInfo*> > busInterfaces = ArrayOf<IInterfaceInfo*>::Alloc(count);
    clsInfo->GetAllInterfaceInfos(busInterfaces);
    ECode ec = InterfaceDescription::Create(this, busInterfaces, descs);
    if (ec != E_STATUS_OK) {
        return ec;
    }
    AutoPtr< ArrayOf<IInterfaceDescription*> > busInterfaceArray;
    descs->ToArray((ArrayOf<IInterface*>**)&busInterfaceArray);
    return RegisterBusObject(objPath, busObj, busInterfaceArray, secure,
            languageTag, description, dt);
    // } catch (AnnotationBusException ex) {
    //     BusException.log(ex);
    //     return Status.BAD_ANNOTATION;
    // }
}

ECode CBusAttachment::IsBusObjectSecure(
    /* [in] */ IBusObject* busObj,
    /* [out] */ Boolean* secure)
{
    return NOERROR;
}

ECode CBusAttachment::UnregisterBusObject(
    /* [in] */ IBusObject* obj)
{
    return NOERROR;
}

ECode CBusAttachment::GetProxyBusObject(
    /* [in] */ const String& busName,
    /* [in] */ const String& objPath,
    /* [in] */ Int32 sessionId,
    /* [in] */ ArrayOf<InterfaceID>* busInterfaces,
    /* [out] */ IProxyBusObject** proxy)
{
    return NOERROR;
}

// public ProxyBusObject getProxyBusObject(String busName,
//         String objPath,
//         int sessionId,
//         Class<?>[] busInterfaces,
//         boolean secure);

// public DBusProxyObj getDBusProxyObj();

ECode CBusAttachment::GetUniqueName(
    /* [out] */ String* uniqueName)
{
    return NOERROR;
}

ECode CBusAttachment::GetGlobalGUIDString(
    /* [out] */ String* guid)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterSignalHandler(
    /* [in] */ const String& ifaceName,
    /* [in] */ const String& signalName,
    /* [in] */ IInterface* obj,
    /* [in] */ IMethodInfo* handlerMethod)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterSignalHandler(
    /* [in] */ const String& ifaceName,
    /* [in] */ const String& signalName,
    /* [in] */ IInterface* obj,
    /* [in] */ IMethodInfo* handlerMethod,
    /* [in] */ const String& source)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterSignalHandlerWithRule(
    /* [in] */ const String& ifaceName,
    /* [in] */ const String& signalName,
    /* [in] */ IInterface* obj,
    /* [in] */ IMethodInfo* handlerMethod,
    /* [in] */ const String& matchRule)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterSignalHandlers(
    /* [in] */ IInterface* obj)
{
    return NOERROR;
}

ECode CBusAttachment::UnregisterSignalHandler(
    /* [in] */ IInterface* obj,
    /* [in] */ IMethodInfo* handlerMethod)
{
    return NOERROR;
}

ECode CBusAttachment::UnregisterSignalHandlers(
    /* [in] */ IInterface* obj)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterKeyStoreListener(
    /* [in] */ IKeyStoreListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::ClearKeyStore()
{
    return NOERROR;
}

ECode CBusAttachment::ClearKeys(
    /* [in] */ const String& guid)
{
    return NOERROR;
}

ECode CBusAttachment::SetKeyExpiration(
    /* [in] */ const String& guid,
    /* [in] */ Int32 timeout)
{
    return NOERROR;
}

ECode CBusAttachment::GetKeyExpiration(
    /* [in] */ const String& guid,
    /* [in] */ IMutableInteger32Value* timeout)
{
    return NOERROR;
}

ECode CBusAttachment::ReloadKeyStore()
{
    return NOERROR;
}

ECode CBusAttachment::RegisterAuthListener(
    /* [in] */ const String& authMechanisms,
    /* [in] */ IAuthListener* listener,
    /* [in] */ const String& keyStoreFileName,
    /* [in] */ Boolean isShared)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterAuthListener(
    /* [in] */ const String& authMechanisms,
    /* [in] */ IAuthListener* listener,
    /* [in] */ const String& keyStoreFileName)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterAuthListener(
    /* [in] */ const String& authMechanisms,
    /* [in] */ IAuthListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::RegisterSecurityViolationListener(
    /* [in] */ ISecurityViolationListener* listener)
{
    return NOERROR;
}

ECode CBusAttachment::GetMessageContext(
    /* [out] */ IMessageContext** context)
{
    return NOERROR;
}

ECode CBusAttachment::EnableConcurrentCallbacks()
{
    return NOERROR;
}

} // namespace Bus
} // namespace Alljoyn
} // namespace Org

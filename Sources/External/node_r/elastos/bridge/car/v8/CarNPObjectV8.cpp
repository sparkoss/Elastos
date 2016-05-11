
#include "ElNode.h"
#include "config.h"

#if ENABLE(CAR_BRIDGE)

#include "npruntime_impl.h"

#include "etl/HashSet.h"
#include "elastos.h"

#include "CarUtilityPrivate.h"
#include "CarNPObjectV8.h"
#include "CarClassV8.h"
#include "CarInstanceV8.h"
#include "CarMethodCobject.h"
#include "CarFieldCobjectV8.h"

#include <utils/Log.h>

namespace JSC {
namespace Bindings {

static NPObject* AllocCarNPObject(NPP, NPClass*)
{
    CarNPObject* obj = static_cast<CarNPObject*>(malloc(sizeof(CarNPObject)));
    if (!obj) {
        return 0;
    }
    memset(obj, 0, sizeof(CarNPObject));
    return reinterpret_cast<NPObject*>(obj);
}

static void FreeCarNPObject(NPObject* npobj)
{
    CarNPObject* obj = reinterpret_cast<CarNPObject*>(npobj);
    obj->mInstance = 0; // free does not call the destructor
    free(obj);
}

static NPClass CarNPObjectClass =
{
    NP_CLASS_STRUCT_VERSION_CTOR,
    AllocCarNPObject, // allocate,
    FreeCarNPObject, // free,
    CarNPObjectInvalidate,//TODO
    CarNPObjectHasMethod,
    CarNPObjectInvoke,
    CarNPObjectInvokeDefault,//TODO
    CarNPObjectHasProperty,//TODO
    CarNPObjectGetProperty,//TODO
    CarNPObjectSetProperty,//TODO
    CarNPObjectRemoveProperty,//TODO
    CarNPObjectEnumerate,//TODO
    CarNPObjectConstruct,//TODO
};

NPObject* CarInstanceToNPObject(CarInstance* instance)
{
    CarNPObject* object;
    object = reinterpret_cast<CarNPObject*>(_NPN_CreateObject(0, &CarNPObjectClass));
    object->mInstance = instance;

    return reinterpret_cast<NPObject*>(object);
}

// Returns null if obj is not a wrapper of JavaInstance
CarInstance* ExtractCarInstance(NPObject* npobj)
{
    CarInstance* retCarInstance = NULL;
    if (npobj->_class == &CarNPObjectClass) {
        retCarInstance = reinterpret_cast<CarNPObject*>(npobj)->mInstance.get();
    }
    return retCarInstance;
}

void CarNPObjectInvalidate(NPObject *npobj)
{
    //TODO
    ALOGD("CarNPObjectInvalidate.begin");
}

bool CarNPObjectHasMethod(NPObject* npobj, NPIdentifier identifier) //TODO
{
    bool retValue = false;

    CarInstance* instance = ExtractCarInstance(npobj);
    if (!instance) return false;

    NPUTF8* name;
    name = _NPN_UTF8FromIdentifier(identifier);
    if (!name) return false;

    instance->begin();
    retValue = (instance->getClass()->methodsNamed(name).size() > 0);

    instance->end();

    // TODO: use NPN_MemFree
    free(name);

    return retValue;
}

bool CarNPObjectInvoke(NPObject* npobj, NPIdentifier identifier, const NPVariant* args, uint32_t argCount, NPVariant* result)
{
    ECode ec = NOERROR;

    CarInstance* instance = ExtractCarInstance(npobj);
    if (!instance) {
        LOG_ERROR("CarNPObjectInvoke: unable to extract car instance from NPObject %p", npobj);
        return false;
    }

    NPUTF8* name;
    name = _NPN_UTF8FromIdentifier(identifier);
    if (!name) {
        LOG_ERROR("CarNPObjectInvoke: unable to get method name from NPIdentifier");
        return false;
    }

    instance->begin();

    MethodList methodList = instance->getClass()->methodsNamed(name);

    WTF::String methodName(name);

    // TODO: use NPN_MemFree
    //free(name);

    // Try to find a good match for the overloaded method. The
    // fundamental problem is that JavaScript doesn't have the
    // notion of method overloading and Java does. We could
    // get a bit more sophisticated and attempt to do some
    // type checking as well as checking the number of parameters.
    size_t numMethods = methodList.size();
    CarMethod* carMethod = 0;

    //TODO: more than one out parameters and with default input parameters
    //bool result_0 = (methodList.size() > 0);
    //if (result_0) {
        for (size_t methodIndex = 0; methodIndex < numMethods; methodIndex++) {
            //To be Fixed: shuld compare with only input parameters count
            //if (aMethod->numParameters() == static_cast<int>(argCount)) {
                carMethod = methodList[methodIndex];
                break;
            //}
        }
    //}

    if (!carMethod) {
        //TODO:
        //result->value.objectValue = *(NPObject**)&identifier;
        //bool retDefault = CarNPObjectInvokeDefault(npobj, args, argCount, result);
        //instance->end();
        //return retDefault;
        free(name);
        return false;
    }

    AutoPtr<IInterface> object = instance->carInstance();

    AutoPtr<IInterfaceInfo> interfaceInfo;
    bool bClass = true;

    AutoPtr<IClassInfo> classInfo;

    ec = CObject::ReflectClassInfo(object, (IClassInfo**)&classInfo);
    if (FAILED(ec)) {
        bClass = false;
        interfaceInfo = IInterfaceInfo::Probe(instance->getInstance()->getDataTypeInfo());
    }

    AutoPtr<IMethodInfo> methodInfo;
    if (bClass) {
        //ec = classInfo->GetMethodInfo(carMethod->name().utf8().data(), (IMethodInfo**)&methodInfo);
        ec = classInfo->GetMethodInfo(Elastos::String(carMethod->name().utf8().data()), Elastos::String("(I32)E"), (IMethodInfo**)&methodInfo);
    }
    else {
        //ec = interfaceInfo->GetMethodInfo(carMethod->name().utf8().data(), (IMethodInfo**)&methodInfo);
        ec = classInfo->GetMethodInfo(Elastos::String(carMethod->name().utf8().data()), Elastos::String("(I32)E"), (IMethodInfo**)&methodInfo);
    }
    if (FAILED(ec)) {
        LOG_ERROR("CarNPObjectInvoke: get methodinfo failed, to invoke default!");
        instance->end();
        free(name);
        return false;
    }

    //-----------------bRunOnUiThread begin-------------------
    bool bRunOnUiThread;

    Elastos::String mMethodAnnotation;
    ec = methodInfo->GetAnnotation(&mMethodAnnotation);
    if (FAILED(ec)) {
        printf("Get %s method annotation failed!\n", name);
        free(name);
        return ec;
    }

    if (mMethodAnnotation == "MainThread") {
        bRunOnUiThread = true;
    }

    carMethod->setRunOnUiThread(bRunOnUiThread);
    //-----------------bRunOnUiThread end-------------------

    free(name);

    unsigned int numParams = carMethod->numParameters();
    ArrayOf<IParamInfo*>* paramInfos = ArrayOf<IParamInfo*>::Alloc(numParams);
    methodInfo->GetAllParamInfos(paramInfos);

    unsigned int inParamsPos = 0;
    unsigned int outParamPos = 0;
    unsigned int outParamsCount = numParams - argCount;
    AutoPtr< ArrayOf<Int32> > outParamsPosBuf = ArrayOf<Int32>::Alloc(outParamsCount);

    CarValue* jArgs = new CarValue[numParams];

    Boolean tagSetLocalPtr = false;

    for (unsigned int i = 0; i < numParams; i++) {
        AutoPtr<IParamInfo> aParameter = (*paramInfos)[i];
        ParamIOAttribute paramIOAttribute;
        aParameter->GetIOAttribute(&paramIOAttribute);
        AutoPtr<IDataTypeInfo> aDataTypeInfo;
        aParameter->GetTypeInfo((IDataTypeInfo**)&aDataTypeInfo);
        CarDataType dataType;
        aDataTypeInfo->GetDataType(&dataType);

        //for test of CTestArgumentList::SetInputArgumentOfLocalPtr
        if (i == 0 && numParams == 3 && dataType == CarDataType_LocalPtr) {
            tagSetLocalPtr = true;
        }
        jArgs[i].mTagSetLocalPtr = false;
        if (tagSetLocalPtr && i == 2) {
            jArgs[i].mTagSetLocalPtr = true;
        }

        AutoPtr<IDataTypeInfo> aElementDataTypeInfo;
        CarDataType elementDataType;
        if (dataType == CarDataType_ArrayOf) {
            ICarArrayInfo::Probe(aDataTypeInfo)->GetElementTypeInfo((IDataTypeInfo**)&aElementDataTypeInfo);
            aElementDataTypeInfo->GetDataType(&elementDataType);
        }
        else if (dataType == CarDataType_LocalPtr) {
            (*(ILocalPtrInfo **)&aDataTypeInfo)->GetTargetTypeInfo((IDataTypeInfo**)&aElementDataTypeInfo);
            aElementDataTypeInfo->GetDataType(&elementDataType);
        }

        jArgs[i].mIOAttribute = paramIOAttribute;
        jArgs[i].mType = dataType;
        jArgs[i].mElementType = elementDataType;
        jArgs[i].mObjectWrapper = new CobjectWrapper(NULL,aDataTypeInfo);

        switch (paramIOAttribute) {
            case ParamIOAttribute_In:
            {
                if (inParamsPos > argCount) {
                    LOG_ERROR("CarNPObjectInvoke param IOAtrribute: args num error");
                    instance->end();
                    for (unsigned int j = 0; j < numParams; j++) {
                        (*paramInfos)[j]->Release();
                        (*paramInfos)[j] = NULL;
                    }
                    ArrayOf<IParamInfo*>::Free(paramInfos);
                    return false;
                }
                convertNPVariantToCarValue(args[inParamsPos], &jArgs[i]);
                inParamsPos++;
                break;
            }
            case ParamIOAttribute_CalleeAllocOut:
                //TODO
                outParamsPosBuf->Set(outParamPos, i);
                outParamPos++;
                break;
            case ParamIOAttribute_CallerAllocOut:
                //TODO
                outParamsPosBuf->Set(outParamPos, i);
                outParamPos++;
                break;
            default:
                //TODO
                break;
        }

        (*paramInfos)[i]->Release();
        (*paramInfos)[i] = NULL;
    }
    ArrayOf<IParamInfo*>::Free(paramInfos);

    bool exceptionOccurred;
    instance->invokeMethod(carMethod, jArgs, exceptionOccurred);
    instance->end();

    if (exceptionOccurred) {
        LOG_ERROR("CarNPObjectInvoke: exception occurred!");
        delete[] jArgs;
        return false;
    }

    convertCarValuesToNPVariant(carMethod, jArgs, outParamsPosBuf, result);

    delete[] jArgs;
    return true;
}

bool CarNPObjectInvokeDefault(NPObject *npobj, const NPVariant *args, uint32_t argCount, NPVariant *result)
{
    //TODO
    ALOGD("CarNPObjectInvokeDefault.begin");

    bool retBool = false;
/*
    NPIdentifier identifier = (NPIdentifier)result->value.objectValue;
    result->value.objectValue = NULL;
    NPUTF8* name;
    name = _NPN_UTF8FromIdentifier(identifier);
    if (!name) {
        LOG_ERROR("CarNPObjectInvokeDefault: unable to get method name from NPIdentifier");
        return false;
    }
    ALOGD("CarNPObjectInvokeDefault.begin method name: %s====",name);

    CarInstance* carInstance = ExtractCarInstance(npobj);
    if (!carInstance) {
        LOG_ERROR("CarNPObjectInvokeDefault: unable to extract car instance from NPObject %p", npobj);
        return false;
    }

    CobjectWrapper* objectWrapper = carInstance->getInstance();
    AutoPtr<IInterface> instance = objectWrapper->getInstance();
    AutoPtr<IDataTypeInfo> dataTypeInfo = objectWrapper->getDataTypeInfo();

    if (!strcmp(name,"Probe")) {
        String nameBuf_0;
        dataTypeInfo->GetName(&nameBuf_0);
        retBool = true;
    }
*/
    return retBool;
}

bool CarNPObjectHasProperty(NPObject* npobj, NPIdentifier identifier)
{
    //TODO

    return false;

    bool retValue = false;

    CarInstance* instance = ExtractCarInstance(npobj);
    if (!instance)
        return false;
    NPUTF8* name;
    name = _NPN_UTF8FromIdentifier(identifier);

    if (!name)
        return false;

    //ALOGD("CarNPObjectHasProperty.begin========name: %s====",name);

    instance->begin();
    //Note: the return type of fieldNames is CarField,not Boolean.
    retValue = instance->getClass()->fieldNamed(name);
    //CarField* carField = instance->getClass()->fieldNamed(name);
    instance->end();

    free(name);

    //ALOGD("CarNPObjectHasProperty.end result:%d",retValue);

    return retValue;
}

bool CarNPObjectGetProperty(NPObject* npobj, NPIdentifier identifier, NPVariant* result)
{
    bool returnValue;

    VOID_TO_NPVARIANT(*result);
    CarInstance* instance = ExtractCarInstance(npobj);
    if (!instance)
        return false;
    NPUTF8* name;
    name = _NPN_UTF8FromIdentifier(identifier);
    if (!name)
        return false;

    ALOGD("CarNPObjectGetProperty.begin========name: %s====",name);

    instance->begin();
    //CarField* field = NULL;
    //TODO:
    CarField* field = instance->getClass()->fieldNamed(name);
    free(name); // TODO: use NPN_MemFree
    if (!field) {
        instance->end();
        return false;
    }

#if PLATFORM(ANDROID)
    // JSC does not seem to support returning object properties so we emulate that
    // behaviour here.
    CarValue value;
#else
    CarValue value;
    //TODO:
    //CarValue value = instance->getField(field);
#endif // PLATFORM(ANDROID)
    instance->end();

    returnValue = true;

    convertCarValueToNPVariant(value, result);

    ALOGD("CarNPObjectGetProperty.end %d",returnValue);
    return returnValue;
}

bool CarNPObjectSetProperty(NPObject *npobj, NPIdentifier name, const NPVariant *value)
{
    //TODO:
    ALOGD("CarNPObjectSetProperty.begin");
    return false;
}

bool CarNPObjectRemoveProperty(NPObject *npobj, NPIdentifier name)
{
    //TODO:
    ALOGD("CarNPObjectRemoveProperty.begin");
    return false;
}

bool CarNPObjectEnumerate(NPObject *npobj, NPIdentifier **value, uint32_t *count){
    CarInstance* instance = ExtractCarInstance(npobj);
    if (!instance) return false;

    CobjectWrapper* objectWrapper = instance->getInstance();

    ECode ec = NOERROR;
    AutoPtr<IClassInfo> classInfo;
    AutoPtr<IInterfaceInfo> interfaceInfo;
    bool bClass = true;

    ec = CObject::ReflectClassInfo(objectWrapper->getInstance(), (IClassInfo**)&classInfo);
    if (FAILED(ec)) {
        bClass = false;
        interfaceInfo = IInterfaceInfo::Probe(objectWrapper->getDataTypeInfo());
    }

    Int32 N;
    if (bClass) {
        classInfo->GetMethodCount(&N);
    }
    else {
        interfaceInfo->GetMethodCount(&N);

        //test code ,to be delete
        Elastos::String nameBuf_0;
        interfaceInfo->GetName(&nameBuf_0);
        ALOGD("CarNPObjectEnumerate test.GetMethodCount : %d interface name: %s============",N,(const char*)nameBuf_0);
    }

    ArrayOf<IMethodInfo*>* methodInfos = ArrayOf<IMethodInfo*>::Alloc(N);

    if (bClass) {
        ec = classInfo->GetAllMethodInfos(methodInfos);
    }
    else {
        ec = interfaceInfo->GetAllMethodInfos(methodInfos);
    }
    if (FAILED(ec)) {
        LOG_ERROR("CarNPObjectEnumerate unable to find methods on instance");
        return false;
    }

    *count = N;
    NPIdentifier* outList(NULL);
    outList = (NPIdentifier*)NPN_MemAlloc((uint32_t)(sizeof(NPIdentifier)*N));

    //Get method and property names
    Elastos::String nameBuf;
    for (Int32 i = 0; i < N; i++) {
        AutoPtr<IMethodInfo> methodInfo = (*methodInfos)[i];
        methodInfo->GetName(&nameBuf);
        outList[i] = _NPN_GetStringIdentifier((const char*)nameBuf);
        methodInfo->Release();
        methodInfo = NULL;
    }

    ArrayOf<IMethodInfo*>::Free(methodInfos);

    *value = outList;

    return true;
}

bool CarNPObjectConstruct(NPObject *npobj, const NPVariant *args, uint32_t argCount, NPVariant *result)
{
    //TODO:
    ALOGD("CarNPObjectConstruct.begin");
    return false;
}

} // namespace Bindings
} // namespace JSC

#endif // ENABLE(CAR_BRIDGE)
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8XPathResult.h"

#include "bindings/core/v8/V8Node.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(XPathResult* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8XPathResult::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::XPathResult* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8XPathResult::wrapperTypeInfo = { gin::kEmbedderBlink, V8XPathResult::domTemplate, V8XPathResult::derefObject, 0, 0, 0, V8XPathResult::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace XPathResultV8Internal {

template <typename T> void V8_USE(T) { }

static void resultTypeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    XPathResult* impl = V8XPathResult::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->resultType());
}

static void resultTypeAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    XPathResultV8Internal::resultTypeAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void numberValueAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    XPathResult* impl = V8XPathResult::toNative(holder);
    ExceptionState exceptionState(ExceptionState::GetterContext, "numberValue", "XPathResult", holder, info.GetIsolate());
    double v8Value = impl->numberValue(exceptionState);
    if (UNLIKELY(exceptionState.throwIfNeeded()))
        return;
    v8SetReturnValue(info, v8Value);
}

static void numberValueAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    XPathResultV8Internal::numberValueAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void stringValueAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    XPathResult* impl = V8XPathResult::toNative(holder);
    ExceptionState exceptionState(ExceptionState::GetterContext, "stringValue", "XPathResult", holder, info.GetIsolate());
    String v8Value = impl->stringValue(exceptionState);
    if (UNLIKELY(exceptionState.throwIfNeeded()))
        return;
    v8SetReturnValueString(info, v8Value, info.GetIsolate());
}

static void stringValueAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    XPathResultV8Internal::stringValueAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void booleanValueAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    XPathResult* impl = V8XPathResult::toNative(holder);
    ExceptionState exceptionState(ExceptionState::GetterContext, "booleanValue", "XPathResult", holder, info.GetIsolate());
    bool v8Value = impl->booleanValue(exceptionState);
    if (UNLIKELY(exceptionState.throwIfNeeded()))
        return;
    v8SetReturnValueBool(info, v8Value);
}

static void booleanValueAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    XPathResultV8Internal::booleanValueAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void singleNodeValueAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    XPathResult* impl = V8XPathResult::toNative(holder);
    ExceptionState exceptionState(ExceptionState::GetterContext, "singleNodeValue", "XPathResult", holder, info.GetIsolate());
    RefPtrWillBeRawPtr<Node> v8Value = impl->singleNodeValue(exceptionState);
    if (UNLIKELY(exceptionState.throwIfNeeded()))
        return;
    v8SetReturnValueFast(info, WTF::getPtr(v8Value.release()), impl);
}

static void singleNodeValueAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    XPathResultV8Internal::singleNodeValueAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void invalidIteratorStateAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    XPathResult* impl = V8XPathResult::toNative(holder);
    v8SetReturnValueBool(info, impl->invalidIteratorState());
}

static void invalidIteratorStateAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    XPathResultV8Internal::invalidIteratorStateAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void snapshotLengthAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    XPathResult* impl = V8XPathResult::toNative(holder);
    ExceptionState exceptionState(ExceptionState::GetterContext, "snapshotLength", "XPathResult", holder, info.GetIsolate());
    unsigned v8Value = impl->snapshotLength(exceptionState);
    if (UNLIKELY(exceptionState.throwIfNeeded()))
        return;
    v8SetReturnValueUnsigned(info, v8Value);
}

static void snapshotLengthAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    XPathResultV8Internal::snapshotLengthAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void iterateNextMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "iterateNext", "XPathResult", info.Holder(), info.GetIsolate());
    XPathResult* impl = V8XPathResult::toNative(info.Holder());
    RefPtrWillBeRawPtr<Node> result = impl->iterateNext(exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
    v8SetReturnValue(info, result.release());
}

static void iterateNextMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    XPathResultV8Internal::iterateNextMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void snapshotItemMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "snapshotItem", "XPathResult", info.Holder(), info.GetIsolate());
    XPathResult* impl = V8XPathResult::toNative(info.Holder());
    unsigned index;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(index, toUInt32(info[0], exceptionState), exceptionState);
    }
    RefPtrWillBeRawPtr<Node> result = impl->snapshotItem(index, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
    v8SetReturnValue(info, result.release());
}

static void snapshotItemMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    XPathResultV8Internal::snapshotItemMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace XPathResultV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8XPathResultAttributes[] = {
    {"resultType", XPathResultV8Internal::resultTypeAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"numberValue", XPathResultV8Internal::numberValueAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"stringValue", XPathResultV8Internal::stringValueAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"booleanValue", XPathResultV8Internal::booleanValueAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"singleNodeValue", XPathResultV8Internal::singleNodeValueAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"invalidIteratorState", XPathResultV8Internal::invalidIteratorStateAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"snapshotLength", XPathResultV8Internal::snapshotLengthAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::MethodConfiguration V8XPathResultMethods[] = {
    {"iterateNext", XPathResultV8Internal::iterateNextMethodCallback, 0, 0},
    {"snapshotItem", XPathResultV8Internal::snapshotItemMethodCallback, 0, 0},
};

static void configureV8XPathResultTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "XPathResult", v8::Local<v8::FunctionTemplate>(), V8XPathResult::internalFieldCount,
        V8XPathResultAttributes, WTF_ARRAY_LENGTH(V8XPathResultAttributes),
        0, 0,
        V8XPathResultMethods, WTF_ARRAY_LENGTH(V8XPathResultMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();
    static const V8DOMConfiguration::ConstantConfiguration V8XPathResultConstants[] = {
        {"ANY_TYPE", 0},
        {"NUMBER_TYPE", 1},
        {"STRING_TYPE", 2},
        {"BOOLEAN_TYPE", 3},
        {"UNORDERED_NODE_ITERATOR_TYPE", 4},
        {"ORDERED_NODE_ITERATOR_TYPE", 5},
        {"UNORDERED_NODE_SNAPSHOT_TYPE", 6},
        {"ORDERED_NODE_SNAPSHOT_TYPE", 7},
        {"ANY_UNORDERED_NODE_TYPE", 8},
        {"FIRST_ORDERED_NODE_TYPE", 9},
    };
    V8DOMConfiguration::installConstants(functionTemplate, prototypeTemplate, V8XPathResultConstants, WTF_ARRAY_LENGTH(V8XPathResultConstants), isolate);
    COMPILE_ASSERT(0 == XPathResult::ANY_TYPE, TheValueOfXPathResult_ANY_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(1 == XPathResult::NUMBER_TYPE, TheValueOfXPathResult_NUMBER_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(2 == XPathResult::STRING_TYPE, TheValueOfXPathResult_STRING_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(3 == XPathResult::BOOLEAN_TYPE, TheValueOfXPathResult_BOOLEAN_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(4 == XPathResult::UNORDERED_NODE_ITERATOR_TYPE, TheValueOfXPathResult_UNORDERED_NODE_ITERATOR_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(5 == XPathResult::ORDERED_NODE_ITERATOR_TYPE, TheValueOfXPathResult_ORDERED_NODE_ITERATOR_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(6 == XPathResult::UNORDERED_NODE_SNAPSHOT_TYPE, TheValueOfXPathResult_UNORDERED_NODE_SNAPSHOT_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(7 == XPathResult::ORDERED_NODE_SNAPSHOT_TYPE, TheValueOfXPathResult_ORDERED_NODE_SNAPSHOT_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(8 == XPathResult::ANY_UNORDERED_NODE_TYPE, TheValueOfXPathResult_ANY_UNORDERED_NODE_TYPEDoesntMatchWithImplementation);
    COMPILE_ASSERT(9 == XPathResult::FIRST_ORDERED_NODE_TYPE, TheValueOfXPathResult_FIRST_ORDERED_NODE_TYPEDoesntMatchWithImplementation);

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8XPathResult::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8XPathResultTemplate);
}

bool V8XPathResult::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8XPathResult::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

XPathResult* V8XPathResult::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(XPathResult* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8XPathResult>(impl, isolate));
    return V8XPathResult::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8XPathResult::createWrapper(PassRefPtrWillBeRawPtr<XPathResult> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8XPathResult>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8XPathResult>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8XPathResult::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(XPathResult* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

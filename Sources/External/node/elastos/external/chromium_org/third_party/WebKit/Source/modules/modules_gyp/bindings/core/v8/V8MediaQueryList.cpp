// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8MediaQueryList.h"

#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/css/MediaQueryListListener.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(MediaQueryList* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8MediaQueryList::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::MediaQueryList* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8MediaQueryList::wrapperTypeInfo = { gin::kEmbedderBlink, V8MediaQueryList::domTemplate, V8MediaQueryList::derefObject, 0, 0, 0, V8MediaQueryList::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace MediaQueryListV8Internal {

template <typename T> void V8_USE(T) { }

static void mediaAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    MediaQueryList* impl = V8MediaQueryList::toNative(holder);
    v8SetReturnValueString(info, impl->media(), info.GetIsolate());
}

static void mediaAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    MediaQueryListV8Internal::mediaAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void matchesAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    MediaQueryList* impl = V8MediaQueryList::toNative(holder);
    v8SetReturnValueBool(info, impl->matches());
}

static void matchesAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    MediaQueryListV8Internal::matchesAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void addListenerMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    MediaQueryList* impl = V8MediaQueryList::toNative(info.Holder());
    RefPtrWillBeRawPtr<MediaQueryListListener> listener;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(listener, MediaQueryListListener::create(ScriptState::current(info.GetIsolate()), ScriptValue(ScriptState::current(info.GetIsolate()), info[0])));
    }
    impl->addListener(listener);
}

static void addListenerMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    MediaQueryListV8Internal::addListenerMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void removeListenerMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    MediaQueryList* impl = V8MediaQueryList::toNative(info.Holder());
    RefPtrWillBeRawPtr<MediaQueryListListener> listener;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(listener, MediaQueryListListener::create(ScriptState::current(info.GetIsolate()), ScriptValue(ScriptState::current(info.GetIsolate()), info[0])));
    }
    impl->removeListener(listener);
}

static void removeListenerMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    MediaQueryListV8Internal::removeListenerMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace MediaQueryListV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8MediaQueryListAttributes[] = {
    {"media", MediaQueryListV8Internal::mediaAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"matches", MediaQueryListV8Internal::matchesAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::MethodConfiguration V8MediaQueryListMethods[] = {
    {"addListener", MediaQueryListV8Internal::addListenerMethodCallback, 0, 0},
    {"removeListener", MediaQueryListV8Internal::removeListenerMethodCallback, 0, 0},
};

static void configureV8MediaQueryListTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "MediaQueryList", v8::Local<v8::FunctionTemplate>(), V8MediaQueryList::internalFieldCount,
        V8MediaQueryListAttributes, WTF_ARRAY_LENGTH(V8MediaQueryListAttributes),
        0, 0,
        V8MediaQueryListMethods, WTF_ARRAY_LENGTH(V8MediaQueryListMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8MediaQueryList::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8MediaQueryListTemplate);
}

bool V8MediaQueryList::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8MediaQueryList::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

MediaQueryList* V8MediaQueryList::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(MediaQueryList* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8MediaQueryList>(impl, isolate));
    return V8MediaQueryList::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8MediaQueryList::createWrapper(PassRefPtrWillBeRawPtr<MediaQueryList> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8MediaQueryList>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8MediaQueryList>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8MediaQueryList::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(MediaQueryList* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

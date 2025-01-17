// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8ApplicationCache.h"

#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8AbstractEventListener.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8EventListenerList.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(ApplicationCache* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8ApplicationCache::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::ApplicationCache* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8ApplicationCache::wrapperTypeInfo = { gin::kEmbedderBlink, V8ApplicationCache::domTemplate, V8ApplicationCache::derefObject, 0, V8ApplicationCache::toEventTarget, 0, V8ApplicationCache::installPerContextEnabledMethods, &V8EventTarget::wrapperTypeInfo, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace ApplicationCacheV8Internal {

template <typename T> void V8_USE(T) { }

static void statusAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->status());
}

static void statusAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::statusAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void oncheckingAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    EventListener* v8Value = impl->onchecking();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void oncheckingAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::oncheckingAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void oncheckingAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->onchecking(), v8Value, V8ApplicationCache::eventListenerCacheIndex, info.GetIsolate());
    impl->setOnchecking(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void oncheckingAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    ApplicationCacheV8Internal::oncheckingAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onerrorAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    EventListener* v8Value = impl->onerror();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void onerrorAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::onerrorAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onerrorAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->onerror(), v8Value, V8ApplicationCache::eventListenerCacheIndex, info.GetIsolate());
    impl->setOnerror(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void onerrorAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    ApplicationCacheV8Internal::onerrorAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onnoupdateAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    EventListener* v8Value = impl->onnoupdate();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void onnoupdateAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::onnoupdateAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onnoupdateAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->onnoupdate(), v8Value, V8ApplicationCache::eventListenerCacheIndex, info.GetIsolate());
    impl->setOnnoupdate(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void onnoupdateAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    ApplicationCacheV8Internal::onnoupdateAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void ondownloadingAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    EventListener* v8Value = impl->ondownloading();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void ondownloadingAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::ondownloadingAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void ondownloadingAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->ondownloading(), v8Value, V8ApplicationCache::eventListenerCacheIndex, info.GetIsolate());
    impl->setOndownloading(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void ondownloadingAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    ApplicationCacheV8Internal::ondownloadingAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onprogressAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    EventListener* v8Value = impl->onprogress();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void onprogressAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::onprogressAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onprogressAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->onprogress(), v8Value, V8ApplicationCache::eventListenerCacheIndex, info.GetIsolate());
    impl->setOnprogress(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void onprogressAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    ApplicationCacheV8Internal::onprogressAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onupdatereadyAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    EventListener* v8Value = impl->onupdateready();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void onupdatereadyAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::onupdatereadyAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onupdatereadyAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->onupdateready(), v8Value, V8ApplicationCache::eventListenerCacheIndex, info.GetIsolate());
    impl->setOnupdateready(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void onupdatereadyAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    ApplicationCacheV8Internal::onupdatereadyAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void oncachedAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    EventListener* v8Value = impl->oncached();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void oncachedAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::oncachedAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void oncachedAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->oncached(), v8Value, V8ApplicationCache::eventListenerCacheIndex, info.GetIsolate());
    impl->setOncached(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void oncachedAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    ApplicationCacheV8Internal::oncachedAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onobsoleteAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    EventListener* v8Value = impl->onobsolete();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void onobsoleteAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ApplicationCacheV8Internal::onobsoleteAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onobsoleteAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ApplicationCache* impl = V8ApplicationCache::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->onobsolete(), v8Value, V8ApplicationCache::eventListenerCacheIndex, info.GetIsolate());
    impl->setOnobsolete(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void onobsoleteAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    ApplicationCacheV8Internal::onobsoleteAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void updateMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "update", "ApplicationCache", info.Holder(), info.GetIsolate());
    ApplicationCache* impl = V8ApplicationCache::toNative(info.Holder());
    impl->update(exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void updateMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    ApplicationCacheV8Internal::updateMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void swapCacheMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "swapCache", "ApplicationCache", info.Holder(), info.GetIsolate());
    ApplicationCache* impl = V8ApplicationCache::toNative(info.Holder());
    impl->swapCache(exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void swapCacheMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    ApplicationCacheV8Internal::swapCacheMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void abortMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ApplicationCache* impl = V8ApplicationCache::toNative(info.Holder());
    impl->abort();
}

static void abortMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    ApplicationCacheV8Internal::abortMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace ApplicationCacheV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8ApplicationCacheAttributes[] = {
    {"status", ApplicationCacheV8Internal::statusAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"onchecking", ApplicationCacheV8Internal::oncheckingAttributeGetterCallback, ApplicationCacheV8Internal::oncheckingAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"onerror", ApplicationCacheV8Internal::onerrorAttributeGetterCallback, ApplicationCacheV8Internal::onerrorAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"onnoupdate", ApplicationCacheV8Internal::onnoupdateAttributeGetterCallback, ApplicationCacheV8Internal::onnoupdateAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"ondownloading", ApplicationCacheV8Internal::ondownloadingAttributeGetterCallback, ApplicationCacheV8Internal::ondownloadingAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"onprogress", ApplicationCacheV8Internal::onprogressAttributeGetterCallback, ApplicationCacheV8Internal::onprogressAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"onupdateready", ApplicationCacheV8Internal::onupdatereadyAttributeGetterCallback, ApplicationCacheV8Internal::onupdatereadyAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"oncached", ApplicationCacheV8Internal::oncachedAttributeGetterCallback, ApplicationCacheV8Internal::oncachedAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"onobsolete", ApplicationCacheV8Internal::onobsoleteAttributeGetterCallback, ApplicationCacheV8Internal::onobsoleteAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::MethodConfiguration V8ApplicationCacheMethods[] = {
    {"update", ApplicationCacheV8Internal::updateMethodCallback, 0, 0},
    {"swapCache", ApplicationCacheV8Internal::swapCacheMethodCallback, 0, 0},
    {"abort", ApplicationCacheV8Internal::abortMethodCallback, 0, 0},
};

static void configureV8ApplicationCacheTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "ApplicationCache", V8EventTarget::domTemplate(isolate), V8ApplicationCache::internalFieldCount,
        V8ApplicationCacheAttributes, WTF_ARRAY_LENGTH(V8ApplicationCacheAttributes),
        0, 0,
        V8ApplicationCacheMethods, WTF_ARRAY_LENGTH(V8ApplicationCacheMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();
    static const V8DOMConfiguration::ConstantConfiguration V8ApplicationCacheConstants[] = {
        {"UNCACHED", 0},
        {"IDLE", 1},
        {"CHECKING", 2},
        {"DOWNLOADING", 3},
        {"UPDATEREADY", 4},
        {"OBSOLETE", 5},
    };
    V8DOMConfiguration::installConstants(functionTemplate, prototypeTemplate, V8ApplicationCacheConstants, WTF_ARRAY_LENGTH(V8ApplicationCacheConstants), isolate);

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8ApplicationCache::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8ApplicationCacheTemplate);
}

bool V8ApplicationCache::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8ApplicationCache::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

ApplicationCache* V8ApplicationCache::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

EventTarget* V8ApplicationCache::toEventTarget(v8::Handle<v8::Object> object)
{
    return toNative(object);
}

v8::Handle<v8::Object> wrap(ApplicationCache* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8ApplicationCache>(impl, isolate));
    return V8ApplicationCache::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8ApplicationCache::createWrapper(PassRefPtrWillBeRawPtr<ApplicationCache> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8ApplicationCache>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8ApplicationCache>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8ApplicationCache::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(ApplicationCache* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

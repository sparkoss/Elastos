// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8RTCDTMFSender.h"

#include "bindings/modules/v8/V8MediaStreamTrack.h"
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

static void initializeScriptWrappableForInterface(RTCDTMFSender* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8RTCDTMFSender::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::RTCDTMFSender* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8RTCDTMFSender::wrapperTypeInfo = { gin::kEmbedderBlink, V8RTCDTMFSender::domTemplate, V8RTCDTMFSender::derefObject, V8RTCDTMFSender::toActiveDOMObject, V8RTCDTMFSender::toEventTarget, 0, V8RTCDTMFSender::installPerContextEnabledMethods, &V8EventTarget::wrapperTypeInfo, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace RTCDTMFSenderV8Internal {

template <typename T> void V8_USE(T) { }

static void canInsertDTMFAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    RTCDTMFSender* impl = V8RTCDTMFSender::toNative(holder);
    v8SetReturnValueBool(info, impl->canInsertDTMF());
}

static void canInsertDTMFAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    RTCDTMFSenderV8Internal::canInsertDTMFAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void trackAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    RTCDTMFSender* impl = V8RTCDTMFSender::toNative(holder);
    RefPtrWillBeRawPtr<MediaStreamTrack> result(impl->track());
    if (result && DOMDataStore::setReturnValueFromWrapper<V8MediaStreamTrack>(info.GetReturnValue(), result.get()))
        return;
    v8::Handle<v8::Value> wrapper = toV8(result.get(), holder, info.GetIsolate());
    if (!wrapper.IsEmpty()) {
        V8HiddenValue::setHiddenValue(info.GetIsolate(), holder, v8AtomicString(info.GetIsolate(), "track"), wrapper);
        v8SetReturnValue(info, wrapper);
    }
}

static void trackAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    RTCDTMFSenderV8Internal::trackAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void toneBufferAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    RTCDTMFSender* impl = V8RTCDTMFSender::toNative(holder);
    v8SetReturnValueString(info, impl->toneBuffer(), info.GetIsolate());
}

static void toneBufferAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    RTCDTMFSenderV8Internal::toneBufferAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void durationAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    RTCDTMFSender* impl = V8RTCDTMFSender::toNative(holder);
    v8SetReturnValueInt(info, impl->duration());
}

static void durationAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    RTCDTMFSenderV8Internal::durationAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void interToneGapAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    RTCDTMFSender* impl = V8RTCDTMFSender::toNative(holder);
    v8SetReturnValueInt(info, impl->interToneGap());
}

static void interToneGapAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    RTCDTMFSenderV8Internal::interToneGapAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void ontonechangeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    RTCDTMFSender* impl = V8RTCDTMFSender::toNative(holder);
    EventListener* v8Value = impl->ontonechange();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void ontonechangeAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    RTCDTMFSenderV8Internal::ontonechangeAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void ontonechangeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    RTCDTMFSender* impl = V8RTCDTMFSender::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->ontonechange(), v8Value, V8RTCDTMFSender::eventListenerCacheIndex, info.GetIsolate());
    impl->setOntonechange(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void ontonechangeAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    RTCDTMFSenderV8Internal::ontonechangeAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void insertDTMFMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "insertDTMF", "RTCDTMFSender", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    RTCDTMFSender* impl = V8RTCDTMFSender::toNative(info.Holder());
    V8StringResource<> tones;
    int duration;
    int interToneGap;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TOSTRING_VOID_INTERNAL(tones, info[0]);
        if (UNLIKELY(info.Length() <= 1)) {
            impl->insertDTMF(tones, exceptionState);
            if (exceptionState.hadException()) {
                exceptionState.throwIfNeeded();
                return;
            }
            return;
        }
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(duration, toInt32(info[1], exceptionState), exceptionState);
        if (UNLIKELY(info.Length() <= 2)) {
            impl->insertDTMF(tones, duration, exceptionState);
            if (exceptionState.hadException()) {
                exceptionState.throwIfNeeded();
                return;
            }
            return;
        }
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(interToneGap, toInt32(info[2], exceptionState), exceptionState);
    }
    impl->insertDTMF(tones, duration, interToneGap, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void insertDTMFMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    RTCDTMFSenderV8Internal::insertDTMFMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace RTCDTMFSenderV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8RTCDTMFSenderAttributes[] = {
    {"canInsertDTMF", RTCDTMFSenderV8Internal::canInsertDTMFAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"track", RTCDTMFSenderV8Internal::trackAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"toneBuffer", RTCDTMFSenderV8Internal::toneBufferAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"duration", RTCDTMFSenderV8Internal::durationAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"interToneGap", RTCDTMFSenderV8Internal::interToneGapAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"ontonechange", RTCDTMFSenderV8Internal::ontonechangeAttributeGetterCallback, RTCDTMFSenderV8Internal::ontonechangeAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::MethodConfiguration V8RTCDTMFSenderMethods[] = {
    {"insertDTMF", RTCDTMFSenderV8Internal::insertDTMFMethodCallback, 0, 1},
};

static void configureV8RTCDTMFSenderTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "RTCDTMFSender", V8EventTarget::domTemplate(isolate), V8RTCDTMFSender::internalFieldCount,
        V8RTCDTMFSenderAttributes, WTF_ARRAY_LENGTH(V8RTCDTMFSenderAttributes),
        0, 0,
        V8RTCDTMFSenderMethods, WTF_ARRAY_LENGTH(V8RTCDTMFSenderMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8RTCDTMFSender::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8RTCDTMFSenderTemplate);
}

bool V8RTCDTMFSender::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8RTCDTMFSender::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

RTCDTMFSender* V8RTCDTMFSender::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

ActiveDOMObject* V8RTCDTMFSender::toActiveDOMObject(v8::Handle<v8::Object> wrapper)
{
    return toNative(wrapper);
}

EventTarget* V8RTCDTMFSender::toEventTarget(v8::Handle<v8::Object> object)
{
    return toNative(object);
}

v8::Handle<v8::Object> wrap(RTCDTMFSender* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8RTCDTMFSender>(impl, isolate));
    return V8RTCDTMFSender::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8RTCDTMFSender::createWrapper(PassRefPtrWillBeRawPtr<RTCDTMFSender> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8RTCDTMFSender>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8RTCDTMFSender>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Dependent);
    return wrapper;
}

void V8RTCDTMFSender::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(RTCDTMFSender* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

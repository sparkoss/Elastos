// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8Timing.h"

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

static void initializeScriptWrappableForInterface(AnimationNodeTiming* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8Timing::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::AnimationNodeTiming* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8Timing::wrapperTypeInfo = { gin::kEmbedderBlink, V8Timing::domTemplate, V8Timing::derefObject, 0, 0, 0, V8Timing::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace AnimationNodeTimingV8Internal {

template <typename T> void V8_USE(T) { }

static void delayAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    v8SetReturnValue(info, impl->delay());
}

static void delayAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AnimationNodeTimingV8Internal::delayAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void delayAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    TONATIVE_VOID(double, cppValue, static_cast<double>(v8Value->NumberValue()));
    impl->setDelay(cppValue);
}

static void delayAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AnimationNodeTimingV8Internal::delayAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void endDelayAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    v8SetReturnValue(info, impl->endDelay());
}

static void endDelayAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AnimationNodeTimingV8Internal::endDelayAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void endDelayAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    TONATIVE_VOID(double, cppValue, static_cast<double>(v8Value->NumberValue()));
    impl->setEndDelay(cppValue);
}

static void endDelayAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AnimationNodeTimingV8Internal::endDelayAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void fillAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    v8SetReturnValueString(info, impl->fill(), info.GetIsolate());
}

static void fillAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AnimationNodeTimingV8Internal::fillAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void fillAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setFill(cppValue);
}

static void fillAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AnimationNodeTimingV8Internal::fillAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void iterationStartAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    v8SetReturnValue(info, impl->iterationStart());
}

static void iterationStartAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AnimationNodeTimingV8Internal::iterationStartAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void iterationStartAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    TONATIVE_VOID(double, cppValue, static_cast<double>(v8Value->NumberValue()));
    impl->setIterationStart(cppValue);
}

static void iterationStartAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AnimationNodeTimingV8Internal::iterationStartAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void iterationsAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    v8SetReturnValue(info, impl->iterations());
}

static void iterationsAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AnimationNodeTimingV8Internal::iterationsAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void iterationsAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    TONATIVE_VOID(double, cppValue, static_cast<double>(v8Value->NumberValue()));
    impl->setIterations(cppValue);
}

static void iterationsAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AnimationNodeTimingV8Internal::iterationsAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void playbackRateAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    v8SetReturnValue(info, impl->playbackRate());
}

static void playbackRateAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AnimationNodeTimingV8Internal::playbackRateAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void playbackRateAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    TONATIVE_VOID(double, cppValue, static_cast<double>(v8Value->NumberValue()));
    impl->setPlaybackRate(cppValue);
}

static void playbackRateAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AnimationNodeTimingV8Internal::playbackRateAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void directionAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    v8SetReturnValueString(info, impl->direction(), info.GetIsolate());
}

static void directionAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AnimationNodeTimingV8Internal::directionAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void directionAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setDirection(cppValue);
}

static void directionAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AnimationNodeTimingV8Internal::directionAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void easingAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    v8SetReturnValueString(info, impl->easing(), info.GetIsolate());
}

static void easingAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    AnimationNodeTimingV8Internal::easingAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void easingAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    AnimationNodeTiming* impl = V8Timing::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setEasing(cppValue);
}

static void easingAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    AnimationNodeTimingV8Internal::easingAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void namedPropertyGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    if (info.Holder()->HasRealNamedProperty(name))
        return;
    if (!info.Holder()->GetRealNamedPropertyInPrototypeChain(name).IsEmpty())
        return;

    AnimationNodeTiming* impl = V8Timing::toNative(info.Holder());
    AtomicString propertyName = toCoreAtomicString(name);
    bool result0Enabled = false;
    double result0;
    bool result1Enabled = false;
    String result1;
    impl->getDuration(propertyName, result0Enabled, result0, result1Enabled, result1);
    if (!result0Enabled && !result1Enabled)
        return;
    if (result0Enabled) {
        v8SetReturnValue(info, result0);
        return;
    }
    if (result1Enabled) {
        v8SetReturnValueString(info, result1, info.GetIsolate());
        return;
    }
    v8SetReturnValueNull(info);
}

static void namedPropertyGetterCallback(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMNamedProperty");
    AnimationNodeTimingV8Internal::namedPropertyGetter(name, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void namedPropertySetter(v8::Local<v8::String> name, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    if (info.Holder()->HasRealNamedProperty(name))
        return;
    if (!info.Holder()->GetRealNamedPropertyInPrototypeChain(name).IsEmpty())
        return;

    AnimationNodeTiming* impl = V8Timing::toNative(info.Holder());
    TOSTRING_VOID(V8StringResource<>, propertyName, name);
    TONATIVE_VOID(double, propertyValue, static_cast<double>(v8Value->NumberValue()));
    bool result = impl->setDuration(propertyName, propertyValue);
    if (!result)
        return;
    v8SetReturnValue(info, v8Value);
}

static void namedPropertySetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMNamedProperty");
    AnimationNodeTimingV8Internal::namedPropertySetter(name, v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace AnimationNodeTimingV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8TimingAttributes[] = {
    {"delay", AnimationNodeTimingV8Internal::delayAttributeGetterCallback, AnimationNodeTimingV8Internal::delayAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"endDelay", AnimationNodeTimingV8Internal::endDelayAttributeGetterCallback, AnimationNodeTimingV8Internal::endDelayAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"fill", AnimationNodeTimingV8Internal::fillAttributeGetterCallback, AnimationNodeTimingV8Internal::fillAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"iterationStart", AnimationNodeTimingV8Internal::iterationStartAttributeGetterCallback, AnimationNodeTimingV8Internal::iterationStartAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"iterations", AnimationNodeTimingV8Internal::iterationsAttributeGetterCallback, AnimationNodeTimingV8Internal::iterationsAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"playbackRate", AnimationNodeTimingV8Internal::playbackRateAttributeGetterCallback, AnimationNodeTimingV8Internal::playbackRateAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"direction", AnimationNodeTimingV8Internal::directionAttributeGetterCallback, AnimationNodeTimingV8Internal::directionAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"easing", AnimationNodeTimingV8Internal::easingAttributeGetterCallback, AnimationNodeTimingV8Internal::easingAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static void configureV8TimingTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    if (!RuntimeEnabledFeatures::webAnimationsAPIEnabled())
        defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "", v8::Local<v8::FunctionTemplate>(), V8Timing::internalFieldCount, 0, 0, 0, 0, 0, 0, isolate);
    else
        defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "Timing", v8::Local<v8::FunctionTemplate>(), V8Timing::internalFieldCount,
            V8TimingAttributes, WTF_ARRAY_LENGTH(V8TimingAttributes),
            0, 0,
            0, 0,
            isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();
    functionTemplate->InstanceTemplate()->SetNamedPropertyHandler(AnimationNodeTimingV8Internal::namedPropertyGetterCallback, AnimationNodeTimingV8Internal::namedPropertySetterCallback, 0, 0, 0);

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8Timing::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8TimingTemplate);
}

bool V8Timing::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8Timing::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

AnimationNodeTiming* V8Timing::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(AnimationNodeTiming* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8Timing>(impl, isolate));
    return V8Timing::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8Timing::createWrapper(PassRefPtrWillBeRawPtr<AnimationNodeTiming> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8Timing>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8Timing>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8Timing::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(AnimationNodeTiming* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

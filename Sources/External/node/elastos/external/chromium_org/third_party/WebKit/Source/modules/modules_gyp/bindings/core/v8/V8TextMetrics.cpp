// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8TextMetrics.h"

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

static void initializeScriptWrappableForInterface(TextMetrics* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8TextMetrics::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::TextMetrics* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8TextMetrics::wrapperTypeInfo = { gin::kEmbedderBlink, V8TextMetrics::domTemplate, V8TextMetrics::derefObject, 0, 0, 0, V8TextMetrics::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, RefCountedObject };

namespace TextMetricsV8Internal {

template <typename T> void V8_USE(T) { }

static void widthAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->width());
}

static void widthAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::widthAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void actualBoundingBoxLeftAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->actualBoundingBoxLeft());
}

static void actualBoundingBoxLeftAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::actualBoundingBoxLeftAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void actualBoundingBoxRightAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->actualBoundingBoxRight());
}

static void actualBoundingBoxRightAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::actualBoundingBoxRightAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void fontBoundingBoxAscentAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->fontBoundingBoxAscent());
}

static void fontBoundingBoxAscentAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::fontBoundingBoxAscentAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void fontBoundingBoxDescentAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->fontBoundingBoxDescent());
}

static void fontBoundingBoxDescentAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::fontBoundingBoxDescentAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void actualBoundingBoxAscentAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->actualBoundingBoxAscent());
}

static void actualBoundingBoxAscentAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::actualBoundingBoxAscentAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void actualBoundingBoxDescentAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->actualBoundingBoxDescent());
}

static void actualBoundingBoxDescentAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::actualBoundingBoxDescentAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void emHeightAscentAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->emHeightAscent());
}

static void emHeightAscentAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::emHeightAscentAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void emHeightDescentAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->emHeightDescent());
}

static void emHeightDescentAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::emHeightDescentAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void hangingBaselineAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->hangingBaseline());
}

static void hangingBaselineAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::hangingBaselineAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void alphabeticBaselineAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->alphabeticBaseline());
}

static void alphabeticBaselineAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::alphabeticBaselineAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void ideographicBaselineAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TextMetrics* impl = V8TextMetrics::toNative(holder);
    v8SetReturnValue(info, impl->ideographicBaseline());
}

static void ideographicBaselineAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TextMetricsV8Internal::ideographicBaselineAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace TextMetricsV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8TextMetricsAttributes[] = {
    {"width", TextMetricsV8Internal::widthAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static void configureV8TextMetricsTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "TextMetrics", v8::Local<v8::FunctionTemplate>(), V8TextMetrics::internalFieldCount,
        V8TextMetricsAttributes, WTF_ARRAY_LENGTH(V8TextMetricsAttributes),
        0, 0,
        0, 0,
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"actualBoundingBoxLeft", TextMetricsV8Internal::actualBoundingBoxLeftAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"actualBoundingBoxRight", TextMetricsV8Internal::actualBoundingBoxRightAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"fontBoundingBoxAscent", TextMetricsV8Internal::fontBoundingBoxAscentAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"fontBoundingBoxDescent", TextMetricsV8Internal::fontBoundingBoxDescentAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"actualBoundingBoxAscent", TextMetricsV8Internal::actualBoundingBoxAscentAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"actualBoundingBoxDescent", TextMetricsV8Internal::actualBoundingBoxDescentAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"emHeightAscent", TextMetricsV8Internal::emHeightAscentAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"emHeightDescent", TextMetricsV8Internal::emHeightDescentAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"hangingBaseline", TextMetricsV8Internal::hangingBaselineAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"alphabeticBaseline", TextMetricsV8Internal::alphabeticBaselineAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"ideographicBaseline", TextMetricsV8Internal::ideographicBaselineAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8TextMetrics::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8TextMetricsTemplate);
}

bool V8TextMetrics::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8TextMetrics::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TextMetrics* V8TextMetrics::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(TextMetrics* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8TextMetrics>(impl, isolate));
    return V8TextMetrics::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8TextMetrics::createWrapper(PassRefPtr<TextMetrics> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8TextMetrics>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8TextMetrics>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8TextMetrics::derefObject(void* object)
{
    fromInternalPointer(object)->deref();
}

template<>
v8::Handle<v8::Value> toV8NoInline(TextMetrics* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

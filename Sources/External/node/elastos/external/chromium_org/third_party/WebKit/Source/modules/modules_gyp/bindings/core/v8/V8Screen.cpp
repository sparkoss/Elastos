// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8Screen.h"

#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/ScriptPromise.h"
#include "bindings/v8/ScriptState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "modules/screen_orientation/ScreenOrientation.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(Screen* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8Screen::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::Screen* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8Screen::wrapperTypeInfo = { gin::kEmbedderBlink, V8Screen::domTemplate, V8Screen::derefObject, 0, 0, 0, V8Screen::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace ScreenV8Internal {

template <typename T> void V8_USE(T) { }

static void heightAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->height());
}

static void heightAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::heightAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void widthAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->width());
}

static void widthAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::widthAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void colorDepthAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->colorDepth());
}

static void colorDepthAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::colorDepthAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void pixelDepthAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->pixelDepth());
}

static void pixelDepthAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::pixelDepthAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void availLeftAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueInt(info, impl->availLeft());
}

static void availLeftAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::availLeftAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void availTopAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueInt(info, impl->availTop());
}

static void availTopAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::availTopAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void availHeightAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->availHeight());
}

static void availHeightAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::availHeightAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void availWidthAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueUnsigned(info, impl->availWidth());
}

static void availWidthAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::availWidthAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void orientationAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Screen* impl = V8Screen::toNative(holder);
    v8SetReturnValueString(info, ScreenOrientation::orientation(*impl), info.GetIsolate());
}

static void orientationAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    ScreenV8Internal::orientationAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void lockOrientationMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("lockOrientation", "Screen", 1, info.Length(), info.GetIsolate());
        return;
    }
    Screen* impl = V8Screen::toNative(info.Holder());
    V8StringResource<> orientation;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TOSTRING_VOID_INTERNAL(orientation, info[0]);
        String string = orientation;
        if (!(string == "any" || string == "landscape" || string == "portrait" || string == "portrait-primary" || string == "portrait-secondary" || string == "landscape-primary" || string == "landscape-secondary")) {
            throwTypeError(ExceptionMessages::failedToExecute("lockOrientation", "Screen", "parameter 1 ('" + string + "') is not a valid enum value."), info.GetIsolate());
            return;
        }
    }
    ScriptState* scriptState = ScriptState::current(info.GetIsolate());
    ScriptPromise result = ScreenOrientation::lockOrientation(scriptState, *impl, orientation);
    v8SetReturnValue(info, result.v8Value());
}

static void lockOrientationMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    ScreenV8Internal::lockOrientationMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void unlockOrientationMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    Screen* impl = V8Screen::toNative(info.Holder());
    ScreenOrientation::unlockOrientation(*impl);
}

static void unlockOrientationMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    ScreenV8Internal::unlockOrientationMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace ScreenV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8ScreenAttributes[] = {
    {"height", ScreenV8Internal::heightAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"width", ScreenV8Internal::widthAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"colorDepth", ScreenV8Internal::colorDepthAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"pixelDepth", ScreenV8Internal::pixelDepthAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"availLeft", ScreenV8Internal::availLeftAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"availTop", ScreenV8Internal::availTopAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"availHeight", ScreenV8Internal::availHeightAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"availWidth", ScreenV8Internal::availWidthAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static void configureV8ScreenTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "Screen", v8::Local<v8::FunctionTemplate>(), V8Screen::internalFieldCount,
        V8ScreenAttributes, WTF_ARRAY_LENGTH(V8ScreenAttributes),
        0, 0,
        0, 0,
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();
    if (RuntimeEnabledFeatures::screenOrientationEnabled()) {
        static const V8DOMConfiguration::AttributeConfiguration attributeConfiguration =\
        {"orientation", ScreenV8Internal::orientationAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */};
        V8DOMConfiguration::installAttribute(instanceTemplate, prototypeTemplate, attributeConfiguration, isolate);
    }
    if (RuntimeEnabledFeatures::screenOrientationEnabled()) {
        prototypeTemplate->Set(v8AtomicString(isolate, "lockOrientation"), v8::FunctionTemplate::New(isolate, ScreenV8Internal::lockOrientationMethodCallback, v8Undefined(), defaultSignature, 1));
    }
    if (RuntimeEnabledFeatures::screenOrientationEnabled()) {
        prototypeTemplate->Set(v8AtomicString(isolate, "unlockOrientation"), v8::FunctionTemplate::New(isolate, ScreenV8Internal::unlockOrientationMethodCallback, v8Undefined(), defaultSignature, 0));
    }

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8Screen::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8ScreenTemplate);
}

bool V8Screen::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8Screen::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

Screen* V8Screen::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(Screen* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8Screen>(impl, isolate));
    return V8Screen::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8Screen::createWrapper(PassRefPtrWillBeRawPtr<Screen> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8Screen>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8Screen>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8Screen::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(Screen* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

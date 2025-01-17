// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8HTMLAppletElement.h"

#include "HTMLNames.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "core/dom/custom/CustomElementCallbackDispatcher.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(HTMLAppletElement* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8HTMLAppletElement::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::HTMLAppletElement* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8HTMLAppletElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLAppletElement::domTemplate, V8HTMLAppletElement::derefObject, 0, V8HTMLAppletElement::toEventTarget, 0, V8HTMLAppletElement::installPerContextEnabledMethods, &V8HTMLElement::wrapperTypeInfo, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace HTMLAppletElementV8Internal {

template <typename T> void V8_USE(T) { }

static void alignAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::alignAttr), info.GetIsolate());
}

static void alignAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::alignAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void alignAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::alignAttr, cppValue);
}

static void alignAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::alignAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void altAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::altAttr), info.GetIsolate());
}

static void altAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::altAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void altAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::altAttr, cppValue);
}

static void altAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::altAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void archiveAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::archiveAttr), info.GetIsolate());
}

static void archiveAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::archiveAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void archiveAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::archiveAttr, cppValue);
}

static void archiveAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::archiveAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void codeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::codeAttr), info.GetIsolate());
}

static void codeAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::codeAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void codeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::codeAttr, cppValue);
}

static void codeAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::codeAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void codeBaseAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    HTMLAppletElement* impl = V8HTMLAppletElement::toNative(holder);
    v8SetReturnValueString(info, impl->getURLAttribute(HTMLNames::codebaseAttr), info.GetIsolate());
}

static void codeBaseAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::codeBaseAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void codeBaseAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::codebaseAttr, cppValue);
}

static void codeBaseAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::codeBaseAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void heightAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::heightAttr), info.GetIsolate());
}

static void heightAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::heightAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void heightAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::heightAttr, cppValue);
}

static void heightAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::heightAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void hspaceAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    HTMLAppletElement* impl = V8HTMLAppletElement::toNative(holder);
    v8SetReturnValueUnsigned(info, std::max(0, impl->getIntegralAttribute(HTMLNames::hspaceAttr)));
}

static void hspaceAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::hspaceAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void hspaceAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ExceptionState exceptionState(ExceptionState::SetterContext, "hspace", "HTMLAppletElement", holder, info.GetIsolate());
    HTMLAppletElement* impl = V8HTMLAppletElement::toNative(holder);
    TONATIVE_VOID_EXCEPTIONSTATE(unsigned, cppValue, toUInt32(v8Value, exceptionState), exceptionState);
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    impl->setUnsignedIntegralAttribute(HTMLNames::hspaceAttr, cppValue);
}

static void hspaceAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::hspaceAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void nameAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    v8SetReturnValueString(info, impl->getNameAttribute(), info.GetIsolate());
}

static void nameAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::nameAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void nameAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::nameAttr, cppValue);
}

static void nameAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::nameAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void objectAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    HTMLAppletElement* impl = V8HTMLAppletElement::toNative(holder);
    v8SetReturnValueString(info, impl->getURLAttribute(HTMLNames::objectAttr), info.GetIsolate());
}

static void objectAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::objectAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void objectAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::objectAttr, cppValue);
}

static void objectAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::objectAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void vspaceAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    HTMLAppletElement* impl = V8HTMLAppletElement::toNative(holder);
    v8SetReturnValueUnsigned(info, std::max(0, impl->getIntegralAttribute(HTMLNames::vspaceAttr)));
}

static void vspaceAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::vspaceAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void vspaceAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    ExceptionState exceptionState(ExceptionState::SetterContext, "vspace", "HTMLAppletElement", holder, info.GetIsolate());
    HTMLAppletElement* impl = V8HTMLAppletElement::toNative(holder);
    TONATIVE_VOID_EXCEPTIONSTATE(unsigned, cppValue, toUInt32(v8Value, exceptionState), exceptionState);
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    impl->setUnsignedIntegralAttribute(HTMLNames::vspaceAttr, cppValue);
}

static void vspaceAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::vspaceAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void widthAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::widthAttr), info.GetIsolate());
}

static void widthAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    HTMLAppletElementV8Internal::widthAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void widthAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Element* impl = V8Element::toNative(holder);
    TOSTRING_VOID(V8StringResource<>, cppValue, v8Value);
    impl->setAttribute(HTMLNames::widthAttr, cppValue);
}

static void widthAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    CustomElementCallbackDispatcher::CallbackDeliveryScope deliveryScope;
    HTMLAppletElementV8Internal::widthAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void indexedPropertyGetterCallback(uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMIndexedProperty");
    V8HTMLAppletElement::indexedPropertyGetterCustom(index, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void indexedPropertySetterCallback(uint32_t index, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMIndexedProperty");
    V8HTMLAppletElement::indexedPropertySetterCustom(index, v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void namedPropertyGetterCallback(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMNamedProperty");
    V8HTMLAppletElement::namedPropertyGetterCustom(name, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void namedPropertySetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMNamedProperty");
    V8HTMLAppletElement::namedPropertySetterCustom(name, v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace HTMLAppletElementV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8HTMLAppletElementAttributes[] = {
    {"align", HTMLAppletElementV8Internal::alignAttributeGetterCallback, HTMLAppletElementV8Internal::alignAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"alt", HTMLAppletElementV8Internal::altAttributeGetterCallback, HTMLAppletElementV8Internal::altAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"archive", HTMLAppletElementV8Internal::archiveAttributeGetterCallback, HTMLAppletElementV8Internal::archiveAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"code", HTMLAppletElementV8Internal::codeAttributeGetterCallback, HTMLAppletElementV8Internal::codeAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"codeBase", HTMLAppletElementV8Internal::codeBaseAttributeGetterCallback, HTMLAppletElementV8Internal::codeBaseAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"height", HTMLAppletElementV8Internal::heightAttributeGetterCallback, HTMLAppletElementV8Internal::heightAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"hspace", HTMLAppletElementV8Internal::hspaceAttributeGetterCallback, HTMLAppletElementV8Internal::hspaceAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"name", HTMLAppletElementV8Internal::nameAttributeGetterCallback, HTMLAppletElementV8Internal::nameAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"object", HTMLAppletElementV8Internal::objectAttributeGetterCallback, HTMLAppletElementV8Internal::objectAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"vspace", HTMLAppletElementV8Internal::vspaceAttributeGetterCallback, HTMLAppletElementV8Internal::vspaceAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"width", HTMLAppletElementV8Internal::widthAttributeGetterCallback, HTMLAppletElementV8Internal::widthAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static void configureV8HTMLAppletElementTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "HTMLAppletElement", V8HTMLElement::domTemplate(isolate), V8HTMLAppletElement::internalFieldCount,
        V8HTMLAppletElementAttributes, WTF_ARRAY_LENGTH(V8HTMLAppletElementAttributes),
        0, 0,
        0, 0,
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();
    functionTemplate->InstanceTemplate()->SetIndexedPropertyHandler(HTMLAppletElementV8Internal::indexedPropertyGetterCallback, HTMLAppletElementV8Internal::indexedPropertySetterCallback, 0, 0, 0);
    functionTemplate->InstanceTemplate()->SetNamedPropertyHandler(HTMLAppletElementV8Internal::namedPropertyGetterCallback, HTMLAppletElementV8Internal::namedPropertySetterCallback, 0, 0, 0);
    functionTemplate->InstanceTemplate()->SetCallAsFunctionHandler(V8HTMLAppletElement::legacyCallCustom);

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8HTMLAppletElement::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8HTMLAppletElementTemplate);
}

bool V8HTMLAppletElement::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8HTMLAppletElement::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLAppletElement* V8HTMLAppletElement::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

EventTarget* V8HTMLAppletElement::toEventTarget(v8::Handle<v8::Object> object)
{
    return toNative(object);
}

v8::Handle<v8::Object> wrap(HTMLAppletElement* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8HTMLAppletElement>(impl, isolate));
    return V8HTMLAppletElement::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8HTMLAppletElement::createWrapper(PassRefPtrWillBeRawPtr<HTMLAppletElement> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8HTMLAppletElement>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8HTMLAppletElement>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Dependent);
    return wrapper;
}

void V8HTMLAppletElement::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(HTMLAppletElement* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

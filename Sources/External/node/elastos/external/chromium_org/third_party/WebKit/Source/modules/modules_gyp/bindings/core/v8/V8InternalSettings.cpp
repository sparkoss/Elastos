// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8InternalSettings.h"

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

static void initializeScriptWrappableForInterface(InternalSettings* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8InternalSettings::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::InternalSettings* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8InternalSettings::wrapperTypeInfo = { gin::kEmbedderBlink, V8InternalSettings::domTemplate, V8InternalSettings::derefObject, 0, 0, 0, V8InternalSettings::installPerContextEnabledMethods, &V8InternalSettingsGenerated::wrapperTypeInfo, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace InternalSettingsV8Internal {

template <typename T> void V8_USE(T) { }

static void setMockScrollbarsEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setMockScrollbarsEnabled", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setMockScrollbarsEnabled(enabled, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setMockScrollbarsEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setMockScrollbarsEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setStandardFontFamilyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setStandardFontFamily", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeError(exceptionState, 2, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> family;
    V8StringResource<> script;
    {
        TOSTRING_VOID_INTERNAL(family, info[0]);
        TOSTRING_VOID_INTERNAL(script, info[1]);
    }
    impl->setStandardFontFamily(family, script, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setStandardFontFamilyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setStandardFontFamilyMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setSerifFontFamilyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setSerifFontFamily", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeError(exceptionState, 2, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> family;
    V8StringResource<> script;
    {
        TOSTRING_VOID_INTERNAL(family, info[0]);
        TOSTRING_VOID_INTERNAL(script, info[1]);
    }
    impl->setSerifFontFamily(family, script, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setSerifFontFamilyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setSerifFontFamilyMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setSansSerifFontFamilyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setSansSerifFontFamily", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeError(exceptionState, 2, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> family;
    V8StringResource<> script;
    {
        TOSTRING_VOID_INTERNAL(family, info[0]);
        TOSTRING_VOID_INTERNAL(script, info[1]);
    }
    impl->setSansSerifFontFamily(family, script, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setSansSerifFontFamilyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setSansSerifFontFamilyMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setFixedFontFamilyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setFixedFontFamily", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeError(exceptionState, 2, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> family;
    V8StringResource<> script;
    {
        TOSTRING_VOID_INTERNAL(family, info[0]);
        TOSTRING_VOID_INTERNAL(script, info[1]);
    }
    impl->setFixedFontFamily(family, script, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setFixedFontFamilyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setFixedFontFamilyMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setCursiveFontFamilyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setCursiveFontFamily", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeError(exceptionState, 2, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> family;
    V8StringResource<> script;
    {
        TOSTRING_VOID_INTERNAL(family, info[0]);
        TOSTRING_VOID_INTERNAL(script, info[1]);
    }
    impl->setCursiveFontFamily(family, script, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setCursiveFontFamilyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setCursiveFontFamilyMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setFantasyFontFamilyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setFantasyFontFamily", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeError(exceptionState, 2, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> family;
    V8StringResource<> script;
    {
        TOSTRING_VOID_INTERNAL(family, info[0]);
        TOSTRING_VOID_INTERNAL(script, info[1]);
    }
    impl->setFantasyFontFamily(family, script, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setFantasyFontFamilyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setFantasyFontFamilyMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setPictographFontFamilyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setPictographFontFamily", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeError(exceptionState, 2, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> family;
    V8StringResource<> script;
    {
        TOSTRING_VOID_INTERNAL(family, info[0]);
        TOSTRING_VOID_INTERNAL(script, info[1]);
    }
    impl->setPictographFontFamily(family, script, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setPictographFontFamilyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setPictographFontFamilyMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setTextAutosizingEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setTextAutosizingEnabled", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setTextAutosizingEnabled(enabled, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setTextAutosizingEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setTextAutosizingEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setTextAutosizingWindowSizeOverrideMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setTextAutosizingWindowSizeOverride", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeError(exceptionState, 2, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    int width;
    int height;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(width, toInt32(info[0], exceptionState), exceptionState);
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(height, toInt32(info[1], exceptionState), exceptionState);
    }
    impl->setTextAutosizingWindowSizeOverride(width, height, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setTextAutosizingWindowSizeOverrideMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setTextAutosizingWindowSizeOverrideMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setAccessibilityFontScaleFactorMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setAccessibilityFontScaleFactor", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    float fontScaleFactor;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(fontScaleFactor, static_cast<float>(info[0]->NumberValue()));
    }
    impl->setAccessibilityFontScaleFactor(fontScaleFactor, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setAccessibilityFontScaleFactorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setAccessibilityFontScaleFactorMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setMediaTypeOverrideMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setMediaTypeOverride", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> mediaTypeOverride;
    {
        TOSTRING_VOID_INTERNAL(mediaTypeOverride, info[0]);
    }
    impl->setMediaTypeOverride(mediaTypeOverride, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setMediaTypeOverrideMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setMediaTypeOverrideMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setEditingBehaviorMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setEditingBehavior", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> behavior;
    {
        TOSTRING_VOID_INTERNAL(behavior, info[0]);
    }
    impl->setEditingBehavior(behavior, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setEditingBehaviorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setEditingBehaviorMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setImagesEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setImagesEnabled", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setImagesEnabled(enabled, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setImagesEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setImagesEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setDefaultVideoPosterURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setDefaultVideoPosterURL", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    V8StringResource<> poster;
    {
        TOSTRING_VOID_INTERNAL(poster, info[0]);
    }
    impl->setDefaultVideoPosterURL(poster, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setDefaultVideoPosterURLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setDefaultVideoPosterURLMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setViewportEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setViewportEnabled", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setViewportEnabled(enabled, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setViewportEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setViewportEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setLayerSquashingEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "setLayerSquashingEnabled", "InternalSettings", info.Holder(), info.GetIsolate());
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setLayerSquashingEnabled(enabled, exceptionState);
    if (exceptionState.hadException()) {
        exceptionState.throwIfNeeded();
        return;
    }
}

static void setLayerSquashingEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setLayerSquashingEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setAuthorShadowDOMForAnyElementEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("setAuthorShadowDOMForAnyElementEnabled", "InternalSettings", 1, info.Length(), info.GetIsolate());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setAuthorShadowDOMForAnyElementEnabled(enabled);
}

static void setAuthorShadowDOMForAnyElementEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setAuthorShadowDOMForAnyElementEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setCSSExclusionsEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("setCSSExclusionsEnabled", "InternalSettings", 1, info.Length(), info.GetIsolate());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setCSSExclusionsEnabled(enabled);
}

static void setCSSExclusionsEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setCSSExclusionsEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setLangAttributeAwareFormControlUIEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("setLangAttributeAwareFormControlUIEnabled", "InternalSettings", 1, info.Length(), info.GetIsolate());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setLangAttributeAwareFormControlUIEnabled(enabled);
}

static void setLangAttributeAwareFormControlUIEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setLangAttributeAwareFormControlUIEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setOverlayScrollbarsEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("setOverlayScrollbarsEnabled", "InternalSettings", 1, info.Length(), info.GetIsolate());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setOverlayScrollbarsEnabled(enabled);
}

static void setOverlayScrollbarsEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setOverlayScrollbarsEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setExperimentalContentSecurityPolicyFeaturesEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("setExperimentalContentSecurityPolicyFeaturesEnabled", "InternalSettings", 1, info.Length(), info.GetIsolate());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setExperimentalContentSecurityPolicyFeaturesEnabled(enabled);
}

static void setExperimentalContentSecurityPolicyFeaturesEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setExperimentalContentSecurityPolicyFeaturesEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void setPseudoClassesInMatchingCriteriaInAuthorShadowTreesEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("setPseudoClassesInMatchingCriteriaInAuthorShadowTreesEnabled", "InternalSettings", 1, info.Length(), info.GetIsolate());
        return;
    }
    InternalSettings* impl = V8InternalSettings::toNative(info.Holder());
    bool enabled;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(enabled, info[0]->BooleanValue());
    }
    impl->setPseudoClassesInMatchingCriteriaInAuthorShadowTreesEnabled(enabled);
}

static void setPseudoClassesInMatchingCriteriaInAuthorShadowTreesEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    InternalSettingsV8Internal::setPseudoClassesInMatchingCriteriaInAuthorShadowTreesEnabledMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace InternalSettingsV8Internal

static const V8DOMConfiguration::MethodConfiguration V8InternalSettingsMethods[] = {
    {"setMockScrollbarsEnabled", InternalSettingsV8Internal::setMockScrollbarsEnabledMethodCallback, 0, 1},
    {"setStandardFontFamily", InternalSettingsV8Internal::setStandardFontFamilyMethodCallback, 0, 2},
    {"setSerifFontFamily", InternalSettingsV8Internal::setSerifFontFamilyMethodCallback, 0, 2},
    {"setSansSerifFontFamily", InternalSettingsV8Internal::setSansSerifFontFamilyMethodCallback, 0, 2},
    {"setFixedFontFamily", InternalSettingsV8Internal::setFixedFontFamilyMethodCallback, 0, 2},
    {"setCursiveFontFamily", InternalSettingsV8Internal::setCursiveFontFamilyMethodCallback, 0, 2},
    {"setFantasyFontFamily", InternalSettingsV8Internal::setFantasyFontFamilyMethodCallback, 0, 2},
    {"setPictographFontFamily", InternalSettingsV8Internal::setPictographFontFamilyMethodCallback, 0, 2},
    {"setTextAutosizingEnabled", InternalSettingsV8Internal::setTextAutosizingEnabledMethodCallback, 0, 1},
    {"setTextAutosizingWindowSizeOverride", InternalSettingsV8Internal::setTextAutosizingWindowSizeOverrideMethodCallback, 0, 2},
    {"setAccessibilityFontScaleFactor", InternalSettingsV8Internal::setAccessibilityFontScaleFactorMethodCallback, 0, 1},
    {"setMediaTypeOverride", InternalSettingsV8Internal::setMediaTypeOverrideMethodCallback, 0, 1},
    {"setEditingBehavior", InternalSettingsV8Internal::setEditingBehaviorMethodCallback, 0, 1},
    {"setImagesEnabled", InternalSettingsV8Internal::setImagesEnabledMethodCallback, 0, 1},
    {"setDefaultVideoPosterURL", InternalSettingsV8Internal::setDefaultVideoPosterURLMethodCallback, 0, 1},
    {"setViewportEnabled", InternalSettingsV8Internal::setViewportEnabledMethodCallback, 0, 1},
    {"setLayerSquashingEnabled", InternalSettingsV8Internal::setLayerSquashingEnabledMethodCallback, 0, 1},
    {"setAuthorShadowDOMForAnyElementEnabled", InternalSettingsV8Internal::setAuthorShadowDOMForAnyElementEnabledMethodCallback, 0, 1},
    {"setCSSExclusionsEnabled", InternalSettingsV8Internal::setCSSExclusionsEnabledMethodCallback, 0, 1},
    {"setLangAttributeAwareFormControlUIEnabled", InternalSettingsV8Internal::setLangAttributeAwareFormControlUIEnabledMethodCallback, 0, 1},
    {"setOverlayScrollbarsEnabled", InternalSettingsV8Internal::setOverlayScrollbarsEnabledMethodCallback, 0, 1},
    {"setExperimentalContentSecurityPolicyFeaturesEnabled", InternalSettingsV8Internal::setExperimentalContentSecurityPolicyFeaturesEnabledMethodCallback, 0, 1},
    {"setPseudoClassesInMatchingCriteriaInAuthorShadowTreesEnabled", InternalSettingsV8Internal::setPseudoClassesInMatchingCriteriaInAuthorShadowTreesEnabledMethodCallback, 0, 1},
};

static void configureV8InternalSettingsTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "InternalSettings", V8InternalSettingsGenerated::domTemplate(isolate), V8InternalSettings::internalFieldCount,
        0, 0,
        0, 0,
        V8InternalSettingsMethods, WTF_ARRAY_LENGTH(V8InternalSettingsMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8InternalSettings::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8InternalSettingsTemplate);
}

bool V8InternalSettings::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8InternalSettings::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

InternalSettings* V8InternalSettings::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(InternalSettings* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8InternalSettings>(impl, isolate));
    return V8InternalSettings::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8InternalSettings::createWrapper(PassRefPtrWillBeRawPtr<InternalSettings> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8InternalSettings>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8InternalSettings>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8InternalSettings::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(InternalSettings* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

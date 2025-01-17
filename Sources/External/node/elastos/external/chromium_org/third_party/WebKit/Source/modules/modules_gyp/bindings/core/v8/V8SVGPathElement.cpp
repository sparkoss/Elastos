// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8SVGPathElement.h"

#include "bindings/core/v8/V8SVGAnimatedNumber.h"
#include "bindings/core/v8/V8SVGPathSegArcAbs.h"
#include "bindings/core/v8/V8SVGPathSegArcRel.h"
#include "bindings/core/v8/V8SVGPathSegClosePath.h"
#include "bindings/core/v8/V8SVGPathSegCurvetoCubicAbs.h"
#include "bindings/core/v8/V8SVGPathSegCurvetoCubicRel.h"
#include "bindings/core/v8/V8SVGPathSegCurvetoCubicSmoothAbs.h"
#include "bindings/core/v8/V8SVGPathSegCurvetoCubicSmoothRel.h"
#include "bindings/core/v8/V8SVGPathSegCurvetoQuadraticAbs.h"
#include "bindings/core/v8/V8SVGPathSegCurvetoQuadraticRel.h"
#include "bindings/core/v8/V8SVGPathSegCurvetoQuadraticSmoothAbs.h"
#include "bindings/core/v8/V8SVGPathSegCurvetoQuadraticSmoothRel.h"
#include "bindings/core/v8/V8SVGPathSegLinetoAbs.h"
#include "bindings/core/v8/V8SVGPathSegLinetoHorizontalAbs.h"
#include "bindings/core/v8/V8SVGPathSegLinetoHorizontalRel.h"
#include "bindings/core/v8/V8SVGPathSegLinetoRel.h"
#include "bindings/core/v8/V8SVGPathSegLinetoVerticalAbs.h"
#include "bindings/core/v8/V8SVGPathSegLinetoVerticalRel.h"
#include "bindings/core/v8/V8SVGPathSegList.h"
#include "bindings/core/v8/V8SVGPathSegMovetoAbs.h"
#include "bindings/core/v8/V8SVGPathSegMovetoRel.h"
#include "bindings/core/v8/V8SVGPoint.h"
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

static void initializeScriptWrappableForInterface(SVGPathElement* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8SVGPathElement::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::SVGPathElement* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8SVGPathElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGPathElement::domTemplate, V8SVGPathElement::derefObject, 0, V8SVGPathElement::toEventTarget, 0, V8SVGPathElement::installPerContextEnabledMethods, &V8SVGGeometryElement::wrapperTypeInfo, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace SVGPathElementV8Internal {

template <typename T> void V8_USE(T) { }

static void pathLengthAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    SVGPathElement* impl = V8SVGPathElement::toNative(holder);
    v8SetReturnValueFast(info, WTF::getPtr(impl->pathLength()), impl);
}

static void pathLengthAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    SVGPathElementV8Internal::pathLengthAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void pathSegListAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    SVGPathElement* impl = V8SVGPathElement::toNative(holder);
    v8SetReturnValueFast(info, WTF::getPtr(impl->pathSegList()), impl);
}

static void pathSegListAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    SVGPathElementV8Internal::pathSegListAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void normalizedPathSegListAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    SVGPathElement* impl = V8SVGPathElement::toNative(holder);
    v8SetReturnValueFast(info, WTF::getPtr(impl->normalizedPathSegList()), impl);
}

static void normalizedPathSegListAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    SVGPathElementV8Internal::normalizedPathSegListAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void animatedPathSegListAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    SVGPathElement* impl = V8SVGPathElement::toNative(holder);
    v8SetReturnValueFast(info, WTF::getPtr(impl->animatedPathSegList()), impl);
}

static void animatedPathSegListAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    SVGPathElementV8Internal::animatedPathSegListAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void animatedNormalizedPathSegListAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    SVGPathElement* impl = V8SVGPathElement::toNative(holder);
    v8SetReturnValueFast(info, WTF::getPtr(impl->animatedNormalizedPathSegList()), impl);
}

static void animatedNormalizedPathSegListAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    SVGPathElementV8Internal::animatedNormalizedPathSegListAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void getTotalLengthMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    v8SetReturnValue(info, impl->getTotalLength());
}

static void getTotalLengthMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::getTotalLengthMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void getPointAtLengthMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("getPointAtLength", "SVGPathElement", 1, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float distance;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(distance, static_cast<float>(info[0]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->getPointAtLength(distance)), impl);
}

static void getPointAtLengthMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::getPointAtLengthMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void getPathSegAtLengthMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("getPathSegAtLength", "SVGPathElement", 1, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float distance;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(distance, static_cast<float>(info[0]->NumberValue()));
    }
    v8SetReturnValueUnsigned(info, impl->getPathSegAtLength(distance));
}

static void getPathSegAtLengthMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::getPathSegAtLengthMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegClosePathMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegClosePath()), impl);
}

static void createSVGPathSegClosePathMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegClosePathMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegMovetoAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegMovetoAbs", "SVGPathElement", 2, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegMovetoAbs(x, y)), impl);
}

static void createSVGPathSegMovetoAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegMovetoAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegMovetoRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegMovetoRel", "SVGPathElement", 2, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegMovetoRel(x, y)), impl);
}

static void createSVGPathSegMovetoRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegMovetoRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegLinetoAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegLinetoAbs", "SVGPathElement", 2, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegLinetoAbs(x, y)), impl);
}

static void createSVGPathSegLinetoAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegLinetoAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegLinetoRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegLinetoRel", "SVGPathElement", 2, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegLinetoRel(x, y)), impl);
}

static void createSVGPathSegLinetoRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegLinetoRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegCurvetoCubicAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 6)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegCurvetoCubicAbs", "SVGPathElement", 6, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    float x1;
    float y1;
    float x2;
    float y2;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
        TONATIVE_VOID_INTERNAL(x1, static_cast<float>(info[2]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y1, static_cast<float>(info[3]->NumberValue()));
        TONATIVE_VOID_INTERNAL(x2, static_cast<float>(info[4]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y2, static_cast<float>(info[5]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegCurvetoCubicAbs(x, y, x1, y1, x2, y2)), impl);
}

static void createSVGPathSegCurvetoCubicAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegCurvetoCubicAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegCurvetoCubicRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 6)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegCurvetoCubicRel", "SVGPathElement", 6, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    float x1;
    float y1;
    float x2;
    float y2;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
        TONATIVE_VOID_INTERNAL(x1, static_cast<float>(info[2]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y1, static_cast<float>(info[3]->NumberValue()));
        TONATIVE_VOID_INTERNAL(x2, static_cast<float>(info[4]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y2, static_cast<float>(info[5]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegCurvetoCubicRel(x, y, x1, y1, x2, y2)), impl);
}

static void createSVGPathSegCurvetoCubicRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegCurvetoCubicRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegCurvetoQuadraticAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 4)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegCurvetoQuadraticAbs", "SVGPathElement", 4, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    float x1;
    float y1;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
        TONATIVE_VOID_INTERNAL(x1, static_cast<float>(info[2]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y1, static_cast<float>(info[3]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegCurvetoQuadraticAbs(x, y, x1, y1)), impl);
}

static void createSVGPathSegCurvetoQuadraticAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegCurvetoQuadraticAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegCurvetoQuadraticRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 4)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegCurvetoQuadraticRel", "SVGPathElement", 4, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    float x1;
    float y1;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
        TONATIVE_VOID_INTERNAL(x1, static_cast<float>(info[2]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y1, static_cast<float>(info[3]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegCurvetoQuadraticRel(x, y, x1, y1)), impl);
}

static void createSVGPathSegCurvetoQuadraticRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegCurvetoQuadraticRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegArcAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 7)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegArcAbs", "SVGPathElement", 7, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    float r1;
    float r2;
    float angle;
    bool largeArcFlag;
    bool sweepFlag;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
        TONATIVE_VOID_INTERNAL(r1, static_cast<float>(info[2]->NumberValue()));
        TONATIVE_VOID_INTERNAL(r2, static_cast<float>(info[3]->NumberValue()));
        TONATIVE_VOID_INTERNAL(angle, static_cast<float>(info[4]->NumberValue()));
        TONATIVE_VOID_INTERNAL(largeArcFlag, info[5]->BooleanValue());
        TONATIVE_VOID_INTERNAL(sweepFlag, info[6]->BooleanValue());
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegArcAbs(x, y, r1, r2, angle, largeArcFlag, sweepFlag)), impl);
}

static void createSVGPathSegArcAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegArcAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegArcRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 7)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegArcRel", "SVGPathElement", 7, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    float r1;
    float r2;
    float angle;
    bool largeArcFlag;
    bool sweepFlag;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
        TONATIVE_VOID_INTERNAL(r1, static_cast<float>(info[2]->NumberValue()));
        TONATIVE_VOID_INTERNAL(r2, static_cast<float>(info[3]->NumberValue()));
        TONATIVE_VOID_INTERNAL(angle, static_cast<float>(info[4]->NumberValue()));
        TONATIVE_VOID_INTERNAL(largeArcFlag, info[5]->BooleanValue());
        TONATIVE_VOID_INTERNAL(sweepFlag, info[6]->BooleanValue());
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegArcRel(x, y, r1, r2, angle, largeArcFlag, sweepFlag)), impl);
}

static void createSVGPathSegArcRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegArcRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegLinetoHorizontalAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegLinetoHorizontalAbs", "SVGPathElement", 1, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegLinetoHorizontalAbs(x)), impl);
}

static void createSVGPathSegLinetoHorizontalAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegLinetoHorizontalAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegLinetoHorizontalRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegLinetoHorizontalRel", "SVGPathElement", 1, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegLinetoHorizontalRel(x)), impl);
}

static void createSVGPathSegLinetoHorizontalRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegLinetoHorizontalRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegLinetoVerticalAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegLinetoVerticalAbs", "SVGPathElement", 1, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float y;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[0]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegLinetoVerticalAbs(y)), impl);
}

static void createSVGPathSegLinetoVerticalAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegLinetoVerticalAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegLinetoVerticalRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegLinetoVerticalRel", "SVGPathElement", 1, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float y;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[0]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegLinetoVerticalRel(y)), impl);
}

static void createSVGPathSegLinetoVerticalRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegLinetoVerticalRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegCurvetoCubicSmoothAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 4)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegCurvetoCubicSmoothAbs", "SVGPathElement", 4, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    float x2;
    float y2;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
        TONATIVE_VOID_INTERNAL(x2, static_cast<float>(info[2]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y2, static_cast<float>(info[3]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegCurvetoCubicSmoothAbs(x, y, x2, y2)), impl);
}

static void createSVGPathSegCurvetoCubicSmoothAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegCurvetoCubicSmoothAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegCurvetoCubicSmoothRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 4)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegCurvetoCubicSmoothRel", "SVGPathElement", 4, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    float x2;
    float y2;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
        TONATIVE_VOID_INTERNAL(x2, static_cast<float>(info[2]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y2, static_cast<float>(info[3]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegCurvetoCubicSmoothRel(x, y, x2, y2)), impl);
}

static void createSVGPathSegCurvetoCubicSmoothRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegCurvetoCubicSmoothRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegCurvetoQuadraticSmoothAbsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegCurvetoQuadraticSmoothAbs", "SVGPathElement", 2, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegCurvetoQuadraticSmoothAbs(x, y)), impl);
}

static void createSVGPathSegCurvetoQuadraticSmoothAbsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegCurvetoQuadraticSmoothAbsMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void createSVGPathSegCurvetoQuadraticSmoothRelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 2)) {
        throwMinimumArityTypeErrorForMethod("createSVGPathSegCurvetoQuadraticSmoothRel", "SVGPathElement", 2, info.Length(), info.GetIsolate());
        return;
    }
    SVGPathElement* impl = V8SVGPathElement::toNative(info.Holder());
    float x;
    float y;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(x, static_cast<float>(info[0]->NumberValue()));
        TONATIVE_VOID_INTERNAL(y, static_cast<float>(info[1]->NumberValue()));
    }
    v8SetReturnValueFast(info, WTF::getPtr(impl->createSVGPathSegCurvetoQuadraticSmoothRel(x, y)), impl);
}

static void createSVGPathSegCurvetoQuadraticSmoothRelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    SVGPathElementV8Internal::createSVGPathSegCurvetoQuadraticSmoothRelMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace SVGPathElementV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8SVGPathElementAttributes[] = {
    {"pathLength", SVGPathElementV8Internal::pathLengthAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"pathSegList", SVGPathElementV8Internal::pathSegListAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"normalizedPathSegList", SVGPathElementV8Internal::normalizedPathSegListAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"animatedPathSegList", SVGPathElementV8Internal::animatedPathSegListAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"animatedNormalizedPathSegList", SVGPathElementV8Internal::animatedNormalizedPathSegListAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::MethodConfiguration V8SVGPathElementMethods[] = {
    {"getTotalLength", SVGPathElementV8Internal::getTotalLengthMethodCallback, 0, 0},
    {"getPointAtLength", SVGPathElementV8Internal::getPointAtLengthMethodCallback, 0, 1},
    {"getPathSegAtLength", SVGPathElementV8Internal::getPathSegAtLengthMethodCallback, 0, 1},
    {"createSVGPathSegClosePath", SVGPathElementV8Internal::createSVGPathSegClosePathMethodCallback, 0, 0},
    {"createSVGPathSegMovetoAbs", SVGPathElementV8Internal::createSVGPathSegMovetoAbsMethodCallback, 0, 2},
    {"createSVGPathSegMovetoRel", SVGPathElementV8Internal::createSVGPathSegMovetoRelMethodCallback, 0, 2},
    {"createSVGPathSegLinetoAbs", SVGPathElementV8Internal::createSVGPathSegLinetoAbsMethodCallback, 0, 2},
    {"createSVGPathSegLinetoRel", SVGPathElementV8Internal::createSVGPathSegLinetoRelMethodCallback, 0, 2},
    {"createSVGPathSegCurvetoCubicAbs", SVGPathElementV8Internal::createSVGPathSegCurvetoCubicAbsMethodCallback, 0, 6},
    {"createSVGPathSegCurvetoCubicRel", SVGPathElementV8Internal::createSVGPathSegCurvetoCubicRelMethodCallback, 0, 6},
    {"createSVGPathSegCurvetoQuadraticAbs", SVGPathElementV8Internal::createSVGPathSegCurvetoQuadraticAbsMethodCallback, 0, 4},
    {"createSVGPathSegCurvetoQuadraticRel", SVGPathElementV8Internal::createSVGPathSegCurvetoQuadraticRelMethodCallback, 0, 4},
    {"createSVGPathSegArcAbs", SVGPathElementV8Internal::createSVGPathSegArcAbsMethodCallback, 0, 7},
    {"createSVGPathSegArcRel", SVGPathElementV8Internal::createSVGPathSegArcRelMethodCallback, 0, 7},
    {"createSVGPathSegLinetoHorizontalAbs", SVGPathElementV8Internal::createSVGPathSegLinetoHorizontalAbsMethodCallback, 0, 1},
    {"createSVGPathSegLinetoHorizontalRel", SVGPathElementV8Internal::createSVGPathSegLinetoHorizontalRelMethodCallback, 0, 1},
    {"createSVGPathSegLinetoVerticalAbs", SVGPathElementV8Internal::createSVGPathSegLinetoVerticalAbsMethodCallback, 0, 1},
    {"createSVGPathSegLinetoVerticalRel", SVGPathElementV8Internal::createSVGPathSegLinetoVerticalRelMethodCallback, 0, 1},
    {"createSVGPathSegCurvetoCubicSmoothAbs", SVGPathElementV8Internal::createSVGPathSegCurvetoCubicSmoothAbsMethodCallback, 0, 4},
    {"createSVGPathSegCurvetoCubicSmoothRel", SVGPathElementV8Internal::createSVGPathSegCurvetoCubicSmoothRelMethodCallback, 0, 4},
    {"createSVGPathSegCurvetoQuadraticSmoothAbs", SVGPathElementV8Internal::createSVGPathSegCurvetoQuadraticSmoothAbsMethodCallback, 0, 2},
    {"createSVGPathSegCurvetoQuadraticSmoothRel", SVGPathElementV8Internal::createSVGPathSegCurvetoQuadraticSmoothRelMethodCallback, 0, 2},
};

static void configureV8SVGPathElementTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "SVGPathElement", V8SVGGeometryElement::domTemplate(isolate), V8SVGPathElement::internalFieldCount,
        V8SVGPathElementAttributes, WTF_ARRAY_LENGTH(V8SVGPathElementAttributes),
        0, 0,
        V8SVGPathElementMethods, WTF_ARRAY_LENGTH(V8SVGPathElementMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8SVGPathElement::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8SVGPathElementTemplate);
}

bool V8SVGPathElement::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8SVGPathElement::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGPathElement* V8SVGPathElement::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

EventTarget* V8SVGPathElement::toEventTarget(v8::Handle<v8::Object> object)
{
    return toNative(object);
}

v8::Handle<v8::Object> wrap(SVGPathElement* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8SVGPathElement>(impl, isolate));
    return V8SVGPathElement::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8SVGPathElement::createWrapper(PassRefPtrWillBeRawPtr<SVGPathElement> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8SVGPathElement>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8SVGPathElement>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Dependent);
    return wrapper;
}

void V8SVGPathElement::derefObject(void* object)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(object)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(SVGPathElement* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

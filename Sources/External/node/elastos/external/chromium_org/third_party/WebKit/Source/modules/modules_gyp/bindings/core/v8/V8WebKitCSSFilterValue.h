// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#ifndef V8WebKitCSSFilterValue_h
#define V8WebKitCSSFilterValue_h

#include "bindings/core/v8/V8CSSValueList.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8DOMWrapper.h"
#include "bindings/v8/WrapperTypeInfo.h"
#include "core/css/CSSFilterValue.h"
#include "platform/heap/Handle.h"

namespace WebCore {

class V8WebKitCSSFilterValue {
public:
    static bool hasInstance(v8::Handle<v8::Value>, v8::Isolate*);
    static v8::Handle<v8::Object> findInstanceInPrototypeChain(v8::Handle<v8::Value>, v8::Isolate*);
    static v8::Handle<v8::FunctionTemplate> domTemplate(v8::Isolate*);
    static CSSFilterValue* toNative(v8::Handle<v8::Object> object)
    {
        return fromInternalPointer(object->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex));
    }
    static CSSFilterValue* toNativeWithTypeCheck(v8::Isolate*, v8::Handle<v8::Value>);
    static const WrapperTypeInfo wrapperTypeInfo;
    static void derefObject(void*);
#if ENABLE(OILPAN)
    static const int persistentHandleIndex = v8DefaultWrapperInternalFieldCount + 0;
    static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0 + 1;
#else
    static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
#endif
    static inline void* toInternalPointer(CSSFilterValue* impl)
    {
        return V8CSSValueList::toInternalPointer(impl);
    }

    static inline CSSFilterValue* fromInternalPointer(void* object)
    {
        return static_cast<CSSFilterValue*>(V8CSSValueList::fromInternalPointer(object));
    }
    static void installPerContextEnabledProperties(v8::Handle<v8::Object>, CSSFilterValue*, v8::Isolate*) { }
    static void installPerContextEnabledMethods(v8::Handle<v8::Object>, v8::Isolate*) { }

private:
    friend v8::Handle<v8::Object> wrap(CSSFilterValue*, v8::Handle<v8::Object> creationContext, v8::Isolate*);
    static v8::Handle<v8::Object> createWrapper(PassRefPtrWillBeRawPtr<CSSFilterValue>, v8::Handle<v8::Object> creationContext, v8::Isolate*);
};

v8::Handle<v8::Object> wrap(CSSFilterValue* impl, v8::Handle<v8::Object> creationContext, v8::Isolate*);

inline v8::Handle<v8::Value> toV8(CSSFilterValue* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (UNLIKELY(!impl))
        return v8::Null(isolate);
    v8::Handle<v8::Value> wrapper = DOMDataStore::getWrapper<V8WebKitCSSFilterValue>(impl, isolate);
    if (!wrapper.IsEmpty())
        return wrapper;
    return wrap(impl, creationContext, isolate);
}

template<typename CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, CSSFilterValue* impl)
{
    if (UNLIKELY(!impl)) {
        v8SetReturnValueNull(callbackInfo);
        return;
    }
    if (DOMDataStore::setReturnValueFromWrapper<V8WebKitCSSFilterValue>(callbackInfo.GetReturnValue(), impl))
        return;
    v8::Handle<v8::Object> wrapper = wrap(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
    v8SetReturnValue(callbackInfo, wrapper);
}

template<typename CallbackInfo>
inline void v8SetReturnValueForMainWorld(const CallbackInfo& callbackInfo, CSSFilterValue* impl)
{
    ASSERT(DOMWrapperWorld::current(callbackInfo.GetIsolate()).isMainWorld());
    if (UNLIKELY(!impl)) {
        v8SetReturnValueNull(callbackInfo);
        return;
    }
    if (DOMDataStore::setReturnValueFromWrapperForMainWorld<V8WebKitCSSFilterValue>(callbackInfo.GetReturnValue(), impl))
        return;
    v8::Handle<v8::Value> wrapper = wrap(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
    v8SetReturnValue(callbackInfo, wrapper);
}

template<class CallbackInfo, class Wrappable>
inline void v8SetReturnValueFast(const CallbackInfo& callbackInfo, CSSFilterValue* impl, Wrappable* wrappable)
{
    if (UNLIKELY(!impl)) {
        v8SetReturnValueNull(callbackInfo);
        return;
    }
    if (DOMDataStore::setReturnValueFromWrapperFast<V8WebKitCSSFilterValue>(callbackInfo.GetReturnValue(), impl, callbackInfo.Holder(), wrappable))
        return;
    v8::Handle<v8::Object> wrapper = wrap(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
    v8SetReturnValue(callbackInfo, wrapper);
}

inline v8::Handle<v8::Value> toV8(PassRefPtrWillBeRawPtr<CSSFilterValue> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl.get(), creationContext, isolate);
}

template<class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, PassRefPtrWillBeRawPtr<CSSFilterValue> impl)
{
    v8SetReturnValue(callbackInfo, impl.get());
}

template<class CallbackInfo>
inline void v8SetReturnValueForMainWorld(const CallbackInfo& callbackInfo, PassRefPtrWillBeRawPtr<CSSFilterValue> impl)
{
    v8SetReturnValueForMainWorld(callbackInfo, impl.get());
}

template<class CallbackInfo, class Wrappable>
inline void v8SetReturnValueFast(const CallbackInfo& callbackInfo, PassRefPtrWillBeRawPtr<CSSFilterValue> impl, Wrappable* wrappable)
{
    v8SetReturnValueFast(callbackInfo, impl.get(), wrappable);
}

}
#endif // V8WebKitCSSFilterValue_h

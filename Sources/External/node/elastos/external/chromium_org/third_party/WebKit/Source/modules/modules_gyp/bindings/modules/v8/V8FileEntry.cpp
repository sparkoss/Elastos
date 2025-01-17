// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8FileEntry.h"

#include "bindings/modules/v8/V8ErrorCallback.h"
#include "bindings/modules/v8/V8FileCallback.h"
#include "bindings/modules/v8/V8FileWriterCallback.h"
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

static void initializeScriptWrappableForInterface(FileEntry* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8FileEntry::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::FileEntry* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8FileEntry::wrapperTypeInfo = { gin::kEmbedderBlink, V8FileEntry::domTemplate, V8FileEntry::derefObject, 0, 0, 0, V8FileEntry::installPerContextEnabledMethods, &V8Entry::wrapperTypeInfo, WrapperTypeObjectPrototype, GarbageCollectedObject };

namespace FileEntryV8Internal {

template <typename T> void V8_USE(T) { }

static void createWriterMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("createWriter", "FileEntry", 1, info.Length(), info.GetIsolate());
        return;
    }
    FileEntry* impl = V8FileEntry::toNative(info.Holder());
    OwnPtr<FileWriterCallback> successCallback;
    OwnPtr<ErrorCallback> errorCallback;
    {
        if (info.Length() <= 0 || !info[0]->IsFunction()) {
            throwTypeError(ExceptionMessages::failedToExecute("createWriter", "FileEntry", "The callback provided as parameter 1 is not a function."), info.GetIsolate());
            return;
        }
        successCallback = V8FileWriterCallback::create(v8::Handle<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));
        if (info.Length() > 1 && !isUndefinedOrNull(info[1])) {
            if (!info[1]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("createWriter", "FileEntry", "The callback provided as parameter 2 is not a function."), info.GetIsolate());
                return;
            }
            errorCallback = V8ErrorCallback::create(v8::Handle<v8::Function>::Cast(info[1]), ScriptState::current(info.GetIsolate()));
        }
    }
    impl->createWriter(successCallback.release(), errorCallback.release());
}

static void createWriterMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    FileEntryV8Internal::createWriterMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void fileMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("file", "FileEntry", 1, info.Length(), info.GetIsolate());
        return;
    }
    FileEntry* impl = V8FileEntry::toNative(info.Holder());
    OwnPtr<FileCallback> successCallback;
    OwnPtr<ErrorCallback> errorCallback;
    {
        if (info.Length() <= 0 || !info[0]->IsFunction()) {
            throwTypeError(ExceptionMessages::failedToExecute("file", "FileEntry", "The callback provided as parameter 1 is not a function."), info.GetIsolate());
            return;
        }
        successCallback = V8FileCallback::create(v8::Handle<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));
        if (info.Length() > 1 && !isUndefinedOrNull(info[1])) {
            if (!info[1]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("file", "FileEntry", "The callback provided as parameter 2 is not a function."), info.GetIsolate());
                return;
            }
            errorCallback = V8ErrorCallback::create(v8::Handle<v8::Function>::Cast(info[1]), ScriptState::current(info.GetIsolate()));
        }
    }
    impl->file(successCallback.release(), errorCallback.release());
}

static void fileMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    FileEntryV8Internal::fileMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace FileEntryV8Internal

static const V8DOMConfiguration::MethodConfiguration V8FileEntryMethods[] = {
    {"createWriter", FileEntryV8Internal::createWriterMethodCallback, 0, 1},
    {"file", FileEntryV8Internal::fileMethodCallback, 0, 1},
};

static void configureV8FileEntryTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "FileEntry", V8Entry::domTemplate(isolate), V8FileEntry::internalFieldCount,
        0, 0,
        0, 0,
        V8FileEntryMethods, WTF_ARRAY_LENGTH(V8FileEntryMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8FileEntry::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8FileEntryTemplate);
}

bool V8FileEntry::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8FileEntry::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

FileEntry* V8FileEntry::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(FileEntry* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8FileEntry>(impl, isolate));
    return V8FileEntry::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8FileEntry::createWrapper(RawPtr<FileEntry> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8FileEntry>(impl.get(), isolate));
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
    V8DOMWrapper::associateObjectWithWrapper<V8FileEntry>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8FileEntry::derefObject(void* object)
{
}

template<>
v8::Handle<v8::Value> toV8NoInline(FileEntry* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore

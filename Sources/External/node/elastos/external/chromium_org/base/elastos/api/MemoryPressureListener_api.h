// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     api_generator
// For
//     org/chromium/base/MemoryPressureListener

#ifndef ELASTOS_ORG_CHROMIUM_BASE_MEMORYPRESSURELISTENER_JNI
#define ELASTOS_ORG_CHROMIUM_BASE_MEMORYPRESSURELISTENER_JNI

//#include <jni.h>

#include "ElAndroid.h"
#include "elastos.h"
#include "base/logging.h"

//#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.

extern "C" {

static void OnMemoryPressure(Elastos::Int32 memoryPressureType);

__attribute__((visibility("default")))
void Elastos_MemoryPressureListener_nativeOnMemoryPressure(
    /* [in] */ Elastos::Int32 memoryPressureType) {
    return OnMemoryPressure(memoryPressureType);
}

};  // extern "C"

// Step 2: method stubs.

// Step 3: Callback init .
struct ElaMemoryPressureListenerCallback
{
    void (*elastos_MemoryPressureListener_registerSystemCallback)(IInterface* context);
};

extern "C" {
static struct ElaMemoryPressureListenerCallback* sElaMemoryPressureListenerCallback;
__attribute__((visibility("default")))
void Elastos_MemoryPressureListener_InitCallback(Elastos::Handle32 cb)
{
    sElaMemoryPressureListenerCallback = (struct ElaMemoryPressureListenerCallback*)cb;
    DLOG(INFO) << "init pointer for sElaMemoryPressureListenerCallback is:" << sElaMemoryPressureListenerCallback;
}
}; // extern "C"

static bool RegisterNativesImpl() {

  return true;
}

#endif  // ELASTOS_ORG_CHROMIUM_BASE_MEMORYPRESSURELISTENER_JNI

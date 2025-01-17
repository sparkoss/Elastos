// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     api_generator
// For
//     org/chromium/base/ContentUriUtils

#ifndef ELASTOS_ORG_CHROMIUM_BASE_CONTENTURIUTILS_JNI
#define ELASTOS_ORG_CHROMIUM_BASE_CONTENTURIUTILS_JNI

//#include <jni.h>

#include "ElAndroid.h"
#include "elastos.h"
#include "base/logging.h"

//#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.

// Step 2: method stubs.

// Step 3: Callback init .
struct ElaContentUriUtilsCallback
{
    Elastos::Int32 (*elastos_ContentUriUtils_openContentUriForRead)(IInterface* context, const Elastos::String& uriString);
    Elastos::Boolean (*elastos_ContentUriUtils_contentUriExists)(IInterface* context, const Elastos::String& uriString);
};

extern "C" {
static struct ElaContentUriUtilsCallback* sElaContentUriUtilsCallback;
__attribute__((visibility("default")))
void Elastos_ContentUriUtils_InitCallback(Elastos::Handle32 cb)
{
    sElaContentUriUtilsCallback = (struct ElaContentUriUtilsCallback*)cb;
    DLOG(INFO) << "init pointer for sElaContentUriUtilsCallback is:" << sElaContentUriUtilsCallback;
}
}; // extern "C"

static bool RegisterNativesImpl() {

  return true;
}

#endif  // ELASTOS_ORG_CHROMIUM_BASE_CONTENTURIUTILS_JNI

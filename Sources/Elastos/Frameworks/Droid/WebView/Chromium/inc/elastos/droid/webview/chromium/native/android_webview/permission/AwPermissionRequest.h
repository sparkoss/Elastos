//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_ANDROIDWEBVIEW_PERMISSION_AWPERMISSIONREQUEST_H__
#define __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_ANDROIDWEBVIEW_PERMISSION_AWPERMISSIONREQUEST_H__

#include "elastos/droid/ext/frameworkext.h"
#include "Elastos.Droid.Net.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Net::IUri;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace AndroidWebview {
namespace Permission {

/**
 * This class wraps permission request in Chromium side, and can only be created
 * by native side.
 */
//@JNINamespace("android_webview")
class AwPermissionRequest
    : public Object
{
public:
    CARAPI_(AutoPtr<IUri>) GetOrigin();

    CARAPI_(Int64) GetResources();

    CARAPI Grant();

    CARAPI Deny();

protected:
    //@Override
    //protected void finalize();
    ~AwPermissionRequest();

private:
    AwPermissionRequest(
        /* [in] */ Handle64 nativeAwPermissionRequest,
        /* [in] */ IUri* origin,
        /* [in] */ Int64 resources);

    //@CalledByNative return AwPermissionRequest
    static CARAPI_(AutoPtr<IInterface>) Create(
        /* [in] */ Handle64 nativeAwPermissionRequest,
        /* [in] */ const String& url,
        /* [in] */ Int64 resources);

    //@CalledByNative
    CARAPI_(void) DetachNativeInstance();

    CARAPI Validate();

    CARAPI_(void) NativeOnAccept(
        /* [in] */ Handle64 nativeAwPermissionRequest,
        /* [in] */ Boolean allowed);

//callback function declaration
public:
    static CARAPI_(void*) ElaAwPermissionRequestCallback_Init();

private:
    static CARAPI_(void) DetachNativeInstance(
        /* [in] */ IInterface* obj);

private:
    static String TAG;

    AutoPtr<IUri> mOrigin;
    Int64 mResources;
    Boolean mProcessed;

    // AwPermissionRequest native instance.
    Handle64 mNativeAwPermissionRequest;
};

} // namespace Permission
} // namespace AndroidWebview
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif//__ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_ANDROIDWEBVIEW_PERMISSION_AWPERMISSIONREQUEST_H__

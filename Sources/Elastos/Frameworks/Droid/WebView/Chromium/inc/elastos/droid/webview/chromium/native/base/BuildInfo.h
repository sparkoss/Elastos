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

#ifndef __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_BASE_BUILDINFO_H__
#define __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_BASE_BUILDINFO_H__

#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Base {

/**
 * BuildInfo is a utility class providing easy access to {@link PackageInfo}
 * information. This is primarly of use for accessesing package information
 * from native code.
 */
class BuildInfo
    : public Object
{
public:
    //@CalledByNative
    static CARAPI_(String) GetDevice();

    //@CalledByNative
    static CARAPI_(String) GetBrand();

    //@CalledByNative
    static CARAPI_(String) GetAndroidBuildId();

    /**
     * @return The build fingerprint for the current Android install.  The value is truncated to a
     *         128 characters as this is used for crash and UMA reporting, which should avoid huge
     *         strings.
     */
    //@CalledByNative
    static CARAPI_(String) GetAndroidBuildFingerprint();

    //@CalledByNative
    static CARAPI_(String) GetDeviceModel();

    //@CalledByNative
    static CARAPI_(String) GetPackageVersionCode(
        /* [in] */ IContext* context);

    //@CalledByNative
    static CARAPI_(String) GetPackageVersionName(
        /* [in] */ IContext* context);

    //@CalledByNative
    static CARAPI_(String) GetPackageLabel(
        /* [in] */ IContext* context);

    //@CalledByNative
    static CARAPI_(String) GetPackageName(
        /* [in] */ IContext* context);

    //@CalledByNative
    static CARAPI_(String) GetBuildType();

    //@CalledByNative
    static CARAPI_(Int32) GetSdkInt();

    static CARAPI_(void*) ElaBuildInfoCallback_Init();

private:
    static CARAPI_(String) GetPackageVersionCode(
        /* [in] */ IInterface* context);

    static CARAPI_(String) GetPackageVersionName(
        /* [in] */ IInterface* context);

    static CARAPI_(String) GetPackageLabel(
        /* [in] */ IInterface* context);

    static CARAPI_(String) GetPackageName(
        /* [in] */ IInterface* context);

    /**
     * BuildInfo is a static utility class and therefore shouldn't be
     * instantiated.
     */
    BuildInfo();

    static const String TAG;
    static const Int32 MAX_FINGERPRINT_LENGTH = 128;
};

} // namespace Base
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif//__ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_BASE_BUILDINFO_H__

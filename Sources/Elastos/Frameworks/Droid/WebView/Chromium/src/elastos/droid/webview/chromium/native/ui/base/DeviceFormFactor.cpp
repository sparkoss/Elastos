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

#include "Elastos.Droid.Content.h"
#include "elastos/droid/webkit/webview/chromium/native/ui/base/DeviceFormFactor.h"
#include "elastos/droid/webkit/webview/chromium/native/ui/api/DeviceFormFactor_dec.h"

using Elastos::Droid::Content::Res::IConfiguration;
using Elastos::Droid::Content::Res::IResources;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Ui {
namespace Base {

//=====================================================================
//                           DeviceFormFactor
//=====================================================================
const Int32 DeviceFormFactor::MINIMUM_TABLET_WIDTH_DP;
Boolean DeviceFormFactor::sIsTablet = FALSE;

Boolean DeviceFormFactor::IsTablet(
    /* [in] */ IContext* context)
{
    // ==================before translated======================
    // if (sIsTablet == null) {
    //     int minimumScreenWidthDp = context.getResources().getConfiguration().
    //             smallestScreenWidthDp;
    //     sIsTablet = minimumScreenWidthDp >= MINIMUM_TABLET_WIDTH_DP;
    // }
    // return sIsTablet;

    if (!sIsTablet) {
        AutoPtr<IResources> resources;
        context->GetResources((IResources**)&resources);

        AutoPtr<IConfiguration> configuration;
        resources->GetConfiguration((IConfiguration**)&configuration);

        Int32 minimumScreenWidthDp = configuration->SMALLEST_SCREEN_WIDTH_DP_UNDEFINED;
        sIsTablet = minimumScreenWidthDp >= MINIMUM_TABLET_WIDTH_DP;
    }
    return sIsTablet;
}

Boolean DeviceFormFactor::IsTablet(
    /* [in] */ IInterface* context)
{
    IContext* c = IContext::Probe(context);
    return IsTablet(c);
}

} // namespace Base
} // namespace Ui
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos



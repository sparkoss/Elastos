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

#ifndef __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_CONTENT_COMMON_SCREENORIENTATIONVALUES_H__
#define __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_CONTENT_COMMON_SCREENORIENTATIONVALUES_H__

#include "elastos/droid/ext/frameworkext.h"

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Content {
namespace Common {

class ScreenOrientationValues
{
public:
    static const Int32 DEFAULT = 0;
    static const Int32 PORTRAIT_PRIMARY = 1;
    static const Int32 PORTRAIT_SECONDARY = 2;
    static const Int32 LANDSCAPE_PRIMARY = 3;
    static const Int32 LANDSCAPE_SECONDARY = 4;
    static const Int32 ANY = 5;
    static const Int32 LANDSCAPE = 6;
    static const Int32 PORTRAIT = 7;
};

} // namespace Common
} // namespace Content
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif//__ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_CONTENT_COMMON_SCREENORIENTATIONVALUES_H__
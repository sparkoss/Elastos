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

#ifndef __ELASTOS_DROID_MEDIA_CWEBVTTPARSERHELPER_H__
#define __ELASTOS_DROID_MEDIA_CWEBVTTPARSERHELPER_H__

#include "_Elastos_Droid_Media_CWebVttParserHelper.h"
#include "Elastos.Droid.Media.h"
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Singleton.h>

namespace Elastos {
namespace Droid {
namespace Media {

CarClass(CWebVttParserHelper)
    , public Singleton
    , public IWebVttParserHelper
{
public:
    CAR_SINGLETON_DECL()

    CAR_INTERFACE_DECL()

    CARAPI ParseFloatPercentage(
        /* [in] */ const String& s,
        /* [out] */ Float* result);

    CARAPI ParseIntPercentage(
        /* [in] */ const String& s,
        /* [out] */ Int32* result);

    CARAPI ParseTimestampMs(
        /* [in] */ const String& s,
        /* [out] */ Int64* result);

    CARAPI TimeToString(
        /* [in] */ Int64 timeMs,
        /* [out] */ String* result);
};

} // namespace Media
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_MEDIA_CWEBVTTPARSERHELPER_H__
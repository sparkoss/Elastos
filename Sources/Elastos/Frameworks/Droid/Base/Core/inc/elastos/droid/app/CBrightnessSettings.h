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

#ifndef __ELASTOS_DROID_APP_CBRIGHTNESSSETTINGS_H__
#define __ELASTOS_DROID_APP_CBRIGHTNESSSETTINGS_H__

#include "_Elastos_Droid_App_CBrightnessSettings.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;
using Elastos::Core::Object;
using Elastos::Core::IStringBuilder;
using Org::Xmlpull::V1::IXmlPullParser;

namespace Elastos {
namespace Droid {
namespace App {

CarClass(CBrightnessSettings)
    , public Object
    , public IBrightnessSettings
    , public IParcelable
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ Int32 value,
        /* [in] */ Boolean override);

    CARAPI GetValue(
        /* [out] */ Int32* value);

    CARAPI SetValue(
        /* [in] */ Int32 value);

    CARAPI SetOverride(
        /* [in] */ Boolean override);

    CARAPI IsOverride(
        /* [out] */ Boolean* override);

    CARAPI IsDirty(
        /* [out] */ Boolean* dirty);

    CARAPI ProcessOverride(
        /* [in] */ IContext* context);

    static CARAPI FromXml(
        /* [in] */ IXmlPullParser* xpp,
        /* [in] */ IContext* context,
        /* [out] */ IBrightnessSettings** obj);

    CARAPI GetXmlString(
        /* [in] */ IStringBuilder* builder,
        /* [in] */ IContext* context);

    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

private:
    Int32 mValue;
    Boolean mOverride;
    Boolean mDirty;
};

} // namespace App
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_APP_CBRIGHTNESSSETTINGS_H__

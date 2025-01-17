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

#ifndef  __ELASTOS_DROID_PHONE_CGSMUMTSOPTIONS_H__
#define  __ELASTOS_DROID_PHONE_CGSMUMTSOPTIONS_H__

#include "_Elastos_Droid_TeleService_Phone_CGsmUmtsOptions.h"
#include "elastos/droid/ext/frameworkext.h"
#include "Elastos.Droid.Preference.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Preference::IPreferenceActivity;
using Elastos::Droid::Preference::IPreferenceScreen;
using Elastos::Droid::Preference::IPreference;
using Elastos::Droid::Preference::IPreferenceOnPreferenceClickListener;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace TeleService {
namespace Phone {

/**
 * List of Network-specific settings screens.
 */
CarClass(CGsmUmtsOptions)
    , public Object
    , public IGsmUmtsOptions
{
private:
    class MyPreferenceOnPreferenceClickListener
        : public Object
        , public IPreferenceOnPreferenceClickListener
    {
    public:
        TO_STRING_IMPL("CGsmUmtsOptions::MyPreferenceOnPreferenceClickListener")

        CAR_INTERFACE_DECL()

        MyPreferenceOnPreferenceClickListener(
            /* [in] */ CGsmUmtsOptions* host)
            : mHost(host)
        {}

        // @Override
        CARAPI OnPreferenceClick(
            /* [in] */ IPreference* preference,
            /* [out] */ Boolean* result);

    private:
        CGsmUmtsOptions* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL();

    CARAPI constructor(
        /* [in] */ IPreferenceActivity* prefActivity,
        /* [in] */ IPreferenceScreen* prefScreen);

    CARAPI PreferenceTreeClick(
        /* [in] */ IPreference* preference,
        /* [out] */ Boolean* result);

protected:
    CARAPI Create();

    CARAPI Log(
        /* [in] */ const String& s);

private:
    static const String TAG;

    AutoPtr<IPreferenceScreen> mButtonAPNExpand;
    AutoPtr<IPreferenceScreen> mButtonOperatorSelectionExpand;

    static const String BUTTON_APN_EXPAND_KEY;
    static const String BUTTON_OPERATOR_SELECTION_EXPAND_KEY;
    static const String BUTTON_CARRIER_SETTINGS_KEY;
    AutoPtr<IPreferenceActivity> mPrefActivity;
    AutoPtr<IPreferenceScreen> mPrefScreen;
};

} // namespace Phone
} // namespace TeleService
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_PHONE_CGSMUMTSOPTIONS_H__
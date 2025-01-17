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

#ifndef __ELASTOS_DROID_PREFERENCE_RINGTONEPREFERENCE_H__
#define __ELASTOS_DROID_PREFERENCE_RINGTONEPREFERENCE_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/preference/Preference.h"

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::IIntent;
using Elastos::Droid::Content::Res::ITypedArray;
using Elastos::Droid::Net::IUri;
using Elastos::Droid::Utility::IAttributeSet;

namespace Elastos {
namespace Droid {
namespace Preference {

class ECO_PUBLIC RingtonePreference
    : public Preference
    , public IRingtonePreference
{
private:
    class ECO_LOCAL InnerListener
        : public Object
        , public IPreferenceManagerOnActivityResultListener
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("RingtonePreference::InnerListener")

        InnerListener(
            /* [in] */ RingtonePreference* host);

        CARAPI OnActivityResult(
            /* [in] */ Int32 requestCode,
            /* [in] */ Int32 resultCode,
            /* [in] */ IIntent* data,
            /* [out] */ Boolean* result);
    private:
        RingtonePreference* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    RingtonePreference();

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyleAttr,
        /* [in] */ Int32 defStyleRes);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyleAttr);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI GetRingtoneType(
        /* [out] */ Int32* type);

    CARAPI SetRingtoneType(
        /* [in] */ Int32 type);

    CARAPI GetSubId(
        /* [out] */ Int32* result);

    CARAPI SetSubId(
        /* [in] */ Int32 subId);

    CARAPI GetShowDefault(
        /* [out] */ Boolean* showDefault);

    CARAPI SetShowDefault(
        /* [in] */ Boolean showDefault);

    CARAPI GetShowSilent(
        /* [out] */ Boolean* showSilent);

    CARAPI SetShowSilent(
        /* [in] */ Boolean showSilent);

    CARAPI GetDialogStyle(
        /* [out] */ Int32* result);

    CARAPI SetDialogStyle(
        /* [in] */ Int32 dialogStyle);

    CARAPI OnActivityResult(
        /* [in] */ Int32 requestCode,
        /* [in] */ Int32 resultCode,
        /* [in] */ IIntent* data,
        /* [out] */ Boolean* result);

protected:
    //@Override
    CARAPI OnClick();

    CARAPI OnPrepareRingtonePickerIntent(
        /* [in] */ IIntent* ringtonePickerIntent);

    CARAPI OnSaveRingtone(
        /* [in] */ IUri* ringtoneUri);

    CARAPI OnRestoreRingtone(
        /* [out] */ IUri** uri);

    CARAPI OnGetDefaultValue(
        /* [in] */ ITypedArray* a,
        /* [in] */ Int32 index,
        /* [out] */ IInterface** value);

    CARAPI OnSetInitialValue(
        /* [in] */ Boolean restorePersistedValue,
        /* [in] */ IInterface* defaultValue);

    CARAPI OnAttachedToHierarchy(
        /* [in] */ IPreferenceManager* preferenceManager);

private:
    ECO_LOCAL static const String TAG;
    // TODO: Add your private member variables here.
    Int32 mRingtoneType;
    Boolean mShowDefault;
    Boolean mShowSilent;
    Int32 mDialogStyle;
    Int32 mRequestCode;
    Int32 mSubscriptionID;
};

}
}
}

#endif // __ELASTOS_DROID_PREFERENCE_RINGTONEPREFERENCE_H__

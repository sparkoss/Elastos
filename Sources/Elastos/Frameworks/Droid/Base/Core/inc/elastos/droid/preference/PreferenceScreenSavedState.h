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

#ifndef __ELASTOS_DROID_PREFERENCE_PREFERENCESCREENSAVEDSTATE_H__
#define __ELASTOS_DROID_PREFERENCE_PREFERENCESCREENSAVEDSTATE_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/preference/PreferenceBaseSavedState.h"

using Elastos::Droid::Os::IBundle;

namespace Elastos {
namespace Droid {
namespace Preference {

class PreferenceScreenSavedState
    : public PreferenceBaseSavedState
    , public IPreferenceScreenSavedState
{
public:
    CAR_INTERFACE_DECL()

    PreferenceScreenSavedState();

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ IParcelable* source);

    CARAPI IsDialogShowing(
        /* [out] */ Boolean* isDialogShowing);

    CARAPI SetDialogShowing(
        /* [in] */ Boolean isDialogShowing);

    CARAPI SetDialogBundle(
        /* [in] */ IBundle* b);

    CARAPI GetDialogBundle(
        /* [out] */ IBundle** b);

    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    CARAPI GetSuperState(
        /* [out] */ IParcelable** superState);

private:
    Boolean mIsDialogShowing;
    AutoPtr<IBundle> mDialogBundle;
};

} // Preference
} // Droid
} // Elastos

#endif  // __ELASTOS_DROID_PREFERENCE_PREFERENCESCREENSAVEDSTATE_H__

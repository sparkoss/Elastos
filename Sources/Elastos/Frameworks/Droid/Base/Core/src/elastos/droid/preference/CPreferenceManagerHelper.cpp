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

#include "elastos/droid/preference/CPreferenceManagerHelper.h"
#include "elastos/droid/preference/PreferenceManager.h"
#include "elastos/droid/R.h"

using Elastos::Droid::R;

namespace Elastos {
namespace Droid {
namespace Preference {

CAR_INTERFACE_IMPL(CPreferenceManagerHelper, Singleton, IPreferenceManagerHelper)

CAR_SINGLETON_IMPL(CPreferenceManagerHelper)


ECode CPreferenceManagerHelper::GetDefaultSharedPreferences(
    /* [in] */ IContext* context,
    /* [out] */ ISharedPreferences** result)
{
    VALIDATE_NOT_NULL(result)
    return PreferenceManager::GetDefaultSharedPreferences(context, result);
}

ECode CPreferenceManagerHelper::SetDefaultValues(
    /* [in] */ IContext* context,
    /* [in] */ Int32 resId,
    /* [in] */ Boolean readAgain)
{
    return PreferenceManager::SetDefaultValues(context, resId, readAgain);
}

ECode CPreferenceManagerHelper::SetDefaultValues(
    /* [in] */ IContext* context,
    /* [in] */ const String& sharedPreferencesName,
    /* [in] */ Int32 sharedPreferencesMode,
    /* [in] */ Int32 resId,
    /* [in] */ Boolean readAgain)
{
    return PreferenceManager::SetDefaultValues(context, sharedPreferencesName, sharedPreferencesMode, resId, readAgain);
}

} // namespace Preference
} // namespace Droid
} // namespace Elastos
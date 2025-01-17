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

#ifndef __ELASTOS_DROID_SERVICE_NOTIFICATION_CONDITION_H__
#define __ELASTOS_DROID_SERVICE_NOTIFICATION_CONDITION_H__

#include "elastos/droid/ext/frameworkext.h"
#include "Elastos.Droid.Net.h"
#include "Elastos.Droid.Service.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Net::IUri;
using Elastos::Droid::Net::IUriBuilder;

namespace Elastos {
namespace Droid {
namespace Service {
namespace Notification {

class Condition
    : public Object
    , public ICondition
    , public IParcelable
{
public:
    CAR_INTERFACE_DECL()

    Condition();

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ IUri* id,
        /* [in] */ const String& summary,
        /* [in] */ const String& line1,
        /* [in] */ const String& line2,
        /* [in] */ Int32 icon,
        /* [in] */ Int32 state,
        /* [in] */ Int32 flags);

    CARAPI constructor(
        /* [in] */ IParcelable* source);

    static CARAPI_(Boolean) IsValidState(
        /* [in] */ Int32 state);

    CARAPI GetId(
        /* [out] */ IUri** id);

    CARAPI SetId(
        /* [in] */ IUri* id);

    CARAPI GetSummary(
        /* [out] */ String* summary);

    CARAPI SetSummary(
        /* [in] */ const String& summary);

    CARAPI GetLine1(
        /* [out] */ String* line1);

    CARAPI SetLine1(
        /* [in] */ const String& line1);

    CARAPI GetLine2(
        /* [out] */ String* line2);

    CARAPI SetLine2(
        /* [in] */ const String& line2);

    CARAPI GetIcon(
        /* [out] */ Int32* icon);

    CARAPI SetIcon(
        /* [in] */ Int32 icon);

    CARAPI GetState(
        /* [out] */ Int32* state);

    CARAPI SetState(
        /* [in] */ Int32 state);

    CARAPI GetFlags(
        /* [out] */ Int32* flags);

    CARAPI SetFlags(
        /* [in] */ Int32 flags);

public:
    // @Override
    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    // @Override
    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

    // @Override
    CARAPI ToString(
        /* [out] */ String* str);

    static CARAPI StateToString(
        /* [in] */ Int32 state,
        /* [out] */ String* str);

    static CARAPI RelevanceToString(
        /* [in] */ Int32 flags,
        /* [out] */ String* str);

    // @Override
    CARAPI Equals(
        /* [in] */ IInterface* o,
        /* [out] */ Boolean* isEquals);

    // @Override
    CARAPI GetHashCode(
        /* [out] */ Int32* hashCode);

    CARAPI Copy(
        /* [out] */ ICondition** copy);

    static CARAPI NewId(
        /* [in] */ IContext* context,
        /* [out] */ IUriBuilder** id);

    static CARAPI IsValidId(
        /* [in] */ IUri* id,
        /* [in] */ const String& pkg,
        /* [out] */ Boolean* isValidId);

public:
    AutoPtr<IUri> mId;
    String mSummary;
    String mLine1;
    String mLine2;
    Int32 mIcon;
    Int32 mState;
    Int32 mFlags;

private:
    const static String TAG;
};

} // namespace Notification
} // namespace Service
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SERVICE_NOTIFICATION_CONDITION_H__

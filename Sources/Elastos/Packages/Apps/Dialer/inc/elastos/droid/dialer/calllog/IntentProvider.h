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

#ifndef __ELASTOS_DROID_DIALER_CALLLOG_INTENTPROVIDER_H__
#define __ELASTOS_DROID_DIALER_CALLLOG_INTENTPROVIDER_H__

#include "_Elastos.Droid.Dialer.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Telecom.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::IIntent;
using Elastos::Droid::Telecom::IPhoneAccountHandle;

namespace Elastos {
namespace Droid {
namespace Dialer {
namespace CallLog {

/**
 * Used to create an intent to attach to an action in the call log.
 * <p>
 * The intent is constructed lazily with the given information.
 */
class IntentProvider
    : public Object
    , public IIntentProvider
{
private:
    class ReturnCallIntentProvider
        : public Object
        , public IIntentProvider
    {
    public:
        CAR_INTERFACE_DECL()

        ReturnCallIntentProvider(
            /* [in] */ const String& number,
            /* [in] */ IPhoneAccountHandle* accountHandle);

        CARAPI GetIntent(
            /* [in] */ IContext* context,
            /* [out] */ IIntent** intent);

    private:
        String mNumber;
        AutoPtr<IPhoneAccountHandle> mAccountHandle;
    };

    class ReturnVideoCallIntentProvider
        : public Object
        , public IIntentProvider
    {
    public:
        CAR_INTERFACE_DECL()

        ReturnVideoCallIntentProvider(
            /* [in] */ const String& number,
            /* [in] */ IPhoneAccountHandle* accountHandle);

        CARAPI GetIntent(
            /* [in] */ IContext* context,
            /* [out] */ IIntent** intent);

    private:
        String mNumber;
        AutoPtr<IPhoneAccountHandle> mAccountHandle;
    };

    class PlayVoicemailIntentProvider
        : public Object
        , public IIntentProvider
    {
    public:
        CAR_INTERFACE_DECL()

        PlayVoicemailIntentProvider(
            /* [in] */ Int64 rowId,
            /* [in] */ const String& voicemailUri);

        CARAPI GetIntent(
            /* [in] */ IContext* context,
            /* [out] */ IIntent** intent);
    private:
        Int64 mRowId;
        String mVoicemailUri;
    };

    class CallDetailIntentProvider
        : public Object
        , public IIntentProvider
    {
    public:
        CAR_INTERFACE_DECL()

        CallDetailIntentProvider(
            /* [in] */ Int64 id,
            /* [in] */ ArrayOf<Int64>* extraIds,
            /* [in] */ const String& voicemailUri);

        CARAPI GetIntent(
            /* [in] */ IContext* context,
            /* [out] */ IIntent** intent);
    private:
        Int64 mId;
        AutoPtr<ArrayOf<Int64> > mExtraIds;
        String mVoicemailUri;
    };

public:
    CAR_INTERFACE_DECL()

    static CARAPI_(AutoPtr<IIntentProvider>) GetReturnCallIntentProvider(
        /* [in] */ const String& number);

    static CARAPI_(AutoPtr<IIntentProvider>) GetReturnCallIntentProvider(
        /* [in] */ const String& number,
        /* [in] */ IPhoneAccountHandle* accountHandle);

    static CARAPI_(AutoPtr<IIntentProvider>) GetReturnVideoCallIntentProvider(
        /* [in] */ const String& number);

    static CARAPI_(AutoPtr<IIntentProvider>) GetReturnVideoCallIntentProvider(
        /* [in] */ const String& number,
        /* [in] */ IPhoneAccountHandle* accountHandle);

    static CARAPI_(AutoPtr<IIntentProvider>) GetPlayVoicemailIntentProvider(
        /* [in] */ Int64 rowId,
        /* [in] */ const String& voicemailUri);

    /**
     * Retrieves the call details intent provider for an entry in the call log.
     *
     * @param id The call ID of the first call in the call group.
     * @param extraIds The call ID of the other calls grouped together with the call.
     * @param voicemailUri If call log entry is for a voicemail, the voicemail URI.
     * @return The call details intent provider.
     */
    static AutoPtr<IIntentProvider> GetCallDetailIntentProvider(
        /* [in] */ Int64 id,
        /* [in] */ ArrayOf<Int64>* extraIds,
        /* [in] */ const String& voicemailUri);

private:
    static const String TAG;
};

} // CallLog
} // Dialer
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_DIALER_CALLLOG_INTENTPROVIDER_H__

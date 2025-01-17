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

#ifndef __ELASTOS_DROID_DIALER_CALLLOG_PHONEACCOUNTUTILS_H__
#define __ELASTOS_DROID_DIALER_CALLLOG_PHONEACCOUNTUTILS_H__

#include <elastos/core/Object.h>
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Graphics.h"
#include "Elastos.Droid.Telecom.h"

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Graphics::Drawable::IDrawable;
using Elastos::Droid::Telecom::IPhoneAccount;
using Elastos::Droid::Telecom::IPhoneAccountHandle;

namespace Elastos {
namespace Droid {
namespace Dialer {
namespace CallLog {

/**
 * Methods to help extract {@code PhoneAccount} information from database and Telecomm sources
 */
class PhoneAccountUtils
{
public:
    /**
     * Generate account info from data in Telecomm database
     */
    static CARAPI_(AutoPtr<IPhoneAccountHandle>) GetAccount(
        /* [in] */ const String& componentString,
        /* [in] */ const String& accountId);

    /**
     * Generate account icon from data in Telecomm database
     */
    static CARAPI_(AutoPtr<IDrawable>) GetAccountIcon(
        /* [in] */ IContext* context,
        /* [in] */ IPhoneAccountHandle* phoneAccount);

    /**
     * Generate account label from data in Telecomm database
     */
    static CARAPI_(String) GetAccountLabel(
        /* [in] */ IContext* context,
        /* [in] */ IPhoneAccountHandle* phoneAccount);

private:
    /**
     * Retrieve the account metadata, but if the account does not exist or the device has only a
     * single registered and enabled account, return null.
     */
    static CARAPI_(AutoPtr<IPhoneAccount>) GetAccountOrNull(
        /* [in] */ IContext* context,
        /* [in] */ IPhoneAccountHandle* phoneAccount);
};

} // CallLog
} // Dialer
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_DIALER_CALLLOG_PHONEACCOUNTUTILS_H__

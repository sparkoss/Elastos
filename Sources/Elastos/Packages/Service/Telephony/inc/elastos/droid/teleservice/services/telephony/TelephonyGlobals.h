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

#ifndef  __ELASTOS_DROID_SERVICES_TELEPHONY_TELEPHONEGLOABLE_H__
#define  __ELASTOS_DROID_SERVICES_TELEPHONY_TELEPHONEGLOABLE_H__

#include "_Elastos.Droid.TeleService.h"
#include "elastos/droid/teleservice/services/telephony/TtyManager.h"
#include <Elastos.Droid.Content.h>
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;

namespace Elastos {
namespace Droid {
namespace TeleService {
namespace Services {
namespace Telephony {

/**
 * Singleton entry point for the telephony-services app. Initializes ongoing systems relating to
 * PSTN calls. This is started when the device starts and will be restarted automatically
 * if it goes away for any reason (e.g., crashes).
 * This is separate from the actual Application class because we only support one instance of this
 * app - running as the default user. {@link com.android.phone.PhoneApp} determines whether or not
 * we are running as the default user and if we are, then initializes and runs this class's
 * {@link #onCreate}.
 */
class TelephonyGlobals
    : public Object
{
public:
    TO_STRING_IMPL("TelephonyGlobals")

    /**
     * Persists the specified parameters.
     *
     * @param context The application context.
     */
    TelephonyGlobals(
        /* [in] */ IContext* context);

    static CARAPI_(AutoPtr<TelephonyGlobals>) GetInstance(
        /* [in] */ IContext* context);

    CARAPI OnCreate();

private:
    static AutoPtr<TelephonyGlobals> sInstance;

    static Object slock;

    /** The application context. */
    AutoPtr<IContext> mContext;

    AutoPtr<TtyManager> mTtyManager;
};

} // namespace Telephony
} // namespace Services
} // namespace TeleService
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SERVICES_TELEPHONY_TELEPHONEGLOABLE_H__

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

#ifndef  __ELASTOS_DROID_PHONE_CDMAPHONECALLSTATE_H__
#define  __ELASTOS_DROID_PHONE_CDMAPHONECALLSTATE_H__

#include "_Elastos.Droid.TeleService.h"
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Object.h>

using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace TeleService {
namespace Phone {

/**
 * Class to internally keep track of Call states to maintain
 * information for Call Waiting and 3Way for CDMA instance of Phone App.
 *
 * Explanation for PhoneApp's Call states and why it is required:
 * IDLE - When no call is going on. This is just required as default state to reset the PhoneApp
 *        call state to when the complete call gets disconnected
 * SINGLE_ACTIVE - When only single call is active.
 *        In normal case(on a single call) this state would be similar for FW's state of ACTIVE
 *        call or phone state of OFFHOOK, but in more complex conditions e.g. when phone is already
 *        in a CONF_CALL state and user rejects a CW, which basically tells the PhoneApp that the
 *        Call is back to a single call, the FW's state still would remain ACTIVE or OFFHOOK and
 *        isGeneric would still be true. At this condition PhoneApp does need to enable the
 *        "Add Call" menu item and disable the "Swap" and "Merge" options
 * THRWAY_ACTIVE - When user initiate an outgoing call when already on a call.
 *        fgCall can have more than one connections from various scenarios (accepting the CW or
 *        making a 3way call) but once we are in this state and one of the parties drops off,
 *        when the user originates another call we need to remember this state to update the menu
 *        items accordingly. FW currently does not differentiate this condition hence PhoneApp
 *        needs to maintain it.
 * CONF_CALL - When the user merges two calls or on accepting the Call waiting call.
 *        This is required cause even though a call might be generic but that does not mean it is
 *        in conference. We can take the same example mention in the SINGLE_ACTIVE state.
 *
 * TODO: Eventually this state information should be maintained by Telephony FW.
 */
class CdmaPhoneCallState
    : public Object
{
public:
    /**
     * Allowable values for the PhoneCallState.
     *   IDLE - When no call is going on.
     *   SINGLE_ACTIVE - When only single call is active
     *   THRWAY_ACTIVE - When user initiate an outgoing call when already on a call
     *   CONF_CALL - When the user merges two calls or on accepting the Call waiting call
     */
    enum PhoneCallState {
        IDLE,
        SINGLE_ACTIVE,
        THRWAY_ACTIVE,
        CONF_CALL
    };

public:
    TO_STRING_IMPL("CdmaPhoneCallState")

    CdmaPhoneCallState()
        : mPreviousCallState(IDLE)
        , mCurrentCallState(IDLE)
        , mThreeWayCallOrigStateDialing(FALSE)
        , mAddCallMenuStateAfterCW(TRUE)
    {}

    /**
     * Initialize PhoneCallState related members - constructor
     */
    CARAPI CdmaPhoneCallStateInit();

    /**
     * Returns the current call state
     */
    CARAPI GetCurrentCallState(
        /* [out] */ PhoneCallState* state);

    /**
     * Set current and previous PhoneCallState's
     */
    CARAPI SetCurrentCallState(
        /* [in] */ PhoneCallState newState);

    /**
     * Return 3Way display information
     */
    CARAPI IsThreeWayCallOrigStateDialing(
        /* [out] */ Boolean* result);

    /**
     * Set 3Way display information
     */
    CARAPI SetThreeWayCallOrigState(
        /* [in] */ Boolean newState);

    /**
     * Return information for enabling/disabling "Add Call" menu item
     */
    CARAPI GetAddCallMenuStateAfterCallWaiting(
        /* [out] */ Boolean* result);

    /**
     * Set mAddCallMenuStateAfterCW to enabling/disabling "Add Call" menu item
     */
    CARAPI SetAddCallMenuStateAfterCallWaiting(
        /* [in] */ Boolean newState);

    /**
     * Return previous PhoneCallState's
     */
    CARAPI GetPreviousCallState(
        /* [out] */ PhoneCallState* state);

    /**
     * Reset all PhoneCallState
     */
    CARAPI ResetCdmaPhoneCallState();

private:
    // For storing current and previous PhoneCallState's
    PhoneCallState mPreviousCallState;
    PhoneCallState mCurrentCallState;

    // Boolean to track 3Way display state
    Boolean mThreeWayCallOrigStateDialing;

    // Flag to indicate if the "Add Call" menu item in an InCallScreen is OK
    // to be displayed after a Call Waiting call was ignored or timed out
    Boolean mAddCallMenuStateAfterCW;
};

} // namespace Phone
} // namespace TeleService
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_PHONE_CDMAPHONECALLSTATE_H__

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

#include "elastos/droid/systemui/statusbar/policy/CUserInfoControllerReceiver.h"
#include "elastos/droid/systemui/statusbar/policy/UserInfoController.h"

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace StatusBar {
namespace Policy {

CAR_OBJECT_IMPL(CUserInfoControllerReceiver)
ECode CUserInfoControllerReceiver::constructor(
    /* [in] */ IUserInfoController* controller)
{
    mHost = (UserInfoController*)controller;
    return BroadcastReceiver::constructor();
}

ECode CUserInfoControllerReceiver::OnReceive(
    /* [in] */ IContext* context,
    /* [in] */ IIntent* intent)
{
    String action;
    intent->GetAction(&action);
    if (IIntent::ACTION_USER_SWITCHED.Equals(action)) {
        mHost->ReloadUserInfo();
    }
    else if (IIntent::ACTION_CONFIGURATION_CHANGED.Equals(action)) {
        if (mHost->mUseDefaultAvatar) {
            mHost->ReloadUserInfo();
        }
    }
    return NOERROR;
}

}// namespace Policy
}// namespace StatusBar
}// namespace SystemUI
}// namespace Droid
}// namespace Elastos

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

#ifndef __ELASTOS_DROID_NET_CDHCPSTATEMACHINEHELPER_H__
#define __ELASTOS_DROID_NET_CDHCPSTATEMACHINEHELPER_H__

#include "_Elastos_Droid_Net_CDhcpStateMachineHelper.h"
#include <elastos/core/Singleton.h>

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Internal::Utility::IStateMachine;

using Elastos::Core::Singleton;

namespace Elastos {
namespace Droid {
namespace Net {

/**
 * StateMachine that interacts with the native DHCP client and can talk to
 * a controller that also needs to be a StateMachine
 *
 * The Dhcp state machine provides the following features:
 * - Wakeup and renewal using the native DHCP client  (which will not renew
 *   on its own when the device is in suspend state and this can lead to device
 *   holding IP address beyond expiry)
 * - A notification right before DHCP request or renewal is started. This
 *   can be used for any additional setup before DHCP. For example, wifi sets
 *   BT-Wifi coex settings right before DHCP is initiated
 *
 * @hide
 */
CarClass(CDhcpStateMachineHelper)
    , public Singleton
    , public IDhcpStateMachineHelper
{
public:
    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL()

    CARAPI MakeDhcpStateMachine(
        /* [in] */ IContext* context,
        /* [in] */ IStateMachine* controller,
        /* [in] */ const String& intf,
        /* [out] */ IDhcpStateMachine** result);
};

} // namespace Net
} // namespace Droid
} // namespace Elastos

#endif //  __ELASTOS_DROID_NET_CDHCPSTATEMACHINEHELPER_H__

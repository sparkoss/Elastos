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

#ifndef  __ELASTOS_DROID_LAUNCHER2_CPACKAGECHANGEDRECEIVER_H__
#define  __ELASTOS_DROID_LAUNCHER2_CPACKAGECHANGEDRECEIVER_H__

#include "_Elastos.Droid.Launcher2.h"
#include "_Elastos_Droid_Launcher2_CPackageChangedReceiver.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/content/BroadcastReceiver.h"
#include "Elastos.Droid.Content.h"

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::IIntent;
using Elastos::Droid::Content::BroadcastReceiver;

namespace Elastos {
namespace Droid {
namespace Launcher2 {

CarClass(CPackageChangedReceiver)
    , public BroadcastReceiver
{
public:
    CAR_OBJECT_DECL();

    CPackageChangedReceiver();

    CARAPI constructor();

    //@Override
    CARAPI OnReceive(
        /* [in] */ IContext* context,
        /* [in] */ IIntent* intent);
};

} // namespace Launcher2
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_LAUNCHER2_CPACKAGECHANGEDRECEIVER_H__
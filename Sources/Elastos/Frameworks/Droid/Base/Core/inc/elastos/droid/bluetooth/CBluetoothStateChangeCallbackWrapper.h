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

#ifndef __ELASTOS_DROID_BLUETOOTH_CBLUETOOTHSTATECHANGECALLBACKWRAPPER_H__
#define __ELASTOS_DROID_BLUETOOTH_CBLUETOOTHSTATECHANGECALLBACKWRAPPER_H__

#include "Elastos.Droid.Bluetooth.h"
#include "Elastos.Droid.Os.h"
#include "_Elastos_Droid_Bluetooth_CBluetoothStateChangeCallbackWrapper.h"
#include "elastos/droid/ext/frameworkdef.h"
#include <elastos/core/Object.h>
//#include "elastos/droid/bluetooth/CBluetoothAdapter.h"
using Elastos::Droid::Os::IBinder;

namespace Elastos {
namespace Droid {
namespace Bluetooth {

CarClass(CBluetoothStateChangeCallbackWrapper)
    , public Object
    , public IIBluetoothStateChangeCallback
    , public IBinder
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CBluetoothStateChangeCallbackWrapper();

    CARAPI OnBluetoothStateChange(
        /* [in] */ Boolean on);

    CARAPI constructor(
        /* [in] */ IInterface* callback);

    CARAPI ToString(
        /* [out] */ String* info)
    {
        VALIDATE_NOT_NULL(info)
        return Object::ToString(info);
    }
private:
    //AutoPtr<CBluetoothAdapter::IBluetoothStateChangeCallback> mCallback;
    AutoPtr<IIBluetoothStateChangeCallback> mCallback;
};

} // namespace Bluetooth
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_BLUETOOTH_CBLUETOOTHSTATECHANGECALLBACKWRAPPER_H__

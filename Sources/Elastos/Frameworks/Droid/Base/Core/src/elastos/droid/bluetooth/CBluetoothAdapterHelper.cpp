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

#include "elastos/droid/bluetooth/CBluetoothAdapterHelper.h"
#include "elastos/droid/bluetooth/CBluetoothAdapter.h"
#include "elastos/droid/ext/frameworkext.h"

namespace Elastos {
namespace Droid {
namespace Bluetooth {

CAR_INTERFACE_IMPL(CBluetoothAdapterHelper, Singleton, IBluetoothAdapterHelper);

CAR_SINGLETON_IMPL(CBluetoothAdapterHelper);

ECode CBluetoothAdapterHelper::GetDefaultAdapter(
    /* [out] */ Elastos::Droid::Bluetooth::IBluetoothAdapter** adapter)
{
    VALIDATE_NOT_NULL(adapter);

    AutoPtr<IBluetoothAdapter> _adapter = CBluetoothAdapter::GetDefaultAdapter();
    *adapter = _adapter;
    REFCOUNT_ADD(*adapter)
    return NOERROR;
}

ECode CBluetoothAdapterHelper::CheckBluetoothAddress(
    /* [in] */ const String& address,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result);

    *result = CBluetoothAdapter::CheckBluetoothAddress(address);

    return NOERROR;
}

}
}
}


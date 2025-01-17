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

#ifndef __ELASTOS_DROID_HARDWARE_CAMERA2_LEGECY_LEGACYEXCEPTIONUTILES_H__
#define __ELASTOS_DROID_HARDWARE_CAMERA2_LEGECY_LEGACYEXCEPTIONUTILES_H__

#include "Elastos.Droid.Hardware.h"
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Object.h>

using Elastos::Core::Object;
using Elastos::Utility::IList;
using Elastos::Utility::ICollection;
using Elastos::Utility::IArrayList;

namespace Elastos {
namespace Droid {
namespace Hardware {
namespace Camera2 {
namespace Legacy {

class LegacyExceptionUtils
    : public Object
    , public ILegacyExceptionUtils
{
public:
    CAR_INTERFACE_DECL()

    static CARAPI ThrowOnError(
        /* [in] */ Int32 errorFlag,
        /* [out] */ Int32* result);

private:
    LegacyExceptionUtils();

private:
    static const String TAG;

};

} // namespace Legacy
} // namespace Camera2
} // namespace Hardware
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_HARDWARE_CAMERA2_LEGECY_LEGACYEXCEPTIONUTILES_H__

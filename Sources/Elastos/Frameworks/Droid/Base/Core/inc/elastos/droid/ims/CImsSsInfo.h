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

#ifndef __ELASTOS_DROID_IMS_CIMSSSINFO_H__
#define __ELASTOS_DROID_IMS_CIMSSSINFO_H__

#include "_Elastos_Droid_Ims_CImsSsInfo.h"
#include "elastos/droid/ext/frameworkdef.h"
#include <elastos/core/Object.h>

namespace Elastos {
namespace Droid {
namespace Ims {

CarClass(CImsSsInfo)
    , public Object
    , public IImsSsInfo
    , public IParcelable
{
public:
    CImsSsInfo();

    virtual ~CImsSsInfo();

    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CARAPI constructor();

    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

    CARAPI ToString(
        /* [out] */ String* result);

public:
    // 0: disabled, 1: enabled
    Int32 mStatus;
    String mIcbNum;
};

} // namespace Ims
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_IMS_CIMSSSINFO_H__

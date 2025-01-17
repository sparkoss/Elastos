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

#ifndef __ELASTOS_DROID_INTERNAL_TELEPHONY_UUSINFO_H__
#define __ELASTOS_DROID_INTERNAL_TELEPHONY_UUSINFO_H__

#include "_Elastos.Droid.Internal.h"
#include <elastos/core/Object.h>

using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Telephony {

class UUSInfo
    : public Object
    , public IUUSInfo
{
public:
    CAR_INTERFACE_DECL()

    UUSInfo();

    CARAPI constructor(
        /* [in] */ Int32 uusType,
        /* [in] */ Int32 uusDcs,
        /* [in] */ ArrayOf<Byte>* uusData);

    CARAPI GetDcs(
        /* [out] */ Int32* result);

    CARAPI SetDcs(
        /* [in] */ Int32 uusDcs);

    CARAPI GetType(
        /* [out] */ Int32* result);

    CARAPI SetType(
        /* [in] */ Int32 uusType);

    CARAPI GetUserData(
        /* [out] */ ArrayOf<Byte>** result);

    CARAPI SetUserData(
        /* [in] */ ArrayOf<Byte>* uusData);

private:
    Int32 mUusType;

    Int32 mUusDcs;

    AutoPtr<ArrayOf<Byte> > mUusData;
};

} // namespace Telephony
} // namespace Internal
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INTERNAL_TELEPHONY_UUSINFO_H__

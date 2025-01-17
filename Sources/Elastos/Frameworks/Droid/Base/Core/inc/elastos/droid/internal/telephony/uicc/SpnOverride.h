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

#ifndef __ELASTOS_DROID_INTERNAL_TELEPHONY_UICC_SPNOVERRIDE_H__
#define __ELASTOS_DROID_INTERNAL_TELEPHONY_UICC_SPNOVERRIDE_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/core/Object.h"

using Elastos::Utility::IHashMap;

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Telephony {
namespace Uicc {

class SpnOverride
    : public Object
    , public ISpnOverride
{
public:
    CAR_INTERFACE_DECL();

    SpnOverride();

    virtual CARAPI ContainsCarrier(
        /* [in] */ const String& carrier,
        /* [out] */ Boolean* result);

    virtual CARAPI GetSpn(
        /* [in] */ const String& carrier,
        /* [out] */ String* result);

private:
    CARAPI_(void) LoadSpnOverrides();

public:
    static const String LOGTAG;
    static const String PARTNER_SPN_OVERRIDE_PATH;

private:
     AutoPtr<IHashMap> mCarrierSpnMap;/*<String, String*/
};

} // namespace Uicc
} // namespace Telephony
} // namespace Internal
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INTERNAL_TELEPHONY_UICC_SPNOVERRIDE_H__

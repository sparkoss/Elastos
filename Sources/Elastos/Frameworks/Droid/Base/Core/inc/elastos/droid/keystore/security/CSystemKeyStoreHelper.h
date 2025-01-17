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

#ifndef __ELASTOS_DROID_KEYSTORE_SECURITY_CSYSTEMKEYSTOREHELPER_H__
#define __ELASTOS_DROID_KEYSTORE_SECURITY_CSYSTEMKEYSTOREHELPER_H__

#include "_Elastos_Droid_KeyStore_Security_CSystemKeyStoreHelper.h"
#include "elastos/droid/keystore/security/SystemKeyStore.h"
#include "elastos/core/Singleton.h"

namespace Elastos {
namespace Droid {
namespace KeyStore {
namespace Security {

CarClass(CSystemKeyStoreHelper)
    , public Singleton
    , public ISystemKeyStoreHelper
{
public:
    CAR_INTERFACE_DECL()
    CAR_SINGLETON_DECL()

    CARAPI GetInstance(
        /* [out] */ ISystemKeyStore** store);

    CARAPI ToHexString(
        /* [in] */ ArrayOf<Byte>* keyData,
        /* [out] */ String* hex);

};

} // namespace Security
} // namespace KeyStore
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_KEYSTORE_SECURITY_CSYSTEMKEYSTOREHELPER_H__

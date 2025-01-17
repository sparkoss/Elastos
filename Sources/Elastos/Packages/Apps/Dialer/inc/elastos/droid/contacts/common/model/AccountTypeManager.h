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

#ifndef __ELASTOS_DROID_CONTACTS_COMMON_MODEL_ACCOUNTTYPEMANAGER_H__
#define __ELASTOS_DROID_CONTACTS_COMMON_MODEL_ACCOUNTTYPEMANAGER_H__

#include "Elastos.Droid.Content.h"
#include "_Elastos.Droid.Dialer.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace Contacts {
namespace Common {
namespace Model {

/**
 * Represents an IM data item, wrapping the columns in
 * {@link ContactsContract.CommonDataKinds.Im}.
 */
class AccountTypeManager
    : public Object
    , public IAccountTypeManager
{
public:
    /**
     * Requests the singleton instance of {@link AccountTypeManager} with data bound from
     * the available authenticators. This method can safely be called from the UI thread.
     */
    static CARAPI_(AutoPtr<IAccountTypeManager>) GetInstance(
        /* [in] */ IContext* context);

};

} // Model
} // Common
} // Contacts
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_CONTACTS_COMMON_MODEL_ACCOUNTTYPEMANAGER_H__

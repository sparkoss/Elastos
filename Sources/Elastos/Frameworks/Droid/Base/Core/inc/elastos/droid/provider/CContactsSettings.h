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

#ifndef __ELASTOS_DROID_PROVIDER_CCONTACTSSETTINGS_H__
#define __ELASTOS_DROID_PROVIDER_CCONTACTSSETTINGS_H__

#include "_Elastos_Droid_Provider_CContactsSettings.h"
#include <elastos/core/Singleton.h>

using Elastos::Droid::Content::IContentResolver;
using Elastos::Droid::Net::IUri;

namespace Elastos {
namespace Droid {
namespace Provider {

CarClass(CContactsSettings)
    , public Singleton
    , public IBaseColumns
    , public IContactsSettings
    , public IContactsSettingsColumns
{
public:
    CAR_SINGLETON_DECL()

    CAR_INTERFACE_DECL()

    /**
     * no public constructor since this is a utility class
     */
    CARAPI constructor();

    /**
     * The content:// style URL for this table
     * @deprecated see {@link android.provider.ContactsContract}
     */
    //@Deprecated
    CARAPI GetCONTENT_URI(
        /* [out] */ IUri** uri);

    /**
     * @deprecated see {@link android.provider.ContactsContract}
     */
    //@Deprecated
    CARAPI GetSetting(
        /* [in] */ IContentResolver* cr,
        /* [in] */ const String& account,
        /* [in] */ const String& key,
        /* [out] */ String* setting);

    /**
     * @deprecated see {@link android.provider.ContactsContract}
     */
    //@Deprecated
    CARAPI SetSetting(
        /* [in] */ IContentResolver* cr,
        /* [in] */ const String& account,
        /* [in] */ const String& key,
        /* [in] */ const String& value);
};

} // Provider
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_PROVIDER_CCONTACTSSETTINGS_H__

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

#ifndef __ELASTOS_DROID_PROVIDER_CCONTACTSCONTRACTSTREAMITEMS_H__
#define __ELASTOS_DROID_PROVIDER_CCONTACTSCONTRACTSTREAMITEMS_H__

#include "_Elastos_Droid_Provider_CContactsContractStreamItems.h"
#include <elastos/core/Singleton.h>

using Elastos::Droid::Net::IUri;

namespace Elastos {
namespace Droid {
namespace Provider {

CarClass(CContactsContractStreamItems)
    , public Singleton
    , public IContactsContractStreamItems
    , public IBaseColumns
    , public IContactsContractStreamItemsColumns
{
public:
    CAR_SINGLETON_DECL()

    CAR_INTERFACE_DECL()

    /**
     * The content:// style URI for this table, which handles social network stream
     * updates for the user's contacts.
     */
    CARAPI GetCONTENT_URI(
        /* [out] */ IUri** uri);

    /**
     * <p>
     * A content:// style URI for the photos stored in a sub-table underneath
     * stream items.  This is only used for inserts, and updates - queries and deletes
     * for photos should be performed by appending
     * {@link StreamItems.StreamItemPhotos#CONTENT_DIRECTORY} path to URIs for a
     * specific stream item.
     * </p>
     * <p>
     * When using this URI, the stream item ID for the photo(s) must be identified
     * in the {@link ContentValues} passed in.
     * </p>
     */
    CARAPI GetCONTENTPHOTOURI(
        /* [out] */ IUri** uri);

    /**
     * This URI allows the caller to query for the maximum number of stream items
     * that will be stored under any single raw contact.
     */
    CARAPI GetCONTENTLIMITURI(
        /* [out] */ IUri** uri);
};

} //Provider
} //Droid
} //Elastos

#endif //__CCONTACTSCONTRACTRAWCONTACTS_H__

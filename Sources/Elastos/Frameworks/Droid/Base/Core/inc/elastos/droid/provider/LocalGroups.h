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

#ifndef __ELASTOS_DROID_PROVIDER_LOCALGROUPS_H__
#define __ELASTOS_DROID_PROVIDER_LOCALGROUPS_H__

#include "elastos/droid/ext/frameworkext.h"
#include "_Elastos.Droid.Net.h"
#include "_Elastos.Droid.Database.h"
#include "_Elastos.Droid.Content.h"
#include "_Elastos.Droid.Provider.h"

using Elastos::Droid::Net::IUri;
using Elastos::Droid::Database::ICursor;
using Elastos::Droid::Content::IContentResolver;

namespace Elastos {
namespace Droid {
namespace Provider {

class LocalGroups
{
public:
    class Group
    {
    public:
        static CARAPI RestoreGroup(
            /* [in] */ ICursor* cursor,
            /* [out] */ ILocalGroupsGroup** group);

        static CARAPI RestoreGroupById(
            /* [in] */ IContentResolver* cr,
            /* [in] */ Int64 groupId,
            /* [out] */ ILocalGroupsGroup** group);
    };

public:
    static const AutoPtr<IUri> AUTHORITY_URI;

    static const AutoPtr<IUri> CONTENT_URI;
};

} // namespace Provider
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_PROVIDER_LOCALGROUPS_H__

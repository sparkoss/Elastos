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

#ifndef  __ELASTOS_DROID_LAUNCHER2_PAGEDVIEWICONCACHE_H__
#define  __ELASTOS_DROID_LAUNCHER2_PAGEDVIEWICONCACHE_H__

#include "_Elastos.Droid.Launcher2.h"
#include "elastos/droid/ext/frameworkext.h"
#include "Elastos.Droid.AppWidget.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Graphics.h"
#include "Elastos.CoreLibrary.Utility.h"
#include <elastos/core/Object.h>

using Elastos::Droid::AppWidget::IAppWidgetProviderInfo;
using Elastos::Droid::Content::IComponentName;
using Elastos::Droid::Content::Pm::IResolveInfo;
using Elastos::Droid::Graphics::IBitmap;
using Elastos::Core::Object;
using Elastos::Utility::IList;
using Elastos::Utility::IArrayList;
using Elastos::Utility::IHashSet;
using Elastos::Utility::IHashMap;

namespace Elastos {
namespace Droid {
namespace Launcher2 {

/**
 * Simple cache mechanism for PagedView outlines.
 */
class PagedViewIconCache
    : public Object
{
public:
    class Key
        : public Object
        , public IKey
    {
    public:
        enum Type {
            ApplicationInfoKey,
            AppWidgetProviderInfoKey,
            ResolveInfoKey
        };

    public:
        CAR_INTERFACE_DECL();

        CARAPI constructor(
            /* [in] */ IApplicationInfo* info);

        CARAPI constructor(
            /* [in] */ IResolveInfo* info);

        CARAPI constructor(
            /* [in] */ IAppWidgetProviderInfo* info);

        CARAPI_(Boolean) IsKeyType(
            /* [in] */ Type t);

        //@Override
        CARAPI Equals(
            /* [in] */ IInterface* obj,
            /* [out] */ Boolean* isEqual);

        //@Override
        CARAPI GetHashCode(
            /* [out] */ Int32* code);

    private:
        CARAPI_(AutoPtr<IComponentName>) GetComponentName();

    private:
        AutoPtr<IComponentName> mComponentName;
        Type mType;
    };

public:
    PagedViewIconCache();

    CARAPI Clear();

    /** Removes all the keys to applications that aren't in the passed in collection */
    CARAPI RetainAllApps(
        /* [in] */ IArrayList* keys);

    /** Removes all the keys to shortcuts that aren't in the passed in collection */
    CARAPI RetainAllShortcuts(
        /* [in] */ IList* keys);

    /** Removes all the keys to widgets that aren't in the passed in collection */
    CARAPI RetainAllAppWidgets(
        /* [in] */ IList* keys);

    CARAPI AddOutline(
        /* [in] */ IKey* key,
        /* [in] */ IBitmap* b);

    CARAPI RemoveOutline(
        /* [in] */ IKey* key) ;

    CARAPI GetOutline(
        /* [in] */ IKey* key,
        /* [out] */ IBitmap** map);

private:
    CARAPI RetainAll(
        /* [in] */ IHashSet* keysToKeep,
        /* [in] */ Key::Type t);

private:
    AutoPtr<IHashMap> mIconOutlineCache;
};

} // namespace Launcher2
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_LAUNCHER2_PAGEDVIEWICONCACHE_H__
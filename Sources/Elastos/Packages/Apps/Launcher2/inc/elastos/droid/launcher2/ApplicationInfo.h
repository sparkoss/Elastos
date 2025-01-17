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

#ifndef  __ELASTOS_DROID_LAUNCHER2_APPLICATIOMINFO_H__
#define  __ELASTOS_DROID_LAUNCHER2_APPLICATIOMINFO_H__

#include "_Elastos.Droid.Launcher2.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/launcher2/ItemInfo.h"
#include "elastos/droid/launcher2/IconCache.h"
#include "elastos/droid/launcher2/ShortcutInfo.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.CoreLibrary.Utility.h"

using Elastos::Droid::Content::IComponentName;
using Elastos::Droid::Content::Pm::ILauncherActivityInfo;
using Elastos::Droid::Os::IUserHandle;
using Elastos::Utility::IHashMap;
using Elastos::Utility::IArrayList;

namespace Elastos {
namespace Droid {
namespace Launcher2 {

/**
 * Represents an app in AllAppsView.
 */
class ApplicationInfo
    : public ItemInfo
    , public IApplicationInfo
{
public:
    CAR_INTERFACE_DECL();

    ApplicationInfo();

    CARAPI constructor();

    /**
     * Must not hold the Context.
     */
    CARAPI constructor(
        /* [in] */ ILauncherActivityInfo* info,
        /* [in] */ IUserHandle* user,
        /* [in] */ IconCache* iconCache,
        /* [in] */ IHashMap* labelCache);

    CARAPI constructor(
        /* [in] */ ApplicationInfo* info);

    /**
     * Creates the application intent based on a component name and various launch flags.
     * Sets {@link #itemType} to {@link LauncherSettings.BaseLauncherColumns#ITEM_TYPE_APPLICATION}.
     *
     * @param className the class name of the component representing the intent
     * @param launchFlags the launch flags
     */
    CARAPI SetActivity(
        /* [in] */ IComponentName* className,
        /* [in] */ Int32 launchFlags);

    //@Override
    CARAPI ToString(
        /* [out] */ String* str);

    static CARAPI_(void) DumpApplicationInfoList(
        /* [in] */ const String& tag,
        /* [in] */ const String& label,
        /* [in] */ IArrayList* list);

    CARAPI MakeShortcut(
        /* [out] */ IShortcutInfo** info);

public:
    /**
     * The intent used to start the application.
     */
    AutoPtr<IIntent> mIntent;

    /**
     * A bitmap version of the application icon.
     */
    AutoPtr<IBitmap> mIconBitmap;

    /**
     * The time at which the app was first installed.
     */
    Int64 mFirstInstallTime;

    AutoPtr<IComponentName> mComponentName;

    Int32 mFlags;

private:
    static const String TAG;
};

} // namespace Launcher2
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_LAUNCHER2_APPLICATIOMINFO_H__
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

#ifndef __ELASTOS_DROID_APP_CACTIVITYMANAGERRECENTTASKINFO_H__
#define __ELASTOS_DROID_APP_CACTIVITYMANAGERRECENTTASKINFO_H__

#include "_Elastos_Droid_App_CActivityManagerRecentTaskInfo.h"
#include <elastos/core/Object.h>

using Elastos::Core::ICharSequence;
using Elastos::Droid::Content::IIntent;
using Elastos::Droid::Content::IComponentName;

namespace Elastos {
namespace Droid {
namespace App {

/**
 * Information you can retrieve about tasks that the user has most recently
 * started or visited.
 */
CarClass(CActivityManagerRecentTaskInfo)
    , public Object
    , public IActivityManagerRecentTaskInfo
    , public IParcelable
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CActivityManagerRecentTaskInfo();

    ~CActivityManagerRecentTaskInfo();

    CARAPI constructor();

    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    CARAPI GetId(
        /* [out] */ Int32* id);

    CARAPI SetId(
        /* [in] */ Int32 id);

    CARAPI GetPersistentId(
        /* [out] */ Int32* id);

    CARAPI SetPersistentId(
        /* [in] */ Int32 id);

    CARAPI GetBaseIntent(
        /* [out] */ IIntent** baseIntent);

    CARAPI SetBaseIntent(
        /* [in] */ IIntent* baseIntent);

    CARAPI GetOrigActivity(
        /* [out] */ IComponentName** origActivity);

    CARAPI SetOrigActivity(
        /* [in] */ IComponentName* origActivity);

    CARAPI GetDescription(
        /* [out] */ ICharSequence** description);

    CARAPI SetDescription(
        /* [in] */ ICharSequence* description);

    CARAPI GetStackId(
        /* [out] */ Int32* stackId);

    CARAPI SetStackId(
        /* [in] */ Int32 stackId);

    CARAPI GetUserId(
        /* [out] */ Int32* userId);

    CARAPI SetUserId(
        /* [in] */ Int32 userId);

    CARAPI GetFirstActiveTime(
        /* [out] */ Int64* firstActiveTime);

    CARAPI SetFirstActiveTime(
        /* [in] */ Int64 firstActiveTime);

    CARAPI GetLastActiveTime(
        /* [out] */ Int64* lastActiveTime);

    CARAPI SetLastActiveTime(
        /* [in] */ Int64 lastActiveTime);

    /**
     * The recent activity values for the highest activity in the stack to have set the values.
     * {@link Activity#setTaskDescription(android.app.ActivityManager.TaskDescription)}.
     */
    CARAPI SetTaskDescription(
        /* [in] */ IActivityManagerTaskDescription* description);

    CARAPI GetTaskDescription(
        /* [out] */ IActivityManagerTaskDescription** description);

    /**
     * Task affiliation for grouping with other tasks.
     */
    CARAPI GetAffiliatedTaskId(
        /* [out] */ Int32* id);

    CARAPI SetAffiliatedTaskId(
        /* [in] */ Int32 id);

    CARAPI GetAffiliatedTaskColor(
        /* [out] */ Int32* color);

    CARAPI SetAffiliatedTaskColor(
        /* [in] */ Int32 color);

    CARAPI ToString(
        /* [out] */ String* str);
private:
    /**
     * If this task is currently running, this is the identifier for it.
     * If it is not running, this will be -1.
     */
    Int32 mId;

    /**
     * The true identifier of this task, valid even if it is not running.
     */
    Int32 mPersistentId;

    /**
     * The original Intent used to launch the task.  You can use this
     * Intent to re-launch the task (if it is no longer running) or bring
     * the current task to the front.
     */
    AutoPtr<IIntent> mBaseIntent;

    /**
     * If this task was started from an alias, this is the actual
     * activity component that was initially started; the component of
     * the baseIntent in this case is the name of the actual activity
     * implementation that the alias referred to.  Otherwise, this is null.
     */
    AutoPtr<IComponentName> mOrigActivity;

    /**
     * Description of the task's last state.
     */
    AutoPtr<ICharSequence> mDescription;


    /**
     * The id of the ActivityStack this Task was on most recently.
     * @hide
     */
    Int32 mStackId;

    /**
     * The id of the user the task was running as.
     * @hide
     */
    Int32 mUserId;

    /**
     * The first time this task was active.
     * @hide
     */
    Int64 mFirstActiveTime;

    /**
     * The last time this task was active.
     * @hide
     */
    Int64 mLastActiveTime;

    /**
     * The recent activity values for the highest activity in the stack to have set the values.
     * {@link Activity#setTaskDescription(android.app.ActivityManager.TaskDescription)}.
     */
    AutoPtr<IActivityManagerTaskDescription> mTaskDescription;

    /**
     * Task affiliation for grouping with other tasks.
     */
    Int32 mAffiliatedTaskId;

    /**
     * Task affiliation color of the source task with the affiliated task id.
     *
     * @hide
     */
    Int32 mAffiliatedTaskColor;
};

} // namespace App
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_APP_CACTIVITYMANAGERRECENTTASKINFO_H__

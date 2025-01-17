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

#ifndef  __ELASTOS_DROID_SYSTEMUI_RECENTS_ALTERNATERECENTSCOMPONENT_H__
#define  __ELASTOS_DROID_SYSTEMUI_RECENTS_ALTERNATERECENTSCOMPONENT_H__

#include "_Elastos.Droid.SystemUI.h"
#include "Elastos.Droid.App.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Graphics.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.View.h"
#include "Elastos.CoreLibrary.Utility.Concurrent.h"
#include "elastos/droid/content/BroadcastReceiver.h"
#include <elastos/core/Runnable.h>
#include "elastos/droid/systemui/recents/RecentsConfiguration.h"
#include "elastos/droid/systemui/recents/misc/SystemServicesProxy.h"
#include "elastos/droid/systemui/recents/views/TaskViewTransform.h"

using Elastos::Droid::App::IActivityManagerRunningTaskInfo;
using Elastos::Droid::App::IActivityOptions;
using Elastos::Droid::App::IActivityOptionsOnAnimationStartedListener;
using Elastos::Droid::Content::BroadcastReceiver;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::IIntent;
using Elastos::Droid::Content::Res::IConfiguration;
using Elastos::Droid::Graphics::IBitmap;
using Elastos::Droid::Graphics::IRect;
using Elastos::Droid::Os::IHandler;
using Elastos::Core::Runnable;
using Elastos::Droid::SystemUI::IRecentsComponentCallbacks;
using Elastos::Droid::SystemUI::Recents::RecentsConfiguration;
using Elastos::Droid::SystemUI::Recents::Misc::SystemServicesProxy;
using Elastos::Droid::SystemUI::Recents::Model::ITask;
using Elastos::Droid::SystemUI::Recents::Views::ITaskViewHeader;
using Elastos::Droid::SystemUI::Recents::Views::ITaskStackView;
using Elastos::Droid::SystemUI::Recents::Views::TaskViewTransform;
using Elastos::Droid::View::ILayoutInflater;
using Elastos::Droid::View::IView;
using Elastos::Utility::Concurrent::Atomic::IAtomicBoolean;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Recents {

/** A proxy implementation for the recents component */
class AlternateRecentsComponent
    : public Object
    , public IActivityOptionsOnAnimationStartedListener
    , public IAlternateRecentsComponent
{
public:
    class RecentAnimationEndedReceiver
        : public BroadcastReceiver
    {
    public:
        TO_STRING_IMPL("AlternateRecentsComponent::RecentAnimationEndedReceiver")

        CARAPI constructor(
            /* [in] */ IAlternateRecentsComponent* host);

        CARAPI OnReceive(
            /* [in] */ IContext* context,
            /* [in] */ IIntent* intent);

    private:
        AlternateRecentsComponent* mHost;
    };

private:
    class OnAnimationStartedRunnable
        : public Runnable
    {
    public:
        OnAnimationStartedRunnable(
            /* [in] */ AlternateRecentsComponent* host);

        CARAPI Run();

    private:
        AlternateRecentsComponent* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    AlternateRecentsComponent(
        /* [in] */ IContext* context);

    CARAPI OnStart();

    CARAPI OnBootCompleted();

    /** Shows the recents */
    CARAPI OnShowRecents(
        /* [in] */ Boolean triggeredFromAltTab,
        /* [in] */ IView* statusBarView);

    /** Hides the recents */
    CARAPI OnHideRecents(
        /* [in] */ Boolean triggeredFromAltTab,
        /* [in] */ Boolean triggeredFromHomeKey);

    /** Toggles the alternate recents activity */
    CARAPI OnToggleRecents(
        /* [in] */ IView* statusBarView);

    CARAPI OnPreloadRecents();

    CARAPI OnCancelPreloadingRecents();

    CARAPI ShowRelativeAffiliatedTask(
        /* [in] */ Boolean showNextTask);

    CARAPI OnShowNextAffiliatedTask();

    CARAPI OnShowPrevAffiliatedTask();

    CARAPI OnConfigurationChanged(
        /* [in] */ IConfiguration* newConfig);

    /** Prepares the header bar layout. */
    CARAPI ReloadHeaderBarLayout();

    /** Gets the top task. */
    CARAPI GetTopMostTask(
        /* [out] */ IActivityManagerRunningTaskInfo** topMostTask);

    /** Returns whether the recents is currently running */
    CARAPI IsRecentsTopMost(
        /* [in] */ IActivityManagerRunningTaskInfo* topTask,
        /* [in] */ IAtomicBoolean* isHomeTopMost,
        /* [out] */ Boolean* result);

    /** Toggles the recents activity */
    CARAPI ToggleRecentsActivity();

    /** Starts the recents activity if it is not already running */
    CARAPI StartRecentsActivity();

    /**
     * Creates the activity options for a unknown state->recents transition.
     */
    CARAPI GetUnknownTransitionActivityOptions(
        /* [out] */ IActivityOptions** ao);

    /**
     * Creates the activity options for a home->recents transition.
     */
    CARAPI GetHomeTransitionActivityOptions(
        /* [in] */ Boolean fromSearchHome,
        /* [out] */ IActivityOptions** ao);

    /**
     * Creates the activity options for an app->recents transition.  If this method sets the static
     * screenshot, then we will use that for the transition.
     */
    CARAPI GetThumbnailTransitionActivityOptions(
        /* [in] */ IActivityManagerRunningTaskInfo* topTask,
        /* [in] */ Boolean isTopTaskHome,
        /* [out] */ IActivityOptions** ao);

    /** Returns the transition rect for the given task id. */
    CARAPI GetThumbnailTransitionTransform(
        /* [in] */ Int32 runningTaskId,
        /* [in] */ Boolean isTopTaskHome,
        /* [in] */ ITask* runningTaskOut,
        /* [out] */ TaskViewTransform** ttt);

    /** Starts the recents activity */
    CARAPI StartRecentsActivity(
        /* [in] */ IActivityManagerRunningTaskInfo* topTask,
        /* [in] */ Boolean isTopTaskHome);

    /** Starts the recents activity */
    CARAPI StartAlternateRecentsActivity(
        /* [in] */ IActivityManagerRunningTaskInfo* topTask,
        /* [in] */ IActivityOptions* opts,
        /* [in] */ const String& extraFlag);

    /** Returns the last screenshot taken, this will be called by the RecentsActivity. */
    static CARAPI GetLastScreenshot(
        /* [out] */ IBitmap** lss);

    /** Recycles the last screenshot taken, this will be called by the RecentsActivity. */
    static CARAPI ConsumeLastScreenshot();

    /** Sets the RecentsComponent callbacks. */
    CARAPI SetRecentsComponentCallback(
        /* [in] */ IRecentsComponentCallbacks* cb);

    /** Notifies the callbacks that the visibility of Recents has changed. */
    static CARAPI NotifyVisibilityChanged(
        /* [in] */ Boolean visible);

    /**** OnAnimationStartedListener Implementation ****/

    // @Override
    CARAPI OnAnimationStarted();

public:
    const static Int32 sMinToggleDelay = 350;

    const static String sToggleRecentsAction;
    const static String sRecentsPackage;
    const static String sRecentsActivity;

    static AutoPtr<IBitmap> sLastScreenshot;
    static AutoPtr<IRecentsComponentCallbacks> sRecentsComponentCallbacks;

    AutoPtr<IContext> mContext;
    AutoPtr<ILayoutInflater> mInflater;
    AutoPtr<SystemServicesProxy> mSystemServicesProxy;
    AutoPtr<IHandler> mHandler;
    Boolean mBootCompleted;
    Boolean mStartAnimationTriggered;

    // Task launching
    AutoPtr<RecentsConfiguration> mConfig;
    AutoPtr<IRect> mWindowRect;
    AutoPtr<IRect> mTaskStackBounds;
    AutoPtr<IRect> mSystemInsets;
    AutoPtr<TaskViewTransform> mTmpTransform;
    Int32 mStatusBarHeight;
    Int32 mNavBarHeight;
    Int32 mNavBarWidth;

    // Header (for transition)
    AutoPtr<ITaskViewHeader> mHeaderBar;
    AutoPtr<ITaskStackView> mDummyStackView;

    // Variables to keep track of if we need to start recents after binding
    AutoPtr<IView> mStatusBarView;
    Boolean mTriggeredFromAltTab;
    Int64 mLastToggleTime;
};

} // namespace Recents
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_RECENTS_ALTERNATERECENTSCOMPONENT_H__
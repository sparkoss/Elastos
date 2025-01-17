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

#ifndef  __ELASTOS_DROID_SYSTEMUI_RECENTS_VIEWS_TASKSTACKVIEWTOUCHHANDLER_H__
#define  __ELASTOS_DROID_SYSTEMUI_RECENTS_VIEWS_TASKSTACKVIEWTOUCHHANDLER_H__

#include "elastos/droid/systemui/recents/RecentsConfiguration.h"
#include "elastos/droid/systemui/recents/views/TaskView.h"
#include "elastos/droid/systemui/recents/views/SwipeHelper.h"

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Recents {
namespace Views {

class TaskStackView;

/* Handles touch events for a TaskStackView. */
class TaskStackViewTouchHandler
    : public Object
{
private:
    class CallBack
        : public Object
        , public ISwipeHelperCallback
    {
    public:
        CAR_INTERFACE_DECL()

        CallBack(
            /* [in] */ TaskStackViewTouchHandler* host)
            : mHost(host)
        {}

        // @Override
        CARAPI GetChildAtPosition(
            /* [in] */ IMotionEvent* ev,
            /* [out] */ IView** view);

        // @Override
        CARAPI CanChildBeDismissed(
            /* [in] */ IView* v,
            /* [out] */ Boolean* result);

        // @Override
        CARAPI OnBeginDrag(
            /* [in] */ IView* v);

        // @Override
        CARAPI OnSwipeChanged(
            /* [in] */ IView* v,
            /* [in] */ Float delta);

        // @Override
        CARAPI OnChildDismissed(
            /* [in] */ IView* v);

        // @Override
        CARAPI OnSnapBackCompleted(
            /* [in] */ IView* v);

        // @Override
        CARAPI OnDragCancelled(
            /* [in] */ IView* v);

    private:
        TaskStackViewTouchHandler* mHost;
    };

public:
    TaskStackViewTouchHandler(
        /* [in] */ IContext* context,
        /* [in] */ TaskStackView* sv,
        /* [in] */ RecentsConfiguration* config,
        /* [in] */ TaskStackViewScroller* scroller);

    /** Velocity tracker helpers */
    CARAPI_(void) InitOrResetVelocityTracker();

    CARAPI_(void) InitVelocityTrackerIfNotExists();

    CARAPI_(void) RecycleVelocityTracker();

    /** Returns the view at the specified coordinates */
    CARAPI_(AutoPtr<TaskView>) FindViewAtPoint(
        /* [in] */ Int32 x,
        /* [in] */ Int32 y);

    /** Constructs a simulated motion event for the current stack scroll. */
    CARAPI_(AutoPtr<IMotionEvent>) CreateMotionEventForStackScroll(
        /* [in] */ IMotionEvent* ev);

    /** Touch preprocessing for handling below */
    CARAPI_(Boolean) OnInterceptTouchEvent(
        /* [in] */ IMotionEvent* ev);

    /** Handles touch events once we have intercepted them */
    CARAPI_(Boolean) OnTouchEvent(
        /* [in] */ IMotionEvent* ev);

    /**** SwipeHelper Implementation ****/

    CARAPI GetChildAtPosition(
        /* [in] */ IMotionEvent* ev,
        /* [out] */ IView** view);

    CARAPI CanChildBeDismissed(
        /* [in] */ IView* v,
        /* [out] */ Boolean* result);

    CARAPI OnBeginDrag(
        /* [in] */ IView* v);

    CARAPI OnSwipeChanged(
        /* [in] */ IView* v,
        /* [in] */ Float delta);

    CARAPI OnChildDismissed(
        /* [in] */ IView* v);

    CARAPI OnSnapBackCompleted(
        /* [in] */ IView* v);

    CARAPI OnDragCancelled(
        /* [in] */ IView* v);

    CARAPI_(AutoPtr<TaskStackView>) GetTaskStackView();

public:
    static Int32 INACTIVE_POINTER_ID;

    AutoPtr<RecentsConfiguration> mConfig;
    AutoPtr<IWeakReference> mWeakTaskStackView; // TaskStackView has this's reference
    AutoPtr<TaskStackViewScroller> mScroller;
    AutoPtr<IVelocityTracker> mVelocityTracker;

    Boolean mIsScrolling;

    Float mInitialP;
    Float mLastP;
    Float mTotalPMotion;
    Int32 mInitialMotionX;
    Int32 mInitialMotionY;
    Int32 mLastMotionX;
    Int32 mLastMotionY;
    Int32 mActivePointerId;
    AutoPtr<TaskView> mActiveTaskView;

    Int32 mMinimumVelocity;
    Int32 mMaximumVelocity;
    // The scroll touch slop is used to calculate when we start scrolling
    Int32 mScrollTouchSlop;
    // The page touch slop is used to calculate when we start swiping
    Float mPagingTouchSlop;

    AutoPtr<SwipeHelper> mSwipeHelper;
    Boolean mInterceptedBySwipeHelper;

private:
    AutoPtr<ISwipeHelperCallback> mCallback;
};

} // namespace Views
} // namespace Recents
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_RECENTS_VIEWS_TASKSTACKVIEWTOUCHHANDLER_H__

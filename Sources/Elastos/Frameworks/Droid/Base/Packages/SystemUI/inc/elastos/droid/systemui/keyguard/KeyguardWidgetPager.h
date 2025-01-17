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

#ifndef __ELASTOS_DROID_SYSTEMUI_KEYGUARD_KEYGUARDWIDGITPAPER_H__
#define __ELASTOS_DROID_SYSTEMUI_KEYGUARD_KEYGUARDWIDGITPAPER_H__

#include "_Elastos.Droid.SystemUI.h"
#include "elastos/droid/systemui/keyguard/PagedView.h"
#include "elastos/droid/animation/AnimatorListenerAdapter.h"
#include <elastos/core/Runnable.h>
#include "Elastos.Droid.Animation.h"
#include "Elastos.Droid.Internal.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.View.h"
#include "Elastos.Droid.Widget.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Animation::IAnimator;
using Elastos::Droid::Animation::IAnimatorSet;
using Elastos::Droid::Animation::ITimeInterpolator;
using Elastos::Droid::Animation::AnimatorListenerAdapter;
using Elastos::Droid::Internal::Widget::ILockPatternUtils;
using Elastos::Core::Runnable;
using Elastos::Droid::Os::IHandler;
using Elastos::Droid::Os::IHandlerThread;
using Elastos::Droid::SystemUI::Keyguard::PagedView;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IMotionEvent;
using Elastos::Droid::View::IViewGroupLayoutParams;
using Elastos::Droid::View::IViewOnLongClickListener;
using Elastos::Droid::Widget::ITextClock;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Keyguard {

class KeyguardWidgetPager
    : public PagedView
    , public IKeyguardWidgetPager
    , public IChallengeLayoutOnBouncerStateChangedListener
{
private:
    class InnerListener
        : public Object
        , public IPagedViewPageSwitchListener
        , public IViewOnLongClickListener
    {
    public:
        TO_STRING_IMPL("KeyguardWidgetPager::InnerListener")

        CAR_INTERFACE_DECL()

        InnerListener(
            /* [in] */ KeyguardWidgetPager* host);

        //@Override
        CARAPI OnPageSwitching(
            /* [in] */ IView* newPage,
            /* [in] */ Int32 newPageIndex);

        //@Override
        CARAPI OnPageSwitched(
            /* [in] */ IView* newPage,
            /* [in] */ Int32 newPageIndex);

        //@Override
        CARAPI OnLongClick(
            /* [in] */ IView* v,
            /* [out] */ Boolean* result);

    private:
        KeyguardWidgetPager* mHost;
    };

    class MyRunnable
        : public Runnable
    {
    public:
        TO_STRING_IMPL("KeyguardWidgetPager::MyRunnable")

        MyRunnable(
            /* [in] */ KeyguardWidgetPager* host,
            /* [in] */ Int32 appWidgetId)
            : mHost(host)
            , mAppWidgetId(appWidgetId)
        {}

        //@Override
        CARAPI Run();

    private:
        KeyguardWidgetPager* mHost;
        Int32 mAppWidgetId;
    };

    class MyRunnable2
        : public Runnable
    {
    public:
        TO_STRING_IMPL("KeyguardWidgetPager::MyRunnable2")

        MyRunnable2(
            /* [in] */ KeyguardWidgetPager* host,
            /* [in] */ Int32 appWidgetId,
            /* [in] */ Int32 index,
            /* [in] */ Int32 pagesRange)
            : mHost(host)
            , mAppWidgetId(appWidgetId)
            , mIndex(index)
            , mPagesRange(pagesRange)
        {}

        //@Override
        CARAPI Run();

    private:
        KeyguardWidgetPager* mHost;
        Int32 mAppWidgetId;
        Int32 mIndex;
        Int32 mPagesRange;
    };

    /*
     * This interpolator emulates the rate at which the perceived scale of an object changes
     * as its distance from a camera increases. When this interpolator is applied to a scale
     * animation on a view, it evokes the sense that the object is shrinking due to moving away
     * from the camera.
     */
    class ZInterpolator
        : public Object
        , public ITimeInterpolator
    {
    public:
        TO_STRING_IMPL("KeyguardWidgetPager::ZInterpolator")

        CAR_INTERFACE_DECL()

        ZInterpolator(
            /* [in] */ Float foc);

        CARAPI GetInterpolation(
            /* [in] */ Float input,
            /* [out] */ Float* polation);

        CARAPI HasNativeInterpolator(
            /* [out] */ Boolean* res);

    private:
        Float mFocalLength;
    };

    class MyAnimatorListenerAdapter
        : public AnimatorListenerAdapter
    {
    public:
        TO_STRING_IMPL("KeyguardWidgetPager::MyAnimatorListenerAdapter")

        MyAnimatorListenerAdapter(
            /* [in] */ KeyguardWidgetPager* host,
            /* [in] */ Boolean show)
            : mHost(host)
            , mShow(show)
        {}

        //@Override
        CARAPI OnAnimationStart(
            /* [in] */ IAnimator* animation);

        //@Override
        CARAPI OnAnimationEnd(
            /* [in] */ IAnimator* animation);

    private:
        KeyguardWidgetPager* mHost;
        Boolean mShow;
    };

public:
    CAR_INTERFACE_DECL()

    KeyguardWidgetPager();

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyle);

    CARAPI SetViewStateManager(
        /* [in] */ IKeyguardViewStateManager* viewStateManager);

    CARAPI SetLockPatternUtils(
        /* [in] */ ILockPatternUtils* l);

    //@Override
    CARAPI OnPageSwitching(
        /* [in] */ IView* newPage,
        /* [in] */ Int32 newPageIndex);

    //@Override
    CARAPI OnPageSwitched(
        /* [in] */ IView* newPage,
        /* [in] */ Int32 newPageIndex);

    //@Override
    CARAPI SnPageBeginWarp();

    //@Override
    CARAPI SnPageEndWarp();

    //@Override
    CARAPI SendAccessibilityEvent(
        /* [in] */ Int32  eventType);

    //@Override
    CARAPI OnTouchEvent(
        /* [in] */ IMotionEvent* ev,
        /* [out] */ Boolean* result);

    //@Override
    CARAPI OnInterceptTouchEvent(
        /* [in] */ IMotionEvent* ev,
        /* [out] */ Boolean* result);

    CARAPI ShowPagingFeedback();

    CARAPI GetUserActivityTimeout(
        /* [out] */ Int64* timetout);

    CARAPI SetCallbacks(
        /* [in] */ IKeyguardWidgetPagerCallbacks* callbacks);

    CARAPI AddWidget(
        /* [in] */ IView* widget);

    CARAPI OnRemoveView(
        /* [in] */ IView* v,
        /* [in] */ Boolean deletePermanently);

    //@Override
    CARAPI OnRemoveViewAnimationCompleted();

    CARAPI OnAddView(
        /* [in] */ IView* v,
        /* [in] */ Int32 index);

    /*
     * We wrap widgets in a special frame which handles drawing the over scroll foreground.
     */
    CARAPI AddWidget(
        /* [in] */ IView* widget,
        /* [in] */ Int32 pageIndex);

    /**
     * Use addWidget() instead.
     * @deprecated
     */
    //@Override
    CARAPI AddView(
        /* [in] */ IView* child,
        /* [in] */ Int32 index);

    /**
     * Use addWidget() instead.
     * @deprecated
     */
    //@Override
    CARAPI AddView(
        /* [in] */ IView* child,
        /* [in] */ Int32 width,
        /* [in] */ Int32 height);

    /**
     * Use addWidget() instead.
     * @deprecated
     */
    //@Override
    CARAPI AddView(
        /* [in] */ IView* child,
        /* [in] */ IViewGroupLayoutParams* params);

    /**
     * Use addWidget() instead.
     * @deprecated
     */
    //@Override
    CARAPI AddView(
        /* [in] */ IView* child,
        /* [in] */ Int32 index,
        /* [in] */ IViewGroupLayoutParams* params);

    CARAPI GetWidgetPageAt(
        /* [in] */ Int32 index,
        /* [out] */ IKeyguardWidgetFrame** frame);

    //@Override
    CARAPI OverScroll(
        /* [in] */ Float amount);

    CARAPI BackgroundAlphaInterpolator(
        /* [in] */ Float r,
        /* [out] */ Float* result);

    CARAPI GetAlphaForPage(
        /* [in] */ Int32 screenCenter,
        /* [in] */ Int32 index,
        /* [in] */ Boolean showSidePages,
        /* [out] */ Float* result);

    CARAPI GetOutlineAlphaForPage(
        /* [in] */ Int32 screenCenter,
        /* [in] */ Int32 index,
        /* [in] */ Boolean showSidePages,
        /* [out] */ Float* result);

    CARAPI IsWidgetPage(
        /* [in] */ Int32 pageIndex,
        /* [out] */ Boolean* result);

    /**
     * Returns the bounded set of pages that are re-orderable.  The range is fully inclusive.
     */
    //@Override
    CARAPI BoundByReorderablePages(
        /* [in] */ Boolean isReordering,
        /* [in] */ ArrayOf<Int32>* range);

    CARAPI ShowOutlinesAndSidePages();

    CARAPI HideOutlinesAndSidePages();

    CARAPI UpdateChildrenContentAlpha(
        /* [in] */ Float sidePageAlpha);

    CARAPI ShowInitialPageHints();

    //@Override
    CARAPI SetCurrentPage(
        /* [in] */ Int32 currentPage);

    //@Override
    CARAPI OnAttachedToWindow();

    CARAPI AnimateOutlinesAndSidePages(
        /* [in] */ Boolean show);

    CARAPI SetWidgetToResetOnPageFadeOut(
        /* [in] */ Int32 widget);

    CARAPI GetWidgetToResetOnPageFadeOut(
        /* [out] */ Int32* result);

    CARAPI AnimateOutlinesAndSidePages(
        /* [in] */ Boolean show,
        /* [in] */ Int32 duration);

    //@Override
    CARAPI OnLongClick(
        /* [in] */ IView* v,
        /* [out] */ Boolean* result);

    CARAPI RemoveWidget(
        /* [in] */ IView* view);

    CARAPI GetWidgetPageIndex(
        /* [in] */ IView* view,
        /* [out] */ Int32* index);

    // ChallengeLayout.OnBouncerStateChangedListener
    //@Override
    CARAPI OnBouncerStateChanged(
        /* [in] */ Boolean bouncerActive);

    CARAPI SetBouncerAnimationDuration(
        /* [in] */ Int32 duration);

    // Zoom in after the bouncer is dismissed
    CARAPI ZoomInFromBouncer();

    // Zoom out after the bouncer is initiated
    CARAPI ZoomOutToBouncer();

    CARAPI SetAddWidgetEnabled(
        /* [in] */ Boolean enabled);

    CARAPI IsAddPage(
        /* [in] */ Int32 pageIndex,
        /* [out] */ Boolean* result);

    CARAPI IsCameraPage(
        /* [in] */ Int32 pageIndex,
        /* [out] */ Boolean* result);

    CARAPI HandleExternalCameraEvent(
        /* [in] */ IMotionEvent* event);

protected:
    //@Override
    CARAPI OnDetachedFromWindow();

    CARAPI OnUnhandledTap(
        /* [in] */ IMotionEvent* ev);

    //@Override
    CARAPI OnPageBeginMoving();

    //@Override
    CARAPI OnPageEndMoving();

    CARAPI EnablePageContentLayers();

    CARAPI DisablePageContentLayers();

    CARAPI IsOverScrollChild(
        /* [in] */ Int32 index,
        /* [in] */ Float scrollProgress,
        /* [out] */ Boolean* result);

    //@Override
    CARAPI ScreenScrolled(
        /* [in] */ Int32 screenCenter);

    CARAPI ReorderStarting();

    //@Override
    CARAPI OnStartReordering();

    //@Override
    CARAPI OnEndReordering();

    CARAPI OnMeasure(
        /* [in] */ Int32 widthMeasureSpec,
        /* [in] */ Int32 heightMeasureSpec);

    //@Override
    CARAPI SetPageHoveringOverDeleteDropTarget(
        /* [in] */ Int32 viewIndex,
        /* [in] */ Boolean isHovering);

    //@Override
    CARAPI ShouldSetTopAlignedPivotForWidget(
        /* [in] */ Int32 childIndex,
        /* [out] */ Boolean* result);

private:
    CARAPI_(void) UpdateWidgetFramesImportantForAccessibility();

    CARAPI_(void) UpdateWidgetFrameImportantForAccessibility(
        /* [in] */ IKeyguardWidgetFrame* frame);

    CARAPI_(void) UserActivity();

    CARAPI_(Boolean) CaptureUserInteraction(
        /* [in] */ IMotionEvent* ev);

    CARAPI EnforceKeyguardWidgetFrame(
        /* [in] */ IView* child);

    CARAPI_(void) UpdatePageAlphaValues(
        /* [in] */ Int32 screenCenter);

    /**
     * Search given {@link View} hierarchy for {@link TextClock} instances that
     * show various time components. Returns combination of
     * {@link #FLAG_HAS_LOCAL_HOUR} and {@link #FLAG_HAS_LOCAL_MINUTE}.
     */
    static CARAPI_(Int32) FindClockInHierarchy(
        /* [in] */ IView* view);

    /**
     * Return combination of {@link #FLAG_HAS_LOCAL_HOUR} and
     * {@link #FLAG_HAS_LOCAL_MINUTE} describing the time represented described
     * by the given {@link TextClock}.
     */
    static CARAPI_(Int32) GetClockFlags(
        /* [in] */ ITextClock* clock);

public:
    AutoPtr<ZInterpolator> mZInterpolator;

    Boolean mShowHintsAfterLayout;

protected:
    static Float OVERSCROLL_MAX_ROTATION;

    AutoPtr<IKeyguardViewStateManager> mViewStateManager;

    AutoPtr<IAnimatorSet> mChildrenOutlineFadeAnimation;
    Int32 mScreenCenter;

    Boolean mShowingInitialHints;

private:
    static Float CAMERA_DISTANCE;
    static const Boolean PERFORM_OVERSCROLL_ROTATION;
    static const Int32 FLAG_HAS_LOCAL_HOUR;
    static const Int32 FLAG_HAS_LOCAL_MINUTE;

    AutoPtr<ILockPatternUtils> mLockPatternUtils;
    Boolean mHasMeasure;

    static const Int64 CUSTOM_WIDGET_USER_ACTIVITY_TIMEOUT;
    static const String TAG;
    Boolean mCenterSmallWidgetsVertically;

    Int32 mPage;
    AutoPtr<IKeyguardWidgetPagerCallbacks> mCallbacks;

    Int32 mWidgetToResetAfterFadeOut;

    // A temporary handle to the Add-Widget view
    AutoPtr<IView> mAddWidgetView;
    Int32 mLastWidthMeasureSpec;
    Int32 mLastHeightMeasureSpec;

    // Bouncer
    Int32 mBouncerZoomInOutDuration;
    Float BOUNCER_SCALE_FACTOR;

    // Background worker thread: used here for persistence, also made available to widget frames
    AutoPtr<IHandlerThread> mBackgroundWorkerThread;
    AutoPtr<IHandler> mBackgroundWorkerHandler;
    Boolean mCameraEventInProgress;
};

} // namespace Keyguard
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_KEYGUARD_KEYGUARDWIDGITPAPER_H__

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

#ifndef __ELASTOS_DROID_PHONE_COMMON_DIALPAD_DIALPADKEYBUTTON_H__
#define __ELASTOS_DROID_PHONE_COMMON_DIALPAD_DIALPADKEYBUTTON_H__

#include "Elastos.Droid.Phone.Common.h"
#include "Elastos.Droid.Graphics.h"
#include "Elastos.Droid.View.h"
#include "Elastos.CoreLibrary.Core.h"
#include <elastos/core/Runnable.h>
#include <elastos/droid/widget/FrameLayout.h>

using Elastos::Droid::Graphics::IRect;
using Elastos::Core::Runnable;
using Elastos::Droid::View::IMotionEvent;
using Elastos::Droid::View::Accessibility::IAccessibilityManager;
using Elastos::Droid::Widget::FrameLayout;
using Elastos::Core::ICharSequence;
using Elastos::Core::IRunnable;

namespace Elastos {
namespace Droid {
namespace Phone {
namespace Common {
namespace Dialpad {

class DialpadKeyButton
    : public FrameLayout
    , public IDialpadKeyButton
{
private:
    class MyRunnable
        : public Runnable
    {
    public:
        MyRunnable(
            /* [in] */ DialpadKeyButton* host)
            : mHost(host)
        {}

        CARAPI Run();

    private:
        DialpadKeyButton* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    DialpadKeyButton();

    CARAPI constructor(
        /* [in] */ IContext* ctx,
        /* [in] */ IAttributeSet* attrs);

    CARAPI constructor(
        /* [in] */ IContext* ctx,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyle);

    CARAPI SetOnPressedListener(
        /* [in] */ IDialpadKeyButtonOnPressedListener* onPressedListener);

    CARAPI SetLongHoverContentDescription(
        /* [in] */ ICharSequence* contentDescription);

    // @Override
    CARAPI SetContentDescription(
        /* [in] */ ICharSequence* contentDescription);

    // @Override
    CARAPI SetPressed(
        /* [in] */ Boolean pressed);

    // @Override
    CARAPI OnSizeChanged(
        /* [in] */ Int32 w,
        /* [in] */ Int32 h,
        /* [in] */ Int32 oldw,
        /* [in] */ Int32 oldh);

    // @Override
    CARAPI PerformAccessibilityAction(
        /* [in] */ Int32 action,
        /* [in] */ IBundle* arguments,
        /* [out] */ Boolean* result);

    // @Override
    CARAPI OnHoverEvent(
        /* [in] */ IMotionEvent* event,
        /* [out] */ Boolean* result);

private:
    CARAPI_(void) InitForAccessibility(
        /* [in] */ IContext* context);

    /**
     * When accessibility is on, simulate press and release to preserve the
     * semantic meaning of performClick(). Required for Braille support.
     */
    CARAPI_(void) SimulateClickForAccessibility();

    CARAPI_(void) SetLongHovered(
        /* [in] */ Boolean enabled);

    CARAPI_(void) CancelLongHover();

    static CARAPI_(Int32) Init_LONG_HOVER_TIMEOUT();

private:
    /** Timeout before switching to long-click accessibility mode. */
    static const Int32 LONG_HOVER_TIMEOUT;

    /** Accessibility manager instance used to check touch exploration state. */
    AutoPtr<IAccessibilityManager> mAccessibilityManager;

    /** Bounds used to filter HOVER_EXIT events. */
    AutoPtr<IRect> mHoverBounds;

    /** Whether this view is currently in the long-hover state. */
    Boolean mLongHovered;

    /** Alternate content description for long-hover state. */
    AutoPtr<ICharSequence> mLongHoverContentDesc;

    /** Backup of standard content description. Used for accessibility. */
    AutoPtr<ICharSequence> mBackupContentDesc;

    /** Backup of clickable property. Used for accessibility. */
    Boolean mWasClickable;

    /** Backup of long-clickable property. Used for accessibility. */
    Boolean mWasLongClickable;

    /** Runnable used to trigger long-click mode for accessibility. */
    AutoPtr<IRunnable> mLongHoverRunnable;

    AutoPtr<IDialpadKeyButtonOnPressedListener> mOnPressedListener;
};

} // namespace Dialpad
} // namespace Common
} // namespace Phone
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_PHONE_COMMON_DIALPAD_DIALPADKEYBUTTON_H__

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

#ifndef  __ELASTOS_DROID_SYSTEMUI_STATUSBAR_CBACKDROPVIEW_H__
#define  __ELASTOS_DROID_SYSTEMUI_STATUSBAR_CBACKDROPVIEW_H__

#include "_Elastos_Droid_SystemUI_StatusBar_CBackDropView.h"
#include <elastos/droid/widget/FrameLayout.h>

using Elastos::Droid::Widget::FrameLayout;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace StatusBar {

/**
 * A view who contains media artwork.
 */
CarClass(CBackDropView)
    , public FrameLayout
    , public IBackDropView
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyleAttr);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyleAttr,
        /* [in] */ Int32 defStyleRes);

    // @Override
    CARAPI HasOverlappingRendering(
        /* [out] */ Boolean* result);

    CARAPI SetOnVisibilityChangedRunnable(
        /* [in] */ IRunnable* runnable);

protected:
    // @Override
    CARAPI OnVisibilityChanged(
        /* [in] */ IView* changedView,
        /* [in] */ Int32 visibility);

private:
    AutoPtr<IRunnable> mOnVisibilityChangedRunnable;
};

} // namespace StatusBar
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_STATUSBAR_CBACKDROPVIEW_H__

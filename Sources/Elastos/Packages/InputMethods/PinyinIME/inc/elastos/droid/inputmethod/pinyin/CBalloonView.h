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

#ifndef __ELASTOS_DROID_INPUTMETHOD_PINYIN_CBALLOONVIEW_H__
#define __ELASTOS_DROID_INPUTMETHOD_PINYIN_CBALLOONVIEW_H__

#include "Elastos.Droid.Graphics.h"
#include "_Elastos_Droid_InputMethod_Pinyin_CBalloonView.h"
#include <elastos/droid/view/View.h>

using Elastos::Droid::Graphics::IPaintFontMetricsInt;

namespace Elastos {
namespace Droid {
namespace InputMethod {
namespace Pinyin {

CarClass(CBalloonView)
    , public Elastos::Droid::View::View
    , public IBalloonView
{
public:
    CBalloonView();

    CAR_OBJECT_DECL();

    CAR_INTERFACE_DECL();

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI_(void) SetIcon(
        /* [in] */ IDrawable* icon);

    CARAPI_(void) SetTextConfig(
        /* [in] */ const String& label,
        /* [in] */ Float fontSize,
        /* [in] */ Boolean textBold,
        /* [in] */ Int32 textColor);

protected:
    CARAPI OnMeasure(
        /* [in] */ Int32 widthMeasureSpec,
        /* [in] */ Int32 heightMeasureSpec);

    CARAPI_(void) OnDraw(
        /* [in] */ ICanvas* canvas);

private:
    CARAPI_(String) GetLimitedLabelForDrawing(
        /* [in] */ const String& rawLabel,
        /* [in] */ Float widthToDraw);

private:
    /**
     * Suspension points used to display long items.
     */
    static String SUSPENSION_POINTS;

    /**
     * The icon to be shown. If it is not NULL, {@link #mLabel} will be
     * ignored.
     */
    AutoPtr<IDrawable> mIcon;

    /**
     * The label to be shown. It is enabled only if {@link #mIcon} is NULL.
     */
    String mLabel;

    Int32 mLabeColor;
    AutoPtr<IPaint> mPaintLabel;
    AutoPtr<IPaintFontMetricsInt> mFmi;

    /**
     * The width to show suspension points.
     */
    Float mSuspensionPointsWidth;
};

} // namespace Pinyin
} // namespace InputMethod
} // namespace Droid
} // namespace Elastos

#endif  //__ELASTOS_DROID_INPUTMETHOD_PINYIN_CBALLOONVIEW_H__

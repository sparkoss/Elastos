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

#include "elastos/droid/systemui/statusbar/CNotificationGuts.h"
#include "R.h"

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace StatusBar {

CAR_OBJECT_IMPL(CNotificationGuts)
CAR_INTERFACE_IMPL(CNotificationGuts, FrameLayout, INotificationGuts)
CNotificationGuts::CNotificationGuts()
    : mClipTopAmount(0)
    , mActualHeight(0)
{}

ECode CNotificationGuts::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IAttributeSet* attrs)
{
    FrameLayout::constructor(context, attrs);
    SetWillNotDraw(FALSE);
    return NOERROR;
}

void CNotificationGuts::OnDraw(
    /* [in] */ ICanvas* canvas)
{
    Draw(canvas, mBackground);
}

void CNotificationGuts::Draw(
    /* [in] */ ICanvas* canvas,
    /* [in] */ IDrawable* drawable)
{
    if (drawable != NULL) {
        Int32 width = 0;
        GetWidth(&width);
        drawable->SetBounds(0, mClipTopAmount, width, mActualHeight);
        drawable->Draw(canvas);
    }
}

ECode CNotificationGuts::OnFinishInflate()
{
    FrameLayout::OnFinishInflate();
    mContext->GetDrawable(R::drawable::notification_guts_bg, (IDrawable**)&mBackground);
    if (mBackground != NULL) {
        mBackground->SetCallback(this);
    }
    return NOERROR;
}

Boolean CNotificationGuts::VerifyDrawable(
    /* [in] */ IDrawable* who)
{
    return FrameLayout::VerifyDrawable(who) || who == mBackground;
}

ECode CNotificationGuts::DrawableStateChanged()
{
    DrawableStateChanged(mBackground);
    return NOERROR;
}

void CNotificationGuts::DrawableStateChanged(
    /* [in] */ IDrawable* d)
{
    Boolean tmp = FALSE;
    if (d != NULL && (d->IsStateful(&tmp), tmp)) {
        AutoPtr<ArrayOf<Int32> > states;
        GetDrawableState((ArrayOf<Int32>**)&states);
        d->SetState(states, &tmp);
    }
}

ECode CNotificationGuts::DrawableHotspotChanged(
    /* [in] */ Float x,
    /* [in] */ Float y)
{
    if (mBackground != NULL) {
        mBackground->SetHotspot(x, y);
    }
    return NOERROR;
}

ECode CNotificationGuts::SetActualHeight(
    /* [in] */ Int32 actualHeight)
{
    mActualHeight = actualHeight;
    Invalidate();
    return NOERROR;
}

ECode CNotificationGuts::GetActualHeight(
    /* [out] */ Int32* height)
{
    VALIDATE_NOT_NULL(height);
    *height = mActualHeight;
    return NOERROR;
}

ECode CNotificationGuts::SetClipTopAmount(
    /* [in] */ Int32 clipTopAmount)
{
    mClipTopAmount = clipTopAmount;
    Invalidate();
    return NOERROR;
}

ECode CNotificationGuts::HasOverlappingRendering(
    /* [out] */ Boolean* has)
{
    VALIDATE_NOT_NULL(has);
    // Prevents this view from creating a layer when alpha is animating.
    *has = FALSE;
    return NOERROR;
}

} // namespace StatusBar
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

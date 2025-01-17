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

#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Os.h"
#include "elastos/droid/graphics/drawable/TransitionDrawable.h"
#include "elastos/droid/graphics/drawable/CTransitionDrawable.h"
#include "elastos/droid/os/SystemClock.h"
#include <elastos/core/Math.h>

using Elastos::Droid::Os::SystemClock;

namespace Elastos {
namespace Droid {
namespace Graphics {
namespace Drawable {

const Int32 TransitionDrawable::TRANSITION_STARTING;
const Int32 TransitionDrawable::TRANSITION_RUNNING;
const Int32 TransitionDrawable::TRANSITION_NONE;

TransitionDrawable::TransitionState::TransitionState(
    /* [in] */ TransitionState* orig,
    /* [in] */ TransitionDrawable* owner,
    /* [in] */ IResources* res)
    : LayerState(orig, owner, res)
{}

ECode TransitionDrawable::TransitionState::NewDrawable(
    /* [out] */ IDrawable** drawable)
{
    VALIDATE_NOT_NULL(drawable)
    return CTransitionDrawable::New(this, NULL, NULL, drawable);
}

ECode TransitionDrawable::TransitionState::NewDrawable(
    /* [in] */ IResources* res,
    /* [out] */ IDrawable** drawable)
{
    VALIDATE_NOT_NULL(drawable)
    return CTransitionDrawable::New(this, res, NULL, drawable);
}

ECode TransitionDrawable::TransitionState::NewDrawable(
    /* [in] */ IResources* res,
    /* [in] */ IResourcesTheme* theme,
    /* [out] */ IDrawable** drawable)
{
    VALIDATE_NOT_NULL(drawable)
    return CTransitionDrawable::New(this, res, theme, drawable);
}

ECode TransitionDrawable::TransitionState::GetChangingConfigurations(
    /* [out] */ Int32* config)
{
    VALIDATE_NOT_NULL(config);
    *config = mChangingConfigurations;
    return NOERROR;
}

CAR_INTERFACE_IMPL(TransitionDrawable, LayerDrawable, ITransitionDrawable);

TransitionDrawable::TransitionDrawable()
    : mTransitionState(TRANSITION_NONE)
    , mReverse(FALSE)
    , mStartTimeMillis(0)
    , mFrom(0)
    , mTo(0)
    , mDuration(0)
    , mOriginalDuration(0)
    , mAlpha(0)
    , mCrossFade(FALSE)
{
}

ECode TransitionDrawable::constructor(
    /* [in] */ ArrayOf<IDrawable*>* layers)
{
    AutoPtr<TransitionState> state = new TransitionState(NULL, NULL, NULL);
    return constructor((IDrawableConstantState*)state, layers);
}

ECode TransitionDrawable::constructor()
{
    AutoPtr<TransitionState> state = new TransitionState(NULL, NULL, NULL);
    return constructor((IDrawableConstantState*)state, NULL, NULL);
}

ECode TransitionDrawable::constructor(
    /* [in] */ IDrawableConstantState* state,
    /* [in] */ IResources* res,
    /* [in] */ IResourcesTheme* theme)
{
    return LayerDrawable::constructor(state, res, theme);
}

ECode TransitionDrawable::constructor(
    /* [in] */ IDrawableConstantState* state,
    /* [in] */ ArrayOf<IDrawable*>* layers)
{
    return LayerDrawable::constructor(layers, state);
}

AutoPtr<LayerDrawable::LayerState> TransitionDrawable::CreateConstantState(
    /* [in] */ LayerState* state,
    /* [in] */ IResources* res)
{
    return new TransitionState((TransitionState*)state, this, res);
}

ECode TransitionDrawable::StartTransition(
    /* [in] */ Int32 durationMillis)
{
    mFrom = 0;
    mTo = 255;
    mAlpha = 0;
    mDuration = mOriginalDuration = durationMillis;
    mReverse = FALSE;
    mTransitionState = TRANSITION_STARTING;
    InvalidateSelf();
    return NOERROR;
}

ECode TransitionDrawable::ResetTransition()
{
    mAlpha = 0;
    mTransitionState = TRANSITION_NONE;
    InvalidateSelf();
    return NOERROR;
}

ECode TransitionDrawable::ReverseTransition(
    /* [in] */ Int32 duration)
{
    const Int64 time = SystemClock::GetUptimeMillis();
    // Animation is over
    if (time - mStartTimeMillis > mDuration) {
        if (mTo == 0) {
            mFrom = 0;
            mTo = 255;
            mAlpha = 0;
            mReverse = FALSE;
        }
        else {
            mFrom = 255;
            mTo = 0;
            mAlpha = 255;
            mReverse = TRUE;
        }
        mDuration = mOriginalDuration = duration;
        mTransitionState = TRANSITION_STARTING;
        InvalidateSelf();
        return NOERROR;
    }

    mReverse = !mReverse;
    mFrom = mAlpha;
    mTo = mReverse ? 0 : 255;
    mDuration = (Int32)(mReverse ? time - mStartTimeMillis :
            mOriginalDuration - (time - mStartTimeMillis));
    mTransitionState = TRANSITION_STARTING;
    return NOERROR;
}

ECode TransitionDrawable::Draw(
    /* [in] */ ICanvas* canvas)
{
    Boolean done = TRUE;

    switch (mTransitionState) {
        case TRANSITION_STARTING:
            mStartTimeMillis = SystemClock::GetUptimeMillis();
            done = FALSE;
            mTransitionState = TRANSITION_RUNNING;
            break;

        case TRANSITION_RUNNING:
            if (mStartTimeMillis >= 0) {
                Float normalized = (Float)
                        (SystemClock::GetUptimeMillis() - mStartTimeMillis) / mDuration;
                done = normalized >= 1.0f;
                normalized = Elastos::Core::Math::Min(normalized, 1.0f);
                mAlpha = (Int32)(mFrom  + (mTo - mFrom) * normalized);
            }
            break;
    }

    const Int32 alpha = mAlpha;
    const Boolean crossFade = mCrossFade;
    AutoPtr< ArrayOf<ChildDrawable*> > array = mLayerState->mChildren;

    if (done) {
        // the setAlpha() calls below trigger invalidation and redraw. If we're done, just draw
        // the appropriate drawable[s] and return
        if (!crossFade || alpha == 0) {
            (*array)[0]->mDrawable->Draw(canvas);
        }
        if (alpha == 0xFF) {
            (*array)[1]->mDrawable->Draw(canvas);
        }
        return NOERROR;
    }

    IDrawable* d;
    d = (*array)[0]->mDrawable;
    if (crossFade) {
        d->SetAlpha(255 - alpha);
    }
    d->Draw(canvas);
    if (crossFade) {
        d->SetAlpha(0xFF);
    }

    if (alpha > 0) {
        d = (*array)[1]->mDrawable;
        d->SetAlpha(alpha);
        d->Draw(canvas);
        d->SetAlpha(0xFF);
    }

    if (!done) {
        InvalidateSelf();
    }
    return NOERROR;
}

ECode TransitionDrawable::SetCrossFadeEnabled(
    /* [in] */ Boolean enabled)
{
    mCrossFade = enabled;
    return NOERROR;
}

ECode TransitionDrawable::IsCrossFadeEnabled(
    /* [out] */ Boolean* enabled)
{
    VALIDATE_NOT_NULL(enabled);
    *enabled = mCrossFade;
    return NOERROR;
}

} // namespace Drawable
} // namespace Graphics
} // namespace Droid
} // namespace Elastos

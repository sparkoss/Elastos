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

#include "elastos/droid/launcher2/LauncherViewPropertyAnimator.h"
#include "elastos/droid/launcher2/LauncherAnimUtils.h"
#include "Elastos.Droid.Service.h"
#include "Elastos.CoreLibrary.Utility.h"
#include <elastos/core/CoreUtils.h>
#include <elastos/utility/logging/Slogger.h>

using Elastos::Droid::Animation::EIID_IAnimatorListener;
using Elastos::Core::IInteger32;
using Elastos::Core::EIID_IInteger32;
using Elastos::Core::CoreUtils;
using Elastos::Utility::CArrayList;
using Elastos::Utility::CEnumSetHelper;
using Elastos::Utility::IEnumSetHelper;
using Elastos::Utility::Logging::Slogger;

namespace Elastos {
namespace Droid {
namespace Launcher2 {

CAR_INTERFACE_IMPL(LauncherViewPropertyAnimator::InnerListener, Object, IAnimatorListener)

LauncherViewPropertyAnimator::InnerListener::InnerListener(
    /* [in] */ LauncherViewPropertyAnimator* host)
    : mHost(host)
{}

ECode LauncherViewPropertyAnimator::InnerListener::OnAnimationCancel(
    /* [in] */ IAnimator* animation)
{
    return mHost->OnAnimationCancel(animation);
}

ECode LauncherViewPropertyAnimator::InnerListener::OnAnimationEnd(
    /* [in] */ IAnimator* animation)
{
    return mHost->OnAnimationEnd(animation);
}

ECode LauncherViewPropertyAnimator::InnerListener::OnAnimationRepeat(
    /* [in] */ IAnimator* animation)
{
    return mHost->OnAnimationRepeat(animation);
}

ECode LauncherViewPropertyAnimator::InnerListener::OnAnimationStart(
    /* [in] */ IAnimator* animation)
{
    return mHost->OnAnimationStart(animation);
}

CAR_INTERFACE_IMPL(LauncherViewPropertyAnimator, Animator, ILauncherViewPropertyAnimator);

LauncherViewPropertyAnimator::LauncherViewPropertyAnimator(
    /* [in] */ IView* target)
    : mTarget(target)
    , mTranslationX(0.0f)
    , mTranslationY(0.0f)
    , mScaleX(0.0f)
    , mScaleY(0.0f)
    , mRotationY(0.0f)
    , mAlpha(0.0f)
    , mStartDelay(0)
    , mDuration(0)
    , mRunning(FALSE)
{
    CArrayList::New((IArrayList**)&mListeners);
}

ECode LauncherViewPropertyAnimator::AddListener(
    /* [in] */ IAnimatorListener* listener)
{
    assert(listener);
    return mListeners->Add(listener);
}

ECode LauncherViewPropertyAnimator::Cancel()
{
    if (mViewPropertyAnimator != NULL) {
        mViewPropertyAnimator->Cancel();
    }
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::Clone(
    /* [out] */ IInterface** result)
{
    VALIDATE_NOT_NULL(result);

    //throw new RuntimeException("Not implemented");
    Slogger::E("LauncherViewPropertyAnimator", "Not implemented");
    return E_RUNTIME_EXCEPTION;
}

ECode LauncherViewPropertyAnimator::End()
{
    //throw new RuntimeException("Not implemented");
    Slogger::E("LauncherViewPropertyAnimator", "Not implemented");
    return E_RUNTIME_EXCEPTION;
}

ECode LauncherViewPropertyAnimator::GetDuration(
    /* [out] */Int64* duration)
{
    VALIDATE_NOT_NULL(duration);

    *duration = mDuration;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::GetListeners(
    /* [out, callee] */ IArrayList** listeners)
{
    VALIDATE_NOT_NULL(listeners);

    *listeners = mListeners;
    REFCOUNT_ADD(*listeners);
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::GetStartDelay(
    /* [out] */ Int64* delay)
{
    VALIDATE_NOT_NULL(delay);

    *delay = mStartDelay;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::OnAnimationCancel(
    /* [in] */ IAnimator* animation)
{
    Int32 size;
    for (Int32 i = 0; i < (mListeners->GetSize(&size), size); i++) {
        AutoPtr<IInterface> obj;
        mListeners->Get(i, (IInterface**)&obj);
        AutoPtr<IAnimatorListener> listener = IAnimatorListener::Probe(obj);
        listener->OnAnimationCancel(this);
    }
    mRunning = FALSE;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::OnAnimationEnd(
    /* [in] */ IAnimator* animation)
{
    Int32 size;
    for (Int32 i = 0; i < (mListeners->GetSize(&size), size); i++) {
        AutoPtr<IInterface> obj;
        mListeners->Get(i, (IInterface**)&obj);
        AutoPtr<IAnimatorListener> listener = IAnimatorListener::Probe(obj);
        listener->OnAnimationEnd(this);
    }
    mRunning = FALSE;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::OnAnimationRepeat(
    /* [in] */ IAnimator* animation)
{
    Int32 size;
    for (Int32 i = 0; i < (mListeners->GetSize(&size), size); i++) {
        AutoPtr<IInterface> obj;
        mListeners->Get(i, (IInterface**)&obj);
        AutoPtr<IAnimatorListener> listener = IAnimatorListener::Probe(obj);
        listener->OnAnimationRepeat(this);
    }
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::OnAnimationStart(
    /* [in] */ IAnimator* animation)
{
    // This is the first time we get a handle to the internal ValueAnimator
    // used by the ViewPropertyAnimator.
    mFirstFrameHelper->OnAnimationStart(animation);

    Int32 size;
    for (Int32 i = 0; i < (mListeners->GetSize(&size), size); i++) {
        AutoPtr<IInterface> obj;
        mListeners->Get(i, (IInterface**)&obj);
        AutoPtr<IAnimatorListener> listener = IAnimatorListener::Probe(obj);
        listener->OnAnimationStart(this);
    }
    mRunning = TRUE;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::IsRunning(
    /* [out] */ Boolean* running)
{
    VALIDATE_NOT_NULL(running);

    *running = mRunning;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::IsStarted(
    /* [out] */ Boolean* started)
{
    VALIDATE_NOT_NULL(started);

    *started = mViewPropertyAnimator != NULL;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::RemoveAllListeners()
{
    return mListeners->Clear();
}

ECode LauncherViewPropertyAnimator::RemoveListener(
    /* [in] */ IAnimatorListener* listener)
{
    return mListeners->Remove(listener);
}

ECode LauncherViewPropertyAnimator::SetDuration(
    /* [in] */ Int64 duration)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_DURATION);
    mDuration = duration;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::SetInterpolator(
    /* [in] */ ITimeInterpolator* value)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_INTERPOLATOR);
    mInterpolator = value;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::SetStartDelay(
    /* [in] */ Int64 startDelay)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_START_DELAY);
    mStartDelay = startDelay;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::SetTarget(
    /* [in] */ IInterface* target)
{
    //throw new RuntimeException("Not implemented");
    Slogger::E("LauncherViewPropertyAnimator", "Not implemented");
    return E_RUNTIME_EXCEPTION;
}

ECode LauncherViewPropertyAnimator::SetupEndValues()
{
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::SetupStartValues()
{
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::Start()
{
    mViewPropertyAnimator = NULL;
    mTarget->Animate((IViewPropertyAnimator**)&mViewPropertyAnimator);

    // FirstFrameAnimatorHelper hooks itself up to the updates on the animator,
    // and then adjusts the play time to keep the first two frames jank-free
    mFirstFrameHelper = new FirstFrameAnimatorHelper(mViewPropertyAnimator, mTarget);

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_TRANSLATION_X) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->TranslationX(mTranslationX);
    }

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_TRANSLATION_Y) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->TranslationY(mTranslationY);
    }

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_SCALE_X) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->ScaleX(mScaleX);
    }

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_ROTATION_Y) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->RotationY(mRotationY);
    }

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_SCALE_Y) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->ScaleY(mScaleY);
    }

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_ALPHA) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->Alpha(mAlpha);
    }

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_START_DELAY) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->SetStartDelay(mStartDelay);
    }

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_DURATION) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->SetDuration(mDuration);
    }

    if (mPropertiesToSet.Find(LauncherViewPropertyAnimator_INTERPOLATOR) != mPropertiesToSet.End()) {
        mViewPropertyAnimator->SetInterpolator(mInterpolator);
    }

    if (mInnerListener == NULL) {
        mInnerListener = new InnerListener(this);
    }
    mViewPropertyAnimator->SetListener(mInnerListener);
    mViewPropertyAnimator->Start();
    LauncherAnimUtils::CancelOnDestroyActivity(this);
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::TranslationX(
    /* [in] */ Float value)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_TRANSLATION_X);
    mTranslationX = value;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::TranslationY(
    /* [in] */ Float value)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_TRANSLATION_Y);
    mTranslationY = value;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::ScaleX(
    /* [in] */ Float value)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_SCALE_X);
    mScaleX = value;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::ScaleY(
    /* [in] */ Float value)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_SCALE_Y);
    mScaleY = value;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::RotationY(
    /* [in] */ Float value)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_ROTATION_Y);
    mRotationY = value;
    return NOERROR;
}

ECode LauncherViewPropertyAnimator::Alpha(
    /* [in] */ Float value)
{
    mPropertiesToSet.Insert(LauncherViewPropertyAnimator_ALPHA);
    mAlpha = value;
    return NOERROR;
}

} // namespace Launcher2
} // namespace Droid
} // namespace Elastos
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

#ifndef  __ELASTOS_DROID_LAUNCHER2_LAUNCHERANIMUTILS_H__
#define  __ELASTOS_DROID_LAUNCHER2_LAUNCHERANIMUTILS_H__

#include "_Elastos.Droid.Launcher2.h"
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Runnable.h>
#include "Elastos.Droid.Animation.h"
#include "Elastos.Droid.View.h"
#include "Elastos.CoreLibrary.Core.h"
#include "Elastos.CoreLibrary.Utility.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Animation::IAnimator;
using Elastos::Droid::Animation::IValueAnimator;
using Elastos::Droid::Animation::IObjectAnimator;
using Elastos::Droid::Animation::IAnimatorListener;
using Elastos::Droid::Animation::IAnimatorSet;
using Elastos::Droid::Animation::IPropertyValuesHolder;
using Elastos::Core::Runnable;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IOnDrawListener;
using Elastos::Core::Object;
using Elastos::Utility::IHashSet;

namespace Elastos {
namespace Droid {
namespace Launcher2 {

class LauncherAnimUtils
{
private:
    class MyAnimatorListener
        : public Object
        , public IAnimatorListener
    {
    public:
        TO_STRING_IMPL("LauncherAnimUtils::MyAnimatorListener")

        CAR_INTERFACE_DECL();

        CARAPI OnAnimationStart(
            /* [in] */ IAnimator* animation);

        CARAPI OnAnimationRepeat(
            /* [in] */ IAnimator* animation);

        CARAPI OnAnimationEnd(
            /* [in] */ IAnimator* animation);

        CARAPI OnAnimationCancel(
            /* [in] */ IAnimator* animation);
    };

    class MyOnDrawListener
        : public Object
        , public IOnDrawListener
    {
    public:
        TO_STRING_IMPL("LauncherAnimUtils::MyOnDrawListener")

        CAR_INTERFACE_DECL();

        MyOnDrawListener(
            /* [in] */ IAnimator* animator,
            /* [in] */ IView* view);

        CARAPI OnDraw();

    private:
        Boolean mStarted;
        AutoPtr<IAnimator> mAnimator;
        AutoPtr<IView> mView;
    };

    class MyRunnable
        : public Runnable
    {
    public:
        TO_STRING_IMPL("LauncherAnimUtils::MyRunnable")

        MyRunnable(
            /* [in] */ IView* view,
            /* [in] */ IOnDrawListener* listener);

        CARAPI Run();

    private:
        AutoPtr<IView> mView;
        AutoPtr<IOnDrawListener> mListener;
    };

public:
    static CARAPI_(void) CancelOnDestroyActivity(
        /* [in] */ IAnimator* a);

    // Helper method. Assumes a draw is pending, and that if the animation's duration is 0
    // it should be cancelled
    static CARAPI_(void) StartAnimationAfterNextDraw(
        /* [in] */ IAnimator* animator,
        /* [in] */ IView* view);

    static CARAPI_(void) OnDestroyActivity();

    static CARAPI_(AutoPtr<IAnimatorSet>) CreateAnimatorSet();

    static CARAPI_(AutoPtr<IValueAnimator>) OfFloat(
        /* [in] */ IView* target,
        /* [in] */ ArrayOf<Float>* values);

    static CARAPI_(AutoPtr<IObjectAnimator>) OfFloat(
        /* [in] */ IView* target,
        /* [in] */ const String& propertyName,
        /* [in] */ ArrayOf<Float>* values);

    static CARAPI_(AutoPtr<IObjectAnimator>) OfPropertyValuesHolder(
        /* [in] */ IView* target,
        /* [in] */ ArrayOf<IPropertyValuesHolder*>* values);

    static CARAPI_(AutoPtr<IObjectAnimator>) OfPropertyValuesHolder(
        /* [in] */ IInterface* target,
        /* [in] */ IView* view,
        /* [in] */ ArrayOf<IPropertyValuesHolder*>* values);

private:
    static CARAPI_(AutoPtr<IAnimatorListener>) GetEndAnimListener();

public:
    static AutoPtr<IHashSet> sAnimators;
    static AutoPtr<IAnimatorListener> sEndAnimListener;
};

} // namespace Launcher2
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_LAUNCHER2_LAUNCHERANIMUTILS_H__
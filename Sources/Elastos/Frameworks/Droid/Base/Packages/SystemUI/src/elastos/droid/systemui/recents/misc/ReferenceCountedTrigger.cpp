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

#include "elastos/droid/systemui/recents/misc/ReferenceCountedTrigger.h"
#include "elastos/droid/systemui/recents/misc/Console.h"
#include <elastos/utility/logging/Logger.h>

using Elastos::Utility::CArrayList;
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Recents {
namespace Misc {

static const String TAG("ReferenceCountedTrigger");

//=================================
// ReferenceCountedTrigger::IncrementRunnable
//=================================

ReferenceCountedTrigger::IncrementRunnable::IncrementRunnable(
    /* [in] */ ReferenceCountedTrigger* host)
    : mHost(host)
{}

ECode ReferenceCountedTrigger::IncrementRunnable::Run()
{
    mHost->Increment();
    return NOERROR;
}

//=================================
// ReferenceCountedTrigger::DecrementRunnable
//=================================

ReferenceCountedTrigger::DecrementRunnable::DecrementRunnable(
    /* [in] */ ReferenceCountedTrigger* host)
    : mHost(host)
{}

ECode ReferenceCountedTrigger::DecrementRunnable::Run()
{
    mHost->Decrement();
    return NOERROR;
}

//=================================
// ReferenceCountedTrigger::MyAnimatorListenerAdapter
//=================================

ReferenceCountedTrigger::MyAnimatorListenerAdapter::MyAnimatorListenerAdapter(
    /* [in] */ IWeakReference* host)
    : mWeakHost(host)
{
}

ECode ReferenceCountedTrigger::MyAnimatorListenerAdapter::OnAnimationEnd(
    /* [in] */ IAnimator* animation)
{
    AutoPtr<IObject> obj;
    mWeakHost->Resolve(EIID_IObject, (IInterface**)&obj);
    if (obj != NULL) {
        Logger::W("ReferenceCountedTrigger::MyAnimatorListenerAdapter", " OnAnimationEnd > trigger Decrement");
        ReferenceCountedTrigger* trigger = (ReferenceCountedTrigger*)obj.Get();
        trigger->Decrement();
    }
    else {
        Logger::W("ReferenceCountedTrigger::MyAnimatorListenerAdapter",
            " OnAnimationEnd > ReferenceCountedTrigger has released!");
    }

    return NOERROR;
}


//=================================
// ReferenceCountedTrigger
//=================================
ReferenceCountedTrigger::ReferenceCountedTrigger()
    : mCount(0)
{
}

ReferenceCountedTrigger::~ReferenceCountedTrigger()
{
}

ECode ReferenceCountedTrigger::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IRunnable* firstIncRunnable,
    /* [in] */ IRunnable* lastDecRunnable,
    /* [in] */ IRunnable* errorRunanable)
{
    mContext = context;
    mErrorRunnable = errorRunanable;

    CArrayList::New((IArrayList**)&mFirstIncRunnables);
    CArrayList::New((IArrayList**)&mLastDecRunnables);

    mIncrementRunnable = new IncrementRunnable(this);
    mDecrementRunnable = new DecrementRunnable(this);
    if (firstIncRunnable != NULL) mFirstIncRunnables->Add(firstIncRunnable);
    if (lastDecRunnable != NULL) mLastDecRunnables->Add(lastDecRunnable);
    return NOERROR;
}

void ReferenceCountedTrigger::Increment()
{
    Boolean isEmpty;
    mFirstIncRunnables->IsEmpty(&isEmpty);
    if (mCount == 0 && !isEmpty) {
        Int32 numRunnables;
        mFirstIncRunnables->GetSize(&numRunnables);
        for (Int32 i = 0; i < numRunnables; i++) {
            AutoPtr<IInterface> obj;
            mFirstIncRunnables->Get(i, (IInterface**)&obj);
            IRunnable::Probe(obj)->Run();
        }
    }
    mCount++;
}

AutoPtr<IRunnable> ReferenceCountedTrigger::IncrementAsRunnable()
{
    return mIncrementRunnable;
}

void ReferenceCountedTrigger::AddLastDecrementRunnable(
    /* [in] */ IRunnable* r)
{
    // To ensure that the last decrement always calls, we increment and decrement after setting
    // the last decrement runnable
    assert(r != NULL);
    Boolean ensureLastDecrement = (mCount == 0);
    if (ensureLastDecrement) Increment();
    mLastDecRunnables->Add(r);
    if (ensureLastDecrement) Decrement();
}

void ReferenceCountedTrigger::Decrement()
{
    mCount--;
    Boolean isEmpty;
    if (mCount == 0 && (mLastDecRunnables->IsEmpty(&isEmpty), !isEmpty)) {
        Int32 numRunnables;
        mLastDecRunnables->GetSize(&numRunnables);
        for (Int32 i = 0; i < numRunnables; i++) {
            AutoPtr<IInterface> obj;
            mLastDecRunnables->Get(i, (IInterface**)&obj);
            IRunnable::Probe(obj)->Run();
        }
    }
    else if (mCount < 0) {
        if (mErrorRunnable != NULL) {
            mErrorRunnable->Run();
        }
        else {
            //TODO
            // new Throwable("Invalid ref count").printStackTrace();
            Console::LogError(mContext, String("Invalid ref count"));
        }
    }
}

AutoPtr<IRunnable> ReferenceCountedTrigger::DecrementAsRunnable()
{
    return mDecrementRunnable;
}

AutoPtr<IAnimatorListener> ReferenceCountedTrigger::DecrementOnAnimationEnd()
{
    AutoPtr<IWeakReference> weakHost;
    GetWeakReference((IWeakReference**)&weakHost);
    AutoPtr<IAnimatorListener> listener = new MyAnimatorListenerAdapter(weakHost);
    return listener;
}

Int32 ReferenceCountedTrigger::GetCount()
{
    return mCount;
}

} // namespace Misc
} // namespace Recents
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos
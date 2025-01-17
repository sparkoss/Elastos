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

#include "elastos/droid/os/RegistrantList.h"
#include "elastos/droid/os/CRegistrant.h"
#include "_Elastos.Droid.Os.h"
#include <elastos/core/AutoLock.h>

using Elastos::Droid::Os::IHandler;
using Elastos::Utility::CArrayList;
using Elastos::Core::AutoLock;

namespace Elastos {
namespace Droid {
namespace Os {

CAR_INTERFACE_IMPL(RegistrantList, Object, IRegistrantList)
RegistrantList::RegistrantList()
{
    CArrayList::New((IArrayList**)&mRegistrants);
}

void RegistrantList::Add(
    /* [in] */ IHandler* h,
    /* [in] */ Int32 what,
    /* [in] */ IInterface* obj)
{
    AutoLock lock(mLock);
    AutoPtr<IRegistrant> registrant;
    CRegistrant::New(h, what, obj, (IRegistrant**)&registrant);
    Add(registrant);
}

void RegistrantList::AddUnique(
    /* [in] */ IHandler* h,
    /* [in] */ Int32 what,
    /* [in] */ IInterface* obj)
{
    AutoLock lock(mLock);
    // if the handler is already in the registrant list, remove it
    Remove(h);
    AutoPtr<IRegistrant> registrant;
    CRegistrant::New(h, what, obj, (IRegistrant**)&registrant);
    Add(registrant);
}

void RegistrantList::Add(
    /* [in] */ IRegistrant* r)
{
    AutoLock lock(mLock);
    RemoveCleared();
    mRegistrants->Add(r);
}

void RegistrantList::RemoveCleared()
{
    AutoLock lock(mLock);
    Int32 size = 0;
    mRegistrants->GetSize(&size);
    for (Int32 i = size - 1; i >= 0 ; i--) {
        AutoPtr<IInterface> obj;
        mRegistrants->Get(i, (IInterface**)&obj);
        Registrant* r = (Registrant*) IObject::Probe(obj);

        if (r->mRefH == NULL) {
            mRegistrants->Remove(i);
        }
    }
}

Int32 RegistrantList::GetSize()
{
    AutoLock lock(mLock);
    Int32 size = 0;
    mRegistrants->GetSize(&size);
    return size;
}

AutoPtr<IInterface> RegistrantList::Get(
    /* [in] */ Int32 index)
{
    AutoLock lock(mLock);
    AutoPtr<IInterface> obj;
    mRegistrants->Get(index, (IInterface**)&obj);
    return obj;
}

void RegistrantList::InternalNotifyRegistrants(
    /* [in] */ IInterface* result,
    /* [in] */ IThrowable* exception)
{
    AutoLock lock(mLock);
    Int32 size = 0;
    mRegistrants->GetSize(&size);
    // for (Int32 i = 0, s = size; i < s ; i++) {
    for (Int32 i = 0; i < size ; i++) {
        AutoPtr<IInterface> obj;
        mRegistrants->Get(i, (IInterface**)&obj);
        Registrant* r = (Registrant*) IObject::Probe(obj);
        r->InternalNotifyRegistrant(result, exception);
    }
}

void RegistrantList::NotifyRegistrants()
{
    InternalNotifyRegistrants(NULL, NULL);
}

void RegistrantList::NotifyException(
    /* [in] */ IThrowable* exception)
{
    InternalNotifyRegistrants(NULL, exception);
}

void RegistrantList::NotifyResult(
    /* [in] */ IInterface* result)
{
    InternalNotifyRegistrants(result, NULL);
}

void RegistrantList::NotifyRegistrants(
    /* [in] */ AsyncResult* ar)
{
    InternalNotifyRegistrants(ar->mResult, ar->mException);
}

void RegistrantList::Remove(
    /* [in] */ IHandler* h)
{
    AutoLock lock(mLock);
    Int32 size = 0;
    mRegistrants->GetSize(&size);
    // for (Int32 i = 0, s = mRegistrants->GetSize() ; i < s ; i++) {
    for (Int32 i = 0; i < size ; i++) {
        AutoPtr<IInterface> obj;
        mRegistrants->Get(i, (IInterface**)&obj);
        Registrant* r = (Registrant*)IObject::Probe(obj);
        AutoPtr<IHandler> rh;

        r->GetHandler((IHandler**)&rh);

        /* Clean up both the requested registrant and
         * any now-collected registrants
         */
        if (rh == NULL || rh.Get() == h) {
            r->Clear();
        }
    }

    RemoveCleared();
}

} // namespace Os
} // namespace Droid
} // namespace Elastos

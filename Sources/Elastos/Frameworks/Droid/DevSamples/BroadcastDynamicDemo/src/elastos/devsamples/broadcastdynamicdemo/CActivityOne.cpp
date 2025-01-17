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

#include "CActivityOne.h"
#include "CBroadcastReceiverOne.h"
#include "CBroadcastReceiverTwo.h"
#include "R.h"
#include <Elastos.Droid.App.h>
#include <Elastos.Droid.Content.h>
#include <Elastos.Droid.Os.h>
#include <Elastos.Droid.View.h>
#include <Elastos.Droid.Widget.h>
#include <elastos/utility/logging/Logger.h>

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::IIntent;
using Elastos::Droid::Content::CIntent;
using Elastos::Droid::Content::IIntentFilter;
using Elastos::Droid::Content::CIntentFilter;
using Elastos::Droid::View::EIID_IViewOnClickListener;
using Elastos::Droid::Widget::IButton;
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace DevSamples {
namespace BroadcastDynamicDemo {

static const String TAG("BroadcastDynamicDemo::CActivityOne");
const String RECEIVER_KEY("Elastos.DevSamples.BroadcastDemo.TEST_RECEIVER");
const Boolean CActivityOne::TEST_ORDERED_BROADCAST = TRUE;

//=======================================================================
// MyListener
//=======================================================================

CAR_INTERFACE_IMPL(CActivityOne::MyListener, Object, IViewOnClickListener)

CActivityOne::MyListener::MyListener(
    /* [in] */ CActivityOne* host)
    : mHost(host)
{
}

ECode CActivityOne::MyListener::OnClick(
    /* [in] */ IView* v)
{
    Int32 id;
    v->GetId(&id);
    switch(id) {
    case R::id::RegisterReceiver:
        Logger::I(TAG, "MyListener::OnClick Register");
        mHost->Register();
        break;

    case R::id::UnregisterReceiver:
        Logger::I(TAG, "MyListener::OnClick Unregister");
        mHost->Unregister();
        break;

    case R::id::SendBroadcast:
        Logger::I(TAG, "MyListener::OnClick Send");
        mHost->Send();
        break;
    }

    return NOERROR;
}

//=======================================================================
// CActivityOne
//=======================================================================

CAR_OBJECT_IMPL(CActivityOne)

ECode CActivityOne::constructor()
{
    Logger::I(TAG, " >> constructor()");
    return Activity::constructor();
}

ECode CActivityOne::OnCreate(
    /* [in] */ IBundle* savedInstanceState)
{
    Logger::I(TAG, " >> OnCreate()");
    Activity::OnCreate(savedInstanceState);
    SetContentView(R::layout::main);

    AutoPtr<MyListener> l = new MyListener(this);
    AutoPtr<IView> view = FindViewById(R::id::RegisterReceiver);
    view->SetOnClickListener(l.Get());

    view = FindViewById(R::id::UnregisterReceiver);
    view->SetOnClickListener(l.Get());

    view = FindViewById(R::id::SendBroadcast);
    view->SetOnClickListener(l.Get());

    return NOERROR;
}

ECode CActivityOne::OnStart()
{
    Logger::I(TAG, " >> OnStart()");
    return Activity::OnStart();
}

ECode CActivityOne::OnResume()
{
    Logger::I(TAG, " >> OnResume()");
    return Activity::OnResume();
}

ECode CActivityOne::OnPause()
{
    Logger::I(TAG, " >> OnPause()");
    return Activity::OnPause();
}

ECode CActivityOne::OnStop()
{
    Logger::I(TAG, " >> OnStop()");
    return Activity::OnStop();
}

ECode CActivityOne::OnDestroy()
{
    Logger::I(TAG, " >> OnDestroy()");
    Unregister();
    return Activity::OnDestroy();
}

ECode CActivityOne::OnActivityResult(
    /* [in] */ Int32 requestCode,
    /* [in] */ Int32 resultCode,
    /* [in] */ IIntent *data)
{
    Logger::I(TAG, " >> OnActivityResult()");
    return Activity::OnActivityResult(requestCode, resultCode, data);
}

ECode CActivityOne::Register()
{
    if (mReceiverOne == NULL) {
        AutoPtr<IIntentFilter> filter;
        CIntentFilter::New(RECEIVER_KEY, (IIntentFilter**)&filter);
        filter->SetPriority(150);
        AutoPtr<IIntent> intent;
        CBroadcastReceiverOne::New((IBroadcastReceiver**)&mReceiverOne);
        RegisterReceiver(mReceiverOne, filter, (IIntent**)&intent);
    }

    if (mReceiverTwo == NULL) {
        AutoPtr<IIntentFilter> filter;
        CIntentFilter::New(RECEIVER_KEY, (IIntentFilter**)&filter);
        filter->SetPriority(250);
        AutoPtr<IIntent> intent;
        CBroadcastReceiverTwo::New((IBroadcastReceiver**)&mReceiverTwo);
        RegisterReceiver(mReceiverTwo, filter, (IIntent**)&intent);
    }
    return NOERROR;
}

ECode CActivityOne::Unregister()
{
    if (mReceiverOne != NULL) {
        UnregisterReceiver(mReceiverOne);
        mReceiverOne = NULL;
    }

    if (mReceiverTwo != NULL) {
        UnregisterReceiver(mReceiverTwo);
        mReceiverTwo = NULL;
    }
    return NOERROR;
}

ECode CActivityOne::Send()
{
    AutoPtr<IIntent> intent;
    CIntent::New(RECEIVER_KEY, (IIntent**)&intent);
    intent->PutExtra(String("msg"), String("Hello Broadcast!"));

    if (TEST_ORDERED_BROADCAST) {
#if 1
        return SendOrderedBroadcast(intent, String(NULL));
#else
        // test permission.
        //
        String permission("kesalin.permission.BROADCAST_PERMISSION");
        return SendOrderedBroadcast(intent, permission);
#endif
    }
    else {
        return SendBroadcast(intent);
    }
}

} // namespace BroadcastDynamicDemo
} // namespace DevSamples
} // namespace Elastos

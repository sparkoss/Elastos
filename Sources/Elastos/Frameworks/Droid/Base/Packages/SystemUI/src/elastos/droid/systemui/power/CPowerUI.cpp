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

#include "elastos/droid/systemui/power/CPowerUI.h"
#include "elastos/droid/systemui/power/CPowerUIReceiver.h"
#include "elastos/droid/systemui/power/PowerNotificationWarnings.h"
#include "Elastos.Droid.Net.h"
#include "Elastos.Droid.Provider.h"
#include "elastos/droid/os/SystemClock.h"
#include "elastos/droid/R.h"
#include <elastos/utility/logging/Logger.h>
#include <elastos/utility/logging/Slogger.h>

using Elastos::Droid::Content::CIntentFilter;
using Elastos::Droid::Content::IContentResolver;
using Elastos::Droid::Content::IIntentFilter;
using Elastos::Droid::Content::Res::IResources;
using Elastos::Droid::Net::IUri;
using Elastos::Droid::Os::CHandler;
using Elastos::Droid::Os::IBatteryManager;
using Elastos::Droid::Os::IUserHandle;
using Elastos::Droid::Os::SystemClock;
using Elastos::Droid::Provider::CSettingsGlobal;
using Elastos::Droid::Provider::ISettingsGlobal;
using Elastos::Droid::SystemUI::StatusBar::Phone::IPhoneStatusBar;
using Elastos::Droid::R;
using Elastos::Utility::Logging::Logger;
using Elastos::Utility::Logging::Slogger;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Power {

//---------------------------------------------------------------------------------------------
//  CPowerUI::Receiver
//-----------------------------------------------------------------------------------------------

ECode CPowerUI::Receiver::constructor(
    /* [in] */ IPowerUI* host)
{
    mHost = (CPowerUI*)host;
    return BroadcastReceiver::constructor();
}

ECode CPowerUI::Receiver::Init()
{
    // Register for Intent broadcasts for...
    AutoPtr<IIntentFilter> filter;
    CIntentFilter::New((IIntentFilter**)&filter);
    filter->AddAction(IIntent::ACTION_BATTERY_CHANGED);
    filter->AddAction(IIntent::ACTION_SCREEN_OFF);
    filter->AddAction(IIntent::ACTION_SCREEN_ON);
    filter->AddAction(IPowerManager::ACTION_POWER_SAVE_MODE_CHANGING);
    filter->AddAction(IPowerManager::ACTION_POWER_SAVE_MODE_CHANGED);
    AutoPtr<IIntent> i;
    mHost->mContext->RegisterReceiver(this, filter, String(NULL), mHost->mHandler, (IIntent**)&i);
    UpdateSaverMode();
    return NOERROR;
}

void CPowerUI::Receiver::UpdateSaverMode()
{
    Boolean isPowerSaveMode;
    mHost->mPowerManager->IsPowerSaveMode(&isPowerSaveMode);
    mHost->SetSaverMode(isPowerSaveMode);
}

ECode CPowerUI::Receiver::OnReceive(
    /* [in] */ IContext* context,
    /* [in] */ IIntent* intent)
{
    String action;
    intent->GetAction(&action);
    if (action.Equals(IIntent::ACTION_BATTERY_CHANGED)) {
        const Int32 oldBatteryLevel = mHost->mBatteryLevel;
        Int32 bl;
        intent->GetInt32Extra(IBatteryManager::EXTRA_LEVEL, 100, &bl);
        mHost->mBatteryLevel = bl;
        const Int32 oldBatteryStatus = mHost->mBatteryStatus;

        Int32 bs;
        intent->GetInt32Extra(IBatteryManager::EXTRA_STATUS,
            IBatteryManager::BATTERY_STATUS_UNKNOWN, &bs);
        mHost->mBatteryStatus = bs;
        const Int32 oldPlugType = mHost->mPlugType;

        Int32 pt;
        intent->GetInt32Extra(IBatteryManager::EXTRA_PLUGGED, 1, &pt);
        mHost->mPlugType = pt;
        const Int32 oldInvalidCharger = mHost->mInvalidCharger;

        Int32 ic;
        intent->GetInt32Extra(IBatteryManager::EXTRA_INVALID_CHARGER, 0, &ic);
        mHost->mInvalidCharger = ic;

        const Boolean plugged = mHost->mPlugType != 0;
        const Boolean oldPlugged = oldPlugType != 0;

        Int32 oldBucket = mHost->FindBatteryLevelBucket(oldBatteryLevel);
        Int32 bucket = mHost->FindBatteryLevelBucket(mHost->mBatteryLevel);

        if (DEBUG) {
            Slogger::D(TAG, "buckets   .....%d .. %d .. ",
                mHost->mLowBatteryAlertCloseLevel,
                (*(mHost->mLowBatteryReminderLevels))[0],
                (*(mHost->mLowBatteryReminderLevels))[1]);
            Slogger::D(TAG, "level          %d --> %d", oldBatteryLevel, mHost->mBatteryLevel);
            Slogger::D(TAG, "status         %d --> %d", oldBatteryStatus, mHost->mBatteryStatus);
            Slogger::D(TAG, "plugType       %d --> %d", oldPlugType, mHost->mPlugType);
            Slogger::D(TAG, "invalidCharger %d --> %d", oldInvalidCharger, mHost->mInvalidCharger);
            Slogger::D(TAG, "bucket         %d --> %d", oldBucket, bucket);
            Slogger::D(TAG, "plugged        %d --> %d", oldPlugged, plugged);
        }

        Boolean isInvalidChargerWarningShowing;
        mHost->mWarnings->IsInvalidChargerWarningShowing(&isInvalidChargerWarningShowing);
        mHost->mWarnings->Update(mHost->mBatteryLevel, bucket, mHost->mScreenOffTime);
        if (oldInvalidCharger == 0 && mHost->mInvalidCharger != 0) {
            Slogger::D(TAG, "showing invalid charger warning");
            mHost->mWarnings->ShowInvalidChargerWarning();
            return E_NULL_POINTER_EXCEPTION;
        }
        else if (oldInvalidCharger != 0 && mHost->mInvalidCharger == 0) {
            mHost->mWarnings->DismissInvalidChargerWarning();
        }
        else if (isInvalidChargerWarningShowing) {
            // if invalid charger is showing, don't show low battery
            return E_NULL_POINTER_EXCEPTION;
        }

        if (!plugged
                && (bucket < oldBucket || oldPlugged)
                && mHost->mBatteryStatus != IBatteryManager::BATTERY_STATUS_UNKNOWN
                && bucket < 0) {
            // only play SFX when the dialog comes up or the bucket changes
            const Boolean playSound = bucket != oldBucket || oldPlugged;
            mHost->mWarnings->ShowLowBatteryWarning(playSound);
        }
        else if (plugged || (bucket > oldBucket && bucket > 0)) {
            mHost->mWarnings->DismissLowBatteryWarning();
        }
        else {
            mHost->mWarnings->UpdateLowBatteryWarning();
        }
    }
    else if (IIntent::ACTION_SCREEN_OFF.Equals(action)) {
        mHost->mScreenOffTime = SystemClock::GetElapsedRealtime();
    }
    else if (IIntent::ACTION_SCREEN_ON.Equals(action)) {
        mHost->mScreenOffTime = -1;
    }
    else if (IPowerManager::ACTION_POWER_SAVE_MODE_CHANGED.Equals(action)) {
        UpdateSaverMode();
    }
    else if (IPowerManager::ACTION_POWER_SAVE_MODE_CHANGING.Equals(action)) {
        Boolean b;
        intent->GetBooleanExtra(IPowerManager::EXTRA_POWER_SAVE_MODE, FALSE, &b);
        mHost->SetSaverMode(b);
    }
    else {
        Slogger::W(TAG, "unknown intent: %s", TO_CSTR(intent));
    }
    return NOERROR;
}

//---------------------------------------------------------------------------------------------
//  CPowerUI::MyObs
//-----------------------------------------------------------------------------------------------

CPowerUI::MyObs::MyObs(
    /* [in] */ CPowerUI* host)
    : mHost(host)
{
}

ECode CPowerUI::MyObs::OnChange(
    /* [in] */ Boolean selfChange)
{
    return mHost->UpdateBatteryWarningLevels();
}

//---------------------------------------------------------------------------------------------
//  CPowerUI
//-----------------------------------------------------------------------------------------------

const String CPowerUI::TAG("CPowerUI");
const Boolean CPowerUI::DEBUG = FALSE;

CAR_OBJECT_IMPL(CPowerUI)

CAR_INTERFACE_IMPL(CPowerUI, SystemUI, IPowerUI)

CPowerUI::CPowerUI()
    : mBatteryLevel(100)
    , mBatteryStatus(IBatteryManager::BATTERY_STATUS_UNKNOWN)
    , mPlugType(0)
    , mInvalidCharger(0)
    , mLowBatteryAlertCloseLevel(0)
    , mScreenOffTime(-1)
{
}

ECode CPowerUI::constructor()
{
    CHandler::New((IHandler**)&mHandler);
    AutoPtr<IBroadcastReceiver> receiver;
    CPowerUIReceiver::New(this, (IBroadcastReceiver**)&receiver);
    mReceiver = (Receiver*)receiver.Get();
    mLowBatteryReminderLevels = ArrayOf<Int32>::Alloc(2);
    return NOERROR;
}

ECode CPowerUI::Start()
{
    AutoPtr<IInterface> pmobj;
    mContext->GetSystemService(IContext::POWER_SERVICE, (IInterface**)&pmobj);
    mPowerManager = IPowerManager::Probe(pmobj);
    Boolean isScreenOn;
    mPowerManager->IsScreenOn(&isScreenOn);
    mScreenOffTime = isScreenOn ? -1 : SystemClock::GetElapsedRealtime();

    AutoPtr<PowerNotificationWarnings> warnings = new PowerNotificationWarnings();
    AutoPtr<IInterface> obj = SystemUI::GetComponent(String("EIID_IPhoneStatusBar"));
    warnings->constructor(mContext, IPhoneStatusBar::Probe(obj));
    mWarnings = warnings;

    AutoPtr<MyObs> obs = new MyObs(this);
    obs->constructor(mHandler);

    AutoPtr<IContentResolver> resolver;
    mContext->GetContentResolver((IContentResolver**)&resolver);

    AutoPtr<ISettingsGlobal> sg;
    CSettingsGlobal::AcquireSingleton((ISettingsGlobal**)&sg);
    AutoPtr<IUri> uri;
    sg->GetUriFor(ISettingsGlobal::LOW_POWER_MODE_TRIGGER_LEVEL, (IUri**)&uri);
    resolver->RegisterContentObserver(uri, FALSE, obs, IUserHandle::USER_ALL);

    UpdateBatteryWarningLevels();
    mReceiver->Init();
    return NOERROR;
}

ECode CPowerUI::SetSaverMode(
    /* [in] */ Boolean mode)
{
    return mWarnings->ShowSaverMode(mode);
}

ECode CPowerUI::UpdateBatteryWarningLevels()
{
    AutoPtr<IResources> res;
    mContext->GetResources((IResources**)&res);
    Int32 critLevel;
    res->GetInteger(R::integer::config_criticalBatteryWarningLevel, &critLevel);

    AutoPtr<IContentResolver> resolver;
    mContext->GetContentResolver((IContentResolver**)&resolver);

    Int32 defWarnLevel;
    res->GetInteger(R::integer::config_lowBatteryWarningLevel, &defWarnLevel);

    AutoPtr<ISettingsGlobal> sg;
    CSettingsGlobal::AcquireSingleton((ISettingsGlobal**)&sg);
    Int32 warnLevel;
    sg->GetInt32(resolver, ISettingsGlobal::LOW_POWER_MODE_TRIGGER_LEVEL, defWarnLevel, &warnLevel);
    if (warnLevel == 0) {
        warnLevel = defWarnLevel;
    }
    if (warnLevel < critLevel) {
        warnLevel = critLevel;
    }

    (*mLowBatteryReminderLevels)[0] = warnLevel;
    (*mLowBatteryReminderLevels)[1] = critLevel;

    Int32 i;
    res->GetInteger(R::integer::config_lowBatteryCloseWarningBump, &i);
    mLowBatteryAlertCloseLevel = (*mLowBatteryReminderLevels)[0] + i;
    return NOERROR;
}

Int32 CPowerUI::FindBatteryLevelBucket(
    /* [in] */ Int32 level)
{
    if (level >= mLowBatteryAlertCloseLevel) {
        return 1;
    }
    if (level > (*mLowBatteryReminderLevels)[0]) {
        return 0;
    }
    const Int32 N = mLowBatteryReminderLevels->GetLength();
    for (Int32 i = N - 1; i >= 0; i--) {
        if (level <= (*mLowBatteryReminderLevels)[i]) {
            return -1 - i;
        }
    }
    Logger::E(TAG, "not possible!");
    return (Int32)(E_RUNTIME_EXCEPTION);
}

} // namespace Power
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos
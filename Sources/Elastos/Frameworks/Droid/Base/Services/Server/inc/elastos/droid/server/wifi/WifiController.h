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

#ifndef __ELASTOS_DROID_SERVER_WIFI_WIFICONTROLLER_H__
#define __ELASTOS_DROID_SERVER_WIFI_WIFICONTROLLER_H__

#include "Elastos.Droid.Content.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/content/BroadcastReceiver.h"
#include "elastos/droid/database/ContentObserver.h"
#include "elastos/droid/internal/utility/State.h"
#include "elastos/droid/internal/utility/StateMachine.h"
#include "elastos/droid/server/wifi/WifiStateMachine.h"
#include "elastos/droid/server/wifi/WifiSettingsStore.h"

using Elastos::Droid::App::IAlarmManager;
using Elastos::Droid::App::IPendingIntent;
using Elastos::Droid::Content::BroadcastReceiver;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::IIntent;
using Elastos::Droid::Database::ContentObserver;
using Elastos::Droid::Internal::Utility::State;
using Elastos::Droid::Internal::Utility::StateMachine;
using Elastos::Droid::Internal::Utility::IProtocol;
using Elastos::Droid::Os::IHandler;
using Elastos::Droid::Os::ILooper;
using Elastos::Droid::Os::IMessage;
using Elastos::Droid::Os::IWorkSource;
using Elastos::Droid::Net::INetworkInfo;
using Elastos::IO::IFileDescriptor;
using Elastos::IO::IPrintWriter;

namespace Elastos {
namespace Droid {
namespace Server {
namespace Wifi {

class WifiServiceImpl;

class WifiController
    : public StateMachine
{
public:
    class DefaultState
        : public State
    {
    public:
        DefaultState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI ProcessMessage(
            /* [in] */ IMessage* msg,
            /* [out] */ Boolean* result);

        CARAPI_(String) GetName()
        {
            return String("DefaultState");
        }

    private:
        WifiController* mOwner;
    };

    class ApStaDisabledState
        : public State
    {
    public:
        ApStaDisabledState(
            /* [in] */ WifiController* owner)
            : mDeferredEnableSerialNumber(0)
            , mHaveDeferredEnable(FALSE)
            , mDisabledTimestamp(0)
            , mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        // @Override
        CARAPI ProcessMessage(
            /* [in] */ IMessage* msg,
            /* [out] */ Boolean* result);

        CARAPI_(String) GetName()
        {
            return String("ApStaDisabledState");
        }

    private:
        CARAPI_(Boolean) DoDeferEnable(
            /* [in] */ IMessage* msg);

    private:
        Int32 mDeferredEnableSerialNumber;
        Boolean mHaveDeferredEnable;
        Int64 mDisabledTimestamp;
        WifiController* mOwner;
    };

    class StaEnabledState
        : public State
    {
    public:
        StaEnabledState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        // @Override
        CARAPI ProcessMessage(
            /* [in] */ IMessage* msg,
            /* [out] */ Boolean* result);

        CARAPI_(String) GetName()
        {
            return String("StaEnabledState");
        }

    private:
        WifiController* mOwner;
    };

    class StaDisabledWithScanState
        : public State
    {
    public:
        StaDisabledWithScanState(
            /* [in] */ WifiController* owner)
            : mDeferredEnableSerialNumber(0)
            , mHaveDeferredEnable(FALSE)
            , mDisabledTimestamp(0)
            , mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        // @Override
        CARAPI ProcessMessage(
            /* [in] */ IMessage* msg,
            /* [out] */ Boolean* result);

        CARAPI_(String) GetName()
        {
            return String("StaDisabledWithScanState");
        }

    private:
        CARAPI_(Boolean) DoDeferEnable(
            /* [in] */ IMessage* msg);

    private:
        Int32 mDeferredEnableSerialNumber;
        Boolean mHaveDeferredEnable;
        Int64 mDisabledTimestamp;
        WifiController* mOwner;
    };

    class ApEnabledState
        : public State
    {
    public:
        ApEnabledState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI ProcessMessage(
            /* [in] */ IMessage* msg,
            /* [out] */ Boolean* result);

        CARAPI_(String) GetName()
        {
            return String("ApEnabledState");
        }

    private:
        WifiController* mOwner;
    };

    class EcmState
        : public State
    {
    public:
        EcmState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        // @Override
        CARAPI ProcessMessage(
            /* [in] */ IMessage* msg,
            /* [out] */ Boolean* result);

        CARAPI_(String) GetName()
        {
            return String("EcmState");
        }

    private:
        WifiController* mOwner;
    };

    /* Parent: StaEnabledState */
    class DeviceActiveState
        : public State
    {
    public:
        DeviceActiveState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        // @Override
        CARAPI ProcessMessage(
            /* [in] */ IMessage* msg,
            /* [out] */ Boolean* result);

        CARAPI_(String) GetName()
        {
            return String("DeviceActiveState");
        }

    private:
        WifiController* mOwner;
    };

    /* Parent: DeviceActiveState. Device is active, and an app is holding a high perf lock. */
    class DeviceActiveHighPerfState
        : public State
    {
    public:
        DeviceActiveHighPerfState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        CARAPI_(String) GetName()
        {
            return String("DeviceActiveHighPerfState");
        }

    private:
        WifiController* mOwner;
    };

    /* Parent: StaEnabledState */
    class DeviceInactiveState
        : public State
    {
    public:
        DeviceInactiveState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI ProcessMessage(
            /* [in] */ IMessage* msg,
            /* [out] */ Boolean* result);

        CARAPI_(String) GetName()
        {
            return String("DeviceInactiveState");
        }

    private:
        WifiController* mOwner;
    };

    /* Parent: DeviceInactiveState. Device is inactive, but an app is holding a scan only lock. */
    class ScanOnlyLockHeldState
        : public State
    {
    public:
        ScanOnlyLockHeldState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        CARAPI_(String) GetName()
        {
            return String("ScanOnlyLockHeldState");
        }

    private:
        WifiController* mOwner;
    };

    /* Parent: DeviceInactiveState. Device is inactive, but an app is holding a full lock. */
    class FullLockHeldState
        : public State
    {
    public:
        FullLockHeldState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        CARAPI_(String) GetName()
        {
            return String("FullLockHeldState");
        }

    private:
        WifiController* mOwner;
    };

    /* Parent: DeviceInactiveState. Device is inactive, but an app is holding a high perf lock. */
    class FullHighPerfLockHeldState
        : public State
    {
    public:
        FullHighPerfLockHeldState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        CARAPI_(String) GetName()
        {
            return String("FullHighPerfLockHeldState");
        }

    private:
        WifiController* mOwner;
    };

    /* Parent: DeviceInactiveState. Device is inactive and no app is holding a wifi lock. */
    class NoLockHeldState
        : public State
    {
    public:
        NoLockHeldState(
            /* [in] */ WifiController* owner)
            : mOwner(owner)
        {
        }

        // @Override
        CARAPI Enter();

        CARAPI_(String) GetName()
        {
            return String("NoLockHeldState");
        }

    private:
        WifiController* mOwner;
    };

private:
    class InnerBroadcastReceiver1
        : public BroadcastReceiver
    {
    public:
        TO_STRING_IMPL("WifiController::InnerBroadcastReceiver1")

        InnerBroadcastReceiver1(
            /* [in] */ WifiController* owner);

        // @Override
        CARAPI OnReceive(
            /* [in] */ IContext* context,
            /* [in] */ IIntent* intent);

    private:
        WifiController* mOwner;
    };

    class InnerContentObserver1
        : public ContentObserver
    {
    public:
        TO_STRING_IMPL("WifiController::InnerContentObserver1")

        CARAPI constructor(
            /* [in] */ WifiController* owner,
            /* [in] */ IHandler* handler);

        // @Override
        CARAPI OnChange(
            /* [in] */ Boolean selfChange);

    private:
        WifiController* mOwner;
    };

    class InnerContentObserver3
        : public ContentObserver
    {
    public:
        TO_STRING_IMPL("WifiController::InnerContentObserver3")

        CARAPI constructor(
            /* [in] */ WifiController* owner,
            /* [in] */ IHandler* handler);

        // @Override
        CARAPI OnChange(
            /* [in] */ Boolean selfChange);

    private:
        WifiController* mOwner;
    };

    class InnerContentObserver5
        : public ContentObserver
    {
    public:
        TO_STRING_IMPL("WifiController::InnerContentObserver5")

        CARAPI constructor(
            /* [in] */ WifiController* owner,
            /* [in] */ IHandler* handler);

        // @Override
        CARAPI OnChange(
            /* [in] */ Boolean selfChange);

    private:
        WifiController* mOwner;
    };

public:
    WifiController(
        /* [in] */ IContext* context,
        /* [in] */ WifiServiceImpl* service,
        /* [in] */ ILooper* looper);

    // @Override
    CARAPI Dump(
        /* [in] */ IFileDescriptor* fd,
        /* [in] */ IPrintWriter* pw,
        /* [in] */ ArrayOf<String>* args);

private:
    CARAPI_(void) InitializeAndRegisterForSettingsChange(
        /* [in] */ ILooper* looper);

    CARAPI_(void) ReadStayAwakeConditions();

    CARAPI_(void) ReadWifiIdleTime();

    CARAPI_(void) ReadWifiSleepPolicy();

    CARAPI_(void) ReadWifiReEnableDelay();

    /**
      * Observes settings changes to scan always mode.
      */
    CARAPI_(void) RegisterForStayAwakeModeChange(
        /* [in] */ IHandler* handler);

    /**
      * Observes settings changes to scan always mode.
      */
    CARAPI_(void) RegisterForWifiIdleTimeChange(
        /* [in] */ IHandler* handler);

    /**
      * Observes changes to wifi sleep policy
      */
    CARAPI_(void) RegisterForWifiSleepPolicyChange(
        /* [in] */ IHandler* handler);

    /**
      * Determines whether the Wi-Fi chipset should stay awake or be put to
      * sleep. Looks at the setting for the sleep policy and the current
      * conditions.
      *
      * @see #shouldDeviceStayAwake(int)
      */
    CARAPI_(Boolean) ShouldWifiStayAwake(
        /* [in] */ Int32 pluggedType);

    /**
      * Determine whether the bit value corresponding to {@code pluggedType} is set in
      * the bit string mStayAwakeConditions. This determines whether the device should
      * stay awake based on the current plugged type.
      *
      * @param pluggedType the type of plug (USB, AC, or none) for which the check is
      * being made
      * @return {@code true} if {@code pluggedType} indicates that the device is
      * supposed to stay awake, {@code false} otherwise.
      */
    CARAPI_(Boolean) ShouldDeviceStayAwake(
        /* [in] */ Int32 pluggedType);

    CARAPI_(void) UpdateBatteryWorkSource();

    CARAPI_(void) CheckLocksAndTransitionWhenDeviceActive();

    CARAPI_(void) CheckLocksAndTransitionWhenDeviceIdle();

public:
    AutoPtr<INetworkInfo> mNetworkInfo;
    /* References to values tracked in WifiService */
    AutoPtr<WifiStateMachine> mWifiStateMachine;
    AutoPtr<WifiSettingsStore> mSettingsStore;
    //real type is WifiServiceImpl::LockList
    //use type Object here, avoid the cross-reference
    AutoPtr<Object> mLocks;
    static const Int32 BASE = IProtocol::BASE_WIFI_CONTROLLER;//0x00026000 = 155648
    static const Int32 CMD_EMERGENCY_MODE_CHANGED = BASE + 1;
    static const Int32 CMD_SCREEN_ON = BASE + 2;
    static const Int32 CMD_SCREEN_OFF = BASE + 3;
    static const Int32 CMD_BATTERY_CHANGED = BASE + 4;
    static const Int32 CMD_DEVICE_IDLE = BASE + 5;
    static const Int32 CMD_LOCKS_CHANGED = BASE + 6;
    static const Int32 CMD_SCAN_ALWAYS_MODE_CHANGED = BASE + 7;
    static const Int32 CMD_WIFI_TOGGLED = BASE + 8;
    static const Int32 CMD_AIRPLANE_TOGGLED = BASE + 9;
    static const Int32 CMD_SET_AP = BASE + 10;
    static const Int32 CMD_DEFERRED_TOGGLE = BASE + 11;
    static const Int32 CMD_USER_PRESENT = BASE + 12;

private:
    static const String TAG;
    static const Boolean DBG;
    AutoPtr<IContext> mContext;
    Boolean mScreenOff;
    Boolean mDeviceIdle;
    Int32 mPluggedType;
    Int32 mStayAwakeConditions;
    Int64 mIdleMillis;
    Int32 mSleepPolicy;
    Boolean mFirstUserSignOnSeen;
    AutoPtr<IAlarmManager> mAlarmManager;
    AutoPtr<IPendingIntent> mIdleIntent;
    static const Int32 IDLE_REQUEST = 0;
    /**
      * See {@link Settings.Global#WIFI_IDLE_MS}. This is the default value if a
      * Settings.Global value is not present. This timeout value is chosen as
      * the approximate point at which the battery drain caused by Wi-Fi
      * being enabled but not active exceeds the battery drain caused by
      * re-establishing a connection to the mobile data network.
      */
    static const Int64 DEFAULT_IDLE_MS = 15 * 60 * 1000;
    /* 15 minutes */
    /**
      * See {@link Settings.Global#WIFI_REENABLE_DELAY_MS}.  This is the default value if a
      * Settings.Global value is not present.  This is the minimum time after wifi is disabled
      * we'll act on an enable.  Enable requests received before this delay will be deferred.
      */
    static const Int64 DEFAULT_REENABLE_DELAY_MS = 500;
    // finding that delayed messages can sometimes be delivered earlier than expected
    // probably rounding errors..  add a margin to prevent problems
    static const Int64 DEFER_MARGIN_MS = 5;
    static const String ACTION_DEVICE_IDLE;
    /**
      * Temporary for computing UIDS that are responsible for starting WIFI.
      * Protected by mWifiStateTracker lock.
      */
    AutoPtr<IWorkSource> mTmpWorkSource;
    Int64 mReEnableDelayMillis;
    AutoPtr<DefaultState> mDefaultState;
    AutoPtr<StaEnabledState> mStaEnabledState;
    AutoPtr<ApStaDisabledState> mApStaDisabledState;
    AutoPtr<StaDisabledWithScanState> mStaDisabledWithScanState;
    AutoPtr<ApEnabledState> mApEnabledState;
    AutoPtr<DeviceActiveState> mDeviceActiveState;
    AutoPtr<DeviceActiveHighPerfState> mDeviceActiveHighPerfState;
    AutoPtr<DeviceInactiveState> mDeviceInactiveState;
    AutoPtr<ScanOnlyLockHeldState> mScanOnlyLockHeldState;
    AutoPtr<FullLockHeldState> mFullLockHeldState;
    AutoPtr<FullHighPerfLockHeldState> mFullHighPerfLockHeldState;
    AutoPtr<NoLockHeldState> mNoLockHeldState;
    AutoPtr<EcmState> mEcmState;
};

} // namespace Wifi
} // namespace Server
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SERVER_WIFI_WIFICONTROLLER_H__

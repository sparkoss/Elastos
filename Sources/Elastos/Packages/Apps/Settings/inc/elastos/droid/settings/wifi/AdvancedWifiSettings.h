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

#ifndef __ELASTOS_DROID_SETTINGS_WIFI_ADVANCEDWIFISETTINGS_H__
#define __ELASTOS_DROID_SETTINGS_WIFI_ADVANCEDWIFISETTINGS_H__

#include "Elastos.Droid.Net.h"
#include "Elastos.Droid.Wifi.h"
#include "elastos/droid/settings/SettingsPreferenceFragment.h"
#include "elastos/droid/app/DialogFragment.h"
#include "elastos/droid/content/BroadcastReceiver.h"

using Elastos::Droid::App::IDialog;
using Elastos::Droid::App::DialogFragment;
using Elastos::Droid::Content::BroadcastReceiver;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::IIntent;
using Elastos::Droid::Content::IIntentFilter;
using Elastos::Droid::Net::INetworkScoreManager;
using Elastos::Droid::Wifi::IWifiManager;
using Elastos::Droid::Os::IBundle;
using Elastos::Droid::Preference::IPreference;
using Elastos::Droid::Preference::IPreferenceOnPreferenceChangeListener;
using Elastos::Droid::Preference::IPreferenceOnPreferenceClickListener;
using Elastos::Droid::Preference::IPreferenceScreen;

namespace Elastos {
namespace Droid {
namespace Settings {
namespace Wifi {

class AdvancedWifiSettings
    : public SettingsPreferenceFragment
{
public:
    class InnerListener
        : public Object
        , public IPreferenceOnPreferenceChangeListener
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("AdvancedWifiSettings::InnerListener")

        InnerListener(
            /* [in] */ AdvancedWifiSettings* host);

        //@Override
        CARAPI OnPreferenceChange(
            /* [in] */ IPreference* preference,
            /* [in] */ IInterface* newValue,
            /* [out] */ Boolean* result);

    private:
        AdvancedWifiSettings* mHost;
    };

    /* Wrapper class for the WPS dialog to properly handle life cycle events like rotation. */
    class WpsFragment
        : public DialogFragment
    {
    public:
        WpsFragment();

        ~WpsFragment();

        // Public default constructor is required for rotation.
        CARAPI constructor();

        CARAPI constructor(
            /* [in] */ Int32 wpsSetup);

        //@Override
        CARAPI OnCreateDialog(
            /* [in] */ IBundle* savedInstanceState,
            /* [out] */ IDialog** dialog);

    private:
        static Int32 mWpsSetup;
    };

private:
    class MyBroadcastReceiver
        : public BroadcastReceiver
    {
    public:
        TO_STRING_IMPL("AdvancedWifiSettings::MyBroadcastReceiver")

        MyBroadcastReceiver(
            /* [in] */ AdvancedWifiSettings* host);

        ~MyBroadcastReceiver();

        //@Override
        CARAPI OnReceive(
            /* [in] */ IContext* context,
            /* [in] */ IIntent* intent);

    private:
        AdvancedWifiSettings* mHost;
    };

    class InitOnPreferenceClickListener
        : public Object
        , public IPreferenceOnPreferenceClickListener
    {
    public:
        CAR_INTERFACE_DECL();

        InitOnPreferenceClickListener(
            /* [in] */ AdvancedWifiSettings* host,
            /* [in] */ Int32 id,
            /* [in] */ const String& key);

        ~InitOnPreferenceClickListener();

        CARAPI OnPreferenceClick(
            /* [in] */ IPreference* preference,
            /* [out] */ Boolean* result);

    private:
        AdvancedWifiSettings* mHost;
        Int32 mId;
        String mKey;
    };

public:
    AdvancedWifiSettings();

    ~AdvancedWifiSettings();

    CARAPI constructor();

    //@Override
    CARAPI OnCreate(
        /* [in] */ IBundle* savedInstanceState);

    //@Override
    CARAPI OnActivityCreated(
        /* [in] */ IBundle* savedInstanceState);

    //@Override
    CARAPI OnResume();

    //@Override
    CARAPI OnPause();

    //@Override
    CARAPI OnPreferenceTreeClick(
        /* [in] */ IPreferenceScreen* screen,
        /* [in] */ IPreference* preference,
        /* [out] */ Boolean* result);

    //@Override
    CARAPI OnPreferenceChange(
        /* [in] */ IPreference* preference,
        /* [in] */ IInterface* newValue,
        /* [out] */ Boolean* result);

private:
    CARAPI_(void) InitPreferences();

    CARAPI_(void) UpdateSleepPolicySummary(
        /* [in] */ IPreference* sleepPolicyPref,
        /* [in] */ const String& value);

    CARAPI_(void) UpdateFrequencyBandSummary(
        /* [in] */ IPreference* frequencyBandPref,
        /* [in] */ Int32 index);

    CARAPI_(void) RefreshWifiInfo();

private:
    static const String TAG;
    static const String KEY_MAC_ADDRESS;
    static const String KEY_CURRENT_IP_ADDRESS;
    static const String KEY_FREQUENCY_BAND;
    static const String KEY_NOTIFY_OPEN_NETWORKS;
    static const String KEY_SLEEP_POLICY;
    static const String KEY_SCAN_ALWAYS_AVAILABLE;
    static const String KEY_INSTALL_CREDENTIALS;
    static const String KEY_WIFI_ASSISTANT;
    static const String KEY_WIFI_DIRECT;
    static const String KEY_WPS_PUSH;
    static const String KEY_WPS_PIN;

    AutoPtr<IWifiManager> mWifiManager;
    AutoPtr<INetworkScoreManager> mNetworkScoreManager;

    AutoPtr<IIntentFilter> mFilter;
    AutoPtr<BroadcastReceiver> mReceiver;
};

} // namespace Wifi
} // namespace Settings
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_SETTINGS_WIFI_ADVANCEDWIFISETTINGS_H__
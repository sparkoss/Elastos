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

//This file is autogenerated for
//    PowerMonitor.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_POWERMONITOR_CALLBACK_DEC_HH
#define ELASTOS_POWERMONITOR_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_PowerMonitor_nativeOnBatteryChargingChanged();
    extern void Elastos_PowerMonitor_nativeOnMainActivitySuspended();
    extern void Elastos_PowerMonitor_nativeOnMainActivityResumed();
    extern void Elastos_PowerMonitor_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Base {

struct ElaPowerMonitorCallback
{
    Boolean (*elastos_PowerMonitor_isBatteryPower)();
};

void* PowerMonitor::ElaPowerMonitorCallback_Init()
{
    static ElaPowerMonitorCallback sElaPowerMonitorCallback;

    sElaPowerMonitorCallback.elastos_PowerMonitor_isBatteryPower = &PowerMonitor::IsBatteryPower;

    Elastos_PowerMonitor_InitCallback((Handle32)&sElaPowerMonitorCallback);
    return &sElaPowerMonitorCallback;
}

static void* sPElaPowerMonitorCallback = PowerMonitor::ElaPowerMonitorCallback_Init();

} // namespace Base
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_POWERMONITOR_CALLBACK_DEC_HH

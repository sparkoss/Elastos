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

#ifndef __ELASTOS_DROID_NET_WIFI_P2P_NSD_CWIFIP2PSERVICERESPONSE_H__
#define __ELASTOS_DROID_NET_WIFI_P2P_NSD_CWIFIP2PSERVICERESPONSE_H__

#include "_Elastos_Droid_Wifi_P2p_Nsd_CWifiP2pServiceResponse.h"
#include "WifiP2pServiceResponse.h"

namespace Elastos {
namespace Droid {
namespace Wifi {
namespace P2p {
namespace Nsd {

CarClass(CWifiP2pServiceResponse), public WifiP2pServiceResponse
{
public:
    CAR_OBJECT_DECL()

    CARAPI GetServiceType(
        /* [out] */ Int32* serviceType);

    CARAPI GetStatus(
        /* [out] */ Int32* status);

    CARAPI GetTransactionId(
        /* [out] */ Int32 * pTransactionId);

    CARAPI GetRawData(
        /* [out, callee] */ ArrayOf<Byte>** rawData);

    CARAPI GetSrcDevice(
        /* [out] */ IWifiP2pDevice** srcDevice);

    CARAPI SetSrcDevice(
        /* [in] */ IWifiP2pDevice* dev);

    CARAPI ToString(
        /* [out] */ String* string);

    CARAPI Equals(
        /* [in] */ IInterface* obj,
        /* [out] */ Boolean* isEqual);

    CARAPI GetHashCode(
        /* [out] */ Int32* hashCode);

    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

    static CARAPI NewInstance(
        /* [in] */ const String& supplicantEvent,
        /* [out, callee] */ ArrayOf<IWifiP2pServiceResponse*>** list);
};

} // namespace Nsd
} // namespace P2p
} // namespace Wifi
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_NET_WIFI_P2P_NSD_CWIFIP2PSERVICERESPONSE_H__

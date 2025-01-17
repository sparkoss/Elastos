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

#include "elastos/droid/wifi/CRttManagerRttParams.h"

namespace Elastos {
namespace Droid {
namespace Wifi {

CAR_INTERFACE_IMPL(CRttManagerRttParams, Object, IRttManagerRttParams)

CAR_OBJECT_IMPL(CRttManagerRttParams)

ECode CRttManagerRttParams::constructor()
{
    mDeviceType = 0;
    mRequestType = 0;
    mFrequency = 0;
    mChannelWidth = 0;
    mNumSamples = 0;
    mNumRetries = 0;
    return NOERROR;
}

ECode CRttManagerRttParams::GetDeviceType(
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);
    *result = mDeviceType;
    return NOERROR;
}

ECode CRttManagerRttParams::SetDeviceType(
    /* [in] */ Int32 deviceType)
{
    mDeviceType = deviceType;
    return NOERROR;
}

ECode CRttManagerRttParams::GetRequestType(
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);
    *result = mRequestType;
    return NOERROR;
}

ECode CRttManagerRttParams::SetRequestType(
    /* [in] */ Int32 requestType)
{
    mRequestType = requestType;
    return NOERROR;
}

ECode CRttManagerRttParams::GetBssid(
    /* [out] */ String* result)
{
    VALIDATE_NOT_NULL(result);
    *result = mBssid;
    return NOERROR;
}

ECode CRttManagerRttParams::SetBssid(
    /* [in] */ const String& bssid)
{
    mBssid = bssid;
    return NOERROR;
}

ECode CRttManagerRttParams::GetFrequency(
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);
    *result = mFrequency;
    return NOERROR;
}

ECode CRttManagerRttParams::SetFrequency(
    /* [in] */ Int32 frequency)
{
    mFrequency = frequency;
    return NOERROR;
}

ECode CRttManagerRttParams::GetChannelWidth(
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);
    *result = mChannelWidth;
    return NOERROR;
}

ECode CRttManagerRttParams::SetChannelWidth(
    /* [in] */ Int32 channelWidth)
{
    mChannelWidth = channelWidth;
    return NOERROR;
}

ECode CRttManagerRttParams::GetNum_samples(
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);
    *result = mNumSamples;
    return NOERROR;
}

ECode CRttManagerRttParams::SetNum_samples(
    /* [in] */ Int32 num_samples)
{
    mNumSamples = num_samples;
    return NOERROR;
}

ECode CRttManagerRttParams::GetNum_retries(
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);
    *result = mNumRetries;
    return NOERROR;
}

ECode CRttManagerRttParams::SetNum_retries(
    /* [in] */ Int32 num_retries)
{
    mNumRetries = num_retries;
    return NOERROR;
}

} // namespace Wifi
} // namespace Droid
} // namespace Elastos

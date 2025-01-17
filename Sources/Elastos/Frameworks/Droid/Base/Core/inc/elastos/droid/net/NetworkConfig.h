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

#ifndef __ELASTOS_DROID_NET_NETWORKCONFIG_H__
#define __ELASTOS_DROID_NET_NETWORKCONFIG_H__

#include "Elastos.Droid.Net.h"
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Object.h>

namespace Elastos {
namespace Droid {
namespace Net {

/**
 * Describes the buildtime configuration of a network.
 * Holds settings read from resources.
 * @hide
 */
class NetworkConfig
    : public Object
    , public INetworkConfig
{
public:
    CAR_INTERFACE_DECL()

    CARAPI constructor();
    /**
     * input string from config.xml resource.  Uses the form:
     * [Connection name],[ConnectivityManager connection type],
     * [associated radio-type],[priority],[dependencyMet]
     */
    CARAPI constructor(
        /* [in] */ const String& init);

    /**
     * Indicates if this network is supposed to be default-routable
     */
    CARAPI IsDefault(
        /* [out] */ Boolean* result);

    /**
     * Human readable string
     */
    CARAPI GetName(
        /* [out] */ String* result);

    /**
     * Human readable string
     */
    CARAPI SetName(
        /* [in] */ const String& name);

    /**
     * Type from ConnectivityManager
     */
    CARAPI GetType(
        /* [out] */ Int32* result);

    /**
     * Type from ConnectivityManager
     */
    CARAPI SetType(
        /* [in] */ Int32 type);

    /**
     * the radio number from radio attributes config
     */
    CARAPI GetRadio(
        /* [out] */ Int32* result);

    /**
     * the radio number from radio attributes config
     */
    CARAPI SetRadio(
        /* [in] */ Int32 radio);

    /**
     * higher number == higher priority when turning off connections
     */
    CARAPI GetPriority(
        /* [out] */ Int32* result);

    /**
     * higher number == higher priority when turning off connections
     */
    CARAPI SetPriority(
        /* [in] */ Int32 priority);

    /**
     * indicates the boot time dependencyMet setting
     */
    CARAPI GetDependencyMet(
        /* [out] */ Boolean* result);

    /**
     * indicates the boot time dependencyMet setting
     */
    CARAPI SetDependencyMet(
        /* [in] */ Boolean dependencyMet);

    /**
     * indicates the default restoral timer in seconds
     * if the network is used as a special network feature
     * -1 indicates no restoration of default
     */
    CARAPI GetRestoreTime(
        /* [out] */ Int32* result);

    /**
     * indicates the default restoral timer in seconds
     * if the network is used as a special network feature
     * -1 indicates no restoration of default
     */
    CARAPI SetRestoreTime(
        /* [in] */ Int32 restoreTime);

private:
    /**
     * Human readable string
     */
    String mName;

    /**
     * Type from ConnectivityManager
     */
    Int32 mType;

    /**
     * the radio number from radio attributes config
     */
    Int32 mRadio;

    /**
     * higher number == higher priority when turning off connections
     */
    Int32 mPriority;

    /**
     * indicates the boot time dependencyMet setting
     */
    Boolean mDependencyMet;

    /**
     * indicates the default restoral timer in seconds
     * if the network is used as a special network feature
     * -1 indicates no restoration of default
     */
    Int32 mRestoreTime;
};

} // namespace Net
} // namespace Droid
} // namespace Elastos
#endif // __ELASTOS_DROID_NET_NETWORKCONFIG_H__

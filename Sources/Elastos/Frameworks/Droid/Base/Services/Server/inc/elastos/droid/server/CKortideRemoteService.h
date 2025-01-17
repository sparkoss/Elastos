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

#ifndef __ELASTOS_DROID_SERVER_KORTIDEREMOTESERVICE_H__
#define __ELASTOS_DROID_SERVER_KORTIDEREMOTESERVICE_H__

#include "_Elastos_Droid_Server_CKortideRemoteService.h"
#include "remote/RemoteCmdListener.h"
#include "remote/LanDispatcher.h"

using Elastos::Droid::Server::Remote::RemoteCmdListener;
using Elastos::Droid::Server::Remote::LanDispatcher;

namespace Elastos {
namespace Droid {
namespace Server {

CarClass(CKortideRemoteService)
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI_(void) InitServerSocket();

    CARAPI SetDeviceName(
        /* [in] */ const String& name,
        /* [out] */ Int32* result);

    CARAPI GetDeviceName(
        /* [out] */ String* deviceName);

private:
    static const String TAG;
    static const Boolean DBG;
    static const Int32 SLEEPTIME_MS;
    static const Int32 RETRYMAX;
    static const Int32 LANPORT;
    static const Int32 NETPORT;
    static Int32 sRetryCounter;

    AutoPtr<IContext> mContext;
    AutoPtr<IServerSocket> mLanServerSocket;
    AutoPtr<IServerSocket> mNetServerSocket;
    AutoPtr<RemoteCmdListener> mLanCmdListener;
    AutoPtr<RemoteCmdListener> mNetCmdListener;
    AutoPtr<LanDispatcher> mLanDispatcher;
    String mDevName;
};

} // Server
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_SERVER_KORTIDEREMOTESERVICE_H__

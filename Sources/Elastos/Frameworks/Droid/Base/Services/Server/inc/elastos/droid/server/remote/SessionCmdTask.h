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

#ifndef __ELASTOS_DROID_SERVER_REMOTE_LANDISPATCHER_H__
#define __ELASTOS_DROID_SERVER_REMOTE_LANDISPATCHER_H__

#include <ext/frameworkext.h>
#include <elastos/core/StringBuilder.h>

using Elastos::Core::ICharSequence;
using Elastos::Core::StringBuilder;
using Elastos::Utility::Concurrent::ICallable;
using Elastos::Droid::Content::IContext;

namespace Elastos {
namespace Droid {
namespace Server {
namespace Remote {

class SessionCmdTask
    : public ICallable
    , public ElRefBase
{
private:
    /************************
     * Internal targetID
     ************************/
    class TargetID
    {
    public:
        static const Int32 Unknown = -1;
        static const Int32 NoTarget = 0;
        static const Int32 RouterSetting = 100;
        static const Int32 Zigbee = 200;
        static const Int32 TVDisp = 300;
    };

public:
    /**********************************************
     *
     *  SessionCmdTask Constructor
     *
     **********************************************/
    SessionCmdTask(
        /* [in] */ IContext* context,
        /* [in] */ const String& clientCmd);

    CAR_INTERFACE_DECL()

    /**
     * call() implements Callable<> and
     * will be timeout if future don't get result in period time.
     */
    CARAPI Call(
        /* [out] */ IInterface** result);

    CARAPI RunForResult(
        /* [out] */ String* result);

    CARAPI_(Int32) GetResultNum();

private:
    CARAPI_(String) ReplaceLast(
        /* [in] */ const String& str,
        /* [in] */ const String& oldStr,
        /* [in] */ const String& newStr);

    CARAPI_(String) ParseRemoteCmd(
        /* [in] */ const String& clientCmd);

    CARAPI FactoryRunForResult(
        /* [in] */ const String& factoryName,
        /* [in] */ const String& cmd,
        /* [out] */ String* result);

private:
    static const String TAG;
    static const Boolean DBG;

    AutoPtr<IContext> mContext;
    String mFactoryName;
    Int32 mTargetID;
    Int32 mCmdSN;
    String mCmdFromRemote;
    AutoPtr<StringBuilder> mResult;
    Int32 mResultNum;
};

} // Remote
} // Server
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_SERVER_REMOTE_LANDISPATCHER_H__

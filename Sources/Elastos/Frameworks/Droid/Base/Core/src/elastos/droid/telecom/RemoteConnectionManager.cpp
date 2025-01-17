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

#include "Elastos.Droid.Internal.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/telecom/RemoteConnectionManager.h"
#include "elastos/droid/telecom/CRemoteConnectionService.h"
#include <elastos/utility/logging/Logger.h>

using Elastos::Utility::CHashMap;
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace Telecom {

//===============================================================
// RemoteConnectionManager::
//===============================================================
CAR_INTERFACE_IMPL(RemoteConnectionManager, Object, IRemoteConnectionManager)

RemoteConnectionManager::RemoteConnectionManager()
{
    CHashMap::New((IMap**)&mRemoteConnectionServices);
}

ECode RemoteConnectionManager::constructor(
    /* [in] */ IConnectionService* ourConnectionServiceImpl)
{
    mOurConnectionServiceImpl = ourConnectionServiceImpl;
    return NOERROR;
}

ECode RemoteConnectionManager::AddConnectionService(
    /* [in] */ IComponentName* componentName,
    /* [in] */ IIConnectionService* outgoingConnectionServiceRpc)
{
    Boolean bContain = FALSE;
    if (!(mRemoteConnectionServices->ContainsKey(componentName, &bContain), bContain)) {
        AutoPtr<IRemoteConnectionService> remoteConnectionService;
        CRemoteConnectionService::New(
                outgoingConnectionServiceRpc,
                mOurConnectionServiceImpl,
                (IRemoteConnectionService**)&remoteConnectionService);
        mRemoteConnectionServices->Put(componentName, remoteConnectionService);
    }
    return NOERROR;
}

ECode RemoteConnectionManager::CreateRemoteConnection(
    /* [in] */ IPhoneAccountHandle* connectionManagerPhoneAccount,
    /* [in] */ IConnectionRequest* request,
    /* [in] */ Boolean isIncoming,
    /* [out] */ IRemoteConnection** result)
{
    VALIDATE_NOT_NULL(result)
    AutoPtr<IPhoneAccountHandle> accountHandle;
    request->GetAccountHandle((IPhoneAccountHandle**)&accountHandle);
    if (accountHandle == NULL) {
        // throw new IllegalArgumentException("accountHandle must be specified.");
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    AutoPtr<IComponentName> componentName;
    accountHandle->GetComponentName((IComponentName**)&componentName);
    Boolean bContain = FALSE;
    if (!(mRemoteConnectionServices->ContainsKey(IInterface::Probe(componentName), &bContain), bContain)) {
        // throw new UnsupportedOperationException("accountHandle not supported: "
        //         + componentName);
        return E_UNSUPPORTED_OPERATION_EXCEPTION;
    }

    AutoPtr<IInterface> p;
    mRemoteConnectionServices->Get(componentName, (IInterface**)&p);
    AutoPtr<IRemoteConnectionService> remoteService = IRemoteConnectionService::Probe(p);
    if (remoteService != NULL) {
        return remoteService->CreateRemoteConnection(
                connectionManagerPhoneAccount, request, isIncoming, result);
    }
    *result = NULL;
    return NOERROR;
}

ECode RemoteConnectionManager::ConferenceRemoteConnections(
    /* [in] */ IRemoteConnection* a,
    /* [in] */ IRemoteConnection* b)
{
    AutoPtr<IIConnectionService> aSer, bSer;
    a->GetConnectionService((IIConnectionService**)&aSer);
    b->GetConnectionService((IIConnectionService**)&bSer);
    if (Object::Equals(IInterface::Probe(aSer), IInterface::Probe(bSer))) {
        String idA, idB;
        a->GetId(&idA);
        b->GetId(&idB);
        aSer->Conference(idA, idB);
    }
    else {
        String idA, idB;
        a->GetId(&idA);
        b->GetId(&idB);
        Logger::W("RemoteConnectionManager", "Request to conference incompatible remote connections (%p,%s) (%p,%s)",
                aSer.Get(), (const char*)idA,
                bSer.Get(), (const char*)idB);
    }
    return NOERROR;
}

} // namespace Telecom
} // namespace Droid
} // namespace Elastos

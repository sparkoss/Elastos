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

#include <Elastos.Droid.Os.h>
#include <Elastos.Droid.Content.h>
#include "elastos/droid/server/SystemService.h"
#include <elastos/droid/server/LocalServices.h>

using Elastos::Droid::Os::IServiceManager;
using Elastos::Droid::Os::CServiceManager;

namespace Elastos {
namespace Droid {
namespace Server {

CAR_INTERFACE_IMPL(SystemService, Object, ISystemService)

SystemService::SystemService()
{}

SystemService::~SystemService()
{}

ECode SystemService::constructor(
    /* [in] */ IContext* context)
{
    mContext = context;
    return NOERROR;
}

ECode SystemService::GetContext(
    /* [out] */ IContext** ctx)
{
    VALIDATE_NOT_NULL(ctx)
    *ctx = mContext;
    REFCOUNT_ADD(*ctx)
    return NOERROR;
}

ECode SystemService::IsSafeMode(
    /* [out] */  Boolean* safeMode)
{
    VALIDATE_NOT_NULL(safeMode)
    AutoPtr<ISystemServiceManager> ssMgr = GetManager();
    return ssMgr->IsSafeMode(safeMode);
}

ECode SystemService::OnBootPhase(
    /* [in] */ Int32 phase)
{
    return NOERROR;
}

ECode SystemService::OnStartUser(
    /* [in] */ Int32 userHandle)
{
    return NOERROR;
}

ECode SystemService::OnSwitchUser(
    /* [in] */ Int32 userHandle)
{
    return NOERROR;
}

ECode SystemService::OnStopUser(
    /* [in] */ Int32 userHandle)
{
    return NOERROR;
}

ECode SystemService::OnCleanupUser(
    /* [in] */ Int32 userHandle)
{
    return NOERROR;
}

void SystemService::PublishBinderService(
    /* [in] */ const String& name,
    /* [in] */ IBinder* service)
{
    PublishBinderService(name, service, FALSE);
}

void SystemService::PublishBinderService(
    /* [in] */ const String& name,
    /* [in] */ IBinder* service,
    /* [in] */ Boolean allowIsolated)
{
    AutoPtr<IServiceManager> smgr;
    CServiceManager::AcquireSingleton((IServiceManager**)&smgr);
    smgr->AddService(name, TO_IINTERFACE(service), allowIsolated);
}

AutoPtr<IBinder> SystemService::GetBinderService(
    /* [in] */ const String& name)
{
    AutoPtr<IServiceManager> smgr;
    CServiceManager::AcquireSingleton((IServiceManager**)&smgr);
    AutoPtr<IInterface> obj;
    smgr->GetService(name, (IInterface**)&obj);
    return IBinder::Probe(obj);
}

void SystemService::PublishLocalService(
    /* [in] */ const InterfaceID& type,
    /* [in] */ IInterface* service)
{
    LocalServices::AddService(type, service);
}

AutoPtr<IInterface> SystemService::GetLocalService(
    /* [in] */const InterfaceID& type)
{
    return LocalServices::GetService(type);
    return NULL;
}

AutoPtr<ISystemServiceManager> SystemService::GetManager()
{
    AutoPtr<IInterface> obj = LocalServices::GetService(EIID_ISystemServiceManager);
    return ISystemServiceManager::Probe(obj);
}


} // namespace Server
} // namepsace Droid
} // namespace Elastos

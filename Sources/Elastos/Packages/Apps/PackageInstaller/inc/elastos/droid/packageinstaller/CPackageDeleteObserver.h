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

#ifndef __ELASTOS_APPS_PACKAGEINSTALLER_CPACKAGEDELETEOBSERVER_H__
#define __ELASTOS_APPS_PACKAGEINSTALLER_CPACKAGEDELETEOBSERVER_H__

#include "_Elastos_Droid_PackageInstaller_CPackageDeleteObserver.h"
#include "elastos/droid/app/Activity.h"
#include "elastos/droid/packageinstaller/CUninstallAppProgress.h"

namespace Elastos {
namespace Droid {
namespace PackageInstaller {

CarClass(CPackageDeleteObserver)
    , public CUninstallAppProgress::PackageDeleteObserver
{
public:
    CAR_OBJECT_DECL()
};

} // namespace PackageInstaller
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_APPS_PACKAGEINSTALLER_CPACKAGEDELETEOBSERVER_H__


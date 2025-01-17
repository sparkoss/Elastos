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

#include "elastos/droid/launcher2/CUninstallShortcutReceiverHelper.h"
#include "elastos/droid/launcher2/UninstallShortcutReceiver.h"

namespace Elastos {
namespace Droid {
namespace Launcher2 {

CAR_SINGLETON_IMPL(CUninstallShortcutReceiverHelper)

CAR_INTERFACE_IMPL(CUninstallShortcutReceiverHelper, Singleton, IUninstallShortcutReceiverHelper)

ECode CUninstallShortcutReceiverHelper::EnableUninstallQueue()
{
    return UninstallShortcutReceiver::EnableUninstallQueue();
}

ECode CUninstallShortcutReceiverHelper::DisableAndFlushUninstallQueue(
    /* [in] */ IContext* context)
{
    return UninstallShortcutReceiver::DisableAndFlushUninstallQueue(context);
}

} // namespace Launcher2
} // namespace Droid
} // namespace Elastos
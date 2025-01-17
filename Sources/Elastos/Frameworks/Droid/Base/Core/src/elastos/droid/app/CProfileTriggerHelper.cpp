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

#include "elastos/droid/app/CProfileTriggerHelper.h"

namespace Elastos {
namespace Droid {
namespace App {

CAR_INTERFACE_IMPL(CProfileTriggerHelper, Singleton, IProfileTriggerHelper)

CAR_SINGLETON_IMPL(CProfileTriggerHelper)

ECode CProfileTriggerHelper::FromXml(
    /* [in] */ IXmlPullParser* xpp,
    /* [in] */ IContext* context,
    /* [out] */ IProfileTrigger** result)
{
    VALIDATE_NOT_NULL(result);
    AutoPtr<IProfileTrigger> p = Profile::ProfileTrigger::FromXml(xpp, context);
    *result = p;
    REFCOUNT_ADD(*result);
    return NOERROR;
}

} // namespace App
} // namespace Droid
} // namespace Elastos

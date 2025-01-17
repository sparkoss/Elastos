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

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/wifi/CEnterpriseField.h"

namespace Elastos {
namespace Droid {
namespace Wifi {

ECode CEnterpriseField::constructor(
    /* [in] */ const String& varName)
{
    mVarName = varName;
    return NOERROR;
}

ECode CEnterpriseField::SetValue(
    /* [in] */ const String& value)
{
    mValue = value;
    return NOERROR;
}

ECode CEnterpriseField::GetVarName(
    /* [out] */ String* varName)
{
    VALIDATE_NOT_NULL(varName);
    *varName = mVarName;
    return NOERROR;
}

ECode CEnterpriseField::GetValue(
    /* [out] */ String* value)
{
    VALIDATE_NOT_NULL(value);
    *value = mValue;
    return NOERROR;
}

} // namespace Wifi
} // namespace Droid
} // namespace Elastos

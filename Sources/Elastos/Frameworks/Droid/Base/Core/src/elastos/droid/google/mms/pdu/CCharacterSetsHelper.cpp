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

#include "elastos/droid/google/mms/pdu/CCharacterSetsHelper.h"
#include "elastos/droid/google/mms/pdu/CharacterSets.h"

namespace Elastos {
namespace Droid {
namespace Google {
namespace Mms {
namespace Pdu {

CAR_INTERFACE_IMPL(CCharacterSetsHelper, Singleton, ICharacterSetsHelper)
CAR_SINGLETON_IMPL(CCharacterSetsHelper)

ECode CCharacterSetsHelper::GetMimeName(
    /* [in] */ Int32 mibEnumValue,
    /* [out] */ String* result)
{
    VALIDATE_NOT_NULL(result);
    *result = CharacterSets::GetMimeName(mibEnumValue);
    return NOERROR;
}

ECode CCharacterSetsHelper::GetMibEnumValue(
    /* [in] */ const String& mimeName,
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);
    *result = CharacterSets::GetMibEnumValue(mimeName);
    return NOERROR;
}

} // namespace Pdu
} // namespace Mms
} // namespace Google
} // namespace Droid
} // namespace Elastos

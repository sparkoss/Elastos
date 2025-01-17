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

#include "CMonkeyCommandReturn.h"

namespace Elastos {
namespace Droid {
namespace Commands {
namespace Monkey {

ECode CMonkeyCommandReturn::HasMessage(
    /* [out] */ Boolean *result)
{
    VALIDATE_NOT_NULL(result);
    return MonkeyCommandReturn::HasMessage(result);
}

ECode CMonkeyCommandReturn::GetMessage(
    /* [out] */ String *message)
{
    VALIDATE_NOT_NULL(message);
    return GetMessage(message);
}

ECode CMonkeyCommandReturn::WasSuccessful(
    /* [out] */ Boolean *result)
{
    VALIDATE_NOT_NULL(result);
    return MonkeyCommandReturn::WasSuccessful(result);
}

ECode CMonkeyCommandReturn::constructor(
    /* [in] */ Boolean success)
{
    return MonkeyCommandReturn::Init(success);
}

ECode CMonkeyCommandReturn::constructor(
    /* [in] */ Boolean success,
    /* [in] */ const String& message)
{
    return MonkeyCommandReturn::Init(success, message);
}

} // namespace Monkey
} // namespace Commands
} // namespace Droid
} // namespace Elastos
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

#include "CMonkeyEventQueue.h"

using Elastos::Core::IRandom;

namespace Elastos {
namespace Droid {
namespace Commands {
namespace Monkey {

CAR_OBJECT_IMPL(CMonkeyEventQueue)

ECode CMonkeyEventQueue::IsEmpty(
    /* [out] */ Boolean *isEmpty)
{
    VALIDATE_NOT_NULL(isEmpty);
    return MonkeyEventQueue::IsEmpty(isEmpty);
}

ECode CMonkeyEventQueue::GetFirst(
    /* [out] */ IMonkeyEvent **monkeyEvent)
{
    VALIDATE_NOT_NULL(monkeyEvent);
    return MonkeyEventQueue::GetFirst(monkeyEvent);
}

ECode CMonkeyEventQueue::RemoveFirst()
{
    return MonkeyEventQueue::RemoveFirst();
}

ECode CMonkeyEventQueue::AddLast(
    /* [in] */ IMonkeyEvent *event)
{
    return MonkeyEventQueue::AddLast(event);
}

ECode CMonkeyEventQueue::constructor(
    /* [in] */ IRandom *random,
    /* [in] */ Int64 throttle,
    /* [in] */ Boolean randomizeThrottle)
{
    return MonkeyEventQueue::Init(random, throttle, randomizeThrottle);
}

} // namespace Monkey
} // namespace Commands
} // namespace Droid
} // namespace Elastos

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

#ifndef __ELASTOS_DROID_INTERNAL_UTILITY_CBITWISEOUTPUTSTREAM_H__
#define __ELASTOS_DROID_INTERNAL_UTILITY_CBITWISEOUTPUTSTREAM_H__

#include "_Elastos_Droid_Internal_Utility_CBitwiseOutputStream.h"
#include "elastos/droid/internal/utility/BitwiseOutputStream.h"

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Utility {

CarClass(CBitwiseOutputStream)
    , public BitwiseOutputStream
{
public:
    CAR_OBJECT_DECL()
};

} // namespace Utility
} // namespace Internal
} // namespace Droid
} // namespace Elastos


#endif //__ELASTOS_DROID_INTERNAL_UTILITY_CBITWISEOUTPUTSTREAM_H__

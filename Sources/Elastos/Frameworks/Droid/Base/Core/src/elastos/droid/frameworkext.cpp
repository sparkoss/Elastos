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
#include <elastos/utility/etl/Map.h>
#include <pthread.h>

namespace Elastos {
namespace Utility {
namespace Etl {

const RBTreeColorType S_RBTreeRed = FALSE;
const RBTreeColorType S_RBTreeBlack = TRUE;

} // namespace Etl
} // namespace Utility
} // namespace Elastos


namespace Elastos {
namespace Utility {

// {C6F9F8F0-9887-492B-87DA-4A8D61762F91}
extern "C" const ClassID ECLSID_CDummyObject =
    {{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
    (char *)"elastos.dll", 0x1c692272};


} // namespace Utility
} // namespace Elastos

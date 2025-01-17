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

#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Os.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/graphics/CPorterDuffXfermode.h"
#include <skia/effects/SkPorterDuff.h>

namespace Elastos {
namespace Droid {
namespace Graphics {

CAR_OBJECT_IMPL(CPorterDuffXfermode);
CAR_INTERFACE_IMPL(CPorterDuffXfermode, Xfermode, IPorterDuffXfermode);
ECode CPorterDuffXfermode::constructor(
    /* [in] */ PorterDuffMode mode)
{
    this->mMode = mode;
    mNativeInstance = NativeCreateXfermode(mode);
    return NOERROR;
}

ECode CPorterDuffXfermode::GetMode(
    /* [out] */ PorterDuffMode* mode)
{
    VALIDATE_NOT_NULL(mode);
    *mode = mMode;
    return NOERROR;
}

Int64 CPorterDuffXfermode::NativeCreateXfermode(
    /* [in] */ PorterDuffMode modeHandle)
{
    SkPorterDuff::Mode mode = static_cast<SkPorterDuff::Mode>(modeHandle);
    return reinterpret_cast<Int64>(SkPorterDuff::CreateXfermode(mode));
}

} // namespace Graphics
} // namepsace Droid
} // namespace Elastos

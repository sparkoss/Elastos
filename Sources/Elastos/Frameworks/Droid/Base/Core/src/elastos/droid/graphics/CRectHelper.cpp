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

#include "elastos/droid/graphics/CRectHelper.h"
#include "elastos/droid/graphics/CRect.h"

namespace Elastos {
namespace Droid {
namespace Graphics {

CAR_SINGLETON_IMPL(CRectHelper);
CAR_INTERFACE_IMPL(CRectHelper, Singleton, IRectHelper);
ECode CRectHelper::UnflattenFromString(
    /* [in] */ const String& str,
    /* [out] */ IRect** rect)
{
    VALIDATE_NOT_NULL(rect);
    AutoPtr<IRect> r = CRect::UnflattenFromString(str);
    *rect = r;
    REFCOUNT_ADD(*rect);
    return NOERROR;
}

ECode CRectHelper::Intersects(
    /* [in] */ IRect* a,
    /* [in] */ IRect* b,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result);
    *result = CRect::Intersects(a, b);
    return NOERROR;
}

} // namespace Graphics
} // namepsace Droid
} // namespace Elastos

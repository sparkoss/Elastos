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

#include "elastos/droid/hardware/camera2/utils/HashCodeHelpers.h"
#include <elastos/core/Math.h>
#include <elastos/core/StringBuffer.h>

using Elastos::Core::StringBuffer;

namespace Elastos {
namespace Droid {
namespace Hardware {
namespace Camera2 {
namespace Utils {

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ ArrayOf<Int32>* array,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    if (array == NULL) {
        *value = 0;
        return NOERROR;
    }

    /*
     *  Note that we use 31 here instead of 33 since it's preferred in Effective Java
     *  and used elsewhere in the runtime (e.g. Arrays#hashCode)
     *
     *  That being said 33 and 31 are nearly identical in terms of their usefulness
     *  according to http://svn.apache.org/repos/asf/apr/apr/trunk/tables/apr_hash.c
     */
    Int32 h = 1;
    for (Int32 i = 0; i < array->GetLength(); i++) {
        Int32 x = (*array)[i];
        // Strength reduction; in case the compiler has illusions about divisions being faster
        h = ((h << 5) - h) ^ x; // (h * 31) XOR x
    }

    *value = h;
    return NOERROR;
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ ArrayOf<Float>* array,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    if (array == NULL) {
        *value = 0;
        return NOERROR;
    }

    Int32 h = 1;
    for (Int32 i = 0; i < array->GetLength(); i++) {
        Float f = (*array)[i];
        Int32 x = Elastos::Core::Math::FloatToInt32Bits(f);
        h = ((h << 5) - h) ^ x; // (h * 31) XOR x
    }

    *value = h;
    return NOERROR;
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ IInterface* a,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);
    *value = Object::GetHashCode(a);
    return NOERROR;
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ IInterface* a,
    /* [in] */ IInterface* b,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    Int32 h;
    GetHashCode(a, &h);

    Int32 x = Object::GetHashCode(b);
    h = ((h << 5) - h) ^ x; // (h * 31) XOR x

    *value = h;
    return NOERROR;
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ IInterface* a,
    /* [in] */ IInterface* b,
    /* [in] */ IInterface* c,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    Int32 h;
    GetHashCode(a, b, &h);

    Int32 x = Object::GetHashCode(c);
    h = ((h << 5) - h) ^ x; // (h * 31) XOR x

    *value = h;
    return NOERROR;
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ IInterface* a,
    /* [in] */ IInterface* b,
    /* [in] */ IInterface* c,
    /* [in] */ IInterface* d,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    Int32 h;
    GetHashCode(a, b, c, &h);

    Int32 x = Object::GetHashCode(d);
    h = ((h << 5) - h) ^ x; // (h * 31) XOR x

    *value = h;
    return NOERROR;
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ Int32 x,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    AutoPtr<ArrayOf<Int32> > array = ArrayOf<Int32>::Alloc(1);
    (*array)[0] = x;
    return GetHashCode(array, value);
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ Int32 x,
    /* [in] */ Int32 y,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    AutoPtr<ArrayOf<Int32> > array = ArrayOf<Int32>::Alloc(2);
    (*array)[0] = x;
    (*array)[1] = y;
    return GetHashCode(array, value);
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ Int32 x,
    /* [in] */ Int32 y,
    /* [in] */ Int32 z,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    AutoPtr<ArrayOf<Int32> > array = ArrayOf<Int32>::Alloc(3);
    (*array)[0] = x;
    (*array)[1] = y;
    (*array)[2] = z;
    return GetHashCode(array, value);
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ Int32 x,
    /* [in] */ Int32 y,
    /* [in] */ Int32 z,
    /* [in] */ Int32 w,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    AutoPtr<ArrayOf<Int32> > array = ArrayOf<Int32>::Alloc(4);
    (*array)[0] = x;
    (*array)[1] = y;
    (*array)[2] = z;
    (*array)[3] = w;
    return GetHashCode(array, value);
}

ECode HashCodeHelpers::GetHashCode(
    /* [in] */ Int32 x,
    /* [in] */ Int32 y,
    /* [in] */ Int32 z,
    /* [in] */ Int32 w,
    /* [in] */ Int32 t,
    /* [out] */ Int32* value)
{
    VALIDATE_NOT_NULL(value);

    AutoPtr<ArrayOf<Int32> > array = ArrayOf<Int32>::Alloc(5);
    (*array)[0] = x;
    (*array)[1] = y;
    (*array)[2] = z;
    (*array)[3] = w;
    (*array)[4] = t;
    return GetHashCode(array, value);
}

} // namespace Utils
} // namespace Camera2
} // namespace Hardware
} // namespace Droid
} // namespace Elastos

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

#ifndef _ORG_JAVIA_ARITY_DOUBLESTACK_H__
#define _ORG_JAVIA_ARITY_DOUBLESTACK_H__

#include "_Org.Javia.Arity.h"
#include <elastos/droid/ext/frameworkext.h>
#include <elastos/core/Object.h>

namespace Org {
namespace Javia {
namespace Arity {

class DoubleStack : public Object
{
public:
    DoubleStack();

    CARAPI_(void) Clear();

    CARAPI_(void) Push(
        /* [in] */ Double a,
        /* [in] */ Double b);

    CARAPI Pop(
        /* [in] */ Int32 cnt);

    CARAPI_(void) Pop();

    CARAPI_(AutoPtr<ArrayOf<Double> >) GetRe();

    CARAPI_(AutoPtr<ArrayOf<Double> >) GetIm();

private:
    AutoPtr<ArrayOf<Double> > mRe;
    AutoPtr<ArrayOf<Double> > mIm;
    Int32 mSize;
};

} // namespace Arity
} // namespace Javia
} // namespace Org

#endif // _ORG_JAVIA_ARITY_DOUBLESTACK_H__
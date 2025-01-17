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

#ifndef _ORG_JAVIA_ARITY_OPTCODEGEN_H__
#define _ORG_JAVIA_ARITY_OPTCODEGEN_H__

#include "org/javia/arity/SimpleCodeGen.h"
#include "org/javia/arity/CEvalContext.h"
#include "org/javia/arity/CCompiledFunction.h"

namespace Org {
namespace Javia {
namespace Arity {

/* Optimizing Code Generator
   Reads tokens in RPN (Reverse Polish Notation) order,
   and generates VM opcodes,
   doing constant-folding optimization.
 */
class OptCodeGen : public SimpleCodeGen
{
public:
    OptCodeGen();

    CARAPI_(void) Start();

    CARAPI Push(
        /* [in] */ Token* token);

    CARAPI_(AutoPtr<CCompiledFunction>) GetFun(
        /* [in] */ Int32 arity);

public:
    AutoPtr<CEvalContext> mContext;
    Int32 mSp;
    AutoPtr<ArrayOf<IComplex*> > mStack;

    AutoPtr<ArrayOf<Double> > mTraceConstsRe;
    AutoPtr<ArrayOf<Double> > mTraceConstsIm;
    AutoPtr<ArrayOf<IFunction*> > mTraceFuncs;
    AutoPtr<ArrayOf<Byte> > mTraceCode;
    AutoPtr<CCompiledFunction> mTracer;

    Int32 mIntrinsicArity;

private:
    Boolean mIsPercent;
};

} // namespace Arity
} // namespace Javia
} // namespace Org

#endif // _ORG_JAVIA_ARITY_OPTCODEGEN_H__
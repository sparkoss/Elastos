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

#ifndef __ELASTOS_DROID_TEXT_METHOD_CDIALERKEYLISTENERHELPER_H__
#define __ELASTOS_DROID_TEXT_METHOD_CDIALERKEYLISTENERHELPER_H__

#include "_Elastos_Droid_Text_Method_CDialerKeyListenerHelper.h"
#include <elastos/core/Singleton.h>

using Elastos::Droid::View::IView;
using Elastos::Droid::View::IKeyEvent;
using Elastos::Core::ICharSequence;

namespace Elastos {
namespace Droid {
namespace Text {
namespace Method {

CarClass(CDialerKeyListenerHelper)
    , public Singleton
    , public IDialerKeyListenerHelper
{
public:
    CAR_SINGLETON_DECL()

    CAR_INTERFACE_DECL()

    CARAPI GetCHARACTERS(
        /* [out, callee] */ ArrayOf<Char32>** ret);

    CARAPI GetInstance(
        /* [out] */ IDialerKeyListener** ret);
};

} // namespace Method
} // namespace Text
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_TEXT_METHOD_CDIALERKEYLISTENERHELPER_H__

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

#ifndef __ELASTOS_DROID_VIEW_CSURFACEVIEWHELPER_H__
#define __ELASTOS_DROID_VIEW_CSURFACEVIEWHELPER_H__

#include "_Elastos_Droid_View_CSurfaceViewHelper.h"
#include <elastos/core/Singleton.h>

using Elastos::Core::Singleton;

namespace Elastos {
namespace Droid {
namespace View {

CarClass(CSurfaceViewHelper)
    , public Singleton
    , public ISurfaceViewHelper
{
public:

    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL()

    CARAPI AdjustSurfaceViewMotion(
        /* [in]*/ IMotionEvent* evt);

};

}// namespace View
}// namespace Droid
}// namespace Elastos

#endif

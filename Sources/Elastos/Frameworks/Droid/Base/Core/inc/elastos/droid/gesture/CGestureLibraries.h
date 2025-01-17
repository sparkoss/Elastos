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

#ifndef __ELASTOS_DROID_GESTURE_CGESTURELIBRARIES_H__
#define __ELASTOS_DROID_GESTURE_CGESTURELIBRARIES_H__

#include "_Elastos_Droid_Gesture_CGestureLibraries.h"
#include "elastos/droid/ext/frameworkdef.h"
#include <elastos/core/Singleton.h>

using Elastos::IO::IFile;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Gesture::IGestureLibraries;

namespace Elastos {
namespace Droid {
namespace Gesture {

CarClass(CGestureLibraries)
    , public Singleton
    , public IGestureLibraries
{
public:
    CAR_SINGLETON_DECL();

    CAR_INTERFACE_DECL()

    CARAPI FromFile(
        /* [in] */  const String& path,
        /* [out] */ IGestureLibrary** gestureLib);

    CARAPI FromFile(
        /* [in] */ IFile* path,
        /* [out] */ IGestureLibrary** gestureLib);

    CARAPI FromPrivateFile(
        /* [in] */ IContext* ctx,
        /* [in] */ const String& name,
        /* [out] */ IGestureLibrary** gestureLib);

    CARAPI FromRawResource(
        /* [in] */ IContext* ctx,
        /* [in] */ Int32 resourceId,
        /* [out] */ IGestureLibrary** gestureLib);
};

} // namespace Gesture
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_GESTURE_CGESTURELIBRARIES_H__

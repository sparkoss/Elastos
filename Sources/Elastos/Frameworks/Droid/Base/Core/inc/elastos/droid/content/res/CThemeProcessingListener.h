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

#ifndef __ELASTOS_DROID_CONTENT_RES_CTHEMEPROCESSINGLISTENER_H__
#define __ELASTOS_DROID_CONTENT_RES_CTHEMEPROCESSINGLISTENER_H__

#include "_Elastos_Droid_Content_Res_CThemeProcessingListener.h"
#include <elastos/core/Runnable.h>

using Elastos::Core::Runnable;

namespace Elastos {
namespace Droid {
namespace Content {
namespace Res {

class CThemeManager;

CarClass(CThemeProcessingListener)
    , public Object
    , public IIThemeProcessingListener
{
private:
    class OnFinishedProcessingRunnable : public Runnable
    {
    public:
        OnFinishedProcessingRunnable(
            /* [in] */ const String& pkgName,
            /* [in] */ CThemeManager* host)
            : mPkgName(pkgName)
            , mHost(host)
        {}

        CARAPI Run();

    private:
        String mPkgName;
        CThemeManager* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CARAPI constructor(
        /* [in] */ IThemeManager* host);

    CARAPI OnFinishedProcessing(
        /* [in] */ const String& pkgName);

private:
    CThemeManager* mHost;
};

} // namespace Res
} // namespace Content
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_CONTENT_RES_CTHEMEPROCESSINGLISTENER_H__

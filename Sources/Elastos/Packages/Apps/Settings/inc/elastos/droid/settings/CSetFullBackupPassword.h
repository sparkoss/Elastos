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

#ifndef __ELASTOS_DROID_SETTINGS_CSETFULLBACKUPPASSWORD_H__
#define __ELASTOS_DROID_SETTINGS_CSETFULLBACKUPPASSWORD_H__

#include "Elastos.Droid.Widget.h"
#include "_Elastos_Droid_Settings_CSetFullBackupPassword.h"
#include "elastos/droid/app/Activity.h"

using Elastos::Droid::App::Activity;
using Elastos::Droid::App::Backup::IIBackupManager;
using Elastos::Droid::Os::IBundle;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::Widget::IButton;
using Elastos::Droid::Widget::ITextView;

namespace Elastos {
namespace Droid {
namespace Settings {

CarClass(CSetFullBackupPassword)
    , public Activity
{
public:
    class MyOnClickListener
        : public Object
        , public IViewOnClickListener
    {
    public:
        TO_STRING_IMPL("CSetFullBackupPassword::MyOnClickListener")

        CAR_INTERFACE_DECL()

        MyOnClickListener(
            /* [in] */ CSetFullBackupPassword* host);

        //@Override
        CARAPI OnClick(
            /* [in] */ IView* v);

    private:
        CSetFullBackupPassword* mHost;
    };

public:
    CAR_OBJECT_DECL()

    CSetFullBackupPassword();

    ~CSetFullBackupPassword();

    CARAPI constructor();

    //@Override
    CARAPI OnCreate(
        /* [in] */ IBundle* icicle);

private:
    CARAPI_(Boolean) SetBackupPassword(
        /* [in] */ const String& currentPw,
        /* [in] */ const String& newPw);

public:
    static const String TAG;

    AutoPtr<IIBackupManager> mBackupManager;
    AutoPtr<ITextView> mCurrentPw;
    AutoPtr<ITextView> mNewPw;
    AutoPtr<ITextView> mConfirmNewPw;
    AutoPtr<IButton> mCancel;
    AutoPtr<IButton> mSet;

    AutoPtr<IViewOnClickListener> mButtonListener;
};

} // namespace Settings
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_SETTINGS_CSETFULLBACKUPPASSWORD_H__
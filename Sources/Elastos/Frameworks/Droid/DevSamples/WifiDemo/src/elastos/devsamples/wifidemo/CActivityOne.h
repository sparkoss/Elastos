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

#ifndef __Elastos_DevSamples_TextViewDemo_CActivityOne_H__
#define __Elastos_DevSamples_TextViewDemo_CActivityOne_H__

#include <Elastos.Droid.Graphics.h>
#include <Elastos.Droid.Widget.h>
#include <Elastos.Droid.Wifi.h>
#include <elastos/droid/app/Activity.h>
#include "_Elastos_DevSamples_WifiDemo_CActivityOne.h"

using Elastos::Droid::App::Activity;
using Elastos::Droid::App::IDialog;
using Elastos::Droid::Content::IDialogInterface;
using Elastos::Droid::Content::IDialogInterfaceOnClickListener;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::View::IViewOnKeyListener;
using Elastos::Droid::View::IViewOnTouchListener;
using Elastos::Droid::View::Animation::IAnimation;
using Elastos::Droid::Widget::IAdapterViewOnItemClickListener;
using Elastos::Droid::Widget::IAdapterViewOnItemLongClickListener;
using Elastos::Droid::Widget::IRadioGroupOnCheckedChangeListener;
using Elastos::Droid::Widget::IAdapterView;
using Elastos::Droid::Widget::IPopupWindow;
using Elastos::Droid::Widget::ICheckBox;
using Elastos::Droid::Widget::IListView;
using Elastos::Droid::Widget::IEditText;
using Elastos::Droid::Widget::ITextView;
using Elastos::Droid::Widget::IRadioGroup;
using Elastos::Droid::Wifi::IWifiManager;

namespace Elastos {
namespace DevSamples {
namespace WifiDemo {

CarClass(CActivityOne)
    , public Activity
{
public:
    class MyListener
        : public Object
        , public IViewOnTouchListener
        , public IViewOnKeyListener
        , public IViewOnClickListener
        , public IAdapterViewOnItemClickListener
        , public IAdapterViewOnItemLongClickListener
        , public IDialogInterfaceOnClickListener
        , public IRadioGroupOnCheckedChangeListener
    {
    public:
        CAR_INTERFACE_DECL()

        MyListener(
            /* [in] */ CActivityOne* host);

        ~MyListener();

        CARAPI OnTouch(
            /* [in] */ IView* v,
            /* [in] */ IMotionEvent* event,
            /* [out] */ Boolean* result);

        CARAPI OnKey(
            /* [in] */ IView * v,
            /* [in] */ Int32 keyCode,
            /* [in] */ IKeyEvent* event,
            /* [out] */ Boolean* result);

        CARAPI OnItemClick(
            /* [in] */ IAdapterView* parent,
            /* [in] */ IView* view,
            /* [in] */ Int32 position,
            /* [in] */ Int64 id);

        CARAPI OnClick(
            /* [in] */ IView* v);

        CARAPI OnClick(
            /* [in] */ IDialogInterface* dialog,
            /* [in] */ Int32 which);

        CARAPI OnItemLongClick(
            /* [in] */ IAdapterView* parent,
            /* [in] */ IView* view,
            /* [in] */ Int32 position,
            /* [in] */ Int64 id,
            /* [out] */ Boolean* result);

        CARAPI OnCheckedChanged(
            /* [in] */ IRadioGroup* group,
            /* [in] */ Int32 checkedId);

    private:
        CActivityOne* mHost;
    };

public:
    CAR_OBJECT_DECL()

    CARAPI constructor();

    virtual CARAPI OnCreateContextMenu(
        /* [in] */ IContextMenu* menu,
        /* [in] */ IView* v,
        /* [in] */ IContextMenuInfo* menuInfo);

protected:
    CARAPI OnCreate(
        /* [in] */ IBundle* savedInstanceState);

    CARAPI OnStart();

    CARAPI OnResume();

    CARAPI OnPause();

    CARAPI OnStop();

    CARAPI OnDestroy();

    CARAPI_(AutoPtr<IDialog>) OnCreateDialog(
    /* [in] */ Int32 id);

    CARAPI ShowAlert(
        /* [in] */ const String& info);

    CARAPI OnCreatePopupWindow();

    CARAPI OnTestPowerManager();

    CARAPI OnTestConnectivityManager();

    CARAPI OnTestWifiEnable();

    CARAPI OnTestWifiDisable();

    CARAPI OnTestWifiConnect();

    CARAPI OnTestWifiStartScan();

    CARAPI OnTestWifiLog(
        /* [in] */ Boolean enable);

    CARAPI OnTestClearWifiConfigurations();

    CARAPI OnTestPing(
        /* [in] */ const String& targetUrl);

    CARAPI OnTestReboot(
        /* [in] */ const String& info);

private:
    CARAPI OnActivityResult(
        /* [in] */ Int32 requestCode,
        /* [in] */ Int32 resultCode,
        /* [in] */ IIntent *data);

    CARAPI CreateNavigationBar();

    CARAPI ConnectWifi(
        /* [in] */ const String& ssid,
        /* [in] */ const String& passwd);
private:
    AutoPtr<IDrawable> mDrawable1;
    AutoPtr<IDrawable> mDrawable2;

    AutoPtr<IView> mButton1;
    AutoPtr<IView> mButton2;
    AutoPtr<IView> mButton3;

    AutoPtr<IAnimation> mAlphaAnimation;
    AutoPtr<IAnimation> mScaleAnimation;
    AutoPtr<IAnimation> mRotateAnimation;
    AutoPtr<IAnimation> mTranslateAnimation;

    AutoPtr<IView> mAnimationButton;
    AutoPtr<IView> mDialogButton;
    AutoPtr<IView> mPopupWindowButton;
    AutoPtr<IView> mPowerManagerButton;
    AutoPtr<IView> mConnectivityManagerButton;
    AutoPtr<IView> mWifiEnableButton;
    AutoPtr<IView> mWifiDisableButton;
    AutoPtr<IView> mWifiStartScanButton;
    AutoPtr<IView> mWifiConnectButton;
    AutoPtr<IView> mWifiDisableLogButton;
    AutoPtr<IView> mWifiEnableLogButton;
    AutoPtr<IView> mWifiClearConfigsButton;
    AutoPtr<IView> mRebootButton;
    AutoPtr<IEditText> mSSIDEditText;
    AutoPtr<IEditText> mPWEditText;
    AutoPtr<IView> mContent;

    AutoPtr<IView> mBack;
    AutoPtr<IView> mHome;
    AutoPtr<IView> mMenu;

    AutoPtr<IPopupWindow> mPopupWindow;

    AutoPtr<ICheckBox> mAndroidCheckBox;
    AutoPtr<ICheckBox> mIosCheckBox;

    AutoPtr<IEditText> mEditText;
    AutoPtr<ITextView> mTextView;
    AutoPtr<IListView> mListView;
    AutoPtr<IRadioGroup> mRadioSex;
    AutoPtr<IWifiManager> mWifiManager;
    Boolean mWifiEnable;
};

} // namespace WifiDemo
} // namespace DevSamples
} // namespace Elastos

#endif // __Elastos_DevSamples_WifiDemo_CActivityOne_H__

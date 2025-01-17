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

#ifndef __ELASTOS_DROID_SETTINGS_APPLICATIONS_CRUNNINGSERVICEDETAILS_H__
#define __ELASTOS_DROID_SETTINGS_APPLICATIONS_CRUNNINGSERVICEDETAILS_H__

#include "_Elastos_Droid_Settings_Applications_CRunningServiceDetails.h"
#include "elastos/droid/settings/applications/CRunningProcessesView.h"
#include "elastos/droid/app/DialogFragment.h"
#include <elastos/core/StringBuilder.h>

using Elastos::Droid::App::IActivity;
using Elastos::Droid::App::IActivityManager;
using Elastos::Droid::App::IDialog;
using Elastos::Droid::App::DialogFragment;
using Elastos::Droid::App::Fragment;
using Elastos::Droid::App::IDialogFragment;
using Elastos::Droid::App::IPendingIntent;
using Elastos::Droid::Content::IComponentName;
using Elastos::Droid::Content::IDialogInterface;
using Elastos::Droid::Content::IDialogInterfaceOnClickListener;
using Elastos::Droid::Os::IBundle;
using Elastos::Droid::View::ILayoutInflater;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IViewGroup;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::Widget::IButton;
using Elastos::Droid::Widget::ITextView;
using Elastos::Utility::IArrayList;
using Elastos::Core::StringBuilder;

namespace Elastos {
namespace Droid {
namespace Settings {
namespace Applications {

CarClass(CRunningServiceDetails)
    , public Fragment
    , public IRunningStateOnRefreshUiListener
{
public:
    class MyAlertDialogFragment
        : public DialogFragment
    {
    public:
        TO_STRING_IMPL("CRunningServiceDetails::MyAlertDialogFragment")

        CARAPI constructor();

        static CARAPI_(AutoPtr<IDialogFragment>) NewConfirmStop(
            /* [in] */ Int32 id,
            /* [in] */ IComponentName* comp);

        CARAPI_(AutoPtr<CRunningServiceDetails>) GetOwner();

        //@Override
        CARAPI OnCreateDialog(
            /* [in] */ IBundle* savedInstanceState,
            /* [out] */ IDialog** result);
    };

protected:
    class ActiveDetail
        : public Object
        , public IViewOnClickListener
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("CRunningServiceDetails::ActiveDetail")

        ActiveDetail(
            /* [in] */ CRunningServiceDetails* host);

        CARAPI_(void) StopActiveService(
            /* [in] */ Boolean confirmed);

        CARAPI OnClick(
            /* [in] */ IView* v);

    public:
        AutoPtr<IView> mRootView;
        AutoPtr<IButton> mStopButton;
        AutoPtr<IButton> mReportButton;
        AutoPtr<RunningState::ServiceItem> mServiceItem;
        AutoPtr<CRunningProcessesView::ActiveItem> mActiveItem;
        AutoPtr<CRunningProcessesView::ViewHolder> mViewHolder;
        AutoPtr<IPendingIntent> mManageIntent;
        AutoPtr<IComponentName> mInstaller;

    private:
        CRunningServiceDetails* mHost;
    };

private:
    class MyOnClickListener
        : public Object
        , public IDialogInterfaceOnClickListener
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("CRunningServiceDetails::MyOnClickListener")

        MyOnClickListener(
            /* [in] */ MyAlertDialogFragment* host,
            /* [in] */ IComponentName* comp);

        CARAPI OnClick(
            /* [in] */ IDialogInterface* dialog,
            /* [in] */ Int32 which);

    private:
        MyAlertDialogFragment* mHost;
        AutoPtr<IComponentName> mComp;
    };

    class MyRunnable
        : public Runnable
    {
    public:
        TO_STRING_IMPL("CRunningServiceDetails::MyRunnable");

        MyRunnable(
            /* [in] */ CRunningServiceDetails* host);

        //@Override
        CARAPI Run();

    private:
        CRunningServiceDetails* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    TO_STRING_IMPL("CRunningServiceDetails")

    CRunningServiceDetails();

    CARAPI constructor();

    //@Override
    CARAPI OnCreate(
        /* [in] */ IBundle* savedInstanceState);

    //@Override
    CARAPI OnCreateView(
        /* [in] */ ILayoutInflater* inflater,
        /* [in] */ IViewGroup* container,
        /* [in] */ IBundle* savedInstanceState,
        /* [out] */ IView** result);

    //@Override
    CARAPI OnPause();

    //@Override
    CARAPI OnResume();

    //@Override
    CARAPI OnRefreshUi(
        /* [in] */ Int32 what);

protected:
    virtual CARAPI_(Boolean) FindMergedItem();

    virtual CARAPI_(void) AddServicesHeader();

    virtual CARAPI_(void) AddProcessesHeader();

    virtual CARAPI_(void) AddServiceDetailsView(
        /* [in] */ RunningState::ServiceItem* si,
        /* [in] */ RunningState::MergedItem* mi,
        /* [in] */ Boolean isService,
        /* [in] */ Boolean inclDetails);

    virtual CARAPI_(void) AddProcessDetailsView(
        /* [in] */ RunningState::ProcessItem* pi,
        /* [in] */ Boolean isMain);

    virtual CARAPI_(void) AddDetailsViews(
        /* [in] */ RunningState::MergedItem* item,
        /* [in] */ Boolean inclServices,
        /* [in] */ Boolean inclProcesses);

    virtual CARAPI_(void) AddDetailViews();

    virtual CARAPI_(void) RefreshUi(
        /* [in] */ Boolean dataChanged);

    virtual CARAPI_(AutoPtr<ActiveDetail>) ActiveDetailForService(
        /* [in] */ IComponentName* comp);

    virtual CARAPI_(void) EnsureData();

    virtual CARAPI_(void) UpdateTimes();

private:
    CARAPI_(void) Finish();

    CARAPI_(void) ShowConfirmStopDialog(
        /* [in] */ IComponentName* comp);

public:
    static const String TAG;

    static const String KEY_UID;
    static const String KEY_USER_ID;
    static const String KEY_PROCESS;
    static const String KEY_BACKGROUND;

    static const Int32 DIALOG_CONFIRM_STOP = 1;

    AutoPtr<IActivityManager> mAm;
    AutoPtr<ILayoutInflater> mInflater;

    AutoPtr<RunningState> mState;
    Boolean mHaveData;

    Int32 mUid;
    Int32 mUserId;
    String mProcessName;
    Boolean mShowBackground;

    AutoPtr<RunningState::MergedItem> mMergedItem;

    AutoPtr<IView> mRootView;
    AutoPtr<IViewGroup> mAllDetails;
    AutoPtr<IViewGroup> mSnippet;
    AutoPtr<CRunningProcessesView::ActiveItem> mSnippetActiveItem;
    AutoPtr<CRunningProcessesView::ViewHolder> mSnippetViewHolder;

    Int32 mNumServices, mNumProcesses;

    AutoPtr<ITextView> mServicesHeader;
    AutoPtr<ITextView> mProcessesHeader;
    // final ArrayList<ActiveDetail> mActiveDetails = new ArrayList<ActiveDetail>();
    AutoPtr<IArrayList> mActiveDetails;

    AutoPtr<StringBuilder> mBuilder;
};

} // namespace Applications
} // namespace Settings
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_SETTINGS_APPLICATIONS_CRUNNINGSERVICEDETAILS_H__
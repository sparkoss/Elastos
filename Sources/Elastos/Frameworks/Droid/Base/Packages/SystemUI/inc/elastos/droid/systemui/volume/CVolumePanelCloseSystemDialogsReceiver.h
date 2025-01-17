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

#ifndef __ELASTOS_DROID_SYSTEMUI_VOLUME_CVOLUMEPANEL_CLOSESYSTEMDIALOG_RECEIVER_H__
#define __ELASTOS_DROID_SYSTEMUI_VOLUME_CVOLUMEPANEL_CLOSESYSTEMDIALOG_RECEIVER_H__

#include "_Elastos_Droid_SystemUI_Volume_CVolumePanelCloseSystemDialogsReceiver.h"
#include "elastos/droid/systemui/volume/VolumePanel.h"

using Elastos::Droid::SystemUI::StatusBar::Phone::ISystemUIDialog;

namespace Elastos {
namespace Droid {
namespace SystemUI{
namespace Volume{

CarClass(CVolumePanelCloseSystemDialogsReceiver), public BroadcastReceiver
{
public:
    CAR_OBJECT_DECL()

    CARAPI constructor(
        /* [in] */ ISystemUIDialog* dlg);

    // @Override
    CARAPI OnReceive(
        /* [in] */ IContext* context,
        /* [in] */ IIntent* intent);

private:
    VolumePanel::SafetyWarning* mHost;
};

} // namespace Volume
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_VOLUME_CVOLUMEPANEL_CLOSESYSTEMDIALOG_RECEIVER_H__

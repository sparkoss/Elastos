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

#include "elastos/droid/systemui/qs/tiles/ColorInversionTile.h"
#include "../R.h"
#include "Elastos.Droid.Provider.h"

using Elastos::Droid::Provider::ISettingsSecure;
using Elastos::Core::CInteger32;
using Elastos::Core::IInteger32;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Qs {
namespace Tiles {

ECode ColorInversionTile::ColorSettings::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IHandler* handler,
    /* [in] */ const String& settingName,
    /* [in] */ ColorInversionTile* host)
{
    mHost = host;
    return SecureSetting::constructor(context, handler, settingName);
}

ECode ColorInversionTile::ColorSettings::HandleValueChanged(
    /* [in] */ Int32 value)
{
    mHost->mUsageTracker->TrackUsage();
    if (mHost->mListening) {
        AutoPtr<IInteger32> obj;
        CInteger32::New(value, (IInteger32**)&obj);
        mHost->HandleRefreshState(obj);
    }
    return NOERROR;
}

CAR_INTERFACE_IMPL(ColorInversionTile, QSTile, IColorInversionTile)
ColorInversionTile::ColorInversionTile(
    /* [in] */ IQSTileHost* host)
    : mListening(FALSE)
{
    QSTile::constructor(host);
    mSetting = new ColorSettings();
    mSetting->constructor(mContext, mHandler,
            ISettingsSecure::ACCESSIBILITY_DISPLAY_INVERSION_ENABLED, this);

    AutoPtr<IContext> ctx;
    host->GetContext((IContext**)&ctx);
    mUsageTracker = new UsageTracker(ctx, this/*ColorInversionTile.class*/);
    if (mSetting->GetValue() != 0 && !mUsageTracker->IsRecentlyUsed()) {
        mUsageTracker->TrackUsage();
    }
    mUsageTracker->SetListening(TRUE);
    mSetting->SetListening(TRUE);
}

void ColorInversionTile::HandleDestroy()
{
    QSTile::HandleDestroy();
    mUsageTracker->SetListening(FALSE);
    mSetting->SetListening(FALSE);
}

AutoPtr<QSTile::State> ColorInversionTile::NewTileState()
{
    return new BooleanState();
}

ECode ColorInversionTile::SetListening(
    /* [in] */ Boolean listening)
{
    mListening = listening;
    return NOERROR;
}

void ColorInversionTile::HandleUserSwitch(
    /* [in] */ Int32 newUserId)
{
    mSetting->SetUserId(newUserId);

    AutoPtr<IInteger32> obj;
    CInteger32::New(mSetting->GetValue(), (IInteger32**)&obj);
    HandleRefreshState(obj);
}

void ColorInversionTile::HandleClick()
{
    mSetting->SetValue(((BooleanState*)mState.Get())->mValue ? 0 : 1);
}

void ColorInversionTile::HandleUpdateState(
    /* [in] */ State* state,
    /* [in] */ IInterface* arg)
{
    Int32 value = 0;
    if (IInteger32::Probe(arg)) {
        IInteger32::Probe(arg)->GetValue(&value);
    }
    else {
        value = mSetting->GetValue();
    }
    Boolean enabled = value != 0;
    state->mVisible = enabled || mUsageTracker->IsRecentlyUsed();
    ((BooleanState*)state)->mValue = enabled;
    mContext->GetString(R::string::quick_settings_inversion_label, &state->mLabel);
    state->mIconId = enabled ? R::drawable::ic_qs_inversion_on : R::drawable::ic_qs_inversion_off;
}

String ColorInversionTile::ComposeChangeAnnouncement()
{
    String v;
    if (((BooleanState*)mState.Get())->mValue) {
        mContext->GetString(R::string::accessibility_quick_settings_color_inversion_changed_on, &v);
    }
    else {
        mContext->GetString(R::string::accessibility_quick_settings_color_inversion_changed_off, &v);
    }
    return v;
}

String ColorInversionTile::GetSimpleName()
{
    return String("ColorInversionTile");
}

} // namespace Tiles
} // namespace Qs
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

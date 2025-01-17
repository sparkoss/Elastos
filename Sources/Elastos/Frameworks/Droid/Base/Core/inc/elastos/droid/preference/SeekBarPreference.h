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

#ifndef __ELASTOS_DROID_PREFERENCE_SEEKBARPREFERENCE_H__
#define __ELASTOS_DROID_PREFERENCE_SEEKBARPREFERENCE_H__

#include "elastos/droid/ext/frameworkext.h"
#include "Elastos.Droid.Widget.h"
#include "elastos/droid/preference/Preference.h"

using Elastos::Core::IComparable;
using Elastos::Droid::Widget::ISeekBar;
using Elastos::Droid::Widget::ISeekBarOnSeekBarChangeListener;

namespace Elastos {
namespace Droid {
namespace Preference {

class ECO_PUBLIC SeekBarPreference
    : public Preference
    , public ISeekBarPreference
{
private:
    class ECO_LOCAL InnerListener
        : public Object
        , public ISeekBarOnSeekBarChangeListener
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("SeekBarPreference::InnerListener")

        InnerListener(
            /* [in] */ SeekBarPreference* host);

        CARAPI OnProgressChanged(
                /* [in] */ ISeekBar* seekBar,
                /* [in] */ Int32 progress,
                /* [in] */ Boolean fromUser);

        CARAPI OnStartTrackingTouch(
            /* [in] */ ISeekBar* seekBar);

        CARAPI OnStopTrackingTouch(
            /* [in] */ ISeekBar* seekBar);

    private:
        SeekBarPreference* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    SeekBarPreference();

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyleAttr,
        /* [in] */ Int32 defStyleRes);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyleAttr);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI GetSummary(
        /* [out] */ ICharSequence** summary);

    CARAPI OnKey(
        /* [in] */ IView* v,
        /* [in] */ Int32 keyCode,
        /* [in] */ IKeyEvent* event,
        /* [out] */ Boolean* result);

    CARAPI SetMax(
        /* [in] */ Int32 max);

    CARAPI SetProgress(
        /* [in] */ Int32 progress);

    CARAPI GetProgress(
        /* [out] */ Int32* result);

protected:
    CARAPI OnBindView(
        /* [in] */ IView* view);

    CARAPI OnSetInitialValue(
        /* [in] */ Boolean restoreValue,
        /* [in] */ IInterface* defaultValue);

    CARAPI OnGetDefaultValue(
        /* [in] */ ITypedArray* a,
        /* [in] */ Int32 index,
        /* [out] */ IInterface** value);

    /**
     * Persist the seekBar's progress value if callChangeListener
     * returns true, otherwise set the seekBar's progress to the stored value
     */
    CARAPI SyncProgress(
        /* [in] */ ISeekBar* seekBar);

    CARAPI OnProgressChanged(
            /* [in] */ ISeekBar* seekBar,
            /* [in] */ Int32 progress,
            /* [in] */ Boolean fromUser);

    CARAPI OnStartTrackingTouch(
        /* [in] */ ISeekBar* seekBar);

    CARAPI OnStopTrackingTouch(
        /* [in] */ ISeekBar* seekBar);

    CARAPI OnSaveInstanceState(
        /* [out] */ IParcelable** state);

    CARAPI OnRestoreInstanceState(
        /* [in] */ IParcelable* state);

private:
    ECO_LOCAL CARAPI SetProgress(
        /* [in] */ Int32 progress,
        /* [in] */ Boolean notifyChanged);

private:
    Int32 mProgress;
    Int32 mMax;
    Boolean mTrackingTouch;
};

}
}
}
#endif // __SeekBarPreference_H__

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

#ifndef __ELASTOS_DROID_DIALER_CCALLTYPEICONSVIEW_H__
#define __ELASTOS_DROID_DIALER_CCALLTYPEICONSVIEW_H__

#include "_Elastos_Droid_Dialer_CallLog_CCallTypeIconsView.h"
#include "Elastos.CoreLibrary.Utility.h"
#include "elastos/droid/view/View.h"

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Graphics::ICanvas;
using Elastos::Droid::Graphics::Drawable::IDrawable;
using Elastos::Droid::Utility::IAttributeSet;
using Elastos::Utility::IList;

namespace Elastos{
namespace Droid{
namespace Dialer {
namespace CallLog {

/**
 * Helper class to perform operations related to call types.
 */
CarClass(CCallTypeIconsView)
    , public Elastos::Droid::View::View
    , public ICallTypeIconsView
{
private:
    class Resources
        : public Object
    {
    public:
        /**
         * Configures the call icon drawables.
         * A single white call arrow which points down and left is used as a basis for all of the
         * call arrow icons, applying rotation and colors as needed.
         *
         * @param context The current context.
         */
        Resources(
            /* [in] */ IContext* context);
    public:
        /**
         * Drawable representing an incoming answered call.
         */
        AutoPtr<IDrawable> mIncoming;

        /**
         * Drawable respresenting an outgoing call.
         */
        AutoPtr<IDrawable> mOutgoing;

        /**
         * Drawable representing an incoming missed call.
         */
        AutoPtr<IDrawable> mMissed;

        /**
         * Drawable representing a voicemail.
         */
        AutoPtr<IDrawable> mVoicemail;

        /**
         * Drawable repesenting a video call.
         */
        AutoPtr<IDrawable> mVideoCall;

        /**
         * The margin to use for icons.
         */
        Int32 mIconMargin;
    };

public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CCallTypeIconsView();

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI Clear();

    CARAPI Add(
        /* [in] */ Int32 callType);

    /**
     * Determines whether the video call icon will be shown.
     *
     * @param showVideo True where the video icon should be shown.
     */
    CARAPI SetShowVideo(
        /* [in] */ Boolean showVideo);

    /**
     * Determines if the video icon should be shown.
     *
     * @return True if the video icon should be shown.
     */
    CARAPI IsVideoShown(
        /* [out] */ Boolean* result);

    // @NeededForTesting
    CARAPI GetCount(
        /* [out] */ Int32* count);

    // @NeededForTesting
    CARAPI GetCallType(
        /* [in] */ Int32 index,
        /* [out] */ Int32* result);

protected:
    // @Override
    CARAPI OnMeasure(
        /* [in] */ Int32 widthMeasureSpec,
        /* [in] */ Int32 heightMeasureSpec);

    // @Override
    CARAPI_(void) OnDraw(
        /* [in] */ ICanvas* canvas);

private:
    CARAPI_(AutoPtr<IDrawable>) GetCallTypeDrawable(
        /* [in] */ Int32 callType);

private:
    AutoPtr<IList> mCallTypes; // = Lists.newArrayListWithCapacity(3);
    Boolean mShowVideo; // = false;
    AutoPtr<Resources> mResources;
    Int32 mWidth;
    Int32 mHeight;
};

} // CallLog
} // Dialer
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_DIALER_CCALLTYPEICONSVIEW_H__

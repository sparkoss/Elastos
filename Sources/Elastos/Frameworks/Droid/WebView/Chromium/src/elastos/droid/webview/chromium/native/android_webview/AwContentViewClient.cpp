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

#include <Elastos.Droid.Widget.h>
#include "elastos/droid/webkit/webview/chromium/native/android_webview/AwContentViewClient.h"
#include "elastos/droid/webkit/webview/chromium/native/base/CommandLine.h"
#include "elastos/droid/webkit/webview/chromium/native/content/browser/ContentVideoView.h"
#include "elastos/droid/webkit/webview/chromium/native/content/common/ContentSwitches.h"
#include "elastos/droid/webkit/webview/chromium/native/android_webview/AwContents.h"
#include "elastos/droid/webkit/URLUtil.h"

using Elastos::Droid::View::IViewGroup;
using Elastos::Droid::View::EIID_IViewOnAttachStateChangeListener;
using Elastos::Droid::Webkit::EIID_IWebChromeClientCustomViewCallback;
using Elastos::Droid::Webkit::URLUtil;
using Elastos::Droid::Webkit::Webview::Chromium::Base::CommandLine;
using Elastos::Droid::Webkit::Webview::Chromium::Content::Browser::ContentVideoView;
using Elastos::Droid::Webkit::Webview::Chromium::Content::Common::ContentSwitches;
using Elastos::Droid::Widget::CFrameLayout;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace AndroidWebview {

//=======================================================================================================
//         AwContentViewClient::AwContentVideoViewClient::InnerWebChromeClientCustomViewCallback
//=======================================================================================================
CAR_INTERFACE_IMPL(AwContentViewClient::AwContentVideoViewClient::InnerWebChromeClientCustomViewCallback, Object, IWebChromeClientCustomViewCallback);

AwContentViewClient::AwContentVideoViewClient::InnerWebChromeClientCustomViewCallback::InnerWebChromeClientCustomViewCallback(
    /* [in] */ AwContentVideoViewClient* owner)
    : mOwner(owner)
{
}

ECode AwContentViewClient::AwContentVideoViewClient::InnerWebChromeClientCustomViewCallback::OnCustomViewHidden()
{
    AutoPtr<ContentVideoView> contentVideoView = ContentVideoView::GetContentVideoView();
    if (contentVideoView != NULL)
        contentVideoView->ExitFullscreen(FALSE);

    return NOERROR;
}

//=======================================================================================================
//          AwContentViewClient::AwContentVideoViewClient::InnerViewOnAttachStateChangeListener
//=======================================================================================================
CAR_INTERFACE_IMPL(AwContentViewClient::AwContentVideoViewClient::InnerViewOnAttachStateChangeListener, Object, IViewOnAttachStateChangeListener);

AwContentViewClient::AwContentVideoViewClient::InnerViewOnAttachStateChangeListener::InnerViewOnAttachStateChangeListener(
    /* [in] */ AwContentVideoViewClient* owner,
    /* [in] */ IFrameLayout* viewGroup)
    : mOwner(owner)
    , mViewGroup(viewGroup)
{
}

//@Override
ECode AwContentViewClient::AwContentVideoViewClient::InnerViewOnAttachStateChangeListener::OnViewDetachedFromWindow(
    /* [in] */ IView* v)
{
    // Intentional no-op (see onDestroyContentVideoView).
    return NOERROR;
}

//@Override
ECode AwContentViewClient::AwContentVideoViewClient::InnerViewOnAttachStateChangeListener::OnViewAttachedToWindow(
    /* [in] */ IView* v)
{
    if (mOwner->mOwner->mAwContents->IsFullScreen())
    {
        return NOERROR;
    }

    AutoPtr<IViewGroup> viewGroup = IViewGroup::Probe(mViewGroup);
    viewGroup->AddView((IView*)mOwner->mOwner->mAwContents->EnterFullScreen());

    return NOERROR;
}

//===============================================================
//        AwContentViewClient::AwContentVideoViewClient
//===============================================================

AwContentViewClient::AwContentVideoViewClient::AwContentVideoViewClient(
    /* [in] */ AwContentViewClient* owner)
    : mOwner(owner)
{
}

//@Override
Boolean AwContentViewClient::AwContentVideoViewClient::OnShowCustomView(
    /* [in] */ IView* view)
{
    AutoPtr<IWebChromeClientCustomViewCallback> cb = new InnerWebChromeClientCustomViewCallback(this);
    // TODO(igsolla): remove the legacy path (kept as a fallback if things go awry).
    if (!AreHtmlControlsEnabled()) {
        OnShowCustomViewLegacy(view, cb);
    }
    else {
        OnShowCustomView(view, cb);
    }
    return TRUE;
}

void AwContentViewClient::AwContentVideoViewClient::OnShowCustomViewLegacy(
    /* [in] */ IView* view,
    /* [in] */ IWebChromeClientCustomViewCallback* cb)
{
    mOwner->mAwContentsClient->OnShowCustomView(view, cb);
}

void AwContentViewClient::AwContentVideoViewClient::OnShowCustomView(
    /* [in] */ IView* view,
    /* [in] */ IWebChromeClientCustomViewCallback* cb)
{
    AutoPtr<IFrameLayout> frameLayout;
    CFrameLayout::New(mOwner->mContext, (IFrameLayout**)&frameLayout);
    AutoPtr<IViewGroup> viewGroup = IViewGroup::Probe(frameLayout);
    viewGroup->AddView(view);
    AutoPtr<IViewOnAttachStateChangeListener> listener = new InnerViewOnAttachStateChangeListener(this, frameLayout);
    AutoPtr<IView> v = IView::Probe(frameLayout);
    v->AddOnAttachStateChangeListener(listener);
    mOwner->mAwContentsClient->OnShowCustomView(v, cb);
}

//@Override
void AwContentViewClient::AwContentVideoViewClient::OnDestroyContentVideoView()
{
    if (AreHtmlControlsEnabled()) {
        mOwner->mAwContents->ExitFullScreen();
    }
    mOwner->mAwContentsClient->OnHideCustomView();
}

//@Override
AutoPtr<IView> AwContentViewClient::AwContentVideoViewClient::GetVideoLoadingProgressView()
{
    return mOwner->mAwContentsClient->GetVideoLoadingProgressView();
}

//===============================================================
//                    AwContentViewClient
//===============================================================

AwContentViewClient::AwContentViewClient(
    /* [in] */ AwContentsClient* awContentsClient,
    /* [in] */ AwSettings* awSettings,
    /* [in] */ AwContents* awContents,
    /* [in] */ IContext* context)
    : mAwContentsClient(awContentsClient)
    , mAwSettings(awSettings)
    , mAwContents(awContents)
    , mContext(context)
{
}

//@Override
void AwContentViewClient::OnBackgroundColorChanged(
    /* [in] */ Int32 color)
{
    mAwContentsClient->OnBackgroundColorChanged(color);
}

//@Override
void AwContentViewClient::OnStartContentIntent(
    /* [in] */ IContext* context,
    /* [in] */ const String& contentUrl)
{
    //  Callback when detecting a click on a content link.
    mAwContentsClient->ShouldOverrideUrlLoading(contentUrl);
}

//@Override
void AwContentViewClient::OnUpdateTitle(
    /* [in] */ const String& title)
{
    mAwContentsClient->OnReceivedTitle(title);
}

//@Override
Boolean AwContentViewClient::ShouldOverrideKeyEvent(
    /* [in] */ IKeyEvent* event)
{
    return mAwContentsClient->ShouldOverrideKeyEvent(event);
}

//@Override
AutoPtr<ContentVideoViewClient> AwContentViewClient::GetContentVideoViewClient()
{
    AutoPtr<ContentVideoViewClient> cvvc = new AwContentVideoViewClient(this);
    return cvvc;
}

//@Override
Boolean AwContentViewClient::ShouldBlockMediaRequest(
    /* [in] */ const String& url)
{
    return mAwSettings != NULL ?  mAwSettings->GetBlockNetworkLoads() && URLUtil::IsNetworkUrl(url) : TRUE;
}

Boolean AwContentViewClient::AreHtmlControlsEnabled()
{
    return !CommandLine::GetInstance()->HasSwitch(
            ContentSwitches::DISABLE_OVERLAY_FULLSCREEN_VIDEO_SUBTITLE);
}

} // namespace AndroidWebview
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

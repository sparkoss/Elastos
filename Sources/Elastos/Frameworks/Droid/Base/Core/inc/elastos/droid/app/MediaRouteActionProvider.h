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

#ifndef __ELASTOS_DROID_APP_MEDIA_ROUTE_ACTION_PROVIDER_H__
#define __ELASTOS_DROID_APP_MEDIA_ROUTE_ACTION_PROVIDER_H__

#include "Elastos.Droid.App.h"
#include "elastos/droid/view/ActionProvider.h"
#include "elastos/droid/media/MediaRouterSimpleCallback.h"


using Elastos::Droid::Content::IContext;
using Elastos::Droid::Media::IMediaRouter;
using Elastos::Droid::Media::MediaRouterSimpleCallback;
using Elastos::Droid::Media::IMediaRouterCallback;
using Elastos::Droid::Media::IMediaRouterRouteInfo;
using Elastos::Droid::View::ActionProvider;
using Elastos::Droid::View::IActionProvider;
using Elastos::Droid::View::IMenuItem;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::View::IViewGroup;

namespace Elastos {
namespace Droid {
namespace App {

/**
 * IntentService is a base class for {@link Service}s that handle asynchronous
 * requests (expressed as {@link Intent}s) on demand.  Clients send requests
 * through {@link android.content.Context#startService(Intent)} calls; the
 * service is started as needed, handles each Intent in turn using a worker
 * thread, and stops itself when it runs out of work.
 *
 * <p>This "work queue processor" pattern is commonly used to offload tasks
 * from an application's main thread.  The IntentService class exists to
 * simplify this pattern and take care of the mechanics.  To use it, extend
 * IntentService and implement {@link #onHandleIntent(Intent)}.  IntentService
 * will receive the Intents, launch a worker thread, and stop the service as
 * appropriate.
 *
 * <p>All requests are handled on a single worker thread -- they may take as
 * long as necessary (and will not block the application's main loop), but
 * only one request will be processed at a time.
 *
 * <div class="special reference">
 * <h3>Developer Guides</h3>
 * <p>For a detailed discussion about how to create services, read the
 * <a href="{@docRoot}guide/topics/fundamentals/services.html">Services</a> developer guide.</p>
 * </div>
 *
 * @see android.os.AsyncTask
 */
class MediaRouteActionProvider
    : public ActionProvider
    , public IMediaRouteActionProvider
{
private:
    class MediaRouterCallback
        : public MediaRouterSimpleCallback
    {
    public:
        MediaRouterCallback();

        CARAPI constructor(
            /* [in] */ IMediaRouteActionProvider* provider);

        //@Override
        CARAPI OnRouteAdded(
            /* [in] */ IMediaRouter* router,
            /* [in] */ IMediaRouterRouteInfo* info);

        //@Override
        CARAPI OnRouteRemoved(
            /* [in] */ IMediaRouter* router,
            /* [in] */ IMediaRouterRouteInfo* info);

        //@Override
        CARAPI OnRouteChanged(
            /* [in] */ IMediaRouter* router,
            /* [in] */ IMediaRouterRouteInfo* info);

        void RefreshRoute(
            /* [in] */ IMediaRouter* router);

    private:
        AutoPtr<IWeakReference> mProviderWeak;
    };

public:
    MediaRouteActionProvider();

    virtual ~MediaRouteActionProvider();

    CAR_INTERFACE_DECL()

    CARAPI constructor(
        /* [in] */ IContext* context);
    /**
     * Sets the types of routes that will be shown in the media route chooser dialog
     * launched by this button.
     *
     * @param types The route types to match.
     */
    CARAPI SetRouteTypes(
        /* [in] */ Int32 types);

    CARAPI SetExtendedSettingsClickListener(
        /* [in] */ IViewOnClickListener* listener);

    // @Override
    CARAPI OnCreateActionView(
        /* [out] */ IView** view);

    // @Override
    CARAPI OnCreateActionView(
        /* [in] */ IMenuItem* item,
        /* [out] */ IView** view);

    //@Override
    CARAPI OnPerformDefaultAction(
        /* [out] */ Boolean* result);

    //@Override
    CARAPI OverridesItemVisibility(
        /* [out] */ Boolean* result);

    //@Override
    CARAPI IsVisible(
        /* [out] */ Boolean* result);

private:
    void RefreshRoute();

private:
    static const String TAG;// = "MediaRouteActionProvider";

    AutoPtr<IContext> mContext;
    AutoPtr<IMediaRouter> mRouter;
    AutoPtr<IMediaRouterCallback> mCallback;

    Int32 mRouteTypes;
    AutoPtr<IMediaRouteButton> mButton;
    AutoPtr<IViewOnClickListener> mExtendedSettingsListener;
};

} // namespace App
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_APP_MEDIA_ROUTE_ACTION_PROVIDER_H__

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

#ifndef __ELASTOS_DROID_SERVER_TV_PERSISTENTDATASTORE_H__
#define __ELASTOS_DROID_SERVER_TV_PERSISTENTDATASTORE_H__

#include "_Elastos.Droid.Server.h"
#include <Elastos.Droid.Media.h>
#include <elastos/core/Object.h>
#include <elastos/droid/ext/frameworkext.h>
#include <elastos/droid/internal/utility/State.h>
#include <elastos/droid/os/Handler.h>
#include <elastos/core/Runnable.h>
#include <elastos/droid/utility/Xml.h>

using Elastos::Core::IRunnable;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Internal::Utility::State;
using Elastos::Droid::Media::Tv::ITvContentRating;
using Elastos::Droid::Os::Handler;
using Elastos::Droid::Os::IHandler;
using Elastos::Core::Runnable;
using Elastos::Droid::Utility::IAtomicFile;
using Elastos::Droid::Utility::Xml;
using Elastos::Utility::IList;
using Org::Xmlpull::V1::IXmlPullParser;
using Org::Xmlpull::V1::IXmlSerializer;

namespace Elastos {
namespace Droid {
namespace Server {
namespace Tv {

/**
 * Manages persistent state recorded by the TV input manager service as an XML file. This class is
 * not thread-safe thus caller must acquire lock on the data store before accessing it. File format:
 * <code>
 * &lt;tv-input-manager-state>
 *   &lt;blocked-ratings>
 *     &lt;rating string="XXXX" />
 *   &lt;/blocked-ratings>
 *   &lt;parental-control enabled="YYYY" />
 * &lt;/tv-input-manager-state>
 * </code>
 */
class PersistentDataStore
    : public Object
{
private:
    class InnerSub_Runnable
        : public Object
        , public IRunnable
    {
    public:
        InnerSub_Runnable(
            /* [in] */ PersistentDataStore* host);

        // @Override
        CARAPI Run();

    private:
        PersistentDataStore* mHost;
    };
public:
    PersistentDataStore();

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ Int32 userId);

    CARAPI IsParentalControlsEnabled(
        /* [out] */ Boolean* result);

    CARAPI SetParentalControlsEnabled(
        /* [in] */ Boolean enabled);

    CARAPI IsRatingBlocked(
        /* [in] */ ITvContentRating* rating,
        /* [out] */ Boolean* result);

    CARAPI GetBlockedRatings(
        /* [out, callee] */ ArrayOf<ITvContentRating*>** result);

    CARAPI AddBlockedRating(
        /* [in] */ ITvContentRating* rating);

    CARAPI RemoveBlockedRating(
        /* [in] */ ITvContentRating* rating);

private:
    CARAPI LoadIfNeeded();

    CARAPI ClearState();

    CARAPI Load();

    CARAPI PostSave();

    CARAPI Save();

    CARAPI BroadcastChangesIfNeeded();

    CARAPI LoadFromXml(
        /* [in] */ IXmlPullParser* parser);

    CARAPI LoadBlockedRatingsFromXml(
        /* [in] */ IXmlPullParser* parser);

    CARAPI SaveToXml(
        /* [in] */ IXmlSerializer* serializer);

private:
    static const String TAG;

    AutoPtr<IContext> mContext;

    AutoPtr<IHandler> mHandler;

    // The atomic file used to safely read or write the file.
    AutoPtr<IAtomicFile> mAtomicFile;

    AutoPtr<IList> mBlockedRatings;

    Boolean mBlockedRatingsChanged;

    Boolean mParentalControlsEnabled;

    Boolean mParentalControlsEnabledChanged;

    // True if the data has been loaded.
    Boolean mLoaded;

    /**
     * Runnable posted when the state needs to be saved. This is used to prevent unnecessary file
     * operations when multiple settings change in rapid succession.
     */
    AutoPtr<IRunnable> mSaveRunnable;

    static const String TAG_TV_INPUT_MANAGER_STATE;

    static const String TAG_BLOCKED_RATINGS;

    static const String TAG_RATING;

    static const String TAG_PARENTAL_CONTROLS;

    static const String ATTR_STRING;

    static const String ATTR_ENABLED;
};

} // namespace Tv
} // namespace Server
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SERVER_TV_PERSISTENTDATASTORE_H__

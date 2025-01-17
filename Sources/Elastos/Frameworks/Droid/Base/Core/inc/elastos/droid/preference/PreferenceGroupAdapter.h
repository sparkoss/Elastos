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

#ifndef __ELASTOS_DROID_PREFERENCE_PREFERENCEGROUPADAPTER_H__
#define __ELASTOS_DROID_PREFERENCE_PREFERENCEGROUPADAPTER_H__

#include "elastos/droid/ext/frameworkext.h"
#include <Elastos.CoreLibrary.Utility.h>
#include "Elastos.Droid.Graphics.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.Preference.h"
#include <elastos/core/Runnable.h>
#include "elastos/droid/widget/BaseAdapter.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Graphics::Drawable:: IDrawable;
using Elastos::Droid::Preference::IPreferenceOnPreferenceChangeListener;
using Elastos::Droid::Os::IHandler;
using Elastos::Core::Runnable;
using Elastos::Droid::View::IViewGroupLayoutParams;
using Elastos::Droid::Widget::BaseAdapter;
using Elastos::Droid::Widget::IBaseAdapter;
using Elastos::Core::IComparable;
using Elastos::Utility::IList;
using Elastos::Utility::ICollections;

namespace Elastos {
namespace Droid {
namespace Preference {

class PreferenceGroupAdapter
    : public BaseAdapter
    , public IPreferenceGroupAdapter
{
private:
    class InnerListener
        : public Object
        , public IPreferenceOnPreferenceChangeInternalListener
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("PreferenceGroupAdapter::InnerListener")

        InnerListener(
            /* [in] */ PreferenceGroupAdapter* host);

        CARAPI OnPreferenceChange(
            /* [in] */ IPreference* preference);

        CARAPI OnPreferenceHierarchyChange(
            /* [in] */ IPreference* preference);

    private:
        PreferenceGroupAdapter* mHost;
    };

    class PreferenceLayout
        : public Object
        , public IComparable
        , public IPreferenceLayout
    {
    public:
        CAR_INTERFACE_DECL()

        PreferenceLayout();

        //@Override
        CARAPI CompareTo(
            /* [in]  */ IInterface* other,
            /* [out]  */ Int32* result);

        CARAPI GetResId(
            /* [out]  */ Int32* resId);

        CARAPI SetResId(
            /* [in]  */ Int32 resId);

        CARAPI GetWidgetResId(
            /* [out]  */ Int32* resId);

        CARAPI SetWidgetResId(
            /* [in]  */ Int32 resId);

        CARAPI GetName(
            /* [out]  */ String* name);

        CARAPI SetName(
            /* [in]  */ const String & name);

    public:
        Int32 mResId;
        Int32 mWidgetResId;
        String mName;
    };

    class SyncRunnable
        : public Runnable
    {
    public:
        SyncRunnable(
            /* [in]  */ PreferenceGroupAdapter* host);

        CARAPI Run();

    private:
        PreferenceGroupAdapter* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    PreferenceGroupAdapter();

    CARAPI constructor(
        /* [in] */ IPreferenceGroup* preferenceGroup);

    CARAPI GetCount(
        /* [out] */ Int32* count);

    // override
    CARAPI GetItem(
        /* [in] */ Int32 position,
        /* [out] */ IInterface** item);

    CARAPI GetItemId(
        /* [in] */ Int32 position,
        /* [out] */ Int64* id);

    /**
     * @hide
     */
    CARAPI SetHighlighted(
        /* [in] */ Int32 position);

    /**
     * @hide
     */
    CARAPI SetHighlightedDrawable(
        /* [in] */ IDrawable* drawable);

    CARAPI GetView(
        /* [in] */ Int32 position,
        /* [in] */ IView* convertView,
        /* [in] */ IViewGroup* parent,
        /* [out] */ IView** view);

    CARAPI IsEnabled(
        /* [in] */ Int32 position,
        /* [out] */ Boolean* enabled);

    CARAPI AreAllItemsEnabled(
        /* [out] */ Boolean* enabled);

    CARAPI OnPreferenceChange(
        /* [in] */ IPreference* preference);

    CARAPI OnPreferenceHierarchyChange(
        /* [in] */ IPreference* preference);

    CARAPI HasStableIds(
        /* [out] */ Boolean* hasStableIds);

    CARAPI GetItemViewType(
        /* [in] */ Int32 position,
        /* [out] */ Int32* type);

    CARAPI GetViewTypeCount(
        /* [out] */ Int32* count);

private:
    CARAPI GetHighlightItemViewType(
        /* [out] */ Int32* type);

    CARAPI_(void) SyncMyPreferences();

    CARAPI_(void) FlattenPreferenceGroup(
        /* [in] */ IList* preferences,
        /* [in] */ IPreferenceGroup* group);
    /**
     * Creates a string that includes the preference name, layout id and widget layout id.
     * If a particular preference type uses 2 different resources, they will be treated as
     * different view types.
     */
    CARAPI_(AutoPtr<IPreferenceLayout>) CreatePreferenceLayout(
        /* [in] */ IPreference* preference,
        /* [in] */ IPreferenceLayout* in);

    CARAPI_(void) AddPreferenceClassName(
        /* [in] */ IPreference* preference);

    static AutoPtr<ICollections> GetCollections();

private:
    const static String TAG;

    static AutoPtr<ICollections> sCollections;

    /**
     * The group that we are providing data from.
     */
    // context usually holds adapter, we use weak-reference here.
    AutoPtr<IWeakReference> mWeakPreferenceGroup;
    // AutoPtr<IPreferenceGroup> mPreferenceGroup;

    /**
     * Maps a position into this adapter -> {@link Preference}. These
     * {@link Preference}s don't have to be direct children of this
     * {@link PreferenceGroup}, they can be grand children or younger)
     */
    AutoPtr<IList> mPreferenceList;

    /**
     * List of unique Preference and its subclasses' names. This is used to find
     * out how many types of views this adapter can return. Once the count is
     * returned, this cannot be modified (since the ListView only checks the
     * count once--when the adapter is being set). We will not recycle views for
     * Preference subclasses seen after the count has been returned.
     */
    AutoPtr<IList> mPreferenceLayouts;

    AutoPtr<IPreferenceLayout> mTempPreferenceLayout;

    /**
     * Blocks the mPreferenceClassNames from being changed anymore.
     */
    Boolean mHasReturnedViewTypeCount;

    Boolean mIsSyncing;

    AutoPtr<IHandler> mHandler;

    AutoPtr<IRunnable> mSyncRunnable;
    Object mLock;

    Int32 mHighlightedPosition;
    AutoPtr<IDrawable> mHighlightedDrawable;

    static AutoPtr<IViewGroupLayoutParams> sWrapperLayoutParams;
};

}
}
}

#endif // __ELASTOS_DROID_PREFERENCE_PREFERENCEGROUPADAPTER_H__

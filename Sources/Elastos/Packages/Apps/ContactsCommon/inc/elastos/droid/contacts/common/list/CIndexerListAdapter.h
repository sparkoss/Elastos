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

#ifndef __ELASTOS_APPS_CONTACTS_COMMON_LIST_CINDEXERLISTADAPTER_H__
#define __ELASTOS_APPS_CONTACTS_COMMON_LIST_CINDEXERLISTADAPTER_H__

#include "_Elastos_Apps_Contacts_Common_List_CIndexerListAdapter.h"


namespace Elastos{
namespace Apps{
namespace Contacts {
namespace Common {
namespace List {

/**
 * A list adapter that supports section indexer and a pinned header.
 */
CarClass(CIndexerListAdapter)
    , public CPinnedHeaderListAdapter
    , public IIndexerListAdapter
    , public ISectionIndexer
{
public:
    /**
     * An item view is displayed differently depending on whether it is placed
     * at the beginning, middle or end of a section. It also needs to know the
     * section header when it is at the beginning of a section. This object
     * captures all this configuration.
     */
    class Placement
        : public object
        , public IIndexerListAdapterPlacement
    {
    public:
        CAR_INTERFACE_DECL()

        Placement();

        CARAPI Invalidate();

    public:
        Boolean mFirstInSection;
        Boolean mLastInSection;
        String mSectionHeader;
    private:
        Int32 mPosition; // = ListView.INVALID_POSITION;
    };

public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CIndexerListAdapter();

    virtual ~CIndexerListAdapter();

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI IsSectionHeaderDisplayEnabled(
        /* [out] */ Boolean* result);

    CARAPI SetSectionHeaderDisplayEnabled(
        /* [in] */ Boolean flag);

    CARAPI GetIndexedPartition(
        /* [out] */ Boolean* result);

    CARAPI SetIndexedPartition(
        /* [in] */ Int32 partition);

    CARAPI GetIndexer(
        /* [out] */ ISectionIndexer** indexer);

    CARAPI SetIndexer(
        /* [in] */ ISectionIndexer* indexer);

    CARAPI GetSections(
        /* [out, callee] */ ArrayOf<IInterface*>** sections);

    /**
     * @return relative position of the section in the indexed partition
     */
    CARAPI GetPositionForSection(
        /* [in] */ Int32 sectionIndex,
        /* [out] */ Int32* result);

    /**
     * @param position relative position in the indexed partition
     */
    CARAPI GetSectionForPosition(
        /* [in] */ Int32 position,
        /* [out] */ Int32* result);

    // @Override
    CARAPI GetPinnedHeaderCount(
        /* [out] */ Int32* count);

    // @Override
    CARAPI GetPinnedHeaderView(
        /* [in] */ Int32 partition,
        /* [in] */ IView* convertView,
        /* [in] */ IViewGroup* parent,
        /* [out] */ IView** result);

    // @Override
    CARAPI ConfigurePinnedHeaders(
        /* [in] */ IPinnedHeaderListView* listView);

    /**
     * Computes the item's placement within its section and populates the {@code placement}
     * object accordingly.  Please note that the returned object is volatile and should be
     * copied if the result needs to be used later.
     */
    CARAPI GetItemPlacementInSection(
        /* [in] */ Int32 position,
        /* [out] */ IIndexerListAdapterPlacement** placement);

protected:
    /**
     * Creates a section header view that will be pinned at the top of the list
     * as the user scrolls.
     */
    CARAPI_(AutoPtr<IView>) CreatePinnedSectionHeaderView(
        /* [in] */ IContext* context,
        /* [in] */ ViewGroup parent) = 0;

    /**
     * Sets the title in the pinned header as the user scrolls.
     */
    CARAPI_(void) SetPinnedSectionTitle(
        /* [in] */ IView* pinnedHeaderView,
        /* [in] */ const String& title) = 0;

protected:
    AutoPtr<IContext> mContext;

private:
    AutoPtr<ISectionIndexer> mIndexer;
    Int32 mIndexedPartition; // = 0;
    Boolean mSectionHeaderDisplayEnabled;
    AutoPtr<IView> mHeader;

    AutoPtr<Placement> mPlacementCache;
};

} // List
} // Common
} // Contacts
} // Apps
} // Elastos

#endif //__ELASTOS_APPS_CONTACTS_COMMON_LIST_CINDEXERLISTADAPTER_H__

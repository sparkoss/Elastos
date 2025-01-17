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

#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Graphics.h"
#include "Elastos.Droid.View.h"
#include "Elastos.Droid.Widget.h"
#include "elastos/droid/text/TextUtils.h"
#include "elastos/droid/webkit/webview/chromium/native/base/ApiCompatibilityUtils.h"
#include "elastos/droid/webkit/webview/chromium/native/ui/ColorSuggestion.h"
#include "elastos/droid/webkit/webview/chromium/native/ui/ColorSuggestionListAdapter.h"
#include "elastos/droid/webkit/webview/chromium/native/ui/R_Ui.h"

using Elastos::Droid::Content::Res::IResources;
using Elastos::Droid::Graphics::Drawable::IDrawable;
using Elastos::Droid::Graphics::Drawable::IGradientDrawable;
using Elastos::Droid::Graphics::Drawable::ILayerDrawable;
using Elastos::Droid::Graphics::IColor;
using Elastos::Droid::Text::TextUtils;
using Elastos::Droid::View::CView;
using Elastos::Droid::View::CViewGroupLayoutParams;
using Elastos::Droid::View::EIID_IViewOnClickListener;
using Elastos::Droid::View::IViewGroupLayoutParams;
using Elastos::Droid::View::IViewGroupMarginLayoutParams;
using Elastos::Droid::View::IViewManager;
using Elastos::Droid::Webkit::Webview::Chromium::Base::ApiCompatibilityUtils;
using Elastos::Droid::Webkit::Webview::Chromium::Ui::R;
using Elastos::Droid::Webkit::Webview::Chromium::Ui::ColorSuggestion;
using Elastos::Droid::Widget::CLinearLayout;
using Elastos::Droid::Widget::CLinearLayoutLayoutParams;
using Elastos::Droid::Widget::ILinearLayout;
using Elastos::Droid::Widget::ILinearLayoutLayoutParams;
using Elastos::Core::CString;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Ui {

//=====================================================================
//                      ColorSuggestionListAdapter
//=====================================================================
const Int32 ColorSuggestionListAdapter::COLORS_PER_ROW;

CAR_INTERFACE_IMPL(ColorSuggestionListAdapter, BaseAdapter, IViewOnClickListener)
ColorSuggestionListAdapter::ColorSuggestionListAdapter(
    /* [in] */ IContext* context,
    /* [in] */ ArrayOf<IInterface*>* suggestions)
    : mContext(context)
    , mSuggestions(suggestions)
{
    // ==================before translated======================
    // mContext = context;
    // mSuggestions = suggestions;
}

ECode ColorSuggestionListAdapter::SetOnColorSuggestionClickListener(
    /* [in] */ IOnColorSuggestionClickListener* listener)
{
    VALIDATE_NOT_NULL(listener);
    // ==================before translated======================
    // mListener = listener;

    mListener = listener;
    return NOERROR;
}

ECode ColorSuggestionListAdapter::OnClick(
    /* [in] */ IView* v)
{
    VALIDATE_NOT_NULL(v);
    // ==================before translated======================
    // if (mListener == null) {
    //     return;
    // }
    // ColorSuggestion suggestion = (ColorSuggestion) v.getTag();
    // if (suggestion == null) {
    //     return;
    // }
    // mListener.onColorSuggestionClick(suggestion);

    if (NULL == mListener) {
        return NOERROR;
    }

    AutoPtr<IInterface> interfaceTmp;
    v->GetTag((IInterface**)&interfaceTmp);
    IObject* objectTmp = IObject::Probe(interfaceTmp);
    ColorSuggestion* suggestion = (ColorSuggestion*)objectTmp;
    if (NULL == suggestion) {
        return NOERROR;
    }

    mListener->OnColorSuggestionClick(TO_IINTERFACE(suggestion));
    return NOERROR;
}

ECode ColorSuggestionListAdapter::GetView(
    /* [in] */ Int32 position,
    /* [in] */ IView* convertView,
    /* [in] */ IViewGroup* parent,
    /* [out] */ IView** view)
{
    VALIDATE_NOT_NULL(view);
    // ==================before translated======================
    // LinearLayout layout;
    // if (convertView != null && convertView instanceof LinearLayout) {
    //     layout = (LinearLayout) convertView;
    // } else {
    //     layout = new LinearLayout(mContext);
    //     layout.setLayoutParams(new AbsListView.LayoutParams(
    //             AbsListView.LayoutParams.MATCH_PARENT,
    //             AbsListView.LayoutParams.WRAP_CONTENT));
    //     layout.setOrientation(LinearLayout.HORIZONTAL);
    //     layout.setBackgroundColor(Color.WHITE);
    //     int buttonHeight =
    //         mContext.getResources().getDimensionPixelOffset(R.dimen.color_button_height);
    //     for (int i = 0; i < COLORS_PER_ROW; ++i) {
    //         View button = new View(mContext);
    //         LinearLayout.LayoutParams layoutParams =
    //                 new LinearLayout.LayoutParams(0, buttonHeight, 1f);
    //         ApiCompatibilityUtils.setMarginStart(layoutParams, -1);
    //         if (i == COLORS_PER_ROW - 1) {
    //             ApiCompatibilityUtils.setMarginEnd(layoutParams, -1);
    //         }
    //         button.setLayoutParams(layoutParams);
    //         button.setBackgroundResource(R.drawable.color_button_background);
    //         layout.addView(button);
    //     }
    // }
    // for (int i = 0; i < COLORS_PER_ROW; ++i) {
    //     setUpColorButton(layout.getChildAt(i), position * COLORS_PER_ROW + i);
    // }
    // return layout;

    AutoPtr<ILinearLayout> layout;
    ILinearLayout* maybelinear = ILinearLayout::Probe(convertView);
    if (NULL != convertView && NULL != maybelinear) {
        layout = maybelinear;
    }
    else {
        CLinearLayout::New(mContext, (ILinearLayout**)&layout);
        AutoPtr<IViewGroupLayoutParams> params;
        CViewGroupLayoutParams::New(IViewGroupLayoutParams::MATCH_PARENT, IViewGroupLayoutParams::WRAP_CONTENT, (IViewGroupLayoutParams**)&params);

        IView::Probe(layout)->SetLayoutParams(params);
        layout->SetOrientation(ILinearLayout::HORIZONTAL);
        IView::Probe(layout)->SetBackgroundColor(IColor::WHITE);

        Int32 buttonHeight = 0;
        AutoPtr<IResources> resource;
        mContext->GetResources((IResources**)&resource);
        resource->GetDimensionPixelOffset(R::dimen::color_button_height, &buttonHeight);
        for (Int32 i = 0; i < COLORS_PER_ROW; ++i) {
            AutoPtr<IView> button;
            CView::New(mContext, (IView**)&button);

            AutoPtr<ILinearLayoutLayoutParams> layoutParams;
            CLinearLayoutLayoutParams::New(0, buttonHeight, 1.0f, (ILinearLayoutLayoutParams**)&layoutParams);

            IViewGroupMarginLayoutParams* viewGroupParams = IViewGroupMarginLayoutParams::Probe(layoutParams);
            ApiCompatibilityUtils::SetMarginStart(viewGroupParams, -1);
            if (i == COLORS_PER_ROW - 1) {
                ApiCompatibilityUtils::SetMarginEnd(viewGroupParams, -1);
            }
            IViewGroupLayoutParams* viewGroupLayoutParams = IViewGroupLayoutParams::Probe(layoutParams);
            button->SetLayoutParams(viewGroupLayoutParams);
            button->SetBackgroundResource(R::drawable::color_button_background);
            IViewGroup::Probe(layout)->AddView(button);
        }
    }

    IViewGroup* viewGroup = IViewGroup::Probe(layout);
    for (Int32 i = 0; i < COLORS_PER_ROW; ++i) {
        AutoPtr<IView> child;
        viewGroup->GetChildAt(i, (IView**)&child);
        SetUpColorButton(child, position * COLORS_PER_ROW + i);
    }

    *view = IView::Probe(layout);
    REFCOUNT_ADD(*view);
    return NOERROR;
}

ECode ColorSuggestionListAdapter::GetItemId(
    /* [in] */ Int32 position,
    /* [out] */ Int64* id)
{
    VALIDATE_NOT_NULL(id);
    // ==================before translated======================
    // return position;

    *id = position;
    return NOERROR;
}

ECode ColorSuggestionListAdapter::GetItem(
    /* [in] */ Int32 position,
    /* [out] */ IInterface** item)
{
    VALIDATE_NOT_NULL(item);
    // ==================before translated======================
    // return null;

    *item = NULL;
    return NOERROR;
}

ECode ColorSuggestionListAdapter::GetCount(
    /* [out] */ Int32* count)
{
    VALIDATE_NOT_NULL(count);
    // ==================before translated======================
    // return (mSuggestions.length + COLORS_PER_ROW - 1) / COLORS_PER_ROW;

    *count = (mSuggestions->GetLength() + COLORS_PER_ROW - 1) / COLORS_PER_ROW;
    return NOERROR;
}

ECode ColorSuggestionListAdapter::SetUpColorButton(
    /* [in] */ IView* button,
    /* [in] */ Int32 index)
{
    VALIDATE_NOT_NULL(button);

    IView* viewTmp = IView::Probe(button);
    if (index >= mSuggestions->GetLength()) {
        viewTmp->SetTag(NULL);
        viewTmp->SetContentDescription(NULL);
        button->SetVisibility(IView::INVISIBLE);
        return NOERROR;
    }

    AutoPtr<IInterface> interfaceTmp = (*mSuggestions)[index];
    viewTmp->SetTag(interfaceTmp);
    viewTmp->SetVisibility(IView::VISIBLE);

    ColorSuggestion* suggestion = (ColorSuggestion*)(IObject::Probe((*mSuggestions)[index]));
    AutoPtr<IDrawable> layersTmp;
    viewTmp->GetBackground((IDrawable**)&layersTmp);
    ILayerDrawable* layers = ILayerDrawable::Probe(layersTmp);

    AutoPtr<IDrawable> swatchTmp;
    layers->FindDrawableByLayerId(R::id::color_button_swatch, (IDrawable**)&swatchTmp);
    IGradientDrawable* swatch = IGradientDrawable::Probe(swatchTmp);

    swatch->SetColor(suggestion->mColor);
    String description = suggestion->mLabel;
    if (TextUtils::IsEmpty(description)) {
        description.AppendFormat("#%06X", (0xFFFFFF & suggestion->mColor));
    }

    AutoPtr<ICharSequence> charSequence;
    CString::New(description, (ICharSequence**)&charSequence);
    viewTmp->SetContentDescription(charSequence);
    viewTmp->SetOnClickListener(this);
    return NOERROR;
}

} // namespace Ui
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

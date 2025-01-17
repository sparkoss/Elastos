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

#include "elastos/droid/systemui/statusbar/policy/CDateView.h"
#include "../R.h"
#include <elastos/droid/text/format/DateFormat.h>

using Elastos::Droid::Content::CIntentFilter;
using Elastos::Droid::Content::IIntentFilter;
using Elastos::Droid::Content::Res::IResourcesTheme;
using Elastos::Droid::Text::Format::DateFormat;
using Elastos::Text::CSimpleDateFormat;
using Elastos::Core::CSystem;
using Elastos::Core::CString;
using Elastos::Core::ICharSequence;
using Elastos::Core::ISystem;
using Elastos::Utility::CDate;
using Elastos::Utility::CLocaleHelper;
using Elastos::Utility::ILocaleHelper;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace StatusBar {
namespace Policy {

CDateView::DateViewBroadcastReceiver::DateViewBroadcastReceiver(
    /* [in] */ CDateView* host)
    : mHost(host)
{}

ECode CDateView::DateViewBroadcastReceiver::OnReceive(
    /* [in] */ IContext* context,
    /* [in] */ IIntent* intent)
{
    String action;
    intent->GetAction(&action);
    if (IIntent::ACTION_TIME_TICK.Equals(action)
            || IIntent::ACTION_TIME_CHANGED.Equals(action)
            || IIntent::ACTION_TIMEZONE_CHANGED.Equals(action)
            || IIntent::ACTION_LOCALE_CHANGED.Equals(action)) {
        if (IIntent::ACTION_LOCALE_CHANGED.Equals(action)
                || IIntent::ACTION_TIMEZONE_CHANGED.Equals(action)) {
            // need to get a fresh date format
            mHost->mDateFormat = NULL;
        }
        mHost->UpdateClock();
    }
    return NOERROR;
}

const String CDateView::TAG("DateView");

CAR_INTERFACE_IMPL(CDateView, TextView, IDateView)

CAR_OBJECT_IMPL(CDateView)

CDateView::CDateView()
{
}

ECode CDateView::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IAttributeSet* attrs)
{
    TextView::constructor(context, attrs);

    mIntentReceiver = new DateViewBroadcastReceiver(this);
    CDate::New((IDate**)&mCurrentTime);

    AutoPtr<IResourcesTheme> rt;
    context->GetTheme((IResourcesTheme**)&rt);

    AutoPtr<ArrayOf<Int32> > attrIds = TO_ATTRS_ARRAYOF(R::styleable::DateView);
    AutoPtr<ITypedArray> a;

    rt->ObtainStyledAttributes(attrs, attrIds,
            0, 0, (ITypedArray**)&a);

    // try {
    a->GetString(R::styleable::DateView_datePattern, &mDatePattern);
    // } finally {
    a->Recycle();
    // }
    if (mDatePattern == NULL) {
        AutoPtr<IContext> c;
        GetContext((IContext**)&c);
        c->GetString(R::string::system_ui_date_pattern, &mDatePattern);
    }
    return NOERROR;
}

ECode CDateView::OnAttachedToWindow()
{
    TextView::OnAttachedToWindow();

    AutoPtr<IIntentFilter> filter;
    CIntentFilter::New((IIntentFilter**)&filter);
    filter->AddAction(IIntent::ACTION_TIME_TICK);
    filter->AddAction(IIntent::ACTION_TIME_CHANGED);
    filter->AddAction(IIntent::ACTION_TIMEZONE_CHANGED);
    filter->AddAction(IIntent::ACTION_LOCALE_CHANGED);

    AutoPtr<IContext> c;
    GetContext((IContext**)&c);
    AutoPtr<IIntent> i;
    c->RegisterReceiver(mIntentReceiver, filter, String(NULL), NULL, (IIntent**)&i);

    UpdateClock();
    return NOERROR;
}

ECode CDateView::OnDetachedFromWindow()
{
    TextView::OnDetachedFromWindow();

    mDateFormat = NULL; // reload the locale next time
    AutoPtr<IContext> c;
    GetContext((IContext**)&c);
    c->UnregisterReceiver(mIntentReceiver);
    return NOERROR;
}

void CDateView::UpdateClock()
{
    if (mDateFormat == NULL) {
        AutoPtr<ILocaleHelper> helper;
        CLocaleHelper::AcquireSingleton((ILocaleHelper**)&helper);
        AutoPtr<ILocale> l;
        helper->GetDefault((ILocale**)&l);
        String fmt = DateFormat::GetBestDateTimePattern(l, mDatePattern);
        CSimpleDateFormat::New(fmt, l, (ISimpleDateFormat**)&mDateFormat);
    }

    AutoPtr<ISystem> s;
    CSystem::AcquireSingleton((ISystem**)&s);
    Int64 t;
    s->GetCurrentTimeMillis(&t);
    mCurrentTime->SetTime(t);

    String text;
    Elastos::Text::IDateFormat::Probe(mDateFormat)->Format(mCurrentTime, &text);
    if (!text.Equals(mLastText)) {
        AutoPtr<ICharSequence> cs;
        CString::New(text, (ICharSequence**)&cs);
        SetText(cs);
        mLastText = text;
    }
}

}// namespace Policy
}// namespace StatusBar
}// namespace SystemUI
}// namespace Droid
}// namespace Elastos

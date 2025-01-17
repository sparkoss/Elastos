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

#include <Elastos.CoreLibrary.Utility.h>
#include "elastos/droid/webkit/webview/chromium/native/content/browser/input/WeekPicker.h"
#include "elastos/droid/webkit/webview/chromium/native/content/R_Content.h"

using Elastos::Droid::Webkit::Webview::Chromium::Content::R;
using Elastos::Utility::ICalendarHelper;
using Elastos::Utility::CCalendarHelper;
using Elastos::Utility::IDate;
using Elastos::Utility::EIID_IDate;
using Elastos::Utility::ITimeZoneHelper;
using Elastos::Utility::CTimeZoneHelper;
using Elastos::Core::CString;
using Elastos::Core::ISystem;
using Elastos::Core::CSystem;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Content {
namespace Browser {
namespace Input {

WeekPicker::WeekPicker(
    /* [in] */ IContext* context,
    /* [in] */ Double minValue,
    /* [in] */ Double maxValue)
    : TwoFieldDatePicker(context, minValue, maxValue)
{
    AutoPtr<IResources> resources;
    GetResources((IResources**)&resources);
    String str;
    resources->GetString(R::string::accessibility_date_picker_week, &str);
    AutoPtr<ICharSequence> cs;
    CString::New(str, (ICharSequence**)&cs);

    IView::Probe(GetPositionInYearSpinner())->SetContentDescription(cs);

    // initialize to current date
    AutoPtr<ICalendarHelper> helper;
    CCalendarHelper::AcquireSingleton((ICalendarHelper**)&helper);
    AutoPtr<ICalendar> cal;
    AutoPtr<ITimeZoneHelper> timeZoneHelper;
    CTimeZoneHelper::AcquireSingleton((ITimeZoneHelper**)&timeZoneHelper);
    AutoPtr<ITimeZone> timeZome;
    timeZoneHelper->GetTimeZone(String("UTC"), (ITimeZone**)&timeZome);
    helper->GetInstance(timeZome, (ICalendar**)&cal);
    cal->SetFirstDayOfWeek(ICalendar::MONDAY);
    cal->SetMinimalDaysInFirstWeek(4);
    Int64 value;
    AutoPtr<ISystem> system;
    CSystem::AcquireSingleton((ISystem**)&system);
    system->GetCurrentTimeMillis(&value);
    cal->SetTimeInMillis(value);
    Init(GetISOWeekYearForDate(cal), GetWeekForDate(cal), NULL);
}

/**
 * Creates a date object from the |year| and |week|.
 */
AutoPtr<ICalendar> WeekPicker::CreateDateFromWeek(
    /* [in] */ Int32 year,
    /* [in] */ Int32 week)
{
    AutoPtr<ICalendarHelper> helper;
    CCalendarHelper::AcquireSingleton((ICalendarHelper**)&helper);
    AutoPtr<ICalendar> date;
    AutoPtr<ITimeZoneHelper> timeZoneHelper;
    CTimeZoneHelper::AcquireSingleton((ITimeZoneHelper**)&timeZoneHelper);
    AutoPtr<ITimeZone> timeZome;
    timeZoneHelper->GetTimeZone(String("UTC"), (ITimeZone**)&timeZome);
    helper->GetInstance(timeZome, (ICalendar**)&date);
    date->Clear();
    date->SetFirstDayOfWeek(ICalendar::MONDAY);
    date->SetMinimalDaysInFirstWeek(4);
    date->Set(ICalendar::DAY_OF_WEEK, ICalendar::MONDAY);
    date->Set(ICalendar::YEAR, year);
    date->Set(ICalendar::WEEK_OF_YEAR, week);
    return date;
}

/**
 * Creates a date object from the |value| which is milliseconds since epoch.
 */
AutoPtr<ICalendar> WeekPicker::CreateDateFromValue(
    /* [in] */ Double value)
{
    AutoPtr<ICalendarHelper> helper;
    CCalendarHelper::AcquireSingleton((ICalendarHelper**)&helper);
    AutoPtr<ICalendar> date;
    AutoPtr<ITimeZoneHelper> timeZoneHelper;
    CTimeZoneHelper::AcquireSingleton((ITimeZoneHelper**)&timeZoneHelper);
    AutoPtr<ITimeZone> timeZome;
    timeZoneHelper->GetTimeZone(String("UTC"), (ITimeZone**)&timeZome);
    helper->GetInstance(timeZome, (ICalendar**)&date);
    date->Clear();
    date->SetFirstDayOfWeek(ICalendar::MONDAY);
    date->SetMinimalDaysInFirstWeek(4);
    date->SetTimeInMillis((Int64) value);
    return date;
}

//@Override
AutoPtr<ICalendar> WeekPicker::GetDateForValue(
    /* [in] */ Double value)
{
    return WeekPicker::CreateDateFromValue(value);
}

Int32 WeekPicker::GetISOWeekYearForDate(
    /* [in] */ ICalendar* date)
{
    Int32 year;
    date->Get(ICalendar::YEAR, &year);
    Int32 month;
    date->Get(ICalendar::MONTH, &month);
    Int32 week;
    date->Get(ICalendar::WEEK_OF_YEAR, &week);
    if (month == 0 && week > 51) {
        year--;
    }
    else if (month == 11 && week == 1) {
        year++;
    }

    return year;
}

Int32 WeekPicker::GetWeekForDate(
    /* [in] */ ICalendar* date)
{
    Int32 weekOfYear;
    date->Get(ICalendar::WEEK_OF_YEAR, &weekOfYear);
    return weekOfYear;
}

//@Override
ECode WeekPicker::SetCurrentDate(
    /* [in] */ Int32 year,
    /* [in] */ Int32 week)
{
    AutoPtr<ICalendar> date = CreateDateFromWeek(year, week);
    Boolean bBefore, bAfter;
    AutoPtr<IDate> _date = IDate::Probe(date);
    _date->IsBefore(IDate::Probe(GetMinDate()), &bBefore);
    if (bBefore) {
        TwoFieldDatePicker::SetCurrentDate(GetMinDate());
    }
    else if (_date->IsAfter(IDate::Probe(GetMaxDate()), &bAfter), bAfter) {
        TwoFieldDatePicker::SetCurrentDate(GetMaxDate());
    }
    else {
        TwoFieldDatePicker::SetCurrentDate(date);
    }

    return NOERROR;
}

Int32 WeekPicker::GetNumberOfWeeks(
    /* [in] */ Int32 year)
{
    // Create a date in the middle of the year, where the week year matches the year.
    AutoPtr<ICalendar> date = CreateDateFromWeek(year, 20);
    Int32 weekOfYear;
    date->GetActualMaximum(ICalendar::WEEK_OF_YEAR, &weekOfYear);
    return weekOfYear;
}

/**
 * @return The selected year.
 */
//@Override
Int32 WeekPicker::GetYear()
{
    return GetISOWeekYearForDate(GetCurrentDate());
}

/**
 * @return The selected week.
 */
Int32 WeekPicker::GetWeek()
{
    return GetWeekForDate(GetCurrentDate());
}

//@Override
Int32 WeekPicker::GetPositionInYear()
{
    return GetWeek();
}

//@Override
Int32 WeekPicker::GetMaxYear()
{
    return GetISOWeekYearForDate(GetMaxDate());
}

//@Override
Int32 WeekPicker::GetMinYear()
{
    return GetISOWeekYearForDate(GetMinDate());
}

//@Override
Int32 WeekPicker::GetMaxPositionInYear(
    /* [in] */ Int32 year)
{
    if (year == GetISOWeekYearForDate(GetMaxDate())) {
        return GetWeekForDate(GetMaxDate());
    }

    return GetNumberOfWeeks(year);
}

//@Override
Int32 WeekPicker::GetMinPositionInYear(
    /* [in] */ Int32 year)
{
    if (year == GetISOWeekYearForDate(GetMinDate())) {
        return GetWeekForDate(GetMinDate());
    }

    return 1;
}

} // namespace Input
} // namespace Browser
} // namespace Content
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

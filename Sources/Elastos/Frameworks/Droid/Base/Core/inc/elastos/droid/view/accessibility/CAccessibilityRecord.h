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

#ifndef __ELASTOS_DROID_VIEW_ACCESSIBILITY_CACCESSIBILITYRECORD_H__
#define __ELASTOS_DROID_VIEW_ACCESSIBILITY_CACCESSIBILITYRECORD_H__

#include "elastos/droid/ext/frameworkdef.h"
#include "_Elastos_Droid_View_Accessibility_CAccessibilityRecord.h"
#include "elastos/droid/view/accessibility/AccessibilityRecord.h"

namespace Elastos {
namespace Droid {
namespace View {
namespace Accessibility {

CarClass(CAccessibilityRecord)
    , public AccessibilityRecord
{
public:
    CAR_OBJECT_DECL()
};

} // Accessibility
} // View
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_VIEW_ACCESSIBILITY_CACCESSIBILITYRECORD_H__

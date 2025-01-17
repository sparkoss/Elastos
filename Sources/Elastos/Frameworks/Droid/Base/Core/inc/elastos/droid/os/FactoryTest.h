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

#ifndef __ELASTOS_DROID_OS_FACTORY_TEST_H__
#define __ELASTOS_DROID_OS_FACTORY_TEST_H__

#include "elastos/droid/ext/frameworkext.h"

namespace Elastos {
namespace Droid {
namespace Os {

/**
 * Provides support for in-place factory test functions.
 *
 * This class provides a few properties that alter the normal operation of the system
 * during factory testing.
 *
 * {@hide}
 */
class ECO_PUBLIC FactoryTest
{
public:
    static const Int32 FACTORY_TEST_OFF;// = 0;
    static const Int32 FACTORY_TEST_LOW_LEVEL;// = 1;
    static const Int32 FACTORY_TEST_HIGH_LEVEL;// = 2;

    /**
     * Gets the current factory test mode.
     *
     * @return One of: {@link #FACTORY_TEST_OFF}, {@link #FACTORY_TEST_LOW_LEVEL},
     * or {@link #FACTORY_TEST_HIGH_LEVEL}.
     */
    static Int32 GetMode();

    /**
     * When true, long-press on power should immediately cause the device to
     * shut down, without prompting the user.
     */
    static Boolean IsLongPressOnPowerOffEnabled();

private:
    ECO_LOCAL FactoryTest();
    ECO_LOCAL FactoryTest(const FactoryTest&);
};

} // namespace Os
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_OS_FACTORY_TEST_H__

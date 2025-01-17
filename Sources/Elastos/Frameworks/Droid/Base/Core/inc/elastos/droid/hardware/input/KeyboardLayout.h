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

#ifndef __ELASTOS_DROID_HARDWARE_INPUT_KEYBOARDLAYOUT_H__
#define __ELASTOS_DROID_HARDWARE_INPUT_KEYBOARDLAYOUT_H__

#include "Elastos.Droid.Hardware.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Hardware::Input::IKeyboardLayout;
using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;

namespace Elastos {
namespace Droid {
namespace Hardware {
namespace Input {

/**
 * Describes a keyboard layout.
 *
 * @hide
 */
class KeyboardLayout
    : public Object
    , public IKeyboardLayout
    , public IComparable
    , public IParcelable
{
public:
    CAR_INTERFACE_DECL()

    KeyboardLayout();

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ const String& descriptor,
        /* [in] */ const String& label,
        /* [in] */ const String& collection,
        /* [in] */ Int32 priority);

    /**
     * Gets the keyboard layout descriptor, which can be used to retrieve
     * the keyboard layout again later using
     * {@link InputManager#getKeyboardLayout(String)}.
     *
     * @return The keyboard layout descriptor.
     */
    CARAPI GetDescriptor(
        /* [out] */ String* descriptor);

    /**
     * Gets the keyboard layout descriptive label to show in the user interface.
     * @return The keyboard layout descriptive label.
     */
    CARAPI GetLabel(
        /* [out] */ String* label);

    /**
     * Gets the name of the collection to which the keyboard layout belongs.  This is
     * the label of the broadcast receiver or application that provided the keyboard layout.
     * @return The keyboard layout collection name.
     */
    CARAPI GetCollection(
        /* [out] */ String* collection);

    //@Override
    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    //@Override
    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

    //@Override
    CARAPI CompareTo(
        /* [in] */ IInterface* another,
        /* [out] */ Int32* result);

    //@Override
    CARAPI ToString(
        /* [out] */ String* str);

private:
    String mDescriptor;
    String mLabel;
    String mCollection;
    Int32 mPriority;

    // public static final Parcelable.Creator<KeyboardLayout> CREATOR =
    //         new Parcelable.Creator<KeyboardLayout>() {
    //     public KeyboardLayout createFromParcel(Parcel source) {
    //         return new KeyboardLayout(source);
    //     }
    //     public KeyboardLayout[] newArray(int size) {
    //         return new KeyboardLayout[size];
    //     }
    // };
};

} // namespace Input
} // namespace Hardware
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_HARDWARE_INPUT_KEYBOARDLAYOUT_H__

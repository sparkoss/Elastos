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

#ifndef __ELASTOS_DROID_GOOGLE_MMS_PDU_BASE64_H__
#define __ELASTOS_DROID_GOOGLE_MMS_PDU_BASE64_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/core/Object.h"

namespace Elastos {
namespace Droid {
namespace Google {
namespace Mms {
namespace Pdu {

class Base64
    : public Object
{
public:
    // Populating the character arrays
    /**
      * Decodes Base64 data into octects
      *
      * @param base64Data Byte array containing Base64 data
      * @return Array containing decoded data.
      */
    static CARAPI_(AutoPtr<ArrayOf<Byte> >) DecodeBase64(
        /* [in] */ ArrayOf<Byte>* base64Data);

    /**
      * Discards any characters outside of the base64 alphabet, per
      * the requirements on page 25 of RFC 2045 - "Any characters
      * outside of the base64 alphabet are to be ignored in base64
      * encoded data."
      *
      * @param data The base-64 encoded data to groom
      * @return The data, less non-base64 characters (see RFC 2045).
      */
    static CARAPI_(AutoPtr<ArrayOf<Byte> >) DiscardNonBase64(
        /* [in] */ ArrayOf<Byte>* data);

private:
    static CARAPI_(AutoPtr<ArrayOf<Byte> >) MiddleInitBase64alphabet();

    /**
      * Check octect wheter it is a base64 encoding.
      *
      * @param octect to be checked byte
      * @return ture if it is base64 encoding, false otherwise.
      */
    static CARAPI_(Boolean) IsBase64(
        /* [in] */ Byte octect);

public:
    /**
      * Used to get the number of Quadruples.
      */
    static const Int32 FOURBYTE = 4;
    /**
      * Byte used to pad output.
      */
    static const Byte PAD;
    /**
      * The base length.
      */
    static const Int32 BASELENGTH = 255;

private:
    // Create arrays to hold the base64 characters
    static AutoPtr<ArrayOf<Byte> > mBase64Alphabet;
};

} // namespace Pdu
} // namespace Mms
} // namespace Google
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_GOOGLE_MMS_PDU_BASE64_H__


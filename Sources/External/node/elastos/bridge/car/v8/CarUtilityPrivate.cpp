/*
 * Copyright 2010, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ElNode.h"
#include "config.h"

#if ENABLE(CAR_BRIDGE)

#include <wtf/OwnArrayPtr.h>
#include <wtf/PassOwnPtr.h>
#include <wtf/text/CString.h>
#include <wtf/text/StringBuilder.h>

#include "etl/HashSet.h"
#include "elastos.h"

#include "CarInstanceCobjectV8.h"
#include "CarClassCobjectV8.h"
#include "CarMethod.h"

#include "CarNPObjectV8.h"
//#if PLATFORM(ANDROID)
#include "npruntime_impl.h"
#include "npruntime_priv.h"
//#endif // PLATFORM(ANDROID)
#include "CarValueV8.h"

#include "CarUtilityPrivate.h"
#include "CarCallbackProxy.h"

#include <utils/Log.h>

namespace JSC {
namespace Bindings {

WebCore::DOMWindow* getRootObject()
{
    static WebCore::DOMWindow* rootObject = NULL;
    if (!rootObject) {
        rootObject = WebCore::V8Proxy::retrieveWindow(WebCore::V8Proxy::currentContext());
    }
    return rootObject;
}

void convertNPVariantToCarValue(NPVariant value, CarValue* result)
{
    CarDataType carDataType = result->mType;
    NPVariantType type = value.type;

    const char* tmpType = ClassNameFromCarDataType((CarDataType)(result->mType));
    const char* tmpSubType = ClassNameFromCarDataType((CarDataType)(result->mElementType));

    switch (carDataType) {
        case CarDataType_Int16:
            if (type == NPVariantType_Int32) {
                result->mInt16Value = (Elastos::Int16)(NPVARIANT_TO_INT32(value));
            }
            else if (type == NPVariantType_Double) {
                result->mInt16Value = (Elastos::Int16)(NPVARIANT_TO_DOUBLE(value));
            }
            break;
        case CarDataType_Int32:
        {
            // //normal
            // if (type == NPVariantType_Int32) {
            //     result->mInt32Value = (Elastos::Int32)(NPVARIANT_TO_INT32(value));
            // }
            // else if (type == NPVariantType_Double) {
            //     result->mInt32Value = (Elastos::Int32)(NPVARIANT_TO_DOUBLE(value));
            // }
            // break;

            Int32 _value;
            if (type == NPVariantType_Int32) {
                _value = (Elastos::Int32)(NPVARIANT_TO_INT32(value));
            }
            else if (type == NPVariantType_Double) {
                _value = (Elastos::Int32)(NPVARIANT_TO_DOUBLE(value));
            }

            if (result->mTagSetLocalPtr) {
                CarValue* aCarValue = new CarValue();
                CarQuintet* carArray;

                NPObject* object = NPVARIANT_IS_OBJECT(value) ? NPVARIANT_TO_OBJECT(value) : 0;
                NPVariant npvLength;
                bool success = _NPN_GetProperty(0, object, _NPN_GetStringIdentifier("length"), &npvLength);
                if (!success) {
                    // No length property so we don't know how many elements to put into the array.
                    // Treat this as an error.
                    // JSC sends null for an array that is not an array of strings or basic types,
                    // do this also in the unknown length case.
                    break;
                }

                // Convert to null if the length property is not a number.
                if (!NPVARIANT_IS_INT32(npvLength) && !NPVARIANT_IS_DOUBLE(npvLength)) {
                    break;
                }

                // Convert to null if the length property is out of bounds.
                double doubleLength = NPVARIANT_IS_INT32(npvLength) ? NPVARIANT_TO_INT32(npvLength) : NPVARIANT_TO_DOUBLE(npvLength);
                if (doubleLength < 0.0 || doubleLength > INT32_MAX) {
                    break;
                }

                Int32 length = static_cast<Int32>(doubleLength);

                for (Int32 i = 0; i < length; i++) {
                    NPVariant npvValue;
                    _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                    Int32 iVal = 0;
                    if (NPVARIANT_IS_INT32(npvValue)) {
                        if(i == 0)carArray = ArrayOf<Elastos::Int32>::Alloc(length);
                        iVal = NPVARIANT_TO_INT32(npvValue);
                        (*(ArrayOf<Elastos::Int32>**)&carArray)->Set(i,iVal);
                    }
                    else if (NPVARIANT_IS_DOUBLE(npvValue)) {
                        if(i == 0)carArray = ArrayOf<Elastos::Int32>::Alloc(length);
                        iVal = NPVARIANT_TO_DOUBLE(npvValue);
                        (*(ArrayOf<Elastos::Int32>**)&carArray)->Set(i,iVal);
                    }
                    else if (NPVARIANT_IS_STRING(npvValue)) {
                        if(i == 0)carArray = ArrayOf<Elastos::String>::Alloc(length);
                        NPString src = NPVARIANT_TO_STRING(npvValue);
                        Elastos::String* _stringValue;
                        const char* utf8String = strdup(src.UTF8Characters);
                        _stringValue = new Elastos::String(utf8String);
                        Int32 length = _stringValue->GetLength();
                        if( !length ) {
                            *_stringValue = NULL;
                        }
                        (*(ArrayOf<Elastos::String>**)&carArray)->Set(i, *_stringValue);
                    }
                }

                _value = (Int32)carArray;
                result->mInt32Value = _value;
            }
            else {
                result->mInt32Value = _value;
            }

            break;
        }
        case CarDataType_Int64:
            if (type == NPVariantType_Int32) {
                result->mInt64Value = (Elastos::Int64)(NPVARIANT_TO_INT32(value));
            }
            else if (type == NPVariantType_Double) {
                result->mInt64Value = (Elastos::Int64)(NPVARIANT_TO_DOUBLE(value));
            }
            break;
        case CarDataType_Byte:
            if (type == NPVariantType_Int32) {
                result->mByteValue = (Elastos::Byte)(NPVARIANT_TO_INT32(value));
            }
            else if (type == NPVariantType_Double) {
                result->mByteValue = (Elastos::Byte)(NPVARIANT_TO_DOUBLE(value));
            }
            break;
        case CarDataType_Float:
            if (type == NPVariantType_Int32) {
                result->mFloatValue = (Elastos::Float)(NPVARIANT_TO_INT32(value));
            }
            else if (type == NPVariantType_Double) {
                result->mFloatValue = (Elastos::Float)(NPVARIANT_TO_DOUBLE(value));
            }
            break;
        case CarDataType_Double:
            if (type == NPVariantType_Int32) {
                result->mDoubleValue = (Elastos::Double)(NPVARIANT_TO_INT32(value));
            }
            else if (type == NPVariantType_Double) {
                result->mDoubleValue = (Elastos::Double)(NPVARIANT_TO_DOUBLE(value));
            }
            break;
        case CarDataType_Char32:
        {
            NPString src = NPVARIANT_TO_STRING(value);
            result->mCharValue = Elastos::String(src.UTF8Characters).GetChar(0);
            break;
        }
        case CarDataType_String:
        {
#ifdef CONVERT_NULL_TO_EMPTY_STRING
            if (type == NPVariantType_Null) {
                result->mStringValue = "";
            } else
#else
            if (type == NPVariantType_String)
#endif
            {
                NPString src = NPVARIANT_TO_STRING(value);
                result->mStringValue = src.UTF8Characters;

                Int32 length = result->mStringValue.GetLength();
                if( !length ) {
                    result->mStringValue = NULL;
                }
            }
            else if (type == NPVariantType_Int32) {
                result->mStringValue = WTF::String::number(NPVARIANT_TO_INT32(value)).utf8().data();
            }
            else if (type == NPVariantType_Bool) {
                result->mStringValue = NPVARIANT_TO_BOOLEAN(value) ? "TRUE" : "FALSE";
            }
            else if (type == NPVariantType_Double) {
                result->mStringValue = WTF::String::number(NPVARIANT_TO_DOUBLE(value)).utf8().data();
            }
            else if (!NPVARIANT_IS_NULL(value)) {
                result->mStringValue = "undefined";
            }
            break;
        }
        case CarDataType_Boolean:
            if (type == NPVariantType_Bool) {
                result->mBooleanValue = (Elastos::Boolean)NPVARIANT_TO_BOOLEAN(value);
            }
            break;
        case CarDataType_EMuid:
        {
            NPObject* object = NPVARIANT_IS_OBJECT(value) ? NPVARIANT_TO_OBJECT(value) : NULL;
            NPVariant npvValue;
            _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(0), &npvValue);
            result->mIid.mData1 = (Int32)(NPVARIANT_TO_DOUBLE(npvValue));
            _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(1), &npvValue);
            result->mIid.mData2 = (Int16)(NPVARIANT_TO_DOUBLE(npvValue));
            _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(2), &npvValue);
            result->mIid.mData3 = (Int16)(NPVARIANT_TO_DOUBLE(npvValue));
            _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(3), &npvValue);
            object = NPVARIANT_IS_OBJECT(value) ? NPVARIANT_TO_OBJECT(npvValue) : NULL;
            for (Int32 i = 0; i < 8; i++) {
                _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                result->mIid.mData4[i] = (Int8)(NPVARIANT_TO_DOUBLE(npvValue));
            }

            break;
        }
        case CarDataType_EGuid:
        {
            NPObject* objectGuid = NPVARIANT_IS_OBJECT(value) ? NPVARIANT_TO_OBJECT(value) : NULL;
            NPVariant npvValue;
            _NPN_GetProperty(0, objectGuid, _NPN_GetStringIdentifier("mClsid"), &npvValue);
            NPObject* object = NPVARIANT_IS_OBJECT(npvValue) ? NPVARIANT_TO_OBJECT(npvValue) : NULL;
            EMuid& iid = result->mCid.mClsid;
            _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(0), &npvValue);
            iid.mData1 = (Int32)(NPVARIANT_TO_DOUBLE(npvValue));
            _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(1), &npvValue);
            iid.mData2 = (Int16)(NPVARIANT_TO_DOUBLE(npvValue));
            _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(2), &npvValue);
            iid.mData3 = (Int16)(NPVARIANT_TO_DOUBLE(npvValue));
            _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(3), &npvValue);
            object = NPVARIANT_IS_OBJECT(value) ? NPVARIANT_TO_OBJECT(npvValue) : NULL;
            for (Int32 i = 0; i < 8; i++) {
                _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                iid.mData4[i] = (Int8)(NPVARIANT_TO_DOUBLE(npvValue));
            }
            _NPN_GetProperty(0, objectGuid, _NPN_GetStringIdentifier("mUunm"), &npvValue);
            NPString str = NPVARIANT_TO_STRING(npvValue);
            strcpy(result->mCid.mUunm, str.UTF8Characters);
            _NPN_GetProperty(0, objectGuid, _NPN_GetStringIdentifier("mCarcode"), &npvValue);
            result->mCid.mCarcode = (Int32)(NPVARIANT_TO_DOUBLE(npvValue));

            break;
        }
        case CarDataType_ECode:
        {
            if (type == NPVariantType_Int32) {
                result->mECodeValue = (Elastos::UInt32)(NPVARIANT_TO_INT32(value));
            }
            else if (type == NPVariantType_Double) {
                result->mECodeValue = (Elastos::UInt32)(NPVARIANT_TO_DOUBLE(value));
            }
            break;
        }
        case CarDataType_Enum:
            if (type == NPVariantType_Int32) {
                result->mEnumValue = (Elastos::Int32)(NPVARIANT_TO_INT32(value));
            }
            else if (type == NPVariantType_Double) {
                result->mEnumValue = (Elastos::Int32)(NPVARIANT_TO_DOUBLE(value));
            }
            break;
        case CarDataType_ArrayOf:
//#if PLATFORM(ANDROID)
        // If we're converting to an array, see if the NPVariant has a length
        // property. If so, create a JNI array of the relevant length and to get
        // the elements of the NPVariant. When we interpret the JavaValue later,
        // we know that the array is represented as a JNI array.
        //
        // FIXME: This is a hack. We should not be using JNI here. We should
        // represent the JavaValue without JNI.
        {
            NPObject* object = NPVARIANT_IS_OBJECT(value) ? NPVARIANT_TO_OBJECT(value) : 0;

            if (!object) {
                ALOGD("convertNPVariantToCarValue CarDataType_ArrayOf 1 error: no input object parameter");
                return;
            }

            NPVariant npvLength;
            bool success = _NPN_GetProperty(0, object, _NPN_GetStringIdentifier("length"), &npvLength);
            if (!success) {
                // No length property so we don't know how many elements to put into the array.
                // Treat this as an error.
                // JSC sends null for an array that is not an array of strings or basic types,
                // do this also in the unknown length case.
                break;
            }

            // Convert to null if the length property is not a number.
            if (!NPVARIANT_IS_INT32(npvLength) && !NPVARIANT_IS_DOUBLE(npvLength)) {
                break;
            }

            // Convert to null if the length property is out of bounds.
            Int32 length = NPVARIANT_IS_INT32(npvLength) ? NPVARIANT_TO_INT32(npvLength) : (Int32)NPVARIANT_TO_DOUBLE(npvLength);
            if (length < 0 || length > INT32_MAX) {
                break;
            }

            CarQuintet* carArray = NULL;
            switch (result->mElementType) {
                case CarDataType_Int16:
                {
                    carArray = ArrayOf<Int16>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Int16 iVal = (Int16)NPVARIANT_TO_DOUBLE(npvValue);
                        reinterpret_cast< ArrayOf<Int16>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);

                    break;
                }
                case CarDataType_Int32:
                {
                    carArray = ArrayOf<Int32>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Int32 iVal = (Int32)NPVARIANT_TO_DOUBLE(npvValue);
                        reinterpret_cast< ArrayOf<Int32>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_Int64:
                {
                    carArray = ArrayOf<Int64>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Int64 iVal = (Int64)NPVARIANT_TO_DOUBLE(npvValue);
                        reinterpret_cast< ArrayOf<Int64>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_Byte:
                {
                    carArray = ArrayOf<Byte>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Byte iVal = (Byte)NPVARIANT_TO_DOUBLE(npvValue);
                        reinterpret_cast< ArrayOf<Byte>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_Char32:
                {
                    carArray = ArrayOf<Char32>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        NPString src = NPVARIANT_TO_STRING(npvValue);
                        Char32 iVal = Elastos::String(src.UTF8Characters).GetChar(0);
                        reinterpret_cast< ArrayOf<Char32>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_Float:
                {
                    carArray = ArrayOf<Float>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Float iVal = (Float)NPVARIANT_TO_DOUBLE(npvValue);
                        reinterpret_cast< ArrayOf<Float>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_Double:
                {
                    carArray = ArrayOf<Double>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Double iVal = (Double)NPVARIANT_TO_DOUBLE(npvValue);
                        reinterpret_cast< ArrayOf<Double>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_String:
                {
                    carArray = ArrayOf<Elastos::String>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        NPString src = NPVARIANT_TO_STRING(npvValue);
                        reinterpret_cast< ArrayOf<Elastos::String>* >(carArray)->Set(i, Elastos::String(src.UTF8Characters));
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_Boolean:
                {
                    carArray = ArrayOf<Boolean>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Boolean iVal = (Boolean)NPVARIANT_TO_BOOLEAN(npvValue);
                        reinterpret_cast< ArrayOf<Boolean>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_EMuid:
                    break;
                case CarDataType_EGuid:
                    break;
                case CarDataType_ECode:
                {
                    carArray = ArrayOf<ECode>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        ECode iVal = (UInt32)NPVARIANT_TO_DOUBLE(npvValue);
                        reinterpret_cast< ArrayOf<ECode>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_Enum:
                {
                    carArray = ArrayOf<Int32>::Alloc(length);

                    // Now iterate over each element and add to the array.
                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Int32 iVal = (Int32)NPVARIANT_TO_DOUBLE(npvValue);
                        reinterpret_cast< ArrayOf<Int32>* >(carArray)->Set(i, iVal);
                    }

                    result->mCarQuintet = carArray;
                    _CarQuintet_AddRef(result->mCarQuintet);
                    break;
                }
                case CarDataType_Interface:
                    break;
                default:
                    break;
            }

            break;
        }
//#endif // PLATFORM(ANDROID)
        case CarDataType_LocalPtr:  //deprecated
        {
            switch (result->mElementType) {
                case CarDataType_Int16:
                {
                    CarValue* aCarValue = new CarValue();
                    aCarValue->mInt16Value = (Elastos::Int16)(NPVARIANT_TO_DOUBLE(value));
                    result->mLocalPtr = aCarValue;
                    break;
                }
                case CarDataType_Int32:
                /*
                //to be used after, as a test, all the Int32 input now is Arrayof, and should translate to Array according to the element type of input js array.
                {
                    //ec = argumentList->SetInputArgumentOfCarArray(i, args[i].pArrayOfInt32Value);
                    CarValue* aCarValue = new CarValue();
                    aCarValue->mInt32Value = (Elastos::Int32)(NPVARIANT_TO_DOUBLE(value));
                    result->mLocalPtr = aCarValue;
                    break;
                }
                */
                case CarDataType_ArrayOf:
                {
                    CarValue* aCarValue = new CarValue();
                    CarQuintet* carArray = NULL;

                    NPObject* object = NPVARIANT_IS_OBJECT(value) ? NPVARIANT_TO_OBJECT(value) : 0;
                    NPVariant npvLength;
                    bool success = _NPN_GetProperty(0, object, _NPN_GetStringIdentifier("length"), &npvLength);
                    if (!success) {
                        // No length property so we don't know how many elements to put into the array.
                        // Treat this as an error.
                        // JSC sends null for an array that is not an array of strings or basic types,
                        // do this also in the unknown length case.
                        break;
                    }

                    // Convert to null if the length property is not a number.
                    if (!NPVARIANT_IS_INT32(npvLength) && !NPVARIANT_IS_DOUBLE(npvLength))
                        break;

                    // Convert to null if the length property is out of bounds.
                    double doubleLength = NPVARIANT_IS_INT32(npvLength) ? NPVARIANT_TO_INT32(npvLength) : NPVARIANT_TO_DOUBLE(npvLength);
                    if (doubleLength < 0.0 || doubleLength > INT32_MAX)
                        break;

                    Int32 length = static_cast<Int32>(doubleLength);

                    for (Int32 i = 0; i < length; i++) {
                        NPVariant npvValue;
                        _NPN_GetProperty(0, object, _NPN_GetIntIdentifier(i), &npvValue);
                        Int32 iVal = 0;
                        if (NPVARIANT_IS_INT32(npvValue)) {
                            if(i == 0)carArray = ArrayOf<Elastos::Int32>::Alloc(length);
                            iVal = NPVARIANT_TO_INT32(npvValue);
                            (*(ArrayOf<Elastos::Int32>**)&carArray)->Set(i,iVal);
                        }
                        else if (NPVARIANT_IS_DOUBLE(npvValue)) {
                            if(i == 0)carArray = ArrayOf<Elastos::Int32>::Alloc(length);
                            iVal = (Int32)NPVARIANT_TO_DOUBLE(npvValue);
                            (*(ArrayOf<Elastos::Int32>**)&carArray)->Set(i,iVal);
                        }
                        else if (NPVARIANT_IS_STRING(npvValue)) {
                            if(i == 0)carArray = ArrayOf<Elastos::String>::Alloc(length);
                            NPString src = NPVARIANT_TO_STRING(npvValue);
                            Elastos::String* _stringValue;
                            _stringValue = new Elastos::String(src.UTF8Characters);

                            Int32 length = _stringValue->GetLength();
                            if( !length ) {
                                *_stringValue = NULL;
                            }
                            //iVal = static_cast<Int32>(NPVARIANT_TO_DOUBLE(npvValue));
                            (*(ArrayOf<Elastos::String>**)&carArray)->Set(i, *_stringValue);
                        }
                    }

                    _CarQuintet_AddRef(carArray);

                    aCarValue->mCarQuintet = carArray;
                    result->mLocalPtr = aCarValue;

                    break;
                }
                case CarDataType_String:
                {
                    //ec = argumentList->SetInputArgumentOfCarArray(i, args[i].pArrayOfInt32Value);
                    break;
                }
                case CarDataType_Interface:
                {
                    //now be used when js transfer a js object as a result to pp value by native callback, just transfer the value to native code, no more need to do.
                    CarValue* aCarValue = new CarValue();
                    aCarValue->mInt32Value = (Elastos::Int32)(NPVARIANT_TO_DOUBLE(value));
                    result->mLocalPtr = aCarValue;
                    break;
                }
                default:
                {
                    ALOGD("=================convertNPVariantToCarValue CarDataType_LocalPtr=========other==============ElementType:%d", result->mElementType);
                    break;
                }
            }

            break;
        }
        case CarDataType_Interface:
        {
            if (type == NPVariantType_Object) {
                NPObject* obj = NPVARIANT_TO_OBJECT(value);
                if (obj->_class == WebCore::npScriptObjectClass) {
                    CarCallbackObject* cb = CarCallbackObject::S_CreateObject(IInterfaceInfo::Probe(result->mObjectWrapper->getDataTypeInfo()), obj);
                    result->mObjectWrapper->setInstance((IObject*)cb);
                }
                else {
                    CarNPObject* carObj = reinterpret_cast<CarNPObject*>(obj);
                    CobjectWrapper* objectWrapper = carObj->mInstance->getInstance();
                    result->mObjectWrapper = objectWrapper;
                }
            }
            else {
                ALOGD("=================convertNPVariantToCarValue CarDataType_Interface===========TODO:the value is not a car or js object");
            }

            break;
        }
        default :
            break;
    }
}

void convertCarValuesToNPVariant_bak(const CarMethod* method, CarValue* values, ArrayOf<Int32>* outParamsPosBuf, NPVariant* result)
{
    VOID_TO_NPVARIANT(*result);

    Int32 length = outParamsPosBuf->GetLength();
    Int32 pos = 0;

    if (length == 0) {
        VOID_TO_NPVARIANT(*result);
    }
    else if (length == 1) {
        pos = (*outParamsPosBuf)[0];
        convertCarValueToNPVariant(values[pos], result);
    }
    else {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();

        v8::Local<v8::Object> pV8Object(v8::Object::New(isolate));

        AutoPtr< ArrayOf<NPVariant> > npvalues = ArrayOf<NPVariant>::Alloc(length);
        for (Int32 i = 0; i < length; i++) {
            pos = (*outParamsPosBuf)[i];

            //convert CarValue to NPVariant
            NPVariant* npvalue = &(*npvalues)[i];
            convertCarValueToNPVariant(values[pos], npvalue);

            //get output parameter name
            const char* paramName = method->parameterAt(pos).utf8().data();
            v8::Local<v8::String> v8Name(v8::String::NewFromUtf8(isolate,paramName));

            //convert NPVarient to V8 viables
            if (npvalue->type == NPVariantType_Null) {
                //TODO:null;
            }
            else if (npvalue->type == NPVariantType_String) {
                NPString src = NPVARIANT_TO_STRING(*npvalue);
                pV8Object->Set(v8Name, v8::String::NewFromUtf8(isolate,src.UTF8Characters));
            }
            else if (npvalue->type == NPVariantType_Int32) {
                pV8Object->Set(v8Name, v8::Int32::New(isolate,NPVARIANT_TO_INT32(*npvalue)));
            }
            else if (npvalue->type == NPVariantType_Bool) {
                pV8Object->Set(v8Name, v8::Boolean::New(isolate,NPVARIANT_TO_BOOLEAN(*npvalue)));
            }
            else if (npvalue->type == NPVariantType_Double) {
                pV8Object->Set(v8Name, v8::Number::New(isolate,NPVARIANT_TO_DOUBLE(*npvalue)));
            }
            else if (!NPVARIANT_IS_NULL(*npvalue)) {
                //TODO:undefined;
            }
        }

        WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);

        pV8NPObject_ret->v8Object.Reset(isolate,pV8Object);
        pV8NPObject_ret->rootObject = getRootObject();
        result->type = NPVariantType_Object;
        result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);
    }
}

//void convertCarValuesToNPVariant(const CarMethod* method, CarValue* values, ArrayOf<Int32>* outParamsPosBuf, Boolean alwaysObject, NPVariant* result)
void convertCarValuesToNPVariant(const CarMethod* method, CarValue* values, ArrayOf<Int32>* outParamsPosBuf, NPVariant* result)
{
    Boolean alwaysObject = false;   //to be finished

    VOID_TO_NPVARIANT(*result);

    Int32 length = outParamsPosBuf->GetLength();
    Int32 pos = 0;

    if (length == 0) {
        VOID_TO_NPVARIANT(*result);
    }
    else if (!alwaysObject && length == 1) {
        pos = (*outParamsPosBuf)[0];
        convertCarValueToNPVariant(values[pos], result);
    }
    else {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        v8::Local<v8::Object> pV8Object(v8::Object::New(isolate));
        AutoPtr< ArrayOf<NPVariant> > npvalues = ArrayOf<NPVariant>::Alloc(length);

        for (Int32 i = 0; i < length; i++) {
            pos = (*outParamsPosBuf)[i];

            //convert CarValue to NPVariant
            NPVariant* npvalue = &(*npvalues)[i];
            convertCarValueToNPVariant(values[pos], npvalue);

            //get output parameter name
            const char* paramName = method->parameterAt(pos).utf8().data();
            v8::Local<v8::String> v8Name(v8::String::NewFromUtf8(isolate,paramName));

            //convert NPVarient to V8 viables
            if (npvalue->type == NPVariantType_Null) {
                //TODO:null;
            }
            else if (npvalue->type == NPVariantType_String) {
                NPString src = NPVARIANT_TO_STRING(*npvalue);
                pV8Object->Set(v8Name, v8::String::NewFromUtf8(isolate,src.UTF8Characters));
            }
            else if (npvalue->type == NPVariantType_Int32) {
                pV8Object->Set(v8Name, v8::Int32::New(isolate,NPVARIANT_TO_INT32(*npvalue)));
            }
            else if (npvalue->type == NPVariantType_Bool) {
                pV8Object->Set(v8Name, v8::Boolean::New(isolate,NPVARIANT_TO_BOOLEAN(*npvalue)));
            }
            else if (npvalue->type == NPVariantType_Double) {
                pV8Object->Set(v8Name, v8::Number::New(isolate,NPVARIANT_TO_DOUBLE(*npvalue)));
            }
            else if (!NPVARIANT_IS_NULL(*npvalue)) {
                //TODO:undefined;
            }
        }

        WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);

        pV8NPObject_ret->v8Object.Reset(isolate,pV8Object);
        pV8NPObject_ret->rootObject = getRootObject();
        result->type = NPVariantType_Object;
        result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);
    }
}

void convertCarValueToNPVariant(CarValue& value, NPVariant* result)
{
    const char* tmpType = ClassNameFromCarDataType((CarDataType)(value.mType));
    const char* tmpSubType = ClassNameFromCarDataType((CarDataType)(value.mElementType));

    VOID_TO_NPVARIANT(*result);

    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    switch (value.mType) {
        case CarDataType_Int16:
            result->type = NPVariantType_Int32;
            result->value.intValue = value.mInt16Value;
            break;
        case CarDataType_Int32:
            result->type = NPVariantType_Int32;
            result->value.intValue = value.mInt32Value;
            break;
        case CarDataType_Int64:
            result->type = NPVariantType_Double;
            result->value.doubleValue = value.mInt64Value;
            break;
        case CarDataType_Byte:
            result->type = NPVariantType_Int32;
            result->value.intValue = value.mByteValue;
            break;
        case CarDataType_Char32:
        {
            AutoPtr<ArrayOf<Char32> > charArray = ArrayOf<Char32>::Alloc(1);
            charArray->Set(0, (Char32)value.mCharValue);
            const char* utf8String = strdup(Elastos::String(*charArray).string());
            STRINGZ_TO_NPVARIANT(utf8String, *result);
            break;
        }
        case CarDataType_Float:
            result->type = NPVariantType_Double;
            result->value.doubleValue = value.mFloatValue;
            break;
        case CarDataType_Double:
            result->type = NPVariantType_Double;
            result->value.doubleValue = value.mDoubleValue;
            break;
        case CarDataType_String:
        {
            // This entire file will likely be removed usptream soon.
            if (value.mStringValue.IsNull()) {
                VOID_TO_NPVARIANT(*result);
                break;
            }
            const char* utf8String = strdup(value.mStringValue.string());
            // The copied string is freed in NPN_ReleaseVariantValue (see npruntime.cpp)
            STRINGZ_TO_NPVARIANT(utf8String, *result);
            break;
        }
        case CarDataType_Boolean:
            result->type = NPVariantType_Bool;
            result->value.boolValue = value.mBooleanValue;
            break;
        case CarDataType_EMuid:
        {
            EMuid& iid = value.mIid;
            v8::Local<v8::Array> v8Array(v8::Array::New(isolate,4));
            v8Array->Set(0, v8::Number::New(isolate,iid.mData1));
            v8Array->Set(1, v8::Number::New(isolate,iid.mData2));
            v8Array->Set(2, v8::Number::New(isolate,iid.mData3));

            v8::Handle<v8::Array> v8Array1(v8::Array::New(isolate,4));
            for(Int32 i = 0; i < 8; i++) {
                v8Array1->Set(i, v8::Number::New(isolate,iid.mData4[i]));
            }
            v8Array->Set(3, v8Array1);

            WebCore::V8NPObject* v8NPObject = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
            v8NPObject->v8Object.Reset(isolate,v8Array);
            v8NPObject->rootObject = getRootObject();

            result->type = NPVariantType_Object;
            result->value.objectValue = _NPN_RetainObject((NPObject*)v8NPObject);

            break;
        }
        case CarDataType_EGuid:
        {
            EMuid& iid = value.mCid.mClsid;

            v8::Local<v8::Array> v8Array(v8::Array::New(isolate,4));
            v8Array->Set(0, v8::Number::New(isolate,iid.mData1));
            v8Array->Set(1, v8::Number::New(isolate,iid.mData2));
            v8Array->Set(2, v8::Number::New(isolate,iid.mData3));
            v8::Handle<v8::Array> v8Array1(v8::Array::New(isolate,4));
            for(Int32 i = 0; i < 8; i++){
                v8Array1->Set(i, v8::Number::New(isolate,iid.mData4[i]));
            }
            v8Array->Set(3, v8Array1);

            v8::Local<v8::Object> v8Object(v8::Object::New(isolate));
            v8Object->Set(v8::String::NewFromUtf8(isolate,"mClsid"), v8Array);
            v8Object->Set(v8::String::NewFromUtf8(isolate,"mUunm"), v8::String::NewFromUtf8(isolate,value.mCid.mUunm));
            v8Object->Set(v8::String::NewFromUtf8(isolate,"mCarcode"), v8::Number::New(isolate,value.mCid.mCarcode));

            WebCore::V8NPObject* v8NPObject = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
            v8NPObject->v8Object.Reset(isolate,v8Object);
            v8NPObject->rootObject = getRootObject();
            result->type = NPVariantType_Object;
            result->value.objectValue = _NPN_RetainObject((NPObject*)v8NPObject);

            break;
        }
        case CarDataType_ECode:
            result->type = NPVariantType_Double;
            result->value.doubleValue = (UInt32)value.mECodeValue;
            break;
        case CarDataType_Enum:
            result->type = NPVariantType_Double;
            result->value.doubleValue = value.mEnumValue;
            break;
        case CarDataType_ArrayOf:
        {
            switch (value.mElementType) {
                case CarDataType_Int16:
                {
                    ArrayOf<Int16>* pArray = reinterpret_cast< ArrayOf<Int16>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Int32::New(isolate,(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Int32:
                {
                    ArrayOf<Int32>* pArray = reinterpret_cast< ArrayOf<Int32>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Int32::New(isolate,(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Int64:
                {
                    ArrayOf<Int64>* pArray = reinterpret_cast< ArrayOf<Int64>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Number::New(isolate,(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Byte:
                {
                    ArrayOf<Byte>* pArray = reinterpret_cast< ArrayOf<Byte>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Int32::New(isolate,(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Char32:
                {
                    ArrayOf<Char32>* pArray = reinterpret_cast< ArrayOf<Char32>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++){
                        AutoPtr<ArrayOf<Char32> > charArray = ArrayOf<Char32>::Alloc(1);
                        charArray->Set(0, (Char32)(*pArray)[i]);
                        const char* utf8String = strdup(Elastos::String(*charArray).string());
                        pV8Array->Set(i, v8::String::NewFromUtf8(isolate,utf8String));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Float:
                {
                    ArrayOf<Float>* pArray = reinterpret_cast< ArrayOf<Float>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Number::New(isolate,(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Double:
                {
                    ArrayOf<Double>* pArray = reinterpret_cast< ArrayOf<Double>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Number::New(isolate,(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_String:
                {
                    ArrayOf<Elastos::String>* pArray = reinterpret_cast< ArrayOf<Elastos::String>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        const char* utf8String = strdup(((*pArray)[i]).string());
                        pV8Array->Set(i, v8::String::NewFromUtf8(isolate,utf8String));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Boolean:
                {
                    ArrayOf<Boolean>* pArray = reinterpret_cast< ArrayOf<Boolean>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Boolean::New(isolate,(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
/*----TODO------------------------------------------------------------
                case CarDataType_EMuid:
                    break;
                case CarDataType_EGuid:
                    break;
----------------------------------------------------------------*/
                case CarDataType_ECode:
                {
                    ArrayOf<ECode>* pArray = reinterpret_cast< ArrayOf<ECode>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Number::New(isolate,(UInt32)(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Enum:
                {
                    ArrayOf<Int32>* pArray = reinterpret_cast< ArrayOf<Int32>* >(value.mCarQuintet);
                    Int32 length = pArray->GetLength();

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        pV8Array->Set(i, v8::Int32::New(isolate,(*pArray)[i]));
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                case CarDataType_Interface:
                {
                    ArrayOf<IInterface*>* pArrayOfPInterface = (ArrayOf<IInterface*>*)value.mCarQuintet;
                    Int32 length = pArrayOfPInterface->GetLength();

                    ArrayOf<NPVariant>* pNPVariantArray = ArrayOf<NPVariant>::Alloc(length);

                    v8::Local<v8::Array> pV8Array(v8::Array::New(isolate,length));
                    for (Int32 i = 0; i < length; i++) {
                        IInterface* tempClassinfo = (*pArrayOfPInterface)[i];

                        NPVariant* tempNPVariant = &(*pNPVariantArray)[i];

                        (*pNPVariantArray)[i].type = NPVariantType_Object;
                        (*pNPVariantArray)[i].value.objectValue = CarInstanceToNPObject(new CarInstanceCobject(new CobjectWrapper(tempClassinfo, NULL), true));

                        v8::Handle<v8::Value> tempV8Object = WebCore::convertNPVariantToV8Object(tempNPVariant, NULL);

                        pV8Array->Set(i, tempV8Object);
                    }

                    WebCore::V8NPObject* pV8NPObject_ret = (WebCore::V8NPObject*)_NPN_CreateObject(NULL, WebCore::npScriptObjectClass);
                    pV8NPObject_ret->v8Object.Reset(isolate,pV8Array);
                    pV8NPObject_ret->rootObject = getRootObject();

                    result->type = NPVariantType_Object;
                    result->value.objectValue = _NPN_RetainObject((NPObject*)pV8NPObject_ret);

                    break;
                }
                default:
                    break;
            }
            break;
        }
        case CarDataType_LocalPtr:  //deprecated
        {
            ArrayOf<Int32>* tempArray2 = reinterpret_cast< ArrayOf<Int32>* >(value.mCarQuintet);

            NPObject tempNPObject;
            //TODO:convert ArrayOf into NPObject
            result->type = NPVariantType_Object;
            result->value.objectValue = &tempNPObject;
            break;
        }
        case CarDataType_Interface:
        {
            result->type = NPVariantType_Object;
            value.mObjectWrapper->setInstance(value.mObjectValue);
            result->value.objectValue = CarInstanceToNPObject(new CarInstanceCobject(value.mObjectWrapper, true));
            break;
        }
        default :
            break;
    }
}

} // namespace Bindings
} // namespace JSC

#endif // ENABLE(JAVA_BRIDGE)
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
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Speech.h"
#include "Elastos.Droid.Os.h"
#include "elastos/droid/webkit/webview/chromium/native/content/browser/SpeechRecognition.h"
#include "elastos/droid/webkit/webview/chromium/native/content/api/SpeechRecognition_dec.h"
#include "elastos/droid/webkit/webview/chromium/native/content/browser/SpeechRecognitionError.h"
#include <elastos/utility/logging/Logger.h>

//using Elastos::Core::IString;
using Elastos::Droid::Content::CIntent;
using Elastos::Droid::Content::CComponentName;
using Elastos::Droid::Content::Pm::IPackageInfo;
using Elastos::Droid::Content::Pm::IPackageItemInfo;
using Elastos::Droid::Content::Pm::EIID_IPackageItemInfo;
using Elastos::Droid::Speech::EIID_IRecognitionListener;
using Elastos::Droid::Speech::CSpeechRecognizerHelper;
using Elastos::Droid::Speech::ISpeechRecognizerHelper;
using Elastos::Utility::IList;
using Elastos::Utility::IIterable;
using Elastos::Utility::IIterator;
using Elastos::Utility::EIID_IIterable;
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Content {
namespace Browser {

//=====================================================================
//                     SpeechRecognition::Listener
//=====================================================================

SpeechRecognition::Listener::Listener(
    /* [in] */ SpeechRecognition* owner)
    : mOwner(owner)
{
}

CAR_INTERFACE_IMPL(SpeechRecognition::Listener, Object, IRecognitionListener);

ECode SpeechRecognition::Listener::OnBeginningOfSpeech()
{
    mOwner->mState = STATE_CAPTURING_SPEECH;
    return mOwner->NativeOnSoundStart(mOwner->mNativeSpeechRecognizerImplAndroid);
}

ECode SpeechRecognition::Listener::OnBufferReceived(
    /* [in] */ ArrayOf<Byte>* buffer)
{
    return NOERROR;
}

ECode SpeechRecognition::Listener::OnEndOfSpeech()
{
    // Ignore onEndOfSpeech in continuous mode to let terminate() take care of ending
    // events. The Android API documentation is vague as to when onEndOfSpeech is called in
    // continuous mode, whereas the Web Speech API defines a stronger semantic on the
    // equivalent (onsoundend) event. Thus, the only way to provide a valid onsoundend
    // event is to trigger it when the last result is received or the session is aborted.
    if (!mOwner->mContinuous) {
        mOwner->NativeOnSoundEnd(mOwner->mNativeSpeechRecognizerImplAndroid);
        // Since Android doesn't have a dedicated event for when audio capture is finished,
        // we fire it after speech has ended.
        mOwner->NativeOnAudioEnd(mOwner->mNativeSpeechRecognizerImplAndroid);
        mOwner->mState = STATE_IDLE;
    }

    return NOERROR;
}

ECode SpeechRecognition::Listener::OnError(
    /* [in] */ Int32 error)
{
    Int32 code = SpeechRecognitionError::NONE;

    // Translate Android SpeechRecognizer errors to Web Speech API errors.
    switch(error) {
        case ISpeechRecognizer::ERROR_AUDIO:
            code = SpeechRecognitionError::AUDIO;
            break;
        case ISpeechRecognizer::ERROR_CLIENT:
            code = SpeechRecognitionError::ABORTED;
            break;
        case ISpeechRecognizer::ERROR_RECOGNIZER_BUSY:
        case ISpeechRecognizer::ERROR_INSUFFICIENT_PERMISSIONS:
            code = SpeechRecognitionError::NOT_ALLOWED;
            break;
        case ISpeechRecognizer::ERROR_NETWORK_TIMEOUT:
        case ISpeechRecognizer::ERROR_NETWORK:
        case ISpeechRecognizer::ERROR_SERVER:
            code = SpeechRecognitionError::NETWORK;
            break;
        case ISpeechRecognizer::ERROR_NO_MATCH:
            code = SpeechRecognitionError::NO_MATCH;
            break;
        case ISpeechRecognizer::ERROR_SPEECH_TIMEOUT:
            code = SpeechRecognitionError::NO_SPEECH;
            break;
        default:
            assert(FALSE);
            return NOERROR;
    }

    return mOwner->Terminate(code);
}

ECode SpeechRecognition::Listener::OnEvent(
    /* [in] */ Int32 event,
    /* [in] */ IBundle* bundle)
{
    return NOERROR;
}

ECode SpeechRecognition::Listener::OnPartialResults(
    /* [in] */ IBundle* bundle)
{
    HandleResults(bundle, TRUE);
    return NOERROR;
}

ECode SpeechRecognition::Listener::OnReadyForSpeech(
    /* [in] */ IBundle* bundle)
{
    mOwner->mState = STATE_AWAITING_SPEECH;
    return mOwner->NativeOnAudioStart(mOwner->mNativeSpeechRecognizerImplAndroid);
}

ECode SpeechRecognition::Listener::OnResults(
    /* [in] */ IBundle* bundle)
{
    HandleResults(bundle, FALSE);
    // We assume that onResults is called only once, at the end of a session, thus we
    // terminate. If one day the recognition provider changes dictation mode behavior to
    // call onResults several times, we should terminate only if (!mContinuous).
    return mOwner->Terminate(SpeechRecognitionError::NONE);
}

ECode SpeechRecognition::Listener::OnRmsChanged(
    /* [in] */ Float rms)
{
    return NOERROR;
}

ECode SpeechRecognition::Listener::HandleResults(
    /* [in] */ IBundle* bundle,
    /* [in] */ Boolean provisional)
{
    if (mOwner->mContinuous && provisional) {
        // In continuous mode, Android's recognizer sends final results as provisional.
        provisional = FALSE;
    }

    AutoPtr<IArrayList> list;
    bundle->GetStringArrayList(
            ISpeechRecognizer::RESULTS_RECOGNITION, (IArrayList**)&list);
    Int32 size;
    list->GetSize(&size);
    //AutoPtr< ArrayOf<IInterface*> > strList = ArrayOf<IInterface*>::Alloc(size);
    AutoPtr< ArrayOf<IInterface*> > oArray;
    //list->ToArray(strList, (ArrayOf<IInterface*>**)&results);
    list->ToArray((ArrayOf<IInterface*>**)&oArray);
    Int32 len = oArray->GetLength();
    AutoPtr<ArrayOf<String> > results = ArrayOf<String>::Alloc(len);
    for(Int32 i = 0; i < len; ++i) {
        ICharSequence* cs = ICharSequence::Probe((*oArray)[i]);
        String str;
        cs->ToString(&str);
        results->Set(i, str);
    }

    AutoPtr< ArrayOf<Float> > scores;
    bundle->GetFloatArray(ISpeechRecognizer::CONFIDENCE_SCORES, (ArrayOf<Float>**)&scores);

    mOwner->NativeOnRecognitionResults(mOwner->mNativeSpeechRecognizerImplAndroid,
                               results,
                               scores,
                               provisional);
    return NOERROR;
}

//=====================================================================
//                          SpeechRecognition
//=====================================================================
const String SpeechRecognition::PROVIDER_PACKAGE_NAME("com.google.android.googlequicksearchbox");
const Int32 SpeechRecognition::PROVIDER_MIN_VERSION;
const Int32 SpeechRecognition::STATE_IDLE;
const Int32 SpeechRecognition::STATE_AWAITING_SPEECH;
const Int32 SpeechRecognition::STATE_CAPTURING_SPEECH;
AutoPtr<IComponentName> SpeechRecognition::sRecognitionProvider;

SpeechRecognition::SpeechRecognition(
    /* [in] */ IContext* context,
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid)
    : mContext(context)
    , mNativeSpeechRecognizerImplAndroid(nativeSpeechRecognizerImplAndroid)
    , mContinuous(FALSE)
{
    mListener = new Listener(this);
    CIntent::New(IRecognizerIntent::ACTION_RECOGNIZE_SPEECH, (IIntent**)&mIntent);

    AutoPtr<ISpeechRecognizerHelper> helper;
    CSpeechRecognizerHelper::AcquireSingleton((ISpeechRecognizerHelper**)&helper);
    if (sRecognitionProvider != NULL) {
        helper->CreateSpeechRecognizer(mContext, sRecognitionProvider, (ISpeechRecognizer**)&mRecognizer);
    }
    else {
        // It is possible to force-enable the speech recognition web platform feature (using a
        // command-line flag) even if initialize() failed to find the PROVIDER_PACKAGE_NAME
        // provider, in which case the first available speech recognition provider is used.
        // Caveat: Continuous mode may not work as expected with a different provider.
        helper->CreateSpeechRecognizer(mContext, (ISpeechRecognizer**)&mRecognizer);
    }

    mRecognizer->SetRecognitionListener(mListener);
}

Boolean SpeechRecognition::Initialize(
    /* [in] */ IContext* context)
{
    AutoPtr<ISpeechRecognizerHelper> helper;
    CSpeechRecognizerHelper::AcquireSingleton((ISpeechRecognizerHelper**)&helper);
    Boolean bFlag;
    helper->IsRecognitionAvailable(context, &bFlag);
    if (!bFlag)
        return FALSE;

    AutoPtr<IPackageManager> pm;
    context->GetPackageManager((IPackageManager**)&pm);
    AutoPtr<IIntent> intent;
    CIntent::New(IRecognitionService::SERVICE_INTERFACE, (IIntent**)&intent);
    AutoPtr<IList> list;
    pm->QueryIntentServices(intent, IPackageManager::GET_SERVICES, (IList**)&list);

    AutoPtr<IIterable> iterable = IIterable::Probe(list);
    AutoPtr<IIterator> iterator;
    iterable->GetIterator((IIterator**)&iterator);
    Boolean bHasNext;
    for (iterator->HasNext(&bHasNext);
         bHasNext; iterator->HasNext(&bHasNext)) {
        AutoPtr<IInterface> resolveObj;
        iterator->GetNext((IInterface**)&resolveObj);
        IResolveInfo* resolve = IResolveInfo::Probe(resolveObj);
        AutoPtr<IServiceInfo> service;
        resolve->GetServiceInfo((IServiceInfo**)&service);

        AutoPtr<IPackageItemInfo> packageItemInfo = IPackageItemInfo::Probe(service);
        String packageName;
        packageItemInfo->GetPackageName(&packageName);
        if (!packageName.Equals(PROVIDER_PACKAGE_NAME))
            continue;

        Int32 versionCode;
        // try {
            AutoPtr<IPackageInfo> packageInfo;
            pm->GetPackageInfo(packageName, 0, (IPackageInfo**)&packageInfo);
            packageInfo->GetVersionCode(&versionCode);
        // } catch (NameNotFoundException e) {
        //     continue;
        // }

        if (versionCode < PROVIDER_MIN_VERSION)
            continue;

        String name;
        packageItemInfo->GetName(&name);
        CComponentName::New(packageName, name, (IComponentName**)&sRecognitionProvider);

        return TRUE;
    }

    // If we reach this point, we failed to find a suitable recognition provider.

    return FALSE;
}

ECode SpeechRecognition::Terminate(
    /* [in] */ Int32 error)
{
    if (mState != STATE_IDLE) {
        if (mState == STATE_CAPTURING_SPEECH) {
            NativeOnSoundEnd(mNativeSpeechRecognizerImplAndroid);
        }
        NativeOnAudioEnd(mNativeSpeechRecognizerImplAndroid);
        mState = STATE_IDLE;
    }

    if (error != SpeechRecognitionError::NONE)
        NativeOnRecognitionError(mNativeSpeechRecognizerImplAndroid, error);

    mRecognizer->Destroy();
    mRecognizer = NULL;
    NativeOnRecognitionEnd(mNativeSpeechRecognizerImplAndroid);
    mNativeSpeechRecognizerImplAndroid = 0;

    return NOERROR;
}

AutoPtr<SpeechRecognition> SpeechRecognition::CreateSpeechRecognition(
    /* [in] */ IContext* context,
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid)
{
    return new SpeechRecognition(context, nativeSpeechRecognizerImplAndroid);
}

ECode SpeechRecognition::StartRecognition(
    /* [in] */ const String& language,
    /* [in] */ Boolean continuous,
    /* [in] */ Boolean interimResults)
{
    if (mRecognizer == NULL)
        return NOERROR;

    mContinuous = continuous;
    mIntent->PutExtra(String("android.speech.extra.DICTATION_MODE"), continuous);
    mIntent->PutExtra(IRecognizerIntent::EXTRA_LANGUAGE, language);
    mIntent->PutExtra(IRecognizerIntent::EXTRA_PARTIAL_RESULTS, interimResults);
    mRecognizer->StartListening(mIntent);

    return NOERROR;
}

ECode SpeechRecognition::AbortRecognition()
{
    if (mRecognizer == NULL)
        return NOERROR;

    mRecognizer->Cancel();
    Terminate(SpeechRecognitionError::ABORTED);

    return NOERROR;
}

ECode SpeechRecognition::StopRecognition()
{
    if (mRecognizer == NULL)
        return NOERROR;

    mContinuous = FALSE;
    mRecognizer->StopListening();

    return NOERROR;
}

ECode SpeechRecognition::NativeOnAudioStart(
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid)
{
    Elastos_SpeechRecognition_nativeOnAudioStart(TO_IINTERFACE(this), nativeSpeechRecognizerImplAndroid);
    return NOERROR;
}

ECode SpeechRecognition::NativeOnSoundStart(
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid)
{
    Elastos_SpeechRecognition_nativeOnSoundStart(TO_IINTERFACE(this), nativeSpeechRecognizerImplAndroid);
    return NOERROR;
}

ECode SpeechRecognition::NativeOnSoundEnd(
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid)
{
    Elastos_SpeechRecognition_nativeOnSoundEnd(TO_IINTERFACE(this), nativeSpeechRecognizerImplAndroid);
    return NOERROR;
}

ECode SpeechRecognition::NativeOnAudioEnd(
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid)
{
    Elastos_SpeechRecognition_nativeOnAudioEnd(TO_IINTERFACE(this), nativeSpeechRecognizerImplAndroid);
    return NOERROR;
}

ECode SpeechRecognition::NativeOnRecognitionResults(
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid,
    /* [in] */ ArrayOf<String>* results,
    /* [in] */ ArrayOf<Float>* scores,
    /* [in] */ Boolean provisional)
{
    Elastos_SpeechRecognition_nativeOnRecognitionResults(TO_IINTERFACE(this),
            nativeSpeechRecognizerImplAndroid, results, scores, provisional);
    return NOERROR;
}

ECode SpeechRecognition::NativeOnRecognitionError(
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid,
    /* [in] */ Int32 error)
{
    Elastos_SpeechRecognition_nativeOnRecognitionError(TO_IINTERFACE(this),
            nativeSpeechRecognizerImplAndroid, error);
    return NOERROR;
}

ECode SpeechRecognition::NativeOnRecognitionEnd(
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid)
{
    Elastos_SpeechRecognition_nativeOnRecognitionEnd(TO_IINTERFACE(this),
            nativeSpeechRecognizerImplAndroid);
    return NOERROR;
}

AutoPtr<IInterface> SpeechRecognition::CreateSpeechRecognition(
    /* [in] */ IInterface* context,
    /* [in] */ Handle64 nativeSpeechRecognizerImplAndroid)
{
    AutoPtr<IContext> c = IContext::Probe(context);
    return TO_IINTERFACE(CreateSpeechRecognition(c, nativeSpeechRecognizerImplAndroid));
}

void SpeechRecognition::StartRecognition(
    /* [in] */ IInterface* obj,
    /* [in] */ const String& language,
    /* [in] */ Boolean continuous,
    /* [in] */ Boolean interimResults)
{
    AutoPtr<SpeechRecognition> mObj = (SpeechRecognition*)(IObject::Probe(obj));
    if (NULL == mObj)
    {
        Logger::E("SpeechRecognition", "SpeechRecognition::StartRecognition, mObj is NULL");
        return;
    }
    mObj->StartRecognition(language, continuous, interimResults);
}

void SpeechRecognition::AbortRecognition(
    /* [in] */ IInterface* obj)
{
    AutoPtr<SpeechRecognition> mObj = (SpeechRecognition*)(IObject::Probe(obj));
    if (NULL == mObj)
    {
        Logger::E("SpeechRecognition", "SpeechRecognition::AbortRecognition, mObj is NULL");
        return;
    }
    mObj->AbortRecognition();
}

void SpeechRecognition::StopRecognition(
    /* [in] */ IInterface* obj)
{
    AutoPtr<SpeechRecognition> mObj = (SpeechRecognition*)(IObject::Probe(obj));
    if (NULL == mObj)
    {
        Logger::E("SpeechRecognition", "SpeechRecognition::StopRecognition, mObj is NULL");
        return;
    }
    mObj->StopRecognition();
}

} // namespace Browser
} // namespace Content
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos


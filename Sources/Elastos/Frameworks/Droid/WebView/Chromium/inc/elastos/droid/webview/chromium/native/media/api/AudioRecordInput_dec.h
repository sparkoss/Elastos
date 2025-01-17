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

//This file is autogenerated for
//    AudioRecordInput.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_AUDIORECORDINPUT_CALLBACK_DEC_HH
#define ELASTOS_AUDIORECORDINPUT_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_AudioRecordInput_nativeCacheDirectBufferAddress(IInterface* caller,Handle64 nativeAudioRecordInputStream,IInterface* buffer);
    extern void Elastos_AudioRecordInput_nativeOnData(IInterface* caller,Handle64 nativeAudioRecordInputStream,Int32 size,Int32 hardwareDelayBytes);
    extern void Elastos_AudioRecordInput_InitCallback(Handle64 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Media {

struct ElaAudioRecordInputCallback
{
    AutoPtr<IInterface> (*elastos_AudioRecordInput_createAudioRecordInput)(Handle64 nativeAudioRecordInputStream, Int32 sampleRate, Int32 channels, Int32 bitsPerSample, Int32 bytesPerBuffer, Boolean usePlatformAEC);
    Boolean (*elastos_AudioRecordInput_open)(IInterface* obj);
    void (*elastos_AudioRecordInput_start)(IInterface* obj);
    void (*elastos_AudioRecordInput_stop)(IInterface* obj);
    void (*elastos_AudioRecordInput_close)(IInterface* obj);
};

void* AudioRecordInput::ElaAudioRecordInputCallback_Init()
{
    static ElaAudioRecordInputCallback sElaAudioRecordInputCallback;

    sElaAudioRecordInputCallback.elastos_AudioRecordInput_createAudioRecordInput = &AudioRecordInput::CreateAudioRecordInput;
    sElaAudioRecordInputCallback.elastos_AudioRecordInput_open = &AudioRecordInput::Open;
    sElaAudioRecordInputCallback.elastos_AudioRecordInput_start = &AudioRecordInput::Start;
    sElaAudioRecordInputCallback.elastos_AudioRecordInput_stop = &AudioRecordInput::Stop;
    sElaAudioRecordInputCallback.elastos_AudioRecordInput_close = &AudioRecordInput::Close;

    Elastos_AudioRecordInput_InitCallback((Handle64)&sElaAudioRecordInputCallback);

    return &sElaAudioRecordInputCallback;
}

static void* sPElaAudioRecordInputCallback = AudioRecordInput::ElaAudioRecordInputCallback_Init();

} // namespace Media
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_AUDIORECORDINPUT_CALLBACK_DEC_HH

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

#ifndef __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_MEDIA_AUDIORECORDINPUT_H__
#define __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_MEDIA_AUDIORECORDINPUT_H__

#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Thread.h>

using Elastos::Droid::Media::IAudioRecord;
using Elastos::Droid::Media::Audiofx::IAcousticEchoCanceler;

using Elastos::Core::Thread;
using Elastos::IO::IByteBuffer;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Media {

// Owned by its native counterpart declared in audio_record_input.h. Refer to
// that class for general comments.
//@JNINamespace("media")
class AudioRecordInput
    : public Object
{
private:
    class AudioRecordThread
        : public Thread
    {
    public:
        AudioRecordThread(
            /* [in] */ AudioRecordInput* owner);

        //@Override
        CARAPI Run();

        CARAPI_(void) JoinRecordThread();

    private:
        AudioRecordInput* mOwner;

        // The "volatile" synchronization technique is discussed here:
        // http://stackoverflow.com/a/106787/299268
        // and more generally in this article:
        // https://www.ibm.com/developerworks/java/library/j-jtp06197/
        volatile Boolean mKeepAlive;
    };

private:
    AudioRecordInput(
        /* [in] */ Handle64 nativeAudioRecordInputStream,
        /* [in] */ Int32 sampleRate,
        /* [in] */ Int32 channels,
        /* [in] */ Int32 bitsPerSample,
        /* [in] */ Int32 bytesPerBuffer,
        /* [in] */ Boolean usePlatformAEC);

    //@CalledByNative return AudioRecordInput
    static CARAPI_(AutoPtr<IInterface>) CreateAudioRecordInput(
        /* [in] */ Handle64 nativeAudioRecordInputStream,
        /* [in] */ Int32 sampleRate,
        /* [in] */ Int32 channels,
        /* [in] */ Int32 bitsPerSample,
        /* [in] */ Int32 bytesPerBuffer,
        /* [in] */ Boolean usePlatformAEC);

    //@SuppressLint("NewApi")
    //@CalledByNative
    CARAPI_(Boolean) Open();

    //@CalledByNative
    CARAPI_(void) Start();

    //@CalledByNative
    CARAPI_(void) Stop();

    //@SuppressLint("NewApi")
    //@CalledByNative
    CARAPI_(void) Close();

    CARAPI_(void) NativeCacheDirectBufferAddress(
        /* [in] */ Handle64 nativeAudioRecordInputStream,
        /* [in] */ IByteBuffer* buffer);

    CARAPI_(void) NativeOnData(
        /* [in] */ Handle64 nativeAudioRecordInputStream,
        /* [in] */ Int32 size,
        /* [in] */ Int32 hardwareDelayBytes);

//callback declare
public:
    static CARAPI_(void*) ElaAudioRecordInputCallback_Init();

    static CARAPI_(Boolean) Open(
        /* [in] */ IInterface* obj);

    static CARAPI_(void) Start(
        /* [in] */ IInterface* obj);

    static CARAPI_(void) Stop(
        /* [in] */ IInterface* obj);

    static CARAPI_(void) Close(
        /* [in] */IInterface* obj);

private:
    static const String TAG;
    // Set to true to enable debug logs. Always check in as false.
    static const Boolean DEBUG;
    // We are unable to obtain a precise measurement of the hardware delay on
    // Android. This is a conservative lower-bound based on measurments. It
    // could surely be tightened with further testing.
    static const Int32 HARDWARE_DELAY_MS = 100;

    const Handle64 mNativeAudioRecordInputStream;
    const Int32 mSampleRate;
    const Int32 mChannels;
    const Int32 mBitsPerSample;
    const Int32 mHardwareDelayBytes;
    const Boolean mUsePlatformAEC;
    AutoPtr<IByteBuffer> mBuffer;
    AutoPtr<IAudioRecord> mAudioRecord;
    AutoPtr<AudioRecordThread> mAudioRecordThread;
    AutoPtr<IAcousticEchoCanceler> mAEC;
};

} // namespace Media
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif//__ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_MEDIA_AUDIORECORDINPUT_H__

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

#ifndef __ELASTOS_DROID_MEDIA_CAUDIOSYSTEM_H__
#define __ELASTOS_DROID_MEDIA_CAUDIOSYSTEM_H__

#include "_Elastos_Droid_Media_CAudioSystem.h"
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Singleton.h>

using Elastos::Utility::IArrayList;

namespace Elastos {
namespace Droid {
namespace Media {

CarClass(CAudioSystem)
    , public Singleton
    , public IAudioSystem
{
public:
    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL()

    CARAPI GetNumStreamTypes(
        /* [out] */ Int32* result);

    /*
     * Sets the microphone mute on or off.
     *
     * @param on set <var>true</var> to mute the microphone;
     *           <var>false</var> to turn mute off
     * @return command completion status see AUDIO_STATUS_OK, see AUDIO_STATUS_ERROR
     */
    CARAPI MuteMicrophone(
        /* [in] */ Boolean on);

    /*
     * Checks whether the microphone mute is on or off.
     *
     * @return true if microphone is muted, false if it's not
     */
    CARAPI IsMicrophoneMuted(
        /* [out] */ Boolean* result);

    /*
     * Checks whether the specified stream type is active.
     *
     * return true if any track playing on this stream is active.
     */
    CARAPI IsStreamActive(
        /* [in] */ Int32 stream,
        /* [in] */ Int32 inPastMs,
        /* [out] */ Boolean* result);

    /*
     * Checks whether the specified stream type is active on a remotely connected device. The notion
     * of what constitutes a remote device is enforced by the audio policy manager of the platform.
     *
     * return true if any track playing on this stream is active on a remote device.
     */
    CARAPI IsStreamActiveRemotely(
        /* [in] */ Int32 stream,
        /* [in] */ Int32 inPastMs,
        /* [out] */ Boolean * result);

    /*
     * Checks whether the specified audio source is active.
     *
     * return true if any recorder using this source is currently recording
     */
    CARAPI IsSourceActive(
        /* [in] */ Int32 source,
        /* [out] */ Boolean* result);

    /*
     * Returns a new unused audio session ID
     */
    CARAPI NewAudioSessionId(
        /* [out] */ Int32* result);

    /*
     * Sets a group generic audio configuration parameters. The use of these parameters
     * are platform dependent, see libaudio
     *
     * param keyValuePairs  list of parameters key value pairs in the form:
     *    key1=value1;key2=value2;...
     */
    CARAPI SetParameters(
        /* [in] */ const String& keyValuePairs);

    /*
     * Gets a group generic audio configuration parameters. The use of these parameters
     * are platform dependent, see libaudio
     *
     * param keys  list of parameters
     * return value: list of parameters key value pairs in the form:
     *    key1=value1;key2=value2;...
     */
    CARAPI GetParameters(
        /* [in] */ const String& keys,
        /* [out] */ String* result);

    /*
     * Registers a callback to be invoked when an error occurs.
     * @param cb the callback to run
     */
    CARAPI SetErrorCallback(
        /* [in] */ IAudioSystemErrorCallback* cb);

    CARAPI GetOutputDeviceName(
        /* [in] */ Int32 device,
        /* [out] */ String* result);

    CARAPI SetDeviceConnectionState(
        /* [in] */ Int32 device,
        /* [in] */ Int32 state,
        /* [in] */ const String& device_address);

    CARAPI GetDeviceConnectionState(
        /* [in] */ Int32 device,
        /* [in] */ const String& device_address,
        /* [out] */ Int32* result);

    CARAPI SetPhoneState(
        /* [in] */ Int32 state,
        /* [out] */ Int32* result);

    CARAPI SetForceUse(
        /* [in] */ Int32 usage,
        /* [in] */ Int32 config);

    CARAPI GetForceUse(
        /* [in] */ Int32 usage,
        /* [out] */ Int32* result);

    CARAPI InitStreamVolume(
        /* [in] */ Int32 stream,
        /* [in] */ Int32 indexMin,
        /* [in] */ Int32 indexMax);

    CARAPI SetStreamVolumeIndex(
        /* [in] */ Int32 stream,
        /* [in] */ Int32 index,
        /* [in] */ Int32 device);

    CARAPI GetStreamVolumeIndex(
        /* [in] */ Int32 stream,
        /* [in] */ Int32 device,
        /* [out] */ Int32* result);

    CARAPI SetMasterVolume(
        /* [in] */ Float value);

    CARAPI GetMasterVolume(
        /* [out] */ Float* result);

    CARAPI SetMasterMute(
        /* [in] */ Boolean mute);

    CARAPI GetMasterMute(
        /* [out] */ Boolean* result);

    CARAPI GetDevicesForStream(
        /* [in] */ Int32 stream,
        /* [out] */ Int32* result);

    // helpers for android.media.AudioManager.getProperty(), see description there for meaning
    CARAPI GetPrimaryOutputSamplingRate(
        /* [out] */ Int32* result);

    CARAPI GetPrimaryOutputFrameCount(
        /* [out] */ Int32* result);

    CARAPI GetOutputLatency(
        /* [in] */ Int32 stream,
        /* [out] */ Int32* result);

    CARAPI SetLowRamDevice(
        /* [in] */ Boolean isLowRamDevice,
        /* [out] */ Int32* result);

    CARAPI CheckAudioFlinger(
        /* [out] */ Int32* result);

    CARAPI ListAudioPorts(
        /* [in] */ IArrayList* ports,
        /* [in] */ ArrayOf<Int32>* generation,
        /* [out] */ Int32* result);

    CARAPI CreateAudioPatch(
        /* [in] */ ArrayOf<IAudioPatch*>* patch,
        /* [in] */ ArrayOf<IAudioPortConfig*>* sources,
        /* [in] */ ArrayOf<IAudioPortConfig*>* sinks,
        /* [out] */ Int32* result);

    CARAPI ReleaseAudioPatch(
        /* [in] */ IAudioPatch* patch,
        /* [out] */ Int32* result);

    CARAPI ListAudioPatches(
        /* [in] */ IArrayList* patches,
        /* [in] */ ArrayOf<Int32>* generation,
        /* [out] */ Int32* result);

    CARAPI SetAudioPortConfig(
        /* [in] */ IAudioPortConfig* config,
        /* [out] */ Int32* result);

    CARAPI GetAudioHwSyncForSession(
        /* [in] */ Int32 sessionId,
        /* [out] */ Int32* result);
};

} // namespace Media
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_MEDIA_CAUDIOSYSTEM_H__

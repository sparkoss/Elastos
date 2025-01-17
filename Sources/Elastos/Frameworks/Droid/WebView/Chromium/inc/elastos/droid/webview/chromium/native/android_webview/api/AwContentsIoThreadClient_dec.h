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
//    AwContentsIoThreadClient.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_AWCONTENTSIOTHREADCLIENT_CALLBACK_DEC_HH
#define ELASTOS_AWCONTENTSIOTHREADCLIENT_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_AwContentsIoThreadClient_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace AndroidWebview {

struct ElaAwContentsIoThreadClientCallback
{
    Int32 (*elastos_AwContentsIoThreadClient_getCacheMode)(IInterface* obj);
    Boolean (*elastos_AwContentsIoThreadClient_shouldBlockContentUrls)(IInterface* obj);
    Boolean (*elastos_AwContentsIoThreadClient_shouldBlockFileUrls)(IInterface* obj);
    Boolean (*elastos_AwContentsIoThreadClient_shouldBlockNetworkLoads)(IInterface* obj);
    Boolean (*elastos_AwContentsIoThreadClient_shouldAcceptThirdPartyCookies)(IInterface* obj);
    void (*elastos_AwContentsIoThreadClient_onDownloadStart)(IInterface* obj, const String& url, const String& userAgent, const String& contentDisposition, const String& mimeType, Int64 contentLength);
    void (*elastos_AwContentsIoThreadClient_newLoginRequest)(IInterface* obj, const String& realm, const String& account, const String& args);
    AutoPtr<IInterface> (*elastos_AwContentsIoThreadClient_shouldInterceptRequest)(IInterface* obj, const String& url, Boolean isMainFrame, Boolean hasUserGesture, const String& method, ArrayOf<String>* requestHeaderNames, ArrayOf<String>* requestHeaderValues);
};

void* AwContentsIoThreadClient::ElaAwContentsIoThreadClientCallback_Init()
{
    static ElaAwContentsIoThreadClientCallback sElaAwContentsIoThreadClientCallback;

    sElaAwContentsIoThreadClientCallback.elastos_AwContentsIoThreadClient_getCacheMode = &AwContentsIoThreadClient::GetCacheMode;
    sElaAwContentsIoThreadClientCallback.elastos_AwContentsIoThreadClient_shouldBlockContentUrls = &AwContentsIoThreadClient::ShouldBlockContentUrls;
    sElaAwContentsIoThreadClientCallback.elastos_AwContentsIoThreadClient_shouldBlockFileUrls = &AwContentsIoThreadClient::ShouldBlockFileUrls;
    sElaAwContentsIoThreadClientCallback.elastos_AwContentsIoThreadClient_shouldBlockNetworkLoads = &AwContentsIoThreadClient::ShouldBlockNetworkLoads;
    sElaAwContentsIoThreadClientCallback.elastos_AwContentsIoThreadClient_shouldAcceptThirdPartyCookies = &AwContentsIoThreadClient::ShouldAcceptThirdPartyCookies;
    sElaAwContentsIoThreadClientCallback.elastos_AwContentsIoThreadClient_onDownloadStart = &AwContentsIoThreadClient::OnDownloadStart;
    sElaAwContentsIoThreadClientCallback.elastos_AwContentsIoThreadClient_newLoginRequest = &AwContentsIoThreadClient::NewLoginRequest;
    sElaAwContentsIoThreadClientCallback.elastos_AwContentsIoThreadClient_shouldInterceptRequest = &AwContentsIoThreadClient::ShouldInterceptRequest;

    Elastos_AwContentsIoThreadClient_InitCallback((Handle32)&sElaAwContentsIoThreadClientCallback);
    return &sElaAwContentsIoThreadClientCallback;
}

static void* sPElaAwContentsIoThreadClientCallback = AwContentsIoThreadClient::ElaAwContentsIoThreadClientCallback_Init();

} // namespace AndroidWebview
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_AWCONTENTSIOTHREADCLIENT_CALLBACK_DEC_HH

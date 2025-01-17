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

#include "Elastos.Droid.Internal.h"
#include "elastos/droid/internal/telephony/uicc/CsimFileHandler.h"

#include <elastos/utility/logging/Logger.h>

using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Telephony {
namespace Uicc {

//=====================================================================
//                           CsimFileHandler
//=====================================================================
CAR_INTERFACE_IMPL(CsimFileHandler, IccFileHandler, ICsimFileHandler);

const String CsimFileHandler::LOGTAG("CsimFH");

CsimFileHandler::CsimFileHandler()
{
}

ECode CsimFileHandler::constructor(
    /* [in] */ IUiccCardApplication* app,
    /* [in] */ const String& aid,
    /* [in] */ ICommandsInterface* ci)
{
    IccFileHandler::constructor(app, aid, ci);
    return NOERROR;
}

String CsimFileHandler::GetEFPath(
    /* [in] */ Int32 efid)
{
    switch(efid) {
    case EF_SMS:
    case EF_CST:
    case EF_FDN:
    case EF_MSISDN:
    case EF_RUIM_SPN:
    case EF_CSIM_LI:
    case EF_CSIM_MDN:
    case EF_CSIM_IMSIM:
    case EF_CSIM_CDMAHOME:
    case EF_CSIM_EPRL:
    case EF_CSIM_MODEL:
    case EF_MODEL:
    case EF_CSIM_PRL:
    case EF_RUIM_ID:
        return MF_SIM + DF_ADF;
    case EF_CSIM_MSPL:
    case EF_CSIM_MLPL:
        return MF_SIM + DF_TELECOM + DF_MMSS;
    }
    String path = GetCommonIccEFPath(efid);
    if (path.IsNull()) {
        // The EFids in UICC phone book entries are decided by the card manufacturer.
        // So if we don't match any of the cases above and if its a UICC return
        // the global 3g phone book path.
        return MF_SIM + DF_TELECOM + DF_PHONEBOOK;
    }
    return path;
}

ECode CsimFileHandler::Logd(
    /* [in] */ const String& msg)
{
    Logger::D(LOGTAG, msg);
    return NOERROR;
}

ECode CsimFileHandler::Loge(
    /* [in] */ const String& msg)
{
    Logger::E(LOGTAG, msg);
    return NOERROR;
}

} // namespace Uicc
} // namespace Telephony
} // namespace Internal
} // namespace Droid
} // namespace Elastos

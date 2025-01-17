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

#include "elastos/droid/media/tv/CTvContractWatchedPrograms.h"
#include "elastos/droid/media/tv/TvContractWatchedPrograms.h"

namespace Elastos {
namespace Droid {
namespace Media {
namespace Tv {

CAR_SINGLETON_IMPL(CTvContractWatchedPrograms)
CAR_INTERFACE_IMPL(CTvContractWatchedPrograms, Singleton, ITvContractWatchedPrograms);

ECode CTvContractWatchedPrograms::GetCONTENT_URI(
    /* [out] */ IUri** uri)
{
    return TvContractWatchedPrograms::GetCONTENT_URI(uri);
}

} // namespace Tv
} // namespace Media
} // namepsace Droid
} // namespace Elastos

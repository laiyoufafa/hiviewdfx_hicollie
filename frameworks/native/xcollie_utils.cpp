/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "xcollie_utils.h"

namespace OHOS {
namespace HiviewDFX {
uint64_t GetCurrentTickMillseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
}

std::string GetSelfProcName()
{
    constexpr uint16_t READ_SIZE = 128;
    std::ifstream fin;
    fin.open("/proc/self/cmdline", std::ifstream::in);
    if (!fin.is_open()) {
        XCOLLIE_LOGE("fin.is_open() false");
        return "";
    }
    char readStr[READ_SIZE] = {'\0'};
    fin.getline(readStr, READ_SIZE - 1);
    fin.close();
    return std::string(readStr);
}
} // end of HiviewDFX
} // end of OHOS
/*
    Copyright (C) 2020 Yaotian Feng, Codetector<codetector@codetector.cn>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "board.h"
#include "quantum.h"

__attribute__((weak)) void __chibios_override___early_init(void) {
    // Reset / Debug Select Input
    palSetLineMode(LINE_RESET , MODE_DIR_IN | MODE_MODE_PULL_UP | MODE_AD_DIGITAL);
    // ISP TP
    palSetLineMode(LINE_USBISP, MODE_DIR_IN | MODE_MODE_PULL_UP | MODE_AD_DIGITAL);
    // USB
    palSetLineMode(LINE_USBVBUS, MODE_FUNC_ALT1 | MODE_MODE_PULL_UP | MODE_AD_DIGITAL);
    palSetLineMode(LINE_USBCONN, MODE_FUNC_ALT1);
}

__attribute__((weak)) void __chibios_override_boardInit(void) {}


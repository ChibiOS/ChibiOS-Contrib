/*
    Copyright (C) 2023 Westberry Technology Corp., Ltd

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

#include "debug.h"

#define SERIAL_DEBUG_DRIVER SD1
#define SERIAL_DEBUG_BAUND 115200
#define SERIAL_DEBUG_TX_PIN PAL_LINE(GPIOA, 9U)
#define SERIAL_DEBUG_RX_PIN PAL_LINE(GPIOA, 10U)
#define SERIAL_DEBUG_TX_PAL_MODE 7
#define SERIAL_DEBUG_RX_PAL_MODE 7

static SerialConfig serialConfig = {SERIAL_DEBUG_BAUND, 3, 0, 0, 0};

void serial_debug_init(void) {
  
  serialConfig.speed = SERIAL_DEBUG_BAUND;
  palSetPadMode(PAL_PORT(SERIAL_DEBUG_TX_PIN), PAL_PAD(SERIAL_DEBUG_TX_PIN),PAL_MODE_ALTERNATE(SERIAL_DEBUG_TX_PAL_MODE) | PAL_WB32_PUPDR_PULLUP | PAL_WB32_OSPEED_HIGH);
  palSetPadMode(PAL_PORT(SERIAL_DEBUG_RX_PIN), PAL_PAD(SERIAL_DEBUG_RX_PIN),PAL_MODE_ALTERNATE(SERIAL_DEBUG_RX_PAL_MODE) | PAL_WB32_PUPDR_PULLUP | PAL_WB32_OSPEED_HIGH);

  sdStart(&SERIAL_DEBUG_DRIVER, &serialConfig);
}


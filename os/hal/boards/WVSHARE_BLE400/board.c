/*
    Copyright (C) 2015 Fabio Utzig

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

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)
/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */
const PALConfig pal_default_config =
{
  .pads = {
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_OUTPUT_PUSHPULL,            // UART_TX
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,                      // UART_RX
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_OUTPUT_PUSHPULL,            // LED0
    PAL_MODE_OUTPUT_PUSHPULL,            // LED1
    PAL_MODE_OUTPUT_PUSHPULL,            // LED2
    PAL_MODE_OUTPUT_PUSHPULL,            // LED3
    PAL_MODE_OUTPUT_PUSHPULL,            // LED4
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
    PAL_MODE_INPUT,
  },
};
#endif

/**
 * @brief   Early initialization code.
 * @details This initialization is performed just after reset before BSS and
 *          DATA segments initialization.
 */
void __early_init(void)
{
}

/**
 * @brief   Late initialization code.
 * @note    This initialization is performed after BSS and DATA segments
 *          initialization and before invoking the main() function.
 */
void boardInit(void)
{
  //FIXME: not really needed yet
  //NRF_CLOCK->XTALFREQ = 0xff;
  //NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;
  //NRF_CLOCK->TASKS_HFCLKSTART = 1;
  //while (!NRF_CLOCK->EVENTS_HFCLKSTARTED) {}
}

/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)
/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */
const PALConfig pal_default_config = {
  #if SN32_HAS_GPIOA
  {.mode = VAL_GPIOA_MODE, .cfg = VAL_GPIOA_CFG},
  #endif
  #if SN32_HAS_GPIOB
  {.mode = VAL_GPIOB_MODE, .cfg = VAL_GPIOB_CFG},
  #endif
  #if SN32_HAS_GPIOC
  {.mode = VAL_GPIOC_MODE, .cfg = VAL_GPIOC_CFG},
  #endif
  #if SN32_HAS_GPIOD
  {.mode = VAL_GPIOD_MODE, .cfg = VAL_GPIOD_CFG},
  #endif
};
#endif

/**
 * @brief   Early initialization code.
 * @details This initialization must be performed just after stack setup
 *          and before any other initialization.
 */
void __early_init(void) {
  sn32_clock_init();
}

/**
 * @brief   Board-specific initialization code.
 */
void boardInit(void) {

}

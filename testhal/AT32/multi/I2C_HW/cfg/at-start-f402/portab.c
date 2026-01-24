/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2025 HorrorTroll
    ChibiOS - Copyright (C) 2023..2025 Zhaqian

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

/**
 * @file    portab.c
 * @brief   Application portability module code.
 *
 * @addtogroup application_portability
 * @{
 */

#include "hal.h"

#include "portab.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*
 * I2C driver configuration structure.
 */
I2CConfig i2ccfg = {
  AT32_CLKCTRL_DIV(9U)   |
  AT32_CLKCTRL_SCLD(14U) | AT32_CLKCTRL_SDAD(0U)  |
  AT32_CLKCTRL_SCLH(49U) | AT32_CLKCTRL_SCLL(49U),
  0,
  0
};

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void portab_setup(void) {
  palSetLineMode(PAL_LINE(GPIOB, 6U), PAL_MODE_MUX(4) | PAL_AT32_OMODE_OPENDRAIN);
  palSetLineMode(PAL_LINE(GPIOB, 7U), PAL_MODE_MUX(4) | PAL_AT32_OMODE_OPENDRAIN);
}

/** @} */

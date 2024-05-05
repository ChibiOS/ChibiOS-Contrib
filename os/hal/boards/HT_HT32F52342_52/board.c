/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

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

/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */
#if HAL_USE_PAL || defined(__DOXYGEN__)
const PALConfig pal_default_config = {
    // GPIO A
    .setup[0] =
        {
            .DIR    = VAL_GPIOA_DIRCR,
            .INE    = VAL_GPIOA_INER,
            .PU     = VAL_GPIOA_PUR,
            .PD     = VAL_GPIOA_PDR,
            .OD     = VAL_GPIOA_ODR,
            .DRV    = VAL_GPIOA_DRVR,
            .LOCK   = 0x0000,
            .OUT    = 0x0000,
            .CFG[0] = VAL_GPIOA_AFCFGR0,
            .CFG[1] = VAL_GPIOA_AFCFGR1,
        },
    // GPIO B
    .setup[1] =
        {
            .DIR    = VAL_GPIOB_DIRCR,
            .INE    = VAL_GPIOB_INER,
            .PU     = VAL_GPIOB_PUR,
            .PD     = VAL_GPIOB_PDR,
            .OD     = VAL_GPIOB_ODR,
            .DRV    = VAL_GPIOB_DRVR,
            .LOCK   = 0x0000,
            .OUT    = 0x0000,
            .CFG[0] = VAL_GPIOB_AFCFGR0,
            .CFG[1] = VAL_GPIOB_AFCFGR1,
        },
    // GPIO C
    .setup[2] =
        {
            .DIR    = VAL_GPIOC_DIRCR,
            .INE    = VAL_GPIOC_INER,
            .PU     = VAL_GPIOC_PUR,
            .PD     = VAL_GPIOC_PDR,
            .OD     = VAL_GPIOC_ODR,
            .DRV    = VAL_GPIOC_DRVR,
            .LOCK   = 0x0000,
            .OUT    = 0x0000,
            .CFG[0] = VAL_GPIOC_AFCFGR0,
            .CFG[1] = VAL_GPIOC_AFCFGR1,
        },
    // GPIO D
    .setup[3] =
        {
            .DIR    = VAL_GPIOD_DIRCR,
            .INE    = VAL_GPIOD_INER,
            .PU     = VAL_GPIOD_PUR,
            .PD     = VAL_GPIOD_PDR,
            .OD     = VAL_GPIOD_ODR,
            .DRV    = VAL_GPIOD_DRVR,
            .LOCK   = 0x0000,
            .OUT    = 0x0000,
            .CFG[0] = VAL_GPIOD_AFCFGR0,
            .CFG[1] = VAL_GPIOD_AFCFGR1,
        },
    .ESSR[0] = VAL_ESSR0,
    .ESSR[1] = VAL_ESSR1,
};
#endif

/*
 * Early initialization code.
 * This initialization must be performed just after stack setup and before
 * any other initialization.
 */
void __early_init(void) {
    ht32_clock_init();
}

/*
 * Board-specific initialization code.
 */
void boardInit(void) {}

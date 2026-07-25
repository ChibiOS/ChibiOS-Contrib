/*
    ChibiOS - Copyright (C) 2020 Alex Lewontin
    Modifications copyright (C) 2026 Belonit

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
 * @file    NUMAKER_M252SD/board.c
 * @brief   NuMaker-M252SD board source.
 *
 * @addtogroup NUMAKER_M252SD
 * @{
 */

#include "hal.h"

#if HAL_USE_SERIAL == TRUE
#if M251_SERIAL_USE_UART0 == TRUE
#include "M251/stddriver/sys.h"
#endif
#endif

/**
 * @brief   Board-specific initialization code.
 *
 * @init
 */
void boardInit(void) {
#if HAL_USE_PAL == TRUE
  OnboardLED_Init();
#endif

#if HAL_USE_SERIAL == TRUE
#if M251_SERIAL_USE_UART0 == TRUE
  SYS->GPB_MFPH = (SYS->GPB_MFPH &
                   ~(SYS_GPB_MFPH_PB12MFP_Msk |
                     SYS_GPB_MFPH_PB13MFP_Msk)) |
                  SYS_GPB_MFPH_PB12MFP_UART0_RXD |
                  SYS_GPB_MFPH_PB13MFP_UART0_TXD;
#endif
#endif
}

/** @} */

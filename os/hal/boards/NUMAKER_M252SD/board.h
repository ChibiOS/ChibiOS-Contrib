/*
    Copyright (C) 2026 Belonit

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
 * @file    NUMAKER_M252SD/board.h
 * @brief   NuMaker-M252SD board header.
 *
 * @addtogroup NUMAKER_M252SD
 * @{
 */

#ifndef BOARD_H
#define BOARD_H

/*
 * Board identifier.
 */
#define BOARD_NUMAKER_M252SD
#define BOARD_NAME                  "NuMaker-M252SD"

/*
 * Target device.
 */
#if !defined(M252SD2AE)
#define M252SD2AE
#endif

/*
 * The optional target X1 footprint is for a 32 MHz crystal and is not
 * populated by default. Applications using a populated X1 must enable HXT
 * and set M251_HXT_CLK to 32000000UL in mcuconf.h.
 */

/*
 * User-visible board resources confirmed from UM_NuMaker-M252SD Rev 1.00.
 */
#define ONBOARD_LED_LINE            PAL_LINE(PB, 14U)

#define OnboardLED_Init()                                       \
  do {                                                          \
    palSetLine(ONBOARD_LED_LINE);                               \
    palSetLineMode(ONBOARD_LED_LINE, PAL_MODE_OUTPUT_PUSHPULL); \
  } while (false)
#define OnboardLED_On()             palClearLine(ONBOARD_LED_LINE)
#define OnboardLED_Off()            palSetLine(ONBOARD_LED_LINE)
#define OnboardLED_Toggle()         palToggleLine(ONBOARD_LED_LINE)

#define ONBOARD_SERIAL_DRIVER       SD0

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* !defined(_FROM_ASM_) */

#endif /* BOARD_H */

/** @} */

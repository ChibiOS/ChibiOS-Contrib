/*
    ChibiOS - Copyright (C) 2024 Xael South

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

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Board identifier.
 */
#define BOARD_SILABS_EFR32FG23_DK2600A
#define BOARD_NAME "BOARD_SILABS_EFR32FG23_DK2600A"

/*
 * Board frequencies.
 */

#if !defined(EFR32_LFXO_FREQ)
#define EFR32_LFXO_FREQ                 32768UL
#define LFXO_RTC_GAIN_DEFAULT_VALUE     0x02UL  /**< Manually estmated value which gave 32.768 kHz on CLKOUTn pin. */
#define LFXO_RTC_CAPTUNE_DEFAULT_VALUE  0x1CUL  /**< Manually estmated value which gave 32.768 kHz on CLKOUTn pin. */
#endif

#if !defined(EFR32_HFXO_FREQ)
#define EFR32_HFXO_FREQ                 39000000UL
#endif

#if !defined(EFR32_CLKIN0_FREQ)
#define EFR32_CLKIN0_FREQ               0UL
#endif

/* PA5 is BUTTON1. */
#define ESCAPE_HATCH_PORT               GPIO_PORTA
#define ESCAPE_HATCH_PIN                5

/*
 * MCU type as defined in the Silicon Labs header.
 */
#if !defined(EFR32FG23B010F512IM48)
#define EFR32FG23B010F512IM48           1
#endif

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */

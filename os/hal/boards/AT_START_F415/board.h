/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * Setup for a AT-START-F415 board.
 */

/*
 * Board identifier.
 */
#define BOARD_AT_START_F415
#define BOARD_NAME                  "Artery AT-START-F415"

/*
 * Board frequencies.
 */
#define AT32_LEXTCLK                32768
#define AT32_HEXTCLK                8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define AT32F415RC

/*
 * IO pins assignments.
 */
#define GPIOA_ARD_A0                0U
#define GPIOA_ADC1_IN0              0U
#define GPIOA_BUTTON                0U
#define GPIOA_ARD_A1                1U
#define GPIOA_ADC1_IN1              1U
#define GPIOA_ARD_D1                2U
#define GPIOA_USART2_TX             2U
#define GPIOA_ARD_D0                3U
#define GPIOA_USART2_RX             3U
#define GPIOA_ARD_A2                4U
#define GPIOA_ADC1_IN4              4U
#define GPIOA_ARD_D13               5U
#define GPIOA_ARD_D12               6U
#define GPIOA_ARD_D11               7U
#define GPIOA_ARD_D7                8U
#define GPIOA_ARD_D8                9U
#define GPIOA_ARD_D2                10U
#define GPIOA_PIN11                 11U
#define GPIOA_PIN12                 12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_ARD_D10               15U

#define GPIOB_ARD_A3                0U
#define GPIOB_ADC1_IN8              0U
#define GPIOB_PIN1                  1U
#define GPIOB_PIN2                  2U
#define GPIOB_ARD_D3                3U
#define GPIOB_SWO                   3U
#define GPIOB_ARD_D5                4U
#define GPIOB_ARD_D4                5U
#define GPIOB_PIN6                  6U
#define GPIOB_PIN7                  7U
#define GPIOB_ARD_SCL               8U
#define GPIOB_ARD_SDA               9U
#define GPIOB_ARD_D6                10U
#define GPIOB_PIN10                 10U
#define GPIOB_ARD_PB11              11U
#define GPIOB_PIN11                 11U
#define GPIOB_ARD_NSS               12U
#define GPIOB_PIN12                 12U
#define GPIOB_ARD_SCK               13U
#define GPIOB_ARD_MISO              14U
#define GPIOB_ARD_MOSI              15U

#define GPIOC_ARD_A5                0U
#define GPIOC_ADC1_IN10             0U
#define GPIOC_ARD_A4                1U
#define GPIOC_ADC1_IN11             1U
#define GPIOC_LED_RED               2U
#define GPIOC_LED_YELLOW            3U
#define GPIOC_PIN4                  4U
#define GPIOC_LED_GREEN             5U
#define GPIOC_PIN6                  6U
#define GPIOC_ARD_D9                7U
#define GPIOC_PIN8                  8U
#define GPIOC_PIN9                  9U
#define GPIOC_PIN10                 10U
#define GPIOC_PIN11                 11U
#define GPIOC_PIN12                 12U
#define GPIOC_BUTTON                13U
#define GPIOC_PIN14                 14U
#define GPIOC_PIN15                 15U

#define GPIOD_OSC_IN                0U
#define GPIOD_PIN0                  0U
#define GPIOD_OSC_OUT               1U
#define GPIOD_PIN1                  1U
#define GPIOD_PIN2                  2U
#define GPIOD_PIN3                  3U
#define GPIOD_PIN4                  4U
#define GPIOD_PIN5                  5U
#define GPIOD_PIN6                  6U
#define GPIOD_PIN7                  7U
#define GPIOD_PIN8                  8U
#define GPIOD_PIN9                  9U
#define GPIOD_PIN10                 10U
#define GPIOD_PIN11                 11U
#define GPIOD_PIN12                 12U
#define GPIOD_PIN13                 13U
#define GPIOD_PIN14                 14U
#define GPIOD_PIN15                 15U

#define GPIOF_PIN0                  0U
#define GPIOF_PIN1                  1U
#define GPIOF_PIN2                  2U
#define GPIOF_PIN3                  3U
#define GPIOF_PIN4                  4U
#define GPIOF_PIN5                  5U
#define GPIOF_PIN6                  6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_PIN10                 10U
#define GPIOF_PIN11                 11U
#define GPIOF_PIN12                 12U
#define GPIOF_PIN13                 13U
#define GPIOF_PIN14                 14U
#define GPIOF_PIN15                 15U

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with Pull-Up or Pull-Down resistor depending on ODT.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the AT32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up except:
 * PA0  - Normal input              (GPIOA_BUTTON)
 * PA2  - Alternate output          (GPIOA_ARD_D1, GPIOA_USART2_TX)
 * PA3  - Normal input              (GPIOA_ARD_D0, GPIOA_USART2_RX)
 * PA14 - Pull-down input           (GPIOA_SWCLK)
 */
#define VAL_GPIOACFGLR          0x88884B84      /*  PA7...PA0 */
#define VAL_GPIOACFGHR          0x88888888      /* PA15...PA8 */
#define VAL_GPIOAODT            0xFFFFFFFF

/*
 * Port B setup.
 */
#define VAL_GPIOBCFGLR          0x88888888      /*  PB7...PB0 */
#define VAL_GPIOBCFGHR          0x88888888      /* PB15...PB8 */
#define VAL_GPIOBODT            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 * PC2  - Push Pull output          (GPIOC_LED_RED)
 * PC3  - Push Pull output          (GPIOC_LED_YELLOW)
 * PC5  - Push Pull output          (GPIOC_LED_GREEN)
 * PC13 - Normal input              (GPIOC_BUTTON)
 */
#define VAL_GPIOCCFGLR          0x88383388      /*  PC7...PC0 */
#define VAL_GPIOCCFGHR          0x88488888      /* PC15...PC8 */
#define VAL_GPIOCODT            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input              (GPIOD_OSC_IN).
 * PD1  - Normal input              (GPIOD_OSC_OUT).
 */
#define VAL_GPIODCFGLR          0x88888844      /*  PD7...PD0 */
#define VAL_GPIODCFGHR          0x88888888      /* PD15...PD8 */
#define VAL_GPIODODT            0xFFFFFFFF

/*
 * Port F setup.
 */
#define VAL_GPIOFCFGLR          0x88888888      /*  PF7...PF0 */
#define VAL_GPIOFCFGHR          0x88888888      /* PF15...PF8 */
#define VAL_GPIOFODT            0xFFFFFFFF

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

/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio
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

#ifndef _BOARD_H_
#define _BOARD_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for a AT-START-F402 board.
 */

/*
 * Board identifier.
 */
#define BOARD_AT_START_F402
#define BOARD_NAME                  "Artery AT-START-F402"

/*
 * Board oscillators-related settings.
 */
#if !defined(AT32_LEXTCLK)
#define AT32_LEXTCLK                32768
#endif

#if !defined(AT32_HEXTCLK)
#define AT32_HEXTCLK                12000000
#endif

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define AT32F402RC

/*
 * IO pins assignments.
 */
#define GPIOA_BUTTON                0U
#define GPIOA_ARD_A1                1U
#define GPIOA_ARD_D1                2U
#define GPIOA_ARD_D0                3U
#define GPIOA_ARD_A2                4U
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
#define GPIOB_PIN1                  1U
#define GPIOB_PIN2                  2U
#define GPIOB_SWO                   3U
#define GPIOB_ARD_D5                4U
#define GPIOB_ARD_D4                5U
#define GPIOB_PIN6                  6U
#define GPIOB_PIN7                  7U
#define GPIOB_ARD_SCL               8U
#define GPIOB_ARD_SDA               9U
#define GPIOB_ARD_D6                10U
#define GPIOB_PIN11                 11U
#define GPIOB_ARD_NSS               12U
#define GPIOB_ARD_SCK               13U
#define GPIOB_PIN14                 14U
#define GPIOB_PIN15                 15U

#define GPIOC_ARD_A5                0U
#define GPIOC_ARD_A4                1U
#define GPIOC_ARD_MISO              2U
#define GPIOC_ARD_MOSI              3U
#define GPIOC_ARD_PC4               4U
#define GPIOC_PIN5                  5U
#define GPIOC_PIN6                  6U
#define GPIOC_ARD_D9                7U
#define GPIOC_PIN8                  8U
#define GPIOC_PIN9                  9U
#define GPIOC_PIN10                 10U
#define GPIOC_PIN11                 11U
#define GPIOC_PIN12                 12U
#define GPIOC_BUTTON                13U
#define GPIOC_LEXT_IN               14U
#define GPIOC_LEXT_OUT              15U

#define GPIOD_PIN2                  2U

#define GPIOF_HEXT_IN               0U
#define GPIOF_HEXT_OUT              1U
#define GPIOF_LED_RED               4U
#define GPIOF_LED_YELLOW            5U
#define GPIOF_LED_GREEN             6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN11                 11U

/*
 * IO lines assignments.
 */
#define LINE_BUTTON                 PAL_LINE(GPIOA, 0U)
#define LINE_ARD_A1                 PAL_LINE(GPIOA, 1U)
#define LINE_ARD_D1                 PAL_LINE(GPIOA, 2U)
#define LINE_ARD_D0                 PAL_LINE(GPIOA, 3U)
#define LINE_ARD_A2                 PAL_LINE(GPIOA, 4U)
#define LINE_ARD_D13                PAL_LINE(GPIOA, 5U)
#define LINE_ARD_D12                PAL_LINE(GPIOA, 6U)
#define LINE_ARD_D11                PAL_LINE(GPIOA, 7U)
#define LINE_ARD_D7                 PAL_LINE(GPIOA, 8U)
#define LINE_ARD_D8                 PAL_LINE(GPIOA, 9U)
#define LINE_ARD_D2                 PAL_LINE(GPIOA, 10U)
#define LINE_SWDIO                  PAL_LINE(GPIOA, 13U)
#define LINE_SWCLK                  PAL_LINE(GPIOA, 14U)
#define LINE_ARD_D10                PAL_LINE(GPIOA, 15U)
#define LINE_ARD_A3                 PAL_LINE(GPIOB, 0U)
#define LINE_SWO                    PAL_LINE(GPIOB, 3U)
#define LINE_ARD_D5                 PAL_LINE(GPIOB, 4U)
#define LINE_ARD_D4                 PAL_LINE(GPIOB, 5U)
#define LINE_ARD_SCL                PAL_LINE(GPIOB, 8U)
#define LINE_ARD_SDA                PAL_LINE(GPIOB, 9U)
#define LINE_ARD_D6                 PAL_LINE(GPIOB, 10U)
#define LINE_ARD_NSS                PAL_LINE(GPIOB, 12U)
#define LINE_ARD_SCK                PAL_LINE(GPIOB, 13U)
#define LINE_ARD_A5                 PAL_LINE(GPIOC, 0U)
#define LINE_ARD_A4                 PAL_LINE(GPIOC, 1U)
#define LINE_ARD_MISO               PAL_LINE(GPIOC, 2U)
#define LINE_ARD_MOSI               PAL_LINE(GPIOC, 3U)
#define LINE_ARD_PC4                PAL_LINE(GPIOC, 4U)
#define LINE_ARD_D9                 PAL_LINE(GPIOC, 7U)
#define LINE_BUTTON_ALT             PAL_LINE(GPIOC, 13U)
#define LINE_LEXT_IN                PAL_LINE(GPIOC, 14U)
#define LINE_LEXT_OUT               PAL_LINE(GPIOC, 15U)
#define LINE_HEXT_IN                PAL_LINE(GPIOF, 0U)
#define LINE_HEXT_OUT               PAL_LINE(GPIOF, 1U)
#define LINE_LED_RED                PAL_LINE(GPIOF, 4U)
#define LINE_LED_YELLOW             PAL_LINE(GPIOF, 5U)
#define LINE_LED_GREEN              PAL_LINE(GPIOF, 6U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the AT32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_MUX(n)             (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODT_LOW(n)              (0U << (n))
#define PIN_ODT_HIGH(n)             (1U << (n))
#define PIN_OMODE_PUSHPULL(n)       (0U << (n))
#define PIN_OMODE_OPENDRAIN(n)      (1U << (n))
#define PIN_ODRVR_STRONGER(n)       (1U << ((n) * 2U))
#define PIN_ODRVR_MODERATE(n)       (3U << ((n) * 2U))
#define PIN_PULL_FLOATING(n)        (0U << ((n) * 2U))
#define PIN_PULL_PULLUP(n)          (1U << ((n) * 2U))
#define PIN_PULL_PULLDOWN(n)        (2U << ((n) * 2U))
#define PIN_IOMUX_MUX(n, v)         ((v) << (((n) % 8U) * 4U))
#define PIN_WPR_DISABLED(n)         (0U << (n))
#define PIN_WPR_ENABLED(n)          (1U << (n))
#define PIN_HDRV_DISABLED(n)        (0U << (n))
#define PIN_HDRV_ENABLED(n)         (1U << (n))

/*
 * Port A setup.
 *
 * PA0  - BUTTON                    (input floating).
 * PA1  - ARD_A1                    (input pullup).
 * PA2  - ARD_D1                    (input pullup).
 * PA3  - ARD_D0                    (input pullup).
 * PA4  - ARD_A2                    (input pullup).
 * PA5  - ARD_D13                   (input pullup).
 * PA6  - ARD_D12                   (input pullup).
 * PA7  - ARD_D11                   (input pullup).
 * PA8  - ARD_D7                    (input pullup).
 * PA9  - ARD_D8 USART1_TX          (multiplexing 7).
 * PA10 - ARD_D2 USART1_RX          (multiplexing 7).
 * PA11 - PIN11                     (input floating).
 * PA12 - PIN12                     (input floating).
 * PA13 - SWDIO                     (multiplexing 0).
 * PA14 - SWCLK                     (multiplexing 0).
 * PA15 - ARD_D10                   (input pullup).
 */
#define VAL_GPIOA_CFGR              (PIN_MODE_INPUT(GPIOA_BUTTON) |         \
                                     PIN_MODE_INPUT(GPIOA_ARD_A1) |         \
                                     PIN_MODE_INPUT(GPIOA_ARD_D1) |         \
                                     PIN_MODE_INPUT(GPIOA_ARD_D0) |         \
                                     PIN_MODE_INPUT(GPIOA_ARD_A2) |         \
                                     PIN_MODE_INPUT(GPIOA_ARD_D13) |        \
                                     PIN_MODE_INPUT(GPIOA_ARD_D12) |        \
                                     PIN_MODE_INPUT(GPIOA_ARD_D11) |        \
                                     PIN_MODE_INPUT(GPIOA_ARD_D7) |         \
                                     PIN_MODE_MUX(GPIOA_ARD_D8) |           \
                                     PIN_MODE_MUX(GPIOA_ARD_D2) |           \
                                     PIN_MODE_INPUT(GPIOA_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOA_PIN12) |          \
                                     PIN_MODE_MUX(GPIOA_SWDIO) |            \
                                     PIN_MODE_MUX(GPIOA_SWCLK) |            \
                                     PIN_MODE_INPUT(GPIOA_ARD_D10))
#define VAL_GPIOA_OMODE             (PIN_OMODE_PUSHPULL(GPIOA_BUTTON) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_A1) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D1) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D0) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_A2) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D13) |    \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D12) |    \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D11) |    \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D7) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D8) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D2) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_ARD_D10))
#define VAL_GPIOA_ODRVR             (PIN_ODRVR_STRONGER(GPIOA_BUTTON) |     \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_A1) |     \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D1) |     \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D0) |     \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_A2) |     \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D13) |    \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D12) |    \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D11) |    \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D7) |     \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D8) |     \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D2) |     \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN11) |      \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN12) |      \
                                     PIN_ODRVR_STRONGER(GPIOA_SWDIO) |      \
                                     PIN_ODRVR_STRONGER(GPIOA_SWCLK) |      \
                                     PIN_ODRVR_STRONGER(GPIOA_ARD_D10))
#define VAL_GPIOA_PULL              (PIN_PULL_FLOATING(GPIOA_BUTTON) |      \
                                     PIN_PULL_PULLUP(GPIOA_ARD_A1) |        \
                                     PIN_PULL_PULLUP(GPIOA_ARD_D1) |        \
                                     PIN_PULL_PULLUP(GPIOA_ARD_D0) |        \
                                     PIN_PULL_PULLUP(GPIOA_ARD_A2) |        \
                                     PIN_PULL_PULLUP(GPIOA_ARD_D13) |       \
                                     PIN_PULL_PULLUP(GPIOA_ARD_D12) |       \
                                     PIN_PULL_PULLUP(GPIOA_ARD_D11) |       \
                                     PIN_PULL_PULLUP(GPIOA_ARD_D7) |        \
                                     PIN_PULL_FLOATING(GPIOA_ARD_D8) |      \
                                     PIN_PULL_FLOATING(GPIOA_ARD_D2) |      \
                                     PIN_PULL_FLOATING(GPIOA_PIN11) |       \
                                     PIN_PULL_FLOATING(GPIOA_PIN12) |       \
                                     PIN_PULL_PULLUP(GPIOA_SWDIO) |         \
                                     PIN_PULL_PULLDOWN(GPIOA_SWCLK) |       \
                                     PIN_PULL_PULLUP(GPIOA_ARD_D10))
#define VAL_GPIOA_ODT               (PIN_ODT_HIGH(GPIOA_BUTTON) |           \
                                     PIN_ODT_HIGH(GPIOA_ARD_A1) |           \
                                     PIN_ODT_HIGH(GPIOA_ARD_D1) |           \
                                     PIN_ODT_HIGH(GPIOA_ARD_D0) |           \
                                     PIN_ODT_HIGH(GPIOA_ARD_A2) |           \
                                     PIN_ODT_HIGH(GPIOA_ARD_D13) |          \
                                     PIN_ODT_HIGH(GPIOA_ARD_D12) |          \
                                     PIN_ODT_HIGH(GPIOA_ARD_D11) |          \
                                     PIN_ODT_HIGH(GPIOA_ARD_D7) |           \
                                     PIN_ODT_HIGH(GPIOA_ARD_D8) |           \
                                     PIN_ODT_HIGH(GPIOA_ARD_D2) |           \
                                     PIN_ODT_HIGH(GPIOA_PIN11) |            \
                                     PIN_ODT_HIGH(GPIOA_PIN12) |            \
                                     PIN_ODT_HIGH(GPIOA_SWDIO) |            \
                                     PIN_ODT_HIGH(GPIOA_SWCLK) |            \
                                     PIN_ODT_HIGH(GPIOA_ARD_D10))
#define VAL_GPIOA_MUXL              (PIN_IOMUX_MUX(GPIOA_BUTTON, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOA_ARD_A1, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOA_ARD_D1, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOA_ARD_D0, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOA_ARD_A2, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOA_ARD_D13, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOA_ARD_D12, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOA_ARD_D11, 0U))
#define VAL_GPIOA_MUXH              (PIN_IOMUX_MUX(GPIOA_ARD_D7, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOA_ARD_D8, 7U) |      \
                                     PIN_IOMUX_MUX(GPIOA_ARD_D2, 7U) |      \
                                     PIN_IOMUX_MUX(GPIOA_PIN11, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOA_PIN12, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOA_SWDIO, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOA_SWCLK, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOA_ARD_D10, 0U))
#define VAL_GPIOA_HDRV              (PIN_HDRV_DISABLED(GPIOA_BUTTON) |      \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_A1) |      \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D1) |      \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D0) |      \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_A2) |      \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D13) |     \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D12) |     \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D11) |     \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D7) |      \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D8) |      \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D2) |      \
                                     PIN_HDRV_DISABLED(GPIOA_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOA_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOA_SWDIO) |       \
                                     PIN_HDRV_DISABLED(GPIOA_SWCLK) |       \
                                     PIN_HDRV_DISABLED(GPIOA_ARD_D10))

/*
 * Port B setup.
 *
 * PB0  - ARD_A3                    (input pullup).
 * PB1  - PIN1                      (input pullup).
 * PB2  - PIN2                      (input pullup).
 * PB3  - SWO                       (multiplexing 0).
 * PB4  - ARD_D5                    (input pullup).
 * PB5  - ARD_D4                    (input pullup).
 * PB6  - PIN6                      (input pullup).
 * PB7  - PIN7                      (input pullup).
 * PB8  - ARD_SCL                   (input pullup).
 * PB9  - ARD_SDA                   (input pullup).
 * PB10 - ARD_D6                    (input pullup).
 * PB11 - PIN11                     (input pullup).
 * PB12 - ARD_NSS                   (input pullup).
 * PB13 - ARD_SCK                   (input pullup).
 * PB14 - PIN14                     (input pullup).
 * PB15 - PIN15                     (input pullup).
 */
#define VAL_GPIOB_CFGR              (PIN_MODE_INPUT(GPIOB_ARD_A3) |         \
                                     PIN_MODE_INPUT(GPIOB_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN2) |           \
                                     PIN_MODE_MUX(GPIOB_SWO) |              \
                                     PIN_MODE_INPUT(GPIOB_ARD_D5) |         \
                                     PIN_MODE_INPUT(GPIOB_ARD_D4) |         \
                                     PIN_MODE_INPUT(GPIOB_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOB_ARD_SCL) |        \
                                     PIN_MODE_INPUT(GPIOB_ARD_SDA) |        \
                                     PIN_MODE_INPUT(GPIOB_ARD_D6) |         \
                                     PIN_MODE_INPUT(GPIOB_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOB_ARD_NSS) |        \
                                     PIN_MODE_INPUT(GPIOB_ARD_SCK) |        \
                                     PIN_MODE_INPUT(GPIOB_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOB_PIN15))
#define VAL_GPIOB_OMODE             (PIN_OMODE_PUSHPULL(GPIOB_ARD_A3) |     \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_SWO) |        \
                                     PIN_OMODE_PUSHPULL(GPIOB_ARD_D5) |     \
                                     PIN_OMODE_PUSHPULL(GPIOB_ARD_D4) |     \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_ARD_SCL) |    \
                                     PIN_OMODE_PUSHPULL(GPIOB_ARD_SDA) |    \
                                     PIN_OMODE_PUSHPULL(GPIOB_ARD_D6) |     \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOB_ARD_NSS) |    \
                                     PIN_OMODE_PUSHPULL(GPIOB_ARD_SCK) |    \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN14) |      \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN15))
#define VAL_GPIOB_ODRVR             (PIN_ODRVR_STRONGER(GPIOB_ARD_A3) |     \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN1) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN2) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_SWO) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_ARD_D5) |     \
                                     PIN_ODRVR_STRONGER(GPIOB_ARD_D4) |     \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN6) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN7) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_ARD_SCL) |    \
                                     PIN_ODRVR_STRONGER(GPIOB_ARD_SDA) |    \
                                     PIN_ODRVR_STRONGER(GPIOB_ARD_D6) |     \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN11) |      \
                                     PIN_ODRVR_STRONGER(GPIOB_ARD_NSS) |    \
                                     PIN_ODRVR_STRONGER(GPIOB_ARD_SCK) |    \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN14) |      \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN15))
#define VAL_GPIOB_PULL              (PIN_PULL_PULLUP(GPIOB_ARD_A3) |        \
                                     PIN_PULL_PULLUP(GPIOB_PIN1) |          \
                                     PIN_PULL_PULLUP(GPIOB_PIN2) |          \
                                     PIN_PULL_FLOATING(GPIOB_SWO) |         \
                                     PIN_PULL_PULLUP(GPIOB_ARD_D5) |        \
                                     PIN_PULL_PULLUP(GPIOB_ARD_D4) |        \
                                     PIN_PULL_PULLUP(GPIOB_PIN6) |          \
                                     PIN_PULL_PULLUP(GPIOB_PIN7) |          \
                                     PIN_PULL_PULLUP(GPIOB_ARD_SCL) |       \
                                     PIN_PULL_PULLUP(GPIOB_ARD_SDA) |       \
                                     PIN_PULL_PULLUP(GPIOB_ARD_D6) |        \
                                     PIN_PULL_PULLUP(GPIOB_PIN11) |         \
                                     PIN_PULL_PULLUP(GPIOB_ARD_NSS) |       \
                                     PIN_PULL_PULLUP(GPIOB_ARD_SCK) |       \
                                     PIN_PULL_PULLUP(GPIOB_PIN14) |         \
                                     PIN_PULL_PULLUP(GPIOB_PIN15))
#define VAL_GPIOB_ODT               (PIN_ODT_HIGH(GPIOB_ARD_A3) |           \
                                     PIN_ODT_HIGH(GPIOB_PIN1) |             \
                                     PIN_ODT_HIGH(GPIOB_PIN2) |             \
                                     PIN_ODT_HIGH(GPIOB_SWO) |              \
                                     PIN_ODT_HIGH(GPIOB_ARD_D5) |           \
                                     PIN_ODT_HIGH(GPIOB_ARD_D4) |           \
                                     PIN_ODT_HIGH(GPIOB_PIN6) |             \
                                     PIN_ODT_HIGH(GPIOB_PIN7) |             \
                                     PIN_ODT_HIGH(GPIOB_ARD_SCL) |          \
                                     PIN_ODT_HIGH(GPIOB_ARD_SDA) |          \
                                     PIN_ODT_HIGH(GPIOB_ARD_D6) |           \
                                     PIN_ODT_HIGH(GPIOB_PIN11) |            \
                                     PIN_ODT_HIGH(GPIOB_ARD_NSS) |          \
                                     PIN_ODT_HIGH(GPIOB_ARD_SCK) |          \
                                     PIN_ODT_HIGH(GPIOB_PIN14) |            \
                                     PIN_ODT_HIGH(GPIOB_PIN15))
#define VAL_GPIOB_MUXL              (PIN_IOMUX_MUX(GPIOB_ARD_A3, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOB_PIN1, 0U) |        \
                                     PIN_IOMUX_MUX(GPIOB_PIN2, 0U) |        \
                                     PIN_IOMUX_MUX(GPIOB_SWO, 0U) |         \
                                     PIN_IOMUX_MUX(GPIOB_ARD_D5, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOB_ARD_D4, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOB_PIN6, 0U) |        \
                                     PIN_IOMUX_MUX(GPIOB_PIN7, 0U))
#define VAL_GPIOB_MUXH              (PIN_IOMUX_MUX(GPIOB_ARD_SCL, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOB_ARD_SDA, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOB_ARD_D6, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOB_PIN11, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOB_ARD_NSS, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOB_ARD_SCK, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOB_PIN14, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOB_PIN15, 0U))
#define VAL_GPIOB_HDRV              (PIN_HDRV_DISABLED(GPIOB_ARD_A3) |      \
                                     PIN_HDRV_DISABLED(GPIOB_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOB_SWO) |         \
                                     PIN_HDRV_DISABLED(GPIOB_ARD_D5) |      \
                                     PIN_HDRV_DISABLED(GPIOB_ARD_D4) |      \
                                     PIN_HDRV_DISABLED(GPIOB_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOB_ARD_SCL) |     \
                                     PIN_HDRV_DISABLED(GPIOB_ARD_SDA) |     \
                                     PIN_HDRV_DISABLED(GPIOB_ARD_D6) |      \
                                     PIN_HDRV_DISABLED(GPIOB_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOB_ARD_NSS) |     \
                                     PIN_HDRV_DISABLED(GPIOB_ARD_SCK) |     \
                                     PIN_HDRV_DISABLED(GPIOB_PIN14) |       \
                                     PIN_HDRV_DISABLED(GPIOB_PIN15))

/*
 * Port C setup.
 *
 * PC0  - ARD_A5                    (input pullup).
 * PC1  - ARD_A4                    (input pullup).
 * PC2  - ARD_MISO                  (input pullup).
 * PC3  - ARD_MOSI                  (input pullup).
 * PC4  - ARD_PC4                   (input pullup).
 * PC5  - PIN5                      (input pullup).
 * PC6  - PIN6                      (input pullup).
 * PC7  - ARD_D9                    (input pullup).
 * PC8  - PIN8                      (input pullup).
 * PC9  - PIN9                      (input pullup).
 * PC10 - PIN10                     (input pullup).
 * PC11 - PIN11                     (input pullup).
 * PC12 - PIN12                     (input pullup).
 * PC13 - BUTTON                    (input floating).
 * PC14 - LEXT_IN                   (input floating).
 * PC15 - LEXT_OUT                  (input floating).
 */
#define VAL_GPIOC_CFGR              (PIN_MODE_INPUT(GPIOC_ARD_A5) |         \
                                     PIN_MODE_INPUT(GPIOC_ARD_A4) |         \
                                     PIN_MODE_INPUT(GPIOC_ARD_MISO) |       \
                                     PIN_MODE_INPUT(GPIOC_ARD_MOSI) |       \
                                     PIN_MODE_INPUT(GPIOC_ARD_PC4) |        \
                                     PIN_MODE_INPUT(GPIOC_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOC_ARD_D9) |         \
                                     PIN_MODE_INPUT(GPIOC_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOC_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOC_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOC_BUTTON) |         \
                                     PIN_MODE_INPUT(GPIOC_LEXT_IN) |        \
                                     PIN_MODE_INPUT(GPIOC_LEXT_OUT))
#define VAL_GPIOC_OMODE             (PIN_OMODE_PUSHPULL(GPIOC_ARD_A5) |     \
                                     PIN_OMODE_PUSHPULL(GPIOC_ARD_A4) |     \
                                     PIN_OMODE_PUSHPULL(GPIOC_ARD_MISO) |   \
                                     PIN_OMODE_PUSHPULL(GPIOC_ARD_MOSI) |   \
                                     PIN_OMODE_PUSHPULL(GPIOC_ARD_PC4) |    \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN5) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_ARD_D9) |     \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN8) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN9) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN10) |      \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOC_BUTTON) |     \
                                     PIN_OMODE_PUSHPULL(GPIOC_LEXT_IN) |    \
                                     PIN_OMODE_PUSHPULL(GPIOC_LEXT_OUT))
#define VAL_GPIOC_ODRVR             (PIN_ODRVR_STRONGER(GPIOC_ARD_A5) |     \
                                     PIN_ODRVR_STRONGER(GPIOC_ARD_A4) |     \
                                     PIN_ODRVR_STRONGER(GPIOC_ARD_MISO) |   \
                                     PIN_ODRVR_STRONGER(GPIOC_ARD_MOSI) |   \
                                     PIN_ODRVR_STRONGER(GPIOC_ARD_PC4) |    \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN5) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN6) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_ARD_D9) |     \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN8) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN9) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN10) |      \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN11) |      \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN12) |      \
                                     PIN_ODRVR_STRONGER(GPIOC_BUTTON) |     \
                                     PIN_ODRVR_STRONGER(GPIOC_LEXT_IN) |    \
                                     PIN_ODRVR_STRONGER(GPIOC_LEXT_OUT))
#define VAL_GPIOC_PULL              (PIN_PULL_PULLUP(GPIOC_ARD_A5) |        \
                                     PIN_PULL_PULLUP(GPIOC_ARD_A4) |        \
                                     PIN_PULL_PULLUP(GPIOC_ARD_MISO) |      \
                                     PIN_PULL_PULLUP(GPIOC_ARD_MOSI) |      \
                                     PIN_PULL_PULLUP(GPIOC_ARD_PC4) |       \
                                     PIN_PULL_PULLUP(GPIOC_PIN5) |          \
                                     PIN_PULL_PULLUP(GPIOC_PIN6) |          \
                                     PIN_PULL_PULLUP(GPIOC_ARD_D9) |        \
                                     PIN_PULL_PULLUP(GPIOC_PIN8) |          \
                                     PIN_PULL_PULLUP(GPIOC_PIN9) |          \
                                     PIN_PULL_PULLUP(GPIOC_PIN10) |         \
                                     PIN_PULL_PULLUP(GPIOC_PIN11) |         \
                                     PIN_PULL_PULLUP(GPIOC_PIN12) |         \
                                     PIN_PULL_FLOATING(GPIOC_BUTTON) |      \
                                     PIN_PULL_FLOATING(GPIOC_LEXT_IN) |     \
                                     PIN_PULL_FLOATING(GPIOC_LEXT_OUT))
#define VAL_GPIOC_ODT               (PIN_ODT_HIGH(GPIOC_ARD_A5) |           \
                                     PIN_ODT_HIGH(GPIOC_ARD_A4) |           \
                                     PIN_ODT_HIGH(GPIOC_ARD_MISO) |         \
                                     PIN_ODT_HIGH(GPIOC_ARD_MOSI) |         \
                                     PIN_ODT_HIGH(GPIOC_ARD_PC4) |          \
                                     PIN_ODT_HIGH(GPIOC_PIN5) |             \
                                     PIN_ODT_HIGH(GPIOC_PIN6) |             \
                                     PIN_ODT_HIGH(GPIOC_ARD_D9) |           \
                                     PIN_ODT_HIGH(GPIOC_PIN8) |             \
                                     PIN_ODT_HIGH(GPIOC_PIN9) |             \
                                     PIN_ODT_HIGH(GPIOC_PIN10) |            \
                                     PIN_ODT_HIGH(GPIOC_PIN11) |            \
                                     PIN_ODT_HIGH(GPIOC_PIN12) |            \
                                     PIN_ODT_HIGH(GPIOC_BUTTON) |           \
                                     PIN_ODT_HIGH(GPIOC_LEXT_IN) |          \
                                     PIN_ODT_HIGH(GPIOC_LEXT_OUT))
#define VAL_GPIOC_MUXL              (PIN_IOMUX_MUX(GPIOC_ARD_A5, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOC_ARD_A4, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOC_ARD_MISO, 0U) |    \
                                     PIN_IOMUX_MUX(GPIOC_ARD_MOSI, 0U) |    \
                                     PIN_IOMUX_MUX(GPIOC_ARD_PC4, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOC_PIN5, 0U) |        \
                                     PIN_IOMUX_MUX(GPIOC_PIN6, 0U) |        \
                                     PIN_IOMUX_MUX(GPIOC_ARD_D9, 0U))
#define VAL_GPIOC_MUXH              (PIN_IOMUX_MUX(GPIOC_PIN8, 0U) |        \
                                     PIN_IOMUX_MUX(GPIOC_PIN9, 0U) |        \
                                     PIN_IOMUX_MUX(GPIOC_PIN10, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOC_PIN11, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOC_PIN12, 0U) |       \
                                     PIN_IOMUX_MUX(GPIOC_BUTTON, 0U) |      \
                                     PIN_IOMUX_MUX(GPIOC_LEXT_IN, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOC_LEXT_OUT, 0U))
#define VAL_GPIOC_HDRV              (PIN_HDRV_DISABLED(GPIOC_ARD_A5) |      \
                                     PIN_HDRV_DISABLED(GPIOC_ARD_A4) |      \
                                     PIN_HDRV_DISABLED(GPIOC_ARD_MISO) |    \
                                     PIN_HDRV_DISABLED(GPIOC_ARD_MOSI) |    \
                                     PIN_HDRV_DISABLED(GPIOC_ARD_PC4) |     \
                                     PIN_HDRV_DISABLED(GPIOC_PIN5) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOC_ARD_D9) |      \
                                     PIN_HDRV_DISABLED(GPIOC_PIN8) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN9) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN10) |       \
                                     PIN_HDRV_DISABLED(GPIOC_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOC_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOC_BUTTON) |      \
                                     PIN_HDRV_DISABLED(GPIOC_LEXT_IN) |     \
                                     PIN_HDRV_DISABLED(GPIOC_LEXT_OUT))

/*
 * Port D setup.
 *
 * PD2  - PIN2                      (input pullup).
 */
#define VAL_GPIOD_CFGR              (PIN_MODE_INPUT(GPIOD_PIN2))
#define VAL_GPIOD_OMODE             (PIN_OMODE_PUSHPULL(GPIOD_PIN2))
#define VAL_GPIOD_ODRVR             (PIN_ODRVR_STRONGER(GPIOD_PIN2))
#define VAL_GPIOD_PULL              (PIN_PULL_PULLUP(GPIOD_PIN2))
#define VAL_GPIOD_ODT               (PIN_ODT_HIGH(GPIOD_PIN2))
#define VAL_GPIOD_MUXL              (PIN_IOMUX_MUX(GPIOD_PIN2, 0U))
#define VAL_GPIOD_MUXH              0U
#define VAL_GPIOD_HDRV              (PIN_HDRV_DISABLED(GPIOD_PIN2))

/*
 * Port F setup.
 *
 * PF0  - HEXT_IN                   (input floating).
 * PF1  - HEXT_OUT                  (input floating).
 * PF4  - LED_RED                   (output pushpull).
 * PF5  - LED_YELLOW                (output pushpull).
 * PF6  - LED_GREEN                 (output pushpull).
 * PF7  - PIN7                      (input pullup).
 * PF11 - PIN11                     (input pullup).
 */
#define VAL_GPIOF_CFGR              (PIN_MODE_INPUT(GPIOF_HEXT_IN) |        \
                                     PIN_MODE_INPUT(GPIOF_HEXT_OUT) |       \
                                     PIN_MODE_OUTPUT(GPIOF_LED_RED) |       \
                                     PIN_MODE_OUTPUT(GPIOF_LED_YELLOW) |    \
                                     PIN_MODE_OUTPUT(GPIOF_LED_GREEN) |     \
                                     PIN_MODE_INPUT(GPIOF_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN11))
#define VAL_GPIOF_OMODE             (PIN_OMODE_PUSHPULL(GPIOF_HEXT_IN) |    \
                                     PIN_OMODE_PUSHPULL(GPIOF_HEXT_OUT) |   \
                                     PIN_OMODE_PUSHPULL(GPIOF_LED_RED) |    \
                                     PIN_OMODE_PUSHPULL(GPIOF_LED_YELLOW) | \
                                     PIN_OMODE_PUSHPULL(GPIOF_LED_GREEN) |  \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN11))
#define VAL_GPIOF_ODRVR             (PIN_ODRVR_STRONGER(GPIOF_HEXT_IN) |    \
                                     PIN_ODRVR_STRONGER(GPIOF_HEXT_OUT) |   \
                                     PIN_ODRVR_STRONGER(GPIOF_LED_RED) |    \
                                     PIN_ODRVR_STRONGER(GPIOF_LED_YELLOW) | \
                                     PIN_ODRVR_STRONGER(GPIOF_LED_GREEN) |  \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN7) |       \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN11))
#define VAL_GPIOF_PULL              (PIN_PULL_FLOATING(GPIOF_HEXT_IN) |     \
                                     PIN_PULL_FLOATING(GPIOF_HEXT_OUT) |    \
                                     PIN_PULL_FLOATING(GPIOF_LED_RED) |     \
                                     PIN_PULL_FLOATING(GPIOF_LED_YELLOW) |  \
                                     PIN_PULL_FLOATING(GPIOF_LED_GREEN) |   \
                                     PIN_PULL_PULLUP(GPIOF_PIN7) |          \
                                     PIN_PULL_PULLUP(GPIOF_PIN11))
#define VAL_GPIOF_ODT               (PIN_ODT_HIGH(GPIOF_HEXT_IN) |          \
                                     PIN_ODT_HIGH(GPIOF_HEXT_OUT) |         \
                                     PIN_ODT_HIGH(GPIOF_LED_RED) |          \
                                     PIN_ODT_HIGH(GPIOF_LED_YELLOW) |       \
                                     PIN_ODT_HIGH(GPIOF_LED_GREEN) |        \
                                     PIN_ODT_HIGH(GPIOF_PIN7) |             \
                                     PIN_ODT_HIGH(GPIOF_PIN11))
#define VAL_GPIOF_MUXL              (PIN_IOMUX_MUX(GPIOF_HEXT_IN, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOF_HEXT_OUT, 0U) |    \
                                     PIN_IOMUX_MUX(GPIOF_LED_RED, 0U) |     \
                                     PIN_IOMUX_MUX(GPIOF_LED_YELLOW, 0U) |  \
                                     PIN_IOMUX_MUX(GPIOF_LED_GREEN, 0U) |   \
                                     PIN_IOMUX_MUX(GPIOF_PIN7, 0U))
#define VAL_GPIOF_MUXH              (PIN_IOMUX_MUX(GPIOF_PIN11, 0U))
#define VAL_GPIOF_HDRV              (PIN_HDRV_DISABLED(GPIOF_HEXT_IN) |     \
                                     PIN_HDRV_DISABLED(GPIOF_HEXT_OUT) |    \
                                     PIN_HDRV_DISABLED(GPIOF_LED_RED) |     \
                                     PIN_HDRV_DISABLED(GPIOF_LED_YELLOW) |  \
                                     PIN_HDRV_DISABLED(GPIOF_LED_GREEN) |   \
                                     PIN_HDRV_DISABLED(GPIOF_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN11))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

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

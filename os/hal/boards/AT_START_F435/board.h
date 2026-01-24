/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian
    ChibiOS - Copyright (C) 2023..2024 Maxjta

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
 * Setup for a AT-START-F435 board.
 */

/*
 * Board identifier.
 */
#define BOARD_AT_START_F435
#define BOARD_NAME                  "Artery AT-START-F435"

/*
 * Board oscillators-related settings.
 */
#if !defined(AT32_LEXTCLK)
#define AT32_LEXTCLK                32768
#endif

#if !defined(AT32_HEXTCLK)
#define AT32_HEXTCLK                8000000
#endif

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define AT32F435ZM

/*
 * IO pins assignments.
 */
#define GPIOA_BUTTON                0U
#define GPIOA_PIN1                  1U
#define GPIOA_PIN2                  2U
#define GPIOA_PIN3                  3U
#define GPIOA_PIN4                  4U
#define GPIOA_PIN5                  5U
#define GPIOA_PIN6                  6U
#define GPIOA_PIN7                  7U
#define GPIOA_PIN8                  8U
#define GPIOA_PIN9                  9U
#define GPIOA_PIN10                 10U
#define GPIOA_PIN11                 11U
#define GPIOA_PIN12                 12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_PIN15                 15U

#define GPIOB_PIN0                  0U
#define GPIOB_PIN1                  1U
#define GPIOB_PIN2                  2U
#define GPIOB_PIN3                  3U
#define GPIOB_PIN4                  4U
#define GPIOB_PIN5                  5U
#define GPIOB_PIN6                  6U
#define GPIOB_PIN7                  7U
#define GPIOB_PIN8                  8U
#define GPIOB_PIN9                  9U
#define GPIOB_PIN10                 10U
#define GPIOB_PIN11                 11U
#define GPIOB_PIN12                 12U
#define GPIOB_PIN13                 13U
#define GPIOB_PIN14                 14U
#define GPIOB_PIN15                 15U

#define GPIOC_PIN0                  0U
#define GPIOC_PIN1                  1U
#define GPIOC_PIN2                  2U
#define GPIOC_PIN3                  3U
#define GPIOC_PIN4                  4U
#define GPIOC_PIN5                  5U
#define GPIOC_PIN6                  6U
#define GPIOC_PIN7                  7U
#define GPIOC_PIN8                  8U
#define GPIOC_PIN9                  9U
#define GPIOC_PIN10                 10U
#define GPIOC_PIN11                 11U
#define GPIOC_PIN12                 12U
#define GPIOC_PIN13                 13U
#define GPIOC_PIN14                 14U
#define GPIOC_PIN15                 15U

#define GPIOD_PIN0                  0U
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

#define GPIOE_PIN0                  0U
#define GPIOE_PIN1                  1U
#define GPIOE_PIN2                  2U
#define GPIOE_PIN3                  3U
#define GPIOE_PIN4                  4U
#define GPIOE_PIN5                  5U
#define GPIOE_PIN6                  6U
#define GPIOE_PIN7                  7U
#define GPIOE_PIN8                  8U
#define GPIOE_PIN9                  9U
#define GPIOE_PIN10                 10U
#define GPIOE_PIN11                 11U
#define GPIOE_PIN12                 12U
#define GPIOE_PIN13                 13U
#define GPIOE_PIN14                 14U
#define GPIOE_PIN15                 15U

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

#define GPIOG_PIN0                  0U
#define GPIOG_PIN1                  1U
#define GPIOG_PIN2                  2U
#define GPIOG_PIN3                  3U
#define GPIOG_PIN4                  4U
#define GPIOG_PIN5                  5U
#define GPIOG_PIN6                  6U
#define GPIOG_PIN7                  7U
#define GPIOG_PIN8                  8U
#define GPIOG_PIN9                  9U
#define GPIOG_PIN10                 10U
#define GPIOG_PIN11                 11U
#define GPIOG_PIN12                 12U
#define GPIOG_PIN13                 13U
#define GPIOG_PIN14                 14U
#define GPIOG_PIN15                 15U

#define GPIOH_PIN0                  0U
#define GPIOH_PIN1                  1U
#define GPIOH_PIN2                  2U
#define GPIOH_PIN3                  3U

/*
 * IO lines assignments.
 */
#define LINE_BUTTON                 PAL_LINE(GPIOA, 0U)
#define LINE_LED_RED                PAL_LINE(GPIOD, 13U)
#define LINE_LED_YELLOW             PAL_LINE(GPIOD, 14U)
#define LINE_LED_GREEN              PAL_LINE(GPIOD, 15U)

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
#define PIN_ODRVR_MODERATE(n)       (2U << ((n) * 2U))
#define PIN_PULL_FLOATING(n)        (0U << ((n) * 2U))
#define PIN_PULL_UP(n)              (1U << ((n) * 2U))
#define PIN_PULL_DOWN(n)            (2U << ((n) * 2U))
#define PIN_IOMUX_MUX(n, v)         ((v) << (((n) % 8U) * 4U))
#define PIN_HDRV_DISABLED(n)        (0U << (n))
#define PIN_HDRV_ENABLED(n)         (1U << (n))


/*
 * GPIOA setup:
 *
 * PA0  - PIN0                      (output none pull).
 * PA1  - PIN1                      (input none pull).
 * PA2  - PIN2                      (input none pull).
 * PA3  - PIN3                      (input none pull).
 * PA4  - PIN4                      (input none pull).
 * PA5  - PIN5                      (input none pull).
 * PA6  - PIN6                      (input none pull).
 * PA7  - PIN7                      (input none pull).
 * PA8  - PIN8                      (input none pull).
 * PA9  - PIN9                      (mux 7).
 * PA10 - PIN10                     (mux 7).
 * PA11 - PIN11                     (input none pull).
 * PA12 - PIN12                     (input none pull).
 * PA13 - SWDIO                     (mux 0).
 * PA14 - SWCLK                     (mux 0).
 * PA15 - PIN15                     (input none pull).
 */
#define VAL_GPIOA_CFGR              (PIN_MODE_INPUT(GPIOA_BUTTON) |         \
                                     PIN_MODE_INPUT(GPIOA_PIN1) |            \
                                     PIN_MODE_INPUT(GPIOA_PIN2) |            \
                                     PIN_MODE_INPUT(GPIOA_PIN3) |            \
                                     PIN_MODE_INPUT(GPIOA_PIN4) |            \
                                     PIN_MODE_INPUT(GPIOA_PIN5) |            \
                                     PIN_MODE_INPUT(GPIOA_PIN6) |            \
                                     PIN_MODE_INPUT(GPIOA_PIN7) |            \
                                     PIN_MODE_INPUT(GPIOA_PIN8) |            \
                                     PIN_MODE_MUX(GPIOA_PIN9) |              \
                                     PIN_MODE_MUX(GPIOA_PIN10) |             \
                                     PIN_MODE_INPUT(GPIOA_PIN11) |           \
                                     PIN_MODE_INPUT(GPIOA_PIN12) |           \
                                     PIN_MODE_MUX(GPIOA_SWDIO) |             \
                                     PIN_MODE_MUX(GPIOA_SWCLK) |             \
                                     PIN_MODE_INPUT(GPIOA_PIN15))

#define VAL_GPIOA_ODT               (PIN_ODT_HIGH(GPIOA_BUTTON) |            \
                                     PIN_ODT_HIGH(GPIOA_PIN1) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN2) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN3) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN4) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN5) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN6) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN7) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN8) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN9) |              \
                                     PIN_ODT_HIGH(GPIOA_PIN10) |             \
                                     PIN_ODT_HIGH(GPIOA_PIN11) |             \
                                     PIN_ODT_HIGH(GPIOA_PIN12) |             \
                                     PIN_ODT_HIGH(GPIOA_SWDIO) |             \
                                     PIN_ODT_HIGH(GPIOA_SWCLK) |             \
                                     PIN_ODT_HIGH(GPIOA_PIN15))

#define VAL_GPIOA_OMODE             (PIN_OMODE_PUSHPULL(GPIOA_BUTTON) |     \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN3) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN4) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN5) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN8) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN9) |       \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN10) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OMODE_PUSHPULL(GPIOA_PIN15))

#define VAL_GPIOA_ODRVR             (PIN_ODRVR_STRONGER(GPIOA_BUTTON) |      \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN1) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN2) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN3) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN4) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN5) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN6) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN7) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN8) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN9) |        \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN10) |       \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN11) |       \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN12) |       \
                                     PIN_ODRVR_STRONGER(GPIOA_SWDIO) |       \
                                     PIN_ODRVR_STRONGER(GPIOA_SWCLK) |       \
                                     PIN_ODRVR_STRONGER(GPIOA_PIN15))

#define VAL_GPIOA_PULL              (PIN_PULL_FLOATING(GPIOA_BUTTON) |           \
                                     PIN_PULL_FLOATING(GPIOA_PIN1) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN2) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN3) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN4) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN5) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN6) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN7) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN8) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN9) |             \
                                     PIN_PULL_FLOATING(GPIOA_PIN10) |            \
                                     PIN_PULL_FLOATING(GPIOA_PIN11) |            \
                                     PIN_PULL_FLOATING(GPIOA_PIN12) |            \
                                     PIN_PULL_FLOATING(GPIOA_SWDIO) |            \
                                     PIN_PULL_FLOATING(GPIOA_SWCLK) |            \
                                     PIN_PULL_FLOATING(GPIOA_PIN15))

#define VAL_GPIOA_MUXL              (PIN_IOMUX_MUX(GPIOA_BUTTON, 0U) |             \
                                     PIN_IOMUX_MUX(GPIOA_PIN1, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOA_PIN2, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOA_PIN3, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOA_PIN4, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOA_PIN5, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOA_PIN6, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOA_PIN7, 0U))

#define VAL_GPIOA_MUXH              (PIN_IOMUX_MUX(GPIOA_PIN8, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOA_PIN9, 7U) |               \
                                     PIN_IOMUX_MUX(GPIOA_PIN10, 7U) |              \
                                     PIN_IOMUX_MUX(GPIOA_PIN11, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOA_PIN12, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOA_SWDIO, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOA_SWCLK, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOA_PIN15, 0U))

#define VAL_GPIOA_HDRV              (PIN_HDRV_DISABLED(GPIOA_BUTTON) |      \
                                     PIN_HDRV_DISABLED(GPIOA_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN3) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN4) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN5) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN8) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN9) |        \
                                     PIN_HDRV_DISABLED(GPIOA_PIN10) |       \
                                     PIN_HDRV_DISABLED(GPIOA_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOA_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOA_SWDIO) |       \
                                     PIN_HDRV_DISABLED(GPIOA_SWCLK) |       \
                                     PIN_HDRV_DISABLED(GPIOA_PIN15))
/*
 * GPIOB setup:
 *
 * PB0  - PIN0                      (input none pull).
 * PB1  - PIN1                      (input none pull).
 * PB2  - PIN2                      (input none pull).
 * PB3  - PIN3                      (input none pull).
 * PB4  - PIN4                      (input none pull).
 * PB5  - PIN5                      (input none pull).
 * PB6  - PIN6                      (input none pull).
 * PB7  - PIN7                      (input none pull).
 * PB8  - PIN8                      (input none pull).
 * PB9  - PIN9                      (input none pull).
 * PB10 - PIN10                     (input none pull).
 * PB11 - PIN11                     (input none pull).
 * PB12 - PIN12                     (input none pull).
 * PB13 - PIN13                     (input none pull).
 * PB14 - PIN14                     (input none pull).
 * PB15 - PIN15                     (input none pull).
 */
#define VAL_GPIOB_CFGR              (PIN_MODE_INPUT(GPIOB_PIN0) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN1) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN2) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN3) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN4) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN5) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN6) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN7) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN8) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN9) |            \
                                     PIN_MODE_INPUT(GPIOB_PIN10) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN11) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN12) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN13) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN14) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN15))

#define VAL_GPIOB_ODT               (PIN_ODT_HIGH(GPIOB_PIN0) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN1) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN2) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN3) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN4) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN5) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN6) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN7) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN8) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN9) |              \
                                     PIN_ODT_HIGH(GPIOB_PIN10) |             \
                                     PIN_ODT_HIGH(GPIOB_PIN11) |             \
                                     PIN_ODT_HIGH(GPIOB_PIN12) |             \
                                     PIN_ODT_HIGH(GPIOB_PIN13) |             \
                                     PIN_ODT_HIGH(GPIOB_PIN14) |             \
                                     PIN_ODT_HIGH(GPIOB_PIN15))

#define VAL_GPIOB_OMODE             (PIN_OMODE_PUSHPULL(GPIOB_PIN0) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN3) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN4) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN5) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN8) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN9) |       \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN10) |      \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN13) |      \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN14) |      \
                                     PIN_OMODE_PUSHPULL(GPIOB_PIN15))

#define VAL_GPIOB_ODRVR             (PIN_ODRVR_STRONGER(GPIOB_PIN0) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN1) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN2) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN3) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN4) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN5) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN6) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN7) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN8) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN9) |        \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN10) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN11) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN12) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN13) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN14) |       \
                                     PIN_ODRVR_STRONGER(GPIOB_PIN15))

#define VAL_GPIOB_PULL              (PIN_PULL_FLOATING(GPIOB_PIN0) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN1) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN2) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN3) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN4) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN5) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN6) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN7) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN8) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN9) |             \
                                     PIN_PULL_FLOATING(GPIOB_PIN10) |            \
                                     PIN_PULL_FLOATING(GPIOB_PIN11) |            \
                                     PIN_PULL_FLOATING(GPIOB_PIN12) |            \
                                     PIN_PULL_FLOATING(GPIOB_PIN13) |            \
                                     PIN_PULL_FLOATING(GPIOB_PIN14) |            \
                                     PIN_PULL_FLOATING(GPIOB_PIN15))

#define VAL_GPIOB_MUXL              (PIN_IOMUX_MUX(GPIOB_PIN0, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN1, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN2, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN3, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN4, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN5, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN6, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN7, 0U))

#define VAL_GPIOB_MUXH              (PIN_IOMUX_MUX(GPIOB_PIN8, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN9, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOB_PIN10, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOB_PIN11, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOB_PIN12, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOB_PIN13, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOB_PIN14, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOB_PIN15, 0U))

#define VAL_GPIOB_HDRV              (PIN_HDRV_DISABLED(GPIOB_PIN0) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN3) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN4) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN5) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN8) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN9) |        \
                                     PIN_HDRV_DISABLED(GPIOB_PIN10) |       \
                                     PIN_HDRV_DISABLED(GPIOB_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOB_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOB_PIN13) |       \
                                     PIN_HDRV_DISABLED(GPIOB_PIN14) |       \
                                     PIN_HDRV_DISABLED(GPIOB_PIN15))

/*
 * GPIOC setup:
 *
 * PC0  - PIN0                      (input none pull).
 * PC1  - PIN1                      (input none pull).
 * PC2  - PIN2                      (input none pull).
 * PC3  - PIN3                      (input none pull).
 * PC4  - PIN4                      (input none pull).
 * PC5  - PIN5                      (input none pull).
 * PC6  - PIN6                      (input none pull).
 * PC7  - PIN7                      (input none pull).
 * PC8  - PIN8                      (input none pull).
 * PC9  - PIN9                      (input none pull).
 * PC10 - PIN10                     (input none pull).
 * PC11 - PIN11                     (input none pull).
 * PC12 - PIN12                     (input none pull).
 * PC13 - PIN13                     (input none pull).
 * PC14 - PIN14                     (input none pull).
 * PC15 - PIN15                     (input none pull).
 */
#define VAL_GPIOC_CFGR              (PIN_MODE_INPUT(GPIOC_PIN0) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN1) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN2) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN3) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN4) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN5) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN6) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN7) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN8) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN9) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN10) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN11) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN12) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN13) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN14) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN15))

#define VAL_GPIOC_ODT               (PIN_ODT_HIGH(GPIOC_PIN0) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN1) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN2) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN3) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN4) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN5) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN6) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN7) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN8) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN9) |              \
                                     PIN_ODT_HIGH(GPIOC_PIN10) |             \
                                     PIN_ODT_HIGH(GPIOC_PIN11) |             \
                                     PIN_ODT_HIGH(GPIOC_PIN12) |             \
                                     PIN_ODT_HIGH(GPIOC_PIN13) |             \
                                     PIN_ODT_HIGH(GPIOC_PIN14) |             \
                                     PIN_ODT_HIGH(GPIOC_PIN15))

#define VAL_GPIOC_OMODE             (PIN_OMODE_PUSHPULL(GPIOC_PIN0) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN3) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN4) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN5) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN8) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN9) |       \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN10) |      \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN13) |      \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN14) |      \
                                     PIN_OMODE_PUSHPULL(GPIOC_PIN15))

#define VAL_GPIOC_ODRVR             (PIN_ODRVR_STRONGER(GPIOC_PIN0) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN1) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN2) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN3) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN4) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN5) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN6) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN7) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN8) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN9) |        \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN10) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN11) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN12) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN13) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN14) |       \
                                     PIN_ODRVR_STRONGER(GPIOC_PIN15))

#define VAL_GPIOC_PULL              (PIN_PULL_FLOATING(GPIOC_PIN0) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN1) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN2) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN3) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN4) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN5) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN6) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN7) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN8) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN9) |             \
                                     PIN_PULL_FLOATING(GPIOC_PIN10) |            \
                                     PIN_PULL_FLOATING(GPIOC_PIN11) |            \
                                     PIN_PULL_FLOATING(GPIOC_PIN12) |            \
                                     PIN_PULL_FLOATING(GPIOC_PIN13) |            \
                                     PIN_PULL_FLOATING(GPIOC_PIN14) |            \
                                     PIN_PULL_FLOATING(GPIOC_PIN15))

#define VAL_GPIOC_MUXL              (PIN_IOMUX_MUX(GPIOC_PIN0, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN1, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN2, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN3, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN4, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN5, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN6, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN7, 0U))

#define VAL_GPIOC_MUXH              (PIN_IOMUX_MUX(GPIOC_PIN8, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN9, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOC_PIN10, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOC_PIN11, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOC_PIN12, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOC_PIN13, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOC_PIN14, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOC_PIN15, 0U))

#define VAL_GPIOC_HDRV              (PIN_HDRV_DISABLED(GPIOC_PIN0) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN3) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN4) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN5) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN8) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN9) |        \
                                     PIN_HDRV_DISABLED(GPIOC_PIN10) |       \
                                     PIN_HDRV_DISABLED(GPIOC_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOC_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOC_PIN13) |       \
                                     PIN_HDRV_DISABLED(GPIOC_PIN14) |       \
                                     PIN_HDRV_DISABLED(GPIOC_PIN15))

/*
 * GPIOD setup:
 *
 * PD0  - PIN0                      (input none pull).
 * PD1  - PIN1                      (input none pull).
 * PD2  - PIN2                      (input none pull).
 * PD3  - PIN3                      (input none pull).
 * PD4  - PIN4                      (input none pull).
 * PD5  - PIN5                      (input none pull).
 * PD6  - PIN6                      (input none pull).
 * PD7  - PIN7                      (input none pull).
 * PD8  - PIN8                      (input none pull).
 * PD9  - PIN9                      (input none pull).
 * PD10 - PIN10                     (input none pull).
 * PD11 - PIN11                     (input none pull).
 * PD12 - PIN12                     (input none pull).
 * PD13 - PIN13                     (input none pull).
 * PD14 - PIN14                     (input none pull).
 * PD15 - PIN15                     (input none pull).
 */
#define VAL_GPIOD_CFGR              (PIN_MODE_INPUT(GPIOD_PIN0) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN1) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN2) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN3) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN4) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN5) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN6) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN7) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN8) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN9) |            \
                                     PIN_MODE_INPUT(GPIOD_PIN10) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN11) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN12) |           \
                                     PIN_MODE_OUTPUT(GPIOD_PIN13) |           \
                                     PIN_MODE_OUTPUT(GPIOD_PIN14) |           \
                                     PIN_MODE_OUTPUT(GPIOD_PIN15))

#define VAL_GPIOD_ODT               (PIN_ODT_HIGH(GPIOD_PIN0) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN1) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN2) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN3) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN4) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN5) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN6) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN7) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN8) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN9) |              \
                                     PIN_ODT_HIGH(GPIOD_PIN10) |             \
                                     PIN_ODT_HIGH(GPIOD_PIN11) |             \
                                     PIN_ODT_HIGH(GPIOD_PIN12) |             \
                                     PIN_ODT_HIGH(GPIOD_PIN13) |             \
                                     PIN_ODT_HIGH(GPIOD_PIN14) |             \
                                     PIN_ODT_HIGH(GPIOD_PIN15))

#define VAL_GPIOD_OMODE             (PIN_OMODE_PUSHPULL(GPIOD_PIN0) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN3) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN4) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN5) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN8) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN9) |       \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN10) |      \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN13) |      \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN14) |      \
                                     PIN_OMODE_PUSHPULL(GPIOD_PIN15))

#define VAL_GPIOD_ODRVR             (PIN_ODRVR_STRONGER(GPIOD_PIN0) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN1) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN2) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN3) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN4) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN5) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN6) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN7) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN8) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN9) |        \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN10) |       \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN11) |       \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN12) |       \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN13) |       \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN14) |       \
                                     PIN_ODRVR_STRONGER(GPIOD_PIN15))

#define VAL_GPIOD_PULL              (PIN_PULL_FLOATING(GPIOD_PIN0) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN1) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN2) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN3) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN4) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN5) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN6) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN7) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN8) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN9) |             \
                                     PIN_PULL_FLOATING(GPIOD_PIN10) |            \
                                     PIN_PULL_FLOATING(GPIOD_PIN11) |            \
                                     PIN_PULL_FLOATING(GPIOD_PIN12) |            \
                                     PIN_PULL_FLOATING(GPIOD_PIN13) |            \
                                     PIN_PULL_FLOATING(GPIOD_PIN14) |            \
                                     PIN_PULL_FLOATING(GPIOD_PIN15))

#define VAL_GPIOD_MUXL              (PIN_IOMUX_MUX(GPIOD_PIN0, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN1, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN2, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN3, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN4, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN5, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN6, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN7, 0U))

#define VAL_GPIOD_MUXH              (PIN_IOMUX_MUX(GPIOD_PIN8, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN9, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOD_PIN10, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOD_PIN11, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOD_PIN12, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOD_PIN13, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOD_PIN14, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOD_PIN15, 0U))

#define VAL_GPIOD_HDRV              (PIN_HDRV_DISABLED(GPIOD_PIN0) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN3) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN4) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN5) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN8) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN9) |        \
                                     PIN_HDRV_DISABLED(GPIOD_PIN10) |       \
                                     PIN_HDRV_DISABLED(GPIOD_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOD_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOD_PIN13) |       \
                                     PIN_HDRV_DISABLED(GPIOD_PIN14) |       \
                                     PIN_HDRV_DISABLED(GPIOD_PIN15))

/*
 * GPIOE setup:
 *
 * PE0  - PIN0                      (input none pull).
 * PE1  - PIN1                      (input none pull).
 * PE2  - PIN2                      (input none pull).
 * PE3  - PIN3                      (input none pull).
 * PE4  - PIN4                      (input none pull).
 * PE5  - PIN5                      (input none pull).
 * PE6  - PIN6                      (input none pull).
 * PE7  - PIN7                      (input none pull).
 * PE8  - PIN8                      (input none pull).
 * PE9  - PIN9                      (input none pull).
 * PE10 - PIN10                     (input none pull).
 * PE11 - PIN11                     (input none pull).
 * PE12 - PIN12                     (input none pull).
 * PE13 - PIN13                     (input none pull).
 * PE14 - PIN14                     (input none pull).
 * PE15 - PIN15                     (input none pull).
 */
#define VAL_GPIOE_CFGR              (PIN_MODE_INPUT(GPIOE_PIN0) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN1) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN2) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN3) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN4) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN5) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN6) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN7) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN8) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN9) |            \
                                     PIN_MODE_INPUT(GPIOE_PIN10) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN11) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN12) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN13) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN14) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN15))

#define VAL_GPIOE_ODT               (PIN_ODT_HIGH(GPIOE_PIN0) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN1) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN2) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN3) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN4) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN5) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN6) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN7) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN8) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN9) |              \
                                     PIN_ODT_HIGH(GPIOE_PIN10) |             \
                                     PIN_ODT_HIGH(GPIOE_PIN11) |             \
                                     PIN_ODT_HIGH(GPIOE_PIN12) |             \
                                     PIN_ODT_HIGH(GPIOE_PIN13) |             \
                                     PIN_ODT_HIGH(GPIOE_PIN14) |             \
                                     PIN_ODT_HIGH(GPIOE_PIN15))

#define VAL_GPIOE_OMODE            (PIN_OMODE_PUSHPULL(GPIOE_PIN0) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN3) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN4) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN5) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN8) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN9) |       \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN10) |      \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN13) |      \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN14) |      \
                                     PIN_OMODE_PUSHPULL(GPIOE_PIN15))

#define VAL_GPIOE_ODRVR             (PIN_ODRVR_STRONGER(GPIOE_PIN0) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN1) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN2) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN3) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN4) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN5) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN6) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN7) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN8) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN9) |        \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN10) |       \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN11) |       \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN12) |       \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN13) |       \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN14) |       \
                                     PIN_ODRVR_STRONGER(GPIOE_PIN15))

#define VAL_GPIOE_PULL              (PIN_PULL_FLOATING(GPIOE_PIN0) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN1) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN2) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN3) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN4) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN5) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN6) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN7) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN8) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN9) |             \
                                     PIN_PULL_FLOATING(GPIOE_PIN10) |            \
                                     PIN_PULL_FLOATING(GPIOE_PIN11) |            \
                                     PIN_PULL_FLOATING(GPIOE_PIN12) |            \
                                     PIN_PULL_FLOATING(GPIOE_PIN13) |            \
                                     PIN_PULL_FLOATING(GPIOE_PIN14) |            \
                                     PIN_PULL_FLOATING(GPIOE_PIN15))

#define VAL_GPIOE_MUXL              (PIN_IOMUX_MUX(GPIOE_PIN0, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN1, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN2, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN3, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN4, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN5, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN6, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN7, 0U))

#define VAL_GPIOE_MUXH              (PIN_IOMUX_MUX(GPIOE_PIN8, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN9, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOE_PIN10, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOE_PIN11, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOE_PIN12, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOE_PIN13, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOE_PIN14, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOE_PIN15, 0U))

#define VAL_GPIOE_HDRV              (PIN_HDRV_DISABLED(GPIOE_PIN0) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN3) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN4) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN5) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN8) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN9) |        \
                                     PIN_HDRV_DISABLED(GPIOE_PIN10) |       \
                                     PIN_HDRV_DISABLED(GPIOE_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOE_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOE_PIN13) |       \
                                     PIN_HDRV_DISABLED(GPIOE_PIN14) |       \
                                     PIN_HDRV_DISABLED(GPIOE_PIN15))

/*
 * GPIOF setup:
 *
 * PF0  - PIN0                      (input none pull).
 * PF1  - PIN1                      (input none pull).
 * PF2  - PIN2                      (input none pull).
 * PF3  - PIN3                      (input none pull).
 * PF4  - PIN4                      (input none pull).
 * PF5  - PIN5                      (input none pull).
 * PF6  - PIN6                      (input none pull).
 * PF7  - PIN7                      (input none pull).
 * PF8  - PIN8                      (input none pull).
 * PF9  - PIN9                      (input none pull).
 * PF10 - PIN10                     (input none pull).
 * PF11 - PIN11                     (input none pull).
 * PF12 - PIN12                     (input none pull).
 * PF13 - PIN13                     (input none pull).
 * PF14 - PIN14                     (input none pull).
 * PF15 - PIN15                     (input none pull).
 */
#define VAL_GPIOF_CFGR              (PIN_MODE_INPUT(GPIOF_PIN0) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN1) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN2) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN3) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN4) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN5) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN6) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN7) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN8) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN9) |            \
                                     PIN_MODE_INPUT(GPIOF_PIN10) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN11) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN12) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN13) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN14) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN15))

#define VAL_GPIOF_ODT               (PIN_ODT_HIGH(GPIOF_PIN0) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN1) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN2) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN3) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN4) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN5) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN6) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN7) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN8) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN9) |              \
                                     PIN_ODT_HIGH(GPIOF_PIN10) |             \
                                     PIN_ODT_HIGH(GPIOF_PIN11) |             \
                                     PIN_ODT_HIGH(GPIOF_PIN12) |             \
                                     PIN_ODT_HIGH(GPIOF_PIN13) |             \
                                     PIN_ODT_HIGH(GPIOF_PIN14) |             \
                                     PIN_ODT_HIGH(GPIOF_PIN15))

#define VAL_GPIOF_OMODE             (PIN_OMODE_PUSHPULL(GPIOF_PIN0) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OMODE_PUSHPULL(GPIOF_PIN15))

#define VAL_GPIOF_ODRVR             (PIN_ODRVR_STRONGER(GPIOF_PIN0) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN1) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN2) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN3) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN4) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN5) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN6) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN7) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN8) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN9) |        \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN10) |       \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN11) |       \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN12) |       \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN13) |       \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN14) |       \
                                     PIN_ODRVR_STRONGER(GPIOF_PIN15))

#define VAL_GPIOF_PULL              (PIN_PULL_FLOATING(GPIOF_PIN0) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN1) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN2) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN3) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN4) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN5) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN6) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN7) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN8) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN9) |             \
                                     PIN_PULL_FLOATING(GPIOF_PIN10) |            \
                                     PIN_PULL_FLOATING(GPIOF_PIN11) |            \
                                     PIN_PULL_FLOATING(GPIOF_PIN12) |            \
                                     PIN_PULL_FLOATING(GPIOF_PIN13) |            \
                                     PIN_PULL_FLOATING(GPIOF_PIN14) |            \
                                     PIN_PULL_FLOATING(GPIOF_PIN15))

#define VAL_GPIOF_MUXL              (PIN_IOMUX_MUX(GPIOF_PIN0, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN1, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN2, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN3, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN4, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN5, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN6, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN7, 0U))

#define VAL_GPIOF_MUXH              (PIN_IOMUX_MUX(GPIOF_PIN8, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN9, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOF_PIN10, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOF_PIN11, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOF_PIN12, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOF_PIN13, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOF_PIN14, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOF_PIN15, 0U))

#define VAL_GPIOF_HDRV              (PIN_HDRV_DISABLED(GPIOF_PIN0) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN3) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN4) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN5) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN8) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN9) |        \
                                     PIN_HDRV_DISABLED(GPIOF_PIN10) |       \
                                     PIN_HDRV_DISABLED(GPIOF_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOF_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOF_PIN13) |       \
                                     PIN_HDRV_DISABLED(GPIOF_PIN14) |       \
                                     PIN_HDRV_DISABLED(GPIOF_PIN15))

/*
 * GPIOG setup:
 *
 * PG0  - PIN0                      (input none pull).
 * PG1  - PIN1                      (input none pull).
 * PG2  - PIN2                      (input none pull).
 * PG3  - PIN3                      (input none pull).
 * PG4  - PIN4                      (input none pull).
 * PG5  - PIN5                      (input none pull).
 * PG6  - PIN6                      (input none pull).
 * PG7  - PIN7                      (input none pull).
 * PG8  - PIN8                      (input none pull).
 * PG9  - PIN9                      (input none pull).
 * PG10 - PIN10                     (input none pull).
 * PG11 - PIN11                     (input none pull).
 * PG12 - PIN12                     (input none pull).
 * PG13 - PIN13                     (input none pull).
 * PG14 - PIN14                     (input none pull).
 * PG15 - PIN15                     (input none pull).
 */
#define VAL_GPIOG_CFGR              (PIN_MODE_INPUT(GPIOG_PIN0) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN1) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN2) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN3) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN4) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN5) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN6) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN7) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN8) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN9) |            \
                                     PIN_MODE_INPUT(GPIOG_PIN10) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN11) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN12) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN13) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN14) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN15))

#define VAL_GPIOG_ODT               (PIN_ODT_HIGH(GPIOG_PIN0) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN1) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN2) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN3) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN4) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN5) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN6) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN7) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN8) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN9) |              \
                                     PIN_ODT_HIGH(GPIOG_PIN10) |             \
                                     PIN_ODT_HIGH(GPIOG_PIN11) |             \
                                     PIN_ODT_HIGH(GPIOG_PIN12) |             \
                                     PIN_ODT_HIGH(GPIOG_PIN13) |             \
                                     PIN_ODT_HIGH(GPIOG_PIN14) |             \
                                     PIN_ODT_HIGH(GPIOG_PIN15))

#define VAL_GPIOG_OMODE             (PIN_OMODE_PUSHPULL(GPIOG_PIN0) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN3) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN4) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN5) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN6) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN7) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN8) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN9) |       \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN10) |      \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN11) |      \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN12) |      \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN13) |      \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN14) |      \
                                     PIN_OMODE_PUSHPULL(GPIOG_PIN15))

#define VAL_GPIOG_ODRVR             (PIN_ODRVR_STRONGER(GPIOG_PIN0) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN1) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN2) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN3) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN4) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN5) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN6) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN7) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN8) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN9) |        \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN10) |       \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN11) |       \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN12) |       \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN13) |       \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN14) |       \
                                     PIN_ODRVR_STRONGER(GPIOG_PIN15))

#define VAL_GPIOG_PULL              (PIN_PULL_FLOATING(GPIOG_PIN0) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN1) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN2) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN3) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN4) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN5) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN6) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN7) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN8) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN9) |             \
                                     PIN_PULL_FLOATING(GPIOG_PIN10) |            \
                                     PIN_PULL_FLOATING(GPIOG_PIN11) |            \
                                     PIN_PULL_FLOATING(GPIOG_PIN12) |            \
                                     PIN_PULL_FLOATING(GPIOG_PIN13) |            \
                                     PIN_PULL_FLOATING(GPIOG_PIN14) |            \
                                     PIN_PULL_FLOATING(GPIOG_PIN15))

#define VAL_GPIOG_MUXL              (PIN_IOMUX_MUX(GPIOG_PIN0, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN1, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN2, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN3, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN4, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN5, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN6, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN7, 0U))

#define VAL_GPIOG_MUXH              (PIN_IOMUX_MUX(GPIOG_PIN8, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN9, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOG_PIN10, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOG_PIN11, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOG_PIN12, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOG_PIN13, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOG_PIN14, 0U) |              \
                                     PIN_IOMUX_MUX(GPIOG_PIN15, 0U))

#define VAL_GPIOG_HDRV              (PIN_HDRV_DISABLED(GPIOG_PIN0) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN3) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN4) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN5) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN6) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN7) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN8) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN9) |        \
                                     PIN_HDRV_DISABLED(GPIOG_PIN10) |       \
                                     PIN_HDRV_DISABLED(GPIOG_PIN11) |       \
                                     PIN_HDRV_DISABLED(GPIOG_PIN12) |       \
                                     PIN_HDRV_DISABLED(GPIOG_PIN13) |       \
                                     PIN_HDRV_DISABLED(GPIOG_PIN14) |       \
                                     PIN_HDRV_DISABLED(GPIOG_PIN15))


/*
 * GPIOH setup:
 *
 * PH0  - PIN0                      (input none pull).
 * PH1  - PIN1                      (input none pull).
 * PH2  - PIN2                      (input none pull).
 * PH3  - PIN3                      (input none pull).
 */
#define VAL_GPIOH_CFGR              (PIN_MODE_INPUT(GPIOH_PIN0) |            \
                                     PIN_MODE_INPUT(GPIOH_PIN1) |            \
                                     PIN_MODE_INPUT(GPIOH_PIN2) |            \
                                     PIN_MODE_INPUT(GPIOH_PIN3))


#define VAL_GPIOH_ODT               (PIN_ODT_HIGH(GPIOH_PIN0) |              \
                                     PIN_ODT_HIGH(GPIOH_PIN1) |              \
                                     PIN_ODT_HIGH(GPIOH_PIN2) |              \
                                     PIN_ODT_HIGH(GPIOH_PIN3))


#define VAL_GPIOH_OMODE             (PIN_OMODE_PUSHPULL(GPIOH_PIN0) |       \
                                     PIN_OMODE_PUSHPULL(GPIOH_PIN1) |       \
                                     PIN_OMODE_PUSHPULL(GPIOH_PIN2) |       \
                                     PIN_OMODE_PUSHPULL(GPIOH_PIN3))


#define VAL_GPIOH_ODRVR             (PIN_ODRVR_STRONGER(GPIOH_PIN0) |        \
                                     PIN_ODRVR_STRONGER(GPIOH_PIN1) |        \
                                     PIN_ODRVR_STRONGER(GPIOH_PIN2) |        \
                                     PIN_ODRVR_STRONGER(GPIOH_PIN3))


#define VAL_GPIOH_PULL              (PIN_PULL_FLOATING(GPIOH_PIN0) |             \
                                     PIN_PULL_FLOATING(GPIOH_PIN1) |             \
                                     PIN_PULL_FLOATING(GPIOH_PIN2) |             \
                                     PIN_PULL_FLOATING(GPIOH_PIN3))


#define VAL_GPIOH_MUXL              (PIN_IOMUX_MUX(GPIOH_PIN0, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOH_PIN1, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOH_PIN2, 0U) |               \
                                     PIN_IOMUX_MUX(GPIOH_PIN3, 0U))


#define VAL_GPIOH_MUXH              (0U)

#define VAL_GPIOH_HDRV              (PIN_HDRV_DISABLED(GPIOH_PIN0) |        \
                                     PIN_HDRV_DISABLED(GPIOH_PIN1) |        \
                                     PIN_HDRV_DISABLED(GPIOH_PIN2) |        \
                                     PIN_HDRV_DISABLED(GPIOH_PIN3))

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

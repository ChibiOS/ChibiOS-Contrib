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

#pragma once

/*
 * Setup for a Generic HT32F52342/52 board.
 */

/*
 * Board identifier.
 */
#define BOARD_HT32_F52342_52
#define BOARD_NAME              "Generic HT32F52342/52 Board"

/*
 * Board frequencies.
 */
#define HT32_LSECLK             32768
#define HT32_HSECLK             8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define HT32F52352

/*
 * IO pins assignments
 */
#define GPIOA_PIN0              0U
#define GPIOA_PIN1              1U
#define GPIOA_PIN2              2U
#define GPIOA_PIN3              3U
#define GPIOA_PIN4              4U
#define GPIOA_PIN5              5U
#define GPIOA_PIN6              6U
#define GPIOA_PIN7              7U
#define GPIOA_PIN8              8U
#define GPIOA_PIN9              9U
#define GPIOA_PIN10             10U
#define GPIOA_PIN11             11U
#define GPIOA_PIN12             12U
#define GPIOA_PIN13             13U
#define GPIOA_PIN14             14U
#define GPIOA_PIN15             15U

#define GPIOB_PIN0              0U
#define GPIOB_PIN1              1U
#define GPIOB_PIN2              2U
#define GPIOB_PIN3              3U
#define GPIOB_PIN4              4U
#define GPIOB_PIN5              5U
#define GPIOB_PIN6              6U
#define GPIOB_PIN7              7U
#define GPIOB_PIN8              8U
#define GPIOB_PIN9              9U
#define GPIOB_PIN10             10U
#define GPIOB_PIN11             11U
#define GPIOB_PIN12             12U
#define GPIOB_PIN13             13U
#define GPIOB_PIN14             14U
#define GPIOB_PIN15             15U

#define GPIOC_PIN0              0U
#define GPIOC_PIN1              1U
#define GPIOC_PIN2              2U
#define GPIOC_PIN3              3U
#define GPIOC_PIN4              4U
#define GPIOC_PIN5              5U
#define GPIOC_PIN6              6U
#define GPIOC_PIN7              7U
#define GPIOC_PIN8              8U
#define GPIOC_PIN9              9U
#define GPIOC_PIN10             10U
#define GPIOC_PIN11             11U
#define GPIOC_PIN12             12U
#define GPIOC_PIN13             13U
#define GPIOC_PIN14             14U
#define GPIOC_PIN15             15U

#define GPIOD_PIN0              0U
#define GPIOD_PIN1              1U
#define GPIOD_PIN2              2U
#define GPIOD_PIN3              3U
#define GPIOD_PIN4              4U
#define GPIOD_PIN5              5U
#define GPIOD_PIN6              6U
#define GPIOD_PIN7              7U
#define GPIOD_PIN8              8U
#define GPIOD_PIN9              9U
#define GPIOD_PIN10             10U
#define GPIOD_PIN11             11U
#define GPIOD_PIN12             12U
#define GPIOD_PIN13             13U
#define GPIOD_PIN14             14U
#define GPIOD_PIN15             15U

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the HT32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)       (0U << (n))
#define PIN_MODE_OUTPUT(n)      (1U << (n))
#define PIN_INPUT_DISABLE(n)    (0U << (n))
#define PIN_INPUT_ENABLE(n)     (1U << (n))
#define PIN_PULLUP_DISABLE(n)   (0U << (n))
#define PIN_PULLUP_ENABLE(n)    (1U << (n))
#define PIN_PULLDOWN_DISABLE(n) (0U << (n))
#define PIN_PULLDOWN_ENABLE(n)  (1U << (n))
#define PIN_ODR_PUSHPULL(n)     (0U << (n))
#define PIN_ODR_OPENDRAIN(n)    (1U << (n))
#define PIN_DRVR_4MA(n)         (0U << (n))
#define PIN_DRVR_8MA(n)         (1U << (n))
#define PIN_AFIO_AF(n, v)       ((v) << (((n) % 8U) * 4U))

/*
 * Port A setup.
 * Everything GPIO input with pull-up except:
 * PA12 - AF0 - SWCLK
 * PA13 - AF0 - SWDIO
 */
#define VAL_GPIOA_DIRCR         (PIN_MODE_INPUT(GPIOA_PIN0) | \
                                 PIN_MODE_INPUT(GPIOA_PIN1) | \
                                 PIN_MODE_INPUT(GPIOA_PIN2) | \
                                 PIN_MODE_INPUT(GPIOA_PIN3) | \
                                 PIN_MODE_INPUT(GPIOA_PIN4) | \
                                 PIN_MODE_INPUT(GPIOA_PIN5) | \
                                 PIN_MODE_INPUT(GPIOA_PIN6) | \
                                 PIN_MODE_INPUT(GPIOA_PIN7) | \
                                 PIN_MODE_INPUT(GPIOA_PIN8) | \
                                 PIN_MODE_INPUT(GPIOA_PIN9) | \
                                 PIN_MODE_INPUT(GPIOA_PIN10) | \
                                 PIN_MODE_INPUT(GPIOA_PIN11) | \
                                 PIN_MODE_INPUT(GPIOA_PIN12) | \
                                 PIN_MODE_INPUT(GPIOA_PIN13) | \
                                 PIN_MODE_INPUT(GPIOA_PIN14) | \
                                 PIN_MODE_INPUT(GPIOA_PIN15))
#define VAL_GPIOA_INER          (PIN_INPUT_ENABLE(GPIOA_PIN0) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN1) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN2) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN3) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN4) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN5) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN6) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN7) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN8) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN9) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN10) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN11) | \
                                 PIN_INPUT_DISABLE(GPIOA_PIN12) | \
                                 PIN_INPUT_DISABLE(GPIOA_PIN13) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN14) | \
                                 PIN_INPUT_ENABLE(GPIOA_PIN15))
#define VAL_GPIOA_PUR           (PIN_PULLUP_ENABLE(GPIOA_PIN0) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN1) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN2) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN3) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN4) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN5) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN6) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN7) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN8) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN9) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN10) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN11) | \
                                 PIN_PULLUP_DISABLE(GPIOA_PIN12) | \
                                 PIN_PULLUP_DISABLE(GPIOA_PIN13) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN14) | \
                                 PIN_PULLUP_ENABLE(GPIOA_PIN15))
#define VAL_GPIOA_PDR           (PIN_PULLDOWN_DISABLE(GPIOA_PIN0) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN1) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN2) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN3) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN4) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN5) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN6) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN7) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN8) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN9) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN10) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN11) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN12) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN13) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN14) | \
                                 PIN_PULLDOWN_DISABLE(GPIOA_PIN15))
#define VAL_GPIOA_ODR           (PIN_ODR_PUSHPULL(GPIOA_PIN0) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN1) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN2) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN3) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN4) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN5) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN6) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN7) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN8) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN9) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN10) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN11) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN12) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN13) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN14) | \
                                 PIN_ODR_PUSHPULL(GPIOA_PIN15))
#define VAL_GPIOA_DRVR          (PIN_DRVR_4MA(GPIOA_PIN0) | \
                                 PIN_DRVR_4MA(GPIOA_PIN1) | \
                                 PIN_DRVR_4MA(GPIOA_PIN2) | \
                                 PIN_DRVR_4MA(GPIOA_PIN3) | \
                                 PIN_DRVR_4MA(GPIOA_PIN4) | \
                                 PIN_DRVR_4MA(GPIOA_PIN5) | \
                                 PIN_DRVR_4MA(GPIOA_PIN6) | \
                                 PIN_DRVR_4MA(GPIOA_PIN7) | \
                                 PIN_DRVR_4MA(GPIOA_PIN8) | \
                                 PIN_DRVR_4MA(GPIOA_PIN9) | \
                                 PIN_DRVR_4MA(GPIOA_PIN10) | \
                                 PIN_DRVR_4MA(GPIOA_PIN11) | \
                                 PIN_DRVR_4MA(GPIOA_PIN12) | \
                                 PIN_DRVR_4MA(GPIOA_PIN13) | \
                                 PIN_DRVR_4MA(GPIOA_PIN14) | \
                                 PIN_DRVR_4MA(GPIOA_PIN15))
#define VAL_GPIOA_AFCFGR0       (PIN_AFIO_AF(GPIOA_PIN0, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN1, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN2, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN3, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN4, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN5, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN6, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN7, AFIO_GPIO))
#define VAL_GPIOA_AFCFGR1       (PIN_AFIO_AF(GPIOA_PIN0, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN8, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN9, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN10, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN11, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN12, AFIO_DEFAULT) | \
                                 PIN_AFIO_AF(GPIOA_PIN13, AFIO_DEFAULT) | \
                                 PIN_AFIO_AF(GPIOA_PIN14, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOA_PIN15, AFIO_GPIO))

/*
 * Port B setup.
 * Everything GPIO input with pull-up except:
 * PB13 - AF0 - XTALIN
 * PB14 - AF0 - XTALOUT
 */
#define VAL_GPIOB_DIRCR         (PIN_MODE_INPUT(GPIOB_PIN0) | \
                                 PIN_MODE_INPUT(GPIOB_PIN1) | \
                                 PIN_MODE_INPUT(GPIOB_PIN2) | \
                                 PIN_MODE_INPUT(GPIOB_PIN3) | \
                                 PIN_MODE_INPUT(GPIOB_PIN4) | \
                                 PIN_MODE_INPUT(GPIOB_PIN5) | \
                                 PIN_MODE_INPUT(GPIOB_PIN6) | \
                                 PIN_MODE_INPUT(GPIOB_PIN7) | \
                                 PIN_MODE_INPUT(GPIOB_PIN8) | \
                                 PIN_MODE_INPUT(GPIOB_PIN9) | \
                                 PIN_MODE_INPUT(GPIOB_PIN10) | \
                                 PIN_MODE_INPUT(GPIOB_PIN11) | \
                                 PIN_MODE_INPUT(GPIOB_PIN12) | \
                                 PIN_MODE_INPUT(GPIOB_PIN13) | \
                                 PIN_MODE_INPUT(GPIOB_PIN14) | \
                                 PIN_MODE_INPUT(GPIOB_PIN15))
#define VAL_GPIOB_INER          (PIN_INPUT_ENABLE(GPIOB_PIN0) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN1) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN2) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN3) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN4) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN5) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN6) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN7) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN8) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN9) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN10) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN11) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN12) | \
                                 PIN_INPUT_DISABLE(GPIOB_PIN13) | \
                                 PIN_INPUT_DISABLE(GPIOB_PIN14) | \
                                 PIN_INPUT_ENABLE(GPIOB_PIN15))
#define VAL_GPIOB_PUR           (PIN_PULLUP_ENABLE(GPIOB_PIN0) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN1) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN2) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN3) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN4) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN5) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN6) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN7) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN8) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN9) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN10) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN11) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN12) | \
                                 PIN_PULLUP_DISABLE(GPIOB_PIN13) | \
                                 PIN_PULLUP_DISABLE(GPIOB_PIN14) | \
                                 PIN_PULLUP_ENABLE(GPIOB_PIN15))
#define VAL_GPIOB_PDR           (PIN_PULLDOWN_DISABLE(GPIOB_PIN0) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN1) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN2) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN3) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN4) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN5) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN6) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN7) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN8) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN9) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN10) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN11) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN12) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN13) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN14) | \
                                 PIN_PULLDOWN_DISABLE(GPIOB_PIN15))
#define VAL_GPIOB_ODR           (PIN_ODR_PUSHPULL(GPIOB_PIN0) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN1) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN2) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN3) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN4) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN5) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN6) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN7) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN8) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN9) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN10) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN11) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN12) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN13) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN14) | \
                                 PIN_ODR_PUSHPULL(GPIOB_PIN15))
#define VAL_GPIOB_DRVR          (PIN_DRVR_4MA(GPIOB_PIN0) | \
                                 PIN_DRVR_4MA(GPIOB_PIN1) | \
                                 PIN_DRVR_4MA(GPIOB_PIN2) | \
                                 PIN_DRVR_4MA(GPIOB_PIN3) | \
                                 PIN_DRVR_4MA(GPIOB_PIN4) | \
                                 PIN_DRVR_4MA(GPIOB_PIN5) | \
                                 PIN_DRVR_4MA(GPIOB_PIN6) | \
                                 PIN_DRVR_4MA(GPIOB_PIN7) | \
                                 PIN_DRVR_4MA(GPIOB_PIN8) | \
                                 PIN_DRVR_4MA(GPIOB_PIN9) | \
                                 PIN_DRVR_4MA(GPIOB_PIN10) | \
                                 PIN_DRVR_4MA(GPIOB_PIN11) | \
                                 PIN_DRVR_4MA(GPIOB_PIN12) | \
                                 PIN_DRVR_4MA(GPIOB_PIN13) | \
                                 PIN_DRVR_4MA(GPIOB_PIN14) | \
                                 PIN_DRVR_4MA(GPIOB_PIN15))
#define VAL_GPIOB_AFCFGR0       (PIN_AFIO_AF(GPIOB_PIN0, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN1, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN2, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN3, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN4, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN5, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN6, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN7, AFIO_GPIO))
#define VAL_GPIOB_AFCFGR1       (PIN_AFIO_AF(GPIOB_PIN0, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN8, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN9, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN10, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN11, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN12, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOB_PIN13, AFIO_DEFAULT) | \
                                 PIN_AFIO_AF(GPIOB_PIN14, AFIO_DEFAULT) | \
                                 PIN_AFIO_AF(GPIOB_PIN15, AFIO_GPIO))

/*
 * Port C setup.
 * Everything GPIO input with pull-up
 * PC6  - AF0 - USBD-
 * PC7  - AF0 - USBD+
 */
#define VAL_GPIOC_DIR           0x0000      /* PC15...PC0 */
#define VAL_GPIOC_INE           0xFF3F      /* PC15...PC0 */
#define VAL_GPIOC_PU            0xFF3F      /* PC15...PC0 */
#define VAL_GPIOC_PD            0x0000      /* PC15...PC0 */
#define VAL_GPIOC_OD            0x0000      /* PC15...PC0 */
#define VAL_GPIOC_DRV           0x0000      /* PC15...PC0 */
#define VAL_GPIOC_AFCFG0        0x00111111  /*  PC7...PC0 */
#define VAL_GPIOC_AFCFG1        0x11111111  /* PC15...PC8 */
#define VAL_GPIOC_DIRCR         (PIN_MODE_INPUT(GPIOC_PIN0) | \
                                 PIN_MODE_INPUT(GPIOC_PIN1) | \
                                 PIN_MODE_INPUT(GPIOC_PIN2) | \
                                 PIN_MODE_INPUT(GPIOC_PIN3) | \
                                 PIN_MODE_INPUT(GPIOC_PIN4) | \
                                 PIN_MODE_INPUT(GPIOC_PIN5) | \
                                 PIN_MODE_INPUT(GPIOC_PIN6) | \
                                 PIN_MODE_INPUT(GPIOC_PIN7) | \
                                 PIN_MODE_INPUT(GPIOC_PIN8) | \
                                 PIN_MODE_INPUT(GPIOC_PIN9) | \
                                 PIN_MODE_INPUT(GPIOC_PIN10) | \
                                 PIN_MODE_INPUT(GPIOC_PIN11) | \
                                 PIN_MODE_INPUT(GPIOC_PIN12) | \
                                 PIN_MODE_INPUT(GPIOC_PIN13) | \
                                 PIN_MODE_INPUT(GPIOC_PIN14) | \
                                 PIN_MODE_INPUT(GPIOC_PIN15))
#define VAL_GPIOC_INER          (PIN_INPUT_ENABLE(GPIOC_PIN0) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN1) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN2) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN3) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN4) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN5) | \
                                 PIN_INPUT_DISABLE(GPIOC_PIN6) | \
                                 PIN_INPUT_DISABLE(GPIOC_PIN7) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN8) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN9) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN10) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN11) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN12) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN13) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN14) | \
                                 PIN_INPUT_ENABLE(GPIOC_PIN15))
#define VAL_GPIOC_PUR           (PIN_PULLUP_ENABLE(GPIOC_PIN0) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN1) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN2) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN3) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN4) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN5) | \
                                 PIN_PULLUP_DISABLE(GPIOC_PIN6) | \
                                 PIN_PULLUP_DISABLE(GPIOC_PIN7) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN8) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN9) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN10) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN11) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN12) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN13) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN14) | \
                                 PIN_PULLUP_ENABLE(GPIOC_PIN15))
#define VAL_GPIOC_PDR           (PIN_PULLDOWN_DISABLE(GPIOC_PIN0) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN1) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN2) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN3) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN4) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN5) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN6) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN7) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN8) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN9) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN10) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN11) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN12) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN13) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN14) | \
                                 PIN_PULLDOWN_DISABLE(GPIOC_PIN15))
#define VAL_GPIOC_ODR           (PIN_ODR_PUSHPULL(GPIOC_PIN0) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN1) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN2) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN3) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN4) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN5) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN6) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN7) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN8) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN9) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN10) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN11) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN12) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN13) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN14) | \
                                 PIN_ODR_PUSHPULL(GPIOC_PIN15))
#define VAL_GPIOC_DRVR          (PIN_DRVR_4MA(GPIOC_PIN0) | \
                                 PIN_DRVR_4MA(GPIOC_PIN1) | \
                                 PIN_DRVR_4MA(GPIOC_PIN2) | \
                                 PIN_DRVR_4MA(GPIOC_PIN3) | \
                                 PIN_DRVR_4MA(GPIOC_PIN4) | \
                                 PIN_DRVR_4MA(GPIOC_PIN5) | \
                                 PIN_DRVR_4MA(GPIOC_PIN6) | \
                                 PIN_DRVR_4MA(GPIOC_PIN7) | \
                                 PIN_DRVR_4MA(GPIOC_PIN8) | \
                                 PIN_DRVR_4MA(GPIOC_PIN9) | \
                                 PIN_DRVR_4MA(GPIOC_PIN10) | \
                                 PIN_DRVR_4MA(GPIOC_PIN11) | \
                                 PIN_DRVR_4MA(GPIOC_PIN12) | \
                                 PIN_DRVR_4MA(GPIOC_PIN13) | \
                                 PIN_DRVR_4MA(GPIOC_PIN14) | \
                                 PIN_DRVR_4MA(GPIOC_PIN15))
#define VAL_GPIOC_AFCFGR0       (PIN_AFIO_AF(GPIOC_PIN0, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN1, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN2, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN3, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN4, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN5, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN6, AFIO_DEFAULT) | \
                                 PIN_AFIO_AF(GPIOC_PIN7, AFIO_DEFAULT))
#define VAL_GPIOC_AFCFGR1       (PIN_AFIO_AF(GPIOC_PIN0, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN8, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN9, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN10, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN11, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN12, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN13, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN14, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOC_PIN15, AFIO_GPIO))

/*
 * Port D setup.
 * Everything GPIO input with pull-up
 */
#define VAL_GPIOD_DIRCR         (PIN_MODE_INPUT(GPIOD_PIN0) | \
                                 PIN_MODE_INPUT(GPIOD_PIN1) | \
                                 PIN_MODE_INPUT(GPIOD_PIN2) | \
                                 PIN_MODE_INPUT(GPIOD_PIN3) | \
                                 PIN_MODE_INPUT(GPIOD_PIN4) | \
                                 PIN_MODE_INPUT(GPIOD_PIN5) | \
                                 PIN_MODE_INPUT(GPIOD_PIN6) | \
                                 PIN_MODE_INPUT(GPIOD_PIN7) | \
                                 PIN_MODE_INPUT(GPIOD_PIN8) | \
                                 PIN_MODE_INPUT(GPIOD_PIN9) | \
                                 PIN_MODE_INPUT(GPIOD_PIN10) | \
                                 PIN_MODE_INPUT(GPIOD_PIN11) | \
                                 PIN_MODE_INPUT(GPIOD_PIN12) | \
                                 PIN_MODE_INPUT(GPIOD_PIN13) | \
                                 PIN_MODE_INPUT(GPIOD_PIN14) | \
                                 PIN_MODE_INPUT(GPIOD_PIN15))
#define VAL_GPIOD_INER          (PIN_INPUT_ENABLE(GPIOD_PIN0) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN1) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN2) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN3) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN4) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN5) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN6) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN7) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN8) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN9) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN10) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN11) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN12) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN13) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN14) | \
                                 PIN_INPUT_ENABLE(GPIOD_PIN15))
#define VAL_GPIOD_PUR           (PIN_PULLUP_ENABLE(GPIOD_PIN0) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN1) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN2) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN3) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN4) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN5) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN6) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN7) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN8) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN9) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN10) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN11) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN12) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN13) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN14) | \
                                 PIN_PULLUP_ENABLE(GPIOD_PIN15))
#define VAL_GPIOD_PDR           (PIN_PULLDOWN_DISABLE(GPIOD_PIN0) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN1) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN2) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN3) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN4) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN5) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN6) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN7) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN8) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN9) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN10) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN11) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN12) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN13) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN14) | \
                                 PIN_PULLDOWN_DISABLE(GPIOD_PIN15))
#define VAL_GPIOD_ODR           (PIN_ODR_PUSHPULL(GPIOD_PIN0) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN1) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN2) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN3) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN4) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN5) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN6) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN7) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN8) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN9) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN10) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN11) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN12) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN13) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN14) | \
                                 PIN_ODR_PUSHPULL(GPIOD_PIN15))
#define VAL_GPIOD_DRVR          (PIN_DRVR_4MA(GPIOD_PIN0) | \
                                 PIN_DRVR_4MA(GPIOD_PIN1) | \
                                 PIN_DRVR_4MA(GPIOD_PIN2) | \
                                 PIN_DRVR_4MA(GPIOD_PIN3) | \
                                 PIN_DRVR_4MA(GPIOD_PIN4) | \
                                 PIN_DRVR_4MA(GPIOD_PIN5) | \
                                 PIN_DRVR_4MA(GPIOD_PIN6) | \
                                 PIN_DRVR_4MA(GPIOD_PIN7) | \
                                 PIN_DRVR_4MA(GPIOD_PIN8) | \
                                 PIN_DRVR_4MA(GPIOD_PIN9) | \
                                 PIN_DRVR_4MA(GPIOD_PIN10) | \
                                 PIN_DRVR_4MA(GPIOD_PIN11) | \
                                 PIN_DRVR_4MA(GPIOD_PIN12) | \
                                 PIN_DRVR_4MA(GPIOD_PIN13) | \
                                 PIN_DRVR_4MA(GPIOD_PIN14) | \
                                 PIN_DRVR_4MA(GPIOD_PIN15))
#define VAL_GPIOD_AFCFGR0       (PIN_AFIO_AF(GPIOD_PIN0, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN1, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN2, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN3, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN4, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN5, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN6, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN7, AFIO_GPIO))
#define VAL_GPIOD_AFCFGR1       (PIN_AFIO_AF(GPIOD_PIN0, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN8, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN9, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN10, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN11, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN12, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN13, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN14, AFIO_GPIO) | \
                                 PIN_AFIO_AF(GPIOD_PIN15, AFIO_GPIO))

/*
 * EXTI setup.
 */
#define VAL_ESSR0               0x00000000
#define VAL_ESSR1               0x00000000

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

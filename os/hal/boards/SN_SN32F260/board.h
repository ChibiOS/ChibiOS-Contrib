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

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for Generic SN32F260 Board
 */

/*
 * Board identifier.
 */
#define BOARD_GENERIC_SN32_F260
#define BOARD_NAME "SN32F260"

/*
 * MCU type as defined in the SN32 header.
 */
#define SN32F260

/*
 * IO pins assignments.
 */
#define GPIOA_PIN0 0U
#define GPIOA_PIN1 1U
#define GPIOA_PIN2 2U
#define GPIOA_PIN3 3U
#define GPIOA_PIN4 4U
#define GPIOA_PIN5 5U
#define GPIOA_PIN6 6U
#define GPIOA_PIN7 7U
#define GPIOA_PIN8 8U
#define GPIOA_PIN9 9U
#define GPIOA_PIN10 10U
#define GPIOA_PIN11 11U
#define GPIOA_PIN12 12U
#define GPIOA_PIN13 13U
#define GPIOA_PIN14 14U
#define GPIOA_PIN15 15U

#define GPIOB_PIN0 0U
#define GPIOB_PIN1 1U
#define GPIOB_PIN2 2U
#define GPIOB_PIN3 3U
#define GPIOB_PIN4 4U
#define GPIOB_PIN5 5U

#define GPIOC_PIN0 0U
#define GPIOC_PIN1 1U
#define GPIOC_PIN2 2U
#define GPIOC_PIN3 3U
#define GPIOC_PIN4 4U
#define GPIOC_PIN5 5U
#define GPIOC_PIN6 6U
#define GPIOC_PIN7 7U
#define GPIOC_PIN8 8U
#define GPIOC_PIN9 9U
#define GPIOC_PIN10 10U

#define GPIOD_PIN0 0U
#define GPIOD_PIN1 1U
#define GPIOD_PIN2 2U
#define GPIOD_PIN3 3U
#define GPIOD_PIN4 4U
#define GPIOD_PIN5 5U
#define GPIOD_PIN6 6U
#define GPIOD_PIN7 7U
#define GPIOD_PIN8 8U

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the SN32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)       (0U << ((n)))
#define PIN_MODE_OUTPUT(n)      (1U << ((n)))

#define PIN_CFG_PULLUP(n)       (0U << ((n*2))) // Pull-up
#define PIN_CFG_SCHMITT_EN(n)   (2U << ((n*2))) // Floating
#define PIN_CFG_SCHMITT_DIS(n)  (3U << ((n*2))) // Input buffer disconnected, alway read as zero.

// Define GPIO register values used by pal_default_config.
// The following values match the chip reset values, all GPIO pins as floating inputs.

#define VAL_GPIOA_MODE \
    ( PIN_MODE_INPUT(GPIOA_PIN0) \
    | PIN_MODE_INPUT(GPIOA_PIN1) \
    | PIN_MODE_INPUT(GPIOA_PIN2) \
    | PIN_MODE_INPUT(GPIOA_PIN3) \
    | PIN_MODE_INPUT(GPIOA_PIN4) \
    | PIN_MODE_INPUT(GPIOA_PIN5) \
    | PIN_MODE_INPUT(GPIOA_PIN6) \
    | PIN_MODE_INPUT(GPIOA_PIN7) \
    | PIN_MODE_INPUT(GPIOA_PIN8) \
    | PIN_MODE_INPUT(GPIOA_PIN9) \
    | PIN_MODE_INPUT(GPIOA_PIN10) \
    | PIN_MODE_INPUT(GPIOA_PIN11) \
    | PIN_MODE_INPUT(GPIOA_PIN12) \
    | PIN_MODE_INPUT(GPIOA_PIN13) \
    | PIN_MODE_INPUT(GPIOA_PIN14) \
    | PIN_MODE_INPUT(GPIOA_PIN15) )
#define VAL_GPIOA_CFG \
    ( PIN_CFG_SCHMITT_EN(GPIOA_PIN0) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN1) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN2) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN3) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN4) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN5) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN6) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN7) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN8) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN9) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN10) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN11) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN12) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN13) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN14) \
    | PIN_CFG_SCHMITT_EN(GPIOA_PIN15) )

#define VAL_GPIOB_MODE \
    ( PIN_MODE_INPUT(GPIOB_PIN0) \
    | PIN_MODE_INPUT(GPIOB_PIN1) \
    | PIN_MODE_INPUT(GPIOB_PIN2) \
    | PIN_MODE_INPUT(GPIOB_PIN3) \
    | PIN_MODE_INPUT(GPIOB_PIN4) \
    | PIN_MODE_INPUT(GPIOB_PIN5) )
#define VAL_GPIOB_CFG \
    ( PIN_CFG_SCHMITT_EN(GPIOB_PIN0) \
    | PIN_CFG_SCHMITT_EN(GPIOB_PIN1) \
    | PIN_CFG_SCHMITT_EN(GPIOB_PIN2) \
    | PIN_CFG_SCHMITT_EN(GPIOB_PIN3) \
    | PIN_CFG_SCHMITT_EN(GPIOB_PIN4) \
    | PIN_CFG_SCHMITT_EN(GPIOB_PIN5) )

#define VAL_GPIOC_MODE \
    ( PIN_MODE_INPUT(GPIOC_PIN0) \
    | PIN_MODE_INPUT(GPIOC_PIN1) \
    | PIN_MODE_INPUT(GPIOC_PIN2) \
    | PIN_MODE_INPUT(GPIOC_PIN3) \
    | PIN_MODE_INPUT(GPIOC_PIN4) \
    | PIN_MODE_INPUT(GPIOC_PIN5) \
    | PIN_MODE_INPUT(GPIOC_PIN6) \
    | PIN_MODE_INPUT(GPIOC_PIN7) \
    | PIN_MODE_INPUT(GPIOC_PIN8) \
    | PIN_MODE_INPUT(GPIOC_PIN9) \
    | PIN_MODE_INPUT(GPIOC_PIN10) )
#define VAL_GPIOC_CFG \
    ( PIN_CFG_SCHMITT_EN(GPIOC_PIN0) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN1) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN2) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN3) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN4) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN5) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN6) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN7) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN8) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN9) \
    | PIN_CFG_SCHMITT_EN(GPIOC_PIN10) )

#define VAL_GPIOD_MODE \
    ( PIN_MODE_INPUT(GPIOD_PIN0) \
    | PIN_MODE_INPUT(GPIOD_PIN1) \
    | PIN_MODE_INPUT(GPIOD_PIN2) \
    | PIN_MODE_INPUT(GPIOD_PIN3) \
    | PIN_MODE_INPUT(GPIOD_PIN4) \
    | PIN_MODE_INPUT(GPIOD_PIN5) \
    | PIN_MODE_INPUT(GPIOD_PIN6) \
    | PIN_MODE_INPUT(GPIOD_PIN7) \
    | PIN_MODE_INPUT(GPIOD_PIN8) )
#define VAL_GPIOD_CFG \
    ( PIN_CFG_SCHMITT_EN(GPIOD_PIN0) \
    | PIN_CFG_SCHMITT_EN(GPIOD_PIN1) \
    | PIN_CFG_SCHMITT_EN(GPIOD_PIN2) \
    | PIN_CFG_SCHMITT_EN(GPIOD_PIN3) \
    | PIN_CFG_SCHMITT_EN(GPIOD_PIN4) \
    | PIN_CFG_SCHMITT_EN(GPIOD_PIN5) \
    | PIN_CFG_SCHMITT_EN(GPIOD_PIN6) \
    | PIN_CFG_SCHMITT_EN(GPIOD_PIN7) \
    | PIN_CFG_SCHMITT_EN(GPIOD_PIN8) )

#if !defined(_FROM_ASM_)
#    ifdef __cplusplus
extern "C" {
#    endif
void boardInit(void);
#    ifdef __cplusplus
}
#    endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */

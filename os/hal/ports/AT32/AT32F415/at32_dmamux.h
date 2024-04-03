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

/**
 * @file    AT32F415/at32_dmamux.h
 * @brief   AT32F415 DMAMUX handler header.
 *
 * @addtogroup AT32F415_DMAMUX
 * @{
 */

#ifndef AT32_DMAMUX_H
#define AT32_DMAMUX_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    DMAMUX request sources
 * @{
 */
#define AT32_DMAMUX_ADC1          1
#define AT32_DMAMUX_SPI1_RX       9
#define AT32_DMAMUX_SPI1_TX       10
#define AT32_DMAMUX_SPI2_RX       11
#define AT32_DMAMUX_SPI2_TX       12
#define AT32_DMAMUX_USART1_RX     25
#define AT32_DMAMUX_USART1_TX     26
#define AT32_DMAMUX_USART2_RX     27
#define AT32_DMAMUX_USART2_TX     28
#define AT32_DMAMUX_USART3_RX     29
#define AT32_DMAMUX_USART3_TX     30
#define AT32_DMAMUX_UART4_RX      31
#define AT32_DMAMUX_UART4_TX      32
#define AT32_DMAMUX_UART5_RX      33
#define AT32_DMAMUX_UART5_TX      34
#define AT32_DMAMUX_I2C1_RX       41
#define AT32_DMAMUX_I2C1_TX       42
#define AT32_DMAMUX_I2C2_RX       43
#define AT32_DMAMUX_I2C2_TX       44
#define AT32_DMAMUX_SDIO1         49
#define AT32_DMAMUX_TMR1_TRIG     53
#define AT32_DMAMUX_TMR1_HALL     54
#define AT32_DMAMUX_TMR1_OVERFLOW 55
#define AT32_DMAMUX_TMR1_CH1      56
#define AT32_DMAMUX_TMR1_CH2      57
#define AT32_DMAMUX_TMR1_CH3      58
#define AT32_DMAMUX_TMR1_CH4      59
#define AT32_DMAMUX_TMR2_TRIG     61
#define AT32_DMAMUX_TMR2_OVERFLOW 63
#define AT32_DMAMUX_TMR2_CH1      64
#define AT32_DMAMUX_TMR2_CH2      65
#define AT32_DMAMUX_TMR2_CH3      66
#define AT32_DMAMUX_TMR2_CH4      67
#define AT32_DMAMUX_TMR3_TRIG     69
#define AT32_DMAMUX_TMR3_OVERFLOW 71
#define AT32_DMAMUX_TMR3_CH1      72
#define AT32_DMAMUX_TMR3_CH2      73
#define AT32_DMAMUX_TMR3_CH3      74
#define AT32_DMAMUX_TMR3_CH4      75
#define AT32_DMAMUX_TMR4_TRIG     77
#define AT32_DMAMUX_TMR4_OVERFLOW 79
#define AT32_DMAMUX_TMR4_CH1      80
#define AT32_DMAMUX_TMR4_CH2      81
#define AT32_DMAMUX_TMR4_CH3      82
#define AT32_DMAMUX_TMR4_CH4      83
#define AT32_DMAMUX_TMR5_TRIG     85
#define AT32_DMAMUX_TMR5_OVERFLOW 87
#define AT32_DMAMUX_TMR5_CH1      88
#define AT32_DMAMUX_TMR5_CH2      89
#define AT32_DMAMUX_TMR5_CH3      90
#define AT32_DMAMUX_TMR5_CH4      91
/** @} */

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

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* AT32_DMAMUX_H */

/** @} */

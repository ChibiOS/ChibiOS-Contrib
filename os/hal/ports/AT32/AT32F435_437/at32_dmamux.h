/*
    ChibiOS - Copyright (C) 2023..2024 Zhaqian
    ChibiOS - Copyright (C) 2024 Maxjta

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
 * @file    AT32F435_437/at32_dmamux.h
 * @brief   AT32F435_437 DMAMUX handler header.
 *
 * @addtogroup AT32F435xx_DMAMUX
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
#define AT32_DMAMUX_MUXREQG1       1
#define AT32_DMAMUX_MUXREQG2       2 
#define AT32_DMAMUX_MUXREQG3       3
#define AT32_DMAMUX_MUXREQG4       4
#define AT32_DMAMUX_ADC1           5
#define AT32_DMAMUX_DAC1           6
#define AT32_DMAMUX_TMR6_OVERFLOW  8
#define AT32_DMAMUX_TMR7_OVERFLOW  9
#define AT32_DMAMUX_SPI1_RX        10
#define AT32_DMAMUX_SPI1_TX        11
#define AT32_DMAMUX_SPI2_RX        12
#define AT32_DMAMUX_SPI2_TX        13
#define AT32_DMAMUX_SPI3_RX        14
#define AT32_DMAMUX_SPI3_TX        15
#define AT32_DMAMUX_I2C1_RX        16
#define AT32_DMAMUX_I2C1_TX        17
#define AT32_DMAMUX_I2C2_RX        18
#define AT32_DMAMUX_I2C2_TX        19
#define AT32_DMAMUX_I2C3_RX        20
#define AT32_DMAMUX_I2C3_TX        21
#define AT32_DMAMUX_USART1_RX      24
#define AT32_DMAMUX_USART1_TX      25
#define AT32_DMAMUX_USART2_RX      26
#define AT32_DMAMUX_USART2_TX      27
#define AT32_DMAMUX_USART3_RX      28
#define AT32_DMAMUX_USART3_TX      29
#define AT32_DMAMUX_UART4_RX       30
#define AT32_DMAMUX_UART4_TX       31
#define AT32_DMAMUX_UART5_RX       32
#define AT32_DMAMUX_UART5_TX       33
#define AT32_DMAMUX_ADC2           36
#define AT32_DMAMUX_ADC3           37
#define AT32_DMAMUX_SDIO1          39
#define AT32_DMAMUX_QSPI1          40
#define AT32_DMAMUX_DAC2           41
#define AT32_DMAMUX_TMR1_CH1       42
#define AT32_DMAMUX_TMR1_CH2       43
#define AT32_DMAMUX_TMR1_CH3       44
#define AT32_DMAMUX_TMR1_CH4       45
#define AT32_DMAMUX_TMR1_OVERFLOW  46
#define AT32_DMAMUX_TMR1_TRIG      47
#define AT32_DMAMUX_TMR1_HALL      48
#define AT32_DMAMUX_TMR8_CH1       49
#define AT32_DMAMUX_TMR8_CH2       50
#define AT32_DMAMUX_TMR8_CH3       51
#define AT32_DMAMUX_TMR8_CH4       52
#define AT32_DMAMUX_TMR8_OVERFLOW  53
#define AT32_DMAMUX_TMR8_TRIG      54
#define AT32_DMAMUX_TMR8_HALL      55
#define AT32_DMAMUX_TMR2_CH1       56
#define AT32_DMAMUX_TMR2_CH2       57
#define AT32_DMAMUX_TMR2_CH3       58
#define AT32_DMAMUX_TMR2_CH4       59
#define AT32_DMAMUX_TMR2_OVERFLOW  60
#define AT32_DMAMUX_TMR3_CH1       61
#define AT32_DMAMUX_TMR3_CH2       62
#define AT32_DMAMUX_TMR3_CH3       63
#define AT32_DMAMUX_TMR3_CH4       64
#define AT32_DMAMUX_TMR3_OVERFLOW  65
#define AT32_DMAMUX_TMR3_TRIG      66
#define AT32_DMAMUX_TMR4_CH1       67
#define AT32_DMAMUX_TMR4_CH2       68
#define AT32_DMAMUX_TMR4_CH3       69
#define AT32_DMAMUX_TMR4_CH4       70
#define AT32_DMAMUX_TMR4_OVERFLOW  71
#define AT32_DMAMUX_TMR5_CH1       72
#define AT32_DMAMUX_TMR5_CH2       73
#define AT32_DMAMUX_TMR5_CH3       74
#define AT32_DMAMUX_TMR5_CH4       75
#define AT32_DMAMUX_TMR5_OVERFLOW  76
#define AT32_DMAMUX_TMR5_TRIG      77
#define AT32_DMAMUX_TMR20_CH1      86
#define AT32_DMAMUX_TMR20_CH2      87
#define AT32_DMAMUX_TMR20_CH3      88
#define AT32_DMAMUX_TMR20_CH4      89
#define AT32_DMAMUX_TMR20_OVERFLOW 90
#define AT32_DMAMUX_TMR20_TRIG     93
#define AT32_DMAMUX_TMR20_HALL     94
#define AT32_DMAMUX_SDIO2          103
#define AT32_DMAMUX_QSPI2          104
#define AT32_DMAMUX_DVP            105
#define AT32_DMAMUX_SPI4_RX        106
#define AT32_DMAMUX_SPI4_TX        107
#define AT32_DMAMUX_I2S2_EXT_RX    110
#define AT32_DMAMUX_I2S2_EXT_TX    111
#define AT32_DMAMUX_I2S3_EXT_RX    112
#define AT32_DMAMUX_I2S3_EXT_TX    113
#define AT32_DMAMUX_USART6_RX      114
#define AT32_DMAMUX_USART6_TX      115
#define AT32_DMAMUX_UART7_RX       116
#define AT32_DMAMUX_UART7_TX       117
#define AT32_DMAMUX_UART8_RX       118
#define AT32_DMAMUX_UART8_TX       119
#define AT32_DMAMUX_TMR2_TRIG      126
#define AT32_DMAMUX_TMR4_TRIG      127
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

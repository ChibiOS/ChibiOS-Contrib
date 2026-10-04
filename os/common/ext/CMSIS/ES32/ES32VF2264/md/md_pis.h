/**********************************************************************************
 *
 * @file    md_pis.h
 * @brief   Header file of PIS module driver.
 *
 * @date    19 July 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          19 July 2022    Lisq            the first version
 *
 * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 **********************************************************************************
 */

#ifndef __MD_PIS_H__
#define __MD_PIS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* Includes ------------------------------------------------------------------ */
#include "md_utils.h"

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/* Exported Macros ----------------------------------------------------------- */

/**
  * @addtogroup Micro_Driver
  * @{
  */

/**
  * @defgroup MD_PIS PIS
  * @brief PIS micro driver
  * @{
  */

/* Exported Types ------------------------------------------------------------ */

/** @defgroup MD_PIS_Public_Types PIS Public Types
  * @{
  */

/**
  * @brief Producer entry
  */
typedef enum
{
    MD_PIS_NON                 = 0x0U,  /**< No async */
    MD_PIS_GPIO_PIN0           = 0x10U, /**< Pin0, level,support async */
    MD_PIS_GPIO_PIN1           = 0x11U, /**< Pin1, level,support async */
    MD_PIS_GPIO_PIN2           = 0x12U, /**< Pin2, level,support async */
    MD_PIS_GPIO_PIN3           = 0x13U, /**< Pin3, level,support async */
    MD_PIS_GPIO_PIN4           = 0x14U, /**< Pin4, level,support async */
    MD_PIS_GPIO_PIN5           = 0x15U, /**< Pin5, level,support async */
    MD_PIS_GPIO_PIN6           = 0x16U, /**< Pin6, level,support async */
    MD_PIS_GPIO_PIN7           = 0x17U, /**< Pin7, level,support async */
    MD_PIS_GPIO_PIN8           = 0x18U, /**< Pin8, level,support async */
    MD_PIS_GPIO_PIN9           = 0x19U, /**< Pin9, level,support async */
    MD_PIS_GPIO_PIN10          = 0x1aU, /**< Pin10, level,support async */
    MD_PIS_GPIO_PIN11          = 0x1bU, /**< Pin11, level,support async */
    MD_PIS_GPIO_PIN12          = 0x1cU, /**< Pin12, level,support async */
    MD_PIS_GPIO_PIN13          = 0x1dU, /**< Pin13, level,support async */
    MD_PIS_GPIO_PIN14          = 0x1eU, /**< Pin14, level,support async */
    MD_PIS_GPIO_PIN15          = 0x1fU, /**< Pin15, level,support async */
    MD_PIS_CLK_HSCO            = 0x20U, /**< CLK: HSCO, level,support async */
    MD_PIS_CLK_LSCO            = 0x21U, /**< CLK: LSCO, level,support async */
    MD_PIS_CLK_BUZ             = 0x22U, /**< PCLK: BUZ, level,support async */
    MD_PIS_ADC0_INSERT         = 0x60U, /**< ADC0 insert, pclk2 pulse,support async */
    MD_PIS_ADC0_NORMAL         = 0x61U, /**< ADC0 normal, pclk2 pulse,support async */
    MD_PIS_ADC0_AWDT           = 0x62U, /**< ADC0 AWDT */
    MD_PIS_LVD                 = 0x70U, /**< LVD, level,support async */
    MD_PIS_UART0_RESERVE0      = 0x80U, /**< Uart0 reserve bit 0 */
    MD_PIS_UART0_RESERVE1      = 0x81U, /**< Uart0 reserve bit 1 */
    MD_PIS_UART0_RESERVE2      = 0x82U, /**< Uart0 reserve bit 2 */
    MD_PIS_UART0_RTSOUT        = 0x83U, /**< Uart0 rtsout, level */
    MD_PIS_UART0_TXOUT         = 0x84U, /**< Uart0 txout, level */
    MD_PIS_UART0_SYN_SEND      = 0x85U, /**< Uart0 syn send, pulse */
    MD_PIS_UART0_SYN_RECV      = 0x86U, /**< Uart0 syn recv, pulse */
    MD_PIS_UART1_RESERVE0      = 0x90U, /**< Uart1 reserve bit 0 */
    MD_PIS_UART1_RESERVE1      = 0x91U, /**< Uart1 reserve bit 1 */
    MD_PIS_UART1_RESERVE2      = 0x92U, /**< Uart1 reserve bit 2 */
    MD_PIS_UART1_RTSOUT        = 0x93U, /**< Uart1 rtsout, level */
    MD_PIS_UART1_TXOUT         = 0x94U, /**< Uart1 txout, level  */
    MD_PIS_UART1_SYN_SEND      = 0x95U, /**< Uart1 syn send, pulse  */
    MD_PIS_UART1_SYN_RECV      = 0x96U, /**< Uart1 syn recv, pulse  */
    MD_PIS_UART2_RESERVE0      = 0xa0U, /**< Uart2 reserve bit 0 */
    MD_PIS_UART2_RESERVE1      = 0xa1U, /**< Uart2 reserve bit 1 */
    MD_PIS_UART2_RESERVE2      = 0xa2U, /**< Uart2 reserve bit 2 */
    MD_PIS_UART2_RTSOUT        = 0xa3U, /**< Uart2 rtsout, level  */
    MD_PIS_UART2_TXOUT         = 0xa4U, /**< Uart2 txout, level  */
    MD_PIS_UART2_SYN_SEND      = 0xa5U, /**< Uart2 syn send, pulse  */
    MD_PIS_UART2_SYN_RECV      = 0xa6U, /**< Uart2 syn recv, pulse  */
    MD_PIS_UART3_RESERVE0      = 0xb0U, /**< Uart3 reserve bit 0 */
    MD_PIS_UART3_RESERVE1      = 0xb1U, /**< Uart3 reserve bit 1 */
    MD_PIS_UART3_RESERVE2      = 0xb2U, /**< Uart3 reserve bit 2 */
    MD_PIS_UART3_RTSOUT        = 0xb3U, /**< Uart3 rtsout, level  */
    MD_PIS_UART3_TXOUT         = 0xb4U, /**< Uart3 txout, level  */
    MD_PIS_UART3_SYN_SEND      = 0xb5U, /**< Uart3 syn send, pulse  */
    MD_PIS_UART3_SYN_RECV      = 0xb6U, /**< Uart3 syn recv, pulse  */
    MD_PIS_UART4_RESERVE0      = 0xc0U, /**< Uart4 reserve bit 0 */
    MD_PIS_UART4_RESERVE1      = 0xc1U, /**< Uart4 reserve bit 1 */
    MD_PIS_UART4_RESERVE2      = 0xc2U, /**< Uart4 reserve bit 2 */
    MD_PIS_UART4_RTSOUT        = 0xc3U, /**< Uart4 rtsout, level  */
    MD_PIS_UART4_TXOUT         = 0xc4U, /**< Uart4 txout, level  */
    MD_PIS_UART4_SYN_SEND      = 0xc5U, /**< Uart4 syn send, pulse  */
    MD_PIS_UART4_SYN_RECV      = 0xc6U, /**< Uart4 syn recv, pulse  */
    MD_PIS_SPI0_RECV           = 0xe0U, /**< Spi0 recv, plck1 pulse */
    MD_PIS_SPI0_SEND           = 0xe1U, /**< Spi0 send, plck1 pulse */
    MD_PIS_SPI0_NE             = 0xe2U, /**< Spi0 ne, plck1 level */
    MD_PIS_SPI1_RECV           = 0xf0U, /**< Spi1 recv, plck1 pulse */
    MD_PIS_SPI1_SEND           = 0xf1U, /**< Spi1 send, plck1 pulse */
    MD_PIS_SPI1_NE             = 0xf2U, /**< Spi1 ne, plck1 level */
    MD_PIS_I2C0_RECV           = 0x100U,    /**< I2c0 recv, plck1 level */
    MD_PIS_I2C0_SEND           = 0x101U,    /**< I2c0 send, plck1 level */
    MD_PIS_I2C1_RECV           = 0x110U,    /**< I2c1 recv, plck1 level */
    MD_PIS_I2C1_SEND           = 0x111U,    /**< I2c1 send, plck1 level */
    MD_PIS_TIMER0_UPDATA       = 0x120U,    /**< Timer0 updata, plck1 pulse */
    MD_PIS_TIMER0_TRIG         = 0x121U,    /**< Timer0 trig, plck1 pulse */
    MD_PIS_TIMER0_INPUT_1      = 0x122U,    /**< Timer0 chan1 input catch, plck1 pulse */
    MD_PIS_TIMER0_OUTPUT_1     = 0x122U,    /**< Timer0 chan1 output compare, plck1 pulse */
    MD_PIS_TIMER0_INPUT_2      = 0x124U,    /**< Timer0 chan2 input catch, plck1 pulse */
    MD_PIS_TIMER0_OUTPUT_2     = 0x124U,    /**< Timer0 chan2 output compare, plck1 pulse */
    MD_PIS_TIMER0_INPUT_3      = 0x126U,    /**< Timer0 chan3 input catch, plck1 pulse */
    MD_PIS_TIMER0_OUTPUT_3     = 0x126U,    /**< Timer0 chan3 output compare, plck1 pulse */
    MD_PIS_TIMER0_INPUT_4      = 0x128U,    /**< Timer0 chan4 input catch, plck1 pulse */
    MD_PIS_TIMER0_OUTPUT_4     = 0x128U,    /**< Timer0 chan4 output compare, plck1 pulse */
    MD_PIS_TIMER5_UPDATA       = 0x1c0U,    /**< Timer5 updata, plck1 pulse */
    MD_PIS_TIMER5_TRIG         = 0x1c1U,    /**< Timer5 trig, plck1 pulse */
    MD_PIS_TIMER5_INPUT_1      = 0x1c2U,    /**< Timer5 chan1 input catch, plck1 pulse */
    MD_PIS_TIMER5_OUTPUT_1     = 0x1c2U,    /**< Timer5 chan1 output compare, plck1 pulse */
    MD_PIS_TIMER5_INPUT_2      = 0x1c4U,    /**< Timer5 chan2 input catch, plck1 pulse */
    MD_PIS_TIMER5_OUTPUT_2     = 0x1c4U,    /**< Timer5 chan2 output compare, plck1 pulse */
    MD_PIS_TIMER5_INPUT_3      = 0x1c6U,    /**< Timer5 chan3 input catch, plck1 pulse */
    MD_PIS_TIMER5_OUTPUT_3     = 0x1c6U,    /**< Timer5 chan3 output compare, plck1 pulse */
    MD_PIS_TIMER5_INPUT_4      = 0x1c8U,    /**< Timer5 chan4 input catch, plck1 pulse */
    MD_PIS_TIMER5_OUTPUT_4     = 0x1c8U,    /**< Timer5 chan4 output compare, plck1 pulse */
    MD_PIS_TIMER6_UPDATA       = 0x1d0U,    /**< Timer6 updata, plck1 pulse */
    MD_PIS_TIMER6_TRIG         = 0x1d1U,    /**< Timer6 trig, plck1 pulse */
    MD_PIS_TIMER6_INPUT_1      = 0x1d2U,    /**< Timer6 chan1 input catch, plck1 pulse */
    MD_PIS_TIMER6_OUTPUT_1     = 0x1d2U,    /**< Timer6 chan1 output compare, plck1 pulse */
    MD_PIS_TIMER6_INPUT_2      = 0x1d4U,    /**< Timer6 chan2 input catch, plck1 pulse */
    MD_PIS_TIMER6_OUTPUT_2     = 0x1d4U,    /**< Timer6 chan2 output compare, plck1 pulse */
    MD_PIS_TIMER6_INPUT_3      = 0x1d6U,    /**< Timer6 chan3 input catch, plck1 pulse */
    MD_PIS_TIMER6_OUTPUT_3     = 0x1d6U,    /**< Timer6 chan3 output compare, plck1 pulse */
    MD_PIS_TIMER6_INPUT_4      = 0x1d8U,    /**< Timer6 chan4 input catch, plck1 pulse */
    MD_PIS_TIMER6_OUTPUT_4     = 0x1d8U,    /**< Timer6 chan4 output compare, plck1 pulse */
    MD_PIS_TIMER7_UPDATA       = 0x1e0U,    /**< Timer7 updata, plck1 pulse */
    MD_PIS_TIMER7_TRIG         = 0x1e1U,    /**< Timer7 trig, plck1 pulse */
    MD_PIS_TIMER7_INPUT_1      = 0x1e2U,    /**< Timer7 chan1 input catch, plck1 pulse */
    MD_PIS_TIMER7_OUTPUT_1     = 0x1e2U,    /**< Timer7 chan1 output compare, plck1 pulse */
    MD_PIS_TIMER7_INPUT_2      = 0x1e4U,    /**< Timer7 chan2 input catch, plck1 pulse */
    MD_PIS_TIMER7_OUTPUT_2     = 0x1e4U,    /**< Timer7 chan2 output compare, plck1 pulse */
    MD_PIS_TIMER7_INPUT_3      = 0x1e6U,    /**< Timer7 chan3 input catch, plck1 pulse */
    MD_PIS_TIMER7_OUTPUT_3     = 0x1e6U,    /**< Timer7 chan3 output compare, plck1 pulse */
    MD_PIS_TIMER7_INPUT_4      = 0x1e8U,    /**< Timer7 chan4 input catch, plck1 pulse */
    MD_PIS_TIMER7_OUTPUT_4     = 0x1e8U,    /**< Timer7 chan4 output compare, plck1 pulse */
    MD_PIS_TIMER4_UPDATA       = 0x1b0U,    /**< Timer4 updata, plck1 pulse */
    MD_PIS_TIMER4_TRIG         = 0x1b1U,    /**< Timer4 trig, plck1 pulse */
    MD_PIS_DMA_CH0             = 0x190U,    /**< DMA CH0 complete, plck1 pulse, support async */
    MD_PIS_DMA_CH1             = 0x191U,    /**< DMA CH1 complete, plck1 pulse, support async */
    MD_PIS_DMA_CH2             = 0x192U,    /**< DMA CH2 complete, plck1 pulse, support async */
    MD_PIS_DMA_CH3             = 0x193U,    /**< DMA CH3 complete, plck1 pulse, support async */
    MD_PIS_DMA_CH4             = 0x194U,    /**< DMA CH4 complete, plck1 pulse, support async */
    MD_PIS_DMA_CH5             = 0x195U,    /**< DMA CH5 complete, plck1 pulse, support async */
    MD_PIS_DMA_CH6             = 0x196U,    /**< DMA CH6 complete, plck1 pulse, support async */
    MD_PIS_DMA_ALL             = 0x19fU,    /**< DMA all channel complete, plck1 pulse, support async */
} md_pis_src_t;

/**
  * @brief Consumer entry
  */
typedef enum
{
    MD_PIS_CH4_TIMER0_ITR0   = 0x0034U, /** Tim0 internal input chan0 */
    MD_PIS_CH5_TIMER0_ITR1   = 0x0035U, /** Tim0 internal input chan1 */
    MD_PIS_CH6_TIMER0_ITR2   = 0x0036U, /** Tim0 internal input chan2 */
    MD_PIS_CH7_TIMER0_ITR3   = 0x0037U, /** Tim0 internal input chan3 */
    MD_PIS_CH4_TIMER1_ITR0   = 0x0034U, /** Tim1 internal input chan0 */
    MD_PIS_CH5_TIMER1_ITR1   = 0x0035U, /** Tim1 internal input chan1 */
    MD_PIS_CH6_TIMER1_ITR2   = 0x0036U, /** Tim1 internal input chan2 */
    MD_PIS_CH7_TIMER1_ITR3   = 0x0037U, /** Tim1 internal input chan3 */
    MD_PIS_CH4_TIMER2_ITR0   = 0x0034U, /** Tim2 internal input chan0 */
    MD_PIS_CH5_TIMER2_ITR1   = 0x0035U, /** Tim2 internal input chan1 */
    MD_PIS_CH6_TIMER2_ITR2   = 0x0036U, /** Tim2 internal input chan2 */
    MD_PIS_CH7_TIMER2_ITR3   = 0x0037U, /** Tim2 internal input chan3 */
    MD_PIS_CH4_TIMER3_ITR0   = 0x0034U, /** Tim3 internal input chan0 */
    MD_PIS_CH5_TIMER3_ITR1   = 0x0035U, /** Tim3 internal input chan1 */
    MD_PIS_CH6_TIMER3_ITR2   = 0x0036U, /** Tim3 internal input chan2 */
    MD_PIS_CH7_TIMER3_ITR3   = 0x0037U, /** Tim3 internal input chan3 */
    MD_PIS_CH4_ADC0_NORMAL   = 0x0034U, /** ADC0 normal transform */
    MD_PIS_CH5_ADC0_INSERT   = 0x0035U, /** ADC0 insert transform */
    MD_PIS_CH7_DMA_REQUEST   = 0x0037U, /** DMA request 7 */
    MD_PIS_CH7_UART4_RXD     = 0x0417U, /**< Uart4 Rx data */
    MD_PIS_CH6_UART3_RXD     = 0x0316U, /**< Uart3 Rx data */
    MD_PIS_CH5_UART2_RXD     = 0x0215U, /**< Uart2 Rx data */
    MD_PIS_CH4_UART1_RXD     = 0x0114U, /**< Uart1 Rx data */
    MD_PIS_CH3_UART0_RXD     = 0x0013U, /**< Uart0 Rx data  */
    MD_PIS_CH4_TIMER3_CH4IN  = 0x1B04U, /**< Tim3 input chan4 */
    MD_PIS_CH4_TIMER2_CH4IN  = 0x1304U, /**< Tim2 input chan4 */
    MD_PIS_CH3_SPI1_CLK      = 0x0F13U, /**< Spi1 clk */
    MD_PIS_CH7_TIMER3_CH3IN  = 0x1A07U, /**< Tim3 input chan3 */
    MD_PIS_CH7_TIMER2_CH3IN  = 0x1207U, /**< Tim2 input chan3 */
    MD_PIS_CH2_SPI1_RX       = 0x0E12U, /**< Spi1 rx */
    MD_PIS_CH6_TIMER3_CH2IN  = 0x1906U, /**< Tim3 input chan2 */
    MD_PIS_CH6_TIMER2_CH2IN  = 0x1106U, /**< Tim2 input chan2 */
    MD_PIS_CH1_SPI0_CLK      = 0x0D11U, /**< SPI0 CLK */
    MD_PIS_CH5_TIMER3_CH1IN  = 0x1805U, /**< Tim3 input chan1 */
    MD_PIS_CH5_TIMER2_CH1IN  = 0x1005U, /**< Tim2 input chan1 */
    MD_PIS_CH0_SPI0_RX       = 0x0C10U, /**< SPI0 RX */
    MD_PIS_CH4_TIMER1_CH4IN  = 0x0B04U, /**< Tim1 input chan4 */
    MD_PIS_CH4_TIMER0_CH4IN  = 0x0304U, /**< Tim0 input chan4 */
    MD_PIS_CH3_TIMER1_CH3IN  = 0x0A03U, /**< Tim1 input chan3 */
    MD_PIS_CH3_TIMER0_CH3IN  = 0x0203U, /**< Tim0 input chan3 */
    MD_PIS_CH2_TIMER1_CH2IN  = 0x0902U, /**< Tim1 input chan2 */
    MD_PIS_CH2_TIMER0_CH2IN  = 0x0102U, /**< Tim0 input chan2 */
    MD_PIS_CH1_TIMER1_CH1IN  = 0x0801U, /**< Tim1 input chan1 */
    MD_PIS_CH1_TIMER0_CH1IN  = 0x0001U, /**< Tim0 input chan1 */
    MD_PIS_CH0_TIMER0_BRKIN  = 0x0400U, /**< Tim0 break in */
    MD_PIS_TRIG_RESERVE      = 0xFFFFU, /**< Other Consumer */
} md_pis_trig_t;

/**
  * @brief input source
  */
typedef enum
{
    MD_SRC_NONE    = 0x00U, /**< None input source */
    MD_SRC_GPIO    = 0x01U, /**< gpio source */
    MD_SRC_CLK     = 0x02U, /**< reserve source */
    MD_SRC_ADC0    = 0x06U, /**< adc0 source */
    MD_SRC_LVD     = 0x07U, /**< lvd source */
    MD_SRC_UART0   = 0x08U, /**< uart0 source */
    MD_SRC_UART1   = 0x09U, /**< uart1 source */
    MD_SRC_UART2   = 0x0AU, /**< uart2 source */
    MD_SRC_UART3   = 0x0BU, /**< uart3 source */
    MD_SRC_UART4   = 0x0CU, /**< uart4 source */
    MD_SRC_SPI0    = 0x0EU, /**< spi0 source */
    MD_SRC_SPI1    = 0x0FU, /**< spi1 source */
    MD_SRC_I2C0    = 0x10U, /**< i2c0 source */
    MD_SRC_I2C1    = 0x11U, /**< i2c1 source */
    MD_SRC_TIM0    = 0x12U, /**< tim0 source */
    MD_SRC_DMA     = 0x19U, /**< dma source */
    MD_SRC_TIM4    = 0x1BU, /**< tim4 source */
    MD_SRC_TIM5    = 0x1CU, /**< tim5 source */
    MD_SRC_TIM6    = 0x1DU, /**< tim6 source */
    MD_SRC_TIM7    = 0x1EU, /**< tim7 source */
} md_pis_input_src_t;

/**
  * @brief Clock select
  */
typedef enum
{
    MD_PIS_CLK_PCLK     = 0U,   /**< APB peripherals clock */
    MD_PIS_CLK_HCLK     = 2U,   /**< AHB peripherals clock */
    MD_PIS_CLK_RESERVE  = 3U,   /**< reserve clock */
} md_pis_clock_t;

/**
  * @brief Level select
  */
typedef enum
{
    MD_PIS_EDGE_NONE    = 0U,   /**< None edge */
    MD_PIS_EDGE_UP      = 1U,   /**< Up edge */
    MD_PIS_EDGE_DOWN    = 2U,   /**< Down edge */
    MD_PIS_EDGE_UP_DOWN = 3U,   /**< Up and down edge */
} md_pis_edge_t;

/**
  * @brief Output style
  */
typedef enum
{
    MD_PIS_OUT_LEVEL = 0U,  /**< Level */
    MD_PIS_OUT_PULSE = 1U,  /**< Pulse */
} md_pis_output_t;
/**
  * @brief Sync select
  */
typedef enum
{
    MD_PIS_SYN_DIRECT         = 0U, /**< Direct */
    MD_PIS_SYN_LEVEL_ASY_APB  = 1U, /**< Producer level signal and Consumer in APB */
    MD_PIS_SYN_LEVEL_ASY_AHB  = 3U, /**< Producer level signal and Consumer in AHB */
    MD_PIS_SYN_PULSE_ASY_APB  = 4U, /**< Producer Pulse signal and Consumer in APB */
    MD_PIS_SYN_PULSE_ASY_AHB  = 6U, /**< Producer Pulse signal and Consumer in AHB */
} md_pis_syncsel_t;

/**
  * @brief Pis channel
  */
typedef enum
{
    MD_PIS_CH_0 = 0U,   /**< Channel 0 */
    MD_PIS_CH_1 = 1U,   /**< Channel 1 */
    MD_PIS_CH_2 = 2U,   /**< Channel 2 */
    MD_PIS_CH_3 = 3U,   /**< Channel 3 */
    MD_PIS_CH_4 = 4U,   /**< Channel 4 */
    MD_PIS_CH_5 = 5U,   /**< Channel 5 */
    MD_PIS_CH_6 = 6U,   /**< Channel 6 */
    MD_PIS_CH_7 = 7U,   /**< Channel 7 */
} md_pis_ch_t;

/**
  * @brief PIS init structure definition
  */
typedef struct
{
    md_pis_src_t p_src;     /**< Producer entry */
    md_pis_output_t p_output;   /**< Producer signal mode */
    md_pis_clock_t p_clk;       /**< Producer module clock */
    md_pis_edge_t p_edge;       /**< Producer module pin output edge */
    md_pis_trig_t c_trig;       /**< Consumer entry */
    md_pis_clock_t c_clk;       /**< Consumer clock */
} md_pis_init_t;

/**
  * @brief PIS state structures definition
  */
typedef enum
{
    MD_PIS_STATE_RESET   = 0x00U,   /**< Peripheral is not initialized */
    MD_PIS_STATE_READY   = 0x01U,   /**< Peripheral Initialized and ready for use */
    MD_PIS_STATE_BUSY    = 0x02U,   /**< An internal process is ongoing */
    MD_PIS_STATE_TIMEOUT = 0x03U,   /**< Timeout state */
    MD_PIS_STATE_ERROR   = 0x04U,   /**< Error */
} md_pis_state_t;

/**
  * @brief PIS modulate target
  */
typedef enum
{
    MD_PIS_UART0_TX   = 0U, /**< Modulate uart0 tx */
    MD_PIS_UART1_TX   = 1U, /**< Modulate uart1 tx */
    MD_PIS_UART2_TX   = 2U, /**< Modulate uart2 tx */
    MD_PIS_UART3_TX   = 3U, /**< Modulate uart3 tx */
    MD_PIS_UART4_TX   = 4U, /**< Modulate uart4 tx */
} md_pis_modu_targ_t;

/**
  * @brief PIS modulate level
  */
typedef enum
{
    MD_PIS_LOW_LEVEL  = 0U, /**< Modulate low level */
    MD_PIS_HIGH_LEVEL = 1U, /**< Modulate high level */
} md_pis_modu_level_t;

/**
  * @brief PIS modulate source
  */
typedef enum
{
    MD_PIS_SRC_NONE     = 0U,   /**< Stop modulate */
    MD_PIS_SRC_TIMER0   = 1U,   /**< Modulate source is TIMER0 */
    MD_PIS_SRC_TIMER5   = 4U,   /**< Modulate source is TIMER5 */
    MD_PIS_SRC_TIMER6   = 5U,   /**< Modulate source is TIMER6 */
    MD_PIS_SRC_TIMER7   = 6U,   /**< Modulate source is TIMER7 */
    MD_PIS_SRC_BUZ      = 8U,   /**< Modulate source is buz */
} md_pis_modu_src_t;

/**
  * @brief PIS modulate channel
  */
typedef enum
{
    MD_PIS_TIMER_CH1 = 0U,  /**< Src is TIMERx and choose channel 1 */
    MD_PIS_TIMER_CH2 = 1U,  /**< Src is TIMERx and choose channel 2 */
    MD_PIS_TIMER_CH3 = 2U,  /**< Src is TIMERx and choose channel 3 */
    MD_PIS_TIMER_CH4 = 3U,  /**< Src is TIMERx and choose channel 4 */
} md_pis_modu_channel_t;
/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_PIS_Public_Functions PIS Public Functions
  * @{
  */
/** @defgroup MD_PIS_Public_Functions_Group2 CH_CON
  * @{
  */
/**
  * @brief  output pis level.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_level_output(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    SET_BIT(PISx->CH_CON[channel], PIS_CH0_CON_LEVEL_MSK);
}

/**
  * @brief  clear pis level.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_level_clear(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    CLEAR_BIT(PISx->CH_CON[channel], PIS_CH0_CON_LEVEL_MSK);
}

/**
  * @brief  output pis pulse.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_pulse_output(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    SET_BIT(PISx->CH_CON[channel], PIS_CH0_CON_PULSE_MSK);
}

/**
  * @brief  Set pis signal synchronization type.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  signal PIS signal.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_signal_syn_type(PIS_TypeDef *PISx, md_pis_ch_t channel, md_pis_syncsel_t signal)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_SYNCSEL_MSK, signal << PIS_CH0_CON_SYNCSEL_POSS);
}

/**
  * @brief  Get pis signal synchronization type.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis channel signal synchronization type @ref md_pis_syncsel_t
  */
__STATIC_INLINE uint32_t md_pis_get_signal_syn_type(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_SYNCSEL_MSK, PIS_CH0_CON_SYNCSEL_POSS);
}

/**
  * @brief  Set pis edge sampling clock.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  clock PIS sample clock.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_edge_sample_clock(PIS_TypeDef *PISx, md_pis_ch_t channel, md_pis_clock_t clock)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_TSCKS_MSK, clock << PIS_CH0_CON_TSCKS_POSS);
}

/**
  * @brief  Get pis edge sampling clock.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis edge sampling clock @ref md_pis_clock_t
  */
__STATIC_INLINE uint32_t md_pis_get_edge_sample_clock(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_TSCKS_MSK, PIS_CH0_CON_TSCKS_POSS);
}

/**
  * @brief  Set pis sample edge.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  edge PIS sample edge.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_sample_edge(PIS_TypeDef *PISx, md_pis_ch_t channel, md_pis_edge_t edge)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_EDGS_MSK, edge << PIS_CH0_CON_EDGS_POSS);
}

/**
  * @brief  Get pis sample edge.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis edge sampling clock @ref md_pis_edge_t
  */
__STATIC_INLINE uint32_t md_pis_get_sample_edge(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_EDGS_MSK, PIS_CH0_CON_EDGS_POSS);
}

/**
  * @brief  Set pis input source.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  src PIS input source.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_input_src(PIS_TypeDef *PISx, md_pis_ch_t channel, md_pis_input_src_t src)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_SRCS_MSK, src << PIS_CH0_CON_SRCS_POSS);
}

/**
  * @brief  Get pis input source.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source @ref md_pis_input_src_t
  */
__STATIC_INLINE uint32_t md_pis_get_input_src(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_SRCS_MSK, PIS_CH0_CON_SRCS_POSS);
}

/**
  * @brief  Set pis input source gpiob.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  pin PIS input source gpiob.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_gpiob(PIS_TypeDef *PISx, md_pis_ch_t channel, uint8_t pin)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, pin << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source gpiob.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source gpiob.
  */
__STATIC_INLINE uint32_t md_pis_get_src_gpiob(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source clk.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  clk PIS input source clk.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_clk(PIS_TypeDef *PISx, md_pis_ch_t channel, uint8_t clk)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, clk << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source clk.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source clk.
  */
__STATIC_INLINE uint32_t md_pis_get_src_clk(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source adc0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  adc0 PIS input source adc0.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_adc0(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t adc0)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, adc0 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source adc0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source adc0.
  */
__STATIC_INLINE uint32_t md_pis_get_src_adc0(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source lvd.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  lvd PIS input source lvd.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_lvd(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t lvd)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, lvd << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source lvd.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source lvd.
  */
__STATIC_INLINE uint32_t md_pis_get_src_lvd(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source uart0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  uart0 PIS input source uart0.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_uart0(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t uart0)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, uart0 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source uart0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source uart0.
  */
__STATIC_INLINE uint32_t md_pis_get_src_uart0(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source uart1.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  uart1 PIS input source uart1.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_uart1(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t uart1)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, uart1 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source uart1.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source uart1.
  */
__STATIC_INLINE uint32_t md_pis_get_src_uart1(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source uart2.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  uart2 PIS input source uart2.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_uart2(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t uart2)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, uart2 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source uart2.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source uart2.
  */
__STATIC_INLINE uint32_t md_pis_get_src_uart2(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source uart3.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  uart3 PIS input source uart3.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_uart3(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t uart3)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, uart3 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source uart3.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source uart3.
  */
__STATIC_INLINE uint32_t md_pis_get_src_uart3(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source uart4.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  uart4 PIS input source uart4.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_uart4(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t uart4)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, uart4 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source uart4.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source uart4.
  */
__STATIC_INLINE uint32_t md_pis_get_src_uart4(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source spi0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  spi0 PIS input source spi0.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_spi0(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t spi0)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, spi0 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source spi0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source spi0.
  */
__STATIC_INLINE uint32_t md_pis_get_src_spi0(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source spi1.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  spi1 PIS input source spi1.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_spi1(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t spi1)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, spi1 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source spi1.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source spi1.
  */
__STATIC_INLINE uint32_t md_pis_get_src_spi1(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source i2c0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  i2c0 PIS input source i2c0.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_i2c0(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t i2c0)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, i2c0 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source i2c0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source i2c0.
  */
__STATIC_INLINE uint32_t md_pis_get_src_i2c0(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source i2c1.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  i2c1 PIS input source i2c1.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_i2c1(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t i2c1)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, i2c1 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source i2c1.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source i2c1
  */
__STATIC_INLINE uint32_t md_pis_get_src_i2c1(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source tim0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  tim0 PIS input source tim0.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_tim0(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t tim0)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, tim0 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source tim0.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source tim0
  */
__STATIC_INLINE uint32_t md_pis_get_src_tim0(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source tim4.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  tim0 PIS input source tim4.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_tim4(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t tim4)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, tim4 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source tim4.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source tim4
  */
__STATIC_INLINE uint32_t md_pis_get_src_tim4(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source tim5.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  tim0 PIS input source tim5.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_tim5(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t tim5)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, tim5 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source tim5.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source tim5
  */
__STATIC_INLINE uint32_t md_pis_get_src_tim5(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source tim6.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  tim0 PIS input source tim6.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_tim6(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t tim6)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, tim6 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source tim6.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source tim6
  */
__STATIC_INLINE uint32_t md_pis_get_src_tim6(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source tim7.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  tim0 PIS input source tim7.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_tim7(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t tim7)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, tim7 << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source tim7.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source tim7
  */
__STATIC_INLINE uint32_t md_pis_get_src_tim7(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Set pis input source dma.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @param  dma PIS input source dma.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_src_dma(PIS_TypeDef *PISx, md_pis_ch_t channel, uint32_t dma)
{
    MODIFY_REG(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, dma << PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @brief  Get pis input source dma.
  * @param  PISx PIS Instance.
  * @param  channel PIS channel.
  * @retval pis input source dma.
  */
__STATIC_INLINE uint32_t md_pis_get_src_dma(PIS_TypeDef *PISx, md_pis_ch_t channel)
{
    return READ_BITS(PISx->CH_CON[channel], PIS_CH0_CON_MSIGS_MSK, PIS_CH0_CON_MSIGS_POSS);
}

/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group3 CH_OER
  * @{
  */
/**
  * @brief  Disable pis channel 7 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_ch7_output(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->CH_OER, PIS_CH_OER_CH7OE_MSK);
}

/**
  * @brief  Enable pis channel 7 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_disable_ch7_output(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->CH_OER, PIS_CH_OER_CH7OE_MSK);
}

/**
  * @brief  Indicate if pis channel 7 output to port is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_ch7_output(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->CH_OER, PIS_CH_OER_CH7OE_MSK) == (PIS_CH_OER_CH7OE_MSK));
}

/**
  * @brief  Disable pis channel 6 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_ch6_output(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->CH_OER, PIS_CH_OER_CH6OE_MSK);
}

/**
  * @brief  Enable pis channel 6 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_disable_ch6_output(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->CH_OER, PIS_CH_OER_CH6OE_MSK);
}

/**
  * @brief  Indicate if pis channel 6 output to port is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_ch6_output(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->CH_OER, PIS_CH_OER_CH6OE_MSK) == (PIS_CH_OER_CH6OE_MSK));
}

/**
  * @brief  Disable pis channel 5 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_ch5_output(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->CH_OER, PIS_CH_OER_CH5OE_MSK);
}

/**
  * @brief  Enable pis channel 5 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_disable_ch5_output(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->CH_OER, PIS_CH_OER_CH5OE_MSK);
}

/**
  * @brief  Indicate if pis channel 5 output to port is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_ch5_output(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->CH_OER, PIS_CH_OER_CH5OE_MSK) == (PIS_CH_OER_CH5OE_MSK));
}

/**
  * @brief  Disable pis channel 4 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_ch4_output(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->CH_OER, PIS_CH_OER_CH4OE_MSK);
}

/**
  * @brief  Enable pis channel 4 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_disable_ch4_output(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->CH_OER, PIS_CH_OER_CH4OE_MSK);
}

/**
  * @brief  Indicate if pis channel 4 output to port is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_ch4_output(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->CH_OER, PIS_CH_OER_CH4OE_MSK) == (PIS_CH_OER_CH4OE_MSK));
}

/**
  * @brief  Disable pis channel 3 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_ch3_output(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->CH_OER, PIS_CH_OER_CH3OE_MSK);
}

/**
  * @brief  Enable pis channel 3 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_disable_ch3_output(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->CH_OER, PIS_CH_OER_CH3OE_MSK);
}

/**
  * @brief  Indicate if pis channel 3 output to port is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_ch3_output(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->CH_OER, PIS_CH_OER_CH3OE_MSK) == (PIS_CH_OER_CH3OE_MSK));
}

/**
  * @brief  Disable pis channel 2 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_ch2_output(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->CH_OER, PIS_CH_OER_CH2OE_MSK);
}

/**
  * @brief  Enable pis channel 2 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_disable_ch2_output(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->CH_OER, PIS_CH_OER_CH2OE_MSK);
}

/**
  * @brief  Indicate if pis channel 2 output to port is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_ch2_output(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->CH_OER, PIS_CH_OER_CH2OE_MSK) == (PIS_CH_OER_CH2OE_MSK));
}

/**
  * @brief  Disable pis channel 1 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_ch1_output(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->CH_OER, PIS_CH_OER_CH1OE_MSK);
}

/**
  * @brief  Enable pis channel 1 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_disable_ch1_output(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->CH_OER, PIS_CH_OER_CH1OE_MSK);
}

/**
  * @brief  Indicate if pis channel 1 output to port is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_ch1_output(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->CH_OER, PIS_CH_OER_CH1OE_MSK) == (PIS_CH_OER_CH1OE_MSK));
}

/**
  * @brief  Disable pis channel 0 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_ch0_output(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->CH_OER, PIS_CH_OER_CH0OE_MSK);
}

/**
  * @brief  Enable pis channel 0 output to port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_disable_ch0_output(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->CH_OER, PIS_CH_OER_CH0OE_MSK);
}

/**
  * @brief  Indicate if pis channel 0 output to port is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_ch0_output(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->CH_OER, PIS_CH_OER_CH0OE_MSK) == (PIS_CH_OER_CH0OE_MSK));
}
/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group4 TAR_CON0
  * @{
  */
/**
  * @brief  Set pis tim3 input etr chose ch6.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_etrin_ch6(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_ETRIN_SEL_MSK);
}

/**
  * @brief  Set pis tim3 input etr chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_etrin_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_ETRIN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim3 input etr chose ch6 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim3_etr_ch6(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_ETRIN_SEL_MSK) == (PIS_TAR_CON0_TIM3_ETRIN_SEL_MSK));
}

/**
  * @brief  Set pis tim3 input capture ch4 chose ch0.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_ch4in_ch0(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH4IN_SEL_MSK);
}

/**
  * @brief  Set pis tim3 input capture ch4 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_ch4in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH4IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim3 input capture ch4 chose ch0 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim3_ch4in_ch0(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH4IN_SEL_MSK) == (PIS_TAR_CON0_TIM3_CH4IN_SEL_MSK));
}

/**
  * @brief  Set pis tim3 input capture ch3 chose ch7.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_ch3in_ch7(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH3IN_SEL_MSK);
}

/**
  * @brief  Set pis tim3 input capture ch3 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_ch3in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH3IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim3 input capture ch3 chose ch7 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim3_ch3in_ch7(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH3IN_SEL_MSK) == (PIS_TAR_CON0_TIM3_CH3IN_SEL_MSK));
}

/**
  * @brief  Set pis tim3 input capture ch2 chose ch6.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_ch2in_ch6(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH2IN_SEL_MSK);
}

/**
  * @brief  Set pis tim3 input capture ch2 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_ch2in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH2IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim3 input capture ch2 chose ch6 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim3_ch2in_ch6(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH2IN_SEL_MSK) == (PIS_TAR_CON0_TIM3_CH2IN_SEL_MSK));
}

/**
  * @brief  Set pis tim3 input capture ch1 chose ch5.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_ch1in_ch5(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH1IN_SEL_MSK);
}

/**
  * @brief  Set pis tim3 input capture ch1 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim3_ch1in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH1IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim3 input capture ch1 chose ch5 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim3_ch1in_ch5(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM3_CH1IN_SEL_MSK) == (PIS_TAR_CON0_TIM3_CH1IN_SEL_MSK));
}

/**
  * @brief  Set pis tim2 input etr chose ch6.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_etrin_ch6(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_ETRIN_SEL_MSK);
}

/**
  * @brief  Set pis tim2 input etr chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_etrin_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_ETRIN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim2 input etr chose ch6 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim2_etr_ch6(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_ETRIN_SEL_MSK) == (PIS_TAR_CON0_TIM2_ETRIN_SEL_MSK));
}

/**
  * @brief  Set pis tim2 input capture ch4 chose ch4.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_ch4in_ch4(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH4IN_SEL_MSK);
}

/**
  * @brief  Set pis tim2 input capture ch4 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_ch4in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH4IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim2 input capture ch4 chose ch4 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim2_ch4in_ch4(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH4IN_SEL_MSK) == (PIS_TAR_CON0_TIM2_CH4IN_SEL_MSK));
}

/**
  * @brief  Set pis tim2 input capture ch3 chose ch3.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_ch3in_ch3(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH3IN_SEL_MSK);
}

/**
  * @brief  Set pis tim2 input capture ch3 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_ch3in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH3IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim2 input capture ch3 chose ch7 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim2_ch3in_ch3(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH3IN_SEL_MSK) == (PIS_TAR_CON0_TIM2_CH3IN_SEL_MSK));
}

/**
  * @brief  Set pis tim2 input capture ch2 chose ch2.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_ch2in_ch2(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH2IN_SEL_MSK);
}

/**
  * @brief  Set pis tim2 input capture ch2 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_ch2in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH2IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim2 input capture ch2 chose ch2 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim2_ch2in_ch2(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH2IN_SEL_MSK) == (PIS_TAR_CON0_TIM2_CH2IN_SEL_MSK));
}

/**
  * @brief  Set pis tim2 input capture ch1 chose ch1.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_ch1in_ch1(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH1IN_SEL_MSK);
}

/**
  * @brief  Set pis tim2 input capture ch1 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim2_ch1in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH1IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim2 input capture ch1 chose ch1 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim2_ch1in_ch1(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM2_CH1IN_SEL_MSK) == (PIS_TAR_CON0_TIM2_CH1IN_SEL_MSK));
}

/**
  * @brief  Set pis tim1 input etr chose ch6.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_etrin_ch6(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_ETRIN_SEL_MSK);
}

/**
  * @brief  Set pis tim1 input etr chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_etrin_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_ETRIN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim1 input etr chose ch6 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim1_etr_ch6(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_ETRIN_SEL_MSK) == (PIS_TAR_CON0_TIM1_ETRIN_SEL_MSK));
}

/**
  * @brief  Set pis tim1 input capture ch4 chose ch4.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_ch4in_ch4(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH4IN_SEL_MSK);
}

/**
  * @brief  Set pis tim1 input capture ch4 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_ch4in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH4IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim1 input capture ch4 chose ch4 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim1_ch4in_ch4(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH4IN_SEL_MSK) == (PIS_TAR_CON0_TIM1_CH4IN_SEL_MSK));
}

/**
  * @brief  Set pis tim1 input capture ch3 chose ch3.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_ch3in_ch3(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH3IN_SEL_MSK);
}

/**
  * @brief  Set pis tim1 input capture ch3 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_ch3in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH3IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim1 input capture ch3 chose ch3 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim1_ch3in_ch3(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH3IN_SEL_MSK) == (PIS_TAR_CON0_TIM1_CH3IN_SEL_MSK));
}

/**
  * @brief  Set pis tim1 input capture ch2 chose ch2.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_ch2in_ch2(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH2IN_SEL_MSK);
}

/**
  * @brief  Set pis tim1 input capture ch2 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_ch2in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH2IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim1 input capture ch2 chose ch2 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim1_ch2in_ch2(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH2IN_SEL_MSK) == (PIS_TAR_CON0_TIM1_CH2IN_SEL_MSK));
}

/**
  * @brief  Set pis tim1 input capture ch1 chose ch1.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_ch1in_ch1(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH1IN_SEL_MSK);
}

/**
  * @brief  Set pis tim1 input capture ch1 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim1_ch1in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH1IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim1 input capture ch1 chose ch1 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim1_ch1in_ch1(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM1_CH1IN_SEL_MSK) == (PIS_TAR_CON0_TIM1_CH1IN_SEL_MSK));
}

/**
  * @brief  Set pis tim0 input etr chose ch5.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_etrin_ch5(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_ETRIN_SEL_MSK);
}

/**
  * @brief  Set pis tim0 input etr chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_etrin_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_ETRIN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim1 input etr chose ch5 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim0_etr_ch5(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_ETRIN_SEL_MSK) == (PIS_TAR_CON0_TIM0_ETRIN_SEL_MSK));
}

/**
  * @brief  Set pis tim0 input capture ch4 chose ch4.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_ch4in_ch4(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH4IN_SEL_MSK);
}

/**
  * @brief  Set pis tim0 input capture ch4 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_ch4in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH4IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim0 input capture ch4 chose ch4 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim0_ch4in_ch4(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH4IN_SEL_MSK) == (PIS_TAR_CON0_TIM0_CH4IN_SEL_MSK));
}

/**
  * @brief  Set pis tim0 input capture ch3 chose ch3.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_ch3in_ch3(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH3IN_SEL_MSK);
}

/**
  * @brief  Set pis tim0 input capture ch3 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_ch3in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH3IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim0 input capture ch3 chose ch3 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim0_ch3in_ch3(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH3IN_SEL_MSK) == (PIS_TAR_CON0_TIM0_CH3IN_SEL_MSK));
}

/**
  * @brief  Set pis tim0 input capture ch2 chose ch2.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_ch2in_ch2(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH2IN_SEL_MSK);
}

/**
  * @brief  Set pis tim0 input capture ch2 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_ch2in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH2IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim0 input capture ch2 chose ch2 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim0_ch2in_ch2(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH2IN_SEL_MSK) == (PIS_TAR_CON0_TIM0_CH2IN_SEL_MSK));
}

/**
  * @brief  Set pis tim0 input capture ch1 chose ch1.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_ch1in_ch1(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH1IN_SEL_MSK);
}

/**
  * @brief  Set pis tim0 input capture ch1 chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_tim0_ch1in_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH1IN_SEL_MSK);
}

/**
  * @brief  Indicate if pis tim0 input capture ch1 chose ch1 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_tim0_ch1in_ch1(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON0, PIS_TAR_CON0_TIM0_CH1IN_SEL_MSK) == (PIS_TAR_CON0_TIM0_CH1IN_SEL_MSK));
}
/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group5 TAR_CON1
  * @{
  */
/**
  * @brief  Set pis spi1 clk input chose ch3.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_spi1_clk_ch3(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI1_CLK_SEL_MSK);
}

/**
  * @brief  Set pis spi1 clk input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_spi1_clk_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI1_CLK_SEL_MSK);
}

/**
  * @brief  Indicate if pis spi1 clk input chose ch3 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_spi1_clk_ch3(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI1_CLK_SEL_MSK) == (PIS_TAR_CON1_SPI1_CLK_SEL_MSK));
}

/**
  * @brief  Set pis spi1 rx input chose ch2.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_spi1_rx_ch2(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI1_RX_SEL_MSK);
}

/**
  * @brief  Set pis spi1 rx input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_spi1_rx_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI1_RX_SEL_MSK);
}

/**
  * @brief  Indicate if pis spi1 rx input chose ch2 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_spi1_rx_ch2(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI1_RX_SEL_MSK) == (PIS_TAR_CON1_SPI1_RX_SEL_MSK));
}

/**
  * @brief  Set pis spi0 clk input chose ch1.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_spi0_clk_ch1(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI0_CLK_SEL_MSK);
}

/**
  * @brief  Set pis spi0 clk input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_spi0_clk_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI0_CLK_SEL_MSK);
}

/**
  * @brief  Indicate if pis spi0 clk input chose ch1 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_spi0_clk_ch1(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI0_CLK_SEL_MSK) == (PIS_TAR_CON1_SPI0_CLK_SEL_MSK));
}

/**
  * @brief  Set pis spi0 rx input chose ch0.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_spi0_rx_ch0(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI0_RX_SEL_MSK);
}

/**
  * @brief  Set pis spi0 rx input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_spi0_rx_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI0_RX_SEL_MSK);
}

/**
  * @brief  Indicate if pis spi0 rx input chose ch0 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_spi0_rx_ch0(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_SPI0_RX_SEL_MSK) == (PIS_TAR_CON1_SPI0_RX_SEL_MSK));
}

/**
  * @brief  Set pis uart4 rx input chose ch7.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart4_rx_ch7(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART4_RXD_SEL_MSK);
}

/**
  * @brief  Set pis uart4 rx input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart4_rx_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART4_RXD_SEL_MSK);
}

/**
  * @brief  Indicate if pis uart4 rx input chose ch7 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_uart4_rx_ch7(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART4_RXD_SEL_MSK) == (PIS_TAR_CON1_UART4_RXD_SEL_MSK));
}

/**
  * @brief  Set pis uart3 rx input chose ch6.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart3_rx_ch6(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART3_RXD_SEL_MSK);
}

/**
  * @brief  Set pis uart3 rx input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart3_rx_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART3_RXD_SEL_MSK);
}

/**
  * @brief  Indicate if pis uart3 rx input chose ch6 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_uart3_rx_ch6(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART3_RXD_SEL_MSK) == (PIS_TAR_CON1_UART3_RXD_SEL_MSK));
}

/**
  * @brief  Set pis uart2 rx input chose ch5.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart2_rx_ch5(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART2_RXD_SEL_MSK);
}

/**
  * @brief  Set pis uart2 rx input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart2_rx_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART2_RXD_SEL_MSK);
}

/**
  * @brief  Indicate if pis uart2 rx input chose ch5 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_uart2_rx_ch5(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART2_RXD_SEL_MSK) == (PIS_TAR_CON1_UART2_RXD_SEL_MSK));
}

/**
  * @brief  Set pis uart1 rx input chose ch4.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart1_rx_ch4(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART1_RXD_SEL_MSK);
}

/**
  * @brief  Set pis uart1 rx input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart1_rx_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART1_RXD_SEL_MSK);
}

/**
  * @brief  Indicate if pis uart1 rx input chose ch4 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_uart1_rx_ch4(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART1_RXD_SEL_MSK) == (PIS_TAR_CON1_UART1_RXD_SEL_MSK));
}

/**
  * @brief  Set pis uart0 rx input chose ch3.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart0_rx_ch3(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART0_RXD_SEL_MSK);
}

/**
  * @brief  Set pis uart0 rx input chose port.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_enable_uart0_rx_port(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART0_RXD_SEL_MSK);
}

/**
  * @brief  Indicate if pis uart0 rx input chose ch3 is enabled
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_enabled_uart0_rx_ch3(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->TAR_CON1, PIS_TAR_CON1_UART0_RXD_SEL_MSK) == (PIS_TAR_CON1_UART0_RXD_SEL_MSK));
}
/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group6 UART0_TXMCR
  * @{
  */
/**
  * @brief  Set pis uart0 tx modulation level high.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart0_tx_mod_high(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->UART0_TXMCR, PIS_UART0_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Set pis uart0 tx modulation level low.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart0_tx_mod_low(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->UART0_TXMCR, PIS_UART0_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Indicate if pis uart0 tx modulation level high is set
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_set_uart0_tx_mod_high(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->UART0_TXMCR, PIS_UART0_TXMCR_TXMLVLS_MSK) == (PIS_UART0_TXMCR_TXMLVLS_MSK));
}

/**
  * @brief  Set pis uart0 modulation source.
  * @param  PISx PIS Instance.
  * @param  src PIS uart0 modulation source.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart0_mod_src(PIS_TypeDef *PISx, md_pis_modu_src_t src)
{
    MODIFY_REG(PISx->UART0_TXMCR, PIS_UART0_TXMCR_TXMSS_MSK, src << PIS_UART0_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Get pis uart0 modulation source.
  * @param  PISx PIS Instance.
  * @retval uart0 modulation source @ref md_pis_modu_src_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart0_mod_src(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART0_TXMCR, PIS_UART0_TXMCR_TXMSS_MSK, PIS_UART0_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Set pis uart0 modulation timx channel.
  * @param  PISx PIS Instance.
  * @param  channel PIS timx modulation channel.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart0_mod_tim_channel(PIS_TypeDef *PISx, md_pis_modu_channel_t channel)
{
    MODIFY_REG(PISx->UART0_TXMCR, PIS_UART0_TXMCR_TXSIGS_MSK, channel << PIS_UART0_TXMCR_TXSIGS_POSS);
}

/**
  * @brief  Get pis uart0 timx modulation channel.
  * @param  PISx PIS Instance.
  * @retval uart0 timx modulation channel @ref md_pis_modu_channel_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart0_mod_tim_channel(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART0_TXMCR, PIS_UART0_TXMCR_TXSIGS_MSK, PIS_UART0_TXMCR_TXSIGS_POSS);
}
/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group7 UART1_TXMCR
  * @{
  */
/**
  * @brief  Set pis uart1 tx modulation level high.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart1_tx_mod_high(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->UART1_TXMCR, PIS_UART1_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Set pis uart1 tx modulation level low.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart1_tx_mod_low(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->UART1_TXMCR, PIS_UART1_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Indicate if pis uart1 tx modulation level high is set
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_set_uart1_tx_mod_high(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->UART1_TXMCR, PIS_UART1_TXMCR_TXMLVLS_MSK) == (PIS_UART1_TXMCR_TXMLVLS_MSK));
}

/**
  * @brief  Set pis uart1 modulation source.
  * @param  PISx PIS Instance.
  * @param  src PIS uart1 modulation source.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart1_mod_src(PIS_TypeDef *PISx, md_pis_modu_src_t src)
{
    MODIFY_REG(PISx->UART1_TXMCR, PIS_UART1_TXMCR_TXMSS_MSK, src << PIS_UART1_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Get pis uart1 modulation source.
  * @param  PISx PIS Instance.
  * @retval uart1 modulation source @ref md_pis_modu_src_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart1_mod_src(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART1_TXMCR, PIS_UART1_TXMCR_TXMSS_MSK, PIS_UART1_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Set pis uart1 modulation timx channel.
  * @param  PISx PIS Instance.
  * @param  channel PIS timx modulation channel.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart1_mod_tim_channel(PIS_TypeDef *PISx, md_pis_modu_channel_t channel)
{
    MODIFY_REG(PISx->UART1_TXMCR, PIS_UART1_TXMCR_TXSIGS_MSK, channel << PIS_UART1_TXMCR_TXSIGS_POSS);
}

/**
  * @brief  Get pis uart1 timx modulation channel.
  * @param  PISx PIS Instance.
  * @retval uart1 timx modulation channel @ref md_pis_modu_channel_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart1_mod_tim_channel(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART1_TXMCR, PIS_UART1_TXMCR_TXSIGS_MSK, PIS_UART1_TXMCR_TXSIGS_POSS);
}
/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group8 UART2_TXMCR
  * @{
  */
/**
  * @brief  Set pis uart2 tx modulation level high.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart2_tx_mod_high(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->UART2_TXMCR, PIS_UART2_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Set pis uart2 tx modulation level low.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart2_tx_mod_low(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->UART2_TXMCR, PIS_UART2_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Indicate if pis uart2 tx modulation level high is set
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_set_uart2_tx_mod_high(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->UART2_TXMCR, PIS_UART2_TXMCR_TXMLVLS_MSK) == (PIS_UART2_TXMCR_TXMLVLS_MSK));
}

/**
  * @brief  Set pis uart2 modulation source.
  * @param  PISx PIS Instance.
  * @param  src PIS uart2 modulation source.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart2_mod_src(PIS_TypeDef *PISx, md_pis_modu_src_t src)
{
    MODIFY_REG(PISx->UART2_TXMCR, PIS_UART2_TXMCR_TXMSS_MSK, src << PIS_UART2_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Get pis uart2 modulation source.
  * @param  PISx PIS Instance.
  * @retval uart2 modulation source @ref md_pis_modu_src_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart2_mod_src(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART2_TXMCR, PIS_UART2_TXMCR_TXMSS_MSK, PIS_UART2_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Set pis uart2 modulation timx channel.
  * @param  PISx PIS Instance.
  * @param  channel PIS timx modulation channel.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart2_mod_tim_channel(PIS_TypeDef *PISx, md_pis_modu_channel_t channel)
{
    MODIFY_REG(PISx->UART2_TXMCR, PIS_UART2_TXMCR_TXSIGS_MSK, channel << PIS_UART2_TXMCR_TXSIGS_POSS);
}

/**
  * @brief  Get pis uart2 timx modulation channel.
  * @param  PISx PIS Instance.
  * @retval uart2 timx modulation channel @ref md_pis_modu_channel_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart2_mod_tim_channel(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART2_TXMCR, PIS_UART2_TXMCR_TXSIGS_MSK, PIS_UART2_TXMCR_TXSIGS_POSS);
}
/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group9 UART3_TXMCR
  * @{
  */
/**
  * @brief  Set pis uart3 tx modulation level high.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart3_tx_mod_high(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->UART3_TXMCR, PIS_UART3_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Set pis uart3 tx modulation level low.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart3_tx_mod_low(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->UART3_TXMCR, PIS_UART3_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Indicate if pis uart3 tx modulation level high is set
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_set_uart3_tx_mod_high(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->UART3_TXMCR, PIS_UART3_TXMCR_TXMLVLS_MSK) == (PIS_UART3_TXMCR_TXMLVLS_MSK));
}

/**
  * @brief  Set pis uart3 modulation source.
  * @param  PISx PIS Instance.
  * @param  src PIS uart3 modulation source.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart3_mod_src(PIS_TypeDef *PISx, md_pis_modu_src_t src)
{
    MODIFY_REG(PISx->UART3_TXMCR, PIS_UART3_TXMCR_TXMSS_MSK, src << PIS_UART3_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Get pis uart3 modulation source.
  * @param  PISx PIS Instance.
  * @retval uart3 modulation source @ref md_pis_modu_src_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart3_mod_src(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART3_TXMCR, PIS_UART3_TXMCR_TXMSS_MSK, PIS_UART3_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Set pis uart3 modulation timx channel.
  * @param  PISx PIS Instance.
  * @param  channel PIS timx modulation channel.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart3_mod_tim_channel(PIS_TypeDef *PISx, md_pis_modu_channel_t channel)
{
    MODIFY_REG(PISx->UART3_TXMCR, PIS_UART3_TXMCR_TXSIGS_MSK, channel << PIS_UART3_TXMCR_TXSIGS_POSS);
}

/**
  * @brief  Get pis uart3 timx modulation channel.
  * @param  PISx PIS Instance.
  * @retval uart3 timx modulation channel @ref md_pis_modu_channel_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart3_mod_tim_channel(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART3_TXMCR, PIS_UART3_TXMCR_TXSIGS_MSK, PIS_UART3_TXMCR_TXSIGS_POSS);
}
/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group10 UART4_TXMCR
  * @{
  */
/**
  * @brief  Set pis uart4 tx modulation level high.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart4_tx_mod_high(PIS_TypeDef *PISx)
{
    SET_BIT(PISx->UART4_TXMCR, PIS_UART4_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Set pis uart4 tx modulation level low.
  * @param  PISx PIS Instance.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart4_tx_mod_low(PIS_TypeDef *PISx)
{
    CLEAR_BIT(PISx->UART4_TXMCR, PIS_UART4_TXMCR_TXMLVLS_MSK);
}

/**
  * @brief  Indicate if pis uart4 tx modulation level high is set
  * @param  PISx PIS Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_pis_is_set_uart4_tx_mod_high(PIS_TypeDef *PISx)
{
    return (uint32_t)(READ_BIT(PISx->UART4_TXMCR, PIS_UART4_TXMCR_TXMLVLS_MSK) == (PIS_UART4_TXMCR_TXMLVLS_MSK));
}

/**
  * @brief  Set pis uart4 modulation source.
  * @param  PISx PIS Instance.
  * @param  src PIS uart4 modulation source.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart4_mod_src(PIS_TypeDef *PISx, md_pis_modu_src_t src)
{
    MODIFY_REG(PISx->UART4_TXMCR, PIS_UART4_TXMCR_TXMSS_MSK, src << PIS_UART4_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Get pis uart4 modulation source.
  * @param  PISx PIS Instance.
  * @retval uart4 modulation source @ref md_pis_modu_src_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart4_mod_src(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART4_TXMCR, PIS_UART4_TXMCR_TXMSS_MSK, PIS_UART4_TXMCR_TXMSS_POSS);
}

/**
  * @brief  Set pis uart4 modulation timx channel.
  * @param  PISx PIS Instance.
  * @param  channel PIS timx modulation channel.
  * @retval None
  */
__STATIC_INLINE void md_pis_set_uart4_mod_tim_channel(PIS_TypeDef *PISx, md_pis_modu_channel_t channel)
{
    MODIFY_REG(PISx->UART4_TXMCR, PIS_UART4_TXMCR_TXSIGS_MSK, channel << PIS_UART4_TXMCR_TXSIGS_POSS);
}

/**
  * @brief  Get pis uart4 timx modulation channel.
  * @param  PISx PIS Instance.
  * @retval uart4 timx modulation channel @ref md_pis_modu_channel_t
  */
__STATIC_INLINE uint32_t md_pis_get_uart4_mod_tim_channel(PIS_TypeDef *PISx)
{
    return READ_BITS(PISx->UART4_TXMCR, PIS_UART4_TXMCR_TXSIGS_MSK, PIS_UART4_TXMCR_TXSIGS_POSS);
}
/**
  * @}
  */
/** @defgroup MD_PIS_Public_Functions_Group1 Initialization
  * @{
  */
extern void md_pis_reset(void);
extern md_status_t md_pis_init(md_pis_init_t *init);
/**
  * @}
  */
/**
  * @}
  */
/**
  * @}
  */
/**
  * @}
  */
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MD_PIS_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

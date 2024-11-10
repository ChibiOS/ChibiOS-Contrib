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
 * @file    AT32F405xx/hal_lld.h
 * @brief   AT32F405xx HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - AT32_LEXTCLK.
 *          - AT32_LEXT_BYPASS (optionally).
 *          - AT32_HEXTCLK.
 *          - AT32_HEXT_BYPASS (optionally).
 *          .
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

#include "at32_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Requires use of SPIv2 driver model.
 */
#define HAL_LLD_SELECT_SPI_V2                  TRUE

/**
 * @name    Platform identification
 * @{
 */
#define PLATFORM_NAME                          "AT32F405xx"

/**
 * @brief   Sub-family identifier.
 */
#if !defined(AT32F405xx) || defined(__DOXYGEN__)
#define AT32F405xx
#endif
/** @} */

/**
 * @name    Absolute Maximum Ratings
 * @{
 */
/**
 * @brief   Maximum system clock frequency.
 */
#define AT32_SYSCLK_MAX                        216000000

/**
 * @brief   Maximum HEXT clock frequency.
 */
#define AT32_HEXTCLK_MAX                       25000000

/**
 * @brief   Maximum HEXT clock frequency using an external source.
 */
#define AT32_HEXTCLK_BYP_MAX                   25000000

/**
 * @brief   Minimum HEXT clock frequency.
 */
#define AT32_HEXTCLK_MIN                       4000000

/**
 * @brief   Minimum HEXT clock frequency.
 */
#define AT32_HEXTCLK_BYP_MIN                   4000000

/**
 * @brief   Maximum LSE clock frequency.
 */
#define AT32_LEXTCLK_MAX                       32768

/**
 * @brief   Maximum LSE clock frequency.
 */
#define AT32_LEXTCLK_BYP_MAX                   1000000

/**
 * @brief   Minimum LEXT clock frequency.
 */
#define AT32_LEXTCLK_MIN                       32768

/**
 * @brief   Maximum PLLs input clock frequency.
 */
#define AT32_PLLIN_MAX                         16000000

/**
 * @brief   Minimum PLLs input clock frequency.
 */
#define AT32_PLLIN_MIN                         2000000

/**
 * @brief   Maximum PLLs VCO clock frequency.
 */
#define AT32_PLLVCO_MAX                        1000000000

/**
 * @brief   Minimum PLLs VCO clock frequency.
 */
#define AT32_PLLVCO_MIN                        500000000

/**
 * @brief   Maximum PLL output clock frequency.
 */
#define AT32_PLLOUT_MAX                        216000000

/**
 * @brief   Minimum PLL output clock frequency.
 */
#define AT32_PLLOUT_MIN                        4000000

/**
 * @brief   Maximum APB1 clock frequency.
 */
#define AT32_PCLK1_MAX                         120000000

/**
 * @brief   Maximum APB2 clock frequency.
 */
#define AT32_PCLK2_MAX                         216000000

/**
 * @brief   Maximum ADC clock frequency.
 */
#define AT32_ADCCLK_MAX                        28000000
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define AT32_HICKCLK                           48000000    /**< High speed internal clock. */
#define AT32_LICKCLK                           40000       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    PWC_CTRL register bits definitions
 * @{
 */
#define AT32_PVMSEL_MASK            (7 << 5)   /**< PVMSEL bits mask.          */
#define AT32_PVMSEL_LEV0            (0 << 5)   /**< PVM level 0.               */
#define AT32_PVMSEL_LEV1            (1 << 5)   /**< PVM level 1.               */
#define AT32_PVMSEL_LEV2            (2 << 5)   /**< PVM level 2.               */
#define AT32_PVMSEL_LEV3            (3 << 5)   /**< PVM level 3.               */
#define AT32_PVMSEL_LEV4            (4 << 5)   /**< PVM level 4.               */
#define AT32_PVMSEL_LEV5            (5 << 5)   /**< PVM level 5.               */
#define AT32_PVMSEL_LEV6            (6 << 5)   /**< PVM level 6.               */
#define AT32_PVMSEL_LEV7            (7 << 5)   /**< PVM level 7.               */
/** @} */

/**
 * @name    PWC_LDOOV register bits definitions
 * @{
 */
#define AT32_LDOOVSEL_MASK          (3 << 0)   /**< LDOOVSEL bits mask.        */
#define AT32_LDOOVSEL_1P0V          (0 << 0)   /**< LDOOVSEL 1.0V.             */
#define AT32_LDOOVSEL_1P1V          (1 << 0)   /**< LDOOVSEL 1.1V.             */
#define AT32_LDOOVSEL_1P2V          (2 << 0)   /**< LDOOVSEL 1.2V.             */
#define AT32_LDOOVSEL_1P3V          (3 << 0)   /**< LDOOVSEL 1.3V.             */
/** @} */

/**
 * @name    CRM_PLLCFG register bits definitions
 * @{
 */
#define AT32_PLL_FP_MASK            (15 << 16)  /**< PLL_FP mask.               */
#define AT32_PLL_FP_DIV1            (0 << 16)   /**< PLL clock divided by 1.    */
#define AT32_PLL_FP_DIV2            (1 << 16)   /**< PLL clock divided by 2.    */
#define AT32_PLL_FP_DIV4            (2 << 16)   /**< PLL clock divided by 4.    */
#define AT32_PLL_FP_DIV6            (3 << 16)   /**< PLL clock divided by 6.    */
#define AT32_PLL_FP_DIV8            (4 << 16)   /**< PLL clock divided by 8.    */
#define AT32_PLL_FP_DIV10           (5 << 16)   /**< PLL clock divided by 10.   */
#define AT32_PLL_FP_DIV12           (6 << 16)   /**< PLL clock divided by 12.   */
#define AT32_PLL_FP_DIV14           (7 << 16)   /**< PLL clock divided by 14.   */
#define AT32_PLL_FP_DIV16           (8 << 16)   /**< PLL clock divided by 16.   */
#define AT32_PLL_FP_DIV18           (9 << 16)   /**< PLL clock divided by 18.   */
#define AT32_PLL_FP_DIV20           (10 << 16)  /**< PLL clock divided by 20.   */
#define AT32_PLL_FP_DIV22           (11 << 16)  /**< PLL clock divided by 22.   */
#define AT32_PLL_FP_DIV24           (12 << 16)  /**< PLL clock divided by 24.   */
#define AT32_PLL_FP_DIV26           (13 << 16)  /**< PLL clock divided by 26.   */
#define AT32_PLL_FP_DIV28           (14 << 16)  /**< PLL clock divided by 28.   */
#define AT32_PLL_FP_DIV30           (15 << 16)  /**< PLL clock divided by 30.   */

#define AT32_PLL_FU_MASK            (7 << 20)   /**< PLL_FU mask.               */
#define AT32_PLL_FU_DIV11           (0 << 20)   /**< PLLU clock divided by 11.  */
#define AT32_PLL_FU_DIV13           (1 << 20)   /**< PLLU clock divided by 13.  */
#define AT32_PLL_FU_DIV12           (2 << 20)   /**< PLLU clock divided by 12.  */
#define AT32_PLL_FU_DIV14           (3 << 20)   /**< PLLU clock divided by 14.  */
#define AT32_PLL_FU_DIV16           (4 << 20)   /**< PLLU clock divided by 16.  */
#define AT32_PLL_FU_DIV18           (5 << 20)   /**< PLLU clock divided by 18.  */
#define AT32_PLL_FU_DIV20           (6 << 20)   /**< PLLU clock divided by 20.  */

#define AT32_PLLRCS_HICK            (0 << 30)   /**< PLL clock source is HICK.  */
#define AT32_PLLRCS_HEXT            (1 << 30)   /**< PLL clock source is HEXT.  */
/** @} */

/**
 * @name    CRM_CFG register bits definitions
 * @{
 */
#define AT32_SCLKSEL_MASK           (3 << 0)    /**< SCLKSEL mask.              */
#define AT32_SCLKSEL_HICK           (0 << 0)    /**< SYSCLK source is HICK.     */
#define AT32_SCLKSEL_HEXT           (1 << 0)    /**< SYSCLK source is HEXT.     */
#define AT32_SCLKSEL_PLL            (2 << 0)    /**< SYSCLK source is PLL.      */

#define AT32_SCLKSTS_MASK           (3 << 2)    /**< SCLKSTS mask.              */
#define AT32_SCLKSTS_HICK           (0 << 2)    /**< SYSCLK use HICK.           */
#define AT32_SCLKSTS_HEXT           (1 << 2)    /**< SYSCLK use HEXT.           */
#define AT32_SCLKSTS_PLL            (2 << 2)    /**< SYSCLK use PLL.            */

#define AT32_AHBDIV_MASK            (15 << 4)   /**< AHBDIV mask.               */
#define AT32_AHBDIV_DIV1            (0 << 4)    /**< SYSCLK divided by 1.       */
#define AT32_AHBDIV_DIV2            (8 << 4)    /**< SYSCLK divided by 2.       */
#define AT32_AHBDIV_DIV4            (9 << 4)    /**< SYSCLK divided by 4.       */
#define AT32_AHBDIV_DIV8            (10 << 4)   /**< SYSCLK divided by 8.       */
#define AT32_AHBDIV_DIV16           (11 << 4)   /**< SYSCLK divided by 16.      */
#define AT32_AHBDIV_DIV64           (12 << 4)   /**< SYSCLK divided by 64.      */
#define AT32_AHBDIV_DIV128          (13 << 4)   /**< SYSCLK divided by 128.     */
#define AT32_AHBDIV_DIV256          (14 << 4)   /**< SYSCLK divided by 256.     */
#define AT32_AHBDIV_DIV512          (15 << 4)   /**< SYSCLK divided by 512.     */

#define AT32_APB1DIV_MASK           (7 << 10)   /**< APB1DIV mask.              */
#define AT32_APB1DIV_DIV1           (0 << 10)   /**< HCLK divided by 1.         */
#define AT32_APB1DIV_DIV2           (4 << 10)   /**< HCLK divided by 2.         */
#define AT32_APB1DIV_DIV4           (5 << 10)   /**< HCLK divided by 4.         */
#define AT32_APB1DIV_DIV8           (6 << 10)   /**< HCLK divided by 8.         */
#define AT32_APB1DIV_DIV16          (7 << 10)   /**< HCLK divided by 16.        */

#define AT32_APB2DIV_MASK           (7 << 13)   /**< APB2DIV mask.              */
#define AT32_APB2DIV_DIV1           (0 << 13)   /**< HCLK divided by 1.         */
#define AT32_APB2DIV_DIV2           (4 << 13)   /**< HCLK divided by 2.         */
#define AT32_APB2DIV_DIV4           (5 << 13)   /**< HCLK divided by 4.         */
#define AT32_APB2DIV_DIV8           (6 << 13)   /**< HCLK divided by 8.         */
#define AT32_APB2DIV_DIV16          (7 << 13)   /**< HCLK divided by 16.        */

#define AT32_ERTCDIV_MASK           (31 << 16)  /**< ERTCDIV mask.              */

#define AT32_I2SF5CLKSEL_MASK       (3 << 22)   /**< I2SF5CLKSEL mask.          */
#define AT32_I2SF5CLKSEL_SCLK       (0 << 22)   /**< I2SF5CLKSEL is SYSCLK.     */
#define AT32_I2SF5CLKSEL_PLL        (1 << 22)   /**< I2SF5CLKSEL is PLL.        */
#define AT32_I2SF5CLKSEL_HICK       (2 << 22)   /**< I2SF5CLKSEL is HICK.       */
#define AT32_I2SF5CLKSEL_EXCLK      (3 << 22)   /**< I2SF5CLKSEL is EXCLK.      */

#define AT32_CLKOUTDIV1_MASK        (7 << 27)   /**< CLKOUTDIV1 mask.           */
#define AT32_CLKOUTDIV1_DIV1        (0 << 27)   /**< CLKOUT divided by 1.       */
#define AT32_CLKOUTDIV1_DIV2        (4 << 27)   /**< CLKOUT divided by 2.       */
#define AT32_CLKOUTDIV1_DIV3        (5 << 27)   /**< CLKOUT divided by 3.       */
#define AT32_CLKOUTDIV1_DIV4        (6 << 27)   /**< CLKOUT divided by 4.       */
#define AT32_CLKOUTDIV1_DIV5        (7 << 27)   /**< CLKOUT divided by 5.       */

#define AT32_CLKOUT_SEL_CFG_MASK    (3 << 30)   /**< CLKOUT_SEL CFG mask.       */
#define AT32_CLKOUT_SEL_MISC1_MASK  (15 << 16)  /**< CLKOUT_SEL MISC1 mask.     */
#define AT32_CLKOUT_SEL_SCLK        (0 << 30)   /**< CLKOUT_SEL SYSCLK.         */
#define AT32_CLKOUT_SEL_HEXT        (2 << 30)   /**< CLKOUT_SEL HEXT.           */
#define AT32_CLKOUT_SEL_PLL         (3 << 30)   /**< CLKOUT_SEL PLL.            */
#define AT32_CLKOUT_SEL_USBFS       ((1 << 30) |     \
                                     (0 << 16)) /**< CLKOUT_SEL USBFS.          */
#define AT32_CLKOUT_SEL_ADC         ((1 << 30) |     \
                                     (1 << 16)) /**< CLKOUT_SEL ADC.            */
#define AT32_CLKOUT_SEL_HICK        ((1 << 30) |     \
                                     (2 << 16)) /**< CLKOUT_SEL HICK.           */
#define AT32_CLKOUT_SEL_LICK        ((1 << 30) |     \
                                     (3 << 16)) /**< CLKOUT_SEL LICK.           */
#define AT32_CLKOUT_SEL_LEXT        ((1 << 30) |     \
                                     (4 << 16)) /**< CLKOUT_SEL LEXT.           */
#define AT32_CLKOUT_SEL_USBHS       ((1 << 30) |     \
                                     (5 << 16)) /**< CLKOUT_SEL USBHS.          */
/** @} */

/**
 * @name    CRM_BPDC register bits definitions
 * @{
 */
#define AT32_ERTCSEL_MASK           (3 << 8)    /**< RTC clock source mask.     */
#define AT32_ERTCSEL_NOCLOCK        (0 << 8)    /**< No clock.                  */
#define AT32_ERTCSEL_LEXT           (1 << 8)    /**< LEXT used as RTC clock.    */
#define AT32_ERTCSEL_LICK           (2 << 8)    /**< LICK used as RTC clock.    */
#define AT32_ERTCSEL_HEXTDIV        (3 << 8)    /**< HEXT divided used as
                                                     RTC clock.                 */
/** @} */

/**
 * @name    CRM_MISC1 register bits definitions
 * @{
 */
#define AT32_HICKDIV_MASK           (1 << 12)   /**< HICKDIV mask.              */
#define AT32_HICKDIV_DIV6           (0 << 12)   /**< HICK divided by 6.         */
#define AT32_HICKDIV_DIV1           (1 << 12)   /**< HICK divided by 1.         */

#define AT32_HICK_TO_SCLK_MASK      (1 << 14)   /**< HICK_TO_SCLK mask.         */
#define AT32_HICK_TO_SCLK_8M        (0 << 14)   /**< SCLK is 8MHz if SCLK 
                                                     is HICK.                   */
#define AT32_HICK_TO_SCLK_HICKOUT   (1 << 14)   /**< SCLK is HICKOUT if SCLK 
                                                     is HICK.                   */

#define AT32_CLKOUTDIV2_MASK        (15 << 28)  /**< CLKOUTDIV2 mask.           */
#define AT32_CLKOUTDIV2_DIV1        (0 << 28)   /**< CLKOUT divided by 1.       */
#define AT32_CLKOUTDIV2_DIV2        (8 << 28)   /**< CLKOUT divided by 2.       */
#define AT32_CLKOUTDIV2_DIV4        (9 << 28)   /**< CLKOUT divided by 4.       */
#define AT32_CLKOUTDIV2_DIV8        (10 << 28)  /**< CLKOUT divided by 8.       */
#define AT32_CLKOUTDIV2_DIV16       (11 << 28)  /**< CLKOUT divided by 16.      */
#define AT32_CLKOUTDIV2_DIV64       (12 << 28)  /**< CLKOUT divided by 64.      */
#define AT32_CLKOUTDIV2_DIV128      (13 << 28)  /**< CLKOUT divided by 128.     */
#define AT32_CLKOUTDIV2_DIV256      (14 << 28)  /**< CLKOUT divided by 256.     */
#define AT32_CLKOUTDIV2_DIV512      (15 << 28)  /**< CLKOUT divided by 512.     */
/** @} */

/**
 * @name    CRM_MISC2 register bits definitions
 * @{
 */
#define AT32_PLLU_USB48_SEL_MASK     (1 << 10)  /**< PLLU_USB48_SEL mask.       */
#define AT32_PLLU_USB48_SEL_PLLU     (0 << 10)  /**< PLLU_USB48_SEL PLLU.       */
#define AT32_PLLU_USB48_SEL_HICK     (1 << 10)  /**< PLLU_USB48_SEL HICK.       */

#define AT32_HICK_TO_SCLK_DIV_MASK   (7 << 16)  /**< HICK_TO_SCLK_DIV mask.     */
#define AT32_HICK_TO_SCLK_DIV_DIV1   (0 << 16)  /**< HICK divided by 1.         */
#define AT32_HICK_TO_SCLK_DIV_DIV2   (1 << 16)  /**< HICK divided by 2.         */
#define AT32_HICK_TO_SCLK_DIV_DIV4   (2 << 16)  /**< HICK divided by 4.         */
#define AT32_HICK_TO_SCLK_DIV_DIV8   (3 << 16)  /**< HICK divided by 8.         */
#define AT32_HICK_TO_SCLK_DIV_DIV16  (4 << 16)  /**< HICK divided by 16.        */

#define AT32_HEXT_TO_SCLK_DIV_MASK   (7 << 19)  /**< HEXT_TO_SCLK_DIV mask.     */
#define AT32_HEXT_TO_SCLK_DIV_DIV1   (0 << 19)  /**< HEXT divided by 1.         */
#define AT32_HEXT_TO_SCLK_DIV_DIV2   (1 << 19)  /**< HEXT divided by 2.         */
#define AT32_HEXT_TO_SCLK_DIV_DIV4   (2 << 19)  /**< HEXT divided by 4.         */
#define AT32_HEXT_TO_SCLK_DIV_DIV8   (3 << 19)  /**< HEXT divided by 8.         */
#define AT32_HEXT_TO_SCLK_DIV_DIV16  (4 << 19)  /**< HEXT divided by 16.        */
#define AT32_HEXT_TO_SCLK_DIV_DIV32  (5 << 19)  /**< HEXT divided by 32.        */
/** @} */

/**
 * @name    SYSTICK_CTRL register bits definitions
 * @{
 */
#define AT32_SYSTICK_CLKSRC_HCLKDIV8 (0 << 0)  /**< Systick clk is hclk/8       */
#define AT32_SYSTICK_CLKSRC_HCLKDIV1 (4 << 0)  /**< Systick clk is hclk.        */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Disables the PWR/CRM initialization in the HAL.
 */
#if !defined(AT32_NO_INIT) || defined(__DOXYGEN__)
#define AT32_NO_INIT                       FALSE
#endif

/**
 * @brief   Enables or disables the programmable voltage detector.
 */
#if !defined(AT32_PVM_ENABLE) || defined(__DOXYGEN__)
#define AT32_PVM_ENABLE                    FALSE
#endif

/**
 * @brief   Sets voltage level for programmable voltage detector.
 */
#if !defined(AT32_PVM) || defined(__DOXYGEN__)
#define AT32_PVM                           AT32_PVMSEL_LEV0
#endif

/**
 * @brief   Enables or disables the HICK clock source.
 */
#if !defined(AT32_HICK_ENABLED) || defined(__DOXYGEN__)
#define AT32_HICK_ENABLED                  TRUE
#endif

/**
 * @brief   Enables or disables the LICK clock source.
 */
#if !defined(AT32_LICK_ENABLED) || defined(__DOXYGEN__)
#define AT32_LICK_ENABLED                  FALSE
#endif

/**
 * @brief   Enables or disables the HEXT clock source.
 */
#if !defined(AT32_HEXT_ENABLED) || defined(__DOXYGEN__)
#define AT32_HEXT_ENABLED                  TRUE
#endif

/**
 * @brief   Enables or disables the LEXT clock source.
 */
#if !defined(AT32_LEXT_ENABLED) || defined(__DOXYGEN__)
#define AT32_LEXT_ENABLED                  FALSE
#endif

/**
 * @brief   Enables or disables the PLLU clock source.
 */
#if !defined(AT32_PLLU_ENABLED) || defined(__DOXYGEN__)
#define AT32_PLLU_ENABLED                  TRUE
#endif

/**
 * @brief   USB clock setting.
 */
#if !defined(AT32_CLOCK48_REQUIRED) || defined(__DOXYGEN__)
#define AT32_CLOCK48_REQUIRED              TRUE
#endif

/**
 * @brief   USB clock source selection.
 */
#if !defined(AT32_PLLU_USB48_SEL) || defined(__DOXYGEN__)
#define AT32_PLLU_USB48_SEL                AT32_PLLU_USB48_SEL_PLLU
#endif

/**
 * @brief   Main clock source selection.
 * @note    If the selected clock source is not the PLL then the PLL is not
 *          initialized and started.
 * @note    The default value is calculated for a 216MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(AT32_SCLKSEL) || defined(__DOXYGEN__)
#define AT32_SCLKSEL                       AT32_SCLKSEL_PLL
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 216MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(AT32_PLLRCS) || defined(__DOXYGEN__)
#define AT32_PLLRCS                        AT32_PLLRCS_HEXT
#endif

/**
 * @brief   PLL_MS divider value.
 * @note    The allowed values are 1..15.
 * @note    The default value is calculated for a 216MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(AT32_PLL_MS_VALUE) || defined(__DOXYGEN__)
#define AT32_PLL_MS_VALUE                  1
#endif

/**
 * @brief   PLL_NS multiplier value.
 * @note    The allowed values are 31..500.
 * @note    The default value is calculated for a 216MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(AT32_PLL_NS_VALUE) || defined(__DOXYGEN__)
#define AT32_PLL_NS_VALUE                  72
#endif

/**
 * @brief   PLL_FP divider value.
 * @note    The allowed values are 1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
 *          22, 24, 26, 28, 30.
 * @note    The default value is calculated for a 216MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(AT32_PLL_FP_VALUE) || defined(__DOXYGEN__)
#define AT32_PLL_FP_VALUE                  4
#endif

/**
 * @brief   PLL_FU divider value.
 * @note    The allowed values are 11, 12, 13, 14, 16, 18, 20.
 * @note    The default value is calculated for a 216MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(AT32_PLL_FU_VALUE) || defined(__DOXYGEN__)
#define AT32_PLL_FU_VALUE                  18
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 216MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(AT32_AHBDIV) || defined(__DOXYGEN__)
#define AT32_AHBDIV                        AT32_AHBDIV_DIV1
#endif

/**
 * @brief   APB1 prescaler value.
 */
#if !defined(AT32_APB1DIV) || defined(__DOXYGEN__)
#define AT32_APB1DIV                       AT32_APB1DIV_DIV2
#endif

/**
 * @brief   APB2 prescaler value.
 */
#if !defined(AT32_APB2DIV) || defined(__DOXYGEN__)
#define AT32_APB2DIV                       AT32_APB2DIV_DIV1
#endif

/**
 * @brief   HICK source selection if SCLK is HICK.
 */
#if !defined(AT32_HICK_TO_SCLK) || defined(__DOXYGEN__)
#define AT32_HICK_TO_SCLK                  AT32_HICK_TO_SCLK_HICKOUT
#endif

/**
 * @brief   HICK prescaler selection.
 */
#if !defined(AT32_HICKDIV) || defined(__DOXYGEN__)
#define AT32_HICKDIV                       AT32_HICKDIV_DIV1
#endif

/**
 * @brief   HICK prescaler value when SCLK is HICK.
 */
#if !defined(AT32_HICK_TO_SCLK_DIV) || defined(__DOXYGEN__)
#define AT32_HICK_TO_SCLK_DIV              AT32_HICK_TO_SCLK_DIV_DIV1
#endif

/**
 * @brief   HEXT prescaler value when SCLK is HEXT.
 */
#if !defined(AT32_HEXT_TO_SCLK_DIV) || defined(__DOXYGEN__)
#define AT32_HEXT_TO_SCLK_DIV              AT32_HEXT_TO_SCLK_DIV_DIV1
#endif

/**
 * @brief   ERTC clock source.
 */
#if !defined(AT32_ERTCSEL) || defined(__DOXYGEN__)
#define AT32_ERTCSEL                      AT32_ERTCSEL_NOCLOCK
#endif

/**
 * @brief   ERTC HEXT prescaler value.
 * @note    The allowed values are 2..31.
 */
#if !defined(AT32_ERTCDIV_VALUE) || defined(__DOXYGEN__)
#define AT32_ERTCDIV_VALUE                12
#endif

/**
 * @brief   I2SF5 clock source.
 */
#if !defined(AT32_I2SF5CLKSEL) || defined(__DOXYGEN__)
#define AT32_I2SF5CLKSEL                  AT32_I2SF5CLKSEL_SCLK
#endif

/**
 * @brief   CLKOUT pin setting.
 */
#if !defined(AT32_CLKOUT_SEL) || defined(__DOXYGEN__)
#define AT32_CLKOUT_SEL                   AT32_CLKOUT_SEL_HICK
#endif

/**
 * @brief   CLKOUT prescaler value 1.
 */
#if !defined(AT32_CLKOUTDIV1) || defined(__DOXYGEN__)
#define AT32_CLKOUTDIV1                   AT32_CLKOUTDIV1_DIV1
#endif

/**
 * @brief   CLKOUT prescaler value 2.
 */
#if !defined(AT32_CLKOUTDIV2) || defined(__DOXYGEN__)
#define AT32_CLKOUTDIV2                   AT32_CLKOUTDIV2_DIV1
#endif

/**
 * @brief   LDOOVSEL setting.
 */
#if !defined(AT32_LDOOVSEL) || defined(__DOXYGEN__)
#define AT32_LDOOVSEL                     AT32_LDOOVSEL_1P3V
#endif

/**
 * @brief   Systick clock source setting.
 */
#if !defined(AT32_SYSTICK_CLKSRC) || defined(__DOXYGEN__)
#define AT32_SYSTICK_CLKSRC               AT32_SYSTICK_CLKSRC_HCLKDIV1
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(AT32F405xx_MCUCONF)
#error "Using a wrong mcuconf.h file, AT32F405xx_MCUCONF not defined"
#endif

/*
 * Board files sanity checks.
 */
#if !defined(AT32_LEXTCLK)
#error "AT32_LEXTCLK not defined in board.h"
#endif

#if !defined(AT32_HEXTCLK)
#error "AT32_HEXTCLK not defined in board.h"
#endif

/*
 * HICK related checks.
 */
#if AT32_HICK_ENABLED
#else /* !AT32_HICK_ENABLED */

#if AT32_SCLKSEL == AT32_SCLKSEL_HICK
#error "HICK not enabled, required by AT32_SCLKSEL"
#endif

#if ((AT32_SCLKSEL == AT32_SCLKSEL_HICK) &&                                      \
     (AT32_PLLRCS == AT32_PLLRCS_HICK))
#error "HICK not enabled, required by AT32_SCLKSEL and AT32_PLLRCS"
#endif

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_HICK) ||                                 \
    ((AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLL) &&                                 \
     (AT32_PLLRCS == AT32_PLLRCS_HICK))
#error "HICK not enabled, required by AT32_CLKOUT_SEL"
#endif

#if (AT32_PLLU_USB48_SEL == AT32_PLLU_USB48_SEL_HICK) ||                         \
    ((AT32_PLLU_USB48_SEL == AT32_PLLU_USB48_SEL_PLLU) &&                        \
     (AT32_PLLRCS == AT32_PLLRCS_HICK))
#error "HICK not enabled, required by AT32_PLLU_USB48_SEL"
#endif

#if (AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_HICK) ||                               \
    ((AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_PLL) &&                               \
     (AT32_PLLRCS == AT32_PLLRCS_HICK)) ||                                       \
    ((AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_SCLK) &&                              \
     (AT32_SCLKSEL == AT32_SCLKSEL_HICK)) ||                                     \
    ((AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_SCLK) &&                              \
     (AT32_SCLKSEL == AT32_SCLKSEL_PLL) &&                                       \
     (AT32_PLLRCS == AT32_PLLRCS_HICK))
#error "HICK not enabled, required by AT32_I2SF5CLKSEL"
#endif

#endif /* !AT32_HICK_ENABLED */

/*
 * HEXT related checks.
 */
#if AT32_HEXT_ENABLED

#if AT32_HEXTCLK == 0
#error "HEXT frequency not defined"
#else /* AT32_HEXTCLK != 0 */
#if defined(AT32_HEXT_BYPASS)
#if (AT32_HEXTCLK < AT32_HEXTCLK_BYP_MIN) || (AT32_HEXTCLK > AT32_HEXTCLK_BYP_MAX)
#error "AT32_HEXTCLK outside acceptable range (AT32_HEXTCLK_MIN...AT32_HEXTCLK_BYP_MAX)"
#endif
#else /* !defined(AT32_HEXT_BYPASS) */
#if (AT32_HEXTCLK < AT32_HEXTCLK_MIN) || (AT32_HEXTCLK > AT32_HEXTCLK_MAX)
#error "AT32_HEXTCLK outside acceptable range (AT32_HEXTCLK_MIN...AT32_HEXTCLK_MAX)"
#endif
#endif /* !defined(AT32_HEXT_BYPASS) */
#endif /* AT32_HEXTCLK != 0 */

#else /* !AT32_HEXT_ENABLED */

#if AT32_SCLKSEL == AT32_SCLKSEL_HEXT
#error "HEXT not enabled, required by AT32_SCLKSEL"
#endif

#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) && (AT32_PLLRCS == AT32_PLLRCS_HEXT)
#error "HEXT not enabled, required by AT32_SCLKSEL and AT32_PLLRCS"
#endif

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_HEXT) ||                                \
    ((AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLL) &&                                \
     (AT32_PLLRCS == AT32_PLLRCS_HEXT))
#error "HEXT not enabled, required by AT32_CLKOUT_SEL"
#endif

#if AT32_ERTCSEL == AT32_ERTCSEL_HEXTDIV
#error "HEXT not enabled, required by AT32_ERTCSEL"
#endif

#if ((AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_PLL) &&                               \
     (AT32_PLLRCS == AT32_PLLRCS_HEXT)) ||                                       \
    ((AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_SCLK) &&                              \
     (AT32_SCLKSEL == AT32_SCLKSEL_HEXT)) ||                                     \
    ((AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_SCLK) &&                              \
     (AT32_SCLKSEL == AT32_SCLKSEL_PLL) &&                                       \
     (AT32_PLLRCS == AT32_PLLRCS_HEXT))
#error "HICK not enabled, required by AT32_I2SF5CLKSEL"
#endif

#endif /* !AT32_HEXT_ENABLED */

#if AT32_LICK_ENABLED
#else /* !AT32_LICK_ENABLED */

#if AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_LICK
#error "LICK not enabled, required by AT32_CLKOUT_SEL"
#endif
#if HAL_USE_RTC && (AT32_ERTCSEL == AT32_ERTCSEL_LICK)
#error "LICK not enabled, required by AT32_ERTCSEL"
#endif
#endif /* !AT32_LICK_ENABLED */

/* LEXT related checks.*/
#if AT32_LEXT_ENABLED
#if (AT32_LEXTCLK == 0)
#error "impossible to activate LEXT, frequency is zero"
#endif

#if (AT32_LEXTCLK < AT32_LEXTCLK_MIN) || (AT32_LEXTCLK > AT32_LEXTCLK_MAX)
#error "AT32_LEXTCLK outside acceptable range (AT32_LEXTCLK_MIN...AT32_LEXTCLK_MAX)"
#endif

#else /* !AT32_LEXT_ENABLED */

#if AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_LEXT
#error "LEXT not enabled, required by AT32_CLKOUT_SEL"
#endif
#if AT32_ERTCSEL == AT32_ERTCSEL_LEXT
#error "LEXT not enabled, required by AT32_ERTCSEL"
#endif
#endif /* !AT32_LEXT_ENABLED */

#if AT32_PLLU_ENABLED
#else /* !AT32_PLLU_ENABLED */

#if AT32_PLLU_USB48_SEL == AT32_PLLU_USB48_SEL_PLLU
#error "PLLU not enabled, required by AT32_PLLU_USB48_SEL"
#endif
#endif /* !AT32_PLLU_ENABLED */

/**
 * @brief   AT32_PLL_MS field.
 */
#if ((AT32_PLL_MS_VALUE >= 1) && (AT32_PLL_MS_VALUE <= 15)) ||                 \
    defined(__DOXYGEN__)
#define AT32_PLL_MS                  (AT32_PLL_MS_VALUE << 0)
#else
#error "invalid AT32_PLL_MS_VALUE value specified"
#endif

/**
 * @brief   HICK output clock frequency.
 */
#if (AT32_HICKDIV == AT32_HICKDIV_DIV1) || defined(__DOXYGEN__)
#define AT32_HICKCLKOUT              (AT32_HICKCLK / 1)
#elif (AT32_HICKDIV == AT32_HICKDIV_DIV6)
#define AT32_HICKCLKOUT              (AT32_HICKCLK / 6)
#else
#error "invalid AT32_HICKDIV value specified"
#endif

/**
 * @brief   PLLs input clock frequency.
 */
#if (AT32_PLLRCS == AT32_PLLRCS_HEXT) || defined(__DOXYGEN__)
#define AT32_PLLCLKIN                (AT32_HEXTCLK / AT32_PLL_MS_VALUE)
#elif AT32_PLLRCS == AT32_PLLRCS_HICK
#define AT32_PLLCLKIN                ((AT32_HICKCLK / 6) / AT32_PLL_MS_VALUE)
#else
#error "invalid AT32_PLLRCS value specified"
#endif

/*
 * PLLs input frequency range check.
 */
#if (AT32_PLLCLKIN < AT32_PLLIN_MIN) || (AT32_PLLCLKIN > AT32_PLLIN_MAX)
#error "AT32_PLLCLKIN outside acceptable range (AT32_PLLIN_MIN...AT32_PLLIN_MAX)"
#endif

/*
 * PLL enable check.
 */
#if (AT32_CLOCK48_REQUIRED && (AT32_PLLU_USB48_SEL == AT32_PLLU_USB48_SEL_PLLU)) ||   \
    (AT32_SCLKSEL == AT32_SCLKSEL_PLL) ||                                             \
    (AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_PLL) ||                                     \
    (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLL) ||                                       \
    (AT32_PLLU_ENABLED) || defined(__DOXYGEN__)
/**
 * @brief   PLL activation flag.
 */
#define AT32_ACTIVATE_PLL            TRUE
#else
#define AT32_ACTIVATE_PLL            FALSE
#endif

/**
 * @brief   AT32_PLL_NS field.
 */
#if ((AT32_PLL_NS_VALUE >= 31) && (AT32_PLL_NS_VALUE <= 500)) ||              \
    defined(__DOXYGEN__)
#define AT32_PLL_NS                  (AT32_PLL_NS_VALUE << 6)
#else
#error "invalid AT32_PLL_NS_VALUE value specified"
#endif

/**
 * @brief   AT32_PLL_FP field.
 */
#if (AT32_PLL_FP_VALUE == 1) || defined(__DOXYGEN__)
#define AT32_PLL_FP                  AT32_PLL_FP_DIV1
#elif AT32_PLL_FP_VALUE == 2
#define AT32_PLL_FP                  AT32_PLL_FP_DIV2
#elif AT32_PLL_FP_VALUE == 4
#define AT32_PLL_FP                  AT32_PLL_FP_DIV4
#elif AT32_PLL_FP_VALUE == 6
#define AT32_PLL_FP                  AT32_PLL_FP_DIV6
#elif AT32_PLL_FP_VALUE == 8
#define AT32_PLL_FP                  AT32_PLL_FP_DIV8
#elif AT32_PLL_FP_VALUE == 10
#define AT32_PLL_FP                  AT32_PLL_FP_DIV10
#elif AT32_PLL_FP_VALUE == 12
#define AT32_PLL_FP                  AT32_PLL_FP_DIV12
#elif AT32_PLL_FP_VALUE == 14
#define AT32_PLL_FP                  AT32_PLL_FP_DIV14
#elif AT32_PLL_FP_VALUE == 16
#define AT32_PLL_FP                  AT32_PLL_FP_DIV16
#elif AT32_PLL_FP_VALUE == 18
#define AT32_PLL_FP                  AT32_PLL_FP_DIV18
#elif AT32_PLL_FP_VALUE == 20
#define AT32_PLL_FP                  AT32_PLL_FP_DIV20
#else
#error "invalid AT32_PLL_FP_VALUE value specified"
#endif

/**
 * @brief   AT32_PLL_FU field.
 */
#if (AT32_PLL_FU_VALUE == 11) || defined(__DOXYGEN__)
#define AT32_PLL_FU                  AT32_PLL_FU_DIV11
#elif AT32_PLL_FU_VALUE == 12
#define AT32_PLL_FU                  AT32_PLL_FU_DIV12
#elif AT32_PLL_FU_VALUE == 13
#define AT32_PLL_FU                  AT32_PLL_FU_DIV13
#elif AT32_PLL_FU_VALUE == 14
#define AT32_PLL_FU                  AT32_PLL_FU_DIV14
#elif AT32_PLL_FU_VALUE == 16
#define AT32_PLL_FU                  AT32_PLL_FU_DIV16
#elif AT32_PLL_FU_VALUE == 18
#define AT32_PLL_FU                  AT32_PLL_FU_DIV18
#elif AT32_PLL_FU_VALUE == 20
#define AT32_PLL_FU                  AT32_PLL_FU_DIV20
#else
#error "invalid AT32_PLL_FU_VALUE value specified"
#endif

/**
 * @brief   PLL VCO frequency.
 */
#define AT32_PLLVCO                  (AT32_PLLCLKIN * AT32_PLL_NS_VALUE)

/*
 * PLL VCO frequency range check.
 */
#if (AT32_PLLVCO < AT32_PLLVCO_MIN) || (AT32_PLLVCO > AT32_PLLVCO_MAX)
#error "AT32_PLLVCO outside acceptable range (AT32_PLLVCO_MIN...AT32_PLLVCO_MAX)"
#endif

/**
 * @brief   PLL PCLK output clock frequency.
 */
#define AT32_PLLPCLK                 (AT32_PLLVCO / AT32_PLL_FP_VALUE)

/*
 * PLL PCLK frequency range check.
 */
#if (AT32_PLLPCLK < AT32_PLLOUT_MIN) || (AT32_PLLPCLK > AT32_PLLOUT_MAX)
#error "AT32_PLLPCLK outside acceptable range (AT32_PLLOUT_MIN...AT32_PLLOUT_MAX)"
#endif

/**
 * @brief   PLL UCLK output clock frequency.
 */
#define AT32_PLLUCLK                 (AT32_PLLVCO / AT32_PLL_FU_VALUE)

/*
 * PLL UCLK frequency range check.
 */
#if (AT32_PLLUCLK < AT32_PLLOUT_MIN) || (AT32_PLLUCLK > AT32_PLLOUT_MAX)
#error "AT32_PLLUCLK outside acceptable range (AT32_PLLOUT_MIN...AT32_PLLOUT_MAX)"
#endif

/**
 * @brief   System clock source.
 */
#if AT32_NO_INIT || (AT32_SCLKSEL == AT32_SCLKSEL_HICK) ||                    \
    defined(__DOXYGEN__)

#if (AT32_HICK_TO_SCLK == AT32_HICK_TO_SCLK_8M) || defined(__DOXYGEN__)
#define AT32_SYSCLKIN                (8000000)
#elif (AT32_HICK_TO_SCLK == AT32_HICK_TO_SCLK_HICKOUT) 
#define AT32_SYSCLKIN                (AT32_HICKCLKOUT)
#else
#error  "invalid AT32_HICK_TO_SCLK value specified"
#endif

#if (AT32_HICK_TO_SCLK_DIV == AT32_HICK_TO_SCLK_DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_SYSCLK                  (AT32_SYSCLKIN / 1)
#elif (AT32_HICK_TO_SCLK_DIV == AT32_HICK_TO_SCLK_DIV_DIV2)
#define AT32_SYSCLK                  (AT32_SYSCLKIN / 2)
#elif (AT32_HICK_TO_SCLK_DIV == AT32_HICK_TO_SCLK_DIV_DIV4)
#define AT32_SYSCLK                  (AT32_SYSCLKIN / 4)
#elif (AT32_HICK_TO_SCLK_DIV == AT32_HICK_TO_SCLK_DIV_DIV8)
#define AT32_SYSCLK                  (AT32_SYSCLKIN / 8)
#elif (AT32_HICK_TO_SCLK_DIV == AT32_HICK_TO_SCLK_DIV_DIV16)
#define AT32_SYSCLK                  (AT32_SYSCLKIN / 16)
#else
#error  "invalid AT32_HICK_TO_SCLK_DIV value specified"
#endif

#elif AT32_SCLKSEL == AT32_SCLKSEL_HEXT

#if (AT32_HEXT_TO_SCLK_DIV == AT32_HEXT_TO_SCLK_DIV_DIV1)
#define AT32_SYSCLK                  (AT32_HEXTCLK / 1)
#elif (AT32_HEXT_TO_SCLK_DIV == AT32_HEXT_TO_SCLK_DIV_DIV2)
#define AT32_SYSCLK                  (AT32_HEXTCLK / 2)
#elif (AT32_HEXT_TO_SCLK_DIV == AT32_HEXT_TO_SCLK_DIV_DIV4)
#define AT32_SYSCLK                  (AT32_HEXTCLK / 4)
#elif (AT32_HEXT_TO_SCLK_DIV == AT32_HEXT_TO_SCLK_DIV_DIV8)
#define AT32_SYSCLK                  (AT32_HEXTCLK / 8)
#elif (AT32_HEXT_TO_SCLK_DIV == AT32_HEXT_TO_SCLK_DIV_DIV16)
#define AT32_SYSCLK                  (AT32_HEXTCLK / 16)
#elif (AT32_HEXT_TO_SCLK_DIV == AT32_HEXT_TO_SCLK_DIV_DIV32)
#define AT32_SYSCLK                  (AT32_HEXTCLK / 32)
#else
#error  "invalid AT32_HEXT_TO_SCLK_DIV value specified"
#endif

#elif AT32_SCLKSEL == AT32_SCLKSEL_PLL

#define AT32_SYSCLK                  AT32_PLLPCLK

#else
#error "invalid AT32_SCLKSEL value specified"
#endif

/* Check on the system clock.*/
#if AT32_SYSCLK > AT32_SYSCLK_MAX
#error "AT32_SYSCLK above maximum rated frequency (AT32_SYSCLK_MAX)"
#endif

/**
 * @brief   AHB frequency.
 */
#if (AT32_AHBDIV == AT32_AHBDIV_DIV1) || defined(__DOXYGEN__)
#define AT32_HCLK                   (AT32_SYSCLK / 1)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV2
#define AT32_HCLK                   (AT32_SYSCLK / 2)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV4
#define AT32_HCLK                   (AT32_SYSCLK / 4)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV8
#define AT32_HCLK                   (AT32_SYSCLK / 8)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV16
#define AT32_HCLK                   (AT32_SYSCLK / 16)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV64
#define AT32_HCLK                   (AT32_SYSCLK / 64)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV128
#define AT32_HCLK                   (AT32_SYSCLK / 128)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV256
#define AT32_HCLK                   (AT32_SYSCLK / 256)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV512
#define AT32_HCLK                   (AT32_SYSCLK / 512)
#else
#error "invalid AT32_AHBDIV value specified"
#endif

/* AHB frequency check.*/
#if AT32_HCLK > AT32_SYSCLK_MAX
#error "AT32_HCLK exceeding maximum frequency (AT32_SYSCLK_MAX)"
#endif

/**
 * @brief   APB1 frequency.
 */
#if (AT32_APB1DIV == AT32_APB1DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_PCLK1                 (AT32_HCLK / 1)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV2
#define AT32_PCLK1                 (AT32_HCLK / 2)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV4
#define AT32_PCLK1                 (AT32_HCLK / 4)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV8
#define AT32_PCLK1                 (AT32_HCLK / 8)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV16
#define AT32_PCLK1                 (AT32_HCLK / 16)
#else
#error "invalid AT32_APB1DIV value specified"
#endif

/* APB1 frequency check.*/
#if AT32_PCLK1 > AT32_PCLK1_MAX
#error "AT32_PCLK1 exceeding maximum frequency (AT32_PCLK1_MAX)"
#endif

/**
 * @brief   APB2 frequency.
 */
#if (AT32_APB2DIV == AT32_APB2DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_PCLK2                 (AT32_HCLK / 1)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV2
#define AT32_PCLK2                 (AT32_HCLK / 2)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV4
#define AT32_PCLK2                 (AT32_HCLK / 4)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV8
#define AT32_PCLK2                 (AT32_HCLK / 8)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV16
#define AT32_PCLK2                 (AT32_HCLK / 16)
#else
#error "invalid AT32_APB2DIV value specified"
#endif

/* APB2 frequency check.*/
#if AT32_PCLK2 > AT32_PCLK2_MAX
#error "AT32_PCLK2 exceeding maximum frequency (AT32_PCLK2_MAX)"
#endif

/* Check on LDOOVSEL value.*/
#if AT32_LDOOVSEL == AT32_LDOOVSEL_1P3V

#if (AT32_HCLK > 216000000) ||                                              \
    (AT32_PCLK1 > 120000000) ||                                             \
    (AT32_PCLK2 > AT32_HCLK)
#error "AT32 bus clock exceeding maximum frequency when LDO is 1.3V"
#endif

#elif AT32_LDOOVSEL == AT32_LDOOVSEL_1P2V

#if (AT32_HCLK > 168000000) ||                                              \
    (AT32_PCLK1 > 120000000) ||                                             \
    (AT32_PCLK2 > AT32_HCLK)
#error "AT32 bus clock exceeding maximum frequency when LDO is 1.2V"
#endif

#elif ((AT32_LDOOVSEL == AT32_LDOOVSEL_1P1V) ||                             \
       (AT32_LDOOVSEL == AT32_LDOOVSEL_1P0V))

#if (AT32_HCLK > 108000000) ||                                              \
    (AT32_PCLK1 > AT32_HCLK) ||                                             \
    (AT32_PCLK2 > AT32_HCLK)
#error "AT32 bus clock exceeding maximum frequency when LDO is 1.0V"
#endif

#else
#error "invalid AT32_LDOOVSEL value specified"
#endif

/**
 * @brief   USB clock.
 */
#if AT32_PLLU_USB48_SEL == AT32_PLLU_USB48_SEL_PLLU
#define AT32_USBCLK                 AT32_PLLUCLK
#elif AT32_PLLU_USB48_SEL == AT32_PLLU_USB48_SEL_HICK
#define AT32_USBCLK                 AT32_HICKCLKOUT
#else
#error "invalid AT32_PLLU_USB48_SEL value specified"
#endif

/**
 * @brief   HEXT divider toward ERTC clock.
 */
#if ((AT32_ERTCDIV_VALUE >= 2) && (AT32_ERTCDIV_VALUE <= 31)) ||            \
    defined(__DOXYGEN__)
#define AT32_HEXTDIVCLK             (AT32_HEXTCLK / AT32_ERTCDIV_VALUE)
#define AT32_ETRCDIV                (AT32_ERTCDIV_VALUE << 16)          
#else
#error "invalid AT32_ERTCDIV value specified"
#endif

/**
 * @brief   ERTC clock.
 */
#if (AT32_ERTCSEL == AT32_ERTCSEL_NOCLOCK) || defined(__DOXYGEN__)
#define AT32_ERTCCLK                0
#elif AT32_ERTCSEL == AT32_ERTCSEL_LEXT
#define AT32_ERTCCLK                AT32_LEXTCLK
#elif AT32_ERTCSEL == AT32_ERTCSEL_LICK
#define AT32_ERTCCLK                AT32_LICKCLK
#elif AT32_ERTCSEL == AT32_ERTCSEL_HEXTDIV
#define AT32_ERTCCLK                AT32_HEXTDIVCLK
#else
#error "invalid AT32_ERTCSEL value specified"
#endif

/**
 * @brief   I2SF5 clock.
 */
#if (AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_SCLK) || defined(__DOXYGEN__)
#define AT32_I2SF5CLK               AT32_SYSCLK
#elif AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_PLL
#define AT32_I2SF5CLK               AT32_PLLPCLK
#elif AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_HICK
#define AT32_I2SF5CLK               AT32_HICKCLKOUT
#elif AT32_I2SF5CLKSEL == AT32_I2SF5CLKSEL_EXCLK
#define AT32_I2SF5CLK               0
#else
#error "invalid AT32_I2SF5CLKSEL value specified"
#endif


/**
 * @brief   Systick clock.
 */
#if (AT32_SYSTICK_CLKSRC == AT32_SYSTICK_CLKSRC_HCLKDIV1) || defined(__DOXYGEN__)
#define AT32_SYSTICK_CLK            AT32_HCLK   
#elif AT32_SYSTICK_CLKSRC == AT32_SYSTICK_CLKSRC_HCLKDIV8
#define AT32_SYSTICK_CLK            (AT32_HCLK / 8)  
#else
#error "invalid AT32_SYSTICK_CLKSRC value specified"
#endif

/**
 * @brief   Timers 2, 3, 4, 6, 7, 13, 14 clock.
 */
#if (AT32_APB1DIV == AT32_APB1DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_TMRCLK1                (AT32_PCLK1 * 1)
#else
#define AT32_TMRCLK1                (AT32_PCLK1 * 2)
#endif

/**
 * @brief   Timers 1, 9, 10, 11 clock.
 */
#if (AT32_APB2DIV == AT32_APB2DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_TMRCLK2                (AT32_PCLK2 * 1)
#else
#define AT32_TMRCLK2                (AT32_PCLK2 * 2)
#endif

/**
 * @brief   Flash settings.
 */
#if (AT32_HCLK <= 32000000) || defined(__DOXYGEN__)
#define AT32_FLASHBITS              0x00000150
#elif (AT32_HCLK <= 64000000)
#define AT32_FLASHBITS              0x00000151
#elif (AT32_HCLK <= 96000000)
#define AT32_FLASHBITS              0x00000152
#elif (AT32_HCLK <= 128000000)
#define AT32_FLASHBITS              0x00000153
#elif (AT32_HCLK <= 160000000)
#define AT32_FLASHBITS              0x00000154
#elif (AT32_HCLK <= 192000000)
#define AT32_FLASHBITS              0x00000155
#elif (AT32_HCLK <= 216000000)
#define AT32_FLASHBITS              0x00000156
#endif

#define DEBUG_CTRL_TMR2_PAUSE DEBUG_APB1_PAUSE_TMR2_PAUSE
/* Various helpers.*/
#include "nvic.h"
#include "cache.h"
#include "mpu_v7m.h"
#include "at32_crm.h"
#include "at32_dma.h"
#include "at32_exint.h"
#include "at32_isr.h"
#include "at32_tmr.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void at32_clock_init(void);
  void at32_clock_reset(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */
/** @} */

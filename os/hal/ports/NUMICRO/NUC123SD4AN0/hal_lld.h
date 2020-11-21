/*
    Copyright (C) 2019 /u/KeepItUnder

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
 * @file    NUC123SD4AN0/hal_lld.h
 * @brief   NUC123SD4AN0 HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - NUC123_LSECLK.
 *          - NUC123_LSEDRV.
 *          - NUC123_LSE_BYPASS (optionally).
 *          - NUC123_HSECLK.
 *          - NUC123_HSE_BYPASS (optionally).
 *          .
 *          .
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification macros
 * @{
 */
#if defined(NUC123SD4AN0) || defined(__DOXYGEN__)
#define PLATFORM_NAME           "NUC123SD4AN0 NUC123 Cortex M0 USB Micro"

#else
#error "NUC123 device unsupported or not specified"
#endif
/** @} */

/**
 * @name    Absolute Maximum Ratings
 * @{
 */
/**
 * @brief   Maximum system clock frequency.
 */
#define NUC123_SYSCLK_MAX        FREQ_72MHZ

/**
 * @brief   Maximum HSE clock frequency.
 */
#define NUC123_HSECLK_MAX        24000000

/**
 * @brief   Minimum HSE clock frequency.
 */
#define NUC123_HSECLK_MIN        4000000

/**
 * @brief   Maximum LSE clock frequency.
 */
#define NUC123_LSECLK_MAX        10000

/**
 * @brief   Minimum LSE clock frequency.
 */
#define NUC123_LSECLK_MIN        10000

/**
 * @brief   Maximum PLLs input clock frequency.
 */
#define NUC123_PLLIN_MAX         24000000

/**
 * @brief   Minimum PLLs input clock frequency.
 */
#define NUC123_PLLIN_MIN         4000000

/**
 * @brief   Maximum PLL output clock frequency.
 */
#define NUC123_PLLOUT_MAX        FREQ_72MHZ

/**
 * @brief   Minimum PLL output clock frequency.
 */
#define NUC123_PLLOUT_MIN        4000000

/**
 * @brief   Maximum APB clock frequency.
 */
#define NUC123_PCLK_MAX          FREQ_72MHZ
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define NUC123_HSICLK            __HIRC       /**< High speed internal clock. */
#define NUC123_HSI_69CLK         691200       /**< ~0.69MHz High speed internal clock. */
#define NUC123_HSI1_38CLK        1382400      /**< ~1.375MHz High speed internal clock. */
#define NUC123_HSI2_76CLK        2764800      /**< ~2.75MHz High speed internal clock. */
#define NUC123_HSI5_5CLK         5529600      /**< ~5.5MHz speed internal clock.*/
#define NUC123_HSI11CLK          11059200     /**< ~11MHz speed internal clock.*/
#define NUC123_LSICLK            __LIRC       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    CLKSEL0 register bits definitions
 * @{
 */

#define NUC123_HCLKSRC_HSE       (0 << 0)    /**< HCLK source is HSE         */
#define NUC123_HCLKSRC_PLL_2     (1 << 0)    /**< HCLK source is PLL/2       */
#define NUC123_HCLKSRC_PLL       (2 << 0)    /**< HCLK source is PLL         */
#define NUC123_HCLKSRC_LSI       (3 << 0)    /**< HCLK source is LSI         */
#define NUC123_HCLKSRC_HSI       (7 << 0)    /**< HCLK source is HSI         */

#define NUC123_SW_HSE            (0 << 3)    /**< SYSCLK source is HSE.      */
#define NUC123_SW_HSE_2          (1 << 3)    /**< SYSCLK source is HSE/2.    */
#define NUC123_SW_HCLK_2         (3 << 3)    /**< SYSCLK source is HCLK/2.   */
#define NUC123_SW_HSI_2          (7 << 3)    /**< SYSCLK source is HSI.      */
/** @} */

/**
 * @name    CLKSEL1 register bits definitions
 * @{
 */
#define NUC123_WDTSRC_MASK       (3 << 0)    /**< WDT source mask            */
#define NUC123_WDTSRC_HCLK_2048  (2 << 0)    /**< WDT source is HCLK/2048    */
#define NUC123_WDTSRC_LSI        (3 << 0)    /**< WDT source is LSI          */

#define NUC123_ADCSRC_MASK       (3 << 2)    /**< ADC source mask            */
#define NUC123_ADCSRC_HSE        (0 << 2)    /**< ADC source is HSE          */
#define NUC123_ADCSRC_PLL        (1 << 2)    /**< ADC source is PLL          */
#define NUC123_ADCSRC_HCLK       (2 << 2)    /**< ADC source is HCLK         */
#define NUC123_ADCSRC_HSI        (3 << 2)    /**< ADC source is HSI          */

#define NUC123_SPI0SRC_MASK      (1 << 4)    /**< SPI0 source mask           */
#define NUC123_SPI0SRC_PLL       (0 << 4)    /**< SPI0 source is PLL         */
#define NUC123_SPI0SRC_HCLK      (1 << 4)    /**< SPI0 source is HCLK        */
#define NUC123_SPI1SRC_MASK      (1 << 5)    /**< SPI1 source MASK           */
#define NUC123_SPI1SRC_PLL       (0 << 5)    /**< SPI1 source is PLL         */
#define NUC123_SPI1SRC_HCLK      (1 << 5)    /**< SPI1 source is HCLK        */
#define NUC123_SPI2SRC_MASK      (1 << 6)    /**< SPI2 source mask           */
#define NUC123_SPI2SRC_PLL       (0 << 6)    /**< SPI2 source is PLL         */
#define NUC123_SPI2SRC_HCLK      (1 << 6)    /**< SPI2 source is HCLK        */

#define NUC123_TMR0SRC_MASK      (7 << 8)    /**< TMR0 source mask           */
#define NUC123_TMR0SRC_HSE       (0 << 8)    /**< TMR0 source is HSE         */
#define NUC123_TMR0SRC_HCLK      (2 << 8)    /**< TMR0 source is HCLK        */
#define NUC123_TMR0SRC_TM0       (3 << 8)    /**< TMR0 source is TM0 pin     */
#define NUC123_TMR0SRC_LSI       (5 << 8)    /**< TMR0 source is LSI         */
#define NUC123_TMR0SRC_HSI       (7 << 8)    /**< TMR0 source is HSI         */

#define NUC123_TMR1SRC_MASK      (7 << 12)   /**< TMR1 source mask           */
#define NUC123_TMR1SRC_HSE       (0 << 12)   /**< TMR1 source is HSE         */
#define NUC123_TMR1SRC_HCLK      (2 << 12)   /**< TMR1 source is HCLK        */
#define NUC123_TMR1SRC_TM1       (3 << 12)   /**< TMR1 source is TM1 pin     */
#define NUC123_TMR1SRC_LSI       (5 << 12)   /**< TMR1 source is LSI         */
#define NUC123_TMR1SRC_HSI       (7 << 12)   /**< TMR1 source is HSI         */

#define NUC123_TMR2SRC_MASK      (7 << 16)   /**< TMR2 source mask           */
#define NUC123_TMR2SRC_HSE       (0 << 16)   /**< TMR2 source is HSE         */
#define NUC123_TMR2SRC_HCLK      (2 << 16)   /**< TMR2 source is HCLK        */
#define NUC123_TMR2SRC_TM2       (3 << 16)   /**< TMR2 source is TM2 pin     */
#define NUC123_TMR2SRC_LSI       (5 << 16)   /**< TMR2 source is LSI         */
#define NUC123_TMR2SRC_HSI       (7 << 16)   /**< TMR2 source is HSI         */

#define NUC123_TMR3SRC_MASK      (7 << 20)   /**< TMR3 source mask           */
#define NUC123_TMR3SRC_HSE       (0 << 20)   /**< TMR3 source is HSE         */
#define NUC123_TMR3SRC_HCLK      (2 << 20)   /**< TMR3 source is HCLK        */
#define NUC123_TMR3SRC_LSI       (5 << 20)   /**< TMR3 source is LSI         */
#define NUC123_TMR3SRC_HSI       (7 << 20)   /**< TMR3 source is HSI         */

#define NUC123_USARTSRC_MASK     (3 << 24)   /**< UART source mask.          */
#define NUC123_USARTSRC_HS3      (0 << 24)   /**< UART source is HSE.        */
#define NUC123_USARTSRC_PLL      (1 << 24)   /**< UART source is PLL.        */
#define NUC123_USARTSRC_HSI      (3 << 24)   /**< UART source is HSI.        */

#define NUC123_PWM01SRCA_MASK    (3 << 28)   /**< PWM0/1 source [1:0] mask   */
#define NUC123_PWM01SRCA_HSE     (0 << 28)   /**< PWM0/1 source [1:0] is HSE */
#define NUC123_PWM01SRCA_HCLK    (2 << 28)   /**< PWM0/1 source [1:0] is HCLK*/
#define NUC123_PWM01SRCA_HSI     (3 << 28)   /**< PWM0/1 source [1:0] is HSI */
#define NUC123_PWM01SRCA_LSI     (3 << 28)   /**< PWM0/1 source [1:0] is LSI */

#define NUC123_PWM23SRCA_MASK    (3 << 30)   /**< PWM2/3 source [1:0] mask   */
#define NUC123_PWM23SRCA_HSE     (0 << 30)   /**< PWM2/3 source [1:0] is HSE */
#define NUC123_PWM23SRCA_HCLK    (2 << 30)   /**< PWM2/3 source [1:0] is HCLK*/
#define NUC123_PWM23SRCA_HSI     (3 << 30)   /**< PWM2/3 source [1:0] is HSI */
#define NUC123_PWM23SRCA_LSI     (3 << 30)   /**< PWM2/3 source [1:0] is LSI */
/** @} */

/**
 * @name    CLKSEL2 register bits definitions
 * @{
 */
#define NUC123_I2SSRC_MASK       (3 << 0)    /**< I2S clock source mask.     */
#define NUC123_I2SSRC_HSE        (0 << 0)    /**< I2S clock source is HSE.   */
#define NUC123_I2SSRC_PLL        (1 << 0)    /**< I2S clock source is PLL.   */
#define NUC123_I2SSRC_HCLK       (2 << 0)    /**< I2S clock source is HCLK.  */
#define NUC123_I2SSRC_HSI        (3 << 0)    /**< I2S clock source is HSI.   */

#define NUC123_FREQDIVSRC_MASK   (3 << 2)    /**< FRQDIV clock source mask   */
#define NUC123_FREQDIVSRC_HSE    (0 << 2)    /**< FRQDIV clock source is HSE */
#define NUC123_FREQDIVSRC_HCLK   (2 << 2)    /**< FRQDIV clock source is HCLK*/
#define NUC123_FREQDIVSRC_HSI    (3 << 2)    /**< FRQDIV clock source is LSI */

#define NUC123_PWM01SRCB_MASK    (1 << 8)    /**< PWM0/1 source [2] mask     */
#define NUC123_PWM01SRCB_HSI     (0 << 8)    /**< PWM0/1 source [2] is HSI   */
#define NUC123_PWM01SRCB_LSI     (1 << 8)    /**< PWM0/1 source [2] is LSI   */

#define NUC123_PWM23SRCB_MASK    (1 << 9)    /**< PWM2/3 source [2] mask     */
#define NUC123_PWM23SRCB_HSI     (0 << 9)    /**< PWM2/3 source [2] is HSI   */
#define NUC123_PWM23SRCB_LSI     (1 << 9)    /**< PWM2/3 source [2] is LSI   */

#define NUC123_WWDTSRC_MASK      (3 << 16)   /**< WWDT source mask           */
#define NUC123_WWDTSRC_HCLK_2048 (2 << 16)   /**< WWDT source is HCLK/2048   */
#define NUC123_WWDTSRC_LSI       (3 << 16)   /**< WWDT source is LSI         */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Disables the PWR/RCC initialization in the HAL.
 */
#if !defined(NUC123_NO_INIT) || defined(__DOXYGEN__)
#define NUC123_NO_INIT                       FALSE
#endif

/**
 * @brief   Enables or disables the HSI clock source.
 */
#if !defined(NUC123_HSI_ENABLED) || defined(__DOXYGEN__)
#define NUC123_HSI_ENABLED                   TRUE
#endif

/**
 * @brief   Enables or disables the LSI clock source.
 */
#if !defined(NUC123_LSI_ENABLED) || defined(__DOXYGEN__)
#define NUC123_LSI_ENABLED                   TRUE
#endif

/**
 * @brief   Enables or disables the HSE clock source.
 */
#if !defined(NUC123_HSE_ENABLED) || defined(__DOXYGEN__)
#define NUC123_HSE_ENABLED                   TRUE
#endif

/**
 * @brief   Enables or disables the LSE clock source.
 */
#if !defined(NUC123_LSE_ENABLED) || defined(__DOXYGEN__)
#define NUC123_LSE_ENABLED                   FALSE
#endif

/**
 * @brief   Main clock source selection.
 * @note    If the selected clock source is not the PLL then the PLL is not
 *          initialized and started.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(NUC123_SW) || defined(__DOXYGEN__)
#define NUC123_SW                            NUC123_SW_HCLK_2
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(NUC123_PLLSRC) || defined(__DOXYGEN__)
#define NUC123_PLLSRC                        NUC123_PLLSRC_HSE
#endif

/**
 * @brief   Crystal PLL pre-divider.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 21MHz crystal using the PLL.
 */
#if !defined(NUC123_PREDIV_VALUE) || defined(__DOXYGEN__)
#define NUC123_PREDIV_VALUE                  1
#endif

/** 
 * @brief   PLL multiplier value.
 * @note    The allowed range is 2...16.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(NUC123_PLLMUL_VALUE) || defined(__DOXYGEN__)
#define NUC123_PLLMUL_VALUE                  6
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 12MHz crystal using the PLL.
 */
#if !defined(NUC123_HPRE) || defined(__DOXYGEN__)
#define NUC123_HPRE                          NUC123_HPRE_DIV1
#endif

/**
 * @brief   APB1 prescaler value.
 */
#if !defined(NUC123_PPRE) || defined(__DOXYGEN__)
#define NUC123_PPRE                          NUC123_PPRE_DIV1
#endif

/**
 * @brief   MCO pin setting.
 */
#if !defined(NUC123_MCOSEL) || defined(__DOXYGEN__)
#define NUC123_MCOSEL                        NUC123_MCOSEL_NOCLOCK
#endif

/**
 * @brief   MCO divider setting.
 */
#if !defined(NUC123_MCOPRE) || defined(__DOXYGEN__)
#define NUC123_MCOPRE                        NUC123_MCOPRE_DIV1
#endif

/**
 * @brief   MCO PLL divider setting.
 */
#if !defined(NUC123_PLLNODIV) || defined(__DOXYGEN__)
#define NUC123_PLLNODIV                      NUC123_PLLNODIV_DIV2
#endif

/**
 * @brief USB Clock source.
 */
#if !defined(NUC123_USBSW) || defined(__DOXYGEN__)
#define NUC123_USBSW                         NUC123_USBSW_HSI48
#endif

/**
 * @brief   CEC clock source.
 */
#if !defined(NUC123_CECSW) || defined(__DOXYGEN__)
#define NUC123_CECSW                         NUC123_CECSW_HSI
#endif

/**
 * @brief   I2C1 clock source.
 */
#if !defined(NUC123_I2C1SW) || defined(__DOXYGEN__)
#define NUC123_I2C1SW                        NUC123_I2C1SW_HSI
#endif

/**
 * @brief   USART1 clock source.
 */
#if !defined(NUC123_USART1SW) || defined(__DOXYGEN__)
#define NUC123_USART1SW                      NUC123_USART1SW_PCLK
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(NUC123SD4AN0_MCUCONF)
#error "Using a wrong mcuconf.h file, NUC123SD4AN0_MCUCONF not defined"
#endif

/*
 * HSI related checks.
 */
#if NUC123_HSI_ENABLED

/*#if NUC123_SW == NUC123_SW_HSE
#error "HSI not enabled, required by NUC123_SW"
#endif

#if NUC123_CECSW == NUC123_CECSW_HSI
#error "HSI not enabled, required by NUC123_CECSW"
#endif

#if NUC123_I2C1SW == NUC123_I2C1SW_HSI
#error "HSI not enabled, required by NUC123_I2C1SW"
#endif

#if NUC123_USART1SW == NUC123_USART1SW_HSI
#error "HSI not enabled, required by NUC123_USART1SW"
#endif

#if (NUC123_SW == NUC123_SW_PLL) &&                                           \
    (NUC123_PLLSRC == NUC123_PLLSRC_HSI_DIV2) ||                              \
    (NUC123_PLLSRC == NUC123_PLLSRC_HSI)
#error "HSI not enabled, required by NUC123_SW and NUC123_PLLSRC"
#endif

#if (NUC123_MCOSEL == NUC123_MCOSEL_HSI) ||                                   \
    ((NUC123_MCOSEL == NUC123_MCOSEL_PLLDIV2) &&                              \
    ((NUC123_PLLSRC == NUC123_PLLSRC_HSI_DIV2) ||                             \
    (NUC123_PLLSRC == NUC123_PLLSRC_HSI)))
#error "HSI not enabled, required by NUC123_MCOSEL"
#endif
*/
#endif /* !NUC123_HSI_ENABLED */

/*
 * HSE related checks.
 */
#if NUC123_HSE_ENABLED

#if NUC123_HSECLK == 0
#error "HSE frequency not defined"
#elif (NUC123_HSECLK < NUC123_HSECLK_MIN) || (NUC123_HSECLK > NUC123_HSECLK_MAX)
#error "NUC123_HSECLK outside acceptable range (NUC123_HSECLK_MIN...NUC123_HSECLK_MAX)"
#endif

#else /* !NUC123_HSE_ENABLED */

#if (NUC123_SW == NUC123_SW_HSE) || (NUC123_SW == NUC123_SW_HSE_2)
#error "HSE not enabled, required by NUC123_SW"
#endif

#if (NUC123_SW == NUC123_SW_HCL) && (NUC123_PLLSRC == NUC123_PLLSRC_HSE)
#error "HSE not enabled, required by NUC123_SW and NUC123_PLLSRC"
#endif

#if (NUC123_MCOSEL == NUC123_MCOSEL_HSE) ||                                   \
    ((NUC123_MCOSEL == NUC123_MCOSEL_PLLDIV2) &&                              \
     (NUC123_PLLSRC == NUC123_PLLSRC_HSE))
#error "HSE not enabled, required by NUC123_MCOSEL"
#endif

#endif /* !NUC123_HSE_ENABLED */

/*
 * LSI related checks.
 */
#if NUC123_LSI_ENABLED
#else /* !NUC123_LSI_ENABLED */

#if NUC123_RTCSEL == NUC123_RTCSEL_LSI
#error "LSI not enabled, required by NUC123_RTCSEL"
#endif

#endif /* !NUC123_LSI_ENABLED */

/*
 * LSE related checks.
 */
#if NUC123_LSE_ENABLED

#if (NUC123_LSECLK == 0)
#error "LSE frequency not defined"
#endif

#if (NUC123_LSECLK < NUC123_LSECLK_MIN) || (NUC123_LSECLK > NUC123_LSECLK_MAX)
#error "NUC123_LSECLK outside acceptable range (NUC123_LSECLK_MIN...NUC123_LSECLK_MAX)"
#endif

#if !defined(NUC123_LSEDRV)
#error "NUC123_LSEDRV not defined"
#endif

#if (NUC123_LSEDRV >> 3) > 3
#error "NUC123_LSEDRV outside acceptable range ((0<<3)...(3<<3))"
#endif

#else /* !NUC123_LSE_ENABLED */

#endif /* !NUC123_LSE_ENABLED */

/* PLL activation conditions.*/
#if (NUC123_SW == NUC123_SW_PLL) ||                                           \
    (NUC123_USBSW == NUC123_USBSW_PCLK) ||                                    \
    (NUC123_MCOSEL == NUC123_MCOSEL_PLLDIV2) ||                               \
    defined(__DOXYGEN__)
/**
 * @brief   PLL activation flag.
 */
#define NUC123_ACTIVATE_PLL          TRUE
#else
#define NUC123_ACTIVATE_PLL          FALSE
#endif

/* HSE, HSI prescaler setting check.*/
#if ((NUC123_PREDIV_VALUE >= 1) || (NUC123_PREDIV_VALUE <= 16))
#define NUC123_PREDIV                ((NUC123_PREDIV_VALUE - 1) << 0)
#else
#error "invalid NUC123_PREDIV value specified"
#endif

/**
 * @brief   PLLMUL field.
 */
#if ((NUC123_PLLMUL_VALUE >= 2) && (NUC123_PLLMUL_VALUE <= 16)) ||            \
    defined(__DOXYGEN__)
#define NUC123_PLLMUL                ((NUC123_PLLMUL_VALUE - 2) << 18)
#else
#error "invalid NUC123_PLLMUL_VALUE value specified"
#endif

/**
 * @brief   PLL input clock frequency.
 */
#if (NUC123_PLLSRC == NUC123_PLLSRC_HSE) || defined(__DOXYGEN__)
#define NUC123_PLLCLKIN              (NUC123_HSECLK / NUC123_PREDIV_VALUE)
#elif NUC123_PLLSRC == NUC123_PLLSRC_HSI_DIV2
#define NUC123_PLLCLKIN              (NUC123_HSICLK / 2)
#elif NUC123_PLLSRC == NUC123_PLLSRC_HSI
#define NUC123_PLLCLKIN              (NUC123_HSICLK / NUC123_PREDIV_VALUE)
#else
#error "invalid NUC123_PLLSRC value specified"
#endif

/* PLL input frequency range check.*/
#if (NUC123_PLLCLKIN < NUC123_PLLIN_MIN) || (NUC123_PLLCLKIN > NUC123_PLLIN_MAX)
#error "NUC123_PLLCLKIN outside acceptable range (NUC123_PLLIN_MIN...NUC123_PLLIN_MAX)"
#endif

/**
 * @brief   PLL output clock frequency.
 */
#define NUC123_PLLCLKOUT             (NUC123_PLLCLKIN * NUC123_PLLMUL_VALUE)

/* PLL output frequency range check.
#if (NUC123_PLLCLKOUT < NUC123_PLLOUT_MIN) || (NUC123_PLLCLKOUT > NUC123_PLLOUT_MAX)
#error "NUC123_PLLCLKOUT outside acceptable range (NUC123_PLLOUT_MIN...NUC123_PLLOUT_MAX)"
#endif
*/
/**
 * @brief   System clock source.
 */
#if (NUC123_SW == NUC123_SW_HSE) || defined(__DOXYGEN__)
#define NUC123_SYSCLK                NUC123_HSECLK
#elif (NUC123_SW == NUC123_SW_HSE_2)
#define NUC123_SYSCLK                NUC123_HSECLK >> 1
#elif (NUC123_SW == NUC123_SW_HCLK_2)
#define NUC123_SYSCLK                FREQ_72MHZ >> 1
#elif (NUC123_SW == NUC123_SW_HSI_2)
#define NUC123_SYSCLK                NUC123_HSI11CLK
#else
#error "invalid NUC123_SW value specified"
#endif

/* Check on the system clock.*/
#if NUC123_SYSCLK > NUC123_SYSCLK_MAX
#error "NUC123_SYSCLK above maximum rated frequency (NUC123_SYSCLK_MAX)"
#endif

/**
 * @brief   AHB frequency.
 *
#if (NUC123_HPRE == NUC123_HPRE_DIV1) || defined(__DOXYGEN__)
#define NUC123_HCLK                  (NUC123_SYSCLK / 1)
#elif NUC123_HPRE == NUC123_HPRE_DIV2
#define NUC123_HCLK                  (NUC123_SYSCLK / 2)
#elif NUC123_HPRE == NUC123_HPRE_DIV4
#define NUC123_HCLK                  (NUC123_SYSCLK / 4)
#elif NUC123_HPRE == NUC123_HPRE_DIV8
#define NUC123_HCLK                  (NUC123_SYSCLK / 8)
#elif NUC123_HPRE == NUC123_HPRE_DIV16
#define NUC123_HCLK                  (NUC123_SYSCLK / 16)
#elif NUC123_HPRE == NUC123_HPRE_DIV64
#define NUC123_HCLK                  (NUC123_SYSCLK / 64)
#elif NUC123_HPRE == NUC123_HPRE_DIV128
#define NUC123_HCLK                  (NUC123_SYSCLK / 128)
#elif NUC123_HPRE == NUC123_HPRE_DIV256
#define NUC123_HCLK                  (NUC123_SYSCLK / 256)
#elif NUC123_HPRE == NUC123_HPRE_DIV512
#define NUC123_HCLK                  (NUC123_SYSCLK / 512)
#else
#error "invalid NUC123_HPRE value specified"
#endif
*/
#define NUC123_HCLK                  (NUC123_SYSCLK / 1)

/* AHB frequency check.*/
#if NUC123_HCLK > NUC123_SYSCLK_MAX
#error "NUC123_HCLK exceeding maximum frequency (NUC123_SYSCLK_MAX)"
#endif

/**
 * @brief   APB frequency.
 */
#if (NUC123_PPRE == NUC123_PPRE_DIV1) || defined(__DOXYGEN__)
#define NUC123_PCLK                  (NUC123_HCLK / 1)
#elif NUC123_PPRE == NUC123_PPRE_DIV2
#define NUC123_PCLK                  (NUC123_HCLK / 2)
#elif NUC123_PPRE == NUC123_PPRE_DIV4
#define NUC123_PCLK                  (NUC123_HCLK / 4)
#elif NUC123_PPRE == NUC123_PPRE_DIV8
#define NUC123_PCLK                  (NUC123_HCLK / 8)
#elif NUC123_PPRE == NUC123_PPRE_DIV16
#define NUC123_PCLK                  (NUC123_HCLK / 16)
#else
#error "invalid NUC123_PPRE value specified"
#endif

/* APB frequency check.*/
#if NUC123_PCLK > NUC123_PCLK_MAX
#error "NUC123_PCLK exceeding maximum frequency (NUC123_PCLK_MAX)"
#endif

/* NUC123_PLLNODIV check.*/
#if (NUC123_PLLNODIV != NUC123_PLLNODIV_DIV2) &&                              \
    (NUC123_PLLNODIV != NUC123_PLLNODIV_DIV1)
#error "invalid NUC123_PLLNODIV value specified"
#endif


/**
 * @brief   CEC frequency.
 */
#if (NUC123_CECSW == NUC123_CECSW_HSI) || defined(__DOXYGEN__)
#define NUC123_CECCLK                NUC123_HSICLK
#elif NUC123_CECSW == NUC123_CECSW_LSE
#define NUC123_CECCLK                NUC123_LSECLK
#elif NUC123_CECSW == NUC123_CECSW_OFF
#define NUC123_CECCLK                0
#else
#error "invalid source selected for CEC clock"
#endif

/**
 * @brief   I2C1 frequency.
 */
#if (NUC123_I2C1SW == NUC123_I2C1SW_HSI) || defined(__DOXYGEN__)
#define NUC123_I2C1CLK               NUC123_HSICLK
#elif NUC123_I2C1SW == NUC123_I2C1SW_SYSCLK
#define NUC123_I2C1CLK               NUC123_SYSCLK
#else
#error "invalid source selected for I2C1 clock"
#endif

/**
 * @brief   USART1 frequency.
 */
#if (NUC123_USART1SW == NUC123_USART1SW_PCLK) || defined(__DOXYGEN__)
#define NUC123_USART1CLK             NUC123_PCLK
#elif NUC123_USART1SW == NUC123_USART1SW_SYSCLK
#define NUC123_USART1CLK             NUC123_SYSCLK
#elif NUC123_USART1SW == NUC123_USART1SW_LSE
#define NUC123_USART1CLK             NUC123_LSECLK
#elif NUC123_USART1SW == NUC123_USART1SW_HSI
#define NUC123_USART1CLK             NUC123_HSICLK
#else
#error "invalid source selected for USART1 clock"
#endif

// /**
//  * @brief   USART2 frequency.
//  */
// #define NUC123_USART2CLK             NUC123_PCLK

// /**
//  * @brief   USART3 frequency.
//  */
// #define NUC123_USART3CLK             NUC123_PCLK

// /**
//  * @brief   USART4 frequency.
//  */
// #define NUC123_UART4CLK              NUC123_PCLK

// /**
//  * @brief   USART5 frequency.
//  */
// #define NUC123_UART5CLK              NUC123_PCLK

// /**
//  * @brief   USART6 frequency.
//  */
// #define NUC123_USART6CLK             NUC123_PCLK

/**
 * @brief   Timers clock.
 */
#if (NUC123_PPRE == NUC123_PPRE_DIV1) || defined(__DOXYGEN__)
#define NUC123_TIMCLK1               (NUC123_PCLK * 1)
#define NUC123_TIMCLK2               (NUC123_PCLK * 1)
#else
#define NUC123_TIMCLK1               (NUC123_PCLK * 2)
#define NUC123_TIMCLK2               (NUC123_PCLK * 2)
#endif

/**
 * @brief   Flash settings.
 */
#if (NUC123_HCLK <= 24000000) || defined(__DOXYGEN__)
#define NUC123_FLASHBITS             0x00000010
#else
#define NUC123_FLASHBITS             0x00000011
#endif

/*
 * For compatibility with driver assuming a specific PPRE clock.
 */
#define NUC123_PCLK1 NUC123_PCLK
#define NUC123_PCLK2 NUC123_PCLK

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Various helpers.*/
#include "nvic.h"
#include "nuc123_isr.h"
//#include "nuc123_dma.h"
#include "hal_clks_lld.h"
#include "hal_pwm_lld.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void NUC123_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @} */

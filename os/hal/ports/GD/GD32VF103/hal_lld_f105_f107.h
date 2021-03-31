/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @defgroup STM32F10X_CL_HAL STM32F105/F107 HAL Support
 * @details HAL support for STM32 Connectivity Line sub-family.
 *
 * @ingroup HAL
 */

/**
 * @file    GD32VF103/hal_lld_f105_f107.h
 * @brief   STM32F10x Connectivity Line HAL subsystem low level driver header.
 *
 * @addtogroup STM32F10X_CL_HAL
 * @{
 */

#ifndef _HAL_LLD_F105_F107_H_
#define _HAL_LLD_F105_F107_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Absolute Maximum Ratings
 * @{
 */
/**
 * @brief   Maximum system clock frequency.
 */
#define GD32_SYSCLK_MAX        72000000

/**
 * @brief   Maximum HSE clock frequency.
 */
#define GD32_HSECLK_MAX        50000000

/**
 * @brief   Minimum HSE clock frequency.
 */
#define GD32_HSECLK_MIN        1000000

/**
 * @brief   Maximum LSE clock frequency.
 */
#define GD32_LSECLK_MAX        1000000

/**
 * @brief   Minimum LSE clock frequency.
 */
#define GD32_LSECLK_MIN        32768

/**
 * @brief   Maximum PLLs input clock frequency.
 */
#define GD32_PLL1IN_MAX        12000000

/**
 * @brief   Minimum PLL1 input clock frequency.
 */
#define GD32_PLL1IN_MIN        3000000

/**
 * @brief   Maximum PLL1 input clock frequency.
 */
#define GD32_PLL23IN_MAX       5000000

/**
 * @brief   Minimum PLL2 and PLL3 input clock frequency.
 */
#define GD32_PLL23IN_MIN       3000000

/**
 * @brief   Maximum PLL1 VCO clock frequency.
 */
#define GD32_PLL1VCO_MAX       144000000

/**
 * @brief   Minimum PLL1 VCO clock frequency.
 */
#define GD32_PLL1VCO_MIN       36000000

/**
 * @brief   Maximum PLL2 and PLL3 VCO clock frequency.
 */
#define GD32_PLL23VCO_MAX      148000000

/**
 * @brief   Minimum PLL2 and PLL3 VCO clock frequency.
 */
#define GD32_PLL23VCO_MIN      80000000

/**
 * @brief   Maximum APB1 clock frequency.
 */
#define GD32_PCLK1_MAX         36000000

/**
 * @brief   Maximum APB2 clock frequency.
 */
#define GD32_PCLK2_MAX         72000000

/**
 * @brief   Maximum ADC clock frequency.
 */
#define GD32_ADCCLK_MAX        14000000

/**
 * @brief   Maximum SPI/I2S clock frequency.
 */
#define GD32_SPII2S_MAX        18000000
/** @} */

/**
 * @name    RCU_CFGR register bits definitions
 * @{
 */
#define GD32_SW_HSI            (0 << 0)    /**< SYSCLK source is HSI.      */
#define GD32_SW_HSE            (1 << 0)    /**< SYSCLK source is HSE.      */
#define GD32_SW_PLL            (2 << 0)    /**< SYSCLK source is PLL.      */

#define GD32_HPRE_DIV1         (0 << 4)    /**< SYSCLK divided by 1.       */
#define GD32_HPRE_DIV2         (8 << 4)    /**< SYSCLK divided by 2.       */
#define GD32_HPRE_DIV4         (9 << 4)    /**< SYSCLK divided by 4.       */
#define GD32_HPRE_DIV8         (10 << 4)   /**< SYSCLK divided by 8.       */
#define GD32_HPRE_DIV16        (11 << 4)   /**< SYSCLK divided by 16.      */
#define GD32_HPRE_DIV64        (12 << 4)   /**< SYSCLK divided by 64.      */
#define GD32_HPRE_DIV128       (13 << 4)   /**< SYSCLK divided by 128.     */
#define GD32_HPRE_DIV256       (14 << 4)   /**< SYSCLK divided by 256.     */
#define GD32_HPRE_DIV512       (15 << 4)   /**< SYSCLK divided by 512.     */

#define GD32_PPRE1_DIV1        (0 << 8)    /**< HCLK divided by 1.         */
#define GD32_PPRE1_DIV2        (4 << 8)    /**< HCLK divided by 2.         */
#define GD32_PPRE1_DIV4        (5 << 8)    /**< HCLK divided by 4.         */
#define GD32_PPRE1_DIV8        (6 << 8)    /**< HCLK divided by 8.         */
#define GD32_PPRE1_DIV16       (7 << 8)    /**< HCLK divided by 16.        */

#define GD32_PPRE2_DIV1        (0 << 11)   /**< HCLK divided by 1.         */
#define GD32_PPRE2_DIV2        (4 << 11)   /**< HCLK divided by 2.         */
#define GD32_PPRE2_DIV4        (5 << 11)   /**< HCLK divided by 4.         */
#define GD32_PPRE2_DIV8        (6 << 11)   /**< HCLK divided by 8.         */
#define GD32_PPRE2_DIV16       (7 << 11)   /**< HCLK divided by 16.        */

#define GD32_ADCPRE_DIV2       (0 << 14)   /**< PPRE2 divided by 2.        */
#define GD32_ADCPRE_DIV4       (1 << 14)   /**< PPRE2 divided by 4.        */
#define GD32_ADCPRE_DIV6       (2 << 14)   /**< PPRE2 divided by 6.        */
#define GD32_ADCPRE_DIV8       (3 << 14)   /**< PPRE2 divided by 8.        */

#define GD32_PLLSRC_HSI        (0 << 16)   /**< PLL clock source is HSI.   */
#define GD32_PLLSRC_PREDIV1    (1 << 16)   /**< PLL clock source is
                                                 PREDIV1.                   */

#define GD32_USBFSPRE_DIV2     (1 << 22)   /**< HCLK*2 divided by 2.       */
#define GD32_USBFSPRE_DIV3     (0 << 22)   /**< HCLK*2 divided by 3.       */

#define GD32_MCOSEL_NOCLOCK    (0 << 24)   /**< No clock on MCO pin.       */
#define GD32_MCOSEL_SYSCLK     (4 << 24)   /**< SYSCLK on MCO pin.         */
#define GD32_MCOSEL_HSI        (5 << 24)   /**< HSI clock on MCO pin.      */
#define GD32_MCOSEL_HSE        (6 << 24)   /**< HSE clock on MCO pin.      */
#define GD32_MCOSEL_PLLDIV2    (7 << 24)   /**< PLL/2 clock on MCO pin.    */
#define GD32_MCOSEL_PLL2       (8 << 24)   /**< PLL2 clock on MCO pin.     */
#define GD32_MCOSEL_PLL3DIV2   (9 << 24)   /**< PLL3/2 clock on MCO pin.   */
#define GD32_MCOSEL_XT1        (10 << 24)  /**< XT1 clock on MCO pin.      */
#define GD32_MCOSEL_PLL3       (11 << 24)  /**< PLL3 clock on MCO pin.     */
/** @} */

/**
 * @name    RCU_BDCR register bits definitions
 * @{
 */
#define GD32_RTCSEL_MASK       (3 << 8)    /**< RTC clock source mask.     */
#define GD32_RTCSEL_NOCLOCK    (0 << 8)    /**< No clock.                  */
#define GD32_RTCSEL_LSE        (1 << 8)    /**< LSE used as RTC clock.     */
#define GD32_RTCSEL_LSI        (2 << 8)    /**< LSI used as RTC clock.     */
#define GD32_RTCSEL_HSEDIV     (3 << 8)    /**< HSE divided by 128 used as
                                                 RTC clock.                 */
/** @} */

/**
 * @name    RCU_CFGR2 register bits definitions
 * @{
 */
#define GD32_PREDIV1SRC_HSE    (0 << 16)   /**< PREDIV1 source is HSE.     */
#define GD32_PREDIV1SRC_PLL2   (1 << 16)   /**< PREDIV1 source is PLL2.    */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Main clock source selection.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(GD32_SW) || defined(__DOXYGEN__)
#define GD32_SW                    GD32_SW_PLL
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(GD32_PLLSRC) || defined(__DOXYGEN__)
#define GD32_PLLSRC                GD32_PLLSRC_PREDIV1
#endif

/**
 * @brief   PREDIV1 clock source.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(GD32_PREDIV1SRC) || defined(__DOXYGEN__)
#define GD32_PREDIV1SRC            GD32_PREDIV1SRC_HSE
#endif

/**
 * @brief   PREDIV1 division factor.
 * @note    The allowed range is 1...16.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(GD32_PREDIV1_VALUE) || defined(__DOXYGEN__)
#define GD32_PREDIV1_VALUE         5
#endif

/**
 * @brief   PLL multiplier value.
 * @note    The allowed range is 4...9.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(GD32_PLLMUL_VALUE) || defined(__DOXYGEN__)
#define GD32_PLLMUL_VALUE          9
#endif

/**
 * @brief   PREDIV2 division factor.
 * @note    The allowed range is 1...16.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(GD32_PREDIV2_VALUE) || defined(__DOXYGEN__)
#define GD32_PREDIV2_VALUE         5
#endif

/**
 * @brief   PLL2 multiplier value.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(GD32_PLL2MUL_VALUE) || defined(__DOXYGEN__)
#define GD32_PLL2MUL_VALUE         8
#endif

/**
 * @brief   PLL3 multiplier value.
 * @note    The default value is calculated for a 50MHz clock from
 *          a 25MHz crystal.
 */
#if !defined(GD32_PLL3MUL_VALUE) || defined(__DOXYGEN__)
#define GD32_PLL3MUL_VALUE         10
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(GD32_HPRE) || defined(__DOXYGEN__)
#define GD32_HPRE                  GD32_HPRE_DIV1
#endif

/**
 * @brief   APB1 prescaler value.
 */
#if !defined(GD32_PPRE1) || defined(__DOXYGEN__)
#define GD32_PPRE1                 GD32_PPRE1_DIV2
#endif

/**
 * @brief   APB2 prescaler value.
 */
#if !defined(GD32_PPRE2) || defined(__DOXYGEN__)
#define GD32_PPRE2                 GD32_PPRE2_DIV2
#endif

/**
 * @brief   ADC prescaler value.
 */
#if !defined(GD32_ADCPRE) || defined(__DOXYGEN__)
#define GD32_ADCPRE                GD32_ADCPRE_DIV4
#endif

/**
 * @brief   USB clock setting.
 */
#if !defined(GD32_USBFS_CLOCK_REQUIRED) || defined(__DOXYGEN__)
#define GD32_USBFS_CLOCK_REQUIRED    TRUE
#endif

/**
 * @brief   OTG prescaler initialization.
 */
#if !defined(GD32_USBFSPRE) || defined(__DOXYGEN__)
#define GD32_USBFSPRE              GD32_USBFSPRE_DIV3
#endif

/**
 * @brief   Dedicated I2S clock setting.
 */
#if !defined(GD32_I2S_CLOCK_REQUIRED) || defined(__DOXYGEN__)
#define GD32_I2S_CLOCK_REQUIRED    FALSE
#endif

/**
 * @brief   MCO pin setting.
 */
#if !defined(GD32_MCOSEL) || defined(__DOXYGEN__)
#define GD32_MCOSEL                   GD32_MCOSEL_NOCLOCK
#endif

/**
 * @brief   RTC clock source.
 */
#if !defined(GD32_RTCSEL) || defined(__DOXYGEN__)
#define GD32_RTCSEL                   GD32_RTCSEL_HSEDIV
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
/*#if !defined(STM32F107_MCUCONF)
#error "Using a wrong mcuconf.h file, STM32F107_MCUCONF not defined"
#endif*/

/*
 * HSI related checks.
 */
#if GD32_HSI_ENABLED
#else /* !GD32_HSI_ENABLED */

#if GD32_SW == GD32_SW_HSI
#error "HSI not enabled, required by GD32_SW"
#endif

#if (GD32_SW == GD32_SW_PLL) && (GD32_PLLSRC == GD32_PLLSRC_HSI)
#error "HSI not enabled, required by GD32_SW and GD32_PLLSRC"
#endif

#if (GD32_MCOSEL == GD32_MCOSEL_HSI) ||                                   \
    ((GD32_MCOSEL == GD32_MCOSEL_PLLDIV2) &&                              \
     (GD32_PLLSRC == GD32_PLLSRC_HSI))
#error "HSI not enabled, required by GD32_MCOSEL"
#endif

#endif /* !GD32_HSI_ENABLED */

/*
 * HSE related checks.
 */
#if GD32_HSE_ENABLED

#if GD32_HSECLK == 0
#error "HSE frequency not defined"
#elif (GD32_HSECLK < GD32_HSECLK_MIN) || (GD32_HSECLK > GD32_HSECLK_MAX)
#error "GD32_HSECLK outside acceptable range (GD32_HSECLK_MIN...GD32_HSECLK_MAX)"
#endif

#else /* !GD32_HSE_ENABLED */

#if GD32_SW == GD32_SW_HSE
#error "HSE not enabled, required by GD32_SW"
#endif

#if (GD32_SW == GD32_SW_PLL) && (GD32_PLLSRC == GD32_PLLSRC_PREDIV1)
#error "HSE not enabled, required by GD32_SW and GD32_PLLSRC"
#endif

#if (GD32_MCOSEL == GD32_MCOSEL_HSE) ||                                   \
    (((GD32_MCOSEL == GD32_MCOSEL_PLLDIV2) ||                             \
      (GD32_MCOSEL == GD32_MCOSEL_PLL2) ||                                \
      (GD32_MCOSEL == GD32_MCOSEL_PLL3) ||                                \
      (GD32_MCOSEL == GD32_MCOSEL_PLL3DIV2)) &&                           \
     (GD32_PLLSRC == GD32_PLLSRC_HSE)) ||                                 \
    (GD32_MCOSEL == GD32_MCOSEL_XT1)
#error "HSE not enabled, required by GD32_MCOSEL"
#endif

#if GD32_RTCSEL == GD32_RTCSEL_HSEDIV
#error "HSE not enabled, required by GD32_RTCSEL"
#endif

#endif /* !GD32_HSE_ENABLED */

/*
 * LSI related checks.
 */
#if GD32_LSI_ENABLED
#else /* !GD32_LSI_ENABLED */

#if GD32_RTCSEL == GD32_RTCSEL_LSI
#error "LSI not enabled, required by GD32_RTCSEL"
#endif

#endif /* !GD32_LSI_ENABLED */

/*
 * LSE related checks.
 */
#if GD32_LSE_ENABLED

#if (GD32_LSECLK == 0)
#error "LSE frequency not defined"
#endif

#if (GD32_LSECLK < GD32_LSECLK_MIN) || (GD32_LSECLK > GD32_LSECLK_MAX)
#error "GD32_LSECLK outside acceptable range (GD32_LSECLK_MIN...GD32_LSECLK_MAX)"
#endif

#else /* !GD32_LSE_ENABLED */

#if GD32_RTCSEL == GD32_RTCSEL_LSE
#error "LSE not enabled, required by GD32_RTCSEL"
#endif

#endif /* !GD32_LSE_ENABLED */

/* PLL1 activation conditions.*/
#if GD32_USBFS_CLOCK_REQUIRED ||                                             \
    (GD32_SW == GD32_SW_PLL) ||                                           \
    (GD32_MCOSEL == GD32_MCOSEL_PLLDIV2) ||                               \
    defined(__DOXYGEN__)
/**
 * @brief   PLL1 activation flag.
 */
#define GD32_ACTIVATE_PLL1         TRUE
#else
#define GD32_ACTIVATE_PLL1         FALSE
#endif

/* PLL2 activation conditions.*/
#if ((GD32_PREDIV1SRC == GD32_PREDIV1SRC_PLL2) && GD32_ACTIVATE_PLL1) || \
    (GD32_MCOSEL == GD32_MCOSEL_PLL2) || defined(__DOXYGEN__)
/**
 * @brief   PLL2 activation flag.
 */
#define GD32_ACTIVATE_PLL2         TRUE
#else
#define GD32_ACTIVATE_PLL2         FALSE
#endif

/* PLL3 activation conditions.*/
#if GD32_I2S_CLOCK_REQUIRED ||                                             \
    (GD32_MCOSEL == GD32_MCOSEL_PLL3DIV2) ||                              \
    (GD32_MCOSEL == GD32_MCOSEL_PLL3) ||                                  \
    defined(__DOXYGEN__)
/**
 * @brief   PLL3 activation flag.
 */
#define GD32_ACTIVATE_PLL3         TRUE
#else
#define GD32_ACTIVATE_PLL3         FALSE
#endif

/**
 * @brief   PREDIV1 field.
 */
#if (GD32_PREDIV1_VALUE >= 1) && (GD32_PREDIV1_VALUE <= 16) ||            \
    defined(__DOXYGEN__)
#define GD32_PREDIV1               ((GD32_PREDIV1_VALUE - 1) << 0)
#else
#error "invalid GD32_PREDIV1_VALUE value specified"
#endif

/**
 * @brief   PREDIV2 field.
 */
#if (GD32_PREDIV2_VALUE >= 1) && (GD32_PREDIV2_VALUE <= 16) ||            \
    defined(__DOXYGEN__)
#define GD32_PREDIV2               ((GD32_PREDIV2_VALUE - 1) << 4)
#else
#error "invalid GD32_PREDIV2_VALUE value specified"
#endif

/**
 * @brief   PLLMUL field.
 */
/*#if ((GD32_PLLMUL_VALUE >= 4) && (GD32_PLLMUL_VALUE <= 9)) ||             \
    defined(__DOXYGEN__)
#define GD32_PLLMUL                ((GD32_PLLMUL_VALUE - 2) << 18)
#else
#error "invalid GD32_PLLMUL_VALUE value specified"
#endif*/

/**
 * @brief   PLL2MUL field.
 */
#if ((GD32_PLL2MUL_VALUE >= 8) && (GD32_PLL2MUL_VALUE <= 14)) ||          \
    defined(__DOXYGEN__)
#define GD32_PLL2MUL               ((GD32_PLL2MUL_VALUE - 2) << 8)
#elif (GD32_PLL2MUL_VALUE == 16)
#define GD32_PLL2MUL               (14 << 8)
#elif (GD32_PLL2MUL_VALUE == 20)
#define GD32_PLL2MUL               (15 << 8)
#else
#error "invalid GD32_PLL2MUL_VALUE value specified"
#endif

/**
 * @brief   PLL3MUL field.
 */
#if ((GD32_PLL3MUL_VALUE >= 8) && (GD32_PLL3MUL_VALUE <= 14)) ||          \
    defined(__DOXYGEN__)
#define GD32_PLL3MUL               ((GD32_PLL3MUL_VALUE - 2) << 12)
#elif (GD32_PLL3MUL_VALUE == 16)
#define GD32_PLL3MUL               (14 << 12)
#elif (GD32_PLL3MUL_VALUE == 20)
#define GD32_PLL3MUL               (15 << 12)
#else
#error "invalid GD32_PLL3MUL_VALUE value specified"
#endif

/**
 * @brief   PLL2 input frequency.
 */
#define GD32_PLL2CLKIN             (GD32_HSECLK / GD32_PREDIV2_VALUE)

/* PLL2 input frequency range check.*/
#if (GD32_PLL2CLKIN < GD32_PLL23IN_MIN) ||                                \
    (GD32_PLL2CLKIN > GD32_PLL23IN_MAX)
#error "GD32_PLL2CLKIN outside acceptable range (GD32_PLL23IN_MIN...GD32_PLL23IN_MAX)"
#endif

/**
 * @brief   PLL2 output clock frequency.
 */
#define GD32_PLL2CLKOUT            (GD32_PLL2CLKIN * GD32_PLL2MUL_VALUE)

/**
 * @brief   PLL2 VCO clock frequency.
 */
#define GD32_PLL2VCO               (GD32_PLL2CLKOUT * 2)

/* PLL2 output frequency range check.*/
#if (GD32_PLL2VCO < GD32_PLL23VCO_MIN) ||                                 \
    (GD32_PLL2VCO > GD32_PLL23VCO_MAX)
#error "GD32_PLL2VCO outside acceptable range (GD32_PLL23VCO_MIN...GD32_PLL23VCO_MAX)"
#endif

/**
 * @brief   PLL3 input frequency.
 */
#define GD32_PLL3CLKIN             (GD32_HSECLK / GD32_PREDIV2_VALUE)

/* PLL3 input frequency range check.*/
#if (GD32_PLL3CLKIN < GD32_PLL23IN_MIN) ||                                \
    (GD32_PLL3CLKIN > GD32_PLL23IN_MAX)
#error "GD32_PLL3CLKIN outside acceptable range (GD32_PLL23IN_MIN...GD32_PLL23IN_MAX)"
#endif

/**
 * @brief   PLL3 output clock frequency.
 */
#define GD32_PLL3CLKOUT            (GD32_PLL3CLKIN * GD32_PLL3MUL_VALUE)

/**
 * @brief   PLL3 VCO clock frequency.
 */
#define GD32_PLL3VCO               (GD32_PLL3CLKOUT * 2)

/* PLL3 output frequency range check.*/
#if (GD32_PLL3VCO < GD32_PLL23VCO_MIN) ||                                 \
    (GD32_PLL3VCO > GD32_PLL23VCO_MAX)
#error "GD32_PLL3CLKOUT outside acceptable range (GD32_PLL23VCO_MIN...GD32_PLL23VCO_MAX)"
#endif

/**
 * @brief   PREDIV1 input frequency.
 */
#if (GD32_PREDIV1SRC == GD32_PREDIV1SRC_HSE) || defined(__DOXYGEN__)
#define GD32_PREDIV1CLK            GD32_HSECLK
#elif GD32_PREDIV1SRC == GD32_PREDIV1SRC_PLL2
#define GD32_PREDIV1CLK            GD32_PLL2CLKOUT
#else
#error "invalid GD32_PREDIV1SRC value specified"
#endif

/**
 * @brief   PLL input clock frequency.
 */
#if (GD32_PLLSRC == GD32_PLLSRC_PREDIV1) || defined(__DOXYGEN__)
#define GD32_PLLCLKIN              (GD32_PREDIV1CLK / GD32_PREDIV1_VALUE)
#elif GD32_PLLSRC == GD32_PLLSRC_HSI
#define GD32_PLLCLKIN              (GD32_HSICLK / 2)
#else
#error "invalid GD32_PLLSRC value specified"
#endif

/* PLL input frequency range check.*/
#if (GD32_PLLCLKIN < GD32_PLL1IN_MIN) || (GD32_PLLCLKIN > GD32_PLL1IN_MAX)
#error "GD32_PLLCLKIN outside acceptable range (GD32_PLL1IN_MIN...GD32_PLL1IN_MAX)"
#endif

/**
 * @brief   PLL output clock frequency.
 */
#define GD32_PLLCLKOUT             (GD32_PLLCLKIN * GD32_PLLMUL_VALUE)

/**
 * @brief   PLL VCO clock frequency.
 */
#define GD32_PLLVCO                (GD32_PLLCLKOUT * 2)

/* PLL output frequency range check.*/
#if (GD32_PLLVCO < GD32_PLL1VCO_MIN) || (GD32_PLLVCO > GD32_PLL1VCO_MAX)
#error "GD32_PLLVCO outside acceptable range (GD32_PLL1VCO_MIN...GD32_PLL1VCO_MAX)"
#endif

/**
 * @brief   System clock source.
 */
#if (GD32_SW == GD32_SW_PLL) || defined(__DOXYGEN__)
#define GD32_SYSCLK                GD32_PLLCLKOUT
#elif (GD32_SW == GD32_SW_HSI)
#define GD32_SYSCLK                GD32_HSICLK
#elif (GD32_SW == GD32_SW_HSE)
#define GD32_SYSCLK                GD32_HSECLK
#else
#error "invalid GD32_SW value specified"
#endif

/* Check on the system clock.*/
#if GD32_SYSCLK > GD32_SYSCLK_MAX
#error "GD32_SYSCLK above maximum rated frequency (GD32_SYSCLK_MAX)"
#endif

/**
 * @brief   AHB frequency.
 */
#if (GD32_HPRE == GD32_HPRE_DIV1) || defined(__DOXYGEN__)
#define GD32_HCLK                  (GD32_SYSCLK / 1)
#elif GD32_HPRE == GD32_HPRE_DIV2
#define GD32_HCLK                  (GD32_SYSCLK / 2)
#elif GD32_HPRE == GD32_HPRE_DIV4
#define GD32_HCLK                  (GD32_SYSCLK / 4)
#elif GD32_HPRE == GD32_HPRE_DIV8
#define GD32_HCLK                  (GD32_SYSCLK / 8)
#elif GD32_HPRE == GD32_HPRE_DIV16
#define GD32_HCLK                  (GD32_SYSCLK / 16)
#elif GD32_HPRE == GD32_HPRE_DIV64
#define GD32_HCLK                  (GD32_SYSCLK / 64)
#elif GD32_HPRE == GD32_HPRE_DIV128
#define GD32_HCLK                  (GD32_SYSCLK / 128)
#elif GD32_HPRE == GD32_HPRE_DIV256
#define GD32_HCLK                  (GD32_SYSCLK / 256)
#elif GD32_HPRE == GD32_HPRE_DIV512
#define GD32_HCLK                  (GD32_SYSCLK / 512)
#else
#error "invalid GD32_HPRE value specified"
#endif

/* AHB frequency check.*/
#if GD32_HCLK > GD32_SYSCLK_MAX
#error "GD32_HCLK exceeding maximum frequency (GD32_SYSCLK_MAX)"
#endif

/**
 * @brief   APB1 frequency.
 */
#if (GD32_PPRE1 == GD32_PPRE1_DIV1) || defined(__DOXYGEN__)
#define GD32_PCLK1                 (GD32_HCLK / 1)
#elif GD32_PPRE1 == GD32_PPRE1_DIV2
#define GD32_PCLK1                 (GD32_HCLK / 2)
#elif GD32_PPRE1 == GD32_PPRE1_DIV4
#define GD32_PCLK1                 (GD32_HCLK / 4)
#elif GD32_PPRE1 == GD32_PPRE1_DIV8
#define GD32_PCLK1                 (GD32_HCLK / 8)
#elif GD32_PPRE1 == GD32_PPRE1_DIV16
#define GD32_PCLK1                 (GD32_HCLK / 16)
#else
#error "invalid GD32_PPRE1 value specified"
#endif

/* APB1 frequency check.*/
#if GD32_PCLK1 > GD32_PCLK1_MAX
#error "GD32_PCLK1 exceeding maximum frequency (GD32_PCLK1_MAX)"
#endif

/**
 * @brief   APB2 frequency.
 */
#if (GD32_PPRE2 == GD32_PPRE2_DIV1) || defined(__DOXYGEN__)
#define GD32_PCLK2                 (GD32_HCLK / 1)
#elif GD32_PPRE2 == GD32_PPRE2_DIV2
#define GD32_PCLK2                 (GD32_HCLK / 2)
#elif GD32_PPRE2 == GD32_PPRE2_DIV4
#define GD32_PCLK2                 (GD32_HCLK / 4)
#elif GD32_PPRE2 == GD32_PPRE2_DIV8
#define GD32_PCLK2                 (GD32_HCLK / 8)
#elif GD32_PPRE2 == GD32_PPRE2_DIV16
#define GD32_PCLK2                 (GD32_HCLK / 16)
#else
#error "invalid GD32_PPRE2 value specified"
#endif

/* APB2 frequency check.*/
#if GD32_PCLK2 > GD32_PCLK2_MAX
#error "GD32_PCLK2 exceeding maximum frequency (GD32_PCLK2_MAX)"
#endif

/**
 * @brief   RTC clock.
 */
#if (GD32_RTCSEL == GD32_RTCSEL_LSE) || defined(__DOXYGEN__)
#define GD32_RTCCLK                GD32_LSECLK
#elif GD32_RTCSEL == GD32_RTCSEL_LSI
#define GD32_RTCCLK                GD32_LSICLK
#elif GD32_RTCSEL == GD32_RTCSEL_HSEDIV
#define GD32_RTCCLK                (GD32_HSECLK / 128)
#elif GD32_RTCSEL == GD32_RTCSEL_NOCLOCK
#define GD32_RTCCLK                0
#else
#error "invalid source selected for RTC clock"
#endif

/**
 * @brief   ADC frequency.
 */
#if (GD32_ADCPRE == GD32_ADCPRE_DIV2) || defined(__DOXYGEN__)
#define GD32_ADCCLK                (GD32_PCLK2 / 2)
#elif GD32_ADCPRE == GD32_ADCPRE_DIV4
#define GD32_ADCCLK                (GD32_PCLK2 / 4)
#elif GD32_ADCPRE == GD32_ADCPRE_DIV6
#define GD32_ADCCLK                (GD32_PCLK2 / 6)
#elif GD32_ADCPRE == GD32_ADCPRE_DIV8
#define GD32_ADCCLK                (GD32_PCLK2 / 8)
#else
#error "invalid GD32_ADCPRE value specified"
#endif

/* ADC frequency check.*/
#if GD32_ADCCLK > GD32_ADCCLK_MAX
#error "GD32_ADCCLK exceeding maximum frequency (GD32_ADCCLK_MAX)"
#endif

/**
 * @brief   OTG frequency.
 */
#if (GD32_USBFSPRE == GD32_USBFSPRE_DIV3) || defined(__DOXYGEN__)
#define GD32_USBFSCLK              (GD32_PLLVCO / 3)
#elif (GD32_USBFSPRE == GD32_USBFSPRE_DIV2)
#define GD32_USBFSCLK              (GD32_PLLVCO / 2)
#else
#error "invalid GD32_USBFSPRE value specified"
#endif

/**
 * @brief   Timers 2, 3, 4, 5, 6, 7 clock.
 */
#if (GD32_PPRE1 == GD32_PPRE1_DIV1) || defined(__DOXYGEN__)
#define GD32_TIMCLK1               (GD32_PCLK1 * 1)
#else
#define GD32_TIMCLK1               (GD32_PCLK1 * 2)
#endif

/**
 * @brief   Timers 1, 8 clock.
 */
#if (GD32_PPRE2 == GD32_PPRE2_DIV1) || defined(__DOXYGEN__)
#define GD32_TIMCLK2               (GD32_PCLK2 * 1)
#else
#define GD32_TIMCLK2               (GD32_PCLK2 * 2)
#endif

/**
 * @brief   Flash settings.
 */
#if (GD32_HCLK <= 24000000) || defined(__DOXYGEN__)
#define GD32_FLASHBITS             0x00000010
#elif GD32_HCLK <= 48000000
#define GD32_FLASHBITS             0x00000011
#else
#define GD32_FLASHBITS             0x00000012
#endif

#endif /* _HAL_LLD_F105_F107_H_ */

/** @} */

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
 * @defgroup GD32VF103_HAL GD32VF103 HAL Support
 * @details HAL support for GD32 Performance Line LD, MD and HD sub-families.
 *
 * @ingroup HAL
 */

/**
 * @file    GD32F1xx/hal_lld_f103.h
 * @brief   GD32VF103 Performance Line HAL subsystem low level driver header.
 *
 * @addtogroup GD32VF103_HAL
 * @{
 */

#ifndef _HAL_LLD_F103_H_
#define _HAL_LLD_F103_H_

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
#define GD32_SYSCLK_MAX        120000000

/**
 * @brief   Maximum HSE clock frequency.
 */
#define GD32_HSECLK_MAX        25000000

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
#define GD32_PLLIN_MAX         25000000

/**
 * @brief   Minimum PLLs input clock frequency.
 */
#define GD32_PLLIN_MIN         1000000

/**
 * @brief   Maximum PLL output clock frequency.
 */
#define GD32_PLLOUT_MAX        120000000

/**
 * @brief   Minimum PLL output clock frequency.
 */
#define GD32_PLLOUT_MIN        16000000

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
/** @} */

/**
 * @name    RCU_CFG0 register bits definitions
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
#define GD32_PLLSRC_HSE        (1 << 16)   /**< PLL clock source is HSE.   */

#define GD32_PLLXTPRE_DIV1     (0 << 17)   /**< HSE divided by 1.          */
#define GD32_PLLXTPRE_DIV2     (1 << 17)   /**< HSE divided by 2.          */

#define GD32_USBPRE_DIV1P5     (0 << 22)   /**< PLLOUT divided by 1.5.     */
#define GD32_USBPRE_DIV1       (1 << 22)   /**< PLLOUT divided by 1.       */
#define GD32_USBPRE_DIV2P5     (2 << 22)   /**< PLLOUT divided by 2.5.     */
#define GD32_USBPRE_DIV2       (3 << 22)   /**< PLLOUT divided by 2.       */

#define GD32_MCOSEL_NOCLOCK    (0 << 24)   /**< No clock on MCO pin.       */
#define GD32_MCOSEL_SYSCLK     (4 << 24)   /**< SYSCLK on MCO pin.         */
#define GD32_MCOSEL_HSI        (5 << 24)   /**< HSI clock on MCO pin.      */
#define GD32_MCOSEL_HSE        (6 << 24)   /**< HSE clock on MCO pin.      */
#define GD32_MCOSEL_PLLDIV2    (7 << 24)   /**< PLL/2 clock on MCO pin.    */
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

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Main clock source selection.
 * @note    If the selected clock source is not the PLL then the PLL is not
 *          initialized and started.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(GD32_SW) || defined(__DOXYGEN__)
#define GD32_SW                    GD32_SW_PLL
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(GD32_PLLSRC) || defined(__DOXYGEN__)
#define GD32_PLLSRC                GD32_PLLSRC_HSE
#endif

/**
 * @brief   Crystal PLL pre-divider.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(GD32_PLLXTPRE) || defined(__DOXYGEN__)
#define GD32_PLLXTPRE              GD32_PLLXTPRE_DIV1
#endif

/**
 * @brief   PLL multiplier value.
 * @note    The allowed range is 2...16.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(GD32_PLLMUL_VALUE) || defined(__DOXYGEN__)
#define GD32_PLLMUL_VALUE          9
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 8MHz crystal using the PLL.
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
#if !defined(GD32_USB_CLOCK_REQUIRED) || defined(__DOXYGEN__)
#define GD32_USB_CLOCK_REQUIRED    TRUE
#endif

/**
 * @brief   USB prescaler initialization.
 */
#if !defined(GD32_USBPRE) || defined(__DOXYGEN__)
#define GD32_USBPRE                GD32_USBPRE_DIV1P5
#endif

/**
 * @brief   MCO pin setting.
 */
#if !defined(GD32_MCOSEL) || defined(__DOXYGEN__)
#define GD32_MCOSEL                GD32_MCOSEL_NOCLOCK
#endif

/**
 * @brief   RTC clock source.
 */
#if !defined(GD32_RTCSEL) || defined(__DOXYGEN__)
#define GD32_RTCSEL                GD32_RTCSEL_LSI
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(GD32VF103_MCUCONF)
#error "Using a wrong mcuconf.h file, GD32VF103_MCUCONF not defined"
#endif

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

#if (GD32_SW == GD32_SW_PLL) && (GD32_PLLSRC == GD32_PLLSRC_HSE)
#error "HSE not enabled, required by GD32_SW and GD32_PLLSRC"
#endif

#if (GD32_MCOSEL == GD32_MCOSEL_HSE) ||                                   \
    ((GD32_MCOSEL == GD32_MCOSEL_PLLDIV2) &&                              \
     (GD32_PLLSRC == GD32_PLLSRC_HSE))
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

/* PLL activation conditions.*/
#if GD32_USB_CLOCK_REQUIRED ||                                             \
    (GD32_SW == GD32_SW_PLL) ||                                           \
    (GD32_MCOSEL == GD32_MCOSEL_PLLDIV2) ||                               \
    defined(__DOXYGEN__)
/**
 * @brief   PLL activation flag.
 */
#define GD32_ACTIVATE_PLL          TRUE
#else
#define GD32_ACTIVATE_PLL          FALSE
#endif

/* HSE prescaler setting check.*/
#if (GD32_PLLXTPRE != GD32_PLLXTPRE_DIV1) &&                              \
    (GD32_PLLXTPRE != GD32_PLLXTPRE_DIV2)
#error "invalid GD32_PLLXTPRE value specified"
#endif

/**
 * @brief   PLLMUL field.
 */
/*#if GD32_PLLMUL_VALUE == 6.5
    #define GD32_PLLMUL 13 << 18*/
#if ((GD32_PLLMUL_VALUE >= 2) && (GD32_PLLMUL_VALUE <= 16)) ||            \
    defined(__DOXYGEN__)
    #define GD32_PLLMUL                ((GD32_PLLMUL_VALUE - 2) << 18)
#elif ((GD32_PLLMUL_VALUE >= 17) && (GD32_PLLMUL_VALUE <= 32))
    #define GD32_PLLMUL                ((1 << 29) | ((GD32_PLLMUL_VALUE - 17) << 18))
#else
#error "invalid GD32_PLLMUL_VALUE value specified"
#endif

//#pragma message(STRING(GD32_PLLMUL))

/**
 * @brief   PLL input clock frequency.
 */
#if (GD32_PLLSRC == GD32_PLLSRC_HSE) || defined(__DOXYGEN__)
#if GD32_PLLXTPRE == GD32_PLLXTPRE_DIV1
#define GD32_PLLCLKIN              (GD32_HSECLK / 1)
#else
#define GD32_PLLCLKIN              (GD32_HSECLK / 2)
#endif
#elif GD32_PLLSRC == GD32_PLLSRC_HSI
#define GD32_PLLCLKIN              (GD32_HSICLK / 2)
#else
#error "invalid GD32_PLLSRC value specified"
#endif

/* PLL input frequency range check.*/
#if (GD32_PLLCLKIN < GD32_PLLIN_MIN) || (GD32_PLLCLKIN > GD32_PLLIN_MAX)
#error "GD32_PLLCLKIN outside acceptable range (GD32_PLLIN_MIN...GD32_PLLIN_MAX)"
#endif

/**
 * @brief   PLL output clock frequency.
 */
#define GD32_PLLCLKOUT             (GD32_PLLCLKIN * GD32_PLLMUL_VALUE)

/* PLL output frequency range check.*/
#if (GD32_PLLCLKOUT < GD32_PLLOUT_MIN) || (GD32_PLLCLKOUT > GD32_PLLOUT_MAX)
#error "GD32_PLLCLKOUT outside acceptable range (GD32_PLLOUT_MIN...GD32_PLLOUT_MAX)"
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
 * @brief   USB frequency.
 */
#if (GD32_USBPRE == GD32_USBPRE_DIV1P5) || defined(__DOXYGEN__)
#define GD32_OTGFSCLK                ((GD32_PLLCLKOUT * 2) / 3)
#elif (GD32_USBPRE == GD32_USBPRE_DIV1)
#define GD32_OTGFSCLK                GD32_PLLCLKOUT
#elif (GD32_USBPRE == GD32_USBPRE_DIV2)
#define GD32_OTGFSCLK                GD32_PLLCLKOUT / 2
#elif (GD32_USBPRE == GD32_USBPRE_DIV2P5)
#define GD32_OTGFSCLK                ((GD32_PLLCLKOUT * 2) / 5)
#else
#error "invalid GD32_USBPRE value specified"
#endif

/**
 * @brief   Timers 2, 3, 4, 5, 6, 7, 12, 13, 14 clock.
 */
#if (GD32_PPRE1 == GD32_PPRE1_DIV1) || defined(__DOXYGEN__)
#define GD32_TIMCLK1               (GD32_PCLK1 * 1)
#else
#define GD32_TIMCLK1               (GD32_PCLK1 * 2)
#endif

/**
 * @brief   Timers 1, 8, 9, 10, 11 clock.
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

#endif /* _HAL_LLD_F103_H_ */

/** @} */

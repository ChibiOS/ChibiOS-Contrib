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
 * @file    AT32F415/hal_lld.h
 * @brief   AT32F415 HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - AT32_LEXTCLK.
 *          - AT32_LEXT_BYPASS (optionally).
 *          - AT32_HEXTCLK.
 *          - AT32_HEXT_BYPASS (optionally).
 *          .
 *          One of the following macros must also be defined:
 *          - AT32F415KB for K Value Medium Density devices.
 *          - AT32F415CB for C Value Medium Density devices.
 *          - AT32F415RB for R Value Medium Density devices.
 *          - AT32F415KC for K Value High Density devices.
 *          - AT32F415CC for C Value High Density devices.
 *          - AT32F415RC for R Value High Density devices.
 *          .
 *
 * @addtogroup HAL
 * @{
 */

#ifndef _HAL_LLD_H_
#define _HAL_LLD_H_

#include "at32_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Requires use of SPIv2 driver model.
 */
#define HAL_LLD_SELECT_SPI_V2    TRUE

/**
 * @name    Platform identification
 * @{
 */
#if defined(__DOXYGEN__)
#define PLATFORM_NAME            "AT32F415"

#elif defined(AT32F415K_MD)
#define PLATFORM_NAME            "AT32F415K Value Line Medium Density"

#elif defined(AT32F415K_HD)
#define PLATFORM_NAME            "AT32F415K Value Line High Density"

#elif defined(AT32F415C_MD)
#define PLATFORM_NAME            "AT32F415C Value Line Medium Density"

#elif defined(AT32F415C_HD)
#define PLATFORM_NAME            "AT32F415C Value Line High Density"

#elif defined(AT32F415R_MD)
#define PLATFORM_NAME            "AT32F415R Value Line Medium Density"

#elif defined(AT32F415R_HD)
#define PLATFORM_NAME            "AT32F415R Value Line High Density"

#else
#error "unsupported or unrecognized AT32F415 member"
#endif

/**
 * @brief   Sub-family identifier.
 */
#if !defined(AT32F415) || defined(__DOXYGEN__)
#define AT32F415
#endif
/** @} */

/**
 * @name    Absolute Maximum Ratings
 * @{
 */

/**
 * @brief   Maximum system clock frequency.
 */
#define AT32_SYSCLK_MAX          150000000

/**
 * @brief   Maximum HEXT clock frequency.
 */
#define AT32_HEXTCLK_MAX         25000000

/**
 * @brief   Minimum HEXT clock frequency.
 */
#define AT32_HEXTCLK_MIN         4000000

/**
 * @brief   Maximum LEXT clock frequency.
 */
#define AT32_LEXTCLK_MAX         1000000

/**
 * @brief   Minimum LEXT clock frequency.
 */
#define AT32_LEXTCLK_MIN         32768

/**
 * @brief   Maximum PLLs input clock frequency.
 */
#define AT32_PLLIN_MAX           16000000

/**
 * @brief   Minimum PLLs input clock frequency.
 */
#define AT32_PLLIN_MIN           2000000

/**
 * @brief   Maximum PLL output clock frequency.
 */
#define AT32_PLLOUT_MAX          150000000

/**
 * @brief   Minimum PLL output clock frequency.
 */
#define AT32_PLLOUT_MIN          4000000

/**
 * @brief   Maximum PLL FR clock frequency.
 */
#define AT32_PLLFR_MAX           1000000000

/**
 * @brief   Minimum PLL FR clock frequency.
 */
#define AT32_PLLFR_MIN           500000000

/**
 * @brief   Maximum APB1 clock frequency.
 */
#define AT32_PCLK1_MAX           75000000

/**
 * @brief   Maximum APB2 clock frequency.
 */
#define AT32_PCLK2_MAX           75000000

/**
 * @brief   Maximum ADC clock frequency.
 */
#define AT32_ADCCLK_MAX          28000000
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define AT32_HICKCLK             48000000                /**< High speed internal clock.        */
#define AT32_LICKCLK             40000                   /**< Low speed internal clock.         */
/** @} */

/**
 * @name    PWC_CTRL register bits definitions
 * @{
 */
#define AT32_PVMSEL_MASK         (7 << 5)                /**< PVMSEL bits mask.                 */
#define AT32_PVMSEL_LEV1         (1 << 5)                /**< PVM level 1.                      */
#define AT32_PVMSEL_LEV2         (2 << 5)                /**< PVM level 2.                      */
#define AT32_PVMSEL_LEV3         (3 << 5)                /**< PVM level 3.                      */
#define AT32_PVMSEL_LEV4         (4 << 5)                /**< PVM level 4.                      */
#define AT32_PVMSEL_LEV5         (5 << 5)                /**< PVM level 5.                      */
#define AT32_PVMSEL_LEV6         (6 << 5)                /**< PVM level 6.                      */
#define AT32_PVMSEL_LEV7         (7 << 5)                /**< PVM level 7.                      */
/** @} */

/**
 * @name    CRM_CFG register bits definitions
 * @{
 */
#define AT32_SCLKSEL_HICK        (0 << 0)                /**< SCLK source is HICK.              */
#define AT32_SCLKSEL_HEXT        (1 << 0)                /**< SCLK source is HEXT.              */
#define AT32_SCLKSEL_PLL         (2 << 0)                /**< SCLK source is PLL.               */

#define AT32_SCLKSTS_HICK        (0 << 2)                /**< SCLK use HICK.                    */
#define AT32_SCLKSTS_HEXT        (1 << 2)                /**< SCLK use HEXT.                    */
#define AT32_SCLKSTS_PLL         (2 << 2)                /**< SCLK use PLL.                     */

#define AT32_AHBDIV_DIV1         (0 << 4)                /**< SCLK divided by 1.                */
#define AT32_AHBDIV_DIV2         (8 << 4)                /**< SCLK divided by 2.                */
#define AT32_AHBDIV_DIV4         (9 << 4)                /**< SCLK divided by 4.                */
#define AT32_AHBDIV_DIV8         (10 << 4)               /**< SCLK divided by 8.                */
#define AT32_AHBDIV_DIV16        (11 << 4)               /**< SCLK divided by 16.               */
#define AT32_AHBDIV_DIV64        (12 << 4)               /**< SCLK divided by 64.               */
#define AT32_AHBDIV_DIV128       (13 << 4)               /**< SCLK divided by 128.              */
#define AT32_AHBDIV_DIV256       (14 << 4)               /**< SCLK divided by 256.              */
#define AT32_AHBDIV_DIV512       (15 << 4)               /**< SCLK divided by 512.              */

#define AT32_APB1DIV_DIV1        (0 << 8)                /**< HCLK divided by 1.                */
#define AT32_APB1DIV_DIV2        (4 << 8)                /**< HCLK divided by 2.                */
#define AT32_APB1DIV_DIV4        (5 << 8)                /**< HCLK divided by 4.                */
#define AT32_APB1DIV_DIV8        (6 << 8)                /**< HCLK divided by 8.                */
#define AT32_APB1DIV_DIV16       (7 << 8)                /**< HCLK divided by 16.               */

#define AT32_APB2DIV_DIV1        (0 << 11)               /**< HCLK divided by 1.                */
#define AT32_APB2DIV_DIV2        (4 << 11)               /**< HCLK divided by 2.                */
#define AT32_APB2DIV_DIV4        (5 << 11)               /**< HCLK divided by 4.                */
#define AT32_APB2DIV_DIV8        (6 << 11)               /**< HCLK divided by 8.                */
#define AT32_APB2DIV_DIV16       (7 << 11)               /**< HCLK divided by 16.               */

#define AT32_ADCDIV_DIV2         (0 << 14)               /**< APB2DIV divided by 2.             */
#define AT32_ADCDIV_DIV4         (1 << 14)               /**< APB2DIV divided by 4.             */
#define AT32_ADCDIV_DIV6         (2 << 14)               /**< APB2DIV divided by 6.             */
#define AT32_ADCDIV_DIV8         (3 << 14)               /**< APB2DIV divided by 8.             */
#define AT32_ADCDIV_DIV12        ((1 << 28) | (1 << 14)) /**< APB2DIV divided by 12.            */
#define AT32_ADCDIV_DIV16        ((1 << 28) | (3 << 14)) /**< APB2DIV divided by 16.            */

#define AT32_PLLRCS_HICK         (0 << 16)               /**< PLL clock source is HICK.         */
#define AT32_PLLRCS_HEXT         (1 << 16)               /**< PLL clock source is HEXT.         */

#define AT32_PLLHEXTDIV_DIV1     (0 << 17)               /**< HEXT divided by 1.                */
#define AT32_PLLHEXTDIV_DIV2     (1 << 17)               /**< HEXT divided by 2.                */

#define AT32_USBDIV_DIV1P5       (0 << 22)               /**< PLLOUT divided by 1.5.            */
#define AT32_USBDIV_DIV1         (1 << 22)               /**< PLLOUT divided by 1.              */
#define AT32_USBDIV_DIV2P5       (2 << 22)               /**< PLLOUT divided by 2.5.            */
#define AT32_USBDIV_DIV2         (3 << 22)               /**< PLLOUT divided by 2.              */
#define AT32_USBDIV_DIV3P5       (1 << 27)               /**< PLLOUT divided by 3.5.            */
#define AT32_USBDIV_DIV3         ((1 << 27) | (1 << 22)) /**< PLLOUT divided by 3.              */
#define AT32_USBDIV_DIV4         ((1 << 27) | (2 << 22)) /**< PLLOUT divided by 4.              */

#define AT32_CLKOUT_SEL_CFG_MSK  (7 << 24)               /**< CLKOUT_SEL pin on CRM_CFG mask.   */
#define AT32_CLKOUT_SEL_NOCLOCK  (0 << 24)               /**< No clock on CLKOUT_SEL pin.       */
#define AT32_CLKOUT_SEL_LICK     (2 << 24)               /**< LICK clockon CLKOUT_SEL pin.      */
#define AT32_CLKOUT_SEL_LEXT     (3 << 24)               /**< LEXT clock on CLKOUT_SEL pin.     */
#define AT32_CLKOUT_SEL_SCLK     (4 << 24)               /**< SCLK on CLKOUT_SEL pin.           */
#define AT32_CLKOUT_SEL_HICK     (5 << 24)               /**< HICK clock on CLKOUT_SEL pin.     */
#define AT32_CLKOUT_SEL_HEXT     (6 << 24)               /**< HEXT clock on CLKOUT_SEL pin.     */
#define AT32_CLKOUT_SEL_PLLDIV2  (7 << 24)               /**< PLL/2 clock on CLKOUT_SEL pin.    */
/** @} */

/**
 * @name    CRM_BPDC register bits definitions
 * @{
 */
#define AT32_ERTCSEL_MASK        (3 << 8)                /**< ERTC clock source mask.           */
#define AT32_ERTCSEL_NOCLOCK     (0 << 8)                /**< No clock.                         */
#define AT32_ERTCSEL_LEXT        (1 << 8)                /**< LEXT used as ERTC clock.          */
#define AT32_ERTCSEL_LICK        (2 << 8)                /**< LICK used as ERTC clock.          */
#define AT32_ERTCSEL_HEXTDIV     (3 << 8)                /**< HEXT divided by 128 used as
                                                              ERTC clock.                       */
/** @} */

/**
 * @name    CRM_PLL register bits definitions
 * @{
 */
#define AT32_PLL_FR_MASK         (7 << 0)                /**< PLL FR mask.                      */
#define AT32_PLL_FR_DIV1         (0 << 0)                /**< PLL divided by 1.                 */
#define AT32_PLL_FR_DIV2         (1 << 0)                /**< PLL divided by 2.                 */
#define AT32_PLL_FR_DIV4         (2 << 0)                /**< PLL divided by 4.                 */
#define AT32_PLL_FR_DIV8         (3 << 0)                /**< PLL divided by 8.                 */
#define AT32_PLL_FR_DIV16        (4 << 0)                /**< PLL divided by 16.                */
#define AT32_PLL_FR_DIV32        (5 << 0)                /**< PLL divided by 32.                */

#define AT32_PLLCFGEN_SOLID      (0 << 31)               /**< PLL use solid config.             */
#define AT32_PLLCFGEN_FLEX       (1 << 31)               /**< PLL use flexible config.          */

/**
 * @name    CRM_MISC1 Additional Register
 * @{
 */
#define AT32_CLKOUT_SEL_MISC_MSK (1 << 27)               /**< CLKOUT_SEL pin on CRM_MISC1 mask. */
#define AT32_CLKOUT_SEL_PLLDIV4  ((1 << 16) | (AT32_CLKOUT_SEL_SCLK))
                                                         /**< PLL/4 clock on CLKOUT_SEL pin.    */
#define AT32_CLKOUT_SEL_USB      ((1 << 16) | (AT32_CLKOUT_SEL_HICK))
                                                         /**< USB clock on CLKOUT_SEL pin.      */
#define AT32_CLKOUT_SEL_ADC      ((1 << 16) | (AT32_CLKOUT_SEL_HEXT))
                                                         /**< ADC clock on CLKOUT_SEL pin.      */
/** @} */

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Disables the PWC/CRM initialization in the HAL.
 */
#if !defined(AT32_NO_INIT) || defined(__DOXYGEN__)
#define AT32_NO_INIT                FALSE
#endif

/**
 * @brief   Enables or disables the power voltage monitoring.
 */
#if !defined(AT32_PVM_ENABLE) || defined(__DOXYGEN__)
#define AT32_PVM_ENABLE             FALSE
#endif

/**
 * @brief   Sets voltage level for power voltage monitoring.
 */
#if !defined(AT32_PVMSEL) || defined(__DOXYGEN__)
#define AT32_PVMSEL                 AT32_PVMSEL_LEV1
#endif

/**
 * @brief   Enables or disables the HICK clock source.
 */
#if !defined(AT32_HICK_ENABLED) || defined(__DOXYGEN__)
#define AT32_HICK_ENABLED           TRUE
#endif

/**
 * @brief   Enables or disables the LICK clock source.
 */
#if !defined(AT32_LICK_ENABLED) || defined(__DOXYGEN__)
#define AT32_LICK_ENABLED           FALSE
#endif

/**
 * @brief   Enables or disables the HEXT clock source.
 */
#if !defined(AT32_HEXT_ENABLED) || defined(__DOXYGEN__)
#define AT32_HEXT_ENABLED           TRUE
#endif

/**
 * @brief   Enables or disables the LEXT clock source.
 */
#if !defined(AT32_LEXT_ENABLED) || defined(__DOXYGEN__)
#define AT32_LEXT_ENABLED           FALSE
#endif

/**
 * @brief   Main clock source selection.
 * @note    If the selected clock source is not the PLL then the PLL is not
 *          initialized and started.
 * @note    The default value is calculated for a 144MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_SCLKSEL) || defined(__DOXYGEN__)
#define AT32_SCLKSEL                AT32_SCLKSEL_PLL
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 144MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_PLLRCS) || defined(__DOXYGEN__)
#define AT32_PLLRCS                 AT32_PLLRCS_HEXT
#endif

/**
 * @brief   Crystal PLL pre-divider.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 144MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_PLLHEXTDIV) || defined(__DOXYGEN__)
#define AT32_PLLHEXTDIV             AT32_PLLHEXTDIV_DIV1
#endif

/**
 * @brief   PLL multiplier value.
 * @note    The allowed range is 2...64.
 * @note    The default value is calculated for a 144MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_PLLMULT_VALUE) || defined(__DOXYGEN__)
#define AT32_PLLMULT_VALUE          18
#endif

/**
 * @brief   PLL config method.
 */
#if !defined(AT32_PLLCFGEN) || defined(__DOXYGEN__)
#define AT32_PLLCFGEN               AT32_PLLCFGEN_SOLID
#endif

/**
 * @brief   PLL FR divider value.
 * @note    The allowed values are 1, 2, 4, 8, 16, 32.
 * @note    The default value is calculated for a 144MHz system clock from
 *          an external 8MHz HEXT clock.
 */
#if !defined(AT32_PLL_FR_VALUE) || defined(__DOXYGEN__)
#define AT32_PLL_FR_VALUE           4
#endif

/**
 * @brief   PLL MS divider value.
 * @note    The allowed values are 1..15.
 * @note    The default value is calculated for a 144MHz system clock from
 *          an external 8MHz HEXT clock.
 */
#if !defined(AT32_PLL_MS_VALUE) || defined(__DOXYGEN__)
#define AT32_PLL_MS_VALUE           1
#endif

/**
 * @brief   PLL NS multiplier value.
 * @note    The allowed values are 31..500.
 * @note    The default value is calculated for a 144MHz system clock from
 *          an external 8MHz HEXT clock.
 */
#if !defined(AT32_PLL_NS_VALUE) || defined(__DOXYGEN__)
#define AT32_PLL_NS_VALUE           72
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 144MHz system clock from
 *          a 8MHz crystal using the PLL.
 */
#if !defined(AT32_AHBDIV) || defined(__DOXYGEN__)
#define AT32_AHBDIV                 AT32_AHBDIV_DIV1
#endif

/**
 * @brief   APB1 prescaler value.
 */
#if !defined(AT32_APB1DIV) || defined(__DOXYGEN__)
#define AT32_APB1DIV                AT32_APB1DIV_DIV2
#endif

/**
 * @brief   APB2 prescaler value.
 */
#if !defined(AT32_APB2DIV) || defined(__DOXYGEN__)
#define AT32_APB2DIV                AT32_APB2DIV_DIV2
#endif

/**
 * @brief   ADC prescaler value.
 */
#if !defined(AT32_ADCDIV) || defined(__DOXYGEN__)
#define AT32_ADCDIV                 AT32_ADCDIV_DIV4
#endif

/**
 * @brief   USB clock setting.
 */
#if !defined(AT32_USB_CLOCK_REQUIRED) || defined(__DOXYGEN__)
#define AT32_USB_CLOCK_REQUIRED     TRUE
#endif

/**
 * @brief   USB prescaler initialization.
 */
#if !defined(AT32_USBDIV) || defined(__DOXYGEN__)
#define AT32_USBDIV                 AT32_USBDIV_DIV3
#endif

/**
 * @brief   CLKOUT_SEL pin setting.
 */
#if !defined(AT32_CLKOUT_SEL) || defined(__DOXYGEN__)
#define AT32_CLKOUT_SEL             AT32_CLKOUT_SEL_NOCLOCK
#endif

/**
 * @brief   ERTC clock source.
 */
#if !defined(AT32_ERTCSEL) || defined(__DOXYGEN__)
#define AT32_ERTCSEL                AT32_ERTCSEL_LICK
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(AT32F415_MCUCONF)
#error "Using a wrong mcuconf.h file, AT32F415_MCUCONF not defined"
#endif

/*
 * HICK related checks.
 */
#if AT32_HICK_ENABLED
#else /* !AT32_HICK_ENABLED */

#if AT32_SCLKSEL == AT32_SCLKSEL_HICK
#error "HICK not enabled, required by AT32_SCLKSEL"
#endif

#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) && (AT32_PLLRCS == AT32_PLLRCS_HICK)
#error "HICK not enabled, required by AT32_SCLKSEL and AT32_PLLRCS"
#endif

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_HICK) ||                            \
    (((AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) ||                       \
      (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV4)) &&                      \
      (AT32_PLLRCS == AT32_PLLRCS_HICK))
#error "HICK not enabled, required by AT32_CLKOUT_SEL"
#endif

#endif /* !AT32_HICK_ENABLED */

/*
 * HEXT related checks.
 */
#if AT32_HEXT_ENABLED

#if AT32_HEXTCLK == 0
#error "HEXT frequency not defined"
#elif (AT32_HEXTCLK < AT32_HEXTCLK_MIN) || (AT32_HEXTCLK > AT32_HEXTCLK_MAX)
#error "AT32_HEXTCLK outside acceptable range (AT32_HEXTCLK_MIN...AT32_HEXTCLK_MAX)"
#endif

#else /* !AT32_HEXT_ENABLED */

#if AT32_SCLKSEL == AT32_SCLKSEL_HEXT
#error "HEXT not enabled, required by AT32_SCLKSEL"
#endif

#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) && (AT32_PLLRCS == AT32_PLLRCS_HEXT)
#error "HEXT not enabled, required by AT32_SCLKSEL and AT32_PLLRCS"
#endif

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_HEXT) ||                            \
    (((AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) ||                       \
      (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV4)) &&                      \
      (AT32_PLLRCS == AT32_PLLRCS_HEXT))
#error "HEXT not enabled, required by AT32_CLKOUT_SEL"
#endif

#if (AT32_ERTCSEL == AT32_ERTCSEL_HEXTDIV)
#error "HEXT not enabled, required by AT32_ERTCSEL"
#endif
#endif /* !AT32_HEXT_ENABLED */

/*
 * LICK related checks.
 */
#if AT32_LICK_ENABLED
#else /* !AT32_LICK_ENABLED */

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_LICK) 
#error "LICK not enabled, required by AT32_CLKOUT_SEL"
#endif

#if HAL_USE_RTC && (AT32_ERTCSEL == AT32_ERTCSEL_LICK)
#error "LICK not enabled, required by AT32_ERTCSEL"
#endif
#endif /* !AT32_LICK_ENABLED */

/*
 * LEXT related checks.
 */
#if AT32_LEXT_ENABLED

#if (AT32_LEXTCLK == 0)
#error "LEXT frequency not defined"
#endif

#if (AT32_LEXTCLK < AT32_LEXTCLK_MIN) || (AT32_LEXTCLK > AT32_LEXTCLK_MAX)
#error "AT32_LEXTCLK outside acceptable range (AT32_LEXTCLK_MIN...AT32_LEXTCLK_MAX)"
#endif

#else /* !AT32_LEXT_ENABLED */

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_LEXT)
#error "LEXT not enabled, required by AT32_CLKOUT_SEL"
#endif

#if AT32_ERTCSEL == AT32_ERTCSEL_LEXT
#error "LEXT not enabled, required by AT32_ERTCSEL"
#endif

#endif /* !AT32_LEXT_ENABLED */

/* PLL activation conditions.*/
#if AT32_USB_CLOCK_REQUIRED ||                                              \
    (AT32_SCLKSEL == AT32_SCLKSEL_PLL) ||                                   \
    (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) ||                         \
    (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV4) ||                         \
    defined(__DOXYGEN__)

/**
 * @brief   PLL activation flag.
 */
#define AT32_ACTIVATE_PLL           TRUE
#else
#define AT32_ACTIVATE_PLL           FALSE
#endif

/* HEXT prescaler setting check.*/
#if (AT32_PLLHEXTDIV != AT32_PLLHEXTDIV_DIV1) &&                            \
    (AT32_PLLHEXTDIV != AT32_PLLHEXTDIV_DIV2)
#error "invalid AT32_PLLHEXTDIV value specified"
#endif

/**
 * @brief   PLLMULT field.
 */
#if ((AT32_PLLMULT_VALUE >= 2) && (AT32_PLLMULT_VALUE <= 16)) ||            \
    defined(__DOXYGEN__)
#define AT32_PLLMULT                ((AT32_PLLMULT_VALUE - 2) << 18)
#elif ((AT32_PLLMULT_VALUE >= 17) && (AT32_PLLMULT_VALUE <= 32))
#define AT32_PLLMULT                ((1 << 29) | ((AT32_PLLMULT_VALUE - 17) << 18))
#elif ((AT32_PLLMULT_VALUE >= 33) && (AT32_PLLMULT_VALUE <= 48))
#define AT32_PLLMULT                ((1 << 30) | ((AT32_PLLMULT_VALUE - 33) << 18))
#elif ((AT32_PLLMULT_VALUE >= 49) && (AT32_PLLMULT_VALUE <= 64))
#define AT32_PLLMULT                ((3 << 29) | ((AT32_PLLMULT_VALUE - 49) << 18))
#else
#error "invalid AT32_PLLMULT_VALUE value specified"
#endif

/**
 * @brief   PLL input clock frequency.
 */
#if (AT32_PLLRCS == AT32_PLLRCS_HEXT) || defined(__DOXYGEN__)
#if AT32_PLLHEXTDIV == AT32_PLLHEXTDIV_DIV1 || defined(__DOXYGEN__)
#define AT32_PLLRCSCLK              (AT32_HEXTCLK / 1)
#else
#define AT32_PLLRCSCLK              (AT32_HEXTCLK / 2)
#endif
#elif AT32_PLLRCS == AT32_PLLRCS_HICK
#define AT32_PLLRCSCLK              (AT32_HICKCLK / 12)
#else
#error "invalid AT32_PLLRCS value specified"
#endif

/**
 * @brief   AT32_PLL_NS field.
 */
#if ((AT32_PLL_NS_VALUE >= 31) && (AT32_PLL_NS_VALUE <= 500)) ||              \
    defined(__DOXYGEN__)
#define AT32_PLL_NS                (AT32_PLL_NS_VALUE << 8)
#else
#error "invalid AT32_PLL_NS_VALUE value specified"
#endif

/**
 * @brief   AT32_PLL_MS field.
 */
#if ((AT32_PLL_MS_VALUE >= 1) && (AT32_PLL_MS_VALUE <= 15)) ||                \
    defined(__DOXYGEN__)
#define AT32_PLL_MS                (AT32_PLL_MS_VALUE << 4)
#else
#error "invalid AT32_PLL_MS_VALUE value specified"
#endif

/**
 * @brief   AT32_PLL_FR field.
 */
#if (AT32_PLL_FR_VALUE == 1) || defined(__DOXYGEN__)
#define AT32_PLL_FR                AT32_PLL_FR_DIV1
#elif AT32_PLL_FR_VALUE == 2
#define AT32_PLL_FR                AT32_PLL_FR_DIV2
#elif AT32_PLL_FR_VALUE == 4
#define AT32_PLL_FR                AT32_PLL_FR_DIV4
#elif AT32_PLL_FR_VALUE == 8
#define AT32_PLL_FR                AT32_PLL_FR_DIV8
#elif AT32_PLL_FR_VALUE == 16
#define AT32_PLL_FR                AT32_PLL_FR_DIV16
#elif AT32_PLL_FR_VALUE == 32
#define AT32_PLL_FR                AT32_PLL_FR_DIV32
#else
#error "invalid AT32_PLL_FR_VALUE value specified"
#endif

/**
 * @brief   PLL input and output clock frequency.
 */
#if (AT32_PLLCFGEN == AT32_PLLCFGEN_SOLID) || defined(__DOXYGEN__)
#define AT32_PLLCLKIN              AT32_PLLRCSCLK  
#define AT32_PLLCLKOUT             (AT32_PLLCLKIN * AT32_PLLMULT_VALUE)
#elif (AT32_PLLCFGEN == AT32_PLLCFGEN_FLEX)
#define AT32_PLLCLKIN              (AT32_PLLRCSCLK / AT32_PLL_MS_VALUE) 
#define AT32_PLLFRCLK              (AT32_PLLCLKIN * AT32_PLL_NS_VALUE)
#define AT32_PLLCLKOUT             (AT32_PLLFRCLK / AT32_PLL_FR_VALUE)

/* PLL FR frequency range check.*/
#if (AT32_PLLFRCLK < AT32_PLLFR_MIN) || (AT32_PLLFRCLK > AT32_PLLFR_MAX)
#error "AT32_PLLFRCLK outside acceptable range (AT32_PLLFR_MIN...AT32_PLLFR_MAX)"
#endif
#else
#error "invalid AT32_PLLCFGEN value specified"
#endif

/* PLL input frequency range check.*/
#if (AT32_PLLCLKIN < AT32_PLLIN_MIN) || (AT32_PLLCLKIN > AT32_PLLIN_MAX)
#error "AT32_PLLCLKIN outside acceptable range (AT32_PLLIN_MIN...AT32_PLLIN_MAX)"
#endif

/* PLL output frequency range check.*/
#if (AT32_PLLCLKOUT < AT32_PLLOUT_MIN) || (AT32_PLLCLKOUT > AT32_PLLOUT_MAX)
#error "AT32_PLLCLKOUT outside acceptable range (AT32_PLLOUT_MIN...AT32_PLLOUT_MAX)"
#endif

/**
 * @brief   PLL frequency reference.
 */
#if ((AT32_PLLCLKIN > 3900000) && (AT32_PLLCLKIN < 5000000))
#define AT32_PLLCLKREF CRM_PLL_PLL_FREF_4M
#elif ((AT32_PLLCLKIN > 5200000) && (AT32_PLLCLKIN < 6250000))
#define AT32_PLLCLKREF CRM_PLL_PLL_FREF_6M
#elif ((AT32_PLLCLKIN > 7812500) && (AT32_PLLCLKIN < 8330000))
#define AT32_PLLCLKREF CRM_PLL_PLL_FREF_8M
#elif ((AT32_PLLCLKIN > 8330000) && (AT32_PLLCLKIN < 12500000))
#define AT32_PLLCLKREF CRM_PLL_PLL_FREF_12M
#elif ((AT32_PLLCLKIN > 15625000) && (AT32_PLLCLKIN < 20830000))
#define AT32_PLLCLKREF CRM_PLL_PLL_FREF_16M
#elif ((AT32_PLLCLKIN > 20830000) && (AT32_PLLCLKIN < 31255000))
#define AT32_PLLCLKREF CRM_PLL_PLL_FREF_25M
#endif

/**
 * @brief   System clock source.
 */
#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) || defined(__DOXYGEN__)
#define AT32_SYSCLK                 AT32_PLLCLKOUT
#elif (AT32_SCLKSEL == AT32_SCLKSEL_HICK)
#define AT32_SYSCLK                 AT32_HICKCLK
#elif (AT32_SCLKSEL == AT32_SCLKSEL_HEXT)
#define AT32_SYSCLK                 AT32_HEXTCLK
#else
#error "invalid AT32_SCLKSEL value specified"
#endif

/* Check on the system clock.*/
#if AT32_SYSCLK > AT32_SYSCLK_MAX
#error "AT32_SYSCLK exceeding maximum frequency (AT32_SYSCLK_MAX)"
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
#define AT32_PCLK1                  (AT32_HCLK / 1)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV2
#define AT32_PCLK1                  (AT32_HCLK / 2)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV4
#define AT32_PCLK1                  (AT32_HCLK / 4)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV8
#define AT32_PCLK1                  (AT32_HCLK / 8)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV16
#define AT32_PCLK1                  (AT32_HCLK / 16)
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
#define AT32_PCLK2                  (AT32_HCLK / 1)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV2
#define AT32_PCLK2                  (AT32_HCLK / 2)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV4
#define AT32_PCLK2                  (AT32_HCLK / 4)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV8
#define AT32_PCLK2                  (AT32_HCLK / 8)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV16
#define AT32_PCLK2                  (AT32_HCLK / 16)
#else
#error "invalid AT32_APB2DIV value specified"
#endif

/* APB2 frequency check.*/
#if AT32_PCLK2 > AT32_PCLK2_MAX
#error "AT32_PCLK2 exceeding maximum frequency (AT32_PCLK2_MAX)"
#endif

/**
 * @brief   ERTC clock.
 */
#if (AT32_ERTCSEL == AT32_ERTCSEL_LEXT) || defined(__DOXYGEN__)
#define AT32_ERTCCLK                AT32_LEXTCLK
#elif AT32_ERTCSEL == AT32_ERTCSEL_LICK
#define AT32_ERTCCLK                AT32_LICKCLK
#elif AT32_ERTCSEL == AT32_ERTCSEL_HEXTDIV
#define AT32_ERTCCLK                (AT32_HEXTCLK / 128)
#elif AT32_ERTCSEL == AT32_ERTCSEL_NOCLOCK
#define AT32_ERTCCLK                0
#else
#error "invalid source selected for ERTC clock"
#endif

/**
 * @brief   ADC frequency.
 */
#if (AT32_ADCDIV == AT32_ADCDIV_DIV2) || defined(__DOXYGEN__)
#define AT32_ADCCLK                 (AT32_PCLK2 / 2)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV4
#define AT32_ADCCLK                 (AT32_PCLK2 / 4)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV6
#define AT32_ADCCLK                 (AT32_PCLK2 / 6)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV8
#define AT32_ADCCLK                 (AT32_PCLK2 / 8)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV12
#define AT32_ADCCLK                 (AT32_PCLK2 / 12)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV16
#define AT32_ADCCLK                 (AT32_PCLK2 / 16)
#else
#error "invalid AT32_ADCDIV value specified"
#endif

/* ADC frequency check.*/
#if AT32_ADCCLK > AT32_ADCCLK_MAX
#error "AT32_ADCCLK exceeding maximum frequency (AT32_ADCCLK_MAX)"
#endif

/**
 * @brief   USB frequency.
 */
#if (AT32_USBDIV == AT32_USBDIV_DIV1P5) || defined(__DOXYGEN__)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 3)
#elif (AT32_USBDIV == AT32_USBDIV_DIV1)
#define AT32_USBCLK                 AT32_PLLCLKOUT
#elif (AT32_USBDIV == AT32_USBDIV_DIV2P5)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 5)
#elif (AT32_USBDIV == AT32_USBDIV_DIV2)
#define AT32_USBCLK                 (AT32_PLLCLKOUT / 2)
#elif (AT32_USBDIV == AT32_USBDIV_DIV3P5)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 7)
#elif (AT32_USBDIV == AT32_USBDIV_DIV3)
#define AT32_USBCLK                 (AT32_PLLCLKOUT / 3)
#elif (AT32_USBDIV == AT32_USBDIV_DIV4)
#define AT32_USBCLK                 (AT32_PLLCLKOUT / 4)
#else
#error "invalid AT32_USBDIV value specified"
#endif

/**
 * @brief   Timers 2, 3, 4, 5 clock.
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
#define AT32_FLASHBITS             0x00000010
#elif (AT32_HCLK <= 64000000)
#define AT32_FLASHBITS             0x00000011
#elif (AT32_HCLK <= 96000000)
#define AT32_FLASHBITS             0x00000012
#elif (AT32_HCLK <= 128000000)
#define AT32_FLASHBITS             0x00000013
#elif (AT32_HCLK <= 150000000)
#define AT32_FLASHBITS             0x00000014
#endif

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
#ifdef __cplusplus
}
#endif

#endif /* _HAL_LLD_H_ */

/** @} */

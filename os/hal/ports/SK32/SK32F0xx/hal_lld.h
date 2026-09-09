/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_lld.h
 * @brief   SK32F0xx HAL subsystem low level driver header.
 * @details This file is the platform specific part of the HAL for the
 *          3Think SK32F0xx family (SK32F072 / SK32F077).
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

/*
 * The vendor device header provides all the register definitions used by
 * this port. It is self contained (it does not require the SPL peripheral
 * headers) and is shared by the whole HAL.
 */
#include "sk32f0xx.h"

/*
 * Registry definitions.
 */
#include "sk32_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification macros
 * @{
 */
#if defined(SK32F072xB) || defined(__DOXYGEN__)
#define PLATFORM_NAME           "SK32F072xB devices"
#elif defined(SK32F077xB)
#define PLATFORM_NAME           "SK32F077xB devices"
#else
#error "SK32F0xx device unsupported or not specified"
#endif
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define SK32_HSI_CLK            SK32_HSICLK     /**< High speed internal clock.*/
#define SK32_PLL48_CLK          SK32_PLL48CLK   /**< USB dedicated 48MHz clock.*/
/** @} */

/**
 * @name    RCC_CFGR register bits definitions
 * @{
 */
#define SK32_SW_HSI             (0 << 0)        /**< SYSCLK source is HSI.     */
#define SK32_SW_PLL             (2 << 0)        /**< SYSCLK source is PLL.     */

#define SK32_HPRE_DIV1          (0 << 4)        /**< SYSCLK divided by 1.      */

#define SK32_PPRE_DIV1          (0 << 8)        /**< HCLK divided by 1.        */

#define SK32_PLLSRC_HSI_PREDIV  (1 << 15)       /**< PLL clock source is
                                                     HSI/PREDIV1.              */
/** @} */

/**
 * @name    RCC_CFGR2 register bits definitions
 * @{
 */
#define SK32_PREDIV1_DIV1       (0 << 0)        /**< PLL input divided by 1.   */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Disables the RCC initialization in the HAL.
 */
#if !defined(SK32_NO_INIT) || defined(__DOXYGEN__)
#define SK32_NO_INIT                        FALSE
#endif

/**
 * @brief   Main clock source selection.
 * @note    The default is a 72MHz system clock from the 8MHz HSI using the
 *          main PLL (HSI / PREDIV1(=1) * PLLMUL(=9)), matching the vendor
 *          clock configuration tool output.
 */
#if !defined(SK32_SW) || defined(__DOXYGEN__)
#define SK32_SW                             SK32_SW_PLL
#endif

/**
 * @brief   PREDIV1 divider value (1..16) applied to the HSI before the PLL.
 * @note    The default is 1 (8MHz into the PLL).
 */
#if !defined(SK32_PREDIV_VALUE) || defined(__DOXYGEN__)
#define SK32_PREDIV_VALUE                   1
#endif

/**
 * @brief   PLL multiplier value (2..16).
 * @note    The default is 9 (72MHz output).
 */
#if !defined(SK32_PLLMUL_VALUE) || defined(__DOXYGEN__)
#define SK32_PLLMUL_VALUE                   9
#endif

/**
 * @brief   AHB prescaler value.
 * @note    Only DIV1 is currently supported by this port.
 */
#if !defined(SK32_HPRE) || defined(__DOXYGEN__)
#define SK32_HPRE                           SK32_HPRE_DIV1
#endif

/**
 * @brief   APB prescaler value.
 * @note    Only DIV1 is currently supported by this port.
 */
#if !defined(SK32_PPRE) || defined(__DOXYGEN__)
#define SK32_PPRE                           SK32_PPRE_DIV1
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(SK32F0xx_MCUCONF)
#error "Using a wrong mcuconf.h file, SK32F0xx_MCUCONF not defined"
#endif

/*
 * Clock source checks.
 */
#if (SK32_SW != SK32_SW_HSI) && (SK32_SW != SK32_SW_PLL)
#error "invalid SK32_SW value specified"
#endif

/*
 * PLL multiplier checks.
 */
#if ((SK32_PLLMUL_VALUE >= 2) && (SK32_PLLMUL_VALUE <= 16)) ||              \
    defined(__DOXYGEN__)
#define SK32_PLLMUL                         ((SK32_PLLMUL_VALUE - 2) << 18)
#else
#error "invalid SK32_PLLMUL_VALUE value specified (2..16)"
#endif

/*
 * PREDIV1 checks.
 */
#if ((SK32_PREDIV_VALUE >= 1) && (SK32_PREDIV_VALUE <= 16)) ||              \
    defined(__DOXYGEN__)
#define SK32_PREDIV1                        (SK32_PREDIV_VALUE - 1)
#else
#error "invalid SK32_PREDIV_VALUE value specified (1..16)"
#endif

/*
 * Prescaler checks (DIV1 only for now).
 */
#if (SK32_HPRE != SK32_HPRE_DIV1) && !defined(__DOXYGEN__)
#error "invalid SK32_HPRE value specified, only SK32_HPRE_DIV1 is supported"
#endif

#if (SK32_PPRE != SK32_PPRE_DIV1) && !defined(__DOXYGEN__)
#error "invalid SK32_PPRE value specified, only SK32_PPRE_DIV1 is supported"
#endif

/**
 * @brief   PLL activation flag.
 */
#if (SK32_SW == SK32_SW_PLL) || defined(__DOXYGEN__)
#define SK32_ACTIVATE_PLL                   TRUE
#else
#define SK32_ACTIVATE_PLL                   FALSE
#endif

/**
 * @brief   PLL input clock frequency (HSI divided by PREDIV1).
 */
#define SK32_PLLCLKIN                       (SK32_HSICLK / SK32_PREDIV_VALUE)

/**
 * @brief   PLL output clock frequency.
 */
#define SK32_PLLCLKOUT                      (SK32_PLLCLKIN * SK32_PLLMUL_VALUE)

/* PLL output frequency range check.*/
#if (SK32_PLLCLKOUT < SK32_PLLCLKIN) || (SK32_PLLCLKOUT > SK32_SYSCLK_MAX)
#error "SK32_PLLCLKOUT outside acceptable range (up to SK32_SYSCLK_MAX)"
#endif

/**
 * @brief   System clock source frequency.
 */
#if (SK32_SW == SK32_SW_PLL) || defined(__DOXYGEN__)
#define SK32_SYSCLK                         SK32_PLLCLKOUT
#elif SK32_SW == SK32_SW_HSI
#define SK32_SYSCLK                         SK32_HSICLK
#else
#error "invalid SK32_SW value specified"
#endif

/**
 * @brief   AHB frequency.
 */
#if (SK32_HPRE == SK32_HPRE_DIV1) || defined(__DOXYGEN__)
#define SK32_HCLK                           (SK32_SYSCLK / 1)
#else
#error "invalid SK32_HPRE value specified"
#endif

/**
 * @brief   APB frequency.
 */
#if (SK32_PPRE == SK32_PPRE_DIV1) || defined(__DOXYGEN__)
#define SK32_PCLK1                          (SK32_HCLK / 1)
#define SK32_PCLK2                          (SK32_HCLK / 1)
#else
#error "invalid SK32_PPRE value specified"
#endif

/**
 * @brief   Timers clock.
 */
#define SK32_TIMCLK1                        SK32_PCLK1
#define SK32_TIMCLK2                        SK32_PCLK2

/**
 * @brief   Flash settings.
 * @note    2 wait states plus prefetch buffer enable, as programmed by the
 *          vendor clock configuration.
 */
#define SK32_FLASHBITS                      (FLASH_ACR_PRFTBE |               \
                                             SK32_FLASH_WAIT_STATES)

/**
 * @brief   USB frequency.
 * @note    The USB controller is clocked by the dedicated PLL48 (enabled by
 *          the USB low level driver), not by the system clock.
 */
#define SK32_USBCLK                         SK32_PLL48CLK

/*
 * DMA services activation.
 *
 * The SK32 DMA helper code (sk32_dma.c) and the DMA1 initialization in
 * hal_lld.c are self-gated on SK32_DMA_REQUIRED: any low level driver of
 * this platform that allocates DMA1 channels must cause the macro to be
 * defined.  The SLED (hal_sled_lld.c) and KBCU (hal_kbcu_lld.c) drivers are
 * the native DMA users, so the macro is tied to the HAL_USE_SLED and
 * HAL_USE_KBCU switches.
 */
#if (defined(HAL_USE_SLED) && (HAL_USE_SLED == TRUE)) ||                     \
    (defined(HAL_USE_KBCU) && (HAL_USE_KBCU == TRUE))
#define SK32_DMA_REQUIRED
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the frequency of a clock point in Hz.
 * @note    Static implementation.
 *
 * @param[in] clkpt     clock point to be returned
 * @return              The clock point frequency in Hz or zero if the
 *                      frequency is unknown.
 *
 * @notapi
 */
#define hal_lld_get_clock_point(clkpt) 0U

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Various helpers.*/
#include "nvic.h"

/*
 * Native SK32F0xx helper headers.
 */
#include "sk32_isr.h"
#include "sk32_rcc.h"
#include "sk32_dma.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void sk32_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @} */

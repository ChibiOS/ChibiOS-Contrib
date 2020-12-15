/*
  Copyright (C) 2020 Alex Lewontin
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
 * @file    NUC123/hal_lld.h
 * @brief   NUC123 HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - NUC123_HSECLK.
 *          - NUC123_HSE_BYPASS (optionally).
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
#define NUC123xxxANx
#undef NUC123xxxAEx
#else
#error "NUC123 device unsupported or not specified"
#endif

/* TODO: Add other NUC123xxxxxx versions */

/** @} */

/**
 * @name    Absolute Maximum Ratings
 * @{
 */

/**
 * @brief   Maximum HSE clock frequency.
 */
#define NUC123_HSECLK_MAX        24000000

/**
 * @brief   Minimum HSE clock frequency.
 */
#define NUC123_HSECLK_MIN        4000000

/**
 * @brief   Minimum PLL frequency.
 */
#define NUC123_PLLCLK_MIN 25000000UL

/**
 * @brief   Maximum PLL frequency.
 */
#define NUC123_PLLCLK_MAX 144000000UL

/**
 * @brief   Minimum HCLK divider value.
 */
#define NUC123_HCLKDIV_MIN 1

/**
 * @brief   Maximum HCLK divider value.
 */
#define NUC123_HCLKDIV_MAX 16
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define NUC123_HSICLK            __HIRC       /**< High speed internal clock. */
#define NUC123_LSICLK            __LIRC       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    HCLK_S bit definitions
 * @{
 */
#define NUC123_HCLKSRC_HSE     (0 << CLK_CLKSEL0_HCLK_S_Pos) /**< HCLK source is HSE.      */
#define NUC123_HCLKSRC_PLL_2   (1 << CLK_CLKSEL0_HCLK_S_Pos) /**< HCLK source is PLL/2.    */
#define NUC123_HCLKSRC_PLL     (2 << CLK_CLKSEL0_HCLK_S_Pos) /**< HCLK source is PLL.      */
#define NUC123_HCLKSRC_LSI     (3 << CLK_CLKSEL0_HCLK_S_Pos) /**< HCLK source is LSI.      */
#define NUC123_HCLKSRC_HSI     (7 << CLK_CLKSEL0_HCLK_S_Pos) /**< HCLK source is HSI.      */
/** @} */

/**
 * @name    PLL_SRC bit definitions
 * @{
 */
#define NUC123_PLLSRC_HSE      (0 << CLK_PLLCON_PLL_SRC_Pos) /**< PLL source is HSE.      */
#define NUC123_PLLSRC_HSI      (1 << CLK_PLLCON_PLL_SRC_Pos) /**< PLL source is HSI.      */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    NUMICRO configuration options
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
#define NUC123_LSI_ENABLED                   FALSE
#endif

/**
 * @brief   Enables or disables the HSE clock source.
 */
#if !defined(NUC123_HSE_ENABLED) || defined(__DOXYGEN__)
#define NUC123_HSE_ENABLED                   TRUE
#endif

/**
 * @brief   Enables or disables PLL
 */
#if !defined(NUC123_PLL_ENABLED) || defined(__DOXYGEN__)
#define NUC123_PLL_ENABLED FALSE
#endif

/**
 * @brief   Clock source for the PLL.
 */
#if !defined(NUC123_HCLK) || defined(__DOXYGEN__)
#define NUC123_HCLK 72000000UL
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(NUC123_MCUCONF)
#error "Using a wrong mcuconf.h file, NUC123_MCUCONF not defined"
#endif

/*
 * HSE checks.
 */
#if NUC123_HSE_ENABLED

#if !defined(NUC123_HSECLK)
#error "HSE frequency not defined"
#elif (NUC123_HSECLK < NUC123_HSECLK_MIN) || (NUC123_HSECLK > NUC123_HSECLK_MAX)
#error "NUC123_HSECLK outside acceptable range (NUC123_HSECLK_MIN...NUC123_HSECLK_MAX)"
#endif
#endif

#define NUC123_PLLCLK (NUC123_HCLK * 2)

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
/* Alias for compatibility */
#define SystemUnlockReg() UNLOCKREG()

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Various helpers */
#include "NUC123.h"
#include "nuc123_isr.h"
#include "nuc123_registry.h"
#include "nvic.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void NUC123_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* _HAL_LLD_H_ */

/** @} */

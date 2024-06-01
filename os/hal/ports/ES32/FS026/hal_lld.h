/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio
              Copyright (C) 2020 Yaotian Feng

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
 * @file    hal_lld.h
 * @brief   ES32 HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef _HAL_LLD_H_
#define _HAL_LLD_H_

#include "es32_registry.h"
#include "nvic.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification macros
 * @{
 */
#define PLATFORM_NAME           "ES32"
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    PLATFORM configuration options
 * @{
 */
/**
 * @brief   Disables the PWR/RCC initialization in the HAL.
 */
#if !defined(ES32_NO_INIT) || defined(__DOXYGEN__)
#define ES32_NO_INIT                       FALSE
#endif

/**
 * @brief   system_clk select.
 */
#if !defined(ES32_SYSCLK_SOURSE_SELECT) || defined(__DOXYGEN__)
#define ES32_SYSCLK_SOURSE_SELECT                       MD_RCU_SW_SYSCLK_HRC48
#endif

/**
 * @brief   external clk config.
 */
#if !defined(ES32_HOSC_CLK_EN) || defined(__DOXYGEN__)
#define ES32_HOSC_CLK_EN                       FALSE
#endif

/**
 * @brief   pll clk config.
 */
#if !defined(ES32_PLL_CLK_EN) || defined(__DOXYGEN__)
#define ES32_PLL_CLK_EN                       FALSE
#endif

#if !defined(ES32_PLL_SOURSE_SELECT) || defined(__DOXYGEN__)
#define ES32_PLL_SOURSE_SELECT                       MD_RCU_PLLSRC_HRC48
#endif

#if !defined(ES32_PLL_CLK_FREQ) || defined(__DOXYGEN__)
#define ES32_PLL_CLK_FREQ                       MD_RCU_PLLCLK_72M
#endif

/**
 * @brief   bus clk config.
 */
#if !defined(ES32_BUS_DIV_HPRE) || defined(__DOXYGEN__)
#define ES32_BUS_DIV_HPRE                       MD_RCU_HPRE_SYSCLK_DIV_1
#endif

#if !defined(ES32_BUS_DIV_PPRE) || defined(__DOXYGEN__)
#define ES32_BUS_DIV_PPRE                       MD_RCU_PPRE_HCLK_DIV_1
#endif

/** @} */

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
void hal_lld_init(void);
void es32_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* _HAL_LLD_H_ */

/** @} */

/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2021 Stefan Kerkmann

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
 * @file    STM32F1xx/hal_lld.h
 * @brief   STM32F1xx HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - GD32_LSECLK.
 *          - GD32_LSE_BYPASS (optionally).
 *          - GD32_HSECLK.
 *          - GD32_HSE_BYPASS (optionally).
 *          .
 *          One of the following macros must also be defined:
 *          - STM32F100xB for Value Line Medium Density devices.
 *          - STM32F100xE for Value Line High Density devices.
 *          - STM32F101x6, STM32F102x6, STM32F103x6 for Performance
 *            Low Density devices.
 *          - STM32F101xB, STM32F102xB, STM32F103xB for Performance
 *            Medium Density devices.
 *          - STM32F101xE, STM32F103xE for Performance High Density devices.
 *          - STM32F101xG, STM32F103xG for Performance eXtra Density devices.
 *          - STM32F105xC, STM32F107xC for Connectivity Line devices.
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
 * @name    Platform identification
 * @{
 */
#if defined(__DOXYGEN__) || \
    defined(GD32VF103TB) || defined(GD32VF103T8) || defined(GD32VF103T6) || defined(GD32VF103T4) || \
    defined(GD32VF103CB) || defined(GD32VF103C8) || defined(GD32VF103C6) || defined(GD32VF103C4) || \
    defined(GD32VF103RB) || defined(GD32VF103R8) || defined(GD32VF103R6) || defined(GD32VF103R4) || \
    defined(GD32VF103VB) || defined(GD32VF103V8)
  #define PLATFORM_NAME           "GigaDevice GD32VF103 RISC-V"
  #define GD32VF103
#else
  #error "unsupported or unrecognized GD32VF103 member"
#endif

/**
 * @brief   Sub-family identifier.
 */
#if !defined(STM32F1XX) || !defined(GD32VF103) || defined(__DOXYGEN__)
#define STM32F1XX
#define GD32VF103
#endif
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define GD32_HSICLK            8000000     /**< High speed internal clock. */
#define GD32_LSICLK            40000       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    PMU_CR register bits definitions
 * @{
 */
#define GD32_PLS_MASK          (7 << 5)    /**< PLS bits mask.             */
#define GD32_PLS_LEV0          (0 << 5)    /**< PVD level 0.               */
#define GD32_PLS_LEV1          (1 << 5)    /**< PVD level 1.               */
#define GD32_PLS_LEV2          (2 << 5)    /**< PVD level 2.               */
#define GD32_PLS_LEV3          (3 << 5)    /**< PVD level 3.               */
#define GD32_PLS_LEV4          (4 << 5)    /**< PVD level 4.               */
#define GD32_PLS_LEV5          (5 << 5)    /**< PVD level 5.               */
#define GD32_PLS_LEV6          (6 << 5)    /**< PVD level 6.               */
#define GD32_PLS_LEV7          (7 << 5)    /**< PVD level 7.               */
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
 * @brief   Disables the PMU/RCU initialization in the HAL.
 */
#if !defined(GD32_NO_INIT) || defined(__DOXYGEN__)
#define GD32_NO_INIT               FALSE
#endif

/**
 * @brief   Enables or disables the programmable voltage detector.
 */
#if !defined(GD32_PVD_ENABLE) || defined(__DOXYGEN__)
#define GD32_PVD_ENABLE            FALSE
#endif

/**
 * @brief   Sets voltage level for programmable voltage detector.
 */
#if !defined(GD32_PLS) || defined(__DOXYGEN__)
#define GD32_PLS                   GD32_PLS_LEV0
#endif

/**
 * @brief   Enables or disables the HSI clock source.
 */
#if !defined(GD32_HSI_ENABLED) || defined(__DOXYGEN__)
#define GD32_HSI_ENABLED           TRUE
#endif

/**
 * @brief   Enables or disables the LSI clock source.
 */
#if !defined(GD32_LSI_ENABLED) || defined(__DOXYGEN__)
#define GD32_LSI_ENABLED           FALSE
#endif

/**
 * @brief   Enables or disables the HSE clock source.
 */
#if !defined(GD32_HSE_ENABLED) || defined(__DOXYGEN__)
#define GD32_HSE_ENABLED           TRUE
#endif

/**
 * @brief   Enables or disables the LSE clock source.
 */
#if !defined(GD32_LSE_ENABLED) || defined(__DOXYGEN__)
#define GD32_LSE_ENABLED           FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/


#include "gd32_registry.h"
#include "stm32f105xc.h"

#include "hal_lld_f103.h"
//#include "hal_lld_f105_f107.h"

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
#include "eclic.h"
#include "gd32_isr.h"
#include "gd32_dma.h"
#include "gd32_rcu.h"
#include "gd32_tim.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void gd32_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @} */

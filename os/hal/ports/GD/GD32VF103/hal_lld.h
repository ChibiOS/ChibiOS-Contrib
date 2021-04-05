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
 * @file    GD32VF103/hal_lld.h
 * @brief   GD32VF103 HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - GD32_LXTALCLK.
 *          - GD32_LXTAL_BYPASS (optionally).
 *          - GD32_HXTALCLK.
 *          - GD32_HXTAL_BYPASS (optionally).
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
#if !defined(GD32VF103) || defined(__DOXYGEN__)
#define GD32VF103
#endif
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define GD32_IRC8MCLK            8000000     /**< High speed internal clock. */
#define GD32_IRC40KCLK            40000       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    PMU_CTL register bits definitions
 * @{
 */
#define GD32_LVDT_MASK          (7 << 5)    /**< LVDT bits mask.            */
#define GD32_LVDT_LEV0          (0 << 5)    /**< LVDT level 0.              */
#define GD32_LVDT_LEV1          (1 << 5)    /**< LVDT level 1.              */
#define GD32_LVDT_LEV2          (2 << 5)    /**< LVDT level 2.              */
#define GD32_LVDT_LEV3          (3 << 5)    /**< LVDT level 3.              */
#define GD32_LVDT_LEV4          (4 << 5)    /**< LVDT level 4.              */
#define GD32_LVDT_LEV5          (5 << 5)    /**< LVDT level 5.              */
#define GD32_LVDT_LEV6          (6 << 5)    /**< LVDT level 6.              */
#define GD32_LVDT_LEV7          (7 << 5)    /**< LVDT level 7.              */
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
#if !defined(GD32_LVDT) || defined(__DOXYGEN__)
#define GD32_LVDT                   GD32_LVDT_LEV0
#endif

/**
 * @brief   Enables or disables the IRC8M clock source.
 */
#if !defined(GD32_IRC8M_ENABLED) || defined(__DOXYGEN__)
#define GD32_IRC8M_ENABLED           TRUE
#endif

/**
 * @brief   Enables or disables the IRC40K clock source.
 */
#if !defined(GD32_IRC40K_ENABLED) || defined(__DOXYGEN__)
#define GD32_IRC40K_ENABLED           FALSE
#endif

/**
 * @brief   Enables or disables the HXTAL clock source.
 */
#if !defined(GD32_HXTAL_ENABLED) || defined(__DOXYGEN__)
#define GD32_HXTAL_ENABLED           TRUE
#endif

/**
 * @brief   Enables or disables the LXTAL clock source.
 */
#if !defined(GD32_LXTAL_ENABLED) || defined(__DOXYGEN__)
#define GD32_LXTAL_ENABLED           FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/


#include "gd32_registry.h"
#include "gd32vf103.h"

#include "hal_lld_gd32vf103.h"

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

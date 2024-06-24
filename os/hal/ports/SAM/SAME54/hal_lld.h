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
 * @file    hal_lld.h
 * @brief   PLATFORM HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#ifndef SAM_XOSC32K_FREQ
#define SAM_XOSC32K_FREQ 0
#endif

#define SAM_DPLL_INPUT_SRC_GCLK 0
#define SAM_DPLL_INPUT_SRC_XOSC32 1
#define SAM_DPLL_INPUT_SRC_XOSC0 2
#define SAM_DPLL_INPUT_SRC_XOSC1 3
#define hal_lld_get_clock_point(clkpt) 0U
#define SAM_DMAC_CHAN_NUM 32
/**
 * @brief   Requires use of SPIv2 driver model.
 */
#define HAL_LLD_SELECT_SPI_V2 TRUE

/**
 * @brief   Specifies implementation of dynamic clock management.
 */
// #define HAL_LLD_USE_CLOCK_MANAGEMENT

/**
 * @name    Platform identification macros
 * @{
 */
#define PLATFORM_NAME "SAME54"
/** @} */

/**
 * @brief Macro for enabling XOSC0
 * 
 */
#if !defined(SAM_XOSC0_ENABLED) || defined(__DOXYGEN__)
#define SAM_XOSC0_ENABLED FALSE
#undef SAM_XOSC0_FREQ
#define SAM_XOSC0_FREQ 0
#endif

/**
 * @brief Macro for enabling XOSC1
 * 
 */
#if !defined(SAM_XOSC1_ENABLED) || defined(__DOXYGEN__)
#define SAM_XOSC1_ENABLED FALSE
#undef SAM_XOSC0_FREQ
#define SAM_XOSC0_FREQ 0
#endif

/**
 * @brief Macro for enabling XOSC32K
 * 
 */
#if !defined(SAM_XOSC32K_ENABLED) || defined(__DOXYGEN__)
#define SAM_XOSC32K_ENABLED FALSE
#endif

/**
 * @brief Macro for enabling FDPLL0
 * 
 */
#if !defined(SAM_FDPLL0_ENABLED) || defined(__DOXYGEN__)
#define SAM_FDPLL0_ENABLED FALSE
#endif

/**
 * @brief Macro for enabling FDPLL1
 * 
 */
#if !defined(SAM_FDPLL1_ENABLED) || defined(__DOXYGEN__)
#define SAM_FDPLL1_ENABLED FALSE
#endif

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    SAME54 configuration options
 * @{
 */
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
#include "nvic.h"
#include "sam_dmac.h"
#include "sam_clk.h"
#include "sam_irq.h"
#include "sam_gclk_add.h"
/*
 * Configuration-related checks.
 */
#if !defined(SAME54_MCUCONF)
#error "Using a wrong mcuconf.h file, SAME54_MCUCONF not defined"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a clock point identifier.
 */
typedef unsigned halclkpt_t;

#if defined(HAL_LLD_USE_CLOCK_MANAGEMENT) || defined(__DOXYGEN__)
/**
 * @brief   Type of a clock point frequency in Hz.
 */
typedef uint32_t halfreq_t;

/**
 * @brief   Type of a clock configuration structure.
 */
typedef struct {
  uint32_t dummy;
} halclkcfg_t;
#endif /* defined(HAL_LLD_USE_CLOCK_MANAGEMENT) */

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if defined(HAL_LLD_USE_CLOCK_MANAGEMENT) && !defined(__DOXYGEN__)
extern const halclkcfg_t hal_clkcfg_reset;
extern const halclkcfg_t hal_clkcfg_default;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void hal_lld_init(void);
#if defined(HAL_LLD_USE_CLOCK_MANAGEMENT) || defined(__DOXYGEN__)
bool hal_lld_clock_switch_mode(const halclkcfg_t* ccp);
halfreq_t hal_lld_get_clock_point(halclkpt_t clkpt);
#endif /* defined(HAL_LLD_USE_CLOCK_MANAGEMENT) */
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @} */

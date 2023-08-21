/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023 HorrorTroll
    ChibiOS - Copyright (C) 2023 Zhaqian

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
 * @file    AT32F41x/hal_lld.h
 * @brief   AT32F41x HAL subsystem low level driver header.
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
#define HAL_LLD_SELECT_SPI_V2           FALSE

/**
 * @name    Platform identification
 * @{
 */
#if defined(__DOXYGEN__)
#define PLATFORM_NAME           "AT32F41x"

#elif defined(AT32F415K_MD)
#define PLATFORM_NAME           "AT32F415K Value Line Medium Density"

#elif defined(AT32F415K_HD)
#define PLATFORM_NAME           "AT32F415K Value Line High Density"

#elif defined(AT32F415C_MD)
#define PLATFORM_NAME           "AT32F415C Value Line Medium Density"

#elif defined(AT32F415C_HD)
#define PLATFORM_NAME           "AT32F415C Value Line High Density"

#elif defined(AT32F415R_MD)
#define PLATFORM_NAME           "AT32F415R Value Line Medium Density"

#elif defined(AT32F415R_HD)
#define PLATFORM_NAME           "AT32F415R Value Line High Density"

#else
#error "unsupported or unrecognized AT32F41x member"
#endif

/**
 * @brief   Sub-family identifier.
 */
#if !defined(AT32F41X) || defined(__DOXYGEN__)
#define AT32F41X
#endif
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define AT32_HICKCLK            48000000    /**< High speed internal clock. */
#define AT32_LICKCLK            40000       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    PWC_CTRL register bits definitions
 * @{
 */
#define AT32_PVMSEL_MASK        (7 << 5)    /**< PVMSEL bits mask.          */
#define AT32_PVMSEL_LEV1        (1 << 5)    /**< PVM level 1.               */
#define AT32_PVMSEL_LEV2        (2 << 5)    /**< PVM level 2.               */
#define AT32_PVMSEL_LEV3        (3 << 5)    /**< PVM level 3.               */
#define AT32_PVMSEL_LEV4        (4 << 5)    /**< PVM level 4.               */
#define AT32_PVMSEL_LEV5        (5 << 5)    /**< PVM level 5.               */
#define AT32_PVMSEL_LEV6        (6 << 5)    /**< PVM level 6.               */
#define AT32_PVMSEL_LEV7        (7 << 5)    /**< PVM level 7.               */
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
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if defined(AT32F415K_MD) || defined(AT32F415K_HD) ||                       \
    defined(AT32F415C_MD) || defined(AT32F415C_HD) ||                       \
    defined(AT32F415R_MD) || defined(AT32F415R_HD) ||                       \
    defined(__DOXYGEN__)
#include "hal_lld_f415.h"
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
#include "at32_isr.h"
//#include "at32_dma.h"
#include "at32_crm.h"
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

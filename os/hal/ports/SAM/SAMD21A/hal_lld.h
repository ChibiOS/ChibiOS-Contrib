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
#define SAM_DMAC_CHAN_NUM        12
#define SAM_EVSYS_CHAN_NUM       12
/**
 * @brief   Requires use of SPIv2 driver model.
 */
#define HAL_LLD_SELECT_SPI_V2           TRUE

/**
 * @name    Platform identification macros
 * @{
 */
#define PLATFORM_NAME               "SAMD21"

#define SAM_MAX_FREQ_SYSCLK         48000000UL

#define SAM_MAX_FREQ_GCLK           48000000UL

#define SAM_OSC8_VAL                1000000UL
#define SAM_OSC32K_VAL              32000UL

#define SAM_XOSC_MAX_VAL            32000000UL
#define SAM_XOSC32K_VAL             32768UL
#define SAM_DFLL48_VAL              48000000UL

#define RTC_HANDLER                 Vector4C
#define EIC_HANDLER                 Vector50
#define DMAC_HANDLER                Vector58
#define SERCOM0_HANDLER             Vector64
#define SERCOM1_HANDLER             Vector68
#define SERCOM2_HANDLER             Vector6C
#define SERCOM3_HANDLER             Vector70
#define SERCOM4_HANDLER             Vector74
#define SERCOM5_HANDLER             Vector78
#define TCC0_HANDLER                Vector7C
#define TCC1_HANDLER                Vector80
#define TC2_HANDLER                 Vector84
#define TC3_HANDLER                 Vector88
#define TC4_HANDLER                 Vector8C
#define TC5_HANDLER                 Vector90
#define TC6_HANDLER                 Vector94
#define TC7_HANDLER                 Vector98
#define ADC_HANDLER                 Vector9C
#define AC_HANDLER                  VectorA0
#define DAC_HANDLER                 VectorA4
#define PTC_HANDLER                 VectorA8
#define I2S_HANDLER                 VectorAC

/**
 * @brief   Enables or disables the HSI clock source.
 */
#if !defined(SAM_OSC8_ENABLED) || defined(__DOXYGEN__)
#define SAM_OSC8_ENABLED                   TRUE
#endif

/**
 * @brief   Enables or disables the LSI clock source.
 */
#if !defined(SAM_OSC32K_ENABLED) || defined(__DOXYGEN__)
#define SAM_OSC32K_ENABLED                 FALSE
#endif

/**
 * @brief   Enables or disables the HSE clock source.
 */
#if !defined(SAM_XOSC_ENABLED) || defined(__DOXYGEN__)
#define SAM_XOSC_ENABLED                   FALSE
#endif

/**
 * @brief   Enables or disables the LSE clock source.
 */
#if !defined(SAM_XOSC32_ENABLED) || defined(__DOXYGEN__)
#define SAM_XOSC32_ENABLED                   TRUE
#endif


/**
 * @brief   Enables or disables the LSE clock source.
 */
#if !defined(SAM_DFLL48_ENABLED) || defined(__DOXYGEN__)
#define SAM_DFLL48_ENABLED                   TRUE
#endif

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/
#include "nvic.h"
#include "sam_dmac.h"
// #include "sam_evsys.h"
/**
 * @name    PLATFORM configuration options
 * @{
 */
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
// #if !defined()
// #endif
/*
 * Configuration-related checks.
 */
// #if !defined(PLATFORM_MCUCONF)
// #error "Using a wrong mcuconf.h file, PLATFORM_MCUCONF not defined"
// #endif

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
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @} */

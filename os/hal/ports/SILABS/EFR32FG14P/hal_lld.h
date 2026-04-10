/*
    ChibiOS - Copyright (C) 2023 Xael South

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

#ifndef _HAL_LLD_H_
#define _HAL_LLD_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#include "efr32_registry.h"

/**
 * @name    Platform identification macros
 * @{
 */
#define PLATFORM_NAME           "EFR32FG14P"
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if defined(EFR32FG14P23X) && !defined(EFR32FG14P23X_MCUCONF)
#error "Using a wrong mcuconf.h file, EFR32FG14P23X_MCUCONF not defined"
#endif

#define EFR32_HCLK                      EFR32_HFRCO_STARTUP_FREQ
#define EFR32_LFXOCLK                   EFR32_LFXO_FREQ
#define EFR32_LFRCOCLK                  EFR32_LFRCO_FREQ
#define EFR32_ULFRCOCLK                 EFR32_ULFRCO_FREQ


#define EFR32_RTCCSEL_NOCLOCK           (0u << 0)
#define EFR32_RTCCSEL_LFXO              (1u << 0)
#define EFR32_RTCCSEL_LFRCO             (1u << 1)
#define EFR32_RTCCSEL_ULFRCO            (1u << 2)

#define EFR32_RTCC_IRQ_HANDLER          VectorBC
#define EFR32_RTCC_IRQ_NUMBER           RTCC_IRQn
#define EFR32_RTCCCLK                   EFR32_LFXOCLK


#define EFR32_LETIM1SEL_NOCLOCK         (0u << 0)
#define EFR32_LETIM1SEL_LFXO            (1u << 0)
#define EFR32_LETIM1SEL_LFRCO           (1u << 1)
#define EFR32_LETIM1SEL_ULFRCO          (1u << 2)

#define EFR32_LETIM1_HANDLER            VectorAC
#define EFR32_LETIM1_NUMBER             LETIMER0_IRQn
#define EFR32_LETIM1CLK                 EFR32_LFXOCLK

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

#ifdef __cplusplus
extern "C" {
#endif
  void efr32_chip_init(void);
  void efr32_clock_init(void);
  void hal_lld_init(void);
#ifdef __cplusplus
}
#endif

#endif /* _HAL_LLD_H_ */

/** @} */

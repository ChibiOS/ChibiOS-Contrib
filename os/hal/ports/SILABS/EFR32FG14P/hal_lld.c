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
 * @file    hal_lld.c
 * @brief   PLATFORM HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   EFR32FG14P chip and errata initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */

void efr32_chip_init(void) {

  CHIP_Init();
}

/**
 * @brief   EFR32FG14P clocks initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
void efr32_clock_init(void) {
  SystemCoreClockUpdate();
    
#if EFR32_LFXO_ENABLED
  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
#else
  CMU_OscillatorEnable(cmuOsc_LFXO, false, false);
#endif

#if EFR32_HFXO_ENABLED
  CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
#else
  CMU_OscillatorEnable(cmuOsc_HFXO, false, false);
#endif

#if EFR32_LFRCO_ENABLED
  CMU_OscillatorEnable(cmuOsc_LFRCO, true, true);
#else
  CMU_OscillatorEnable(cmuOsc_LFRCO, false, false);
#endif

#if EFR32_HFRCO_ENABLED
  CMU_OscillatorEnable(cmuOsc_HFRCO, true, true);
#else
  CMU_OscillatorEnable(cmuOsc_HFRCO, false, false);
#endif

#if defined(EFR32_RTCCSEL)
#if EFR32_RTCCSEL == EFR32_RTCCSEL_NOCLOCK
  CMU_ClockSelectSet(cmuClock_RTCC, cmuSelect_Disabled);
  
#elif EFR32_RTCCSEL == EFR32_RTCCSEL_LFXO
  CMU_ClockEnable(cmuClock_HFLE, true);
  CMU_ClockSelectSet(cmuClock_LFE, cmuSelect_LFXO);

#elif EFR32_RTCCSEL == EFR32_RTCCSEL_LFRCO
  CMU_ClockEnable(cmuClock_HFLE, true);
  CMU_ClockSelectSet(cmuClock_LFE, cmuSelect_LFRCO);

#elif EFR32_RTCCSEL == EFR32_RTCCSEL_ULFRCO
  CMU_ClockEnable(cmuClock_HFLE, true);
  CMU_ClockSelectSet(cmuClock_LFE, cmuSelect_ULFRCO);

#else
#error "EFR32_RTCCSEL not specified"
#endif
#endif

#if defined(EFR32_LETIM1SEL)
#if EFR32_LETIM1SEL == EFR32_LETIM1SEL_NOCLOCK
  CMU_ClockSelectSet(cmuClock_LETIMER0, cmuSelect_Disabled);
  
#elif EFR32_LETIM1SEL == EFR32_LETIM1SEL_LFXO
  CMU_ClockEnable(cmuClock_HFLE, true);
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);

#elif EFR32_LETIM1SEL == EFR32_LETIM1SEL_LFRCO
  CMU_ClockEnable(cmuClock_HFLE, true);
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFRCO);

#elif EFR32_LETIM1SEL == EFR32_LETIM1SEL_ULFRCO
  CMU_ClockEnable(cmuClock_HFLE, true);
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_ULFRCO);

#else
#error "EFR32_LETIM1SEL not specified"
#endif
#endif
}


/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {
  /* NVIC initialization.*/
  nvicInit();
}

/** @} */

/*
    Copyright (C) 2015 Fabio Utzig

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
 * @file    NRF51/NRF51822/hal_lld.c
 * @brief   NRF51822 HAL Driver subsystem low level driver source.
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
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
  /* High frequency clock initialisation
   *  (If NRF51_XTAL_VALUE is not defined assume its an RC oscillator)
   */
#if defined(NRF51_XTAL_VALUE)
#if   NRF51_XTAL_VALUE == 16000000
  NRF_CLOCK->XTALFREQ = 0xFF;
#elif NRF51_XTAL_VALUE == 32000000
  NRF_CLOCK->XTALFREQ = 0x00;
#endif
#endif
  NRF_CLOCK->TASKS_HFCLKSTOP = 1;
  
  /* Low frequency clock initialisation
   * If source not specified, use the internal RC (0) which is prefered 
   * over synthetized clock from the high frequency clock (2)
   */
#if defined(NRF51_LFCLK_SOURCE)
#if (NRF51_LFCLK_SOURCE >=0) && (NRF51_LFCLK_SOURCE <= 2)
  NRF_CLOCK->LFCLKSRC = NRF51_LFCLK_SOURCE;
#else
#error "Possible value for NRF51_LFCLK_SOURCE are 0=RC, 1=XTAL, 2=Synth"
#endif
#else
  NRF_CLOCK->LFCLKSRC = 0;
#endif
  
#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE)
  NRF_CLOCK->TASKS_LFCLKSTART = 1;
#endif
}

/**
 * @}
 */

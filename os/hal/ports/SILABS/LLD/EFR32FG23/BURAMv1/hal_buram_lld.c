/*
    ChibiOS/HAL - Copyright (C) 2024 Xael South

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
 * @file    hal_buram_lld.c
 * @brief   BURAM Driver subsystem low level driver source.
 *
 * @addtogroup BURAM
 * @{
 */
#include "hal.h"

#if (HAL_USE_BURAM == TRUE) || defined(__DOXYGEN__)

#include "hal_buram_lld.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local types.                                                       */
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
 * @brief   Configures and activates the BURAM peripheral.
 *
 * @param[in] buramp        pointer to the @p BURAMDriver object
 * @param[in] cfgp          pointer to the @p BURAMConfig object
 *
 * @notapi
 */
void buram_lld_start(BURAMDriver *buramp, const BURAMConfig *cfgp) {

  (void)cfgp;

  if (false) {
  }
  /* BURAM clock could have been enabled during the early init,
     so just check if the clock is enabled yet. */
  #if BURAM_USE_BURAM1
  else if (buramp == &BURAMD1) {
    if ((CMU->CLKEN0 & CMU_CLKEN0_BURAM) == 0U) {
      CMU->CLKEN0_SET = CMU_CLKEN0_BURAM;
    }
  }
  #endif
  #if BURAM_USE_BURAM2
  else if (buramp == &BURAMD2) {
    if ((CMU->CLKEN0 & CMU_CLKEN0_BURAM) == 0U) {
      CMU->CLKEN0_SET = CMU_CLKEN0_BURAM;
    }
  }
  #endif
  #if BURAM_USE_BURAM3
  else if (buramp == &BURAMD3) {
    if ((CMU->CLKEN0 & CMU_CLKEN0_BURAM) == 0U) {
      CMU->CLKEN0_SET = CMU_CLKEN0_BURAM;
    }
  }
  #endif
  #if BURAM_USE_BURAM4
  else if (buramp == &BURAMD4) {
    if ((CMU->CLKEN0 & CMU_CLKEN0_BURAM) == 0U) {
      CMU->CLKEN0_SET = CMU_CLKEN0_BURAM;
    }
  }
  #endif
}

/**
 * @brief   Deactivates the BURAM peripheral.
 *
 * @param[in] buramp        pointer to the @p BURAMDriver object
 *
 * @notapi
 */
void buram_lld_stop(BURAMDriver *buramp) {

  if (false) {
  }
  #if BURAM_USE_BURAM1
  if (buramp == &BURAMD1) {
    #if !BURAM_USE_BURAM2 && !BURAM_USE_BURAM3 && !BURAM_USE_BURAM4
    CMU->CLKEN0_CLR = CMU_CLKEN0_BURAM;
    #endif
  }
  #endif
  #if BURAM_USE_BURAM2
  if (buramp == &BURAMD2) {
    #if !BURAM_USE_BURAM1 && !BURAM_USE_BURAM3 && !BURAM_USE_BURAM4
    CMU->CLKEN0_CLR = CMU_CLKEN0_BURAM;
    #endif
  }
  #endif
  #if BURAM_USE_BURAM3
  if (buramp == &BURAMD3) {
    #if !BURAM_USE_BURAM1 && !BURAM_USE_BURAM2 && !BURAM_USE_BURAM4
    CMU->CLKEN0_CLR = CMU_CLKEN0_BURAM;
    #endif
  }
  #endif
  #if BURAM_USE_BURAM4
  if (buramp == &BURAMD4) {
    #if !BURAM_USE_BURAM1 && !BURAM_USE_BURAM2 && !BURAM_USE_BURAM3
    CMU->CLKEN0_CLR = CMU_CLKEN0_BURAM;
    #endif
  }
  #endif
}

#endif /* HAL_USE_BURAM */

/** @} */

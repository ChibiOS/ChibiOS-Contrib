/*
    ChibiOS - Copyright (C) 2015 Fabio Utzig

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
 * @file    st_lld.c
 * @brief   NRF51822 ST subsystem low level driver source.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

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

#if (OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC) || defined(__DOXYGEN__)
/**
 * @brief   System Timer vector (RTC0)
 * @details This interrupt is used for system tick in periodic mode.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector6C) {

  OSAL_IRQ_PROLOGUE();

  NRF_RTC0->EVENTS_TICK = 0;
      
  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();

  OSAL_IRQ_EPILOGUE();
}
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {
#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING)

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  /* Using RTC with prescaler */
  NRF_RTC0->TASKS_STOP  = 1;
  NRF_RTC0->PRESCALER   = (NRF51_LFCLK_FREQUENCY / OSAL_ST_FREQUENCY) - 1; 
  NRF_RTC0->INTENSET    = RTC_INTENSET_TICK_Msk;

  /* Start timer */
  nvicEnableVector(RTC0_IRQn, 8);
  NRF_RTC0->TASKS_START = 1;
#endif

}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

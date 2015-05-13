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
 * @brief   System Timer vector.
 * @details This interrupt is used for system tick in periodic mode.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector60) {

  OSAL_IRQ_PROLOGUE();

  /* Clear timer compare event */
  if (NRF_TIMER0->EVENTS_COMPARE[0] != 0)
    NRF_TIMER0->EVENTS_COMPARE[0] = 0;

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

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  NRF_TIMER0->TASKS_CLEAR = 1;

  /*
   * Using 32-bit mode with prescaler 16 configures this
   * timer with a 1MHz clock.
   */
  NRF_TIMER0->BITMODE = 3;
  NRF_TIMER0->PRESCALER = 4;

  /*
   * Configure timer 0 compare capture 0 to generate interrupt
   * and clear timer value when event is generated.
   */
  NRF_TIMER0->CC[0] = (1000000 / OSAL_ST_FREQUENCY) - 1;
  NRF_TIMER0->SHORTS = 1;
  NRF_TIMER0->INTENSET = 0x10000;

  nvicEnableVector(TIMER0_IRQn, 8);

  /* Start timer */
  NRF_TIMER0->TASKS_START = 1;
#endif

}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

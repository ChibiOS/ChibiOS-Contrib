/*
    Copyright (C) 2019 /u/KeepItUnder
    Copyright (C) 2020 Alex Lewontin
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/hal_st_lld.c
 * @brief   M251/M252 ST subsystem low level driver source.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

#if (OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC) || defined(__DOXYGEN__)

/**
 * @brief   SysTick interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_ST_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();

  OSAL_IRQ_EPILOGUE();
}

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  /* The packed SHPR layout used by Cortex-M23 requires a negative IRQn.
     Program the priority before enabling SysTick so the first tick cannot
     run briefly at the reset priority.*/
  NVIC_SetPriority(SysTick_IRQn, M251_ST_IRQ_PRIORITY);

  SysTick->LOAD = (M251_ST_CLK / OSAL_ST_FREQUENCY) - 1U;
  SysTick->VAL = 0U;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk |
                  SysTick_CTRL_TICKINT_Msk;
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */
}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

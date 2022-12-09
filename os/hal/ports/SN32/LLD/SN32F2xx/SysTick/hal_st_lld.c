/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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
 * @file    hal_st_lld.c
 * @brief   PLATFORM ST subsystem low level driver source.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define SYSTICK_CK                          SN32_HCLK

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING

#if (OSAL_ST_RESOLUTION == 32)
#error "Tickless mode on SN32 supports only 16bit timers"
#endif

#if SN32_ST_USE_TIMER == CT16B0

#if !SN32_HAS_CT16B0
#error "CT16B0 not present in the selected device"
#endif

#define ST_ENABLE_CLOCK()                   sys1EnableCT16B0()
#define ST_INIT_CLOCK()                     CT16B0_ResetTimer()

#elif SN32_ST_USE_TIMER == CT16B1

#if !SN32_HAS_CT16B1
#error "CT16B1 not present in the selected device"
#endif

#define ST_ENABLE_CLOCK()                   sys1EnableCT16B1()
#define ST_INIT_CLOCK()                     CT16B1_ResetTimer()

#else
#error "SN32_ST_USE_TIMER specifies an unsupported timer"
#endif

#define ST_HANDLER                          SysTick_Handler

#if SYSTICK_CK % OSAL_ST_FREQUENCY != 0
#error "the selected ST frequency is not obtainable because integer rounding"
#endif

#if (SYSTICK_CK / OSAL_ST_FREQUENCY) - 1 > 0xFF
#error "the selected ST frequency is not obtainable because CT16 timer prescaler limits"
#endif

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC

#define ST_HANDLER                          SysTick_Handler

#if SYSTICK_CK % OSAL_ST_FREQUENCY != 0
#error "the selected ST frequency is not obtainable because integer rounding"
#endif

#if (SYSTICK_CK / OSAL_ST_FREQUENCY) - 1 > 0xFFFFFF
#error "the selected ST frequency is not obtainable because SysTick timer counter limits"
#endif

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

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

OSAL_IRQ_HANDLER(ST_HANDLER) {

  OSAL_IRQ_PROLOGUE();
  st_lld_serve_interrupt();
  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  /* Free running counter mode.*/

  /* Enabling timer clock.*/
  ST_ENABLE_CLOCK();
  ST_INIT_CLOCK();
  /* Initializing the counter in free running mode.*/
  SN32_ST_TIM->PRE    = (SYSTICK_CK / OSAL_ST_FREQUENCY) - 1;
  SN32_ST_TIM->TMRCTRL |= mskCT16_CEN_EN;

  /* Reset the SysTick timer. */
  SysTick->LOAD = 0;
  SysTick->VAL = 0;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk;
  SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;

  /* Configure the SysTick interrupt. */
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, SN32_ST_IRQ_PRIORITY);
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC

    /* Periodic systick mode, the Cortex-Mx internal systick timer is used
     in this mode.*/
  SysTick->LOAD = (SYSTICK_CK / OSAL_ST_FREQUENCY) - 1;
  SysTick->VAL = 0;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk |
                  SysTick_CTRL_TICKINT_Msk;

  /* IRQ enabled.*/
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, SN32_ST_IRQ_PRIORITY);
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */
}

/**
 * @brief   IRQ handling code.
 */
void st_lld_serve_interrupt(void) {
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  /* Disable the SysTick interrupt, but keep the timer running (the ENABLE bit
   * is used to store the state for st_lld_is_alarm_active(), which may be
   * checked by some debug assertions). */
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk;

  /* Clear any pending SysTick requests in case the IRQ handling was delayed so
   * much that the SysTick timer has wrapped again. */
  SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;
#endif
  {
    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
  }
}
#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

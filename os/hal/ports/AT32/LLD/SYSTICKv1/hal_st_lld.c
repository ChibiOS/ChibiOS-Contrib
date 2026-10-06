/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    ChibiOS - Copyright (C) 2023-2026 HorrorTroll.
    ChibiOS - Copyright (C) 2023-2026 Zhaqian.

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
 * @file    SYSTICKv1/hal_st_lld.c
 * @brief   ST Driver subsystem low level driver code.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING

#if (OSAL_ST_RESOLUTION != 16) && (OSAL_ST_RESOLUTION != 32)
#error "unsupported ST resolution"
#endif

#if (OSAL_ST_RESOLUTION == 32)
#define ST_PR_INIT                          0xFFFFFFFFU
#define ST_CTRL1_INIT                       0x00000400U
#else
#define ST_PR_INIT                          0x0000FFFFU
#define ST_CTRL1_INIT                       0x00000000U
#endif

#if AT32_ST_USE_TIMER == 1

#if !AT32_HAS_TMR1
#error "TMR1 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR1_IS_32BITS
#error "TMR1 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR1_CH_HANDLER
#define ST_NUMBER                           AT32_TMR1_CH_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR1(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR1_STOP()

#elif AT32_ST_USE_TIMER == 2

#if !AT32_HAS_TMR2
#error "TMR2 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR2_IS_32BITS
#error "TMR2 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR2_HANDLER
#define ST_NUMBER                           AT32_TMR2_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR2(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR2_STOP()

#elif AT32_ST_USE_TIMER == 3

#if !AT32_HAS_TMR3
#error "TMR3 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR3_IS_32BITS
#error "TMR3 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR3_HANDLER
#define ST_NUMBER                           AT32_TMR3_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR3(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR3_STOP()

#elif AT32_ST_USE_TIMER == 4

#if !AT32_HAS_TMR4
#error "TMR4 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR4_IS_32BITS
#error "TMR4 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR4_HANDLER
#define ST_NUMBER                           AT32_TMR4_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR4(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR4_STOP()

#elif AT32_ST_USE_TIMER == 5

#if !AT32_HAS_TMR5
#error "TMR5 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR5_IS_32BITS
#error "TMR5 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR5_HANDLER
#define ST_NUMBER                           AT32_TMR5_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR5(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR5_STOP()

#elif AT32_ST_USE_TIMER == 9

#if !AT32_HAS_TMR9
#error "TMR9 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR9_IS_32BITS
#error "TMR9 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR9_HANDLER
#define ST_NUMBER                           AT32_TMR9_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR9(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR9_STOP()

#elif AT32_ST_USE_TIMER == 10

#if !AT32_HAS_TMR10
#error "TMR10 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR10_IS_32BITS
#error "TMR10 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR10_HANDLER
#define ST_NUMBER                           AT32_TMR10_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR10(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR10_STOP()

#elif AT32_ST_USE_TIMER == 11

#if !AT32_HAS_TMR11
#error "TMR11 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR11_IS_32BITS
#error "TMR11 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR11_HANDLER
#define ST_NUMBER                           AT32_TMR11_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK2
#define ST_ENABLE_CLOCK()                   crmEnableTMR11(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR11_STOP()

#elif AT32_ST_USE_TIMER == 13

#if !AT32_HAS_TMR13
#error "TMR13 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR13_IS_32BITS
#error "TMR13 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR13_HANDLER
#define ST_NUMBER                           AT32_TMR13_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR13(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR13_STOP()

#elif AT32_ST_USE_TIMER == 14

#if !AT32_HAS_TMR14
#error "TMR14 not present in the selected device"
#endif

#if (OSAL_ST_RESOLUTION == 32) && !AT32_TMR14_IS_32BITS
#error "TMR14 is not a 32bits timer"
#endif

#define ST_HANDLER                          AT32_TMR14_HANDLER
#define ST_NUMBER                           AT32_TMR14_NUMBER
#define ST_CLOCK_SRC                        AT32_TMRCLK1
#define ST_ENABLE_CLOCK()                   crmEnableTMR14(true)
#define ST_ENABLE_PAUSE()                   AT32_DEBUG_TMR14_STOP()

#else
#error "AT32_ST_USE_TIMER specifies an unsupported timer"
#endif

/* Free running prescaler rounded to the nearest integer, the resulting tick
   frequency and its absolute deviation from OSAL_ST_FREQUENCY. These are
   expressions only (no objects): they fold to constants on static-clock
   devices and, where used solely inside osalDbgAssert(), they fully vanish
   when assertions are disabled.*/
#define ST_PSC          ((((halfreq_t)ST_CLOCK_SRC +                         \
                           ((halfreq_t)OSAL_ST_FREQUENCY / 2U)) /            \
                          (halfreq_t)OSAL_ST_FREQUENCY) - 1U)
#define ST_TICK         ((halfreq_t)ST_CLOCK_SRC / (ST_PSC + 1U))
#define ST_TICK_ERROR   ((ST_TICK >= (halfreq_t)OSAL_ST_FREQUENCY) ?         \
                         (ST_TICK - (halfreq_t)OSAL_ST_FREQUENCY) :          \
                         ((halfreq_t)OSAL_ST_FREQUENCY - ST_TICK))

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC

#define ST_HANDLER                          SysTick_Handler

#if defined(AT32_CORE_CK)
#define SYSTICK_CK                          AT32_CORE_CK
#else
#define SYSTICK_CK                          AT32_HCLK
#endif

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

#if !defined(AT32_SYSTICK_SUPPRESS_ISR)
/**
 * @brief   Interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(ST_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  st_lld_serve_interrupt();

  OSAL_IRQ_EPILOGUE();
}
#endif

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
  /* Free running counter mode. The prescaler is rounded to the nearest
     integer; the resulting tick frequency is required to be within
     AT32_ST_FREQUENCY_TOLERANCE per-mille of OSAL_ST_FREQUENCY (a tolerance
     of zero, the default, requires an exact integer divisor). The checks are
     pure expressions confined to the assertions, so they leave no code
     when assertions are disabled.*/
  osalDbgAssert(ST_PSC < 0x10000U, "clock prescaler overflow");
  osalDbgAssert((ST_TICK_ERROR * 1000U) <= ((halfreq_t)OSAL_ST_FREQUENCY *
                                            (halfreq_t)AT32_ST_FREQUENCY_TOLERANCE),
                "clock rounding error");

  /* Enabling timer clock.*/
  ST_ENABLE_CLOCK();

  /* Enabling the pause mode during debug for this timer.*/
  ST_ENABLE_PAUSE();

  /* Initializing the counter in free running mode.*/
  AT32_ST_TMR->CTRL1  = ST_CTRL1_INIT;
  AT32_ST_TMR->DIV    = (uint32_t)ST_PSC;
  AT32_ST_TMR->PR     = ST_PR_INIT;
  AT32_ST_TMR->CM1    = 0;
  AT32_ST_TMR->CDT[0] = 0;
#if ST_LLD_NUM_ALARMS > 1
  AT32_ST_TMR->CDT[1] = 0;
#endif
#if ST_LLD_NUM_ALARMS > 2
  AT32_ST_TMR->CDT[2] = 0;
#endif
#if ST_LLD_NUM_ALARMS > 3
  AT32_ST_TMR->CDT[3] = 0;
#endif
  AT32_ST_TMR->IDEN   = 0;
  AT32_ST_TMR->CTRL2  = 0;
  AT32_ST_TMR->SWEVT  = AT32_TMR_SWEVT_OVFSWTR;
  AT32_ST_TMR->CTRL1 |= AT32_TMR_CTRL1_TMREN;

#if !defined(AT32_SYSTICK_SUPPRESS_ISR)
  /* IRQ enabled.*/
  nvicEnableVector(ST_NUMBER, AT32_ST_IRQ_PRIORITY);
#endif
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
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, AT32_ST_IRQ_PRIORITY);
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */
}

/**
 * @brief   IRQ handling code.
 */
void st_lld_serve_interrupt(void) {
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  uint32_t ists;
  at32_tmr_t *timp = AT32_ST_TMR;

  ists  = timp->ISTS;
  ists &= timp->IDEN & AT32_TMR_IDEN_IRQ_MASK;
  timp->ISTS = ~ists;

  if ((ists & AT32_TMR_ISTS_C1IF) != 0U)
#endif
  {
    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
  }
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
#if ST_LLD_NUM_ALARMS > 1
  if ((ists & AT32_TMR_ISTS_C2IF) != 0U) {
    if (st_callbacks[1] != NULL) {
      st_callbacks[1](1U);
    }
  }
#endif
#if ST_LLD_NUM_ALARMS > 2
  if ((ists & AT32_TMR_ISTS_C3IF) != 0U) {
    if (st_callbacks[2] != NULL) {
      st_callbacks[2](2U);
    }
  }
#endif
#if ST_LLD_NUM_ALARMS > 3
  if ((ists & AT32_TMR_ISTS_C4IF) != 0U) {
    if (st_callbacks[3] != NULL) {
      st_callbacks[3](3U);
    }
  }
#endif
#endif
}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

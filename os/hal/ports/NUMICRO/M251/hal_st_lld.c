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

#include "M251/stddriver/clk.h"

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

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)

/**
 * @brief   Returns the input clock of the selected TIMER PWM counter.
 *
 * @return              The TIMER PWM input clock in Hz.
 *
 * @notapi
 */
static uint32_t st_lld_get_timer_clock(void) {
  uint32_t divider;

#if M251_ST_USE_TIMER < 2
  divider = (CLK->PCLKDIV & CLK_PCLKDIV_APB0DIV_Msk) >>
            CLK_PCLKDIV_APB0DIV_Pos;
#else
  divider = (CLK->PCLKDIV & CLK_PCLKDIV_APB1DIV_Msk) >>
            CLK_PCLKDIV_APB1DIV_Pos;
#endif

  if (divider > 5U) {
    osalSysHalt("invalid ST PCLK divider");
  }

  return SystemCoreClock >> divider;
}

/**
 * @brief   TIMER interrupt handler.
 * @details This interrupt is used for system alarms in free-running mode.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_ST_TIMER_HANDLER) {
  uint32_t status;

  OSAL_IRQ_PROLOGUE();

  status = M251_ST_TIM->PWMINTSTS0 & M251_ST_TIM->PWMINTEN0;
  status &= TIMER_PWMINTSTS0_PIF_Msk | TIMER_PWMINTSTS0_CMPUIF_Msk;
  M251_ST_TIM->PWMINTSTS0 = status;

  if (status != 0U) {
    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
  }

  OSAL_IRQ_EPILOGUE();
}

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  uint32_t clock_mask;
  uint32_t clock_select;
  uint32_t clock_select_mask;
  uint32_t counter_divider;
  uint32_t reset_mask;
  uint32_t timer_clock;

#if M251_ST_USE_TIMER == 0
  clock_mask = CLK_APBCLK0_TMR0CKEN_Msk;
  clock_select = CLK_CLKSEL1_TMR0SEL_PCLK0;
  clock_select_mask = CLK_CLKSEL1_TMR0SEL_Msk;
  reset_mask = SYS_IPRST1_TMR0RST_Msk;
#elif M251_ST_USE_TIMER == 1
  clock_mask = CLK_APBCLK0_TMR1CKEN_Msk;
  clock_select = CLK_CLKSEL1_TMR1SEL_PCLK0;
  clock_select_mask = CLK_CLKSEL1_TMR1SEL_Msk;
  reset_mask = SYS_IPRST1_TMR1RST_Msk;
#elif M251_ST_USE_TIMER == 2
  clock_mask = CLK_APBCLK0_TMR2CKEN_Msk;
  clock_select = CLK_CLKSEL1_TMR2SEL_PCLK1;
  clock_select_mask = CLK_CLKSEL1_TMR2SEL_Msk;
  reset_mask = SYS_IPRST1_TMR2RST_Msk;
#else
  clock_mask = CLK_APBCLK0_TMR3CKEN_Msk;
  clock_select = CLK_CLKSEL1_TMR3SEL_PCLK1;
  clock_select_mask = CLK_CLKSEL1_TMR3SEL_Msk;
  reset_mask = SYS_IPRST1_TMR3RST_Msk;
#endif

  m251_lld_unlock();
  CLK->APBCLK0 |= clock_mask;
  CLK->CLKSEL1 = (CLK->CLKSEL1 & ~clock_select_mask) | clock_select;
  SYS->IPRST1 |= reset_mask;
  SYS->IPRST1 &= ~reset_mask;
  m251_lld_lock();

  timer_clock = st_lld_get_timer_clock();
  if ((timer_clock < OSAL_ST_FREQUENCY) ||
      ((timer_clock % OSAL_ST_FREQUENCY) != 0U)) {
    osalSysHalt("ST frequency not obtainable");
  }

  counter_divider = timer_clock / OSAL_ST_FREQUENCY;
  if (counter_divider > 256U) {
    osalSysHalt("ST frequency not obtainable");
  }

  M251_ST_TIM->CTL = TIMER_CTL_FUNCSEL_Msk;
  M251_ST_TIM->PWMCTL = 0U;
  M251_ST_TIM->PWMCLKPSC = counter_divider - 1U;
  M251_ST_TIM->PWMPERIOD = 0xFFFFU;
  M251_ST_TIM->PWMCMPDAT = 0U;
  M251_ST_TIM->PWMPOCTL = 0U;
  M251_ST_TIM->PWMINTEN0 = 0U;
  M251_ST_TIM->PWMINTSTS0 = TIMER_PWMINTSTS0_PIF_Msk |
                            TIMER_PWMINTSTS0_CMPUIF_Msk;
  M251_ST_TIM->PWMCNTCLR = TIMER_PWMCNTCLR_CNTCLR_Msk;
  M251_ST_TIM->PWMCTL = TIMER_PWMCTL_CNTEN_Msk;

  nvicEnableVector(M251_ST_TIMER_NUMBER, M251_ST_IRQ_PRIORITY);
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

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

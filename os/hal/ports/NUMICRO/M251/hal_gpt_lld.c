/*
    Copyright (C) 2024 Hansem Ro <hansemro@outlook.com>
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
 * @file    M251/hal_gpt_lld.c
 * @brief   M251/M252 GPT subsystem low level driver source.
 *
 * @addtogroup GPT
 * @{
 */

#include "hal.h"

#if (HAL_USE_GPT == TRUE) || defined(__DOXYGEN__)

#include "m251_isr.h"
#include "M251/stddriver/clk.h"
#include "M251/stddriver/timer.h"

static uint32_t _gpt_get_pclk0(void) {
  uint32_t div = (CLK->PCLKDIV & CLK_PCLKDIV_APB0DIV_Msk) >>
                  CLK_PCLKDIV_APB0DIV_Pos;
  return SystemCoreClock >> div;
}

#if (M251_GPT_USE_TMR2 == TRUE) || (M251_GPT_USE_TMR3 == TRUE)
static uint32_t _gpt_get_pclk1(void) {
  uint32_t div = (CLK->PCLKDIV & CLK_PCLKDIV_APB1DIV_Msk) >>
                  CLK_PCLKDIV_APB1DIV_Pos;
  return SystemCoreClock >> div;
}
#endif

static uint32_t _gpt_ticks_to_counts(const GPTDriver *gptp,
                                     gptcnt_t interval) {
  uint64_t numerator = (uint64_t)gptp->clock * interval;
  uint64_t denominator = (uint64_t)gptp->config->frequency *
                         ((uint64_t)gptp->psc + 1U);
  uint32_t counts = (uint32_t)((numerator + denominator / 2U) / denominator);

  if (counts > 0xFFFFFFU) {
    counts = 0xFFFFFFU;
  }
  if (counts < 2U) {
    counts = 2U;
  }

  return counts;
}

static gptcnt_t _gpt_counts_to_ticks(const GPTDriver *gptp,
                                     uint32_t counts) {
  uint64_t numerator = (uint64_t)counts * gptp->config->frequency *
                       ((uint64_t)gptp->psc + 1U);

  return (gptcnt_t)((numerator + gptp->clock / 2U) / gptp->clock);
}

static void _gpt_lld_start_hw(GPTDriver *gptp) {
  uint32_t psc = 0U;
  uint32_t clock = gptp->clock;
  uint32_t freq  = gptp->config->frequency;

  osalDbgAssert((freq > 0U) && (freq <= (clock / 2U)),
                "GPT frequency out of range");

  if (freq >= clock) {
    psc = 0U;
  }
  else {
    /* Upper bound: CMP >= 2 requires tick >= freq * 2.*/
    uint32_t max_psc = clock / (freq * 2U);
    if (max_psc > 0U) {
      max_psc--;
    }
    if (max_psc > 255U) {
      max_psc = 255U;
    }

    /* Search for smallest valid PSC, giving the largest CMP.*/
    psc = 255U;
    for (uint32_t p = 0U; p <= max_psc; p++) {
      uint64_t cmp = (uint64_t)clock / ((uint64_t)(p + 1U) * (uint64_t)freq);
      if (cmp <= 0xFFFFFFUL) {
        psc = p;
        break;
      }
    }
  }

  gptp->psc = (uint8_t)psc;
  gptp->tim->CTL = TIMER_PERIODIC_MODE | ((uint32_t)gptp->psc << TIMER_CTL_PSC_Pos);
}

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   GPTD1 (TIMER0) driver identifier.
 */
#if (M251_GPT_USE_TMR0 == TRUE) || defined(__DOXYGEN__)
GPTDriver GPTD1;
#endif

/**
 * @brief   GPTD2 (TIMER1) driver identifier.
 */
#if (M251_GPT_USE_TMR1 == TRUE) || defined(__DOXYGEN__)
GPTDriver GPTD2;
#endif

/**
 * @brief   GPTD3 (TIMER2) driver identifier.
 */
#if (M251_GPT_USE_TMR2 == TRUE) || defined(__DOXYGEN__)
GPTDriver GPTD3;
#endif

/**
 * @brief   GPTD4 (TIMER3) driver identifier.
 */
#if (M251_GPT_USE_TMR3 == TRUE) || defined(__DOXYGEN__)
GPTDriver GPTD4;
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level GPT driver initialization.
 *
 * @notapi
 */
void gpt_lld_init(void) {

#if (M251_GPT_USE_TMR0 == TRUE)
  GPTD1.state  = GPT_UNINIT;
  GPTD1.config = NULL;
  GPTD1.tim    = TIMER0;
  GPTD1.clock  = 0U;
  gptObjectInit(&GPTD1);
#endif

#if (M251_GPT_USE_TMR1 == TRUE)
  GPTD2.state  = GPT_UNINIT;
  GPTD2.config = NULL;
  GPTD2.tim    = TIMER1;
  GPTD2.clock  = 0U;
  gptObjectInit(&GPTD2);
#endif

#if (M251_GPT_USE_TMR2 == TRUE)
  GPTD3.state  = GPT_UNINIT;
  GPTD3.config = NULL;
  GPTD3.tim    = TIMER2;
  GPTD3.clock  = 0U;
  gptObjectInit(&GPTD3);
#endif

#if (M251_GPT_USE_TMR3 == TRUE)
  GPTD4.state  = GPT_UNINIT;
  GPTD4.config = NULL;
  GPTD4.tim    = TIMER3;
  GPTD4.clock  = 0U;
  gptObjectInit(&GPTD4);
#endif
}

/**
 * @brief   Configures and activates the GPT peripheral.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_start(GPTDriver *gptp) {

  if (gptp->state == GPT_STOP) {
#if (M251_GPT_USE_TMR0 == TRUE)
    if (gptp == &GPTD1) {
      m251_lld_unlock();
      CLK->APBCLK0 |= CLK_APBCLK0_TMR0CKEN_Msk;
      CLK->CLKSEL1 = (CLK->CLKSEL1 & ~CLK_CLKSEL1_TMR0SEL_Msk) |
                      CLK_CLKSEL1_TMR0SEL_PCLK0;
      m251_lld_lock();
      nvicEnableVector(M251_TMR0_NUMBER, M251_GPT_TMR0_IRQ_PRIORITY);
      gptp->clock = _gpt_get_pclk0();
    }
#endif
#if (M251_GPT_USE_TMR1 == TRUE)
    if (gptp == &GPTD2) {
      m251_lld_unlock();
      CLK->APBCLK0 |= CLK_APBCLK0_TMR1CKEN_Msk;
      CLK->CLKSEL1 = (CLK->CLKSEL1 & ~CLK_CLKSEL1_TMR1SEL_Msk) |
                      CLK_CLKSEL1_TMR1SEL_PCLK0;
      m251_lld_lock();
      nvicEnableVector(M251_TMR1_NUMBER, M251_GPT_TMR1_IRQ_PRIORITY);
      gptp->clock = _gpt_get_pclk0();
    }
#endif
#if (M251_GPT_USE_TMR2 == TRUE)
    if (gptp == &GPTD3) {
      m251_lld_unlock();
      CLK->APBCLK0 |= CLK_APBCLK0_TMR2CKEN_Msk;
      CLK->CLKSEL1 = (CLK->CLKSEL1 & ~CLK_CLKSEL1_TMR2SEL_Msk) |
                      CLK_CLKSEL1_TMR2SEL_PCLK1;
      m251_lld_lock();
      nvicEnableVector(M251_TMR2_NUMBER, M251_GPT_TMR2_IRQ_PRIORITY);
      gptp->clock = _gpt_get_pclk1();
    }
#endif
#if (M251_GPT_USE_TMR3 == TRUE)
    if (gptp == &GPTD4) {
      m251_lld_unlock();
      CLK->APBCLK0 |= CLK_APBCLK0_TMR3CKEN_Msk;
      CLK->CLKSEL1 = (CLK->CLKSEL1 & ~CLK_CLKSEL1_TMR3SEL_Msk) |
                      CLK_CLKSEL1_TMR3SEL_PCLK1;
      m251_lld_lock();
      nvicEnableVector(M251_TMR3_NUMBER, M251_GPT_TMR3_IRQ_PRIORITY);
      gptp->clock = _gpt_get_pclk1();
    }
#endif
  }

  _gpt_lld_start_hw(gptp);
}

/**
 * @brief   Deactivates the GPT peripheral.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop(GPTDriver *gptp) {

  if (gptp->state == GPT_READY) {
    gptp->tim->CTL = 0U;
    gptp->tim->INTSTS = TIMER_INTSTS_TIF_Msk;
    gptp->psc = 0U;

#if (M251_GPT_USE_TMR0 == TRUE)
    if (gptp == &GPTD1) {
      nvicDisableVector(M251_TMR0_NUMBER);
      m251_lld_unlock();
      CLK->APBCLK0 &= ~CLK_APBCLK0_TMR0CKEN_Msk;
      m251_lld_lock();
    }
#endif
#if (M251_GPT_USE_TMR1 == TRUE)
    if (gptp == &GPTD2) {
      nvicDisableVector(M251_TMR1_NUMBER);
      m251_lld_unlock();
      CLK->APBCLK0 &= ~CLK_APBCLK0_TMR1CKEN_Msk;
      m251_lld_lock();
    }
#endif
#if (M251_GPT_USE_TMR2 == TRUE)
    if (gptp == &GPTD3) {
      nvicDisableVector(M251_TMR2_NUMBER);
      m251_lld_unlock();
      CLK->APBCLK0 &= ~CLK_APBCLK0_TMR2CKEN_Msk;
      m251_lld_lock();
    }
#endif
#if (M251_GPT_USE_TMR3 == TRUE)
    if (gptp == &GPTD4) {
      nvicDisableVector(M251_TMR3_NUMBER);
      m251_lld_unlock();
      CLK->APBCLK0 &= ~CLK_APBCLK0_TMR3CKEN_Msk;
      m251_lld_lock();
    }
#endif
  }
}

/**
 * @brief   Starts the timer in continuous mode.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @param[in] interval  period in ticks
 *
 * @notapi
 */
void gpt_lld_start_timer(GPTDriver *gptp, gptcnt_t interval) {
  uint32_t cmp;

  cmp = _gpt_ticks_to_counts(gptp, interval);

  gptp->tim->CMP = cmp;
  gptp->tim->INTSTS = TIMER_INTSTS_TIF_Msk;
  gptp->tim->CTL = TIMER_PERIODIC_MODE | ((uint32_t)gptp->psc << TIMER_CTL_PSC_Pos) |
                   TIMER_CTL_INTEN_Msk | TIMER_CTL_CNTEN_Msk;
}

/**
 * @brief   Stops the timer.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop_timer(GPTDriver *gptp) {

  gptp->tim->CTL &= ~(TIMER_CTL_INTEN_Msk | TIMER_CTL_CNTEN_Msk);
  gptp->tim->INTSTS = TIMER_INTSTS_TIF_Msk;
}

/**
 * @brief   Starts the timer in one-shot mode and waits for completion.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @param[in] interval  time interval in ticks
 *
 * @notapi
 */
void gpt_lld_polled_delay(GPTDriver *gptp, gptcnt_t interval) {
  uint32_t cmp;

  cmp = _gpt_ticks_to_counts(gptp, interval);

  gptp->tim->CTL = TIMER_ONESHOT_MODE | ((uint32_t)gptp->psc << TIMER_CTL_PSC_Pos);
  gptp->tim->CMP = cmp;
  gptp->tim->INTSTS = TIMER_INTSTS_TIF_Msk;
  gptp->tim->CTL |= TIMER_CTL_CNTEN_Msk;

  while ((gptp->tim->INTSTS & TIMER_INTSTS_TIF_Msk) == 0U) {}

  gptp->tim->CTL = 0U;
  gptp->tim->INTSTS = TIMER_INTSTS_TIF_Msk;
}

/**
 * @brief   Changes the timer interval.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @param[in] interval  new interval in ticks
 *
 * @notapi
 */
void gpt_lld_change_interval(GPTDriver *gptp, gptcnt_t interval) {
  gptp->tim->CMP = _gpt_ticks_to_counts(gptp, interval);
}

/**
 * @brief   Returns the programmed timer interval.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The interval in ticks.
 *
 * @notapi
 */
gptcnt_t gpt_lld_get_interval(GPTDriver *gptp) {
  return _gpt_counts_to_ticks(gptp, gptp->tim->CMP);
}

/**
 * @brief   Returns the current timer counter value.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 * @return              The counter value in ticks.
 *
 * @notapi
 */
gptcnt_t gpt_lld_get_counter(GPTDriver *gptp) {
  return _gpt_counts_to_ticks(gptp, gptp->tim->CNT);
}

/**
 * @brief   Serves a GPT interrupt.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_serve_interrupt(GPTDriver *gptp) {

  gptp->tim->INTSTS = TIMER_INTSTS_TIF_Msk;
  _gpt_isr_invoke_cb(gptp);
}

#if (M251_GPT_USE_TMR0 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   TMR0 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_TMR0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  gpt_lld_serve_interrupt(&GPTD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if (M251_GPT_USE_TMR1 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   TMR1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_TMR1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  gpt_lld_serve_interrupt(&GPTD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if (M251_GPT_USE_TMR2 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   TMR2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_TMR2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  gpt_lld_serve_interrupt(&GPTD3);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if (M251_GPT_USE_TMR3 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   TMR3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_TMR3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  gpt_lld_serve_interrupt(&GPTD4);
  OSAL_IRQ_EPILOGUE();
}
#endif

#endif /* HAL_USE_GPT == TRUE */

/** @} */

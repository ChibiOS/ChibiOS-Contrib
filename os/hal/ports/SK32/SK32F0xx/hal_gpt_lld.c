/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_gpt_lld.c
 * @brief   SK32F0xx GPT subsystem low level driver source.
 *
 * @addtogroup GPT
 * @{
 */

#include "hal.h"

#if HAL_USE_GPT || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   GPTD3 driver identifier.
 * @note    The driver GPTD3 allocates the general purpose timer TIM3
 *          (APB1 clock domain) when enabled.
 */
#if SK32_GPT_USE_TIM3 || defined(__DOXYGEN__)
GPTDriver GPTD3;
#endif

/**
 * @brief   GPTD16 driver identifier.
 * @note    The driver GPTD16 allocates the general purpose timer TIM16
 *          (APB2 clock domain) when enabled.
 */
#if SK32_GPT_USE_TIM16 || defined(__DOXYGEN__)
GPTDriver GPTD16;
#endif

/**
 * @brief   GPTD17 driver identifier.
 * @note    The driver GPTD17 allocates the general purpose timer TIM17
 *          (APB2 clock domain) when enabled.
 */
#if SK32_GPT_USE_TIM17 || defined(__DOXYGEN__)
GPTDriver GPTD17;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SK32_GPT_USE_TIM3 || defined(__DOXYGEN__)
#if !defined(SK32_TIM3_SUPPRESS_ISR)
#if !defined(SK32_TIM3_HANDLER)
#error "SK32_TIM3_HANDLER not defined"
#endif
/**
 * @brief   TIM3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_TIM3_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD3);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SK32_TIM3_SUPPRESS_ISR) */
#endif /* SK32_GPT_USE_TIM3 */

#if SK32_GPT_USE_TIM16 || defined(__DOXYGEN__)
#if !defined(SK32_TIM16_SUPPRESS_ISR)
#if !defined(SK32_TIM16_HANDLER)
#error "SK32_TIM16_HANDLER not defined"
#endif
/**
 * @brief   TIM16 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_TIM16_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD16);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SK32_TIM16_SUPPRESS_ISR) */
#endif /* SK32_GPT_USE_TIM16 */

#if SK32_GPT_USE_TIM17 || defined(__DOXYGEN__)
#if !defined(SK32_TIM17_SUPPRESS_ISR)
#if !defined(SK32_TIM17_HANDLER)
#error "SK32_TIM17_HANDLER not defined"
#endif
/**
 * @brief   TIM17 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_TIM17_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD17);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SK32_TIM17_SUPPRESS_ISR) */
#endif /* SK32_GPT_USE_TIM17 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level GPT driver initialization.
 *
 * @notapi
 */
void gpt_lld_init(void) {

#if SK32_GPT_USE_TIM3
  /* Driver initialization.*/
  GPTD3.tim = TIM3;
  gptObjectInit(&GPTD3);
#endif

#if SK32_GPT_USE_TIM16
  /* Driver initialization.*/
  GPTD16.tim = TIM16;
  gptObjectInit(&GPTD16);
#endif

#if SK32_GPT_USE_TIM17
  /* Driver initialization.*/
  GPTD17.tim = TIM17;
  gptObjectInit(&GPTD17);
#endif
}

/**
 * @brief   Configures and activates the GPT peripheral.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_start(GPTDriver *gptp) {
  uint16_t psc;

  if (gptp->state == GPT_STOP) {
    /* Clock activation.*/
#if SK32_GPT_USE_TIM3
    if (&GPTD3 == gptp) {
      rccEnableTIM3(true);
      rccResetTIM3();
#if !defined(SK32_TIM3_SUPPRESS_ISR)
      nvicEnableVector(SK32_TIM3_NUMBER, SK32_GPT_TIM3_IRQ_PRIORITY);
#endif
      gptp->clock = SK32_TIMCLK1;
    }
#endif

#if SK32_GPT_USE_TIM16
    if (&GPTD16 == gptp) {
      rccEnableTIM16(true);
      rccResetTIM16();
#if !defined(SK32_TIM16_SUPPRESS_ISR)
      nvicEnableVector(SK32_TIM16_NUMBER, SK32_GPT_TIM16_IRQ_PRIORITY);
#endif
      gptp->clock = SK32_TIMCLK2;
    }
#endif

#if SK32_GPT_USE_TIM17
    if (&GPTD17 == gptp) {
      rccEnableTIM17(true);
      rccResetTIM17();
#if !defined(SK32_TIM17_SUPPRESS_ISR)
      nvicEnableVector(SK32_TIM17_NUMBER, SK32_GPT_TIM17_IRQ_PRIORITY);
#endif
      gptp->clock = SK32_TIMCLK2;
    }
#endif
  }

  /* Prescaler value calculation.*/
  psc = (uint16_t)((gptp->clock / gptp->config->frequency) - 1U);
  osalDbgAssert(((uint32_t)(psc + 1U) * gptp->config->frequency) ==
                gptp->clock, "invalid frequency");

  /* Timer configuration.*/
  gptp->tim->CR1  = 0U;                         /* Initially stopped.       */
  gptp->tim->CR2  = gptp->config->cr2;
  gptp->tim->PSC  = psc;                        /* Prescaler value.         */
  gptp->tim->SR   = 0U;                         /* Clear pending IRQs.      */
  gptp->tim->DIER = gptp->config->dier &        /* DMA-related DIER bits.   */
                    ~SK32_TIM_DIER_IRQ_MASK;
}

/**
 * @brief   Deactivates the GPT peripheral.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop(GPTDriver *gptp) {

  if (gptp->state == GPT_READY) {
    gptp->tim->CR1  = 0U;                       /* Timer disabled.          */
    gptp->tim->DIER = 0U;                       /* All IRQs disabled.       */
    gptp->tim->SR   = 0U;                       /* Clear pending IRQs.      */

#if SK32_GPT_USE_TIM3
    if (&GPTD3 == gptp) {
#if !defined(SK32_TIM3_SUPPRESS_ISR)
      nvicDisableVector(SK32_TIM3_NUMBER);
#endif
      rccDisableTIM3();
    }
#endif

#if SK32_GPT_USE_TIM16
    if (&GPTD16 == gptp) {
#if !defined(SK32_TIM16_SUPPRESS_ISR)
      nvicDisableVector(SK32_TIM16_NUMBER);
#endif
      rccDisableTIM16();
    }
#endif

#if SK32_GPT_USE_TIM17
    if (&GPTD17 == gptp) {
#if !defined(SK32_TIM17_SUPPRESS_ISR)
      nvicDisableVector(SK32_TIM17_NUMBER);
#endif
      rccDisableTIM17();
    }
#endif
  }
}

/**
 * @brief   Starts the timer in continuous mode.
 * @note    Interval values 0 and 1 are invalid on this architecture.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 * @param[in] interval  period in ticks
 *
 * @notapi
 */
void gpt_lld_start_timer(GPTDriver *gptp, gptcnt_t interval) {

  osalDbgAssert(interval > (gptcnt_t)0, "invalid interval");

  gptp->tim->ARR = (uint32_t)(interval - 1U);   /* Time constant.           */
  gptp->tim->EGR = TIM_EGR_UG;                  /* Update event.            */
  gptp->tim->CNT = 0U;                          /* Reset counter.           */

  /* NOTE: After generating the UG event it takes several clock cycles before
     SR bit 0 goes to 1. This is why the clearing of CNT has been inserted
     before the clearing of SR, to give it some time.*/
  gptp->tim->SR  = 0U;                          /* Clear pending IRQs.      */
  if (NULL != gptp->config->callback)
    gptp->tim->DIER |= TIM_DIER_UIE;            /* Update Event IRQ enabled.*/
  gptp->tim->CR1 = TIM_CR1_ARPE | TIM_CR1_URS | TIM_CR1_CEN;
}

/**
 * @brief   Stops the timer.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop_timer(GPTDriver *gptp) {

  gptp->tim->CR1 = 0U;                          /* Initially stopped.       */
  gptp->tim->SR  = 0U;                          /* Clear pending IRQs.      */

  /* All interrupts disabled.*/
  gptp->tim->DIER &= ~SK32_TIM_DIER_IRQ_MASK;
}

/**
 * @brief   Starts the timer in one shot mode and waits for completion.
 * @details This function specifically polls the timer waiting for completion
 *          in order to not have extra delays caused by interrupt servicing,
 *          this function is only recommended for short delays.
 * @note    Interval values 0 and 1 are invalid on this architecture.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 * @param[in] interval  time interval in ticks
 *
 * @notapi
 */
void gpt_lld_polled_delay(GPTDriver *gptp, gptcnt_t interval) {

  osalDbgAssert(interval > (gptcnt_t)0, "invalid interval");

  gptp->tim->CR1 = TIM_CR1_UDIS;                /* Immediate update.        */
  gptp->tim->ARR = (uint32_t)(interval - 1U);   /* Time constant.           */
  gptp->tim->EGR = TIM_EGR_UG;                  /* Update event.            */
  gptp->tim->SR  = 0U;                          /* Clear pending IRQs.      */
  gptp->tim->CR1 = TIM_CR1_OPM | TIM_CR1_URS | TIM_CR1_CEN;
  while (!(gptp->tim->SR & TIM_SR_UIF))
    ;
  gptp->tim->SR = 0U;                           /* Clear pending IRQs.      */
}

/**
 * @brief   Shared IRQ handler.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_serve_interrupt(GPTDriver *gptp) {
  uint32_t sr;

  sr  = gptp->tim->SR;
  sr &= gptp->tim->DIER & SK32_TIM_DIER_IRQ_MASK;
  gptp->tim->SR = ~sr;
  if ((sr & TIM_SR_UIF) != 0) {
    _gpt_isr_invoke_cb(gptp);
  }
}

#endif /* HAL_USE_GPT */

/** @} */

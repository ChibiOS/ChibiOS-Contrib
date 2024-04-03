/*
    Copyright (C) 2024 Hansem Ro <hansemro@outlook.com>

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
 * @file    hal_gpt_lld.c
 * @brief   PLATFORM GPT subsystem low level driver source.
 *
 * @addtogroup GPT
 * @{
 */

#include "hal.h"

#if (HAL_USE_GPT == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define NUC123_TIMER_CLKSRC_HSE             0x0UL
#define NUC123_TIMER_CLKSRC_HCLK            0x2UL
#define NUC123_TIMER_CLKSRC_HSI             0x3UL
#define NUC123_TIMER_CLKSRC_LSI             0x7UL

#define NUC123_TIMER_TCSR_MODE_ONESHOT      0x0UL << TIMER_TCSR_MODE_Pos
#define NUC123_TIMER_TCSR_MODE_PERIODIC     0x1UL << TIMER_TCSR_MODE_Pos
#define NUC123_TIMER_TCSR_MODE_TOGGLEOUTPUT 0x2UL << TIMER_TCSR_MODE_Pos
#define NUC123_TIMER_TCSR_MODE_CONTINUOUS   0x3UL << TIMER_TCSR_MODE_Pos

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   GPTD0 (TIMER0) driver identifier.
 */
#if (NUC123_GPT_USE_TIMER0 == TRUE) || defined(__DOXYGEN__)
GPTDriver GPTD0;
#endif

/**
 * @brief   GPTD1 (TIMER1) driver identifier.
 */
#if (NUC123_GPT_USE_TIMER1 == TRUE) || defined(__DOXYGEN__)
GPTDriver GPTD1;
#endif

/**
 * @brief   GPTD2 (TIMER2) driver identifier.
 */
#if (NUC123_GPT_USE_TIMER2 == TRUE) || defined(__DOXYGEN__)
GPTDriver GPTD2;
#endif

/**
 * @brief   GPTD3 (TIMER3) driver identifier.
 */
#if (NUC123_GPT_USE_TIMER3 == TRUE) || defined(__DOXYGEN__)
GPTDriver GPTD3;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void gpt_lld_handler(GPTDriver *gptp) {
  if (gptp->TIMER->TISR & TIMER_TISR_TIF_Msk) {
    gptp->TIMER->TISR |= TIMER_TISR_TIF_Msk;
    if (gptp->config->callback)
      gptp->config->callback(gptp);
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (NUC123_GPT_USE_TIMER0 == TRUE) || defined(__DOXYGEN__)
OSAL_IRQ_HANDLER(NUC123_TIM1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  gpt_lld_handler(&GPTD0);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if (NUC123_GPT_USE_TIMER1 == TRUE) || defined(__DOXYGEN__)
OSAL_IRQ_HANDLER(NUC123_TIM2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  gpt_lld_handler(&GPTD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if (NUC123_GPT_USE_TIMER2 == TRUE) || defined(__DOXYGEN__)
OSAL_IRQ_HANDLER(NUC123_TIM3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  gpt_lld_handler(&GPTD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if (NUC123_GPT_USE_TIMER3 == TRUE) || defined(__DOXYGEN__)
OSAL_IRQ_HANDLER(NUC123_TIM4_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  gpt_lld_handler(&GPTD3);
  OSAL_IRQ_EPILOGUE();
}
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
  /* Driver initialization.*/
#if NUC123_GPT_USE_TIMER0 == TRUE
  gptObjectInit(&GPTD0);
  GPTD0.TIMER = TIMER0;
#endif
#if NUC123_GPT_USE_TIMER1 == TRUE
  gptObjectInit(&GPTD1);
  GPTD1.TIMER = TIMER1;
#endif
#if NUC123_GPT_USE_TIMER2 == TRUE
  gptObjectInit(&GPTD2);
  GPTD2.TIMER = TIMER2;
#endif
#if NUC123_GPT_USE_TIMER3 == TRUE
  gptObjectInit(&GPTD3);
  GPTD3.TIMER = TIMER3;
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
  uint32_t clksel1;
  if (gptp->state == GPT_STOP) {
    clksel1 = CLK->CLKSEL1;
    /* Enables the peripheral.*/
#if NUC123_GPT_USE_TIMER0 == TRUE
    if (&GPTD0 == gptp) {
      clksel1 &= (~CLK_CLKSEL1_TMR0_S_Msk) | (NUC123_TIMER_CLKSRC_HCLK << CLK_CLKSEL1_TMR0_S_Pos);
      CLK->APBCLK |= CLK_APBCLK_TMR0_EN_Msk;
      nvicEnableVector(NUC123_TIM1_NUMBER, NUC123_GPT_TIMER0_IRQ_PRIORITY);
    }
#endif
#if NUC123_GPT_USE_TIMER1 == TRUE
    if (&GPTD1 == gptp) {
      clksel1 &= (~CLK_CLKSEL1_TMR1_S_Msk) | (NUC123_TIMER_CLKSRC_HCLK << CLK_CLKSEL1_TMR1_S_Pos);
      CLK->APBCLK |= CLK_APBCLK_TMR1_EN_Msk;
      nvicEnableVector(NUC123_TIM2_NUMBER, NUC123_GPT_TIMER1_IRQ_PRIORITY);
    }
#endif
#if NUC123_GPT_USE_TIMER2 == TRUE
    if (&GPTD2 == gptp) {
      clksel1 &= (~CLK_CLKSEL1_TMR2_S_Msk) | (NUC123_TIMER_CLKSRC_HCLK << CLK_CLKSEL1_TMR2_S_Pos);
      CLK->APBCLK |= CLK_APBCLK_TMR2_EN_Msk;
      nvicEnableVector(NUC123_TIM3_NUMBER, NUC123_GPT_TIMER2_IRQ_PRIORITY);
    }
#endif
#if NUC123_GPT_USE_TIMER3 == TRUE
    if (&GPTD3 == gptp) {
      clksel1 &= (~CLK_CLKSEL1_TMR3_S_Msk) | (NUC123_TIMER_CLKSRC_HCLK << CLK_CLKSEL1_TMR3_S_Pos);
      CLK->APBCLK |= CLK_APBCLK_TMR3_EN_Msk;
      nvicEnableVector(NUC123_TIM4_NUMBER, NUC123_GPT_TIMER3_IRQ_PRIORITY);
    }
#endif
  }

  /* Configures the peripheral.*/
  gptp->TIMER->TCSR = 0;
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
    /* Resets the peripheral.*/
    /* Disables the peripheral.*/
#if NUC123_GPT_USE_TIMER0 == TRUE
    if (&GPTD0 == gptp) {
      SYS->IPRSTC2 |= SYS_IPRSTC2_TMR0_RST_Msk;
      SYS->IPRSTC2 &= ~SYS_IPRSTC2_TMR0_RST_Msk;
      CLK->APBCLK &= ~CLK_APBCLK_TMR0_EN_Msk;
      nvicDisableVector(NUC123_TIM1_NUMBER);
    }
#endif
#if NUC123_GPT_USE_TIMER1 == TRUE
    if (&GPTD1 == gptp) {
      SYS->IPRSTC2 |= SYS_IPRSTC2_TMR1_RST_Msk;
      SYS->IPRSTC2 &= ~SYS_IPRSTC2_TMR1_RST_Msk;
      CLK->APBCLK &= ~CLK_APBCLK_TMR1_EN_Msk;
      nvicDisableVector(NUC123_TIM2_NUMBER);
    }
#endif
#if NUC123_GPT_USE_TIMER2 == TRUE
    if (&GPTD2 == gptp) {
      SYS->IPRSTC2 |= SYS_IPRSTC2_TMR2_RST_Msk;
      SYS->IPRSTC2 &= ~SYS_IPRSTC2_TMR2_RST_Msk;
      CLK->APBCLK &= ~CLK_APBCLK_TMR2_EN_Msk;
      nvicDisableVector(NUC123_TIM3_NUMBER);
    }
#endif
#if NUC123_GPT_USE_TIMER3 == TRUE
    if (&GPTD3 == gptp) {
      SYS->IPRSTC2 |= SYS_IPRSTC2_TMR3_RST_Msk;
      SYS->IPRSTC2 &= ~SYS_IPRSTC2_TMR3_RST_Msk;
      CLK->APBCLK &= ~CLK_APBCLK_TMR3_EN_Msk;
      nvicDisableVector(NUC123_TIM4_NUMBER);
    }
#endif
  }
}

/**
 * @brief   Starts the timer in continuous mode.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 * @param[in] interval  period in ticks
 *
 * @notapi
 */
void gpt_lld_start_timer(GPTDriver *gptp, gptcnt_t interval) {
  gptp->TIMER->TISR = TIMER_TISR_TIF_Msk | TIMER_TISR_TWF_Msk;
  gptp->TIMER->TCMPR = ((NUC123_HCLK / gptp->config->frequency) * interval) & 0xFFFFFF;
  gptp->TIMER->TCSR = NUC123_TIMER_TCSR_MODE_PERIODIC | TIMER_TCSR_CRST_Msk |
                      TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk;
}

/**
 * @brief   Stops the timer.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop_timer(GPTDriver *gptp) {
  gptp->TIMER->TCSR &= (~TIMER_TCSR_CEN_Msk) | (~TIMER_TCSR_IE_Msk);
}

/**
 * @brief   Starts the timer in one shot mode and waits for completion.
 * @details This function specifically polls the timer waiting for completion
 *          in order to not have extra delays caused by interrupt servicing,
 *          this function is only recommended for short delays.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 * @param[in] interval  time interval in ticks
 *
 * @notapi
 */
void gpt_lld_polled_delay(GPTDriver *gptp, gptcnt_t interval) {
  gptp->TIMER->TISR = TIMER_TISR_TIF_Msk | TIMER_TISR_TWF_Msk;
  gptp->TIMER->TCMPR = ((NUC123_HCLK / gptp->config->frequency) * interval) & 0xFFFFFF;
  gptp->TIMER->TCSR = NUC123_TIMER_TCSR_MODE_ONESHOT | TIMER_TCSR_CRST_Msk |
                      TIMER_TCSR_TDR_EN_Msk | TIMER_TCSR_CEN_Msk | TIMER_TCSR_IE_Msk;
  while (!(gptp->TIMER->TISR & TIMER_TISR_TIF_Msk))
    ;
}

#endif /* HAL_USE_GPT == TRUE */

/** @} */

/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    CT/hal_gpt_lld.c
 * @brief   SN32 GPT subsystem low level driver source.
 *
 * @addtogroup GPT
 * @{
 */

#include "hal.h"

#if HAL_USE_GPT || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define GPT_CLK                          SN32_HCLK
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   GPTD1 driver identifier.
 * @note    The driver GPTD1 allocates the complex timer CT16B0 when enabled.
 */
#if SN32_GPT_USE_CT16B0 || defined(__DOXYGEN__)
GPTDriver GPTD1;
#endif

/**
 * @brief   GPTD2 driver identifier.
 * @note    The driver GPTD2 allocates the timer CT16B1 when enabled.
 */
#if SN32_GPT_USE_CT16B1 || defined(__DOXYGEN__)
GPTDriver GPTD2;
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

#if SN32_GPT_USE_CT16B0 || defined(__DOXYGEN__)
#if !defined(SN32_CT16B0_SUPPRESS_ISR)
#if !defined(SN32_CT16B0_HANDLER)
#error "SN32_CT16B0_HANDLER not defined"
#endif
/**
 * @brief   CT16B0 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_CT16B0_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SN32_CT16B0_SUPPRESS_ISR) */
#endif /* SN32_GPT_USE_CT16B0 */

#if SN32_GPT_USE_CT16B1 || defined(__DOXYGEN__)
#if !defined(SN32_CT16B1_SUPPRESS_ISR)
#if !defined(SN32_CT16B1_HANDLER)
#error "SN32_CT16B1_HANDLER not defined"
#endif
/**
 * @brief   CT16B1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_CT16B1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD2);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SN32_CT16B1_SUPPRESS_ISR) */
#endif /* SN32_GPT_USE_CT16B1 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level GPT driver initialization.
 *
 * @notapi
 */
void gpt_lld_init(void) {

#if SN32_GPT_USE_CT16B0
  /* Driver initialization.*/
  GPTD1.ct = SN32_CT16B0;
  gptObjectInit(&GPTD1);
#endif

#if SN32_GPT_USE_CT16B1
  /* Driver initialization.*/
  GPTD2.ct = SN32_CT16B1;
  gptObjectInit(&GPTD2);
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
#if SN32_GPT_USE_CT16B0
    if (&GPTD1 == gptp) {
      sys1EnableCT16B0();
      CT16B0_ResetTimer();
#if !defined(SN32_CT16B0_SUPPRESS_ISR)
      nvicEnableVector(SN32_CT16B0_NUMBER, SN32_GPT_CT16B0_IRQ_PRIORITY);
#endif
    gptp->clock = GPT_CLK;
    }
#endif

#if SN32_GPT_USE_CT16B1
    if (&GPTD2 == gptp) {
      sys1EnableCT16B1();
      CT16B1_ResetTimer();
#if !defined(SN32_CT16B1_SUPPRESS_ISR)
      nvicEnableVector(SN32_CT16B1_NUMBER, SN32_GPT_CT16B1_IRQ_PRIORITY);
#endif
    gptp->clock = GPT_CLK;
    }
#endif
  }
  else {
    /* Driver re-configuration scenario, it must be stopped first.*/
    gptp->ct->TMRCTRL = CT16_CEN_DIS;       /* Timer disabled.              */
#if SN32_GPT_USE_CT16B0
      if (&GPTD1 == gptp) {
        CT16B0_ResetTimer();                /* Counter reset to zero.       */
      }
#endif
#if SN32_GPT_USE_CT16B1
      if (&GPTD2 == gptp) {
        CT16B1_ResetTimer();                /* Counter reset to zero.       */
      }
#endif
  }

  /* Prescaler value calculation.*/
  psc = ((gptp->clock / gptp->config->frequency) - 1);
  osalDbgAssert((psc <= 0xFF) &&     /* Prescaler calculation.             */
                ((psc + 1) * gptp->config->frequency) == gptp->clock,
                "invalid frequency");

  /* Timer configuration.*/
  gptp->ct->CNTCTRL = gptp->config->cntctrl;
  gptp->ct->PRE  = psc;                        /* Prescaler value.         */
  gptp->ct->IC   &= 0x1FFFFFF;                 /* Clear pending IRQs.      */
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
    gptp->ct->TMRCTRL = CT16_CEN_DIS;          /* Timer disabled.          */
    gptp->ct->IC   &= 0x1FFFFFF;               /* Clear pending IRQs.      */

#if SN32_GPT_USE_CT16B0
    if (&GPTD1 == gptp) {
#if !defined(SN32_CT16B0_SUPPRESS_ISR)
      nvicDisableVector(SN32_CT16B0_NUMBER);
#endif
      sys1DisableCT16B0();
    }
#endif

#if SN32_GPT_USE_CT16B1
    if (&GPTD2 == gptp) {
#if !defined(SN32_CT16B1_SUPPRESS_ISR)
      nvicDisableVector(SN32_CT16B1_NUMBER);
#endif
      sys1DisableCT16B1();
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

  gptp->ct->MR0 = (uint32_t)(interval - 1U);  /* Time constant.           */
#if SN32_GPT_USE_CT16B0
      if (&GPTD1 == gptp) {
        CT16B0_ResetTimer();                  /* Counter reset to zero.   */
      }
#endif
#if SN32_GPT_USE_CT16B1
      if (&GPTD2 == gptp) {
        CT16B1_ResetTimer();                  /* Counter reset to zero.   */
      }
#endif
  gptp->ct->IC      &= 0x1FFFFFF;             /* Clear pending IRQs.      */
  if (NULL != gptp->config->callback)
    gptp->ct->MCTRL |= mskCT16_MR0IE_EN;
  gptp->ct->TMRCTRL |= mskCT16_CEN_EN;
}

/**
 * @brief   Stops the timer.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop_timer(GPTDriver *gptp) {

  gptp->ct->TMRCTRL = CT16_CEN_DIS;            /* Initially stopped.       */
  gptp->ct->IC      &= 0x1FFFFFF;              /* Clear pending IRQs.      */
  gptp->ct->MCTRL &= ~mskCT16_MR0IE_EN;        /* Disable the interrupt    */

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

  gptp->ct->MR0 = (uint32_t)(interval - 1U);   /* Time constant.           */
  gptp->ct->MCTRL = (mskCT16_MR0IE_EN | mskCT16_MR0STOP_EN);
  gptp->ct->IC &= 0x1FFFFFF;                   /* Clear pending IRQs.      */
  gptp->ct->TMRCTRL |= mskCT16_CEN_EN;
  while ((gptp->ct->RIS & mskCT16_MR0IF)!= 0)
    ;
  gptp->ct->IC &= 0x1FFFFFF;                   /* Clear pending IRQs.      */
}

/**
 * @brief   Shared IRQ handler.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_serve_interrupt(GPTDriver *gptp) {
  uint32_t ris;

  ris  = gptp->ct->RIS;
  gptp->ct->IC = ris;
  if ((ris & mskCT16_MR0IF) != 0)
    _gpt_isr_invoke_cb(gptp);
}

#endif /* HAL_USE_GPT */

/** @} */

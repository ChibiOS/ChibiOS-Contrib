/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    TMRv1/hal_gpt_lld.c
 * @brief   AT32 GPT subsystem low level driver source.
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
 * @brief   GPTD1 driver identifier.
 * @note    The driver GPTD1 allocates the complex timer TMR1 when enabled.
 */
#if AT32_GPT_USE_TMR1 || defined(__DOXYGEN__)
GPTDriver GPTD1;
#endif

/**
 * @brief   GPTD2 driver identifier.
 * @note    The driver GPTD2 allocates the timer TMR2 when enabled.
 */
#if AT32_GPT_USE_TMR2 || defined(__DOXYGEN__)
GPTDriver GPTD2;
#endif

/**
 * @brief   GPTD3 driver identifier.
 * @note    The driver GPTD3 allocates the timer TMR3 when enabled.
 */
#if AT32_GPT_USE_TMR3 || defined(__DOXYGEN__)
GPTDriver GPTD3;
#endif

/**
 * @brief   GPTD4 driver identifier.
 * @note    The driver GPTD4 allocates the timer TMR4 when enabled.
 */
#if AT32_GPT_USE_TMR4 || defined(__DOXYGEN__)
GPTDriver GPTD4;
#endif

/**
 * @brief   GPTD5 driver identifier.
 * @note    The driver GPTD5 allocates the timer TMR5 when enabled.
 */
#if AT32_GPT_USE_TMR5 || defined(__DOXYGEN__)
GPTDriver GPTD5;
#endif

/**
 * @brief   GPTD9 driver identifier.
 * @note    The driver GPTD9 allocates the timer TMR9 when enabled.
 */
#if AT32_GPT_USE_TMR9 || defined(__DOXYGEN__)
GPTDriver GPTD9;
#endif

/**
 * @brief   GPTD10 driver identifier.
 * @note    The driver GPTD10 allocates the timer TMR10 when enabled.
 */
#if AT32_GPT_USE_TMR10 || defined(__DOXYGEN__)
GPTDriver GPTD10;
#endif

/**
 * @brief   GPTD11 driver identifier.
 * @note    The driver GPTD11 allocates the timer TMR11 when enabled.
 */
#if AT32_GPT_USE_TMR11 || defined(__DOXYGEN__)
GPTDriver GPTD11;
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

#if AT32_GPT_USE_TMR1 || defined(__DOXYGEN__)
#if !defined(AT32_TMR1_SUPPRESS_ISR)
#if !defined(AT32_TMR1_OVF_HANDLER)
#error "AT32_TMR1_OVF_HANDLER not defined"
#endif
/**
 * @brief   TMR1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_OVF_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR1_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TMR1 */

#if AT32_GPT_USE_TMR2 || defined(__DOXYGEN__)
#if !defined(AT32_TMR2_SUPPRESS_ISR)
#if !defined(AT32_TMR2_HANDLER)
#error "AT32_TMR2_HANDLER not defined"
#endif
/**
 * @brief   TMR2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD2);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR2_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TMR2 */

#if AT32_GPT_USE_TMR3 || defined(__DOXYGEN__)
#if !defined(AT32_TMR3_SUPPRESS_ISR)
#if !defined(AT32_TMR3_HANDLER)
#error "AT32_TMR3_HANDLER not defined"
#endif
/**
 * @brief   TMR3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR3_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD3);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR3_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TMR3 */

#if AT32_GPT_USE_TMR4 || defined(__DOXYGEN__)
#if !defined(AT32_TMR4_SUPPRESS_ISR)
#if !defined(AT32_TMR4_HANDLER)
#error "AT32_TMR4_HANDLER not defined"
#endif
/**
 * @brief   TMR4 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR4_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD4);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR4_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TMR4 */

#if AT32_GPT_USE_TMR5 || defined(__DOXYGEN__)
#if !defined(AT32_TMR5_SUPPRESS_ISR)
#if !defined(AT32_TMR5_HANDLER)
#error "AT32_TMR5_HANDLER not defined"
#endif
/**
 * @brief   TMR5 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR5_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  gpt_lld_serve_interrupt(&GPTD5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR5_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TMR5 */

#if AT32_GPT_USE_TMR9 || defined(__DOXYGEN__)
#if !defined(AT32_TMR9_SUPPRESS_ISR)
#error "TMR9 ISR not defined by platform"
#endif /* !defined(AT32_TMR9_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TMR9 */

#if AT32_GPT_USE_TMR10 || defined(__DOXYGEN__)
#if !defined(AT32_TMR10_SUPPRESS_ISR)
#error "TMR10 ISR not defined by platform"
#endif /* !defined(AT32_TMR10_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TMR10 */

#if AT32_GPT_USE_TMR11 || defined(__DOXYGEN__)
#if !defined(AT32_TMR11_SUPPRESS_ISR)
#error "TMR11 ISR not defined by platform"
#endif /* !defined(AT32_TMR11_SUPPRESS_ISR) */
#endif /* AT32_GPT_USE_TMR11 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level GPT driver initialization.
 *
 * @notapi
 */
void gpt_lld_init(void) {

#if AT32_GPT_USE_TMR1
  /* Driver initialization.*/
  gptObjectInit(&GPTD1);
  GPTD1.tmr = AT32_TMR1;
  GPTD1.has_plus_mode = (bool)AT32_TMR1_IS_32BITS;
#endif

#if AT32_GPT_USE_TMR2
  /* Driver initialization.*/
  gptObjectInit(&GPTD2);
  GPTD2.tmr = AT32_TMR2;
  GPTD2.has_plus_mode = (bool)AT32_TMR2_IS_32BITS;
#endif

#if AT32_GPT_USE_TMR3
  /* Driver initialization.*/
  gptObjectInit(&GPTD3);
  GPTD3.tmr = AT32_TMR3;
  GPTD3.has_plus_mode = (bool)AT32_TMR3_IS_32BITS;
#endif

#if AT32_GPT_USE_TMR4
  /* Driver initialization.*/
  gptObjectInit(&GPTD4);
  GPTD4.tmr = AT32_TMR4;
  GPTD4.has_plus_mode = (bool)AT32_TMR4_IS_32BITS;
#endif

#if AT32_GPT_USE_TMR5
  /* Driver initialization.*/
  gptObjectInit(&GPTD5);
  GPTD5.tmr = AT32_TMR5;
  GPTD5.has_plus_mode = (bool)AT32_TMR5_IS_32BITS;
#endif

#if AT32_GPT_USE_TMR9
  /* Driver initialization.*/
  gptObjectInit(&GPTD9);
  GPTD9.tmr = AT32_TMR9;
  GPTD9.has_plus_mode = (bool)AT32_TMR9_IS_32BITS;
#endif

#if AT32_GPT_USE_TMR10
  /* Driver initialization.*/
  gptObjectInit(&GPTD10);
  GPTD10.tmr = AT32_TMR10;
  GPTD10.has_plus_mode = (bool)AT32_TMR10_IS_32BITS;
#endif

#if AT32_GPT_USE_TMR11
  /* Driver initialization.*/
  gptObjectInit(&GPTD11);
  GPTD11.tmr = AT32_TMR11;
  GPTD11.has_plus_mode = (bool)AT32_TMR11_IS_32BITS;
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
  uint16_t div;

  if (gptp->state == GPT_STOP) {
    /* Clock activation.*/
#if AT32_GPT_USE_TMR1
    if (&GPTD1 == gptp) {
      crmEnableTMR1(true);
      crmResetTMR1();
#if !defined(AT32_TMR1_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR1_OVF_NUMBER, AT32_GPT_TMR1_IRQ_PRIORITY);
#endif
      gptp->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_GPT_USE_TMR2
    if (&GPTD2 == gptp) {
      crmEnableTMR2(true);
      crmResetTMR2();
#if !defined(AT32_TMR2_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR2_NUMBER, AT32_GPT_TMR2_IRQ_PRIORITY);
#endif
      gptp->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_GPT_USE_TMR3
    if (&GPTD3 == gptp) {
      crmEnableTMR3(true);
      crmResetTMR3();
#if !defined(AT32_TMR3_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR3_NUMBER, AT32_GPT_TMR3_IRQ_PRIORITY);
#endif
      gptp->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_GPT_USE_TMR4
    if (&GPTD4 == gptp) {
      crmEnableTMR4(true);
      crmResetTMR4();
#if !defined(AT32_TMR4_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR4_NUMBER, AT32_GPT_TMR4_IRQ_PRIORITY);
#endif
      gptp->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_GPT_USE_TMR5
    if (&GPTD5 == gptp) {
      crmEnableTMR5(true);
      crmResetTMR5();
#if !defined(AT32_TMR5_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR5_NUMBER, AT32_GPT_TMR5_IRQ_PRIORITY);
#endif
      gptp->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_GPT_USE_TMR9
    if (&GPTD9 == gptp) {
      crmEnableTMR9(true);
      crmResetTMR9();
#if !defined(AT32_TMR9_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR9_NUMBER, AT32_GPT_TMR9_IRQ_PRIORITY);
#endif
      gptp->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_GPT_USE_TMR10
    if (&GPTD10 == gptp) {
      crmEnableTMR10(true);
      crmResetTMR10();
#if !defined(AT32_TMR10_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR10_NUMBER, AT32_GPT_TMR10_IRQ_PRIORITY);
#endif
      gptp->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_GPT_USE_TMR11
    if (&GPTD11 == gptp) {
      crmEnableTMR11(true);
      crmResetTMR11();
#if !defined(AT32_TMR11_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR11_NUMBER, AT32_GPT_TMR11_IRQ_PRIORITY);
#endif
      gptp->clock = AT32_TMRCLK2;
    }
#endif
  }

  /* Prescaler value calculation.*/
  div = (uint16_t)((gptp->clock / gptp->config->frequency) - 1);
  osalDbgAssert(((uint32_t)(div + 1) * gptp->config->frequency) == gptp->clock,
                "invalid frequency");

  /* If timer counter is 32bits.*/
  if (gptp->has_plus_mode) {
    gptp->tmr->CTRL1 = AT32_TMR_CTRL1_PMEN;
  }

  /* Timer configuration.*/
  gptp->tmr->CTRL2 = gptp->config->ctrl2;
  gptp->tmr->DIV   = div;                       /* Prescaler value.         */
  gptp->tmr->ISTS  = 0;                         /* Clear pending IRQs.      */
  gptp->tmr->IDEN  = gptp->config->iden &       /* DMA-related IDEN bits.   */
                     ~AT32_TMR_IDEN_IRQ_MASK;
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
    gptp->tmr->CTRL1 = 0;                       /* Timer disabled.          */
    gptp->tmr->IDEN  = 0;                       /* All IRQs disabled.       */
    gptp->tmr->ISTS  = 0;                       /* Clear pending IRQs.      */

#if AT32_GPT_USE_TMR1
    if (&GPTD1 == gptp) {
#if !defined(AT32_TMR1_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR1_OVF_NUMBER);
#endif
      crmDisableTMR1();
    }
#endif

#if AT32_GPT_USE_TMR2
    if (&GPTD2 == gptp) {
#if !defined(AT32_TMR2_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR2_NUMBER);
#endif
      crmDisableTMR2();
    }
#endif

#if AT32_GPT_USE_TMR3
    if (&GPTD3 == gptp) {
#if !defined(AT32_TMR3_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR3_NUMBER);
#endif
      crmDisableTMR3();
    }
#endif

#if AT32_GPT_USE_TMR4
    if (&GPTD4 == gptp) {
#if !defined(AT32_TMR4_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR4_NUMBER);
#endif
      crmDisableTMR4();
    }
#endif

#if AT32_GPT_USE_TMR5
    if (&GPTD5 == gptp) {
#if !defined(AT32_TMR5_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR5_NUMBER);
#endif
      crmDisableTMR5();
    }
#endif

#if AT32_GPT_USE_TMR9
    if (&GPTD9 == gptp) {
#if !defined(AT32_TMR9_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR9_NUMBER);
#endif
      crmDisableTMR9();
    }
#endif

#if AT32_GPT_USE_TMR10
    if (&GPTD10 == gptp) {
#if !defined(AT32_TMR10_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR10_NUMBER);
#endif
      crmDisableTMR10();
    }
#endif

#if AT32_GPT_USE_TMR11
    if (&GPTD11 == gptp) {
#if !defined(AT32_TMR11_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR11_NUMBER);
#endif
      crmDisableTMR11();
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

  gptp->tmr->PR    = (uint32_t)(interval - 1U); /* Time constant.           */
  gptp->tmr->SWEVT = AT32_TMR_SWEVT_OVFSWTR;    /* Update event.            */
  gptp->tmr->CVAL  = 0;                         /* Reset counter.           */

  /* NOTE: After generating the OVFSWTR event it takes several clock cycles
     before ISTS bit 0 goes to 1. This is why the clearing of CVAL has been
     inserted before the clearing of ISTS, to give it some time.*/
  gptp->tmr->ISTS = 0;                          /* Clear pending IRQs.      */
  if (NULL != gptp->config->callback)
    gptp->tmr->IDEN |= AT32_TMR_IDEN_OVFIEN;    /* Update Event IRQ enabled.*/
  gptp->tmr->CTRL1 |= AT32_TMR_CTRL1_PRBEN | AT32_TMR_CTRL1_OVFS | AT32_TMR_CTRL1_TMREN;
}

/**
 * @brief   Stops the timer.
 *
 * @param[in] gptp      pointer to the @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_stop_timer(GPTDriver *gptp) {

  gptp->tmr->CTRL1 &= ~(AT32_TMR_CTRL1_PRBEN | AT32_TMR_CTRL1_OVFS | 
                        AT32_TMR_CTRL1_TMREN);  /* Initially stopped.       */
  gptp->tmr->ISTS  = 0;                         /* Clear pending IRQs.      */

  /* All interrupts disabled.*/
  gptp->tmr->IDEN &= ~AT32_TMR_IDEN_IRQ_MASK;
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

  gptp->tmr->PR    = (uint32_t)(interval - 1U); /* Time constant.           */
  gptp->tmr->SWEVT = AT32_TMR_SWEVT_OVFSWTR;    /* Update event.            */
  gptp->tmr->ISTS  = 0;                         /* Clear pending IRQs.      */
  gptp->tmr->CTRL1 |= AT32_TMR_CTRL1_OCMEN | AT32_TMR_CTRL1_OVFS | AT32_TMR_CTRL1_TMREN;
  while (!(gptp->tmr->ISTS & AT32_TMR_ISTS_OVFIF))
    ;
  gptp->tmr->ISTS  = 0;                         /* Clear pending IRQs.      */
}

/**
 * @brief   Shared IRQ handler.
 *
 * @param[in] gptp      pointer to a @p GPTDriver object
 *
 * @notapi
 */
void gpt_lld_serve_interrupt(GPTDriver *gptp) {
  uint32_t ists;

  ists  = gptp->tmr->ISTS;
  ists &= gptp->tmr->IDEN & AT32_TMR_IDEN_IRQ_MASK;
  gptp->tmr->ISTS = ~ists;
  if ((ists & AT32_TMR_ISTS_OVFIF) != 0) {
    _gpt_isr_invoke_cb(gptp);
  }
}

#endif /* HAL_USE_GPT */

/** @} */

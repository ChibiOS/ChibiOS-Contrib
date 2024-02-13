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
/*
   Concepts and parts of this file have been contributed by Fabio Utzig and
   Xo Wang.
 */

/**
 * @file    TMRv1/hal_icu_lld.c
 * @brief   AT32 ICU subsystem low level driver header.
 *
 * @addtogroup ICU
 * @{
 */

#include "hal.h"

#if HAL_USE_ICU || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   ICUD1 driver identifier.
 * @note    The driver ICUD1 allocates the complex timer TMR1 when enabled.
 */
#if AT32_ICU_USE_TMR1 || defined(__DOXYGEN__)
ICUDriver ICUD1;
#endif

/**
 * @brief   ICUD2 driver identifier.
 * @note    The driver ICUD1 allocates the timer TMR2 when enabled.
 */
#if AT32_ICU_USE_TMR2 || defined(__DOXYGEN__)
ICUDriver ICUD2;
#endif

/**
 * @brief   ICUD3 driver identifier.
 * @note    The driver ICUD1 allocates the timer TMR3 when enabled.
 */
#if AT32_ICU_USE_TMR3 || defined(__DOXYGEN__)
ICUDriver ICUD3;
#endif

/**
 * @brief   ICUD4 driver identifier.
 * @note    The driver ICUD4 allocates the timer TMR4 when enabled.
 */
#if AT32_ICU_USE_TMR4 || defined(__DOXYGEN__)
ICUDriver ICUD4;
#endif

/**
 * @brief   ICUD5 driver identifier.
 * @note    The driver ICUD5 allocates the timer TMR5 when enabled.
 */
#if AT32_ICU_USE_TMR5 || defined(__DOXYGEN__)
ICUDriver ICUD5;
#endif

/**
 * @brief   ICUD9 driver identifier.
 * @note    The driver ICUD9 allocates the timer TMR9 when enabled.
 */
#if AT32_ICU_USE_TMR9 || defined(__DOXYGEN__)
ICUDriver ICUD9;
#endif

/**
 * @brief   ICUD10 driver identifier.
 * @note    The driver ICUD10 allocates the timer TMR10 when enabled.
 */
#if AT32_ICU_USE_TMR10 || defined(__DOXYGEN__)
ICUDriver ICUD10;
#endif

/**
 * @brief   ICUD11 driver identifier.
 * @note    The driver ICUD11 allocates the timer TMR11 when enabled.
 */
#if AT32_ICU_USE_TMR11 || defined(__DOXYGEN__)
ICUDriver ICUD11;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static bool icu_lld_wait_edge(ICUDriver *icup) {
  uint32_t ists;
  bool result;

  /* Polled mode so re-enabling the interrupts while the operation is
     performed.*/
  osalSysUnlock();

  /* Polling the right bit depending on the input channel.*/
  if (icup->config->channel == ICU_CHANNEL_1) {
    /* Waiting for an edge.*/
    while (((ists = icup->tmr->ISTS) &
            (AT32_TMR_ISTS_C1IF | AT32_TMR_ISTS_OVFIF)) == 0)
      ;
  }
  else {
    /* Waiting for an edge.*/
    while (((ists = icup->tmr->ISTS) &
            (AT32_TMR_ISTS_C2IF | AT32_TMR_ISTS_OVFIF)) == 0)
      ;
  }

  /* Edge or overflow?*/
  result = (ists & AT32_TMR_ISTS_OVFIF) != 0 ? true : false;

  /* Done, disabling interrupts again.*/
  osalSysLock();

  /* Resetting all flags.*/
  icup->tmr->ISTS &= ~(AT32_TMR_ISTS_C1IF |
                       AT32_TMR_ISTS_C2IF |
                       AT32_TMR_ISTS_OVFIF);

  return result;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if AT32_ICU_USE_TMR1 || defined(__DOXYGEN__)
#if !defined(AT32_TMR1_SUPPRESS_ISR)
#if !defined(AT32_TMR1_OVF_HANDLER)
#error "AT32_TMR1_OVF_HANDLER not defined"
#endif
/**
 * @brief   TMR1 overflow interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_OVF_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  icu_lld_serve_interrupt(&ICUD1);

  OSAL_IRQ_EPILOGUE();
}

#if !defined(AT32_TMR1_CH_HANDLER)
#error "AT32_TMR1_CH_HANDLER not defined"
#endif
/**
 * @brief   TMR1 channel interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_CH_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  icu_lld_serve_interrupt(&ICUD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR1_SUPPRESS_ISR) */
#endif /* AT32_ICU_USE_TMR1 */

#if AT32_ICU_USE_TMR2 || defined(__DOXYGEN__)
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

  icu_lld_serve_interrupt(&ICUD2);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR2_SUPPRESS_ISR) */
#endif /* AT32_ICU_USE_TMR2 */

#if AT32_ICU_USE_TMR3 || defined(__DOXYGEN__)
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

  icu_lld_serve_interrupt(&ICUD3);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR3_SUPPRESS_ISR) */
#endif /* AT32_ICU_USE_TMR3 */

#if AT32_ICU_USE_TMR4 || defined(__DOXYGEN__)
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

  icu_lld_serve_interrupt(&ICUD4);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR4_SUPPRESS_ISR) */
#endif /* AT32_ICU_USE_TMR4 */

#if AT32_ICU_USE_TMR5 || defined(__DOXYGEN__)
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

  icu_lld_serve_interrupt(&ICUD5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR5_SUPPRESS_ISR) */
#endif /* AT32_ICU_USE_TMR5 */

#if AT32_ICU_USE_TMR9 || defined(__DOXYGEN__)
#if !defined(AT32_TMR9_SUPPRESS_ISR)
#error "TMR9 ISR not defined by platform"
#endif /* !defined(AT32_TMR9_SUPPRESS_ISR) */
#endif /* AT32_ICU_USE_TMR9 */

#if AT32_ICU_USE_TMR10 || defined(__DOXYGEN__)
#if !defined(AT32_TMR10_SUPPRESS_ISR)
#error "TMR10 ISR not defined by platform"
#endif /* !defined(AT32_TMR10_SUPPRESS_ISR) */
#endif /* AT32_ICU_USE_TMR10 */

#if AT32_ICU_USE_TMR11 || defined(__DOXYGEN__)
#if !defined(AT32_TMR11_SUPPRESS_ISR)
#error "TMR11 ISR not defined by platform"
#endif /* !defined(AT32_TMR11_SUPPRESS_ISR) */
#endif /* AT32_ICU_USE_TMR11 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ICU driver initialization.
 *
 * @notapi
 */
void icu_lld_init(void) {

#if AT32_ICU_USE_TMR1
  /* Driver initialization.*/
  icuObjectInit(&ICUD1);
  ICUD1.tmr = AT32_TMR1;
  ICUD1.has_plus_mode = (bool)AT32_TMR1_IS_32BITS;
#endif

#if AT32_ICU_USE_TMR2
  /* Driver initialization.*/
  icuObjectInit(&ICUD2);
  ICUD2.tmr = AT32_TMR2;
  ICUD2.has_plus_mode = (bool)AT32_TMR2_IS_32BITS;
#endif

#if AT32_ICU_USE_TMR3
  /* Driver initialization.*/
  icuObjectInit(&ICUD3);
  ICUD3.tmr = AT32_TMR3;
  ICUD3.has_plus_mode = (bool)AT32_TMR3_IS_32BITS;
#endif

#if AT32_ICU_USE_TMR4
  /* Driver initialization.*/
  icuObjectInit(&ICUD4);
  ICUD4.tmr = AT32_TMR4;
  ICUD4.has_plus_mode = (bool)AT32_TMR4_IS_32BITS;
#endif

#if AT32_ICU_USE_TMR5
  /* Driver initialization.*/
  icuObjectInit(&ICUD5);
  ICUD5.tmr = AT32_TMR5;
  ICUD5.has_plus_mode = (bool)AT32_TMR5_IS_32BITS;
#endif

#if AT32_ICU_USE_TMR9
  /* Driver initialization.*/
  icuObjectInit(&ICUD9);
  ICUD9.tmr = AT32_TMR9;
  ICUD9.has_plus_mode = (bool)AT32_TMR9_IS_32BITS;
#endif

#if AT32_ICU_USE_TMR10
  /* Driver initialization.*/
  icuObjectInit(&ICUD10);
  ICUD10.tmr = AT32_TMR10;
  ICUD10.has_plus_mode = (bool)AT32_TMR10_IS_32BITS;
#endif

#if AT32_ICU_USE_TMR11
  /* Driver initialization.*/
  icuObjectInit(&ICUD11);
  ICUD11.tmr = AT32_TMR11;
  ICUD11.has_plus_mode = (bool)AT32_TMR11_IS_32BITS;
#endif
}

/**
 * @brief   Configures and activates the ICU peripheral.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
void icu_lld_start(ICUDriver *icup) {
  uint32_t div;

  osalDbgAssert((icup->config->channel == ICU_CHANNEL_1) ||
                (icup->config->channel == ICU_CHANNEL_2),
                "invalid input");

  if (icup->state == ICU_STOP) {
    /* Clock activation and timer reset.*/
#if AT32_ICU_USE_TMR1
    if (&ICUD1 == icup) {
      crmEnableTMR1(true);
      crmResetTMR1();
#if !defined(AT32_TMR1_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR1_OVF_NUMBER, AT32_ICU_TMR1_IRQ_PRIORITY);
      nvicEnableVector(AT32_TMR1_CH_NUMBER, AT32_ICU_TMR1_IRQ_PRIORITY);
#endif
      icup->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_ICU_USE_TMR2
    if (&ICUD2 == icup) {
      crmEnableTMR2(true);
      crmResetTMR2();
#if !defined(AT32_TMR2_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR2_NUMBER, AT32_ICU_TMR2_IRQ_PRIORITY);
#endif
      icup->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_ICU_USE_TMR3
    if (&ICUD3 == icup) {
      crmEnableTMR3(true);
      crmResetTMR3();
#if !defined(AT32_TMR3_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR3_NUMBER, AT32_ICU_TMR3_IRQ_PRIORITY);
#endif
     icup->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_ICU_USE_TMR4
    if (&ICUD4 == icup) {
      crmEnableTMR4(true);
      crmResetTMR4();
#if !defined(AT32_TMR4_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR4_NUMBER, AT32_ICU_TMR4_IRQ_PRIORITY);
#endif
      icup->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_ICU_USE_TMR5
    if (&ICUD5 == icup) {
      crmEnableTMR5(true);
      crmResetTMR5();
#if !defined(AT32_TMR5_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR5_NUMBER, AT32_ICU_TMR5_IRQ_PRIORITY);
#endif
      icup->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_ICU_USE_TMR9
    if (&ICUD9 == icup) {
      crmEnableTMR9(true);
      crmResetTMR9();
      icup->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_ICU_USE_TMR10
    if (&ICUD10 == icup) {
      crmEnableTMR10(true);
      crmResetTMR10();
      icup->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_ICU_USE_TMR11
    if (&ICUD11 == icup) {
      crmEnableTMR11(true);
      crmResetTMR11();
      icup->clock = AT32_TMRCLK2;
    }
#endif
  }
  else {
    /* Driver re-configuration scenario, it must be stopped first.*/
    icup->tmr->CTRL1  = 0;                  /* Timer disabled.              */
    icup->tmr->CDT[0] = 0;                  /* Comparator 1 disabled.       */
    icup->tmr->CDT[1] = 0;                  /* Comparator 2 disabled.       */
    icup->tmr->CVAL   = 0;                  /* Counter reset to zero.       */
  }

  /* If timer counter is 32bits.*/
  if (icup->has_plus_mode) {
    icup->tmr->CTRL1 = AT32_TMR_CTRL1_PMEN;
  }

  /* Timer configuration.*/
  icup->tmr->ISTS = 0;                      /* Clear eventual pending IRQs. */
  icup->tmr->IDEN = icup->config->iden &    /* DMA-related IDEN settings.   */
                    ~AT32_TMR_IDEN_IRQ_MASK;
  div = (icup->clock / icup->config->frequency) - 1;
  osalDbgAssert((div <= 0xFFFF) &&
                ((div + 1) * icup->config->frequency) == icup->clock,
                "invalid frequency");
  icup->tmr->DIV = div;
  if (icup->config->pr == 0U) {
    /* Zero is an invalid value and is turned in maximum value, also for
       legacy configurations compatibility.*/
    icup->tmr->PR = 0xFFFFFFFFU;
  }
  else {
    icup->tmr->PR = icup->config->pr;
  }

  if (icup->config->channel == ICU_CHANNEL_1) {
    /* Selected input 1.
       CM1_C1C = 01 = CH1 Input on C1IFP1.
       CM1_C2C = 10 = CH2 Input on C1IFP2.*/
    icup->tmr->CM1 = AT32_TMR_CM1_C1C(1) | AT32_TMR_CM1_C2C(2);

    /* STCTRL_STIS  = 101, input is C1IF1.
       STCTRL_SMSEL = 100, reset on rising edge.*/
    icup->tmr->STCTRL = AT32_TMR_STCTRL_STIS(5) | AT32_TMR_STCTRL_SMSEL(4);

    /* The CCTRL settings depend on the selected trigger mode.
       ICU_INPUT_ACTIVE_HIGH: Active on rising edge, idle on falling edge.
       ICU_INPUT_ACTIVE_LOW:  Active on falling edge, idle on rising edge.*/
    if (icup->config->mode == ICU_INPUT_ACTIVE_HIGH)
      icup->tmr->CCTRL = AT32_TMR_CCTRL_C1EN |
                         AT32_TMR_CCTRL_C2EN | AT32_TMR_CCTRL_C2P;
    else
      icup->tmr->CCTRL = AT32_TMR_CCTRL_C1EN | AT32_TMR_CCTRL_C1P |
                         AT32_TMR_CCTRL_C2EN;

    /* Direct pointers to the capture registers in order to make reading
       data faster from within callbacks.*/
    icup->wccrp = &icup->tmr->CDT[1];
    icup->pccrp = &icup->tmr->CDT[0];
  }
  else {
    /* Selected input 2.
       CM1_C1C = 10 = CH1 Input on C2IFP1.
       CM1_C2C = 01 = CH2 Input on C2IFP2.*/
    icup->tmr->CM1 = AT32_TMR_CM1_C1C(2) | AT32_TMR_CM1_C2C(1);

    /* STCTRL_STIS  = 110, input is C1IF2.
       STCTRL_SMSEL = 100, reset on rising edge.*/
    icup->tmr->STCTRL = AT32_TMR_STCTRL_STIS(6) | AT32_TMR_STCTRL_SMSEL(4);

    /* The CCTRL settings depend on the selected trigger mode.
       ICU_INPUT_ACTIVE_HIGH: Active on rising edge, idle on falling edge.
       ICU_INPUT_ACTIVE_LOW:  Active on falling edge, idle on rising edge.*/
    if (icup->config->mode == ICU_INPUT_ACTIVE_HIGH)
      icup->tmr->CCTRL = AT32_TMR_CCTRL_C1EN | AT32_TMR_CCTRL_C1P |
                         AT32_TMR_CCTRL_C2EN;
    else
      icup->tmr->CCTRL = AT32_TMR_CCTRL_C1EN |
                         AT32_TMR_CCTRL_C2EN | AT32_TMR_CCTRL_C2P;

    /* Direct pointers to the capture registers in order to make reading
       data faster from within callbacks.*/
    icup->wccrp = &icup->tmr->CDT[0];
    icup->pccrp = &icup->tmr->CDT[1];
  }
}

/**
 * @brief   Deactivates the ICU peripheral.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
void icu_lld_stop(ICUDriver *icup) {

  if (icup->state == ICU_READY) {
    /* Clock deactivation.*/
    icup->tmr->CTRL1 = 0;                   /* Timer disabled.              */
    icup->tmr->IDEN  = 0;                   /* All IRQs disabled.           */
    icup->tmr->ISTS  = 0;                   /* Clear eventual pending IRQs. */

#if AT32_ICU_USE_TMR1
    if (&ICUD1 == icup) {
#if !defined(AT32_TMR1_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR1_OVF_NUMBER);
      nvicDisableVector(AT32_TMR1_CH_NUMBER);
#endif
      crmDisableTMR1();
    }
#endif

#if AT32_ICU_USE_TMR2
    if (&ICUD2 == icup) {
#if !defined(AT32_TMR2_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR2_NUMBER);
#endif
      crmDisableTMR2();
    }
#endif

#if AT32_ICU_USE_TMR3
    if (&ICUD3 == icup) {
#if !defined(AT32_TMR3_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR3_NUMBER);
#endif
      crmDisableTMR3();
    }
#endif

#if AT32_ICU_USE_TMR4
    if (&ICUD4 == icup) {
#if !defined(AT32_TMR4_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR4_NUMBER);
#endif
      crmDisableTMR4();
    }
#endif

#if AT32_ICU_USE_TMR5
    if (&ICUD5 == icup) {
#if !defined(AT32_TMR5_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR5_NUMBER);
#endif
      crmDisableTMR5();
    }
#endif

#if AT32_ICU_USE_TMR9
    if (&ICUD9 == icup) {
      crmDisableTMR9();
    }
#endif

#if AT32_ICU_USE_TMR10
    if (&ICUD10 == icup) {
      crmDisableTMR10();
    }
#endif

#if AT32_ICU_USE_TMR11
    if (&ICUD11 == icup) {
      crmDisableTMR11();
    }
#endif
  }
}

/**
 * @brief   Starts the input capture.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
void icu_lld_start_capture(ICUDriver *icup) {

  /* Triggering an OVFSWTR and clearing the IRQ status.*/
  icup->tmr->SWEVT |= AT32_TMR_SWEVT_OVFSWTR;
  icup->tmr->ISTS   = 0;

  /* Timer is started.*/
  icup->tmr->CTRL1 |= AT32_TMR_CTRL1_OVFS | AT32_TMR_CTRL1_TMREN;
}

/**
 * @brief   Waits for a completed capture.
 * @note    The operation is performed in polled mode.
 * @note    In order to use this function notifications must be disabled.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The capture status.
 * @retval false        if the capture is successful.
 * @retval true         if a timer overflow occurred.
 *
 * @notapi
 */
bool icu_lld_wait_capture(ICUDriver *icup) {

  /* If the driver is still in the ICU_WAITING state then we need to wait
     for the first activation edge.*/
  if (icup->state == ICU_WAITING)
    if (icu_lld_wait_edge(icup))
      return true;

  /* This edge marks the availability of a capture result.*/
  return icu_lld_wait_edge(icup);
}

/**
 * @brief   Stops the input capture.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
void icu_lld_stop_capture(ICUDriver *icup) {

  /* Timer stopped.*/
  icup->tmr->CTRL1 &= ~(AT32_TMR_CTRL1_OVFS | AT32_TMR_CTRL1_TMREN);

  /* All interrupts disabled.*/
  icup->tmr->IDEN &= ~AT32_TMR_IDEN_IRQ_MASK;
}

/**
 * @brief   Enables notifications.
 * @pre     The ICU unit must have been activated using @p icuStart() and the
 *          capture started using @p icuStartCapture().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
void icu_lld_enable_notifications(ICUDriver *icup) {
  uint32_t iden = icup->tmr->IDEN;

  /* If interrupts were already enabled then the operation is skipped.
     This is done in order to avoid clearing the ISTS and risk losing
     pending interrupts.*/
  if ((iden & AT32_TMR_IDEN_IRQ_MASK) == 0) {
    /* Previously triggered IRQs are ignored, status cleared.*/
    icup->tmr->ISTS = 0;

    if (icup->config->channel == ICU_CHANNEL_1) {
      /* Enabling periodic callback on CC1.*/
      iden |= AT32_TMR_IDEN_C1IEN;

      /* Optionally enabling width callback on CC2.*/
      if (icup->config->width_cb != NULL)
        iden |= AT32_TMR_IDEN_C2IEN;
    }
    else {
      /* Enabling periodic callback on CC2.*/
      iden |= AT32_TMR_IDEN_C2IEN;

      /* Optionally enabling width callback on CC1.*/
      if (icup->config->width_cb != NULL)
        iden |= AT32_TMR_IDEN_C1IEN;
    }

    /* If an overflow callback is defined then also the overflow callback
       is enabled.*/
    if (icup->config->overflow_cb != NULL)
      iden |= AT32_TMR_IDEN_OVFIEN;

    /* One single atomic write.*/
    icup->tmr->IDEN = iden;
  }
}

/**
 * @brief   Disables notifications.
 * @pre     The ICU unit must have been activated using @p icuStart() and the
 *          capture started using @p icuStartCapture().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
void icu_lld_disable_notifications(ICUDriver *icup) {

  /* All interrupts disabled.*/
  icup->tmr->IDEN &= ~AT32_TMR_IDEN_IRQ_MASK;
}

/**
 * @brief   Shared IRQ handler.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
void icu_lld_serve_interrupt(ICUDriver *icup) {
  uint32_t ists;

  ists  = icup->tmr->ISTS;
  ists &= icup->tmr->IDEN & AT32_TMR_IDEN_IRQ_MASK;
  icup->tmr->ISTS = ~ists;
  if (icup->config->channel == ICU_CHANNEL_1) {
    if ((ists & AT32_TMR_ISTS_C2IF) != 0)
      _icu_isr_invoke_width_cb(icup);
    if ((ists & AT32_TMR_ISTS_C1IF) != 0)
      _icu_isr_invoke_period_cb(icup);
  }
  else {
    if ((ists & AT32_TMR_ISTS_C1IF) != 0)
      _icu_isr_invoke_width_cb(icup);
    if ((ists & AT32_TMR_ISTS_C2IF) != 0)
      _icu_isr_invoke_period_cb(icup);
  }
  if ((ists & AT32_TMR_ISTS_OVFIF) != 0)
    _icu_isr_invoke_overflow_cb(icup);
}

#endif /* HAL_USE_ICU */

/** @} */

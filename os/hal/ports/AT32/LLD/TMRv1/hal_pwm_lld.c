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
 * @file    TMRv1/hal_pwm_lld.c
 * @brief   AT32 PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#include "hal.h"

#if HAL_USE_PWM || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   PWMD1 driver identifier.
 * @note    The driver PWMD1 allocates the complex timer TMR1 when enabled.
 */
#if AT32_PWM_USE_TMR1 || defined(__DOXYGEN__)
PWMDriver PWMD1;
#endif

/**
 * @brief   PWMD2 driver identifier.
 * @note    The driver PWMD2 allocates the timer TMR2 when enabled.
 */
#if AT32_PWM_USE_TMR2 || defined(__DOXYGEN__)
PWMDriver PWMD2;
#endif

/**
 * @brief   PWMD3 driver identifier.
 * @note    The driver PWMD3 allocates the timer TMR3 when enabled.
 */
#if AT32_PWM_USE_TMR3 || defined(__DOXYGEN__)
PWMDriver PWMD3;
#endif

/**
 * @brief   PWMD4 driver identifier.
 * @note    The driver PWMD4 allocates the timer TMR4 when enabled.
 */
#if AT32_PWM_USE_TMR4 || defined(__DOXYGEN__)
PWMDriver PWMD4;
#endif

/**
 * @brief   PWMD5 driver identifier.
 * @note    The driver PWMD5 allocates the timer TMR5 when enabled.
 */
#if AT32_PWM_USE_TMR5 || defined(__DOXYGEN__)
PWMDriver PWMD5;
#endif

/**
 * @brief   PWMD9 driver identifier.
 * @note    The driver PWMD9 allocates the timer TMR9 when enabled.
 */
#if AT32_PWM_USE_TMR9 || defined(__DOXYGEN__)
PWMDriver PWMD9;
#endif

/**
 * @brief   PWMD10 driver identifier.
 * @note    The driver PWMD10 allocates the timer TMR10 when enabled.
 */
#if AT32_PWM_USE_TMR10 || defined(__DOXYGEN__)
PWMDriver PWMD10;
#endif

/**
 * @brief   PWMD11 driver identifier.
 * @note    The driver PWMD11 allocates the timer TMR11 when enabled.
 */
#if AT32_PWM_USE_TMR11 || defined(__DOXYGEN__)
PWMDriver PWMD11;
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

#if AT32_PWM_USE_TMR1 || defined(__DOXYGEN__)
#if !defined(AT32_TMR1_SUPPRESS_ISR)
#if !defined(AT32_TMR1_OVF_HANDLER)
#error "AT32_TMR1_OVF_HANDLER not defined"
#endif
/**
 * @brief   TMR1 overflow interrupt handler.
 * @note    It is assumed that this interrupt is only activated if the callback
 *          pointer is not equal to @p NULL in order to not perform an extra
 *          check in a potentially critical interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_OVF_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  pwm_lld_serve_interrupt(&PWMD1);

  OSAL_IRQ_EPILOGUE();
}

#if !defined(AT32_TMR1_CH_HANDLER)
#error "AT32_TMR1_CH_HANDLER not defined"
#endif
/**
 * @brief   TMR1 channel interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_TMR1_CH_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  pwm_lld_serve_interrupt(&PWMD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR1_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TMR1 */

#if AT32_PWM_USE_TMR2 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD2);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR2_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TMR2 */

#if AT32_PWM_USE_TMR3 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD3);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR3_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TMR3 */

#if AT32_PWM_USE_TMR4 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD4);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR4_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TMR4 */

#if AT32_PWM_USE_TMR5 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_TMR5_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TMR5 */

#if AT32_PWM_USE_TMR9 || defined(__DOXYGEN__)
#if !defined(AT32_TMR9_SUPPRESS_ISR)
#error "TMR9 ISR not defined by platform"
#endif /* !defined(AT32_TMR9_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TMR9 */

#if AT32_PWM_USE_TMR10 || defined(__DOXYGEN__)
#if !defined(AT32_TMR10_SUPPRESS_ISR)
#error "TMR10 ISR not defined by platform"
#endif /* !defined(AT32_TMR10_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TMR10 */

#if AT32_PWM_USE_TMR11 || defined(__DOXYGEN__)
#if !defined(AT32_TMR11_SUPPRESS_ISR)
#error "TMR11 ISR not defined by platform"
#endif /* !defined(AT32_TMR11_SUPPRESS_ISR) */
#endif /* AT32_PWM_USE_TMR11 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level PWM driver initialization.
 *
 * @notapi
 */
void pwm_lld_init(void) {

#if AT32_PWM_USE_TMR1
  /* Driver initialization.*/
  pwmObjectInit(&PWMD1);
  PWMD1.channels = AT32_TMR1_CHANNELS;
  PWMD1.tmr = AT32_TMR1;
  PWMD1.has_brk = true;
  PWMD1.has_plus_mode = (bool)AT32_TMR1_IS_32BITS;
#endif

#if AT32_PWM_USE_TMR2
  /* Driver initialization.*/
  pwmObjectInit(&PWMD2);
  PWMD2.channels = AT32_TMR2_CHANNELS;
  PWMD2.tmr = AT32_TMR2;
  PWMD2.has_brk = false;
  PWMD2.has_plus_mode = (bool)AT32_TMR2_IS_32BITS;
#endif

#if AT32_PWM_USE_TMR3
  /* Driver initialization.*/
  pwmObjectInit(&PWMD3);
  PWMD3.channels = AT32_TMR3_CHANNELS;
  PWMD3.tmr = AT32_TMR3;
  PWMD3.has_brk = false;
  PWMD3.has_plus_mode = (bool)AT32_TMR3_IS_32BITS;
#endif

#if AT32_PWM_USE_TMR4
  /* Driver initialization.*/
  pwmObjectInit(&PWMD4);
  PWMD4.channels = AT32_TMR4_CHANNELS;
  PWMD4.tmr = AT32_TMR4;
  PWMD4.has_brk = false;
  PWMD4.has_plus_mode = (bool)AT32_TMR4_IS_32BITS;
#endif

#if AT32_PWM_USE_TMR5
  /* Driver initialization.*/
  pwmObjectInit(&PWMD5);
  PWMD5.channels = AT32_TMR5_CHANNELS;
  PWMD5.tmr = AT32_TMR5;
  PWMD5.has_brk = false;
  PWMD5.has_plus_mode = (bool)AT32_TMR5_IS_32BITS;
#endif

#if AT32_PWM_USE_TMR9
  /* Driver initialization.*/
  pwmObjectInit(&PWMD9);
  PWMD9.channels = AT32_TMR9_CHANNELS;
  PWMD9.tmr = AT32_TMR9;
  PWMD9.has_brk = false;
  PWMD9.has_plus_mode = (bool)AT32_TMR9_IS_32BITS;
#endif

#if AT32_PWM_USE_TMR10
  /* Driver initialization.*/
  pwmObjectInit(&PWMD10);
  PWMD10.channels = AT32_TMR10_CHANNELS;
  PWMD10.tmr = AT32_TMR10;
  PWMD10.has_brk = false;
  PWMD10.has_plus_mode = (bool)AT32_TMR10_IS_32BITS;
#endif

#if AT32_PWM_USE_TMR11
  /* Driver initialization.*/
  pwmObjectInit(&PWMD11);
  PWMD11.channels = AT32_TMR11_CHANNELS;
  PWMD11.tmr = AT32_TMR11;
  PWMD11.has_brk = false;
  PWMD11.has_plus_mode = (bool)AT32_TMR11_IS_32BITS;
#endif
}

/**
 * @brief   Configures and activates the PWM peripheral.
 * @note    Starting a driver that is already in the @p PWM_READY state
 *          disables all the active channels.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_start(PWMDriver *pwmp) {
  uint32_t div;
  uint32_t cctrl;

  if (pwmp->state == PWM_STOP) {
    /* Clock activation and timer reset.*/
#if AT32_PWM_USE_TMR1
    if (&PWMD1 == pwmp) {
      crmEnableTMR1(true);
      crmResetTMR1();
#if !defined(AT32_TMR1_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR1_OVF_NUMBER, AT32_PWM_TMR1_IRQ_PRIORITY);
      nvicEnableVector(AT32_TMR1_CH_NUMBER, AT32_PWM_TMR1_IRQ_PRIORITY);
#endif
      pwmp->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_PWM_USE_TMR2
    if (&PWMD2 == pwmp) {
      crmEnableTMR2(true);
      crmResetTMR2();
#if !defined(AT32_TMR2_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR2_NUMBER, AT32_PWM_TMR2_IRQ_PRIORITY);
#endif
      pwmp->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_PWM_USE_TMR3
    if (&PWMD3 == pwmp) {
      crmEnableTMR3(true);
      crmResetTMR3();
#if !defined(AT32_TMR3_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR3_NUMBER, AT32_PWM_TMR3_IRQ_PRIORITY);
#endif
      pwmp->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_PWM_USE_TMR4
    if (&PWMD4 == pwmp) {
      crmEnableTMR4(true);
      crmResetTMR4();
#if !defined(AT32_TMR4_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR4_NUMBER, AT32_PWM_TMR4_IRQ_PRIORITY);
#endif
      pwmp->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_PWM_USE_TMR5
    if (&PWMD5 == pwmp) {
      crmEnableTMR5(true);
      crmResetTMR5();
#if !defined(AT32_TMR5_SUPPRESS_ISR)
      nvicEnableVector(AT32_TMR5_NUMBER, AT32_PWM_TMR5_IRQ_PRIORITY);
#endif
      pwmp->clock = AT32_TMRCLK1;
    }
#endif

#if AT32_PWM_USE_TMR9
    if (&PWMD9 == pwmp) {
      crmEnableTMR9(true);
      crmResetTMR9();
      pwmp->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_PWM_USE_TMR10
    if (&PWMD10 == pwmp) {
      crmEnableTMR10(true);
      crmResetTMR10();
      pwmp->clock = AT32_TMRCLK2;
    }
#endif

#if AT32_PWM_USE_TMR11
    if (&PWMD11 == pwmp) {
      crmEnableTMR11(true);
      crmResetTMR11();
      pwmp->clock = AT32_TMRCLK2;
    }
#endif

    /* All channels configured in PWM1 mode with preload enabled and will
       stay that way until the driver is stopped.*/
    pwmp->tmr->CM1 = AT32_TMR_CM1_C1OCTRL(6) | AT32_TMR_CM1_C1OBEN |
                     AT32_TMR_CM1_C2OCTRL(6) | AT32_TMR_CM1_C2OBEN;
    pwmp->tmr->CM2 = AT32_TMR_CM2_C3OCTRL(6) | AT32_TMR_CM2_C3OBEN |
                     AT32_TMR_CM2_C4OCTRL(6) | AT32_TMR_CM2_C4OBEN;
  }
  else {
    /* Driver re-configuration scenario, it must be stopped first.*/
    pwmp->tmr->CTRL1  = 0;                  /* Timer disabled.              */
    pwmp->tmr->CDT[0] = 0;                  /* Comparator 1 disabled.       */
    pwmp->tmr->CDT[1] = 0;                  /* Comparator 2 disabled.       */
    pwmp->tmr->CDT[2] = 0;                  /* Comparator 3 disabled.       */
    pwmp->tmr->CDT[3] = 0;                  /* Comparator 4 disabled.       */
    pwmp->tmr->CVAL   = 0;                  /* Counter reset to zero.       */
  }

  /* If timer counter is 32bits.*/
  if (pwmp->has_plus_mode) {
    pwmp->tmr->CTRL1 = AT32_TMR_CTRL1_PMEN;
  }

  /* Timer configuration.*/
  div = (pwmp->clock / pwmp->config->frequency) - 1;
  osalDbgAssert((div <= 0xFFFF) &&
                ((div + 1) * pwmp->config->frequency) == pwmp->clock,
                "invalid frequency");
  pwmp->tmr->DIV   = div;
  pwmp->tmr->PR    = pwmp->period - 1;
  pwmp->tmr->CTRL2 = pwmp->config->ctrl2;

  /* Output enables and polarities setup.*/
  cctrl = 0;
  switch (pwmp->config->channels[0].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    cctrl |= AT32_TMR_CCTRL_C1P;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    cctrl |= AT32_TMR_CCTRL_C1EN;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[1].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    cctrl |= AT32_TMR_CCTRL_C2P;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    cctrl |= AT32_TMR_CCTRL_C2EN;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[2].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    cctrl |= AT32_TMR_CCTRL_C3P;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    cctrl |= AT32_TMR_CCTRL_C3EN;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[3].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    cctrl |= AT32_TMR_CCTRL_C4P;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    cctrl |= AT32_TMR_CCTRL_C4EN;
    /* Falls through.*/
  default:
    ;
  }
  if (pwmp->has_brk) {
    switch (pwmp->config->channels[0].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      cctrl |= AT32_TMR_CCTRL_C1CP;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      cctrl |= AT32_TMR_CCTRL_C1CEN;
      /* Falls through.*/
    default:
      ;
    }
    switch (pwmp->config->channels[1].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      cctrl |= AT32_TMR_CCTRL_C2CP;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      cctrl |= AT32_TMR_CCTRL_C2CEN;
      /* Falls through.*/
    default:
      ;
    }
    switch (pwmp->config->channels[2].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      cctrl |= AT32_TMR_CCTRL_C3CP;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      cctrl |= AT32_TMR_CCTRL_C3CEN;
      /* Falls through.*/
    default:
      ;
    }
  }

  pwmp->tmr->CCTRL = cctrl;
  pwmp->tmr->SWEVT = AT32_TMR_SWEVT_OVFSWTR; /* Update event.                */
  pwmp->tmr->ISTS  = 0;                      /* Clear pending IRQs.          */
  pwmp->tmr->IDEN  = pwmp->config->iden &    /* DMA-related IDEN settings.   */
                     ~AT32_TMR_IDEN_IRQ_MASK;
  if (pwmp->has_brk) {
    pwmp->tmr->BRK = pwmp->config->brk | AT32_TMR_BRK_OEN;
  }
  /* Timer configured and started.*/
  pwmp->tmr->CTRL1 |= AT32_TMR_CTRL1_PRBEN | AT32_TMR_CTRL1_OVFS |
                      AT32_TMR_CTRL1_TMREN;
}

/**
 * @brief   Deactivates the PWM peripheral.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_stop(PWMDriver *pwmp) {

  /* If in ready state then disables the PWM clock.*/
  if (pwmp->state == PWM_READY) {
    pwmp->tmr->CTRL1 = 0;                   /* Timer disabled.              */
    pwmp->tmr->IDEN  = 0;                   /* All IRQs disabled.           */
    pwmp->tmr->ISTS  = 0;                   /* Clear eventual pending IRQs. */
    if (pwmp->has_brk) {
      pwmp->tmr->BRK = 0;
    }

#if AT32_PWM_USE_TMR1
    if (&PWMD1 == pwmp) {
#if !defined(AT32_TMR1_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR1_OVF_NUMBER);
      nvicDisableVector(AT32_TMR1_CH_NUMBER);
#endif
      crmDisableTMR1();
    }
#endif

#if AT32_PWM_USE_TMR2
    if (&PWMD2 == pwmp) {
#if !defined(AT32_TMR2_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR2_NUMBER);
#endif
      crmDisableTMR2();
    }
#endif

#if AT32_PWM_USE_TMR3
    if (&PWMD3 == pwmp) {
#if !defined(AT32_TMR3_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR3_NUMBER);
#endif
      crmDisableTMR3();
    }
#endif

#if AT32_PWM_USE_TMR4
    if (&PWMD4 == pwmp) {
#if !defined(AT32_TMR4_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR4_NUMBER);
#endif
      crmDisableTMR4();
    }
#endif

#if AT32_PWM_USE_TMR5
    if (&PWMD5 == pwmp) {
#if !defined(AT32_TMR5_SUPPRESS_ISR)
      nvicDisableVector(AT32_TMR5_NUMBER);
#endif
      crmDisableTMR5();
    }
#endif

#if AT32_PWM_USE_TMR9
    if (&PWMD9 == pwmp) {
      crmDisableTMR9();
    }
#endif

#if AT32_PWM_USE_TMR10
    if (&PWMD10 == pwmp) {
      crmDisableTMR10();
    }
#endif

#if AT32_PWM_USE_TMR11
    if (&PWMD11 == pwmp) {
      crmDisableTMR11();
    }
#endif
  }
}

/**
 * @brief   Enables a PWM channel.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The channel is active using the specified configuration.
 * @note    The function has effect at the next cycle start.
 * @note    Channel notification is not enabled.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 * @param[in] width     PWM pulse width as clock pulses number
 *
 * @notapi
 */
void pwm_lld_enable_channel(PWMDriver *pwmp,
                            pwmchannel_t channel,
                            pwmcnt_t width) {

  /* Changing channel duty cycle on the fly.*/
  pwmp->tmr->CDT[channel] = width;
}

/**
 * @brief   Disables a PWM channel and its notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The channel is disabled and its output line returned to the
 *          idle state.
 * @note    The function has effect at the next cycle start.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel) {

  pwmp->tmr->CDT[channel] = 0;
  pwmp->tmr->IDEN &= ~(2 << channel);
}

/**
 * @brief   Enables the periodic activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_enable_periodic_notification(PWMDriver *pwmp) {
  uint32_t iden = pwmp->tmr->IDEN;

  /* If the IRQ is not already enabled care must be taken to clear it,
     it is probably already pending because the timer is running.*/
  if ((iden & AT32_TMR_IDEN_OVFIEN) == 0) {
    pwmp->tmr->ISTS = ~AT32_TMR_ISTS_OVFIF;
    pwmp->tmr->IDEN = iden | AT32_TMR_IDEN_OVFIEN;
  }
}

/**
 * @brief   Disables the periodic activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_disable_periodic_notification(PWMDriver *pwmp) {

  pwmp->tmr->IDEN &= ~AT32_TMR_IDEN_OVFIEN;
}

/**
 * @brief   Enables a channel de-activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @pre     The channel must have been activated using @p pwmEnableChannel().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_enable_channel_notification(PWMDriver *pwmp,
                                         pwmchannel_t channel) {
  uint32_t iden = pwmp->tmr->IDEN;

  /* If the IRQ is not already enabled care must be taken to clear it,
     it is probably already pending because the timer is running.*/
  if ((iden & (2 << channel)) == 0) {
    pwmp->tmr->ISTS = ~(2 << channel);
    pwmp->tmr->IDEN = iden | (2 << channel);
  }
}

/**
 * @brief   Disables a channel de-activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @pre     The channel must have been activated using @p pwmEnableChannel().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_disable_channel_notification(PWMDriver *pwmp,
                                          pwmchannel_t channel) {

  pwmp->tmr->IDEN &= ~(2 << channel);
}

/**
 * @brief   Common TMR2...TMR5,TMR9 IRQ handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_serve_interrupt(PWMDriver *pwmp) {
  uint32_t ists;

  ists  = pwmp->tmr->ISTS;
  ists &= pwmp->tmr->IDEN & AT32_TMR_IDEN_IRQ_MASK;
  pwmp->tmr->ISTS = ~ists;
  if (((ists & AT32_TMR_ISTS_C1IF) != 0) &&
      (pwmp->config->channels[0].callback != NULL))
    pwmp->config->channels[0].callback(pwmp);
  if (((ists & AT32_TMR_ISTS_C2IF) != 0) &&
      (pwmp->config->channels[1].callback != NULL))
    pwmp->config->channels[1].callback(pwmp);
  if (((ists & AT32_TMR_ISTS_C3IF) != 0) &&
      (pwmp->config->channels[2].callback != NULL))
    pwmp->config->channels[2].callback(pwmp);
  if (((ists & AT32_TMR_ISTS_C4IF) != 0) &&
      (pwmp->config->channels[3].callback != NULL))
    pwmp->config->channels[3].callback(pwmp);
  if (((ists & AT32_TMR_ISTS_OVFIF) != 0) && (pwmp->config->callback != NULL))
    pwmp->config->callback(pwmp);
}

#endif /* HAL_USE_PWM */

/** @} */

/*
    Copyright (C) 2020

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
 * @file    hal_pwm_lld.c
 * @brief   ES32 PWM subsystem low level driver source.
 *
 * @addtogroup PWM
 * @{
 */

#include "hal.h"

#if (HAL_USE_PWM == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   PWM_AD16C4T1 driver identifier.
 * @note    The driver PWM_AD16C4T1 allocates the complex timer AD16C4T1 when enabled.
 */
#if ES32_PWM_USE_AD16C4T1 || defined(__DOXYGEN__)
PWMDriver PWM_AD16C4T1;
#endif

/**
 * @brief   PWM_GP32C4T1 driver identifier.
 * @note    The driver PWM_GP32C4T1 allocates the timer GP32C4T1 when enabled.
 */
#if ES32_PWM_USE_GP32C4T1 || defined(__DOXYGEN__)
PWMDriver PWM_GP32C4T1;
#endif

/**
 * @brief   PWM_GP16C4T1 driver identifier.
 * @note    The driver PWM_GP16C4T1 allocates the timer GP16C4T1 when enabled.
 */
#if ES32_PWM_USE_GP16C4T1 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C4T1;
#endif

/**
 * @brief   PWM_GP16C4T2 driver identifier.
 * @note    The driver PWM_GP16C4T2 allocates the timer GP16C4T2 when enabled.
 */
#if ES32_PWM_USE_GP16C4T2 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C4T2;
#endif

/**
 * @brief   PWM_GP16C4T3 driver identifier.
 * @note    The driver PWM_GP16C4T3 allocates the timer GP16C4T3 when enabled.
 */
#if ES32_PWM_USE_GP16C4T3 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C4T3;
#endif

/**
 * @brief   PWM_GP16C2T1 driver identifier.
 * @note    The driver PWM_GP16C2T1 allocates the timer GP16C2T1 when enabled.
 */
#if ES32_PWM_USE_GP16C2T1 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C2T1;
#endif

/**
 * @brief   PWM_GP16C2T2 driver identifier.
 * @note    The driver PWM_GP16C2T2 allocates the timer GP16C2T2 when enabled.
 */
#if ES32_PWM_USE_GP16C2T2 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C2T2;
#endif

/**
 * @brief   PWM_GP16C2T3 driver identifier.
 * @note    The driver PWM_GP16C2T3 allocates the timer GP16C2T3 when enabled.
 */
#if ES32_PWM_USE_GP16C2T3 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C2T3;
#endif

/**
 * @brief   PWM_GP16C2T4 driver identifier.
 * @note    The driver PWM_GP16C2T4 allocates the timer GP16C2T4 when enabled.
 */
#if ES32_PWM_USE_GP16C2T4 || defined(__DOXYGEN__)
PWMDriver PWM_GP16C2T4;
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

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level PWM driver initialization.
 *
 * @notapi
 */
void pwm_lld_init(void) {

#if ES32_PWM_USE_AD16C4T1
  /* Driver initialization.*/
  pwmObjectInit(&PWM_AD16C4T1);
  PWM_AD16C4T1.channels = 4;
  PWM_AD16C4T1.tim = AD16C4T1;
  PWM_AD16C4T1.has_bdcfg = true;
#endif

#if ES32_PWM_USE_GP32C4T1
  /* Driver initialization.*/
  pwmObjectInit(&PWM_GP32C4T1);
  PWM_GP32C4T1.channels = 4;
  PWM_GP32C4T1.tim = GP32C4T1;
  PWM_GP32C4T1.has_bdcfg = false;
#endif

#if ES32_PWM_USE_GP16C4T1
  /* Driver initialization.*/
  pwmObjectInit(&PWM_GP16C4T1);
  PWM_GP16C4T1.channels = 4;
  PWM_GP16C4T1.tim = GP16C4T1;
  PWM_GP16C4T1.has_bdcfg = false;
#endif

#if ES32_PWM_USE_GP16C4T2
  /* Driver initialization.*/
  pwmObjectInit(&PWM_GP16C4T2);
  PWM_GP16C4T2.channels = 4;
  PWM_GP16C4T2.tim = GP16C4T2;
  PWM_GP16C4T2.has_bdcfg = false;
#endif

#if ES32_PWM_USE_GP16C4T3
  /* Driver initialization.*/
  pwmObjectInit(&PWM_GP16C4T3);
  PWM_GP16C4T3.channels = 4;
  PWM_GP16C4T3.tim = GP16C4T3;
  PWM_GP16C4T3.has_bdcfg = false;
#endif

#if ES32_PWM_USE_GP16C2T1
  /* Driver initialization.*/
  pwmObjectInit(&PWM_GP16C2T1);
  PWM_GP16C2T1.channels = 2;
  PWM_GP16C2T1.tim = GP16C2T1;
  PWM_GP16C2T1.has_bdcfg = true;
#endif

#if ES32_PWM_USE_GP16C2T2
  /* Driver initialization.*/
  pwmObjectInit(&PWM_GP16C2T2);
  PWM_GP16C2T2.channels = 2;
  PWM_GP16C2T2.tim = GP16C2T2;
  PWM_GP16C2T2.has_bdcfg = true;
#endif

#if ES32_PWM_USE_GP16C2T3
  /* Driver initialization.*/
  pwmObjectInit(&PWM_GP16C2T3);
  PWM_GP16C2T3.channels = 2;
  PWM_GP16C2T3.tim = GP16C2T3;
  PWM_GP16C2T3.has_bdcfg = true;
#endif

#if ES32_PWM_USE_GP16C2T4
  /* Driver initialization.*/
  pwmObjectInit(&PWM_GP16C2T4);
  PWM_GP16C2T4.channels = 2;
  PWM_GP16C2T4.tim = GP16C2T4;
  PWM_GP16C2T4.has_bdcfg = true;
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
  uint32_t psc;
  uint32_t ccer;

  if (pwmp->state == PWM_STOP) {
    /* Clock activation and timer reset.*/
#if ES32_PWM_USE_AD16C4T1
    if (&PWM_AD16C4T1 == pwmp) {
      RCU->APB2EN |= RCU_APB2EN_AD16C4T1EN;
      RCU->APB2RST |= RCU_APB2RST_AD16C4T1EN;
      RCU->APB2RST &= ~RCU_APB2RST_AD16C4T1EN;
    }
#endif

#if ES32_PWM_USE_GP32C4T1
    if (&PWM_GP32C4T1 == pwmp) {
      RCU->APB1EN |= RCU_APB1EN_GP32C4T1EN;
      RCU->APB1RST |= RCU_APB1RST_GP32C4T1EN;
      RCU->APB1RST &= ~RCU_APB1RST_GP32C4T1EN;
    }
#endif

#if ES32_PWM_USE_GP16C4T1
    if (&PWM_GP16C4T1 == pwmp) {
      RCU->APB1EN |= RCU_APB1EN_GP16C4T1EN;
      RCU->APB1RST |= RCU_APB1RST_GP16C4T1EN;
      RCU->APB1RST &= ~RCU_APB1RST_GP16C4T1EN;
    }
#endif

#if ES32_PWM_USE_GP16C4T2
    if (&PWM_GP16C4T2 == pwmp) {
      RCU->APB1EN |= RCU_APB1EN_GP16C4T2EN;
      RCU->APB1RST |= RCU_APB1RST_GP16C4T2EN;
      RCU->APB1RST &= ~RCU_APB1RST_GP16C4T2EN;
    }
#endif

#if ES32_PWM_USE_GP16C4T3
    if (&PWM_GP16C4T3 == pwmp) {
      RCU->APB1EN |= RCU_APB1EN_GP16C4T3EN;
      RCU->APB1RST |= RCU_APB1RST_GP16C4T3EN;
      RCU->APB1RST &= ~RCU_APB1RST_GP16C4T3EN;
    }
#endif

#if ES32_PWM_USE_GP16C2T1
    if (&PWM_GP16C2T1 == pwmp) {
      RCU->APB2EN |= RCU_APB2EN_GP16C2T1EN;
      RCU->APB2RST |= RCU_APB2RST_GP16C2T1EN;
      RCU->APB2RST &= ~RCU_APB2RST_GP16C2T1EN;
    }
#endif

#if ES32_PWM_USE_GP16C2T2
    if (&PWM_GP16C2T2 == pwmp) {
      RCU->APB2EN |= RCU_APB2EN_GP16C2T2EN;
      RCU->APB2RST |= RCU_APB2RST_GP16C2T2EN;
      RCU->APB2RST &= ~RCU_APB2RST_GP16C2T2EN;
    }
#endif

#if ES32_PWM_USE_GP16C2T3
    if (&PWM_GP16C2T3 == pwmp) {
      RCU->APB2EN |= RCU_APB2EN_GP16C2T3EN;
      RCU->APB2RST |= RCU_APB2RST_GP16C2T3EN;
      RCU->APB2RST &= ~RCU_APB2RST_GP16C2T3EN;
    }
#endif

#if ES32_PWM_USE_GP16C2T4
    if (&PWM_GP16C2T4 == pwmp) {
      RCU->APB2EN |= RCU_APB2EN_GP16C2T4EN;
      RCU->APB2RST |= RCU_APB2RST_GP16C2T4EN;
      RCU->APB2RST &= ~RCU_APB2RST_GP16C2T4EN;
    }
#endif

    /* All channels configured in PWM1 mode with preload enabled and will
       stay that way until the driver is stopped.*/
    md_timer_set_output_compare1_mode_ch1mod(pwmp->tim, MD_TIMER_OUTPUTMODE_PWMMODE1);
    md_timer_set_output_compare2_mode_ch2mod(pwmp->tim, MD_TIMER_OUTPUTMODE_PWMMODE1);
    md_timer_set_output_compare3_mode_ch3mod(pwmp->tim, MD_TIMER_OUTPUTMODE_PWMMODE1);
    md_timer_set_output_compare4_mode_ch4mod(pwmp->tim, MD_TIMER_OUTPUTMODE_PWMMODE1);
    md_timer_enable_output_compare1_preload_ch1pen(pwmp->tim);
    md_timer_enable_output_compare2_preload_ch2pen(pwmp->tim);
    md_timer_enable_output_compare3_preload_ch3pen(pwmp->tim);
    md_timer_enable_output_compare4_preload_ch4pen(pwmp->tim);
  }
  else {
    /* Driver re-configuration scenario, it must be stopped first.*/
    md_timer_set_con1(pwmp->tim, DISABLE);                                  /* Timer disabled.              */
    md_timer_set_capture_compare1_value_ccrv1(pwmp->tim, DISABLE);          /* Comparator 1 disabled.       */
    md_timer_set_capture_compare2_value_ccrv2(pwmp->tim, DISABLE);          /* Comparator 2 disabled.       */
    md_timer_set_capture_compare3_value_ccrv3(pwmp->tim, DISABLE);          /* Comparator 3 disabled.       */
    md_timer_set_capture_compare4_value_ccrv4(pwmp->tim, DISABLE);          /* Comparator 4 disabled.       */
    md_timer_set_counter_value_cntv(pwmp->tim, DISABLE);                    /* Counter reset to zero.       */
  }

  /* Timer configuration.*/
  psc = (SystemFrequency_APBClk / pwmp->config->frequency) - 1;
  md_timer_set_prescaler_value_pscv(pwmp->tim, psc);
  md_timer_set_auto_reload_value_arrv(pwmp->tim, pwmp->period - 1);
  md_timer_set_con2(pwmp->tim, pwmp->config->con2);

  /* Output enables and polarities setup.*/
  ccer = 0;
  switch (pwmp->config->channels[0].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    ccer |= TIMER_CCEP_CC1POL;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    ccer |= TIMER_CCEP_CC1EN;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[1].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    ccer |= TIMER_CCEP_CC2POL;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    ccer |= TIMER_CCEP_CC2EN;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[2].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    ccer |= TIMER_CCEP_CC3POL;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    ccer |= TIMER_CCEP_CC3EN;
    /* Falls through.*/
  default:
    ;
  }
  switch (pwmp->config->channels[3].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    ccer |= TIMER_CCEP_CC4POL;
    /* Falls through.*/
  case PWM_OUTPUT_ACTIVE_HIGH:
    ccer |= TIMER_CCEP_CC4EN;
    /* Falls through.*/
  default:
    ;
  }
  if (pwmp->has_bdcfg) {
    switch (pwmp->config->channels[0].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      ccer |= TIMER_CCEP_CC1NPOL;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      ccer |= TIMER_CCEP_CC1NEN;
      /* Falls through.*/
    default:
      ;
    }
    switch (pwmp->config->channels[1].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      ccer |= TIMER_CCEP_CC2NPOL;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      ccer |= TIMER_CCEP_CC2NEN;
      /* Falls through.*/
    default:
      ;
    }
    switch (pwmp->config->channels[2].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      ccer |= TIMER_CCEP_CC3NPOL;
      /* Falls through.*/
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH:
      ccer |= TIMER_CCEP_CC3NEN;
      /* Falls through.*/
    default:
      ;
    }
    switch (pwmp->config->channels[3].mode & PWM_COMPLEMENTARY_OUTPUT_MASK) {
    case PWM_COMPLEMENTARY_OUTPUT_ACTIVE_LOW:
      ccer |= TIMER_CCEP_CC4NPOL;
      /* Falls through.*/
    default:
      ;
    }
  }

  md_timer_set_ccep(pwmp->tim, ccer);
  md_timer_set_sge(pwmp->tim, TIMER_SGE_SGUPD);                  /* Update event.                */
  md_timer_set_icr(pwmp->tim, PWM_COMPLEMENTARY_INTERRUPT_MASK); /* Clear pending IRQs.          */
  md_timer_set_dmaen(pwmp->tim, pwmp->config->dmaen);
  
  if (pwmp->has_bdcfg) {
    md_timer_set_bdcfg(pwmp->tim, pwmp->config->bdcfg | TIMER_BDCFG_GOEN);
  }
  /* Timer configured and started.*/
  md_timer_set_con1(pwmp->tim, TIMER_CON1_ARPEN | TIMER_CON1_UERSEL |
                               TIMER_CON1_CNTEN);
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
    md_timer_set_con1(pwmp->tim, DISABLE);                         /* Timer disabled.              */
    md_timer_set_idr(pwmp->tim, PWM_COMPLEMENTARY_INTERRUPT_MASK); /* All IRQs disabled.           */
    md_timer_set_icr(pwmp->tim, PWM_COMPLEMENTARY_INTERRUPT_MASK); /* Clear eventual pending IRQs. */
    if (pwmp->has_bdcfg) {
      md_timer_set_bdcfg(pwmp->tim, DISABLE);
    }

#if ES32_PWM_USE_AD16C4T1
    if (&PWM_AD16C4T1 == pwmp) {
      RCU->APB2EN &= ~RCU_APB2EN_AD16C4T1EN;
    }
#endif

#if ES32_PWM_USE_GP32C4T1
    if (&PWM_GP32C4T1 == pwmp) {
      RCU->APB1EN &= ~RCU_APB1EN_GP32C4T1EN;
    }
#endif

#if ES32_PWM_USE_GP16C4T1
    if (&PWM_GP16C4T1 == pwmp) {
      RCU->APB1EN &= ~RCU_APB1EN_GP16C4T1EN;
    }
#endif

#if ES32_PWM_USE_GP16C4T2
    if (&PWM_GP16C4T2 == pwmp) {
      RCU->APB1EN &= ~RCU_APB1EN_GP16C4T2EN;
    }
#endif

#if ES32_PWM_USE_GP16C4T3
    if (&PWM_GP16C4T3 == pwmp) {
      RCU->APB1EN &= ~RCU_APB1EN_GP16C4T3EN;
    }
#endif

#if ES32_PWM_USE_GP16C2T1
    if (&PWM_GP16C2T1 == pwmp) {
      RCU->APB2EN &= ~RCU_APB2EN_GP16C2T1EN;
    }
#endif

#if ES32_PWM_USE_GP16C2T2
    if (&PWM_GP16C2T2 == pwmp) {
      RCU->APB2EN &= ~RCU_APB2EN_GP16C2T2EN;
    }
#endif

#if ES32_PWM_USE_GP16C2T3
    if (&PWM_GP16C2T3 == pwmp) {
      RCU->APB2EN &= ~RCU_APB2EN_GP16C2T3EN;
    }
#endif

#if ES32_PWM_USE_GP16C2T4
    if (&PWM_GP16C2T4 == pwmp) {
      RCU->APB2EN &= ~RCU_APB2EN_GP16C2T4EN;
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
#if PWM_CHANNELS <= 4
  switch(channel)
  {
    case 0:
      md_timer_set_capture_compare1_value_ccrv1(pwmp->tim, width);
      break;
    case 1:
      md_timer_set_capture_compare2_value_ccrv2(pwmp->tim, width);
      break;
    case 2:
      md_timer_set_capture_compare3_value_ccrv3(pwmp->tim, width);
      break;
    case 3:
      md_timer_set_capture_compare4_value_ccrv4(pwmp->tim, width);
      break;
    default:
      break;
  }
#endif
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

#if PWM_CHANNELS <= 4
  switch(channel)
  {
    case 0:
      md_timer_set_capture_compare1_value_ccrv1(pwmp->tim, DISABLE);
      md_timer_disable_it_ch1(pwmp->tim);
      break;
    case 1:
      md_timer_set_capture_compare2_value_ccrv2(pwmp->tim, DISABLE);
      md_timer_disable_it_ch2(pwmp->tim);
      break;
    case 2:
      md_timer_set_capture_compare3_value_ccrv3(pwmp->tim, DISABLE);
      md_timer_disable_it_ch3(pwmp->tim);
      break;
    case 3:
      md_timer_set_capture_compare4_value_ccrv4(pwmp->tim, DISABLE);
      md_timer_disable_it_ch4(pwmp->tim);
      break;
    default:
      break;
  }
#endif
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
  uint32_t intr_flag = md_timer_get_ivs(pwmp->tim);

  /* If the IRQ is not already enabled care must be taken to clear it,
     it is probably already pending because the timer is running.*/
  if ((intr_flag & TIMER_IVS_UPD) == 0) {
    md_timer_clear_it_upd(pwmp->tim);
    md_timer_enable_it_upd(pwmp->tim);
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

  md_timer_disable_it_upd(pwmp->tim);
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
  uint32_t intr_flag = md_timer_get_ivs(pwmp->tim);

  /* If the IRQ is not already enabled care must be taken to clear it,
     it is probably already pending because the timer is running.*/
  if ((intr_flag & (2 << channel)) == 0) {
    md_timer_set_icr(pwmp->tim, 2 << channel);
    md_timer_set_ier(pwmp->tim, intr_flag | (2 << channel));
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

  md_timer_set_idr(pwmp->tim, 2 << channel);
}

/**
 * @brief   Common TIM2...TIM5,TIM9 IRQ handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_serve_interrupt(PWMDriver *pwmp) {
  uint32_t intr_flag;

  intr_flag  = md_timer_get_ifm(pwmp->tim);
  md_timer_set_icr(pwmp->tim, intr_flag);
  if (((intr_flag & TIMER_IFM_CH1) != 0) &&
      (pwmp->config->channels[0].callback != NULL))
    pwmp->config->channels[0].callback(pwmp);
  if (((intr_flag & TIMER_IFM_CH2) != 0) &&
      (pwmp->config->channels[1].callback != NULL))
    pwmp->config->channels[1].callback(pwmp);
  if (((intr_flag & TIMER_IFM_CH3) != 0) &&
      (pwmp->config->channels[2].callback != NULL))
    pwmp->config->channels[2].callback(pwmp);
  if (((intr_flag & TIMER_IFM_CH4) != 0) &&
      (pwmp->config->channels[3].callback != NULL))
    pwmp->config->channels[3].callback(pwmp);
  if (((intr_flag & TIMER_IFM_UPD) != 0) && (pwmp->config->callback != NULL))
    pwmp->config->callback(pwmp);
}

#endif /* HAL_USE_PWM == TRUE */

/** @} */

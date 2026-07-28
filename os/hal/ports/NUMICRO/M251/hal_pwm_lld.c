/*
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
 * @file    M251/hal_pwm_lld.c
 * @brief   M251/M252 PWM subsystem low level driver source.
 *
 * @addtogroup PWM
 * @{
 */

#include "hal.h"

#if (HAL_USE_PWM == TRUE) || defined(__DOXYGEN__)

#include "m251_isr.h"
#include "M251/stddriver/bpwm.h"
#include "M251/stddriver/clk.h"

#define BPWM_WGCTL0_CH_MASK(ch)                                           \
  (BPWM_WGCTL0_ZPCTL0_Msk << ((ch) * 2))
#define BPWM_WGCTL0_CH_PRDP_MASK(ch)                                      \
  (BPWM_WGCTL0_PRDPCTL0_Msk << ((ch) * 2))
#define BPWM_WGCTL1_CH_CMPU_MASK(ch)                                      \
  (BPWM_WGCTL1_CMPUCTL0_Msk << ((ch) * 2))
#define BPWM_WGCTL1_CH_CMPD_MASK(ch)                                      \
  (BPWM_WGCTL1_CMPDCTL0_Msk << ((ch) * 2))

#define BPWM_WGCTL0_CH_VAL(ch, val)                                       \
  (((uint32_t)(val) & 0x3U) << ((ch) * 2))
#define BPWM_WGCTL0_CH_PRDP_VAL(ch, val)                                  \
  (((uint32_t)(val) & 0x3U) << ((ch) * 2))
#define BPWM_WGCTL1_CH_CMPU_VAL(ch, val)                                  \
  (((uint32_t)(val) & 0x3U) << ((ch) * 2))
#define BPWM_WGCTL1_CH_CMPD_VAL(ch, val)                                  \
  (((uint32_t)(val) & 0x3U) << ((ch) * 2 + 16U))

static uint32_t _bpwm_get_pclk(uint32_t mask, uint32_t pos) {
  uint32_t code = (CLK->PCLKDIV & mask) >> pos;

  return SystemCoreClock >> code;
}

static uint32_t _bpwm_ticks_to_counts(const PWMDriver *pwmp,
                                      pwmcnt_t ticks) {
  uint64_t numerator = (uint64_t)pwmp->clock * ticks;
  uint64_t denominator = (uint64_t)pwmp->config->frequency *
                         pwmp->clock_divisor;

  return (uint32_t)((numerator + denominator / 2U) / denominator);
}

static void _bpwm_configure_wgctl(PWMDriver *pwmp, pwmchannel_t ch) {
  BPWM_T *bpwm = pwmp->bpwm;
  pwmmode_t mode = pwmp->config->channels[ch].mode & PWM_OUTPUT_MASK;
  uint32_t zero_action = BPWM_OUTPUT_NOTHING;
  uint32_t compare_action = BPWM_OUTPUT_NOTHING;

  if (mode == PWM_OUTPUT_ACTIVE_HIGH) {
    zero_action = BPWM_OUTPUT_HIGH;
    compare_action = BPWM_OUTPUT_LOW;
  }
  else if (mode == PWM_OUTPUT_ACTIVE_LOW) {
    zero_action = BPWM_OUTPUT_LOW;
    compare_action = BPWM_OUTPUT_HIGH;
  }

  bpwm->WGCTL0 = (bpwm->WGCTL0 & ~BPWM_WGCTL0_CH_MASK(ch)) |
                  BPWM_WGCTL0_CH_VAL(ch, zero_action);

  bpwm->WGCTL1 = (bpwm->WGCTL1 & ~BPWM_WGCTL1_CH_CMPU_MASK(ch)) |
                  BPWM_WGCTL1_CH_CMPU_VAL(ch, compare_action);
}

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   PWMD1 (BPWM0) driver identifier.
 */
#if (M251_PWM_USE_BPWM0 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD1;
#endif

/**
 * @brief   PWMD2 (BPWM1) driver identifier.
 */
#if (M251_PWM_USE_BPWM1 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD2;
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level PWM driver initialization.
 *
 * @notapi
 */
void pwm_lld_init(void) {

#if (M251_PWM_USE_BPWM0 == TRUE)
  pwmObjectInit(&PWMD1);
  PWMD1.channels = PWM_CHANNELS;
  PWMD1.bpwm     = BPWM0;
  PWMD1.clock    = 0U;
  PWMD1.clock_divisor = 1U;
#endif

#if (M251_PWM_USE_BPWM1 == TRUE)
  pwmObjectInit(&PWMD2);
  PWMD2.channels = PWM_CHANNELS;
  PWMD2.bpwm     = BPWM1;
  PWMD2.clock    = 0U;
  PWMD2.clock_divisor = 1U;
#endif
}

/**
 * @brief   Configures and activates the PWM peripheral.
 * @note    Starting a driver that is already in the @p PWM_READY state
 *          disables all active channels.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_start(PWMDriver *pwmp) {
  uint32_t psc;
  uint32_t raw_period;
  uint32_t bpwm_clk = pwmp->clock;

  if (pwmp->state == PWM_STOP) {
#if (M251_PWM_USE_BPWM0 == TRUE)
    if (pwmp == &PWMD1) {
      m251_lld_unlock();
      CLK->APBCLK1 |= CLK_APBCLK1_BPWM0CKEN_Msk;
      SYS->IPRST2 |= SYS_IPRST2_BPWM0RST_Msk;
      SYS->IPRST2 &= ~SYS_IPRST2_BPWM0RST_Msk;
      CLK->CLKSEL2 = (CLK->CLKSEL2 & ~CLK_CLKSEL2_BPWM0SEL_Msk) |
                      CLK_CLKSEL2_BPWM0SEL_PCLK0;
      m251_lld_lock();
      nvicEnableVector(M251_BPWM0_NUMBER, M251_PWM_BPWM0_IRQ_PRIORITY);
      bpwm_clk = _bpwm_get_pclk(CLK_PCLKDIV_APB0DIV_Msk,
                                CLK_PCLKDIV_APB0DIV_Pos);
    }
#endif
#if (M251_PWM_USE_BPWM1 == TRUE)
    if (pwmp == &PWMD2) {
      m251_lld_unlock();
      CLK->APBCLK1 |= CLK_APBCLK1_BPWM1CKEN_Msk;
      SYS->IPRST2 |= SYS_IPRST2_BPWM1RST_Msk;
      SYS->IPRST2 &= ~SYS_IPRST2_BPWM1RST_Msk;
      CLK->CLKSEL2 = (CLK->CLKSEL2 & ~CLK_CLKSEL2_BPWM1SEL_Msk) |
                      CLK_CLKSEL2_BPWM1SEL_PCLK1;
      m251_lld_lock();
      nvicEnableVector(M251_BPWM1_NUMBER, M251_PWM_BPWM1_IRQ_PRIORITY);
      bpwm_clk = _bpwm_get_pclk(CLK_PCLKDIV_APB1DIV_Msk,
                                CLK_PCLKDIV_APB1DIV_Pos);
    }
#endif
    pwmp->clock = bpwm_clk;
  }

  osalDbgAssert((pwmp->config->frequency > 0U) &&
                (pwmp->config->period > 0U),
                "invalid PWM configuration");

  psc = (uint32_t)(((uint64_t)pwmp->clock * pwmp->config->period +
                    (uint64_t)pwmp->config->frequency * 0x10000U - 1U) /
                   ((uint64_t)pwmp->config->frequency * 0x10000U));
  if (psc == 0U)
    psc = 1U;
  osalDbgAssert(psc <= 0x1000U, "PWM period out of range");
  pwmp->clock_divisor = (uint16_t)psc;

  raw_period = _bpwm_ticks_to_counts(pwmp, pwmp->config->period);
  osalDbgAssert((raw_period > 0U) && (raw_period <= 0x10000U),
                "PWM period out of range");

  /* A READY-to-READY start must disable the previous configuration first.*/
  pwmp->bpwm->POEN = 0U;
  pwmp->bpwm->INTEN = 0U;
  pwmp->bpwm->CTL0 = 0U;
  pwmp->bpwm->CTL1 = 0U;
  pwmp->bpwm->CNTEN = 0U;
  pwmp->bpwm->INTSTS = BPWM_INTSTS_ZIF0_Msk |
                       BPWM_INTSTS_PIF0_Msk |
                       (BPWM_INTSTS_CMPUIF0_Msk * 0x3FU) |
                       (BPWM_INTSTS_CMPDIF0_Msk * 0x3FU);

  pwmp->bpwm->CLKPSC = psc - 1U;

  for (pwmchannel_t i = 0U; i < PWM_CHANNELS; i++)
    _bpwm_configure_wgctl(pwmp, i);

  pwmp->bpwm->PERIOD = raw_period - 1U;

  pwmp->bpwm->CNTEN = BPWM_CNTEN_CNTEN0_Msk;
}

/**
 * @brief   Deactivates the PWM peripheral.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_stop(PWMDriver *pwmp) {

  pwmp->bpwm->CNTEN = 0U;
  pwmp->bpwm->POEN = 0U;
  pwmp->bpwm->INTEN = 0U;

#if (M251_PWM_USE_BPWM0 == TRUE)
  if (pwmp == &PWMD1) {
    nvicDisableVector(M251_BPWM0_NUMBER);
    m251_lld_unlock();
    CLK->APBCLK1 &= ~CLK_APBCLK1_BPWM0CKEN_Msk;
    m251_lld_lock();
  }
#endif
#if (M251_PWM_USE_BPWM1 == TRUE)
  if (pwmp == &PWMD2) {
    nvicDisableVector(M251_BPWM1_NUMBER);
    m251_lld_unlock();
    CLK->APBCLK1 &= ~CLK_APBCLK1_BPWM1CKEN_Msk;
    m251_lld_lock();
  }
#endif
}

/**
 * @brief   Changes the PWM period.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] period    new period in ticks
 *
 * @notapi
 */
void pwm_lld_change_period(PWMDriver *pwmp, pwmcnt_t period) {
  uint32_t raw_period = _bpwm_ticks_to_counts(pwmp, period);

  osalDbgAssert((raw_period > 0U) && (raw_period <= 0x10000U),
                "PWM period out of range");
  pwmp->bpwm->PERIOD = raw_period - 1U;
}

/**
 * @brief   Enables a PWM channel.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier
 * @param[in] width     PWM pulse width in ticks
 *
 * @notapi
 */
void pwm_lld_enable_channel(PWMDriver *pwmp,
                            pwmchannel_t channel,
                            pwmcnt_t width) {

  uint32_t raw_width = _bpwm_ticks_to_counts(pwmp, width);
  uint32_t raw_period = pwmp->bpwm->PERIOD + 1U;

  if (raw_width > raw_period)
    raw_width = raw_period;
  pwmp->bpwm->CMPDAT[channel] = raw_width;
  if ((pwmp->config->channels[channel].mode & PWM_OUTPUT_MASK) !=
      PWM_OUTPUT_DISABLED) {
    pwmp->bpwm->POEN |= (1UL << channel);
  }
}

/**
 * @brief   Disables a PWM channel and its notification.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier
 *
 * @notapi
 */
void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel) {

  pwmp->bpwm->POEN &= ~(1UL << channel);
}

/**
 * @brief   Enables the periodic interrupt.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_enable_periodic_notification(PWMDriver *pwmp) {

  pwmp->bpwm->INTSTS = BPWM_INTSTS_PIF0_Msk;
  pwmp->bpwm->INTEN |= BPWM_INTEN_PIEN0_Msk;
}

/**
 * @brief   Disables the periodic interrupt.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_disable_periodic_notification(PWMDriver *pwmp) {

  pwmp->bpwm->INTEN &= ~BPWM_INTEN_PIEN0_Msk;
}

/**
 * @brief   Enables a channel interrupt.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier
 *
 * @notapi
 */
void pwm_lld_enable_channel_notification(PWMDriver *pwmp,
                                         pwmchannel_t channel) {

  pwmp->bpwm->INTSTS = BPWM_INTSTS_CMPUIF0_Msk << channel;
  pwmp->bpwm->INTEN |=
      (BPWM_INTEN_CMPUIEN0_Msk << channel);
}

/**
 * @brief   Disables a channel interrupt.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier
 *
 * @notapi
 */
void pwm_lld_disable_channel_notification(PWMDriver *pwmp,
                                          pwmchannel_t channel) {

  pwmp->bpwm->INTEN &=
      ~(BPWM_INTEN_CMPUIEN0_Msk << channel);
}

#if (M251_PWM_USE_BPWM0 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   BPWM0 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_BPWM0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  uint32_t flags = PWMD1.bpwm->INTSTS;
  uint32_t enabled = PWMD1.bpwm->INTEN;

  PWMD1.bpwm->INTSTS = flags;

  if (((flags & BPWM_INTSTS_PIF0_Msk) != 0U) &&
      ((enabled & BPWM_INTEN_PIEN0_Msk) != 0U)) {
    if (PWMD1.config->callback != NULL)
      PWMD1.config->callback(&PWMD1);
  }

  for (pwmchannel_t i = 0U; i < PWM_CHANNELS; i++) {
    if (((flags & (BPWM_INTSTS_CMPUIF0_Msk << i)) != 0U) &&
        ((enabled & (BPWM_INTEN_CMPUIEN0_Msk << i)) != 0U)) {
      if (PWMD1.config->channels[i].callback != NULL)
        PWMD1.config->channels[i].callback(&PWMD1);
    }
  }

  OSAL_IRQ_EPILOGUE();
}
#endif

#if (M251_PWM_USE_BPWM1 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   BPWM1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_BPWM1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  uint32_t flags = PWMD2.bpwm->INTSTS;
  uint32_t enabled = PWMD2.bpwm->INTEN;

  PWMD2.bpwm->INTSTS = flags;

  if (((flags & BPWM_INTSTS_PIF0_Msk) != 0U) &&
      ((enabled & BPWM_INTEN_PIEN0_Msk) != 0U)) {
    if (PWMD2.config->callback != NULL)
      PWMD2.config->callback(&PWMD2);
  }

  for (pwmchannel_t i = 0U; i < PWM_CHANNELS; i++) {
    if (((flags & (BPWM_INTSTS_CMPUIF0_Msk << i)) != 0U) &&
        ((enabled & (BPWM_INTEN_CMPUIEN0_Msk << i)) != 0U)) {
      if (PWMD2.config->channels[i].callback != NULL)
        PWMD2.config->channels[i].callback(&PWMD2);
    }
  }

  OSAL_IRQ_EPILOGUE();
}
#endif

#endif /* HAL_USE_PWM == TRUE */

/** @} */

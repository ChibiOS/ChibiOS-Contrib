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
 * @file    CT/hal_pwm_lld.c
 * @brief   SN32 PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#include "hal.h"

#if HAL_USE_PWM || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define PWM_CLK                          SN32_HCLK
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   PWMD1 driver identifier.
 * @note    The driver PWMD1 allocates the complex timer CT16B1 when enabled.
 */
#if SN32_PWM_USE_CT16B1 || defined(__DOXYGEN__)
PWMDriver PWMD1;
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

#if SN32_PWM_USE_CT16B1 || defined(__DOXYGEN__)
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

  pwm_lld_serve_interrupt(&PWMD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SN32_CT16B0_SUPPRESS_ISR) */
#endif /* SN32_PWM_USE_CT16B1 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level PWM driver initialization.
 *
 * @notapi
 */
void pwm_lld_init(void) {

#if SN32_PWM_USE_CT16B1
  /* Driver initialization.*/
  pwmObjectInit(&PWMD1);
  PWMD1.channels = PWM_CHANNELS;
  PWMD1.ct = SN32_CT16B1;
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
  uint32_t pwmctrl;
  uint32_t pwmctrl2;
  uint32_t pwmen;
  uint32_t pwmioen;

  if (pwmp->state == PWM_STOP) {
    /* Clock activation and timer reset.*/
#if SN32_PWM_USE_CT16B1
    if (&PWMD1 == pwmp) {
      sys1EnableCT16B1();
      CT16B1_ResetTimer();
#if !defined(SN32_CT16B1_SUPPRESS_ISR)
      nvicEnableVector(SN32_CT16B1_NUMBER, SN32_PWM_CT16B1_IRQ_PRIORITY);
#endif
    pwmp->clock = PWM_CLK;
    }
#endif

#if defined(SN32F240B)
  /* PFPA - Map all PWM outputs to their PWM A pins */
  SN_PFPA->CT16B1 = 0x00000000;
  /* PFPA assignment for PWM B-pin mapping.*/
  for(uint8_t i=0; i<PWM_CHANNELS; i++){
    if(pwmp->config->channels[i].pfpamsk != 0) {
      SN_PFPA->CT16B1 |= (1<<i);
    }
  }
#endif

  /* Channel PWM mode selection and polarities setup.*/
  pwmctrl = 0;
  pwmctrl2 = 0;
  pwmen = 0;
  pwmioen = 0;
  switch (pwmp->config->channels[0].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM0MODE_1;
    pwmen |= mskCT16_PWM0EN_EN;
    pwmioen |= mskCT16_PWM0IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM0MODE_2;
    pwmen |= mskCT16_PWM0EN_EN;
    pwmioen |= mskCT16_PWM0IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[1].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM1MODE_1;
    pwmen |= mskCT16_PWM1EN_EN;
    pwmioen |= mskCT16_PWM1IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM1MODE_2;
    pwmen |= mskCT16_PWM1EN_EN;
    pwmioen |= mskCT16_PWM1IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[2].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM2MODE_1;
    pwmen |= mskCT16_PWM2EN_EN;
    pwmioen |= mskCT16_PWM2IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM2MODE_2;
    pwmen |= mskCT16_PWM2EN_EN;
    pwmioen |= mskCT16_PWM2IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[3].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM3MODE_1;
    pwmen |= mskCT16_PWM3EN_EN;
    pwmioen |= mskCT16_PWM3IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM3MODE_2;
    pwmen |= mskCT16_PWM3EN_EN;
    pwmioen |= mskCT16_PWM3IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[4].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM4MODE_1;
    pwmen |= mskCT16_PWM4EN_EN;
    pwmioen |= mskCT16_PWM4IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM4MODE_2;
    pwmen |= mskCT16_PWM4EN_EN;
    pwmioen |= mskCT16_PWM4IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[5].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM5MODE_1;
    pwmen |= mskCT16_PWM5EN_EN;
    pwmioen |= mskCT16_PWM5IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM5MODE_2;
    pwmen |= mskCT16_PWM5EN_EN;
    pwmioen |= mskCT16_PWM5IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[6].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM6MODE_1;
    pwmen |= mskCT16_PWM6EN_EN;
    pwmioen |= mskCT16_PWM6IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM6MODE_2;
    pwmen |= mskCT16_PWM6EN_EN;
    pwmioen |= mskCT16_PWM6IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[7].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM7MODE_1;
    pwmen |= mskCT16_PWM7EN_EN;
    pwmioen |= mskCT16_PWM7IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM7MODE_2;
    pwmen |= mskCT16_PWM7EN_EN;
    pwmioen |= mskCT16_PWM7IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[8].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM8MODE_1;
    pwmen |= mskCT16_PWM8EN_EN;
    pwmioen |= mskCT16_PWM8IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM8MODE_2;
    pwmen |= mskCT16_PWM8EN_EN;
    pwmioen |= mskCT16_PWM8IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[9].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM9MODE_1;
    pwmen |= mskCT16_PWM9EN_EN;
    pwmioen |= mskCT16_PWM9IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM9MODE_2;
    pwmen |= mskCT16_PWM9EN_EN;
    pwmioen |= mskCT16_PWM9IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[10].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM10MODE_1;
    pwmen |= mskCT16_PWM10EN_EN;
    pwmioen |= mskCT16_PWM10IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM10MODE_2;
    pwmen |= mskCT16_PWM10EN_EN;
    pwmioen |= mskCT16_PWM10IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[11].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM11MODE_1;
    pwmen |= mskCT16_PWM11EN_EN;
    pwmioen |= mskCT16_PWM11IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM11MODE_2;
    pwmen |= mskCT16_PWM11EN_EN;
    pwmioen |= mskCT16_PWM11IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[12].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM12MODE_1;
    pwmen |= mskCT16_PWM12EN_EN;
    pwmioen |= mskCT16_PWM12IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM12MODE_2;
    pwmen |= mskCT16_PWM12EN_EN;
    pwmioen |= mskCT16_PWM12IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[13].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM13MODE_1;
    pwmen |= mskCT16_PWM13EN_EN;
    pwmioen |= mskCT16_PWM13IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM13MODE_2;
    pwmen |= mskCT16_PWM13EN_EN;
    pwmioen |= mskCT16_PWM13IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[14].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM14MODE_1;
    pwmen |= mskCT16_PWM14EN_EN;
    pwmioen |= mskCT16_PWM14IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM14MODE_2;
    pwmen |= mskCT16_PWM14EN_EN;
    pwmioen |= mskCT16_PWM14IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[15].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl |= mskCT16_PWM15MODE_1;
    pwmen |= mskCT16_PWM15EN_EN;
    pwmioen |= mskCT16_PWM15IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl |= mskCT16_PWM15MODE_2;
    pwmen |= mskCT16_PWM15EN_EN;
    pwmioen |= mskCT16_PWM15IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[16].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl2 |= mskCT16_PWM16MODE_1;
    pwmen |= mskCT16_PWM16EN_EN;
    pwmioen |= mskCT16_PWM16IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl2 |= mskCT16_PWM16MODE_2;
    pwmen |= mskCT16_PWM16EN_EN;
    pwmioen |= mskCT16_PWM16IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[17].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl2 |= mskCT16_PWM17MODE_1;
    pwmen |= mskCT16_PWM17EN_EN;
    pwmioen |= mskCT16_PWM17IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl2 |= mskCT16_PWM17MODE_2;
    pwmen |= mskCT16_PWM17EN_EN;
    pwmioen |= mskCT16_PWM17IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[18].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl2 |= mskCT16_PWM18MODE_1;
    pwmen |= mskCT16_PWM18EN_EN;
    pwmioen |= mskCT16_PWM18IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl2 |= mskCT16_PWM18MODE_2;
    pwmen |= mskCT16_PWM18EN_EN;
    pwmioen |= mskCT16_PWM18IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[19].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl2 |= mskCT16_PWM19MODE_1;
    pwmen |= mskCT16_PWM19EN_EN;
    pwmioen |= mskCT16_PWM19IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl2 |= mskCT16_PWM19MODE_2;
    pwmen |= mskCT16_PWM19EN_EN;
    pwmioen |= mskCT16_PWM19IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[20].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl2 |= mskCT16_PWM20MODE_1;
    pwmen |= mskCT16_PWM20EN_EN;
    pwmioen |= mskCT16_PWM20IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl2 |= mskCT16_PWM20MODE_2;
    pwmen |= mskCT16_PWM20EN_EN;
    pwmioen |= mskCT16_PWM20IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[21].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl2 |= mskCT16_PWM21MODE_1;
    pwmen |= mskCT16_PWM21EN_EN;
    pwmioen |= mskCT16_PWM21IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl2 |= mskCT16_PWM21MODE_2;
    pwmen |= mskCT16_PWM21EN_EN;
    pwmioen |= mskCT16_PWM21IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[22].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl2 |= mskCT16_PWM22MODE_1;
    pwmen |= mskCT16_PWM22EN_EN;
    pwmioen |= mskCT16_PWM22IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl2 |= mskCT16_PWM22MODE_2;
    pwmen |= mskCT16_PWM22EN_EN;
    pwmioen |= mskCT16_PWM22IOEN_EN;
    break;
  }
#if PWM_CHANNELS > 23
  switch (pwmp->config->channels[23].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl2 |= mskCT16_PWM23MODE_1;
    pwmen |= mskCT16_PWM23EN_EN;
    pwmioen |= mskCT16_PWM23IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl2 |= mskCT16_PWM23MODE_2;
    pwmen |= mskCT16_PWM23EN_EN;
    pwmioen |= mskCT16_PWM23IOEN_EN;
    break;
  }
#endif
  pwmp->ct->PWMCTRL  = pwmctrl;
  pwmp->ct->PWMCTRL2 = pwmctrl2;
  pwmp->ct->PWMENB   = pwmen;
  pwmp->ct->PWMIOENB = pwmioen;
  }
  else {
    /* Driver re-configuration scenario, it must be stopped first.*/
    pwmp->ct->TMRCTRL = CT16_CEN_DIS;       /* Timer disabled.              */
    CT16B1_ResetTimer();                    /* Counter reset to zero.       */
  }

  /* Timer configuration.*/
  psc = (pwmp->clock / pwmp->config->frequency) - 1;
  osalDbgAssert((psc <= 0xFF) &&     /* Prescaler calculation.             */
                ((psc + 1) * pwmp->config->frequency) == pwmp->clock,
                "invalid frequency");
  pwmp->ct->PRE  = psc;
#if PWM_CHANNELS > 23
  pwmp->ct->MR24 = pwmp->period - 1;

#if SN32_PWM_USE_ONESHOT || defined(__DOXYGEN__)
  pwmp->ct->MCTRL3 |= mskCT16_MR24STOP_EN;
#elif !defined(SN32_PWM_NO_RESET)
  pwmp->ct->MCTRL3 |= mskCT16_MR24RST_EN;
#endif
#else
  pwmp->ct->MR23 = pwmp->period - 1;

#if SN32_PWM_USE_ONESHOT || defined(__DOXYGEN__)
  pwmp->ct->MCTRL3 |= mskCT16_MR23STOP_EN;
#elif !defined(SN32_PWM_NO_RESET)
  pwmp->ct->MCTRL3 |= mskCT16_MR23RST_EN;
#endif
#endif
  pwmp->ct->IC       &= 0x1FFFFFF;           /* Clear pending IRQs.          */

  /* Timer configured and started.*/
  pwmp->ct->TMRCTRL |= mskCT16_CEN_EN;
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
    pwmp->ct->TMRCTRL = CT16_CEN_DIS;       /* Timer disabled.              */
    pwmp->ct->IC &= 0x1FFFFFF;              /* Clear pending IRQs.          */

#if SN32_PWM_USE_CT16B1
    if (&PWMD1 == pwmp) {
#if !defined(SN32_CT16B1_SUPPRESS_ISR)
      nvicDisableVector(SN32_CT16B1_NUMBER);
#endif
      sys1DisableCT16B1();
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
  switch(channel){
    case 0:
      pwmp->ct->MR0 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM0IOEN_EN;
      break;
    case 1:
      pwmp->ct->MR1 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM1IOEN_EN;
      break;
    case 2:
      pwmp->ct->MR2 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM2IOEN_EN;
      break;
    case 3:
      pwmp->ct->MR3 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM3IOEN_EN;
      break;
    case 4:
      pwmp->ct->MR4 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM4IOEN_EN;
      break;
    case 5:
      pwmp->ct->MR5 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM5IOEN_EN;
      break;
    case 6:
      pwmp->ct->MR6 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM6IOEN_EN;
      break;
    case 7:
      pwmp->ct->MR7 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM7IOEN_EN;
      break;
    case 8:
      pwmp->ct->MR8 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM8IOEN_EN;
      break;
    case 9:
      pwmp->ct->MR9 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM9IOEN_EN;
      break;
    case 10:
      pwmp->ct->MR10 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM10IOEN_EN;
      break;
    case 11:
      pwmp->ct->MR11 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM11IOEN_EN;
      break;
    case 12:
      pwmp->ct->MR12 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM12IOEN_EN;
      break;
    case 13:
      pwmp->ct->MR13 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM13IOEN_EN;
      break;
    case 14:
      pwmp->ct->MR14 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM14IOEN_EN;
      break;
    case 15:
      pwmp->ct->MR15 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM15IOEN_EN;
      break;
    case 16:
      pwmp->ct->MR16 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM16IOEN_EN;
      break;
    case 17:
      pwmp->ct->MR17 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM17IOEN_EN;
      break;
    case 18:
      pwmp->ct->MR18 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM18IOEN_EN;
      break;
    case 19:
      pwmp->ct->MR19 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM19IOEN_EN;
      break;
    case 20:
      pwmp->ct->MR20 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM20IOEN_EN;
      break;
    case 21:
      pwmp->ct->MR21 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM21IOEN_EN;
      break;
    case 22:
      pwmp->ct->MR22 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM22IOEN_EN;
      break;
#if PWM_CHANNELS > 23
    case 23:
      pwmp->ct->MR23 = width;
      pwmp->ct->PWMIOENB |= mskCT16_PWM23IOEN_EN;
      break;
#endif
    default:
      ;
  }
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

  switch(channel){
    case 0:
      pwmp->ct->IC |= mskCT16_MR0IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM0IOEN_EN;
      break;
    case 1:
      pwmp->ct->IC |= mskCT16_MR1IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM1IOEN_EN;
      break;
    case 2:
      pwmp->ct->IC |= mskCT16_MR2IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM2IOEN_EN;
      break;
    case 3:
      pwmp->ct->IC |= mskCT16_MR3IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM3IOEN_EN;
      break;
    case 4:
      pwmp->ct->IC |= mskCT16_MR4IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM4IOEN_EN;
      break;
    case 5:
      pwmp->ct->IC |= mskCT16_MR5IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM5IOEN_EN;
      break;
    case 6:
      pwmp->ct->IC |= mskCT16_MR6IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM6IOEN_EN;
      break;
    case 7:
      pwmp->ct->IC |= mskCT16_MR7IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM7IOEN_EN;
      break;
    case 8:
      pwmp->ct->IC |= mskCT16_MR8IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM8IOEN_EN;
      break;
    case 9:
      pwmp->ct->IC |= mskCT16_MR9IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM9IOEN_EN;
      break;
    case 10:
      pwmp->ct->IC |= mskCT16_MR10IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM10IOEN_EN;
      break;
    case 11:
      pwmp->ct->IC |= mskCT16_MR11IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM11IOEN_EN;
      break;
    case 12:
      pwmp->ct->IC |= mskCT16_MR12IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM12IOEN_EN;
      break;
    case 13:
      pwmp->ct->IC |= mskCT16_MR13IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM13IOEN_EN;
      break;
    case 14:
      pwmp->ct->IC |= mskCT16_MR14IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM14IOEN_EN;
      break;
    case 15:
      pwmp->ct->IC |= mskCT16_MR15IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM15IOEN_EN;
      break;
    case 16:
      pwmp->ct->IC |= mskCT16_MR16IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM16IOEN_EN;
      break;
    case 17:
      pwmp->ct->IC |= mskCT16_MR17IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM17IOEN_EN;
      break;
    case 18:
      pwmp->ct->IC |= mskCT16_MR18IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM18IOEN_EN;
      break;
    case 19:
      pwmp->ct->IC |= mskCT16_MR19IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM19IOEN_EN;
      break;
    case 20:
      pwmp->ct->IC |= mskCT16_MR20IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM20IOEN_EN;
      break;
    case 21:
      pwmp->ct->IC |= mskCT16_MR21IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM21IOEN_EN;
      break;
    case 22:
      pwmp->ct->IC |= mskCT16_MR22IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM22IOEN_EN;
      break;
#if PWM_CHANNELS > 23
    case 23:
      pwmp->ct->IC |= mskCT16_MR23IC;
      pwmp->ct->PWMIOENB &= ~mskCT16_PWM23IOEN_EN;
      break;
#endif
    default:
      ;
  }
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
#if PWM_CHANNELS > 23
  pwmp->ct->MCTRL3 |= mskCT16_MR24IE_EN;
#else
  pwmp->ct->MCTRL3 |= mskCT16_MR23IE_EN;
#endif
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
#if PWM_CHANNELS > 23
  pwmp->ct->IC |= mskCT16_MR24IC;
  pwmp->ct->MCTRL3 &= ~mskCT16_MR24IE_EN;
#else
  pwmp->ct->IC |= mskCT16_MR23IC;
  pwmp->ct->MCTRL3 &= ~mskCT16_MR23IE_EN;
#endif
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
  switch(channel){
    case 0:
      pwmp->ct->MCTRL |= mskCT16_MR0IE_EN;
      break;
    case 1:
      pwmp->ct->MCTRL |= mskCT16_MR1IE_EN;
      break;
    case 2:
      pwmp->ct->MCTRL |= mskCT16_MR2IE_EN;
      break;
    case 3:
      pwmp->ct->MCTRL |= mskCT16_MR3IE_EN;
      break;
    case 4:
      pwmp->ct->MCTRL |= mskCT16_MR4IE_EN;
      break;
    case 5:
      pwmp->ct->MCTRL |= mskCT16_MR5IE_EN;
      break;
    case 6:
      pwmp->ct->MCTRL |= mskCT16_MR6IE_EN;
      break;
    case 7:
      pwmp->ct->MCTRL |= mskCT16_MR7IE_EN;
      break;
    case 8:
      pwmp->ct->MCTRL |= mskCT16_MR8IE_EN;
      break;
    case 9:
      pwmp->ct->MCTRL |= mskCT16_MR9IE_EN;
      break;
    case 10:
      pwmp->ct->MCTRL2 |= mskCT16_MR10IE_EN;
      break;
    case 11:
      pwmp->ct->MCTRL2 |= mskCT16_MR11IE_EN;
      break;
    case 12:
      pwmp->ct->MCTRL2 |= mskCT16_MR12IE_EN;
      break;
    case 13:
      pwmp->ct->MCTRL2 |= mskCT16_MR13IE_EN;
      break;
    case 14:
      pwmp->ct->MCTRL2 |= mskCT16_MR14IE_EN;
      break;
    case 15:
      pwmp->ct->MCTRL2 |= mskCT16_MR15IE_EN;
      break;
    case 16:
      pwmp->ct->MCTRL2 |= mskCT16_MR16IE_EN;
      break;
    case 17:
      pwmp->ct->MCTRL2 |= mskCT16_MR17IE_EN;
      break;
    case 18:
      pwmp->ct->MCTRL2 |= mskCT16_MR18IE_EN;
      break;
    case 19:
      pwmp->ct->MCTRL2 |= mskCT16_MR19IE_EN;
      break;
    case 20:
      pwmp->ct->MCTRL3 |= mskCT16_MR20IE_EN;
      break;
    case 21:
      pwmp->ct->MCTRL3 |= mskCT16_MR21IE_EN;
      break;
    case 22:
      pwmp->ct->MCTRL3 |= mskCT16_MR22IE_EN;
      break;
#if PWM_CHANNELS > 23
    case 23:
      pwmp->ct->MCTRL3 |= mskCT16_MR23IE_EN;
      break;
#endif
    default:
      ;
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
  switch(channel){
    case 0:
      pwmp->ct->MCTRL &= ~mskCT16_MR0IE_EN;
      break;
    case 1:
      pwmp->ct->MCTRL &= ~mskCT16_MR1IE_EN;
      break;
    case 2:
      pwmp->ct->MCTRL &= ~mskCT16_MR2IE_EN;
      break;
    case 3:
      pwmp->ct->MCTRL &= ~mskCT16_MR3IE_EN;
      break;
    case 4:
      pwmp->ct->MCTRL &= ~mskCT16_MR4IE_EN;
      break;
    case 5:
      pwmp->ct->MCTRL &= ~mskCT16_MR5IE_EN;
      break;
    case 6:
      pwmp->ct->MCTRL &= ~mskCT16_MR6IE_EN;
      break;
    case 7:
      pwmp->ct->MCTRL &= ~mskCT16_MR7IE_EN;
      break;
    case 8:
      pwmp->ct->MCTRL &= ~mskCT16_MR8IE_EN;
      break;
    case 9:
      pwmp->ct->MCTRL &= ~mskCT16_MR9IE_EN;
      break;
    case 10:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR10IE_EN;
      break;
    case 11:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR11IE_EN;
      break;
    case 12:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR12IE_EN;
      break;
    case 13:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR13IE_EN;
      break;
    case 14:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR14IE_EN;
      break;
    case 15:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR15IE_EN;
      break;
    case 16:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR16IE_EN;
      break;
    case 17:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR17IE_EN;
      break;
    case 18:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR18IE_EN;
      break;
    case 19:
      pwmp->ct->MCTRL2 &= ~mskCT16_MR19IE_EN;
      break;
    case 20:
      pwmp->ct->MCTRL3 &= ~mskCT16_MR20IE_EN;
      break;
    case 21:
      pwmp->ct->MCTRL3 &= ~mskCT16_MR21IE_EN;
      break;
    case 22:
      pwmp->ct->MCTRL3 &= ~mskCT16_MR22IE_EN;
      break;
#if PWM_CHANNELS > 23
    case 23:
      pwmp->ct->MCTRL3 &= ~mskCT16_MR23IE_EN;
      break;
#endif
    default:
      ;
  }}

/**
 * @brief   Common CT IRQ handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_serve_interrupt(PWMDriver *pwmp) {
  uint32_t ris;

  ris  = pwmp->ct->RIS;
  pwmp->ct->IC = ris;
  if (((ris & mskCT16_MR0IF) != 0) &&
      (pwmp->config->channels[0].callback != NULL))
    pwmp->config->channels[0].callback(pwmp);
  if (((ris & mskCT16_MR1IF) != 0) &&
      (pwmp->config->channels[1].callback != NULL))
    pwmp->config->channels[1].callback(pwmp);
  if (((ris & mskCT16_MR2IF) != 0) &&
      (pwmp->config->channels[2].callback != NULL))
    pwmp->config->channels[2].callback(pwmp);
  if (((ris & mskCT16_MR3IF) != 0) &&
      (pwmp->config->channels[3].callback != NULL))
    pwmp->config->channels[3].callback(pwmp);
  if (((ris & mskCT16_MR4IF) != 0) &&
      (pwmp->config->channels[4].callback != NULL))
    pwmp->config->channels[4].callback(pwmp);
  if (((ris & mskCT16_MR5IF) != 0) &&
      (pwmp->config->channels[5].callback != NULL))
    pwmp->config->channels[5].callback(pwmp);
  if (((ris & mskCT16_MR6IF) != 0) &&
      (pwmp->config->channels[6].callback != NULL))
    pwmp->config->channels[6].callback(pwmp);
  if (((ris & mskCT16_MR7IF) != 0) &&
      (pwmp->config->channels[7].callback != NULL))
    pwmp->config->channels[7].callback(pwmp);
  if (((ris & mskCT16_MR8IF) != 0) &&
      (pwmp->config->channels[8].callback != NULL))
    pwmp->config->channels[8].callback(pwmp);
  if (((ris & mskCT16_MR9IF) != 0) &&
      (pwmp->config->channels[9].callback != NULL))
    pwmp->config->channels[9].callback(pwmp);
  if (((ris & mskCT16_MR10IF) != 0) &&
      (pwmp->config->channels[10].callback != NULL))
    pwmp->config->channels[10].callback(pwmp);
  if (((ris & mskCT16_MR11IF) != 0) &&
      (pwmp->config->channels[11].callback != NULL))
    pwmp->config->channels[11].callback(pwmp);
  if (((ris & mskCT16_MR12IF) != 0) &&
      (pwmp->config->channels[12].callback != NULL))
    pwmp->config->channels[12].callback(pwmp);
  if (((ris & mskCT16_MR13IF) != 0) &&
      (pwmp->config->channels[13].callback != NULL))
    pwmp->config->channels[13].callback(pwmp);
  if (((ris & mskCT16_MR14IF) != 0) &&
      (pwmp->config->channels[14].callback != NULL))
    pwmp->config->channels[14].callback(pwmp);
  if (((ris & mskCT16_MR15IF) != 0) &&
      (pwmp->config->channels[15].callback != NULL))
    pwmp->config->channels[15].callback(pwmp);
  if (((ris & mskCT16_MR16IF) != 0) &&
      (pwmp->config->channels[16].callback != NULL))
    pwmp->config->channels[16].callback(pwmp);
  if (((ris & mskCT16_MR17IF) != 0) &&
      (pwmp->config->channels[17].callback != NULL))
    pwmp->config->channels[17].callback(pwmp);
  if (((ris & mskCT16_MR18IF) != 0) &&
      (pwmp->config->channels[18].callback != NULL))
    pwmp->config->channels[18].callback(pwmp);
  if (((ris & mskCT16_MR19IF) != 0) &&
      (pwmp->config->channels[19].callback != NULL))
    pwmp->config->channels[19].callback(pwmp);
  if (((ris & mskCT16_MR20IF) != 0) &&
      (pwmp->config->channels[20].callback != NULL))
    pwmp->config->channels[20].callback(pwmp);
  if (((ris & mskCT16_MR21IF) != 0) &&
      (pwmp->config->channels[21].callback != NULL))
    pwmp->config->channels[21].callback(pwmp);
  if (((ris & mskCT16_MR22IF) != 0) &&
      (pwmp->config->channels[22].callback != NULL))
    pwmp->config->channels[22].callback(pwmp);
#if PWM_CHANNELS > 23
  if (((ris & mskCT16_MR23IF) != 0) &&
      (pwmp->config->channels[23].callback != NULL))
    pwmp->config->channels[23].callback(pwmp);
  if (((ris & mskCT16_MR24IF) != 0) && (pwmp->config->callback != NULL))
    pwmp->config->callback(pwmp);
#else
  if (((ris & mskCT16_MR23IF) != 0) && (pwmp->config->callback != NULL))
    pwmp->config->callback(pwmp);
#endif
}

#endif /* HAL_USE_PWM */

/** @} */

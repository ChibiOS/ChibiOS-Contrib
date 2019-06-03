/*
    Copyright (C) 2019 /u/KeepItUnder

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
 * @file    TIMv1/hal_pwm_lld.c
 * @brief   PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#include "hal.h"

// #if HAL_USE_PWM || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

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
// void pwm_lld_init(void) {

// }

void pwm_lld_start(PWM_T *pwm, uint32_t mask) {
    uint32_t pwmStart = 0;

    for(uint32_t i = 0; i < PWM_CHANNELS; i++) {
        if (mask & (1 << i)) {
            pwmStart |= (PWM_PCR_CH0EN_Msk << (i * 8));
        }
    }

    (pwm)->PCR |= pwmStart;
}


void pwm_lld_enable_period_int(PWM_T *pwm, uint32_t pwmChannel,  uint32_t periodType) {
    (pwm)->PIER = ((pwm)->PIER & ~(0x01ul << (pwmChannel >> 1))) | (0x01ul << pwmChannel) | (periodType << (pwmChannel >> 1));
}


void pwm_lld_disable_period_int(PWM_T *pwm, uint32_t pwmChannel) {
    (pwm)->PIER &= ~(PWM_PIER_PWMIE0_Msk << pwmChannel);
}


uint32_t pwm_lld_get_period_int(PWM_T *pwm, uint32_t pwmChannel) {
    if ((pwm)->PIIR & (0x01ul << (pwmChannel))) {
        return 1;
    } else {
        return 0;
    }
}


void pwm_lld_clear_period_int(PWM_T *pwm, uint32_t pwmChannel) {
    (pwm)->PIIR = (0x01ul << pwmChannel);
}


uint32_t pwm_lld_config_output_channel(PWM_T *pwm, uint32_t channel, uint32_t freq, uint32_t duty)
{
    uint32_t regSource;
    uint32_t clkSource;
    uint32_t pwmClk;
    uint8_t divider = 1;
    uint8_t prescale = 0xFF;
    uint16_t CNR = 0xFFFF;

    if (channel < 2) {
        regSource = ((CLK->CLKSEL2 & (CLK_CLKSEL2_PWM01_S_Msk)) >> (CLK_CLKSEL2_PWM01_S_Pos - 2)) | (CLK->CLKSEL1 & (CLK_CLKSEL1_PWM01_S_Msk)) >> (CLK_CLKSEL1_PWM01_S_Pos);
    } else {
        regSource = ((CLK->CLKSEL2 & (CLK_CLKSEL2_PWM23_S_Msk)) >> (CLK_CLKSEL2_PWM23_S_Pos - 2)) | (CLK->CLKSEL1 & (CLK_CLKSEL1_PWM23_S_Msk)) >> (CLK_CLKSEL1_PWM23_S_Pos);
    }

    if (regSource == 2) {
        SystemCoreClockUpdate();
        clkSource = SystemCoreClock;
    } else {
      switch (regSource) {
        case 0:
          clkSource = __HXT;
          break;
        case 1:
        case 4:
        case 5:
        case 6:
          clkSource = 0;
          break;
        case 2:
          SystemCoreClockUpdate();
          clkSource = SystemCoreClock;
          break;
        case 3:
          clkSource = __HIRC;
          break;
        case 7:
          clkSource = __LIRC;
          break;
      }
    }

    /* Calculate best divider */
    while (divider < 17) {
        pwmClk = (clkSource / (freq)) / divider;
        // If pwmClk is larger than (CNR * prescale) then divider can still be bigger
        if (pwmClk > (0x10000 * 0x100)) {
            continue;
        }

        // Set prescaler to CNR value lower than 0xFFFF
        prescale = (pwmClk + 0xFFFF) / 0x10000;

        // Keep prescale bigger than 2 this loop
        if (prescale < 3) {
            prescale = 2;
        }

        pwmClk /= prescale;

        if (pwmClk <= 0x10000) {
            if (pwmClk == 1) {
                CNR = 1;     // Too fast, and PWM cannot generate expected frequency...
            } else {
                CNR = pwmClk;
            }
            break;
        }

        divider = divider << 1;
    }

    pwmClk = clkSource / (prescale * divider * CNR);

    /* Calculate PWM Registers */
    prescale -= 1;
    CNR -= 1;

    /* Set final divider for output calculation */
    switch (divider) {
      case 1:
        divider = 4;
        break;
      case 4:
        divider = 1;
        break;
      case 8:
        divider = 2;
        break;
      case 16:
        divider = 3;
        break;
      case 0:
      case 2:
      case 3:
      case 5:
      case 6:
      case 7:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      default:
        divider = 0;
        break;
    }

    // Prescaler is shared every two channels (01/23/etc.)
    (pwm)->PPR = ((pwm)->PPR & ~(PWM_PPR_CP01_Msk << ((channel >> 1) * 8))) | (prescale << ((channel >> 1) * 8));
    (pwm)->CSR = ((pwm)->CSR & ~(PWM_CSR_CSR0_Msk << (4 * channel))) | (divider << (4 * channel));

    // Set edge-aligned PWM
    (pwm)->PCR &= ~(PWM_PCR_PWM01TYPE_Msk << (channel >> 1));
    (pwm)->PCR |= PWM_PCR_CH0MOD_Msk << (8 * channel);

    // Set PWM register values
    if (duty) {
        *((__IO uint32_t *)((((uint32_t) & ((pwm)->CMR0)) + channel * 12))) = duty * (CNR + 1) / 100 - 1;
    } else {
        *((__IO uint32_t *)((((uint32_t) & ((pwm)->CMR0)) + channel * 12))) = 0;
    }

    *((__IO uint32_t *)((((uint32_t) & ((pwm)->CNR0)) + channel * 12))) = CNR;

    return(pwmClk);
}

// #endif /* HAL_USE_PWM */

/** @} */

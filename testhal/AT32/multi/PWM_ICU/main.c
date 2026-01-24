/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2025 HorrorTroll
    ChibiOS - Copyright (C) 2023..2025 Zhaqian

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

#include "ch.h"
#include "hal.h"

#include "portab.h"

/*===========================================================================*/
/* PWM driver related.                                                       */
/*===========================================================================*/

void pwmpcb(PWMDriver *pwmp) {
  (void)pwmp;
}

void pwmc1cb(PWMDriver *pwmp) {
  (void)pwmp;
}

/*===========================================================================*/
/* ICU driver related.                                                       */
/*===========================================================================*/

icucnt_t last_width, last_period;

void icuwidthcb(ICUDriver *icup) {
  palSetLine(PORTAB_BLINK_LED1);
  palSetLine(PORTAB_BLINK_LED2);
  palSetLine(PORTAB_BLINK_LED3);
  last_width = icuGetWidthX(icup);
}

void icuperiodcb(ICUDriver *icup) {
  palClearLine(PORTAB_BLINK_LED1);
  palClearLine(PORTAB_BLINK_LED2);
  palClearLine(PORTAB_BLINK_LED3);
  last_period = icuGetPeriodX(icup);
}

void icuovfcb(ICUDriver *icup) {
  (void)icup;
}

/*===========================================================================*/
/* Application code.                                                         */
/*===========================================================================*/

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Starting PWM driver 1 and enabling the notifications.
   * GPIOA8 is programmed as PWM output (channel 1 of TMR1).
   */
  pwmStart(&PORTAB_PWM1, &pwmcfg);
  pwmEnablePeriodicNotification(&PORTAB_PWM1);

  /*
   * Starting ICU driver 3.
   * GPIOA6 is programmed as ICU input (channel 1 of TMR3).
   */
  icuStart(&PORTAB_ICU1, &icucfg);

  /*
   * Board-dependent setup code.
   */
  portab_setup();

  /*
   * Board LED is programmed as output.
   */
  palToggleLine(PORTAB_BLINK_LED1);
  palToggleLine(PORTAB_BLINK_LED2);
  palToggleLine(PORTAB_BLINK_LED3);
  chThdSleepMilliseconds(1000);

  /*
   * Starting ICU capture and enabling the notifications.
   */
  icuStartCapture(&PORTAB_ICU1);
  icuEnableNotifications(&PORTAB_ICU1);

  /*
   * Normal main() thread activity, various PWM patterns are generated
   * cyclically, if the ICU input is connected to the PWM output the
   * board LED mirrors the PWM output.
   */
  while (true) {
    /*
     * Starts the PWM channel 0 using 75% duty cycle.
     */
    pwmEnableChannel(&PORTAB_PWM1, 0, PWM_PERCENTAGE_TO_WIDTH(&PORTAB_PWM1, 7500));
    pwmEnableChannelNotification(&PORTAB_PWM1, 0);
    chThdSleepMilliseconds(5000);

    /*
     * Changes the PWM channel 0 to 50% duty cycle.
     */
    pwmEnableChannel(&PORTAB_PWM1, 0, PWM_PERCENTAGE_TO_WIDTH(&PORTAB_PWM1, 5000));
    chThdSleepMilliseconds(5000);

    /*
     * Changes the PWM channel 0 to 25% duty cycle.
     */
    pwmEnableChannel(&PORTAB_PWM1, 0, PWM_PERCENTAGE_TO_WIDTH(&PORTAB_PWM1, 2500));
    chThdSleepMilliseconds(5000);

    /*
     * Changes PWM period to half second the duty cycle becomes 50%
     * implicitly.
     */
    pwmChangePeriod(&PORTAB_PWM1, 5000);
    chThdSleepMilliseconds(5000);

    /*
     * Disables channel 0.
     */
    pwmDisableChannel(&PORTAB_PWM1, 0);
  }
}

/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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

/*===========================================================================*/
/* GPIO test use case on the GENERIC_SK32_F077 board.                        */
/*===========================================================================*/

/*
 * Board resources used by this test:
 *
 *  - PB14 / PB15: two board LEDs wired to push-pull outputs, the PAL
 *    abstraction drives them high (PAL_HIGH) to switch the LEDs on.
 *
 * Both the pad based APIs (palSetPadMode(), palSetPad(), ...) are exercised
 * on this port because they operate on the underlying GPIO register block.
 */

/* Blinker thread, times are in milliseconds.  Both LEDs are switched on for
   500 ms and off for 500 ms, forever (1 s full blink period). */
static THD_WORKING_AREA(waBlinkThread, 128);
static THD_FUNCTION(BlinkThread, arg) {
  (void)arg;
  chRegSetThreadName("led-blink");
  while (true) {
    palSetPad(GPIOB, GPIOB_PIN14);
    palSetPad(GPIOB, GPIOB_PIN15);
    chThdSleepMilliseconds(500);

    palClearPad(GPIOB, GPIOB_PIN14);
    palClearPad(GPIOB, GPIOB_PIN15);
    chThdSleepMilliseconds(500);
  }
}

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

  /* Configuring the PB14/PB15 LED lines as push-pull outputs, initially off. */
  palSetPadMode(GPIOB, GPIOB_PIN14, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOB, GPIOB_PIN15, PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB, GPIOB_PIN14);
  palClearPad(GPIOB, GPIOB_PIN15);

  /*
   * Creating the LED blinker thread.
   */
  chThdCreateStatic(waBlinkThread, sizeof(waBlinkThread), NORMALPRIO,
                    BlinkThread, NULL);

  /*
   * Normal main() thread activity.
   */
  while (true) {
    chThdSleepMilliseconds(500);
  }
}

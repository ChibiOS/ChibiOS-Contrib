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

/*
 * This is a periodic thread that does absolutely nothing except flashing
 * a LED.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palToggleLine(PORTAB_BLINK_LED3);
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

  /*
   * Board-dependent setup code.
   */
  portab_setup();

  /*
   * Starting the I2C driver 1.
   */
  i2cStart(&PORTAB_I2C1, &i2ccfg);

  /*
   * Starting the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO-1, Thread1, NULL);

  /*
   * Normal main() thread activity, in this demo it does nothing.
   */
  while (true) {
    unsigned i;
    msg_t msg;
    static const uint8_t cmd[] = {0, 0};
    uint8_t data[16];

    msg = i2cMasterTransmitTimeout(&PORTAB_I2C1, 0x52, cmd, sizeof(cmd),
                                   data, sizeof(data), TIME_INFINITE);
    if (msg != MSG_OK)
      palToggleLine(PORTAB_BLINK_LED1);
    for (i = 0; i < 256; i++) {
      msg = i2cMasterReceiveTimeout(&PORTAB_I2C1, 0x52,
                                    data, sizeof(data), TIME_INFINITE);
      if (msg != MSG_OK)
        palToggleLine(PORTAB_BLINK_LED1);
    }

    chThdSleepMilliseconds(500);
    palToggleLine(PORTAB_BLINK_LED2);
  }

  return 0;
}

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

/*
 * SK32F077 native serial smoke test.
 *
 * USART2 is mapped on PA2 (TX) / PA3 (RX), alternate function 1, as
 * configured by the board early initialization code (board.h).  The driver
 * is the native SK32F0xx SR/DR class serial LLD (hal_serial_lld.c).
 *
 * The demo blinks the green LED and echoes back over SD2 every byte
 * received from the UART at the default bit rate (38400 baud, 8N1).
 */

#include "ch.h"
#include "hal.h"

/*===========================================================================*/
/* Generic code.                                                             */
/*===========================================================================*/

/*
 * LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 256);
static THD_FUNCTION(Thread1, arg) {
  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palToggleLine(LINE_LED_GREEN);
    chThdSleepMilliseconds(250);
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
   * Starting the serial driver SD2 (USART2) with the default configuration,
   * the driver enables the USART2 clock and NVIC vector when started.
   */
  sdStart(&SD2, NULL);

  /*
   * Starting the LED blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  /*
   * Banner and then byte-by-byte echo loop.
   */
  {
    static const char banner[] = "SK32F077 native serial demo ready\r\n";

    sdWrite(&SD2, (const uint8_t *)banner, sizeof(banner) - 1U);
  }

  while (true) {
    msg_t b;

    b = sdGetTimeout(&SD2, TIME_INFINITE);
    if (b >= MSG_OK) {
      sdPut(&SD2, b);
    }
  }
}

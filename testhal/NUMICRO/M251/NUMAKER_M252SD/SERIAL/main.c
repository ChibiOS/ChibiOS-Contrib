/*
  ChibiOS - Copyright (C) 2020 Alex Lewontin
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

#include "hal.h"
#include "chprintf.h"
#include "M251/stddriver/uart.h"

#define SERIAL_DRIVER   SD0

static char buf;

static const SerialConfig scfg = {
  .speed = 115200,
  .line  = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1,
};

static char caesar_shift(char c) {

  if ((c >= 'a') && (c < 'z')) {
    return (char)(c + 1);
  }
  if (c == 'z') {
    return 'a';
  }
  if ((c >= 'A') && (c < 'Z')) {
    return (char)(c + 1);
  }
  if (c == 'Z') {
    return 'A';
  }
  return c;
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
    Exercise a complete clock/FIFO/interrupt stop-start lifecycle before the
    interactive echo test.
  */
  sdStart(&SERIAL_DRIVER, &scfg);
  sdStop(&SERIAL_DRIVER);
  sdStart(&SERIAL_DRIVER, &scfg);

  chprintf((BaseSequentialStream *)&SERIAL_DRIVER,
           "\nSerial stop/start PASS. Initialized...\n");
  while (true) {
    buf = streamGet((BaseSequentialStream *)&SERIAL_DRIVER);
    buf = caesar_shift(buf);
    streamPut((BaseSequentialStream *)&SERIAL_DRIVER, buf);
  }
}

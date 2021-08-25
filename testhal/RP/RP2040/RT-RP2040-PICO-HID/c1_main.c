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

#include "ch.h"
#include "hal.h"

#ifdef USB_DEBUG

#include "rp_fifo.h"

#include "chprintf.h"

uint8_t remained_data = 0;

void process_command(uint32_t data) {
  if (remained_data > 0) {
    remained_data -= 1;
    chprintf((BaseSequentialStream *)&SIOD0, "0x%X\r\n", data);
  } else {
    uint8_t cmd = (data & 0xFF000000) >> 24;
    uint8_t length = (data & 0xFF0000) >> 16;
    if (length > 0) {
      remained_data = length;
    }
    chprintf((BaseSequentialStream *)&SIOD0, "%X\r\n", cmd);
  }
}
#endif // USB_DEBUG

/**
 * Core 1 entry point.
 */
void c1_main(void) {

  /*
   * Starting a new OS instance running on this core, we need to wait for
   * system initialization on the other side.
   */
  chSysWaitSystemState(ch_sys_running);
  chInstanceObjectInit(&ch1, &ch_core1_cfg);

  /* It is alive now.*/
  chSysUnlock();

#ifdef USB_DEBUG
  /*
   * Setting up GPIOs.
   */
  palSetLineMode(0U, PAL_MODE_ALTERNATE_UART);
  palSetLineMode(1U, PAL_MODE_ALTERNATE_UART);

  /*
   * Activates the UART0 SIO driver using the default configuration.
   */
  sioStart(&SIOD0, NULL);
  sioStartOperation(&SIOD0, NULL);

  chThdSleepMilliseconds(100);
  chprintf((BaseSequentialStream *)&SIOD0, "-- Started in c1\r\n");
#endif // USB_DEBUG

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop (re)spawning a shell.
   */
  while (true) {
    chThdSleepMilliseconds(200);
  }
}

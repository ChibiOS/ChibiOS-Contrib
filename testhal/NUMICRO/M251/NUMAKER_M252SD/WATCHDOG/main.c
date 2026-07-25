/*
    Copyright (C) 2026 Belonit

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
#include "shcfg.h"

/**
 * @brief   Reset cause captured before HAL initialization.
 */
uint32_t boot_reset_cause;

int main(void) {

  boot_reset_cause = SYS->RSTSTS;
  SYS->RSTSTS = boot_reset_cause;

  halInit();
  chSysInit();

  sdStart(&SD0, NULL);
  shellInit();

  chprintf((BaseSequentialStream *)&SD0,
           "\r\nM252 watchdog/reset test\r\n"
           "Commands: cause, reset, wdt_stop, wdt\r\n");
  print_reset_cause((BaseSequentialStream *)&SD0);

  while (true) {
    thread_t *shelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell",
                                            NORMALPRIO + 1, shellThread,
                                            (void *)&shell_cfg);
    if (shelltp == NULL) {
      chprintf((BaseSequentialStream *)&SD0, "Unable to create shell\r\n");
      chThdSleepMilliseconds(1000);
      continue;
    }
    chThdWait(shelltp);
    chThdSleepMilliseconds(1000);
  }
}

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

#include "shcfg.h"

#include "chprintf.h"

static const WDGConfig wdg_config = {
  .timeout          = M251_WDG_TIMEOUT_2POW16,
  .reset_delay      = M251_WDG_RESET_DELAY_3CLK,
  .reset_on_timeout = true,
  .run_in_debug     = false,
};

static void print_flag(BaseSequentialStream *chp, uint32_t mask,
                       const char *name) {

  if ((boot_reset_cause & mask) != 0U) {
    chprintf(chp, " %s", name);
  }
}

/**
 * @brief   Prints the reset cause captured during startup.
 *
 * @param[in] chp       pointer to the output stream
 *
 * @notapi
 */
void print_reset_cause(BaseSequentialStream *chp) {
  chprintf(chp, "Reset cause: 0x%08lX", (unsigned long)boot_reset_cause);
  print_flag(chp, SYS_RSTSTS_PORF_Msk, "PORF");
  print_flag(chp, SYS_RSTSTS_PINRF_Msk, "PINRF");
  print_flag(chp, SYS_RSTSTS_WDTRF_Msk, "WDTRF");
  print_flag(chp, SYS_RSTSTS_LVRF_Msk, "LVRF");
  print_flag(chp, SYS_RSTSTS_BODRF_Msk, "BODRF");
  print_flag(chp, SYS_RSTSTS_SYSRF_Msk, "SYSRF");
  print_flag(chp, SYS_RSTSTS_PMURF_Msk, "PMURF");
  print_flag(chp, SYS_RSTSTS_CPURF_Msk, "CPURF");
  print_flag(chp, SYS_RSTSTS_CPULKRF_Msk, "CPULKRF");
  print_flag(chp, SYS_RSTSTS_VBATLVRF_Msk, "VBATLVRF");
  chprintf(chp, "\r\n");
}

static void cmd_cause(BaseSequentialStream *chp, int argc, char *argv[]) {

  (void)argv;
  if (argc != 0) {
    shellUsage(chp, "cause");
    return;
  }

  print_reset_cause(chp);
}

static void cmd_reset(BaseSequentialStream *chp, int argc, char *argv[]) {

  (void)argv;
  if (argc != 0) {
    shellUsage(chp, "reset");
    return;
  }

  chprintf(chp, "Requesting Cortex-M23 system reset...\r\n");
  chThdSleepMilliseconds(100);
  NVIC_SystemReset();
}

static void cmd_wdt(BaseSequentialStream *chp, int argc, char *argv[]) {

  (void)argv;
  if (argc != 0) {
    shellUsage(chp, "wdt");
    return;
  }

  chprintf(chp,
           "Starting WDT: LIRC, 2^16 clocks (about 1.7 s).\r\n");
  if (wdgStart(&WDGD1, &wdg_config) != HAL_RET_SUCCESS) {
    chprintf(chp, "Unable to start WDT\r\n");
    return;
  }

  for (unsigned i = 1U; i <= 3U; i++) {
    chThdSleepMilliseconds(1000);
    wdgReset(&WDGD1);
    chprintf(chp, "Feed %u/3 OK\r\n", i);
  }

  chprintf(chp, "Feeding stopped; waiting for watchdog reset...\r\n");
  while (true) {
    chThdSleepMilliseconds(1000);
  }
}

static void cmd_wdt_stop(BaseSequentialStream *chp, int argc, char *argv[]) {

  (void)argv;
  if (argc != 0) {
    shellUsage(chp, "wdt_stop");
    return;
  }

  chprintf(chp, "Starting and stopping WDT twice...\r\n");
  if (wdgStart(&WDGD1, &wdg_config) != HAL_RET_SUCCESS) {
    chprintf(chp, "Unable to start WDT\r\n");
    return;
  }
  chThdSleepMilliseconds(500);
  wdgStop(&WDGD1);
  chThdSleepMilliseconds(2500);

  if (wdgStart(&WDGD1, &wdg_config) != HAL_RET_SUCCESS) {
    chprintf(chp, "Unable to restart WDT\r\n");
    return;
  }
  chThdSleepMilliseconds(500);
  wdgStop(&WDGD1);
  chThdSleepMilliseconds(2500);
  chprintf(chp, "WDT start/stop/start/stop lifecycle PASS\r\n");
}

static const ShellCommand commands[] = {
  {"cause", cmd_cause},
  {"reset", cmd_reset},
  {"wdt_stop", cmd_wdt_stop},
  {"wdt", cmd_wdt},
  {NULL, NULL},
};

/**
 * @brief   Shell configuration.
 */
const ShellConfig shell_cfg = {
  .sc_channel = (BaseSequentialStream *)&SD0,
  .sc_commands = commands,
};

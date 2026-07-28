/*
    Copyright (C) 2021 Alex Lewontin
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
#include "shcfg.h"

/** @brief Start address of the linker-reserved MFS area.*/
extern uint8_t __mfs_start__;
/** @brief End address of the linker-reserved MFS area.*/
extern uint8_t __mfs_end__;

static THD_WORKING_AREA(waBlinkThread, 128);
static THD_FUNCTION(BlinkThread, arg) {
  (void)arg;
  chRegSetThreadName("blinker");

  while (true) {
    OnboardLED_Toggle();
    chThdSleepMilliseconds(500);
  }
}

static bool mfs_bounds_valid(void) {
  const flash_descriptor_t *desc = flashGetDescriptor(&EFLD1);
  uintptr_t flash_start = (uintptr_t)desc->address;
  uintptr_t flash_end = flash_start + desc->size;
  uintptr_t mfs_start = (uintptr_t)&__mfs_start__;
  uintptr_t mfs_end = (uintptr_t)&__mfs_end__;

  return (desc->sectors_size == 512U) && (mfs_start == 0x0000F000U)
         && (mfs_end == 0x00010000U) && (mfs_start >= flash_start)
         && (mfs_end <= flash_end);
}

int main(void) {
  halInit();
  chSysInit();

  sdStart(&SD0, NULL);
  eflStart(&EFLD1, NULL);

  if (!mfs_bounds_valid()) {
    chprintf((BaseSequentialStream *)&SD0,
             "Invalid MFS linker or EFL geometry\r\n");
    OnboardLED_On();
    while (true) {
      chThdSleepMilliseconds(1000);
    }
  }

  mfsObjectInit(&mfsd, &mfsbuf);
  mfs_error_t err = mfsStart(&mfsd, &mfsd_config);
  if (MFS_IS_ERROR(err)) {
    chprintf((BaseSequentialStream *)&SD0, "MFS mount failed: %d\r\n", err);
    OnboardLED_On();
    while (true) {
      chThdSleepMilliseconds(1000);
    }
  }

  shellInit();
  chThdCreateStatic(waBlinkThread, sizeof(waBlinkThread), NORMALPRIO,
                    BlinkThread, NULL);

  chprintf((BaseSequentialStream *)&SD0,
           "\r\nM252 EFL/MFS demo\r\n"
           "Storage: 0x0000F000..0x0000FFFF (two 2 KiB banks)\r\n"
           "Commands: kvs_put, kvs_get, kvs_erase\r\n");

  while (true) {
    thread_t *shelltp =
        chThdCreateFromHeap(NULL, SHELL_WA_SIZE, "shell", NORMALPRIO + 1,
                            shellThread, (void *)&shell_cfg);
    if (shelltp == NULL) {
      chprintf((BaseSequentialStream *)&SD0, "Unable to create shell\r\n");
      chThdSleepMilliseconds(1000);
      continue;
    }
    chThdWait(shelltp);
    chThdSleepMilliseconds(1000);
  }
}

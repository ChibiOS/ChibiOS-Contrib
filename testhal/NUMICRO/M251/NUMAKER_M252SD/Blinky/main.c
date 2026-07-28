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

#include "ch.h"
#include "hal.h"

static THD_WORKING_AREA(waProtectedRegisters, 128);
static volatile bool protected_entered;
static volatile bool protected_done;
static volatile bool protected_failed;

static THD_FUNCTION(ProtectedRegistersThread, arg) {

  (void)arg;
  m251_lld_unlock();
  protected_entered = true;
  chThdSleepMilliseconds(100);
  if ((SYS->REGLCTL & 1U) == 0U) {
    protected_failed = true;
  }
  m251_lld_lock();
  protected_done = true;
}

static void test_protected_register_nesting(void) {
  bool initially_unlocked = (SYS->REGLCTL & 1U) != 0U;

  m251_lld_unlock();
  chThdCreateStatic(waProtectedRegisters, sizeof(waProtectedRegisters),
                    NORMALPRIO + 1, ProtectedRegistersThread, NULL);
  while (!protected_entered) {
    chThdSleepMilliseconds(1);
  }

  /* The worker still owns a nested unlock, so this lock must not physically
     relock the protected register bank.*/
  m251_lld_lock();
  if ((SYS->REGLCTL & 1U) == 0U) {
    protected_failed = true;
  }

  while (!protected_done) {
    chThdSleepMilliseconds(1);
  }
  if (((SYS->REGLCTL & 1U) != 0U) != initially_unlocked) {
    protected_failed = true;
  }
  if (protected_failed) {
    osalSysHalt("protected-register nesting failed");
  }
}

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization also initializes the configured device drivers and
   *   performs the board-specific initialization.
   * - RT initialization enables scheduling and interrupts.
   */
  halInit();
  chSysInit();

  test_protected_register_nesting();

  while (true) {
    OnboardLED_Toggle();
    osalThreadSleepMilliseconds(1000);
  }
}

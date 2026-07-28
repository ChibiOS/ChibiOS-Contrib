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

#define INPUT_LINE  PAL_LINE(PA, 0U)
#define OUTPUT_LINE PAL_LINE(PA, 3U)

static volatile uint32_t rising_count;
static volatile uint32_t falling_count;

static void input_cb(void *arg) {
  (void)arg;

  if (palReadLine(INPUT_LINE) == PAL_HIGH) {
    rising_count++;
  }
  else {
    falling_count++;
  }
  OnboardLED_Toggle();
}

int main(void) {
  uint32_t last_rising = 0U;
  uint32_t last_falling = 0U;
  bool output_high = false;

  halInit();
  chSysInit();

  sdStart(&SD0, NULL);
  chprintf((BaseSequentialStream *)&SD0,
           "\r\nM252 PAL edge-event test\r\n"
           "Connect D10/PA.3 to D11/PA.0.\r\n");

  palClearLine(OUTPUT_LINE);
  palSetLineMode(OUTPUT_LINE, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLineMode(INPUT_LINE, PAL_MODE_INPUT_PULLDOWN);
  palSetLineCallback(INPUT_LINE, input_cb, NULL);
  palEnableLineEvent(INPUT_LINE, PAL_EVENT_MODE_BOTH_EDGES);

  /* A transition while disabled must not invoke the callback. Disabling an
     event also clears its callback, which must be registered again before
     re-enabling. The stale source must not be reported as a new edge.*/
  palDisableLineEvent(INPUT_LINE);
  palSetLine(OUTPUT_LINE);
  chThdSleepMilliseconds(100);
  if ((rising_count != 0U) || (falling_count != 0U)
      || (palReadLine(INPUT_LINE) != PAL_HIGH)) {
    chprintf((BaseSequentialStream *)&SD0,
             "disable self-test: ERROR input=%u rising=%u falling=%u\r\n",
             palReadLine(INPUT_LINE), rising_count, falling_count);
    chThdSleepMilliseconds(100);
    osalSysHalt("PAL event disable failed");
  }
  palSetLineCallback(INPUT_LINE, input_cb, NULL);
  palEnableLineEvent(INPUT_LINE, PAL_EVENT_MODE_BOTH_EDGES);
  palClearLine(OUTPUT_LINE);
  chThdSleepMilliseconds(100);
  if ((rising_count != 0U) || (falling_count != 1U)) {
    chprintf((BaseSequentialStream *)&SD0,
             "re-enable self-test: ERROR input=%u rising=%u falling=%u\r\n",
             palReadLine(INPUT_LINE), rising_count, falling_count);
    chThdSleepMilliseconds(100);
    osalSysHalt("PAL event re-enable failed");
  }
  chSysLock();
  rising_count = 0U;
  falling_count = 0U;
  chSysUnlock();

  chprintf((BaseSequentialStream *)&SD0,
           "disable/re-enable self-test: PASS\r\n"
           "D11 initial level: %u\r\n",
           palReadLine(INPUT_LINE));

  while (true) {
    output_high = !output_high;
    palWriteLine(OUTPUT_LINE, output_high ? PAL_HIGH : PAL_LOW);
    chThdSleepMilliseconds(100);

    uint32_t input = palReadLine(INPUT_LINE);
    uint32_t rising = rising_count;
    uint32_t falling = falling_count;
    bool passed;

    if (output_high) {
      passed = (input == PAL_HIGH) && (rising == (last_rising + 1U))
               && (falling == last_falling);
    }
    else {
      passed = (input == PAL_LOW) && (rising == last_rising)
               && (falling == (last_falling + 1U));
    }

    chprintf((BaseSequentialStream *)&SD0,
             "output=%u input=%u rising=%u falling=%u %s\r\n", output_high,
             input, rising, falling, passed ? "OK" : "ERROR");
    last_rising = rising;
    last_falling = falling;
    chThdSleepMilliseconds(900);
  }
}

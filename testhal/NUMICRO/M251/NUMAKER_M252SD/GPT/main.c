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

#include "ch.h"
#include "hal.h"

static volatile uint32_t callback_count;

static void gpt_callback(GPTDriver *gptp) {

  (void)gptp;
  callback_count++;
  OnboardLED_Toggle();
}

static const GPTConfig gptcfg = {
  .frequency = 1U,
  .callback = gpt_callback,
};

int main(void) {
  uint32_t snapshot;

  halInit();
  chSysInit();

  gptStart(&GPTD1, &gptcfg);
  gptStartContinuous(&GPTD1, 1U);

  chThdSleepMilliseconds(2500);
  if (callback_count < 2U) {
    osalSysHalt("GPT callback did not fire");
  }

  gptStopTimer(&GPTD1);
  snapshot = callback_count;
  chThdSleepMilliseconds(1200);
  if (callback_count != snapshot) {
    osalSysHalt("GPT timer stop failed");
  }

  gptStop(&GPTD1);
  gptStart(&GPTD1, &gptcfg);
  gptStartContinuous(&GPTD1, 1U);
  snapshot = callback_count;
  chThdSleepMilliseconds(1200);
  if (callback_count == snapshot) {
    osalSysHalt("GPT timer restart failed");
  }

  while (true) {
    chThdSleepMilliseconds(1000);
  }
}

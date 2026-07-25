/*
    Adapted from ChibiOS-Contrib/testhal/KINETIS/FRDM-KL25Z/PWM
    Copyright (C) 2015 flabbergast <s3+flabbergast@sdfeu.org>
    Modifications copyright (C) 2020 Alex Lewontin
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
#include "M251/stddriver/sys.h"

#define PWM_OUTPUT_LINE                     PAL_LINE(PA, 0U)

static volatile uint32_t period_callbacks;
static volatile uint32_t channel_callbacks;

static void period_cb(PWMDriver *pwmp) {

  (void)pwmp;
  period_callbacks++;
}

static void channel_cb(PWMDriver *pwmp) {

  (void)pwmp;
  channel_callbacks++;
}

static const PWMConfig pwmcfg = {
  .frequency = 100000U,
  .period    = 100U,
  .callback  = period_cb,
  .channels  = {
    {PWM_OUTPUT_ACTIVE_LOW, channel_cb},
    {PWM_OUTPUT_DISABLED, NULL},
    {PWM_OUTPUT_DISABLED, NULL},
    {PWM_OUTPUT_DISABLED, NULL},
    {PWM_OUTPUT_DISABLED, NULL},
    {PWM_OUTPUT_DISABLED, NULL},
  },
};

static const pwmcnt_t brightness_steps[] = {
  1U, 10U, 25U, 50U, 75U, 90U,
};

int main(void) {
  uint32_t period_snapshot;
  uint32_t channel_snapshot;

  halInit();
  chSysInit();

  /* PB.14 must not drive against the jumpered BPWM0_CH0 output on PA.0.*/
  palSetLineMode(ONBOARD_LED_LINE, PAL_MODE_INPUT);

  SYS->GPA_MFPL = (SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0MFP_Msk) |
                  SYS_GPA_MFPL_PA0MFP_BPWM0_CH0;
  palSetLineMode(PWM_OUTPUT_LINE, PAL_MODE_UNCONNECTED | PAL_M251_MFP_PRESERVE);

  pwmStart(&PWMD1, &pwmcfg);

  /*
    Exercise both notification sources, their disable paths, and a complete
    stop/start cycle before entering the visual duty-cycle test.
  */
  pwmEnableChannel(&PWMD1, 0U, 50U);
  pwmEnablePeriodicNotification(&PWMD1);
  pwmEnableChannelNotification(&PWMD1, 0U);
  chThdSleepMilliseconds(250);
  if ((period_callbacks == 0U) || (channel_callbacks == 0U)) {
    osalSysHalt("PWM notification did not fire");
  }

  pwmDisableChannelNotification(&PWMD1, 0U);
  channel_snapshot = channel_callbacks;
  period_snapshot = period_callbacks;
  chThdSleepMilliseconds(100);
  if ((channel_callbacks != channel_snapshot) ||
      (period_callbacks == period_snapshot)) {
    osalSysHalt("PWM channel notification disable failed");
  }

  pwmDisablePeriodicNotification(&PWMD1);
  period_snapshot = period_callbacks;
  chThdSleepMilliseconds(100);
  if (period_callbacks != period_snapshot) {
    osalSysHalt("PWM periodic notification disable failed");
  }

  /* Exercise the READY-to-READY reconfiguration path.*/
  pwmStart(&PWMD1, &pwmcfg);
  pwmStop(&PWMD1);
  pwmStart(&PWMD1, &pwmcfg);

  while (true) {
    for (size_t i = 0U;
         i < sizeof(brightness_steps) / sizeof(brightness_steps[0]);
         i++) {
      pwmEnableChannel(&PWMD1, 0U, brightness_steps[i]);
      chThdSleepMilliseconds(2000);
    }
  }
}

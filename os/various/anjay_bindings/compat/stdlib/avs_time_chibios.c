/*
    ChibiOS - Copyright (C) 2023 Xael South

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

#include <avsystem/commons/avs_time.h>

#include "ch.h"
#include "hal.h"

/*
 * The avs_time_real_now() function should return the current real time,
 * i.e. the amount of time that passed since January 1st, 1970, midnight
 * UTC (the Unix epoch).
 */
avs_time_real_t avs_time_real_now(void) {

  avs_time_real_t result;

  const systime_t now = chVTGetSystemTime();

  /* Using TIME_I2S() is impossible because of rounding up to the next seconds. */
  result.since_real_epoch.seconds = (time_conv_t)now / (time_conv_t)CH_CFG_ST_FREQUENCY;
  result.since_real_epoch.nanoseconds = (time_conv_t)now - (time_conv_t)(
                                          result.since_real_epoch.seconds) * (time_conv_t)CH_CFG_ST_FREQUENCY;
  result.since_real_epoch.nanoseconds = TIME_I2US(result.since_real_epoch.nanoseconds) *
                                        (time_conv_t)1000;

  return result;
}

/*
 * The avs_time_monotonic_now() function should return the current monotonic time,
 * i.e. the amount of time that passed since some epoch - it might be any point in time,
 * but needs to be stable at least throughout the lifetime of the process - different
 * epochs might be used for different launches of the application.
 *
 * System boot time is often used as an epoch for the monotonic clock.
 * If the real-time clock is considered stable, and not reset while the application is
 * running, it may be also used as the monotonic clock.
*/
avs_time_monotonic_t avs_time_monotonic_now(void) {

  avs_time_monotonic_t result;

  const systime_t now = chVTGetSystemTime();

  /* Using TIME_I2S() is impossible because of rounding up to the next seconds. */
  result.since_monotonic_epoch.seconds = (time_conv_t)now / (time_conv_t)CH_CFG_ST_FREQUENCY;
  result.since_monotonic_epoch.nanoseconds = (time_conv_t)now - (time_conv_t)(
        result.since_monotonic_epoch.seconds) * (time_conv_t)CH_CFG_ST_FREQUENCY;
  result.since_monotonic_epoch.nanoseconds = TIME_I2US(result.since_monotonic_epoch.nanoseconds) *
      (time_conv_t)1000;

  return result;
}

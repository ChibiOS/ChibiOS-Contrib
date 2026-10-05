/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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

/*===========================================================================*/
/* SK32F0xx RTC calendar and alarm test.                                     */
/*===========================================================================*/

/*
 * Test resources used by this test:
 *
 *  - RTCD1 (RTC), clocked by the internal LSI oscillator (see SK32_RTC_USE_LSE
 *    in cfg/mcuconf.h), the calendar runs at 1Hz.
 *  - PB14 / PB15: two board LEDs wired to push-pull outputs, the PAL
 *    abstraction drives them high (PAL_HIGH) to switch the LEDs on.
 *
 * Test procedure:
 *  - A known date/time is written with rtcSetTime() and immediately read back
 *    with rtcGetTime(): the year, month, day and the time of day are verified
 *    while the seconds are only bounded because the calendar may have already
 *    advanced between the two calls.
 *  - Alarm A is programmed to fire at second 58 of every minute with the
 *    date, hour and minute fields masked out, and the alarm callback is
 *    installed.  The alarm is also read back with rtcGetAlarm() and compared
 *    against the expected ALRMAR encoding.
 *  - The main thread waits up to ten seconds for the alarm callback to fire
 *    (it is expected after about three seconds because the calendar was set
 *    to 12:34:55) and then verifies that the calendar advanced past the alarm
 *    second.
 *  - On success the test enters a steady state blinking PB14 at 1Hz while
 *    PB15 keeps toggling on every alarm.  On any failure both LEDs are
 *    switched on solid and the system halts.
 */

/* Alarm callback counter, incremented in interrupt context. */
static volatile uint32_t alarmcnt;

/* Alarm callback, toggles PB15 on every alarm A event. */
static void alarmcb(RTCDriver *rtcp, rtcevent_t event) {

  (void)rtcp;

  if (event == RTC_EVENT_ALARM_A) {
    alarmcnt++;
    palTogglePad(GPIOB, GPIOB_PIN15);
  }
}

/*
 * Both LEDs on solid and halt, used on any test failure.
 */
static void test_fail(void) {

  palSetPad(GPIOB, GPIOB_PIN14);
  palSetPad(GPIOB, GPIOB_PIN15);
  chSysHalt("RTC test FAIL");
}

/*
 * Application entry point.
 */
int main(void) {
  RTCDateTime timespec;
  RTCAlarm alarmrd;
  uint32_t startcnt;
  unsigned i;

  /* Alarm A: match second 58, no date/hour/minute match. */
  static const RTCAlarm alarm = {
    RTC_ALRM_MSK4       |   /* No month/week day match.                 */
    RTC_ALRM_MSK3       |   /* No hour match.                           */
    RTC_ALRM_MSK2       |   /* No minutes match.                        */
    RTC_ALRM_ST(5)      |
    RTC_ALRM_SU(8)          /* Match second 58.                         */
  };

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /* Configuring the PB14/PB15 LED lines as push-pull outputs, initially off. */
  palSetPadMode(GPIOB, GPIOB_PIN14, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOB, GPIOB_PIN15, PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB, GPIOB_PIN14);
  palClearPad(GPIOB, GPIOB_PIN15);

  /*
   * Writing a known date/time, the seconds are set to 55 so that the second
   * 58 alarm programmed below fires after only about three seconds.
   */
  timespec.year        = 2024U - RTC_BASE_YEAR;
  timespec.month       = 1U;
  timespec.dstflag     = 0U;
  timespec.dayofweek   = RTC_DAY_MONDAY;
  timespec.day         = 1U;
  timespec.millisecond = (12U * 3600U + 34U * 60U + 55U) * 1000U;
  rtcSetTime(&RTCD1, &timespec);

  /* Reading the calendar back and verifying the fields. */
  rtcGetTime(&RTCD1, &timespec);
  if ((timespec.year != (2024U - RTC_BASE_YEAR)) ||
      (timespec.month != 1U) ||
      (timespec.day != 1U) ||
      (timespec.millisecond < (12U * 3600U + 34U * 60U + 55U) * 1000U) ||
      (timespec.millisecond >= (12U * 3600U + 34U * 60U + 58U) * 1000U)) {
    test_fail();
  }

  /* Installing the callback first, then arming alarm A. */
  rtcSetCallback(&RTCD1, alarmcb);
  rtcSetAlarm(&RTCD1, 0U, &alarm);

  /* Verifying that the ALRMAR register holds the expected encoding. */
  rtcGetAlarm(&RTCD1, 0U, &alarmrd);
  if (alarmrd.alrmr != alarm.alrmr) {
    test_fail();
  }

  /* Both LEDs on while waiting for the alarm. */
  startcnt = alarmcnt;
  palSetPad(GPIOB, GPIOB_PIN14);
  palSetPad(GPIOB, GPIOB_PIN15);

  /* Waiting up to ten seconds for the alarm callback to fire. */
  for (i = 0U; i < 100U; i++) {
    if (alarmcnt != startcnt) {
      break;
    }
    chThdSleepMilliseconds(100);
  }
  if (alarmcnt == startcnt) {
    test_fail();
  }

  /* Verifying that the calendar advanced to at least the alarm second. */
  rtcGetTime(&RTCD1, &timespec);
  if (timespec.millisecond < (12U * 3600U + 34U * 60U + 58U) * 1000U) {
    test_fail();
  }

  /* Success: LEDs off, steady state with a 1Hz heartbeat on PB14 and an
     alarm-driven toggle on PB15. */
  palClearPad(GPIOB, GPIOB_PIN14);
  palClearPad(GPIOB, GPIOB_PIN15);
  while (true) {
    palTogglePad(GPIOB, GPIOB_PIN14);
    chThdSleepMilliseconds(500);
  }
}

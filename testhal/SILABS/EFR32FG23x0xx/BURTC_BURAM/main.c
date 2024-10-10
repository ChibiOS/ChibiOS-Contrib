/*
    ChibiOS - Copyright (C) 2024 Xael South

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

#include <string.h>
#include "cmsis_os.h"
#include "hal.h"
#include "hal_buram.h"

static void led_on(void) {

  /* PB2 = LED */
  palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPad(GPIOB, 2);
}

static void led_off(void) {

  /* PB2 = LED */
  palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB, 2);
}

static int time_is_set;
static int alarm_triggered;

static const RTCAlarm alarmspec1 = {
  .tv_sec = 2,
  .tv_usec = 100,
};

static void rtc_callback(RTCDriver* rtcp, rtcevent_t evt) {

  switch (evt) {
    case RTC_EVENT_TIME_SET:
      time_is_set++;
      break;
    case RTC_EVENT_ALARM:
      alarm_triggered++;
      /* Retrigger alarm. */
      rtcSetAlarm(rtcp, 0, &alarmspec1);
      break;
    case RTC_EVENT_TS_OVF:
      break;
  }
}

static void test_rtc(void) {

  rtcSetCallback(&RTCD1, rtc_callback);

  const RTCDateTime ts1 = {
    .year = 44,
    .month = 6,
    .dstflag = 0,
    .dayofweek = 7,
    .day = 9,
    .millisecond = (19 * 3600 + 4 * 60 + 30) * 1000 + 123
  };
  rtcSetTime(&RTCD1, &ts1);

  osDelay(1000);
  osDelay(1000);

  RTCDateTime ts2 = { 0 };
  rtcGetTime(&RTCD1, &ts2);

  osalDbgAssert(time_is_set == 1, "no time set event");
  osalDbgAssert(ts1.year == ts2.year, "wrong year");
  osalDbgAssert(ts1.month == ts2.month, "wrong month");
  osalDbgAssert(ts1.dstflag == ts2.dstflag, "wrong dstflag");
  osalDbgAssert(ts1.dayofweek == ts2.dayofweek, "wrong dayofweek");
  osalDbgAssert(ts1.day == ts2.day, "wrong day");
  osalDbgAssert((ts1.millisecond + 2000 - ts2.millisecond) < 10, "wrong milliscond");
}

static void test_rtc_alarm(void) {

  rtcSetAlarm(&RTCD1, 0, &alarmspec1);

  RTCAlarm alarmspec2 = { 0 };
  rtcGetAlarm(&RTCD1, 0, &alarmspec2);

  osalDbgAssert(alarmspec1.tv_sec == alarmspec2.tv_sec, "wrong alarm second");
  osalDbgAssert((alarmspec1.tv_usec - alarmspec2.tv_usec) < 50, "wrong alarm microsecond");

  osDelay(alarmspec1.tv_sec * 1000 + 1 + alarmspec1.tv_usec / 1000);
  osalDbgAssert(alarm_triggered == 1, "no first alarm triggered");

  osDelay(alarmspec1.tv_sec * 1000 + 1 + alarmspec1.tv_usec / 1000);
  osalDbgAssert(alarm_triggered == 2, "no second alarm triggered");
}

/*
 * Application entry point.
 */
int main(void) {

  int unused = 0;
  (void)unused;

  /* HAL initialization, this also initializes the configured device drivers
     and performs the board-specific initializations.*/
  halInit();

  /* The kernel is initialized but not started yet, this means that
     main() is executing with absolute priority but interrupts are
     already enabled.*/
  osKernelInitialize();

  /* Kernel started, the main() thread has priority osPriorityNormal
     by default.*/
  osKernelStart();

  buramInit();
  BURAMConfig cfgp;
  buramStart(&BURAMD1, &cfgp);

  led_off();
  test_rtc();
  test_rtc_alarm();
  led_on();

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    osDelay(1000);
  }
}
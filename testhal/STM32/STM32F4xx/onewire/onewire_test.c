/*
    ChibiOS/RT - Copyright (C) 2014 Uladzimir Pylinsky aka barthess

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

#include "onewire.h"

/*
 ******************************************************************************
 * DEFINES
 ******************************************************************************
 */
#define ONEWIRE_MASTER_CHANNEL        2 /* this PWM channel drives bus */
#define ONEWIRE_SAMPLE_CHANNEL        3 /* this one generates interrupts when sampling needed */

#if defined(BOARD_ST_STM32F4_DISCOVERY)
#define GPIOB_ONEWIRE                 GPIOB_PIN8
#define search_led_off()              (palClearPad(GPIOD, GPIOD_LED4))
#define search_led_on()               (palSetPad(GPIOD, GPIOD_LED4))
#else
#define GPIOB_ONEWIRE                 GPIOB_TACHOMETER
#include "pads.h"
#define search_led_on     red_led_on
#define search_led_off    red_led_off
#endif

/*
 ******************************************************************************
 * EXTERNS
 ******************************************************************************
 */

/*
 ******************************************************************************
 * PROTOTYPES
 ******************************************************************************
 */

static uint_fast8_t onewire_read_bit_X(void);

#if ONEWIRE_USE_STRONG_PULLUP
static void strong_pullup_assert(void);
static void strong_pullup_release(void);
#endif

/*
 ******************************************************************************
 * GLOBAL VARIABLES
 ******************************************************************************
 */

static uint8_t testbuf[12];

static float temperature[3];

/*
 *
 */
static const onewireConfig ow_cfg = {
  &PWMD4,
  ONEWIRE_MASTER_CHANNEL,
  ONEWIRE_SAMPLE_CHANNEL,
  onewire_read_bit_X,
#if ONEWIRE_USE_STRONG_PULLUP
  strong_pullup_assert,
  strong_pullup_release
#endif
};

/*
 ******************************************************************************
 ******************************************************************************
 * LOCAL FUNCTIONS
 ******************************************************************************
 ******************************************************************************
 */

#if ONEWIRE_USE_STRONG_PULLUP
/**
 *
 */
static void strong_pullup_assert(void) {
  palSetPadMode(GPIOB, GPIOB_ONEWIRE, PAL_MODE_ALTERNATE(2) |
                  PAL_STM32_OTYPE_PUSHPULL | PAL_STM32_PUDR_PULLUP);
}

/**
 *
 */
static void strong_pullup_release(void) {
  palSetPadMode(GPIOB, GPIOB_ONEWIRE, PAL_MODE_ALTERNATE(2) |
                PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUDR_PULLUP);
}
#endif /* ONEWIRE_USE_STRONG_PULLUP */

/**
 *
 */
static uint_fast8_t onewire_read_bit_X(void) {
#if ONEWIRE_SYNTH_SEARCH_TEST
  return _synth_ow_read_bit();
#else
  return palReadPad(GPIOB, GPIOB_ONEWIRE);
#endif
}

/*
 ******************************************************************************
 * EXPORTED FUNCTIONS
 ******************************************************************************
 */

/**
 *
 */
void onewireTest(void) {

  uint16_t tmp;
  uint8_t rombuf[24];
  size_t devices_on_bus = 0;
  size_t i = 0;
  volatile bool presence;

  onewireObjectInit(&OWD1);
  onewireStart(&OWD1, &ow_cfg);

#if ONEWIRE_SYNTH_SEARCH_TEST
  synthSearchRomTest(&OWD1);
#endif

  for (i=0; i<3; i++)
    temperature[i] = -666;

  while (true) {
    if (true == onewireReset(&OWD1)){

      memset(rombuf, 0x55, sizeof(rombuf));
      search_led_on();
      devices_on_bus = onewireSearchRom(&OWD1, rombuf, 3);
      search_led_off();
      osalDbgCheck(devices_on_bus <= 3);
      osalDbgCheck(devices_on_bus  > 0);

      if (1 == devices_on_bus){
        /* test read rom command */
        presence = onewireReset(&OWD1);
        osalDbgCheck(true == presence);
        testbuf[0] = ONEWIRE_CMD_READ_ROM;
        onewireWrite(&OWD1, testbuf, 1, 0);
        onewireRead(&OWD1, testbuf, 8);
        osalDbgCheck(testbuf[7] == onewireCRC(testbuf, 7));
        osalDbgCheck(0 == memcmp(rombuf, testbuf, 8));
      }

      /* start temperature measurement on all connected devices at once */
      presence = onewireReset(&OWD1);
      osalDbgCheck(true == presence);
      testbuf[0] = ONEWIRE_CMD_SKIP_ROM;
      testbuf[1] = ONEWIRE_CMD_CONVERT_TEMP;

#if ONEWIRE_USE_STRONG_PULLUP
      onewireWrite(&OWD1, testbuf, 2, MS2ST(750));
#else
      onewireWrite(&OWD1, testbuf, 2, 0);
      /* poll bus waiting ready signal from all connected devices */
      testbuf[0] = 0;
      while (testbuf[0] == 0){
        osalThreadSleepMilliseconds(50);
        onewireRead(&OWD1, testbuf, 1);
      }
#endif

      for (i=0; i<devices_on_bus; i++) {
        /* read temperature device by device from their scratchpads */
        presence = onewireReset(&OWD1);
        osalDbgCheck(true == presence);

        testbuf[0] = ONEWIRE_CMD_MATCH_ROM;
        memcpy(&testbuf[1], &rombuf[i*8], 8);
        testbuf[9] = ONEWIRE_CMD_READ_SCRATCHPAD;
        onewireWrite(&OWD1, testbuf, 10, 0);

        onewireRead(&OWD1, testbuf, 9);
        osalDbgCheck(testbuf[8] == onewireCRC(testbuf, 8));
        tmp = 0;
        tmp |= (testbuf[1] << 8) | testbuf[0];
        temperature[i] = tmp * 0.0625;
      }
    }
    else {
      osalSysHalt("");
    }
    osalThreadSleep(1); /* enforce ChibiOS's stack overflow check */
  }

  onewireStop(&OWD1);
}

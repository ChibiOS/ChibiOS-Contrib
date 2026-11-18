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
/* SK32F0xx watchdog test, IWDG (WDGD1) or WWDG (WDGD2).                     */
/*===========================================================================*/

/*
 * Test resources used by this test:
 *
 *  - WDGD1 (IWDG, clocked by the LSI oscillator) or WDGD2 (WWDG, clocked by
 *    PCLK1), selected through the WDG_TEST_USE_WWDG switch below, both
 *    drivers are enabled in cfg/mcuconf.h.
 *  - PB14 / PB15: two board LEDs wired to push-pull outputs, the PAL
 *    abstraction drives them high (PAL_HIGH) to switch the LEDs on.
 *
 * Test procedure:
 *  - The selected watchdog is started with wdgStart() and the returned status
 *    plus the resulting driver state are verified.
 *  - The main thread enters a loop refreshing the watchdog every 10ms (well
 *    inside the shortest of the two deadlines) and toggling PB14 every 500ms,
 *    so a correctly serviced watchdog never resets the board and the LED
 *    blinks at 1Hz.
 *  - To observe the reset behaviour of the watchdog comment out the
 *    wdgReset() call: the board then resets continuously and PB14 no longer
 *    blinks (the LED appears dim or off).  Leaving the call in place proves
 *    that the refresh path works and that the deadline is long enough.
 *  - On any detected failure both LEDs are switched on solid and the system
 *    halts.
 */

/**
 * @brief   Watchdog controller selection.
 * @details Set to 0 to exercise the IWDG (WDGD1), to 1 to exercise the WWDG
 *          (WDGD2).
 */
#define WDG_TEST_USE_WWDG           0

#if WDG_TEST_USE_WWDG && !SK32_WDG_USE_WWDG
#error "SK32_WDG_USE_WWDG must be TRUE to run the WWDG test"
#endif

#if !WDG_TEST_USE_WWDG && !SK32_WDG_USE_IWDG
#error "SK32_WDG_USE_IWDG must be TRUE to run the IWDG test"
#endif

#if WDG_TEST_USE_WWDG
#define WDG_TEST_DRIVER             WDGD2
#else
#define WDG_TEST_DRIVER             WDGD1
#endif

/*
 * Watchdog configurations.
 * IWDG: LSI ~40kHz divided by 64 gives a 625Hz counter clock, a reload value
 *       of 1000 sets a deadline of about 1.6s.
 * WWDG: PCLK1 72MHz divided by 4096 and by the 8 prescaler gives a 2197Hz
 *       counter clock, the counter counts down from 0x7F and resets the
 *       board when it reaches 0x3F, a deadline of about 29ms.  The window
 *       value is set to 0x7F so that the refresh is never considered too
 *       early.
 */
static const WDGConfig wdgcfg = {
#if WDG_TEST_USE_WWDG
  .pr           = 0U,
  .rlr          = 0U,
  .winr         = 0U,
  .t            = 0x7FU,
  .w            = 0x7FU,
  .wdgtb        = SK32_WWDG_WDGTB_DIV8
#else
  .pr           = SK32_IWDG_PR_DIV64,
  .rlr          = SK32_IWDG_RL(1000),
  .winr         = SK32_IWDG_WIN_DISABLED,
  .t            = 0U,
  .w            = 0U,
  .wdgtb        = 0U
#endif
};

/*
 * Both LEDs on solid and halt, used on any test failure.
 */
static void test_fail(void) {

  palSetPad(GPIOB, GPIOB_PIN14);
  palSetPad(GPIOB, GPIOB_PIN15);
  chSysHalt("WDG test FAIL");
}

/*
 * Application entry point.
 */
int main(void) {
  uint32_t n;

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

  /* Starting the selected watchdog, the generic layer reports success and
     moves the driver to the ready state. */
  if (wdgStart(&WDG_TEST_DRIVER, &wdgcfg) != HAL_RET_SUCCESS) {
    test_fail();
  }
  if (WDG_TEST_DRIVER.state != WDG_READY) {
    test_fail();
  }

  /*
   * Normal main() thread activity: refresh the watchdog every 10ms and blink
   * PB14 every 500ms.
   */
  n = 0U;
  while (true) {
    wdgReset(&WDG_TEST_DRIVER);

    if (++n >= 50U) {
      n = 0U;
      palTogglePad(GPIOB, GPIOB_PIN14);
    }

    chThdSleepMilliseconds(10);
  }
}

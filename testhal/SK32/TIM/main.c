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
/* SK32F0xx TIM3/TIM16/TIM17 GPT interrupt counting test.                    */
/*===========================================================================*/

/*
 * Test resources used by this test:
 *
 *  - GPTD3  (TIM3,  APB1 clock domain) with a 10 kHz tick and a 10000-tick
 *    period: its update interrupt fires once per second.
 *  - GPTD16 (TIM16, APB2 clock domain) with a 10 kHz tick and a 2000-tick
 *    period: its update interrupt fires five times per second.
 *  - GPTD17 (TIM17, APB2 clock domain) with a 2 kHz tick and a 2000-tick
 *    period: its update interrupt fires once per second.
 *  - PB14 / PB15: two board LEDs wired to push-pull outputs, the PAL
 *    abstraction drives them high (PAL_HIGH) to switch the LEDs on.
 *
 * Test procedure:
 *  - Each update interrupt increments its own counter in the GPT callback
 *    (interrupt context) and GPTD3/GPTD16 additionally toggle PB14/PB15,
 *    producing two clearly distinguishable blink rates (1 s period on PB14,
 *    200 ms period on PB15).
 *  - The main thread samples the three counters every 10 s of wall time and
 *    verifies that GPTD3 and GPTD17 have ticked about ten times and GPTD16
 *    about fifty times: this proves the timers are actually counting and
 *    that the update interrupts are being serviced.
 *  - On the first out-of-range delta both LEDs are switched on solid and the
 *    system halts.
 */

/* Interrupt context counters, incremented by the GPT callbacks. */
static volatile uint32_t cnt3;
static volatile uint32_t cnt16;
static volatile uint32_t cnt17;

/*
 * GPT update callbacks.  GPTD3 toggles PB14 (once per second) and GPTD16
 * toggles PB15 (five times per second), GPTD17 is only used for counting.
 */
static void gpt3cb(GPTDriver *gptp) {

  (void)gptp;
  cnt3++;
  palTogglePad(GPIOB, GPIOB_PIN14);
}

static void gpt16cb(GPTDriver *gptp) {

  (void)gptp;
  cnt16++;
  palTogglePad(GPIOB, GPIOB_PIN15);
}

static void gpt17cb(GPTDriver *gptp) {

  (void)gptp;
  cnt17++;
}

/*
 * GPT configurations.
 * The 72 MHz peripheral clock is divided down to the tick frequency, then
 * each period is expressed in ticks of that timer tick clock.
 */
static const GPTConfig gpt3cfg = {
  .frequency = 10000U,              /* 72MHz / 7200 -> 10 kHz tick clock.   */
  .callback  = gpt3cb,
  .cr2       = 0U,
  .dier      = 0U
};

static const GPTConfig gpt16cfg = {
  .frequency = 10000U,              /* 72MHz / 7200 -> 10 kHz tick clock.   */
  .callback  = gpt16cb,
  .cr2       = 0U,
  .dier      = 0U
};

static const GPTConfig gpt17cfg = {
  .frequency = 2000U,               /* 72MHz / 36000 -> 2 kHz tick clock.   */
  .callback  = gpt17cb,
  .cr2       = 0U,
  .dier      = 0U
};

/*
 * Application entry point.
 */
int main(void) {
  uint32_t base3;
  uint32_t base16;
  uint32_t base17;

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
   * GPTD3: 1 Hz period (10000 ticks @ 10 kHz).
   * GPTD16: 200 ms period (2000 ticks @ 10 kHz).
   * GPTD17: 1 s period (2000 ticks @ 2 kHz).
   */
  gptStart(&GPTD3, &gpt3cfg);
  gptStart(&GPTD16, &gpt16cfg);
  gptStart(&GPTD17, &gpt17cfg);
  gptStartContinuous(&GPTD3, 10000U);
  gptStartContinuous(&GPTD16, 2000U);
  gptStartContinuous(&GPTD17, 2000U);

  /*
   * Counting verification loop.
   */
  base3  = cnt3;
  base16 = cnt16;
  base17 = cnt17;
  while (true) {
    uint32_t delta3;
    uint32_t delta16;
    uint32_t delta17;

    /* Sampling window of 10 s of wall time.*/
    chThdSleepMilliseconds(10000);

    delta3  = cnt3  - base3;
    delta16 = cnt16 - base16;
    delta17 = cnt17 - base17;

    /*
     * Expected values: about 10 interrupts for GPTD3 and GPTD17 (1 Hz) and
     * about 50 interrupts for GPTD16 (5 Hz).  A small tolerance absorbs the
     * phase difference between the sampling points and the timer periods.
     */
    if ((delta3 < 8U)  || (delta3  > 12U) ||
        (delta16 < 45U) || (delta16 > 55U) ||
        (delta17 < 8U)  || (delta17 > 12U)) {
      /* Failure: both LEDs on solid, halt.*/
      palSetPad(GPIOB, GPIOB_PIN14);
      palSetPad(GPIOB, GPIOB_PIN15);
      chSysHalt("TIM interrupt counting FAIL");
    }

    base3  = cnt3;
    base16 = cnt16;
    base17 = cnt17;
  }
}

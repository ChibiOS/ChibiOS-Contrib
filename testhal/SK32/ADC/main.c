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
/* SK32F0xx ADC1 VREFINT sampling test.                                      */
/*===========================================================================*/

/*
 * Test resources used by this test:
 *
 *  - ADC1 with the internal reference voltage VREFINT (channel 17) as the
 *    only sampled source.  The VREFEN bit of the shared ADC CCR register is
 *    set right after adcStart() and left enabled for the whole test.
 *  - The native SK32F0xx ADC LLD samples the DR register inside the ADC
 *    interrupt handler (EOC events), no DMA stream is used.
 *  - PB14 / PB15: two board LEDs wired to push-pull outputs, the PAL
 *    abstraction drives them high (PAL_HIGH) to switch the LEDs on.
 *
 * Test procedure:
 *  - The main thread starts ADCD1 (the ADC kernel clock is PCLK/4, i.e.
 *    18 MHz with the 72 MHz PCLK of this platform), enables VREFINT and
 *    performs a sequence of blocking single conversions (12 bit, right
 *    aligned, 239.5 cycle sampling time).
 *  - Each conversion returns a raw sample of VREFINT / VDDA * 4096: with
 *    the ~1.2 V reference and a supply in the 1.8 .. 3.6 V range the value
 *    must fall in the 1100 .. 2900 window.  Eight consecutive samples must
 *    additionally be stable (max - min <= 100) because an internal
 *    reference does not move.
 *  - On success PB14 is switched on solid and PB15 blinks at 1 Hz as a
 *    heartbeat.  On the first out-of-range or unstable sample PB14 is
 *    switched off, PB15 is switched on solid and the system halts.
 */

#define ADC_NUM_SAMPLES                 8U

/* Acceptable raw window for the 12 bit VREFINT conversion (see above). */
#define ADC_VREFINT_RAW_MIN             1100U
#define ADC_VREFINT_RAW_MAX             2900U
/* Maximum allowed spread across the samples of one measurement. */
#define ADC_VREFINT_RAW_SPREAD          100U

/*
 * ADC conversion group: a single conversion of channel 17 (VREFINT), 12 bit
 * resolution (RES bits = 0), right aligned (ALIGN = 0), software triggered
 * (EXTEN = 0), one shot.  The 239.5 cycle sampling time is the longest one
 * available and is the recommended setting for the internal references.
 */
static const ADCConversionGroup vrefgrp = {
  .circular     = FALSE,
  .num_channels = 1U,
  .end_cb       = NULL,
  .error_cb     = NULL,
  .cfgr1        = 0U,
  .tr           = 0U,
  .smpr         = ADC_SMPR_SMP_239P5,
  .chselr       = ADC_CHSELR_CHSEL17
};

/*
 * Application entry point.
 */
int main(void) {
  adcsample_t sample[ADC_NUM_SAMPLES];
  adcsample_t mn;
  adcsample_t mx;
  unsigned i;

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
   * Starting the ADC and enabling the VREFINT analog source.  A short delay
   * lets the internal reference settle before the first conversion.
   */
  adcStart(&ADCD1, NULL);
  adcSK32EnableVREF(&ADCD1);
  chThdSleepMilliseconds(10);

  while (true) {
    /* Sampling one measurement: ADC_NUM_SAMPLES blocking conversions.*/
    for (i = 0U; i < ADC_NUM_SAMPLES; i++) {
      msg_t res;

      res = adcConvert(&ADCD1, &vrefgrp, &sample[i], 1U);
      if (res != MSG_OK) {
        /* Conversion aborted by an ADC error event.*/
        palClearPad(GPIOB, GPIOB_PIN14);
        palSetPad(GPIOB, GPIOB_PIN15);
        chSysHalt("ADC conversion FAIL");
      }
    }

    /* Range check.*/
    mn = sample[0];
    mx = sample[0];
    for (i = 1U; i < ADC_NUM_SAMPLES; i++) {
      if (sample[i] < mn) {
        mn = sample[i];
      }
      if (sample[i] > mx) {
        mx = sample[i];
      }
    }

    if ((mn < ADC_VREFINT_RAW_MIN) || (mx > ADC_VREFINT_RAW_MAX) ||
        ((uint32_t)(mx - mn) > (uint32_t)ADC_VREFINT_RAW_SPREAD)) {
      /* Failure: PB14 off, PB15 on solid, halt.*/
      palClearPad(GPIOB, GPIOB_PIN14);
      palSetPad(GPIOB, GPIOB_PIN15);
      chSysHalt("ADC VREFINT FAIL");
    }

    /* Success: PB14 on solid, PB15 blinks at 1 Hz as a heartbeat.*/
    palSetPad(GPIOB, GPIOB_PIN14);
    palTogglePad(GPIOB, GPIOB_PIN15);
    chThdSleepMilliseconds(500);
  }
}

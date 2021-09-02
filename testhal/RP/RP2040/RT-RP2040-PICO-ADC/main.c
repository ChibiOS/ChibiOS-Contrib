/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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

#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "hal_adc.h"

#include "chprintf.h"

#define LED_GREEN_PIN  25U

/*
 * Green LED blinker thread, times are in milliseconds.
 */
static CH_SYS_CORE0_MEMORY THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    chThdSleepMilliseconds(500);
    palToggleLine(LED_GREEN_PIN);
  }
}

/*
 * Call back function which called when ADC is finished.
 */
void adc_end_callback(ADCDriver *adcp) {
  (void)adcp;
  chprintf((BaseSequentialStream *)&SIOD0, "ADC end cb\r\n");
}

/*
 * Call back function which called when ADC gives some error.
 */
void adc_error_callback(ADCDriver *adcp, adcerror_t err) {
  (void)adcp;
  chprintf((BaseSequentialStream *)&SIOD0, "error: %d\r\n", err);
}

/*
 * Application entry point.
 */
int main(void) {
  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Activates the UART0 SIO driver using the default configuration.
   */
  sioStart(&SIOD0, NULL);
  sioStartOperation(&SIOD0, NULL);

  /*
   * Setting up GPIOs.
   */
  palSetLineMode(LED_GREEN_PIN, PAL_MODE_OUTPUT_PUSHPULL | PAL_RP_PAD_DRIVE12);

  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  const ADCConfig adcConfig = {
    0,      // div_int
    0,      // div_frac
    false,  // shift
  };

  const ADCConversionGroup adcConvGroup = {
    true,                 // circular
    2,                    // num_channels
    &adc_end_callback,    // end_cb
    &adc_error_callback,  // error_cb
    RP_ADC_CH0 | RP_ADC_CH1, // channel_mask
  };

  adcStart(&ADCD1, &adcConfig);

  /* Enable temperature sensor. */
  //adcRPEnableTS(&ADCD1);

  adcsample_t buf[2] = {0, 0};

  adcStartConversion(&ADCD1, &adcConvGroup, (adcsample_t *)&buf, 1);

  chThdSleepMilliseconds(500);
  chprintf((BaseSequentialStream *)&SIOD0, "buf[0]: %d\r\n", buf[0]);
  chprintf((BaseSequentialStream *)&SIOD0, "buf[1]: %d\r\n", buf[1]);
  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop.
   */
  while (true) {
    chThdSleepMilliseconds(500);
  }
}

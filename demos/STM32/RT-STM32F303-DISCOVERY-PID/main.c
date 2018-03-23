/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

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
#include "pid.h"

pid_t pid;
float input = 0, output = 0, target = 3500;

#define ADC_GRP1_NUM_CHANNELS   1
#define ADC_GRP1_BUF_DEPTH      8

static adcsample_t samples[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];

/*
 * ADC streaming callback.
 */
static void adccallback(ADCDriver *adcp, adcsample_t *buffer, size_t n) {

  (void)adcp;
  (void)n;
  if (samples == buffer) {
    input = buffer[4];
  }
}

/*
 * ADC conversion group.
 * Mode:        Linear buffer, 8 samples of 2 channels, SW triggered.
 * Channels:    IN0, IN8.
 */
static const ADCConversionGroup adcgrpcfg1 = {
  TRUE,
  ADC_GRP1_NUM_CHANNELS,
  adccallback,
  NULL,
  ADC_CFGR_CONT,            /* CFGR    */
  ADC_TR(0, 4095),          /* TR1     */
  {                         /* SMPR[2] */
    ADC_SMPR1_SMP_AN0(ADC_SMPR_SMP_19P5),
    0
  },
  {                         /* SQR[4]  */
    ADC_SQR1_SQ1_N(ADC_CHANNEL_IN0),
    0,
    0,
    0
  }
};

static const DACConfig dac1cfg1 = {
  .init         = 2047U,
  .datamode     = DAC_DHRM_12BIT_RIGHT,
  .cr           = 0
};

static void gptcb(GPTDriver *drv) {
    
    (void)drv;
    pid_compute(&pid);
    dacPutChannelX(&DACD1, 0, output);
}

/*
 * GPT6 configuration.
 */
static const GPTConfig gpt6cfg1 = {
  .frequency    = 100U,
  .callback     = gptcb,
  .cr2          = TIM_CR2_MMS_1,    /* MMS = 010 = TRGO on Update Event.    */
  .dier         = 0U
};

/*
 * Red LEDs blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palSetPad(GPIOE, GPIOE_LED10_RED);
    chThdSleepMilliseconds(500);
    palClearPad(GPIOE, GPIOE_LED10_RED);
    chThdSleepMilliseconds(500);
  }
}

/*
 * Application entry point.
 */
int main(void) {

  halInit();
  chSysInit();

  /*
  * Set PA0 PA3 PA4 to Analog (ADC1_CH1, DAC1_CH1)
  * You will have to connect these with a jumper wire
  */
  palSetPadMode(GPIOA, 0, PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOA, 3, PAL_MODE_INPUT_ANALOG);

  /*
   * Start peripherals
   */
  adcStart(&ADCD1, NULL);
  dacStart(&DACD1, &dac1cfg1);
  gptStart(&GPTD6, &gpt6cfg1);

  /*
   * Starting a continuous conversion.
   */
  gptStartContinuous(&GPTD6, 2U);
  
  pid_create(&pid, &input, &output, &target, 2.0, 5.0, 1.0, PID_ON_M, PID_DIRECT);
  pid_setSampleTime(&pid, 10);
  pid_setMode(&pid, PID_AUTOMATIC);
  
    /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
  
  adcStartConversion(&ADCD1, &adcgrpcfg1, samples, ADC_GRP1_BUF_DEPTH);


  /*
   * Normal main() thread activity.
   */
  while (true) {

    chThdSleepMilliseconds(250);
    palToggleLine(LINE_LED3_RED);
  }
  return 0;
}

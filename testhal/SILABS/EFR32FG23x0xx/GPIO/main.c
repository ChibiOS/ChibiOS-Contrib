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

#include "cmsis_os.h"
#include "hal.h"

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

static int gpio_callback_counter;

static void gpio_callback(void* arg) {

  int *cnt = arg;
  (void)cnt;

  *cnt = *cnt + 1;
}

static void test_clock_clkout2(void) {

  /* Clock output 2 works only on ports A or B. */

  /* FRSCO clock is on PA7: 20 MHz. */
  //palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_FSRCO));

  /* HFXO clock is on PA7: 39 MHz. */
  //palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_HFXO));

  /* HFRCODPLL clock is on PA7: 19 MHz. */
  palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_HFRCODPLL));

  /* HFRCOEM23 clock is on PA7: 19 MHz. */
  //palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_HFRCOEM23));

  /* LFXO clock is on PA7: 32768 Hz. */
  //palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_LFXO));

  /* LFRCO clock is on PA7: 32768 Hz. */
  //palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_LFRCO));

  /* ULFRCO clock is on PA7: 1000 Hz. */
  //palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_ULFRCO));  

  /* HCLK clock is present on PA7: 19 MHz. */
  //palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_HCLK));

  /* TODO: The clock should be measured by timer. */
}

static void test_clock_clkout1(void) {

  /* Clock output 1 works only on ports C or D. */


  /* FRSCO clock is on PA7: 20 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT1_FSRCO));

  /* HFXO clock is on PA7: 39 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT1_HFXO));

  /* HFRCODPLL clock is on PA7: 19 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT1_HFRCODPLL));

  /* HFRCOEM23 clock is on PA7: 19 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT1_HFRCOEM23));

  /* LFXO clock is on PA7: 32768 Hz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT1_LFXO));

  /* LFRCO clock is on PA7: 32768 Hz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT1_LFRCO));

  /* ULFRCO clock is on PA7: 1000 Hz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT1_ULFRCO));  

  /* HCLK clock is present on PA7: 19 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT1_HCLK));

  /* TODO: The clock should be measured by timer. */
}

static void test_clock_clkout0(void) {

  /* Clock output 0 works only on ports C or D. */

  /* FRSCO clock is on PA7: 20 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_FSRCO));

  /* HFXO clock is on PA7: 39 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_HFXO));

  /* HFRCODPLL clock is on PA7: 19 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_HFRCODPLL));

  /* HFRCOEM23 clock is on PA7: 19 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_HFRCOEM23));

  /* LFXO clock is on PA7: 32768 Hz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_LFXO));

  /* LFRCO clock is on PA7: 32768 Hz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_LFRCO));

  /* ULFRCO clock is on PA7: 1000 Hz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_ULFRCO));  

  /* HCLK clock is present on PA7: 19 MHz. */
  //palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_HCLK));

  /* TODO: The clock should be measured by timer. */
}

static void test_gpio(void) {

  uint32_t pin_states;
  (void)pin_states;

  gpio_callback_counter = 0;

    /* PB1 = BUTTON0. */
  palSetPadMode(GPIOB, 1, PAL_MODE_INPUT);
  palSetPadCallback(GPIOB, 1, gpio_callback, &gpio_callback_counter);
  palEnablePadEvent(GPIOB, 1, PAL_EVENT_MODE_BOTH_EDGES);

  /* PA5 = BUTTON1. */
  palSetPadMode(GPIOA, 5, PAL_MODE_OUTPUT_PUSHPULL);

  /* PB1 must be connected to PA5 via jumper wire. */
  palWritePad(GPIOA, 5, PAL_HIGH);
  pin_states = palReadPad(GPIOB, 1);
  osalDbgCheck(pin_states == PAL_HIGH);

  palWritePad(GPIOA, 5, PAL_LOW);
  pin_states = palReadPad(GPIOB, 1);
  osalDbgCheck(pin_states == PAL_LOW);

  palSetPad(GPIOA, 5);
  pin_states = palReadPad(GPIOB, 1);
  osalDbgCheck(pin_states == PAL_HIGH);

  palClearPad(GPIOA, 5);
  pin_states = palReadPad(GPIOB, 1);
  osalDbgCheck(pin_states == PAL_LOW);

  palTogglePad(GPIOA, 5);
  pin_states = palReadPad(GPIOB, 1);
  osalDbgCheck(pin_states == PAL_HIGH);

  palTogglePad(GPIOA, 5);
  pin_states = palReadPad(GPIOB, 1);
  osalDbgCheck(pin_states == PAL_LOW);

  palDisablePadEvent(GPIOB, 1);
  palSetPadMode(GPIOB, 1, PAL_MODE_RESET);
  palSetPadMode(GPIOA, 5, PAL_MODE_RESET);

  osalDbgAssert(gpio_callback_counter == 6, "Bug ON");
}

/*
 * Application entry point.
 */
int main(void) {

  int unused = 0; (void)unused;

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

  led_off();
  test_clock_clkout2();
  test_clock_clkout1();
  test_clock_clkout0();
  test_gpio();
  led_on();

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    osDelay(1000);
  }
}

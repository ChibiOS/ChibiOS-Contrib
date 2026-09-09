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
/* USART1 self-loopback test on the GENERIC_SK32_F077 board.                 */
/*===========================================================================*/

/*
 * Test resources used by this test:
 *
 *  - PB5 (USART1_TX) and PB6 (USART1_RX), both on alternate function 10.
 *    The two pads are shorted on the board so every transmitted byte is
 *    received back on the RX line (self-loopback).
 *  - PB14 / PB15: two board LEDs wired to push-pull outputs, the PAL
 *    abstraction drives them high (PAL_HIGH) to switch the LEDs on.
 *
 * Test procedure:
 *  - 256 bytes (0x00 .. 0xFF) are sent one at a time over SD1 (USART1,
 *    115200 8N1) and each one is waited for on the input queue with a
 *    timeout; the received byte must equal the transmitted one.
 *  - PB14 blinks at 1 Hz while the test is running and keeps blinking
 *    forever after a full pass.
 *  - On the first failure both LEDs are switched on solid and the system
 *    halts (the failed byte number is reported through the debug channel
 *    when a debugger is attached).
 */

/* Blinker thread, times are in milliseconds. */
static THD_WORKING_AREA(waBlinkThread, 128);
static THD_FUNCTION(BlinkThread, arg) {
  (void)arg;
  chRegSetThreadName("led-blink");
  while (true) {
    palSetPad(GPIOB, GPIOB_PIN14);
    chThdSleepMilliseconds(500);

    palClearPad(GPIOB, GPIOB_PIN14);
    chThdSleepMilliseconds(500);
  }
}

/* Marks a failed round trip and halts the system. */
static void fail(uint16_t round, uint8_t tx, uint8_t rx) {
  palSetPad(GPIOB, GPIOB_PIN14);
  palSetPad(GPIOB, GPIOB_PIN15);
  chSysHalt("USART1 loopback FAIL");
  (void)round;
  (void)tx;
  (void)rx;
}

/*
 * Application entry point.
 */
int main(void) {

  static const SerialConfig usart1_cfg = {
    .speed = 115200,
    .cr1   = 0,                    /* 8 data bits, no parity, no OVER8.      */
    .cr2   = USART_CR2_STOP1_BITS, /* One stop bit.                          */
    .cr3   = 0
  };
  unsigned round;

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
   * Creating the LED blinker thread.
   */
  chThdCreateStatic(waBlinkThread, sizeof(waBlinkThread), NORMALPRIO,
                    BlinkThread, NULL);

  /*
   * USART1 pads setup on alternate function 10:
   *  - PB5 = USART1_TX, push-pull output.
   *  - PB6 = USART1_RX, input line connected to the peripheral through the
   *    alternate function (floating, the line is driven by PB5 through the
   *    loopback wire).
   */
  palSetPadMode(GPIOB, 5U, PAL_MODE_ALTERNATE(10) |
                          PAL_SK32_OSPEED_MID);
  palSetPadMode(GPIOB, 6U, PAL_MODE_ALTERNATE(10) |
                          PAL_SK32_OSPEED_MID);

  /* Starting the serial driver (enables the USART1 clock and the NVIC
     vector, then programs BRR/CR1/CR2/CR3). */
  sdStart(&SD1, &usart1_cfg);

  /*
   * Running the loopback test.
   */
  for (round = 0; round < 256; round++) {
    uint8_t tx = (uint8_t)round;
    uint8_t rx = 0;

    /* Sending the byte, blocking with a timeout.*/
    if (sdWriteTimeout(&SD1, &tx, 1U, TIME_MS2I(100)) != 1U) {
      fail(round, tx, rx);
    }

    /* Waiting for the echoed byte, the RXNE interrupt pushes it into the
       input queue.  The timeout catches wiring/driver faults.*/
    if (sdReadTimeout(&SD1, &rx, 1U, TIME_MS2I(500)) != 1U) {
      fail(round, tx, rx);
    }

    /* The received byte must match the transmitted one.*/
    if (rx != tx) {
      fail(round, tx, rx);
    }
  }

  /* Full pass: signal it by switching PB15 on (PB14 keeps blinking).*/
  palSetPad(GPIOB, GPIOB_PIN15);

  /*
   * Normal main() thread activity.
   */
  while (true) {
    chThdSleepMilliseconds(1000);
  }
}

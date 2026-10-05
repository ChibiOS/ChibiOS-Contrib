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
/* SPI1 self-loopback test on the GENERIC_SK32_F077 board.                   */
/*===========================================================================*/

/*
 * Test resources used by this test:
 *
 *  - PA7 (SPI1_MOSI) and PA6 (SPI1_MISO), both on alternate function 12.
 *    The two pads are shorted on the board so the master receives back on
 *    MISO the very byte it shifts out on MOSI (self-loopback, the SCK clock
 *    is generated internally by the SPI1 master).
 *  - PB14 / PB15: two board LEDs wired to push-pull outputs, the PAL
 *    abstraction drives them high (PAL_HIGH) to switch the LEDs on.
 *
 * Test procedure:
 *  - 256 bytes (0x00 .. 0xFF) are exchanged over SPID1 (SPI1 master, CPOL=0
 *    CPHA=0, 8 bits, 72MHz/32 = 2.25MHz) in one synchronous
 *    @p spiExchange() and the received buffer must equal the transmitted
 *    one.
 *  - The test round is repeated forever; PB15 is toggled after every
 *    successful round (visible blinking) while PB14 provides a 1 Hz
 *    heartbeat.
 *  - On the first mismatch both LEDs are switched on solid and the system
 *    halts.
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

/*
 * Application entry point.
 */
int main(void) {

  static const SPIConfig spi1_cfg = {
    .end_cb = NULL,
    .ssport = GPIOA,              /* Dummy, no slave select used.            */
    .sspad  = 0U,
    .cr1    = SK32_SPI_BR_PCLK_DIV32,
    .cr2    = 0U
  };
  uint8_t txbuf[256];
  uint8_t rxbuf[256];
  bool    led = false;
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
   * Creating the LED blinker thread.
   */
  chThdCreateStatic(waBlinkThread, sizeof(waBlinkThread), NORMALPRIO,
                    BlinkThread, NULL);

  /*
   * SPI1 pads setup on alternate function 12:
   *  - PA7 = SPI1_MOSI (master output).
   *  - PA6 = SPI1_MISO (master input, connected to MOSI through the
   *    loopback wire).
   * The SCK pin is left unconfigured, the serial clock is generated
   * internally by the master and both data pads are driven/sampled
   * synchronously with it.
   */
  palSetPadMode(GPIOA, 7U, PAL_MODE_ALTERNATE(12) |
                          PAL_SK32_OSPEED_MID);
  palSetPadMode(GPIOA, 6U, PAL_MODE_ALTERNATE(12) |
                          PAL_SK32_OSPEED_MID);

  /* Filling the transmit buffer with the 0x00..0xFF pattern.*/
  for (i = 0U; i < sizeof(txbuf); i++) {
    txbuf[i] = (uint8_t)i;
  }

  /* Starting the SPI driver (enables the SPI1 clock and the NVIC vector,
     then programs CR1/CR2 in master mode with software slave management).*/
  spiStart(&SPID1, &spi1_cfg);

  /*
   * Running the loopback test forever.
   */
  while (true) {
    /* Synchronous full-duplex exchange, RXNE/TXE interrupt driven.*/
    spiExchange(&SPID1, sizeof(txbuf), txbuf, rxbuf);

    /* Verifying the received buffer.*/
    for (i = 0U; i < sizeof(txbuf); i++) {
      if (rxbuf[i] != txbuf[i]) {
        palSetPad(GPIOB, GPIOB_PIN14);
        palSetPad(GPIOB, GPIOB_PIN15);
        chSysHalt("SPI1 loopback FAIL");
      }
    }

    /* Signaling a successful round with a slow PB15 blink.*/
    if (led) {
      palClearPad(GPIOB, GPIOB_PIN15);
      led = false;
    }
    else {
      palSetPad(GPIOB, GPIOB_PIN15);
      led = true;
    }
    chThdSleepMilliseconds(250);
  }
}

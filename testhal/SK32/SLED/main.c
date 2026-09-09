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
#include "hal_sled_lld.h"

/*===========================================================================*/
/* SLED2 (PC0 / SLED1_CH0) 64xRGB chaser on the GENERIC_SK32_F077 board.     */
/*===========================================================================*/

/*
 * LED string: 64 addressable WS2812/SK6812 RGB LEDs driven by the SK32F077
 * SLED peripheral.  Only the PC0 pad is used:
 *
 *  - PC0 = SLED1_CH0 output pad (datasheet naming), served by the SLED2
 *    group registers (DR[1]/DMAEN2/RSTSTR2, DMA1 channel 2, request SLED_G2);
 *    alternate function 14.
 *
 *  - The data is written with 8-bit wide accesses (@p SLED_WIDTH_8BIT): every
 *    byte is replicated on the four channels of the group, but only CH0 is
 *    wired to the string on PC0 so the byte stream drives the strip.
 *
 *  - Wire order is GRB and the SLED block serializes each byte verbatim (no
 *    bit packing): 64 LEDs * 3 bytes = 192 bytes per frame.
 *
 * A "running water" (chaser) effect is rendered: a bright comet with a short
 * fading tail sweeps along the 64 LEDs and wraps around.
 *
 * PB14 / PB15: PB15 toggles after every acknowledged frame; PB14 is driven
 * solid HIGH when a frame times out (the test never halts).
 */

/*===========================================================================*/
/* Application entry point.                                                   */
/*===========================================================================*/
int main(void) {

  /* Vendor RGBKeyboardSTK time codes: T0H=4, T1H=15, TRST=80 cycles, clock
     /4, baud /32.*/
  static const SLEDConfig sled_cfg = {
    .t0h_cycles      = 4U,
    .t1h_cycles      = 15U,
    .trst_cycles     = 80U,
    .prescaler       = 3U,
    .baud_prescaler  = 31U,
    .idle_polarity   = SLED_POLARITY_LOW,
    .reset_polarity  = SLED_POLARITY_LOW
  };

  /* Number of RGB LEDs and its byte frame size (3 bytes GRB each).*/
  enum {
    LED_COUNT     = 64,
    FRAME_BYTES   = LED_COUNT * 3
  };

  static uint8_t frame[FRAME_BYTES];
  bool    led_success = false;
  uint32_t head = 0U;
  unsigned led;

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
   * Output pad setup on alternate function 14: PC0 = SLED1_CH0, served by
   * the SLED2 group registers (DR[1]).  The SLED low level driver does not
   * configure the pads, so it is routed here before the subsystem is
   * started.
   */
  palSetPadMode(GPIOC, 0U, PAL_MODE_ALTERNATE(14) | PAL_SK32_OSPEED_HIGHEST);

  /*
   * Starting the SLED subsystem with the SLED2 group enabled (SK32_SLED_USE_
   * SLED2=TRUE is set in the Makefile).
   */
  sled_lld_init();
  sled_lld_start(&sled_cfg);

  /*
   * Frame loop: render one chaser frame every 30 ms and stream it out.
   * PB15 toggles on every acknowledged frame, PB14 stays solid HIGH after a
   * timeout.
   */
  while (true) {

    /* Render the chaser: a bright white head with a red/blue fading tail. */
    for (led = 0U; led < LED_COUNT; led++) {
      uint8_t *px = &frame[led * 3U];
      int32_t d = (int32_t)((head + LED_COUNT - (uint32_t)led) % LED_COUNT);
      uint8_t  a;

      if (d == 0) {
        /* Comet head: bright white. */
        px[0] = 0xFFU;   /* G */
        px[1] = 0xFFU;   /* R */
        px[2] = 0xFFU;   /* B */
      }
      else {
        /* Fading tail, intensity falls off with distance from the head. */
        a = (d >= 12U) ? 0U : (uint8_t)(32U - ((uint32_t)d * 32U) / 12U);
        px[0] = (uint8_t)(a * 8U / 32U);        /* G (small)  */
        px[1] = (uint8_t)(a * 24U / 32U);       /* R (medium) */
        px[2] = (uint8_t)(a * 16U / 32U);       /* B (large)  */
      }
    }

    /* 8-bit write on the SLED2 group: every byte goes out on CH0 = PC0. */
    if (sled_lld_send_bytes(SLED2, frame, sizeof(frame)) == MSG_OK) {
      led_success = !led_success;
      (led_success) ? palSetPad(GPIOB, GPIOB_PIN15) : palClearPad(GPIOB, GPIOB_PIN15);
    }
    else {
      /* Frame not acknowledged: report it on PB14 and keep going. */
      palSetPad(GPIOB, GPIOB_PIN14);
    }

    /* Advance the chaser head (wraps around).*/
    head = (head + 1U) % LED_COUNT;

    chThdSleepMilliseconds(30);
  }
}
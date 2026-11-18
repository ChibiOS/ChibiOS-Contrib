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
#include "hal_kbcu_lld.h"

/*===========================================================================*/
/* KBCU independent-mode bring-up test on the GENERIC_SK32_F077 board.       */
/*===========================================================================*/

/*
 * Hardware description.
 *
 * The KBCU peripheral is driven in independent scan mode: the RGB (LED)
 * scanning and the KEY scanning run at the same level and the key statuses
 * are read back on dedicated KEY inputs through the shared KSR registers.
 * The RGB frame is streamed into the LED registers by DMA1 channel 4
 * (memory to peripheral, targeting KBCU->DMAR).
 *
 *   Columns (COL) are the scan outputs, Keys (KEY) are the row inputs:
 *     COL0 = PC7 (alternate function 7),  COL1 = PC8 (AF7),
 *     COL4 = PC4 (AF8),                    COL5 = PC5 (AF8)  (not used here,
 *                                                             kept for reference)
 *     KEY0 = PD3 (AF9),                    KEY1 = PB1 (AF8),
 *     KEY2 = PB2 (AF8)
 *
 *   Status LEDs on the board:
 *     PB14 stays SOLID HIGH if the KBCU start sequence fails to complete,
 *     PB15 toggles once per detected key press (jumper test described below).
 *
 * How to exercise it:
 *   - RGB: connect a scope to the COL pins (e.g. PC7) and observe the scan
 *     burst; wire RGB LEDs on the columns to see the streamed frame colour.
 *   - Key: short COL0 (PC7) to KEY0 (PD3) with a jumper to simulate a pressed
 *     key at (column 0, row 0).  The KBCU key interrupt fires, the driver
 *     snapshot callback runs and PB15 toggles.
 */

/*===========================================================================*/
/* Application entry point.                                                   */
/*===========================================================================*/

/**
 * @brief   Key status callback, invoked from the KBCU ISR on a key change.
 * @note    Only the first KSR word is inspected and asserted: the test wires
 *          a single key at (column 0, row 0).
 */
static void key_isr(const uint32_t *ksr) {
  (void)ksr;
}

int main(void) {

  /* Independent scan mode configuration.  The field values mirror the vendor
     RGBKeyboardSTK demo: key/columns effective level LOW, clock divided by
     "1" (PSC = 1), no dead time, no flicker, no column mask.  columns_cycle_
     value (CCR) drives the LED brightness duty, columns_cycle_count (ARR) the
     scan frequency.*/
  static const KBCUConfig kbcu_cfg = {
    .columns_num            = 16U,                 /* 16 columns            */
    .columns_cycle_value    = 0x3FU,               /* CCR 0x00..0x7F duty   */
    .columns_cycle_count    = 0xFFU,               /* ARR 0x01..0xFF        */
    .clock_division         = 1U,                  /* PSC                  */
    .key_effective_level    = KBCU_KEY_LEVEL_LOW,
    .columns_effective_level = KBCU_COLUMN_LEVEL_LOW,
    .dead_time              = KBCU_DEADTIME_0,
    .flicker_length         = 0U,
    .column_mask            = 0U
  };

  /* RGB frame: 8 pixels x 3 bytes (R,G,B), pushed via DMA1 channel 4.  The
     burst length (DCR.DBL) must stay within 0x00..0x1F so it is capped at
     the frame size here (24 <= 31).*/
  static uint8_t frame[8U * 3U];
  enum {
    FRAME_BYTES = sizeof(frame),
    BURST_LEN   = FRAME_BYTES
  };

  volatile uint32_t key_events = 0U;
  uint8_t  phase = 0U;
  unsigned i;

  halInit();
  chSysInit();

  /* PB14/PB15 status LEDs as push-pull outputs, initially off.*/
  palSetPadMode(GPIOB, 14U, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOB, 15U, PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB, 14U);
  palClearPad(GPIOB, 15U);

  /*
   * Column/KEY pads in alternate function (the KBCU network is wired by the
   * hardware scan engine, the driver does not touch these pins).
   */
  palSetPadMode(GPIOB, 1U, PAL_MODE_ALTERNATE(8) | PAL_SK32_OSPEED_HIGHEST); /* KEY1 */
  palSetPadMode(GPIOB, 2U, PAL_MODE_ALTERNATE(8) | PAL_SK32_OSPEED_HIGHEST); /* KEY2 */
  palSetPadMode(GPIOD, 3U, PAL_MODE_ALTERNATE(9) | PAL_SK32_OSPEED_HIGHEST); /* KEY0 */
  palSetPadMode(GPIOC, 7U, PAL_MODE_ALTERNATE(7) | PAL_SK32_OSPEED_HIGHEST); /* COL0 */
  palSetPadMode(GPIOC, 8U, PAL_MODE_ALTERNATE(7) | PAL_SK32_OSPEED_HIGHEST); /* COL1 */
  palSetPadMode(GPIOC, 4U, PAL_MODE_ALTERNATE(8) | PAL_SK32_OSPEED_HIGHEST); /* COL4 */
  palSetPadMode(GPIOC, 5U, PAL_MODE_ALTERNATE(8) | PAL_SK32_OSPEED_HIGHEST); /* COL5 */

  /* Starting the KBCU peripheral in independent scan mode.*/
  kbcu_lld_init();
  kbcu_lld_start(&kbcu_cfg);

  /* Key interrupt only (no frame/column interrupt), frame count 1.  Install
     the snapshot callback.*/
  kbcu_lld_itconfig(KBCU_IT_KEY, 1U);
  kbcu_lld_set_callback(key_isr);

  /*
   * RGB/DMA loop: render a running rainbow into the frame buffer and push it
   * to the KBCU LED registers through DMA1 channel 4 every 30 ms.
   *   - PB14 toggles each iteration: heartbeat proving the loop is alive.
   *   - PB15 reflects the KBCU key activity: when the tester shorts COL0 (PC7)
   *     to KEY0 (PD3) the key interrupt fires and PB15 latches HIGH.
   */
  while (true) {
    /* Heartbeat: the loop is responsive.*/
    palTogglePad(GPIOB, 14U);

    /* Render a rainbow gradient, rotated by the phase counter.*/
    for (i = 0U; i < 8U; i++) {
      uint8_t *px = &frame[i * 3U];
      px[0] = (uint8_t)((i * 32U + phase) & 0xFFU);       /* R */
      px[1] = (uint8_t)((i * 32U + phase * 2U) & 0xFFU);  /* G */
      px[2] = (uint8_t)((i * 32U + phase * 3U) & 0xFFU);  /* B */
    }

    /* Push the frame to the LED registers by DMA (single-shot burst).*/
    kbcu_lld_led_dma_start(KBCU_DMBASE_LEDR0, BURST_LEN, frame, FRAME_BYTES);

    /* If the KBCU reported a key status change at least once, the key input
       (KEY0 = PD3) has been toggled; latch PB15.  The flag is a high-to-low
       interrupt latch so it is cleared here after sampling.*/
    if (kbcu_lld_get_key_flag() != 0U) {
      key_events++;
      palSetPad(GPIOB, 15U);
      KBCU->SR = (KBCU->SR & ~KBCU_SR_KEYF);
    }

    /* Advance the phase and wait for the next frame slot.*/
    phase = (uint8_t)(phase + 1U);

    chThdSleepMilliseconds(30);
  }
}
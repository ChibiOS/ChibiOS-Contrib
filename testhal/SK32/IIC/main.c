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
/* I2C1 EEPROM test on the GENERIC_SK32_F077 board.                          */
/*===========================================================================*/

/*
 * Test resources used by this test:
 *
 *  - PB6 (I2C1_SCL) and PB7 (I2C1_SDA), both on alternate function 13 in
 *    open drain mode.  A 24Cxx/M24C64 style I2C EEPROM (hardware address
 *    0xA0, A0/A1/A2 strapped low) with 4.7k pull-up resistors to VCC must
 *    be wired to the two pads, the same connection used by the vendor
 *    I2C_EEPROM example.
 *  - PB14 / PB15: two board LEDs wired to push-pull outputs, the PAL
 *    abstraction drives them high (PAL_HIGH) to switch the LEDs on.
 *
 * Test procedure:
 *  - The I2C1 master is started at 100kHz standard mode (the SK32 I2C
 *    input clock is analyzed as the 8MHz HSI by the low level driver).
 *  - Every round a byte (a rotating pattern) is written to the EEPROM
 *    address 0x0000 with a byte write, the internal write cycle is awaited
 *    and the byte is read back with a combined random read
 *    (write the two address bytes, repeated START, read one byte).
 *  - PB15 is toggled after every round whose readback matches (visible
 *    blinking) while PB14 provides a 1 Hz heartbeat.
 *  - On the first mismatch or transfer error (e.g. no EEPROM wired -> ACK
 *    failure) both LEDs are switched on solid and the system halts.
 */

/* EEPROM slave address, 7 bits (0xA0 with the R/W bit => 0x50). */
#define EEPROM_ADDR                     0x50U

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
  static const I2CConfig i2c1_cfg = {
    .op_mode     = OPMODE_I2C,
    .clock_speed = 100000U,
    .duty_cycle  = STD_DUTY_CYCLE
  };
  uint8_t txbuf[3];                 /* Address high, address low, data byte. */
  uint8_t rxbuf[1];
  uint8_t pattern = 0x00U;
  bool    led     = false;
  msg_t   msg;

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
   * I2C1 pads setup on alternate function 13 (open drain, floating, the
   * pull-ups are external 4.7k resistors on the EEPROM module):
   *  - PB6 = I2C1_SCL.
   *  - PB7 = I2C1_SDA.
   */
  palSetPadMode(GPIOB, 6U, PAL_SK32_MODE_ALTERNATE |
                           PAL_SK32_ALTERNATE(13) |
                           PAL_SK32_OTYPE_OPENDRAIN |
                           PAL_SK32_OSPEED_MID |
                           PAL_SK32_PUPDR_FLOATING);
  palSetPadMode(GPIOB, 7U, PAL_SK32_MODE_ALTERNATE |
                           PAL_SK32_ALTERNATE(13) |
                           PAL_SK32_OTYPE_OPENDRAIN |
                           PAL_SK32_OSPEED_MID |
                           PAL_SK32_PUPDR_FLOATING);

  /* Starting the I2C driver (enables the I2C1 clock and the NVIC vector,
     then programs CR2/CCR/CR1 in master mode).*/
  i2cStart(&I2CD1, &i2c1_cfg);

  /*
   * Running the EEPROM write/read test forever.
   */
  while (true) {
    /* Byte write: [addr high][addr low][data] at address 0x0000.*/
    txbuf[0] = 0x00U;
    txbuf[1] = 0x00U;
    txbuf[2] = pattern;
    msg = i2cMasterTransmitTimeout(&I2CD1, EEPROM_ADDR, txbuf,
                                   sizeof(txbuf), NULL, 0U,
                                   TIME_MS2I(50));
    if (msg != MSG_OK) {
      palSetPad(GPIOB, GPIOB_PIN14);
      palSetPad(GPIOB, GPIOB_PIN15);
      chSysHalt("I2C1 EEPROM write FAIL");
    }

    /* Waiting for the internal write cycle (tWR <= 5ms typical).*/
    chThdSleepMilliseconds(10);

    /* Random read: write the two address bytes then read one byte back.*/
    msg = i2cMasterTransmitTimeout(&I2CD1, EEPROM_ADDR, txbuf, 2U,
                                   rxbuf, sizeof(rxbuf),
                                   TIME_MS2I(50));
    if (msg != MSG_OK) {
      palSetPad(GPIOB, GPIOB_PIN14);
      palSetPad(GPIOB, GPIOB_PIN15);
      chSysHalt("I2C1 EEPROM read FAIL");
    }

    /* Verifying the readback byte.*/
    if (rxbuf[0] != pattern) {
      palSetPad(GPIOB, GPIOB_PIN14);
      palSetPad(GPIOB, GPIOB_PIN15);
      chSysHalt("I2C1 EEPROM data mismatch");
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

    pattern++;
    chThdSleepMilliseconds(100);
  }
}

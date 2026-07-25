/*
    Copyright (C) 2026 Belonit

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

/**
 * @file    lcd1602.c
 * @brief   HD44780 LCD1602 over PCF8574 test driver.
 *
 * @addtogroup LCD1602
 * @{
 */

#include "lcd1602.h"

#define LCD1602_TIMEOUT       TIME_MS2I(10)
#define LCD1602_RS            0x01U
#define LCD1602_ENABLE        0x04U
#define LCD1602_BACKLIGHT     0x08U
#define LCD1602_LINE_LENGTH   16U

static msg_t lcd1602_transmit(LCD1602Driver *driver, const uint8_t *buffer,
                              size_t size) {
  return i2cMasterTransmitTimeout(driver->i2cd, driver->i2caddr, buffer, size,
                                  NULL, 0U, LCD1602_TIMEOUT);
}

static bool lcd1602_write_nibble(LCD1602Driver *driver, uint8_t nibble,
                                 uint8_t control) {
  uint8_t value = (uint8_t)((nibble << 4U) | control | LCD1602_BACKLIGHT);
  const uint8_t pulse[] = {
      (uint8_t)(value | LCD1602_ENABLE),
      value,
  };

  return lcd1602_transmit(driver, pulse, sizeof(pulse)) == MSG_OK;
}

static bool lcd1602_write_byte(LCD1602Driver *driver, uint8_t value,
                               uint8_t control) {
  return lcd1602_write_nibble(driver, value >> 4U, control)
         && lcd1602_write_nibble(driver, value & 0x0FU, control);
}

static bool lcd1602_command(LCD1602Driver *driver, uint8_t command) {
  bool ok = lcd1602_write_byte(driver, command, 0U);

  if ((command == 0x01U) || (command == 0x02U)) {
    osalThreadSleepMilliseconds(2);
  }
  return ok;
}

static bool lcd1602_write_row(LCD1602Driver *driver, uint8_t address,
                              const char *text) {
  if (!lcd1602_command(driver, (uint8_t)(0x80U | address))) {
    return false;
  }

  for (size_t i = 0U; i < LCD1602_LINE_LENGTH; i++) {
    uint8_t value = ' ';

    if (*text != '\0') {
      value = (uint8_t)*text++;
    }
    if (!lcd1602_write_byte(driver, value, LCD1602_RS)) {
      return false;
    }
  }
  return true;
}

static bool lcd1602_probe(LCD1602Driver *driver) {
  static const i2caddr_t addresses[] = {0x27U, 0x3FU};
  const uint8_t idle = LCD1602_BACKLIGHT;

  for (size_t i = 0U; i < sizeof(addresses) / sizeof(addresses[0]); i++) {
    msg_t msg;

    driver->i2caddr = addresses[i];
    msg = lcd1602_transmit(driver, &idle, sizeof(idle));
    if (msg == MSG_OK) {
      return true;
    }
    if ((msg == MSG_TIMEOUT)
        && (i + 1U < sizeof(addresses) / sizeof(addresses[0]))) {
      i2cStart(driver->i2cd, driver->i2ccfg);
    }
  }
  return false;
}

/**
 * @brief   Initializes a standard PCF8574-backed LCD1602.
 *
 * @param[in,out] driver pointer to an @p LCD1602Driver object
 * @return              Operation status.
 * @retval true         Display initialized successfully.
 * @retval false        No supported backpack responded or a transfer failed.
 *
 * @notapi
 */
bool lcd1602_init(LCD1602Driver *driver) {
  bool ok;

  i2cStart(driver->i2cd, driver->i2ccfg);
  ok = lcd1602_probe(driver);
  if (ok) {
    osalThreadSleepMilliseconds(50);
    ok = lcd1602_write_nibble(driver, 0x03U, 0U);
    osalThreadSleepMilliseconds(5);
    ok = ok && lcd1602_write_nibble(driver, 0x03U, 0U);
    osalThreadSleepMilliseconds(1);
    ok = ok && lcd1602_write_nibble(driver, 0x03U, 0U)
         && lcd1602_write_nibble(driver, 0x02U, 0U)
         && lcd1602_command(driver, 0x28U)
         && lcd1602_command(driver, 0x08U)
         && lcd1602_command(driver, 0x01U)
         && lcd1602_command(driver, 0x06U)
         && lcd1602_command(driver, 0x0CU);
  }
  i2cStop(driver->i2cd);
  return ok;
}

/**
 * @brief   Writes two padded or truncated 16-character rows.
 *
 * @param[in,out] driver pointer to an @p LCD1602Driver object
 * @param[in]     row0   first row text
 * @param[in]     row1   second row text
 * @return              Operation status.
 * @retval true         Both rows were transferred successfully.
 * @retval false        An I2C transfer failed.
 *
 * @notapi
 */
bool lcd1602_write_lines(LCD1602Driver *driver, const char *row0,
                         const char *row1) {
  bool ok;

  i2cStart(driver->i2cd, driver->i2ccfg);
  ok = lcd1602_write_row(driver, 0x00U, row0)
       && lcd1602_write_row(driver, 0x40U, row1);
  i2cStop(driver->i2cd);
  return ok;
}

/** @}*/

/*
    Copyright (C) 2020 Ein Terakawa
    Modifications copyright (C) 2026 Belonit

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
 * @file    ssd1306.c
 * @brief   SSD1306 I2C test driver.
 *
 * @addtogroup SSD1306
 * @{
 */

#include "ssd1306.h"
#include <string.h>

#define SSD1306_COMMAND_TIMEOUT TIME_MS2I(10)
#define SSD1306_FRAME_TIMEOUT   TIME_MS2I(100)

static msg_t ssd1306_transmit(SSD1306_DRIVER *driver, const uint8_t *buffer,
                               size_t size, systime_t timeout) {
  return i2cMasterTransmitTimeout(driver->i2cd, driver->i2caddr, buffer, size,
                                  NULL, 0U, timeout);
}

/* Keep command/data call sites shaped like the NUC123 reference driver.*/
#define send_cmd(driver, buffer)                                               \
  ssd1306_transmit((driver), (buffer), sizeof(buffer), SSD1306_COMMAND_TIMEOUT)
#define send_data(driver, buffer, size)                                        \
  ssd1306_transmit((driver), (buffer), (size), SSD1306_FRAME_TIMEOUT)

static void ssd1306_bus_start(SSD1306_DRIVER *driver) {
  i2cStart(driver->i2cd, driver->i2ccfg);
}

static void ssd1306_bus_stop(SSD1306_DRIVER *driver) {
  i2cStop(driver->i2cd);
}

/**
 * @brief   Initializes an SSD1306 display and clears its framebuffer.
 *
 * @param[in,out] driver pointer to an @p SSD1306_DRIVER object
 * @return              Operation status.
 * @retval true         Display initialized successfully.
 * @retval false        An I2C transfer failed.
 *
 * @notapi
 */
bool ssd1306_init(SSD1306_DRIVER *driver) {
  const uint8_t setup[] = {
      SSD1306_CONTROL_COMMAND,
      SSD1306_DISPLAY_OFF,
      SSD1306_SET_CLOCK,
      0x80U,
      SSD1306_SET_MULTIPLEX,
      driver->height - 1U,
      SSD1306_SET_OFFSET,
      0x00U,
      SSD1306_DISPLAY_START_LINE,
      SSD1306_CHARGE_PUMP,
      0x14U,
      SSD1306_SET_ADDRESS_MODE,
      0x00U,
      driver->rotate180 ? (SSD1306_SEGMENT_REMAP | 0x01U)
                        : SSD1306_SEGMENT_REMAP,
      driver->rotate180 ? SSD1306_COM_SCAN_REVERSE : SSD1306_COM_SCAN_NORMAL,
      SSD1306_SET_COM_PINS,
      driver->height == 32U ? 0x02U : 0x12U,
      SSD1306_SET_CONTRAST,
      0x7FU,
      SSD1306_SET_PRECHARGE,
      0xC4U,
      SSD1306_SET_VCOMH,
      0x20U,
      SSD1306_DISPLAY_ALL_ON_RESUME,
      SSD1306_NORMAL_DISPLAY,
      SSD1306_DEACTIVATE_SCROLL,
  };

  msg_t msg;

  /* Upload a deterministic frame before enabling the panel.*/
  ssd1306_bus_start(driver);
  msg = send_cmd(driver, setup);
  ssd1306_bus_stop(driver);
  if (msg == MSG_OK) {
    const size_t frame_size = driver->width * driver->height / 8U;

    memset(SSD1306_GET_FRAMEBUFFER(driver), 0, frame_size);
    if (!ssd1306Update(driver)) {
      return false;
    }

    static const uint8_t display_on[] = {
        SSD1306_CONTROL_COMMAND,
        SSD1306_DISPLAY_ON,
    };
    ssd1306_bus_start(driver);
    msg = send_cmd(driver, display_on);
    ssd1306_bus_stop(driver);
  }
  return msg == MSG_OK;
}

/**
 * @brief   Transfers the current framebuffer to an SSD1306 display.
 *
 * @param[in,out] driver pointer to an @p SSD1306_DRIVER object
 * @return              Operation status.
 * @retval true         Framebuffer transferred successfully.
 * @retval false        An I2C transfer failed.
 *
 * @notapi
 */
bool ssd1306Update(SSD1306_DRIVER *driver) {
  const uint8_t window[] = {
      SSD1306_CONTROL_COMMAND,  SSD1306_SET_COLUMN_ADDRESS, 0x00U,
      driver->width - 1U,       SSD1306_SET_PAGE_ADDRESS,   0x00U,
      driver->height / 8U - 1U,
  };
  const uint32_t frame_size = driver->width * driver->height / 8U;
  msg_t msg;

  ssd1306_bus_start(driver);
  msg = send_cmd(driver, window);
  if (msg != MSG_OK) {
    ssd1306_bus_stop(driver);
    return false;
  }

  driver->buf[0] = SSD1306_CONTROL_DATA;

  msg = send_data(driver, driver->buf, 1U + frame_size);
  ssd1306_bus_stop(driver);
  return msg == MSG_OK;
}

/** @} */

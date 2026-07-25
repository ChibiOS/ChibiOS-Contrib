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
 * @file    ssd1306.h
 * @brief   SSD1306 I2C test driver header.
 *
 * @addtogroup SSD1306
 * @{
 */

#ifndef SSD1306_H
#define SSD1306_H

#include "hal.h"

/**
 * @brief   SSD1306 command and control-byte values used by the test driver.
 */
enum ssd1306_cmds
{
  /** @brief Command stream control byte.*/
  SSD1306_CONTROL_COMMAND = 0x00,
  /** @brief Data stream control byte.*/
  SSD1306_CONTROL_DATA = 0x40,
  /** @brief Set contrast command.*/
  SSD1306_SET_CONTRAST = 0x81,
  /** @brief Disable display command.*/
  SSD1306_DISPLAY_OFF = 0xAE,
  /** @brief Enable display command.*/
  SSD1306_DISPLAY_ON = 0xAF,
  /** @brief Charge pump configuration command.*/
  SSD1306_CHARGE_PUMP = 0x8D,
  /** @brief Display clock configuration command.*/
  SSD1306_SET_CLOCK = 0xD5,
  /** @brief Pre-charge period configuration command.*/
  SSD1306_SET_PRECHARGE = 0xD9,
  /** @brief VCOMH level configuration command.*/
  SSD1306_SET_VCOMH = 0xDB,
  /** @brief Memory addressing mode command.*/
  SSD1306_SET_ADDRESS_MODE = 0x20,
  /** @brief Column address window command.*/
  SSD1306_SET_COLUMN_ADDRESS = 0x21,
  /** @brief Page address window command.*/
  SSD1306_SET_PAGE_ADDRESS = 0x22,
  /** @brief Display start line command base.*/
  SSD1306_DISPLAY_START_LINE = 0x40,
  /** @brief Segment remap command base.*/
  SSD1306_SEGMENT_REMAP = 0xA0,
  /** @brief Normal COM scan direction command.*/
  SSD1306_COM_SCAN_NORMAL = 0xC0,
  /** @brief Reversed COM scan direction command.*/
  SSD1306_COM_SCAN_REVERSE = 0xC8,
  /** @brief Multiplex ratio command.*/
  SSD1306_SET_MULTIPLEX = 0xA8,
  /** @brief Display offset command.*/
  SSD1306_SET_OFFSET = 0xD3,
  /** @brief COM pin configuration command.*/
  SSD1306_SET_COM_PINS = 0xDA,
  /** @brief Resume displaying GDDRAM contents command.*/
  SSD1306_DISPLAY_ALL_ON_RESUME = 0xA4,
  /** @brief Normal, non-inverted display command.*/
  SSD1306_NORMAL_DISPLAY = 0xA6,
  /** @brief Disable scrolling command.*/
  SSD1306_DEACTIVATE_SCROLL = 0x2E,
};

/**
 * @brief   SSD1306 test driver configuration and state.
 */
typedef struct
{
  /** @brief I2C driver used by the display.*/
  I2CDriver *i2cd;
  /** @brief I2C bus configuration.*/
  const I2CConfig *i2ccfg;
  /** @brief Seven-bit I2C slave address.*/
  i2caddr_t i2caddr;
  /** @brief Display width in pixels.*/
  uint8_t width;
  /** @brief Display height in pixels.*/
  uint8_t height;
  /** @brief Enables 180-degree display rotation.*/
  bool rotate180;
  /** @brief Transfer buffer containing a control byte and the framebuffer.*/
  uint8_t *buf;
} SSD1306_DRIVER;

/**
 * @brief   Declares and initializes an SSD1306 test driver object.
 *
 * @param[in] name              driver object name
 * @param[in] i2cdp             pointer to the I2C driver
 * @param[in] addr              seven-bit I2C slave address
 * @param[in] display_width     display width in pixels
 * @param[in] display_height    display height in pixels
 * @param[in] rotate            enables 180-degree rotation
 */
#define DEFINE_SSD1306_DRIVER(name, i2cdp, addr, display_width,            \
                              display_height, rotate)                      \
  _Static_assert((display_width) == 128U,                                  \
                 "SSD1306 width must be 128");                             \
  _Static_assert((display_height) == 32U || (display_height) == 64U,       \
                 "SSD1306 height must be 32 or 64");                       \
  static uint8_t name##_buf[1U + (display_width) * (display_height) / 8U]; \
  static SSD1306_DRIVER name = {                                           \
      .i2cd = (i2cdp),                                                     \
      .i2caddr = (addr),                                                   \
      .width = (display_width),                                            \
      .height = (display_height),                                          \
      .rotate180 = (rotate),                                               \
      .buf = name##_buf,                                                   \
  }

/**
 * @brief   Returns the framebuffer associated with an SSD1306 driver.
 *
 * @param[in] ssd1306   pointer to an @p SSD1306_DRIVER object
 * @return              Pointer to the first framebuffer byte.
 */
#define SSD1306_GET_FRAMEBUFFER(ssd1306) (&((ssd1306)->buf[1]))

bool ssd1306_init(SSD1306_DRIVER *driver);
bool ssd1306Update(SSD1306_DRIVER *driver);

#endif /* SSD1306_H */

/** @}*/

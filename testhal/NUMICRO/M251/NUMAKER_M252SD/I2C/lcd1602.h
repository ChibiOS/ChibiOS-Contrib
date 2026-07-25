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
 * @file    lcd1602.h
 * @brief   HD44780 LCD1602 over PCF8574 test driver header.
 *
 * @addtogroup LCD1602
 * @{
 */

#ifndef LCD1602_H
#define LCD1602_H

#include "hal.h"

/**
 * @brief   LCD1602 test driver configuration and state.
 */
typedef struct {
  /** @brief I2C driver used by the PCF8574 backpack.*/
  I2CDriver *i2cd;
  /** @brief I2C bus configuration.*/
  const I2CConfig *i2ccfg;
  /** @brief Detected seven-bit PCF8574 address.*/
  i2caddr_t i2caddr;
} LCD1602Driver;

/**
 * @brief   Initializes a standard PCF8574-backed LCD1602.
 * @details Addresses 0x27 and 0x3F are probed in that order.
 *
 * @param[in,out] driver pointer to an @p LCD1602Driver object
 * @return              Operation status.
 * @retval true         Display initialized successfully.
 * @retval false        No supported backpack responded or a transfer failed.
 *
 * @notapi
 */
bool lcd1602_init(LCD1602Driver *driver);

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
                         const char *row1);

#endif /* LCD1602_H */

/** @}*/

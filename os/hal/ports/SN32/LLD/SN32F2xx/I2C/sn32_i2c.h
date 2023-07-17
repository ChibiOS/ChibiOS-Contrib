/*
    Copyright (C) 2023 1Conan
    Copyright (C) 2023 Dimitris Mantzouranis

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

#ifndef SN32_I2C_H
#define SN32_I2C_H

typedef struct {
  union {
    uint32_t CTRL;

    struct {
      uint32_t : 1;
      uint32_t NACK : 1;
      uint32_t ACK : 1;
      uint32_t : 1;
      uint32_t STO : 1;
      uint32_t STA : 1;
      uint32_t : 1;
      uint32_t MODE : 1;
      uint32_t I2CEN : 1;
      uint32_t : 23;
    } CTRL_b;
  };

  union {
    uint32_t STAT;

    struct {
      uint32_t RX_DN : 1;
      uint32_t ACK_STAT : 1;
      uint32_t NACK_STAT : 1;
      uint32_t STOP_DN : 1;
      uint32_t START_DN : 1;
      uint32_t MST : 1;
      uint32_t SLV_RX_HIT : 1;
      uint32_t SLV_TX_HIT : 1;
      uint32_t LOST_ARB : 1;
      uint32_t TIMEOUT : 1;
      uint32_t : 5;
      uint32_t I2CIF : 1;
      uint32_t : 16;
    } STAT_b;
  };

  uint32_t TXDATA;
  uint32_t RXDATA;

  union {
    uint32_t SLVADRR0;

    struct {
      uint32_t ADDR : 10;
      uint32_t : 20;
      uint32_t GCEN : 1;
      uint32_t ADD_MODE : 1;

    } SLVADDR0_b;
  };

  uint32_t SLVADDR1;
  uint32_t SLVADDR2;
  uint32_t SLVADDR3;
  uint32_t SCLHT;
  uint32_t SCLLT;
  uint32_t SCLCT;
  uint32_t TOCTRL;
} sn32_i2c_t;

#endif /* SN32_I2C_H */

/** @} */
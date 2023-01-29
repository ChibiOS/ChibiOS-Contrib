/*
    ChibiOS - Copyright (C) 2023 1Conan

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

#ifndef SN32_SPI_H
#define SN32_SPI_H

typedef struct {
  union {
    uint32_t CTRL0;
    struct {
      uint32_t SPIEN : 1;
      uint32_t LOOPBACK : 1;
      uint32_t SDODIS : 1;
      uint32_t MS : 1;
      uint32_t FORMAT : 1;
      uint32_t : 1;
      uint32_t FRESET : 2;
      uint32_t DL : 4;
      uint32_t TXFIFOTH : 3;
      uint32_t RXFIFOTH : 3;
      uint32_t SELDIS : 1;
      uint32_t : 13;
    } CTRL0_b;
  };

  uint32_t CTRL1;
  uint32_t CLKDIV;

  union {
    uint32_t STAT;

    struct {
      uint32_t TX_EMPTY : 1;
      uint32_t TX_FULL : 1;
      uint32_t RX_EMPTY : 1;
      uint32_t RX_FULL : 1;
      uint32_t BUSY : 1;
      uint32_t TXFIFOTHF : 1;
      uint32_t RXFIFOTHF : 1;
      uint32_t : 25;
    } STAT_b;
  };

  union {
    uint32_t IE;

    struct {
      uint32_t RXOVFIE : 1;
      uint32_t RXTOIE : 1;
      uint32_t RXFIFOTHIE : 1;
      uint32_t TXFIFOTHIE : 1;
      uint32_t : 28;
    } IE_b;
  };

  union {
    uint32_t RIS;

    struct {
      uint32_t RXOVFIF : 1;
      uint32_t RXTOIF : 1;
      uint32_t RXFIFOTHIF : 1;
      uint32_t TXFIFOTHIF : 1;
      uint32_t : 28;
    } RIS_b;
  };

  union {
    uint32_t IC;

    struct {
      uint32_t RXOVFIC : 1;
      uint32_t RXTOIC : 1;
      uint32_t RXFIFOTHIC : 1;
      uint32_t TXFIFOTHIC : 1;
      uint32_t : 28;
    } IC_b;
  };

  uint32_t DATA;
  uint32_t DFDLY;
} sn32_spi_t;

#endif /* SN32_SPI_H */

/** @} */

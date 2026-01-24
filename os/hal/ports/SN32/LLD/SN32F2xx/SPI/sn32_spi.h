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
    volatile uint32_t CTRL0;                    /*!< (@ 0x00000000) Offset:0x00 SPIn Control Register 0                        */

    struct {
      volatile uint32_t SPIEN      : 1;         /*!< [0..0] SPI enable                                                         */
      volatile uint32_t LOOPBACK   : 1;         /*!< [1..1] Loopback mode enable                                               */
      volatile uint32_t SDODIS     : 1;         /*!< [2..2] Slave data out disable                                             */
      volatile uint32_t MS         : 1;         /*!< [3..3] Master/Slave selection                                             */
      volatile uint32_t FORMAT     : 1;         /*!< [4..4] Interface format                                                   */
               uint32_t            : 1;
      volatile uint32_t FRESET     : 2;         /*!< [7..6] SPI FSM and FIFO Reset                                             */
      volatile uint32_t DL         : 4;         /*!< [11..8] Data length = DL[3:0]+1                                           */
      volatile uint32_t TXFIFOTH   : 3;         /*!< [14..12] TX FIFO Threshold level                                          */
      volatile uint32_t RXFIFOTH   : 3;         /*!< [17..15] RX FIFO Threshold level                                          */
      volatile uint32_t SELDIS     : 1;         /*!< [18..18] Auto-SEL disable bit                                             */
               uint32_t            : 13;
    } CTRL0_b;
  };

  volatile uint32_t CTRL1;                      /*!< (@ 0x00000004) Offset:0x04 SPIn Control Register 1                        */
  volatile uint32_t CLKDIV;                     /*!< (@ 0x00000008) Offset:0x08 SPIn Clock Divider Register                    */

  union {
    volatile const uint32_t STAT;               /*!< (@ 0x0000000C) Offset:0x0C SPIn Status Register                           */

    struct {
      volatile const uint32_t TX_EMPTY   : 1;   /*!< [0..0] TX FIFO empty flag                                                 */
      volatile const uint32_t TX_FULL    : 1;   /*!< [1..1] TX FIFO full flag                                                  */
      volatile const uint32_t RX_EMPTY   : 1;   /*!< [2..2] RX FIFO empty flag                                                 */
      volatile const uint32_t RX_FULL    : 1;   /*!< [3..3] RX FIFO full flag                                                  */
      volatile const uint32_t BUSY       : 1;   /*!< [4..4] Busy flag                                                          */
      volatile const uint32_t TXFIFOTHF  : 1;   /*!< [5..5] TX FIFO threshold flag                                             */
      volatile const uint32_t RXFIFOTHF  : 1;   /*!< [6..6] RX FIFO threshold flag                                             */
                     uint32_t            : 25;
    } STAT_b;
  };

  union {
    volatile uint32_t IE;                       /*!< (@ 0x00000010) Offset:0x10 SPIn Interrupt Enable Register                 */

    struct {
      volatile uint32_t RXOVFIE    : 1;         /*!< [0..0] RX FIFO overflow interrupt enable                                  */
      volatile uint32_t RXTOIE     : 1;         /*!< [1..1] RX time-out interrupt enable                                       */
      volatile uint32_t RXFIFOTHIE : 1;         /*!< [2..2] RX FIFO threshold interrupt enable                                 */
      volatile uint32_t TXFIFOTHIE : 1;         /*!< [3..3] TX FIFO threshold interrupt enable                                 */
               uint32_t            : 28;
    } IE_b;
  };

  union {
    volatile const uint32_t RIS;                /*!< (@ 0x00000014) Offset:0x14 SPIn Raw Interrupt Status Register             */

    struct {
      volatile const uint32_t RXOVFIF    : 1;   /*!< [0..0] RX FIFO overflow interrupt flag                                    */
      volatile const uint32_t RXTOIF     : 1;   /*!< [1..1] RX time-out interrupt flag                                         */
      volatile const uint32_t RXFIFOTHIF : 1;   /*!< [2..2] RX FIFO threshold interrupt flag                                   */
      volatile const uint32_t TXFIFOTHIF : 1;   /*!< [3..3] TX FIFO threshold interrupt flag                                   */
                     uint32_t            : 28;
    } RIS_b;
  };

  union {
    volatile uint32_t IC;                       /*!< (@ 0x00000018) Offset:0x18 SPIn Interrupt Clear Register                  */

    struct {
      volatile uint32_t RXOVFIC    : 1;         /*!< [0..0] RX FIFO overflow flag clear                                        */
      volatile uint32_t RXTOIC     : 1;         /*!< [1..1] RX time-out interrupt flag clear                                   */
      volatile uint32_t RXFIFOTHIC : 1;         /*!< [2..2] RX Interrupt flag Clear                                            */
      volatile uint32_t TXFIFOTHIC : 1;         /*!< [3..3] TX Interrupt flag Clear                                            */
               uint32_t            : 28;
    } IC_b;
  };

  volatile uint32_t DATA;                       /*!< (@ 0x0000001C) Offset:0x1C SPIn Data Register                             */
  volatile uint32_t DFDLY;                      /*!< (@ 0x00000020) Offset:0x20 SPIn Data Fetch Register                       */
} sn32_spi_t;

#endif /* SN32_SPI_H */

/** @} */

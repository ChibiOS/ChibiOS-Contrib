/*
    Copyright (C) 2023 1Conan
    Copyright (C) 2025 Dimitris Mantzouranis

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
#    define SN32_I2C_H

typedef struct {
  union {
    volatile uint32_t CTRL; /*!< (@ 0x00000000) Offset:0x00 I2Cn Control Register                          */

    struct {
      uint32_t : 1;
      volatile uint32_t NACK : 1; /*!< [1..1] NACK assert flag                                              */
      volatile uint32_t ACK : 1;  /*!< [2..2] ACK assert flag                                               */
      uint32_t : 1;
      volatile uint32_t STO : 1; /*!< [4..4] STOP assert flag                                               */
      volatile uint32_t STA : 1; /*!< [5..5] START assert flag                                              */
      uint32_t : 1;
      volatile uint32_t I2CMODE : 1; /*!< [7..7] I2C mode                                                   */
      volatile uint32_t I2CEN : 1;   /*!< [8..8] I2Cn interface enable                                      */
      uint32_t : 23;
    } CTRL_b;
  };

  union {
    volatile uint32_t STAT; /*!< (@ 0x00000004) Offset:0x04 I2Cn Status Register                            */

    struct {
      volatile const uint32_t RX_DN : 1;      /*!< [0..0] RX done status                                    */
      volatile const uint32_t ACK_STAT : 1;   /*!< [1..1] ACK done status                                   */
      volatile const uint32_t NACK_STAT : 1;  /*!< [2..2] NACK done status                                  */
      volatile const uint32_t STOP_DN : 1;    /*!< [3..3] STOP done status                                  */
      volatile const uint32_t START_DN : 1;   /*!< [4..4] START done status                                 */
      volatile const uint32_t MST : 1;        /*!< [5..5] I2C master/slave status                           */
      volatile const uint32_t SLV_RX_HIT : 1; /*!< [6..6] Slave RX address hit flag                         */
      volatile const uint32_t SLV_TX_HIT : 1; /*!< [7..7] Slave TX address hit flag                         */
      volatile const uint32_t LOST_ARB : 1;   /*!< [8..8] Lost arbitration status                           */
      volatile const uint32_t TIMEOUT : 1;    /*!< [9..9] Time-out status                                   */
      uint32_t : 5;
      volatile uint32_t I2CIF : 1;            /*!< [15..15] I2C interrupt flag                              */
      uint32_t : 16;
    } STAT_b;
  };

  volatile uint32_t       TXDATA; /*!< (@ 0x00000008) Offset:0x08 I2Cn TX Data Register                     */
  volatile const uint32_t RXDATA; /*!< (@ 0x0000000C) Offset:0x0C I2Cn RX Data Register                     */

  union {
    volatile uint32_t SLVADDR0; /*!< (@ 0x00000010) Offset:0x10 I2Cn Slave Address 0 Register               */

    struct {
      volatile uint32_t ADDR : 10;    /*!< [9..0] I2Cn slave address 0                                      */
      uint32_t : 20;
      volatile uint32_t  GCEN : 1;    /*!< [30..30] General call address enable                             */
      volatile uint32_t ADD_MODE : 1; /*!< [31..31] Slave address mode                                      */
    } SLVADDR0_b;
  };

  volatile uint32_t SLVADDR1; /*!< (@ 0x00000014) Offset:0x14 I2Cn Slave Address 1 Register                 */
  volatile uint32_t SLVADDR2; /*!< (@ 0x00000018) Offset:0x18 I2Cn Slave Address 2 Register                 */
  volatile uint32_t SLVADDR3; /*!< (@ 0x0000001C) Offset:0x1C I2Cn Slave Address 3 Register                 */
  volatile uint32_t SCLHT;    /*!< (@ 0x00000020) Offset:0x20 I2Cn SCL High Time Register                   */
  volatile uint32_t SCLLT;    /*!< (@ 0x00000024) Offset:0x24 I2Cn SCL Low Time Register                    */
  volatile uint32_t SCLCT;    /*!< (@ 0x00000028) Offset:0x28 I2C SCL Check Time register                   */
  volatile uint32_t TOCTRL;   /*!< (@ 0x0000002C) Offset:0x2C I2Cn Timeout Control Register                 */
} sn32_i2c_t;


/* I2C n Status register <I2Cn_STAT> (0x04) */
#define mskI2C_RX_DONE               (1 << 0)
#define mskI2C_ACK_DONE              (1 << 1)
#define mskI2C_NACK_DONE             (1 << 2)
#define mskI2C_STOP_DONE             (1 << 3)
#define mskI2C_START_DONE            (1 << 4)
#define mskI2C_MASTER_STATUS         (1 << 5)
#define mskI2C_SLAVE_RX_MATCH        (1 << 6)
#define mskI2C_SLAVE_TX_MATCH        (1 << 7)
#define mskI2C_LOST_ARB              (1 << 8)
#define mskI2C_I2C_TIMEOUT           (1 << 9)
#define mskI2C_I2CIF_PENDING         (1 << 15)

#endif /* SN32_I2C_H */

/** @} */
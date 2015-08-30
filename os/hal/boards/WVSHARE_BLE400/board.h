/*
    Copyright (C) 2015 Fabio Utzig

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

#ifndef _BOARD_H_
#define _BOARD_H_

/* Board identifier. */
#define BOARD_WVSHARE_BLE400
#define BOARD_NAME              "WvShare BLE400"

/* Board oscillators-related settings. */
#define XTAL_VALUE              16000000

/* GPIO pins. */
#define KEY1           16
#define KEY2           17
#define LED0           18
#define LED1           19
#define LED2           20
#define LED3           21
#define LED4           22
#define UART_TX        9
#define UART_RX        11
#define SPI_SCK        25
#define SPI_MOSI       24
#define SPI_MISO       23
#define SPI_SS         30
#define I2C_SCL        1
#define I2C_SDA        0

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */

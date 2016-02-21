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
#define BOARD_NRF51_DK
#define BOARD_NAME              "nRF51 DK"

/* Board oscillators-related settings. */
#define NRF51_XTAL_VALUE        16000000
#define NRF51_LFCLK_SOURCE      1

/* GPIO pins. */
#define BTN1           17
#define BTN2           18
#define BTN3           19
#define BTN4           20
#define LED1           21
#define LED2           22
#define LED3           23
#define LED4           24
#define UART_RTS        8
#define UART_TX         9
#define UART_CTS       10
#define UART_RX        11
#define SPI_SCK        29
#define SPI_MOSI       25
#define SPI_MISO       28
#define SPI_SS         24
#define I2C_SCL         7
#define I2C_SDA        30

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

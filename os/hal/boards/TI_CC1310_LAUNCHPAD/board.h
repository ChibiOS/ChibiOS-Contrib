/*
    Copyright (C) 2023 Xael South

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

#ifndef BOARD_H
#define BOARD_H

/*
 * Setup for Texas Instruments CC1310 Launchpad Board.
 */

/*
 * Board identifier.
 */
#define BOARD_TI_CC1310_LAUNCHPAD
#define BOARD_NAME              "Texas Instruments CC1310 Launchpad"

/*
 * MCU type and revision as defined in the TI header.
 */
#define CC1310F128RGZ

/*
 * Board oscillators-related settings.
 */
/*
 * Board oscillators-related settings.
 */
#define TI_XOSC_LF         32768
#define TI_RCOSC_LF        32000

#define TI_XOSC_HF         24000000
#define TI_RCOSC_HF        24000000

/*
 * IO pins assignments.
 */
#define DIO1
#define DIO2_RXD
#define DIO3_TXD
#define DIO4_SCL
#define DIO5_SDA
#define DIO6_RLED
#define DIO7_GLED
#define DIO8_MISO
#define DII9_MOSI
#define DIO10_SCLK
#define DIO11_CS
#define DIO12
#define DIO13_BTN1
#define DIO14_BTN2
#define DIO15
#define DIO16_TDO
#define DIO17_TDI
#define DIO18_RTS_SWO
#define DIO19_CTS
#define DIO20_FLASH_CS
#define DIO21
#define DIO22
#define DIO23_ANALOG
#define DIO24_ANALOG
#define DIO25_ANALOG
#define DIO26_ANALOG
#define DIO27_ANALOG
#define DIO28_ANALOG
#define DIO29_ANALOG
#define DIO30_ANALOG

/*
 * IO lines assignments.
 */
#define LINE_DIO1           PAL_LINE(GPIOA, 0U)
#define LINE_DIO2_RXD       PAL_LINE(GPIOA, 1U)
#define LINE_DIO3_TXD       PAL_LINE(GPIOA, 2U)

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 */
#define PIN_DATA_LOW(n)         (0U << (n))
#define PIN_DATA_HIGH(n)        (1U << (n))

#define PIN_DIR_IN(n)           (0U << (n))
#define PIN_DIR_OUT(n)          (1U << (n))

#define PIN_AFSEL_GPIO(n)       (0U << (n))
#define PIN_AFSEL_ALTERNATE(n)  (1U << (n))

#define PIN_ODR_DISABLE(n)      (0U << (n))
#define PIN_ODR_ENABLE(n)       (1U << (n))

#define PIN_PxR_DISABLE(n)      (0U << (n))
#define PIN_PxR_ENABLE(n)       (1U << (n))

#define PIN_DEN_DISABLE(n)      (0U << (n))
#define PIN_DEN_ENABLE(n)       (1U << (n))

#define PIN_AMSEL_DISABLE(n)    (0U << (n))
#define PIN_AMSEL_ENABLE(n)     (1U << (n))

#define PIN_DRxR_DISABLE(n)     (0U << (n))
#define PIN_DRxR_ENABLE(n)      (1U << (n))

#define PIN_SLR_DISABLE(n)      (0U << (n))
#define PIN_SLR_ENABLE(n)       (1U << (n))

#define PIN_PCTL_MODE(n, mode)  (mode << ((n) * 4))

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */

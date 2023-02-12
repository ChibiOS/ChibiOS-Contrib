/*
    ChibiOS - Copyright (C) 2015 RedoX https://github.com/RedoXyde

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

/*
 * Setup for the EdgePro1 board.
 */

/*
 * Board identifier.
 */
#define BOARD_EDGEPRO1
#define BOARD_NAME                  "EdgePro1"

/*
 * MCU type
 */
#define MIMXRT1064

/*
 * IO pins assignments.
 *
 * These come from (with light string replacement from CORE_ to EDGEPRO1_ for
 * consistency with the EDGEPRO1 3.6 port):
 * https://github.com/PaulStoffregen/cores/blob/master/EDGEPRO14/core_pins.h
 *
 */

// We expose EDGEPRO1 pin numbers
#define EDGEPRO1_PIN0 0
#define EDGEPRO1_PIN1 1
#define EDGEPRO1_PIN2 2
#define EDGEPRO1_PIN3 3
#define EDGEPRO1_PIN4 4
#define EDGEPRO1_PIN5 5
#define EDGEPRO1_PIN6 6
#define EDGEPRO1_PIN7 7
#define EDGEPRO1_PIN8 8
#define EDGEPRO1_PIN9 9
#define EDGEPRO1_PIN10 10
#define EDGEPRO1_PIN11 11
#define EDGEPRO1_PIN12 12
#define EDGEPRO1_PIN13 13
#define EDGEPRO1_PIN14 14
#define EDGEPRO1_PIN15 15
#define EDGEPRO1_PIN16 16


#define EDGEPRO1_PIN0_BIT           2
#define EDGEPRO1_PIN1_BIT           3
#define EDGEPRO1_PIN2_BIT           0
#define EDGEPRO1_PIN3_BIT           1
#define EDGEPRO1_PIN4_BIT           13
#define EDGEPRO1_PIN5_BIT           14
#define EDGEPRO1_PIN6_BIT           16
#define EDGEPRO1_PIN7_BIT           15
#define EDGEPRO1_PIN8_BIT           7
#define EDGEPRO1_PIN9_BIT           6
#define EDGEPRO1_PIN10_BIT          10
#define EDGEPRO1_PIN11_BIT          5
#define EDGEPRO1_PIN12_BIT          8
#define EDGEPRO1_PIN13_BIT          9
#define EDGEPRO1_PIN14_BIT          6
#define EDGEPRO1_PIN15_BIT          7
#define EDGEPRO1_PIN16_BIT          4


#define EDGEPRO1_PIN0_IOPORT        GPIO7
#define EDGEPRO1_PIN1_IOPORT        GPIO7
#define EDGEPRO1_PIN2_IOPORT        GPIO7
#define EDGEPRO1_PIN3_IOPORT        GPIO7
#define EDGEPRO1_PIN4_IOPORT        GPIO9
#define EDGEPRO1_PIN5_IOPORT        GPIO9
#define EDGEPRO1_PIN6_IOPORT        GPIO9
#define EDGEPRO1_PIN7_IOPORT        GPIO9
#define EDGEPRO1_PIN8_IOPORT        GPIO6
#define EDGEPRO1_PIN9_IOPORT        GPIO6
#define EDGEPRO1_PIN10_IOPORT       GPIO6
#define EDGEPRO1_PIN11_IOPORT       GPIO6
#define EDGEPRO1_PIN12_IOPORT       GPIO6
#define EDGEPRO1_PIN13_IOPORT       GPIO6
#define EDGEPRO1_PIN14_IOPORT       GPIO6
#define EDGEPRO1_PIN15_IOPORT       GPIO6
#define EDGEPRO1_PIN16_IOPORT       GPIO6


// mux config registers control which peripheral uses the pin
#define EDGEPRO1_PIN0_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_02
#define EDGEPRO1_PIN1_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03
#define EDGEPRO1_PIN2_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_00
#define EDGEPRO1_PIN3_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_01
#define EDGEPRO1_PIN4_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_13
#define EDGEPRO1_PIN5_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_14
#define EDGEPRO1_PIN6_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_16
#define EDGEPRO1_PIN7_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_15
#define EDGEPRO1_PIN8_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_07
#define EDGEPRO1_PIN9_MUX        kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_06
#define EDGEPRO1_PIN10_MUX       kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_10
#define EDGEPRO1_PIN11_MUX       kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_05
#define EDGEPRO1_PIN12_MUX       kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_08
#define EDGEPRO1_PIN13_MUX       kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_09
#define EDGEPRO1_PIN14_MUX       kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_06
#define EDGEPRO1_PIN15_MUX       kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_07
#define EDGEPRO1_PIN16_MUX       kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_04

// pad config registers control pullup/pulldown/keeper, drive strength, etc
#define EDGEPRO1_PIN0_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_02
#define EDGEPRO1_PIN1_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_03
#define EDGEPRO1_PIN2_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_00
#define EDGEPRO1_PIN3_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_01
#define EDGEPRO1_PIN4_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_13
#define EDGEPRO1_PIN5_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_14
#define EDGEPRO1_PIN6_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_16
#define EDGEPRO1_PIN7_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_15
#define EDGEPRO1_PIN8_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_07
#define EDGEPRO1_PIN9_PAD     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_06
#define EDGEPRO1_PIN10_PAD    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_10
#define EDGEPRO1_PIN11_PAD    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_05
#define EDGEPRO1_PIN12_PAD    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_08
#define EDGEPRO1_PIN13_PAD    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_09
#define EDGEPRO1_PIN14_PAD    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_06
#define EDGEPRO1_PIN15_PAD    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_07
#define EDGEPRO1_PIN16_PAD    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_04


#define LINE_PIN0           PAL_LINE(EDGEPRO1_PIN0_IOPORT, EDGEPRO1_PIN0)
#define LINE_PIN1           PAL_LINE(EDGEPRO1_PIN1_IOPORT, EDGEPRO1_PIN1)
#define LINE_PIN2           PAL_LINE(EDGEPRO1_PIN2_IOPORT, EDGEPRO1_PIN2)
#define LINE_PIN3           PAL_LINE(EDGEPRO1_PIN3_IOPORT, EDGEPRO1_PIN3)
#define LINE_PIN4           PAL_LINE(EDGEPRO1_PIN4_IOPORT, EDGEPRO1_PIN4)
#define LINE_PIN5           PAL_LINE(EDGEPRO1_PIN5_IOPORT, EDGEPRO1_PIN5)
#define LINE_PIN6           PAL_LINE(EDGEPRO1_PIN6_IOPORT, EDGEPRO1_PIN6)
#define LINE_PIN7           PAL_LINE(EDGEPRO1_PIN7_IOPORT, EDGEPRO1_PIN7)
#define LINE_PIN8           PAL_LINE(EDGEPRO1_PIN8_IOPORT, EDGEPRO1_PIN8)
#define LINE_PIN9           PAL_LINE(EDGEPRO1_PIN9_IOPORT, EDGEPRO1_PIN9)
#define LINE_PIN10          PAL_LINE(EDGEPRO1_PIN10_IOPORT, EDGEPRO1_PIN10)
#define LINE_PIN11          PAL_LINE(EDGEPRO1_PIN11_IOPORT, EDGEPRO1_PIN11)
#define LINE_PIN12          PAL_LINE(EDGEPRO1_PIN12_IOPORT, EDGEPRO1_PIN12)
#define LINE_PIN13          PAL_LINE(EDGEPRO1_PIN13_IOPORT, EDGEPRO1_PIN13)
#define LINE_PIN14          PAL_LINE(EDGEPRO1_PIN14_IOPORT, EDGEPRO1_PIN14)
#define LINE_PIN15          PAL_LINE(EDGEPRO1_PIN15_IOPORT, EDGEPRO1_PIN15)
#define LINE_PIN16          PAL_LINE(EDGEPRO1_PIN16_IOPORT, EDGEPRO1_PIN16)


#define LINE_LED            LINE_PIN13

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

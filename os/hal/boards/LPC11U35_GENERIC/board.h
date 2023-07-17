/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

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

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef _BOARD_H_
#define _BOARD_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for LPC11U35 board.
 */

/*
 * Board identifier.
 */
#define BOARD_LPC11U35_GENERIC  
#define BOARD_NAME                  "LPC11U35_GENERIC"

#define LPC11U35

/*
 * IO pins assignments.
 *
 * Define ST/SN GPIO convensions so that we could use A1..B31 shorthands as
 * defined in chibios: platforms/chibios/_pin_defs.h
 */
#define GPIOA                                           IOPORT0
#define GPIOB                                           IOPORT1


#define LINE_RESET                                      PAL_LINE(IOPORT0, 0)
#define LINE_USBISP                                     PAL_LINE(IOPORT0, 1)
#define LINE_USBCONN                                    PAL_LINE(IOPORT0, 6)
#define LINE_USBVBUS                                    PAL_LINE(IOPORT0, 3)

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

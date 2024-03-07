/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif

#include "fs026.h"
#include "md_tick.h"
#include "md_rcu.h"
#include "md_syscfg.h"
#include "md_fc.h"
#include "md_gpio.h"
#include "md_dma.h"
#include "md_csu.h"
#include "md_rtc.h"
#include "md_exti.h"
#include "md_uart.h"
#include "md_spi.h"
#include "md_i2c.h"
#include "md_timer.h"
#include "md_wwdt.h"
#include "md_iwdt.h"
#include "md_adc.h"
#include "md_utils.h"
#include "ald_usb.h"

#define ES32_HAS_GPIOA 1
#define ES32_HAS_GPIOB 1
#define ES32_HAS_GPIOC 1
#define ES32_HAS_GPIOD 1


  void boardInit(void);

#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */

/*
    ChibiOS - Copyright (C) 2021 Stefan Kerkmann.

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    chcore.c
 * @brief   Port related template code.
 *
 * @addtogroup port_core
 * @details Non portable code templates.
 * @{
 */

#include "ch.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

volatile uint32_t rt_interrupt_from_thread;
volatile uint32_t rt_interrupt_to_thread;
volatile uint32_t  rt_thread_switch_interrupt_flag = 0;

volatile thread_t * last_ntp;
volatile thread_t * last_otp;

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void switch_thread_by_handler(thread_t *ntp, thread_t *otp)
{
	last_ntp = ntp;
	last_otp = otp;
	
    rt_interrupt_from_thread = (uint32_t)(&(otp->ctx.sp));
    rt_interrupt_to_thread = (uint32_t)(&(ntp->ctx.sp));
    rt_thread_switch_interrupt_flag = 1;
	
    *((uint8_t*)0xE080100C) = 0x1;//trig MACHINE_MODE_SOFT_Handler
	
	__enable_irq();
	__disable_irq();
}

/** @} */

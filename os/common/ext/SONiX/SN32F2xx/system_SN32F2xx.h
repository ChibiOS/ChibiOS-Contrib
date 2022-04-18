/**************************************************************************//**
 * @file     system_SN32F240B.h
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Header File
 *           for the SONIX SN32F240B Device
 * @version  V1.1
 * @date     Jul 2017
 *
 * @note
 * Copyright (C) 2009-2017 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __SYSTEM_SN32F2xx_H
#define __SYSTEM_SN32F2xx_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "SN32F2xx.h"
extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */


/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);
#if defined(SN32F240B)
/**
 * Initialize the Flash controller
 *
 * @param  none
 * @return none
 *
 * @brief  Update the Flash power control.
 */
extern void FlashClockUpdate (void);

/**
 * Switch System to Slow Mode
 * @param  none
 * @return none
 *
 * @brief  Special init required for SystemCoreClock <= 8000
 */
extern void SlowModeSwitch (void);
#endif /* defined(SN32F240B) */

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_SN32F2xx_H */

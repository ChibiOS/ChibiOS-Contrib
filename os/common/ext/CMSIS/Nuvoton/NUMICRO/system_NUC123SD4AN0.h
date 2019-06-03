 /**************************************************************************//**
 * @file     system_NUC123SD4AN0.h
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Header File for
 *           Device NUC123SD4AN0
 * @version  V5.00
 * @date     13. May 2019
 ******************************************************************************/
/*
 * Copyright (c) 2019 /u/KeepItUnder. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SYSTEM_NUC123SD4AN0_H   /* ToDo: replace '<Device>' with your device name */
#define SYSTEM_NUC123SD4AN0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * Frequency Defines
 * 
 * See NUC123 Technical Reference Manual 5.4.2, page 103
 * 
 */

#define __HXT          (12000000ul)    // PCB-mounted High Frequency Crystal (12MHz)
#define __HIRC         (22118400ul)    // Internal MCU-block HF Oscillator Frequency (22.1184MHz)
#define __LXT          (32768ul)       // PCB-mounted Low Frequency Crystal (32kHz)
#define __LIRC         (10000ul)       // Internal MCU-block LF Oscillator Frequency (10kHz)
#define __HSI          (50000000ul)    // PLL clock (50MHz)


extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */
extern uint32_t CyclesPerUs;         /*!< Cycles per micro second              */
extern uint32_t PllClock;            /*!< PLL Output Clock Frequency           */


/**
  \brief Setup the microcontroller system.

   Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
  \brief  Update SystemCoreClock variable.

   Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

extern void SystemUnlockReg (void);


#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_NUC123SD4AN0_H */
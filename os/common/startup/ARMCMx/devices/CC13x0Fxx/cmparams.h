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

/**
 * @file    CC13x0Fxx/cmparams.h
 * @brief   ARM Cortex-M3 parameters for the CC13x0Fxx.
 *
 * @defgroup ARMCMx_CC13x0Fxx CC13x0Fxx Specific Parameters
 * @ingroup ARMCMx_SPECIFIC
 * @details This file contains the Cortex-M3 specific parameters for the
 *          CC13x0Fxx platform.
 * @{
 */

#ifndef CMPARAMS_H
#define CMPARAMS_H

/* Defines required for correct CMSIS header functioning */
#define __CM3_REV                 0x200U /*!< Cortex-M3 Revision r2p0                      */
#define __MPU_PRESENT             0U     /*!< Does not provides MPU                        */
#define __NVIC_PRIO_BITS          3U     /*!< Uses 3 Bits for the Priority Levels          */
#define __Vendor_SysTickConfig    0U     /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             0U

/**
 * @brief   Cortex core model.
 */
#define CORTEX_MODEL            3

/**
 * @brief   Floating Point unit presence.
 */
#define CORTEX_HAS_FPU          0

/**
 * @brief   Number of bits in priority masks.
 */
#define CORTEX_PRIORITY_BITS    3

/* If the device type is not externally defined, for example from the Makefile,
   then a file named board.h is included. This file must contain a device
   definition compatible with the include file.*/
#if !defined (CC1310F128RGZ_R20)  && !defined (CC1310F128RGZ)  &&       \
    !defined (CC1310F128RHB_R20)  && !defined (CC1310F128RHB)  &&       \
    !defined (CC1310F128RSM_R20)  && !defined (CC1310F128RSM)  &&       \
    !defined (CC1310F128_R20)     && !defined (CC1310F128)     &&       \
    !defined (CC1312R1FRGZ_R10)   && !defined (CC1312R1FRGZ)   &&       \
    !defined (CC1312R1F_R10)      && !defined (CC1312R1F)
#include "board.h"
#endif

/**
 * @brief   Number of interrupt vectors.
 * @note    This number does not include the 16 system vectors and must be
 *          rounded to a multiple of 8.
 */
#define CORTEX_NUM_VECTORS      56

/* The following code is not processed when the file is included from an
   asm module.*/
#if !defined(_FROM_ASM_)

/*!< Interrupt Number Definition */
typedef enum
{
/******  Cortex-M3 Processor Exceptions Numbers ******************************************************/
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                        */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                         */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                       */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                          */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                    */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                          */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                      */

/******  CC13x0 specific Interrupt Numbers ***********************************************************/
  EXTI_IRQn                   = 0,      /*!< GPIO edge detect                               */
  I2C_IRQn                    = 1,      /*!< I2C Event Interrup                             */
  RFCP1_IRQn                  = 2,      /*!< RF Core and packet engine 1                     */
  RTC_IRQn                    = 4,      /*!< AON RTC                                        */
  USART1_IRQn                 = 5,      /*!< USART1 global Interrupt                        */
  USART2_IRQn                 = 6,      /*!< USART2 global Interrupt                        */

} IRQn_Type;

/* Including the device CMSIS header. Note, we are not using the definitions
   from this header because we need this file to be usable also from
   assembler source files. We verify that the info matches instead.*/
#include "core_cm3.h"

/* Including the TivaWare peripheral headers.*/
#include "inc/hw_chip_def.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_nvic.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_gpio.h"
#include "inc/hw_uart.h"
#include "inc/hw_i2c.h"
#include "inc/hw_wdt.h"
#include "inc/hw_ssi.h"
#include "inc/hw_udma.h"
#include "inc/hw_ddi_0_osc.h"

/*lint -save -e9029 [10.4] Signedness comes from external files, it is
  unpredictable but gives no problems.*/
#if CORTEX_MODEL != __CORTEX_M
#error "CMSIS __CORTEX_M mismatch"
#endif

#if CORTEX_HAS_FPU != __FPU_PRESENT
#error "CMSIS __FPU_PRESENT mismatch"
#endif

#if CORTEX_PRIORITY_BITS != __NVIC_PRIO_BITS
#error "CMSIS __NVIC_PRIO_BITS mismatch"
#endif
/*lint -restore*/

#endif /* !defined(_FROM_ASM_) */

#endif /* CMPARAMS_H */

/** @} */

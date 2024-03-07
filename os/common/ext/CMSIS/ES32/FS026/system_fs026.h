/**********************************************************************************
 *
 * @file    system_es32f0283.h
 * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *
 * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
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
 *
 **********************************************************************************
 */ 

/* Define to prevent recursive inclusion -------------------------------------*/ 

#ifndef __SYSTEM_FS026_H__
#define __SYSTEM_ES32F0283_H__

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes -------------------------------------------------------*/
#include <stdint.h>
 
/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup system_es32f0283
  * @{
  */
   
/* Public Functions -----------------------------------------------------------*/
/* Public Init Structure ------------------------------------------------------*/
/* Public Macros --------------------------------------------------------------*/
/* Public Constants -----------------------------------------------------------*/
/* Private Variables ----------------------------------------------------------*/
/* Private Macros -------------------------------------------------------------*/
/* Private Constants-----------------------------------------------------------*/

/* Public Types ---------------------------------------------------------------*/
/** @addtogroup Public_Types 
  * @{
  */
extern unsigned int SystemCoreClock;
extern unsigned int SystemFrequency_SysClk;
extern unsigned int SystemFrequency_AHBClk;
extern unsigned int SystemFrequency_APBClk;
extern unsigned int HRC48Frequency;
extern unsigned int PLL0Frequency;

/* Exported function -------------------------------------------------*/
/** @addtogroup Public_Functions
  * @{
  */

extern void SystemInit (void);

#ifdef __cplusplus
}
#endif

#endif 

/**
  * @} Public_Functions 
  */

/**
  * @} Public_Types
  */
  
/**
  * @} system_es32f0283
  */
  
/**
  * @} CMSIS
  */ 
/********** (C) COPYRIGHT Eastsoft Microelectronics END OF FILE **********/

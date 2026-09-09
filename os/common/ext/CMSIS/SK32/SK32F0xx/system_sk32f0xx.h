/**
  ******************************************************************************
  * @file    system_sk32f0xx.h
  * @author  3Think FD Department
  * @version V1.0.0
  * @date    2-September-2025
  * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer System Header File.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 3Tink.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup sk32f0xx_system
  * @{
  */  
  
/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef __SYSTEM_SK32F0XX_H
#define __SYSTEM_SK32F0XX_H

#ifdef __cplusplus
 extern "C" {
#endif 

/** @addtogroup SK32F0xx_System_Includes
  * @{
  */

/**
  * @}
  */


/** @addtogroup SK32F0xx_System_Exported_types
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */

/**
  * @}
  */

/** @addtogroup SK32F0xx_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup SK32F0xx_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup SK32F0xx_System_Exported_Functions
  * @{
  */
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_SK32F0XX_H */

/**
  * @}
  */
  
/**
  * @}
  */  

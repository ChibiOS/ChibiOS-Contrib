/**********************************************************************************
 *
 * @file    md_exti.h
 * @brief   header file of md_exti.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
 *          14 Dec  2021    Ginger          Modify function instructions
 *          21 Mar  2022    AE Team         Modify MD Driver
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
#ifndef __MD_EXTI_H__
#define __MD_EXTI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_EXTI EXTI
  * @brief EXTI micro driver
  * @{
  */


/** @defgroup MD_EXTI_Public_Macros EXTI Public Macros
  * @{
  */

#define MD_EXTI_PORT_GPIOA                  (0x00000000UL)       /*!< @brief Select GPIOA for EXTIx */
#define MD_EXTI_PORT_GPIOB                  (0x00000001UL)       /*!< @brief Select GPIOB for EXTIx */
#define MD_EXTI_PORT_GPIOC                  (0x00000002UL)       /*!< @brief Select GPIOC for EXTIx */
#define MD_EXTI_PORT_GPIOD                  (0x00000003UL)       /*!< @brief Select GPIOD for EXTIx */

#define MD_EXTI_GPIO0                       (1<<0)      /*!< @brief Select GPIO0 for EXTIx */
#define MD_EXTI_GPIO1                       (1<<1)      /*!< @brief Select GPIO1 for EXTIx */
#define MD_EXTI_GPIO2                       (1<<2)      /*!< @brief Select GPIO2 for EXTIx */
#define MD_EXTI_GPIO3                       (1<<3)      /*!< @brief Select GPIO3 for EXTIx */
#define MD_EXTI_GPIO4                       (1<<4)      /*!< @brief Select GPIO4 for EXTIx */
#define MD_EXTI_GPIO5                       (1<<5)      /*!< @brief Select GPIO5 for EXTIx */
#define MD_EXTI_GPIO6                       (1<<6)      /*!< @brief Select GPIO6 for EXTIx */
#define MD_EXTI_GPIO7                       (1<<7)      /*!< @brief Select GPIO7 for EXTIx */
#define MD_EXTI_GPIO8                       (1<<8)      /*!< @brief Select GPIO0 for EXTIx */
#define MD_EXTI_GPIO9                       (1<<9)      /*!< @brief Select GPIO1 for EXTIx */
#define MD_EXTI_GPIO10                      (1<<10)     /*!< @brief Select GPIO2 for EXTIx */
#define MD_EXTI_GPIO11                      (1<<11)     /*!< @brief Select GPIO3 for EXTIx */
#define MD_EXTI_GPIO12                      (1<<12)     /*!< @brief Select GPIO4 for EXTIx */
#define MD_EXTI_GPIO13                      (1<<13)     /*!< @brief Select GPIO5 for EXTIx */
#define MD_EXTI_GPIO14                      (1<<14)     /*!< @brief Select GPIO6 for EXTIx */
#define MD_EXTI_GPIO15                      (1<<15)     /*!< @brief Select GPIO7 for EXTIx */

#define MD_EXTI_PIN_GPIO0                   (0)       /*!< @brief Select GPIO0 for EXTIx */
#define MD_EXTI_PIN_GPIO1                   (4)       /*!< @brief Select GPIO1 for EXTIx */
#define MD_EXTI_PIN_GPIO2                   (8)       /*!< @brief Select GPIO2 for EXTIx */
#define MD_EXTI_PIN_GPIO3                   (12)      /*!< @brief Select GPIO3 for EXTIx */
#define MD_EXTI_PIN_GPIO4                   (16)      /*!< @brief Select GPIO4 for EXTIx */
#define MD_EXTI_PIN_GPIO5                   (20)      /*!< @brief Select GPIO5 for EXTIx */
#define MD_EXTI_PIN_GPIO6                   (24)      /*!< @brief Select GPIO6 for EXTIx */
#define MD_EXTI_PIN_GPIO7                   (28)      /*!< @brief Select GPIO7 for EXTIx */

#define MD_EXTI_PIN_GPIO8                   (0)        /*!< @brief Select GPIO8  for EXTIx */
#define MD_EXTI_PIN_GPIO9                   (4)        /*!< @brief Select GPIO9  for EXTIx */
#define MD_EXTI_PIN_GPIO10                  (8)        /*!< @brief Select GPIO10 for EXTIx */
#define MD_EXTI_PIN_GPIO11                  (12)       /*!< @brief Select GPIO11 for EXTIx */
#define MD_EXTI_PIN_GPIO12                  (16)       /*!< @brief Select GPIO12 for EXTIx */
#define MD_EXTI_PIN_GPIO13                  (20)       /*!< @brief Select GPIO13 for EXTIx */
#define MD_EXTI_PIN_GPIO14                  (24)       /*!< @brief Select GPIO14 for EXTIx */
#define MD_EXTI_PIN_GPIO15                  (28)       /*!< @brief Select GPIO15 for EXTIx */

#define MD_EXTI_GPIOA0                      (0 << MD_EXTI_PIN_GPIO0)
#define MD_EXTI_GPIOA1                      (0 << MD_EXTI_PIN_GPIO1)
#define MD_EXTI_GPIOA2                      (0 << MD_EXTI_PIN_GPIO2)
#define MD_EXTI_GPIOA3                      (0 << MD_EXTI_PIN_GPIO3)
#define MD_EXTI_GPIOA4                      (0 << MD_EXTI_PIN_GPIO4)
#define MD_EXTI_GPIOA5                      (0 << MD_EXTI_PIN_GPIO5)
#define MD_EXTI_GPIOA6                      (0 << MD_EXTI_PIN_GPIO6)
#define MD_EXTI_GPIOA7                      (0 << MD_EXTI_PIN_GPIO7)
#define MD_EXTI_GPIOA8                      (0 << MD_EXTI_PIN_GPIO8)
#define MD_EXTI_GPIOA9                      (0 << MD_EXTI_PIN_GPIO9)
#define MD_EXTI_GPIOA10                     (0 << MD_EXTI_PIN_GPIO10)
#define MD_EXTI_GPIOA11                     (0 << MD_EXTI_PIN_GPIO11)
#define MD_EXTI_GPIOA12                     (0 << MD_EXTI_PIN_GPIO12)
#define MD_EXTI_GPIOA13                     (0 << MD_EXTI_PIN_GPIO13)
#define MD_EXTI_GPIOA14                     (0 << MD_EXTI_PIN_GPIO14)
#define MD_EXTI_GPIOA15                     (0 << MD_EXTI_PIN_GPIO15)

#define MD_EXTI_GPIOB0                      (1 << MD_EXTI_PIN_GPIO0)
#define MD_EXTI_GPIOB1                      (1 << MD_EXTI_PIN_GPIO1)
#define MD_EXTI_GPIOB2                      (1 << MD_EXTI_PIN_GPIO2)
#define MD_EXTI_GPIOB3                      (1 << MD_EXTI_PIN_GPIO3)
#define MD_EXTI_GPIOB4                      (1 << MD_EXTI_PIN_GPIO4)
#define MD_EXTI_GPIOB5                      (1 << MD_EXTI_PIN_GPIO5)
#define MD_EXTI_GPIOB6                      (1 << MD_EXTI_PIN_GPIO6)
#define MD_EXTI_GPIOB7                      (1 << MD_EXTI_PIN_GPIO7)
#define MD_EXTI_GPIOB8                      (1 << MD_EXTI_PIN_GPIO8)
#define MD_EXTI_GPIOB9                      (1 << MD_EXTI_PIN_GPIO9)
#define MD_EXTI_GPIOB10                     (1 << MD_EXTI_PIN_GPIO10)
#define MD_EXTI_GPIOB11                     (1 << MD_EXTI_PIN_GPIO11)
#define MD_EXTI_GPIOB12                     (1 << MD_EXTI_PIN_GPIO12)
#define MD_EXTI_GPIOB13                     (1 << MD_EXTI_PIN_GPIO13)
#define MD_EXTI_GPIOB14                     (1 << MD_EXTI_PIN_GPIO14)
#define MD_EXTI_GPIOB15                     (1 << MD_EXTI_PIN_GPIO15)

#define MD_EXTI_GPIOC0                      (2 << MD_EXTI_PIN_GPIO0)
#define MD_EXTI_GPIOC1                      (2 << MD_EXTI_PIN_GPIO1)
#define MD_EXTI_GPIOC2                      (2 << MD_EXTI_PIN_GPIO2)
#define MD_EXTI_GPIOC3                      (2 << MD_EXTI_PIN_GPIO3)
#define MD_EXTI_GPIOC4                      (2 << MD_EXTI_PIN_GPIO4)
#define MD_EXTI_GPIOC5                      (2 << MD_EXTI_PIN_GPIO5)
#define MD_EXTI_GPIOC6                      (2 << MD_EXTI_PIN_GPIO6)
#define MD_EXTI_GPIOC7                      (2 << MD_EXTI_PIN_GPIO7)
#define MD_EXTI_GPIOC8                      (2 << MD_EXTI_PIN_GPIO8)
#define MD_EXTI_GPIOC9                      (2 << MD_EXTI_PIN_GPIO9)
#define MD_EXTI_GPIOC10                     (2 << MD_EXTI_PIN_GPIO10)
#define MD_EXTI_GPIOC11                     (2 << MD_EXTI_PIN_GPIO11)
#define MD_EXTI_GPIOC12                     (2 << MD_EXTI_PIN_GPIO12)
#define MD_EXTI_GPIOC13                     (2 << MD_EXTI_PIN_GPIO13)
#define MD_EXTI_GPIOC14                     (2 << MD_EXTI_PIN_GPIO14)
#define MD_EXTI_GPIOC15                     (2 << MD_EXTI_PIN_GPIO15)

#define MD_EXTI_GPIOD0                      (3 << MD_EXTI_PIN_GPIO0)
#define MD_EXTI_GPIOD1                      (3 << MD_EXTI_PIN_GPIO1)
#define MD_EXTI_GPIOD2                      (3 << MD_EXTI_PIN_GPIO2)
#define MD_EXTI_GPIOD3                      (3 << MD_EXTI_PIN_GPIO3)
#define MD_EXTI_GPIOD4                      (3 << MD_EXTI_PIN_GPIO4)
#define MD_EXTI_GPIOD5                      (3 << MD_EXTI_PIN_GPIO5)
#define MD_EXTI_GPIOD6                      (3 << MD_EXTI_PIN_GPIO6)
#define MD_EXTI_GPIOD7                      (3 << MD_EXTI_PIN_GPIO7)
#define MD_EXTI_GPIOD8                      (3 << MD_EXTI_PIN_GPIO8)
#define MD_EXTI_GPIOD9                      (3 << MD_EXTI_PIN_GPIO9)
#define MD_EXTI_GPIOD10                     (3 << MD_EXTI_PIN_GPIO10)
#define MD_EXTI_GPIOD11                     (3 << MD_EXTI_PIN_GPIO11)
#define MD_EXTI_GPIOD12                     (3 << MD_EXTI_PIN_GPIO12)
#define MD_EXTI_GPIOD13                     (3 << MD_EXTI_PIN_GPIO13)
#define MD_EXTI_GPIOD14                     (3 << MD_EXTI_PIN_GPIO14)
#define MD_EXTI_GPIOD15                     (3 << MD_EXTI_PIN_GPIO15)

#define MD_EXTI_EVENT_GPIO0                 (1<<0)        /*!< @brief Select GPIO0  for EXTIx */
#define MD_EXTI_EVENT_GPIO1                 (1<<1)        /*!< @brief Select GPIO1  for EXTIx */
#define MD_EXTI_EVENT_GPIO2                 (1<<2)        /*!< @brief Select GPIO2  for EXTIx */
#define MD_EXTI_EVENT_GPIO3                 (1<<3)        /*!< @brief Select GPIO3  for EXTIx */
#define MD_EXTI_EVENT_GPIO4                 (1<<4)        /*!< @brief Select GPIO4  for EXTIx */
#define MD_EXTI_EVENT_GPIO5                 (1<<5)        /*!< @brief Select GPIO5  for EXTIx */
#define MD_EXTI_EVENT_GPIO6                 (1<<6)        /*!< @brief Select GPIO6  for EXTIx */
#define MD_EXTI_EVENT_GPIO7                 (1<<7)        /*!< @brief Select GPIO7  for EXTIx */
#define MD_EXTI_EVENT_GPIO8                 (1<<8)        /*!< @brief Select GPIO8  for EXTIx */
#define MD_EXTI_EVENT_GPIO9                 (1<<9)        /*!< @brief Select GPIO9  for EXTIx */
#define MD_EXTI_EVENT_GPIO10                (1<<10)       /*!< @brief Select GPIO10 for EXTIx */
#define MD_EXTI_EVENT_GPIO11                (1<<11)       /*!< @brief Select GPIO11 for EXTIx */
#define MD_EXTI_EVENT_GPIO12                (1<<12)       /*!< @brief Select GPIO12 for EXTIx */
#define MD_EXTI_EVENT_GPIO13                (1<<13)       /*!< @brief Select GPIO13 for EXTIx */
#define MD_EXTI_EVENT_GPIO14                (1<<14)       /*!< @brief Select GPIO14 for EXTIx */
#define MD_EXTI_EVENT_GPIO15                (1<<15)       /*!< @brief Select GPIO15 for EXTIx */
#define MD_EXTI_EVENT_CMP1                  (1<<16)       /*!< @brief Select CMP1   for EXTIx */
#define MD_EXTI_EVENT_CMP2                  (1<<17)       /*!< @brief Select CMP2   for EXTIx */
#define MD_EXTI_EVENT_LVD                   (1<<20)       /*!< @brief Select LVD    for EXTIx */
#define MD_EXTI_EVENT_WAKEUP                (1<<21)       /*!< @brief Select WAKEUP for EXTIx */

#define MD_EXTI_DEBOUNCECOUNT_IMMEDIATELY   0U
#define MD_EXTI_DEBOUNCECOUNT_2_TIMES       1U
#define MD_EXTI_DEBOUNCECOUNT_3_TIMES       2U
#define MD_EXTI_DEBOUNCECOUNT_4_TIMES       3U
#define MD_EXTI_DEBOUNCECOUNT_5_TIMES       4U
#define MD_EXTI_DEBOUNCECOUNT_6_TIMES       5U
#define MD_EXTI_DEBOUNCECOUNT_7_TIMES       6U
#define MD_EXTI_DEBOUNCECOUNT_8_TIMES       7U

/**
* @}
*/

/** @defgroup MD_EXTI_Public_Functions EXTI Public Functions
  * @{
  */

/** @defgroup MD_EXTI_Public_Functions_Group2 IER
  * @{
  */

/**
  * @brief  Enable interrupt on line
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->IER
  * @retval None
  */
__STATIC_INLINE void md_exti_set_ier(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->IER, value);
}

/**
  * @brief  Enable Wake Up interrupt
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_enable_it_wakeup(EXTI_TypeDef *exti)
{
    SET_BIT(exti->IER, EXTI_IER_WAKEUP);
}

/**
  * @brief  Enable Low Power Detector (LVD) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_enable_it_low_power_detector(EXTI_TypeDef *exti)
{
    SET_BIT(exti->IER, EXTI_IER_LVD);
}

/**
  * @brief  Enable Comparator2 (CMP2) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_enable_it_comparator2(EXTI_TypeDef *exti)
{
    SET_BIT(exti->IER, EXTI_IER_CMP2);
}

/**
  * @brief  Enable Comparator1 (CMP1) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_enable_it_comparator1(EXTI_TypeDef *exti)
{
    SET_BIT(exti->IER, EXTI_IER_CMP1);
}

/**
  * @brief  Enable GPIOy interrupt.
  * @param  exti EXTI Instance
  * @param  gpioy(gpio0~gpio15) The value write in EXTI->IER
            @arg @ref MD_EXTI_EVENT_GPIO0
            @arg @ref MD_EXTI_EVENT_GPIO1
            @arg @ref MD_EXTI_EVENT_GPIO2
            @arg @ref MD_EXTI_EVENT_GPIO3
            @arg @ref MD_EXTI_EVENT_GPIO4
            @arg @ref MD_EXTI_EVENT_GPIO5
            @arg @ref MD_EXTI_EVENT_GPIO6
            @arg @ref MD_EXTI_EVENT_GPIO7
            @arg @ref MD_EXTI_EVENT_GPIO8
            @arg @ref MD_EXTI_EVENT_GPIO9
            @arg @ref MD_EXTI_EVENT_GPIO10
            @arg @ref MD_EXTI_EVENT_GPIO11
            @arg @ref MD_EXTI_EVENT_GPIO12
            @arg @ref MD_EXTI_EVENT_GPIO13
            @arg @ref MD_EXTI_EVENT_GPIO14
            @arg @ref MD_EXTI_EVENT_GPIO15
  * @retval None
  */
__STATIC_INLINE void md_exti_enable_it_gpio_pin(EXTI_TypeDef *exti, uint32_t gpioy)
{
    SET_BIT(exti->IER, gpioy);
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group3 IDR
  * @{
  */
/**
  * @brief  Disable interrupt on line
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->IDR
  * @retval None
  */
__STATIC_INLINE void md_exti_set_idr(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->IDR, value);
}

/**
  * @brief  Disable Wake Up interrupt
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_disable_it_wakeup(EXTI_TypeDef *exti)
{
    SET_BIT(exti->IDR, EXTI_IDR_WAKEUP);
}

/**
  * @brief  Disable Low Power Detector (LVD) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_disable_it_low_power_detector(EXTI_TypeDef *exti)
{
    SET_BIT(exti->IDR, EXTI_IDR_LVD);
}

/**
  * @brief  Disable Comparator2 (CMP2) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_disable_it_comparator2(EXTI_TypeDef *exti)
{
    SET_BIT(exti->IDR, EXTI_IDR_CMP2);
}

/**
  * @brief  Disable Comparator1 (CMP1) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_disable_it_comparator1(EXTI_TypeDef *exti)
{
    SET_BIT(exti->IDR, EXTI_IDR_CMP1);
}

/**
  * @brief  Disable GPIOy interrupt.
  * @param  exti EXTI Instance
  * @param  gpioy(gpio0~gpio15) The value write in EXTI->IDR
            @arg @ref MD_EXTI_EVENT_GPIO0
            @arg @ref MD_EXTI_EVENT_GPIO1
            @arg @ref MD_EXTI_EVENT_GPIO2
            @arg @ref MD_EXTI_EVENT_GPIO3
            @arg @ref MD_EXTI_EVENT_GPIO4
            @arg @ref MD_EXTI_EVENT_GPIO5
            @arg @ref MD_EXTI_EVENT_GPIO6
            @arg @ref MD_EXTI_EVENT_GPIO7
            @arg @ref MD_EXTI_EVENT_GPIO8
            @arg @ref MD_EXTI_EVENT_GPIO9
            @arg @ref MD_EXTI_EVENT_GPIO10
            @arg @ref MD_EXTI_EVENT_GPIO11
            @arg @ref MD_EXTI_EVENT_GPIO12
            @arg @ref MD_EXTI_EVENT_GPIO13
            @arg @ref MD_EXTI_EVENT_GPIO14
            @arg @ref MD_EXTI_EVENT_GPIO15
  * @retval None
  */
__STATIC_INLINE void md_exti_disable_it_gpio_pin(EXTI_TypeDef *exti, uint32_t gpioy)
{
    SET_BIT(exti->IDR, gpioy);
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group4 IVS
  * @{
  */
/**
  * @brief  Interrupt Valid Status on line
  * @param  exti EXTI Instance
  * @retval EXTI->IVS value
  */
__STATIC_INLINE uint32_t md_exti_get_ivs(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->IVS));
}

/**
  * @brief  Wake Up interrupt enabled state.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_enabled_it_wakeup(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->IVS, EXTI_IVS_WAKEUP) == (EXTI_IVS_WAKEUP));
}

/**
  * @brief  Low Power Detector (LVD) interrupt enable state.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_enabled_it_low_power_detector(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->IVS, EXTI_IVS_LVD) == (EXTI_IVS_LVD));
}

/**
  * @brief  Comparator2 (CMP2) interrupt enable state.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_enabled_it_comparator2(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->IVS, EXTI_IVS_CMP2) == (EXTI_IVS_CMP2));
}

/**
  * @brief  Comparator1 (CMP1) interrupt enable state.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_enabled_it_comparator1(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->IVS, EXTI_IVS_CMP1) == (EXTI_IVS_CMP1));
}

/**
  * @brief  GPIOy interrupt. (y=0...15) Interrupt enable state.
  * @param  exti EXTI Instance
  * @param  gpioy(gpio0~gpio15) The value Read in EXTI->IVS
            @arg @ref MD_EXTI_EVENT_GPIO0
            @arg @ref MD_EXTI_EVENT_GPIO1
            @arg @ref MD_EXTI_EVENT_GPIO2
            @arg @ref MD_EXTI_EVENT_GPIO3
            @arg @ref MD_EXTI_EVENT_GPIO4
            @arg @ref MD_EXTI_EVENT_GPIO5
            @arg @ref MD_EXTI_EVENT_GPIO6
            @arg @ref MD_EXTI_EVENT_GPIO7
            @arg @ref MD_EXTI_EVENT_GPIO8
            @arg @ref MD_EXTI_EVENT_GPIO9
            @arg @ref MD_EXTI_EVENT_GPIO10
            @arg @ref MD_EXTI_EVENT_GPIO11
            @arg @ref MD_EXTI_EVENT_GPIO12
            @arg @ref MD_EXTI_EVENT_GPIO13
            @arg @ref MD_EXTI_EVENT_GPIO14
            @arg @ref MD_EXTI_EVENT_GPIO15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_enabled_it_gpio_pin(EXTI_TypeDef *exti, uint32_t gpioy)
{
    return (READ_BIT(exti->IVS, gpioy) == gpioy);
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group5 RIF
  * @{
  */
/**
  * @brief  Check if Raw interrupt flag Status on line is actived
  * @param  exti EXTI Instance
  * @retval EXTI->RIF value
  */
__STATIC_INLINE uint32_t md_exti_get_rif(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->RIF));
}

/**
  * @brief  Wake Up interrupts the original state.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_active_it_wakeup(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->RIF, EXTI_RIF_WAKEUP) == (EXTI_RIF_WAKEUP));
}

/**
  * @brief  Low Power Detector (LVD) interrupts the original state.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_active_it_low_power_detector(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->RIF, EXTI_RIF_LVD) == (EXTI_RIF_LVD));
}

/**
  * @brief  Comparator2 (CMP2) interrupts the original state.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_active_it_comparator2(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->RIF, EXTI_RIF_CMP2) == (EXTI_RIF_CMP2));
}

/**
  * @brief  Comparator1 (CMP1) interrupts the original state.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_active_it_comparator1(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->RIF, EXTI_RIF_CMP1) == (EXTI_RIF_CMP1));
}

/**
  * @brief  GPIOy interrupt. (y=0...15) Interrupt the original state.
  * @param  exti EXTI Instance
  * @param  gpioy(gpio0~gpio15) The value Read in EXTI->IVS
            @arg @ref MD_EXTI_EVENT_GPIO0
            @arg @ref MD_EXTI_EVENT_GPIO1
            @arg @ref MD_EXTI_EVENT_GPIO2
            @arg @ref MD_EXTI_EVENT_GPIO3
            @arg @ref MD_EXTI_EVENT_GPIO4
            @arg @ref MD_EXTI_EVENT_GPIO5
            @arg @ref MD_EXTI_EVENT_GPIO6
            @arg @ref MD_EXTI_EVENT_GPIO7
            @arg @ref MD_EXTI_EVENT_GPIO8
            @arg @ref MD_EXTI_EVENT_GPIO9
            @arg @ref MD_EXTI_EVENT_GPIO10
            @arg @ref MD_EXTI_EVENT_GPIO11
            @arg @ref MD_EXTI_EVENT_GPIO12
            @arg @ref MD_EXTI_EVENT_GPIO13
            @arg @ref MD_EXTI_EVENT_GPIO14
            @arg @ref MD_EXTI_EVENT_GPIO15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_active_it_gpio_pin(EXTI_TypeDef *exti, uint32_t gpioy)
{
    return (READ_BIT(exti->RIF, gpioy) == gpioy);
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group6 IFM
  * @{
  */
/**
  * @brief  Check if Interrupt Flag Masked Status on line is actived
  * @param  exti EXTI Instance
  * @retval EXTI->IFM value
  */
__STATIC_INLINE uint32_t md_exti_get_ifm(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->IFM));
}

/**
  * @brief  Wake Up interrupt mask status.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_masked_it_wakeup(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->IFM, EXTI_IFM_WAKEUP) == (EXTI_IFM_WAKEUP));
}

/**
  * @brief  Low Power Detector (LVD) interrupt mask status.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_masked_it_low_power_detector(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->IFM, EXTI_IFM_LVD) == (EXTI_IFM_LVD));
}

/**
  * @brief  Comparator2 (CMP2) interrupt mask status.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_masked_it_comparator2(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->IFM, EXTI_IFM_CMP2) == (EXTI_IFM_CMP2));
}

/**
  * @brief  Comparator1 (CMP1) interrupt mask status.
  * @param  exti EXTI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_masked_it_comparator1(EXTI_TypeDef *exti)
{
    return (READ_BIT(exti->IFM, EXTI_IFM_CMP1) == (EXTI_IFM_CMP1));
}

/**
  * @brief  GPIOy interrupt. (y=0...15) Interrupt mask status.
  * @param  exti EXTI Instance
  * @param  gpioy(gpio0~gpio15) The value Read in EXTI->IFM
            @arg @ref MD_EXTI_EVENT_GPIO0
            @arg @ref MD_EXTI_EVENT_GPIO1
            @arg @ref MD_EXTI_EVENT_GPIO2
            @arg @ref MD_EXTI_EVENT_GPIO3
            @arg @ref MD_EXTI_EVENT_GPIO4
            @arg @ref MD_EXTI_EVENT_GPIO5
            @arg @ref MD_EXTI_EVENT_GPIO6
            @arg @ref MD_EXTI_EVENT_GPIO7
            @arg @ref MD_EXTI_EVENT_GPIO8
            @arg @ref MD_EXTI_EVENT_GPIO9
            @arg @ref MD_EXTI_EVENT_GPIO10
            @arg @ref MD_EXTI_EVENT_GPIO11
            @arg @ref MD_EXTI_EVENT_GPIO12
            @arg @ref MD_EXTI_EVENT_GPIO13
            @arg @ref MD_EXTI_EVENT_GPIO14
            @arg @ref MD_EXTI_EVENT_GPIO15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_exti_is_masked_it_gpio_pin(EXTI_TypeDef *exti, uint32_t gpioy)
{
    return (READ_BIT(exti->IFM, gpioy) == gpioy);
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group7 ICR
  * @{
  */
/**
  * @brief  Interrupt Clear on line
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->ICR
  * @retval None
  */
__STATIC_INLINE void md_exti_set_icr(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->ICR, value);
}

/**
  * @brief  Clear the Wake Up interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_clear_it_wakeup(EXTI_TypeDef *exti)
{
    SET_BIT(exti->ICR, EXTI_ICR_WAKEUP);
}

/**
  * @brief  Clear the Low Power Detector (LVD) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_clear_it_low_power_detector(EXTI_TypeDef *exti)
{
    SET_BIT(exti->ICR, EXTI_ICR_LVD);
}

/**
  * @brief  Clear the Comparator2 (CMP2) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_clear_it_comparator2(EXTI_TypeDef *exti)
{
    SET_BIT(exti->ICR, EXTI_ICR_CMP2);
}

/**
  * @brief  Clear the Comparator1 (CMP1) interrupt.
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE void md_exti_clear_it_comparator1(EXTI_TypeDef *exti)
{
    SET_BIT(exti->ICR, EXTI_ICR_CMP1);
}

/**
  * @brief  Clear the GPIOy interrupt. (y=0...15).
  * @param  exti EXTI Instance
  * @param  gpioy(gpio0~gpio15) The value write in EXTI->ICR
            @arg @ref MD_EXTI_EVENT_GPIO0
            @arg @ref MD_EXTI_EVENT_GPIO1
            @arg @ref MD_EXTI_EVENT_GPIO2
            @arg @ref MD_EXTI_EVENT_GPIO3
            @arg @ref MD_EXTI_EVENT_GPIO4
            @arg @ref MD_EXTI_EVENT_GPIO5
            @arg @ref MD_EXTI_EVENT_GPIO6
            @arg @ref MD_EXTI_EVENT_GPIO7
            @arg @ref MD_EXTI_EVENT_GPIO8
            @arg @ref MD_EXTI_EVENT_GPIO9
            @arg @ref MD_EXTI_EVENT_GPIO10
            @arg @ref MD_EXTI_EVENT_GPIO11
            @arg @ref MD_EXTI_EVENT_GPIO12
            @arg @ref MD_EXTI_EVENT_GPIO13
            @arg @ref MD_EXTI_EVENT_GPIO14
            @arg @ref MD_EXTI_EVENT_GPIO15
  * @retval None
  */
__STATIC_INLINE void md_exti_clear_it_gpio_pin(EXTI_TypeDef *exti, uint32_t gpioy)
{
    SET_BIT(exti->ICR, gpioy);
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group8 RTS
  * @{
  */
/**
 * @brief  Set rising trigger event configuration bit of line
 * @param  exti EXTI Instance
 * @param  value The value write in EXTI->RTS
 * @retval None
 */
__STATIC_INLINE void md_exti_set_rts(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->RTS, value);
}

/**
  * @brief  Get rising trigger event configuration bit of line
  * @param  exti EXTI Instance
  * @retval EXTI->RTS value
  */
__STATIC_INLINE uint32_t md_exti_get_rts(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->RTS));
}

/**
 * @brief  Enable RTSy: Rising edge trigger event configuration. (y=0...21).
 * @param  exti EXTI Instance
 * @param  rtsy The value write in EXTI->RTS
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
 * @retval None
 */
__STATIC_INLINE void md_exti_enable_rising_edge_trigger(EXTI_TypeDef *exti, uint32_t rtsy)
{
    SET_BIT(exti->RTS, rtsy);
}

/**
 * @brief  Disable RTSy: Rising edge trigger event configuration. (y=0...21).
 * @param  exti EXTI Instance
 * @param  rtsy The value write in EXTI->RTS
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
 * @retval None
 */
__STATIC_INLINE void md_exti_disable_rising_edge_trigger(EXTI_TypeDef *exti, uint32_t rtsy)
{
    CLEAR_BIT(exti->RTS, rtsy);
}

/**
 * @brief  Is enabled RTSy: Rising edge trigger event configuration. (y=0...21).
 * @param  exti EXTI Instance
 * @param  rtsy The value write in EXTI->RTS
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
  * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t md_exti_is_enabled_rising_edge_trigger(EXTI_TypeDef *exti, uint32_t rtsy)
{
    return ((READ_BIT(exti->RTS, rtsy) == (rtsy)));
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group9 FTS
  * @{
  */
/**
  * @brief  Set falling trigger event configuration bit of line
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->FTS
  * @retval None
  */
__STATIC_INLINE void md_exti_set_fts(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->FTS, value);
}

/**
  * @brief  Get falling trigger event configuration bit of line
  * @param  exti EXTI Instance
  * @retval EXTI->FTS Value
  */
__STATIC_INLINE uint32_t md_exti_get_fts(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->FTS));
}

/**
 * @brief  Enable FTSy: Falling edge trigger event configuration. (y=0...21).
 * @param  exti EXTI Instance
 * @param  ftsy The value write in EXTI->FTS
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
 * @retval None
 */
__STATIC_INLINE void md_exti_enable_falling_edge_trigger(EXTI_TypeDef *exti, uint32_t ftsy)
{
    SET_BIT(exti->FTS, ftsy);
}

/**
 * @brief  Disable FTSy: Falling edge trigger event configuration. (y=0...21).
 * @param  exti EXTI Instance
 * @param  ftsy The value write in EXTI->RTS
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
 * @retval None
 */
__STATIC_INLINE void md_exti_disable_falling_edge_trigger(EXTI_TypeDef *exti, uint32_t ftsy)
{
    CLEAR_BIT(exti->FTS, ftsy);
}

/**
 * @brief  Is enabled FTSy: Falling edge trigger event configuration. (y=0...21).
 * @param  exti EXTI Instance
 * @param  ftsy The value write in EXTI->RTS
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
  * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t md_exti_is_enabled_falling_edge_trigger(EXTI_TypeDef *exti, uint32_t ftsy)
{
    return ((READ_BIT(exti->FTS, ftsy) == (ftsy)));
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group10 SWI
  * @{
  */
/**
  * @brief  Set software interrupt on line
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->SWI
  * @retval None
  */
__STATIC_INLINE void md_exti_set_swi(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->SWI, value);
}

/**
  * @brief  Get software interrupt on line
  * @param  exti EXTI Instance
  * @retval EXTI->SWI Value
  */
__STATIC_INLINE uint32_t md_exti_get_swi(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->SWI));
}

/**
 * @brief  Enable SWIy: Software interruption. (y=0...21).
 * @param  exti EXTI Instance
 * @param  swiy The value write in EXTI->SWI
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
 * @retval None
 */
__STATIC_INLINE void md_exti_enable_software_interrupt(EXTI_TypeDef *exti, uint32_t swiy)
{
    SET_BIT(exti->SWI, swiy);
}

/**
 * @brief  Disable SWIy: Software interruption. (y=0...21).
 * @param  exti EXTI Instance
 * @param  swiy The value write in EXTI->SWI
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
 * @retval None
 */
__STATIC_INLINE void md_exti_disable_software_interrupt(EXTI_TypeDef *exti, uint32_t swiy)
{
    CLEAR_BIT(exti->SWI, swiy);
}

/**
 * @brief  Is enabled SWIy: Software interruption. (y=0...21).
 * @param  exti EXTI Instance
 * @param  swiy The value write in EXTI->SWI
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
  * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t md_exti_is_enabled_software_interrupt(EXTI_TypeDef *exti, uint32_t swiy)
{
    return ((READ_BIT(exti->SWI, swiy) == (swiy)));
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group11 ADTE1
  * @{
  */
/**
  * @brief  Set ADC trigger on line
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->ADTE1
  * @retval None
  */
__STATIC_INLINE void md_exti_set_adte1(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->ADTE1, value);
}

/**
  * @brief  Get ADC trigger on line
  * @param  exti EXTI Instance
  * @retval EXTI->ADTE1 Value
  */
__STATIC_INLINE uint32_t md_exti_get_adte1(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->ADTE1));
}

/**
  * @brief  enable ADTEy: ADC trigger is enabled. (y=0...17).
  * @param  exti EXTI Instance
  * @param  adtey The value write in EXTI->ADTE1
         @arg @ref (MD_EXTI_EVENT_GPIO0 | MD_EXTI_EVENT_GPIO1 | MD_EXTI_EVENT_GPIO2 | MD_EXTI_EVENT_GPIO3 |
                    MD_EXTI_EVENT_GPIO4 | MD_EXTI_EVENT_GPIO5 | MD_EXTI_EVENT_GPIO6 | MD_EXTI_EVENT_GPIO7 |
                    MD_EXTI_EVENT_GPIO8 | MD_EXTI_EVENT_GPIO9 | MD_EXTI_EVENT_GPIO10 | MD_EXTI_EVENT_GPIO11 |
                    MD_EXTI_EVENT_GPIO12 | MD_EXTI_EVENT_GPIO13 | MD_EXTI_EVENT_GPIO14 | MD_EXTI_EVENT_GPIO15 |
                    MD_EXTI_EVENT_CMP1 | MD_EXTI_EVENT_CMP2)
  * @retval None
  */
__STATIC_INLINE void md_exti_enable_adc_trigger_source_1(EXTI_TypeDef *exti, uint32_t adtey)
{
    SET_BIT(exti->ADTE1, adtey);
}

/**
  * @brief  disable ADTEy: ADC trigger is disabled. (y=0...17).
  * @param  exti EXTI Instance
  * @param  adtey The value write in EXTI->ADTE1
         @arg @ref (MD_EXTI_EVENT_GPIO0 | MD_EXTI_EVENT_GPIO1 | MD_EXTI_EVENT_GPIO2 | MD_EXTI_EVENT_GPIO3 |
                    MD_EXTI_EVENT_GPIO4 | MD_EXTI_EVENT_GPIO5 | MD_EXTI_EVENT_GPIO6 | MD_EXTI_EVENT_GPIO7 |
                    MD_EXTI_EVENT_GPIO8 | MD_EXTI_EVENT_GPIO9 | MD_EXTI_EVENT_GPIO10 | MD_EXTI_EVENT_GPIO11 |
                    MD_EXTI_EVENT_GPIO12 | MD_EXTI_EVENT_GPIO13 | MD_EXTI_EVENT_GPIO14 | MD_EXTI_EVENT_GPIO15 |
                    MD_EXTI_EVENT_CMP1 | MD_EXTI_EVENT_CMP2)
  * @retval None
  */
__STATIC_INLINE void md_exti_disable_adc_trigger_source_1(EXTI_TypeDef *exti, uint32_t adtey)
{
    CLEAR_BIT(exti->ADTE1, adtey);
}

/**
  * @brief  Get ADTEy: ADC trigger is enabled. (y=0...17).
  * @param  exti EXTI Instance
  * @retval adc trigger source
  */
__STATIC_INLINE uint32_t md_exti_is_enabled_adc_trigger_source_1(EXTI_TypeDef *exti, uint32_t adtey)
{
    return (uint32_t)((bool)(READ_BIT(exti->ADTE1, adtey)));
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group12 ADTE2
  * @{
  */
/**
  * @brief  Set ADC trigger on line
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->ADTE2
  * @retval None
  */
__STATIC_INLINE void md_exti_set_adte2(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->ADTE2, value);
}

/**
  * @brief  Get ADC trigger on line
  * @param  exti EXTI Instance
  * @retval EXTI->ADTE2 Value
  */
__STATIC_INLINE uint32_t md_exti_get_adte2(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->ADTE2));
}

/**
  * @brief  Enable ADTEy: ADC trigger is enabled. (y=0...17).
  * @param  exti EXTI Instance
  * @param  adtey The value write in EXTI->ADTE1
         @arg @ref (MD_EXTI_EVENT_GPIO0 | MD_EXTI_EVENT_GPIO1 | MD_EXTI_EVENT_GPIO2 | MD_EXTI_EVENT_GPIO3 |
                    MD_EXTI_EVENT_GPIO4 | MD_EXTI_EVENT_GPIO5 | MD_EXTI_EVENT_GPIO6 | MD_EXTI_EVENT_GPIO7 |
                    MD_EXTI_EVENT_GPIO8 | MD_EXTI_EVENT_GPIO9 | MD_EXTI_EVENT_GPIO10 | MD_EXTI_EVENT_GPIO11 |
                    MD_EXTI_EVENT_GPIO12 | MD_EXTI_EVENT_GPIO13 | MD_EXTI_EVENT_GPIO14 | MD_EXTI_EVENT_GPIO15 |
                    MD_EXTI_EVENT_CMP1 | MD_EXTI_EVENT_CMP2)
  * @retval None
  */
__STATIC_INLINE void md_exti_enable_adc_trigger_source_2(EXTI_TypeDef *exti, uint32_t adtey)
{
    SET_BIT(exti->ADTE2, adtey);
}

/**
  * @brief  Disable ADTEy: ADC trigger is disabled. (y=0...17).
  * @param  exti EXTI Instance
  * @param  adtey The value write in EXTI->ADTE1
         @arg @ref (MD_EXTI_EVENT_GPIO0 | MD_EXTI_EVENT_GPIO1 | MD_EXTI_EVENT_GPIO2 | MD_EXTI_EVENT_GPIO3 |
                    MD_EXTI_EVENT_GPIO4 | MD_EXTI_EVENT_GPIO5 | MD_EXTI_EVENT_GPIO6 | MD_EXTI_EVENT_GPIO7 |
                    MD_EXTI_EVENT_GPIO8 | MD_EXTI_EVENT_GPIO9 | MD_EXTI_EVENT_GPIO10 | MD_EXTI_EVENT_GPIO11 |
                    MD_EXTI_EVENT_GPIO12 | MD_EXTI_EVENT_GPIO13 | MD_EXTI_EVENT_GPIO14 | MD_EXTI_EVENT_GPIO15 |
                    MD_EXTI_EVENT_CMP1 | MD_EXTI_EVENT_CMP2)
  * @retval None
  */
__STATIC_INLINE void md_exti_disable_adc_trigger_source_2(EXTI_TypeDef *exti, uint32_t adtey)
{
    CLEAR_BIT(exti->ADTE2, adtey);
}

/**
  * @brief  Get ADTEy: ADC trigger is enabled. (y=0...17).
  * @param  exti EXTI Instance
   * @retval adc trigger source
  */
__STATIC_INLINE uint32_t md_exti_is_enabled_adc_trigger_source_2(EXTI_TypeDef *exti, uint32_t adtey)
{
    return (uint32_t)((bool)(READ_BIT(exti->ADTE2, adtey)));
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group13 DB
  * @{
  */
/**
  * @brief  Set debounce enable bit of line
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->DB
  * @retval None
  */
__STATIC_INLINE void md_exti_set_db(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->DB, value);
}

/**
  * @brief  Get debounce enable bit of line
  * @param  exti EXTI Instance
  * @retval EXTI->DB Value
  */
__STATIC_INLINE uint32_t md_exti_get_db(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->DB));
}

/**
 * @brief  Enable DBENy: Bounce elimination function switch. (y=0...21).
 * @param  exti EXTI Instance
 * @param  dbeny The value write in EXTI->DB
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
 * @retval None
 */
__STATIC_INLINE void md_exti_enable_debounce(EXTI_TypeDef *exti, uint32_t dbeny)
{
    SET_BIT(exti->DB, dbeny);
}

/**
 * @brief  disable DBENy: Bounce elimination function switch. (y=0...21).
 * @param  exti EXTI Instance
 * @param  dbeny The value write in EXTI->DB
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
 * @retval None
 */
__STATIC_INLINE void md_exti_disable_debounce(EXTI_TypeDef *exti, uint32_t dbeny)
{
    CLEAR_BIT(exti->DB, dbeny);
}

/**
 * @brief  Enabled DBENy: Bounce elimination function switch. (y=0...21).
 * @param  exti EXTI Instance
 * @param  dbeny The value write in EXTI->DB
         @arg @ref  MD_EXTI_EVENT_GPIO0
         @arg @ref  MD_EXTI_EVENT_GPIO1
         @arg @ref  MD_EXTI_EVENT_GPIO2
         @arg @ref  MD_EXTI_EVENT_GPIO3
         @arg @ref  MD_EXTI_EVENT_GPIO4
         @arg @ref  MD_EXTI_EVENT_GPIO5
         @arg @ref  MD_EXTI_EVENT_GPIO6
         @arg @ref  MD_EXTI_EVENT_GPIO7
         @arg @ref  MD_EXTI_EVENT_GPIO8
         @arg @ref  MD_EXTI_EVENT_GPIO9
         @arg @ref  MD_EXTI_EVENT_GPIO10
         @arg @ref  MD_EXTI_EVENT_GPIO11
         @arg @ref  MD_EXTI_EVENT_GPIO12
         @arg @ref  MD_EXTI_EVENT_GPIO13
         @arg @ref  MD_EXTI_EVENT_GPIO14
         @arg @ref  MD_EXTI_EVENT_GPIO15
         @arg @ref  MD_EXTI_EVENT_CMP1
         @arg @ref  MD_EXTI_EVENT_CMP2
         @arg @ref  MD_EXTI_EVENT_LVD
         @arg @ref  MD_EXTI_EVENT_WAKEUP
  * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t md_exti_is_enabled_debounce(EXTI_TypeDef *exti, uint32_t dbeny)
{
    return ((READ_BIT(exti->DB, dbeny) == (dbeny)));
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group14 DBC
  * @{
  */
/**
  * @brief  Set Sampling Rate Control Register
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->DBC
  * @retval None
  */
__STATIC_INLINE void md_exti_set_dbc(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->DBC, value);
}

/**
  * @brief  Get Sampling Rate Control Register
  * @param  exti EXTI Instance
  * @retval EXTI->DBC Value
  */
__STATIC_INLINE uint32_t md_exti_get_dbc(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->DBC));
}

/**
  * @brief  Set Bounce elimination prescaler
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->DBC
  * @retval None
  */
__STATIC_INLINE void md_exti_set_debounce_prescaler(EXTI_TypeDef *exti, uint32_t value)
{
    MODIFY_REG(exti->DBC, EXTI_DBC_DBPRE_MSK, value << EXTI_DBC_DBPRE_POSS);
}

/**
  * @brief  Get Bounce elimination prescaler
  * @param  exti EXTI Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_exti_get_debounce_prescaler(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_BIT(exti->DBC, EXTI_DBC_DBPRE_MSK) >> EXTI_DBC_DBPRE_POSS);
}

/**
  * @brief  Set Bounce elimination counter
  * @param  exti EXTI Instance
  * @param  dbcnt The value write in EXTI->DBC
            @arg @ref MD_EXTI_DEBOUNCECOUNT_IMMEDIATELY
            @arg @ref MD_EXTI_DEBOUNCECOUNT_2_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_3_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_4_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_5_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_6_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_7_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_8_TIMES
  * @retval None
  */
__STATIC_INLINE void md_exti_set_debounce_count(EXTI_TypeDef *exti, uint32_t dbcnt)
{
    MODIFY_REG(exti->DBC, EXTI_DBC_DBCNT_MSK, dbcnt << EXTI_DBC_DBCNT_POSS);
}

/**
  * @brief  Get Bounce elimination counter
  * @param  exti EXTI Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_EXTI_DEBOUNCECOUNT_IMMEDIATELY
            @arg @ref MD_EXTI_DEBOUNCECOUNT_2_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_3_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_4_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_5_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_6_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_7_TIMES
            @arg @ref MD_EXTI_DEBOUNCECOUNT_8_TIMES
  */
__STATIC_INLINE uint32_t md_exti_get_debounce_count(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_BIT(exti->DBC, EXTI_DBC_DBCNT_MSK) >> EXTI_DBC_DBCNT_POSS);
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group15 ICFG1
  * @{
  */
/**
  * @brief  Set EXTI interrupt configuration register 1
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->ICFG1
  * @retval None
  */
__STATIC_INLINE void md_exti_set_icfg1(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->ICFG1, value);
}

/**
  * @brief  Get EXTI interrupt configuration register 1
  * @param  exti EXTI Instance
  * @retval EXTI->ICFG1 Value
  */
__STATIC_INLINE uint32_t md_exti_get_icfg1(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->ICFG1));
}

/**
  * @brief  Set EXTI interrupt configuration register 1
  * @param  exti EXTI Instance
  * @param  extiy The value write in EXTI->ICFG1
            @arg @ref MD_EXTI_GPIOA0 | MD_EXTI_GPIOA1 | MD_EXTI_GPIOA2 | MD_EXTI_GPIOA3 |
                      MD_EXTI_GPIOA4 | MD_EXTI_GPIOA5 | MD_EXTI_GPIOA6 | MD_EXTI_GPIOA7)

            @arg @ref MD_EXTI_GPIOB0 | MD_EXTI_GPIOB1 | MD_EXTI_GPIOB2 | MD_EXTI_GPIOB3 |
                      MD_EXTI_GPIOB4 | MD_EXTI_GPIOB5 | MD_EXTI_GPIOB6 | MD_EXTI_GPIOB7)

            @arg @ref MD_EXTI_GPIOC0 | MD_EXTI_GPIOC1 | MD_EXTI_GPIOC2 | MD_EXTI_GPIOC3 |
                      MD_EXTI_GPIOC4 | MD_EXTI_GPIOC5 | MD_EXTI_GPIOC6 | MD_EXTI_GPIOC7)

            @arg @ref MD_EXTI_GPIOD0 | MD_EXTI_GPIOD1 | MD_EXTI_GPIOD2 | MD_EXTI_GPIOD3 |
                      MD_EXTI_GPIOD4 | MD_EXTI_GPIOD5 | MD_EXTI_GPIOD6 | MD_EXTI_GPIOD7)
  * @retval None
  */
__STATIC_INLINE void md_exti_set_interrupt_pin_0_7(EXTI_TypeDef *exti, uint32_t extiy)
{
    MODIFY_REG(exti->ICFG1, EXTI_ICFG1_EXTIy, extiy);
}

/**
  * @brief  Get EXTI interrupt configuration register 1
  * @param  exti EXTI Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_EXTI_GPIOA0
            @arg @ref MD_EXTI_GPIOA1
            @arg @ref MD_EXTI_GPIOA2
            @arg @ref MD_EXTI_GPIOA3
            @arg @ref MD_EXTI_GPIOA4
            @arg @ref MD_EXTI_GPIOA5
            @arg @ref MD_EXTI_GPIOA6
            @arg @ref MD_EXTI_GPIOA7

            @arg @ref MD_EXTI_GPIOB0
            @arg @ref MD_EXTI_GPIOB1
            @arg @ref MD_EXTI_GPIOB2
            @arg @ref MD_EXTI_GPIOB3
            @arg @ref MD_EXTI_GPIOB4
            @arg @ref MD_EXTI_GPIOB5
            @arg @ref MD_EXTI_GPIOB6
            @arg @ref MD_EXTI_GPIOB7

            @arg @ref MD_EXTI_GPIOC0
            @arg @ref MD_EXTI_GPIOC1
            @arg @ref MD_EXTI_GPIOC2
            @arg @ref MD_EXTI_GPIOC3
            @arg @ref MD_EXTI_GPIOC4
            @arg @ref MD_EXTI_GPIOC5
            @arg @ref MD_EXTI_GPIOC6
            @arg @ref MD_EXTI_GPIOC7

            @arg @ref MD_EXTI_GPIOD0
            @arg @ref MD_EXTI_GPIOD1
            @arg @ref MD_EXTI_GPIOD2
            @arg @ref MD_EXTI_GPIOD3
            @arg @ref MD_EXTI_GPIOD4
            @arg @ref MD_EXTI_GPIOD5
            @arg @ref MD_EXTI_GPIOD6
            @arg @ref MD_EXTI_GPIOD7
  */
__STATIC_INLINE uint32_t md_exti_get_interrupt_pin_0_7(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_BIT(exti->ICFG1, EXTI_ICFG1_EXTIy));
}
/**
  * @}
  */

/** @defgroup MD_EXTI_Public_Functions_Group16 ICFG2
  * @{
  */
/**
  * @brief  Set EXTI interrupt configuration register 2
  * @param  exti EXTI Instance
  * @param  value The value write in EXTI->ICFG2
  * @retval None
  */
__STATIC_INLINE void md_exti_set_icfg2(EXTI_TypeDef *exti, uint32_t value)
{
    WRITE_REG(exti->ICFG2, value);
}

/**
  * @brief  Get EXTI interrupt configuration register 2
  * @param  exti EXTI Instance
  * @retval EXTI->ICFG2 Value
  */
__STATIC_INLINE uint32_t md_exti_get_icfg2(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_REG(exti->ICFG2));
}

/**
  * @brief  Set EXTI interrupt configuration register 2
  * @param  exti EXTI Instance
  * @param  extiy The value write in EXTI->ICFG1
            @arg @ref MD_EXTI_GPIOA8 | MD_EXTI_GPIOA9 | MD_EXTI_GPIOA10 | MD_EXTI_GPIOA11 |
                      MD_EXTI_GPIOA12 | MD_EXTI_GPIOA13 | MD_EXTI_GPIOA14 | MD_EXTI_GPIOA15)

            @arg @ref MD_EXTI_GPIOB8 | MD_EXTI_GPIOB9 | MD_EXTI_GPIOB10 | MD_EXTI_GPIOB11 |
                      MD_EXTI_GPIOB12 | MD_EXTI_GPIOB13 | MD_EXTI_GPIOB14 | MD_EXTI_GPIOB15)

            @arg @ref MD_EXTI_GPIOC8 | MD_EXTI_GPIOC9 | MD_EXTI_GPIOC10 | MD_EXTI_GPIOC11 |
                      MD_EXTI_GPIOC12 | MD_EXTI_GPIOC13 | MD_EXTI_GPIOC14 | MD_EXTI_GPIOC15)

            @arg @ref MD_EXTI_GPIOD8 | MD_EXTI_GPIOD9 | MD_EXTI_GPIOD10 | MD_EXTI_GPIOD11 |
                      MD_EXTI_GPIOD12 | MD_EXTI_GPIOD13 | MD_EXTI_GPIOD14 | MD_EXTI_GPIOD15)
  * @retval None
  */
__STATIC_INLINE void md_exti_set_interrupt_pin_8_15(EXTI_TypeDef *exti, uint32_t extiy)
{
    MODIFY_REG(exti->ICFG2, EXTI_ICFG2_EXTIy, extiy);
}

/**
  * @brief  Get EXTI interrupt configuration register 2
  * @param  exti EXTI Instance
  * @retval None
            @arg @ref MD_EXTI_GPIOA8
            @arg @ref MD_EXTI_GPIOA9
            @arg @ref MD_EXTI_GPIOA10
            @arg @ref MD_EXTI_GPIOA11
            @arg @ref MD_EXTI_GPIOA12
            @arg @ref MD_EXTI_GPIOA13
            @arg @ref MD_EXTI_GPIOA14
            @arg @ref MD_EXTI_GPIOA15

            @arg @ref MD_EXTI_GPIOB8
            @arg @ref MD_EXTI_GPIOB9
            @arg @ref MD_EXTI_GPIOB10
            @arg @ref MD_EXTI_GPIOB11
            @arg @ref MD_EXTI_GPIOB12
            @arg @ref MD_EXTI_GPIOB13
            @arg @ref MD_EXTI_GPIOB14
            @arg @ref MD_EXTI_GPIOB15

            @arg @ref MD_EXTI_GPIOC8
            @arg @ref MD_EXTI_GPIOC9
            @arg @ref MD_EXTI_GPIOC10
            @arg @ref MD_EXTI_GPIOC11
            @arg @ref MD_EXTI_GPIOC12
            @arg @ref MD_EXTI_GPIOC13
            @arg @ref MD_EXTI_GPIOC14
            @arg @ref MD_EXTI_GPIOC15

            @arg @ref MD_EXTI_GPIOD8
            @arg @ref MD_EXTI_GPIOD9
            @arg @ref MD_EXTI_GPIOD10
            @arg @ref MD_EXTI_GPIOD11
            @arg @ref MD_EXTI_GPIOD12
            @arg @ref MD_EXTI_GPIOD13
            @arg @ref MD_EXTI_GPIOD14
            @arg @ref MD_EXTI_GPIOD15
  */
__STATIC_INLINE uint32_t md_exti_get_interrupt_pin_8_15(EXTI_TypeDef *exti)
{
    return (uint32_t)(READ_BIT(exti->ICFG2, EXTI_ICFG2_EXTIy));
}
/**
  * @}
  */

///**
//  * @brief  Set EXTI interrupt configuration register 2
//  * @param  exti EXTI Instance
//  * @param  port  The value write in EXTI->ICFG1
//            @arg @ref MD_EXTI_PORT_GPIOA
//            @arg @ref MD_EXTI_PORT_GPIOB
//            @arg @ref MD_EXTI_PORT_GPIOC
//            @arg @ref MD_EXTI_PORT_GPIOD
//  * @param  extiy The value write in EXTI->ICFG1
//            @arg @ref MD_EXTI_GPIO0
//            @arg @ref MD_EXTI_GPIO1
//            @arg @ref MD_EXTI_GPIO2
//            @arg @ref MD_EXTI_GPIO3
//            @arg @ref MD_EXTI_GPIO4
//            @arg @ref MD_EXTI_GPIO5
//            @arg @ref MD_EXTI_GPIO6
//            @arg @ref MD_EXTI_GPIO7
//            @arg @ref MD_EXTI_GPIO8
//            @arg @ref MD_EXTI_GPIO9
//            @arg @ref MD_EXTI_GPIO10
//            @arg @ref MD_EXTI_GPIO11
//            @arg @ref MD_EXTI_GPIO12
//            @arg @ref MD_EXTI_GPIO13
//            @arg @ref MD_EXTI_GPIO14
//            @arg @ref MD_EXTI_GPIO15
//  * @retval None
//  */
//__STATIC_INLINE void md_exti_set_interrupt_source(EXTI_TypeDef *exti, uint32_t port, uint32_t extiy)
//{
//  if((extiy >> 8) == 0)
//    MODIFY_REG(exti->ICFG1, EXTI_ICFG1_EXTIy, port << extiy);
//  else
//    MODIFY_REG(exti->ICFG2, EXTI_ICFG2_EXTIy, port << extiy);
//}

///**
//  * @brief  Get EXTI interrupt configuration register 2
//  * @param  exti EXTI Instance
//  * @retval None
//            @arg @ref MD_EXTI_GPIOA8
//            @arg @ref MD_EXTI_GPIOA9
//            @arg @ref MD_EXTI_GPIOA10
//            @arg @ref MD_EXTI_GPIOA11
//            @arg @ref MD_EXTI_GPIOA12
//            @arg @ref MD_EXTI_GPIOA13
//            @arg @ref MD_EXTI_GPIOA14
//            @arg @ref MD_EXTI_GPIOA15

//            @arg @ref MD_EXTI_GPIOB8
//            @arg @ref MD_EXTI_GPIOB9
//            @arg @ref MD_EXTI_GPIOB10
//            @arg @ref MD_EXTI_GPIOB11
//            @arg @ref MD_EXTI_GPIOB12
//            @arg @ref MD_EXTI_GPIOB13
//            @arg @ref MD_EXTI_GPIOB14
//            @arg @ref MD_EXTI_GPIOB15

//            @arg @ref MD_EXTI_GPIOC8
//            @arg @ref MD_EXTI_GPIOC9
//            @arg @ref MD_EXTI_GPIOC10
//            @arg @ref MD_EXTI_GPIOC11
//            @arg @ref MD_EXTI_GPIOC12
//            @arg @ref MD_EXTI_GPIOC13
//            @arg @ref MD_EXTI_GPIOC14
//            @arg @ref MD_EXTI_GPIOC15

//            @arg @ref MD_EXTI_GPIOD8
//            @arg @ref MD_EXTI_GPIOD9
//            @arg @ref MD_EXTI_GPIOD10
//            @arg @ref MD_EXTI_GPIOD11
//            @arg @ref MD_EXTI_GPIOD12
//            @arg @ref MD_EXTI_GPIOD13
//            @arg @ref MD_EXTI_GPIOD14
//            @arg @ref MD_EXTI_GPIOD15
//  */
//__STATIC_INLINE uint32_t md_exti_get_interrupt_source(EXTI_TypeDef *exti, uint32_t extiy)
//{
//  if((extiy>>8) == 0)
//    return (uint32_t)(READ_BIT(exti->ICFG1, extiy));
//  else
//    return (uint32_t)(READ_BIT(exti->ICFG2, extiy));
//}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}  Micro_Driver
  */

#ifdef __cplusplus
}
#endif
#endif


/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

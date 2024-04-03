/**********************************************************************************
 *
 * @file    md_gpio.h
 * @brief   header file of md_gpio.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
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
#ifndef __MD_GPIO_H__
#define __MD_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_GPIO GPIO
  * @brief GPIO micro driver
  * @{
  */

/** @defgroup MD_GPIO_Pubulic_Types GPIO Pubulic Types
  * @{
  */

/**
  * @brief MD GPIO Init Structure definition
  */
typedef struct
{
    uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                              This parameter can be any value of @ref MD_GPIO_PC_PIN */

    uint32_t Mode;         /*!< Specifies the operating mode for the selected pins.
                              This parameter can be a value of @ref MD_GPIO_PC_MODE.

                              GPIO HW configuration can be modified afterwards using unitary function @ref md_gpio_set_mode().*/

    uint32_t OutputType;   /*!< Specifies the operating output type for the selected pins.
                              This parameter can be a value of @ref MD_GPIO_PC_OT.

                              GPIO HW configuration can be modified afterwards using unitary function @ref md_gpio_set_output_type().*/


    uint32_t Pull;         /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                              This parameter can be a value of @ref MD_GPIO_PC_PULL.

                              GPIO HW configuration can be modified afterwards using unitary function @ref md_gpio_set_pull().*/

    uint32_t OutDrive;     /*!< Specifies the output driving current for the selected pins.
                              This parameter can be a value of @ref MD_GPIO_PC_DS.

                              GPIO HW configuration can be modified afterwards using unitary function @ref md_gpio_get_ds().*/

    uint32_t Function;     /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref MD_GPIO_PC_FUNCTION.

                              GPIO HW configuration can be modified afterwards using unitary function @ref md_gpio_set_function0_7() and md_gpio_set_function8_15().*/
} md_gpio_inittypedef;

/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Macros GPIO Public Macros
  * @{
  */

/**
  * @brief MD_GPIO_PIN Pin
  */
#define MD_GPIO_PIN_0                      (0x0001U)  /*!< Select pin 0 */
#define MD_GPIO_PIN_1                      (0x0002U)  /*!< Select pin 1 */
#define MD_GPIO_PIN_2                      (0x0004U)  /*!< Select pin 2 */
#define MD_GPIO_PIN_3                      (0x0008U)  /*!< Select pin 3 */
#define MD_GPIO_PIN_4                      (0x0010U)  /*!< Select pin 4 */
#define MD_GPIO_PIN_5                      (0x0020U)  /*!< Select pin 5 */
#define MD_GPIO_PIN_6                      (0x0040U)  /*!< Select pin 6 */
#define MD_GPIO_PIN_7                      (0x0080U)  /*!< Select pin 7 */
#define MD_GPIO_PIN_8                      (0x0100U)  /*!< Select pin 8 */
#define MD_GPIO_PIN_9                      (0x0200U)  /*!< Select pin 9 */
#define MD_GPIO_PIN_10                     (0x0400U) /*!< Select pin 10 */
#define MD_GPIO_PIN_11                     (0x0800U) /*!< Select pin 11 */
#define MD_GPIO_PIN_12                     (0x1000U) /*!< Select pin 12 */
#define MD_GPIO_PIN_13                     (0x2000U) /*!< Select pin 13 */
#define MD_GPIO_PIN_14                     (0x4000U) /*!< Select pin 14 */
#define MD_GPIO_PIN_15                     (0x8000U) /*!< Select pin 15 */
#define MD_GPIO_PIN_ALL                    (0xFFFFU) /*!< Select all pins */

/**
  * @brief MD_GPIO_LCK Lock
  */
#define MD_GPIO_UNLOCK                  (0x00000000UL)       /** @brief Select input mode */
#define MD_GPIO_LOCK                    (0X00000001UL)       /** @brief Select output mode */


/**
  * @brief MD_GPIO_MODE Mode
  */
#define MD_GPIO_MODE_INPUT                 (0x00000000UL)       /** @brief Select input mode */
#define MD_GPIO_MODE_OUTPUT                (0X00000001UL)       /** @brief Select output mode */
#define MD_GPIO_MODE_FUNCTION              (0X00000002UL)       /** @brief Select function mode */
#define MD_GPIO_MODE_ANALOG                (0x00000003UL)       /** @brief Select analog mode */

/**
  * @brief MD_GPIO_OT Output Type
  */
#define MD_GPIO_OUTPUT_PUSHPULL            (0x00000000U) /** @brief Select push-pull as output type */
#define MD_GPIO_OUTPUT_OPENDRAIN           (0x00000001U) /** @brief Select open-drain as output type */

/**
  * @brief MD_GPIO_PULL FLOATING/ Pull Up / Pull Down
  */
#define MD_GPIO_PULL_FLOATING              (0x00000000UL) /** @brief Select I/O no pull */
#define MD_GPIO_PULL_UP                    (0x00000001UL) /** @brief Select I/O pull up */
#define MD_GPIO_PULL_DOWN                  (0x00000002UL) /** @brief Select I/O pull down */

/**
  * @brief MD_GPIO_DS Output driving/sinking current
  */
#define MD_GPIO_DRIVING_16MA                    (0x00000001U) /** @brief Select I/O 16mA driving/sinking current */
#define MD_GPIO_DRIVING_8MA                     (0x00000000U) /** @brief Select I/O 8mA driving/sinking current */

/**
  * @brief MD_GPIO_FUNCTION Alternate Function
  */
#define MD_GPIO_AF0                       (0x00000000UL) /** @brief Select alternate function 0 */
#define MD_GPIO_AF1                       (0x00000001UL) /** @brief Select alternate function 1 */
#define MD_GPIO_AF2                       (0x00000002UL) /** @brief Select alternate function 2 */
#define MD_GPIO_AF3                       (0x00000003UL) /** @brief Select alternate function 3 */
#define MD_GPIO_AF4                       (0x00000004UL) /** @brief Select alternate function 4 */
#define MD_GPIO_AF5                       (0x00000005UL) /** @brief Select alternate function 5 */
#define MD_GPIO_AF6                       (0x00000006UL) /** @brief Select alternate function 6 */
#define MD_GPIO_AF7                       (0x00000007UL) /** @brief Select alternate function 7 */
#define MD_GPIO_AF8                       (0x00000008UL) /** @brief Select alternate function 8 */
#define MD_GPIO_AF9                       (0x00000009UL) /** @brief Select alternate function 9 */

/**
  * @brief MD_GPIO_FILTER Input Filter
  */
#define MD_GPIO_FILTER_BYPASS             (0x00000000UL) /** @brief Select bypass */
#define MD_GPIO_FILTER_GLITCH             (0x00000001UL) /** @brief Select glitch free for 20ns plus */

/**
  * @brief MD_GPIO_IST Input Type
  */
#define MD_GPIO_IST_TTL                   (0x00000000UL) /** @brief Select TTL IO Level */
#define MD_GPIO_IST_CMOS                  (0x00000001UL) /** @brief Select CMOS IO Level */

/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions GPIO Public Functions
  * @{
  */

/** @defgroup MD_GPIO_Public_Functions_Group2 ID
  * @{
  */
/**
  * @brief  Return full input data register value for a dedicated port.
  * @param  GPIOx GPIO Port
  * @retval Input data register value of port
  */
__STATIC_INLINE uint32_t md_gpio_get_inputport(GPIO_TypeDef *GPIOx)
{
    return (uint32_t)(READ_REG(GPIOx->ID));
}

/**
  * @brief  Return input pin data.
  * @param  GPIOx GPIO Port
  * @param  pin each pin of the port
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval Input pin data value of port
  *         @arg @ref 0 0r 1
  */

__STATIC_INLINE uint32_t md_gpio_get_inputpinset(GPIO_TypeDef *GPIOx, uint32_t pin)
{
    return (READ_BIT(GPIOx->ID, pin) == pin);
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group3 OD
  * @{
  */
/**
  * @brief  Write output data register for the port.
  * @param  GPIOx GPIO Port
  * @param  PortValue Level value for each pin of the port
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  *         @arg @ref MD_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_outputport(GPIO_TypeDef *GPIOx, uint32_t PortValue)
{
    WRITE_REG(GPIOx->OD, PortValue);
}

/**
  * @brief  Read output data register for the port.
  * @param  GPIOx GPIO Port
  * @retval Output data register value of port
  */
__STATIC_INLINE uint32_t md_gpio_get_outputport(GPIO_TypeDef *GPIOx)
{
    return (uint32_t)(READ_REG(GPIOx->OD));
}

/**
  * @brief  Set output pin data.
  * @param  GPIOx GPIO Port
  * @param  pin each pin of the port
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_outputpinset(GPIO_TypeDef *GPIOx, uint32_t pin)
{
    SET_BIT(GPIOx->OD, pin);
}

/**
  * @brief  Return output pin data.
  * @param  GPIOx GPIO Port
  * @param  pin each pin of the port
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval Input pin data value of port
  *         @arg @ref 0 0r 1
  */
__STATIC_INLINE uint32_t md_gpio_get_outputpinset(GPIO_TypeDef *GPIOx, uint32_t pin)
{
    return (READ_BIT(GPIOx->OD, pin) == pin);
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group4 BSBR
  * @{
  */
/**
  * @brief  Set several pins to high level on dedicated gpio port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  *         @arg @ref MD_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_high(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
    WRITE_REG(GPIOx->BSBR, PinMask);
}

/**
  * @brief  Reset several pins to low level on dedicated gpio port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  *         @arg @ref MD_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_low(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
    WRITE_REG(GPIOx->BSBR, (PinMask << 16));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group5 LCK
  * @{
  */
/**
  * @brief  Lock configuration of several pins for a dedicated port.
  * @note   When the lock sequence has been applied on a port bit, the
  *         value of this port bit can no longer be modified until the
  *         next reset.
  * @note   LOCK key write sequence:
  *         WR GPIOx_LCK = (~LCK[15:0]<<16) + LCK[15:0]
  *         WR GPIOx_LCK = (~LCK[15:0]<<16) + LCK[15:0]
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  *         @arg @ref MD_GPIO_PIN_ALL
  * @param  PinLock This parameter can be one of the following values:
  *         @arg @ref  MD_GPIO_UNLOCK
  *         @arg @ref  MD_GPIO_LOCK
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_lockpin(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t PinLock)
{
    WRITE_REG(GPIOx->LCK, ((~(GPIOx->LCK | PinLock << (POSITION_VAL(Pin))) << 16) | (GPIOx->LCK | PinLock << (POSITION_VAL(Pin)))));
    WRITE_REG(GPIOx->LCK, ((~(GPIOx->LCK | PinLock << (POSITION_VAL(Pin))) << 16) | (GPIOx->LCK | PinLock << (POSITION_VAL(Pin)))));
}

/**
  * @brief  Return 1 if all pins passed as parameter, of a dedicated port, are locked. else Return 0.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  *         @arg @ref MD_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_gpio_get_lockpin(GPIO_TypeDef *GPIOx, uint32_t PinLock)
{
    return ((READ_BIT(GPIOx->LCK, PinLock) == (PinLock)));
}

/**
  * @brief  Get Lock key is enabled
  * @param  GPIOx GPIO Port
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_gpio_is_enabled_anylockpin(GPIO_TypeDef *GPIOx)
{
    return ((READ_BIT(GPIOx->LCK, GPIO_LCK_LCKK) == (GPIO_LCK_LCKK)));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group6 MOD
  * @{
  */
/**
  * @brief  Configure gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Input mode, output mode, Alternate function mode, or Analog mode.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_MODE_INPUT
  *         @arg @ref MD_GPIO_MODE_OUTPUT
  *         @arg @ref MD_GPIO_MODE_FUNCTION
  *         @arg @ref MD_GPIO_MODE_ANALOG
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
    MODIFY_REG(GPIOx->MOD, (GPIO_MOD_MOD0  << (POSITION_VAL(Pin) * 2U)), (Mode << (POSITION_VAL(Pin) * 2U)));
}

/**
  * @brief  Return gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Input mode, output mode, Alternate function mode, or Analog mode.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_GPIO_MODE_INPUT
  *         @arg @ref MD_GPIO_MODE_OUTPUT
  *         @arg @ref MD_GPIO_MODE_FUNCTION
  *         @arg @ref MD_GPIO_MODE_ANALOG
  */
__STATIC_INLINE uint32_t md_gpio_get_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->MOD, (GPIO_MOD_MOD0  << (POSITION_VAL(Pin) * 2U))) >> (POSITION_VAL(Pin) * 2U));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group7 PUD
  * @{
  */
/**
  * @brief  Configure gpio pull-up or pull-down for a dedicated pin on a dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @param  Pull This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PULL_FLOATING
  *         @arg @ref MD_GPIO_PULL_UP
  *         @arg @ref MD_GPIO_PULL_DOWN
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_pull(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Pull)
{
    MODIFY_REG(GPIOx->PUD, (GPIO_PUD_PUD0  << (POSITION_VAL(Pin) * 2U)), (Pull << (POSITION_VAL(Pin) * 2U)));
}

/**
  * @brief  Return gpio pull-up or pull-down for a dedicated pin on a dedicated port
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_GPIO_PULL_FLOATING
  *         @arg @ref MD_GPIO_PULL_UP
  *         @arg @ref MD_GPIO_PULL_DOWN
  */
__STATIC_INLINE uint32_t md_gpio_get_pin_pull(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->PUD, (GPIO_PUD_PUD0  << (POSITION_VAL(Pin) * 2U))) >> (POSITION_VAL(Pin) * 2U));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group8 OT
  * @{
  */
/**
  * @brief  Configure gpio output type for several pins on dedicated port.
  * @note   Output type as to be set when gpio pin is in output or
  *         alternate modes. Possible type are Push-pull or Open-drain.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be a combination of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @param  OutputType This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref MD_GPIO_OUTPUT_OPENDRAIN
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_output_type(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t OutputType)
{
    MODIFY_REG(GPIOx->OT, (GPIO_OT_OT0  << (POSITION_VAL(Pin))), (OutputType << (POSITION_VAL(Pin))));
}

/**
  * @brief  Return gpio output type for several pins on dedicated port.
  * @note   Output type as to be set when gpio pin is in output or
  *         alternate modes. Possible type are Push-pull or Open-drain.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref MD_GPIO_OUTPUT_OPENDRAIN
  */
__STATIC_INLINE uint32_t md_gpio_get_pin_output_type(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    return (uint32_t)((READ_BIT(GPIOx->OT, (GPIO_OT_OT0 << (POSITION_VAL(Pin)))) >> (POSITION_VAL(Pin))) & (0x1U));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group9 DS
  * @{
  */
/**
  * @brief  Configure gpio output driving/sinking current a dedicated pin on a dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @param  Odrv This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_DRIVING_8MA
  *         @arg @ref MD_GPIO_DRIVING_16MA
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_outputdriving(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Odrv)
{
    MODIFY_REG(GPIOx->DS, (GPIO_DS_DS0  << (POSITION_VAL(Pin))), (Odrv << (POSITION_VAL(Pin))));
}

/**
  * @brief  Return gpio output driving/sinking current a dedicated pin on a dedicated port.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_GPIO_DRIVING_8MA
  *         @arg @ref MD_GPIO_DRIVING_16MA
  */
__STATIC_INLINE uint32_t md_gpio_get_pin_outputdriving(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->DS, (GPIO_DS_DS0  << (POSITION_VAL(Pin)))) >> (POSITION_VAL(Pin)));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group10 FIR
  * @{
  */
/**
  * @brief  Enable input filter register for the port.
  * @note   These bits are written by software to configure
  *         the input signal over thought a glitch filter.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  *         @arg @ref MD_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void md_gpio_enable_pin_filter(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    SET_BIT(GPIOx->FIR, Pin);
}


/**
  * @brief  Disable input filter register for the port.
  * @note   These bits are written by software to configure
  *         the input signal over thought a glitch filter.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  *         @arg @ref MD_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void md_gpio_disable_pin_filter(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    CLEAR_BIT(GPIOx->FIR, Pin);
}

/**
  * @brief  Check if input filter register for the port is enabled.
  * @note   These bits are written by software to configure
  *         the input signal over thought a glitch filter.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  *         @arg @ref MD_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE uint32_t md_gpio_is_enabled_pin_filter(GPIO_TypeDef *GPIOx, uint32_t Pin)
{

    return ((READ_BIT(GPIOx->FIR, Pin) == (Pin)));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group11 IST
  * @{
  */
/**
  * @brief  Set gpio Input Schmitt Trigger for GPIO_FIR register.
  * @param  GPIOx GPIO Port
  * @param  Pin_Ist This parameter sets the required pin Input Schmitt Trigger
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pinist(GPIO_TypeDef *GPIOx, uint32_t Pin_Ist)
{
    WRITE_REG(GPIOx->IST, Pin_Ist);
}

/**
  * @brief  Get gpio Input Schmitt Trigger for GPIO_OT register.
  * @param  GPIOx GPIO Port
  * @retval Return the Input Schmitt Trigger of each pin
  */
__STATIC_INLINE uint32_t md_gpio_get_pinist(GPIO_TypeDef *GPIOx)
{
    return (uint32_t)READ_REG(GPIOx->IST);
}

/**
  * @brief  Configure GPIOx port Input Schmitt Trigger Register.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @param  Iolev This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_IST_TTL
  *         @arg @ref MD_GPIO_IST_CMOS
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_type(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Iolev)
{
    MODIFY_REG(GPIOx->IST, (GPIO_IST_IST0  << (POSITION_VAL(Pin))), (Iolev << (POSITION_VAL(Pin))));
}

/**
  * @brief  Return GPIOx port Input Schmitt Trigger Register
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_GPIO_IST_TTL
  *         @arg @ref MD_GPIO_IST_CMOS
  */
__STATIC_INLINE uint32_t md_gpio_get_pin_type(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->IST, (GPIO_IST_IST0  << (POSITION_VAL(Pin)))) >> (POSITION_VAL(Pin)));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group12 AFL
  * @{
  */
/**
  * @brief  Configure gpio alternate function of a dedicated pin from 0 to 7 for a dedicated port.
  * @note   Possible values are from FUNCTION0 to FUNCTION7 depending on target.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  * @param  Function This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_AF0
  *         @arg @ref MD_GPIO_AF1
  *         @arg @ref MD_GPIO_AF2
  *         @arg @ref MD_GPIO_AF3
  *         @arg @ref MD_GPIO_AF4
  *         @arg @ref MD_GPIO_AF5
  *         @arg @ref MD_GPIO_AF6
  *         @arg @ref MD_GPIO_AF7
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_function0_7(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Function)
{
    MODIFY_REG(GPIOx->AFL, (GPIO_AFL_AF0  << (POSITION_VAL(Pin) * 4U)), (Function << (POSITION_VAL(Pin) * 4U)));
}

/**
  * @brief  Return gpio alternate function of a dedicated pin from 0 to 7 for a dedicated port.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_0
  *         @arg @ref MD_GPIO_PIN_1
  *         @arg @ref MD_GPIO_PIN_2
  *         @arg @ref MD_GPIO_PIN_3
  *         @arg @ref MD_GPIO_PIN_4
  *         @arg @ref MD_GPIO_PIN_5
  *         @arg @ref MD_GPIO_PIN_6
  *         @arg @ref MD_GPIO_PIN_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_GPIO_AF0
  *         @arg @ref MD_GPIO_AF1
  *         @arg @ref MD_GPIO_AF2
  *         @arg @ref MD_GPIO_AF3
  *         @arg @ref MD_GPIO_AF4
  *         @arg @ref MD_GPIO_AF5
  *         @arg @ref MD_GPIO_AF6
  *         @arg @ref MD_GPIO_AF7
  */
__STATIC_INLINE uint32_t md_gpio_get_pin_function0_7(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->AFL, (GPIO_AFL_AF0  << (POSITION_VAL(Pin) * 4U))) >> (POSITION_VAL(Pin) * 4U));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group13 AFH
  * @{
  */
/**
  * @brief  Configure gpio alternate function of a dedicated pin from 8 to 15 for a dedicated port.
  * @note   Possible values are from FUNCTION0 to FUNCTION7 depending on target.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @param  Function This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_AF0
  *         @arg @ref MD_GPIO_AF1
  *         @arg @ref MD_GPIO_AF2
  *         @arg @ref MD_GPIO_AF3
  *         @arg @ref MD_GPIO_AF4
  *         @arg @ref MD_GPIO_AF5
  *         @arg @ref MD_GPIO_AF6
  *         @arg @ref MD_GPIO_AF7
  * @retval None
  */
__STATIC_INLINE void md_gpio_set_pin_function8_15(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Function)
{
    MODIFY_REG(GPIOx->AFH, (GPIO_AFH_AF8  << (POSITION_VAL(Pin >> 8U) * 4U)), (Function << (POSITION_VAL(Pin >> 8U) * 4U)));
}

/**
  * @brief  Return gpio alternate function of a dedicated pin from 0 to 7 for a dedicated port.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref MD_GPIO_PIN_8
  *         @arg @ref MD_GPIO_PIN_9
  *         @arg @ref MD_GPIO_PIN_10
  *         @arg @ref MD_GPIO_PIN_11
  *         @arg @ref MD_GPIO_PIN_12
  *         @arg @ref MD_GPIO_PIN_13
  *         @arg @ref MD_GPIO_PIN_14
  *         @arg @ref MD_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref MD_GPIO_AF0
  *         @arg @ref MD_GPIO_AF1
  *         @arg @ref MD_GPIO_AF2
  *         @arg @ref MD_GPIO_AF3
  *         @arg @ref MD_GPIO_AF4
  *         @arg @ref MD_GPIO_AF5
  *         @arg @ref MD_GPIO_AF6
  *         @arg @ref MD_GPIO_AF7
  */
__STATIC_INLINE uint32_t md_gpio_get_pin_function8_15(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(GPIOx->AFH, (GPIO_AFH_AF8  << (POSITION_VAL(Pin >> 8U) * 4U))) >> (POSITION_VAL(Pin >> 8U) * 4U));
}
/**
  * @}
  */

/** @defgroup MD_GPIO_Public_Functions_Group1 Initialization
  * @{
  */
ErrorStatus md_gpio_deinit(GPIO_TypeDef *GPIOx);
ErrorStatus md_gpio_init(GPIO_TypeDef *GPIOx, md_gpio_inittypedef *GPIO_InitStruct);
void        md_gpio_struct_init(md_gpio_inittypedef *GPIO_InitStruct);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @} Micro_Driver
  */


#ifdef __cplusplus
}
#endif
#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

/**********************************************************************************
 *
 * @file    md_gpio.c
 * @brief   GPIO module driver.
 *
 * @date    13 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          13 Dec. 2022    Lisq            the first version
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

/* Includes ------------------------------------------------------------------ */
#include "md_gpio.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_GPIO
  * @{
  */

/** @addtogroup MD_GPIO_Public_Functions
  * @{
  */
/** @addtogroup MD_GPIO_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Initialize the GPIOx peripheral according to the specified
  *         parameters in the gpio_init_t.
  * @param  GPIOx: Where x can be (A--B) to select the GPIO peripheral.
  * @param  pin: The pin which need to initialize.
  * @param  init: Pointer to a md_gpio_init_t structure that can contains
  *         the configuration information for the specified parameters.
  * @retval None
  */
void md_gpio_init(GPIO_TypeDef *GPIOx, uint16_t pin, md_gpio_init_t *init)
{
    uint32_t i, pos, mask, tmp;

    for (i = 0; i < 16; ++i)
    {
        if (((pin >> i) & 0x1) == 0)
            continue;

        /* Get position and 1-bit mask */
        pos  = i;
        mask = 0x1 << pos;

        /* Set PIN filter enable or disable */
        tmp  = READ_REG(GPIOx->FLT);
        tmp &= ~mask;
        tmp |= (init->flt << pos);
        WRITE_REG(GPIOx->FLT, tmp);

        /* Set PIN type ttl or smit */
        tmp  = READ_REG(GPIOx->TYPE);
        tmp &= ~mask;
        tmp |= (init->type << pos);
        WRITE_REG(GPIOx->TYPE, tmp);

        /* Configure PIN function */
        pos  = i < 8 ? (i << 2) : ((i - 8) << 2);
        mask = 0xF << pos;
        tmp  = i < 8 ? READ_REG(GPIOx->FUNC0) : READ_REG(GPIOx->FUNC1);
        tmp &= ~mask;
        tmp |= (init->func << pos);
        i < 8 ? WRITE_REG(GPIOx->FUNC0, tmp) : WRITE_REG(GPIOx->FUNC1, tmp);

        /* Get position and 2-bits mask */
        pos  = i << 1;
        mask = 0x3 << pos;

        /* Set PIN mode */
        tmp  = READ_REG(GPIOx->MODE);
        tmp &= ~mask;
        tmp |= (init->mode << pos);
        WRITE_REG(GPIOx->MODE, tmp);

        /* Set PIN open-drain or push-pull */
        tmp  = READ_REG(GPIOx->OD);
        tmp &= ~mask;
        tmp |= (init->odos << pos);
        WRITE_REG(GPIOx->OD, tmp);

        /* Set PIN push-up or/and push-down */
        tmp  = READ_REG(GPIOx->PUPD);
        tmp &= ~mask;
        tmp |= (init->pupd << pos);
        WRITE_REG(GPIOx->PUPD, tmp);

        /* Set PIN output P-MOS driver */
        tmp  = READ_REG(GPIOx->ODRV);
        tmp &= ~mask;
        tmp |= (init->odrv << pos);
        WRITE_REG(GPIOx->ODRV, tmp);
    }

    return;
}

/**
  * @brief  Initialize the GPIOx peripheral using the default parameters.
  * @param  init: Pointer to a md_gpio_init_t structure
  * @retval None
  */
void md_gpio_init_struct(md_gpio_init_t *init)
{
    /* Fill md_gpio_init_t structure with default parameter */
    init->mode  = MD_GPIO_MODE_OUTPUT;
    init->odos  = MD_GPIO_PUSH_PULL;
    init->pupd  = MD_GPIO_PUSH_UP;
    init->odrv  = MD_GPIO_OUT_DRIVE_NORMAL;
    init->flt   = MD_GPIO_FILTER_DISABLE;
    init->type  = MD_GPIO_TYPE_CMOS;
    init->func  = MD_GPIO_FUNC_1;

    return;
}

/**
  * @brief  Set or clear the select Pin data.
  * @param  GPIOx: Where x can be (A--B) to select the GPIO peripheral.
  * @param  pin: The specified pin to be written.
  * @param  val: The specifies value to be written.
  * @retval None
  */
void md_gpio_write_pin(GPIO_TypeDef *GPIOx, uint16_t pin, uint8_t val)
{
    if ((val & (0x01)) == 0x00)
        GPIOx->BSRR = pin << 16U;
    else
        GPIOx->BSRR = pin;

    return;
}

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
 * @}
 */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

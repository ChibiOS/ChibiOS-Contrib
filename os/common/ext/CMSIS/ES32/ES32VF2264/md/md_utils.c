/**********************************************************************************
 *
 * @file    md_utils.c
 * @brief   UTILS module driver.
 *
 * @date    27 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          27 Dec. 2022    Lisq            the first version
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
#include <string.h>
#include "md_utils.h"
#include "md_cmu.h"

/* Private Macros ------------------------------------------------------------ */
/* Public Variables ---------------------------------------------------------- */

/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/** @defgroup Micro_Driver EASTSOFT Micro Driver
  * @{
  */

/* Private Variables --------------------------------------------------------- */

/** @defgroup MD_UTILS Utils
  * @brief Utils module driver
  * @{
  */
/** @defgroup MD_UTILS_Private_Variables Utils Private Variables
  * @{
  */
static __IO uint32_t __md_tick = 0;
/**
  * @}
  */

/* Private Function ---------------------------------------------------------- */

/** @defgroup MD_UTILS_Public_Functions Utils Public Functions
  * @{
  */
/**
  * @brief  This function configures the source of the time base.
  *         The time source is configured to have 1ms time base with a dedicated
  *         Tick interrupt priority.
  * @retval None
  */
void md_init_1ms_tick(void)
{
    /* Configure the SysTick IRQ */
    csi_coret_config(md_cmu_get_clock() / 1000, CLINT_IRQn);
    csi_vic_set_prio(CLINT_IRQn, 0);
    csi_vic_enable_sirq(CLINT_IRQn);

    return;
}

/**
  * @brief  This function invoked by Systick ISR.
  * @note   This function is declared as __weak to be overwritten in case of
  *         other implementations in user file.
  * @retval None
  */
__weak void md_systick_irq_cbk(void)
{
    /* do nothing */
    return;
}

/**
  * @brief  This function invoked by Systick ISR each 1ms.
  * @retval None
  */
__isr__ void md_inc_tick(void)
{
    ++__md_tick;
    md_systick_irq_cbk();
    return;
}

/**
  * @brief  Provides a tick value in millisecond.
  * @retval tick value
  */
uint32_t md_get_tick(void)
{
    return __md_tick;
}

/**
  * @brief  This function provides accurate delay (in microsecond) based
  *         on variable incremented.
  * @param  delay: specifies the delay time length, in microsecond.
  * @retval None
  */
void md_delay_1us(__IO uint32_t delay)
{
    unsigned int start, now, delta, ticks;
    start = CORET->MTIME;
	ticks = (md_cmu_get_clock() / 1000000UL) * delay;

    do
    {
        now = CORET->MTIME;
        delta = now - start;
    }
    while (delta < ticks);
}

/**
  * @brief  This function provides accurate delay (in milliseconds) based
  *         on variable incremented.
  * @param  delay: specifies the delay time length, in milliseconds.
  * @retval None
  */
void md_delay_1ms(__IO uint32_t delay)
{
    md_delay_1us(delay * 1000);
}

/**
  * @brief  Configure interrupt.
  * @param  irq: Interrunpt type.
  * @param  prio: preempt priority(0-7). The larger the prio value, the higher the priority.
  * @param  status: Status.
  *           @arg ENABLE
  *           @arg DISABLE
  * @retval None
  */
void md_mcu_irq_config(IRQn_Type irq, uint8_t prio, type_func_t status)
{
    if (status == ENABLE)
    {
        csi_vic_set_prio(irq, prio);
        csi_vic_enable_sirq(irq);

        if (irq == ADC_IRQn)
            CLIC->CLICINT[irq].ATTR |= (CLIC_INTATTR_SHV_Msk | (0x1UL << CLIC_INTATTR_TRIG_Pos));
    }
    else
    {
        csi_vic_disable_sirq(irq);
    }

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

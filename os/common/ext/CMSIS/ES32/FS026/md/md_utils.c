/**********************************************************************************
 *
 * @file    md_utils.c
 * @brief   UTILS module driver.
 *
 * @date    30 Apri 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          30 Apri 2021    yanght          the first version
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
#include "md_rcu.h"
#include "md_tick.h"

/** @defgroup Micro_Driver EASTSOFT Micro Driver
  * @{
  */

/** @defgroup MD_UTILS Utils
  * @brief Utils module driver
  * @{
  */
/** @defgroup MD_UTILS_Private_Variables Private Variables
  * @{
  */
static __IO uint32_t __md_tick = 0;
/**
  * @}
  */

/** @defgroup MD_UTILS_Public_Functions UTILS Public Functions
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
    md_tick_waitms(1, 1);
    NVIC_SetPriority(SysTick_IRQn, 3);
    return;
}

/**
  * @brief  This function invoked by Systick ISR.
  * @note   This function is declared as __weak to be overwritten in case of
  *         other implementations in user file.
  * @retval None
  */
__WEAK void md_systick_irq_cbk(void)
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
  * @brief  This function provides accurate delay (in milliseconds) based
  *         on variable incremented.
  * @param  delay: specifies the delay time length, in milliseconds.
  * @retval None
  */
void md_delay_1ms(__IO uint32_t delay)
{
    uint32_t tick;

    tick  = md_get_tick();
    delay = delay == 0 ? 1 : delay;

    while ((md_get_tick() - tick) < delay)
        ;
}
/**
  * @brief  This function provides accurate delay (in microsecond) based
  *         on variable incremented.
  * @param  delay: specifies the delay time length, in microsecond.
  * @retval None
  */
void md_delay_1us(__IO uint32_t delay)
{
    unsigned int start, now, delta, reload, us_tick;
    start = SysTick->VAL;
    reload = SysTick->LOAD;
    us_tick = SystemFrequency_SysClk / 1000000UL;

    do
    {
        now = SysTick->VAL;
        delta = start > now ? start - now : reload + start - now;
    }
    while (delta < (us_tick * delay));
}
/**
  * @brief  Configure interrupt.
  * @param  irq: Interrunpt type.
  * @param  prio: preempt priority(0-3).
  * @param  status: Status.
  *           @arg ENABLE
  *           @arg DISABLE
  * @retval None
  */
void md_mcu_irq_config(IRQn_Type irq, uint8_t prio, TypeFunc status)
{
    if (status == ENABLE)
    {
        NVIC_SetPriority(irq, prio);
        NVIC_EnableIRQ(irq);
    }
    else
    {
        NVIC_DisableIRQ(irq);
    }

    return;
}

/**
  * @brief  Get the CPU ID.
  * @retval CPU ID.
  */
uint32_t md_mcu_get_cpu_id(void)
{
    return SCB->CPUID;
}

/**
  * @brief  Get the UID.
  * @param  buf: Pointer to UID, len: 12Bytes(96-bits)
  * @retval None
  */
void md_mcu_get_uid(uint8_t *buf)
{
    memcpy(&buf[0], (void *)MD_MCU_UID0_ADDR, 4);
    memcpy(&buf[4], (void *)MD_MCU_UID1_ADDR, 4);
    memcpy(&buf[8], (void *)MD_MCU_UID2_ADDR, 4);

    return;
}

/**
  * @brief  Get the CHIPID
  * @retval CHPID
  */
uint32_t md_mcu_get_chipid(void)
{
    return (uint32_t) * (uint32_t *)MD_MCU_CHIPID_ADDR;
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

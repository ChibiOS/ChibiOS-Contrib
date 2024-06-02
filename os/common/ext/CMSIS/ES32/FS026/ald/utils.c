/**********************************************************************************
 *
 * @file    utils.c
 * @brief   utils C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021    Ginger          the first version
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

/* Includes -------------------------------------------------------------------*/
#include "utils.h"
#include "cmsis_compiler.h"

/** @defgroup ALD
  * @brief Shanghai Eastsoft Microelectronics Cortex-M Chip Abstraction Layer Driver(ALD)
  * @{
  */

/** @defgroup UTILS Utils
  * @brief Utils module driver
  * @{
  */

/** @defgroup ALD_Private_Constants Private Constants
  * @brief ALD Private Constants
  * @{
  */

/**
  * @brief ALD version number
  */
#define __LIB_VERSION_MAIN  (0x01) /**< [31:24] main version */
#define __LIB_VERSION_SUB1  (0x00) /**< [23:16] sub1 version */
#define __LIB_VERSION_SUB2  (0x00) /**< [15:8]  sub2 version */
#define __LIB_VERSION_RC  (0x00) /**< [7:0]  release candidate */
#define __LIB_VERSION    ((__LIB_VERSION_MAIN << 24) | \
                          (__LIB_VERSION_SUB1 << 16) | \
                          (__LIB_VERSION_SUB2 << 8 ) | \
                          (__LIB_VERSION_RC))
/**
  * @} ALD_Private_Constants
  */

/** @defgroup ALD_Private_Variables Private Variables
  * @{
  */
/** @brief lib_tick: Increase by one millisecond
  */
static __IO uint32_t lib_tick;
uint32_t __systick_interval = SYSTICK_INTERVAL_1MS;
/**
  * @} ALD_Private_Variables
  */


/** @defgroup ALD_Public_Functions Public Functions
  * @{
  */

/** @defgroup ALD_Public_Functions_Group1 Initialization Function
  * @brief    Initialization functions
  *
  * @verbatim
 ===============================================================================
              ##### Initialization functions #####
 ===============================================================================
   [..]  This section provides functions allowing to:
      (+) Initializes interface, the NVIC allocation and initial clock
          configuration. It initializes the source of time base also when timeout
          is needed and the backup domain when enabled.
      (+) Configure The time base source to have 1ms time base with a dedicated
          Tick interrupt priority.
        (++) Systick timer is used by default as source of time base, but user
             can eventually implement his proper time base source (a general purpose
             timer for example or other time source), keeping in mind that Time base
             duration should be kept 1ms.
        (++) Time base configuration function (__init_tick()) is called automatically
             at the beginning of the program after reset by mcu_hal_init() or at
       any time when clock is configured.
        (++) Source of time base is configured  to generate interrupts at regular
             time intervals. Care must be taken if __delay_ms() is called from a
             peripheral ISR process, the Tick interrupt line must have higher priority
            (numerically lower) than the peripheral interrupt. Otherwise the caller
            ISR process will be blocked.
       (++) functions affecting time base configurations are declared as __WEAK
             to make  override possible  in case of other implementations in user file.
      (+) Configure the interval of Systick interrupt.

    @endverbatim
  * @{
  */

/**
  * @brief  This function Configures time base source, NVIC and DMA.
  * @note   This function is called at the beginning of program after reset and before
  *         the clock configuration.
  * @note   The time base configuration is based on System clock when exiting from Reset.
  *         Once done, time base tick start incrementing.
  *         In the default implementation, Systick is used as source of time base.
  *         The tick variable is incremented each 1ms in its ISR.
  * @retval None
  */
void ald_init(void)
{
    __init_tick(TICK_INT_PRIORITY);
    return;
}

/**
  * @brief  This function configures the source of the time base.
  *         The time source is configured to have 1ms time base with a dedicated
  *         Tick interrupt priority.
  * @note   In the default implementation, SysTick timer is the source of time base.
  *         It is used to generate interrupts at regular time intervals.
  *         Care must be taken if __delay_ms() is called from a peripheral ISR process,
  *         The SysTick interrupt must have higher priority (numerically lower)
  *         than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
  *         The function is declared as __WEAK to be overwritten in case of other
  *         implementation in user file.
  * @param  prio: Tick interrupt priority.
  * @retval None
  */
__WEAK void __init_tick(uint32_t prio)
{
    /* Configure the SysTick IRQ */
    SysTick_Config(SystemFrequency_SysClk / SYSTICK_INTERVAL_1MS);

    if (prio != 3)

        NVIC_SetPriority(SysTick_IRQn, prio);

    return;
}

/**
  * @brief  Selects the interval of systick interrupt.
  * @param  value: The value of interval:
  *           @arg @ref SYSTICK_INTERVAL_1MS    1 millisecond
  *           @arg @ref SYSTICK_INTERVAL_10MS   10 milliseconds
  *           @arg @ref SYSTICK_INTERVAL_100MS  100 milliseconds
  *           @arg @ref SYSTICK_INTERVAL_1000MS 1 second
  * @retval None
  */
void systick_interval_select(systick_interval_t value)
{
    assert_param(IS_SYSTICK_INTERVAL(value));

    SysTick_Config(SystemFrequency_SysClk / value);
    __systick_interval = value;

    if (TICK_INT_PRIORITY != 3)
        NVIC_SetPriority(SysTick_IRQn, TICK_INT_PRIORITY);

    return;
}
/**
  * @} ALD_Public_Functions_Group1
  */

/** @defgroup ALD_Public_Functions_Group2 Control functions
  * @brief    Control functions
  *
  * @verbatim
 ===============================================================================
                      ##### Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Provide a tick value in millisecond
      (+) Provide a blocking delay in millisecond
      (+) Suspend the time base source interrupt
      (+) Resume the time base source interrupt
      (+) Get the HAL version
      (+) Waiting for flag
      (+) Configure the interrupt
      (+) Provide system tick value
      (+) Get CPU ID
    @endverbatim
  * @{
  */

/**
  * @brief  This function is called to increment a global variable "lib_tick"
  *         used as application time base.
  * @note   In the default implementation, this variable is incremented each 1ms
  *         in Systick ISR.
  * @note   This function is declared as __WEAK to be overwritten in case of other
  *         implementations in user file.
  * @retval None
  */
__WEAK void __inc_tick(void)
{
    ++lib_tick;
}

/**
  * @brief  This function invoked by Systick ISR.
  * @note   This function is declared as __WEAK to be overwritten in case of
  *         other implementations in user file.
  * @retval None
  */
__WEAK void systick_irq_cbk(void)
{
    /* do nothing */
    return;
}



/**
  * @brief  Provides a tick value in millisecond.
  * @note   This function is declared as __WEAK to be overwritten in case of other
  *         implementations in user file.
  * @retval tick value
  */
__WEAK uint32_t __get_tick(void)
{
    return lib_tick;
}

/**
  * @brief  This function provides accurate delay (in milliseconds) based
  *         on variable incremented.
  * @note   In the default implementation, SysTick timer is the source of time base.
  *         It is used to generate interrupts at regular time intervals where lib_tick
  *         is incremented.
  * @note   This function is declared as __WEAK to be overwritten in case of other
  *         implementations in user file.
  * @param  delay: specifies the delay time length, in milliseconds.
  * @retval None
  */
__WEAK void __delay_ms(__IO uint32_t delay)
{
    uint32_t tick, __delay;

    switch (__systick_interval)
    {
        case SYSTICK_INTERVAL_1MS:
            __delay = delay;
            break;

        case SYSTICK_INTERVAL_10MS:
            __delay = delay / 10;
            break;

        case SYSTICK_INTERVAL_100MS:
            __delay = delay / 100;
            break;

        case SYSTICK_INTERVAL_1000MS:
            __delay = delay / 1000;
            break;

        default:
            __delay = delay;
            break;
    }

    tick    = __get_tick();
    __delay = __delay == 0 ? 1 : __delay;

    while ((__get_tick() - tick) < __delay)
        ;
}

/**
  * @brief  Suspend Tick increment.
  * @note   In the default implementation, SysTick timer is the source of time base.
  *         It is used to generate interrupts at regular time intervals.
  *         Once __suspend_tick() is called, the the SysTick interrupt
  *         will be disabled and so Tick increment is suspended.
  * @note   This function is declared as __WEAK to be overwritten
  *         in case of other implementations in user file.
  * @retval None
  */
__WEAK void __suspend_tick(void)
{
    CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief  Resume Tick increment.
  * @note   In the default implementation, SysTick timer is the source of
  *         time base. It is used to generate interrupts at regular time
  *         intervals. Once __resume_tick() is called, the the SysTick
  *         interrupt will be enabled and so Tick increment is resumed.
  * @note   This function is declared as __WEAK to be overwritten
  *         in case of other implementations in user file.
  * @retval None
  */
__WEAK void __resume_tick(void)
{
    SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief  This method returns the HAL revision
  * @retval version: 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t get_lib_version(void)
{
    return __LIB_VERSION;
}

/**
  * @brief  Waiting the specified bit in the register change to SET/RESET.
  * @param  reg: The register address.
  * @param  bit: The specified bit.
  * @param  status: The status for waiting.
  * @param  timeout: Timeout duration.
  * @retval Status, see @ref hal_status_t.
  */
ald_status_t __wait_flag(uint32_t *reg, uint32_t bit, FlagStatus status, uint32_t timeout)
{
    uint32_t tick = __get_tick();

    assert_param(timeout > 0);

    if (status == SET)
    {
        while (!(IS_BIT_SET(*reg, bit)))
        {
            if (((__get_tick()) - tick) > timeout)
                return TIMEOUT;
        }
    }
    else
    {
        while ((IS_BIT_SET(*reg, bit)))
        {
            if (((__get_tick()) - tick) > timeout)
                return TIMEOUT;
        }
    }

    return OK;
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
void mcu_irq_config(IRQn_Type irq, uint8_t prio, TypeFunc status)
{
    assert_param(IS_FUNC_STATE(status));
    assert_param(IS_PRIO(prio));

    if (status == ENABLE)
    {
        NVIC_SetPriority(irq, prio);
        NVIC_EnableIRQ(irq);
        NVIC_ClearPendingIRQ(irq);

    }
    else
    {
        NVIC_DisableIRQ(irq);
    }

    return;
}

/**
  * @brief  Get the system tick.
  * @retval The value of current tick.
  */
uint32_t mcu_get_tick(void)
{
    uint32_t load = SysTick->LOAD;
    uint32_t val  = SysTick->VAL;

    return (load - val);
}

/**
  * @brief  Get the CPU ID.
  * @retval CPU ID.
  */
uint32_t mcu_get_cpu_id(void)
{
    return SCB->CPUID;
}

/**
  * @brief  clear_tick
  * @retval none.
  */
void __clear_tick(void)
{
    lib_tick = 0;
}

/**
  * @} ALD_Public_Functions_Group2
  */

/**
  * @} ALD_Public_Functions
  */


/**
  * @} UTILS
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics END OF FILE****/

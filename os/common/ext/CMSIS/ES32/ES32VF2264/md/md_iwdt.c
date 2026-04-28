/**********************************************************************************
 *
 * @file    md_iwdt.c
 * @brief   IWDT module driver.
 *
 * @date    20 July 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          20 July 2022    Lisq            the first version
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
#include "md_iwdt.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_IWDT IWDT
  * @{
  */
/** @addtogroup MD_IWDT_Public_Functions
  * @{
  */

/** @addtogroup MD_IWDT_Public_Functions_Group1
  * @{
  */
/**
 * @brief Initializes the IWDT according to the specified parameters.
 * @param load: Specifies the free-running downcounter value.
 * @param interrupt: Enable or disable interrupt.
 * @retval None
 */
void md_iwdt_init(uint32_t load, type_func_t interrupt)
{
    assert_param(IS_FUNC_STATE(interrupt));

    IWDT_UNLOCK();
    md_iwdt_set_count_overload(load);
    md_iwdt_set_count_clock2();
    md_iwdt_enable_reset();

    if (interrupt == ENABLE)
    {
        md_iwdt_enable_interrupt();
    }
    else
    {
        md_iwdt_disable_interrupt();
    }

    IWDT_LOCK();

    return;
}

/**
 * @brief Initializes the IWDT without reset according to the specified parameters.
 * @param load: Specifies the free-running downcounter value.
 * @param interrupt: Enable or disable interrupt.
 * @retval None
 */
void md_iwdt_init_no_reset(uint32_t load, type_func_t interrupt)
{
    assert_param(IS_FUNC_STATE(interrupt));

    IWDT_UNLOCK();
    md_iwdt_set_count_overload(load);
    md_iwdt_set_count_clock2();
    md_iwdt_disable_reset();

    if (interrupt == ENABLE)
    {
        md_iwdt_enable_interrupt();
    }
    else
    {
        md_iwdt_disable_interrupt();
    }

    IWDT_LOCK();

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

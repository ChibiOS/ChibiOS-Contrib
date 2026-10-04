/**********************************************************************************
 *
 * @file    md_wwdt.c
 * @brief   WWDT module driver.
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
#include "md_wwdt.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_WWDT WWDT
  * @{
  */
/** @defgroup MD_WWDT_Public_Functions  WWDT Public Functions
  * @{
  */
/** @defgroup MD_WWDT_Public_Functions_Group1 Initialization
  * @{
  */

/**
  * @brief Initializes the WWDT according to the specified parameters.
  * @param load: Specifies the free-running downcounter value.
  * @param win: specifics the no dog windows,
  *        the parameter can be one of the following values:
  *        @arg @ref MD_WWDT_WIN_25 No dog window size: 25%
  *        @arg @ref MD_WWDT_WIN_50 No dog window size: 50%
  *        @arg @ref MD_WWDT_WIN_75 No dog window size: 75%
  *        @arg @ref MD_WWDT_WIN_00 No dog window size: 0%
  * @param interrupt: Enable or disable interrupt.
  * @retval None
  */
void md_wwdt_init(uint32_t load, md_wwdt_win_t win, type_func_t interrupt)
{
    WWDT_UNLOCK();
    md_wwdt_set_count_overload(load);
    md_wwdt_set_forbid_feed_time(win);
    md_wwdt_set_count_lrc();
    md_wwdt_enable_reset();

    if (interrupt == ENABLE)
    {
        md_wwdt_enable_interrupt();
    }
    else
    {
        md_wwdt_disable_interrupt();
    }

    WWDT_LOCK();

    return;
}

/**
  * @brief Initializes the WWDT without reset according to the specified parameters.
  * @param load: Specifies the free-running downcounter value.
  * @param win: specifics the no dog windows,
  *        the parameter can be one of the following values:
  *        @arg @ref MD_WWDT_WIN_25 No dog window size: 25%
  *        @arg @ref MD_WWDT_WIN_50 No dog window size: 50%
  *        @arg @ref MD_WWDT_WIN_75 No dog window size: 75%
  *        @arg @ref MD_WWDT_WIN_00 No dog window size: 0%
  * @param interrupt: Enable or disable interrupt.
  * @retval None
  */
void md_wwdt_init_no_reset(uint32_t load, md_wwdt_win_t win, type_func_t interrupt)
{
    WWDT_UNLOCK();
    md_wwdt_set_count_overload(load);
    md_wwdt_set_forbid_feed_time(win);
    md_wwdt_set_count_lrc();
    md_wwdt_disable_reset();

    if (interrupt == ENABLE)
    {
        md_wwdt_enable_interrupt();
    }
    else
    {
        md_wwdt_disable_interrupt();
    }

    WWDT_LOCK();

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

/**********************************************************************************
 *
 * @file    md_rmu.c
 * @brief   Reset management unit driver.
 *
 * @date    26 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          26 Dec. 2022    Lisq            the first version
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
#include "md_rmu.h"
#include "md_syscfg.h"

/* Private Macros ------------------------------------------------------------ */
/* Private Variables --------------------------------------------------------- */
/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/* Private Function ---------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_RMU
  * @{
  */

/** @addtogroup MD_RMU_Public_Functions
  * @{
  */
/** @addtogroup MD_RMU_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Reset the RMU register
  * @retval None
  */
void md_rmu_reset(void)
{
    MD_SYSCFG_UNLOCK();
    WRITE_REG(RMU->CR, 0x0);
    WRITE_REG(RMU->CRSTSR, 0xFFFF);
    WRITE_REG(RMU->AHB1RSTR, 0x0);
    WRITE_REG(RMU->AHB2RSTR, 0x0);
    WRITE_REG(RMU->APBRSTR, 0x0);
    MD_SYSCFG_LOCK();

    return;
}

/**
  * @brief  Configure BOR parameters.
  * @param  flt: filter time.
  * @retval None
  */
void md_rmu_bor_config(md_rmu_bor_filter_t flt)
{
    MD_SYSCFG_UNLOCK();
    MODIFY_REG(RMU->CR, RMU_CR_BORFLT_MSK, flt << RMU_CR_BORFLT_POSS);
    MD_SYSCFG_LOCK();

    return;
}

/**
  * @brief  Get specified reset status
  * @param  state: Speicifies the type of the reset,
  * @retval The status.
  */
uint32_t md_rmu_get_reset_status(md_rmu_state_t state)
{
    if (state == MD_RMU_RST_ALL)
        return RMU->RSTSR;

    if (READ_BIT(RMU->RSTSR, state))
        return SET;

    return RESET;
}

/**
  * @brief  Clear the specified reset status
  * @param  state: Specifies the type of the reset,
  * @retval None
  */
void md_rmu_clear_reset_status(md_rmu_state_t state)
{
    MD_SYSCFG_UNLOCK();
    WRITE_REG(RMU->CRSTSR, state);
    MD_SYSCFG_LOCK();

    return;
}

/**
  * @brief  Reset peripheral device
  * @param  perh: The peripheral device,
  * @retval None
  */
void md_rmu_reset_periperal(md_rmu_peripheral_t perh)
{
    uint32_t idx, pos;

    idx = ((uint32_t)perh >> 27) & 0x7;
    pos = perh & ~(0x7 << 27);
    MD_SYSCFG_UNLOCK();

    switch (idx)
    {
        case 0:
            WRITE_REG(RMU->AHB1RSTR, pos);
            break;

        case 1:
            WRITE_REG(RMU->AHB2RSTR, pos);
            break;

        case 2:
            WRITE_REG(RMU->APBRSTR, pos);
            break;

        default:
            break;
    }

    MD_SYSCFG_LOCK();
    return;
}

/**
  * @brief  System reset request
  * @param  None
  * @retval None
  */
void md_rmu_reset_system(void)
{
    csi_cpu_reset(MEXSTATUS_RESET_CORE);

    return;
}

/**
  * @brief  Chip reset request
  * @param  None
  * @retval None
  */
void md_rmu_reset_chip(void)
{
    MD_SYSCFG_UNLOCK();
    SET_BIT(RMU->AHB2RSTR, RMU_AHB2RSTR_CHIPRST_MSK);
    MD_SYSCFG_LOCK();

    return;
}

/**
  * @brief  CPU reset request
  * @param  None
  * @retval None
  */
void md_rmu_reset_cpu(void)
{
    MD_SYSCFG_UNLOCK();
    SET_BIT(RMU->AHB2RSTR, RMU_AHB2RSTR_CPURST_MSK);
    MD_SYSCFG_LOCK();

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

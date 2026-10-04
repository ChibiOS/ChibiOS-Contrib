/**********************************************************************************
 *
 * @file    md_pmu.c
 * @brief   Power management unit driver.
 *
 * @date    16 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          16 Dec. 2022    Lisq            the first version
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
#include "md_pmu.h"
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

/** @addtogroup MD_PMU
  * @{
  */

/** @addtogroup MD_PMU_Public_Functions
  * @{
  */
/** @addtogroup MD_PMU_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Reset the PMU register
  * @retval None
  */
void md_pmu_reset(void)
{
    MD_SYSCFG_UNLOCK();
    WRITE_REG(PMU->CR, 0x1C000080);
    WRITE_REG(PMU->LVDCR, 0x0);
    MD_SYSCFG_LOCK();
    return;
}

/**
  * @brief  Enter stop mode
  * @retval None
  */
void md_pmu_stop_enter(void)
{
	uint32_t clint_irq_en = 0U;
	clint_irq_en = csi_vic_get_enabled_irq(CLINT_IRQn);
	csi_vic_disable_sirq(CLINT_IRQn);

    MD_SYSCFG_UNLOCK();
    CLEAR_BIT(PMU->CR, PMU_CR_VROSCEN_MSK);
    MODIFY_REG(PMU->CR, PMU_CR_LPSTOP_MSK | PMU_CR_BGSTOP_MSK | \
               PMU_CR_STPRTNEN_MSK | PMU_CR_FSTOP_MSK, \
               1 << PMU_CR_LPSTOP_POS | 1 << PMU_CR_BGSTOP_POS \
               | 1 << PMU_CR_STPRTNEN_POS | 1 << PMU_CR_FSTOP_POS);
    /* WKEVNSEL is only for testing, and user should set it to be 0x10. */
    MODIFY_REG(PMU->CR, PMU_CR_WKEVNSEL_MSK, (0x10 << PMU_CR_WKEVNSEL_POSS));
    MD_SYSCFG_LOCK();

    csi_cpu_sleep_wfi(MEXSTATUS_SLEEP_DEEP);

    __WFI_();

    if(clint_irq_en)
		csi_vic_enable_sirq(CLINT_IRQn);
}

/**
  * @brief  Enter sleep mode
  * @retval None
  */
void md_pmu_sleep_enter(void)
{
	uint32_t clint_irq_en = 0U;
	clint_irq_en = csi_vic_get_enabled_irq(CLINT_IRQn);
	csi_vic_disable_sirq(CLINT_IRQn);

    MD_SYSCFG_UNLOCK();
    /* WKEVNSEL is only for testing, and user should set it to be 0x10. */
    MODIFY_REG(PMU->CR, PMU_CR_WKEVNSEL_MSK, (0x10 << PMU_CR_WKEVNSEL_POSS));
    MD_SYSCFG_LOCK();

    csi_cpu_sleep_wfi(MEXSTATUS_SLEEP_LIGHT);

    __WFI_();

    if(clint_irq_en)
		csi_vic_enable_sirq(CLINT_IRQn);
}

/**
  * @brief  Configure lvd using specified parameters.
  * @param  sel: LVD threshold voltage.
  * @param  mode: LVD trigger mode.
  * @param  state: New state, ENABLE/DISABLE;
  * @retval None
  */
void md_pmu_lvd_config(md_pmu_lvd_voltage_sel_t sel, md_pmu_lvd_trigger_mode_t mode, type_func_t state)
{
    MD_SYSCFG_UNLOCK();

    if (state)
    {
        MODIFY_REG(PMU->LVDCR, PMU_LVDCR_LVDS_MSK, sel << PMU_LVDCR_LVDS_POSS);
        MODIFY_REG(PMU->LVDCR, PMU_LVDCR_LVDIFS_MSK, mode << PMU_LVDCR_LVDIFS_POSS);
        SET_BIT(PMU->LVDCR, PMU_LVDCR_LVDFLT_MSK);
        SET_BIT(PMU->LVDCR, PMU_LVDCR_LVDCIF_MSK);
        SET_BIT(PMU->LVDCR, PMU_LVDCR_LVDIE_MSK);
        SET_BIT(PMU->LVDCR, PMU_LVDCR_LVDEN_MSK);
    }
    else
    {
        SET_BIT(PMU->LVDCR, PMU_LVDCR_LVDCIF_MSK);
        CLEAR_BIT(PMU->LVDCR, PMU_LVDCR_LVDIE_MSK);
        CLEAR_BIT(PMU->LVDCR, PMU_LVDCR_LVDEN_MSK);
    }

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

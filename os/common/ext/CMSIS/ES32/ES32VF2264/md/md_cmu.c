/**********************************************************************************
 *
 * @file    md_cmu.c
 * @brief   CMU module driver.
 *
 * @date    15 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          15 Dec. 2022    Lisq            the first version
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
#include "md_cmu.h"
#include "md_msc.h"

/* Private Macros ------------------------------------------------------------ */

/* Public Variables ---------------------------------------------------------- */
/* Private Constants --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */

/** @addtogroup MD_CMU
  * @{
  */

/* Private Variables --------------------------------------------------------- */

/**
  * @defgroup MD_CMU_Private_Variables CMU Private Variables
  * @{
  */
uint32_t md_system_clock = 48000000U;
/**
  * @}
  */

/* Private Function ---------------------------------------------------------- */

/** @defgroup MD_CMU_Private_Functions CMU Private Functions
  * @{
  */

/**
  * @brief  Update the current system clock. This function
  *         will be invoked, when system clock has changed.
  * @param  clock: The new clock.
  * @retval None
  */

static void md_cmu_clock_update(uint32_t clock)
{
    md_system_clock = clock;
}
/**
  * @}
  */
/** @addtogroup MD_CMU_Public_Functions
  * @{
  */
/** @addtogroup MD_CMU_Public_Functions_Group1
  * @{
  */
/**
  * @brief  Configure system clock using default.
  *         Select MD_CMU_CLOCK_HRC(48MHz) as system clock and
  *         enable MD_CMU_CLOCK_LRC(32000Hz).
  * @retval The status of MD.
  */
md_status_t md_cmu_clock_config_default(void)
{
    uint32_t cnt = 4000U, tmp;

    md_msc_set_flash_read_wait_cycle(2);

    MD_SYSCFG_UNLOCK();

    WRITE_REG(CMU->CFGR, 0x0);

    tmp = READ_REG(CMU->CLKENR);
    /* Enable HRC48M */
    SET_BIT(tmp, CMU_CLKENR_HRC48MEN_MSK);
    WRITE_REG(CMU->CLKENR, tmp);

    for (cnt = 4000; cnt; --cnt);

    cnt = 4000;

    while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HRC48MACT_MSK))) && (--cnt));

    cnt = 4000;

    while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HRC48MRDY_MSK))) && (--cnt));

    /* Select HRC48M */
    MODIFY_REG(CMU->CSR, CMU_CSR_SYS_CMD_MSK, MD_CMU_CLOCK_HRC48M << CMU_CSR_SYS_CMD_POSS);

    cnt = 4000;

    while (READ_BIT(CMU->CSR, CMU_CSR_SYS_RDYN_MSK) && (--cnt));

    if (READ_BITS(CMU->CSR, CMU_CSR_SYS_STU_MSK, CMU_CSR_SYS_STU_POSS) != MD_CMU_CLOCK_HRC48M)
    {
        MD_SYSCFG_LOCK();
        return MD_ERROR;
    }

    md_cmu_clock_update(48000000);

    MD_SYSCFG_LOCK();

    return MD_OK;
}

/**
  * @brief  Configure system clock using specified parameters
  * @param  clk: The parameter can be one of the following:
  *           @arg @ref MD_CMU_CLOCK_HRC  4MHz or 48MHz
  *           @arg @ref MD_CMU_CLOCK_LRC  32kHz
  *           @arg @ref MD_CMU_CLOCK_PLL  48MHz, 64MHz, 72MHz
  *           @arg @ref MD_CMU_CLOCK_HOSC 4MHz, 8MHz, 12MHz
  * @param  clock: The clock which will be set. the value depends
  *         on the parameter of clk.
  * @retval The status of MD.
  */
md_status_t md_cmu_clock_config(md_cmu_clock_t clk, uint32_t clock)
{
    uint32_t cnt = 8000U;

    md_msc_set_flash_read_wait_cycle(2);

    MD_SYSCFG_UNLOCK();
    MODIFY_REG(CMU->CFGR, 0xFFFFFFU, 0);

    switch (clk)
    {
        case MD_CMU_CLOCK_HRC48M:
            assert_param(clock == 48000000);

            SET_BIT(CMU->CLKENR, CMU_CLKENR_HRC48MEN_MSK);

            for (cnt = 4000; cnt; --cnt);

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HRC48MACT_MSK))) && (--cnt));

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HRC48MRDY_MSK))) && (--cnt));

            MODIFY_REG(CMU->CSR, CMU_CSR_SYS_CMD_MSK, MD_CMU_CLOCK_HRC48M << CMU_CSR_SYS_CMD_POSS);

            cnt = 4000;

            while (READ_BIT(CMU->CSR, CMU_CSR_SYS_RDYN_MSK) && (--cnt));

            if (READ_BITS(CMU->CSR, CMU_CSR_SYS_STU_MSK, CMU_CSR_SYS_STU_POSS) != MD_CMU_CLOCK_HRC48M)
            {
                MD_SYSCFG_LOCK();
                return MD_ERROR;
            }

            md_cmu_clock_update(clock);

            break;

        case MD_CMU_CLOCK_LRC:
            assert_param(clock == 32000);

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_LRCRDY_MSK))) && (--cnt));

            MODIFY_REG(CMU->CSR, CMU_CSR_SYS_CMD_MSK, MD_CMU_CLOCK_LRC << CMU_CSR_SYS_CMD_POSS);

            cnt = 4000;

            while (READ_BIT(CMU->CSR, CMU_CSR_SYS_RDYN_MSK) && (--cnt));

            if (READ_BITS(CMU->CSR, CMU_CSR_SYS_STU_MSK, CMU_CSR_SYS_STU_POSS) != MD_CMU_CLOCK_LRC)
            {
                MD_SYSCFG_LOCK();
                return MD_ERROR;
            }

            md_cmu_clock_update(clock);

            break;

        case MD_CMU_CLOCK_HOSC:
            assert_param(clock == 4000000 || clock == 8000000 || clock == 12000000);

            SET_BIT(CMU->CLKENR, CMU_CLKENR_HOSCEN_MSK);

            MODIFY_REG(CMU->HOSCCFG, CMU_HOSCCFG_FREQ_MSK, clock / 4000000 - 1);

            for (cnt = 8000; cnt; --cnt);

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HOSCACT_MSK))) && (--cnt));

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HOSCRDY_MSK))) && (--cnt));

            MODIFY_REG(CMU->CSR, CMU_CSR_SYS_CMD_MSK, MD_CMU_CLOCK_HOSC << CMU_CSR_SYS_CMD_POSS);

            cnt = 4000;

            while (READ_BIT(CMU->CSR, CMU_CSR_SYS_RDYN_MSK) && (--cnt));

            if (READ_BITS(CMU->CSR, CMU_CSR_SYS_STU_MSK, CMU_CSR_SYS_STU_POSS) != MD_CMU_CLOCK_HOSC)
            {
                MD_SYSCFG_LOCK();
                return MD_ERROR;
            }

            md_cmu_clock_update(clock);

            break;

        case MD_CMU_CLOCK_PLL:
            assert_param(clock == 72000000 || clock == 64000000 || clock == 48000000);

            SET_BIT(CMU->CLKENR, CMU_CLKENR_PLLEN_MSK);

            for (cnt = 4000; cnt; --cnt);

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_PLLACT_MSK))) && (--cnt));

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_PLLRDY_MSK))) && (--cnt));

            MODIFY_REG(CMU->CSR, CMU_CSR_SYS_CMD_MSK, MD_CMU_CLOCK_PLL << CMU_CSR_SYS_CMD_POSS);

            cnt = 4000;

            while (READ_BIT(CMU->CSR, CMU_CSR_SYS_RDYN_MSK) && (--cnt));

            if (READ_BITS(CMU->CSR, CMU_CSR_SYS_STU_MSK, CMU_CSR_SYS_STU_POSS) != MD_CMU_CLOCK_PLL)
            {
                MD_SYSCFG_LOCK();
                return MD_ERROR;
            }

            md_cmu_clock_update(clock);

            break;

        case MD_CMU_CLOCK_HRC4M:
            assert_param(clock == 4000000);

            SET_BIT(CMU->CLKENR, CMU_CLKENR_HRC4MEN_MSK);

            for (cnt = 4000; cnt; --cnt);

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HRC4MACT_MSK))) && (--cnt));

            cnt = 4000;

            while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HRC4MRDY_MSK))) && (--cnt));

            MODIFY_REG(CMU->CSR, CMU_CSR_SYS_CMD_MSK, MD_CMU_CLOCK_HRC4M << CMU_CSR_SYS_CMD_POSS);

            cnt = 4000;

            while (READ_BIT(CMU->CSR, CMU_CSR_SYS_RDYN_MSK) && (--cnt));

            if (READ_BITS(CMU->CSR, CMU_CSR_SYS_STU_MSK, CMU_CSR_SYS_STU_POSS) != MD_CMU_CLOCK_HRC4M)
            {
                MD_SYSCFG_LOCK();
                return MD_ERROR;
            }

            md_cmu_clock_update(clock);

            break;

        default:
            break;
    }

    MD_SYSCFG_LOCK();
    return MD_OK;
}

/**
  * @brief  Configure PLL using specified parameters.
  * @param  input: The input clock type.
  * @param  output: The output clock which can be 48MHz/64MHz/72MHz.
  * @retval None
  */
void md_cmu_pll_config(md_cmu_pll_input_t input, md_cmu_pll_output_t output)
{
    uint32_t cnt = 4000U;

    MD_SYSCFG_UNLOCK();

    if (READ_BITS(CMU->CSR, CMU_CSR_SYS_STU_MSK, CMU_CSR_SYS_STU_POSS) == MD_CMU_CLOCK_PLL)
    {
        SET_BIT(CMU->CLKENR, CMU_CLKENR_HRC48MEN_MSK);

        for (cnt = 4000; cnt; --cnt);

        cnt = 4000;

        while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HRC48MACT_MSK))) && (--cnt));

        cnt = 4000;

        while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HRC48MRDY_MSK))) && (--cnt));

        MODIFY_REG(CMU->CSR, CMU_CSR_SYS_CMD_MSK, MD_CMU_CLOCK_HRC48M << CMU_CSR_SYS_CMD_POSS);

        cnt = 4000;

        while (READ_BIT(CMU->CSR, CMU_CSR_SYS_RDYN_MSK) && (--cnt));
    }

    if (input == MD_CMU_PLL_INPUT_HRC4M)
    {
        SET_BIT(CMU->CLKENR, CMU_CLKENR_HRC4MEN_MSK);
    }
    else
    {
        SET_BIT(CMU->CLKENR, CMU_CLKENR_HOSCEN_MSK);

        if (input == MD_CMU_PLL_INPUT_HOSC4M)
        {
            MODIFY_REG(CMU->HOSCCFG, CMU_HOSCCFG_FREQ_MSK, 0);
        }
        else if (input == MD_CMU_PLL_INPUT_HOSC8M)
        {
            MODIFY_REG(CMU->HOSCCFG, CMU_HOSCCFG_FREQ_MSK, 1);
        }
		else
		{

		}

        cnt = 20000;

        while ((!(READ_BIT(CMU->CLKSR, CMU_CLKSR_HOSCRDY_MSK))) && (--cnt));
    }

    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_PLLEN_MSK);

    MODIFY_REG(CMU->PLLCFG, CMU_PLLCFG_REFS_MSK, input << CMU_PLLCFG_REFS_POSS);
    MODIFY_REG(CMU->PLLCFG, CMU_PLLCFG_CLKOS_MSK, output << CMU_PLLCFG_CLKOS_POSS);

    SET_BIT(CMU->PULMCR, CMU_PULMCR_EN_MSK);
    MODIFY_REG(CMU->PULMCR, CMU_PULMCR_MODE_MSK, 0x2 << CMU_PULMCR_MODE_POSS);

    MD_SYSCFG_LOCK();
    return;
}

/**
  * @brief  Configure the bus division.
  * @param  bus: The type of bus:
  *          @arg CMU_SYS
  *          @arg CMU_PCLK
  * @param  clk_div: The value of divider.
  * @retval None
  */
void md_cmu_div_config(md_cmu_bus_t bus, md_cmu_div_t clk_div)
{
    MD_SYSCFG_UNLOCK();

    switch (bus)
    {
        case MD_CMU_SYS:
            MODIFY_REG(CMU->CFGR, CMU_CFGR_SYSDIV_MSK, clk_div << CMU_CFGR_SYSDIV_POSS);
            break;

        case MD_CMU_PCLK:
            MODIFY_REG(CMU->CFGR, CMU_CFGR_PCLKDIV_MSK, clk_div << CMU_CFGR_PCLKDIV_POSS);
            break;

        default:
            break;
    }

    MD_SYSCFG_LOCK();

    return;
}

/**
  * @brief  Get SYS clock
  * @retval The value of SYS clock
  */
uint32_t md_cmu_get_sys_clock(void)
{
    uint32_t sys_div = READ_BITS(CMU->CFGR, CMU_CFGR_SYSDIV_MSK, CMU_CFGR_SYSDIV_POSS);

    return md_system_clock >> sys_div;
}

/**
  * @brief  Get APB clock.
  * @retval The value of APB clock.
  */
uint32_t md_cmu_get_pclk_clock(void)
{
    uint32_t sys_div  = READ_BITS(CMU->CFGR, CMU_CFGR_SYSDIV_MSK, CMU_CFGR_SYSDIV_POSS);
    uint32_t apb_div = READ_BITS(CMU->CFGR, CMU_CFGR_PCLKDIV_MSK, CMU_CFGR_PCLKDIV_POSS);

    return (md_system_clock >> sys_div) >> apb_div;
}

/**
  * @brief  Gets current system clock.
  * @retval The value of system clock.
  */
uint32_t md_cmu_get_clock(void)
{
    return md_system_clock;
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

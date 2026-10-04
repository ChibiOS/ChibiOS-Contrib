/**********************************************************************************
 *
 * @file    md_cmu.h
 * @brief   Header file of CMU module driver.
 *
 * @date    14 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          14 Dec. 2022    Lisq            the first version
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


#ifndef __MD_CMU_H__
#define __MD_CMU_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------ */
#include "md_utils.h"
#include "md_syscfg.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_CMU CMU
  * @brief CMU micro driver

  * @{
  */

/* Exported Macros ----------------------------------------------------------- */

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/* Exported Types ------------------------------------------------------------ */

/** @defgroup MD_CMU_MD_Public_Types CMU Public Types
  * @{
  */
/**
  * @brief CMU state structure definition
  */
typedef enum
{
    MD_CMU_CLOCK_HRC48M  = 0x1U,   /**< HRC48M */
    MD_CMU_CLOCK_LRC     = 0x2U,   /**< LRC */
    MD_CMU_CLOCK_HOSC    = 0x3U,   /**< HOSC */
    MD_CMU_CLOCK_PLL     = 0x4U,   /**< PLL */
    MD_CMU_CLOCK_HRC4M   = 0x5U,   /**< HRC4M */
} md_cmu_clock_t;

/**
  * @brief PLL output clock
  */
typedef enum
{
    MD_CMU_PLL_OUTPUT_72M = 0x0U,   /**< 72MHz */
    MD_CMU_PLL_OUTPUT_64M = 0x2U,   /**< 64MHz */
    MD_CMU_PLL_OUTPUT_48M = 0x3U,   /**< 48MHz */
} md_cmu_pll_output_t;

/**
  * @brief PLL referance clock
  */
typedef enum
{
    MD_CMU_PLL_INPUT_HRC4M   = 0x0U,    /**< HRC4M */
    MD_CMU_PLL_INPUT_HOSC4M  = 0x1U,    /**< HOSC4M */
    MD_CMU_PLL_INPUT_HOSC8M  = 0x2U,    /**< HOSC8M */
} md_cmu_pll_input_t;

/**
  * @brief Frequency division select bit
  */
typedef enum
{
    MD_CMU_DIV_1    = 0x0U,     /**< Division by 1 */
    MD_CMU_DIV_2    = 0x1U,     /**< Division by 2 */
    MD_CMU_DIV_4    = 0x2U,     /**< Division by 4 */
    MD_CMU_DIV_8    = 0x3U,     /**< Division by 8 */
    MD_CMU_DIV_16   = 0x4U,     /**< Division by 16 */
    MD_CMU_DIV_32   = 0x5U,     /**< Division by 32 */
    MD_CMU_DIV_64   = 0x6U,     /**< Division by 64 */
    MD_CMU_DIV_128  = 0x7U,     /**< Division by 128 */
    MD_CMU_DIV_256  = 0x8U,     /**< Division by 256 */
    MD_CMU_DIV_512  = 0x9U,     /**< Division by 512 */
    MD_CMU_DIV_1024 = 0xAU,     /**< Division by 1024 */
    MD_CMU_DIV_2048 = 0xBU,     /**< Division by 2048 */
    MD_CMU_DIV_4096 = 0xCU,     /**< Division by 4096 */
} md_cmu_div_t;

/**
  * @brief Bus type
  */
typedef enum
{
    MD_CMU_SYS    = 0x1U,     /**< SYS bus */
    MD_CMU_PCLK   = 0x2U,     /**< APB bus */
} md_cmu_bus_t;
/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_CMU_Public_Functions CMU Public Functions
  * @{
  */
/** @defgroup MD_CMU_Public_Functions_Group2 CSR
  * @{
  */
/**
  * @brief  Configure system clock.
  * @param  clk: Clock parameter. can be one of the following values:
  *         @arg @ref MD_CMU_CLOCK_HRC48M
  *         @arg @ref MD_CMU_CLOCK_LRC
  *         @arg @ref MD_CMU_CLOCK_HOSC
  *         @arg @ref MD_CMU_CLOCK_PLL
  *         @arg @ref MD_CMU_CLOCK_HRC4M
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_config_clock(md_cmu_clock_t clk)
{
    MODIFY_REG(CMU->CSR, CMU_CSR_SYS_CMD_MSK, clk);
}

/**
  * @brief  Get system clock.
  * @retval Current system clock. Can be one of the following values:
  *         @arg @ref MD_CMU_CLOCK_HRC48M
  *         @arg @ref MD_CMU_CLOCK_LRC
  *         @arg @ref MD_CMU_CLOCK_HOSC
  *         @arg @ref MD_CMU_CLOCK_PLL
  *         @arg @ref MD_CMU_CLOCK_HRC4M
  */
__STATIC_INLINE uint32_t md_cmu_get_current_clock(void)
{
    return READ_BITS(CMU->CSR, CMU_CSR_SYS_STU_MSK, CMU_CSR_SYS_STU_POSS);
}

/**
  * @brief  Get Status of switch clock.
  * @retval Status:
  *         - 0: Ready
  *         - 1: Busy
  */
__STATIC_INLINE uint32_t md_cmu_get_sys_rdyn(void)
{
    return READ_BITS(CMU->CSR, CMU_CSR_SYS_RDYN_MSK, CMU_CSR_SYS_RDYN_POS);
}

/**
  * @brief  Configure system clock filter.
  * @param  cft: Value of the following:
  *         - 0x55: Select system clock filter
  *         - 0xAA: Bypass system clock filter
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_config_cft(uint32_t cft)
{
    MODIFY_REG(CMU->CSR, CMU_CSR_CFT_CMD_MSK, cft << CMU_CSR_CFT_CMD_POSS);
}

/**
  * @brief  Get system clock.
  * @retval Current filter clock:
  *         - 0: Select system clock filter
  *         - 1: Bypass system clock filter
  */
__STATIC_INLINE uint32_t md_cmu_get_active_filter(void)
{
    return READ_BITS(CMU->CSR, CMU_CSR_CFT_STU_MSK, CMU_CSR_CFT_STU_POS);
}

/**
  * @brief  Get Status of switch filter clock.
  * @retval Status:
  *         - 0: Ready
  *         - 1: Busy
  */
__STATIC_INLINE uint32_t md_cmu_get_cft_rdyn(void)
{
    return READ_BITS(CMU->CSR, CMU_CSR_CFT_RDYN_MSK, CMU_CSR_CFT_RDYN_POS);
}
/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group3 CFGR
  * @{
  */

/**
  * @brief  Select PLLCLK to be I2S clock source
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_sel_i2sclk_pll(void)
{
    SET_BIT(CMU->CFGR, CMU_CFGR_I2SSW_MSK);
}

/**
  * @brief  Select HOSCCLK to be I2S clock source
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_sel_i2sclk_hosc(void)
{
    CLEAR_BIT(CMU->CFGR, CMU_CFGR_I2SSW_MSK);
}

/**
  * @brief  Gets I2S clock source
  * @retval Value:
  *         - 0: HOSCCLK
  *         - 1: PLLCLK
  */
__STATIC_INLINE uint32_t md_cmu_get_i2sclk(void)
{
    return READ_BITS(CMU->CFGR, CMU_CFGR_I2SSW_MSK, CMU_CFGR_I2SSW_POS);
}

/**
  * @brief  Select PLLCLK to be USB clock source
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_sel_usbclk_pll(void)
{
    SET_BIT(CMU->CFGR, CMU_CFGR_USBSW_MSK);
}

/**
  * @brief  Select HRC48CLK to be USB clock source
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_sel_usbclk_hrc48(void)
{
    CLEAR_BIT(CMU->CFGR, CMU_CFGR_USBSW_MSK);
}

/**
  * @brief  Gets USB clock source
  * @retval Value:
  *         - 0: HRC48CLK
  *         - 1: PLLCLK
  */
__STATIC_INLINE uint32_t md_cmu_get_usbclk(void)
{
    return READ_BITS(CMU->CFGR, CMU_CFGR_USBSW_MSK, CMU_CFGR_USBSW_POS);
}

/**
  * @brief  Sets SYSCLK divider.
  * @param  div: Value of the following:
  *         - 0x0: Fclk / 1
  *         - 0x1: Fclk / 2
  *         - 0x2: Fclk / 4
  *         - 0x3: Fclk / 8
  *         - 0x4: Fclk / 16
  *         - 0x5: Fclk / 32
  *         - 0x6: Fclk / 64
  *         - 0x7: Fclk / 128
  *         - 0x8: Fclk / 256
  *         - 0x9: Fclk / 512
  *         - 0xA: Fclk / 1024
  *         - 0xB: Fclk / 2048
  *         - 0xC: Fclk / 4096
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_set_sysclk_div(uint32_t div)
{
    MODIFY_REG(CMU->CFGR, CMU_CFGR_SYSDIV_MSK, div << CMU_CFGR_SYSDIV_POSS);
}

/**
  * @brief  Gets SYSCLK divider.
  * @retval  divider: Value of the following:
  *         - 0x0: Fclk / 1
  *         - 0x1: Fclk / 2
  *         - 0x2: Fclk / 4
  *         - 0x3: Fclk / 8
  *         - 0x4: Fclk / 16
  *         - 0x5: Fclk / 32
  *         - 0x6: Fclk / 64
  *         - 0x7: Fclk / 128
  *         - 0x8: Fclk / 256
  *         - 0x9: Fclk / 512
  *         - 0xA: Fclk / 1024
  *         - 0xB: Fclk / 2048
  *         - 0xC: Fclk / 4096
  */
__STATIC_INLINE uint32_t md_cmu_get_sysclk_div(void)
{
    return READ_BITS(CMU->CFGR, CMU_CFGR_SYSDIV_MSK, CMU_CFGR_SYSDIV_POSS);
}

/**
  * @brief  Sets PCLK divider.
  * @param  div: Value of the following:
  *         - 0x0: Fclk / 1
  *         - 0x1: Fclk / 2
  *         - 0x2: Fclk / 4
  *         - 0x3: Fclk / 8
  *         - 0x4: Fclk / 16
  *         - 0x5: Fclk / 32
  *         - 0x6: Fclk / 64
  *         - 0x7: Fclk / 128
  *         - 0x8: Fclk / 256
  *         - 0x9: Fclk / 512
  *         - 0xA: Fclk / 1024
  *         - 0xB: Fclk / 2048
  *         - 0xC: Fclk / 4096
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_set_pclk_div(uint32_t div)
{
    MODIFY_REG(CMU->CFGR, CMU_CFGR_PCLKDIV_MSK, div << CMU_CFGR_PCLKDIV_POSS);
}

/**
  * @brief  Gets PCLK divider.
  * @retval  divider: Value of the following:
  *         - 0x0: Fclk / 1
  *         - 0x1: Fclk / 2
  *         - 0x2: Fclk / 4
  *         - 0x3: Fclk / 8
  *         - 0x4: Fclk / 16
  *         - 0x5: Fclk / 32
  *         - 0x6: Fclk / 64
  *         - 0x7: Fclk / 128
  *         - 0x8: Fclk / 256
  *         - 0x9: Fclk / 512
  *         - 0xA: Fclk / 1024
  *         - 0xB: Fclk / 2048
  *         - 0xC: Fclk / 4096
  */
__STATIC_INLINE uint32_t md_cmu_get_pclk_div(void)
{
    return READ_BITS(CMU->CFGR, CMU_CFGR_PCLKDIV_MSK, CMU_CFGR_PCLKDIV_POSS);
}

/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group4 CLKENR
  * @{
  */
/**
  * @brief  Enable HOSC
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_hosc(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_HOSCEN_MSK);
}

/**
  * @brief  Disable HOSC
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_hosc(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_HOSCEN_MSK);
}

/**
  * @brief  Gets HOSC status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hosc(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_HOSCEN_MSK, CMU_CLKENR_HOSCEN_POS);
}

/**
  * @brief  Enable HRC48M
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_hrc48m(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_HRC48MEN_MSK);
}

/**
  * @brief  Disable HRC48M
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_hrc48m(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_HRC48MEN_MSK);
}

/**
  * @brief  Gets HRC48M status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hrc48m(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_HRC48MEN_MSK, CMU_CLKENR_HRC48MEN_POS);
}

/**
  * @brief  Enable HRC4M
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_hrc4m(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_HRC4MEN_MSK);
}

/**
  * @brief  Disable HRC4M
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_hrc4m(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_HRC4MEN_MSK);
}

/**
  * @brief  Gets HRC4M status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hrc4m(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_HRC4MEN_MSK, CMU_CLKENR_HRC4MEN_POS);
}

/**
  * @brief  Enable PLL
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_pll(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_PLLEN_MSK);
}

/**
  * @brief  Disable PLL
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_pll(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_PLLEN_MSK);
}

/**
  * @brief  Gets PLL status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_pll(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_PLLEN_MSK, CMU_CLKENR_PLLEN_POS);
}

/**
  * @brief  Enable HRC48M Bypass Filter
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_hrc48mflybps(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_HRC48MFLYBPS_MSK);
}

/**
  * @brief  Disable HRC48M Bypass Filter
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_hrc48mflybps(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_HRC48MFLYBPS_MSK);
}

/**
  * @brief  Gets HRC48M Bypass Filter status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hrc48mflybps(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_HRC48MFLYBPS_MSK, CMU_CLKENR_HRC48MFLYBPS_POS);
}

/**
  * @brief  Enable I2SCK
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_i2sck(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_I2SCKEN_MSK);
}

/**
  * @brief  Disable I2SCK
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_i2sck(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_I2SCKEN_MSK);
}

/**
  * @brief  Gets I2SCK status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_i2sck(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_I2SCKEN_MSK, CMU_CLKENR_I2SCKEN_POS);
}

/**
  * @brief  Enable USBCK 48M
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_usbck48(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_USBCKEN_MSK);
}

/**
  * @brief  Disable USBCK 48M
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_usbck48(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_USBCKEN_MSK);
}

/**
  * @brief  Gets USBCK 48M status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_usbck48(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_USBCKEN_MSK, CMU_CLKENR_USBCKEN_POS);
}

/**
  * @brief  Enable HOSC32K
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_hosc32k(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_HOSC32K_MSK);
}

/**
  * @brief  Disable HOSC32K
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_hosc32k(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_HOSC32K_MSK);
}

/**
  * @brief  Gets HOSC32K status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hosc32k(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_HOSC32K_MSK, CMU_CLKENR_HOSC32K_POS);
}

/**
  * @brief  Enable HOSCBPS
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_hoscbps(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_HOSCBPS_MSK);
}

/**
  * @brief  Disable HOSCBPS
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_hoscbps(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_HOSCBPS_MSK);
}

/**
  * @brief  Gets HOSCBPS status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hoscbps(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_HOSCBPS_MSK, CMU_CLKENR_HOSCBPS_POS);
}

/**
  * @brief  Enable HOSCFLYBPS
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_enable_hoscflybps(void)
{
    SET_BIT(CMU->CLKENR, CMU_CLKENR_HOSCFLYBPS_MSK);
}

/**
  * @brief  Disable HOSCFLYBPS
  * @retval NONE
  */
__STATIC_INLINE void md_cmu_disable_hoscflybps(void)
{
    CLEAR_BIT(CMU->CLKENR, CMU_CLKENR_HOSCFLYBPS_MSK);
}

/**
  * @brief  Gets HOSCFLYBPS status
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hoscflybps(void)
{
    return READ_BITS(CMU->CLKENR, CMU_CLKENR_HOSCFLYBPS_MSK, CMU_CLKENR_HOSCFLYBPS_POS);
}

/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group5 CLKSR
  * @{
  */
/**
  * @brief  Check the HOSC is active.
  * @retval Status:
  *         - 0: Not active
  *         - 1: Active
  */
__STATIC_INLINE uint32_t md_cmu_is_active_state_hosc(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_HOSCACT_MSK, CMU_CLKSR_HOSCACT_POS);
}

/**
  * @brief  Check the PLL is active.
  * @retval Status:
  *         - 0: Not active
  *         - 1: Active
  */
__STATIC_INLINE uint32_t md_cmu_is_active_state_pll(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_PLLACT_MSK, CMU_CLKSR_PLLACT_POS);
}

/**
  * @brief  Check the HRC4M is active.
  * @retval Status:
  *         - 0: Not active
  *         - 1: Active
  */
__STATIC_INLINE uint32_t md_cmu_is_active_state_hrc4m(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_HRC4MACT_MSK, CMU_CLKSR_HRC4MACT_POS);
}

/**
  * @brief  Check the HRC48M is active.
  * @retval Status:
  *         - 0: Not active
  *         - 1: Active
  */
__STATIC_INLINE uint32_t md_cmu_is_active_state_hrc48m(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_HRC48MACT_MSK, CMU_CLKSR_HRC48MACT_POS);
}

/**
  * @brief  Check the HOSC is stable.
  * @retval Status:
  *         - 0: Not stable
  *         - 1: Stable
  */
__STATIC_INLINE uint32_t md_cmu_is_stable_state_hosc(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_HOSCRDY_MSK, CMU_CLKSR_HOSCRDY_POS);
}

/**
  * @brief  Check the HRC4MRDY is stable.
  * @retval Status:
  *         - 0: Not stable
  *         - 1: Stable
  */
__STATIC_INLINE uint32_t md_cmu_is_stable_state_hrc4mrdy(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_HRC4MRDY_MSK, CMU_CLKSR_HRC4MRDY_POS);
}

/**
  * @brief  Check the HRC48MRDY is stable.
  * @retval Status:
  *         - 0: Not stable
  *         - 1: Stable
  */
__STATIC_INLINE uint32_t md_cmu_is_stable_state_hrc48mrdy(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_HRC48MRDY_MSK, CMU_CLKSR_HRC48MRDY_POS);
}

/**
  * @brief  Check the LRCRDY is stable.
  * @retval Status:
  *         - 0: Not stable
  *         - 1: Stable
  */
__STATIC_INLINE uint32_t md_cmu_is_stable_state_lrcrdy(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_LRCRDY_MSK, CMU_CLKSR_LRCRDY_POS);
}

/**
  * @brief  Check the PLLRDY is stable.
  * @retval Status:
  *         - 0: Not stable
  *         - 1: Stable
  */
__STATIC_INLINE uint32_t md_cmu_is_stable_state_pllrdy(void)
{
    return READ_BITS(CMU->CLKSR, CMU_CLKSR_PLLRDY_MSK, CMU_CLKSR_PLLRDY_POS);
}

/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group6 HOSCCFG
  * @{
  */
/**
  * @brief  Sets HOSC frequence.
  * @param  clk: The value of following:
  *         - 0x0: 4MHz
  *         - 0x1: 8MHz
  *         - 0x2: 12MHz
  *         - 0x3: 16MHz
  *         - 0x4: 20MHz
  *         - 0x5: 24MHz
  * @retval None
  */
__STATIC_INLINE void md_cmu_set_hosc_freq(uint32_t clk)
{
    MODIFY_REG(CMU->HOSCCFG, CMU_HOSCCFG_FREQ_MSK, clk << CMU_HOSCCFG_FREQ_POSS);
}

/**
  * @brief  Gets HOSC frequence.
  * @retval  clk: The value of following:
  *         - 0x0: 4MHz
  *         - 0x1: 8MHz
  *         - 0x2: 12MHz
  *         - 0x3: 16MHz
  *         - 0x4: 20MHz
  *         - 0x5: 24MHz
  */
__STATIC_INLINE uint32_t md_cmu_get_hosc_freq(void)
{
    return READ_BITS(CMU->HOSCCFG, CMU_HOSCCFG_FREQ_MSK, CMU_HOSCCFG_FREQ_POSS);
}
/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group7 HOSMCR
  * @{
  */
/**
  * @brief  Enable HOSC safe.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_hosc_safe(void)
{
    SET_BIT(CMU->HOSMCR, CMU_HOSMCR_EN_MSK);
}

/**
  * @brief  Disable HOSC safe.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_hosc_safe(void)
{
    CLEAR_BIT(CMU->HOSMCR, CMU_HOSMCR_EN_MSK);
}

/**
  * @brief  Check HOSC safe is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hosc_safe(void)
{
    return READ_BITS(CMU->HOSMCR, CMU_HOSMCR_EN_MSK, CMU_HOSMCR_EN_POS);
}

/**
  * @brief  Gets HOSC stop state.
  * @retval Status:
  *         - 0: HOSC run
  *         - 1: HOSC stop
  */
__STATIC_INLINE uint32_t md_cmu_get_hosc_stop_state(void)
{
    return READ_BITS(CMU->HOSMCR, CMU_HOSMCR_FLAG_MSK, CMU_HOSMCR_FLAG_POS);
}

/**
  * @brief  Sets HOSC frequence region
  * @param  clk: The value of following:
  *         - 0: 1-2MHz
  *         - 1: 2-4MHz
  *         - 2: 4-8MHz
  *         - 3: 8-16MHz
  *         - 4: 16-24MHz
  * @retval None
  */
__STATIC_INLINE void md_cmu_set_hosc_freq_region(uint32_t clk)
{
    MODIFY_REG(CMU->HOSMCR, CMU_HOSMCR_FRQS_MSK, clk << CMU_HOSMCR_FRQS_POSS);
}

/**
  * @brief  Gets HOSC frequence region
  * @retval The value of following:
  *         - 0: 1-2MHz
  *         - 1: 2-4MHz
  *         - 2: 4-8MHz
  *         - 3: 8-16MHz
  *         - 4: 16-24MHz
  */
__STATIC_INLINE uint32_t md_cmu_get_hosc_freq_region(void)
{
    return READ_BITS(CMU->HOSMCR, CMU_HOSMCR_FRQS_MSK, CMU_HOSMCR_FRQS_POSS);
}

/**
  * @brief  Enable STR interrupt
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_hosc_str_interrupt(void)
{
    SET_BIT(CMU->HOSMCR, CMU_HOSMCR_STRIE_MSK);
}

/**
  * @brief  Disable STR interrupt
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_hosc_str_interrupt(void)
{
    CLEAR_BIT(CMU->HOSMCR, CMU_HOSMCR_STRIE_MSK);
}

/**
  * @brief  Check STR interrupt is enable.
  * @retval Status.
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hosc_str_interrupt(void)
{
    return READ_BITS(CMU->HOSMCR, CMU_HOSMCR_STRIE_MSK, CMU_HOSMCR_STRIE_POS);
}

/**
  * @brief  Enable STP interrupt
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_hosc_stp_interrupt(void)
{
    SET_BIT(CMU->HOSMCR, CMU_HOSMCR_STPIE_MSK);
}

/**
  * @brief  Disable STP interrupt
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_hosc_stp_interrupt(void)
{
    CLEAR_BIT(CMU->HOSMCR, CMU_HOSMCR_STPIE_MSK);
}

/**
  * @brief  Check STP interrupt is enable.
  * @retval Status.
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hosc_stp_interrupt(void)
{
    return READ_BITS(CMU->HOSMCR, CMU_HOSMCR_STPIE_MSK, CMU_HOSMCR_STPIE_POS);
}

/**
  * @brief  Gets STR flag state
  * @retval State
  */
__STATIC_INLINE uint32_t md_cmu_is_active_flag_hosc_str(void)
{
    return READ_BITS(CMU->HOSMCR, CMU_HOSMCR_STRIF_MSK, CMU_HOSMCR_STRIF_POS);
}

/**
  * @brief  Clear STR flag
  * @retval None
  */
__STATIC_INLINE void md_cmu_clear_flag_hosc_str(void)
{
    SET_BIT(CMU->HOSMCR, CMU_HOSMCR_STRIF_MSK);
}

/**
  * @brief  Gets STP flag state
  * @retval State
  */
__STATIC_INLINE uint32_t md_cmu_is_active_flag_hosc_stp(void)
{
    return READ_BITS(CMU->HOSMCR, CMU_HOSMCR_STPIF_MSK, CMU_HOSMCR_STPIF_POS);
}

/**
  * @brief  Clear STP flag
  * @retval None
  */
__STATIC_INLINE void md_cmu_clear_flag_hosc_stp(void)
{
    SET_BIT(CMU->HOSMCR, CMU_HOSMCR_STPIF_MSK);
}

/**
  * @brief  Enable HOSC NMI interrupt
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_hosc_nmi_interrupt(void)
{
    SET_BIT(CMU->HOSMCR, CMU_HOSMCR_NMIE_MSK);
}

/**
  * @brief  Disable HOSC NMI interrupt
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_hosc_nmi_interrupt(void)
{
    CLEAR_BIT(CMU->HOSMCR, CMU_HOSMCR_NMIE_MSK);
}

/**
  * @brief  Check HOSC NMI interrupt is enable.
  * @retval Status.
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hosc_nmi_interrupt(void)
{
    return READ_BITS(CMU->HOSMCR, CMU_HOSMCR_NMIE_MSK, CMU_HOSMCR_NMIE_POS);
}

/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group8 PULMCR
  * @{
  */
/**
  * @brief  Enable PLL unlock management.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_pll_unlock_manage(void)
{
    SET_BIT(CMU->PULMCR, CMU_PULMCR_EN_MSK);
}

/**
  * @brief  Disable PLL unlock management.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_pll_unlock_manage(void)
{
    CLEAR_BIT(CMU->PULMCR, CMU_PULMCR_EN_MSK);
}

/**
  * @brief  Check PLL unlock management is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_pll_unlock_manage(void)
{
    return READ_BITS(CMU->PULMCR, CMU_PULMCR_EN_MSK, CMU_PULMCR_EN_POS);
}

/**
  * @brief  Gets current selected clock.
  * @retval Status:
  *         - 0: PLL
  *         - 1: HRC
  */
__STATIC_INLINE uint32_t md_cmu_get_current_sel_clock(void)
{
    return READ_BITS(CMU->PULMCR, CMU_PULMCR_CLKS_MSK, CMU_PULMCR_CLKS_POS);
}

/**
  * @brief  Select mode after PLL unlock
  * @param  sel : Value of following:
  *         - 0: No operation
  *         - 1: Switch to HRC
  *         - 2: Switch to HRC, and switch back to PLL when PLL re-lock
  * @retval None
  */
__STATIC_INLINE void md_cmu_set_pll_unlock_mode(uint32_t sel)
{
    MODIFY_REG(CMU->PULMCR, CMU_PULMCR_MODE_MSK, sel << CMU_PULMCR_MODE_POSS);
}

/**
  * @brief  Gets high clock output type
  * @retval Value of following:
  *         - 0: No operation
  *         - 1: Switch to HRC
  *         - 2: Switch to HRC, and switch back to PLL when PLL re-lock
  */
__STATIC_INLINE uint32_t md_cmu_get_pll_unlock_mode(void)
{
    return READ_BITS(CMU->PULMCR, CMU_PULMCR_MODE_MSK, CMU_PULMCR_MODE_POSS);
}

/**
  * @brief  Enable PLL lock interrupt.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_pll_lock_interrupt(void)
{
    SET_BIT(CMU->PULMCR, CMU_PULMCR_LCKIE_MSK);
}

/**
  * @brief  Disable PLL lock interrupt.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_pll_lock_interrupt(void)
{
    CLEAR_BIT(CMU->PULMCR, CMU_PULMCR_LCKIE_MSK);
}

/**
  * @brief  Check PLL lock interrupt is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_pll_lock_interrupt(void)
{
    return READ_BITS(CMU->PULMCR, CMU_PULMCR_LCKIE_MSK, CMU_PULMCR_LCKIE_POS);
}

/**
  * @brief  Enable PLL unlock interrupt.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_pll_unlock_interrupt(void)
{
    SET_BIT(CMU->PULMCR, CMU_PULMCR_ULKIE_MSK);
}

/**
  * @brief  Disable PLL unlock interrupt.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_pll_unlock_interrupt(void)
{
    CLEAR_BIT(CMU->PULMCR, CMU_PULMCR_ULKIE_MSK);
}

/**
  * @brief  Check PLL unlock interrupt is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_pll_unlock_interrupt(void)
{
    return READ_BITS(CMU->PULMCR, CMU_PULMCR_ULKIE_MSK, CMU_PULMCR_ULKIE_POS);
}

/**
  * @brief  Clear PLL lock flag.
  * @retval None
  */
__STATIC_INLINE void md_cmu_clear_flag_pll_lock(void)
{
    SET_BIT(CMU->PULMCR, CMU_PULMCR_LCKIF_MSK);
}

/**
  * @brief  Get PLL lock flag.
  * @retval Status:
  *         - 0: Flag is clear
  *         - 1: PLL lock
  */
__STATIC_INLINE uint32_t md_cmu_is_active_flag_pll_lock(void)
{
    return READ_BITS(CMU->PULMCR, CMU_PULMCR_LCKIF_MSK, CMU_PULMCR_LCKIF_POS);
}

/**
  * @brief  Clear PLL unlock flag.
  * @retval None
  */
__STATIC_INLINE void md_cmu_clear_flag_pll_unlock(void)
{
    SET_BIT(CMU->PULMCR, CMU_PULMCR_ULKIF_MSK);
}

/**
  * @brief  Get PLL unlock flag.
  * @retval Status:
  *         - 0: Flag is clear
  *         - 1: PLL unlock
  */
__STATIC_INLINE uint32_t md_cmu_is_active_flag_pll_unlock(void)
{
    return READ_BITS(CMU->PULMCR, CMU_PULMCR_ULKIF_MSK, CMU_PULMCR_ULKIF_POS);
}

/**
  * @brief  Enable PLL NMI interrupt
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_pll_nmi_interrupt(void)
{
    SET_BIT(CMU->PULMCR, CMU_PULMCR_NMIE_MSK);
}

/**
  * @brief  Disable PLL NMI interrupt
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_pll_nmi_it(void)
{
    CLEAR_BIT(CMU->PULMCR, CMU_PULMCR_NMIE_MSK);
}

/**
  * @brief  Check PLL NMI interrupt is enable.
  * @retval Status.
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_pll_nmi_it(void)
{
    return READ_BITS(CMU->PULMCR, CMU_PULMCR_NMIE_MSK, CMU_PULMCR_NMIE_POS);
}

/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group9 CLKOCR
  * @{
  */
/**
  * @brief  Enable HSC output.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_hsco(void)
{
    SET_BIT(CMU->CLKOCR, CMU_CLKOCR_HSCOEN_MSK);
}

/**
  * @brief  Disable HSC output.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_hsco(void)
{
    CLEAR_BIT(CMU->CLKOCR, CMU_CLKOCR_HSCOEN_MSK);
}

/**
  * @brief  Check HSC output is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_hsco(void)
{
    return READ_BITS(CMU->CLKOCR, CMU_CLKOCR_HSCOEN_MSK, CMU_CLKOCR_HSCOEN_POS);
}

/**
  * @brief  Sets high clock output type
  * @param  sel : Value of following:
  *         - 0: HOSC
  *         - 1: HOSM
  *         - 2: HRC4M
  *         - 3: LRC
  *         - 4: SYSCLK
  *         - 5: HOSC32K
  *         - 6: HRC48M
  *         - 7: PLL
  * @retval None
  */
__STATIC_INLINE void md_cmu_set_hsco_type(uint32_t sel)
{
    MODIFY_REG(CMU->CLKOCR, CMU_CLKOCR_HSCOS_MSK, sel << CMU_CLKOCR_HSCOS_POSS);
}

/**
  * @brief  Gets high clock output type
  * @retval Value of following:
  *         - 0: HOSC
  *         - 1: HOSM
  *         - 2: HRC4M
  *         - 3: LRC
  *         - 4: SYSCLK
  *         - 5: HOSC32K
  *         - 6: HRC48M
  *         - 7: PLL
  */
__STATIC_INLINE uint32_t md_cmu_get_hsco_type(void)
{
    return READ_BITS(CMU->CLKOCR, CMU_CLKOCR_HSCOS_MSK, CMU_CLKOCR_HSCOS_POSS);
}

/**
  * @brief  Sets high clock output divider
  * @param  div: Value of following:
  *         - 0: HSC / 1
  *         - 1: HSC / 2
  *         - 2: HSC / 4
  *         - 3: HSC / 8
  *         - 4: HSC / 16
  *         - 5: HSC / 32
  *         - 6: HSC / 64
  *         - 7: HSC / 128
  * @retval None
  */
__STATIC_INLINE void md_cmu_set_hsco_div(uint32_t div)
{
    MODIFY_REG(CMU->CLKOCR, CMU_CLKOCR_HSCODIV_MSK, div << CMU_CLKOCR_HSCODIV_POSS);
}

/**
  * @brief  Gets high clock output divider
  * @retval Value of following:
  *         - 0: HSC / 1
  *         - 1: HSC / 2
  *         - 2: HSC / 4
  *         - 3: HSC / 8
  *         - 4: HSC / 16
  *         - 5: HSC / 32
  *         - 6: HSC / 64
  *         - 7: HSC / 128
  */
__STATIC_INLINE uint32_t md_cmu_get_hsco_div(void)
{
    return READ_BITS(CMU->CLKOCR, CMU_CLKOCR_HSCODIV_MSK, CMU_CLKOCR_HSCODIV_POSS);
}

/**
  * @brief  Enable LSC output.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_lsco(void)
{
    SET_BIT(CMU->CLKOCR, CMU_CLKOCR_LSCOEN_MSK);
}

/**
  * @brief  Disable LSC output.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_lsco(void)
{
    CLEAR_BIT(CMU->CLKOCR, CMU_CLKOCR_LSCOEN_MSK);
}

/**
  * @brief  Check LSC output is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_lsco(void)
{
    return READ_BITS(CMU->CLKOCR, CMU_CLKOCR_LSCOEN_MSK, CMU_CLKOCR_LSCOEN_POS);
}

/**
  * @brief  Sets low clock output type
  * @param  sel : Value of following:
  *         - 0: BUZZ
  *         - 1: LRC
  * @retval None
  */
__STATIC_INLINE void md_cmu_set_lsco_type(uint32_t sel)
{
    MODIFY_REG(CMU->CLKOCR, CMU_CLKOCR_LSCOS_MSK, sel << CMU_CLKOCR_LSCOS_POSS);
}

/**
  * @brief  Gets low clock output type
  * @retval Value of following:
  *         - 0: BUZZ
  *         - 1: LRC
  */
__STATIC_INLINE uint32_t md_cmu_get_lsco_type(void)
{
    return READ_BITS(CMU->CLKOCR, CMU_CLKOCR_LSCOS_MSK, CMU_CLKOCR_LSCOS_POSS);
}
/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group10 BUZZCR
  * @{
  */
/**
  * @brief  Enable BUZZ output.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_buzz(void)
{
    SET_BIT(CMU->BUZZCR, CMU_BUZZCR_EN_MSK);
}

/**
  * @brief  Disable BUZZ output.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_buzz(void)
{
    CLEAR_BIT(CMU->BUZZCR, CMU_BUZZCR_EN_MSK);
}

/**
  * @brief  Check BUZZ output is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_buzz(void)
{
    return READ_BITS(CMU->BUZZCR, CMU_BUZZCR_EN_MSK, CMU_BUZZCR_EN_POS);
}

/**
  * @brief  Sets BUZZ divider
  * @param  div: Value of following:
  *         - 0: Freq / 2
  *         - 1: Freq / 4
  *         - 2: Freq / 8
  *         - 3: Freq / 16
  *         - 4: Freq / 32
  *         - 5: Freq / 64
  *         - 6: Freq / 128
  *         - 7: Freq / 256
  * @retval None
  */
__STATIC_INLINE void md_cmu_set_buzz_div(uint32_t div)
{
    MODIFY_REG(CMU->BUZZCR, CMU_BUZZCR_DIV_MSK, div << CMU_BUZZCR_DIV_POSS);
}

/**
  * @brief  Gets BUZZ divider
  * @retval Value of following:
  *         - 0: Freq / 2
  *         - 1: Freq / 4
  *         - 2: Freq / 8
  *         - 3: Freq / 16
  *         - 4: Freq / 32
  *         - 5: Freq / 64
  *         - 6: Freq / 128
  *         - 7: Freq / 256
  */
__STATIC_INLINE uint32_t md_cmu_get_buzz_div(void)
{
    return READ_BITS(CMU->BUZZCR, CMU_BUZZCR_DIV_MSK, CMU_BUZZCR_DIV_POSS);
}

/**
  * @brief  Sets BUZZ data
  * @param  data: Region is from 0x00 to 0xFFFF
  * @retval None
  */
__STATIC_INLINE void md_cmu_set_buzz_data(uint32_t data)
{
    MODIFY_REG(CMU->BUZZCR, CMU_BUZZCR_DAT_MSK, data << CMU_BUZZCR_DAT_POSS);
}

/**
  * @brief  Gets BUZZ data
  * @retval BUZZ data
  */
__STATIC_INLINE uint32_t md_cmu_get_buzz_data(uint32_t data)
{
    return READ_BITS(CMU->BUZZCR, CMU_BUZZCR_DAT_MSK, CMU_BUZZCR_DAT_POSS);
}
/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group11 AHBENR
  * @{
  */
/**
  * @brief  Enable GPIO peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_gpio(void)
{
    SET_BIT(CMU->AHBENR, CMU_AHBENR_GPIOEN_MSK);
}

/**
  * @brief  Disable GPIO peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_gpio(void)
{
    CLEAR_BIT(CMU->AHBENR, CMU_AHBENR_GPIOEN_MSK);
}

/**
  * @brief  Check GPIO peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_gpio(void)
{
    return READ_BITS(CMU->AHBENR, CMU_AHBENR_GPIOEN_MSK, CMU_AHBENR_GPIOEN_POS);
}

/**
  * @brief  Enable CRC peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_crc(void)
{
    SET_BIT(CMU->AHBENR, CMU_AHBENR_CRCEN_MSK);
}

/**
  * @brief  Disable CRC peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_crc(void)
{
    CLEAR_BIT(CMU->AHBENR, CMU_AHBENR_CRCEN_MSK);
}

/**
  * @brief  Check CRC peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_crc(void)
{
    return READ_BITS(CMU->AHBENR, CMU_AHBENR_CRCEN_MSK, CMU_AHBENR_CRCEN_POS);
}

/**
  * @brief  Enable DMA peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_dma(void)
{
    SET_BIT(CMU->AHBENR, CMU_AHBENR_DMAEN_MSK);
}

/**
  * @brief  Disable DMA peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_dma(void)
{
    CLEAR_BIT(CMU->AHBENR, CMU_AHBENR_DMAEN_MSK);
}

/**
  * @brief  Check DMA peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_dma(void)
{
    return READ_BITS(CMU->AHBENR, CMU_AHBENR_DMAEN_MSK, CMU_AHBENR_DMAEN_POS);
}

/**
  * @brief  Enable PIS peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_pis(void)
{
    SET_BIT(CMU->AHBENR, CMU_AHBENR_PISEN_MSK);
}

/**
  * @brief  Disable PIS peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_pis(void)
{
    CLEAR_BIT(CMU->AHBENR, CMU_AHBENR_PISEN_MSK);
}

/**
  * @brief  Check PIS peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_pis(void)
{
    return READ_BITS(CMU->AHBENR, CMU_AHBENR_PISEN_MSK, CMU_AHBENR_PISEN_POS);
}

/**
  * @brief  Enable USB peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_usb(void)
{
    SET_BIT(CMU->AHBENR, CMU_AHBENR_USBEN_MSK);
}

/**
  * @brief  Disable USB peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_usb(void)
{
    CLEAR_BIT(CMU->AHBENR, CMU_AHBENR_USBEN_MSK);
}

/**
  * @brief  Check USB peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_usb(void)
{
    return READ_BITS(CMU->AHBENR, CMU_AHBENR_USBEN_MSK, CMU_AHBENR_USBEN_POS);
}

/**
  * @brief  Enable CSU peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_csu(void)
{
    SET_BIT(CMU->AHBENR, CMU_AHBENR_CSUEN_MSK);
}

/**
  * @brief  Disable CSU peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_csu(void)
{
    CLEAR_BIT(CMU->AHBENR, CMU_AHBENR_CSUEN_MSK);
}

/**
  * @brief  Check CSU peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_csu(void)
{
    return READ_BITS(CMU->AHBENR, CMU_AHBENR_CSUEN_MSK, CMU_AHBENR_CSUEN_POS);
}

/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group12 APBENR
  * @{
  */
/**
  * @brief  Enable AD16C4T0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_ad16c4t0(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_AD16C4T0EN_MSK);
}

/**
  * @brief  Disable AD16C4T0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_ad16c4t0(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_AD16C4T0EN_MSK);
}

/**
  * @brief  Check AD16C4T0 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_ad16c4t0(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_AD16C4T0EN_MSK, CMU_APBENR_AD16C4T0EN_POS);
}

/**
  * @brief  Enable BS16T0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_bs16t0(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_BS16T0EN_MSK);
}

/**
  * @brief  Disable BS16T0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_bs16t0(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_BS16T0EN_MSK);
}

/**
  * @brief  Check BS16T0 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_bs16t0(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_BS16T0EN_MSK, CMU_APBENR_BS16T0EN_POS);
}

/**
  * @brief  Enable GP16C4T0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_gp16c4t0(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_GP16C4T0EN_MSK);
}

/**
  * @brief  Disable GP16C4T0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_gp16c4t0(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_GP16C4T0EN_MSK);
}

/**
  * @brief  Check GP16C4T0 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_gp16c4t0(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_GP16C4T0EN_MSK, CMU_APBENR_GP16C4T0EN_POS);
}

/**
  * @brief  Enable GP16C4T1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_gp16c4t1(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_GP16C4T1EN_MSK);
}

/**
  * @brief  Disable GP16C4T1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_gp16c4t1(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_GP16C4T1EN_MSK);
}

/**
  * @brief  Check GP16C4T1 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_gp16c4t1(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_GP16C4T1EN_MSK, CMU_APBENR_GP16C4T1EN_POS);
}

/**
  * @brief  Enable GP16C4T2 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_gp16c4t2(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_GP16C4T2EN_MSK);
}

/**
  * @brief  Disable GP16C4T2 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_gp16c4t2(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_GP16C4T2EN_MSK);
}

/**
  * @brief  Check GP16C4T2 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_gp16c4t2(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_GP16C4T2EN_MSK, CMU_APBENR_GP16C4T2EN_POS);
}

/**
  * @brief  Enable EUART0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_euart0(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_EUART0EN_MSK);
}

/**
  * @brief  Disable EUART0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_euart0(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_EUART0EN_MSK);
}

/**
  * @brief  Check EUART0 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_euart0(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_EUART0EN_MSK, CMU_APBENR_EUART0EN_POS);
}

/**
  * @brief  Enable EUART1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_euart1(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_EUART1EN_MSK);
}

/**
  * @brief  Disable EUART1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_euart1(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_EUART1EN_MSK);
}

/**
  * @brief  Check EUART1 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_euart1(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_EUART1EN_MSK, CMU_APBENR_EUART1EN_POS);
}

/**
  * @brief  Enable CUART0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_cuart0(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_CUART0EN_MSK);
}

/**
  * @brief  Disable CUART0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_cuart0(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_CUART0EN_MSK);
}

/**
  * @brief  Check CUART0 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_cuart0(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_CUART0EN_MSK, CMU_APBENR_CUART0EN_POS);
}

/**
  * @brief  Enable CUART1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_cuart1(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_CUART1EN_MSK);
}

/**
  * @brief  Disable CUART1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_cuart1(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_CUART1EN_MSK);
}

/**
  * @brief  Check CUART1 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_cuart1(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_CUART1EN_MSK, CMU_APBENR_CUART1EN_POS);
}

/**
  * @brief  Enable CUART2 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_cuart2(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_CUART2EN_MSK);
}

/**
  * @brief  Disable CUART2 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_cuart2(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_CUART2EN_MSK);
}

/**
  * @brief  Check CUART2 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_cuart2(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_CUART2EN_MSK, CMU_APBENR_CUART2EN_POS);
}

/**
  * @brief  Enable SPI0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_spi0(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_SPI0EN_MSK);
}

/**
  * @brief  Disable SPI0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_spi0(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_SPI0EN_MSK);
}

/**
  * @brief  Check SPI0 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_spi0(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_SPI0EN_MSK, CMU_APBENR_SPI0EN_POS);
}

/**
  * @brief  Enable SPI1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_spi1(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_SPI1EN_MSK);
}

/**
  * @brief  Disable SPI1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_spi1(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_SPI1EN_MSK);
}

/**
  * @brief  Check SPI1 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_spi1(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_SPI1EN_MSK, CMU_APBENR_SPI1EN_POS);
}

/**
  * @brief  Enable I2C0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_i2c0(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_I2C0EN_MSK);
}

/**
  * @brief  Disable I2C0 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_i2c0(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_I2C0EN_MSK);
}

/**
  * @brief  Check I2C0 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_i2c0(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_I2C0EN_MSK, CMU_APBENR_I2C0EN_POS);
}

/**
  * @brief  Enable I2C1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_i2c1(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_I2C1EN_MSK);
}

/**
  * @brief  Disable I2C1 peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_i2c1(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_I2C1EN_MSK);
}

/**
  * @brief  Check I2C1 peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_i2c1(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_I2C1EN_MSK, CMU_APBENR_I2C1EN_POS);
}

/**
  * @brief  Enable WWDT peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_wwdt(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_WWDTEN_MSK);
}

/**
  * @brief  Disable WWDT peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_wwdt(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_WWDTEN_MSK);
}

/**
  * @brief  Check WWDT peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_wwdt(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_WWDTEN_MSK, CMU_APBENR_WWDTEN_POS);
}

/**
  * @brief  Enable IWDT peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_iwdt(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_IWDTEN_MSK);
}

/**
  * @brief  Disable IWDT peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_iwdt(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_IWDTEN_MSK);
}

/**
  * @brief  Check IWDT peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_iwdt(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_IWDTEN_MSK, CMU_APBENR_IWDTEN_POS);
}

/**
  * @brief  Enable DBGC peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_dbgc(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_DBGCEN_MSK);
}

/**
  * @brief  Disable DBGC peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_dbgc(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_DBGCEN_MSK);
}

/**
  * @brief  Check DBGC peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_dbgc(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_DBGCEN_MSK, CMU_APBENR_DBGCEN_POS);
}

/**
  * @brief  Enable ADC peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_adc(void)
{
    SET_BIT(CMU->APBENR, CMU_APBENR_ADCEN_MSK);
}

/**
  * @brief  Disable ADC peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_adc(void)
{
    CLEAR_BIT(CMU->APBENR, CMU_APBENR_ADCEN_MSK);
}

/**
  * @brief  Check ADC peripheral is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_perh_adc(void)
{
    return READ_BITS(CMU->APBENR, CMU_APBENR_ADCEN_MSK, CMU_APBENR_ADCEN_POS);
}

/**
  * @brief  Enable ALL peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_perh_all(void)
{
    WRITE_REG(CMU->AHBENR, 0xFFFFFFFF);
    WRITE_REG(CMU->APBENR, 0xFFFFFFFF);
}

/**
  * @brief  Disable ALL peripheral.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_perh_all(void)
{
    WRITE_REG(CMU->AHBENR, 0x0);
    WRITE_REG(CMU->APBENR, 0x0);
}
/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group13 LPENR
  * @{
  */

/**
  * @brief  Enable PLL low power mode.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_lp_pll(void)
{
    SET_BIT(CMU->LPENR, CMU_LPENR_PLLEN_MSK);
}

/**
  * @brief  Disable PLL low power mode.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_lp_pll(void)
{
    CLEAR_BIT(CMU->LPENR, CMU_LPENR_PLLEN_MSK);
}

/**
  * @brief  Check PLL low power mode is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_lp_pll(void)
{
    return READ_BITS(CMU->LPENR, CMU_LPENR_PLLEN_MSK, CMU_LPENR_PLLEN_POS);
}

/**
  * @brief  Enable HRC4M low power mode.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_lp_hrc4m(void)
{
    SET_BIT(CMU->LPENR, CMU_LPENR_HRC4MEN_MSK);
}

/**
  * @brief  Disable HRC4M low power mode.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_lp_hrc4m(void)
{
    CLEAR_BIT(CMU->LPENR, CMU_LPENR_HRC4MEN_MSK);
}

/**
  * @brief  Check HRC4M low power mode is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_lp_hrc4m(void)
{
    return READ_BITS(CMU->LPENR, CMU_LPENR_HRC4MEN_MSK, CMU_LPENR_HRC4MEN_POS);
}

/**
  * @brief  Enable HRC48M low power mode.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_lp_hrc48m(void)
{
    SET_BIT(CMU->LPENR, CMU_LPENR_HRC48MEN_MSK);
}

/**
  * @brief  Disable HRC48M low power mode.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_lp_hrc48m(void)
{
    CLEAR_BIT(CMU->LPENR, CMU_LPENR_HRC48MEN_MSK);
}

/**
  * @brief  Check HRC48M low power mode is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_lp_hrc48m(void)
{
    return READ_BITS(CMU->LPENR, CMU_LPENR_HRC48MEN_MSK, CMU_LPENR_HRC48MEN_POS);
}

/**
  * @brief  Enable HOSC low power mode.
  * @retval None
  */
__STATIC_INLINE void md_cmu_enable_lp_hosc(void)
{
    SET_BIT(CMU->LPENR, CMU_LPENR_HOSCEN_MSK);
}

/**
  * @brief  Disable HOSC low power mode.
  * @retval None
  */
__STATIC_INLINE void md_cmu_disable_lp_hosc(void)
{
    CLEAR_BIT(CMU->LPENR, CMU_LPENR_HOSCEN_MSK);
}

/**
  * @brief  Check HOSC low power mode is enable.
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_cmu_is_enabled_lp_hosc(void)
{
    return READ_BITS(CMU->LPENR, CMU_LPENR_HOSCEN_MSK, CMU_LPENR_HOSCEN_POS);
}

/**
  * @}
  */
/** @defgroup MD_CMU_Public_Functions_Group1 Initialization and Get BUS Clock value
  * @{
  */
extern md_status_t md_cmu_clock_config_default(void);
extern md_status_t md_cmu_clock_config(md_cmu_clock_t clk, uint32_t clock);
extern void md_cmu_pll_config(md_cmu_pll_input_t input, md_cmu_pll_output_t output);
extern void md_cmu_div_config(md_cmu_bus_t bus, md_cmu_div_t clk_div);
extern uint32_t md_cmu_get_sys_clock(void);
extern uint32_t md_cmu_get_pclk_clock(void);
extern uint32_t md_cmu_get_clock(void);
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
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __MD_CMU_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

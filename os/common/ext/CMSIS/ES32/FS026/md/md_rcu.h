/**********************************************************************************
 *
 * @file    md_rcu.h
 * @brief   header file of md_rcu.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *          24 Mar 2022     AE Team         Modify MD Driver
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MD_RCU_H__
#define __MD_RCU_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include <stdbool.h>
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */


/** @defgroup MD_RCU RCU
  * @brief RCU micro driver
  * @{
  */

/** @defgroup MD_RCU_Pubulic_Types RCU Pubulic Types
  * @{
  */
/**
  * @brief MD_RCU_Public_Types RCU Init Type
  */

typedef struct
{
    uint32_t  Mpre;        /*! MCO clock prescaler  */
    uint32_t  Msw;         /*! MCO clock output  */
    uint32_t  PllSrc;      /*! PLL clock source  */
    uint32_t  Pllclk;      /*! PLL clock   */
    uint32_t  Ppre;        /*! APB clock prescaler  */
    uint32_t  Hpre;        /*! AHB clock prescaler  */
    uint32_t  Sw;          /*! system clock   */
    uint32_t  HS_Clock;    /*! high spped clock enable  */
    uint32_t  LS_Clock;    /*! low spped clock enable  */
} md_rcu_init_typedef;

/**
  * @}
  */
/** @defgroup MD_RCU_Public_Macros RCU Public Macros
  * @{
  */

#ifndef __HOSC
#define __HOSC          ( 8000000UL)
#endif
#define __HRC           ( 4000000UL)
#define __LOSC          (   32768UL)
#define __LRC           (   32000UL)
#define __PLL0_CLKREF   ( 4000000UL)
#define __HRC48         (48000000UL)

/**
  * @brief MD_RCU_LOSCRDY_FLAG LOSC clock ready flag
  */
#define MD_RCU_LOSCRDY_NOT_READY    (0x00000000UL)  /** @brief LOSC oscillator not ready */
#define MD_RCU_LOSCRDY_READY        (0x00000001UL)  /** @brief LOSC oscillator ready */

/**
  * @brief MD_RCU_LRCRDY_FLAG LRC clock ready flag
  */
#define MD_RCU_LRCRDY_NOT_READY     (0x00000000UL)  /** @brief LRC oscillator not ready */
#define MD_RCU_LRCRDY_READY         (0x00000001UL)  /** @brief LRC oscillator ready */

/**
  * @brief MD_RCU_PLL0_FLAG PLL0 clock ready flag
  */
#define MD_RCU_PLL0RDY_NOT_READY    (0x00000000UL)  /** @brief PLL0 not ready */
#define MD_RCU_PLL0RDY_READY        (0x00000001UL)  /** @brief PLL0 ready */

/**
  * @brief MD_RCU_HRC48RDY_FLAG HRC48 clock ready flag
  */
#define MD_RCU_HRC48RDY_NOT_READY   (0x00000000UL)  /** @brief HRC48 oscillator not ready */
#define MD_RCU_HRC48RDY_READY       (0x00000001UL)  /** @brief HRC48 oscillator ready */

/**
  * @brief MD_RCU_HOSCRDY_FLAG HOSC clock ready flag
  */
#define MD_RCU_HOSCRDY_NOT_READY    (0x00000000UL)  /** @brief HOSC oscillator not ready */
#define MD_RCU_HOSCRDY_READY        (0x00000001UL)  /** @brief HOSC oscillator ready */

/**
  * @brief MD_RCU_HRCRDY_FLAG HRC clock ready flag
  */
#define MD_RCU_HRCRDY_NOT_READY     (0x00000000UL)  /** @brief HRC oscillator not ready */
#define MD_RCU_HRCRDY_READY         (0x00000001UL)  /** @brief HRC oscillator ready */

/**
  * @brief MD_RCU_MCO_DIV Microcontroller clock output select
  */
#define MD_RCU_MPRE_MCO_DIV1        (0x00000000UL)  /** @brief MCO DIV = 1  */
#define MD_RCU_MPRE_MCO_DIV2        (0x00000001UL)  /** @brief MCO DIV = 2  */
#define MD_RCU_MPRE_MCO_DIV4        (0x00000002UL)  /** @brief MCO DIV = 4  */
#define MD_RCU_MPRE_MCO_DIV8        (0x00000003UL)  /** @brief MCO DIV = 8  */
#define MD_RCU_MPRE_MCO_DIV16       (0x00000004UL)  /** @brief MCO DIV = 16 */
#define MD_RCU_MPRE_MCO_DIV32       (0x00000005UL)  /** @brief MCO DIV = 32 */
#define MD_RCU_MPRE_MCO_DIV64       (0x00000006UL)  /** @brief MCO DIV = 64 */
#define MD_RCU_MPRE_MCO_DIV128      (0x00000007UL)  /** @brief MCO DIV = 128*/

/**
  * @brief MD_RCU_MCO_OUTPUT Microcontroller clock output select
  */
#define MD_RCU_MSW_MCO_DISABLE      (0x00000000UL)  /** @brief MCO output disabled, no clock on MCO */
#define MD_RCU_MSW_MCO_LRC          (0x00000001UL)  /** @brief Internal low speed (LRC) oscillator clock selected */
#define MD_RCU_MSW_MCO_LOSC         (0x00000002UL)  /** @brief External low speed (LOSC) oscillator clock selected */
#define MD_RCU_MSW_MCO_HRC          (0x00000003UL)  /** @brief Internal high speed (HRC) oscillator clock selected */
#define MD_RCU_MSW_MCO_HOSC         (0x00000004UL)  /** @brief External high speed (HOSC) oscillator clock selected */
#define MD_RCU_MSW_MCO_HRC48        (0x00000005UL)  /** @brief HRC48 clock selected */
#define MD_RCU_MSW_MCO_PLL0         (0x00000006UL)  /** @brief PLL0 clock selected */
#define MD_RCU_MSW_MCO_SYSCLK       (0x00000008UL)  /** @brief System clock selected(SYSCLK) */
#define MD_RCU_MSW_MCO_HCLK         (0x00000009UL)  /** @brief AHB clock selected(HCLK) */
#define MD_RCU_MSW_MCO_PCLK         (0x0000000AUL)  /** @brief APB clock selected(PCLK) */

/**
  * @brief MD_RCU_PLLSRC PLL reference clock source
  */
#define MD_RCU_PLLSRC_HRC         (0x00000000UL)  /** @brief HRC/PREDIV selected as PLL reference clock */
#define MD_RCU_PLLSRC_HOSC        (0x00000001UL)  /** @brief HOSC/PREDIV selected as PLL reference clock */
#define MD_RCU_PLLSRC_HRC48       (0x00000002UL)  /** @brief HRC48/PREDIV selected as PLL reference clock */

/**
  * @brief MD_RCU_PLL_CLK PLL reference clock source
  */
#define MD_RCU_PLLCLK_PASS          0
#define MD_RCU_PLLCLK_4M            4000000
#define MD_RCU_PLLCLK_8M            8000000
#define MD_RCU_PLLCLK_12M           12000000
#define MD_RCU_PLLCLK_16M           16000000
#define MD_RCU_PLLCLK_24M           24000000
#define MD_RCU_PLLCLK_32M           32000000
#define MD_RCU_PLLCLK_36M           36000000
#define MD_RCU_PLLCLK_40M           40000000
#define MD_RCU_PLLCLK_48M           48000000
#define MD_RCU_PLLCLK_64M           64000000
#define MD_RCU_PLLCLK_72M           72000000

/**
  * @brief MD_RCU_PLL_DIV Microcontroller clock output select
  */
#define MD_RCU_PREDIV_PLL_DIV1      (0x00000000UL)  /** @brief PLL DIV = 1 */
#define MD_RCU_PREDIV_PLL_DIV2      (0x00000001UL)  /** @brief PLL DIV = 2 */
#define MD_RCU_PREDIV_PLL_DIV3      (0x00000002UL)  /** @brief PLL DIV = 3 */
#define MD_RCU_PREDIV_PLL_DIV4      (0x00000003UL)  /** @brief PLL DIV = 4 */
#define MD_RCU_PREDIV_PLL_DIV5      (0x00000004UL)  /** @brief PLL DIV = 5 */
#define MD_RCU_PREDIV_PLL_DIV6      (0x00000005UL)  /** @brief PLL DIV = 6 */
#define MD_RCU_PREDIV_PLL_DIV7      (0x00000006UL)  /** @brief PLL DIV = 7 */
#define MD_RCU_PREDIV_PLL_DIV8      (0x00000007UL)  /** @brief PLL DIV = 8 */
#define MD_RCU_PREDIV_PLL_DIV9      (0x00000008UL)  /** @brief PLL DIV = 9 */
#define MD_RCU_PREDIV_PLL_DIV10     (0x00000009UL)  /** @brief PLL DIV = 10*/
#define MD_RCU_PREDIV_PLL_DIV11     (0x0000000AUL)  /** @brief PLL DIV = 11*/
#define MD_RCU_PREDIV_PLL_DIV12     (0x0000000BUL)  /** @brief PLL DIV = 12*/
#define MD_RCU_PREDIV_PLL_DIV13     (0x0000000CUL)  /** @brief PLL DIV = 13*/
#define MD_RCU_PREDIV_PLL_DIV14     (0x0000000DUL)  /** @brief PLL DIV = 14*/
#define MD_RCU_PREDIV_PLL_DIV15     (0x0000000EUL)  /** @brief PLL DIV = 15*/
#define MD_RCU_PREDIV_PLL_DIV16     (0x0000000FUL)  /** @brief PLL DIV = 16*/

/**
  * @brief MD_RCU_APB_CLK_DIV APB clock prescaler(PCLK)
  */
#define MD_RCU_PPRE_HCLK_DIV_1    (0x00000000UL)  /** @brief HCLK not divided */
#define MD_RCU_PPRE_HCLK_DIV_2    (0x00000004UL)  /** @brief HCLK divided by 2 */
#define MD_RCU_PPRE_HCLK_DIV_4    (0x00000005UL)  /** @brief HCLK divided by 4 */
#define MD_RCU_PPRE_HCLK_DIV_8    (0x00000006UL)  /** @brief HCLK divided by 8 */
#define MD_RCU_PPRE_HCLK_DIV_16   (0x00000007UL)  /** @brief HCLK divided by 16 */


/**
  * @brief MD_RCU_AHB_CLK_DIV AHB clock prescaler(HCLK)
  */
#define MD_RCU_HPRE_SYSCLK_DIV_1    (0x00000000UL)  /** @brief SYSCLK not divided    */
#define MD_RCU_HPRE_SYSCLK_DIV_2    (0x00000008UL)  /** @brief SYSCLK divided by 2   */
#define MD_RCU_HPRE_SYSCLK_DIV_4    (0x00000009UL)  /** @brief SYSCLK divided by 4   */
#define MD_RCU_HPRE_SYSCLK_DIV_8    (0x0000000AUL)  /** @brief SYSCLK divided by 8   */
#define MD_RCU_HPRE_SYSCLK_DIV_16   (0x0000000BUL)  /** @brief SYSCLK divided by 16  */
#define MD_RCU_HPRE_SYSCLK_DIV_64   (0x0000000CUL)  /** @brief SYSCLK divided by 64  */
#define MD_RCU_HPRE_SYSCLK_DIV_128  (0x0000000DUL)  /** @brief SYSCLK divided by 128 */
#define MD_RCU_HPRE_SYSCLK_DIV_256  (0x0000000EUL)  /** @brief SYSCLK divided by 256 */
#define MD_RCU_HPRE_SYSCLK_DIV_512  (0x0000000FUL)  /** @brief SYSCLK divided by 512 */

/**
  * @brief MD_RCU_SYS_CLK_SWS System clock switch(SYSCLK)
  */
#define MD_RCU_SWS_SYSCLK_HRC       (0x00000000UL)  /** @brief HRC selected as system clock   */
#define MD_RCU_SWS_SYSCLK_HOSC      (0x00000001UL)  /** @brief HOSC selected as system clock  */
#define MD_RCU_SWS_SYSCLK_PLL0      (0x00000002UL)  /** @brief PLL0 selected as system clock  */
#define MD_RCU_SWS_SYSCLK_HRC48     (0x00000003UL)  /** @brief HRC48 selected as system clock */

/**
  * @brief MD_RCU_SYS_CLK_SW System clock switch(SYSCLK)
  */
#define MD_RCU_SW_SYSCLK_HRC        (0x00000000UL)  /** @brief HRC selected as system clock   */
#define MD_RCU_SW_SYSCLK_HOSC       (0x00000001UL)  /** @brief HOSC selected as system clock  */
#define MD_RCU_SW_SYSCLK_PLL0       (0x00000002UL)  /** @brief PLL0 selected as system clock  */
#define MD_RCU_SW_SYSCLK_HRC48      (0x00000003UL)  /** @brief HRC48 selected as system clock */

/**
  * @brief MD_RCU_PLL0_DIV
  */
#define MD_RCU_FM_PLL0_DIV_8        (0x00000000UL)
#define MD_RCU_FM_PLL0_DIV_16       (0x00000001UL)
#define MD_RCU_FM_PLL0_DIV_32       (0x00000002UL)
#define MD_RCU_FM_PLL0_DIV_64       (0x00000003UL)

/**
  * @brief MD_RCU_USBCLK USB Clock Source Select
  */
#define MD_RCU_USBSW_USBCLK_HRC48CLK  (0x00000000UL)
#define MD_RCU_USBSW_USBCLK_PLL0CLK   (0x00000002UL)

/**
  * @brief MD_RCU_I2SCKSL I2S Clock Source Select
  */
#define MD_RCU_I2SSW_I2SCLK_HRC48CLK  (0x00000000UL)
#define MD_RCU_I2SSW_I2SCLK_HOSCCLK   (0x00000001UL)
#define MD_RCU_I2SSW_I2SCLK_PLL0CLK   (0x00000002UL)

/**
  * @brief MD_RCU_SRCSEL Calibration Clock Source Select
  */
#define MD_RCU_SRCSEL_HRC_4MHZ      (0x00000000UL)
#define MD_RCU_SRCSEL_HRC_48MHZ     (0x00000001UL)

/**
  * @brief MD_RCU_HRC48SEL HRC48 calibration value selection
  */
#define MD_RCU_HRC48SEL_OPTIONBYTE  (0x00000000UL)
#define MD_RCU_HRC48SEL_HRC48TRIM   (0x00000001UL)

/**
  * @brief MD_RCU_HRCSEL HRCSEL calibration value selection
  */
#define MD_RCU_HRCSEL_OPTIONBYTE    (0x00000000UL)
#define MD_RCU_HRCSEL_HRCTRIM       (0x00000001UL)

/**
  * @brief MD_RCU_LRCSEL LRCSEL calibration value selection
  */
#define MD_RCU_LRCSEL_OPTIONBYTE    (0x00000000UL)
#define MD_RCU_LRCSEL_LRCTRIM       (0x00000001UL)

/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions RCU Public Functions
  * @{
  */

/** @defgroup MD_RCU_Public_Functions_Group2 CON
  * @{
  */
/**
  * @brief  Set RCU_CON Register
  * @param  rcu RCU Instance
  * @param  con
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_con(RCU_TypeDef *rcu, uint32_t con)
{
    WRITE_REG(rcu->CON, con);
}

/**
  * @brief  Get RCU_CON Register
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rcu_get_con(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->CON));
}

/**
  * @brief  Clock security system enable(CSS)
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_hosc_css(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->CON, RCU_CON_CSSON);
}

/**
  * @brief  Clock security system disable(CSS)
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_hosc_css(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->CON, RCU_CON_CSSON);
}

/**
  * @brief  Get Clock security system (CSS)
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Hosc css enable
  *         @arg 0x0 : Hosc css disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_hosc_css(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_CSSON) == (RCU_CON_CSSON));
}

/**
  * @brief  Get PLL0 clock ready flag
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_PLL0RDY_NOT_READY
  *         @arg @ref MD_RCU_PLL0RDY_READY
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_pll0_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_PLL0RDY) == (RCU_CON_PLL0RDY));
}

/**
  * @brief  PLL0 enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_pll0(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->CON, RCU_CON_PLL0ON);
}

/**
  * @brief  PLL0 disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_pll0(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->CON, RCU_CON_PLL0ON);
}

/**
  * @brief  Get PLL0 bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : PLL0 enable
  *         @arg 0x0 : PLL0 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_pll0(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_PLL0ON) == (RCU_CON_PLL0ON));
}

/**
  * @brief  Get HRC48 clock ready flag
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_HRC48RDY_NOT_READY
  *         @arg @ref MD_RCU_HRC48RDY_READY
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_hrc48_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_HRC48RDY) == (RCU_CON_HRC48RDY));
}

/**
  * @brief  HRC48 enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_hrc48(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->CON, RCU_CON_HRC48ON);
}

/**
  * @brief  HRC48 disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_hrc48(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->CON, RCU_CON_HRC48ON);
}

/**
  * @brief  Get HRC48 bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : HRC48 enable
  *         @arg 0x0 : HRC48 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_hrc48(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_HRC48ON) == (RCU_CON_HRC48ON));
}

/**
  * @brief  HOSC bypass mode enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_hosc_bypass(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->CON, RCU_CON_HOSCBYP);
}

/**
  * @brief  HOSC bypass mode disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_hosc_bypass(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->CON, RCU_CON_HOSCBYP);
}

/**
  * @brief  Get HOSC bypass mode bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Hosc bypass enable
  *         @arg 0x0 : Hosc bypass disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_hosc_bypass(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_HOSCBYP) == (RCU_CON_HOSCBYP));
}

/**
  * @brief  Get HOSC clock ready flag
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_HOSCRDY_NOT_READY
  *         @arg @ref MD_RCU_HOSCRDY_READY
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_hosc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_HOSCRDY) == (RCU_CON_HOSCRDY));
}

/**
  * @brief  HOSC enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_hosc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->CON, RCU_CON_HOSCON);
}

/**
  * @brief  HOSC disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_hosc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->CON, RCU_CON_HOSCON);
}

/**
  * @brief  Get HOSC bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Hosc enable
  *         @arg 0x0 : Hosc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_hosc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_HOSCON) == (RCU_CON_HOSCON));
}

/**
  * @brief  Get HRCRDY clock ready flag
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_HRCRDY_NOT_READY
  *         @arg @ref MD_RCU_HRCRDY_READY
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_hrc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_HRCRDY) == (RCU_CON_HRCRDY));
}

/**
  * @brief  HRC enbale bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_hrc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->CON, RCU_CON_HRCON);
}

/**
  * @brief  HRC disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_hrc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->CON, RCU_CON_HRCON);
}

/**
  * @brief  Get HRC bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Hrc enable
  *         @arg 0x0 : Hrc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_hrc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->CON, RCU_CON_HRCON) == (RCU_CON_HRCON));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group3 CFG
  * @{
  */
/**
  * @brief  Set RCU_CFG Register
  * @param  rcu RCU Instance
  * @param  cfg
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_cfg(RCU_TypeDef *rcu, uint32_t cfg)
{
    WRITE_REG(rcu->CFG, cfg);
}

/**
  * @brief  Get RCU_CFG Register
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rcu_get_cfg(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->CFG));
}

/**
  * @brief  Set MCO clock output prescaler
  * @note   Output Frequency = MCO/(MPRE+1)
  * @param  rcu RCU Instance
  * @param  mpre This parameter can be one of the following values:
  *         @arg @ref MD_RCU_MPRE_MCO_DIV1
  *         @arg @ref MD_RCU_MPRE_MCO_DIV2
  *         @arg @ref MD_RCU_MPRE_MCO_DIV4
  *         @arg @ref MD_RCU_MPRE_MCO_DIV8
  *         @arg @ref MD_RCU_MPRE_MCO_DIV16
  *         @arg @ref MD_RCU_MPRE_MCO_DIV32
  *         @arg @ref MD_RCU_MPRE_MCO_DIV64
  *         @arg @ref MD_RCU_MPRE_MCO_DIV128
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_mco_div(RCU_TypeDef *rcu, uint32_t mpre)
{
    MODIFY_REG(rcu->CFG, RCU_CFG_MPRE, mpre << RCU_CFG_MPRE_POSS);
}

/**
  * @brief  Get MCO clock output prescaler
  * @note   Output Frequency = MCO/(MPRE+1)
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_MPRE_MCO_DIV1
  *         @arg @ref MD_RCU_MPRE_MCO_DIV2
  *         @arg @ref MD_RCU_MPRE_MCO_DIV4
  *         @arg @ref MD_RCU_MPRE_MCO_DIV8
  *         @arg @ref MD_RCU_MPRE_MCO_DIV16
  *         @arg @ref MD_RCU_MPRE_MCO_DIV32
  *         @arg @ref MD_RCU_MPRE_MCO_DIV64
  *         @arg @ref MD_RCU_MPRE_MCO_DIV128
  */
__STATIC_INLINE uint32_t md_rcu_get_mco_div(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG, RCU_CFG_MPRE) >> RCU_CFG_MPRE_POSS);
}

/**
  * @brief  Set MCO clock output (MCO)
  * @param  rcu RCU Instance
  *         @arg @ref MD_RCU_MSW_MCO_DISABLE
  *         @arg @ref MD_RCU_MSW_MCO_LRC
  *         @arg @ref MD_RCU_MSW_MCO_LOSC
  *         @arg @ref MD_RCU_MSW_MCO_HRC
  *         @arg @ref MD_RCU_MSW_MCO_HOSC
  *         @arg @ref MD_RCU_MSW_MCO_HRC48
  *         @arg @ref MD_RCU_MSW_MCO_PLL0
  *         @arg @ref MD_RCU_MSW_MCO_SYSCLK
  *         @arg @ref MD_RCU_MSW_MCO_HCLK
  *         @arg @ref MD_RCU_MSW_MCO_PCLK
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_mco_source(RCU_TypeDef *rcu, uint32_t msw)
{
    MODIFY_REG(rcu->CFG, RCU_CFG_MSW, msw << RCU_CFG_MSW_POSS);
}

/**
  * @brief  Get Microcontroller clock output (MCO)
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_MSW_MCO_DISABLE
  *         @arg @ref MD_RCU_MSW_MCO_LRC
  *         @arg @ref MD_RCU_MSW_MCO_LOSC
  *         @arg @ref MD_RCU_MSW_MCO_HRC
  *         @arg @ref MD_RCU_MSW_MCO_HOSC
  *         @arg @ref MD_RCU_MSW_MCO_HRC48
  *         @arg @ref MD_RCU_MSW_MCO_PLL0
  *         @arg @ref MD_RCU_MSW_MCO_SYSCLK
  *         @arg @ref MD_RCU_MSW_MCO_HCLK
  *         @arg @ref MD_RCU_MSW_MCO_PCLK
  */
__STATIC_INLINE uint32_t md_rcu_get_mco_source(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG, RCU_CFG_MSW) >> RCU_CFG_MSW_POSS);
}

/**
  * @brief  Set PLL0 reference clock source
  * @param  rcu RCU Instance
  *         @arg @ref MD_RCU_PLLSRC_HRC
  *         @arg @ref MD_RCU_PLLSRC_HOSC
  *         @arg @ref MD_RCU_PLLSRC_HRC48
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_pll_source(RCU_TypeDef *rcu, uint32_t pllsrc)
{
    MODIFY_REG(rcu->CFG, RCU_CFG_PLLSRC, pllsrc << RCU_CFG_PLLSRC_POSS);
}

/**
  * @brief  Get PLL0/1 reference clock source
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_PLLSRC_HRC
  *         @arg @ref MD_RCU_PLLSRC_HOSC
  *         @arg @ref MD_RCU_PLLSRC_HRC48
  */
__STATIC_INLINE uint32_t md_rcu_get_pll_source(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG, RCU_CFG_PLLSRC) >> RCU_CFG_PLLSRC_POSS);
}

/**
  * @brief  Set PLL0 reference clock pre-divider
  * @param  rcu RCU Instance
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV1
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV2
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV3
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV4
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV5
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV6
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV7
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV8
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV9
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV10
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV11
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV12
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV13
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV14
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV15
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV16
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_pll_prediv(RCU_TypeDef *rcu, uint32_t prediv)
{
    MODIFY_REG(rcu->CFG, RCU_CFG_PREDIV, prediv << RCU_CFG_PREDIV_POSS);
}
/**
  * @brief  Get PLL0 reference clock pre-divider
  * @note
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV1
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV2
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV3
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV4
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV5
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV6
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV7
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV8
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV9
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV10
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV11
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV12
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV13
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV14
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV15
  *         @arg @ref MD_RCU_PREDIV_PLL_DIV16
  */
__STATIC_INLINE uint32_t md_rcu_get_pll_prediv(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG, RCU_CFG_PREDIV) >> RCU_CFG_PREDIV_POSS);
}

/**
  * @brief  Set APB clock prescaler(PCLK)
  * @param  rcu RCU Instance
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_1
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_2
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_4
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_8
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_16
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_pclk_div(RCU_TypeDef *rcu, uint32_t ppre)
{
    MODIFY_REG(rcu->CFG, RCU_CFG_PPRE, ppre << RCU_CFG_PPRE_POSS);
}

/**
  * @brief  Get APB clock prescaler(PCLK)
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_1
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_2
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_4
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_8
  *         @arg @ref MD_RCU_PPRE_HCLK_DIV_16
  */
__STATIC_INLINE uint32_t md_rcu_get_pclk_div(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG, RCU_CFG_PPRE) >> RCU_CFG_PPRE_POSS);
}

/**
  * @brief  Set AHB clock prescaler(HCLK)
  * @param  rcu RCU Instance
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_1
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_2
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_4
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_8
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_16
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_64
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_128
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_256
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_512
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_hclk_div(RCU_TypeDef *rcu, uint32_t hpre)
{
    MODIFY_REG(rcu->CFG, RCU_CFG_HPRE, hpre << RCU_CFG_HPRE_POSS);
}

/**
  * @brief  Get AHB clock prescaler(HCLK)
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_1
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_2
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_4
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_8
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_16
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_64
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_128
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_256
  *         @arg @ref MD_RCU_HPRE_SYSCLK_DIV_512
  */
__STATIC_INLINE uint32_t md_rcu_get_hclk_div(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG, RCU_CFG_HPRE) >> RCU_CFG_HPRE_POSS);
}

/**
  * @brief  System clock selection status
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_SWS_SYSCLK_HRC
  *         @arg @ref MD_RCU_SWS_SYSCLK_HOSC
  *         @arg @ref MD_RCU_SWS_SYSCLK_PLL0
  *         @arg @ref MD_RCU_SWS_SYSCLK_HRC48
  */
__STATIC_INLINE uint32_t md_rcu_get_current_system_clock(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG, RCU_CFG_SWS) >> RCU_CFG_SWS_POSS);
}

/**
  * @brief  Select system clock (SYSCLK) source
  * @param  rcu RCU Instance
  *         @arg @ref MD_RCU_SW_SYSCLK_HRC
  *         @arg @ref MD_RCU_SW_SYSCLK_HOSC
  *         @arg @ref MD_RCU_SW_SYSCLK_PLL0
  *         @arg @ref MD_RCU_SW_SYSCLK_HRC48
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_system_clock_source(RCU_TypeDef *rcu, uint32_t sw)
{
    MODIFY_REG(rcu->CFG, RCU_CFG_SW, sw << RCU_CFG_SW_POSS);
}

/**
  * @brief  Get Select system clock (SYSCLK) source
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_SW_SYSCLK_HRC
  *         @arg @ref MD_RCU_SW_SYSCLK_HOSC
  *         @arg @ref MD_RCU_SW_SYSCLK_PLL0
  *         @arg @ref MD_RCU_SW_SYSCLK_HRC48
  */
__STATIC_INLINE uint32_t md_rcu_get_system_clock_source(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG, RCU_CFG_SW) >> RCU_CFG_SW_POSS);
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group4 PLL0
  * @{
  */
/**
  * @brief  Set RCU_PLL0 Register
  * @param  rcu RCU Instance
  * @param  pll0
  */
__STATIC_INLINE void md_rcu_set_pll0(RCU_TypeDef *rcu, uint32_t pll0)
{
    WRITE_REG(rcu->PLL0, pll0);
}

/**
  * @brief  Get RCU_PLL0 Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_rcu_get_pll0(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->PLL0));
}

/**
  * @brief  Set PLL0 VCO frequency fractional multiplication value
  * @param  rcu RCU Instance
  * @param  fk
  * @retval
  */
__STATIC_INLINE void md_rcu_set_pll0_fk(RCU_TypeDef *rcu, uint32_t fk)
{
    MODIFY_REG(rcu->PLL0, RCU_PLL0_FK, (fk << RCU_PLL0_FK_POSS));
}

/**
  * @brief  Get PLL0 VCO frequency fractional multiplication value
  * @param  rcu RCU Instance
  * @retval fk
  */
__STATIC_INLINE uint32_t md_rcu_get_pll0_fk(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->PLL0, RCU_PLL0_FK) >> RCU_PLL0_FK_POSS);
}

/**
  * @brief  Set PLL0 VCO frequency integer multiplication value
  * @param  rcu RCU Instance
  * @param  fn
  * @retval
  */
__STATIC_INLINE void md_rcu_set_pll0_fn(RCU_TypeDef *rcu, uint32_t fn)
{
    MODIFY_REG(rcu->PLL0, RCU_PLL0_FN, (fn << RCU_PLL0_FN_POSS));
}

/**
  * @brief  Get PLL0 VCO frequency integer multiplication value
  * @param  rcu RCU Instance
  * @retval fn
  */
__STATIC_INLINE uint32_t md_rcu_get_pll0_fn(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->PLL0, RCU_PLL0_FN) >> RCU_PLL0_FN_POSS);
}

/**
  * @brief  Set PLL0 clock output frequency division ratio
  * @param  rcu RCU Instance
  *         @arg @ref MD_RCU_FM_PLL0_DIV_8
  *         @arg @ref MD_RCU_FM_PLL0_DIV_16
  *         @arg @ref MD_RCU_FM_PLL0_DIV_32
  *         @arg @ref MD_RCU_FM_PLL0_DIV_64
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_pll0_fm(RCU_TypeDef *rcu, uint32_t fm)
{
    MODIFY_REG(rcu->PLL0, RCU_PLL0_FM, fm << RCU_PLL0_FM_POSS);
}

/**
  * @brief  Get PLL0 clock output frequency division ratio
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_FM_PLL0_DIV_8
  *         @arg @ref MD_RCU_FM_PLL0_DIV_16
  *         @arg @ref MD_RCU_FM_PLL0_DIV_32
  *         @arg @ref MD_RCU_FM_PLL0_DIV_64
  */
__STATIC_INLINE uint32_t md_rcu_get_pll0_fm(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->PLL0, RCU_PLL0_FM) >> RCU_PLL0_FM_POSS);
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group5 CFG2
  * @{
  */
/**
  * @brief  Set RCU_CFG2 Register
  * @param  rcu RCU Instance
  * @param  cfg2
  */
__STATIC_INLINE void md_rcu_set_cfg2(RCU_TypeDef *rcu, uint32_t cfg2)
{
    WRITE_REG(rcu->CFG2, cfg2);
}

/**
  * @brief  Get RCU_CFG2 Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_rcu_get_cfg2(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->CFG2));
}

/**
  * @brief  Set Current system clock frequency
  * @param  rcu RCU Instance
  * @param  sysfreq
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x4
  * @retval
  */
__STATIC_INLINE void md_rcu_set_current_system_frequency(RCU_TypeDef *rcu, uint32_t sysfreq)
{
    MODIFY_REG(rcu->CFG2, RCU_CFG2_SYSFREQ, (sysfreq << RCU_CFG2_SYSFREQ_POSS));
}

/**
  * @brief  Get Current system clock frequency
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x4
  */
__STATIC_INLINE uint32_t md_rcu_get_current_system_frequency(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG2, RCU_CFG2_SYSFREQ) >> RCU_CFG2_SYSFREQ_POSS);
}

/**
  * @brief  Set USB clock (USBCLK) source
  * @param  rcu RCU Instance
  * @param  usbsw
  *         @arg @ref MD_RCU_USBSW_USBCLK_HRC48CLK
  *         @arg @ref MD_RCU_USBSW_USBCLK_PLL0CLK
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_usb_phyclk_source(RCU_TypeDef *rcu, uint32_t usbsw)
{
    MODIFY_REG(rcu->CFG2, RCU_CFG2_USBSW, usbsw << RCU_CFG2_USBSW_POSS);
}

/**
  * @brief  Get USB clock (USBCLK) source
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_USBSW_USBCLK_HRC48CLK
  *         @arg @ref MD_RCU_USBSW_USBCLK_PLL0CLK
  */
__STATIC_INLINE uint32_t md_rcu_get_usb_phyclk_source(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG2, RCU_CFG2_USBSW) >> RCU_CFG2_USBSW_POSS);
}

/**
  * @brief  Set I2S clock (I2SCLK) source
  * @param  rcu RCU Instance
  * @param  i2ssw
  *         @arg @ref MD_RCU_I2SSW_I2SCLK_HRC48CLK
  *         @arg @ref MD_RCU_I2SSW_I2SCLK_HOSCCLK
  *         @arg @ref MD_RCU_I2SSW_I2SCLK_PLL0CLK
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_i2s_clk_source(RCU_TypeDef *rcu, uint32_t i2ssw)
{
    MODIFY_REG(rcu->CFG2, RCU_CFG2_I2SSW, i2ssw << RCU_CFG2_I2SSW_POSS);
}

/**
  * @brief  Get I2S clock (I2SCLK) source
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_I2SSW_I2SCLK_HRC48CLK
  *         @arg @ref MD_RCU_I2SSW_I2SCLK_HOSCCLK
  *         @arg @ref MD_RCU_I2SSW_I2SCLK_PLL0CLK
  */
__STATIC_INLINE uint32_t md_rcu_get_i2s_clk_source(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CFG2, RCU_CFG2_I2SSW) >> RCU_CFG2_I2SSW_POSS);
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group6 IER
  * @{
  */
/**
  * @brief  Set RCU_IER Register
  * @param  rcu RCU Instance
  * @param  ier
  */
__STATIC_INLINE void md_rcu_set_ier(RCU_TypeDef *rcu, uint32_t ier)
{
    WRITE_REG(rcu->IER, ier);
}

/**
  * @brief  Clock security system interrupt enable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_enable_it_css_hosc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IER, RCU_IER_CSSHOSC);
}

/**
  * @brief  PLL clock source stable interrupt enable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_enable_it_pll0_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IER, RCU_IER_PLL0RDY);
}

/**
  * @brief  HRC48 clock source stable interrupt enable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_enable_it_hrc48_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IER, RCU_IER_HRC48RDY);
}

/**
  * @brief  HOSC clock source stable interrupt enable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_enable_it_hosc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IER, RCU_IER_HOSCRDY);
}

/**
  * @brief  HRC clock source stable interrupt enable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_enable_it_hrc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IER, RCU_IER_HRCRDY);
}

/**
  * @brief  LOSC clock source stable interrupt enable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_enable_it_losc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IER, RCU_IER_LOSCRDY);
}

/**
  * @brief  LRC clock source stable interrupt enable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_enable_it_lrc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IER, RCU_IER_LRCRDY);
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group7 IDR
  * @{
  */
/**
  * @brief  Set RCU_IDR Register
  * @param  rcu RCU Instance
  * @param  idr
  */
__STATIC_INLINE void md_rcu_set_idr(RCU_TypeDef *rcu, uint32_t idr)
{
    WRITE_REG(rcu->IDR, idr);
}

/**
  * @brief  Clock security system interrupt disable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_disable_it_css_hosc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IDR, RCU_IDR_CSSHOSC);
}

/**
  * @brief  PLL clock source stable interrupt disable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_disable_it_pll0_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IDR, RCU_IDR_PLL0RDY);
}

/**
  * @brief  HRC48 clock source stable interrupt disable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_disable_it_hrc48_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IDR, RCU_IDR_HRC48RDY);
}

/**
  * @brief  HOSC clock source stable interrupt disable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_disable_it_hosc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IDR, RCU_IDR_HOSCRDY);
}

/**
  * @brief  HRC clock source stable interrupt disable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_disable_it_hrc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IDR, RCU_IDR_HRCRDY);
}

/**
  * @brief  LOSC clock source stable interrupt disable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_disable_it_losc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IDR, RCU_IDR_LOSCRDY);
}

/**
  * @brief  LRC clock source stable interrupt disable
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE void md_rcu_disable_it_lrc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->IDR, RCU_IDR_LRCRDY);
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group8 IVS
  * @{
  */
/**
  * @brief  Set RCU_IVS Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_rcu_get_ivs(RCU_TypeDef *rcu)
{
    return (uint32_t) READ_REG(rcu->IVS);
}

/**
  * @brief  Clock security system interrupt active state
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_it_css_hosc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IVS, RCU_IVS_CSSHOSC) == (RCU_IVS_CSSHOSC));
}

/**
  * @brief  PLL clock source stable interrupt active state
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_it_pll0_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IVS, RCU_IVS_PLL0RDY) == (RCU_IVS_PLL0RDY));
}

/**
  * @brief  HRC48 clock source stable interrupt active state
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_it_hrc48_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IVS, RCU_IVS_HRC48RDY) == (RCU_IVS_HRC48RDY));
}

/**
  * @brief  HOSC clock source stable interrupt active state
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_it_hosc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IVS, RCU_IVS_HOSCRDY) == (RCU_IVS_HOSCRDY));
}

/**
  * @brief  HRC clock source stable interrupt active state
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_it_hrc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IVS, RCU_IVS_HRCRDY) == (RCU_IVS_HRCRDY));
}

/**
  * @brief  LOSC clock source stable interrupt active state
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_it_losc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IVS, RCU_IVS_LOSCRDY) == (RCU_IVS_LOSCRDY));
}

/**
  * @brief  LRC clock source stable interrupt active state
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_it_lrc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IVS, RCU_IVS_LRCRDY) == (RCU_IVS_LRCRDY));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group9 RIF
  * @{
  */
/**
  * @brief  Set RCU_RIF Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_rcu_get_rif(RCU_TypeDef *rcu)
{
    return (uint32_t)READ_REG(rcu->RIF);
}

/**
  * @brief  Clock security system unmasked interrupt flag status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_active_it_css_hosc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RIF, RCU_RIF_CSSHOSC) == (RCU_RIF_CSSHOSC));
}

/**
  * @brief  PLL clock source stable unmasked interrupt flag status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_active_it_pll0_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RIF, RCU_RIF_PLL0RDY) == (RCU_RIF_PLL0RDY));
}

/**
  * @brief  HRC48 clock source stable unmasked interrupt flag status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_active_it_hrc48_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RIF, RCU_RIF_HRC48RDY) == (RCU_RIF_HRC48RDY));
}

/**
  * @brief  HOSC clock source stable unmasked interrupt flag status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_active_it_hosc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RIF, RCU_RIF_HOSCRDY) == (RCU_RIF_HOSCRDY));
}

/**
  * @brief  HRC clock source stable unmasked interrupt flag status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_active_it_hrc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RIF, RCU_RIF_HRCRDY) == (RCU_RIF_HRCRDY));
}

/**
  * @brief  LOSC clock source stable unmasked interrupt flag status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_active_it_losc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RIF, RCU_RIF_LOSCRDY) == (RCU_RIF_LOSCRDY));
}

/**
  * @brief  LRC clock source stable unmasked interrupt flag status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_active_it_lrc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RIF, RCU_RIF_LRCRDY) == (RCU_RIF_LRCRDY));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group10 IFM
  * @{
  */
/**
  * @brief  Set RCU_IFM Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_rcu_get_ifm(RCU_TypeDef *rcu)
{
    return (uint32_t)READ_REG(rcu->IFM);
}

/**
  * @brief  Clock security system interrupt flag mask status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_masked_it_css_hosc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IFM, RCU_IFM_CSSHOSC) == (RCU_IFM_CSSHOSC));
}

/**
  * @brief  PLL clock source stable interrupt flag mask status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_masked_it_pll0_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IFM, RCU_IFM_PLL0RDY) == (RCU_IFM_PLL0RDY));
}

/**
  * @brief  HRC48 clock source stable interrupt flag mask status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_masked_it_hrc48_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IFM, RCU_IFM_HRC48RDY) == (RCU_IFM_HRC48RDY));
}

/**
  * @brief  HOSC clock source stable interrupt flag mask status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_masked_it_hosc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IFM, RCU_IFM_HOSCRDY) == (RCU_IFM_HOSCRDY));
}

/**
  * @brief  HRC clock source stable interrupt flag mask status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_masked_it_hrc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IFM, RCU_IFM_HRCRDY) == (RCU_IFM_HRCRDY));
}

/**
  * @brief  LOSC clock source stable interrupt flag mask status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_masked_it_losc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IFM, RCU_IFM_LOSCRDY) == (RCU_IFM_LOSCRDY));
}

/**
  * @brief  LRC clock source stable interrupt flag mask status
  * @param  rcu RCU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_rcu_is_masked_it_lrc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->IFM, RCU_IFM_LRCRDY) == (RCU_IFM_LRCRDY));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group11 ICR
  * @{
  */
/**
  * @brief  Set RCU_ICR Register
  * @param  rcu RCU Instance
  * @param  icr
  */
__STATIC_INLINE void md_rcu_set_icr(RCU_TypeDef *rcu, uint32_t icr)
{
    WRITE_REG(rcu->ICR, icr);
}

/**
  * @brief  Clear Clock security system interrupt
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_rcu_clear_it_css_hosc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->ICR, RCU_ICR_CSSHOSC);
}

/**
  * @brief  Clear PLL0 clock source stable interrupt flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_rcu_clear_it_pll0_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->ICR, RCU_ICR_PLL0RDY);
}

/**
  * @brief  Clear HRC48 clock source stable interrupt flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_rcu_clear_it_hrc48_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->ICR, RCU_ICR_HRC48RDY);
}

/**
  * @brief  Clear HOSC clock source stable interrupt flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_rcu_clear_it_hosc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->ICR, RCU_ICR_HOSCRDY);
}

/**
  * @brief  Clear HRC clock source stable interrupt flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_rcu_clear_it_hrc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->ICR, RCU_ICR_HRCRDY);
}

/**
  * @brief  Clear LOSC clock source stable interrupt flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_rcu_clear_it_losc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->ICR, RCU_ICR_LOSCRDY);
}

/**
  * @brief  Clear LRC clock source stable interrupt flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_rcu_clear_it_lrc_ready(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->ICR, RCU_ICR_LRCRDY);
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group12 AHBRST
  * @{
  */
/**
  * @brief  Set RCU_AHBRST Register
  * @param  rcu RCU Instance
  * @param  ahbrst
  */
__STATIC_INLINE void md_rcu_set_ahbrst(RCU_TypeDef *rcu, uint32_t ahbrst)
{
    WRITE_REG(rcu->AHBRST, ahbrst);
}

/**
  * @brief  Get RCU_AHBRST Register
  * @param  rcu RCU Instance
  * @param  ahbrst
  */
__STATIC_INLINE uint32_t md_rcu_get_ahbrst(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->AHBRST));
}

/**
  * @brief  GPIOD reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpiod_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_GPDEN);
}

/**
  * @brief  GPIOD reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpiod_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_GPDEN);
}

/**
  * @brief  Get GPIOD reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpiod_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_GPDEN) == (RCU_AHBRST_GPDEN));
}

/**
  * @brief  GPIOC reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpioc_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_GPCEN);
}

/**
  * @brief  GPIOC reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpioc_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_GPCEN);
}

/**
  * @brief  Get GPIOC reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpioc_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_GPCEN) == (RCU_AHBRST_GPCEN));
}

/**
  * @brief  GPIOB reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpiob_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_GPBEN);
}

/**
  * @brief  GPIOB reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpiob_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_GPBEN);
}

/**
  * @brief  Get GPIOB reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpiob_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_GPBEN) == (RCU_AHBRST_GPBEN));
}

/**
  * @brief  GPIOA reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpioa_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_GPAEN);
}

/**
  * @brief  GPIOA reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpioa_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_GPAEN);
}

/**
  * @brief  Get GPIOA reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpioa_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_GPAEN) == (RCU_AHBRST_GPAEN));
}

/**
  * @brief  CALC reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_calc_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_CALCEN);
}

/**
  * @brief  CALC reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_calc_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_CALCEN);
}

/**
  * @brief  Get CALC reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_calc_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_CALCEN) == (RCU_AHBRST_CALCEN));
}

/**
  * @brief  USB reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_usb_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_USBEN);
}

/**
  * @brief  USB reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_usb_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_USBEN);
}

/**
  * @brief  Get USB reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_usb_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_USBEN) == (RCU_AHBRST_USBEN));
}

/**
  * @brief  AES reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_aes_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_AESEN);
}

/**
  * @brief  AES reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_aes_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_AESEN);
}

/**
  * @brief  Get AES reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_aes_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_AESEN) == (RCU_AHBRST_AESEN));
}

/**
  * @brief  CRC reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_crc_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_CRCEN);
}

/**
  * @brief  CRC reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_crc_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_CRCEN);
}

/**
  * @brief  Get CRC reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_crc_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_CRCEN) == (RCU_AHBRST_CRCEN));
}

/**
  * @brief  CSU reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_csu_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_CSUEN);
}

/**
  * @brief  CSU reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_csu_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_CSUEN);
}

/**
  * @brief  Get CSU reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_csu_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_CSUEN) == (RCU_AHBRST_CSUEN));
}

/**
  * @brief  KBCU reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_kbcu_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_KBCUEN);
}

/**
  * @brief  KBCU reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_kbcu_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_KBCUEN);
}

/**
  * @brief  Get KBCU reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_kbcu_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_KBCUEN) == (RCU_AHBRST_KBCUEN));
}

/**
  * @brief  RTC reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_rtc_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_RTCEN);
}

/**
  * @brief  RTC reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_rtc_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_RTCEN);
}

/**
  * @brief  Get RTC reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_rtc_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_RTCEN) == (RCU_AHBRST_RTCEN));
}

/**
  * @brief  DMA1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_dma1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBRST, RCU_AHBRST_DMA1EN);
}

/**
  * @brief  DMA1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_dma1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBRST, RCU_AHBRST_DMA1EN);
}

/**
  * @brief  Get DMA1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_dma1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBRST, RCU_AHBRST_DMA1EN) == (RCU_AHBRST_DMA1EN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group13 APB1RST
  * @{
  */
/**
  * @brief  Set RCU_APB1RST Register
  * @param  rcu RCU Instance
  * @param  apb1rst
  */
__STATIC_INLINE void md_rcu_set_apb1rst(RCU_TypeDef *rcu, uint32_t apb1rst)
{
    WRITE_REG(rcu->APB1RST, apb1rst);
}

/**
  * @brief  Get RCU_APB1RST Register
  * @param  rcu RCU Instance
  * @param  apb1rst
  */
__STATIC_INLINE uint32_t md_rcu_get_apb1rst(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->APB1RST));
}

/**
  * @brief  I2C2 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2c2_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_I2C2EN);
}

/**
  * @brief  I2C2 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2c2_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_I2C2EN);
}

/**
  * @brief  Get I2C2 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2c2_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_I2C2EN) == (RCU_APB1RST_I2C2EN));
}

/**
  * @brief  I2C1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2c1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_I2C1EN);
}

/**
  * @brief  I2C1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2c1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_I2C1EN);
}

/**
  * @brief  Get I2C1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2c1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_I2C1EN) == (RCU_APB1RST_I2C1EN));
}

/**
  * @brief  UART4 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart4_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_UART4EN);
}

/**
  * @brief  UART4 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart4_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_UART4EN);
}

/**
  * @brief  Get UART4 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart4_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_UART4EN) == (RCU_APB1RST_UART4EN));
}

/**
  * @brief  UART3 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart3_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_UART3EN);
}

/**
  * @brief  UART3 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart3_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_UART3EN);
}

/**
  * @brief  Get UART3 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart3_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_UART3EN) == (RCU_APB1RST_UART3EN));
}

/**
  * @brief  UART2 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart2_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_UART2EN);
}

/**
  * @brief  UART2 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart2_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_UART2EN);
}

/**
  * @brief  Get UART2 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart2_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_UART2EN) == (RCU_APB1RST_UART2EN));
}

/**
  * @brief  SPI3 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi3_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_SPI3EN);
}

/**
  * @brief  SPI3 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi3_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_SPI3EN);
}

/**
  * @brief  Get SPI3 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi3_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_SPI3EN) == (RCU_APB1RST_SPI3EN));
}

/**
  * @brief  SPI2 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi2_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_SPI2EN);
}

/**
  * @brief  SPI2 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi2_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_SPI2EN);
}

/**
  * @brief  Get SPI2 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi2_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_SPI2EN) == (RCU_APB1RST_SPI2EN));
}

/**
  * @brief  WWDT reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_wwdt_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_WWDTEN);
}

/**
  * @brief  WWDT reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_wwdt_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_WWDTEN);
}

/**
  * @brief  Get WWDT reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_wwdt_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_WWDTEN) == (RCU_APB1RST_WWDTEN));
}

/**
  * @brief  BS16T1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_bs16t1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_BS16T1EN);
}

/**
  * @brief  BS16T1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_bs16t1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_BS16T1EN);
}

/**
  * @brief  Get BS16T1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_bs16t1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_BS16T1EN) == (RCU_APB1RST_BS16T1EN));
}

/**
  * @brief  GP16C4T3 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t3_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T3EN);
}

/**
  * @brief  GP16C4T3 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t3_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T3EN);
}

/**
  * @brief  Get GP16C4T3 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t3_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T3EN) == (RCU_APB1RST_GP16C4T3EN));
}

/**
  * @brief  GP16C4T2 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t2_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T2EN);
}

/**
  * @brief  GP16C4T2 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t2_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T2EN);
}

/**
  * @brief  Get GP16C4T2 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t2_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T2EN) == (RCU_APB1RST_GP16C4T2EN));
}

/**
  * @brief  GP16C4T1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T1EN);
}

/**
  * @brief  GP16C4T1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T1EN);
}

/**
  * @brief  Get GP16C4T1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_GP16C4T1EN) == (RCU_APB1RST_GP16C4T1EN));
}

/**
  * @brief  GP32C4T1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp32c4t1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1RST, RCU_APB1RST_GP32C4T1EN);
}

/**
  * @brief  GP32C4T1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp32c4t1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1RST, RCU_APB1RST_GP32C4T1EN);
}

/**
  * @brief  Get GP32C4T1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp32c4t1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1RST, RCU_APB1RST_GP32C4T1EN) == (RCU_APB1RST_GP32C4T1EN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group14 APB2RST
  * @{
  */
/**
  * @brief  Set RCU_APB2RST Register
  * @param  rcu RCU Instance
  * @param  apb2rst
  */
__STATIC_INLINE void md_rcu_set_apb2rst(RCU_TypeDef *rcu, uint32_t apb2rst)
{
    WRITE_REG(rcu->APB2RST, apb2rst);
}

/**
  * @brief  Get RCU_APB2RST Register
  * @param  rcu RCU Instance
  * @param  apb2rst
  */
__STATIC_INLINE uint32_t md_rcu_get_apb2rst(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->APB2RST));
}

/**
  * @brief  CMP reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_cmp_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_CMPEN);
}

/**
  * @brief  CMP reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_cmp_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_CMPEN);
}

/**
  * @brief  Get CMP reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_cmp_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_CMPEN) == (RCU_APB2RST_CMPEN));
}

/**
  * @brief  GP16C2T4 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t4_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T4EN);
}

/**
  * @brief  GP16C2T4 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t4_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T4EN);
}

/**
  * @brief  Get GP16C2T4 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t4_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T4EN) == (RCU_APB2RST_GP16C2T4EN));
}

/**
  * @brief  GP16C2T3 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t3_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T3EN);
}

/**
  * @brief  GP16C2T3 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t3_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T3EN);
}

/**
  * @brief  Get GP16C2T3 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t3_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T3EN) == (RCU_APB2RST_GP16C2T3EN));
}

/**
  * @brief  GP16C2T2 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t2_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T2EN);
}

/**
  * @brief  GP16C2T2 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t2_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T2EN);
}

/**
  * @brief  Get GP16C2T2 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t2_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T2EN) == (RCU_APB2RST_GP16C2T2EN));
}

/**
  * @brief  GP16C2T1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T1EN);
}

/**
  * @brief  GP16C2T1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T1EN);
}

/**
  * @brief  Get GP16C2T1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_GP16C2T1EN) == (RCU_APB2RST_GP16C2T1EN));
}

/**
  * @brief  UART1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_UART1EN);
}

/**
  * @brief  UART1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_UART1EN);
}

/**
  * @brief  Get UART1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_UART1EN) == (RCU_APB2RST_UART1EN));
}

/**
  * @brief  SPI1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_SPI1EN);
}

/**
  * @brief  I2S1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2s1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_SPI1EN);
}


/**
  * @brief  SPI1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_SPI1EN);
}

/**
  * @brief  I2S1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2s1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_SPI1EN);
}

/**
  * @brief  Get SPI1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_SPI1EN) == (RCU_APB2RST_SPI1EN));
}

/**
  * @brief  Get I2S1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2s1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_SPI1EN) == (RCU_APB2RST_SPI1EN));
}

/**
  * @brief  AD16C4T1 reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_ad16c4t1_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_AD16C4T1EN);
}

/**
  * @brief  AD16C4T1 reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_ad16c4t1_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_AD16C4T1EN);
}

/**
  * @brief  Get AD16C4T1 reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_ad16c4t1_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_AD16C4T1EN) == (RCU_APB2RST_AD16C4T1EN));
}

/**
  * @brief  ADC reset request enable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_adc_reset(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2RST, RCU_APB2RST_ADCEN);
}

/**
  * @brief  ADC reset request disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_adc_reset(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2RST, RCU_APB2RST_ADCEN);
}

/**
  * @brief  Get ADC reset request bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Reset enable
  *         @arg 0x0 : Reset disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_adc_reset(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2RST, RCU_APB2RST_ADCEN) == (RCU_APB2RST_ADCEN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group15 AHBEN
  * @{
  */
/**
  * @brief  Set RCU_AHBEN Register
  * @param  rcu RCU Instance
  * @param  ahben
  */
__STATIC_INLINE void md_rcu_set_ahben(RCU_TypeDef *rcu, uint32_t ahben)
{
    WRITE_REG(rcu->AHBEN, ahben);
}

/**
  * @brief  Get RCU_AHBEN Register
  * @param  rcu RCU Instance
  * @param  ahben
  */
__STATIC_INLINE uint32_t md_rcu_get_ahben(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->AHBEN));
}

/**
  * @brief  GPIOD clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpiod(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_GPDEN);
}

/**
  * @brief  GPIOD Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpiod(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_GPDEN);
}

/**
  * @brief  Get GPIOD Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpiod enable
  *         @arg 0x0 : gpiod disable.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpiod(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_GPDEN) == (RCU_AHBEN_GPDEN));
}

/**
  * @brief  GPIOC clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpioc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_GPCEN);
}

/**
  * @brief  GPIOC Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpioc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_GPCEN);
}

/**
  * @brief  Get GPIOC Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpioc enable
  *         @arg 0x0 : gpioc disable.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpioc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_GPCEN) == (RCU_AHBEN_GPCEN));
}

/**
  * @brief  GPIOB clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpiob(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_GPBEN);
}

/**
  * @brief  GPIOB Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpiob(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_GPBEN);
}

/**
  * @brief  Get GPIOB Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpiob enable
  *         @arg 0x0 : gpiob disable.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpiob(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_GPBEN) == (RCU_AHBEN_GPBEN));
}

/**
  * @brief  GPIOA clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpioa(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_GPAEN);
}

/**
  * @brief  GPIOA Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpioa(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_GPAEN);
}

/**
  * @brief  Get GPIOA Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpioa enable
  *         @arg 0x0 : gpioa disable.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpioa(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_GPAEN) == (RCU_AHBEN_GPAEN));
}

/**
  * @brief  CALC clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_calc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_CALCEN);
}

/**
  * @brief  CALC Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_calc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_CALCEN);
}

/**
  * @brief  Get CALC Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : calc enable
  *         @arg 0x0 : calc disable.
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_calc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_CALCEN) == (RCU_AHBEN_CALCEN));
}

/**
  * @brief  USB clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_usb(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_USBEN);
}

/**
  * @brief  USB Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_usb(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_USBEN);
}

/**
  * @brief  Get USB Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : usb enable
  *         @arg 0x0 : usb disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_usb(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_USBEN) == (RCU_AHBEN_USBEN));
}

/**
  * @brief  AES clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_aes(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_AESEN);
}

/**
  * @brief  AES Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_aes(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_AESEN);
}

/**
  * @brief  Get AES Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : aes enable
  *         @arg 0x0 : aes disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_aes(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_AESEN) == (RCU_AHBEN_AESEN));
}

/**
  * @brief  CRC clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_crc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_CRCEN);
}

/**
  * @brief  CRC Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_crc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_CRCEN);
}

/**
  * @brief  Get CRC Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : crc enable
  *         @arg 0x0 : crc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_crc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_CRCEN) == (RCU_AHBEN_CRCEN));
}

/**
  * @brief  CSU clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_csu(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_CSUEN);
}

/**
  * @brief  CSU Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_csu(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_CSUEN);
}

/**
  * @brief  Get CSU Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : csu enable
  *         @arg 0x0 : csu disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_csu(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_CSUEN) == (RCU_AHBEN_CSUEN));
}

/**
  * @brief  KBCU clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_kbcu(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_KBCUEN);
}

/**
  * @brief  KBCU Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_kbcu(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_KBCUEN);
}

/**
  * @brief  Get KBCU Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : kbcu enable
  *         @arg 0x0 : kbcu disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_kbcu(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_KBCUEN) == (RCU_AHBEN_KBCUEN));
}

/**
  * @brief  RTC clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_rtc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_RTCEN);
}

/**
  * @brief  RTC Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_rtc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_RTCEN);
}

/**
  * @brief  Get RTC Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : rtc enable
  *         @arg 0x0 : rtc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_rtc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_RTCEN) == (RCU_AHBEN_RTCEN));
}

/**
  * @brief  DMA1 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_dma1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBEN, RCU_AHBEN_DMA1EN);
}

/**
  * @brief  DMA1 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_dma1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBEN, RCU_AHBEN_DMA1EN);
}

/**
  * @brief  Get DMA1 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : dma1 enable
  *         @arg 0x0 : dma1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_dma1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBEN, RCU_AHBEN_DMA1EN) == (RCU_AHBEN_DMA1EN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group16 APB1EN
  * @{
  */
/**
  * @brief  Set RCU_APB1EN Register
  * @param  rcu RCU Instance
  * @param  apb1en
  */
__STATIC_INLINE void md_rcu_set_apb1en(RCU_TypeDef *rcu, uint32_t apb1en)
{
    WRITE_REG(rcu->APB1EN, apb1en);
}

/**
  * @brief  Get RCU_APB1EN Register
  * @param  rcu RCU Instance
  * @param  apb1en
  */
__STATIC_INLINE uint32_t md_rcu_get_apb1en(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->APB1EN));
}

/**
  * @brief  I2C2 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2c2(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_I2C2EN);
}

/**
  * @brief  I2C2 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2c2(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_I2C2EN);
}

/**
  * @brief  Get I2C2 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : i2c2 enable
  *         @arg 0x0 : i2c2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2c2(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_I2C2EN) == (RCU_APB1EN_I2C2EN));
}

/**
  * @brief  I2C1 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2c1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_I2C1EN);
}

/**
  * @brief  I2C1 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2c1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_I2C1EN);
}

/**
  * @brief  Get I2C1 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : i2c1 enable
  *         @arg 0x0 : i2c1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2c1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_I2C1EN) == (RCU_APB1EN_I2C1EN));
}

/**
  * @brief  UART4 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart4(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_UART4EN);
}

/**
  * @brief  UART4 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart4(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_UART4EN);
}

/**
  * @brief  Get UART4 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart4 enable
  *         @arg 0x0 : uart4 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart4(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_UART4EN) == (RCU_APB1EN_UART4EN));
}

/**
  * @brief  UART3 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart3(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_UART3EN);
}

/**
  * @brief  UART3 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart3(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_UART3EN);
}

/**
  * @brief  Get UART3 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart3 enable
  *         @arg 0x0 : uart3 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart3(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_UART3EN) == (RCU_APB1EN_UART3EN));
}

/**
  * @brief  UART2 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart2(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_UART2EN);
}

/**
  * @brief  UART2 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart2(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_UART2EN);
}

/**
  * @brief  Get UART2 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart2 enable
  *         @arg 0x0 : uart2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart2(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_UART2EN) == (RCU_APB1EN_UART2EN));
}


/**
  * @brief  SPI3 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi3(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_SPI3EN);
}

/**
  * @brief  SPI3 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi3(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_SPI3EN);
}

/**
  * @brief  Get SPI3 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi3 enable
  *         @arg 0x0 : spi3 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi3(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_SPI3EN) == (RCU_APB1EN_SPI3EN));
}


/**
  * @brief  SPI2 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi2(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_SPI2EN);
}

/**
  * @brief  SPI2 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi2(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_SPI2EN);
}

/**
  * @brief  Get SPI2 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi2 enable
  *         @arg 0x0 : spi2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi2(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_SPI2EN) == (RCU_APB1EN_SPI2EN));
}

/**
  * @brief  WWDT clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_wwdt(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_WWDTEN);
}

/**
  * @brief  WWDT Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_wwdt(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_WWDTEN);
}

/**
  * @brief  Get WWDT Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : wwdt enable
  *         @arg 0x0 : wwdt disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_wwdt(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_WWDTEN) == (RCU_APB1EN_WWDTEN));
}

/**
  * @brief  BS16T1 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_bs16t1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_BS16T1EN);
}

/**
  * @brief  BS16T1 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_bs16t1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_BS16T1EN);
}

/**
  * @brief  Get BS16T1 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : bs16t1 enable
  *         @arg 0x0 : bs16t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_bs16t1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_BS16T1EN) == (RCU_APB1EN_BS16T1EN));
}

/**
  * @brief  GP16C4T3 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t3(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T3EN);
}

/**
  * @brief  GP16C4T3 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t3(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T3EN);
}

/**
  * @brief  Get GP16C4T3 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t3 enable
  *         @arg 0x0 : gp16c4t3 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t3(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T3EN) == (RCU_APB1EN_GP16C4T3EN));
}

/**
  * @brief  GP16C4T2 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t2(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T2EN);
}

/**
  * @brief  GP16C4T2 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t2(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T2EN);
}

/**
  * @brief  Get GP16C4T2 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t2 enable
  *         @arg 0x0 : gp16c4t2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t2(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T2EN) == (RCU_APB1EN_GP16C4T2EN));
}

/**
  * @brief  GP16C4T1 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T1EN);
}

/**
  * @brief  GP16C4T1 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T1EN);
}

/**
  * @brief  Get GP16C4T1 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t1 enable
  *         @arg 0x0 : gp16c4t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_GP16C4T1EN) == (RCU_APB1EN_GP16C4T1EN));
}

/**
  * @brief  GP32C4T1 clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp32c4t1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1EN, RCU_APB1EN_GP32C4T1EN);
}

/**
  * @brief  GP32C4T1 Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp32c4t1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1EN, RCU_APB1EN_GP32C4T1EN);
}

/**
  * @brief  Get GP32C4T1 Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp32c4t1 enable
  *         @arg 0x0 : gp32c4t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp32c4t1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1EN, RCU_APB1EN_GP32C4T1EN) == (RCU_APB1EN_GP32C4T1EN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group17 APB2EN
  * @{
  */
/**
  * @brief  Set RCU_APB2EN Register
  * @param  rcu RCU Instance
  * @param  apb2en
  */
__STATIC_INLINE void md_rcu_set_apb2en(RCU_TypeDef *rcu, uint32_t apb2en)
{
    WRITE_REG(rcu->APB2EN, apb2en);
}

/**
  * @brief  Get RCU_APB2EN Register
  * @param  rcu RCU Instance
  * @param  apb2en
  */
__STATIC_INLINE uint32_t md_rcu_get_apb2en(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->APB2EN));
}

/**
  * @brief  CMP clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_cmp(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_CMPEN);
}

/**
  * @brief  CMP Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_cmp(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_CMPEN);
}

/**
  * @brief  Get CMP Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : cmp enable
  *         @arg 0x0 : cmp disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_cmp(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_CMPEN) == (RCU_APB2EN_CMPEN));
}

/**
  * @brief  GP16C2T4EN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t4(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T4EN);
}

/**
  * @brief  GP16C2T4EN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t4(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T4EN);
}

/**
  * @brief  Get GP16C2T4EN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t4 enable
  *         @arg 0x0 : gp16c2t4 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t4(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T4EN) == (RCU_APB2EN_GP16C2T4EN));
}

/**
  * @brief  GP16C2T3EN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t3(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T3EN);
}

/**
  * @brief  GP16C2T3EN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t3(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T3EN);
}

/**
  * @brief  Get GP16C2T3EN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t3 enable
  *         @arg 0x0 : gp16c2t3 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t3(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T3EN) == (RCU_APB2EN_GP16C2T3EN));
}

/**
  * @brief  GP16C2T2EN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t2(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T2EN);
}

/**
  * @brief  GP16C2T2EN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t2(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T2EN);
}

/**
  * @brief  Get GP16C2T2EN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t2 enable
  *         @arg 0x0 : gp16c2t2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t2(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T2EN) == (RCU_APB2EN_GP16C2T2EN));
}

/**
  * @brief  GP16C2T1EN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T1EN);
}

/**
  * @brief  GP16C2T1EN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T1EN);
}

/**
  * @brief  Get GP16C2T1EN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t1 enable
  *         @arg 0x0 : gp16c2t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_GP16C2T1EN) == (RCU_APB2EN_GP16C2T1EN));
}

/**
  * @brief  UART1EN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_UART1EN);
}

/**
  * @brief  UART1EN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_UART1EN);
}

/**
  * @brief  Get UART1EN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart1 enable
  *         @arg 0x0 : uart1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_UART1EN) == (RCU_APB2EN_UART1EN));
}

/**
  * @brief  SPI1EN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_SPI1EN);
}

/**
  * @brief  I2S1EN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2s1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_SPI1EN);
}

/**
  * @brief  SPI1EN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_SPI1EN);
}

/**
  * @brief  I2S1EN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2s1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_SPI1EN);
}

/**
  * @brief  Get SPI1EN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi1 enable
  *         @arg 0x0 : spi1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_SPI1EN) == (RCU_APB2EN_SPI1EN));
}

/**
  * @brief  Get I2S1EN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi1 enable
  *         @arg 0x0 : spi1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2s1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_SPI1EN) == (RCU_APB2EN_SPI1EN));
}

/**
  * @brief  AD16C4T1EN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_ad16c4t1(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_AD16C4T1EN);
}

/**
  * @brief  AD16C4T1EN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_ad16c4t1(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_AD16C4T1EN);
}

/**
  * @brief  Get AD16C4T1EN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : ad16c4t1 enable
  *         @arg 0x0 : ad16c4t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_ad16c4t1(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_AD16C4T1EN) == (RCU_APB2EN_AD16C4T1EN));
}

/**
  * @brief  ADCEN clock enable bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_adc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2EN, RCU_APB2EN_ADCEN);
}

/**
  * @brief  ADCEN Clock disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_adc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2EN, RCU_APB2EN_ADCEN);
}

/**
  * @brief  Get ADCEN Clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : adc enable
  *         @arg 0x0 : adc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_adc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2EN, RCU_APB2EN_ADCEN) == (RCU_APB2EN_ADCEN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group18 AHBSL
  * @{
  */
/**
  * @brief  Set RCU_AHBSL Register
  * @param  rcu RCU Instance
  * @param  ahbsl
  */
__STATIC_INLINE void md_rcu_set_ahbsl(RCU_TypeDef *rcu, uint32_t ahbsl)
{
    WRITE_REG(rcu->AHBSL, ahbsl);
}

/**
  * @brief  Get RCU_AHBSL Register
  * @param  rcu RCU Instance
  * @param  ahbsl
  */
__STATIC_INLINE uint32_t md_rcu_get_ahbsl(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->AHBSL));
}

/**
  * @brief  GPDEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpiod_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_GPDEN);
}

/**
  * @brief  GPDEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpiod_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_GPDEN);
}

/**
  * @brief  Get GPDEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpiod enable
  *         @arg 0x0 : gpiod disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpiod_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_GPDEN) == (RCU_AHBSL_GPDEN));
}

/**
  * @brief  GPCEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpioc_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_GPCEN);
}

/**
  * @brief  GPCEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpioc_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_GPCEN);
}

/**
  * @brief  Get GPCEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpioc enable
  *         @arg 0x0 : gpioc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpioc_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_GPCEN) == (RCU_AHBSL_GPCEN));
}

/**
  * @brief  GPBEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpiob_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_GPBEN);
}

/**
  * @brief  GPBEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpiob_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_GPBEN);
}

/**
  * @brief  Get GPBEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpiob enable
  *         @arg 0x0 : gpiob disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpiob_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_GPBEN) == (RCU_AHBSL_GPBEN));
}

/**
  * @brief  GPAEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gpioa_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_GPAEN);
}

/**
  * @brief  GPAEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gpioa_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_GPAEN);
}

/**
  * @brief  Get GPAEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpioa enable
  *         @arg 0x0 : gpioa disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gpioa_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_GPAEN) == (RCU_AHBSL_GPAEN));
}

/**
  * @brief  CALCEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_calc_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_CALCEN);
}

/**
  * @brief  CALCEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_calc_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_CALCEN);
}

/**
  * @brief  Get CALCEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : calc enable
  *         @arg 0x0 : calc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_calc_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_CALCEN) == (RCU_AHBSL_CALCEN));
}

/**
  * @brief  USBEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_usb_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_USBEN);
}

/**
  * @brief  USBEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_usb_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_USBEN);
}

/**
  * @brief  Get USBEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : usb enable
  *         @arg 0x0 : usb disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_usb_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_USBEN) == (RCU_AHBSL_USBEN));
}

/**
  * @brief  AESEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_aes_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_AESEN);
}

/**
  * @brief  AESEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_aes_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_AESEN);
}

/**
  * @brief  Get AESEN clock during Sleep mode bit.
  * @param  rcu RCU InstanceInstance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : aes enable
  *         @arg 0x0 : aes disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_aes_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_AESEN) == (RCU_AHBSL_AESEN));
}

/**
  * @brief  CRCEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_crc_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_CRCEN);
}

/**
  * @brief  CRCEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_crc_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_CRCEN);
}

/**
  * @brief  Get CRCEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : crc enable
  *         @arg 0x0 : crc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_crc_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_CRCEN) == (RCU_AHBSL_CRCEN));
}

/**
  * @brief  CSUEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_csu_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_CSUEN);
}

/**
  * @brief  CSUEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_csu_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_CSUEN);
}

/**
  * @brief  Get CSUEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : csu enable
  *         @arg 0x0 : csu disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_csu_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_CSUEN) == (RCU_AHBSL_CSUEN));
}

/**
  * @brief  KBCUEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_kbcu_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_KBCUEN);
}

/**
  * @brief  KBCUEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_kbcu_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_KBCUEN);
}

/**
  * @brief  Get KBCUEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : kbcu enable
  *         @arg 0x0 : kbcu disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_kbcu_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_KBCUEN) == (RCU_AHBSL_KBCUEN));
}

/**
  * @brief  RTCEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_rtc_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_RTCEN);
}

/**
  * @brief  RTCEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_rtc_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_RTCEN);
}

/**
  * @brief  Get RTCEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : rtc enable
  *         @arg 0x0 : rtc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_rtc_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_RTCEN) == (RCU_AHBSL_RTCEN));
}

/**
  * @brief  DMA1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_dma1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->AHBSL, RCU_AHBSL_DMA1EN);
}

/**
  * @brief  DMA1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_dma1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->AHBSL, RCU_AHBSL_DMA1EN);
}

/**
  * @brief  Get DMA1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : dma1 enable
  *         @arg 0x0 : dma1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_dma1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->AHBSL, RCU_AHBSL_DMA1EN) == (RCU_AHBSL_DMA1EN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group19 APB1SL
  * @{
  */
/**
  * @brief  Set RCU_APB1SL Register
  * @param  rcu RCU Instance
  * @param  apb1sl
  */
__STATIC_INLINE void md_rcu_set_apb1sl(RCU_TypeDef *rcu, uint32_t apb1sl)
{
    WRITE_REG(rcu->APB1SL, apb1sl);
}

/**
  * @brief  Get RCU_APB1SL Register
  * @param  rcu RCU Instance
  * @param  apb1sl
  */
__STATIC_INLINE uint32_t md_rcu_get_apb1sl(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->APB1SL));
}

/**
  * @brief  I2C2EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2c2_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_I2C2EN);
}

/**
  * @brief  I2C2EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2c2_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_I2C2EN);
}

/**
  * @brief  Get I2C2EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : i2c2 enable
  *         @arg 0x0 : i2c2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2c2_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_I2C2EN) == (RCU_APB1SL_I2C2EN));
}

/**
  * @brief  I2C1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2c1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_I2C1EN);
}

/**
  * @brief  I2C1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2c1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_I2C1EN);
}

/**
  * @brief  Get I2C1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : i2c1 enable
  *         @arg 0x0 : i2c1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2c1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_I2C1EN) == (RCU_APB1SL_I2C1EN));
}

/**
  * @brief  UART4EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart4_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_UART4EN);
}

/**
  * @brief  UART4EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart4_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_UART4EN);
}

/**
  * @brief  Get UART4EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart4 enable
  *         @arg 0x0 : uart4 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart4_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_UART4EN) == (RCU_APB1SL_UART4EN));
}

/**
  * @brief  UART3EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart3_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_UART3EN);
}

/**
  * @brief  UART3EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart3_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_UART3EN);
}

/**
  * @brief  Get UART3EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart3 enable
  *         @arg 0x0 : uart3 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart3_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_UART3EN) == (RCU_APB1SL_UART3EN));
}

/**
  * @brief  UART2EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart2_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_UART2EN);
}

/**
  * @brief  UART2EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart2_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_UART2EN);
}

/**
  * @brief  Get UART2EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart2 enable
  *         @arg 0x0 : uart2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart2_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_UART2EN) == (RCU_APB1SL_UART2EN));
}

/**
  * @brief  SPI3EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi3_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_SPI3EN);
}

/**
  * @brief  SPI3EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi3_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_SPI3EN);
}

/**
  * @brief  Get SPI3EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi3 enable
  *         @arg 0x0 : spi3 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi3_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_SPI3EN) == (RCU_APB1SL_SPI3EN));
}

/**
  * @brief  SPI2EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi2_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_SPI2EN);
}

/**
  * @brief  SPI2EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi2_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_SPI2EN);
}

/**
  * @brief  Get SPI2EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi2 enable
  *         @arg 0x0 : spi2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi2_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_SPI2EN) == (RCU_APB1SL_SPI2EN));
}

/**
  * @brief  WWDTEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_wwdt_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_WWDTEN);
}

/**
  * @brief WWDTEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_wwdt_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_WWDTEN);
}

/**
  * @brief  Get WWDTEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : wwdt enable
  *         @arg 0x0 : wwdt disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_wwdt_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_WWDTEN) == (RCU_APB1SL_WWDTEN));
}

/**
  * @brief  BS16T1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_bs16t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_BS16T1EN);
}

/**
  * @brief  BS16T1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_bs16t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_BS16T1EN);
}

/**
  * @brief  Get BS16T1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : bs16t1 enable
  *         @arg 0x0 : bs16t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_bs16t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_BS16T1EN) == (RCU_APB1SL_BS16T1EN));
}

/**
  * @brief  GP16C4T3EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t3_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T3EN);
}

/**
  * @brief  GP16C4T3EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t3_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T3EN);
}

/**
  * @brief  Get GP16C4T3EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t3 enable
  *         @arg 0x0 : gp16c4t3 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t3_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T3EN) == (RCU_APB1SL_GP16C4T3EN));
}

/**
  * @brief  GP16C4T2EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t2_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T2EN);
}

/**
  * @brief  GP16C4T2EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t2_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T2EN);
}

/**
  * @brief  Get GP16C4T2EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t2 enable
  *         @arg 0x0 : gp16c4t2 disable
y */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t2_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T2EN) == (RCU_APB1SL_GP16C4T2EN));
}

/**
  * @brief  GP16C4T1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T1EN);
}

/**
  * @brief  GP16C4T1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T1EN);
}

/**
  * @brief  Get GP16C4T1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t1 enable
  *         @arg 0x0 : gp16c4t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_GP16C4T1EN) == (RCU_APB1SL_GP16C4T1EN));
}

/**
  * @brief  GP32C4T1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp32c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB1SL, RCU_APB1SL_GP32C4T1EN);
}

/**
  * @brief  GP32C4T1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp32c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB1SL, RCU_APB1SL_GP32C4T1EN);
}

/**
  * @brief  Get GP32C4T1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp32c4t1 enable
  *         @arg 0x0 : gp32c4t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp32c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB1SL, RCU_APB1SL_GP32C4T1EN) == (RCU_APB1SL_GP32C4T1EN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group20 APB2SL
  * @{
  */
/**
  * @brief  Set RCU_APB2SL Register
  * @param  rcu RCU Instance
  * @param  apb2sl
  */
__STATIC_INLINE void md_rcu_set_apb2sl(RCU_TypeDef *rcu, uint32_t apb2sl)
{
    WRITE_REG(rcu->APB2SL, apb2sl);
}

/**
  * @brief  Get RCU_APB2SL Register
  * @param  rcu RCU Instance
  * @param  apb2sl
  */
__STATIC_INLINE uint32_t md_rcu_get_apb2sl(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->APB2SL));
}

/**
  * @brief  CMP clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_cmp_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_CMPEN);
}

/**
  * @brief  CMP clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_cmp_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_CMPEN);
}

/**
  * @brief  Get CMP clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : cmp enable
  *         @arg 0x0 : cmp disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_cmp_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_CMPEN) == (RCU_APB2SL_CMPEN));
}

/**
  * @brief  GP16C2T4EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t4_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T4EN);
}

/**
  * @brief  GP16C2T4EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t4_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T4EN);
}

/**
  * @brief  Get GP16C2T4EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t4 enable
  *         @arg 0x0 : gp16c2t4 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t4_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T4EN) == (RCU_APB2SL_GP16C2T4EN));
}

/**
  * @brief  GP16C2T3EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t3_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T3EN);
}

/**
  * @brief  GP16C2T3EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t3_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T3EN);
}

/**
  * @brief  Get GP16C2T3EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t3 enable
  *         @arg 0x0 : gp16c2t3 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t3_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T3EN) == (RCU_APB2SL_GP16C2T3EN));
}

/**
  * @brief  GP16C2T2EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t2_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T2EN);
}

/**
  * @brief  GP16C2T2EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t2_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T2EN);
}

/**
  * @brief  Get GP16C2T2EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t2 enable
  *         @arg 0x0 : gp16c2t2 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t2_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T2EN) == (RCU_APB2SL_GP16C2T2EN));
}

/**
  * @brief  GP16C2T1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_gp16c2t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T1EN);
}

/**
  * @brief  GP16C2T1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_gp16c2t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T1EN);
}

/**
  * @brief  Get GP16C2T1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t1 enable
  *         @arg 0x0 : gp16c2t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_gp16c2t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_GP16C2T1EN) == (RCU_APB2SL_GP16C2T1EN));
}

/**
  * @brief  UART1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_uart1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_UART1EN);
}

/**
  * @brief  UART1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_uart1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_UART1EN);
}

/**
  * @brief  Get UART1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart1 enable
  *         @arg 0x0 : uart1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_uart1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_UART1EN) == (RCU_APB2SL_UART1EN));
}

/**
  * @brief  SPI1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_spi1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_SPI1EN);
}

/**
  * @brief  I2S1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_i2s1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_SPI1EN);
}

/**
  * @brief  SPI1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_spi1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_SPI1EN);
}

/**
  * @brief  I2S1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_i2s1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_SPI1EN);
}


/**
  * @brief  Get SPI1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi1 enable
  *         @arg 0x0 : spi1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_spi1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_SPI1EN) == (RCU_APB2SL_SPI1EN));
}

/**
  * @brief  Get I2S1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi1 enable
  *         @arg 0x0 : spi1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_i2s1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_SPI1EN) == (RCU_APB2SL_SPI1EN));
}

/**
  * @brief  AD16C4T1EN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_ad16c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_AD16C4T1EN);
}

/**
  * @brief  AD16C4T1EN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_ad16c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_AD16C4T1EN);
}

/**
  * @brief  Get AD16C4T1EN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : ad16c4t1 enable
  *         @arg 0x0 : ad16c4t1 disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_ad16c4t1_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_AD16C4T1EN) == (RCU_APB2SL_AD16C4T1EN));
}

/**
  * @brief  ADCEN clock enable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_adc_in_sleep_mode(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->APB2SL, RCU_APB2SL_ADCEN);
}

/**
  * @brief  ADCEN clock disable during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_adc_in_sleep_mode(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->APB2SL, RCU_APB2SL_ADCEN);
}

/**
  * @brief  Get ADCEN clock during Sleep mode bit.
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : adc enable
  *         @arg 0x0 : adc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_adc_in_sleep_mode(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->APB2SL, RCU_APB2SL_ADCEN) == (RCU_APB2SL_ADCEN));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group21 LCON
  * @{
  */
/**
  * @brief  Set RCU_LCON Register
  * @param  rcu RCU Instance
  * @param  lcon
  */
__STATIC_INLINE void md_rcu_set_lcon(RCU_TypeDef *rcu, uint32_t lcon)
{
    WRITE_REG(rcu->LCON, lcon);
}

/**
  * @brief  Get RCU_LCON Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_rcu_get_lcon(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_REG(rcu->LCON));
}

/**
  * @brief  Set LOSC bypass mode enabled
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_losc_bypass(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->LCON, RCU_LCON_LOSCBYP);
}

/**
  * @brief  Set LOSC bypass mode disabled
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_losc_bypass(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->LCON, RCU_LCON_LOSCBYP);
}

/**
  * @brief  Get LOSC bypass mode
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : losc bypass enable
  *         @arg 0x0 : losc bypass disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_losc_bypass(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->LCON, RCU_LCON_LOSCBYP) == (RCU_LCON_LOSCBYP));
}

/**
  * @brief  Get LOSCRDY clock ready flag
  * @note
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_LOSCRDY_NOT_READY
  *         @arg @ref MD_RCU_LOSCRDY_READY
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_losc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->LCON, RCU_LCON_LOSCRDY) == (RCU_LCON_LOSCRDY));
}

/**
  * @brief  Set LOSC enbale bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_losc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->LCON, RCU_LCON_LOSCON);
}

/**
  * @brief  Set LOSC disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_losc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->LCON, RCU_LCON_LOSCON);
}

/**
  * @brief  Get LOSC bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : losc enable
  *         @arg 0x0 : losc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_losc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->LCON, RCU_LCON_LOSCON) == (RCU_LCON_LOSCON));
}

/**
  * @brief  Get LRCRDY clock ready flag
  * @note
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_LRCRDY_NOT_READY
  *         @arg @ref MD_RCU_LRCRDY_READY
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_lrc_ready(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->LCON, RCU_LCON_LRCRDY) == (RCU_LCON_LRCRDY));
}

/**
  * @brief  Set LRC enbale bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_enable_lrc(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->LCON, RCU_LCON_LRCON);
}

/**
  * @brief  Set LRC disable bit
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_disable_lrc(RCU_TypeDef *rcu)
{
    CLEAR_BIT(rcu->LCON, RCU_LCON_LRCON);
}

/**
  * @brief  Get LRC clock bit
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : lrc enable
  *         @arg 0x0 : lrc disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_lrc(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->LCON, RCU_LCON_LRCON) == (RCU_LCON_LRCON));
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group22 RSTF
  * @{
  */
/**
  * @brief  Set RCU_RSTF Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE void md_rcu_set_rstf(RCU_TypeDef *rcu, uint32_t rstf)
{
    WRITE_REG(rcu->RSTF, rstf);
}

/**
  * @brief  Get RCU_RSTF Register
  * @param  rcu RCU Instance
  */
__STATIC_INLINE uint32_t md_rcu_get_rstf(RCU_TypeDef *rcu)
{
    return (uint32_t)READ_REG(rcu->RSTF);
}

/**
  * @brief  Get Low power reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_wakeup(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RSTF, RCU_RSTF_LPRSTF) == (RCU_RSTF_LPRSTF));
}

/**
  * @brief  Get WWDT reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_wwdt(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RSTF, RCU_RSTF_WWDTRSTF) == (RCU_RSTF_WWDTRSTF));
}

/**
  * @brief  Get IWDT reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_iwdt(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RSTF, RCU_RSTF_IWDTRSTF) == (RCU_RSTF_IWDTRSTF));
}

/**
  * @brief  Get SW reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_software(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RSTF, RCU_RSTF_SWRSTF) == (RCU_RSTF_SWRSTF));
}

/**
  * @brief  Get Option Byte reload reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_option_byte_reload(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RSTF, RCU_RSTF_OBLRSTF) == (RCU_RSTF_OBLRSTF));
}

/**
  * @brief  Get NRST external pin reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_nrst(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RSTF, RCU_RSTF_NRSTF) == (RCU_RSTF_NRSTF));
}

/**
  * @brief  Get BOR reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_bor(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RSTF, RCU_RSTF_BORRSTF) == (RCU_RSTF_BORRSTF));
}

/**
  * @brief  Get POR/PDR reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_rcu_is_active_flag_por(RCU_TypeDef *rcu)
{
    return (READ_BIT(rcu->RSTF, RCU_RSTF_PORRSTF) == (RCU_RSTF_PORRSTF));
}

/**
  * @brief  Clear reset flag
  * @param  rcu RCU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void md_rcu_clear_flag_reset_flag(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->RSTF, RCU_RSTF_CLRFLG);
}
/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group27 CKTRIM
  * @{
  */
/**
  * @brief  Set RCU_CKTRIM Register
  * @param  rcu RCU Instance
  * @param  cktrim
  */
__STATIC_INLINE void md_rcu_set_cktrim(RCU_TypeDef *rcu, uint32_t cktrim)
{
    WRITE_REG(rcu->CKTRIM, cktrim);
}

/**
  * @brief  Get RCU_CKTRIM Register
  * @param  rcu RCU Instance
  * @param  cktrim
  */
__STATIC_INLINE uint32_t md_rcu_get_cktrim(RCU_TypeDef *rcu)
{
    return (uint32_t)READ_REG(rcu->CKTRIM);
}

/**
  * @brief  HRC48 update event
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_trigger_hrc48trim_update(RCU_TypeDef *rcu)
{
    SET_BIT(rcu->CKTRIM, RCU_CKTRIM_HRC48UE);
}

/**
  * @brief  Set HRC48 calibration value selection
  * @param  rcu RCU Instance
  *         @arg @ref MD_RCU_HRC48SEL_OPTIONBYTE
  *         @arg @ref MD_RCU_HRC48SEL_HRC48TRIM
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_hrc48trim_source(RCU_TypeDef *rcu, uint32_t hrc48sel)
{
    MODIFY_REG(rcu->CKTRIM, RCU_CKTRIM_HRC48SEL, hrc48sel << RCU_CKTRIM_HRC48SEL_POS);
}

/**
  * @brief  Get HRC48 calibration value selection
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_HRC48SEL_OPTIONBYTE
  *         @arg @ref MD_RCU_HRC48SEL_HRC48TRIM
  */
__STATIC_INLINE uint32_t md_rcu_get_hrc48trim_source(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CKTRIM, RCU_CKTRIM_HRC48SEL) >> RCU_CKTRIM_HRC48SEL_POS);
}

/**
  * @brief  Set HRC calibration value selection
  * @param  rcu RCU Instance
  * @param  hrcsel
  *         @arg @ref MD_RCU_HRCSEL_OPTIONBYTE
  *         @arg @ref MD_RCU_HRCSEL_HRCTRIM
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_hrctrim_source(RCU_TypeDef *rcu, uint32_t hrcsel)
{
    MODIFY_REG(rcu->CKTRIM, RCU_CKTRIM_HRCSEL, hrcsel << RCU_CKTRIM_HRCSEL_POS);
}

/**
  * @brief  Get HRC calibration value selection
  * @param  rcu RCU Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_RCU_HRCSEL_OPTIONBYTE
  *         @arg @ref MD_RCU_HRCSEL_HRCTRIM
  */
__STATIC_INLINE uint32_t md_rcu_get_hrctrim_source(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CKTRIM, RCU_CKTRIM_HRCSEL) >> RCU_CKTRIM_HRCSEL_POS);
}

/**
  * @brief  Set HRC48 calibration value
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_hrc48trim(RCU_TypeDef *rcu, uint32_t hrc48trim)
{
    MODIFY_REG(rcu->CKTRIM, RCU_CKTRIM_HRC48TRIM, (hrc48trim << RCU_CKTRIM_HRC48TRIM_POSS));
}

/**
  * @brief  Get HRC48 calibration value
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rcu_get_hrc48trim(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CKTRIM, RCU_CKTRIM_HRC48TRIM) >> RCU_CKTRIM_HRC48TRIM_POSS);
}

/**
  * @brief  Set HRC calibration value
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE void md_rcu_set_hrctrim(RCU_TypeDef *rcu, uint32_t hrctrim)
{
    MODIFY_REG(rcu->CKTRIM, RCU_CKTRIM_HRCTRIM, (hrctrim << RCU_CKTRIM_HRCTRIM_POSS));
}

/**
  * @brief  Get HRC calibration value
  * @param  rcu RCU Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_rcu_get_hrctrim(RCU_TypeDef *rcu)
{
    return (uint32_t)(READ_BIT(rcu->CKTRIM, RCU_CKTRIM_HRCTRIM) >> RCU_CKTRIM_HRCTRIM_POSS);
}

/**
  * @}
  */

/** @defgroup MD_RCU_Public_Functions_Group1 Initialization
  * @{
  */
void md_rcu_pll0_init(RCU_TypeDef *, md_rcu_init_typedef *);
void md_rcu_sys_init(RCU_TypeDef *, md_rcu_init_typedef *);
void  md_tick_waitms_rcu(uint8_t Unit, uint16_t msCnt);

void md_rcu_hrc_software_trim(RCU_TypeDef *, uint8_t);
void md_rcu_hrc_disable_software_trim(RCU_TypeDef *);
void md_rcu_hrc48_software_trim(RCU_TypeDef *, uint16_t);
void md_rcu_hrc48_disable_software_trim(RCU_TypeDef *);
uint16_t md_rcu_get_hrc_option_trim_value(RCU_TypeDef *);
uint16_t md_rcu_get_hrc48_option_trim_value(RCU_TypeDef *);
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
  * @} Micro_Driver
  */


#ifdef __cplusplus
}
#endif
#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

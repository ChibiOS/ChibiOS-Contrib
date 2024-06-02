/**********************************************************************************
 *
 * @file    md_csu.h
 * @brief   header file of md_csu.c
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov  2021    Ginger          the first version
 *          25 Mar 2022     AE Team         Modify MD Driver
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
#ifndef __MD_CSU_H__
#define __MD_CSU_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include <stdbool.h>
#include "fs026.h"


/** @addtogroup Micro_Driver
  * @{
  */


/** @defgroup MD_CSU CSU
  * @brief CSU micro driver
  * @{
  */

/** @defgroup MD_CSU_Pubulic_Types CSU Pubulic Types
  * @{
  */

/**
  * @brief CSU Init structure
  */
typedef struct
{
    uint32_t TrimSel;         /*!< Trim Value Selection.*/
    uint32_t PolSel;          /*!< Synchronous clock polarity selection.*/
    uint32_t SyncSrc;         /*!< Synchronous clock source selection.*/
    uint32_t SyncDiv;         /*!< Synchronous clock source pre-divider.*/
} md_csu_init_typedef;

typedef struct
{
    uint32_t CntTh;           /*!< Count tolerance.*/
    uint32_t Reload;          /*!< Counter reload value.*/
} md_csu_set_typedef;
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Macros CSU Public Macros
  * @{
  */

#define MD_CSU_CFG_TRIMSEL_OPTIONBYTE       (0U)
#define MD_CSU_CFG_TRIMSEL_CUSTOM           (1U)

#define MD_CSU_CFG_POLSEL_RISING            (0U)
#define MD_CSU_CFG_POLSEL_FALLING           (1U)

#define MD_CSU_CFG_SYNCSRC_GPIO             (0U)
#define MD_CSU_CFG_SYNCSRC_LOSC             (1U)
#define MD_CSU_CFG_SYNCSRC_USB              (2U)
#define MD_CSU_CFG_SYNCSRC_SW               (3U)

#define MD_CSU_CFG_SYNCDIV_DIV1             (0U)
#define MD_CSU_CFG_SYNCDIV_DIV2             (1U)
#define MD_CSU_CFG_SYNCDIV_DIV4             (2U)
#define MD_CSU_CFG_SYNCDIV_DIV8             (3U)
#define MD_CSU_CFG_SYNCDIV_DIV16            (4U)
#define MD_CSU_CFG_SYNCDIV_DIV32            (5U)
#define MD_CSU_CFG_SYNCDIV_DIV64            (6U)
#define MD_CSU_CFG_SYNCDIV_DIV128           (7U)

#define     CSU_CLKSRC_GPIO                 1000                     // GPIO Input 1kHz Frequency (User defined)
#define     CSU_CLKSRC_LOSC                 __LOSC                   // LOSC 32.768kHz Divide by 32
#define     CSU_CLKSRC_USB_SOF              1000                     // Get USB SOF Package every 1 ms
#define     FSYNC                           CSU_CLKSRC_USB_SOF       // Clock Source Selection (User defined)
#define     MD_CSU_CFG_RELOAD               ((__HRC48/FSYNC)-1)      // (Ftarget/Fsync)-1
#define     MD_CSU_CFG_CNTTH                (__HRC48/FSYNC/5/100/2)  // (Ftarget/Fsync)*SETP[%]/100%/2
/**
  * @}
  */


/** @defgroup MD_CSU_Public_Functions CSU Public Functions
  * @{
  */

/** @defgroup MD_CSU_Public_Functions_Group2 CON
  * @{
  */
/**
  * @brief  Set CSU_CON Register
  * @param  csu CSU Instance
  * @param  con
  * @retval None
  */
__STATIC_INLINE void md_csu_set_con(CSU_TypeDef *csu, uint32_t con)
{
    WRITE_REG(csu->CON, con);
}

/**
  * @brief  Get CSU_CON Register
  * @param  csu CSU Instance
  * @retval Read all CSU_CON Register
  */
__STATIC_INLINE uint32_t md_csu_get_con(CSU_TypeDef *csu)
{
    return (uint32_t) READ_REG(csu->CON);
}

/**
  * @brief  Set CSU Trim Value.
  * @param  csu CSU Instance.
  * @param  trim
  * @retval None
  */
__STATIC_INLINE void md_csu_set_hrc48trim(CSU_TypeDef *csu, uint32_t trim)
{
    MODIFY_REG(csu->CON, CSU_CON_TRIM, trim << CSU_CON_TRIM_POSS);
}

/**
  * @brief  Get CSU Trim Value.
  * @param  csu CSU Instance.
  * @retval Read HRC48 Trim value
  */
__STATIC_INLINE uint32_t md_csu_get_hrc48trim(CSU_TypeDef *csu)
{
    return (uint32_t)((READ_BIT(csu->CON, CSU_CON_TRIM)) >> CSU_CON_TRIM_POSS);
}

/**
  * @brief  CSU Software synchronization clock generation.
  * @param  csu CSU Instance
  * @retval None
  */
__STATIC_INLINE void md_csu_trigger_sync_software(CSU_TypeDef *csu)
{
    SET_BIT(csu->CON, CSU_CON_SYNCGEN);
}

/**
  * @brief  CSU Automatic calibration switch enable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_enable_trim_auto(CSU_TypeDef *csu)
{
    SET_BIT(csu->CON, CSU_CON_AUTOEN);
}

/**
  * @brief  CSU  Automatic calibration switch disable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_disable_trim_auto(CSU_TypeDef *csu)
{
    CLEAR_BIT(csu->CON, CSU_CON_AUTOEN);
}

/**
  * @brief  Check if CSU  Automatic calibration switch is enabled.
  * @param  csu CSU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : trim auto enable
  *         @arg 0x0 : trim auto disable
  */
__STATIC_INLINE uint32_t md_csu_is_enabled_trim_auto(CSU_TypeDef *csu)
{
    return (uint32_t)(READ_BIT(csu->CON, CSU_CON_AUTOEN) == (CSU_CON_AUTOEN));
}

/**
  * @brief  CSU Counter switch enable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_enable_trim_counter(CSU_TypeDef *csu)
{
    SET_BIT(csu->CON, CSU_CON_CNTEN);
}

/**
  * @brief  CSU Counter switch disable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_disable_trim_counter(CSU_TypeDef *csu)
{
    CLEAR_BIT(csu->CON, CSU_CON_CNTEN);
}

/**
  * @brief  Check if CSU Counter switch is enabled.
  * @param  csu CSU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : trim counter enable
  *         @arg 0x0 : trim counter disable
  */
__STATIC_INLINE uint32_t md_csu_is_enabled_trim_counter(CSU_TypeDef *csu)
{
    return (uint32_t)(READ_BIT(csu->CON, CSU_CON_CNTEN) == (CSU_CON_CNTEN));
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group3 CFG
  * @{
  */
/**
  * @brief  Set CSU_CFG Register
  * @param  csu CSU Instance
  * @param  cfg
  * @retval None
  */
__STATIC_INLINE void md_csu_set_cfg(CSU_TypeDef *csu, uint32_t cfg)
{
    WRITE_REG(csu->CFG, cfg);
}

/**
  * @brief  Get CSU_CFG Register
  * @param  csu CSU Instance
  * @retval Read all CSU_CFG Register
  */
__STATIC_INLINE uint32_t md_csu_get_cfg(CSU_TypeDef *csu)
{
    return (uint32_t) READ_REG(csu->CFG);
}

/**
  * @brief  Set CSU Trim Value Selection.
  * @param  csu CSU Instance.
  * @param  trimsel
            @arg @ref MD_CSU_CFG_TRIMSEL_OPTIONBYTE
            @arg @ref MD_CSU_CFG_TRIMSEL_CUSTOM
  * @retval None
  */
__STATIC_INLINE void md_csu_set_trim_source(CSU_TypeDef *csu, uint32_t trimsel)
{
    MODIFY_REG(csu->CFG, CSU_CFG_TRIMSEL, trimsel << CSU_CFG_TRIMSEL_POS);
}

/**
  * @brief  Get CSU Trim Value Selection.
  * @param  csu CSU Instance.
  * @retval The retval can be one of the following values:
            @arg @ref MD_CSU_CFG_TRIMSEL_OPTIONBYTE
            @arg @ref MD_CSU_CFG_TRIMSEL_CUSTOM
  */
__STATIC_INLINE uint32_t md_csu_get_trim_source(CSU_TypeDef *csu)
{
    return (uint32_t)(READ_BIT(csu->CFG, CSU_CFG_TRIMSEL) >> CSU_CFG_TRIMSEL_POS);
}

/**
  * @brief  Set CSU Synchronous clock polarity selection.
  * @param  csu CSU Instance.
  * @param  polsel
            @arg @ref MD_CSU_CFG_POLSEL_RISING
            @arg @ref MD_CSU_CFG_POLSEL_FALLING
  * @retval None
  */
__STATIC_INLINE void md_csu_set_sync_polarity(CSU_TypeDef *csu, uint32_t polsel)
{
    MODIFY_REG(csu->CFG, CSU_CFG_POLSEL, polsel << CSU_CFG_POLSEL_POS);
}

/**
  * @brief  Get CSU Synchronous clock polarity selection.
  * @param  csu CSU Instance.
  * @retval The retval can be one of the following values:
            @arg @ref MD_CSU_CFG_POLSEL_RISING
            @arg @ref MD_CSU_CFG_POLSEL_FALLING
  */
__STATIC_INLINE uint32_t md_csu_get_sync_polarity(CSU_TypeDef *csu)
{
    return (uint32_t)(READ_BIT(csu->CFG, CSU_CFG_POLSEL) >> CSU_CFG_POLSEL_POS);
}

/**
  * @brief  Set CSU Synchronous clock source selection.
  * @param  csu CSU Instance.
  * @param  syncsrc
            @arg @ref MD_CSU_CFG_SYNCSRC_GPIO
            @arg @ref MD_CSU_CFG_SYNCSRC_LOSC
            @arg @ref MD_CSU_CFG_SYNCSRC_USB
            @arg @ref MD_CSU_CFG_SYNCSRC_SW
  * @retval None
  */
__STATIC_INLINE void md_csu_set_sync_source(CSU_TypeDef *csu, uint32_t syncsrc)
{
    MODIFY_REG(csu->CFG, CSU_CFG_SYNCSRC, syncsrc << CSU_CFG_SYNCSRC_POSS);
}

/**
  * @brief  Get CSU Synchronous clock source selection.
  * @param  csu CSU Instance.
  * @retval The retval can be one of the following values:
            @arg @ref MD_CSU_CFG_SYNCSRC_GPIO
            @arg @ref MD_CSU_CFG_SYNCSRC_LOSC
            @arg @ref MD_CSU_CFG_SYNCSRC_USB
            @arg @ref MD_CSU_CFG_SYNCSRC_SW
  */
__STATIC_INLINE uint32_t md_csu_get_sync_source(CSU_TypeDef *csu)
{
    return (uint32_t)(READ_BIT(csu->CFG, CSU_CFG_SYNCSRC) >> CSU_CFG_SYNCSRC_POSS);
}

/**
  * @brief  Set CSU Synchronous clock source pre-divider.
  * @param  csu CSU Instance.
  * @param  syncdiv
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV1
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV2
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV4
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV8
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV16
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV32
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV64
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV128
  * @retval None
  */
__STATIC_INLINE void md_csu_set_sync_source_div(CSU_TypeDef *csu, uint32_t syncdiv)
{
    MODIFY_REG(csu->CFG, CSU_CFG_SYNCDIV, syncdiv << CSU_CFG_SYNCDIV_POSS);
}

/**
  * @brief  Get CSU Synchronous clock source pre-divider.
  * @param  csu CSU Instance.
  * @retval The retval can be one of the following values:
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV1
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV2
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV4
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV8
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV16
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV32
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV64
            @arg @ref MD_CSU_CFG_SYNCDIV_DIV128
  */
__STATIC_INLINE uint32_t md_csu_get_sync_source_div(CSU_TypeDef *csu)
{
    return (uint32_t)(READ_BIT(csu->CFG, CSU_CFG_SYNCDIV) >> CSU_CFG_SYNCDIV_POSS);
}

/**
  * @brief  Set CSU Count tolerance.
  * @param  csu CSU Instance.
  * @param  cntth
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_csu_set_trim_counter_tolerance(CSU_TypeDef *csu, uint32_t cntth)
{
    MODIFY_REG(csu->CFG, CSU_CFG_CNTTH, cntth << CSU_CFG_CNTTH_POSS);
}

/**
  * @brief  Get CSU Count tolerance.
  * @param  csu CSU Instance.
  * @retval Read Count tolerance
  *         @arg Max Value 0xFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_csu_get_trim_counter_tolerance(CSU_TypeDef *csu)
{
    return (uint32_t)((READ_BIT(csu->CFG, CSU_CFG_CNTTH)) >> CSU_CFG_CNTTH_POSS);
}

/**
  * @brief  Set CSU Counter reload value.
  * @param  csu CSU Instance.
  * @param  reload
  *         @arg Max Value 0xFFFF
  *         @arg Min Value 0x0
  * @retval None
  */
__STATIC_INLINE void md_csu_set_trim_counter_reload(CSU_TypeDef *csu, uint32_t reload)
{
    MODIFY_REG(csu->CFG, CSU_CFG_RELOAD, reload << CSU_CFG_RELOAD_POSS);
}

/**
  * @brief  Get CSU Counter reload value.
  * @param  csu CSU Instance.
  * @retval Read Counter reload value
  *         @arg Max Value 0xFFFF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_csu_get_trim_counter_reload(CSU_TypeDef *csu)
{
    return (uint32_t)((READ_BIT(csu->CFG, CSU_CFG_RELOAD)) >> CSU_CFG_RELOAD_POSS);
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group4 STAT
  * @{
  */
/**
  * @brief  Get CSU_STAT Register
  * @param  csu CSU Instance
  * @retval Read all CSC_STAT Register
  */
__STATIC_INLINE uint32_t md_csu_get_stat(CSU_TypeDef *csu)
{
    return (uint32_t) READ_REG(csu->STAT);
}

/**
  * @brief  Get CSU Option Byte value.
  * @param  csu CSU Instance.
  * @retval Read Option Byte trim value
  */
__STATIC_INLINE uint32_t md_csu_get_option_hrc48trim(CSU_TypeDef *csu)
{
    return (uint32_t)((READ_BIT(csu->STAT, CSU_STAT_OPT_TRIM)) >> CSU_STAT_OPT_TRIM_POSS);
}

/**
  * @brief  Get CSU Counter direction.
  * @param  csu CSU Instance
  * @retval Read Counter direction
  *         @arg 0x1 : Countdown
  *         @arg 0x0 : Countup
  */
__STATIC_INLINE uint32_t md_csu_get_trim_counter_direction(CSU_TypeDef *csu)
{
    return (uint32_t)((READ_BIT(csu->STAT, CSU_STAT_CNTDIR)) >> CSU_STAT_CNTDIR_POS);
}

/**
  * @brief  Get CSU Count value record.
  * @param  csu CSU Instance.
  * @retval Read Count value record
  */
__STATIC_INLINE uint32_t md_csu_get_trim_counter_capture(CSU_TypeDef *csu)
{
    return (uint32_t)((READ_BIT(csu->STAT, CSU_STAT_CNTCAP)) >> CSU_STAT_CNTCAP_POSS);
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group5 IER
  * @{
  */
/**
  * @brief  Set CSU_IER Register
  * @param  csu CSU Instance
  * @param  ier
  */
__STATIC_INLINE void md_csu_set_ier(CSU_TypeDef *csu, uint32_t ier)
{
    WRITE_REG(csu->IER, ier);
}

/**
  * @brief  Ideal synchronous interrupt function Enable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_enable_it_trim_match(CSU_TypeDef *csu)
{
    SET_BIT(csu->IER, CSU_IER_FHIT);
}

/**
  * @brief  Calibration value error interrupt function Enable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_enable_it_trim_error(CSU_TypeDef *csu)
{
    SET_BIT(csu->IER, CSU_IER_TRIMERR);
}

/**
  * @brief  Clock synchronization abnormal interrupt function Enable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_enable_it_trim_fault(CSU_TypeDef *csu)
{
    SET_BIT(csu->IER, CSU_IER_FFAULT);
}

/**
  * @brief  Clock synchronization error interrupt function Enable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_enable_it_counter_error(CSU_TypeDef *csu)
{
    SET_BIT(csu->IER, CSU_IER_FERROR);
}

/**
  * @brief  Clock synchronization warning interrupt function Enable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_enable_it_counter_warning(CSU_TypeDef *csu)
{
    SET_BIT(csu->IER, CSU_IER_FWARN);
}

/**
  * @brief  Clock synchronization match interrupt function Enable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_enable_it_counter_match(CSU_TypeDef *csu)
{
    SET_BIT(csu->IER, CSU_IER_FMATCH);
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group6 IDR
  * @{
  */
/**
  * @brief  Set CSU_IDR Register
  * @param  csu CSU Instance
  * @param  idr
  */
__STATIC_INLINE void md_csu_set_idr(CSU_TypeDef *csu, uint32_t idr)
{
    WRITE_REG(csu->IDR, idr);
}

/**
  * @brief  Ideal synchronous interrupt function Disable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_disable_it_trim_match(CSU_TypeDef *csu)
{
    SET_BIT(csu->IDR, CSU_IDR_FHIT);
}

/**
  * @brief  Calibration value error interrupt function Disable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_disable_it_trim_error(CSU_TypeDef *csu)
{
    SET_BIT(csu->IDR, CSU_IDR_TRIMERR);
}

/**
  * @brief  Clock synchronization abnormal interrupt function Disable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_disable_it_trim_fault(CSU_TypeDef *csu)
{
    SET_BIT(csu->IDR, CSU_IDR_FFAULT);
}

/**
  * @brief  Clock synchronization error interrupt function Disable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_disable_it_counter_error(CSU_TypeDef *csu)
{
    SET_BIT(csu->IDR, CSU_IDR_FERROR);
}

/**
  * @brief  Clock synchronization warning interrupt function Disable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_disable_it_counter_warning(CSU_TypeDef *csu)
{
    SET_BIT(csu->IDR, CSU_IDR_FWARN);
}

/**
  * @brief  Clock synchronization match interrupt function Disable.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_disable_it_counter_match(CSU_TypeDef *csu)
{
    SET_BIT(csu->IDR, CSU_IDR_FMATCH);
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group7 IVS
  * @{
  */
/**
  * @brief  Get CSU_IVS Register
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_csu_get_ivs(CSU_TypeDef *csu)
{
    return (uint32_t) READ_REG(csu->IVS);
}

/**
  * @brief  Check if Ideal synchronous interrupt is enabled.
  * @param  csu CSU Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : trim match
  *         @arg 0x0 : trim mismatch
  */
__STATIC_INLINE uint32_t md_csu_is_enabled_it_trim_match(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IVS, CSU_IVS_FHIT) == (CSU_IVS_FHIT));
}

/**
  * @brief  Check if Calibration value error interrupt is enabled.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_enabled_it_trim_error(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IVS, CSU_IVS_TRIMERR) == (CSU_IVS_TRIMERR));
}

/**
  * @brief  Check if Clock synchronization abnormal interrupt is enabled.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_enabled_it_trim_fault(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IVS, CSU_IVS_FFAULT) == (CSU_IVS_FFAULT));
}

/**
  * @brief  Check if Clock synchronization error interrupt is enabled.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_enabled_it_counter_error(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IVS, CSU_IVS_FERROR) == (CSU_IVS_FERROR));
}

/**
  * @brief  Check if Clock synchronization warning interrupt is enabled.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_enabled_it_counter_warning(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IVS, CSU_IVS_FWARN) == (CSU_IVS_FWARN));
}

/**
  * @brief  Check if Clock synchronization match interrupt is enabled.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_enabled_it_counter_match(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IVS, CSU_IVS_FMATCH) == (CSU_IVS_FMATCH));
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group8 RIF
  * @{
  */
/**
  * @brief  Set CSU_RIF Register
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_csu_get_rif(CSU_TypeDef *csu)
{
    return (uint32_t) READ_REG(csu->RIF);
}

/**
  * @brief  Get Ideal synchronous interrupt flag.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_active_flag_trim_match(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->RIF, CSU_RIF_FHIT) == (CSU_RIF_FHIT));
}

/**
  * @brief  Get Calibration value error interrupt flag.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_active_flag_trim_error(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->RIF, CSU_RIF_TRIMERR) == (CSU_RIF_TRIMERR));
}

/**
  * @brief  Get Clock synchronization abnormal interrupt flag.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_active_flag_trim_fault(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->RIF, CSU_RIF_FFAULT) == (CSU_RIF_FFAULT));
}

/**
  * @brief  Get Clock synchronization error interrupt flag.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_active_flag_counter_error(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->RIF, CSU_RIF_FERROR) == (CSU_RIF_FERROR));
}

/**
  * @brief  Get Clock synchronization warning interrupt flag.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_active_flag_counter_warning(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->RIF, CSU_RIF_FWARN) == (CSU_RIF_FWARN));
}

/**
  * @brief  Get Clock synchronization match interrupt flag.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_active_flag_counter_match(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->RIF, CSU_RIF_FMATCH) == (CSU_RIF_FMATCH));
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group9 IFM
  * @{
  */
/**
  * @brief  Set CSU_IFM Register
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE uint32_t md_csu_get_ifm(CSU_TypeDef *csu)
{
    return (uint32_t) READ_REG(csu->IFM);
}

/**
  * @brief  Get Ideal synchronous interrupt flag masked.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_masked_it_trim_match(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IFM, CSU_IFM_FHIT) == (CSU_IFM_FHIT));
}

/**
  * @brief  Get Calibration value error interrupt flag masked.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_masked_it_trim_error(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IFM, CSU_IFM_TRIMERR) == (CSU_IFM_TRIMERR));
}

/**
  * @brief  Get Clock synchronization abnormal interrupt flag masked.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_masked_it_trim_fault(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IFM, CSU_IFM_FFAULT) == (CSU_IFM_FFAULT));
}

/**
  * @brief  Get Clock synchronization error interrupt flag masked.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_masked_it_counter_error(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IFM, CSU_IFM_FERROR) == (CSU_IFM_FERROR));
}

/**
  * @brief  Get Clock synchronization warning interrupt flag masked.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_masked_it_counter_warning(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IFM, CSU_IFM_FWARN) == (CSU_IFM_FWARN));
}

/**
  * @brief  Get Clock synchronization match interrupt flag masked.
  * @param  csu CSU Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_csu_is_masked_it_counter_match(CSU_TypeDef *csu)
{
    return (READ_BIT(csu->IFM, CSU_IFM_FMATCH) == (CSU_IFM_FMATCH));
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group10 ICR
  * @{
  */
/**
  * @brief  Set CSU_ICR Register
  * @param  csu CSU Instance
  * @param  icr
  * @retval None.
  */
__STATIC_INLINE void md_csu_set_icr(CSU_TypeDef *csu, uint32_t icr)
{
    WRITE_REG(csu->ICR, icr);
}

/**
  * @brief  Ideal synchronous interrupt function flag clear.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_clear_it_trim_match(CSU_TypeDef *csu)
{
    SET_BIT(csu->ICR, CSU_ICR_FHIT);
}

/**
  * @brief  Calibration value error interrupt function flag clear.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_clear_it_trim_error(CSU_TypeDef *csu)
{
    SET_BIT(csu->ICR, CSU_ICR_TRIMERR);
}

/**
  * @brief  Clock synchronization abnormal interrupt function flag clear.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_clear_it_trim_fault(CSU_TypeDef *csu)
{
    SET_BIT(csu->ICR, CSU_ICR_FFAULT);
}

/**
  * @brief  Clock synchronization error interrupt function flag clear.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_clear_it_counter_error(CSU_TypeDef *csu)
{
    SET_BIT(csu->ICR, CSU_ICR_FERROR);
}

/**
  * @brief  Clock synchronization warning interrupt function flag clear.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_clear_it_counter_warning(CSU_TypeDef *csu)
{
    SET_BIT(csu->ICR, CSU_ICR_FWARN);
}

/**
  * @brief  Clock synchronization match interrupt function flag clear.
  * @param  csu CSU Instance
  * @retval None.
  */
__STATIC_INLINE void md_csu_clear_it_counter_match(CSU_TypeDef *csu)
{
    SET_BIT(csu->ICR, CSU_ICR_FMATCH);
}
/**
  * @}
  */

/** @defgroup MD_CSU_Public_Functions_Group1 Initialization
  * @{
  */
void md_csu_init(CSU_TypeDef *csu, md_csu_init_typedef *CSU_InitStruct);
void md_csu_set(CSU_TypeDef *csu, md_csu_init_typedef *CSU_InitStruct, uint16_t);
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

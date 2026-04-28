/**********************************************************************************
 *
 * @file    md_wwdt.h
 * @brief   Header file of WWDT module driver.
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

#ifndef __MD_WWDT_H__
#define __MD_WWDT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------ */
#include "md_utils.h"

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

/** @addtogroup Micro_Driver
  * @{
  */
/** @addtogroup MD_WWDT WWDT
  * @{
  */

/* Exported Types ------------------------------------------------------------ */

/** @defgroup MD_WWDT_Public_Types WWDT Public Types
  * @{
  */
/**
  * @brief wwdt no dog window
  */
typedef enum
{
    MD_WWDT_WIN_25 = 0x0U,        /**< No dog window size: 25% */
    MD_WWDT_WIN_50 = 0x1U,        /**< No dog window size: 50% */
    MD_WWDT_WIN_75 = 0x2U,        /**< No dog window size: 75% */
    MD_WWDT_WIN_00 = 0x3U,        /**< No dog window size: 0% */
} md_wwdt_win_t;
/**
 * @}
 */

/* Exported Macros ----------------------------------------------------------- */

/**
 * @defgroup MD_WWDT_Private_Macros WWDT Private Macros
 * @{
 */
#define WWDT_UNLOCK() {WRITE_REG(WWDT->LOCK, 0x1ACCE551U);}
#define WWDT_LOCK()   {WRITE_REG(WWDT->LOCK, 0xFFFFFFFFU);}
/**
 * @}
 */

/* Exported Functions -------------------------------------------------------- */

/** @addtogroup MD_WWDT_Public_Functions  WWDT Public Functions
  * @{
  */
/** @defgroup MD_WWDT_Public_Functions_Group2 LOAD
  * @{
  */
/**
  * @brief  Set wwdt count overload value.
  * @param  cnt: Value for overload value.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_count_overload(uint32_t cnt)
{
    MODIFY_REG(WWDT->LOAD_, WWDT_LOAD_LOAD_MSK, cnt << WWDT_LOAD_LOAD_POSS);
}
/**
 * @}
 */
/** @defgroup MD_WWDT_Public_Functions_Group3 VALUE
  * @{
  */
/**
  * @brief  Get wwdt current count value.
  * @retval Value for count value.
  */
__STATIC_INLINE uint32_t md_wwdt_get_count_value(void)
{
    return READ_BITS(WWDT->VALUE, WWDT_VALUE_VALUE_MSK, WWDT_VALUE_VALUE_POSS);
}
/**
 * @}
 */
/** @defgroup MD_WWDT_Public_Functions_Group4 CON
  * @{
  */
/**
  * @brief  Set wwdt forbid feed dog time.
  * @param  time: forbid feed dog time @see wwdt_win_t.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_forbid_feed_time(md_wwdt_win_t time)
{
    MODIFY_REG(WWDT->CON, WWDT_CON_WWDTWIN_MSK, time << WWDT_CON_WWDTWIN_POSS);
}

/**
  * @brief  Read wwdt forbid feed dog time.
  * @retval Time for forbid feed dog.
  */
__STATIC_INLINE uint32_t md_wwdt_get_forbid_feed_time(void)
{
    return READ_BITS(WWDT->CON, WWDT_CON_WWDTWIN_MSK, WWDT_CON_WWDTWIN_POSS);
}

/**
  * @brief  Set wwdt count by pclk.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_count_pclk(void)
{
    CLEAR_BIT(WWDT->CON, WWDT_CON_CLKS_MSK);
}

/**
  * @brief  Set wwdt count by lrc.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_set_count_lrc(void)
{
    SET_BIT(WWDT->CON, WWDT_CON_CLKS_MSK);
}

/**
  * @brief  Check if wwdt count clock is pclk source.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint8_t md_wwdt_is_enable_count_pclk(void)
{
    return (READ_BIT(WWDT->CON, WWDT_CON_CLKS_MSK) != WWDT_CON_CLKS_MSK);
}

/**
  * @brief  Check if wwdt count clock is lrc source.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint8_t md_wwdt_is_enable_count_lrc(void)
{
    return (READ_BIT(WWDT->CON, WWDT_CON_CLKS_MSK) == WWDT_CON_CLKS_MSK);
}

/**
  * @brief  Enable wwdt reset bit.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_enable_reset(void)
{
    SET_BIT(WWDT->CON, WWDT_CON_RSTEN_MSK);
}

/**
  * @brief  Disable wwdt reset bit.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_disable_reset(void)
{
    CLEAR_BIT(WWDT->CON, WWDT_CON_RSTEN_MSK);
}

/**
  * @brief  Check if is enable reset bit.
  * @retval State for 1 or 0
  */
__STATIC_INLINE uint8_t md_wwdt_is_enable_reset(void)
{
    return (READ_BIT(WWDT->CON, WWDT_CON_RSTEN_MSK) == WWDT_CON_RSTEN_MSK);
}

/**
  * @brief  Enable wwdt interrupt.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_enable_interrupt(void)
{
    SET_BIT(WWDT->CON, WWDT_CON_IE_MSK);
}

/**
  * @brief  Disable wwdt interrupt.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_disable_interrupt(void)
{
    CLEAR_BIT(WWDT->CON, WWDT_CON_IE_MSK);
}

/**
  * @brief  Check if is enable interrupt.
  * @retval State for 1 or 0
  */
__STATIC_INLINE uint8_t md_wwdt_is_enable_interrupt(void)
{
    return (READ_BIT(WWDT->CON, WWDT_CON_IE_MSK) == WWDT_CON_IE_MSK);
}

/**
  * @brief  Enable wwdt module.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_enable(void)
{
    SET_BIT(WWDT->CON, WWDT_CON_EN_MSK);
}

/**
  * @brief  Disable wwdt interrupt.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_disable(void)
{
    CLEAR_BIT(WWDT->CON, WWDT_CON_EN_MSK);
}

/**
  * @brief  Check if is enable interrupt.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint8_t md_wwdt_is_enable(void)
{
    return (READ_BIT(WWDT->CON, WWDT_CON_EN_MSK) == WWDT_CON_EN_MSK);
}
/**
 * @}
 */
/** @defgroup MD_WWDT_Public_Functions_Group5 INTCLR
  * @{
  */
/**
  * @brief  Clear wwdt Interrupt flag.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_clear_interrupt(void)
{
    WRITE_REG(WWDT->INTCLR, 0x55AA);
}
/**
  * @brief  feed wwdt.
  * @retval None
  */
__STATIC_INLINE void md_wwdt_feed_wwdt(void)
{
    WRITE_REG(WWDT->INTCLR, 0xFFFFFFFF);
}
/**
 * @}
 */
/** @defgroup MD_WWDT_Public_Functions_Group6 RIS
  * @{
  */
/**
  * @brief  Read wwdt interrupt flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint8_t md_wwdt_read_interrupt(void)
{
    return (READ_BIT(WWDT->RIS, WWDT_RIS_WWDTIF_MSK) == WWDT_RIS_WWDTIF_MSK);
}
/**
 * @}
 */
/** @defgroup MD_WWDT_Public_Functions_Group7 LOCK
  * @{
  */
/**
  * @brief  Read wwdt project register status.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint8_t md_wwdt_lock_status(void)
{
    return (READ_BIT(WWDT->LOCK, WWDT_LOCK_LOCK_MSK) == WWDT_LOCK_LOCK_MSK);
}

/**
  * @}
  */
/** @addtogroup MD_WWDT_Public_Functions_Group1 Initialization
  * @{
  */
extern void md_wwdt_init(uint32_t load, md_wwdt_win_t win, type_func_t interrupt);
extern void md_wwdt_init_no_reset(uint32_t load, md_wwdt_win_t win, type_func_t interrupt);
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

#endif /* __MD_WWDT_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

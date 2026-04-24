/**********************************************************************************
 *
 * @file    md_msc.h
 * @brief   Header file of MSC module driver.
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

#ifndef __MD_MSC_H__
#define __MD_MSC_H__

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

/* Exported Macros ----------------------------------------------------------- */

/** @defgroup MD_MSC MSC
  * @brief MSC module driver
  * @{
  */
/**
  * @defgroup MD_MSC_Public_Macros MSC Public Macros
  * @{
  */
#define FLASH_REG_UNLOCK()              \
    do {                            \
        WRITE_REG(MSC->FLASHKEY, 0x8ACE0246);   \
        WRITE_REG(MSC->FLASHKEY, 0x9BDF1357);   \
    } while (0)

#define FLASH_REG_LOCK()                \
    do {                            \
        WRITE_REG(MSC->FLASHKEY, 0x0);  \
        WRITE_REG(MSC->FLASHKEY, 0x0);  \
    } while (0)


#define MD_MSC_CODE_WSP_ADDR 0x10000000U
#define MD_MSC_CODE_PE_ADDR  0x10000004U
#define MD_MSC_CODE_WP_ADDR  0x10000008U

#define MD_MSC_DATA_WSP_ADDR 0x10000010U
#define MD_MSC_DATA_PE_ADDR  0x10000014U
#define MD_MSC_DATA_WP_ADDR  0x10000018U
/**
  * @}
  */

/* Exported Types ------------------------------------------------------------ */

/** @defgroup MD_MSC_Private_Types MSC Private Types
  * @{
  */
typedef uint32_t (*MD_MSC_PE)(uint32_t adr, uint32_t adri, uint32_t sect);
typedef uint32_t (*MD_MSC_WP)(uint32_t adr, uint32_t adri, uint32_t data);
typedef uint32_t (*MD_MSC_WSP)(uint32_t adr, uint32_t adri, uint8_t *buf, uint32_t sz, uint32_t epif);

/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup IAP_Public_Functions MSC Public Functions
  * @{
  */
/** @defgroup IAP_Public_Functions_Group1 FLASH Operation Functions
  * @{
  */
/**
  * @brief  Erases a specified page.
  * @param  adr: The beginning address of the page to be erased.
  * @param  adri:Inverse code of adr
  * @param  sect:erase section
  * @retval The result:
  *           - 0: SUCCESS
  *           - 1: MD_ERROR
  */
__STATIC_INLINE__ uint32_t md_msc_code_erase_page(uint32_t adr, uint32_t adri, uint32_t sect)
{
    uint32_t status;

    MD_MSC_PE pe = (MD_MSC_PE)(*(uint32_t *)MD_MSC_CODE_PE_ADDR);
    FLASH_REG_UNLOCK();
    __disable_irq_();
    status = (*pe)(adr, adri, sect);
    __enable_irq_();
    FLASH_REG_LOCK();

    return !status;
}

/**
  * @brief  Programs a word at a specified address.
  * @param  adr: Specifies the address to be programmed.
  *         Bit0-1 must be zero.
  * @param  adri:Inverse code of adr
  * @param  data: Specifies the data to be programmed.
  * @retval The result:
  *           - 0: SUCCESS
  *           - 1: MD_ERROR
  */
__STATIC_INLINE__ uint32_t md_msc_code_program_word(uint32_t adr, uint32_t adri, uint32_t data)
{
    uint32_t status;

    MD_MSC_WP wp = (MD_MSC_WP)(*(uint32_t *)MD_MSC_CODE_WP_ADDR);

    if (adr & 0x3)
        return 1;

    FLASH_REG_UNLOCK();
    __disable_irq_();
    status = (*wp)(adr, adri, data);
    __enable_irq_();
    FLASH_REG_LOCK();

    return !status;
}


/**
  * @brief  Programs datas at a specified address.
  * @param  adr: Specifies the address to be programmed.
  *         Bit0-1 must be zero.
  * @param  adri:Inverse code of adr
  * @param  buf: Specifies the data to be programmed.
  * @param  sz: Specifies the data length to be programmed.
  *         Bit0-1 must be zero.
  * @param  epif: Erase page flag before programming.
  * @retval The result:
  *           - 0: SUCCESS
  *           - 1: MD_ERROR
  */
__STATIC_INLINE__ uint32_t md_msc_code_program_words(uint32_t adr, uint32_t adri, uint8_t *buf, uint32_t sz, uint32_t epif)
{
    uint32_t status;

    MD_MSC_WSP wsp = (MD_MSC_WSP)(*(uint32_t *)MD_MSC_CODE_WSP_ADDR);

    if ((adr & 0x3) || (sz & 0x3))
        return 1;

    FLASH_REG_UNLOCK();
    __disable_irq_();
    status = (*wsp)(adr, adri, buf, sz, epif);
    __enable_irq_();
    FLASH_REG_LOCK();

    return !status;
}

/**
  * @brief  Erases a specified page.
  * @param  adr: The beginning address of the page to be erased.
  * @param  adri:Inverse code of adr
  * @param  sect:erase section
  * @retval The result:
  *           - 0: SUCCESS
  *           - 1: MD_ERROR
  */
__STATIC_INLINE__ uint32_t md_msc_data_erase_page(uint32_t adr, uint32_t adri, uint32_t sect)
{
    uint32_t status;

    MD_MSC_PE pe = (MD_MSC_PE)(*(uint32_t *)MD_MSC_DATA_PE_ADDR);
    FLASH_REG_UNLOCK();
    __disable_irq_();
    status = (*pe)(adr, adri, sect);
    __enable_irq_();
    FLASH_REG_LOCK();

    return !status;
}

/**
  * @brief  Programs a word at a specified address.
  * @param  adr: Specifies the address to be programmed.
  *         Bit0-1 must be zero.
  * @param  adri:Inverse code of adr
  * @param  data: Specifies the data to be programmed.
  * @retval The result:
  *           - 0: SUCCESS
  *           - 1: MD_ERROR
  */
__STATIC_INLINE__ uint32_t md_msc_data_program_word(uint32_t adr, uint32_t adri, uint32_t data)
{
    uint32_t status;

    MD_MSC_WP wp = (MD_MSC_WP)(*(uint32_t *)MD_MSC_DATA_WP_ADDR);

    if (adr & 0x3)
        return 1;

    FLASH_REG_UNLOCK();
    __disable_irq_();
    status = (*wp)(adr, adri, data);
    __enable_irq_();
    FLASH_REG_LOCK();

    return !status;
}


/**
  * @brief  Programs datas at a specified address.
  * @param  adr: Specifies the address to be programmed.
  *         Bit0-1 must be zero.
  * @param  adri:Inverse code of adr
  * @param  buf: Specifies the data to be programmed.
  * @param  sz: Specifies the data length to be programmed.
  *         Bit0-1 must be zero.
  * @param  epif: Erase page flag before programming.
  * @retval The result:
  *           - 0: SUCCESS
  *           - 1: MD_ERROR
  */
__STATIC_INLINE__ uint32_t md_msc_data_program_words(uint32_t adr, uint32_t adri, uint8_t *buf, uint32_t sz, uint32_t epif)
{
    uint32_t status;

    MD_MSC_WSP wsp = (MD_MSC_WSP)(*(uint32_t *)MD_MSC_DATA_WSP_ADDR);

    if ((adr & 0x3) || (sz & 0x3))
        return 1;

    FLASH_REG_UNLOCK();
    __disable_irq_();
    status = (*wsp)(adr, adri, buf, sz, epif);
    __enable_irq_();
    FLASH_REG_LOCK();

    return !status;
}
/**
  * @}
  */
/** @defgroup IAP_Public_Functions_Group2 MSC Control Functions
  * @{
  */
/**
  * @brief  Set flash read wait cycle
  * @param  cycle: Wait cycle, [0-3] sysclock
  * @retval None
  */
__STATIC_INLINE__ void md_msc_set_flash_read_wait_cycle(uint8_t cycle)
{
    uint32_t tmp;

    tmp = MSC->MEMWAIT;
    MODIFY_REG(tmp, MSC_MEMWAIT_FLASH_W_MSK, (0x30U | cycle) << MSC_MEMWAIT_FLASH_W_POSS);
    MSC->MEMWAIT = tmp;
}

/**
  * @brief  Get flash read wait cycle
  * @retval Wait cycle, [0-3] sysclock
  */
__STATIC_INLINE__ uint32_t md_msc_get_flash_read_wait_cycle(void)
{
    return READ_BITS(MSC->MEMWAIT, MSC_MEMWAIT_FLASH_W_MSK, MSC_MEMWAIT_FLASH_W_POSS);
}

/**
  * @brief  Set sram read wait cycle
  * @param  cycle: Wait cycle, [0-3] sysclock
  * @retval None
  */
__STATIC_INLINE__ void md_msc_set_flash_sram_wait_cycle(uint8_t cycle)
{
    MODIFY_REG(MSC->MEMWAIT, MSC_MEMWAIT_SRAM_W_MSK, (cycle | 0x30) << MSC_MEMWAIT_SRAM_W_POSS);
}

/**
  * @brief  Get sram read wait cycle
  * @retval Wait cycle, [0-3] sysclock
  */
__STATIC_INLINE__ uint32_t md_msc_get_sram_read_wait_cycle(void)
{
    return READ_BITS(MSC->MEMWAIT, MSC_MEMWAIT_SRAM_W_MSK, MSC_MEMWAIT_SRAM_W_POSS);
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
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MD_MSC_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

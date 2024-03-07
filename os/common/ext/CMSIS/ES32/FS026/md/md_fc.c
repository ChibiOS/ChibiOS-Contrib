/**********************************************************************************
 *
 * @file    md_fc.c
 * @brief   md_fc C file
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
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

/* Includes -------------------------------------------------------------------*/
#include "md_syscfg.h"
#include "md_fc.h"

/** @addtogroup Micro_Driver
  * @{
  */

#if defined (FC)

/** @defgroup FC FC
  * @brief FC micro driver
  * @{
  */

/* Private types --------------------------------------------------------------*/
/* Private variables ----------------------------------------------------------*/
/* Private macros -------------------------------------------------------------*/

/* Private constants ----------------------------------------------------------*/
/** @defgroup MD_FC_Private_Constants FC Private Constants
  * @{
  */

#define  REMAPDATA_BASE    ((     uint32_t)0x00000000) /*  FLASH Main  (128K Bytes)  */
#define  REMAPINFO_BASE    ((     uint32_t)0x00000000) /*  FLASH Info  (  4K Bytes)  */

/**
  * @} MD_FC_Private_Constants
  */

/* Private function prototypes ------------------------------------------------*/

/* Public functions -----------------------------------------------------------*/
/** @defgroup MD_FC_Public_Functions FC Public Functions
  * @{
  */

/**
  * @brief   FC unlock.
  * @param   None
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: FC unlock done
  *          - ERROR: FC unlock fail
  */
ErrorStatus md_fc_unlock(void)
{
    ErrorStatus status = ERROR;

    /* Unlock EF*/
    if (!md_fc_is_active_flag_flash_unlock(FC))
    {
        md_fc_set_flash_unlock(FC, MD_FC_PC_EF_UL_KEY1);
        md_fc_set_flash_unlock(FC, MD_FC_PC_EF_UL_KEY2);

        if (!md_fc_is_active_flag_flash_unlock(FC))
            return status;
    }

    status = SUCCESS;
    return status;
}

/**
  * @brief   FC lock.
  * @param   None
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: FC lock done
  *          - ERROR: FC lock fail
  */
ErrorStatus md_fc_lock(void)
{
    ErrorStatus status = ERROR;

    /* Unlock EF*/
    if (md_fc_is_active_flag_flash_unlock(FC))
    {
        md_fc_set_flash_unlock(FC, MD_FC_PC_EF_UL_LOCK);

        if (md_fc_is_active_flag_flash_unlock(FC))
            return status;
    }

    status = SUCCESS;
    return status;
}

/**
  * @brief   FC main erase.
  * @note    To prevent unexpected code branch, the main erase function must specify a dedicated main erase ID
  * @param   MEraseID Key for main erase, must be 0xA5A5AA55
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: Main flash erased
  *          - ERROR: Main erase ID mismatch
  */
ErrorStatus md_fc_main_erase(uint32_t MEraseID)
{
    ErrorStatus status = ERROR;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return status;

    /* Check the ID */
    if (MEraseID != MD_FC_PC_EF_MERASEID)
        return status;

    md_fc_set_pa(FC, 0x0);
    /* Write MERASE to CMD*/
    md_fc_set_flash_command(FC, MD_FC_CMD_FULL_ERASE);

    status = SUCCESS;
    return status;
}

/**
  * @brief   FC Sector Erase
  * @note    To prevent unexpected code branch, the page erase function must specify the complement start address
  * @param   pSErasePara Pointer to structure md_fc_ControlTypeDef
  * @retval  An ErrorStatus enumeration value.
  *          - SUCCESS: Specified page address erased
  *          - ERROR: Complement of start address mismatch
  */
ErrorStatus md_fc_sector_erase(md_fc_ControlTypeDef *pSErasePara)
{
    ErrorStatus status = ERROR;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return status;

    /* Check the start address and complement of start address*/
    if (pSErasePara->SAddr & pSErasePara->SAddrC)
        return status;

    /* Write sector address to PA*/
    md_fc_disable_info_region(FC);
    md_fc_set_program_address(FC, pSErasePara->SAddr);
    /* Write SERASE to CMD*/
    md_fc_set_flash_command(FC, MD_FC_CMD_SECTOR_ERASE);

    status = SUCCESS;
    return status;
}

/**
  * @brief   FC Page Erase
  * @note    To prevent unexpected code branch, the page erase function must specify the complement start address
  * @param   pSErasePara Pointer to structure md_fc_ControlTypeDef
  * @retval  An ErrorStatus enumeration value.
  *         - SUCCESS: Specified page address erased
  *         - ERROR: Complement of start address mismatch
  */
ErrorStatus md_fc_page_erase(md_fc_ControlTypeDef *pSErasePara)
{
    ErrorStatus status = ERROR;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return status;

    /* Check the start address and complement of start address*/
    if (pSErasePara->SAddr & pSErasePara->SAddrC)
        return status;

    md_fc_disable_info_region(FC);    
    /* Write sector address to PA*/
    md_fc_set_program_address(FC, pSErasePara->SAddr);
    /* Write SERASE to CMD*/
    md_fc_set_flash_command(FC, MD_FC_CMD_PAGE_ERASE);

    status = SUCCESS;
    return status;
}

/**
  * @brief   FC Info. Page Erase
  * @note    To prevent unexpected code branch, the page erase function must specify the complement start address
  * @param   pSErasePara Pointer to structure md_fc_ControlTypeDef
  * @retval  An ErrorStatus enumeration value.
  *         - SUCCESS: Specified page address erased
  *         - ERROR: Complement of start address mismatch
  */
ErrorStatus md_fc_info_page_erase(md_fc_ControlTypeDef *pSErasePara)
{
    ErrorStatus status = ERROR;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return status;

    /* Check the start address and complement of start address*/
    if (pSErasePara->SAddr & pSErasePara->SAddrC)
        return status;

    md_fc_enable_info_region(FC);
    /* Write sector address to PA*/
    md_fc_set_program_address(FC, pSErasePara->SAddr);
    /* Write SERASE to CMD*/
    md_fc_set_flash_command(FC, MD_FC_CMD_PAGE_ERASE);

    md_fc_disable_info_region(FC);

    status = SUCCESS;
    return status;
}

/**
  * @brief   FC Page Program
  * @note    To prevent unexpected code branch, the page program function must specify the complement start address
  * @param   pProgramPara Pointer to structure md_fc_ControlTypeDef
  * @retval  An ErrorStatus enumeration value.
  *          - SUCCESS: Data in data buffer programed to specified page address
  *          - ERROR: Complement of start address mismatch
  */
ErrorStatus md_fc_program(md_fc_ControlTypeDef *pProgramPara)
{
    ErrorStatus status = ERROR;
    uint16_t  BCnt;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return status;

    md_fc_set_program_counter(FC, pProgramPara->BCnt);
    md_fc_set_program_address(FC, pProgramPara->SAddr);
    BCnt = pProgramPara->BCnt;
    BCnt = (BCnt + 3) >> 2;

    while (BCnt--)
    {
        /* Check the start address and complement of start address*/
        if (pProgramPara->SAddr & pProgramPara->SAddrC)
        {
            return status;
        }

        /* Write lower 32bit program data to PLD*/
        md_fc_set_program_data(FC, *pProgramPara->pU32Buf++);

        /* Write PROGRAM to CMD*/
        md_fc_set_flash_command(FC, MD_FC_CMD_PROG_EFLASH);
    }

    status = SUCCESS;
    return status;
}

/**
  * @brief   FC Info. Page Program
  * @note    To prevent unexpected code branch, the page program function must specify the complement start address
  * @param   pProgramPara Pointer to structure md_fc_ControlTypeDef
  * @retval  An ErrorStatus enumeration value.
  *          - SUCCESS: Data in data buffer programed to specified page address
  *          - ERROR: Complement of start address mismatch
  */
ErrorStatus md_fc_info_program(md_fc_ControlTypeDef *pProgramPara)
{
    ErrorStatus status = ERROR;
    uint16_t  BCnt;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return status;

    md_fc_enable_info_region(FC);
    md_fc_set_program_counter(FC, pProgramPara->BCnt);
    md_fc_set_program_address(FC, pProgramPara->SAddr);
    BCnt = pProgramPara->BCnt;
    BCnt = (BCnt + 3) >> 2;

    while (BCnt--)
    {
        /* Check the start address and complement of start address*/
        if (pProgramPara->SAddr & pProgramPara->SAddrC)
        {
            return status;
        }

        /* Write lower 32bit program data to PLD*/
        md_fc_set_program_data(FC, *pProgramPara->pU32Buf++);

        /* Write PROGRAM to CMD*/
        md_fc_set_flash_command(FC, MD_FC_CMD_PROG_EFLASH);
    }

    md_fc_disable_info_region(FC);

    status = SUCCESS;
    return status;
}

/**
  * @brief   FC Page Read
  * @param   pReadPara Pointer to structure md_fc_ControlTypeDef
  * @retval  Always return SUCCESS
  *          - Data in specified page address read to data buffer
  */
ErrorStatus  md_fc_read(md_fc_ControlTypeDef *pReadPara)
{
    ErrorStatus status = SUCCESS;
    uint32_t   *EFAddr;
    uint16_t  BCnt;

    if (md_syscfg_get_memory_mapping_real(SYSCFG) == MD_SYSCFG_MEMMOD_MAIN)  /*  Reamp from Main  */
        EFAddr = (uint32_t *)(REMAPDATA_BASE + pReadPara->SAddr);
    else
        EFAddr = (uint32_t *)(FLASH_BASE + pReadPara->SAddr);

    BCnt = pReadPara->BCnt;
    BCnt = (BCnt + 3) >> 2;

    while (BCnt--)
        *pReadPara->pU32Buf++ = *EFAddr++;

    return status;
}

/**
  * @brief   FC Update UCRP Protect
  * @param   pUpdateBit Pointer to structure md_fc_UpdProtTypeDdef
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: protect set success
  *          - ERROR: The status is locked
  */
ErrorStatus  md_fc_update_ucrp(md_fc_UpdProtTypeDef *pUpdateBit)
{
    ErrorStatus status = SUCCESS;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return ERROR;

    md_fc_set_protect0(FC, pUpdateBit->UpdateL);
    md_fc_set_protect1(FC, pUpdateBit->UpdateH);
    md_fc_set_flash_command(FC, MD_FC_CMD_UCRP_PROTECT);

    return status;
}

/**
  * @brief   FC Update Read Protect
  * @param   parameter can be one of the following values:
  *         @arg @ref Level0 0xaaaaaaaa
  *         @arg @ref Level1 0xbbbbbbbb
  *         @arg @ref Level2 0xcccccccc
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: protect set success
  *          - ERROR: The status is locked
  */
ErrorStatus  md_fc_update_rp(uint32_t level)
{
    ErrorStatus status = SUCCESS;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return ERROR;

    md_fc_set_protect0(FC, level);
    md_fc_set_flash_command(FC, MD_FC_CMD_RP_PROTECT);

    return status;
}

/**
  * @brief   FC Update Write Protect
  * @param   pUpdateBit Pointer to structure md_fc_UpdProtTypeDdef
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: protect set success
  *          - ERROR: The status is locked
  */
ErrorStatus  md_fc_update_wp(md_fc_UpdProtTypeDef *pUpdateBit)
{
    ErrorStatus status = SUCCESS;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return ERROR;

    md_fc_set_protect0(FC, pUpdateBit->UpdateL);
    md_fc_set_protect1(FC, pUpdateBit->UpdateH);
    md_fc_set_flash_command(FC, MD_FC_CMD_WP_PROTECT);

    return status;
}

/**
  * @brief   FC Clear UCRP Protect
  * @param
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: protect clear success
  *          - ERROR: The status is locked
  */
ErrorStatus  md_fc_clear_ucrp(void)
{
    ErrorStatus status = SUCCESS;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return ERROR;

    /* Write sector address to PA*/
    md_fc_enable_info_region(FC);
    md_fc_set_program_address(FC, MD_FC_PC_EF_IPAGESZ * 0);
    /* Write SERASE to CMD*/
    md_fc_set_flash_command(FC, MD_FC_CMD_PAGE_ERASE);
    md_fc_disable_info_region(FC);

    return status;
}

/**
  * @brief   FC Clear WP Protect
  * @param
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: protect clear success
  *          - ERROR: The status is locked
  */
ErrorStatus  md_fc_clear_wp(void)
{
    ErrorStatus status = SUCCESS;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return ERROR;

    /* Write sector address to PA*/
    md_fc_enable_info_region(FC);
    md_fc_set_program_address(FC, MD_FC_PC_EF_IPAGESZ * 2);
    /* Write SERASE to CMD*/
    md_fc_set_flash_command(FC, MD_FC_CMD_PAGE_ERASE);
    md_fc_disable_info_region(FC);

    return status;
}

/**
  * @brief   FC Clear User Option (Info. Page 2)
  * @param
  * @retval  An ErrorStatus enumeration value:
  *          - SUCCESS: protect clear success
  *          - ERROR: The status is locked
  */
ErrorStatus  md_fc_clear_user_option(void)
{
    ErrorStatus status = SUCCESS;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return ERROR;

    /* Write sector address to PA*/
    md_fc_enable_info_region(FC);
    md_fc_set_program_address(FC, MD_FC_PC_EF_IPAGESZ * 2);
    /* Write SERASE to CMD*/
    md_fc_set_flash_command(FC, MD_FC_CMD_PAGE_ERASE);
    md_fc_disable_info_region(FC);

    return status;
}

/**
  * @brief   FC Reload Option Byte
  * @note    Write fixed value 0xE to trigger the option byte reload.
             After option byte is reloaded, the system reset will be triggered.
  * @param   None
  * @retval  None
  */
ErrorStatus  md_fc_option_byte_reload()
{
    ErrorStatus status = SUCCESS;

    /* Check the status not lock */
    if (!md_fc_is_active_flag_flash_unlock(FC))
        return ERROR;

    md_fc_set_option_byte_reload(FC, MD_FC_OPRLD_0XE);

    return status;
}

/**
  * @brief   FC Read Info. page
  * @param   None
  * @retval  Always return SUCCESS
  *          - Data in specified page address read to data buffer
  */
ErrorStatus  md_fc_read_info(uint32_t info_addr, uint32_t *info)
{
    ErrorStatus status = SUCCESS;
    uint32_t   *EFAddr;

    if (md_fc_is_enabled_flash_prefetch(FC))
    {
        md_fc_disable_flash_prefetch(FC);
        EFAddr = (uint32_t *)(FLASH_INFO_BASE + info_addr);
        *info       = *EFAddr;
        md_fc_enable_flash_prefetch(FC);
    }
    else
    {
        EFAddr = (uint32_t *)(FLASH_INFO_BASE + info_addr);
        *info       = *EFAddr;
    }

    return status;
}

/**
  * @brief   FC read chipid (Address 0x08A0)
  * @param   pReadPara Pointer to structure md_fc_ControlTypeDef
  * @retval  Always return SUCCESS
  *          - Data in specified page address read to data buffer
  */
ErrorStatus  md_fc_read_chipid(uint32_t *CHIPID)
{
    ErrorStatus status = SUCCESS;
    uint32_t   *EFAddr;

    if (md_fc_is_enabled_flash_prefetch(FC))
    {
        md_fc_disable_flash_prefetch(FC);
        EFAddr = (uint32_t *)(FLASH_INFO_BASE + CHIP_ID);
        *CHIPID       = *EFAddr;
        md_fc_enable_flash_prefetch(FC);
    }
    else
    {
        EFAddr = (uint32_t *)(FLASH_INFO_BASE + CHIP_ID);
        *CHIPID       = *EFAddr;
    }

    return status;
}

/**
  * @brief   FC read unique id (Address 0x08A4/0x08A8/0x08AC/0x08B0)
  * @param   pReadPara Pointer to structure md_fc_ControlTypeDef
  * @retval  Always return SUCCESS
  *          - Data in specified page address read to data buffer
  */
ErrorStatus  md_fc_read_uid(uint32_t *UID0, uint32_t *UID1, uint32_t *UID2, uint32_t *UID3)
{
    ErrorStatus status = SUCCESS;
    uint32_t   *EFAddr;

    if (md_fc_is_enabled_flash_prefetch(FC))
    {
        md_fc_disable_flash_prefetch(FC);
        EFAddr = (uint32_t *)(FLASH_INFO_BASE + U_ID);
        *UID0   = *EFAddr++;
        *UID1   = *EFAddr++;
        *UID2   = *EFAddr++;
        *UID3   = *EFAddr;
        md_fc_enable_flash_prefetch(FC);
    }
    else
    {
        EFAddr = (uint32_t *)(FLASH_INFO_BASE + U_ID);
        *UID0   = *EFAddr++;
        *UID1   = *EFAddr++;
        *UID2   = *EFAddr++;
        *UID3   = *EFAddr;
    }

    return status;
}

void md_fc_protect_bit(uint8_t page, uint32_t *UPH, uint32_t *UPL)
{
    if (page < 128)
    {
        *UPL &= (~(1 << (page / 4)));
        *UPH &= 0xFFFFFFFF;
    }
    else
    {
        *UPL &= 0xFFFFFFFF;
        *UPH &= (~(1 << ((page - 128) / 4)));
    }
}

void md_fc_protect_bit_s(uint8_t sector, uint32_t *UPH, uint32_t *UPL)
{
    if (sector < 32)
    {
        *UPL &= (~(1 << sector));
        *UPH &= 0xFFFFFFFF;
    }
    else
    {
        *UPL &= 0xFFFFFFFF;
        *UPH &= (~(1 << (sector - 32)));
    }
}

/**
  * @} MD_FC_Public_Functions
  */

/**
  * @} FC
  */
#endif

/**
  * @} Micro_Driver
  */

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

/**********************************************************************************
 *
 * @file    md_fc.h
 * @brief   header file of md_fc.c
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
#ifndef __MD_FC_H__
#define __MD_FC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup  MD_FC FC
  * @brief FC micro driver
  * @{
  */

/** @defgroup MD_FC_Pubulic_Types FC Pubulic Types
  * @{
  */

/**
  * @brief MD FC Parameter Structure definition
  */
typedef struct
{
    uint32_t SAddr;      /*!< Specifies the FC sector address to be erased.
                This parameter should be aligned with 0x400*/

    uint32_t SAddrC;    /*!< Specifies the complement of FC sector address to be erased.
                This parameter should be the complement of FC page address*/

    uint16_t BCnt;      /*!< Specifies the control byte count.
                For program, this parameter should be aligned with 8 and smaller than 0x400
                For read, this parameter should be aligned with 4*/

    uint32_t *pU32Buf;    /*!< Specifies the uint32_t data buffer to program.
                This parameter should be the pointer to uint32_t*/

} md_fc_ControlTypeDef;

/**
  * @brief MD FC Update Protect Level Structure definition
  */
typedef struct
{
    uint32_t UpdateL;    /*!< Specifies the protect sector bit mapping low byte (sector 31~0) (0=protect, 1=unprotect).
                This parameter can be any value between 0~65535*/

    uint32_t UpdateH;    /*!< Specifies the protect sector bit mapping high byte (sector 63~32) (0=protect, 1=unprotect).
                This parameter can be any value between 0~65535*/

} md_fc_UpdProtTypeDef;

/**
  * @}
  */

/** @defgroup MD_FC_Public_Macros FC Public Macros
  * @{
  */

#define  CHIP_ID    0x08A0
#define  U_ID       0x08A4

#define  Level0 0xaaaaaaaa
#define  Level1 0xbbbbbbbb
#define  Level2 0xcccccccc

#define  MD_FC_PC_EF_MPAGESZ                      (0x00000200UL)    /** @brief Select main page size */
#define  MD_FC_PC_EF_IPAGESZ                      (0x00000200UL)    /** @brief Select information page size */
#define  MD_FC_PC_EF_MERASEID                     (0xA5A5AA55UL)    /** @brief Select main erase ID */

#define  MD_FC_PC_EF_UL_LOCK                      (0x00000000UL)    /** @brief EF Lock Key */
#define  MD_FC_PC_EF_UL_KEY1                      (0x00112233UL)    /** @brief EF Unlock Key1 */
#define  MD_FC_PC_EF_UL_KEY2                      (0x55667788UL)    /** @brief EF Unlock Key2 */

#define  MD_FC_CMD_PROG_EFLASH                    (0xF0)            /** @brief Program EFlash  */
#define  MD_FC_CMD_PAGE_ERASE                     (0xF1)            /** @brief Page Erase  */
#define  MD_FC_CMD_SECTOR_ERASE                   (0xF2)            /** @brief Sector Erase  */
#define  MD_FC_CMD_FULL_ERASE                     (0xF3)            /** @brief Full Erase  */
#define  MD_FC_CMD_UCRP_PROTECT                   (0xF5)            /** @brief UCRP Protect  */
#define  MD_FC_CMD_RP_PROTECT                     (0xF6)            /** @brief RP Protect  */
#define  MD_FC_CMD_WP_PROTECT                     (0xF7)            /** @brief WP Protect  */

#define  MD_FC_PC_SREMAP_MAIN                     (0x00)            /** @brief Main Flash memory mapped at 0x0000 0000  */
#define  MD_FC_PC_SREMAP_BOOTROM                  (0x01)            /** @brief Bootrom mapped at 0x0000 0000  */
#define  MD_FC_PC_SREMAP_SRAM                     (0x02)            /** @brief SRAM mapped at 0x0000 0000  */

#define  MD_FC_OPRLD_0XE                          (0xE )            /** @brief Fill in the fixed value 0xE to trigger configuration word reload  */

#define  MD_FC_WAIT_LESS_THAN_24MHz               (0x0 )            /** @brief System frequency<24Mhz.  */
#define  MD_FC_WAIT_BETWEEN_24MHz_AND_48Mhz       (0x1 )            /** @brief System frequency>24Mhz and system frequency<=48Mhz.  */
#define  MD_FC_WAIT_BETWEEN_48MHz_AND_72Mhz       (0x2 )            /** @brief System frequency>48Mhz and system frequency<=72Mhz.  */
#define  MD_FC_WAIT_MORE_THAN_72Mhz               (0x3 )            /** @brief System frequency>72Mhz.  */

/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions FC Public Functions
  * @{
  */

/** @defgroup MD_FC_Public_Functions_Group2 CMD
  * @{
  */
/**
  * @brief  Set FC CMD Flash Command
  * @param  fc FC Instance
  * @param  cmd Flash command
            @arg @ref MD_FC_CMD_PROG_EFLASH(0xF0) : Program EFlash
            @arg @ref MD_FC_CMD_PAGE_ERASE(0xF1) : Page Erase
            @arg @ref MD_FC_CMD_SECTOR_ERASE(0xF2) : Sector Erase
            @arg @ref MD_FC_CMD_FULL_ERASE(0xF3) : Full Erase
            @arg @ref MD_FC_CMD_UCRP_PROTECT(0xF5) : UCRP Protect
            @arg @ref MD_FC_CMD_RP_PROTECT(0xF6) : RP Protect
            @arg @ref MD_FC_CMD_WP_PROTECTE(0xF7) : WP Protect
  * @retval None
  */
__STATIC_INLINE void md_fc_set_flash_command(FC_TypeDef *fc, uint32_t Cmd)
{
    MODIFY_REG(fc->CMD, FC_CMD_CMD, Cmd);
}

/**
  * @brief  Get FC CMD Flash Command
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_FC_CMD_PROG_EFLASH(0xF0) : Program EFlash
  *         @arg @ref MD_FC_CMD_PAGE_ERASE(0xF1) : Page Erase
  *         @arg @ref MD_FC_CMD_SECTOR_ERASE(0xF2) : Sector Erase
  *         @arg @ref MD_FC_CMD_FULL_ERASE(0xF3) : Full Erase
  *         @arg @ref MD_FC_CMD_UCRP_PROTECT(0xF5) : UCRP Protect
  *         @arg @ref MD_FC_CMD_RP_PROTECT(0xF6) : RP Protect
  *         @arg @ref MD_FC_CMD_WP_PROTECTE(0xF7) : WP Protect
  */
__STATIC_INLINE uint32_t md_fc_get_flash_command(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->CMD, FC_CMD_CMD));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group3 PA
  * @{
  */
/**
  * @brief  Set FC PA
  * @param  fc FC Instance
  * @param  pa Flash programming address
  * @retval None
  */
__STATIC_INLINE void md_fc_set_pa(FC_TypeDef *fc, uint32_t pa)
{
    WRITE_REG(fc->PA, pa);
}

/**
  * @brief  Get FC PA
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_fc_get_pa(FC_TypeDef *fc)
{
    return (uint32_t)(READ_REG(fc->PA));
}

/**
  * @brief  Set FC Program Counter
  * @note   Provide maximum 128 times continuous program without modify progeam address
  * @param  fc FC Instance
  * @param  pcnt Programming byte,pcnt > 0
  * @retval None
  */
__STATIC_INLINE void md_fc_set_program_counter(FC_TypeDef *fc, uint32_t pcnt)
{
    MODIFY_REG(fc->PA, FC_PA_PCNT, ((((pcnt + 3) >> 2) - 1) << FC_PA_PCNT_POSS));
}

/**
  * @brief  Get FC Program Counter
  * @note  Provide maximum 128 times continuous program
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x7f
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_program_counter(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->PA, FC_PA_PCNT) >> FC_PA_PCNT_POSS);
}

/**
  * @brief  Enable FC Information Block
  * @note  User can program/erase Info. Block page 7 when Flash protect is disable
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE void md_fc_enable_info_region(FC_TypeDef *fc)
{
    SET_BIT(fc->PA, FC_PA_IFREN);
}

/**
  * @brief  Disable FC Information Block
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE void md_fc_disable_info_region(FC_TypeDef *fc)
{
    CLEAR_BIT(fc->PA, FC_PA_IFREN);
}

/**
  * @brief  Is FC Information Block Enabled
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Enable
  *         @arg 0x0 : Disable
  */
__STATIC_INLINE uint32_t md_fc_is_enabled_info_region(FC_TypeDef *fc)
{
    return (READ_BIT(fc->PA, FC_PA_IFREN) == (FC_PA_IFREN));
}

/**
  * @brief  Set FC Program/Erase Address
  * @note  Program      : PROG_ADDR[12: 2] is word addressaddress
  * @note  Page Erase   : PROG_ADDR[16: 9] is page address, and PROG_ADDR[8:0] don't care
  * @note  Sector Erase : PROG_ADDR[16:11] is sector address, and PROG_ADDR[10:0] don't care
  * @note  Macro Erase  : PROG_ADDR[16: 0] don't care
  * @param  fc FC Instance
  * @param  PAddr Program/erase address
  * @retval None
  */
__STATIC_INLINE void md_fc_set_program_address(FC_TypeDef *fc, uint32_t PAddr)
{
    MODIFY_REG(fc->PA, FC_PA_PA, PAddr);
}

/**
  * @brief  Get FC Program/Erase Address
  * @note  Program      : PROG_ADDR[12: 2] is word addressaddress
  * @note  Page Erase   : PROG_ADDR[16: 9] is page address, and PROG_ADDR[8:0] don't care
  * @note  Sector Erase : PROG_ADDR[16:11] is sector address, and PROG_ADDR[10:0] don't care
  * @note  Macro Erase  : PROG_ADDR[16: 0] don't care
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_fc_get_program_address(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->PA, FC_PA_PA));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group4 PLD
  * @{
  */
/**
  * @brief  Set FC Program Low Data
  * @note  Eflash supports 32 bits data program, this register provides Low 32 bits data
  * @param  fc FC Instance
  * @param  pld Flash programming data lower 32 bits
  * @retval None
  */
__STATIC_INLINE void md_fc_set_program_data(FC_TypeDef *fc, uint32_t pld)
{
    MODIFY_REG(fc->PLD, FC_PLD_PLD, pld);
}

/**
  * @brief  Get FC Program Low Data
  * @note  Eflash supports 32 bits data program, this register provides Low 32 bits data
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_program_data(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->PLD, FC_PLD_PLD));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group5 CTL
  * @{
  */
/**
  * @brief  Set FC CON
  * @param  fc FC Instance
  * @param  ctl Flash control register
  * @retval None
  */
__STATIC_INLINE void md_fc_set_ctl(FC_TypeDef *fc, uint32_t ctl)
{
    WRITE_REG(fc->CTL, ctl);
}

/**
  * @brief  Get FC CON
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_fc_get_ctl(FC_TypeDef *fc)
{
    return (uint32_t)(READ_REG(fc->CTL));
}

/**
  * @brief  Enable FC Control Sleep
  * @note   When receive sleep or deep sleep from CPU, controller will mask Eflash control signal when this option is selected.
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE void md_fc_enable_flash_stop_mode(FC_TypeDef *fc)
{
    SET_BIT(fc->CTL, FC_CTL_FCSLEEP);
}

/**
  * @brief  Disable FC Control Sleep
  * @note   When receive sleep or deep sleep from CPU, controller will mask Eflash control signal when this option is selected.
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE void md_fc_disable_flash_stop_mode(FC_TypeDef *fc)
{
    CLEAR_BIT(fc->CTL, FC_CTL_FCSLEEP);
}

/**
  * @brief  Is FC Control Sleep Enabled
  * @note  When receive sleep or deep sleep from CPU, controller will mask Eflash control signal when this option is selected.
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         0x0:Disable Flash sleep mask function
  *         0x1:Enable Flash sleep mask function
  */
__STATIC_INLINE uint8_t md_fc_is_enabled_flash_stop_mode(FC_TypeDef *fc)
{
    return (READ_BIT(fc->CTL, FC_CTL_FCSLEEP) == (FC_CTL_FCSLEEP));
}

/**
  * @brief  Enable FC Control PreFetch
  * @note  This function allow user to pre-fetch 64 bits data from Eflash when the last 32bits data in data buffer has been read
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE void md_fc_enable_flash_prefetch(FC_TypeDef *fc)
{
    SET_BIT(fc->CTL, FC_CTL_PFEN);
}

/**
  * @brief  Disable FC Control PreFetch
  * @note  This function allow user to pre-fetch 64 bits data from Eflash when the last 32bits data in data buffer has been read
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE void md_fc_disable_flash_prefetch(FC_TypeDef *fc)
{
    CLEAR_BIT(fc->CTL, FC_CTL_PFEN);
}

/**
  * @brief  Is FC Control PreFetch Enabled
  * @note   This function allow user to pre-fetch 64 bits data from Eflash when the last 32bits data in data buffer has been read
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         0x0:Disable pre-fetch function
  *         0x1:Enable pre-fetch function
  */
__STATIC_INLINE uint8_t md_fc_is_enabled_flash_prefetch(FC_TypeDef *fc)
{
    return (READ_BIT(fc->CTL, FC_CTL_PFEN) == (FC_CTL_PFEN));
}

/**
  * @brief  Set FC Control Configuration word load key
  * @note   Fill in the fixed value 0xE to trigger the configuration word reload
  * @param  fc FC Instance
  * @param  oprld Configuration word load key
  *         @arg @ref  MD_FC_OPRLD_0XE
  * @retval None
  */
__STATIC_INLINE void md_fc_set_option_byte_reload(FC_TypeDef *fc, uint32_t oprld)
{
    MODIFY_REG(fc->CTL, FC_CTL_OPRLD, oprld << FC_CTL_OPRLD_POSS);
}

/**
  * @brief  Set FC Control Wait Cycle
  * @param  fc FC Instance
  * @param  Wait Flash read wait cycle
            @arg @ref MD_FC_WAIT_LESS_THAN_24MHz
            @arg @ref MD_FC_WAIT_BETWEEN_24MHz_AND_48Mhz
            @arg @ref MD_FC_WAIT_BETWEEN_48MHz_AND_72Mhz
            @arg @ref MD_FC_WAIT_MORE_THAN_72Mhz
  * @retval None
  */
__STATIC_INLINE void md_fc_set_read_latency(FC_TypeDef *fc, uint32_t Wait)
{
    MODIFY_REG(fc->CTL, FC_CTL_WAIT, Wait << FC_CTL_WAIT_POSS);
}

/**
  * @brief  Get FC Control Wait Cycle
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_FC_WAIT_LESS_THAN_24MHz
            @arg @ref MD_FC_WAIT_BETWEEN_24MHz_AND_48Mhz
            @arg @ref MD_FC_WAIT_BETWEEN_48MHz_AND_72Mhz
            @arg @ref MD_FC_WAIT_MORE_THAN_72Mhz
  */
__STATIC_INLINE uint32_t md_fc_get_read_latency(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->CTL, FC_CTL_WAIT) >> FC_CTL_WAIT_POSS);
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group6 STAT
  * @{
  */
/**
  * @brief  Get FC STAT
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_sta(FC_TypeDef *fc)
{
    return (uint32_t)(READ_REG(fc->STAT));
}

/**
  * @brief  Get FC Option Byte reload times
  * @note   This bit is set when Option Byte Data is valid
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xF
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_option_byte_reload_times(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->STAT, FC_STA_OPRLDLOOP) >> FC_STA_OPRLDLOOP_POSS);
}

/**
  * @brief  Set Protection area read status
  * @param  fc FC Instance
  * @retval none
  */
__STATIC_INLINE void md_fc_clear_flag_protect_area_read(FC_TypeDef *fc)
{
    SET_BIT(fc->STAT, FC_STA_PRTAREARD);
}

/**
  * @brief  Get Protection area read status
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Value 0x1 : An illegal action occurred in the program area to read the data in the protected area
  *         @arg Value 0x0 : The protected area has not been read
  */
__STATIC_INLINE uint32_t md_fc_is_active_flag_protect_area_read(FC_TypeDef *fc)
{
    return (READ_BIT(fc->STAT, FC_STA_PRTAREARD) == (FC_STA_PRTAREARD));
}

/**
  * @brief  Set Protected area operating status
  * @param  fc FC Instance
  * @retval none
  */
__STATIC_INLINE void md_fc_clear_flag_protect_area_write(FC_TypeDef *fc)
{
    SET_BIT(fc->STAT, FC_STA_PRTAREAWR);
}

/**
  * @brief  Get FC Protected area operating status
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Value 0x1 : An illegal action in the operation protection zone of the program area has occurred
  *         @arg Value 0x0 : The protected area has not been operated by Program/Erase
  */
__STATIC_INLINE uint32_t md_fc_is_active_flag_protect_area_write(FC_TypeDef *fc)
{
    return (READ_BIT(fc->STAT, FC_STA_PRTAREAWR) == (FC_STA_PRTAREAWR));
}

/**
  * @brief  Get FC_CMD register protection status
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Value 0x1 : FC_CMD register is unlocked
  *         @arg Value 0x0 : FC_CMD register lock
  */
__STATIC_INLINE uint32_t md_fc_is_active_flag_flash_unlock(FC_TypeDef *fc)
{
    return (READ_BIT(fc->STAT, FC_STA_CMDULK) == (FC_STA_CMDULK));
}

/**
  * @brief  Get Flash Controller Busy Status
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Value 0x1 : Flash controller busy
  *         @arg Value 0x0 : Flash controller idle
  */
__STATIC_INLINE uint32_t md_fc_is_active_flag_flash_busy(FC_TypeDef *fc)
{
    return (READ_BIT(fc->STAT, FC_STA_FCBUSY) == (FC_STA_FCBUSY));
}

/**
  * @brief  Get Program area write protection (WP) protection status
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Value 0x1 : Protection function is not turned on
  *         @arg Value 0x0 : Protection function is on
  */
__STATIC_INLINE uint32_t md_fc_is_active_flag_wp_disable(FC_TypeDef *fc)
{
    return (READ_BIT(fc->STAT, FC_STA_WPDIS) == (FC_STA_WPDIS));
}

/**
  * @brief  Get Program area read protection (RP) protection status
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Value 0x2 : Read protection level is Lv2
  *         @arg Value 0x1 : Read protection level is Lv1
  *         @arg Value 0x0 : Read protection level is Lv0
  */
__STATIC_INLINE uint32_t md_fc_get_rp_level(FC_TypeDef *fc)
{
    return (READ_BIT(fc->STAT, FC_STA_RPLV) >> FC_STA_RPLV_POSS);
}

/**
  * @brief  Get Program area user code readout protection (UCRP) protection status
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Value 0x1 : Protection function is not turned on
  *         @arg Value 0x0 : Protection function is on
  */
__STATIC_INLINE uint32_t md_fc_is_active_flag_ucrp_disable(FC_TypeDef *fc)
{
    return (READ_BIT(fc->STAT, FC_STA_UCRPDIS) == (FC_STA_UCRPDIS));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group7 UPL
  * @{
  */
/**
  * @brief  Set FC Protect Update Low Data
  * @note   Update main block Protect setting 0
  * @param  fc FC Instance
  * @param  upl Update protection setting low 32 bits
  * @retval None
  */
__STATIC_INLINE void md_fc_set_protect0(FC_TypeDef *fc, uint32_t upl)
{
    MODIFY_REG(fc->UPL, FC_UPL_UPL, upl);
}

/**
  * @brief  Get FC Protect Update Low Data
  * @note   Update main block Protect setting 0
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_fc_get_protect0(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->UPL, FC_UPL_UPL));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group8 UPH
  * @{
  */
/**
  * @brief  Set FC Protect Update High Data
  * @note   Update main block Protect setting 1
  * @param  fc FC Instance
  * @param  uph Update protection setting High 32 bits
  * @retval None
  */
__STATIC_INLINE void md_fc_set_protect1(FC_TypeDef *fc, uint32_t uph)
{
    MODIFY_REG(fc->UPH, FC_UPH_UPH, uph);
}

/**
  * @brief  Get FC Protect Update High Data
  * @note   Update main block Protect setting 1
  * @param  fc FC Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_fc_get_protect1(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->UPH, FC_UPH_UPH));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group9 UL
  * @{
  */
/**
  * @brief  Set FC Flash control unlock key
  * @note   0x00112233 / 0x55667788
  * @param  fc FC Instance
  * @param  ul Flash control unlock key
            @arg @ref MD_FC_PC_EF_UL_LOCK
            @arg @ref MD_FC_PC_EF_UL_KEY1
            @arg @ref MD_FC_PC_EF_UL_KEY2
  * @retval None
  */
__STATIC_INLINE void md_fc_set_flash_unlock(FC_TypeDef *fc, uint32_t ul)
{
    MODIFY_REG(fc->UL, FC_UL_UL, ul);
}

/**
  * @brief  Get FC Flash control unlock key
  * @note   0x00112233 / 0x55667788
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_FC_PC_EF_UL_LOCK
            @arg @ref MD_FC_PC_EF_UL_KEY1
            @arg @ref MD_FC_PC_EF_UL_KEY2
  */
__STATIC_INLINE uint32_t md_fc_get_flash_unlock(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->UL, FC_UL_UL));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group10 UCRPL
  * @{
  */
/**
  * @brief  Get Flash configuration word user code read protection setting low 32 bits
  * @note  Program area Sector 31 ~ Sector 0 user code readout protection settings
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_ucrp0(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->UCRPL, FC_UCRPL_UCRPL));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group11 UCRPH
  * @{
  */
/**
  * @brief  Get Flash configuration word user code read protection setting high 32 bits
  * @note  Program area Sector 63 ~ Sector 32 user code readout protection settings
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_ucrp1(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->UCRPH, FC_UCRPH_UCRPH));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group12 RP
  * @{
  */
/**
  * @brief  Get Flash configuration word read protection setting
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg 0xAAAAAAAA: Lv0
  *         @arg 0xCCCCCCCC: Lv2
  *         @arg else: Lv1
  */
__STATIC_INLINE uint32_t md_fc_get_rp(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->RP, FC_RP_RP));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group13 WPL
  * @{
  */
/**
  * @brief  Get Flash memory configuration word write protection setting low 32 bits
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_wp0(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->WPL, FC_WPL_WPL));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group14 WPH
  * @{
  */
/**
  * @brief  Get Flash memory configuration word write protection setting high 32 bits
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_wp1(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->WPH, FC_WPH_WPH));
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group15 REMAP
  * @{
  */
/**
  * @brief  Get FC REMAP
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xffffffff
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint32_t md_fc_get_remap(FC_TypeDef *fc)
{
    return (uint32_t)(READ_REG(fc->REMAP));
}

/**
  * @brief  Get FC Hardware Remap Option
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xff
  *         @arg Min Value 0x0
  *         @arg Value 0xa5 skip bootroom
  */
__STATIC_INLINE uint8_t md_fc_get_option_bootrom_bypass(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->REMAP, FC_REMAP_BOOTBYP) >> FC_REMAP_BOOTBYP_POSS);
}

/**
  * @brief  Get FC Software Remap Option
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_FC_PC_SREMAP_MAIN(0x0)    : Main Flash memory mapped at 0x0000 0000
  *         @arg @ref MD_FC_PC_SREMAP_BOOTROM(0x1) : Bootrom mapped at 0x0000 0000
  *         @arg @ref MD_FC_PC_SREMAP_SRAM(0x2)    : SRAM mapped at 0x0000 0000
  *         @arg Else : Reserved
  */
__STATIC_INLINE uint8_t md_fc_get_option_memory_mapping(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->REMAP, FC_REMAP_SELECT) >> FC_REMAP_SELECT_POSS);
}

/**
  * @brief  Get FC Software Remap Base Address Settng Data
  * @note  If set 0x1, it means second 4k Byte, If set 0x2, it means third 4k Byte, and so on
  * @note  This value is invalid if the value in SREMAP field is 0x3
  * @param  fc FC Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0x1f
  *         @arg Min Value 0x0
  */
__STATIC_INLINE uint8_t md_fc_get_option_flash_remap_base(FC_TypeDef *fc)
{
    return (uint32_t)(READ_BIT(fc->REMAP, FC_REMAP_SEFBASE) >> FC_REMAP_SEFBASE_POSS);
}
/**
  * @}
  */

/** @defgroup MD_FC_Public_Functions_Group1 Initialization
  * @{
  */
ErrorStatus  md_fc_unlock(void);
ErrorStatus  md_fc_lock(void);
ErrorStatus  md_fc_main_erase(uint32_t MEraseID);
ErrorStatus  md_fc_sector_erase(md_fc_ControlTypeDef *pSErasePara);
ErrorStatus  md_fc_page_erase(md_fc_ControlTypeDef *pSErasePara);
ErrorStatus  md_fc_info_page_erase(md_fc_ControlTypeDef *pSErasePara);
ErrorStatus  md_fc_program(md_fc_ControlTypeDef *pProgramPara);
ErrorStatus  md_fc_info_program(md_fc_ControlTypeDef *pProgramPara);
ErrorStatus  md_fc_read(md_fc_ControlTypeDef *pReadPara);
ErrorStatus  md_fc_update_ucrp(md_fc_UpdProtTypeDef *pUpdateBit);
ErrorStatus  md_fc_update_rp(uint32_t);
ErrorStatus  md_fc_update_wp(md_fc_UpdProtTypeDef *pUpdateBit);
ErrorStatus  md_fc_clear_ucrp(void);
ErrorStatus  md_fc_clear_wp(void);
ErrorStatus  md_fc_clear_user_option(void);
ErrorStatus  md_fc_option_byte_reload(void);
ErrorStatus  md_fc_read_info(uint32_t info_addr, uint32_t *info);
ErrorStatus  md_fc_read_chipid(uint32_t *);
ErrorStatus  md_fc_read_uid(uint32_t *, uint32_t *, uint32_t *, uint32_t *);
void md_fc_protect_bit(uint8_t, uint32_t *, uint32_t *);
void md_fc_protect_bit_s(uint8_t, uint32_t *, uint32_t *);
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


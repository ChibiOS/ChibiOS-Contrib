/**********************************************************************************
 *
 * @file    md_syscfg.h
 * @brief   header file of md_syscfg.c
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MD_SYSCFG_H__
#define __MD_SYSCFG_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes -------------------------------------------------------------------*/
#include <stdbool.h>
#include "fs026.h"

/** @addtogroup Micro_Driver
  * @{
  */

/** @defgroup MD_SYSCFG SYSCFG
  * @brief SYSCFG micro driver
  * @{
  */

/** @defgroup MD_SYSCFG_Public_Macros SYSCFG Public Macros
  * @{
  */

/**
  * @brief Memory mapping Status
  */
#define MD_SYSCFG_REALMOD_MAIN            (0x00000000UL)  /** @brief Main Flash memory mapped at 0x00000000 */
#define MD_SYSCFG_REALMOD_BOOTROM         (0x00000001UL)  /** @brief Bootrom mapped at 0x00000000 */
#define MD_SYSCFG_REALMOD_SRAM            (0x00000002UL)  /** @brief SRAM mapped at 0x00000000 */

/**
  * @brief MD_SYSCFG_REMAP_MEMMOD_FLAG Memory mapping selection bits
  */
#define MD_SYSCFG_MEMMOD_MAIN             (0x00000000UL)  /** @brief Main Flash memory mapped at 0x00000000 */
#define MD_SYSCFG_MEMMOD_BOOTROM          (0x00000001UL)  /** @brief Bootrom mapped at 0x00000000 */
#define MD_SYSCFG_MEMMOD_SRAM             (0x00000002UL)  /** @brief SRAM mapped at 0x00000000 */

/**
  * @brief MD_SYSCFG_PWR_RESSRC VRES voltage divider power supply selection
  */
#define MD_SYSCFG_PWR_VREFINT           (0x00000000UL)  /** @brief The voltage divider power supply selects VBG. */
#define MD_SYSCFG_PWR_VDDA              (0x00000001UL)  /** @brief The voltage divider power supply selects VDDA. */

/**
  * @brief MD_SYSCFG_IRSEL_PLR_FLAG IR Polarity
  */
#define MD_SYSCFG_PLR_INV_SEL1_AND_SEL2     (0x00000000UL)  /** @brief IR out = ~(SEL1 & SEL2) */
#define MD_SYSCFG_PLR_SEL1_AND_SEL2         (0x00000001UL)  /** @brief IR out = SEL1 & SEL2 */

/**
  * @brief MD_SYSCFG_IRSEL_SEL2 IR Select 2
  */
#define MD_SYSCFG_SEL2_OFF                (0x00000000UL)  /** @brief 0000: OFF */
#define MD_SYSCFG_SEL2_GP16C2T4_CH1       (0x00000001UL)  /** @brief 0001: GP16C2T4_CH1 */
#define MD_SYSCFG_SEL2_GP16C2T4_CH2       (0x00000002UL)  /** @brief 0010: GP16C2T4_CH2 */
#define MD_SYSCFG_SEL2_UART2_TX           (0x00000004UL)  /** @brief 0100: UART2_TX */
#define MD_SYSCFG_SEL2_UART4_TX           (0x00000008UL)  /** @brief 1000: UART4_TX */

/**
  * @brief MD_SYSCFG_IRSEL_SEL1 IR Select 1
  */
#define MD_SYSCFG_SEL1_OFF                (0x00000000UL)  /** @brief 0000: OFF */
#define MD_SYSCFG_SEL1_GP16C2T2_CH1       (0x00000001UL)  /** @brief 0001: GP16C2T2_CH1 */
#define MD_SYSCFG_SEL1_GP16C2T2_CH2       (0x00000002UL)  /** @brief 0010: GP16C2T2_CH2 */
#define MD_SYSCFG_SEL1_GP16C2T3_CH1       (0x00000004UL)  /** @brief 0100: GP16C2T3_CH1 */
#define MD_SYSCFG_SEL1_GP16C2T3_CH2       (0x00000008UL)  /** @brief 1000: GP16C2T3_CH2 */

/**
  * @brief MD_SYSCFG_MEMMOD_SMOD
  */
#define MD_SYSCFG_SMOD_32KB           (0x0000001FUL) /** @brief 0x1F: 32KB */
#define MD_SYSCFG_SMOD_16KB           (0x0000000FUL) /** @brief 0x0F: 16KB */
#define MD_SYSCFG_SMOD_8KB            (0x00000007UL) /** @brief 0x07: 8KB  */
#define MD_SYSCFG_SMOD_4KB            (0x00000003UL) /** @brief 0x03: 4KB  */
#define MD_SYSCFG_SMOD_2KB            (0x00000001UL) /** @brief 0x01: 2KB  */

/**
  * @brief MD_SYSCFG_MEMMOD_FMOD
  */
#define MD_SYSCFG_FMOD_256KB          (0x000000FFUL) /** @brief 0xFF: 256KB */
#define MD_SYSCFG_FMOD_128KB          (0x0000007FUL) /** @brief 0x7F: 128KB */
#define MD_SYSCFG_FMOD_64KB           (0x0000003FUL) /** @brief 0x3F: 64KB  */
#define MD_SYSCFG_FMOD_32KB           (0x0000001FUL) /** @brief 0x1F: 32KB  */
#define MD_SYSCFG_FMOD_16KB           (0x0000000FUL) /** @brief 0x0F: 16KB  */

/**
  * @brief MD_SYSCFG_PWRCON_BORLS These bits are written by software to select the Low voltage reset voltage
  */
#define MD_SYSCFG_SYS_BORLS_LV0           (0x00000000UL)  /** @brief 0000: 2.0V */
#define MD_SYSCFG_SYS_BORLS_LV1           (0x00000001UL)  /** @brief 0001: 2.3V */
#define MD_SYSCFG_SYS_BORLS_LV2           (0x00000002UL)  /** @brief 0010: 2.6V */
#define MD_SYSCFG_SYS_BORLS_LV3           (0x00000003UL)  /** @brief 0011: 2.9V */
#define MD_SYSCFG_SYS_BORLS_LV4           (0x00000004UL)  /** @brief 0100: 3.2V */
#define MD_SYSCFG_SYS_BORLS_LV5           (0x00000005UL)  /** @brief 0101: 3.5V */
#define MD_SYSCFG_SYS_BORLS_LV6           (0x00000006UL)  /** @brief 0110: 3.8V */
#define MD_SYSCFG_SYS_BORLS_LV7           (0x00000007UL)  /** @brief 0111: 4.1V */

/**
  * @brief MD_SYSCFG_CFG_DBGHEN DBG Halt enable bit
  */
#define MD_SYSCFG_DBGHEN_IWDT               (0x00002000UL)  /** @brief 1<<13: IWDT     */
#define MD_SYSCFG_DBGHEN_WWDT               (0x00001000UL)  /** @brief 1<<12: WWDT     */
#define MD_SYSCFG_DBGHEN_I2C2               (0x00000800UL)  /** @brief 1<<11: I2C2     */
#define MD_SYSCFG_DBGHEN_I2C1               (0x00000400UL)  /** @brief 1<<10: I2C1     */
#define MD_SYSCFG_DBGHEN_BS16T1             (0x00000200UL)  /** @brief 1<<9 : BS16T1   */
#define MD_SYSCFG_DBGHEN_GP16C4T3           (0x00000100UL)  /** @brief 1<<8 : GP16C4T3 */
#define MD_SYSCFG_DBGHEN_GP16C4T2           (0x00000080UL)  /** @brief 1<<7 : GP16C4T2 */
#define MD_SYSCFG_DBGHEN_GP16C4T1           (0x00000040UL)  /** @brief 1<<6 : GP16C4T1 */
#define MD_SYSCFG_DBGHEN_GP32C4T1           (0x00000020UL)  /** @brief 1<<5 : GP32C4T1 */
#define MD_SYSCFG_DBGHEN_GP16C2T4           (0x00000010UL)  /** @brief 1<<4 : GP16C2T4 */
#define MD_SYSCFG_DBGHEN_GP16C2T3           (0x00000008UL)  /** @brief 1<<3 : GP16C2T3 */
#define MD_SYSCFG_DBGHEN_GP16C2T2           (0x00000004UL)  /** @brief 1<<2 : GP16C2T2 */
#define MD_SYSCFG_DBGHEN_GP16C2T1           (0x00000002UL)  /** @brief 1<<1 : GP16C2T1 */
#define MD_SYSCFG_DBGHEN_AD16C4T1           (0x00000001UL)  /** @brief 1<<0 : AD16C4T1 */

/**
  * @brief MD_SYSCFG_PWRCON_BORLS These bits are written by software to select the Low voltage reset voltage
  */
#define MD_SYSCFG_BORLS_LV0               (0x00000000UL)  /** @brief 0000: 2.0V */
#define MD_SYSCFG_BORLS_LV1               (0x00000001UL)  /** @brief 0001: 2.3V */
#define MD_SYSCFG_BORLS_LV2               (0x00000002UL)  /** @brief 0010: 2.6V */
#define MD_SYSCFG_BORLS_LV3               (0x00000003UL)  /** @brief 0011: 2.9V */
#define MD_SYSCFG_BORLS_LV4               (0x00000004UL)  /** @brief 0100: 3.2V */
#define MD_SYSCFG_BORLS_LV5               (0x00000005UL)  /** @brief 0101: 3.5V */
#define MD_SYSCFG_BORLS_LV6               (0x00000006UL)  /** @brief 0110: 3.8V */
#define MD_SYSCFG_BORLS_LV7               (0x00000007UL)  /** @brief 0111: 4.1V */

/**
  * @brief MD_SYSCFG_PWRCON_LVDLS These bits are Low voltage detection voltage range selection
  */
#define MD_SYSCFG_LVDLS_R1V9_F2V            (0x00000000UL)  /** @brief 0000: R-1.9V, F-2.0V */
#define MD_SYSCFG_LVDLS_R2V1_F2V2           (0x00000001UL)  /** @brief 0001: R-2.1V, F-2.2V */
#define MD_SYSCFG_LVDLS_R2V3_F2V4           (0x00000002UL)  /** @brief 0010: R-2.3V, F-2.4V */
#define MD_SYSCFG_LVDLS_R2V5_F2V6           (0x00000003UL)  /** @brief 0011: R-2.5V, F-2.6V */
#define MD_SYSCFG_LVDLS_R2V7_F2V8           (0x00000004UL)  /** @brief 0100: R-2.7V, F-2.8V */
#define MD_SYSCFG_LVDLS_R2V9_F3V            (0x00000005UL)  /** @brief 0101: R-2.9V, F-3.0V */
#define MD_SYSCFG_LVDLS_R3V1_F3V2           (0x00000006UL)  /** @brief 0110: R-3.1V, F-3.2V */
#define MD_SYSCFG_LVDLS_R3V3_F3V4           (0x00000007UL)  /** @brief 0111: R-3.3V, F-3.4V */
#define MD_SYSCFG_LVDLS_R3V5_F3V6           (0x00000008UL)  /** @brief 1000: R-3.5V, F-3.6V */
#define MD_SYSCFG_LVDLS_R3V7_F3V8           (0x00000009UL)  /** @brief 1001: R-3.7V, F-3.8V */
#define MD_SYSCFG_LVDLS_R3V9_F4V            (0x0000000AUL)  /** @brief 1010: R-3.9V, F-4.0V */
#define MD_SYSCFG_LVDLS_R4V1_F4V2           (0x0000000BUL)  /** @brief 1011: R-4.1V, F-4.2V */
#define MD_SYSCFG_LVDLS_R4V3_F4V4           (0x0000000CUL)  /** @brief 1100: R-4.3V, F-4.4V */
#define MD_SYSCFG_LVDLS_R4V5_F4V6           (0x0000000DUL)  /** @brief 1101: R-4.5V, F-4.6V */
#define MD_SYSCFG_LVDLS_R4V7_F4V8           (0x0000000EUL)  /** @brief 1110: R-4.7V, F-4.8V */
#define MD_SYSCFG_LVDLS_R4V9_F5V            (0x0000000FUL)  /** @brief 1111: R-4.9V, F-5.0V */

/**
  * @brief MD_SYSCFG_WKTRIM_LOSCRCNT These bits are External low-speed clock oscillator, clock stabilization time counter
  */
#define MD_SYSCFG_LOSCRCNT_2048           (0x00000000UL)  /** @brief 00: LOSC count 2048  */
#define MD_SYSCFG_LOSCRCNT_4096           (0x00000001UL)  /** @brief 01: LOSC count 4096  */
#define MD_SYSCFG_LOSCRCNT_8192           (0x00000002UL)  /** @brief 10: LOSC count 8192  */
#define MD_SYSCFG_LOSCRCNT_16384          (0x00000003UL)  /** @brief 11: LOSC count 16384 */

/**
  * @brief MD_SYSCFG_WKTRIM_LOSCCURSEL These bits are External low-speed clock oscillator, start-up current configuration
  */
#define MD_SYSCFG_LOSCCURSEL_120NA          (0x00000000UL)  /** @brief 000: 120nA  */
#define MD_SYSCFG_LOSCCURSEL_200NA          (0x00000001UL)  /** @brief 001: 200nA  */
#define MD_SYSCFG_LOSCCURSEL_280NA          (0x00000002UL)  /** @brief 010: 280nA  */
#define MD_SYSCFG_LOSCCURSEL_360NA          (0x00000003UL)  /** @brief 011: 360nA  */
#define MD_SYSCFG_LOSCCURSEL_440NA          (0x00000004UL)  /** @brief 100: 440nA  */
#define MD_SYSCFG_LOSCCURSEL_520NA          (0x00000005UL)  /** @brief 101: 520nA  */
#define MD_SYSCFG_LOSCCURSEL_600NA          (0x00000006UL)  /** @brief 110: 600nA  */
#define MD_SYSCFG_LOSCCURSEL_680NA          (0x00000007UL)  /** @brief 111: 680nA  */

/**
  * @brief MD_SYSCFG_WKUP_WKEG WKEGx:WKUPx pin edge sensitive type select
  */
#define MD_SYSCFG_WKEG_USBDP                (0x00008000UL)   /** @brief 1<<15    */
#define MD_SYSCFG_WKEG_USBDM                (0x00004000UL)   /** @brief 1<<14    */
#define MD_SYSCFG_WKEG_RTC                  (0x00000800UL)   /** @brief 1<<11    */
#define MD_SYSCFG_WKEG_IWDT                 (0x00000400UL)   /** @brief 1<<10    */
#define MD_SYSCFG_WKEG_LVD                  (0x00000200UL)   /** @brief 1<<9     */
#define MD_SYSCFG_WKEG_NRST                 (0x00000100UL)   /** @brief 1<<8     */
#define MD_SYSCFG_WKEG_WKUP7                (0x00000080UL)   /** @brief 1<<7     */
#define MD_SYSCFG_WKEG_WKUP6                (0x00000040UL)   /** @brief 1<<6     */
#define MD_SYSCFG_WKEG_WKUP5                (0x00000020UL)   /** @brief 1<<5     */
#define MD_SYSCFG_WKEG_WKUP4                (0x00000010UL)   /** @brief 1<<4     */
#define MD_SYSCFG_WKEG_WKUP3                (0x00000008UL)   /** @brief 1<<3     */
#define MD_SYSCFG_WKEG_WKUP2                (0x00000004UL)   /** @brief 1<<2     */
#define MD_SYSCFG_WKEG_WKUP1                (0x00000002UL)   /** @brief 1<<1     */
#define MD_SYSCFG_WKEG_WKUP0                (0x00000001UL)   /** @brief 1<<0     */

/**
  * @brief MD_SYSCFG_WKUP_WKEN WKENx: Enable WKUPx pin or wakeup event
  */
#define MD_SYSCFG_WKEN_USBDP                (0x00008000UL)   /** @brief 1<<15    */
#define MD_SYSCFG_WKEN_USBDM                (0x00004000UL)   /** @brief 1<<14    */
#define MD_SYSCFG_WKEN_RTC                  (0x00000800UL)   /** @brief 1<<11    */
#define MD_SYSCFG_WKEN_IWDT                 (0x00000400UL)   /** @brief 1<<10    */
#define MD_SYSCFG_WKEN_LVD                  (0x00000200UL)   /** @brief 1<<9     */
#define MD_SYSCFG_WKEN_NRST                 (0x00000100UL)   /** @brief 1<<8     */
#define MD_SYSCFG_WKEN_WKUP7                (0x00000080UL)   /** @brief 1<<7     */
#define MD_SYSCFG_WKEN_WKUP6                (0x00000040UL)   /** @brief 1<<6     */
#define MD_SYSCFG_WKEN_WKUP5                (0x00000020UL)   /** @brief 1<<5     */
#define MD_SYSCFG_WKEN_WKUP4                (0x00000010UL)   /** @brief 1<<4     */
#define MD_SYSCFG_WKEN_WKUP3                (0x00000008UL)   /** @brief 1<<3     */
#define MD_SYSCFG_WKEN_WKUP2                (0x00000004UL)   /** @brief 1<<2     */
#define MD_SYSCFG_WKEN_WKUP1                (0x00000002UL)   /** @brief 1<<1     */
#define MD_SYSCFG_WKEN_WKUP0                (0x00000001UL)   /** @brief 1<<0     */

/**
  * @brief MD_SYSCFG_WKSR_LPLS Low Power Level Select
  */
#define MD_SYSCFG_LPLS_STOP_MODE            (0x00000000UL)  /** @brief 0 : Level 0, Stop Mode     */
#define MD_SYSCFG_LPLS_STANDBY0_MODE        (0x00000001UL)  /** @brief 1 : Level 1, Standby0 Mode */
#define MD_SYSCFG_LPLS_STANDBY1_MODE        (0x00000002UL)  /** @brief 2 : Level 2, Standby1 Mode */
#define MD_SYSCFG_LPLS_SHUTDOWN_MODE        (0x00000003UL)  /** @brief 3 : Level 3, Shutdown Mode */

/**
  * @brief MD_SYSCFG_WKSR_FG FGx: WKUPx pin or wakeup event flag
  */
#define MD_SYSCFG_FG_USBDP                  (0x00008000UL)  /** @brief 1<<15    */
#define MD_SYSCFG_FG_USBDM                  (0x00004000UL)  /** @brief 1<<14    */
#define MD_SYSCFG_FG_RTC                    (0x00000800UL)  /** @brief 1<<11    */
#define MD_SYSCFG_FG_IWDT                   (0x00000400UL)  /** @brief 1<<10    */
#define MD_SYSCFG_FG_LVD                    (0x00000200UL)  /** @brief 1<<9     */
#define MD_SYSCFG_FG_NRST                   (0x00000100UL)  /** @brief 1<<8     */
#define MD_SYSCFG_FG_WKUP7                  (0x00000080UL)  /** @brief 1<<7     */
#define MD_SYSCFG_FG_WKUP6                  (0x00000040UL)  /** @brief 1<<6     */
#define MD_SYSCFG_FG_WKUP5                  (0x00000020UL)  /** @brief 1<<5     */
#define MD_SYSCFG_FG_WKUP4                  (0x00000010UL)  /** @brief 1<<4     */
#define MD_SYSCFG_FG_WKUP3                  (0x00000008UL)  /** @brief 1<<3     */
#define MD_SYSCFG_FG_WKUP2                  (0x00000004UL)  /** @brief 1<<2     */
#define MD_SYSCFG_FG_WKUP1                  (0x00000002UL)  /** @brief 1<<1     */
#define MD_SYSCFG_FG_WKUP0                  (0x00000001UL)  /** @brief 1<<0     */

/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions SYSCFG Public Functions
  * @{
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group2 REMAP
  * @{
  */
/**
  * @brief  Set SYSCFG_REMAP Register
  * @param  syscfg SYSCFG Instance
  * @param  remap
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_remap(SYSCFG_TypeDef *syscfg, uint32_t remap)
{
    WRITE_REG(syscfg->REMAP, remap);
}

/**
  * @brief  Get SYSCFG_REMAP Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_remap(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)READ_REG(syscfg->REMAP);
}

/**
  * @brief  Get Current flash start address status
  * @note   If set 0x1, it means second 4k Byte, If set 0x2, it means third 4k Byte, and so on.
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 31
  *         @arg Min Value 0
  */
__STATIC_INLINE uint32_t md_syscfg_get_flash_remap_base_real(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->REMAP, SYSCFG_REMAP_REALBASE) >> SYSCFG_REMAP_REALBASE_POSS);
}

/**
  * @brief  Get Current Memory mapping Status
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_SYSCFG_REALMOD_MAIN
  *         @arg @ref MD_SYSCFG_REALMOD_BOOTROM
  *         @arg @ref MD_SYSCFG_REALMOD_SRAM
  */
__STATIC_INLINE uint32_t md_syscfg_get_memory_mapping_real(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->REMAP, SYSCFG_REMAP_REALMOD) >> SYSCFG_REMAP_REALMOD_POSS);
}
/**
  * @brief  Set Remap Main Flash Base Address Selection
  * @note   If set 0x1, it means second 4k Byte, If set 0x2, it means third 4k Byte, and so on.
  * @param  syscfg SYSCFG Instance
  * @param  efbase This parameter can be one of the following values:
  *         @arg Max Value 31
  *         @arg Min Value 0
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_flash_remap_base(SYSCFG_TypeDef *syscfg, uint32_t efbase)
{
    MODIFY_REG(syscfg->REMAP, SYSCFG_REMAP_EFBASE, (efbase << SYSCFG_REMAP_EFBASE_POSS));
}
/**
  * @brief  Get Remap Main Flash Base Address Selection
  * @note   If read 0x1, it means second 4k Byte, If read 0x2, it means third 4k Byte, and so on.
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 31
  *         @arg Min Value 0
  */
__STATIC_INLINE uint32_t md_syscfg_get_flash_remap_base(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->REMAP, SYSCFG_REMAP_EFBASE) >> SYSCFG_REMAP_EFBASE_POSS);
}
/**
  * @brief  Set Memory mapping selection bits
  * @param  syscfg SYSCFG Instance
  * @param  memmod This parameter can be one of the following values:
  *         @arg @ref MD_SYSCFG_MEMMOD_MAIN
  *         @arg @ref MD_SYSCFG_MEMMOD_BOOTROM
  *         @arg @ref MD_SYSCFG_MEMMOD_SRAM
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_memory_mapping(SYSCFG_TypeDef *syscfg, uint32_t memmod)
{
    MODIFY_REG(syscfg->REMAP, SYSCFG_REMAP_MEMMOD, memmod << SYSCFG_REMAP_MEMMOD_POSS);
}
/**
  * @brief  Get Memory mapping selection bits
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_SYSCFG_MEMMOD_MAIN
  *         @arg @ref MD_SYSCFG_MEMMOD_BOOTROM
  *         @arg @ref MD_SYSCFG_MEMMOD_SRAM
  */
__STATIC_INLINE uint32_t md_syscfg_get_memory_mapping(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->REMAP, SYSCFG_REMAP_MEMMOD) >> SYSCFG_REMAP_MEMMOD_POSS);
}
/**
  * @brief  Set Start Remap bit
  * @note   This bit set High to start remapping process, that will be auto clear when process was finish.
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_memory_remap(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->REMAP, SYSCFG_REMAP_REMAP);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group3 PWR
  * @{
  */
/**
  * @brief  Set SYSCFG_PWR Register
  * @param  syscfg SYSCFG Instance
  * @param  pwr
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_pwr(SYSCFG_TypeDef *syscfg, uint32_t pwr)
{
    WRITE_REG(syscfg->PWR, pwr);
}

/**
  * @brief  Get SYSCFG_PWR Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_pwr(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->PWR));
}

/**
  * @brief  Set LDOUSB regulator current mode enable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_ldousb_lowpower(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->PWR, SYSCFG_PWR_LDOUSBSBY);
}

/**
  * @brief  Set LDOUSB regulator current mode disable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_ldousb_lowpower(SYSCFG_TypeDef *syscfg)
{
    CLEAR_BIT(syscfg->PWR, SYSCFG_PWR_LDOUSBSBY);
}
/**
  * @brief  Check if LDOUSB regulator current mode is enabled
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : ldousb lowpower mode enable
  *         @arg 0x0 : ldousb lowpower mode disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_ldousb_lowpower(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->PWR, SYSCFG_PWR_LDOUSBSBY) == (SYSCFG_PWR_LDOUSBSBY));
}

/**
  * @brief  Set LDOUSB regulator operation mode enable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_ldousb(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->PWR, SYSCFG_PWR_LDOUSBEN);
}

/**
  * @brief  Set LDOUSB regulator operation mode disable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_ldousb(SYSCFG_TypeDef *syscfg)
{
    CLEAR_BIT(syscfg->PWR, SYSCFG_PWR_LDOUSBEN);
}
/**
  * @brief  Check if LDOUSB regulator operation mode is enabled
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : ldousb enable
  *         @arg 0x0 : ldousb disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_ldousb(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->PWR, SYSCFG_PWR_LDOUSBEN) == (SYSCFG_PWR_LDOUSBEN));
}

/**
  * @brief  Set VRES voltage divider power supply selection
  * @param  syscfg SYSCFG Instance
  * @param  ressrc voltage divider power supply selection
            @arg @ref MD_SYSCFG_PWR_VREFINT
            @arg @ref MD_SYSCFG_PWR_VDDA
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_vref_source(SYSCFG_TypeDef *syscfg, uint32_t ressrc)
{
    MODIFY_REG(syscfg->PWR, SYSCFG_PWR_RESSRC, ressrc << SYSCFG_PWR_RESSRC_POS);
}

/**
  * @brief  Get VRES voltage divider power supply selection
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_PWR_VREFINT
            @arg @ref MD_SYSCFG_PWR_VDDA
  */
__STATIC_INLINE uint32_t md_syscfg_get_vref_source(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->PWR, SYSCFG_PWR_RESSRC) >> SYSCFG_PWR_RESSRC_POS);
}

/**
  * @brief  Set VRES voltage divider circuit switch enable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_vref(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->PWR, SYSCFG_PWR_RESEN);
}

/**
  * @brief  Set VRES voltage divider circuit switch disable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_vref(SYSCFG_TypeDef *syscfg)
{
    CLEAR_BIT(syscfg->PWR, SYSCFG_PWR_RESEN);
}
/**
  * @brief  Check if VRES voltage divider circuit switch is enabled
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : Vref enable
  *         @arg 0x0 : Vref disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_vref(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->PWR, SYSCFG_PWR_RESEN) == (SYSCFG_PWR_RESEN));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group4 IRSEL
  * @{
  */
/**
  * @brief  Set SYSCFG_IRSEL Register
  * @param  syscfg SYSCFG Instance
  * @param  irsel
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_irsel(SYSCFG_TypeDef *syscfg, uint32_t irsel)
{
    WRITE_REG(syscfg->IRSEL, irsel);
}

/**
  * @brief  Get SYSCFG_IRSEL Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_irsel(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->IRSEL));
}

/**
  * @brief  Set IR Polarity
  * @param  syscfg SYSCFG Instance
  * @param  plr This parameter can be one of the following values:
  *         @arg @ref MD_SYSCFG_PLR_INV_SEL1_AND_SEL2
  *         @arg @ref MD_SYSCFG_PLR_SEL1_AND_SEL2
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_ir_polarity(SYSCFG_TypeDef *syscfg, uint32_t plr)
{
    MODIFY_REG(syscfg->IRSEL, SYSCFG_IRSEL_PLR, plr << SYSCFG_IRSEL_PLR_POS);
}
/**
  * @brief  Get IR Polarity
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_SYSCFG_PLR_INV_SEL1_AND_SEL2
  *         @arg @ref MD_SYSCFG_PLR_SEL1_AND_SEL2
  */
__STATIC_INLINE uint32_t md_syscfg_get_ir_polarity(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->IRSEL, SYSCFG_IRSEL_PLR) >> SYSCFG_IRSEL_PLR_POS);
}
/**
  * @brief  Set IR Select 2
  * @param  syscfg SYSCFG Instance
  * @param  sel2 This parameter can be one of the following values:
  *         @arg @ref MD_SYSCFG_SEL2_OFF
  *         @arg @ref MD_SYSCFG_SEL2_GP16C2T4_CH1
  *         @arg @ref MD_SYSCFG_SEL2_GP16C2T4_CH2
  *         @arg @ref MD_SYSCFG_SEL2_UART2_TX
  *         @arg @ref MD_SYSCFG_SEL2_UART4_TX
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_ir_source2(SYSCFG_TypeDef *syscfg, uint32_t sel2)
{
    MODIFY_REG(syscfg->IRSEL, SYSCFG_IRSEL_SEL2, sel2 << SYSCFG_IRSEL_SEL2_POSS);
}
/**
  * @brief  Get IR Select 2
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_SYSCFG_SEL2_OFF
  *         @arg @ref MD_SYSCFG_SEL2_GP16C2T4_CH1
  *         @arg @ref MD_SYSCFG_SEL2_GP16C2T4_CH2
  *         @arg @ref MD_SYSCFG_SEL2_UART2_TX
  *         @arg @ref MD_SYSCFG_SEL2_UART4_TX
  */
__STATIC_INLINE uint32_t md_syscfg_get_ir_source2(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->IRSEL, SYSCFG_IRSEL_SEL2) >> SYSCFG_IRSEL_SEL2_POSS);
}
/**
  * @brief  Set IR Select 1
  * @param  syscfg SYSCFG Instance
  * @param  sel1 This parameter can be one of the following values:
  *         @arg @ref MD_SYSCFG_SEL1_OFF
  *         @arg @ref MD_SYSCFG_SEL1_GP16C2T2_CH1
  *         @arg @ref MD_SYSCFG_SEL1_GP16C2T2_CH2
  *         @arg @ref MD_SYSCFG_SEL1_GP16C2T3_CH1
  *         @arg @ref MD_SYSCFG_SEL1_GP16C2T3_CH2
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_ir_source1(SYSCFG_TypeDef *syscfg, uint32_t sel1)
{
    MODIFY_REG(syscfg->IRSEL, SYSCFG_IRSEL_SEL1, sel1 << SYSCFG_IRSEL_SEL1_POSS);
}
/**
  * @brief  Get IR Select 1
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg @ref MD_SYSCFG_SEL1_OFF
  *         @arg @ref MD_SYSCFG_SEL1_GP16C2T2_CH1
  *         @arg @ref MD_SYSCFG_SEL1_GP16C2T2_CH2
  *         @arg @ref MD_SYSCFG_SEL1_GP16C2T3_CH1
  *         @arg @ref MD_SYSCFG_SEL1_GP16C2T3_CH2
  */
__STATIC_INLINE uint32_t md_syscfg_get_ir_source1(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->IRSEL, SYSCFG_IRSEL_SEL1) >> SYSCFG_IRSEL_SEL1_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group5 SYSTRIM
  * @{
  */
/**
  * @brief  Get SYSCFG_SYSTRIM Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_systrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->SYSTRIM));
}

/**
  * @brief  Get USB LDO calibration value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_usbldotrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->SYSTRIM, SYSCFG_SYSTRIM_USBLDOTRIM) >> SYSCFG_SYSTRIM_USBLDOTRIM_POSS);
}

/**
  * @brief  Get Programmable low voltage detection calibration value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_lvdtrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->SYSTRIM, SYSCFG_SYSTRIM_LVDTRIM) >> SYSCFG_SYSTRIM_LVDTRIM_POSS);
}

/**
  * @brief  Get BandGap reference voltage calibration value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_bandgaptrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->SYSTRIM, SYSCFG_SYSTRIM_BGTRIM) >> SYSCFG_SYSTRIM_BGTRIM_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group6 CLKTRIM
  * @{
  */
/**
  * @brief  Get SYSCFG_CLKTRIM Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_clktrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->CLKTRIM));
}

/**
  * @brief  Get PLL FNS control
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_pllfnstrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->CLKTRIM, SYSCFG_CLKTRIM_PLLFNS) >> SYSCFG_CLKTRIM_PLLFNS_POSS);
}

/**
  * @brief  Get HRC 48MHz clock calibration value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_hrc48trim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->CLKTRIM, SYSCFG_CLKTRIM_HRC48TRIM) >> SYSCFG_CLKTRIM_HRC48TRIM_POSS);
}

/**
  * @brief  Get LRC clock calibration value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_lrctrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->CLKTRIM, SYSCFG_CLKTRIM_LRCTRIM) >> SYSCFG_CLKTRIM_LRCTRIM_POSS);
}

/**
  * @brief  Get HRC clock calibration value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_hrctrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->CLKTRIM, SYSCFG_CLKTRIM_HRCTRIM) >> SYSCFG_CLKTRIM_HRCTRIMM_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group7 OSCTRIM
  * @{
  */
/**
  * @brief  Get SYSCFG_OSCTRIM Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_osctrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->OSCTRIM));
}

/**
  * @brief  Get LOSC clock stable count value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_losc_ready_count(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->OSCTRIM, SYSCFG_OSCTRIM_LOSCRCNT) >> SYSCFG_OSCTRIM_LOSCRCNT_POSS);
}

/**
  * @brief  Get LOSC current selection
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_losc_current_select(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->OSCTRIM, SYSCFG_OSCTRIM_LOSCCURSEL) >> SYSCFG_OSCTRIM_LOSCCURSEL_POSS);
}

/**
  * @brief  Get HOSC clock stable count value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_hosc_ready_count(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->OSCTRIM, SYSCFG_OSCTRIM_HOSCRCNT) >> SYSCFG_OSCTRIM_HOSCRCNT_POSS);
}

/**
  * @brief  Get HOSC current selection
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_hosc_current_select(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->OSCTRIM, SYSCFG_OSCTRIM_HOSCCURSEL) >> SYSCFG_OSCTRIM_HOSCCURSEL_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group8 IPTRIM
  * @{
  */
/**
  * @brief  Get SYSCFG_IPTRIM Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_iptrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->IPTRIM));
}

/**
  * @brief  Get Comparator 2 calibration value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_cmp2trim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->IPTRIM, SYSCFG_IPTRIM_CMP2TRIM) >> SYSCFG_IPTRIM_CMP2TRIM_POSS);
}

/**
  * @brief  Get Comparator 1 calibration value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_option_cmp1trim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->IPTRIM, SYSCFG_IPTRIM_CMP1TRIM) >> SYSCFG_IPTRIM_CMP1TRIM_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group9 AHBIPEN
  * @{
  */
/**
  * @brief  Get SYSCFG_AHBIPEN Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_ahbipen(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->AHBIPEN));
}

/**
  * @brief  Get GPIO D Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpiod exist
  *         @arg 0x0 : gpiod non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gpiod_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_GPDEN) == (SYSCFG_AHBIPEN_GPDEN));
}

/**
  * @brief  Get GPIO C Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpioc exist
  *         @arg 0x0 : gpioc non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gpioc_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_GPCEN) == (SYSCFG_AHBIPEN_GPCEN));
}

/**
  * @brief  Get GPIO B Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpiob exist
  *         @arg 0x0 : gpiob non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gpiob_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_GPBEN) == (SYSCFG_AHBIPEN_GPBEN));
}

/**
  * @brief  Get GPIO A Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gpioa exist
  *         @arg 0x0 : gpioa non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gpioa_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_GPAEN) == (SYSCFG_AHBIPEN_GPAEN));
}

/**
  * @brief  Get CALC Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : calc exist
  *         @arg 0x0 : calc non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_calc_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_CALCEN) == (SYSCFG_AHBIPEN_CALCEN));
}

/**
  * @brief  Get USB Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : usb exist
  *         @arg 0x0 : usb non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_usb_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_USBEN) == (SYSCFG_AHBIPEN_USBEN));
}

/**
  * @brief  Get AES Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : aes exist
  *         @arg 0x0 : aes non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_aes_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_AESEN) == (SYSCFG_AHBIPEN_AESEN));
}

/**
  * @brief  Get CRC Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : crc exist
  *         @arg 0x0 : crc non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_crc_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_CRCEN) == (SYSCFG_AHBIPEN_CRCEN));
}

/**
  * @brief  Get CSU Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : csu exist
  *         @arg 0x0 : csu non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_csu_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_CSUEN) == (SYSCFG_AHBIPEN_CSUEN));
}

/**
  * @brief  Get KBCU Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : kbcu exist
  *         @arg 0x0 : kbcu non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_kbcu_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_KBCUEN) == (SYSCFG_AHBIPEN_KBCUEN));
}

/**
  * @brief  Get RTC Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : rtc exist
  *         @arg 0x0 : rtc non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_rtc_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_RTCEN) == (SYSCFG_AHBIPEN_RTCEN));
}

/**
  * @brief  Get DMA1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : dma1 exist
  *         @arg 0x0 : dma1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_dma1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->AHBIPEN, SYSCFG_AHBIPEN_DMA1EN) == (SYSCFG_AHBIPEN_DMA1EN));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group10 APB1IPEN
  * @{
  */
/**
  * @brief  Get SYSCFG_APB1IPEN Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_apb1ipen(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->APB1IPEN));
}

/**
  * @brief  Get I2C2 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : i2c2 exist
  *         @arg 0x0 : i2c2 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_i2c2_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_I2C2EN) == (SYSCFG_APB1IPEN_I2C2EN));
}

/**
  * @brief  Get I2C1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : i2c1 exist
  *         @arg 0x0 : i2c1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_i2c1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_I2C1EN) == (SYSCFG_APB1IPEN_I2C1EN));
}

/**
  * @brief  Get UART4 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart4 exist
  *         @arg 0x0 : uart4 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_uart4_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_UART4EN) == (SYSCFG_APB1IPEN_UART4EN));
}

/**
  * @brief  Get UART3 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart3 exist
  *         @arg 0x0 : uart3 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_uart3_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_UART3EN) == (SYSCFG_APB1IPEN_UART3EN));
}

/**
  * @brief  Get UART2 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart2 exist
  *         @arg 0x0 : uart2 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_uart2_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_UART2EN) == (SYSCFG_APB1IPEN_UART2EN));
}

/**
  * @brief  Get SPI3 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi3 exist
  *         @arg 0x0 : spi3 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_spi3_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_SPI3EN) == (SYSCFG_APB1IPEN_SPI3EN));
}

/**
  * @brief  Get SPI2 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi2 exist
  *         @arg 0x0 : spi2 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_spi2_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_SPI2EN) == (SYSCFG_APB1IPEN_SPI2EN));
}

/**
  * @brief  Get IWDT Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : iwdt exist
  *         @arg 0x0 : iwdt non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_iwdt_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_IWDTEN) == (SYSCFG_APB1IPEN_IWDTEN));
}

/**
  * @brief  Get WWDT Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : wwdt exist
  *         @arg 0x0 : wwdt non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_wwdt_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_WWDTEN) == (SYSCFG_APB1IPEN_WWDTEN));
}

/**
  * @brief  Get BS16T1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : bs16t1 exist
  *         @arg 0x0 : bs16t1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_bs16t1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_BS16T1EN) == (SYSCFG_APB1IPEN_BS16T1EN));
}

/**
  * @brief  Get GP16C4T3 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t3 exist
  *         @arg 0x0 : gp16c4t3 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gp16c4t3_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_GP16C4T3EN) == (SYSCFG_APB1IPEN_GP16C4T3EN));
}

/**
  * @brief  Get GP16C4T2 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t2 exist
  *         @arg 0x0 : gp16c4t2 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gp16c4t2_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_GP16C4T2EN) == (SYSCFG_APB1IPEN_GP16C4T2EN));
}

/**
  * @brief  Get GP16C4T1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c4t1 exist
  *         @arg 0x0 : gp16c4t1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gp16c4t1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_GP16C4T1EN) == (SYSCFG_APB1IPEN_GP16C4T1EN));
}

/**
  * @brief  Get GP32C4T1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp32c4t1 exist
  *         @arg 0x0 : gp32c4t1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gp32c4t1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB1IPEN, SYSCFG_APB1IPEN_GP32C4T1EN) == (SYSCFG_APB1IPEN_GP32C4T1EN));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group11 APB2IPEN
  * @{
  */
/**
  * @brief  Get SYSCFG_APB2IPEN Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_apb2ipen(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->APB2IPEN));
}

/**
  * @brief  Get CMP Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : cmp exist
  *         @arg 0x0 : cmp non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_cmp_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_CMPEN) == (SYSCFG_APB2IPEN_CMPEN));
}

/**
  * @brief  Get GP16C2T4 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t4 exist
  *         @arg 0x0 : gp16c2t4 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gp16c2t4_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_GP16C2T4EN) == (SYSCFG_APB2IPEN_GP16C2T4EN));
}

/**
  * @brief  Get GP16C2T3 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t3 exist
  *         @arg 0x0 : gp16c2t3 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gp16c2t3_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_GP16C2T3EN) == (SYSCFG_APB2IPEN_GP16C2T3EN));
}

/**
  * @brief  Get GP16C2T2 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t2 exist
  *         @arg 0x0 : gp16c2t2 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gp16c2t2_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_GP16C2T2EN) == (SYSCFG_APB2IPEN_GP16C2T2EN));
}

/**
  * @brief  Get GP16C2T1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : gp16c2t1 exist
  *         @arg 0x0 : gp16c2t1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_gp16c2t1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_GP16C2T1EN) == (SYSCFG_APB2IPEN_GP16C2T1EN));
}

/**
  * @brief  Get UART1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : uart1 exist
  *         @arg 0x0 : uart1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_uart1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_UART1EN) == (SYSCFG_APB2IPEN_UART1EN));
}

/**
  * @brief  Get SPI1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : spi1 exist
  *         @arg 0x0 : spi1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_spi1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_SPI1EN) == (SYSCFG_APB2IPEN_SPI1EN));
}

/**
  * @brief  Get AD16C4T1 Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : ad16c4t1 exist
  *         @arg 0x0 : ad16c4t1 non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_ad16c4t1_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_AD16C4T1EN) == (SYSCFG_APB2IPEN_AD16C4T1EN));
}

/**
  * @brief  Get ADC Peripheral valid state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : adc exist
  *         @arg 0x0 : adc non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_adc_exist(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->APB2IPEN, SYSCFG_APB2IPEN_ADCEN) == (SYSCFG_APB2IPEN_ADCEN));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group12 MEMMOD
  * @{
  */
/**
  * @brief  Get SYSCFG_MEMMOD Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_memmod(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->MEMMOD));
}

/**
  * @brief  Get memory size
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_SMOD_32KB
            @arg @ref MD_SYSCFG_SMOD_16KB
            @arg @ref MD_SYSCFG_SMOD_8KB
            @arg @ref MD_SYSCFG_SMOD_4KB
            @arg @ref MD_SYSCFG_SMOD_2KB
  */
__STATIC_INLINE uint32_t md_syscfg_get_sram_size(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->MEMMOD, SYSCFG_MEMMOD_SMOD) >> SYSCFG_MEMMOD_SMOD_POSS);
}

/**
  * @brief  Get flash size
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_FMOD_256KB
            @arg @ref MD_SYSCFG_FMOD_128KB
            @arg @ref MD_SYSCFG_FMOD_64KB
            @arg @ref MD_SYSCFG_FMOD_32KB
            @arg @ref MD_SYSCFG_FMOD_16KB
  */
__STATIC_INLINE uint32_t md_syscfg_get_flash_size(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->MEMMOD, SYSCFG_MEMMOD_FMOD) >> SYSCFG_MEMMOD_FMOD_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group13 ADCVREF
  * @{
  */
/**
  * @brief  Get ADC reference voltage measurement value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_adc_reference(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->ADCVREF, SYSCFG_ADCVREF_ADCVREF));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group14 ADCTEMP
  * @{
  */
/**
  * @brief  Get SYSCFG_ADCTEMP Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_adctemp(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->ADCTEMP));
}

/**
  * @brief  Get ADC temperature sensor high temperature measurement value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_adc_high_temperature_reference(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->ADCTEMP, SYSCFG_ADCTEMP_ADCTEMPH) >> SYSCFG_ADCTEMP_ADCTEMPH_POSS);
}

/**
  * @brief  Get ADC temperature sensor low temperature measurement value
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_adc_low_temperature_reference(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->ADCTEMP, SYSCFG_ADCTEMP_ADCTEMPL) >> SYSCFG_ADCTEMP_ADCTEMPL_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group15 SYSSET
  * @{
  */
/**
  * @brief  Get SYSCFG_SYSSET Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_sysset(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->SYSSET));
}

/**
  * @brief  Get User configuration word IWDT switch
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_iwdt_hardware_enable(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->SYSSET, SYSCFG_SYSSET_SYS_IWDTEN) >> SYSCFG_SYSSET_SYS_IWDTEN_POSS);
}

/**
  * @brief  Get User configuration word IWDT switch
  * @param  syscfg SYSCFG Instance
  * @retval
  */
__STATIC_INLINE uint32_t md_syscfg_get_bor_hardware_enable(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->SYSSET, SYSCFG_SYSSET_SYS_BOREN) >> SYSCFG_SYSSET_SYS_BOREN_POSS);
}

/**
  * @brief  Get User configuration word IWDT switch
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_SYS_BORLS_LV0
            @arg @ref MD_SYSCFG_SYS_BORLS_LV1
            @arg @ref MD_SYSCFG_SYS_BORLS_LV2
            @arg @ref MD_SYSCFG_SYS_BORLS_LV3
            @arg @ref MD_SYSCFG_SYS_BORLS_LV4
            @arg @ref MD_SYSCFG_SYS_BORLS_LV5
            @arg @ref MD_SYSCFG_SYS_BORLS_LV6
            @arg @ref MD_SYSCFG_SYS_BORLS_LV7
  */
__STATIC_INLINE uint32_t md_syscfg_get_bor_level_hardware_select(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->SYSSET, SYSCFG_SYSSET_SYS_BORLS) >> SYSCFG_SYSSET_SYS_BORLS_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group16 CFG
  * @{
  */
/**
  * @brief  Set SYSCFG_CFG Register
  * @param  syscfg SYSCFG Instance
  * @param  cfg
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_cfg(SYSCFG_TypeDef *syscfg, uint32_t cfg)
{
    WRITE_REG(syscfg->CFG, cfg);
}

/**
  * @brief  Get SYSCFG_CFG Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_cfg(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->CFG));
}

/**
  * @brief  Set DBG Halt enable bit
  * @note   Set bit to stopped the counter clock when the core is halted
  * @param  syscfg SYSCFG Instance
  * @param  dbghen This parameter can be one of the following values:
            @arg @ref MD_SYSCFG_DBGHEN_IWDT
            @arg @ref MD_SYSCFG_DBGHEN_WWDT
            @arg @ref MD_SYSCFG_DBGHEN_I2C2
            @arg @ref MD_SYSCFG_DBGHEN_I2C1
            @arg @ref MD_SYSCFG_DBGHEN_BS16T1
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T3
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T2
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T1
            @arg @ref MD_SYSCFG_DBGHEN_GP32C4T1
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T4
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T3
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T2
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T1
            @arg @ref MD_SYSCFG_DBGHEN_AD16C4T1
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_debug_hault(SYSCFG_TypeDef *syscfg, uint32_t dbghen)
{
    SET_BIT(syscfg->CFG, dbghen << SYSCFG_CFG_DBGHEN_POSS);
}

/**
  * @brief  Set DBG Halt disable bit
  * @note   Set bit to let the counter clock continuous output when the core is halted
  * @param  syscfg SYSCFG Instance
  * @param  dbghen This parameter can be one of the following values:
            @arg @ref MD_SYSCFG_DBGHEN_IWDT
            @arg @ref MD_SYSCFG_DBGHEN_WWDT
            @arg @ref MD_SYSCFG_DBGHEN_I2C2
            @arg @ref MD_SYSCFG_DBGHEN_I2C1
            @arg @ref MD_SYSCFG_DBGHEN_BS16T1
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T3
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T2
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T1
            @arg @ref MD_SYSCFG_DBGHEN_GP32C4T1
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T4
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T3
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T2
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T1
            @arg @ref MD_SYSCFG_DBGHEN_AD16C4T1
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_debug_hault(SYSCFG_TypeDef *syscfg, uint32_t dbghen)
{
    CLEAR_BIT(syscfg->CFG, dbghen << SYSCFG_CFG_DBGHEN_POSS);
}

/**
  * @brief  Get DBG Halt enable bit
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_DBGHEN_IWDT
            @arg @ref MD_SYSCFG_DBGHEN_WWDT
            @arg @ref MD_SYSCFG_DBGHEN_I2C2
            @arg @ref MD_SYSCFG_DBGHEN_I2C1
            @arg @ref MD_SYSCFG_DBGHEN_BS16T1
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T3
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T2
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T1
            @arg @ref MD_SYSCFG_DBGHEN_GP32C4T1
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T4
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T3
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T2
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T1
            @arg @ref MD_SYSCFG_DBGHEN_AD16C4T1
  */
__STATIC_INLINE uint32_t md_syscfg_get_debug_hault(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->CFG, SYSCFG_CFG_DBGHEN) >> SYSCFG_CFG_DBGHEN_POSS);
}

/**
  * @brief  DBG Halt bit is enabled
  * @param  syscfg SYSCFG Instance
            @arg @ref MD_SYSCFG_DBGHEN_IWDT
            @arg @ref MD_SYSCFG_DBGHEN_WWDT
            @arg @ref MD_SYSCFG_DBGHEN_I2C2
            @arg @ref MD_SYSCFG_DBGHEN_I2C1
            @arg @ref MD_SYSCFG_DBGHEN_BS16T1
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T3
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T2
            @arg @ref MD_SYSCFG_DBGHEN_GP16C4T1
            @arg @ref MD_SYSCFG_DBGHEN_GP32C4T1
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T4
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T3
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T2
            @arg @ref MD_SYSCFG_DBGHEN_GP16C2T1
            @arg @ref MD_SYSCFG_DBGHEN_AD16C4T1
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : IP debug hault enable
  *         @arg 0x0 : IP debug hault disable
  */
__STATIC_INLINE uint32_t md_rcu_is_enabled_debug_hault(SYSCFG_TypeDef *syscfg, uint32_t dbgh)
{
    return (READ_BIT(syscfg->CFG, dbgh << SYSCFG_CFG_DBGHEN_POSS) == (dbgh << SYSCFG_CFG_DBGHEN_POSS));
}

/**
  * @brief  Low voltage detection (LVD) event input switch enable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_timer_break_lvd(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->CFG, SYSCFG_CFG_LVDLCK);
}
/**
  * @brief  Low voltage detection (LVD) event input switch disable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_timer_break_lvd(SYSCFG_TypeDef *syscfg)
{
    CLEAR_BIT(syscfg->CFG, SYSCFG_CFG_LVDLCK);
}
/**
  * @brief  Check if Low voltage detection (LVD) event input switch is enabled
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : LVD Timer break function enable
  *         @arg 0x0 : LVD Timer break function disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_timer_break_lvd(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->CFG, SYSCFG_CFG_LVDLCK) == (SYSCFG_CFG_LVDLCK));
}

/**
  * @brief  Clock Security Event (CSS) input switch enable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_timer_break_css(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->CFG, SYSCFG_CFG_CSSLCK);
}
/**
  * @brief  Clock Security Event (CSS) input switch disable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_timer_break_css(SYSCFG_TypeDef *syscfg)
{
    CLEAR_BIT(syscfg->CFG, SYSCFG_CFG_CSSLCK);
}
/**
  * @brief  Check if Clock Security Event (CSS) input switch is enabled
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : CSS Timer break function enable
  *         @arg 0x0 : CSS Timer break function disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_timer_break_css(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->CFG, SYSCFG_CFG_CSSLCK) == (SYSCFG_CFG_CSSLCK));
}

/**
  * @brief  CPU Lockup event input switch enable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_timer_break_cpu_lockup(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->CFG, SYSCFG_CFG_CPULCK);
}
/**
  * @brief  CPU Lockup event input switch disable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_timer_break_cpu_lockup(SYSCFG_TypeDef *syscfg)
{
    CLEAR_BIT(syscfg->CFG, SYSCFG_CFG_CPULCK);
}
/**
  * @brief  Check if CPU Lockup event input switch is enabled
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : CPU Lockup Timer break function enable
  *         @arg 0x0 : CPU Lockup Timer break function disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_timer_break_cpu_lockup(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->CFG, SYSCFG_CFG_CPULCK) == (SYSCFG_CFG_CPULCK));
}

/**
  * @brief  Get Backup register bus idle flag
  * @param  syscfg SYSCFG Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_syscfg_is_active_flag_backup_bus_idle(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->CFG, SYSCFG_CFG_BKREADY) == (SYSCFG_CFG_BKREADY));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group17 PWRCON
  * @{
  */
/**
  * @brief  Set SYSCFG_PWRCON register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_pwrcon(SYSCFG_TypeDef *syscfg, uint32_t pwrcon)
{
    WRITE_REG(syscfg->PWRCON, pwrcon);
}

/**
  * @brief  Get SYSCFG_PWRCON Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_pwrcon(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->PWRCON));
}

/**
  * @brief  Get IWDT state
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : IWDT enable
  *         @arg 0x0 : IWDT disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_iwdt(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->PWRCON, SYSCFG_PWRCON_IWDTEN) == (SYSCFG_PWRCON_IWDTEN));
}

/**
  * @brief  Low voltage reset switch enable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_bor(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->PWRCON, SYSCFG_PWRCON_BOREN);
}
/**
  * @brief  Low voltage reset switch disable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_bor(SYSCFG_TypeDef *syscfg)
{
    CLEAR_BIT(syscfg->PWRCON, SYSCFG_PWRCON_BOREN);
}
/**
  * @brief  Check if Low voltage reset switch is enabled
  * @param  syscfg SYSCFG Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_syscfg_is_enable_bor(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->PWRCON, SYSCFG_PWRCON_BOREN) == (SYSCFG_PWRCON_BOREN));
}

/**
  * @brief  Set Low voltage reset voltage interval selection
  * @param  syscfg SYSCFG Instance
  * @param  borls Low voltage reset voltage interval selection
            @arg @ref MD_SYSCFG_BORLS_LV0
            @arg @ref MD_SYSCFG_BORLS_LV1
            @arg @ref MD_SYSCFG_BORLS_LV2
            @arg @ref MD_SYSCFG_BORLS_LV3
            @arg @ref MD_SYSCFG_BORLS_LV4
            @arg @ref MD_SYSCFG_BORLS_LV5
            @arg @ref MD_SYSCFG_BORLS_LV6
            @arg @ref MD_SYSCFG_BORLS_LV7
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_bor_level(SYSCFG_TypeDef *syscfg, uint32_t borls)
{
    MODIFY_REG(syscfg->PWRCON, SYSCFG_PWRCON_BORLS, borls << SYSCFG_PWRCON_BORLS_POSS);
}

/**
  * @brief  Get Low voltage reset voltage interval selection
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_BORLS_LV0
            @arg @ref MD_SYSCFG_BORLS_LV1
            @arg @ref MD_SYSCFG_BORLS_LV2
            @arg @ref MD_SYSCFG_BORLS_LV3
            @arg @ref MD_SYSCFG_BORLS_LV4
            @arg @ref MD_SYSCFG_BORLS_LV5
            @arg @ref MD_SYSCFG_BORLS_LV6
            @arg @ref MD_SYSCFG_BORLS_LV7
  */
__STATIC_INLINE uint32_t md_syscfg_get_bor_level(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->PWRCON, SYSCFG_PWRCON_BORLS) >> SYSCFG_PWRCON_BORLS_POSS);
}

/**
  * @brief  Low voltage detection switch enable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_lvd(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->PWRCON, SYSCFG_PWRCON_LVDEN);
}
/**
  * @brief  Low voltage detection switch disable
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_lvd(SYSCFG_TypeDef *syscfg)
{
    CLEAR_BIT(syscfg->PWRCON, SYSCFG_PWRCON_LVDEN);
}
/**
  * @brief  Check if Low voltage detection switch is enabled
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : LVD enable
  *         @arg 0x0 : LVD disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_lvd(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->PWRCON, SYSCFG_PWRCON_LVDEN) == (SYSCFG_PWRCON_LVDEN));
}

/**
  * @brief  Set Low voltage detection voltage range selection
  * @param  syscfg SYSCFG Instance
  * @param  lvdls Low voltage detection voltage range selection
            @arg @ref MD_SYSCFG_LVDLS_R1V9_F2V
            @arg @ref MD_SYSCFG_LVDLS_R2V1_F2V2
            @arg @ref MD_SYSCFG_LVDLS_R2V3_F2V4
            @arg @ref MD_SYSCFG_LVDLS_R2V5_F2V6
            @arg @ref MD_SYSCFG_LVDLS_R2V7_F2V8
            @arg @ref MD_SYSCFG_LVDLS_R2V9_F3V
            @arg @ref MD_SYSCFG_LVDLS_R3V1_F3V2
            @arg @ref MD_SYSCFG_LVDLS_R3V3_F3V4
            @arg @ref MD_SYSCFG_LVDLS_R3V5_F3V6
            @arg @ref MD_SYSCFG_LVDLS_R3V7_F3V8
            @arg @ref MD_SYSCFG_LVDLS_R3V9_F4V
            @arg @ref MD_SYSCFG_LVDLS_R4V1_F4V2
            @arg @ref MD_SYSCFG_LVDLS_R4V3_F4V4
            @arg @ref MD_SYSCFG_LVDLS_R4V5_F4V6
            @arg @ref MD_SYSCFG_LVDLS_R4V7_F4V8
            @arg @ref MD_SYSCFG_LVDLS_R4V9_F5V
            @arg @ref MD_SYSCFG_LVDLS_R4V9_F5V
  * @retval None
*/
__STATIC_INLINE void md_syscfg_set_lvd_level(SYSCFG_TypeDef *syscfg, uint32_t lvdls)
{
    MODIFY_REG(syscfg->PWRCON, SYSCFG_PWRCON_LVDLS, lvdls << SYSCFG_PWRCON_LVDLS_POSS);
}

/**
  * @brief  Get Low voltage detection voltage range selection
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_LVDLS_R1V9_F2V
            @arg @ref MD_SYSCFG_LVDLS_R2V1_F2V2
            @arg @ref MD_SYSCFG_LVDLS_R2V3_F2V4
            @arg @ref MD_SYSCFG_LVDLS_R2V5_F2V6
            @arg @ref MD_SYSCFG_LVDLS_R2V7_F2V8
            @arg @ref MD_SYSCFG_LVDLS_R2V9_F3V
            @arg @ref MD_SYSCFG_LVDLS_R3V1_F3V2
            @arg @ref MD_SYSCFG_LVDLS_R3V3_F3V4
            @arg @ref MD_SYSCFG_LVDLS_R3V5_F3V6
            @arg @ref MD_SYSCFG_LVDLS_R3V7_F3V8
            @arg @ref MD_SYSCFG_LVDLS_R3V9_F4V
            @arg @ref MD_SYSCFG_LVDLS_R4V1_F4V2
            @arg @ref MD_SYSCFG_LVDLS_R4V3_F4V4
            @arg @ref MD_SYSCFG_LVDLS_R4V5_F4V6
            @arg @ref MD_SYSCFG_LVDLS_R4V7_F4V8
            @arg @ref MD_SYSCFG_LVDLS_R4V9_F5V
  */
__STATIC_INLINE uint32_t md_syscfg_get_lvd_level(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->PWRCON, SYSCFG_PWRCON_LVDLS) >> SYSCFG_PWRCON_LVDLS_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group18 WKTRIM
  * @{
  */
/**
  * @brief  Set SYSCFG_WKTRIM register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_wktrim(SYSCFG_TypeDef *syscfg, uint32_t wktrim)
{
    WRITE_REG(syscfg->WKTRIM, wktrim);
}

/**
  * @brief  Get SYSCFG_WKTRIM Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_wktrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->WKTRIM));
}

/**
  * @brief  Set External low-speed clock oscillator, clock stabilization time counter
  * @param  syscfg SYSCFG Instance
  * @param  loscrcnt clock stabilization time counter
            @arg @ref MD_SYSCFG_LOSCRCNT_2048
            @arg @ref MD_SYSCFG_LOSCRCNT_4096
            @arg @ref MD_SYSCFG_LOSCRCNT_8192
            @arg @ref MD_SYSCFG_LOSCRCNT_16384
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_losc_ready_count(SYSCFG_TypeDef *syscfg, uint32_t loscrcnt)
{
    MODIFY_REG(syscfg->WKTRIM, SYSCFG_WKTRIM_LOSCRCNT, loscrcnt << SYSCFG_WKTRIM_LOSCRCNT_POSS);
}

/**
  * @brief  Get External low-speed clock oscillator, clock stabilization time counter
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_LOSCRCNT_2048
            @arg @ref MD_SYSCFG_LOSCRCNT_4096
            @arg @ref MD_SYSCFG_LOSCRCNT_8192
            @arg @ref MD_SYSCFG_LOSCRCNT_16384
  */
__STATIC_INLINE uint32_t md_syscfg_get_losc_ready_count(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->WKTRIM, SYSCFG_WKTRIM_LOSCRCNT) >> SYSCFG_WKTRIM_LOSCRCNT_POSS);
}

/**
  * @brief  Set External low-speed clock oscillator, start-up current configuration
  * @param  syscfg SYSCFG Instance
  * @param  losccursel Starting current configuration
            @arg @ref MD_SYSCFG_LOSCCURSEL_120NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_200NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_280NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_360NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_440NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_520NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_600NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_680NA
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_losc_current_select(SYSCFG_TypeDef *syscfg, uint32_t losccursel)
{
    MODIFY_REG(syscfg->WKTRIM, SYSCFG_WKTRIM_LOSCCURSEL, losccursel << SYSCFG_WKTRIM_LOSCCURSEL_POSS);
}

/**
  * @brief  Get External low-speed clock oscillator, start-up current configuration
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_LOSCCURSEL_120NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_200NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_280NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_360NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_440NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_520NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_600NA
            @arg @ref MD_SYSCFG_LOSCCURSEL_680NA
  */
__STATIC_INLINE uint32_t md_syscfg_get_losc_current_select(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->WKTRIM, SYSCFG_WKTRIM_LOSCCURSEL) >> SYSCFG_WKTRIM_LOSCCURSEL_POSS);
}

/**
  * @brief  Get Low voltage detection (LVD) calibration value
  * @param  syscfg SYSCFG Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t md_syscfg_get_lvdtrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->WKTRIM, SYSCFG_WKTRIM_LVDTRIM) >> SYSCFG_WKTRIM_LVDTRIM_POSS);
}

/**
  * @brief  Get BandGap calibration value
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 15
  *         @arg Min Value 0
  */
__STATIC_INLINE uint32_t md_syscfg_get_bandgaptrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->WKTRIM, SYSCFG_WKTRIM_BGTRIM) >> SYSCFG_WKTRIM_BGTRIM_POSS);
}

/**
  * @brief  Get LRC clock calibration value
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 127
  *         @arg Min Value 0
  */
__STATIC_INLINE uint32_t md_syscfg_get_lrctrim(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->WKTRIM, SYSCFG_WKTRIM_LRCTRIM) >> SYSCFG_WKTRIM_LRCTRIM_POSS);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group19 WKUP
  * @{
  */
/**
  * @brief  Set SYSCFG_WKUP register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_wkup(SYSCFG_TypeDef *syscfg, uint32_t wkup)
{
    WRITE_REG(syscfg->WKUP, wkup);
}

/**
  * @brief  Get SYSCFG_WKUP Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_wkup(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->WKUP));
}

/**
  * @brief  Enable Wake-up event rising edge mode
  * @param  syscfg SYSCFG Instance
  * @param  wkeg Wake-up event rising edge or falling edge mode
            @arg @ref MD_SYSCFG_WKEG_USBDP
            @arg @ref MD_SYSCFG_WKEG_USBDM
            @arg @ref MD_SYSCFG_WKEG_RTC
            @arg @ref MD_SYSCFG_WKEG_IWDT
            @arg @ref MD_SYSCFG_WKEG_LVD
            @arg @ref MD_SYSCFG_WKEG_NRST
            @arg @ref MD_SYSCFG_WKEG_WKUP7
            @arg @ref MD_SYSCFG_WKEG_WKUP6
            @arg @ref MD_SYSCFG_WKEG_WKUP5
            @arg @ref MD_SYSCFG_WKEG_WKUP4
            @arg @ref MD_SYSCFG_WKEG_WKUP3
            @arg @ref MD_SYSCFG_WKEG_WKUP2
            @arg @ref MD_SYSCFG_WKEG_WKUP1
            @arg @ref MD_SYSCFG_WKEG_WKUP0
   * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_wakeup_edge_rising(SYSCFG_TypeDef *syscfg, uint32_t wkeg)
{
    SET_BIT(syscfg->WKUP, wkeg << SYSCFG_WKUP_WKEG_POSS);
}

/**
  * @brief  Enable Wake-up event falling edge mode
  * @param  syscfg SYSCFG Instance
  * @param  wkeg Wake-up event rising edge or falling edge mode
            @arg @ref MD_SYSCFG_WKEG_USBDP
            @arg @ref MD_SYSCFG_WKEG_USBDM
            @arg @ref MD_SYSCFG_WKEG_RTC
            @arg @ref MD_SYSCFG_WKEG_IWDT
            @arg @ref MD_SYSCFG_WKEG_LVD
            @arg @ref MD_SYSCFG_WKEG_NRST
            @arg @ref MD_SYSCFG_WKEG_WKUP7
            @arg @ref MD_SYSCFG_WKEG_WKUP6
            @arg @ref MD_SYSCFG_WKEG_WKUP5
            @arg @ref MD_SYSCFG_WKEG_WKUP4
            @arg @ref MD_SYSCFG_WKEG_WKUP3
            @arg @ref MD_SYSCFG_WKEG_WKUP2
            @arg @ref MD_SYSCFG_WKEG_WKUP1
            @arg @ref MD_SYSCFG_WKEG_WKUP0
   * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_wakeup_edge_falling(SYSCFG_TypeDef *syscfg, uint32_t wkeg)
{
    CLEAR_BIT(syscfg->WKUP, wkeg << SYSCFG_WKUP_WKEG_POSS);
}

/**
  * @brief  Get Wake-up event rising edge or falling edge mode
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_WKEG_USBDP
            @arg @ref MD_SYSCFG_WKEG_USBDM
            @arg @ref MD_SYSCFG_WKEG_RTC
            @arg @ref MD_SYSCFG_WKEG_IWDT
            @arg @ref MD_SYSCFG_WKEG_LVD
            @arg @ref MD_SYSCFG_WKEG_NRST
            @arg @ref MD_SYSCFG_WKEG_WKUP7
            @arg @ref MD_SYSCFG_WKEG_WKUP6
            @arg @ref MD_SYSCFG_WKEG_WKUP5
            @arg @ref MD_SYSCFG_WKEG_WKUP4
            @arg @ref MD_SYSCFG_WKEG_WKUP3
            @arg @ref MD_SYSCFG_WKEG_WKUP2
            @arg @ref MD_SYSCFG_WKEG_WKUP1
            @arg @ref MD_SYSCFG_WKEG_WKUP0
  *         @arg 0x1 : rising edge enable
  *         @arg 0x0 : falling edge enable
  */
__STATIC_INLINE uint32_t md_syscfg_get_wakeup_edge(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->WKUP, SYSCFG_WKUP_WKEG) >> SYSCFG_WKUP_WKEG_POSS);
}

/**
  * @brief  Wake-up event rising edge is enabled
  * @param  syscfg SYSCFG Instance
            @arg @ref MD_SYSCFG_WKEG_USBDP
            @arg @ref MD_SYSCFG_WKEG_USBDM
            @arg @ref MD_SYSCFG_WKEG_RTC
            @arg @ref MD_SYSCFG_WKEG_IWDT
            @arg @ref MD_SYSCFG_WKEG_LVD
            @arg @ref MD_SYSCFG_WKEG_NRST
            @arg @ref MD_SYSCFG_WKEG_WKUP7
            @arg @ref MD_SYSCFG_WKEG_WKUP6
            @arg @ref MD_SYSCFG_WKEG_WKUP5
            @arg @ref MD_SYSCFG_WKEG_WKUP4
            @arg @ref MD_SYSCFG_WKEG_WKUP3
            @arg @ref MD_SYSCFG_WKEG_WKUP2
            @arg @ref MD_SYSCFG_WKEG_WKUP1
            @arg @ref MD_SYSCFG_WKEG_WKUP0
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : rising edge enable
  *         @arg 0x0 : falling edge enable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_wakeup_edge_rising(SYSCFG_TypeDef *syscfg, uint32_t wkeg)
{
    return (READ_BIT(syscfg->WKUP, wkeg << SYSCFG_WKUP_WKEG_POSS) == (wkeg << SYSCFG_WKUP_WKEG_POSS));
}

/**
  * @brief  Wake-up event falling edge is enabled
  * @param  syscfg SYSCFG Instance
            The retval can be one of the following values:
            @arg @ref MD_SYSCFG_WKEG_USBDP
            @arg @ref MD_SYSCFG_WKEG_USBDM
            @arg @ref MD_SYSCFG_WKEG_RTC
            @arg @ref MD_SYSCFG_WKEG_IWDT
            @arg @ref MD_SYSCFG_WKEG_LVD
            @arg @ref MD_SYSCFG_WKEG_NRST
            @arg @ref MD_SYSCFG_WKEG_WKUP7
            @arg @ref MD_SYSCFG_WKEG_WKUP6
            @arg @ref MD_SYSCFG_WKEG_WKUP5
            @arg @ref MD_SYSCFG_WKEG_WKUP4
            @arg @ref MD_SYSCFG_WKEG_WKUP3
            @arg @ref MD_SYSCFG_WKEG_WKUP2
            @arg @ref MD_SYSCFG_WKEG_WKUP1
            @arg @ref MD_SYSCFG_WKEG_WKUP0
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : falling edge enable
  *         @arg 0x0 : rising edge enable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_wakeup_edge_falling(SYSCFG_TypeDef *syscfg, uint32_t wkeg)
{
    return (READ_BIT(syscfg->WKUP, wkeg << SYSCFG_WKUP_WKEG_POSS) == 0);
}

/**
  * @brief  Enable Wake-up pin or wake-up event switch
  * @param  syscfg SYSCFG Instance
  * @param  wken Wake-up pin or wake-up event switch
            @arg @ref MD_SYSCFG_WKEN_USBDP
            @arg @ref MD_SYSCFG_WKEN_USBDM
            @arg @ref MD_SYSCFG_WKEN_RTC
            @arg @ref MD_SYSCFG_WKEN_IWDT
            @arg @ref MD_SYSCFG_WKEN_LVD
            @arg @ref MD_SYSCFG_WKEN_NRST
            @arg @ref MD_SYSCFG_WKEN_WKUP7
            @arg @ref MD_SYSCFG_WKEN_WKUP6
            @arg @ref MD_SYSCFG_WKEN_WKUP5
            @arg @ref MD_SYSCFG_WKEN_WKUP4
            @arg @ref MD_SYSCFG_WKEN_WKUP3
            @arg @ref MD_SYSCFG_WKEN_WKUP2
            @arg @ref MD_SYSCFG_WKEN_WKUP1
            @arg @ref MD_SYSCFG_WKEN_WKUP0
  * @retval None
  */
__STATIC_INLINE void md_syscfg_enable_wakeup(SYSCFG_TypeDef *syscfg, uint32_t wken)
{
    SET_BIT(syscfg->WKUP, wken);
}

/**
  * @brief  disable Wake-up pin or wake-up event switch
  * @param  syscfg SYSCFG Instance
  * @param  wken Wake-up pin or wake-up event switch
            @arg @ref MD_SYSCFG_WKEN_USBDP
            @arg @ref MD_SYSCFG_WKEN_USBDM
            @arg @ref MD_SYSCFG_WKEN_RTC
            @arg @ref MD_SYSCFG_WKEN_IWDT
            @arg @ref MD_SYSCFG_WKEN_LVD
            @arg @ref MD_SYSCFG_WKEN_NRST
            @arg @ref MD_SYSCFG_WKEN_WKUP7
            @arg @ref MD_SYSCFG_WKEN_WKUP6
            @arg @ref MD_SYSCFG_WKEN_WKUP5
            @arg @ref MD_SYSCFG_WKEN_WKUP4
            @arg @ref MD_SYSCFG_WKEN_WKUP3
            @arg @ref MD_SYSCFG_WKEN_WKUP2
            @arg @ref MD_SYSCFG_WKEN_WKUP1
            @arg @ref MD_SYSCFG_WKEN_WKUP0
  * @retval None
  */
__STATIC_INLINE void md_syscfg_disable_wakeup(SYSCFG_TypeDef *syscfg, uint32_t wken)
{
    CLEAR_BIT(syscfg->WKUP, wken);
}

/**
  * @brief  Wake-up pin or wake-up event switch is enabled
  * @param  syscfg SYSCFG Instance
  * @param  wken Wake-up pin or wake-up event switch
            @arg @ref MD_SYSCFG_WKEN_USBDP
            @arg @ref MD_SYSCFG_WKEN_USBDM
            @arg @ref MD_SYSCFG_WKEN_RTC
            @arg @ref MD_SYSCFG_WKEN_IWDT
            @arg @ref MD_SYSCFG_WKEN_LVD
            @arg @ref MD_SYSCFG_WKEN_NRST
            @arg @ref MD_SYSCFG_WKEN_WKUP7
            @arg @ref MD_SYSCFG_WKEN_WKUP6
            @arg @ref MD_SYSCFG_WKEN_WKUP5
            @arg @ref MD_SYSCFG_WKEN_WKUP4
            @arg @ref MD_SYSCFG_WKEN_WKUP3
            @arg @ref MD_SYSCFG_WKEN_WKUP2
            @arg @ref MD_SYSCFG_WKEN_WKUP1
            @arg @ref MD_SYSCFG_WKEN_WKUP0
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : wakeup event enable
  *         @arg 0x0 : wakeup event disable
  */
__STATIC_INLINE uint32_t md_syscfg_is_enabled_wakeup(SYSCFG_TypeDef *syscfg, uint32_t wken)
{
    return (READ_BIT(syscfg->WKUP, wken) == wken);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group20 WKSR
  * @{
  */
/**
  * @brief  Set SYSCFG_WKSR register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_wksr(SYSCFG_TypeDef *syscfg, uint32_t wksr)
{
    WRITE_REG(syscfg->WKSR, wksr);
}

/**
  * @brief  Get SYSCFG_WKSR Register
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_syscfg_get_wksr(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->WKSR));
}


/**
  * @brief  Clear the wake-up flag
  * @param  syscfg SYSCFG Instance
  * @retval None
  */
__STATIC_INLINE void md_syscfg_clear_flag_wakeup(SYSCFG_TypeDef *syscfg)
{
    SET_BIT(syscfg->WKSR, SYSCFG_WKSR_WKCLR);
}

/**
  * @brief  Set Low power mode selection
  * @param  syscfg SYSCFG Instance
  * @param  lpls Low power mode selection
            @arg @ref MD_SYSCFG_LPLS_STOP_MODE
            @arg @ref MD_SYSCFG_LPLS_STANDBY0_MODE
            @arg @ref MD_SYSCFG_LPLS_STANDBY1_MODE
            @arg @ref MD_SYSCFG_LPLS_SHUTDOWN_MODE
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_lowpower_mode(SYSCFG_TypeDef *syscfg, uint32_t lpls)
{
    MODIFY_REG(syscfg->WKSR, SYSCFG_WKSR_LPLS, lpls << SYSCFG_WKSR_LPLS_POSS);
}

/**
  * @brief  Get Low power mode selection
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_LPLS_STOP_MODE
            @arg @ref MD_SYSCFG_LPLS_STANDBY0_MODE
            @arg @ref MD_SYSCFG_LPLS_STANDBY1_MODE
            @arg @ref MD_SYSCFG_LPLS_SHUTDOWN_MODE
  */
__STATIC_INLINE uint32_t md_syscfg_get_lowpower_mode(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->WKSR, SYSCFG_WKSR_LPLS) >> SYSCFG_WKSR_LPLS_POSS);
}

/**
  * @brief  Get Wake flag
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg 0x1 : wakeup flag exist
  *         @arg 0x0 : wakeup flag non-existent
  */
__STATIC_INLINE uint32_t md_syscfg_is_active_flag_wakeup(SYSCFG_TypeDef *syscfg)
{
    return (READ_BIT(syscfg->WKSR, SYSCFG_WKSR_FLAG) == (SYSCFG_WKSR_FLAG));
}

/**
  * @brief  Get Low-power mode wake-up flag
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_FG_USBDP
            @arg @ref MD_SYSCFG_FG_USBDM
            @arg @ref MD_SYSCFG_FG_RTC
            @arg @ref MD_SYSCFG_FG_IWDT
            @arg @ref MD_SYSCFG_FG_LVD
            @arg @ref MD_SYSCFG_FG_NRST
            @arg @ref MD_SYSCFG_FG_WKUP7
            @arg @ref MD_SYSCFG_FG_WKUP6
            @arg @ref MD_SYSCFG_FG_WKUP5
            @arg @ref MD_SYSCFG_FG_WKUP4
            @arg @ref MD_SYSCFG_FG_WKUP3
            @arg @ref MD_SYSCFG_FG_WKUP2
            @arg @ref MD_SYSCFG_FG_WKUP1
            @arg @ref MD_SYSCFG_FG_WKUP0
  */
__STATIC_INLINE uint32_t md_syscfg_get_wakeup_event(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_BIT(syscfg->WKSR, SYSCFG_WKSR_FG) >> SYSCFG_WKSR_FG_POSS);
}

/**
  * @brief  Get Low-power mode wake-up flag
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
            @arg @ref MD_SYSCFG_FG_USBDP
            @arg @ref MD_SYSCFG_FG_USBDM
            @arg @ref MD_SYSCFG_FG_RTC
            @arg @ref MD_SYSCFG_FG_IWDT
            @arg @ref MD_SYSCFG_FG_LVD
            @arg @ref MD_SYSCFG_FG_NRST
            @arg @ref MD_SYSCFG_FG_WKUP7
            @arg @ref MD_SYSCFG_FG_WKUP6
            @arg @ref MD_SYSCFG_FG_WKUP5
            @arg @ref MD_SYSCFG_FG_WKUP4
            @arg @ref MD_SYSCFG_FG_WKUP3
            @arg @ref MD_SYSCFG_FG_WKUP2
            @arg @ref MD_SYSCFG_FG_WKUP1
            @arg @ref MD_SYSCFG_FG_WKUP0
  */
__STATIC_INLINE uint32_t md_syscfg_is_active_flag_wakeup_event(SYSCFG_TypeDef *syscfg, uint32_t wkfg)
{
    return (READ_BIT(syscfg->WKSR, wkfg) == wkfg);
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group21 BKREG0
  * @{
  */
/**
  * @brief  Set Backup Register 0.
  * @note   This field was saved in the always on block, reset by power reset.
  * @param  syscfg SYSCFG Instance
  * @param  bkreg0 This parameter can be one of the following values:
  *         @arg Max Value 0xFFFFFFFF
  *         @arg Min Value 0
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_bkreg0(SYSCFG_TypeDef *syscfg, uint32_t bkreg0)
{
    WRITE_REG(syscfg->BKREG0, bkreg0);
}
/**
  * @brief  Get Backup Register 0.
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xFFFFFFFF
  *         @arg Min Value 0
  */
__STATIC_INLINE uint32_t md_syscfg_get_bkreg0(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->BKREG0));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group22 BKREG1
  * @{
  */
/**
  * @brief  Set Backup Register 1.
  * @note   This field was saved in the always on block, reset by power reset.
  * @param  syscfg SYSCFG Instance
  * @param  bkreg1 This parameter can be one of the following values:
  *         @arg Max Value 0xFFFFFFFF
  *         @arg Min Value 0
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_bkreg1(SYSCFG_TypeDef *syscfg, uint32_t bkreg1)
{
    WRITE_REG(syscfg->BKREG1, bkreg1);
}
/**
  * @brief  Get Backup Register 1.
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xFFFFFFFF
  *         @arg Min Value 0
  */
__STATIC_INLINE uint32_t md_syscfg_get_bkreg1(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->BKREG1));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group23 BKREG2
  * @{
  */
/**
  * @brief  Set Backup Register 2.
  * @note   This field was saved in the always on block, reset by power reset.
  * @param  syscfg SYSCFG Instance
  * @param  bkreg2 This parameter can be one of the following values:
  *         @arg Max Value 0xFFFFFFFF
  *         @arg Min Value 0
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_bkreg2(SYSCFG_TypeDef *syscfg, uint32_t bkreg2)
{
    WRITE_REG(syscfg->BKREG2, bkreg2);
}
/**
  * @brief  Get Backup Register 2.
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xFFFFFFFF
  *         @arg Min Value 0
  */
__STATIC_INLINE uint32_t md_syscfg_get_bkreg2(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->BKREG2));
}
/**
  * @}
  */

/** @defgroup MD_SYSCFG_Public_Functions_Group24 BKREG3
  * @{
  */
/**
  * @brief  Set Backup Register 3.
  * @note   This field was saved in the always on block, reset by power reset.
  * @param  syscfg SYSCFG Instance
  * @param  bkreg3 This parameter can be one of the following values:
  *         @arg Max Value 0xFFFFFFFF
  *         @arg Min Value 0
  * @retval None
  */
__STATIC_INLINE void md_syscfg_set_bkreg3(SYSCFG_TypeDef *syscfg, uint32_t bkreg3)
{
    WRITE_REG(syscfg->BKREG3, bkreg3);
}
/**
  * @brief  Get Backup Register 3.
  * @param  syscfg SYSCFG Instance
  * @retval The retval can be one of the following values:
  *         @arg Max Value 0xFFFFFFFF
  *         @arg Min Value 0
  */
__STATIC_INLINE uint32_t md_syscfg_get_bkreg3(SYSCFG_TypeDef *syscfg)
{
    return (uint32_t)(READ_REG(syscfg->BKREG3));
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
  * @}  Micro_Driver
  */

#ifdef __cplusplus
}
#endif
#endif

/******************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

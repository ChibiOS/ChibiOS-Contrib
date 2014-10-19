/*
    ChibiOS/HAL - Copyright (C) 2006-2014 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
/*
   Concepts and parts of this file have been contributed by Uladzimir Pylinsky
   aka barthess (SDRAM routines added by Nick Klimov aka progfin).
 */

/**
 * @file    fsmc_sdram.h
 * @brief   SDRAM Driver subsystem low level driver header.
 *
 * @addtogroup SDRAM
 * @{
 */

#ifndef _FMC_SDRAM_H_
#define _FMC_SDRAM_H_

#if (defined(STM32F427xx) || defined(STM32F437xx) || \
     defined(STM32F429xx) || defined(STM32F439xx))

#include "fsmc.h"

#if STM32_USE_FSMC_SDRAM || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/** @defgroup FMC_ColumnBits_Number
  * @{
  */
#define FMC_ColumnBits_Number_8b           ((uint32_t)0x00000000)
#define FMC_ColumnBits_Number_9b           ((uint32_t)0x00000001)
#define FMC_ColumnBits_Number_10b          ((uint32_t)0x00000002)
#define FMC_ColumnBits_Number_11b          ((uint32_t)0x00000003)

#define IS_FMC_COLUMNBITS_NUMBER(COLUMN) \
    (((COLUMN) == FMC_ColumnBits_Number_8b)  || \
    ((COLUMN) == FMC_ColumnBits_Number_9b)  || \
    ((COLUMN) == FMC_ColumnBits_Number_10b) || \
    ((COLUMN) == FMC_ColumnBits_Number_11b))

/**
  * @}
  */

/** @defgroup FMC_RowBits_Number
  * @{
  */
#define FMC_RowBits_Number_11b             ((uint32_t)0x00000000)
#define FMC_RowBits_Number_12b             ((uint32_t)0x00000004)
#define FMC_RowBits_Number_13b             ((uint32_t)0x00000008)

#define IS_FMC_ROWBITS_NUMBER(ROW) \
    (((ROW) == FMC_RowBits_Number_11b) || \
    ((ROW) == FMC_RowBits_Number_12b) || \
    ((ROW) == FMC_RowBits_Number_13b))

/**
  * @}
  */

/** @defgroup FMC_SDMemory_Data_Width
  * @{
  */
#define FMC_SDMemory_Width_8b                ((uint32_t)0x00000000)
#define FMC_SDMemory_Width_16b               ((uint32_t)0x00000010)
#define FMC_SDMemory_Width_32b               ((uint32_t)0x00000020)

#define IS_FMC_SDMEMORY_WIDTH(WIDTH) \
    (((WIDTH) == FMC_SDMemory_Width_8b)  || \
    ((WIDTH) == FMC_SDMemory_Width_16b) || \
    ((WIDTH) == FMC_SDMemory_Width_32b))

/**
  * @}
  */

/** @defgroup FMC_InternalBank_Number
  * @{
  */
#define FMC_InternalBank_Number_2          ((uint32_t)0x00000000)
#define FMC_InternalBank_Number_4          ((uint32_t)0x00000040)

#define IS_FMC_INTERNALBANK_NUMBER(NUMBER) \
    (((NUMBER) == FMC_InternalBank_Number_2) || \
    ((NUMBER) == FMC_InternalBank_Number_4))

/**
  * @}
  */


/** @defgroup FMC_CAS_Latency
  * @{
  */
#define FMC_CAS_Latency_1                  ((uint32_t)0x00000080)
#define FMC_CAS_Latency_2                  ((uint32_t)0x00000100)
#define FMC_CAS_Latency_3                  ((uint32_t)0x00000180)

#define IS_FMC_CAS_LATENCY(LATENCY) \
    (((LATENCY) == FMC_CAS_Latency_1) || \
    ((LATENCY) == FMC_CAS_Latency_2) || \
    ((LATENCY) == FMC_CAS_Latency_3))

/**
  * @}
  */

/** @defgroup FMC_Write_Protection
  * @{
  */
#define FMC_Write_Protection_Disable       ((uint32_t)0x00000000)
#define FMC_Write_Protection_Enable        ((uint32_t)0x00000200)

#define IS_FMC_WRITE_PROTECTION(WRITE) \
    (((WRITE) == FMC_Write_Protection_Disable) || \
    ((WRITE) == FMC_Write_Protection_Enable))

/**
  * @}
  */


/** @defgroup FMC_SDClock_Period
  * @{
  */
#define FMC_SDClock_Disable                ((uint32_t)0x00000000)
#define FMC_SDClock_Period_2               ((uint32_t)0x00000800)
#define FMC_SDClock_Period_3               ((uint32_t)0x00000C00)
#define FMC_SDClock_Period_Mask            ((uint32_t)0x00000C00)

#define IS_FMC_SDCLOCK_PERIOD(PERIOD) \
    (((PERIOD) == FMC_SDClock_Disable) || \
    ((PERIOD) == FMC_SDClock_Period_2) || \
    ((PERIOD) == FMC_SDClock_Period_3))

/**
  * @}
  */

/** @defgroup FMC_Read_Burst
  * @{
  */
#define FMC_Read_Burst_Disable             ((uint32_t)0x00000000)
#define FMC_Read_Burst_Enable              ((uint32_t)0x00001000)
#define FMC_Read_Burst_Mask                ((uint32_t)0x00001000)

#define IS_FMC_READ_BURST(RBURST) \
    (((RBURST) == FMC_Read_Burst_Disable) || \
    ((RBURST) == FMC_Read_Burst_Enable))

/**
  * @}
  */

/** @defgroup FMC_ReadPipe_Delay
  * @{
  */
#define FMC_ReadPipe_Delay_0               ((uint32_t)0x00000000)
#define FMC_ReadPipe_Delay_1               ((uint32_t)0x00002000)
#define FMC_ReadPipe_Delay_2               ((uint32_t)0x00004000)
#define FMC_ReadPipe_Delay_Mask            ((uint32_t)0x00006000)

#define IS_FMC_READPIPE_DELAY(DELAY) \
    (((DELAY) == FMC_ReadPipe_Delay_0) || \
    ((DELAY) == FMC_ReadPipe_Delay_1) || \
    ((DELAY) == FMC_ReadPipe_Delay_2))

/**
  * @}
  */

/** @defgroup FMC_Command_Mode
  * @{
  */
#define FMC_Command_Mode_normal            ((uint32_t)0x00000000)
#define FMC_Command_Mode_CLK_Enabled       ((uint32_t)0x00000001)
#define FMC_Command_Mode_PALL              ((uint32_t)0x00000002)
#define FMC_Command_Mode_AutoRefresh       ((uint32_t)0x00000003)
#define FMC_Command_Mode_LoadMode          ((uint32_t)0x00000004)
#define FMC_Command_Mode_Selfrefresh       ((uint32_t)0x00000005)
#define FMC_Command_Mode_PowerDown         ((uint32_t)0x00000006)

#define IS_FMC_COMMAND_MODE(COMMAND) \
    (((COMMAND) == FMC_Command_Mode_normal)      || \
    ((COMMAND) == FMC_Command_Mode_CLK_Enabled) || \
    ((COMMAND) == FMC_Command_Mode_PALL)        || \
    ((COMMAND) == FMC_Command_Mode_AutoRefresh) || \
    ((COMMAND) == FMC_Command_Mode_LoadMode)    || \
    ((COMMAND) == FMC_Command_Mode_Selfrefresh) || \
    ((COMMAND) == FMC_Command_Mode_PowerDown))

/**
  * @}
  */

/** @defgroup FMC_Command_Target
  * @{
  */
#define FMC_Command_Target_bank2           ((uint32_t)0x00000008)
#define FMC_Command_Target_bank1           ((uint32_t)0x00000010)
#define FMC_Command_Target_bank1_2         ((uint32_t)0x00000018)

#define IS_FMC_COMMAND_TARGET(TARGET) \
    (((TARGET) == FMC_Command_Target_bank1) || \
    ((TARGET) == FMC_Command_Target_bank2) || \
    ((TARGET) == FMC_Command_Target_bank1_2))

/**
  * @}
  */   
  
/** @defgroup FMC_AutoRefresh_Number
  * @{
  */  
#define IS_FMC_AUTOREFRESH_NUMBER(NUMBER) (((NUMBER) > 0) && ((NUMBER) <= 16))

/**
  * @}
  */

/** @defgroup FMC_ModeRegister_Definition
  * @{
  */
#define IS_FMC_MODE_REGISTER(CONTENT) ((CONTENT) <= 8191)

/**
  * @}
  */


/**
  * @brief  FMC SDRAM Mode definition register defines
  */
#define FMC_SDCMR_MRD_BURST_LENGTH_1             ((uint16_t)0x0000)
#define FMC_SDCMR_MRD_BURST_LENGTH_2             ((uint16_t)0x0001)
#define FMC_SDCMR_MRD_BURST_LENGTH_4             ((uint16_t)0x0002)
#define FMC_SDCMR_MRD_BURST_LENGTH_8             ((uint16_t)0x0004)
#define FMC_SDCMR_MRD_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define FMC_SDCMR_MRD_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define FMC_SDCMR_MRD_CAS_LATENCY_2              ((uint16_t)0x0020)
#define FMC_SDCMR_MRD_CAS_LATENCY_3              ((uint16_t)0x0030)
#define FMC_SDCMR_MRD_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define FMC_SDCMR_MRD_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000) 
#define FMC_SDCMR_MRD_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)      


#define FMC_RowCycleDelay_Mask             ((uint16_t)0x0000000F << 12)
#define FMC_RPDelay_Mask                   ((uint16_t)0x0000000F << 20)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/
/**
 * @name    Configuration options
 * @{
 */

/**
 * @brief   SDRAM driver enable switch.
 * @details If set to @p TRUE the support for SDRAM1 is included.
 */
#if !defined(STM32_SDRAM_USE_FSMC_SDRAM1) || defined(__DOXYGEN__)
#define STM32_SDRAM_USE_FSMC_SDRAM1                  FALSE
#else
#define STM32_SDRAM1_MAP_BASE                        FSMC_Bank5_MAP_BASE
#endif

/**
 * @brief   SDRAM driver enable switch.
 * @details If set to @p TRUE the support for SDRAM2 is included.
 */
#if !defined(STM32_SDRAM_USE_FSMC_SDRAM2) || defined(__DOXYGEN__)
#define STM32_SDRAM_USE_FSMC_SDRAM2                  FALSE
#else
#define STM32_SDRAM2_MAP_BASE                        FSMC_Bank6_MAP_BASE
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !STM32_SDRAM_USE_FSMC_SDRAM1 && !STM32_SDRAM_USE_FSMC_SDRAM2
#error "SDRAM driver activated but no SDRAM peripheral assigned"
#endif

#if (STM32_SDRAM_USE_FSMC_SDRAM1 || STM32_SDRAM_USE_FSMC_SDRAM2) && !STM32_HAS_FSMC
#error "FMC not present in the selected device"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
/**
 * @brief   Driver state machine possible states.
 */
typedef enum {
  SDRAM_UNINIT = 0,                   /**< Not initialized.                */
  SDRAM_STOP = 1,                     /**< Stopped.                        */
  SDRAM_READY = 2,                    /**< Ready.                          */
} sdramstate_t;

/**
 * @brief   Type of a structure representing an SDRAM driver.
 */
typedef struct SDRAMDriver SDRAMDriver;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  uint32_t                  sdcr;
  uint32_t                  sdtr;
} SDRAMConfig;

/**
 * @brief   Structure representing an SDRAM driver.
 */
struct SDRAMDriver {
  /**
   * @brief   Driver state.
   */
  sdramstate_t              state;
  /**
   * @brief     Pointer to the FMC SDRAM registers block.
   */
  FSMC_SDRAM_TypeDef     *sdram;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if STM32_SDRAM_USE_FSMC_SDRAM1 && !defined(__DOXYGEN__)
extern SDRAMDriver SDRAMD1;
#endif

#if STM32_SDRAM_USE_FSMC_SDRAM2 && !defined(__DOXYGEN__)
extern SDRAMDriver SDRAMD2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void fsmcSdramInit(void);
  void fsmcSdramStart(SDRAMDriver *sdramp, const SDRAMConfig *cfgp);
  void fsmcSdramStop(SDRAMDriver *sdramp);
  void fsmcSdram_WaitReady(void);
  void fsmcSdram_WriteProtectionConfig(SDRAMDriver *sdramp, int State);
#ifdef __cplusplus
}
#endif

#endif /* STM32_USE_FSMC_SDRAM */

#endif /* STM32F427xx / STM32F429xx / STM32F437xx / STM32F439xx */

#endif /* _FMC_SDRAM_H_ */

/** @} */

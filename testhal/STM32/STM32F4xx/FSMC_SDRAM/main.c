/*
    ChibiOS/RT - Copyright (C) 2006-2014 Giovanni Di Sirio

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
   aka barthess.
 */

/*
TODO:
write memtest function using ideas from http://www.memtest86.com/technical.htm
*/

#include "ch.h"
#include "hal.h"

#include "string.h"

#include "fsmc_sdram.h"

/*
 ******************************************************************************
 * DEFINES
 ******************************************************************************
 */
#define USE_INFINITE_MEMTEST        FALSE

/*
 *  FMC SDRAM Mode definition register defines
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

/*
 * FMC_ReadPipe_Delay
 */
#define FMC_ReadPipe_Delay_0               ((uint32_t)0x00000000)
#define FMC_ReadPipe_Delay_1               ((uint32_t)0x00002000)
#define FMC_ReadPipe_Delay_2               ((uint32_t)0x00004000)
#define FMC_ReadPipe_Delay_Mask            ((uint32_t)0x00006000)

/*
 * FMC_Read_Burst
 */
#define FMC_Read_Burst_Disable             ((uint32_t)0x00000000)
#define FMC_Read_Burst_Enable              ((uint32_t)0x00001000)
#define FMC_Read_Burst_Mask                ((uint32_t)0x00001000)

/*
 * FMC_SDClock_Period
 */
#define FMC_SDClock_Disable                ((uint32_t)0x00000000)
#define FMC_SDClock_Period_2               ((uint32_t)0x00000800)
#define FMC_SDClock_Period_3               ((uint32_t)0x00000C00)
#define FMC_SDClock_Period_Mask            ((uint32_t)0x00000C00)

/*
 * FMC_ColumnBits_Number
 */
#define FMC_ColumnBits_Number_8b           ((uint32_t)0x00000000)
#define FMC_ColumnBits_Number_9b           ((uint32_t)0x00000001)
#define FMC_ColumnBits_Number_10b          ((uint32_t)0x00000002)
#define FMC_ColumnBits_Number_11b          ((uint32_t)0x00000003)

/*
 * FMC_RowBits_Number
 */
#define FMC_RowBits_Number_11b             ((uint32_t)0x00000000)
#define FMC_RowBits_Number_12b             ((uint32_t)0x00000004)
#define FMC_RowBits_Number_13b             ((uint32_t)0x00000008)

/*
 * FMC_SDMemory_Data_Width
 */
#define FMC_SDMemory_Width_8b                ((uint32_t)0x00000000)
#define FMC_SDMemory_Width_16b               ((uint32_t)0x00000010)
#define FMC_SDMemory_Width_32b               ((uint32_t)0x00000020)

/*
 * FMC_InternalBank_Number
 */
#define FMC_InternalBank_Number_2          ((uint32_t)0x00000000)
#define FMC_InternalBank_Number_4          ((uint32_t)0x00000040)

/*
 * FMC_CAS_Latency
 */
#define FMC_CAS_Latency_1                  ((uint32_t)0x00000080)
#define FMC_CAS_Latency_2                  ((uint32_t)0x00000100)
#define FMC_CAS_Latency_3                  ((uint32_t)0x00000180)

/*
 * FMC_Write_Protection
 */
#define FMC_Write_Protection_Disable       ((uint32_t)0x00000000)
#define FMC_Write_Protection_Enable        ((uint32_t)0x00000200)

/*
 ******************************************************************************
 * EXTERNS
 ******************************************************************************
 */

/*
 ******************************************************************************
 * PROTOTYPES
 ******************************************************************************
 */

/*
 ******************************************************************************
 * GLOBAL VARIABLES
 ******************************************************************************
 */
static uint32_t extram_check_buf[16 * 1024];
static uint32_t *extram_start = (uint32_t *)STM32_SDRAM1_MAP_BASE;
static const size_t extram_size = 1024*1024;

/*
 * SDRAM driver configuration structure.
 */
static const SDRAMConfig sdram_cfg = {
  .sdcr = (uint32_t) FMC_ColumnBits_Number_9b |
                     FMC_RowBits_Number_13b |
                     FMC_SDMemory_Width_16b |
                     FMC_InternalBank_Number_4 |
                     FMC_CAS_Latency_3 |
                     FMC_Write_Protection_Disable |
                     FMC_SDClock_Period_3 |
                     FMC_Read_Burst_Enable |
                     FMC_ReadPipe_Delay_1,
  .sdtr = (uint32_t) (2   - 1) | // FMC_LoadToActiveDelay = 2 (TMRD: 2 Clock cycles)
                     (7 <<  4) | // FMC_ExitSelfRefreshDelay = 7 (TXSR: min=70ns (7x11.11ns))
                     (4 <<  8) | // FMC_SelfRefreshTime = 4 (TRAS: min=42ns (4x11.11ns) max=120k (ns))
                     (7 << 12) | // FMC_RowCycleDelay = 7 (TRC:  min=70 (7x11.11ns))
                     (2 << 16) | // FMC_WriteRecoveryTime = 2 (TWR:  min=1+ 7ns (1+1x11.11ns))
                     (2 << 20) | // FMC_RPDelay = 2 (TRP:  20ns => 2x11.11ns)
                     (2 << 24),  // FMC_RCDDelay = 2 (TRCD: 20ns => 2x11.11ns)
  /* NRFS = 4-1*/
  .sdcmr = (3 << 5) | (FMC_SDCMR_MRD_BURST_LENGTH_2 |
                       FMC_SDCMR_MRD_BURST_TYPE_SEQUENTIAL |
                       FMC_SDCMR_MRD_CAS_LATENCY_3 |
                       FMC_SDCMR_MRD_OPERATING_MODE_STANDARD |
                       FMC_SDCMR_MRD_WRITEBURST_MODE_SINGLE) << 9,

  /* if (STM32_SYSCLK == 180000000) ->
     64ms/4096=15.625us
     15.625us*90MHz=1406-20=1386 */
  .sdrtr = 1386 << 1
};

/* benchmarking results in MiB/S */
double memset_speed_ext;
double memset_speed_int;
double memcpy_speed_ext2int;
double memcpy_speed_int2ext;

/*
 ******************************************************************************
 ******************************************************************************
 * LOCAL FUNCTIONS
 ******************************************************************************
 ******************************************************************************
 */
/**
 *
 */
static void extram_benchmark(void){

  size_t i=0;
  time_measurement_t mem_tmu;

  /* memset speed ext */
  chTMObjectInit(&mem_tmu);
  chTMStartMeasurementX(&mem_tmu);
  memset(extram_start, 0x55, extram_size);
  //memset(extram_start, 0x00, extram_size);
  chTMStopMeasurementX(&mem_tmu);
  memset_speed_ext = 1 / (mem_tmu.cumulative / (double)STM32_SYSCLK);

  /* memset speed int */
  chTMObjectInit(&mem_tmu);
  chTMStartMeasurementX(&mem_tmu);
  for (i=0; i<16; i++)
    memset(extram_check_buf, i, sizeof(extram_check_buf));
  chTMStopMeasurementX(&mem_tmu);
  memset_speed_int = 1 / (mem_tmu.cumulative / (double)STM32_SYSCLK);

  /* memcpy ext2int */
  chTMObjectInit(&mem_tmu);
  chTMStartMeasurementX(&mem_tmu);
  for (i=0; i<16; i++)
    memcpy(extram_check_buf, extram_start+ i * sizeof(extram_check_buf), sizeof(extram_check_buf));
  chTMStopMeasurementX(&mem_tmu);
  memcpy_speed_ext2int = 1 / (mem_tmu.cumulative / (double)STM32_SYSCLK);

  /* memcpy int2ext */
  chTMObjectInit(&mem_tmu);
  memset(extram_check_buf, 0xAA, sizeof(extram_check_buf));
  chTMStartMeasurementX(&mem_tmu);
  for (i=0; i<16; i++)
    memcpy(extram_start + i * sizeof(extram_check_buf), extram_check_buf, sizeof(extram_check_buf));
  chTMStopMeasurementX(&mem_tmu);
  memcpy_speed_int2ext = 1 / (mem_tmu.cumulative / (double)STM32_SYSCLK);
}

/**
 *
 */
#if USE_INFINITE_MEMTEST
static void memstest(void){
  while (true) {
    ;
  }
}
#endif /* USE_INFINITE_MEMTEST */

/*
 ******************************************************************************
 * EXPORTED FUNCTIONS
 ******************************************************************************
 */

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  fsmcSdramInit();
  fsmcSdramStart(&SDRAMD, &sdram_cfg);
  extram_benchmark();

#if USE_INFINITE_MEMTEST
  memtest();
#endif

  /*
   * Normal main() thread activity, in this demo it does nothing.
   */
  while (TRUE) {
    chThdSleepMilliseconds(500);
  }
}



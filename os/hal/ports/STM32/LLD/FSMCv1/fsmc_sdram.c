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
 * @file    fsmc_sdram.c
 * @brief   SDRAM Driver subsystem low level driver source.
 *
 * @addtogroup SDRAM
 * @{
 */

#include "hal.h"

#if (defined(STM32F427xx) || defined(STM32F437xx) || \
     defined(STM32F429xx) || defined(STM32F439xx))

#if STM32_USE_FSMC_SDRAM || defined(__DOXYGEN__)

#include "fsmc_sdram.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define SDCR2_DONTCARE_BITS (FMC_SDClock_Period_Mask | \
                             FMC_Read_Burst_Mask | \
                             FMC_ReadPipe_Delay_Mask)

#define SDTR2_DONTCARE_BITS (FMC_RowCycleDelay_Mask | FMC_RPDelay_Mask)

/*
 * FMC SDCRx write protection mask
 */
#define SDCR_WriteProtection_RESET ((uint32_t)0x00007DFF)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/
/**
 * @brief   SDRAM driver identifier.
 */
SDRAMDriver SDRAMD;

/*===========================================================================*/
/* Driver local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Wait until the SDRAM controller is ready.
 *
 * @notapi
 */
static void _sdram_wait_ready(void) {
  /* Wait until the SDRAM controller is ready */
  while (SDRAMD.sdram->SDSR & FMC_SDSR_BUSY);
}

/**
 * @brief   Executes the SDRAM memory initialization sequence.
 *
 * @param[in] sdramp         pointer to the @p SDRAMDriver object
 *
 * @notapi
 */
static void _sdram_init_sequence(void) {

  uint32_t tmp = 0;
  uint32_t command_target = 0;

#if STM32_SDRAM_USE_FSMC_SDRAM1
  command_target |= FMC_SDCMR_CTB1;
#endif
#if STM32_SDRAM_USE_FSMC_SDRAM2
  command_target |= FMC_SDCMR_CTB2;
#endif

  /* Step 3: Configure a clock configuration enable command.*/
  _sdram_wait_ready();
  SDRAMD.sdram->SDCMR = (uint32_t) FMC_Command_Mode_CLK_Enabled |
          command_target |
          ((1 -1) << 5) | // FMC_AutoRefreshNumber = 1
          (0 << 9);        // FMC_ModeRegisterDefinition = 0

  /* Step 4: Insert 10 ms delay.*/
  chSysPolledDelayX(MS2ST(10));

  /* Step 5: Configure a PALL (precharge all) command.*/
  _sdram_wait_ready();
  SDRAMD.sdram->SDCMR = (uint32_t) FMC_Command_Mode_PALL |
          command_target |
          ((1 -1) << 5) | // FMC_AutoRefreshNumber = 1
          (0 << 9);        // FMC_ModeRegisterDefinition = 0

  /* Step 6.1: Configure a Auto-Refresh command: send the first command.*/
  _sdram_wait_ready();
  SDRAMD.sdram->SDCMR = (uint32_t) FMC_Command_Mode_AutoRefresh |
          command_target |
          ((4 -1) << 5) | // FMC_AutoRefreshNumber = 4
          (0 << 9);        // FMC_ModeRegisterDefinition = 0

  /* Step 6.2: Send the second command.*/
  SDRAMD.sdram->SDCMR = (uint32_t) FMC_Command_Mode_AutoRefresh |
          command_target |
          ((4 -1) << 5) | // FMC_AutoRefreshNumber = 4
          (0 << 9);        // FMC_ModeRegisterDefinition = 0

  /* Step 7: Program the external memory mode register.*/
  _sdram_wait_ready();
  tmp = FMC_SDCMR_MRD_BURST_LENGTH_2 |
          FMC_SDCMR_MRD_BURST_TYPE_SEQUENTIAL |
          FMC_SDCMR_MRD_CAS_LATENCY_3 |
          FMC_SDCMR_MRD_OPERATING_MODE_STANDARD |
          FMC_SDCMR_MRD_WRITEBURST_MODE_SINGLE;
  SDRAMD.sdram->SDCMR = (uint32_t) FMC_Command_Mode_LoadMode |
          command_target |
          ((1 -1) << 5) | // FMC_AutoRefreshNumber = 1
          (tmp << 9);

  /* Step 8: Set clock.*/
  _sdram_wait_ready();
  // 64ms/4096=15.625us
#if (STM32_SYSCLK == 180000000)
  //15.625us*90MHz=1406-20=1386
  SDRAMD.sdram->SDRTR=1386<<1;
#elif (STM32_SYSCLK == 168000000)
  //15.625us*84MHz=1312-20=1292
  SDRAMD.sdram->SDRTR=1292<<1;
#else
  #error No refresh timings for this clock
#endif

  _sdram_wait_ready();
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SDRAM driver initialization.
 */
void fsmcSdramInit(void) {

  fsmc_init();

  SDRAMD.sdram = FSMCD1.sdram;
  SDRAMD.state = SDRAM_STOP;
}

/**
 * @brief   Configures and activates the SDRAM peripheral.
 *
 * @param[in] sdramp        pointer to the @p SDRAMDriver object
 * @param[in] cfgp          pointer to the @p SDRAMConfig object
 */
void fsmcSdramStart(SDRAMDriver *sdramp, const SDRAMConfig *cfgp) {

  if (FSMCD1.state == FSMC_STOP)
    fsmc_start(&FSMCD1);

  osalDbgAssert((sdramp->state == SDRAM_STOP) || (sdramp->state == SDRAM_READY),
              "SDRAM. Invalid state.");

  if (sdramp->state == SDRAM_STOP) {
#if STM32_SDRAM_USE_FSMC_SDRAM1
    sdramp->sdram->banks[0].SDCR = cfgp->sdcr1;
    sdramp->sdram->banks[0].SDTR = cfgp->sdtr1;
#endif
#if STM32_SDRAM_USE_FSMC_SDRAM2
    sdramp->sdram->banks[1].SDCR = cfgp->sdcr2;
    sdramp->sdram->banks[1].SDTR = cfgp->sdtr2;
#endif
    _sdram_init_sequence();

    sdramp->state = SDRAM_READY;
  }
}

/**
 * @brief   Deactivates the SDRAM peripheral.
 *
 * @param[in] sdramp         pointer to the @p SDRAMDriver object
 *
 * @notapi
 */
void fsmcSdramStop(SDRAMDriver *sdramp) {

  if (sdramp->state == SDRAM_READY) {
    sdramp->state = SDRAM_STOP;
  }
}

/**
 * @brief  Enables or disables write protection to the specified SDRAM Bank.
 * @param  SDRAM_Bank: Defines the FMC SDRAM bank. This parameter can be
 *                     FMC_Bank1_SDRAM or FMC_Bank2_SDRAM.
 * @param  NewState: new state of the write protection flag.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
//void fsmcSdram_WriteProtectionConfig(SDRAMDriver *sdramp, int state) {
//
//  if (state)
//    sdramp->sdram->SDCR |= FMC_Write_Protection_Enable;
//  else
//    sdramp->sdram->SDCR &= SDCR_WriteProtection_RESET;
//}

#endif /* STM32_USE_FSMC_SDRAM */

#endif /* STM32F427xx / STM32F429xx / STM32F437xx / STM32F439xx */

/** @} */


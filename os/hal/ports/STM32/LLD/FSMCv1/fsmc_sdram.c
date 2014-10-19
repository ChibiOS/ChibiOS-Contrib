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

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/
/**
 * @brief   SDRAM1 driver identifier.
 */
#if STM32_SDRAM_USE_FSMC_SDRAM1 || defined(__DOXYGEN__)
SDRAMDriver SDRAMD1;
#endif

/**
 * @brief   SDRAM2 driver identifier.
 */
#if STM32_SDRAM_USE_FSMC_SDRAM2 || defined(__DOXYGEN__)
SDRAMDriver SDRAMD2;
#endif

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
 * @brief   Executes the SDRAM memory initialization sequence.
 *
 * @param[in] sdramp         pointer to the @p SDRAMDriver object
 *
 * @notapi
 */
static void fsmcSdramInitSequence(uint32_t CommandTarget) {
  uint32_t tmpreg;
  /* Step 3 -----------------------------------------------------------------*/
  /* Wait until the SDRAM controller is ready */
  while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY);
  /* Configure a clock configuration enable command */
  FMC_Bank5_6->SDCMR = (uint32_t) FMC_Command_Mode_CLK_Enabled |
    CommandTarget | 
    ((1 -1) <<  5) | // FMC_AutoRefreshNumber = 1
    (0 << 9);        // FMC_ModeRegisterDefinition = 0
  /* Step 4 -----------------------------------------------------------------*/
  /* Insert 10 ms delay */
  chSysPolledDelayX(MS2ST(10));
  /* Step 5 -----------------------------------------------------------------*/
  /* Wait until the SDRAM controller is ready */
  while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY);
  /* Configure a PALL (precharge all) command */
  FMC_Bank5_6->SDCMR = (uint32_t) FMC_Command_Mode_PALL |
    CommandTarget |
    ((1 -1) <<  5) | // FMC_AutoRefreshNumber = 1
    (0 << 9);        // FMC_ModeRegisterDefinition = 0
  /* Step 6 -----------------------------------------------------------------*/
  /* Wait until the SDRAM controller is ready */
  while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY);
  /* Configure a Auto-Refresh command: Send the first command */
  FMC_Bank5_6->SDCMR = (uint32_t) FMC_Command_Mode_AutoRefresh |
    CommandTarget |
    ((4 -1) <<  5) | // FMC_AutoRefreshNumber = 4
    (0 << 9);        // FMC_ModeRegisterDefinition = 0
  /* Wait until the SDRAM controller is ready */
  while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY);
  /* Configure a Auto-Refresh command: Send the second command*/
  FMC_Bank5_6->SDCMR = (uint32_t) FMC_Command_Mode_AutoRefresh |
    CommandTarget |
    ((4 -1) <<  5) | // FMC_AutoRefreshNumber = 4
    (0 << 9);        // FMC_ModeRegisterDefinition = 0
  /* Step 7 -----------------------------------------------------------------*/
  /* Wait until the SDRAM controller is ready */
  while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY);
  /* Program the external memory mode register */
  tmpreg = FMC_SDCMR_MRD_BURST_LENGTH_2 |
    FMC_SDCMR_MRD_BURST_TYPE_SEQUENTIAL |
    FMC_SDCMR_MRD_CAS_LATENCY_3 |
    FMC_SDCMR_MRD_OPERATING_MODE_STANDARD |
    FMC_SDCMR_MRD_WRITEBURST_MODE_SINGLE;
  /* Send the command */
  FMC_Bank5_6->SDCMR = (uint32_t) FMC_Command_Mode_LoadMode |
    CommandTarget |
    ((1 -1) <<  5) | // FMC_AutoRefreshNumber = 1
    (tmpreg << 9);
  /* Step 8 -----------------------------------------------------------------*/
  /* Wait until the SDRAM controller is ready */
  while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY);
  // 64ms/4096=15.625us
#if (STM32_SYSCLK == 180000000)
  //15.625us*90MHz=1406-20=1386
  FMC_Bank5_6->SDRTR=1386<<1;
#elif (STM32_SYSCLK == 168000000)
  //15.625us*84MHz=1312-20=1292
  FMC_Bank5_6->SDRTR=1292<<1;
#else
  #error No refresh timings for this clock
#endif
  /* Wait until the SDRAM controller is ready */
  while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SDRAM driver initialization.
 *
 * @notapi
 */
void fsmcSdramInit(void) {

  fsmc_init();

#if STM32_SDRAM_USE_FSMC_SDRAM1
  SDRAMD1.sdram = FSMCD1.sdram1;
  SDRAMD1.state = SDRAM_STOP;
#endif /* STM32_SDRAM_USE_FSMC_SDRAM1 */

#if STM32_SDRAM_USE_FSMC_SDRAM2
  SDRAMD2.sdram = FSMCD1.sdram2;
  SDRAMD2.state = SDRAM_STOP;
#endif /* STM32_SDRAM_USE_FSMC_SDRAM2 */

}

/**
 * @brief   Configures and activates the SDRAM peripheral.
 *
 * @param[in] sdramp        pointer to the @p SDRAMDriver object
 * @param[in] cfgp          pointer to the @p SDRAMConfig object
 *
 * @notapi
 */
#define SDCR2_DONTCARE_BITS (FMC_SDClock_Period_Mask | \
                             FMC_Read_Burst_Mask | \
                             FMC_ReadPipe_Delay_Mask)
#define SDTR2_DONTCARE_BITS (FMC_RowCycleDelay_Mask | FMC_RPDelay_Mask)
void fsmcSdramStart(SDRAMDriver *sdramp, const SDRAMConfig *cfgp) {

  if (FSMCD1.state == FSMC_STOP)
    fsmc_start(&FSMCD1);

  osalDbgAssert((sdramp->state == SDRAM_STOP) || (sdramp->state == SDRAM_READY),
              "invalid state");

  if (sdramp->state == SDRAM_STOP) {
    // Executes the SDRAM memory initialization sequence.
    if (sdramp->sdram == (FSMC_SDRAM_TypeDef *)FSMC_Bank5_R_BASE) {
      sdramp->sdram->SDCR = cfgp->sdcr;
      sdramp->sdram->SDTR = cfgp->sdtr;
      fsmcSdramInitSequence(FMC_Command_Target_bank1);
    } else { /* SDCR2 "don't care" bits configuration */
      ((FSMC_SDRAM_TypeDef *)FSMC_Bank5_R_BASE)->SDCR = 
        cfgp->sdcr & SDCR2_DONTCARE_BITS;
      sdramp->sdram->SDCR = cfgp->sdcr;
      ((FSMC_SDRAM_TypeDef *)FSMC_Bank5_R_BASE)->SDTR = 
        cfgp->sdtr & SDTR2_DONTCARE_BITS;
      sdramp->sdram->SDTR = cfgp->sdtr;
      fsmcSdramInitSequence(FMC_Command_Target_bank2);
    }
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
 * @brief   Wait until the SDRAM controller is ready.
 *
 * @notapi
 */
void fsmcSdram_WaitReady(void) {
  /* Wait until the SDRAM controller is ready */
  while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY);
}

/**
  * @brief  Enables or disables write protection to the specified SDRAM Bank.
  * @param  SDRAM_Bank: Defines the FMC SDRAM bank. This parameter can be
  *                     FMC_Bank1_SDRAM or FMC_Bank2_SDRAM.
  * @param  NewState: new state of the write protection flag.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
/* FMC SDCRx write protection Mask*/
#define SDCR_WriteProtection_RESET ((uint32_t)0x00007DFF)
void fsmcSdram_WriteProtectionConfig(SDRAMDriver *sdramp, int State) {

  if (State)
    sdramp->sdram->SDCR |= FMC_Write_Protection_Enable;
  else
    sdramp->sdram->SDCR &= SDCR_WriteProtection_RESET;

}


#endif /* STM32_USE_FSMC_SDRAM */

#endif /* STM32F427xx / STM32F429xx / STM32F437xx / STM32F439xx */

/** @} */


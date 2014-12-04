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
   aka barthess.
 */

/**
 * @file    fsmc.c
 * @brief   FSMC Driver subsystem low level driver source template.
 *
 * @addtogroup FSMC
 * @{
 */
#include "hal.h"
#include "fsmc.h"

#if HAL_USE_NAND || STM32_USE_FSMC_SRAM || STM32_USE_FSMC_SDRAM || \
  defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   FSMC1 driver identifier.
 */
#if STM32_FSMC_USE_FSMC1 || defined(__DOXYGEN__)
FSMCDriver FSMCD1;
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

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level FSMC driver initialization.
 *
 * @notapi
 */
void fsmc_init(void) {

  if (FSMCD1.state == FSMC_UNINIT) {
    FSMCD1.state  = FSMC_STOP;

#if STM32_SRAM_USE_FSMC_SRAM1
    FSMCD1.sram1 = (FSMC_SRAM_NOR_TypeDef *)(FSMC_Bank1_R_BASE);
#endif

#if STM32_SRAM_USE_FSMC_SRAM2
    FSMCD1.sram2 = (FSMC_SRAM_NOR_TypeDef *)(FSMC_Bank1_R_BASE + 8);
#endif

#if STM32_SRAM_USE_FSMC_SRAM3
    FSMCD1.sram3 = (FSMC_SRAM_NOR_TypeDef *)(FSMC_Bank1_R_BASE + 8 * 2);
#endif

#if STM32_SRAM_USE_FSMC_SRAM4
    FSMCD1.sram4 = (FSMC_SRAM_NOR_TypeDef *)(FSMC_Bank1_R_BASE + 8 * 3);
#endif

#if STM32_NAND_USE_FSMC_NAND1
    FSMCD1.nand1 = (FSMC_NAND_TypeDef *)FSMC_Bank2_R_BASE;
#endif

#if STM32_NAND_USE_FSMC_NAND2
    FSMCD1.nand2 = (FSMC_NAND_TypeDef *)FSMC_Bank3_R_BASE;
#endif

#if STM32_USE_FSMC_PCCARD
    FSMCD1.pccard = (FSMC_PCCARD_TypeDef *)FSMC_Bank4_R_BASE;
#endif

#if (defined(STM32F427xx) || defined(STM32F437xx) || \
     defined(STM32F429xx) || defined(STM32F439xx))
  #if STM32_USE_FSMC_SDRAM
    FSMCD1.sdram = (FSMC_SDRAM_TypeDef *)FSMC_Bank5_6_R_BASE;
  #endif
#endif
  }
}

/**
 * @brief   Configures and activates the FSMC peripheral.
 *
 * @param[in] fsmcp      pointer to the @p FSMCDriver object
 *
 * @notapi
 */
void fsmc_start(FSMCDriver *fsmcp) {

  osalDbgAssert((fsmcp->state == FSMC_STOP) || (fsmcp->state == FSMC_READY),
              "invalid state");

  if (fsmcp->state == FSMC_STOP) {
    /* Enables the peripheral.*/
#if STM32_FSMC_USE_FSMC1
    if (&FSMCD1 == fsmcp) {
      rccResetFSMC();
      rccEnableFSMC(FALSE);
#if (!STM32_NAND_USE_EXT_INT && HAL_USE_NAND)
      nvicEnableVector(STM32_FSMC_NUMBER, STM32_FSMC_FSMC1_IRQ_PRIORITY);
#endif
    }
#endif /* STM32_FSMC_USE_FSMC1 */

    fsmcp->state = FSMC_READY;
  }
}

/**
 * @brief   Deactivates the FSMC peripheral.
 *
 * @param[in] emcp      pointer to the @p FSMCDriver object
 *
 * @notapi
 */
void fsmc_stop(FSMCDriver *fsmcp) {

  if (fsmcp->state == FSMC_READY) {
    /* Resets the peripheral.*/
    rccResetFSMC();

    /* Disables the peripheral.*/
#if STM32_FSMC_USE_FSMC1
    if (&FSMCD1 == fsmcp) {
#if (!STM32_NAND_USE_EXT_INT && HAL_USE_NAND)
      nvicDisableVector(STM32_FSMC_NUMBER);
#endif
      rccDisableFSMC(FALSE);
    }
#endif /* STM32_FSMC_USE_FSMC1 */

    fsmcp->state = FSMC_STOP;
  }
}

#if !STM32_NAND_USE_EXT_INT
/**
 * @brief   FSMC shared interrupt handler.
 *
 * @notapi
 */
CH_IRQ_HANDLER(STM32_FSMC_HANDLER) {

  CH_IRQ_PROLOGUE();
#if STM32_NAND_USE_FSMC_NAND1
  if (FSMCD1.nand1->SR & FSMC_SR_ISR_MASK){
    NANDD1.isr_handler(&NANDD1);
  }
#endif
#if STM32_NAND_USE_FSMC_NAND2
  if (FSMCD1.nand2->SR & FSMC_SR_ISR_MASK){
    NANDD2.isr_handler(&NANDD2);
  }
#endif
  CH_IRQ_EPILOGUE();
}
#endif /* !STM32_NAND_USE_EXT_INT */

#endif /* HAL_USE_FSMC || STM32_USE_FSMC_SRAM || STM32_USE_FSMC_SDRAM */

/** @} */

/*
    ChibiOS - Copyright (C) 2023 Xael South

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

/**
 * @file    SYSTICKv3/hal_st_lld.c
 * @brief   ST Driver subsystem low level driver code.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  #if EFR32_ST_USE_TIMER == 1
    #if (OSAL_ST_RESOLUTION == 32) && !EFR32_LETIM1_IS_32BITS
      #error "LETIM1 is not a 32 bit timer"
    #endif
  
    #if !EFR32_HAS_LETIM1
      #error "LETIM1 not present in the selected device"
    #endif

    #if EFR32_LETIM1SEL != EFR32_LETIM1SEL_LFXO && \
        EFR32_LETIM1SEL != EFR32_LETIM1SEL_LFRCO && \
        EFR32_LETIM1SEL != EFR32_LETIM1SEL_ULFRCO
      #error "EFR32_LETIM1SEL is neither EFR32_LETIM1SEL_LFXO nor EFR32_LETIM1SEL_LFRCO nor EFR32_LETIM1SEL_ULFRCO"
    #endif

    #define ST_HANDLER                    EFR32_LETIM1_HANDLER
    #define ST_NUMBER                     EFR32_LETIM1_NUMBER
    #define ST_CLOCK_SRC                  EFR32_LETIM1CLK
    #define ST_ENABLE_CLOCK()             CMU->LFACLKEN0 |= CMU_LFACLKEN0_LETIMER0
    #define ST_SET_PRESCALER()            CMU->LFAPRESC0 |= EFR32_ST_PRESC
  #else
    #error "EFR32_ST_USE_TIMER specifies an unsupported timer"
  #endif

  #if (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 32768U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV32768
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 16386U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV16384
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 8192U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV8192
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 4096U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV4096
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 2048U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV2048
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 1024U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV1024
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 512U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV512
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 256U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV256
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 128U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV128
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 64U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV64
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 32U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV32
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 16U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV16
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 8U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV8
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 4U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV4
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 2U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV2
  #elif (ST_CLOCK_SRC/OSAL_ST_FREQUENCY == 1U)
    #define EFR32_ST_PRESC    CMU_LFAPRESC0_LETIMER0_DIV1
  #else
    #error "EFR32_ST_PRESC is not obtainable"
  #endif
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  #error "OSAL_ST_MODE_PERIODIC is not supported by SYSTICKv3"
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

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


#if !defined(EFR32_SYSTICK_SUPPRESS_ISR)
/**
 * @brief   Interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(ST_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  st_lld_serve_interrupt();

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  /* Free running counter mode.*/
  osalDbgAssert((ST_CLOCK_SRC % OSAL_ST_FREQUENCY) == 0U,
                "clock rounding error");
  osalDbgAssert(((ST_CLOCK_SRC / OSAL_ST_FREQUENCY) - 1U) < 0x10000,
                "clock prescaler overflow");

  /* Enabling timer clock. */
  ST_ENABLE_CLOCK();

  /* Set prescaler. */
  ST_SET_PRESCALER();

  /* Enable timer. */
  EFR32_ST_TIM->EN_SET = LETIMER_EN_EN;

  /* Initializing the counter in free running mode. */
  EFR32_ST_TIM->IEN    = 0;
  EFR32_ST_TIM->IFC    = _LETIMER_IFC_MASK;
  EFR32_ST_TIM->CTRL   = LETIMER_CTRL_REPMODE_FREE;
  EFR32_ST_TIM->COMP0  = 0;

  /* Wait for command to complete. */
  while (EFR32_ST_TIM->SYNCBUSY & LETIMER_SYNCBUSY_CMD) {
  }

  /* Start timer on continuous mode. */
  EFR32_ST_TIM->CNT    = 0;
  EFR32_ST_TIM->CMD    = LETIMER_CMD_START;

#if !defined(EFR32_SYSTICK_SUPPRESS_ISR)
  /* IRQ enabled.*/
  nvicEnableVector(ST_NUMBER, EFR32_ST_IRQ_PRIORITY);
#endif
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  /* Periodic systick mode, the Cortex-Mx internal systick timer is used
     in this mode.*/

  /* IRQ enabled.*/
  nvicEnableVector(HANDLER_SYSTICK, EFR32_ST_IRQ_PRIORITY);
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */
}

/**
 * @brief   IRQ handling code.
 */
void st_lld_serve_interrupt(void) {

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  if ((EFR32_ST_TIM->IF & LETIMER_IF_COMP0) != 0U) {
    EFR32_ST_TIM->IFC = LETIMER_IFC_COMP0;
#endif
    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  }
#endif
}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

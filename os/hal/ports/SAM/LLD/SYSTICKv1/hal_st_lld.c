/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    hal_st_lld.c
 * @brief   PLATFORM ST subsystem low level driver source.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"
#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

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

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
static void st_lld_serve_interrupt(void);
/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void)
{
  /* Connect GENCLK to RTC */
  sam_gclk_mux(SAM_RTC_GCLK_SRC_ID, GCLK_CLKCTRL_ID_RTC, TRUE);

  PM_REGS->PM_APBAMASK |= PM_APBAMASK_RTC_Msk;
  /* Reset Peripheral before usage */
  RTC_REGS->MODE0.RTC_CTRL = RTC_MODE0_CTRL_SWRST_Msk;
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  /* Set to 32 */
  RTC_REGS->MODE0.RTC_CTRL = RTC_MODE0_CTRL_PRESCALER(SAM_RTC_DIV) | RTC_MODE0_CTRL_MODE_COUNT32;
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  nvicEnableVector(RTC_IRQn, SAM_EIC_IRQ_PRIORITY);
}

static void st_lld_serve_interrupt(void)
{
  uint32_t isr;
  /* Get and clear the RTC interrupts. */
  isr = RTC_REGS->MODE0.RTC_INTFLAG;
  RTC_REGS->MODE0.RTC_INTFLAG = RTC_MODE0_INTFLAG_Msk;
  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();
}

OSAL_IRQ_HANDLER(RTC_HANDLER)
{
  OSAL_IRQ_PROLOGUE();

  st_lld_serve_interrupt();

  OSAL_IRQ_EPILOGUE();
}
#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

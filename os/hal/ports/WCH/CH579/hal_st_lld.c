/**
 * @file    hal_st_lld.c
 * @brief   CH579M ST subsystem low level driver.
 * @details ARM SysTick in periodic mode.  QMK sets OSAL_ST_MODE_PERIODIC
 *          and OSAL_ST_FREQUENCY = 1000 (1 kHz tick) by default.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define SYSTICK_CK CH579_SYSCLK

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   SysTick IRQ — drives the OSAL tick.
 */
OSAL_IRQ_HANDLER(SysTick_Handler) {
  OSAL_IRQ_PROLOGUE();

  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();

  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Initialises the SysTick timer for periodic tick generation.
 * @note    Called by halInit() via st_lld_init().
 *
 * @notapi
 */
void st_lld_init(void) {
  /* Configure SysTick for periodic interrupts at OSAL_ST_FREQUENCY. */
  SysTick->LOAD = (SYSTICK_CK / OSAL_ST_FREQUENCY) - 1UL;
  SysTick->VAL = 0UL;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | /* processor clock */
                  SysTick_CTRL_TICKINT_Msk |   /* enable exception */
                  SysTick_CTRL_ENABLE_Msk;     /* start counting  */

  /* Set SysTick interrupt priority. */
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, CH579_ST_IRQ_PRIORITY);
}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

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
#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
#define ST_HANDLER                          SysTick_Handler
#define SYSTICK_CK                          SAM_CPU_FREQ
#elif OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
#define ST_HANDLER                          RTC_HANDLER
#endif
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
static uint8_t isAlarmActive;
#endif
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
 * @brief Serving RTC Interrupt
 * 
 * @notapi
 */
static void st_lld_serve_interrupt(void);

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void)
{
  #if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  isAlarmActive = false;
  PM_REGS->PM_APBAMASK |= PM_APBAMASK_RTC_Msk;
  /* Connect GENCLK to RTC */
  sam_gclk_mux(SAM_RTC_GCLK_SRC_ID, GCLK_CLKCTRL_ID_RTC, TRUE);

  /* Reset Peripheral before usage */
  RTC_REGS->MODE0.RTC_CTRL = RTC_MODE0_CTRL_SWRST_Msk;
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  /* Set to 32 */
  RTC_REGS->MODE0.RTC_CTRL = RTC_MODE0_CTRL_PRESCALER(SAM_RTC_DIV) | RTC_MODE0_CTRL_MODE_COUNT32;
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  nvicEnableVector(RTC_IRQn, SAM_EIC_IRQ_PRIORITY);
  #endif
  #if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  SysTick->LOAD = (SYSTICK_CK / OSAL_ST_FREQUENCY) - 1;
  SysTick->VAL = 0;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk |
                  SysTick_CTRL_TICKINT_Msk;

  /* IRQ enabled.*/
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, SAM_ST_IRQ_PRIORITY);
  #endif
}
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
/**
 * @brief   Starts the alarm.
 * @note    Makes sure that no spurious alarms are triggered after
 *          this call.
 *
 * @param[in] abstime   the time to be set for the first alarm
 *
 * @notapi
 */
void st_lld_start_alarm(systime_t abstime)
{
  RTC_REGS->MODE0.RTC_CTRL &= ~RTC_MODE0_CTRL_ENABLE_Msk;
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  RTC_REGS->MODE0.RTC_INTFLAG = RTC_MODE0_INTENSET_CMP0_Msk;
  RTC_REGS->MODE0.RTC_COMP = (uint32_t)abstime;
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  RTC_REGS->MODE0.RTC_INTENSET = RTC_MODE0_INTENSET_CMP0_Msk;
  RTC_REGS->MODE0.RTC_CTRL |= RTC_MODE0_CTRL_ENABLE_Msk;
  while ((RTC_REGS->MODE0.RTC_STATUS & RTC_STATUS_SYNCBUSY_Msk) == RTC_STATUS_SYNCBUSY_Msk)
    ;
  isAlarmActive = true;
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
void st_lld_stop_alarm(void)
{
  #if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  RTC_REGS->MODE0.RTC_INTENCLR = RTC_MODE0_INTENCLR_CMP0_Msk;
  isAlarmActive = false;
  #endif
}

/**
 * @brief   Determines if the alarm is active.
 *
 * @return              The alarm status.
 * @retval false        if the alarm is not active.
 * @retval true         is the alarm is active
 *
 * @notapi
 */
bool st_lld_is_alarm_active(void)
{
  return isAlarmActive;
}
#endif

static void st_lld_serve_interrupt(void)
{
  #if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  uint8_t isr;
  /* Get and clear the RTC interrupts. */
  isr = RTC_REGS->MODE0.RTC_INTFLAG;
  RTC_REGS->MODE0.RTC_INTFLAG = isr;
  RTC_REGS->MODE0.RTC_INTENCLR = isr;
  if(isr & RTC_MODE0_INTFLAG_CMP0_Msk)
  #endif
  {
    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
  }
}
OSAL_IRQ_HANDLER(ST_HANDLER)
{
  OSAL_IRQ_PROLOGUE();

  st_lld_serve_interrupt();

  OSAL_IRQ_EPILOGUE();
}
#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

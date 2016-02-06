/*
    ChibiOS - Copyright (C) 2015 Fabio Utzig
                            2016 Stephane D'Alu

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
 * @file    st_lld.c
 * @brief   NRF51822 ST subsystem low level driver source.
 *
 * @addtogroup ST
 * @{
 */

#include "hal.h"

#if (OSAL_ST_MODE != OSAL_ST_MODE_NONE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#if   (OSAL_ST_RESOLUTION == 32)
#define ST_OVERFLOW_VALUE                         0xFFFFFFFF
#elif (OSAL_ST_RESOLUTION == 24)
#define ST_OVERFLOW_VALUE                         0x00FFFFFF
#elif (OSAL_ST_RESOLUTION == 16)
#define ST_OVERFLOW_VALUE                         0x0000FFFF
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

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC) || defined(__DOXYGEN__)
#if (NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_RTC)
/**
 * @brief   System Timer vector (RTC0)
 * @details This interrupt is used for system tick in periodic mode
 *          if selected with NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_RTC
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector6C) {

  OSAL_IRQ_PROLOGUE();

  NRF_RTC0->EVENTS_TICK = 0;
      
  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();

  OSAL_IRQ_EPILOGUE();
}
#endif

#if (NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_TIMER)
/**
 * @brief   System Timer vector. (TIMER0)
 * @details This interrupt is used for system tick in periodic mode
 *          if selected with NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_TIMER
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector60) {

  OSAL_IRQ_PROLOGUE();

  /* Clear timer compare event */
  if (NRF_TIMER0->EVENTS_COMPARE[0] != 0)
    NRF_TIMER0->EVENTS_COMPARE[0] = 0;

  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)
#if (NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_RTC)
/**
 * @brief   System Timer vector (RTC0)
 * @details This interrupt is used for freerunning mode (tick-less)
 *          if selected with NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_RTC
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector6C) {

  OSAL_IRQ_PROLOGUE();

  NRF_RTC0->EVENTS_COMPARE[0] = 0;
      
  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();

  OSAL_IRQ_EPILOGUE();
}
#endif
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
#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING)
#if (NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_RTC)
  /* Using RTC with prescaler */
  NRF_RTC0->TASKS_STOP  = 1;
  NRF_RTC0->PRESCALER   = (NRF51_LFCLK_FREQUENCY / OSAL_ST_FREQUENCY) - 1; 
  NRF_RTC0->EVTENCLR    = RTC_EVTEN_COMPARE0_Msk;
  NRF_RTC0->EVENTS_COMPARE[0] = 0;
  NRF_RTC0->INTENSET    = RTC_INTENSET_COMPARE0_Msk;

  /* Start timer */
  nvicEnableVector(RTC0_IRQn, 8);
  NRF_RTC0->TASKS_START = 1;
#endif
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
#if (NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_RTC)
  /* Using RTC with prescaler */
  NRF_RTC0->TASKS_STOP  = 1;
  NRF_RTC0->PRESCALER   = (NRF51_LFCLK_FREQUENCY / OSAL_ST_FREQUENCY) - 1; 
  NRF_RTC0->INTENSET    = RTC_INTENSET_TICK_Msk;

  /* Start timer */
  nvicEnableVector(RTC0_IRQn, 8);
  NRF_RTC0->TASKS_START = 1;
#endif

#if (NRF51_SYSTEM_TICKS == NRF51_SYSTEM_TICKS_AS_TIMER)
  NRF_TIMER0->TASKS_CLEAR = 1;

  /*
   * Using 32-bit mode with prescaler 16 configures this
   * timer with a 1MHz clock.
   */
  NRF_TIMER0->BITMODE = 3;
  NRF_TIMER0->PRESCALER = 4;

  /*
   * Configure timer 0 compare capture 0 to generate interrupt
   * and clear timer value when event is generated.
   */
  NRF_TIMER0->CC[0] = (1000000 / OSAL_ST_FREQUENCY) - 1;
  NRF_TIMER0->SHORTS = 1;
  NRF_TIMER0->INTENSET = 0x10000;

  /* Start timer */
  nvicEnableVector(TIMER0_IRQn, 8);
  NRF_TIMER0->TASKS_START = 1;
#endif
#endif
}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

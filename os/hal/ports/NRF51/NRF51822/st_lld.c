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

#if NRF51_ST_USE_RTC0 == TRUE || NRF51_ST_USE_RTC1 == TRUE

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING

static void serve_rtc_interrupt(NRF_RTC_Type *rtc) {

  if (rtc->EVENTS_COMPARE[0]) {
    rtc->EVENTS_COMPARE[0] = 0;

    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
  }

#if OSAL_ST_RESOLUTION == 16
  if (rtc->EVENTS_COMPARE[1]) {
    rtc->EVENTS_COMPARE[1] = 0;
    rtc->TASKS_CLEAR = 1;
  }
#endif
}

static void rtc_init(NRF_RTC_Type *rtc, int irq) {

  /* Using RTC with prescaler */
  rtc->TASKS_STOP  = 1;
  rtc->PRESCALER   = (NRF51_LFCLK_FREQUENCY / OSAL_ST_FREQUENCY) - 1;
  rtc->EVTENCLR    = RTC_EVTENSET_COMPARE0_Msk;
  rtc->EVENTS_COMPARE[0] = 0;
  rtc->INTENSET    = RTC_INTENSET_COMPARE0_Msk;
#if OSAL_ST_RESOLUTION == 16
  rtc->CC[1]       = 0x10000; /* 2^16 */
  rtc->EVENTS_COMPARE[1] = 0;
  rtc->EVTENSET    = RTC_EVTENSET_COMPARE0_Msk;
  rtc->INTENSET    = RTC_INTENSET_COMPARE1_Msk;
#endif
  rtc->TASKS_CLEAR  = 1;

  /* Start timer */
  nvicEnableVector(irq, NRF51_ST_PRIORITY);
  rtc->TASKS_START = 1;
}

#elif OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC

static void serve_rtc_interrupt(NRF_RTC_Type *rtc) {

  rtc->EVENTS_TICK = 0;

  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();
}

static void rtc_init(NRF_RTC_Type *rtc, int irq) {

  /* Using RTC with prescaler */
  rtc->TASKS_STOP  = 1;
  rtc->PRESCALER   = (NRF51_LFCLK_FREQUENCY / OSAL_ST_FREQUENCY) - 1;
  rtc->INTENSET    = RTC_INTENSET_TICK_Msk;

  /* Start timer */
  nvicEnableVector(irq, NRF51_ST_PRIORITY);
  rtc->TASKS_START = 1;
}

#endif /* OSAL_ST_MODE */

#endif /* NRF51_ST_USE_RTC0 == TRUE || NRF51_ST_USE_RTC1 == TRUE */

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC) || defined(__DOXYGEN__)

#if NRF51_ST_USE_RTC0 == TRUE
/**
 * @brief   System Timer vector (RTC0)
 * @details This interrupt is used for system tick in periodic mode
 *          if selected with NRF51_ST_USE_RTC0
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector6C) {

  OSAL_IRQ_PROLOGUE();

  serve_rtc_interrupt(NRF_RTC0);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if NRF51_ST_USE_RTC1 == TRUE
/**
 * @brief   System Timer vector (RTC1)
 * @details This interrupt is used for system tick in periodic mode
 *          if selected with NRF51_ST_USE_RTC1
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector84) {

  OSAL_IRQ_PROLOGUE();

  serve_rtc_interrupt(NRF_RTC1);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if NRF51_ST_USE_TIMER0 == TRUE
/**
 * @brief   System Timer vector. (TIMER0)
 * @details This interrupt is used for system tick in periodic mode
 *          if selected with NRF51_ST_USE_TIMER0
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

#elif (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)

#if NRF51_ST_USE_RTC0 == TRUE
/**
 * @brief   System Timer vector (RTC0)
 * @details This interrupt is used for freerunning mode (tick-less)
 *          if selected with NRF51_ST_USE_RTC0 
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector6C) {

  OSAL_IRQ_PROLOGUE();

  serve_rtc_interrupt(NRF_RTC0);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if NRF51_ST_USE_RTC1 == TRUE
/**
 * @brief   System Timer vector (RTC1)
 * @details This interrupt is used for freerunning mode (tick-less)
 *          if selected with NRF51_ST_USE_RTC1
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector84) {

  OSAL_IRQ_PROLOGUE();

  serve_rtc_interrupt(NRF_RTC1);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {

#if NRF51_ST_USE_RTC0 == TRUE
  rtc_init(NRF_RTC0, RTC0_IRQn);
#endif

#if NRF51_ST_USE_RTC1 == TRUE
  rtc_init(NRF_RTC1, RTC1_IRQn);
#endif

#if NRF51_ST_USE_TIMER0 == TRUE && OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
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
  nvicEnableVector(TIMER0_IRQn, NRF51_ST_PRIORITY);
  NRF_TIMER0->TASKS_START = 1;
#endif /* NRF51_ST_USE_TIMER0 == TRUE && OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */
}

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

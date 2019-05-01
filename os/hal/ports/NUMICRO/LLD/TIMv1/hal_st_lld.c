/*
    Copyright (C) 2019 /u/KeepItUnder

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
 * @file    TIMv1/hal_st_lld.c
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

#if (OSAL_ST_RESOLUTION == 32)
#define ST_ARR_INIT                         0xFFFFFFFF
#else
#define ST_ARR_INIT                         0x0000FFFF
#endif

#if NUC123_ST_USE_TIMER == 2
#if (OSAL_ST_RESOLUTION == 32) && !NUC123_TIM2_IS_32BITS
#error "TIM2 is not a 32bits timer"
#endif

#if defined(NUC123_TIM2_IS_USED)
#error "ST requires TIM2 but the timer is already used"
#else
#define NUC123_TIM2_IS_USED
#endif

#define ST_HANDLER                          NUC123_TIM2_HANDLER
#define ST_NUMBER                           NUC123_TIM2_NUMBER
#define ST_USE_TIMER                        TIMER2

#elif NUC123_ST_USE_TIMER == 3
#if (OSAL_ST_RESOLUTION == 32) && !NUC123_TIM3_IS_32BITS
#error "TIM3 is not a 32bits timer"
#endif

#if defined(NUC123_TIM3_IS_USED)
#error "ST requires TIM3 but the timer is already used"
#else
#define NUC123_TIM3_IS_USED
#endif

#define ST_HANDLER                          NUC123_TIM3_HANDLER
#define ST_NUMBER                           NUC123_TIM3_NUMBER
#define ST_USE_TIMER                        TIMER3

#elif NUC123_ST_USE_TIMER == 4
#if (OSAL_ST_RESOLUTION == 32) && !NUC123_TIM4_IS_32BITS
#error "TIM4 is not a 32bits timer"
#endif

#if defined(NUC123_TIM4_IS_USED)
#error "ST requires TIM4 but the timer is already used"
#else
#define NUC123_TIM4_IS_USED
#endif

#define ST_HANDLER                          NUC123_TIM4_HANDLER
#define ST_NUMBER                           NUC123_TIM4_NUMBER
#define ST_USE_TIMER                        TIMER4

#else
#error "NUC123_ST_USE_TIMER specifies an unsupported timer"
#endif

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

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
/**
 * @brief   System Timer vector.
 * @details This interrupt is used for system tick in periodic mode.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SysTick_Handler) {

  OSAL_IRQ_PROLOGUE();

  osalSysLockFromISR();
  osalOsTimerHandlerI();
  osalSysUnlockFromISR();

  /* DEBUG Output to pin PB8 */
  //GPIO_TOGGLE(PB8);
  //GPIO_TOGGLE(PD10);
  //GPIO_TOGGLE(PB14);
  //uint16_t quickChange = PB14;

  //pal_lld_writepad(GPIOB, 14, ~quickChange);
  // if (PB14 == 0)
  //   palSetLine(B14);
  // else
  //   palClearLine(B14);
  //palToggleLine(B14);
  
  OSAL_IRQ_EPILOGUE();
}
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)
/**
 * @brief   TIM2 interrupt handler.
 * @details This interrupt is used for system tick in free running mode.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(ST_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Note, under rare circumstances an interrupt can remain latched even if
     the timer SR register has been cleared, in those cases the interrupt
     is simply ignored.*/
  if (TIMER_GetIntFlag(NUC123_ST_TIM)) {
    TIMER_ClearIntFlag(NUC123_ST_TIM);

    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
  }

  /* DEBUG Output to pin PC13 */
  //GPIO_TOGGLE(PB8);
  //GPIO_TOGGLE(PD11);

  OSAL_IRQ_EPILOGUE();
}
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

/* DEBUG - Catch unused Interrupt Vectors and output to test pins

OSAL_IRQ_HANDLER(Vector7C){
  OSAL_IRQ_PROLOGUE();

  GPIO_TOGGLE(PB8);
  GPIO_TOGGLE(PB11);
  
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(NUC123_TIM3_HANDLER){

  OSAL_IRQ_PROLOGUE();

  GPIO_TOGGLE(PB4);
  GPIO_TOGGLE(PB5);
  GPIO_TOGGLE(PB6);
  GPIO_TOGGLE(PB7);
  GPIO_TOGGLE(PB8);
  
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(NUC123_TIM4_HANDLER){

  OSAL_IRQ_PROLOGUE();

  GPIO_TOGGLE(PB4);
  GPIO_TOGGLE(PB5);
  GPIO_TOGGLE(PB6);
  GPIO_TOGGLE(PB7);
  GPIO_TOGGLE(PB8);
  
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(NUC123_ADC_HANDLER){

  OSAL_IRQ_PROLOGUE();

  GPIO_TOGGLE(PB4);
  GPIO_TOGGLE(PB5);
  GPIO_TOGGLE(PB6);
  GPIO_TOGGLE(PB7);
  GPIO_TOGGLE(PB8);
  
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(NUC123_USB1_HANDLER){

  OSAL_IRQ_PROLOGUE();

  GPIO_TOGGLE(PB4);
  GPIO_TOGGLE(PB5);
  GPIO_TOGGLE(PB6);
  GPIO_TOGGLE(PB7);
  GPIO_TOGGLE(PB8);
  
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(NUC123_PDMA_HANDLER){

  OSAL_IRQ_PROLOGUE();

  GPIO_TOGGLE(PB4);
  GPIO_TOGGLE(PB5);
  GPIO_TOGGLE(PB6);
  GPIO_TOGGLE(PB7);
  GPIO_TOGGLE(PB8);
  
  OSAL_IRQ_EPILOGUE();
}

//OSAL_IRQ_HANDLER(HardFault_Handler){
//  OSAL_IRQ_PROLOGUE();

//  NVIC_SystemReset();
  
//  OSAL_IRQ_EPILOGUE();
//}
*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ST driver initialization.
 *
 * @notapi
 */
void st_lld_init(void) {

  //GPIO_SetMode(PB, BIT6, GPIO_PMD_OUTPUT);
  //PB6 = 1;

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  /* Free running counter mode.*/

  /* Enabling timer clock.*/
  //ST_ENABLE_CLOCK();
  //GPIO_SetMode(PB, BIT7, GPIO_PMD_OUTPUT);
  //PB7 = 1;
  
  TIMER_Open(ST_USE_TIMER, TIMER_CONTINUOUS_MODE, OSAL_ST_FREQUENCY);

  /* Initializing the counter in free running mode.*/
/*  NUC123_ST_TIM->PSC    = (ST_CLOCK_SRC / OSAL_ST_FREQUENCY) - 1;
  NUC123_ST_TIM->ARR    = ST_ARR_INIT;
  NUC123_ST_TIM->CCMR1  = 0;
  NUC123_ST_TIM->CCR[0] = 0;
  NUC123_ST_TIM->DIER   = 0;
  NUC123_ST_TIM->CR2    = 0;
  NUC123_ST_TIM->EGR    = TIM_EGR_UG;
  NUC123_ST_TIM->CR1    = TIM_CR1_CEN;
*/
  /* IRQ enabled.*/
  nvicEnableVector(ST_NUMBER, NUC123_ST_IRQ_PRIORITY);

  TIMER_EnableInt(ST_USE_TIMER);

  /* Start the Timer! */
  TIMER_Start(ST_USE_TIMER);
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  /* Periodic systick mode, the Cortex-Mx internal systick timer is used
     in this mode.*/

//  GPIO_SetMode(PB, BIT8, GPIO_PMD_OUTPUT);
//  PB8 = 1;

 // CLK_EnableSysTick(CLK_CLKSEL0_STCLK_S_HCLK, (NUC123_HCLK / OSAL_ST_FREQUENCY) - 1);
  SysTick->LOAD = (NUC123_HCLK / OSAL_ST_FREQUENCY) - 1;
  SysTick->VAL = 0;
  SysTick->CTRL = (~SysTick_CTRL_CLKSOURCE_Msk) &
                  (SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);

  /* IRQ enabled.*/
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, NUC123_ST_IRQ_PRIORITY);
  
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

/* DEBUG */

//  TIMER_Open(TIMER3, TIMER_CONTINUOUS_MODE, OSAL_ST_FREQUENCY);

//  nvicEnableVector(NUC123_TIM3_NUMBER, 0);

//  TIMER_EnableInt(TIMER3);
//  TIMER_Start(TIMER3);

//      /* Enable peripheral clock */
//    CLK_EnableModuleClock(UART0_MODULE);
//     CLK_EnableModuleClock(USBD_MODULE);
//     CLK_EnableModuleClock(TMR0_MODULE);
//     CLK_EnableModuleClock(TMR1_MODULE);
//     CLK_EnableModuleClock(TMR2_MODULE);
//     CLK_EnableModuleClock(TMR3_MODULE);
// //
//     /* Peripheral clock source */
// //    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_PLL, CLK_CLKDIV_UART(1));
//     CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, 0);
//     CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_HIRC, 0);
//     CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2_S_HCLK, 0);
//     CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3_S_LIRC, 0);

}

#else /* OSAL_ST_MODE == OSAL_ST_MODE_NONE!!! */
  #error "We can't proceed without an OSAL_ST clock!"

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/** @} */

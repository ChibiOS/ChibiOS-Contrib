/*
    Copyright (C) 2019 /u/KeepItUnder
    Copyright (C) 2020 Alex Lewontin

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

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING)

#if (OSAL_ST_RESOLUTION == 32)
#define ST_ARR_INIT                         0xFFFFFFFF
#else
#define ST_ARR_INIT                         0x0000FFFF
#endif

#if NUC126_ST_USE_TIMER == 2
#if (OSAL_ST_RESOLUTION == 32) && !NUC126_TIM2_IS_32BITS
#error "TIM2 is not a 32bits timer"
#endif

#if defined(NUC126_TIM2_IS_USED)
#error "ST requires TIM2 but the timer is already used"
#else
#define NUC126_TIM2_IS_USED
#endif

#define ST_HANDLER                          NUC126_TIM2_HANDLER
#define ST_NUMBER                           NUC126_TIM2_NUMBER
#define ST_USE_TIMER                        TIMER2

#elif NUC126_ST_USE_TIMER == 3
#if (OSAL_ST_RESOLUTION == 32) && !NUC126_TIM3_IS_32BITS
#error "TIM3 is not a 32bits timer"
#endif

#if defined(NUC126_TIM3_IS_USED)
#error "ST requires TIM3 but the timer is already used"
#else
#define NUC126_TIM3_IS_USED
#endif

#define ST_HANDLER                          NUC126_TIM3_HANDLER
#define ST_NUMBER                           NUC126_TIM3_NUMBER
#define ST_USE_TIMER                        TIMER3

#elif NUC126_ST_USE_TIMER == 4
#if (OSAL_ST_RESOLUTION == 32) && !NUC126_TIM4_IS_32BITS
#error "TIM4 is not a 32bits timer"
#endif

#if defined(NUC126_TIM4_IS_USED)
#error "ST requires TIM4 but the timer is already used"
#else
#define NUC126_TIM4_IS_USED
#endif

#define ST_HANDLER                          NUC126_TIM4_HANDLER
#define ST_NUMBER                           NUC126_TIM4_NUMBER
#define ST_USE_TIMER                        TIMER4

#else
#error "NUC126_ST_USE_TIMER specifies an unsupported timer"
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
  if (NUC126_ST_TIM->INTSTS & TIMER_INTSTS_TIF_Msk) {

    // TIMER_ClearIntFlag(NUC126_ST_TIM);
    NUC126_ST_TIM->INTSTS = TIMER_INTSTS_TIF_Msk;

    osalSysLockFromISR();
    osalOsTimerHandlerI();
    osalSysUnlockFromISR();
  }

  OSAL_IRQ_EPILOGUE();
}
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

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  /* Free running counter mode.*/

  /* Enabling timer clock.*/
  
  st_lld_timer_open(ST_USE_TIMER, TIMER_MODE_CONTINUOUS, OSAL_ST_FREQUENCY);

  /* Initializing the counter in free running mode.*/
/*  NUC126_ST_TIM->PSC    = (ST_CLOCK_SRC / OSAL_ST_FREQUENCY) - 1;
  NUC126_ST_TIM->ARR    = ST_ARR_INIT;
  NUC126_ST_TIM->CCMR1  = 0;
  NUC126_ST_TIM->CCR[0] = 0;
  NUC126_ST_TIM->DIER   = 0;
  NUC126_ST_TIM->CR2    = 0;
  NUC126_ST_TIM->EGR    = TIM_EGR_UG;
  NUC126_ST_TIM->CR1    = TIM_CR1_CEN;
*/
  /* IRQ enabled.*/
  nvicEnableVector(ST_NUMBER, NUC126_ST_IRQ_PRIORITY);

  // TIMER_EnableInt(ST_USE_TIMER);
  ST_USE_TIMER->CTL |= TIMER_CTL_INTEN_Msk;

  /* Start the Timer! */
  // TIMER_Start(ST_USE_TIMER);
  ST_USE_TIMER->CTL |= TIMER_CTL_CNTEN_Msk;

#endif /* OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING */

#if OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC
  /* Periodic systick mode, the Cortex-Mx internal systick timer is used
     in this mode.*/
  SystemUnlockReg();
  CLK->CLKSEL0 &= ~CLK_CLKSEL0_STCLKSEL_Msk;
  CLK->CLKSEL0 |= CLK_CLKSEL0_STCLKSEL_HCLK_DIV2;
  LOCKREG();
  
  SysTick->LOAD = ((NUC126_HCLK / 2) / OSAL_ST_FREQUENCY) - 1;
  SysTick->VAL = 0;
  SysTick->CTRL = (~SysTick_CTRL_CLKSOURCE_Msk) &
                  (SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);

  /* IRQ enabled.*/
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, NUC126_ST_IRQ_PRIORITY);
  
#endif /* OSAL_ST_MODE == OSAL_ST_MODE_PERIODIC */

}

#else /* OSAL_ST_MODE == OSAL_ST_MODE_NONE!!! */
  #error "We can't proceed without an OSAL_ST clock!"

#endif /* OSAL_ST_MODE != OSAL_ST_MODE_NONE */

/**
  * @brief      Get PCLK0 frequency
  * @param      None
  * @return     PCLK0 frequency
  * @details    This function get PCLK0 frequency. The frequency unit is Hz.
  */
static uint32_t CLK_GetPCLK0Freq(void)
{
    SystemCoreClockUpdate();
    if(CLK->CLKSEL0 & CLK_CLKSEL0_PCLK0SEL_Msk)
        return SystemCoreClock >> 1;
    else
        return SystemCoreClock;
}

/**
  * @brief      Get PCLK1 frequency
  * @param      None
  * @return     PCLK1 frequency
  * @details    This function get PCLK1 frequency. The frequency unit is Hz.
  */
static uint32_t CLK_GetPCLK1Freq(void)
{
    SystemCoreClockUpdate();
    if(CLK->CLKSEL0 & CLK_CLKSEL0_PCLK1SEL_Msk)
        return SystemCoreClock >> 1;
    else
        return SystemCoreClock;
}

/**
  * @brief      Get Timer Clock Frequency
  *
  * @param[in]  timer   The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  *
  * @return     Timer clock frequency
  *
  * @details    This API is used to get the timer clock frequency.
  * @note       This API cannot return correct clock rate if timer source is from external clock input.
  */
static uint32_t TIMER_GetModuleClock(TIMER_T *timer)
{
    uint32_t u32Src, u32Clk;
    const uint32_t au32Clk[] = {__HXT, __LXT, 0, 0, 0, __LIRC, 0, __HIRC};

    if(timer == TIMER0)
        u32Src = (CLK->CLKSEL1 & CLK_CLKSEL1_TMR0SEL_Msk) >> CLK_CLKSEL1_TMR0SEL_Pos;
    else if(timer == TIMER1)
        u32Src = (CLK->CLKSEL1 & CLK_CLKSEL1_TMR1SEL_Msk) >> CLK_CLKSEL1_TMR1SEL_Pos;
    else if(timer == TIMER2)
        u32Src = (CLK->CLKSEL1 & CLK_CLKSEL1_TMR2SEL_Msk) >> CLK_CLKSEL1_TMR2SEL_Pos;
    else  // Timer 3
        u32Src = (CLK->CLKSEL1 & CLK_CLKSEL1_TMR3SEL_Msk) >> CLK_CLKSEL1_TMR3SEL_Pos;

    if(u32Src == 2)
    {
        if((timer == TIMER0) || (timer == TIMER1))
        {
            u32Clk = CLK_GetPCLK0Freq();
        }
        else
        {
            u32Clk = CLK_GetPCLK1Freq();
        }
    }
    else
    {
        u32Clk = au32Clk[u32Src];
    }

    return u32Clk;
}

static uint32_t TIMER_Open(TIMER_T *timer, uint32_t u32Mode, uint32_t u32Freq) {
    uint32_t u32Clk = TIMER_GetModuleClock(timer);
    uint32_t u32Cmpr = 0UL, u32Prescale = 0UL;

    /* Fastest possible timer working freq is (u32Clk / 2). While cmpr = 2, prescaler = 0. */
    if(u32Freq > (u32Clk / 2UL))
    {
        u32Cmpr = 2UL;
    }
    else
    {
        u32Cmpr = u32Clk / u32Freq;
        u32Prescale = (u32Cmpr >> 24);  /* for 24 bits CMPDAT */
        if (u32Prescale > 0UL)
            u32Cmpr = u32Cmpr / (u32Prescale + 1UL);
    }

    timer->CTL = u32Mode | u32Prescale;
    timer->CMP = u32Cmpr;

    return(u32Clk / (u32Cmpr * (u32Prescale + 1UL)));
}

/**
  * @brief      Stop Timer Counting
  *
  * @param[in]  timer   The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  *
  * @return     None
  *
  * @details    This API stops timer counting and disable all timer interrupt function.
  */
static void TIMER_Close(TIMER_T *timer)
{
    timer->CTL = 0;
    timer->EXTCTL = 0;
}

uint32_t st_lld_timer_getmoduleclock(TIMER_T *timer)
{
    return TIMER_GetModuleClock(timer);
}

uint32_t st_lld_timer_open(TIMER_T *timer, uint32_t tmrMode, uint32_t tmrFreq)
{
    return TIMER_Open(timer, tmrMode, tmrFreq);
}

void st_lld_timer_close(TIMER_T *timer)
{
    TIMER_Close(timer);
}


/** @} */

/*
    Copyright (C) 2022 Westberry Technology (ChangZhou) Corp., Ltd

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

#include "ch.h"
#include "hal.h"
#include "board.h"

/*===========================================================================*/
/* Private variables.                                                        */
/*===========================================================================*/
/*===========================================================================*/
/* Generic code.                                                             */
/*===========================================================================*/

#define PORTAB_LINE_LED1 PAL_LINE(GPIOB, 14U)
#define PORTAB_LINE_LED2 PAL_LINE(GPIOB, 13U)
#define PORTAB_LED_OFF   PAL_HIGH
#define PORTAB_LED_ON    AL_LOW

#define PORTAB_LINE_BUTTON    PAL_LINE(GPIOA, 0U)
#define PORTAB_BUTTON_PRESSED PAL_LOW

#if defined(PORTAB_LINE_LED2)
/*
 * LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg)
{
  (void)arg;
  chRegSetThreadName("blinker");
  while (true)
  {
    systime_t time = palReadLine(PORTAB_LINE_BUTTON) == PORTAB_BUTTON_PRESSED ? 250 : 500;
    palToggleLine(PORTAB_LINE_LED2);
    chThdSleepMilliseconds(time);
  }
}
#endif

#if PAL_USE_WAIT || defined(__DOXYGEN__)

/**
  * @brief  Configure PORTAB_LINE_BUTTON in interrupt mode
  * @param  None
  * @return None
  */
void EXTI0_Config(void)
{
  /* 
   * Init button port and pad.
   */
  palSetPadMode(PAL_PORT(PORTAB_LINE_BUTTON), PAL_PAD(PORTAB_LINE_BUTTON), PAL_WB32_MODE_INPUT | PAL_WB32_PUPDR_PULLDOWN);

  /* 
   * Enabling events on both edges of the button line.
   */
  palEnableLineEvent(PORTAB_LINE_BUTTON, PAL_EVENT_MODE_RISING_EDGE);

  /*
   * Configure the interrupt priority.
   */
  nvicEnableVector(EXTI0_IRQn, WB32_IRQ_EXTI0_PRIORITY);
}

/*
 * Application entry point.
 */
int main(void)
{
  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();
  
  /* 
   * Init LED port and pad.
   */
  palSetPadMode(PAL_PORT(PORTAB_LINE_LED1), PAL_PAD(PORTAB_LINE_LED1), PAL_WB32_MODE_OUTPUT | PAL_WB32_OTYPE_PUSHPULL);
  palSetPadMode(PAL_PORT(PORTAB_LINE_LED2), PAL_PAD(PORTAB_LINE_LED2), PAL_WB32_MODE_OUTPUT | PAL_WB32_OTYPE_PUSHPULL);
  
  /*
   * Configure PA0 in interrupt mode 
   */
  EXTI0_Config();  

#if defined(PORTAB_LINE_LED2)
  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
#endif

  /*
   * Normal main() thread activity.
   */
  while (true)
  {
    /* Waiting for an edge on the button.*/
    palWaitLineTimeout(PORTAB_LINE_BUTTON, TIME_INFINITE);
    
    palToggleLine(PORTAB_LINE_LED1);
  }
}

#endif /* PAL_USE_WAIT */

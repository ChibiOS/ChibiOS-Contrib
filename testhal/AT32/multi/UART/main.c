/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2025 HorrorTroll
    ChibiOS - Copyright (C) 2023..2025 Zhaqian

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

#include "portab.h"

static virtual_timer_t vt1, vt2;

static void restart(virtual_timer_t *vtp, void *p) {

  (void)vtp;
  (void)p;

  chSysLockFromISR();
  uartStartSendI(&PORTAB_UART1, 14, "Hello World!\r\n");
  chSysUnlockFromISR();
}

static void ledoff(virtual_timer_t *vtp, void *p) {

  (void)vtp;
  (void)p;

#if defined(AT32F415)
  palSetLine(PORTAB_BLINK_LED1);
  palSetLine(PORTAB_BLINK_LED2);
  palSetLine(PORTAB_BLINK_LED3);
#else
  palClearLine(PORTAB_BLINK_LED1);
  palClearLine(PORTAB_BLINK_LED2);
  palClearLine(PORTAB_BLINK_LED3);
#endif
}

/*
 * This callback is invoked when a transmission buffer has been completely
 * read by the driver.
 */
void txend1(UARTDriver *uartp) {

  (void)uartp;

#if defined(AT32F415)
  palClearLine(PORTAB_BLINK_LED1);
  palClearLine(PORTAB_BLINK_LED2);
  palClearLine(PORTAB_BLINK_LED3);
#else
  palSetLine(PORTAB_BLINK_LED1);
  palSetLine(PORTAB_BLINK_LED2);
  palSetLine(PORTAB_BLINK_LED3);
#endif
}

/*
 * This callback is invoked when a transmission has physically completed.
 */
void txend2(UARTDriver *uartp) {

  (void)uartp;

#if defined(AT32F415)
  palSetLine(PORTAB_BLINK_LED1);
  palSetLine(PORTAB_BLINK_LED2);
  palSetLine(PORTAB_BLINK_LED3);
#else
  palClearLine(PORTAB_BLINK_LED1);
  palClearLine(PORTAB_BLINK_LED2);
  palClearLine(PORTAB_BLINK_LED3);
#endif
  chSysLockFromISR();
  chVTSetI(&vt1, TIME_MS2I(5000), restart, NULL);
  chSysUnlockFromISR();
}

/*
 * This callback is invoked on a receive error, the errors mask is passed
 * as parameter.
 */
void rxerr(UARTDriver *uartp, uartflags_t e) {

  (void)uartp;
  (void)e;
}

/*
 * This callback is invoked when a character is received but the application
 * was not ready to receive it, the character is passed as parameter.
 */
void rxchar(UARTDriver *uartp, uint16_t c) {

  (void)uartp;
  (void)c;

  /* Flashing the LED each time a character is received.*/
#if defined(AT32F415)
  palClearLine(PORTAB_BLINK_LED1);
  palClearLine(PORTAB_BLINK_LED2);
  palClearLine(PORTAB_BLINK_LED3);
#else
  palSetLine(PORTAB_BLINK_LED1);
  palSetLine(PORTAB_BLINK_LED2);
  palSetLine(PORTAB_BLINK_LED3);
#endif

  chSysLockFromISR();
  chVTSetI(&vt2, TIME_MS2I(200), ledoff, NULL);
  chSysUnlockFromISR();
}

/*
 * This callback is invoked when a receive buffer has been completely written.
 */
void rxend(UARTDriver *uartp) {

  (void)uartp;
}

/*
 * Application entry point.
 */
int main(void) {

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
   * Board-dependent setup code.
   */
  portab_setup();

  /*
   * Activates the serial driver 1 using the driver default configuration.
   */
  uartStart(&PORTAB_UART1, &uartcfg);

  /*
   * Starts the transmission, it will be handled entirely in background.
   */
  uartStartSend(&PORTAB_UART1, 13, "Starting...\r\n");

  /*
   * Normal main() thread activity, in this demo it does nothing.
   */
  while (true) {
    chThdSleepMilliseconds(500);
  }
}

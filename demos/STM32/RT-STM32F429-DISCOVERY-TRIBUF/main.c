/*
    Copyright (C) 2013-2015 Andrea Zoppi

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

#include "chprintf.h"
#if HAL_USE_SERIAL_USB
#include "usbcfg.h"
#endif

#include "tribuf.h"

/*===========================================================================*/
/* MISCELLANEOUS                                                             */
/*===========================================================================*/

#if HAL_USE_SERIAL_USB
/* Virtual serial port over USB.*/
SerialUSBDriver SDU1;
static BaseSequentialStream *const chout = (BaseSequentialStream *)&SDU1;
#else
static BaseSequentialStream *const chout = (BaseSequentialStream *)&SD1;
#endif

/*
 * Red LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;

  chRegSetThreadName("blinker1");
  while (true) {
    palClearPad(GPIOG, GPIOG_LED4_RED);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOG, GPIOG_LED4_RED);
    chThdSleepMilliseconds(500);
  }
}

/*
 * Green LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread2, 128);
static THD_FUNCTION(Thread2, arg) {

  (void)arg;

  chRegSetThreadName("blinker2");
  while (true) {
    palClearPad(GPIOG, GPIOG_LED3_GREEN);
    chThdSleepMilliseconds(250);
    palSetPad(GPIOG, GPIOG_LED3_GREEN);
    chThdSleepMilliseconds(250);
  }
}

/*===========================================================================*/
/* TriBuf related.                                                           */
/*===========================================================================*/

#define WRITER_DELAY        10
#define READER_DELAY        20

#define WRITER_STACK_SIZE      256
#define READER_STACK_SIZE      256

#define WRITER_PRIORITY     (NORMALPRIO + 1)
#define READER_PRIORITY     (NORMALPRIO + 2)

static thread_t *writertp;
static thread_t *readertp;

static tribuf_t tribuf;
static char buffers[3];

static const char text[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n";

/*
 * Reads from the front buffer.
 */
static char read_front(void) {

  const char *front;
  msg_t error;

  error = tribufWaitReadyTimeout(&tribuf, MS2ST(1000));
  if (error == MSG_TIMEOUT)
    chSysHalt("ERROR: read_front() timed out");
  tribufSwapFront(&tribuf);
  front = (const char *)tribufGetFront(&tribuf);
  return front[0];
}

/*
 * Overwrites the back buffer with the provided character.
 */
static void write_back(char c) {

  char *back;

  back = (char *)tribufGetBack(&tribuf);
  back[0] = c;
  tribufSwapBack(&tribuf);
}

/*
 * Overwrites the back buffer with a fixed text, character by character.
 */
static THD_WORKING_AREA(writer_wa, WRITER_STACK_SIZE);
static THD_FUNCTION(writer_thread, arg) {

  const uint32_t delay = (uint32_t)(msg_t)arg;
  size_t i;
  char c;

  chRegSetThreadName("writer_thread");
  for (;;) {
    for (i = 0; i < sizeof(text); ++i) {
      c = text[i];
      write_back(c);
      chThdSleepMilliseconds(delay);
    }
  }
}

/*
 * Reads the front buffer and prints it.
 */
static THD_WORKING_AREA(reader_wa, READER_STACK_SIZE);
static THD_FUNCTION(reader_thread, arg) {

  const uint32_t delay = (uint32_t)(msg_t)arg;
  char c;

  chRegSetThreadName("reader_thread");
  for (;;) {
    c = read_front();
    chprintf(chout, "%c", c);
    chThdSleepMilliseconds(delay);
  }
}

/*===========================================================================*/
/* Initialization and main thread.                                           */
/*===========================================================================*/

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

#if HAL_USE_SERIAL_USB
  /*
   * Initializes a serial-over-USB CDC driver.
   */
  sduObjectInit(&SDU1);
  sduStart(&SDU1, &serusbcfg);

  /*
   * Activates the USB driver and then the USB bus pull-up on D+.
   * Note, a delay is inserted in order to not have to disconnect the cable
   * after a reset.
   */
  usbDisconnectBus(serusbcfg.usbp);
  chThdSleepMilliseconds(1000);
  usbStart(serusbcfg.usbp, &usbcfg);
  usbConnectBus(serusbcfg.usbp);
#else
  /*
   * Initializes serial port.
   */
  sdStart(&SD1, NULL);
#endif /* HAL_USE_SERIAL_USB */

  /*
   * Creating the blinker threads.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1),
                    NORMALPRIO + 10, Thread1, NULL);
  chThdCreateStatic(waThread2, sizeof(waThread2),
                    NORMALPRIO + 10, Thread2, NULL);

  /*
   * Writer and reader threads started for triple buffer demo.
   */
  tribufObjectInit(&tribuf, &buffers[0], &buffers[1], &buffers[2]);

  readertp = chThdCreateStatic(reader_wa, sizeof(reader_wa),
                               READER_PRIORITY,
                               reader_thread, (void *)READER_DELAY);

  writertp = chThdCreateStatic(writer_wa, sizeof(writer_wa),
                               WRITER_PRIORITY,
                               writer_thread, (void *)WRITER_DELAY);

  /* TODO: Add shell commands with varying thread creation and delays */
  for (;;)
    chThdSleepMilliseconds(1000);

  return 0;
}


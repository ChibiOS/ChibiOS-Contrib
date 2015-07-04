/*
    Copyright (C) 2015 Andrea Zoppi

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
#include "tribuf.h"

#include <stdio.h>
#include <stdlib.h>

#define WRITE_LOOPS         10
#define WRITE_DELAY         2
#define READ_DELAY          1

#define WRITER_WA_SIZE      THD_WORKING_AREA_SIZE(4096)

static thread_t *prodtp;

static tribuf_t tribuf;
static char buffers[3];

/*
 * Reads from the front buffer.
 */
static char read_front(void) {

  const char *front;
  msg_t error;

  chSysLock();
  error = tribufWaitReadyTimeoutS(&tribuf, MS2ST(1000));
  if (error != MSG_OK)
    halt("ERROR: read_front timeout");
  tribufSwapFrontI(&tribuf);
  front = tribufGetFrontI(&tribuf);
  chSysUnlock();
  return *front;
}

/*
 * Overwrites the back buffer with the provided character.
 */
static void write_back(char c) {

  char *back;

  chSysLock();
  back = tribufGetBackI(&tribuf);
  *back = c;
  tribufSwapBackI(&tribuf);
  chSysUnlock();
}

/*
 * Overwrites the back buffer with the alphabet 100 times.
 */
static THD_FUNCTION(writer_thread, arg) {

  const uint32_t delay = (uint32_t)(msg_t)arg;
  size_t loops = WRITE_LOOPS;
  char c;

  while (loops--) {
    for (c = 'A'; c <= 'Z'; ++c) {
      write_back(c);
      chThdSleepMilliseconds(delay);
    }
    write_back('\n');
    chThdSleepMilliseconds(delay);
  }
}

/*
 * Simulator main.
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
   * Triple buffer handler initialization.
   */
  tribufObjectInit(&tribuf, &buffers[0], &buffers[1], &buffers[2]);

  /*
   * Console thread started.
   */
  prodtp = chThdCreateFromHeap(NULL, WRITER_WA_SIZE, (NORMALPRIO + 1),
                               writer_thread, (void *)WRITE_DELAY);

  /*
   * Reads from the front buffer.
   */
  while (!chThdTerminatedX(prodtp)) {
    putchar(read_front());
    chThdSleepMilliseconds(READ_DELAY);
  }

  chThdRelease(prodtp);
  fputs("\n", stdout);
  fflush(stdout);
  return 0;
}

/*
 * Critical error function.
 */
void halt(const char *reason) {

  fflush(stdout);
  fputs("\n", stdout);
  fputs(reason, stderr);
  fflush(stderr);
  exit(1);
}

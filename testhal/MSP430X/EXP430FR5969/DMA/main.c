/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

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

#include "hal.h"
#include "ch.h"
#include "string.h"
#include "hal_dma_lld.h"

/*
 * Thread 2.
 */
THD_WORKING_AREA(waThread1, 2048);
THD_FUNCTION(Thread1, arg) {

  (void)arg;

  /*
   * Activate the serial driver 0 using the driver default configuration.
   */
  sdStart(&SD0, NULL);

  while (chnGetTimeout(&SD0, TIME_INFINITE)) {
    chnWrite(&SD0, (const uint8_t *)"Executing DMA test suite...\r\n", 29);
    chThdSleepMilliseconds(2000);
    /* Test 1 - use DMA engine to execute a word-wise memory-to-memory copy. */
    chnWrite(&SD0, (const uint8_t *)"TEST 1: Word-to-word, memory-to-memory copy with DMA engine, no callbacks\r\n", 82);
    unsigned char instring[16];  
    memcpy( instring,  "Before DMA test \r\n", 16 );
    unsigned char outstring[16];
    memcpy( outstring, "After DMA test  \r\n", 16 );
    chnWrite(&SD0, instring, 16);
    msp430x_dma_req_t request = {
        outstring, /* source address */
        instring, /* destination address */
        8, /* number of words */
        0, /* address mode - do nothing */
        MSP430X_DMA_SRCWORD | MSP430X_DMA_DSTWORD, /* word transfer */
        MSP430X_DMA_BLOCK, /* block (and blocking) transfer */
        DMA_TRIGGER_MNEM(DMAREQ), /* software-requested trigger */
        {
          NULL, /* no callback */
          NULL /* no arguments */
        }
    };
    dmaRequest(&request, TIME_IMMEDIATE);
  }
}

/*
 * Threads static table, one entry per thread. The number of entries must
 * match NIL_CFG_NUM_THREADS.
 */
THD_TABLE_BEGIN
  THD_TABLE_ENTRY(waThread1, "dma_test", Thread1, NULL)
THD_TABLE_END

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
  WDTCTL = WDTPW | WDTHOLD;
  

  halInit();
  chSysInit();
  
  /* This is now the idle thread loop, you may perform here a low priority
     task but you must never try to sleep or wait in this loop. Note that
     this tasks runs at the lowest priority level so any instruction added
     here will be executed after all other tasks have been started.*/
  while (true) {
  }
}

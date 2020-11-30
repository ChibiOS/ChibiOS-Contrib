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

#include "ch.h"
#include "hal.h"
#include "usbdfu.h"
#include <string.h>

#define CM_RESET_VECTOR_OFFSET    4

static void jump_to_application(void) __attribute__ ((noreturn));

static void jump_to_application(void) {

    /* Use the application's vector table */
    // Copy Vector Table to RAM_START(0x10000000)
    memcpy((void*) 0x10000000, (void*)APP_BASE, 512);
    // Switch Vector Table
    LPC_SYSCON->SYSMEMREMAP = 0x1; // User RAM mode

    /* Initialize the application's stack pointer */
    __set_MSP(*((volatile uint32_t*)(APP_BASE)));
    uint32_t target_start = *((volatile uint32_t*)(APP_BASE + CM_RESET_VECTOR_OFFSET));
    uint32_t initial_sp = *((volatile uint32_t*)(APP_BASE));
    /* Jump to the application entry point */
    __ASM volatile ("mov sp, %0\n" "bx %1" : : "r" (initial_sp), "r" (target_start) : );

    while (1) {}
}

#define IAP_LOCATION  0x1fff1ff1
typedef void (*IAP)(uint32_t [], uint32_t []);
const IAP iap_entry = (IAP)IAP_LOCATION;

/*
 * Application entry point.
 */
int main(void) {
  halInit();
  /*
   * System initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  chSysInit();

  memset(fw_buffer, 0, FW_BUFFER_SIZE);
  dfu_need_flush = 0;

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * increasing the minutes counter.
   */
  while (true) {
    uint32_t iap_command[5];
    uint32_t iap_result[4];

    usbDisconnectBus(&USBD1);
    chThdSleepMilliseconds(1500);
    usbStart(&USBD1, &usbcfg);
    usbConnectBus(&USBD1);

    while(1){
      if (dfu_need_flush) {
        if (global_offset == APP_BASE) {
          do {
          iap_command[0] = 50; // Prep Sector
          iap_command[1] = 3; // Start Sec
          iap_command[2] = 15; // Stop Sec
          iap_entry(iap_command, iap_result);
          } while(iap_result[0]);
          // Erase All Flash (3-15)
          do {
          iap_command[0] = 52; // Erase Sector
          iap_command[1] = 3; // Start Sec
          iap_command[2] = 15; // Stop Sec
          iap_command[3] = 48000; // 48MHz
          iap_entry(iap_command, iap_result);
          } while(iap_result[0]);
        }
        uint32_t start_sector = global_offset / 4096;
        uint32_t end_sector = (global_offset + FW_BUFFER_SIZE) / 4096;
        iap_command[0] = 50; // Prep Sector
        iap_command[1] = start_sector; // Start Sec
        iap_command[2] = end_sector; // Stop Sec
        iap_entry(iap_command, iap_result);
        // Copy the buffer
        iap_command[0] = 51;
        iap_command[1] = global_offset;
        iap_command[2] = (uint32_t)fw_buffer;
        iap_command[3] = FW_BUFFER_SIZE;
        iap_command[4] = 48000;
        iap_entry(iap_command, iap_result);
        global_offset += FW_BUFFER_SIZE;

        dfu_need_flush = 0;
        memset(fw_buffer, 0, FW_BUFFER_SIZE);
        buffer_fill = 0;
        if (currentState == STATE_DFU_DNLOAD_SYNC || currentState == STATE_DFU_DNBUSY)
          currentState = STATE_DFU_DNLOAD_IDLE;
        if (currentState == STATE_DFU_MANIFEST_SYNC) {
          currentState = STATE_DFU_MANIFEST_WAIT_RESET;
          chThdSleepMilliseconds(2000);
          jump_to_application();
        }
      }
    }
  }
}

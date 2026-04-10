/*
    ChibiOS - Copyright (C) 2024 Xael South

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

#include <string.h>
#include "cmsis_os.h"
#include "hal.h"

static void led_on(void) {

  /* PB2 = LED */
  palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPad(GPIOB, 2);
}

static void led_off(void) {

  /* PB2 = LED */
  palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB, 2);
}

static void test_GetX_PutX(SIODriver *siop, uint16_t data) {

  msg_t msg;

  osDelay(10);
  sioPutX(siop, data);
  osDelay(10);
  msg = sioGetX(siop);
  osalDbgCheck(data == msg);
}

static void test_sioAsyncRead_sioAsyncWrite(SIODriver *siop, const uint8_t *tx_buffer, size_t n) {

  uint8_t rx_buffer[16];
  size_t rx_bytes = 0;
  size_t tx_bytes = 0;

  osalDbgCheck(n <= sizeof(rx_buffer));

  osDelay(10);

  while (tx_bytes < n) {
    tx_bytes += sioAsyncWrite(siop, &tx_buffer[tx_bytes], n - tx_bytes);

    while (rx_bytes < tx_bytes) {
      rx_bytes += sioAsyncRead(siop, &rx_buffer[rx_bytes], n - rx_bytes);
    }
  }

  osalDbgCheck(tx_bytes == n);
  osalDbgCheck(rx_bytes == n);
}

static void test_synchronized_api(SIODriver *siop, const uint8_t *tx_buffer, size_t n) {

#if (SIO_USE_SYNCHRONIZATION == TRUE) || defined(__DOXYGEN__)
  msg_t msg;
  uint8_t rx_buffer[16];
  size_t rx_bytes = 0;
  size_t tx_bytes = 0;

  osalDbgCheck(n <= sizeof(rx_buffer));

  osDelay(10);

  while (tx_bytes < n) {
    tx_bytes += sioAsyncWrite(siop, &tx_buffer[tx_bytes], n - tx_bytes);
    msg = sioSynchronizeTXEnd(siop, TIME_INFINITE);
    osalDbgCheck(msg == MSG_OK);

    while (rx_bytes < tx_bytes) {
      msg = sioSynchronizeRX(siop, TIME_INFINITE);
      osalDbgCheck(msg == MSG_OK);
      rx_bytes += sioAsyncRead(siop, &rx_buffer[rx_bytes], n - rx_bytes);
    }
  }

  osalDbgCheck(tx_bytes == n);
  osalDbgCheck(rx_bytes == n);
#endif
}

static void test_vcom_eusart_slow(void) {

  SIODriver *siop = NULL;
  const SIOConfig sio_config = {
    .baud = 2400U,       /* Baudrate (2400 max. for LF operation) */
    .cfg0 = (0U <<  0) | /* ASYNC operation */
    (4U <<  5),  /* Disable oversampling (for LF operation) */
    .framecfg = EFR32_SIO_LLD_EUSART_8E1,
  };

  #if EFR32_SIO_USE_EUSART1 == TRUE
  palSetPadMode(GPIOA, 9, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART0_TX));
  palSetPadMode(GPIOA, 10, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART0_RX));

  siop = &SIOD1;
  sioStart(siop, &sio_config);
  test_synchronized_api(siop, (const uint8_t*)"\r\nEUSART1", 9);
  test_GetX_PutX(siop, '1');
  test_sioAsyncRead_sioAsyncWrite(siop, (const uint8_t*)"EUSART1", 7);
  osDelay(10);
  sioStop(siop);

  palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(EUSART0_TX_DIS));
  palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(EUSART0_RX_DIS));
  #endif

  #if EFR32_SIO_USE_EUSART2 == TRUE
  palSetPadMode(GPIOA, 9, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART1_TX));
  palSetPadMode(GPIOA, 10, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART1_RX));

  siop = &SIOD2;
  sioStart(siop, &sio_config);
  test_synchronized_api(siop, (const uint8_t*)"\r\nEUSART2", 9);
  test_GetX_PutX(siop, '2');
  test_sioAsyncRead_sioAsyncWrite(siop, (const uint8_t*)"EUSART2", 7);
  osDelay(10);
  sioStop(siop);

  palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(EUSART1_TX_DIS));
  palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(EUSART1_RX_DIS));
  #endif

  #if EFR32_SIO_USE_EUSART3 == TRUE
  osalDbgAssert(true, "Untestable since EUSART3 is only available on Port C and D which are not present on the board header.");
  #endif
}

/*
 * Application entry point.
 */
int main(void) {

  int unused = 0;
  (void)unused;

  /* HAL initialization, this also initializes the configured device drivers
     and performs the board-specific initializations.*/
  halInit();

  /* The kernel is initialized but not started yet, this means that
     main() is executing with absolute priority but interrupts are
     already enabled.*/
  osKernelInitialize();

  /* Kernel started, the main() thread has priority osPriorityNormal
     by default.*/
  osKernelStart();

  led_off();
  test_vcom_eusart_slow();
  led_on();

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    osDelay(1000);
  }
}

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

#include "cmsis_os.h"
#include "hal.h"
#include "chprintf.h"
#include "rt_test_root.h"
#include "oslib_test_root.h"

#include "emlib_chibios.h"

CC_USED CC_SECTION(".ram0")
static int no_init_variable;

CC_USED
static void gpio_callback(void* arg) {

  (void)arg;
  return;
}

static const SIOConfig sio_config = {
  #if 0
  .baud = 9600U,       /* Baudrate (9600 max. for LF operation) */
  .cfg0 = (0U <<  0) | /* ASYNC operation */
  (4U <<  5),  /* Disable oversampling (for LF operation) */
  #else
  .baud = 115200U,       /* Baudrate */
  .cfg0 = (0U <<  0) |   /* ASYNC operation */
  (0U <<  5),    /* 16x oversampling (for HF operation) */
  #endif
  .framecfg = (2U <<  0) | /* 8 data bits */
  (0U <<  8) | /* No parity */
  (1U << 12),  /* One stop bit*/
};

/*
 * Application entry point.
 */
int main(void) {

  /* HAL initialization, this also initializes the configured device drivers
     and performs the board-specific initializations.*/
  halInit();

  /* The kernel is initialized but not started yet, this means that
     main() is executing with absolute priority but interrupts are
     already enabled.*/
  osKernelInitialize();

  palSetPadMode(GPIOC, 3, PAL_MODE_INPUT_PULLUP);

  #if 0
  palSetPadMode(GPIOC, 3, PAL_MODE_OUTPUT_PUSHPULL);
  palWritePad(GPIOC, 3, PAL_HIGH);
  palWritePad(GPIOC, 3, PAL_LOW);
  palSetPad(GPIOC, 3);
  palClearPad(GPIOC, 3);
  palSetPad(GPIOC, 3);
  palTogglePad(GPIOC, 3);
  palTogglePad(GPIOC, 3);
  palSetPadMode(GPIOC, 3, PAL_MODE_RESET);

  palSetPadMode(GPIOC, 3, PAL_MODE_INPUT_PULLUP);
  uint32_t pins;
  (void)pins;
  pins = palReadPad(GPIOC, 3);
  pins = palReadPad(GPIOC, 3);

  palSetPadCallback(GPIOC, 3, gpio_callback, NULL);
  palEnablePadEvent(GPIOC, 3, PAL_EVENT_MODE_BOTH_EDGES);
  #endif

  #if 0
  //CMU_ClockEnable(cmuSelect_EM23GRPACLK, true);
  //CMU_Clock_TypeDef clock, CMU_Select_TypeDef ref
  //CMU_ClockSelectSet(cmuClock_EM23GRPACLK, cmuSelect_ULFRCO);
  //CMU_Clock_TypeDef clock, CMU_Select_TypeDef ref

  //CMU_ClkOutPinConfig(1, cmuSelect_LFRCO, 1U, gpioPortC, 3); // 32.768 Hz
  //CMU_ClkOutPinConfig(1, cmuSelect_LFXO, 1U, gpioPortC, 3); // ?? != 32.768 kHz
  //CMU_ClkOutPinConfig(1, cmuSelect_HCLK, 1U, gpioPortC, 3); // 19 MHz
  //CMU_ClkOutPinConfig(1, cmuSelect_FSRCO, 1U, gpioPortC, 3); // 20 Mhz
  //CMU_ClkOutPinConfig(1, cmuSelect_ULFRCO, 1U, gpioPortC, 3); // 1000 Hz
  //CMU_ClkOutPinConfig(1, cmuSelect_EM01GRPACLK, 1U, gpioPortC, 3);
  //CMU_ClkOutPinConfig(1, cmuSelect_EM01GRPCCLK, 1U, gpioPortC, 3);
  //CMU_ClkOutPinConfig(1, cmuSelect_EM23GRPACLK, 1U, gpioPortC, 3);

  //CMU_ClkOutPinConfig(0, cmuSelect_LFRCO, 1U, gpioPortC, 3);
  //CMU_ClkOutPinConfig(0, cmuSelect_LFRCO, 1U, gpioPortC, 2);
  //CMU_ClkOutPinConfig(0, cmuSelect_LFRCO, 1U, gpioPortC, 1);
  #endif

  SIODriver* siop = NULL;

  #if EFR32_SIO_USE_EUSART1 == TRUE
  palSetPadMode(GPIOC, 2, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART0_TX));
  palSetPadMode(GPIOC, 1, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART0_RX));

  siop = &SIOD1;
  sioStart(siop, &sio_config);
  sioStop(siop);
  sioStart(siop, &sio_config);
  #endif

  #if EFR32_SIO_USE_EUSART2 == TRUE
  palSetPadMode(GPIOC, 2, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART1_TX));
  palSetPadMode(GPIOC, 1, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART1_RX));

  siop = &SIOD2;
  sioStart(siop, &sio_config);
  sioStop(siop);
  sioStart(siop, &sio_config);
  #endif

  #if EFR32_SIO_USE_EUSART3 == TRUE
  palSetPadMode(GPIOC, 2, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART2_TX));
  palSetPadMode(GPIOC, 1, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART2_RX));

  siop = &SIOD3;
  sioStart(siop, &sio_config);
  sioStop(siop);
  sioStart(siop, &sio_config);
  #endif

  #if EFR32_SIO_USE_USART1 == TRUE
  palSetPadMode(GPIOC, 2, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(USART0_TX));
  palSetPadMode(GPIOC, 1, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(USART0_RX));

  siop = &SIOD4;
  sioStart(siop, &sio_config);
  sioStop(siop);
  sioStart(siop, &sio_config);
  #endif

  /* Kernel started, the main() thread has priority osPriorityNormal
     by default.*/
  osKernelStart();

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    //palDisablePadEvent(GPIOC, 3);
    if (siop != NULL) {
      if (palReadPad(GPIOC, 3) == PAL_LOW) {
        test_execute((BaseSequentialStream*)siop, &rt_test_suite);
        test_execute((BaseSequentialStream*)siop, &oslib_test_suite);
      }

      while (true) {
        msg_t msg;
        uint8_t buf[32];
      #if 0
        msg = sioGetX(siop);
        if (msg == MSG_TIMEOUT) break;
        sioPutX(siop, msg);
      #elif 0
        msg = sioSynchronizeRX(siop, TIME_MS2I(1000));
        if (msg == MSG_TIMEOUT)break;
        msg = sioGetX(siop);
        //osalDbgAssert(msg != MSG_TIMEOUT);
        sioPutX(siop, msg);
        msg = sioSynchronizeTXEnd(siop, TIME_MS2I(1000));
        //osalDbgAssert(msg == MSG_OK);
      #elif 1
        msg = sioSynchronizeRX(siop, TIME_MS2I(1000));
        if (msg == MSG_TIMEOUT) break;
        size_t rb = sioAsyncRead(siop, buf, sizeof(buf));
        if (rb > 0) {
          sioAsyncWrite(siop, buf, rb);
          msg = sioSynchronizeTX(siop, TIME_MS2I(1));
          //msg = sioSynchronizeTXEnd(siop, TIME_MS2I(1000));
        }
      #endif
      }

      //osDelay(1000);

    #if 0
      SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
      EMU_EnterEM2(true);
    #endif
    }
  }
}
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

  #if 0
  palSetPadMode(GPIOC, 3, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT0_HCLK));
  while (true);
  #endif

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

  #if EFR32_SIO_USE_EUSART1 == TRUE
  #if 0
  palSetPadMode(GPIOC, 2, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART0_TX));
  palSetPadMode(GPIOC, 1, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART0_RX));
  #else
  palSetPadMode(GPIOB, 1, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART0_TX));
  palSetPadMode(GPIOB, 2, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART0_RX));
  #endif

  static const SIOConfig sio_config1 = {
    #if 1
    .baud = 9600U,       /* Baudrate (9600 max. for LF operation) */
    .cfg0 = (0U <<  0) | /* ASYNC operation */
            (4U <<  5),  /* Disable oversampling (for LF operation) */
    .framecfg = EFR32_SIO_LLD_EUSART_8E1,
    #else
    .baud = 115200U,       /* Baudrate */
    .cfg0 = (0U <<  0) |   /* ASYNC operation */
            (0U <<  5),    /* 16x oversampling (for HF operation) */
    .framecfg = EFR32_SIO_LLD_EUSART_8N1,
    #endif
  };

  SIODriver* siop = &SIOD1;
  sioStart(siop, &sio_config1);
  sioStop(siop);
  sioStart(siop, &sio_config1);
  #endif

  #if EFR32_SIO_USE_EUSART2 == TRUE
  palSetPadMode(GPIOC, 2, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART1_TX));
  palSetPadMode(GPIOC, 1, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART1_RX));

  static const SIOConfig sio_config2 = {
    .baud = 115200U,       /* Baudrate */
    .cfg0 = (0U <<  0) |   /* ASYNC operation */
            (0U <<  5),    /* 16x oversampling (for HF operation) */
    .framecfg = EFR32_SIO_LLD_EUSART_8N1,
  };

  SIODriver* siop = &SIOD2;
  sioStart(siop, &sio_config2);
  sioStop(siop);
  sioStart(siop, &sio_config2);
  #endif

  #if EFR32_SIO_USE_EUSART3 == TRUE
  palSetPadMode(GPIOC, 2, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART2_TX));
  palSetPadMode(GPIOC, 1, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART2_RX));

  static const SIOConfig sio_config3 = {
    .baud = 115200U,       /* Baudrate */
    .cfg0 = (0U <<  0) |   /* ASYNC operation */
            (0U <<  5),    /* 16x oversampling (for HF operation) */
    .framecfg = EFR32_SIO_LLD_EUSART_8N1,
  };

  SIODriver* siop = &SIOD3;
  sioStart(siop, &sio_config3);
  sioStop(siop);
  sioStart(siop, &sio_config3);
  #endif

  #if EFR32_SIO_USE_USART1 == TRUE
  #if 1
  palSetPadMode(GPIOC, 2, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(USART0_TX));
  palSetPadMode(GPIOC, 1, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(USART0_RX));
  #else
  palSetPadMode(GPIOB, 1, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(USART0_TX));
  palSetPadMode(GPIOB, 2, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(USART0_RX));
  #endif

  static const SIOConfig sio_config4 = {
    .baud = 115200U,       /* Baudrate */
    .cfg0 = (0U <<  0) |   /* ASYNC operation */
            (0U <<  5),    /* 16x oversampling (for HF operation) */
    .framecfg = EFR32_SIO_LLD_USART_8N1,
  };

  SIODriver* siop = &SIOD4;
  sioStart(siop, &sio_config4);
  sioStop(siop);
  sioStart(siop, &sio_config4);
  #endif

  /* Kernel started, the main() thread has priority osPriorityNormal
     by default.*/
  osKernelStart();

    RTCDateTime ts = {
      .year = 44,
      .month = 6,
      .dstflag = 0,
      .dayofweek = 7,
      .day = 9,
      .millisecond = (19*3600 + 4*60 + 30) * 1000 + 123
    };
    rtcSetTime(&RTCD1, &ts);
    struct tm tim;
    uint32_t tv_msec;

    RTCAlarm alarmspec = { 
      .sec = 5,
    };
    rtcSetAlarm(&RTCD1, 0, &alarmspec);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    //palDisablePadEvent(GPIOC, 3);
    #if 1
    //osDelay(1000);
    rtcGetAlarm(&RTCD1, 0, &alarmspec);
    rtcGetTime(&RTCD1, &ts);
    rtcConvertDateTimeToStructTm(&ts, &tim, &tv_msec);
    chprintf((BaseSequentialStream*)siop, "%02u-%02u-%02u %02u:%02u:%02u, %d\r\n",
             tim.tm_year + 1900, tim.tm_mon + 1, tim.tm_mday,
             tim.tm_hour, tim.tm_min, tim.tm_sec, tim.tm_wday);
    //chprintf((BaseSequentialStream*)tm_mon  siop, "%u\r\n", ts2.millisecond);
    //continue;                         
    #endif                            
    if (siop != NULL) {               
      #if 0
      // Don't execute tests.
      palSetPadMode(GPIOC, 3, PAL_MODE_INPUT_PULLUP);
      if (palReadPad(GPIOC, 3) == PAL_LOW) {
        test_execute((BaseSequentialStream*)siop, &rt_test_suite);
        test_execute((BaseSequentialStream*)siop, &oslib_test_suite);
      }
      #endif

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
        if (msg == SIO_MSG_ERRORS) {
          sioGetAndClearErrors(siop);
          break;
        }
        if (msg == MSG_TIMEOUT) break;
        size_t rb = sioAsyncRead(siop, buf, sizeof(buf));
        if (rb > 0) {
          sioAsyncWrite(siop, buf, rb);
          msg = sioSynchronizeTX(siop, TIME_MS2I(1));
          //msg = sioSynchronizeTXEnd(siop, TIME_MS2I(1000));
        }
      #elif 0
        buf[0] = '5A';
        sioAsyncWrite(siop, buf, 1);
        msg = sioSynchronizeTX(siop, TIME_MS2I(1));
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
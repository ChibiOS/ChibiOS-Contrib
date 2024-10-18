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

#include "em_device.h"
#include "rail_types.h"
#include "rail.h"

#if 0
static uint8_t payload_C_MODE_FRAME_B[] ={   0x54, 0x3D, 0x54, 0x3D, // Sync Byte_1 to Sync Byte_4  for C-Mode, Frame-B
  0x2F, 0x44, 0xC5, 0x14, 0x89, 0x42, 0x61, 0x20, 0x31, 0x08, 0x7A, 0x53, 0x0B, 0x00, 0x20, 0x2F,
  0x2F, 0x04, 0x6D, 0x34, 0x2C, 0xD3, 0x2A, 0x03, 0x6E, 0x00, 0x00, 0x00, 0x42, 0x6C, 0x00, 0x00,
  0x43, 0x6E, 0x00, 0x00, 0x00, 0x31, 0x7F, 0x08, 0x34, 0x6D, 0x19, 0x31, 0xDE, 0x29, 0xF0, 0x50
};

static uint8_t payload_C_MODE_FRAME_A[] ={   0x54, 0x3D, 0x54, 0xCD, // Sync Byte_1 to Sync Byte_4 for C Mode, Frame A
  0x31, 0x44, 0x93, 0x44, 0x48, 0x32, 0x75, 0x26, 0x35, 0x08, 0x6D, 0x95, 0x7A, 0xA3, 0x00, 0x00,
  0x20, 0x0B, 0x6E, 0x16, 0x00, 0x00, 0x4B, 0x6E, 0x21, 0x02, 0x00, 0x42, 0x91, 0xDD, 0x6C, 0xBF,
  0x2A, 0xCB, 0x08, 0x6E, 0x16, 0x00, 0x00, 0xC2, 0x08, 0x6C, 0xDE, 0x29, 0x32, 0x6C, 0x8C, 0xC4,
  0xFF, 0xFF, 0x04, 0x6D, 0x27, 0x0E, 0xD2, 0x2A, 0x3D, 0x89
};
#endif

static uint8_t payload_C_MODE_FRAME[] =
{ 0x31, 0x44, 0x93, 0x44, 0x48, 0x32, 0x75, 0x26, 0x35, 0x08, // 0x6D, 0x95,
  0x7A, 0xA3, 0x00, 0x00, 0x20, 0x0B, 0x6E, 0x16, 0x00, 0x00, 0x4B, 0x6E, 0x21, 0x02, 0x00, 0x42, // 0x91, 0xDD,
  0x6C, 0xBF, 0x2A, 0xCB, 0x08, 0x6E, 0x16, 0x00, 0x00, 0xC2, 0x08, 0x6C, 0xDE, 0x29, 0x32, 0x6C, // 0x8C, 0xC4,
  0xFF, 0xFF, 0x04, 0x6D, 0x27, 0x0E, 0xD2, 0x2A, // 0x3D, 0x89
};

CC_ALIGN_DATA(16) static uint8_t railFifo[1024];

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

#if 0
typedef enum {
  __X = 0, } CMU_Clock_TypeDef;

typedef syssts_t CORE_irqState_t;

typedef struct {
  uint8_t minor;       /**< Minor revision number. */
  uint8_t major;       /**< Major revision number. */
#if defined(_SYSCFG_CHIPREV_PARTNUMBER_MASK)
  uint16_t partNumber; /**< Device part number.    */
#else
  uint8_t family;      /**< Device family number.  */
#endif
} SYSTEM_ChipRevision_TypeDef;

uint32_t SystemHFXOClockGet(void) {

  return __X;
}

uint32_t SystemHFRCODPLLClockGet(void) {

  return __X;
}

uint32_t SystemSYSCLKGet(void) {

  return EFR32_HFXO_FREQ;
}

void CMU_ClockEnable(CMU_Clock_TypeDef clock, bool enable) {

  // Set breakpoint and debug into, what clock and enable will be here.
  return;
}

void SYSTEM_ChipRevisionGet(SYSTEM_ChipRevision_TypeDef *rev) {

  CMU->CLKEN0_SET = CMU_CLKEN0_SYSCFG;
  uint32_t chiprev = SYSCFG->CHIPREV;

#if defined(_SYSCFG_CHIPREV_PARTNUMBER_MASK)
  rev->partNumber = ((chiprev & SYSCFG_CHIPREV_PARTNUMBER1) >> 5) | (chiprev & SYSCFG_CHIPREV_PARTNUMBER0);
#else
  rev->family = (chiprev & _SYSCFG_CHIPREV_FAMILY_MASK) >> _SYSCFG_CHIPREV_FAMILY_SHIFT;
#endif
  rev->major  = (chiprev & _SYSCFG_CHIPREV_MAJOR_MASK) >> _SYSCFG_CHIPREV_MAJOR_SHIFT;
  rev->minor  = (chiprev & _SYSCFG_CHIPREV_MINOR_MASK) >> _SYSCFG_CHIPREV_MINOR_SHIFT;

  return;
}

uint32_t sli_tz_syscfg_read_chiprev_register(void)
{
  return SYSCFG->CHIPREV;
}
#endif

void _eventsCallback(RAIL_Handle_t railHandle, RAIL_Events_t events) {

  (void)railHandle;
  (void)events;

  return;
}

void RAIL_InitCompleteCallback(RAIL_Handle_t railHandle) {

  (void)railHandle;

  return;
}

void st_callback(unsigned alarm) {

  stStopAlarmN(alarm);
  stStartAlarmN(alarm, stGetCounter() + chTimeMS2I(3000));
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
  led_on();

  stSetCallback(1, st_callback);
  //stStartAlarmN(1, stGetCounter() + chTimeMS2I(3000));

  RAIL_Config_t railCfg = { .eventsCallback = _eventsCallback };
  RAIL_Handle_t railHandle = RAIL_Init(&railCfg, RAIL_InitCompleteCallback);

  //RAIL_SetFixedLength(railHandle, RAIL_SETFIXEDLENGTH_INVALID);
  //RAIL_WriteTxFifo(railHandle, payload_C_MODE_FRAME, sizeof(payload_C_MODE_FRAME), true);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    osDelay(2000);

    #if 0
    #define RAIL_CHANNEL_0  0
    memcpy(railFifo, payload_C_MODE_FRAME, sizeof(payload_C_MODE_FRAME));
    RAIL_SetTxFifo(railHandle, railFifo, sizeof(payload_C_MODE_FRAME), sizeof(railFifo));
    RAIL_StartTx(railHandle, RAIL_CHANNEL_0, RAIL_TX_OPTIONS_DEFAULT, NULL);
    #endif
  }
}


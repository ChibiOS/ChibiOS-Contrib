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

#include "rail.h"
#include "sli_rail_util_callbacks.h" // for internal-only callback signatures
#include "sl_rail_util_init.h"
#include "sl_rail_util_protocol.h"

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

static void led_toggle(void) {

  /* PB2 = LED */
  palTogglePad(GPIOB, 2);
}

void st_callback(unsigned alarm) {

  stStopAlarmN(alarm);
  stStartAlarmN(alarm, stGetCounter() + chTimeMS2I(3000));
}

extern const RAIL_ChannelConfig_t *channelConfigs[];

static RAIL_Handle_t railHandle;

static void send_datagram(void) {

  static const uint8_t wmbus_datagram_1[] = {
    0x31, 0x44, 0x93, 0x44, 0x48, 0x32, 0x75, 0x26, 0x35, 0x08, // 0x6D, 0x95,
    0x7A, 0xA3, 0x00, 0x00, 0x20, 0x0B, 0x6E, 0x16, 0x00, 0x00, 0x4B, 0x6E, 0x21, 0x02, 0x00, 0x42, // 0x91, 0xDD,
    0x6C, 0xBF, 0x2A, 0xCB, 0x08, 0x6E, 0x16, 0x00, 0x00, 0xC2, 0x08, 0x6C, 0xDE, 0x29, 0x32, 0x6C, // 0x8C, 0xC4,
    0xFF, 0xFF, 0x04, 0x6D, 0x27, 0x0E, 0xD2, 0x2A, // 0x3D, 0x89
  };

  CC_ALIGN_DATA(16)static uint8_t railFifo[1024];

  led_toggle();

  #define RAIL_CHANNEL_0  0
  memcpy(railFifo, wmbus_datagram_1, sizeof(wmbus_datagram_1));
  RAIL_SetTxFifo(railHandle, railFifo, sizeof(wmbus_datagram_1), sizeof(railFifo));
  RAIL_StartTx(railHandle, RAIL_CHANNEL_0, RAIL_TX_OPTIONS_DEFAULT, NULL);
}

/* Overload weak function from sl_rail_util_callbacks.c. */
void sl_rail_util_on_assert_failed(RAIL_Handle_t rail_handle,
                                   RAIL_AssertErrorCodes_t error_code) {

  (void)rail_handle;
  (void)error_code;
  osalDbgAssert(false, "rail_handle with error_code");
}

/* Overload weak function from sl_rail_util_callbacks.c. */
void sl_rail_util_on_rf_ready(RAIL_Handle_t rail_handle) {

  (void)rail_handle;
}

/* Overload weak function from sl_rail_util_callbacks.c. */
void sl_rail_util_on_channel_config_change(RAIL_Handle_t rail_handle,
                                           const RAIL_ChannelConfigEntry_t *entry) {

  (void)rail_handle;
  (void)entry;
}

/* Overload weak function from sl_rail_util_callbacks.c. */
void sl_rail_util_on_event(RAIL_Handle_t rail_handle,
                           RAIL_Events_t events) {

  (void)rail_handle;
  (void)events;
}

void custom_RAIL_Init(void) {

  enum {
    WMBUS_MODE_T1A = 0,
    WMBUS_MODE_C1A = 1,
    WMBUS_MODE_S1 = 2
  };

  RAIL_Status_t status;

  RAIL_Config_t sl_rail_config = {
    .eventsCallback = &sli_rail_util_on_event,
    // Other fields are ignored nowadays
  };

  railHandle = RAIL_Init(&sl_rail_config,
                         &sli_rail_util_on_rf_ready);

  RAIL_DataConfig_t data_config = {
    .txSource = SL_RAIL_UTIL_INIT_DATA_FORMAT_INST0_TX_SOURCE,
    .rxSource = SL_RAIL_UTIL_INIT_DATA_FORMAT_INST0_RX_SOURCE,
    .txMethod = SL_RAIL_UTIL_INIT_DATA_FORMAT_INST0_TX_MODE,
    .rxMethod = SL_RAIL_UTIL_INIT_DATA_FORMAT_INST0_RX_MODE,
  };
  status = RAIL_ConfigData(railHandle, &data_config);

  const RAIL_ChannelConfig_t *channel_config = channelConfigs[WMBUS_MODE_C1A];

  (void)RAIL_ConfigChannels(railHandle,
                            channel_config,
                            &sli_rail_util_on_channel_config_change);
  status = sl_rail_util_protocol_config(railHandle,
                                        SL_RAIL_UTIL_INIT_PROTOCOL_INST0_DEFAULT);

  status = RAIL_ConfigCal(railHandle,
                          0U
                          | (SL_RAIL_UTIL_INIT_CALIBRATION_TEMPERATURE_NOTIFY_INST0_ENABLE
                             ? RAIL_CAL_TEMP : 0U)
                          | (SL_RAIL_UTIL_INIT_CALIBRATION_ONETIME_NOTIFY_INST0_ENABLE
                             ? RAIL_CAL_ONETIME : 0U));
  status = RAIL_ConfigEvents(railHandle,
                             RAIL_EVENTS_ALL,
                             SL_RAIL_UTIL_INIT_EVENT_INST0_MASK);

  RAIL_StateTransitions_t tx_transitions = {
    .success = SL_RAIL_UTIL_INIT_TRANSITION_INST0_TX_SUCCESS,
    .error = SL_RAIL_UTIL_INIT_TRANSITION_INST0_TX_ERROR
  };
  RAIL_StateTransitions_t rx_transitions = {
    .success = SL_RAIL_UTIL_INIT_TRANSITION_INST0_RX_SUCCESS,
    .error = SL_RAIL_UTIL_INIT_TRANSITION_INST0_RX_ERROR
  };
  status = RAIL_SetTxTransitions(railHandle,
                                 &tx_transitions);
  status = RAIL_SetRxTransitions(railHandle,
                                 &rx_transitions);
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
  custom_RAIL_Init();
  stSetCallback(1, st_callback);
  stStartAlarmN(1, stGetCounter() + chTimeMS2I(3000));
  led_on();

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    osDelay(3000);
    send_datagram();
  }
}


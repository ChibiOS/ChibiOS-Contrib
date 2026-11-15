/***************************************************************************//**
 * @file
 * @brief
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
#include "rail.h"
#include "rail_ble.h" // for RAIL_BLE_State_t
#include "sli_rail_util_callbacks.h" // for internal-only callback signatures
#include "sl_rail_util_init.h"
#include "sl_rail_util_protocol.h"
#if defined(SL_COMPONENT_CATALOG_PRESENT)
#include "sl_component_catalog.h"
#endif

#if defined(SL_CATALOG_TIMING_TEST_PRESENT) && !SL_RAIL_LIB_MULTIPROTOCOL_SUPPORT
// Needed for measuring RAIL_Init() time as a part of 
// detailed timing characterization.
#include "em_device.h"
#if defined(_SILICON_LABS_32B_SERIES_2)
#include "em_timer.h"
#else
#include "sl_hal_timer.h"
#endif // defined(_SILICON_LABS_32B_SERIES_2)

#if defined(SL_CATALOG_CLOCK_MANAGER_PRESENT)
#include "sl_clock_manager.h"
#else
#include "em_cmu.h"
#endif //defined(SL_CATALOG_CLOCK_MANAGER_PRESENT)
#endif //defined(SL_CATALOG_TIMING_TEST_PRESENT) && !SL_RAIL_LIB_MULTIPROTOCOL_SUPPORT

#ifdef SL_CATALOG_APP_ASSERT_PRESENT
#include "app_assert.h"
#define APP_ASSERT(expr, ...) app_assert(expr,__VA_ARGS__)
#else
#define APP_ASSERT(expr, ...) \
  do {                        \
    if (!(expr)) {            \
      while (1) ;             \
    }                         \
  } while (0)
#endif

#if 0U \
  || SL_RAIL_UTIL_INIT_RADIO_CONFIG_SUPPORT_INST0_ENABLE \
  || 0U
  #include "rail_config.h"
#endif

// Instance: inst0
static RAIL_Handle_t sl_rail_handle_inst0 = RAIL_EFR32_HANDLE;

#if defined(SL_CATALOG_TIMING_TEST_PRESENT) && !SL_RAIL_LIB_MULTIPROTOCOL_SUPPORT
uint32_t sli_timing_start_tick = 0U;
uint32_t sli_timing_end_tick = 0U;
static TIMER_TypeDef *timer = TIMER0;
static void setupTimingTestTimer(void)
{
// Clock TIMER0 using the HF clock
#ifndef SL_CATALOG_CLOCK_MANAGER_PRESENT
  CMU_CLOCK_SELECT_SET(TIMER0, HFXO);
  CMU_ClockEnable(cmuClock_TIMER0, true);
  // Use default configuration, prescaled by 8.
  TIMER_Init_TypeDef timerCfg = TIMER_INIT_DEFAULT;
  timerCfg.prescale = timerPrescale8;
  // Enable TIMER0 to upcount
  TIMER_Init(timer, &timerCfg);
#else
  sl_clock_manager_enable_bus_clock(SL_BUS_CLOCK_TIMER0);
  sl_hal_timer_config_t timerCfg = SL_HAL_TIMER_CONFIG_DEFAULT;
  // Use default configuration, prescaled by 8.
  timerCfg.prescaler = TIMER_CFG_PRESC_DIV8;
   // Enable TIMER0 to upcount
  sl_hal_timer_init(timer, &timerCfg);
#endif //SL_CATALOG_CLOCK_MANAGER_PRESENT
}
#endif

static void sl_rail_util_init_inst0(void)
{
#if SL_RAIL_UTIL_INIT_INST0_ENABLE
  RAIL_Status_t status;
  RAIL_Config_t sl_rail_config = {
    .eventsCallback = &sli_rail_util_on_event,
    // Other fields are ignored nowadays
  };
  (void) status; // Suppress compiler warning if status ends up unused
#ifdef SL_CATALOG_TIMING_TEST_PRESENT
  setupTimingTestTimer();
  sli_timing_start_tick = timer->CNT;
#endif // SL_CATALOG_TIMING_TEST_PRESENT
  sl_rail_handle_inst0 = RAIL_Init(&sl_rail_config,
#if SL_RAIL_UTIL_INIT_INIT_COMPLETE_CALLBACK_INST0_ENABLE
                             &sli_rail_util_on_rf_ready
#else
                             NULL
#endif // SL_RAIL_UTIL_INIT_INIT_COMPLETE_CALLBACK_INST0_ENABLE
                             );
#ifdef SL_CATALOG_TIMING_TEST_PRESENT
  sli_timing_end_tick = timer->CNT;
#endif // SL_CATALOG_TIMING_TEST_PRESENT
  APP_ASSERT((NULL != sl_rail_handle_inst0),
             "RAIL_Init failed, return value: NULL");

#if SL_RAIL_UTIL_INIT_DATA_FORMATS_INST0_ENABLE
  RAIL_DataConfig_t data_config = {
    .txSource = SL_RAIL_UTIL_INIT_DATA_FORMAT_INST0_TX_SOURCE,
    .rxSource = SL_RAIL_UTIL_INIT_DATA_FORMAT_INST0_RX_SOURCE,
    .txMethod = SL_RAIL_UTIL_INIT_DATA_FORMAT_INST0_TX_MODE,
    .rxMethod = SL_RAIL_UTIL_INIT_DATA_FORMAT_INST0_RX_MODE,
  };
  status = RAIL_ConfigData(sl_rail_handle_inst0, &data_config);
  APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
             "RAIL_ConfigData failed, return value: %d",
             status);
#endif // SL_RAIL_UTIL_INIT_DATA_FORMATS_INST0_ENABLE

#if SL_RAIL_UTIL_INIT_PROTOCOLS_INST0_ENABLE
  const RAIL_ChannelConfig_t *channel_config = NULL;
  if (SL_RAIL_UTIL_INIT_PROTOCOL_INST0_DEFAULT
      == SL_RAIL_UTIL_PROTOCOL_PROPRIETARY) {
#if SL_RAIL_UTIL_INIT_RADIO_CONFIG_SUPPORT_INST0_ENABLE
    channel_config = channelConfigs[SL_RAIL_UTIL_INIT_PROTOCOL_PROPRIETARY_INST0_INDEX];
#else // !SL_RAIL_UTIL_INIT_RADIO_CONFIG_SUPPORT_INST0_ENABLE
    APP_ASSERT(false,
               "SL_RAIL_UTIL_INIT_RADIO_CONFIG_SUPPORT_INST0_ENABLE must be true when (SL_RAIL_UTIL_INIT_PROTOCOL_INST0_DEFAULT == SL_RAIL_UTIL_PROTOCOL_PROPRIETARY)");
#endif // SL_RAIL_UTIL_INIT_RADIO_CONFIG_SUPPORT_INST0_ENABLE
  }
  (void) RAIL_ConfigChannels(sl_rail_handle_inst0,
                             channel_config,
                             &sli_rail_util_on_channel_config_change);
  status = sl_rail_util_protocol_config(sl_rail_handle_inst0,
                                        SL_RAIL_UTIL_INIT_PROTOCOL_INST0_DEFAULT);
  APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
             "sl_rail_util_protocol_config failed, return value: %d",
             status);
#endif // SL_RAIL_UTIL_INIT_PROTOCOLS_INST0_ENABLE

#if SL_RAIL_UTIL_INIT_CALIBRATIONS_INST0_ENABLE
  status = RAIL_ConfigCal(sl_rail_handle_inst0,
                          0U
                          | (SL_RAIL_UTIL_INIT_CALIBRATION_TEMPERATURE_NOTIFY_INST0_ENABLE
                             ? RAIL_CAL_TEMP : 0U)
                          | (SL_RAIL_UTIL_INIT_CALIBRATION_ONETIME_NOTIFY_INST0_ENABLE
                             ? RAIL_CAL_ONETIME : 0U));
  APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
             "RAIL_ConfigCal failed, return value: %d",
             status);
#endif // SL_RAIL_UTIL_INIT_CALIBRATIONS_INST0_ENABLE

#if SL_RAIL_UTIL_INIT_EVENTS_INST0_ENABLE
  status = RAIL_ConfigEvents(sl_rail_handle_inst0,
                             RAIL_EVENTS_ALL,
                             SL_RAIL_UTIL_INIT_EVENT_INST0_MASK);
  APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
             "RAIL_ConfigEvents failed, return value: %d",
             status);
#endif // SL_RAIL_UTIL_INIT_EVENTS_INST0_ENABLE

#if SL_RAIL_UTIL_INIT_TRANSITIONS_INST0_ENABLE
  RAIL_StateTransitions_t tx_transitions = {
    .success = SL_RAIL_UTIL_INIT_TRANSITION_INST0_TX_SUCCESS,
    .error = SL_RAIL_UTIL_INIT_TRANSITION_INST0_TX_ERROR
  };
  RAIL_StateTransitions_t rx_transitions = {
    .success = SL_RAIL_UTIL_INIT_TRANSITION_INST0_RX_SUCCESS,
    .error = SL_RAIL_UTIL_INIT_TRANSITION_INST0_RX_ERROR
  };
  status = RAIL_SetTxTransitions(sl_rail_handle_inst0,
                                 &tx_transitions);
  APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
             "RAIL_SetTxTransitions failed, return value: %d",
             status);
  status = RAIL_SetRxTransitions(sl_rail_handle_inst0,
                                 &rx_transitions);
  APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
             "RAIL_SetRxTransitions failed, return value: %d",
             status);
#endif // SL_RAIL_UTIL_INIT_TRANSITIONS_INST0_ENABLE
#else // !SL_RAIL_UTIL_INIT_INST0_ENABLE
  // Eliminate compiler warnings.
  (void) sl_rail_handle_inst0;
#endif // SL_RAIL_UTIL_INIT_INST0_ENABLE
}

RAIL_Handle_t sl_rail_util_get_handle(sl_rail_util_handle_type_t handle)
{
  RAIL_Handle_t *sl_rail_handle_array[] = {
    &sl_rail_handle_inst0,
  };
  return *sl_rail_handle_array[handle];
}

#define INIT_INSTANCES (0 + 1)

#if (INIT_INSTANCES > 1) && !SL_RAIL_LIB_MULTIPROTOCOL_SUPPORT
  #error "sl_rail_util_init.c: If you are going to use more than one rail_util_init instance, you must use the Multiprotocol RAIL library."
#elif (INIT_INSTANCES > 4)
  static uint64_t extraStateBuffers[INIT_INSTANCES - 4][RAIL_STATE_BUFFER_BYTES / sizeof(uint64_t)];
  static RAIL_StateBufferEntry_t extraProtos[INIT_INSTANCES - 4];
#else
  // RAIL provides enough built-in state buffers for all the instances
#endif

void sl_rail_util_init(void)
{
#if   (INIT_INSTANCES > 2)
  RAIL_Status_t status;
  status = RAIL_AddStateBuffer3(RAIL_EFR32_HANDLE);
  APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
             "RAIL_AddStateBuffer3 failed, return value: %d",
             status);
#if   (INIT_INSTANCES > 3)
  status = RAIL_AddStateBuffer4(RAIL_EFR32_HANDLE);
  APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
             "RAIL_AddStateBuffer4 failed, return value: %d",
             status);
#endif
#if   (INIT_INSTANCES > 4)
  for (int i = 0; i < (INIT_INSTANCES - 4); i++) {
    extraProtos[i].bufferBytes = sizeof(extraStateBuffers[0]);
    extraProtos[i].buffer = extraStateBuffers[i];
    status = RAIL_AddStateBuffer(RAIL_EFR32_HANDLE, &extraProtos[i]);
    APP_ASSERT((RAIL_STATUS_NO_ERROR == status),
               "RAIL_AddStateBuffer(%d) failed, return value: %d",
               (INIT_INSTANCES + i), status);
  }
#endif
#endif
  sl_rail_util_init_inst0();
}

 /***************************************************************************//**
 * @file sl_rail_util_callbacks.c
 * @brief RAIL Callbacks
 *   WARNING: Auto-Generated Radio Callbacks  -  DO NOT EDIT
 *            Any application code placed within this file will be discarged
 *            upon project regeneration.
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
#include "sl_component_catalog.h"
#ifdef SL_CATALOG_APP_ASSERT_PRESENT
#include "app_assert.h"
#define APP_ASSERT(expr, ...) app_assert(expr,__VA_ARGS__)
#else
 #define APP_ASSERT(expr, string ,rail_handle, error_code) \
  do {                         \
    if (!(expr)) {             \
      while (1) ;              \
    }                          \
  } while (0)
#endif
#include "sl_rail_util_callbacks_config.h"
#include "pa_conversions_efr32.h"

// Provide weak function called by callback RAILCb_AssertFailed.
__WEAK
void sl_rail_util_on_assert_failed(RAIL_Handle_t rail_handle,
                                   RAIL_AssertErrorCodes_t error_code)
{
  (void) rail_handle;
  (void) error_code;
  APP_ASSERT(false,
             "rail_handle: 0x%X, error_code: %d",
             rail_handle,
             error_code);
}

#if SL_RAIL_UTIL_CALLBACKS_ASSERT_FAILED_OVERRIDE
// Note: RAILCb_AssertFailed is called directly by the RAIL library when
// needed, so maintain this exact function signature.
void RAILCb_AssertFailed(RAIL_Handle_t rail_handle,
                         RAIL_AssertErrorCodes_t error_code)
{
  sl_rail_util_on_assert_failed(rail_handle, error_code);
}
#endif

// Provide weak function called by callback sli_rail_util_on_rf_ready.
__WEAK
void sl_rail_util_on_rf_ready(RAIL_Handle_t rail_handle)
{
  (void) rail_handle;
}

// Internal-only callback set up through call to RAIL_Init().
void sli_rail_util_on_rf_ready(RAIL_Handle_t rail_handle)
{
  sl_rail_util_on_rf_ready(rail_handle);
}

// Provide weak function called by callback
// sli_rail_util_on_channel_config_change.
__WEAK
void sl_rail_util_on_channel_config_change(RAIL_Handle_t rail_handle,
                                           const RAIL_ChannelConfigEntry_t *entry)
{
  (void) rail_handle;
  (void) entry;
}

// Internal-only callback set up through call to RAIL_ConfigChannels().
void sli_rail_util_on_channel_config_change(RAIL_Handle_t rail_handle,
                                            const RAIL_ChannelConfigEntry_t *entry)
{
  sl_rail_util_pa_on_channel_config_change(rail_handle, entry);
  sl_rail_util_on_channel_config_change(rail_handle, entry);
}

// Provide weak function called by callback sli_rail_util_on_event.
__WEAK
void sl_rail_util_on_event(RAIL_Handle_t rail_handle,
                           RAIL_Events_t events)
{
  (void) rail_handle;
  (void) events;
}

// Internal-only callback set up through call to RAIL_Init().
void sli_rail_util_on_event(RAIL_Handle_t rail_handle,
                            RAIL_Events_t events)
{
  sl_rail_util_on_event(rail_handle, events);
}

/***************************************************************************//**
 * @file
 * @brief Simple Button Driver Configuration
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_SIMPLE_BUTTON_CONFIG_H
#define SL_SIMPLE_BUTTON_CONFIG_H

#include "em_gpio.h"
// <<< Use Configuration Wizard in Context Menu >>>

// <h> Simple Button Driver Configuration

// <o SL_SIMPLE_BUTTON_DEBOUNCE_BITS> Number of bits <1-15>
// <i> Default: 5
// <i> Defines the number of calls to sl_simple_button_poll_step wherein the button
// <i> state must remain the same before the button state is considered debounced
#define SL_SIMPLE_BUTTON_DEBOUNCE_BITS    5U

// <o SL_SIMPLE_BUTTON_GPIO_MODE>
// <gpioModeInput=> GPIO Input
// <gpioModeInputPull=> GPIO Input Pull
// <gpioModeInputPullFilter=> GPIO Input Pull Filter
// <i> Default: gpioModeInput
#define SL_SIMPLE_BUTTON_GPIO_MODE        gpioModeInput

// <q SL_SIMPLE_BUTTON_GPIO_DOUT>
// <i> SL_SIMPLE_BUTTON_GPIO_MODE == gpioModeInput, Filter if DOUT is set
// <i> SL_SIMPLE_BUTTON_GPIO_MODE == gpioModeInputPull, DOUT determines pull direction
// <i> SL_SIMPLE_BUTTON_GPIO_MODE == gpioModeInputPullFilter, DOUT determines pull direction
#define SL_SIMPLE_BUTTON_GPIO_DOUT        0U

// <q SL_SIMPLE_BUTTON_POLARITY>
// <i> 0  Active Low
// <i> 1  Active High
// <i> Default: 0
#define SL_SIMPLE_BUTTON_POLARITY         0U

// <q SL_SIMPLE_BUTTON_ALLOW_LED_CONFLICT> Allow the app to manage Buttons and LEDs on the same pin
// <i> 0  Error if Buttons and LEDs are on the same pin
// <i> 1  Do not error if Buttons and LEDs are on the same pin
// <i> Default: 0
#define SL_SIMPLE_BUTTON_ALLOW_LED_CONFLICT  0U

// </h>

// <<< end of configuration section >>>
#endif // SL_SIMPLE_BUTTON_CONFIG_H

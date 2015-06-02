/*
    Copyright (C) 2015 Fabio Utzig

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

/**
 * @file    pal_lld.c
 * @brief   NRF51822 PAL subsystem low level driver source.
 *
 * @addtogroup PAL
 * @{
 */

#include "osal.h"
#include "hal.h"

#if (HAL_USE_PAL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

void _pal_lld_setpadmode(uint8_t pad, iomode_t mode)
{
  uint8_t value = 0;

  osalDbgAssert(pad < 32, "invalid pad");

  switch (mode) {
  case PAL_MODE_RESET:
  case PAL_MODE_UNCONNECTED:
    value = 2;
    break;
  case PAL_MODE_INPUT:
  case PAL_MODE_INPUT_ANALOG:
    value = 0;
    break;
  case PAL_MODE_INPUT_PULLUP:
    value = 0xC;
    break;
  case PAL_MODE_INPUT_PULLDOWN:
    value = 4;
    break;
  case PAL_MODE_OUTPUT_PUSHPULL:
    value = 1;
    break;
  case PAL_MODE_OUTPUT_OPENDRAIN:
    value = 0x61;
    break;
  }

  NRF_GPIO->PIN_CNF[pad] = value;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   STM32 I/O ports configuration.
 * @details Ports A-D(E, F, G, H) clocks enabled.
 *
 * @param[in] config    the STM32 ports configuration
 *
 * @notapi
 */
void _pal_lld_init(const PALConfig *config)
{
  uint8_t i;

  for (i = 0; i < TOTAL_GPIO_PADS; i++) {
    pal_lld_setpadmode(IOPORT1, i, config->pads[i]);
  }
}

/**
 * @brief   Pads mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 *
 * @param[in] port      the port identifier
 * @param[in] mask      the group mask
 * @param[in] mode      the mode
 *
 * @notapi
 */
void _pal_lld_setgroupmode(ioportid_t port,
                           ioportmask_t mask,
                           iomode_t mode)
{
  uint8_t i;

  (void)mask;

  for (i = 0; i < TOTAL_GPIO_PADS; i++) {
    pal_lld_setpadmode(port, i, mode);
  }
}

#endif /* HAL_USE_PAL == TRUE */

/** @} */

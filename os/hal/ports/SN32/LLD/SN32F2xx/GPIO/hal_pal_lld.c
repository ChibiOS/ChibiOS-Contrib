/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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
 * @file    GPIOv3/hal_pal_lld.c
 * @brief   SN32 PAL low level driver code.
 *
 * @addtogroup PAL
 * @{
 */

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)

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

static void initgpio(SN_GPIO0_Type *gpiop, const sn32_gpio_setup_t *config) {

    gpiop->DATA  = config->data;
    gpiop->MODE  = config->mode;
    gpiop->CFG   = config->cfg;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   SN32 I/O ports configuration.
 * @details Ports A-D clocks enabled.
 *
 * @param[in] config    the SN32 ports configuration
 *
 * @notapi
 */
void _pal_lld_init(const PALConfig *config) {

  /*
   * Initial GPIO setup.
   */

#if SN32_HAS_GPIOA
  initgpio(GPIOA, &config->PAData);
#endif
#if SN32_HAS_GPIOB
  initgpio(GPIOB, &config->PBData);
#endif
#if SN32_HAS_GPIOC
  initgpio(GPIOC, &config->PCData);
#endif
#if SN32_HAS_GPIOD
  initgpio(GPIOD, &config->PDData);
#endif

}

/**
 * @brief   Pad mode setup.
 * @details This function programs a pad
 *          with the specified mode.
 * @note    @p PAL_MODE_UNCONNECTED is implemented as push pull at minimum
 *          speed.
 *
 * @param[in] port      the port identifier
 * @param[in] pad       the pad number
 * @param[in] mode      the mode
 *
 * @notapi
 */
void _pal_lld_setpadmode(ioportid_t port,
                           uint32_t pad,
                           iomode_t mode) {

  switch (mode) {

    case PAL_MODE_INPUT_ANALOG:
        //set MODE as INPUT
        port->MODE &= ~(1 << pad);
        // disable pull up resistor
        // disable Schmitt trigger
        // keep DATA low
        port->CFG |= (3 << (pad * 2));
        break;

    case PAL_MODE_INPUT:
        //set MODE as INPUT
        port->MODE &= ~(1 << pad);
        // disable pull up resistor
        // enable Schmitt trigger
        port->CFG |= (2 << (pad * 2));
        break;

    case PAL_MODE_INPUT_PULLUP:
        //set MODE as INPUT
        port->MODE &= ~(1 << pad);
        //enable pull up resistor
        port->CFG &= ~(3 << (pad * 2));
        break;

    case PAL_MODE_OUTPUT_PUSHPULL:
        //set MODE as OUTPUT
        port->MODE |= (1 << pad);
        break;

    default:
        break;
  }
}

#endif /* HAL_USE_PAL */

/** @} */

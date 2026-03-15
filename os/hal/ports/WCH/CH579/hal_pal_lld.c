/**
 * @file    hal_pal_lld.c
 * @brief   CH579M PAL (GPIO) low level driver.
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
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Pads group mode setup.
 * @details This function programs a group of pads belonging to a port
 *          to the specified PAL mode.
 *
 * @param[in] port      the port identifier
 * @param[in] mask      the group mask (bit N → pad N)
 * @param[in] mode      the mode — one of PAL_MODE_INPUT,
 *                      PAL_MODE_INPUT_PULLUP, PAL_MODE_INPUT_PULLDOWN,
 *                      PAL_MODE_OUTPUT_PUSHPULL
 *
 * @notapi
 */
void pal_lld_setgroupmode(ioportid_t port, ioportmask_t mask, iomode_t mode) {
  switch (mode) {
  case PAL_MODE_INPUT:
    /* Floating input: DIR=0, PU=0, PD_DRV=0 */
    port->DIR &= ~mask;
    port->PU &= ~mask;
    port->PD_DRV &= ~mask;
    break;

  case PAL_MODE_INPUT_PULLUP:
    /* Input with pull-up: DIR=0, PU=1 */
    port->DIR &= ~mask;
    port->PD_DRV &= ~mask;
    port->PU |= mask;
    break;

  case PAL_MODE_INPUT_PULLDOWN:
    /* Input with pull-down: DIR=0, PD_DRV=1 (pull-down bit) */
    port->DIR &= ~mask;
    port->PU &= ~mask;
    port->PD_DRV |= mask;
    break;

  case PAL_MODE_OUTPUT_PUSHPULL:
    /* Push-pull output: DIR=1, PU=0 */
    port->PU &= ~mask;
    port->PD_DRV &= ~mask;
    port->DIR |= mask;
    break;

  default:
    /* Unsupported — leave unchanged */
    break;
  }
}

#endif /* HAL_USE_PAL */

/** @} */

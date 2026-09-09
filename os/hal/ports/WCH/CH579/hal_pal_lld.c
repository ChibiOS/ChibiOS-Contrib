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
/* ChibiOS calls pal_lld_setgroupmode with 4 args: (port, mask, offset, mode).
 * offset is always 0 for single-pad calls; we accept and ignore it.
 *
 * CH579 GPIO control registers (DIR, PU, PD_DRV) are fully readable as 32-bit
 * values — the original "write-only / bus fault" comment was incorrect; reads
 * are confirmed working via the WCH EVT SDK (CH57x_gpio.c uses |= / &=).
 * We therefore use direct read-modify-write and protect each register triplet
 * with a critical section so that concurrent calls (e.g. from interrupt context)
 * cannot interleave partial updates. */
void _pal_lld_setgroupmode(ioportid_t port, ioportmask_t mask,
                           uint32_t offset, iomode_t mode) {
  (void)offset;

  syssts_t sts = osalSysGetStatusAndLockX();

  switch (mode) {
  case PAL_MODE_INPUT:
    port->DIR    &= ~mask;
    port->PU     &= ~mask;
    port->PD_DRV &= ~mask;
    break;

  case PAL_MODE_INPUT_PULLUP:
    port->DIR    &= ~mask;
    port->PU     |= mask;
    port->PD_DRV &= ~mask;
    break;

  case PAL_MODE_INPUT_PULLDOWN:
    port->DIR    &= ~mask;
    port->PU     &= ~mask;
    port->PD_DRV |= mask;
    break;

  case PAL_MODE_OUTPUT_PUSHPULL:
    port->DIR    |= mask;
    port->PU     &= ~mask;
    port->PD_DRV &= ~mask;
    break;

  default:
    break;
  }

  osalSysRestoreStatusX(sts);
}

#endif /* HAL_USE_PAL */

/** @} */

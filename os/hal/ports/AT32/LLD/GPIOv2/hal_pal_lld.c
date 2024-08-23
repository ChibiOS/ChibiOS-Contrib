/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2024 Maxjta

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
 * @file    GPIOv2/hal_pal_lld.c
 * @brief   AT32 PAL low level driver code.
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

#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   Event records for the 16 GPIO EXINT channels.
 */
palevent_t _pal_events[16];
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   PAL driver initialization.
 *
 * @notapi
 */
void _pal_lld_init(void) {

#if PAL_USE_CALLBACKS || PAL_USE_WAIT || defined(__DOXYGEN__)
  unsigned i;

  for (i = 0; i < 16; i++) {
    _pal_init_event(i);
  }
#endif
  crmEnableAHB1(AT32_GPIO_EN_MASK, false);
}

/**
 * @brief   Pads mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 * @note    @p PAL_MODE_UNCONNECTED is implemented as push pull at minimum
 *          speed.
 *
 * @param[in] port      the port identifier
 * @param[in] mask      the group mask
 * @param[in] mode      the mode
 *
 * @notapi
 */
void _pal_lld_setgroupmode(ioportid_t port,
                           ioportmask_t mask,
                           iomode_t mode) {

  uint32_t cfgr   = (mode & PAL_AT32_MODE_MASK) >> 0;
  uint32_t omode  = (mode & PAL_AT32_OMODE_MASK) >> 2;
  uint32_t odrvr  = (mode & PAL_AT32_ODRV_MASK) >> 3;
  uint32_t pull   = (mode & PAL_AT32_PULL_MASK) >> 5;
  uint32_t muxr   = (mode & PAL_AT32_ALTERNATE_MASK) >> 7;
  uint32_t hdrv   = (mode & PAL_AT32_HDRV_MASK) >> 11;
  uint32_t bit    = 0;

  while (true) {
    if ((mask & 1) != 0) {
      uint32_t muxrmask, m1, m2, m4;

      muxrmask = muxr << ((bit & 7) * 4);
      m1 = 1 << bit;
      m2 = 3 << (bit * 2);
      m4 = 15 << ((bit & 7) * 4);
      port->OMODE  = (port->OMODE & ~m1) | omode;
      port->ODRVR  = (port->ODRVR & ~m2) | odrvr;
      port->PULL   = (port->PULL & ~m2) | pull;
      port->HDRV   = (port->HDRV & ~m1) | hdrv;
      if ((mode & PAL_AT32_MODE_MASK) == PAL_AT32_MODE_ALTERNATE) {
        /* If going in alternate mode then the alternate number is set
           before switching mode in order to avoid glitches.*/
        if (bit < 8)
          port->MUXL = (port->MUXL & ~m4) | muxrmask;
        else
          port->MUXH = (port->MUXH & ~m4) | muxrmask;
        port->CFGR   = (port->CFGR & ~m2) | cfgr;
      }
      else {
        /* If going into a non-alternate mode then the mode is switched
           before setting the alternate mode in order to avoid glitches.*/
        port->CFGR   = (port->CFGR & ~m2) | cfgr;
        if (bit < 8)
          port->MUXL = (port->MUXL & ~m4) | muxrmask;
        else
          port->MUXH = (port->MUXH & ~m4) | muxrmask;
      }
    }
    mask >>= 1;
    if (!mask)
      return;
    omode <<= 1;
    odrvr <<= 2;
    pull  <<= 2;
    cfgr  <<= 2;
    bit++;
  }
}

#if PAL_USE_CALLBACKS || PAL_USE_WAIT || defined(__DOXYGEN__)
/**
 * @brief   Pad event enable.
 * @note    Programming an unknown or unsupported mode is silently ignored.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] mode      pad event mode
 *
 * @notapi
 */
void _pal_lld_enablepadevent(ioportid_t port,
                             iopadid_t pad,
                             ioeventmode_t mode) {

  uint32_t padmask, cidx, coff, cmask, portidx;

  /* Enable SCFG clock. */
  crmEnableSCFG(false);

  /* Mask of the pad.*/
  padmask = 1U << (uint32_t)pad;

  /* Multiple channel setting of the same channel not allowed, first disable
     it. This is done because on AT32 the same channel cannot be mapped on
     multiple ports.*/
  osalDbgAssert(((EXINT->POLCFG1 & padmask) == 0U) &&
                ((EXINT->POLCFG2 & padmask) == 0U), "channel already in use");

  /* Port index is obtained assuming that GPIO ports are placed at regular
     0x400 intervals in memory space. So far this is true for all devices.*/
  portidx = (((uint32_t)port - (uint32_t)GPIOA) >> 10U) & 0xFU;

  /* Index and mask of the EXINTC register to be used.*/
  cidx  = (uint32_t)pad >> 2U;
  coff  = ((uint32_t)pad & 3U) * 4U;
  cmask = ~(0xFU << coff);
  SCFG->EXINTC[cidx] = (SCFG->EXINTC[cidx] & cmask) | (portidx << coff);

  /* Programming edge registers.*/
  if (mode & PAL_EVENT_MODE_RISING_EDGE)
    EXINT->POLCFG1 |= padmask;
  else
    EXINT->POLCFG1 &= ~padmask;
  if (mode & PAL_EVENT_MODE_FALLING_EDGE)
    EXINT->POLCFG2 |= padmask;
  else
    EXINT->POLCFG2 &= ~padmask;

  /* Programming interrupt and event registers.*/
  EXINT->INTEN |= padmask;
  EXINT->EVTEN &= ~padmask;
}

/**
 * @brief   Pad event disable.
 * @details This function disables previously programmed event callbacks.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
void _pal_lld_disablepadevent(ioportid_t port, iopadid_t pad) {
  uint32_t padmask, polcfg1, polcfg2;

  polcfg1 = EXINT->POLCFG1;
  polcfg2 = EXINT->POLCFG2;

  /* Mask of the pad.*/
  padmask = 1U << (uint32_t)pad;

  /* If either RTRS1 or POLCFG2 is enabled then the channel is in use.*/
  if (((polcfg1 | polcfg2) & padmask) != 0U) {
    uint32_t cidx, coff, cport, portidx;

    /* Port index is obtained assuming that GPIO ports are placed at regular
       0x400 intervals in memory space. So far this is true for all devices.*/
    portidx = (((uint32_t)port - (uint32_t)GPIOA) >> 10U) & 0xFU;

    /* Index and mask of the EXINTC register to be used.*/
    cidx  = (uint32_t)pad >> 2U;
    coff  = ((uint32_t)pad & 3U) * 4U;
    cport = (SCFG->EXINTC[cidx] >> coff) & 0xFU;

    osalDbgAssert(cport == portidx, "channel mapped on different port");

    /* Disabling channel.*/
    EXINT->INTEN   &= ~padmask;
    EXINT->EVTEN   &= ~padmask;
    EXINT->POLCFG1  = polcfg1 & ~padmask;
    EXINT->POLCFG2  = polcfg2 & ~padmask;
    EXINT->INTSTS   = padmask;

#if PAL_USE_CALLBACKS || PAL_USE_WAIT
  /* Callback cleared and/or thread reset.*/
  _pal_clear_event(pad);
#endif
  }
}
#endif /* PAL_USE_CALLBACKS || PAL_USE_WAIT */

#endif /* HAL_USE_PAL */

/** @} */

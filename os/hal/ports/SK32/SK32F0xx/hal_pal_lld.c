/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_pal_lld.c
 * @brief   SK32F0xx PAL low level driver code.
 * @details This driver is written directly against the vendor CMSIS header
 *          (@p sk32f0xx.h).  The GPIO registers are the STM32F0-style
 *          MODER/OTYPER/OSPEEDR/PUPDR/IDR/ODR/BSRR/AFR set (the BSRR
 *          register is written with a single 32 bits access, the alternate
 *          function registers are an AFR[2] array) and the EXTI line
 *          multiplexing is programmed through the SYSCFG EXTICR registers
 *          (4 bits per line).
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
 * @brief   Event records for the 16 GPIO EXTI channels.
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

  uint32_t moder   = (mode & PAL_SK32_MODE_MASK) >> 0;
  uint32_t otyper  = (mode & PAL_SK32_OTYPE_MASK) >> 2;
  uint32_t ospeedr = (mode & PAL_SK32_OSPEED_MASK) >> 3;
  uint32_t pupdr   = (mode & PAL_SK32_PUPDR_MASK) >> 5;
  uint32_t altr    = (mode & PAL_SK32_ALTERNATE_MASK) >> 7;
  uint32_t bit     = 0;
  while (true) {
    if ((mask & 1) != 0) {
      uint32_t altrmask, m1, m2, m4;

      altrmask = altr << ((bit & 7) * 4);
      m1 = 1 << bit;
      m2 = 3 << (bit * 2);
      m4 = 15 << ((bit & 7) * 4);
      port->OTYPER  = (port->OTYPER & ~m1) | otyper;
      port->OSPEEDR = (port->OSPEEDR & ~m2) | ospeedr;
      port->PUPDR   = (port->PUPDR & ~m2) | pupdr;
      if ((mode & PAL_SK32_MODE_MASK) == PAL_SK32_MODE_ALTERNATE) {
        /* If going in alternate mode then the alternate number is set
           before switching mode in order to avoid glitches.*/
        if (bit < 8)
          port->AFR[0] = (port->AFR[0] & ~m4) | altrmask;
        else
          port->AFR[1] = (port->AFR[1] & ~m4) | altrmask;
        port->MODER   = (port->MODER & ~m2) | moder;
      }
      else {
        /* If going into a non-alternate mode then the mode is switched
           before setting the alternate mode in order to avoid glitches.*/
        port->MODER   = (port->MODER & ~m2) | moder;
        if (bit < 8)
          port->AFR[0] = (port->AFR[0] & ~m4) | altrmask;
        else
          port->AFR[1] = (port->AFR[1] & ~m4) | altrmask;
      }
    }
    mask >>= 1;
    if (!mask)
      return;
    otyper <<= 1;
    ospeedr <<= 2;
    pupdr <<= 2;
    moder <<= 2;
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

  uint32_t padmask, cridx, croff, crmask, portidx;

  /* Mask of the pad.*/
  padmask = 1U << (uint32_t)pad;

  /* Multiple channel setting of the same channel not allowed, first disable
     it. This is done because on SK32 the same channel cannot be mapped on
     multiple ports.*/
  osalDbgAssert(((EXTI->RTSR & padmask) == 0U) &&
                ((EXTI->FTSR & padmask) == 0U), "channel already in use");

  /* Port index is obtained assuming that GPIO ports are placed at regular
     0x400 intervals in memory space. So far this is true for all devices.*/
  portidx = (((uint32_t)port - (uint32_t)GPIOA) >> 10U) & 0xFU;

  /* Index and mask of the EXTICR register to be used, on this family the
     line to port mapping is done in the SYSCFG block, 4 bits per line.*/
  cridx  = (uint32_t)pad >> 2U;
  croff  = ((uint32_t)pad & 3U) * 4U;
  crmask = ~(0xFU << croff);
  SYSCFG->EXTICR[cridx] = (SYSCFG->EXTICR[cridx] & crmask) | (portidx << croff);

  /* Programming edge registers.*/
  if (mode & PAL_EVENT_MODE_RISING_EDGE)
    EXTI->RTSR |= padmask;
  else
    EXTI->RTSR &= ~padmask;
  if (mode & PAL_EVENT_MODE_FALLING_EDGE)
    EXTI->FTSR |= padmask;
  else
    EXTI->FTSR &= ~padmask;

  /* Programming interrupt and event registers.*/
  EXTI->IMR |= padmask;
  EXTI->EMR &= ~padmask;
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
  uint32_t padmask, rtsr, ftsr;

  rtsr = EXTI->RTSR;
  ftsr = EXTI->FTSR;

  /* Mask of the pad.*/
  padmask = 1U << (uint32_t)pad;

  /* If either RTSR or FTSR is enabled then the channel is in use.*/
  if (((rtsr | ftsr) & padmask) != 0U) {
    uint32_t cridx, croff, crport, portidx;

    /* Port index is obtained assuming that GPIO ports are placed at regular
       0x400 intervals in memory space. So far this is true for all devices.*/
    portidx = (((uint32_t)port - (uint32_t)GPIOA) >> 10U) & 0xFU;

    /* Index and mask of the EXTICR register to be used.*/
    cridx  = (uint32_t)pad >> 2U;
    croff  = ((uint32_t)pad & 3U) * 4U;
    crport = (SYSCFG->EXTICR[cridx] >> croff) & 0xFU;

    osalDbgAssert(crport == portidx, "channel mapped on different port");

    /* Disabling channel.*/
    EXTI->IMR  &= ~padmask;
    EXTI->EMR  &= ~padmask;
    EXTI->RTSR  = rtsr & ~padmask;
    EXTI->FTSR  = ftsr & ~padmask;
    EXTI->PR    = padmask;

#if PAL_USE_CALLBACKS || PAL_USE_WAIT
    /* Callback cleared and/or thread reset.*/
    _pal_clear_event(pad);
#endif
  }
}
#endif /* PAL_USE_CALLBACKS || PAL_USE_WAIT */

#endif /* HAL_USE_PAL */

/** @} */

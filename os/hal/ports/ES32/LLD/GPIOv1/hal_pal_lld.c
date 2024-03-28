/*
    Copyright (C) 2020

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
 * @file    hal_pal_lld.c
 * @brief   ES32 PAL subsystem low level driver source.
 *
 * @addtogroup PAL
 * @{
 */

#include "hal.h"

#if (HAL_USE_PAL == TRUE) || defined(__DOXYGEN__)

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
                           iomode_t mode)
{

  uint32_t mod   = (mode & PAL_ES32_MODE_MASK) >> 0;
  uint32_t ot  = (mode & PAL_ES32_OT_MASK) >> 2;
  uint32_t ds = (mode & PAL_ES32_DS_MASK) >> 3;
  uint32_t pud   = (mode & PAL_ES32_PUD_MASK) >> 5;
  uint32_t altr    = (mode & PAL_ES32_ALTERNATE_MASK) >> 7;
  uint32_t bit     = 0;
  while (true) {
    if ((mask & 1) != 0) {
      uint32_t altrmask, m1, m2, m4;

      altrmask = altr << ((bit & 7) * 4);
      m1 = 1 << bit;
      m2 = 3 << (bit * 2);
      m4 = 15 << ((bit & 7) * 4);
      port->OT  = (port->OT & ~m1) | ot;
      port->DS = (port->DS & ~m1) | ds;
      port->PUD   = (port->PUD & ~m2) | pud;
      if ((mode & PAL_ES32_MODE_MASK) == PAL_ES32_MODE_ALTERNATE) {
        /* If going in alternate mode then the alternate number is set
           before switching mode in order to avoid glitches.*/
        if (bit < 8)
          port->AFL = (port->AFL & ~m4) | altrmask;
        else
          port->AFH = (port->AFH & ~m4) | altrmask;
        port->MOD   = (port->MOD & ~m2) | mod;
      }
      else {
        /* If going into a non-alternate mode then the mode is switched
           before setting the alternate mode in order to avoid glitches.*/
        port->MOD   = (port->MOD & ~m2) | mod;
        if (bit < 8)
          port->AFL = (port->AFL & ~m4) | altrmask;
        else
          port->AFH = (port->AFH & ~m4) | altrmask;
      }
    }
    mask >>= 1;
    if (!mask)
      return;
    ot <<= 1;
    ds <<= 1;
    pud <<= 2;
    mod <<= 2;
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

  if (pad & 3U)
    NVIC_EnableIRQ((IRQn_Type) EXTI_0to1_IRQn);    /* EXTI_0to1_IRQn interrupt */
  else if (pad & 0xCU)	
    NVIC_EnableIRQ((IRQn_Type) EXTI_2to3_IRQn);    /* EXTI_2to3_IRQn interrupt */
  else if (pad & 0xFFF0U)
    NVIC_EnableIRQ((IRQn_Type) EXTI_4to15_IRQn);   /* EXTI_4to15_IRQn interrupt */

  /* Clear pending interrupt flag before enable interrupt event */
  EXTI->ICR = EXTI_IFM;

  /* Programming edge registers.*/
  if (mode & PAL_EVENT_MODE_RISING_EDGE)
    EXTI->RTS |= padmask;
  else
    EXTI->RTS &= ~padmask;
  if (mode & PAL_EVENT_MODE_FALLING_EDGE)
    EXTI->FTS |= padmask;
  else
    EXTI->FTS &= ~padmask;

  portidx = (((uint32_t)port - (uint32_t)GPIOA) >> 10U) & 0x3U;
  if (padmask < 8) 
    EXTI_ICFG1 = (uint32_t)portidx << (pad * 4U);
  else
    EXTI_ICFG2 = (uint32_t)portidx << (pad * 4U);
  
  EXTI_IER = padmask;
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
  uint32_t padmask, rtsr1, ftsr1;

  rts = EXTI->RTS;
  fts = EXTI->FTS;

  /* Mask of the pad.*/
  padmask = 1U << (uint32_t)pad;

  /* Clear pending interrupt flag before enable interrupt event */
  EXTI->ICR = EXTI_IFM;
  EXTI->IDR = padmask;

  if (((pad & 3U) | (EXTI_IER & 3U)) == 0)
    NVIC_DisableIRQ((IRQn_Type) EXTI_0to1_IRQn);    /* EXTI_0to1_IRQn interrupt */
  else if (((pad & 0xCU) | (EXTI_IER & 0xCU)) == 0)
    NVIC_DisableIRQ((IRQn_Type) EXTI_2to3_IRQn);    /* EXTI_2to3_IRQn interrupt */
  else if ((pad & 0xFFF0U) | (EXTI_IER & 0xFFF0U) == 0)
    NVIC_DisableIRQ((IRQn_Type) EXTI_4to15_IRQn);   /* EXTI_4to15_IRQn interrupt */

  /* Disabling channel.*/
  EXTI->RTS  = rts & ~padmask;
  EXTI->FTS  = fts & ~padmask;

#if PAL_USE_CALLBACKS || PAL_USE_WAIT
  /* Callback cleared and/or thread reset.*/
  _pal_clear_event(pad);
#endif
  }
}
#endif /* PAL_USE_CALLBACKS || PAL_USE_WAIT */
#endif /* HAL_USE_PAL == TRUE */

/** @} */

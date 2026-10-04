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
	md_gpio_init_t  gpio_config;
  
    gpio_config.mode  = (mode & PAL_ES32_MODE_MASK) >> 0;
    gpio_config.odos  = (mode & PAL_ES32_OT_MASK) >> 2;
    gpio_config.odrv  = (mode & PAL_ES32_DS_MASK) >> 3;
    gpio_config.pupd  = (mode & PAL_ES32_PUD_MASK) >> 5;
    gpio_config.flt   = MD_GPIO_FILTER_DISABLE;
    gpio_config.type  = MD_GPIO_TYPE_CMOS;
    gpio_config.func  = MD_GPIO_FUNC_1;
	
	if(gpio_config.mode == PAL_ES32_MODE_ALTERNATE)
	{
		gpio_config.func  = (mode & PAL_ES32_ALTERNATE_MASK) >> 7;
	}
	
    md_gpio_init(port, mask, &gpio_config);
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

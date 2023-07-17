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

#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
palevent_t _pal_events[TOTAL_PORTS * PAL_IOPORTS_WIDTH];
#endif /* (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) */

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void initgpio(ioportid_t gpiop, const sn32_gpio_setup_t *config) {
    gpiop->DATA  = config->data;
    gpiop->MODE  = config->mode;
    gpiop->CFG   = config->cfg;
}

#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
static void irq_handler(ioportid_t port, uint32_t offset) {
    chSysLockFromISR();
    uint32_t ris = port->RIS; /* Get pending interrupts on this port. */
    port->IC = 0xFFFFFFFFU; /* Clear all pending interrupts on this port. */
    chSysUnlockFromISR();

    /* invoke callbacks for pending interrupts */
    for (iopadid_t pad = 0; pad < PAL_IOPORTS_WIDTH; pad++) {
        if (ris & (1 << pad)) {
            _pal_isr_code(offset + pad);
        }
    }
}
#endif /* (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) */

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
#if SN32_HAS_GPIOA
OSAL_IRQ_HANDLER(SN32_GPIOA_HANDLER) {
    OSAL_IRQ_PROLOGUE();
    irq_handler(GPIOA, 0);
    OSAL_IRQ_EPILOGUE();
}
#endif
#if SN32_HAS_GPIOB
OSAL_IRQ_HANDLER(SN32_GPIOB_HANDLER) {
    OSAL_IRQ_PROLOGUE();
    irq_handler(GPIOB, PAL_IOPORTS_WIDTH);
    OSAL_IRQ_EPILOGUE();
}
#endif
#if SN32_HAS_GPIOC
OSAL_IRQ_HANDLER(SN32_GPIOC_HANDLER) {
    OSAL_IRQ_PROLOGUE();
    irq_handler(GPIOC, PAL_IOPORTS_WIDTH * 2);
    OSAL_IRQ_EPILOGUE();
}
#endif
#if SN32_HAS_GPIOD
OSAL_IRQ_HANDLER(SN32_GPIOD_HANDLER) {
    OSAL_IRQ_PROLOGUE();
    irq_handler(GPIOD, PAL_IOPORTS_WIDTH * 3);
    OSAL_IRQ_EPILOGUE();
}
#endif
#endif /* (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) */

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

#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
#if SN32_HAS_GPIOA
  sys1EnableP0();
  nvicEnableVector(SN32_GPIOA_NUMBER, SN32_GPIOA_IRQ_PRIORITY);
#endif
#if SN32_HAS_GPIOB
  sys1EnableP1();
  nvicEnableVector(SN32_GPIOB_NUMBER, SN32_GPIOB_IRQ_PRIORITY);
#endif
#if SN32_HAS_GPIOC
  sys1EnableP2();
  nvicEnableVector(SN32_GPIOC_NUMBER, SN32_GPIOC_IRQ_PRIORITY);
#endif
#if SN32_HAS_GPIOD
  sys1EnableP3();
  nvicEnableVector(SN32_GPIOD_NUMBER, SN32_GPIOD_IRQ_PRIORITY);
#endif

  for (uint8_t i = 0; i < TOTAL_PORTS * PAL_IOPORTS_WIDTH; i++) {
    _pal_init_event(i);
  }
#endif

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
                           iopadid_t pad,
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

#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
/**
 * @brief   Returns a PAL event structure associated to a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
palevent_t* _pal_lld_get_pad_event(ioportid_t port,
                                   iopadid_t pad) {
  if (port == GPIOA) {
    return _pal_events + pad;
  } else if (port == GPIOB) {
    return _pal_events + PAL_IOPORTS_WIDTH + pad;
  } else if (port == GPIOC) {
    return _pal_events + PAL_IOPORTS_WIDTH * 2 + pad;
  } else if (port == GPIOD) {
    return _pal_events + PAL_IOPORTS_WIDTH * 3 + pad;
  }
  return NULL;
}

/**
 * @brief   Enables a pad event.
 *
 * @param[in] port   port containing pad whose event is to be enabled
 * @param[in] pad    pad whose event is to be enabled
 * @param[in] mode   mode of the event
 *
 * @notapi
 */
void _pal_lld_enablepadevent(ioportid_t port,
                             iopadid_t pad,
                             iomode_t mode) {
  switch(mode) {
    case PAL_EVENT_MODE_RISING_EDGE:
      port->IS  &= ~(1 << pad);
      port->IBS &= ~(1 << pad);
      port->IEV &= ~(1 << pad);
      port->IE  |= (1 << pad);
      break;
    case PAL_EVENT_MODE_FALLING_EDGE:
      port->IS  &= ~(1 << pad);
      port->IBS &= ~(1 << pad);
      port->IEV |= (1 << pad);
      port->IE  |= (1 << pad);
      break;
    case PAL_EVENT_MODE_BOTH_EDGES:
      port->IS  &= ~(1 << pad);
      port->IBS |= (1 << pad);
      port->IE  |= (1 << pad);
      break;
    case PAL_EVENT_MODE_DISABLED:
      port->IS  &= ~(1 << pad);
      port->IBS &= ~(1 << pad);
      port->IEV &= ~(1 << pad);
      port->IE  &= ~(1 << pad);
      break;
    default:
      return;
  }
}

/**
 * @brief   Disables a pad event
 *
 * @param[in] port      port containing pad whose event is to be disabled
 * @param[in] pad       pad whose event is to be disabled
 *
 * @notapi
 */
void _pal_lld_disablepadevent(ioportid_t port, iopadid_t pad) {
  _pal_lld_enablepadevent(port, pad, PAL_EVENT_MODE_DISABLED);

  if (port == GPIOA) {
    _pal_clear_event(pad);
  } else if (port == GPIOB) {
    _pal_clear_event(PAL_IOPORTS_WIDTH + pad);
  } else if (port == GPIOC) {
    _pal_clear_event(PAL_IOPORTS_WIDTH * 2 + pad);
  } else if (port == GPIOD) {
    _pal_clear_event(PAL_IOPORTS_WIDTH * 3 + pad);
  }
}

/**
 * @brief   Returns whether a pad event is enabled
 *
 * @param[in] port     port containing the pad
 * @param[in] pad      pad whose event is to be queried
 *
 * @notapi
 */
bool _pal_lld_ispadeventenabled(ioportid_t port, iopadid_t pad) {
  return ((port->IE >> pad) & 1);
}
#endif /* (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE) */
#endif /* HAL_USE_PAL */

/** @} */

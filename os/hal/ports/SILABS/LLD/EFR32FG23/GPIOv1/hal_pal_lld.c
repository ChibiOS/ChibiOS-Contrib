/*
    ChibiOS - Copyright (C) 2024 Xael South

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
 * @brief   PLATFORM PAL subsystem low level driver source.
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
 * @brief   Event records for the PAL_EVENTS_SIZE GPIO odd and even channels.
 */
palevent_t _pal_events[PAL_EVENTS_SIZE];
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

__STATIC_INLINE void _pal_lld_reg_masked_write(volatile uint32_t* address,
                                               uint32_t mask,
                                               uint32_t value) {

  *address = (*address & ~mask) | (value & mask);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (PAL_USE_WAIT || PAL_USE_CALLBACKS) || defined(__DOXYGEN__)
/**
 * @brief   EFR32_GPIO_ODD_HANDLER interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_GPIO_ODD_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Get and clear pending GPIO interrupts. */
  uint32_t flags = GPIO->IF;
  _pal_lld_reg_masked_write(&(GPIO->IF_CLR), 0xAAAUL, flags);

  for (uint32_t pad = 1U; pad < PAL_EVENTS_SIZE; pad += 2U) {
    if ((flags & (1U << pad)) != 0U) {
      _pal_isr_code(pad);
    }
  }

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   EFR32_GPIO_ODD_HANDLER interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_GPIO_EVEN_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Get and clear pending GPIO interrupts. */
  uint32_t flags = GPIO->IF;
  _pal_lld_reg_masked_write(&(GPIO->IF_CLR), 0x555UL, flags);

  for (uint32_t pad = 0U; pad < PAL_EVENTS_SIZE; pad += 2U) {
    if ((flags & (1U << pad)) != 0U) {
      _pal_isr_code(pad);
    }
  }

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   I/O ports configuration.
 *
 * @notapi
 */
void _pal_lld_init(const PALConfig* config) {

#if PAL_USE_CALLBACKS || PAL_USE_WAIT || defined(__DOXYGEN__)
  int i;

  for (i = 0; i < 16; i++) {
    _pal_init_event(i);
  }
#endif

  /*
   * Enables the GPIO related clocks.
   */
  CMU->CLKEN0_SET = CMU_CLKEN0_GPIO;

  /*
   * Initial GPIO setup.
   */
  GPIO_PORT(GPIOA)->CTRL  = config->PAData.ctrlr;
  GPIO_PORT(GPIOA)->MODEL = config->PAData.modelr;
  GPIO_PORT(GPIOA)->MODEH = config->PAData.modehr;
  GPIO_PORT(GPIOA)->DOUT  = config->PAData.doutr;

  GPIO_PORT(GPIOB)->CTRL  = config->PBData.ctrlr;
  GPIO_PORT(GPIOB)->MODEL = config->PBData.modelr;
  GPIO_PORT(GPIOB)->MODEH = config->PBData.modehr;
  GPIO_PORT(GPIOB)->DOUT  = config->PBData.doutr;

  GPIO_PORT(GPIOC)->CTRL  = config->PCData.ctrlr;
  GPIO_PORT(GPIOC)->MODEL = config->PCData.modelr;
  GPIO_PORT(GPIOC)->MODEH = config->PCData.modehr;
  GPIO_PORT(GPIOC)->DOUT  = config->PCData.doutr;

  GPIO_PORT(GPIOD)->CTRL  = config->PDData.ctrlr;
  GPIO_PORT(GPIOD)->MODEL = config->PDData.modelr;
  GPIO_PORT(GPIOD)->MODEH = config->PDData.modehr;
  GPIO_PORT(GPIOD)->DOUT  = config->PDData.doutr;

#if (PAL_USE_WAIT || PAL_USE_CALLBACKS) || defined(__DOXYGEN__)
  nvicEnableVector(EFR32_GPIO_ODD_NUMBER, EFR32_GPIO_ODD_IRQ_PRIORITY);
  nvicEnableVector(EFR32_GPIO_EVEN_NUMBER, EFR32_GPIO_EVEN_IRQ_PRIORITY);
#endif
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
                           iomode_t mode) {

  uint32_t pad = 0;

  osalDbgCheck(mask <= PAL_WHOLE_PORT);

  while (mask) {
    if ((mask & 1) != 0) {
      _pal_lld_setpadmode(port, pad, mode);
      _pal_lld_setalternatefunction(port, pad, mode);
    }

    mask >>= 1;
    pad++;
  }
}

void _pal_lld_setalternatefunction(ioportid_t port,
                                   iopadid_t pad,
                                   iomode_t mode) {

  uint32_t altfunc = (mode & PAL_EFR32_ALTERNATE_FUNCSEL_MASK);

  switch (altfunc) {
    case PAL_EFR32_ALTERNATE_FUNCSEL_NONE:
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART0_RX_DIS:
      GPIO->EUSARTROUTE[0].ROUTEEN &= ~GPIO_EUSART_ROUTEEN_RXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART0_TX_DIS:
      GPIO->EUSARTROUTE[0].ROUTEEN &= ~GPIO_EUSART_ROUTEEN_TXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART0_RX:
      GPIO->EUSARTROUTE[0].RXROUTE = (GPIO_PORT_INDEX(port) << _GPIO_EUSART_RXROUTE_PORT_SHIFT) |
                                     (pad << _GPIO_EUSART_RXROUTE_PIN_SHIFT);
      GPIO->EUSARTROUTE[0].ROUTEEN |= GPIO_EUSART_ROUTEEN_RXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART0_TX:
      GPIO->EUSARTROUTE[0].TXROUTE = (GPIO_PORT_INDEX(port) << _GPIO_EUSART_TXROUTE_PORT_SHIFT) |
                                     (pad << _GPIO_EUSART_TXROUTE_PIN_SHIFT);
      GPIO->EUSARTROUTE[0].ROUTEEN |= GPIO_EUSART_ROUTEEN_TXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART1_RX_DIS:
      GPIO->EUSARTROUTE[1].ROUTEEN &= ~GPIO_EUSART_ROUTEEN_RXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART1_TX_DIS:
      GPIO->EUSARTROUTE[1].ROUTEEN &= ~GPIO_EUSART_ROUTEEN_TXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART1_RX:
      GPIO->EUSARTROUTE[1].RXROUTE = (GPIO_PORT_INDEX(port) << _GPIO_EUSART_RXROUTE_PORT_SHIFT) |
                                     (pad << _GPIO_EUSART_RXROUTE_PIN_SHIFT);
      GPIO->EUSARTROUTE[1].ROUTEEN |= GPIO_EUSART_ROUTEEN_RXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART1_TX:
      GPIO->EUSARTROUTE[1].TXROUTE = (GPIO_PORT_INDEX(port) << _GPIO_EUSART_TXROUTE_PORT_SHIFT) |
                                     (pad << _GPIO_EUSART_TXROUTE_PIN_SHIFT);
      GPIO->EUSARTROUTE[1].ROUTEEN |= GPIO_EUSART_ROUTEEN_TXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART2_RX_DIS:
      GPIO->EUSARTROUTE[2].ROUTEEN &= ~GPIO_EUSART_ROUTEEN_RXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART2_TX_DIS:
      GPIO->EUSARTROUTE[2].ROUTEEN &= ~GPIO_EUSART_ROUTEEN_TXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART2_RX:
      GPIO->EUSARTROUTE[2].RXROUTE = (GPIO_PORT_INDEX(port) << _GPIO_EUSART_RXROUTE_PORT_SHIFT) |
                                     (pad << _GPIO_EUSART_RXROUTE_PIN_SHIFT);
      GPIO->EUSARTROUTE[2].ROUTEEN |= GPIO_EUSART_ROUTEEN_RXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_EUSART2_TX:
      GPIO->EUSARTROUTE[2].TXROUTE = (GPIO_PORT_INDEX(port) << _GPIO_EUSART_TXROUTE_PORT_SHIFT) |
                                     (pad << _GPIO_EUSART_TXROUTE_PIN_SHIFT);
      GPIO->EUSARTROUTE[2].ROUTEEN |= GPIO_EUSART_ROUTEEN_TXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_USART0_RX_DIS:
      GPIO->USARTROUTE[0].ROUTEEN &= ~GPIO_USART_ROUTEEN_RXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_USART0_TX_DIS:
      GPIO->USARTROUTE[0].ROUTEEN &= ~GPIO_USART_ROUTEEN_TXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_USART0_RX:
      GPIO->USARTROUTE[0].RXROUTE = (GPIO_PORT_INDEX(port) << _GPIO_USART_RXROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_USART_RXROUTE_PIN_SHIFT);
      GPIO->USARTROUTE[0].ROUTEEN |= GPIO_USART_ROUTEEN_RXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_USART0_TX:
      GPIO->USARTROUTE[0].TXROUTE = (GPIO_PORT_INDEX(port) << _GPIO_USART_TXROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_USART_TXROUTE_PIN_SHIFT);
      GPIO->USARTROUTE[0].ROUTEEN |= GPIO_USART_ROUTEEN_TXPEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_NOCLOCK:
      GPIO->CMUROUTE_CLR.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_FSRCO:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL0_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL0_FSRCO;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      GPIO->CMUROUTE.CLKOUT0ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT0ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT0ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_HFXO:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL0_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL0_HFXO;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      GPIO->CMUROUTE.CLKOUT0ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT0ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT0ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_HFRCODPLL:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL0_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL0_HFRCODPLL;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      GPIO->CMUROUTE.CLKOUT0ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT0ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT0ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_HFRCOEM23:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL0_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL0_HFRCOEM23;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      GPIO->CMUROUTE.CLKOUT0ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT0ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT0ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_LFXO:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL0_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL0_LFXO;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      GPIO->CMUROUTE.CLKOUT0ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT0ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT0ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT1_LFXO:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL1_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL1_LFXO;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT1PEN;
      GPIO->CMUROUTE.CLKOUT1ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT1ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT1ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT2_LFXO:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOA) || (GPIO_PORT_INDEX(port) == GPIOB));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL2_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL2_LFXO;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT2PEN;
      GPIO->CMUROUTE.CLKOUT2ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT2ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT2ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_LFRCO:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL0_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL0_LFRCO;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      GPIO->CMUROUTE.CLKOUT0ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT0ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT0ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_ULFRCO:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL0_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL0_ULFRCO;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      GPIO->CMUROUTE.CLKOUT0ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT0ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT0ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT0_HCLK:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL0_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL0_HCLK;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT0PEN;
      GPIO->CMUROUTE.CLKOUT0ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT0ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT0ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT1_HCLK:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOC) || (GPIO_PORT_INDEX(port) == GPIOD));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL1_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL1_HCLK;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT1PEN;
      GPIO->CMUROUTE.CLKOUT1ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT1ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT1ROUTE_PIN_SHIFT);
      break;

    case PAL_EFR32_ALTERNATE_FUNCSEL_CLKOUT2_HCLK:
      osalDbgCheck((GPIO_PORT_INDEX(port) == GPIOA) || (GPIO_PORT_INDEX(port) == GPIOB));
      CMU->EXPORTCLKCTRL = (CMU->EXPORTCLKCTRL & ~_CMU_EXPORTCLKCTRL_CLKOUTSEL2_MASK) | CMU_EXPORTCLKCTRL_CLKOUTSEL2_HCLK;
      GPIO->CMUROUTE_SET.ROUTEEN = GPIO_CMU_ROUTEEN_CLKOUT2PEN;
      GPIO->CMUROUTE.CLKOUT2ROUTE = (GPIO_PORT_INDEX(port) << _GPIO_CMU_CLKOUT2ROUTE_PORT_SHIFT) |
                                    (pad << _GPIO_CMU_CLKOUT2ROUTE_PIN_SHIFT);
      break;

    default:
      osalDbgAssert(false, "unimplemented alternate function");
      break;
  }
}

void _pal_lld_setpadmode(ioportid_t port,
                         iopadid_t pad,
                         iomode_t mode) {

  uint32_t moder = (mode & PAL_EFR32_MODE_MASK) >> PAL_EFR32_MODE_SHIFT;
  uint32_t doutr = (mode & PAL_EFR32_DOUT_MASK) >> PAL_EFR32_DOUT_SHIFT;

  if (pad < 8) {
    _pal_lld_reg_masked_write(&(GPIO_PORT(port)->MODEL), 0xFu << ((pad - 0) * 4), moder << ((pad - 0) * 4));
  } else {
    _pal_lld_reg_masked_write(&(GPIO_PORT(port)->MODEH), 0xFu << ((pad - 8) * 4), moder << ((pad - 8) * 4));
  }

  pal_lld_writepad(port, pad, (doutr != 0) ? PAL_HIGH : PAL_LOW);
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

  uint32_t int_no = pad;
  uint32_t rising_edge, falling_edge;

  osalDbgCheck(pad < GPIO_PORT_SIZE(port));

  switch (mode & PAL_EVENT_MODE_EDGES_MASK) {
    default:
    case PAL_EVENT_MODE_DISABLED:
      rising_edge = 0U;
      falling_edge = 0U;
      break;
    case PAL_EVENT_MODE_RISING_EDGE:
      rising_edge = 1U;
      falling_edge = 0U;
      break;
    case PAL_EVENT_MODE_FALLING_EDGE:
      rising_edge = 0U;
      falling_edge = 1U;
      break;
    case PAL_EVENT_MODE_BOTH_EDGES:
      rising_edge = 1U;
      falling_edge = 1U;
      break;
  }

  if (int_no < 8) {
    /* The EXTIPSELL register controls pins 0-7. */
    _pal_lld_reg_masked_write(&GPIO->EXTIPSELL, 0b11UL << (4U * int_no), GPIO_PORT_INDEX(port) << (4U * int_no));
    /* The EXTIPINSELL register controls interrupt 0-7. */
    _pal_lld_reg_masked_write(&GPIO->EXTIPINSELL, 0b11UL << (4U * int_no), (uint32_t)((pad % 4) & 0b11UL) << (4U * int_no));
  } else {
    uint32_t tmp = int_no - 8;
    /* EXTIPSELH controls pins 8-15 of the interrupt configuration. */
    _pal_lld_reg_masked_write(&GPIO->EXTIPSELH, 0b11UL << (4U * tmp), GPIO_PORT_INDEX(port) << (4U * tmp));
    /* EXTIPINSELH controls interrupt 8-15 of the interrupt/pin number mapping. */
    _pal_lld_reg_masked_write(&GPIO->EXTIPINSELH, 0b11UL << (4U * tmp), (uint32_t)((pad % 4) & 0b11UL) << (4U * tmp));
  }

  /* Enable/disable the rising edge interrupt. */
  _pal_lld_reg_masked_write(&(GPIO->EXTIRISE), (1U << int_no), (rising_edge << int_no));

  /* Enable/disable the falling edge interrupt. */
  _pal_lld_reg_masked_write(&(GPIO->EXTIFALL), (1U << int_no), (falling_edge << int_no));

  /* Clear any pending interrupt. */
  _pal_lld_reg_masked_write(&(GPIO->IF_CLR), (1U << int_no), (1U << int_no));

  /* Finally enable/disable interrupt. */
  _pal_lld_reg_masked_write(&(GPIO->IEN), (1U << int_no), (1U << int_no));
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

  (void)port;

  uint32_t int_no = pad;

  /* Disable the rising edge interrupt. */
  _pal_lld_reg_masked_write(&(GPIO->EXTIRISE), (1U << int_no), (0U << int_no));

  /* Disable the falling edge interrupt. */
  _pal_lld_reg_masked_write(&(GPIO->EXTIFALL), (1U << int_no), (0U << int_no));

  /* Finally disable interrupt. */
  _pal_lld_reg_masked_write(&(GPIO->IEN), (1U << int_no), (0U << int_no));

  /* Clear any pending interrupt. */
  _pal_lld_reg_masked_write(&(GPIO->IF_CLR), (1U << int_no), (1U << int_no));
}
#endif /* PAL_USE_CALLBACKS || PAL_USE_WAIT */

#endif /* HAL_USE_PAL == TRUE */

/** @} */
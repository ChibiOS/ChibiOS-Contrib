/*
    Copyright (C) 2019 /u/KeepItUnder

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

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

// TODO these are wrong (GPIOE) but commented out
/* DEBUG

OSAL_IRQ_HANDLER(NUC126_GPIOAB_HANDLER){
    OSAL_IRQ_PROLOGUE();

  GPIO_TOGGLE(PB4);
  GPIO_TOGGLE(PB5);
  GPIO_TOGGLE(PB6);
  GPIO_TOGGLE(PB7);
  GPIO_TOGGLE(PB8);

    OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(NUC126_GPIOCDF_HANDLER){
    OSAL_IRQ_PROLOGUE();

  GPIO_TOGGLE(PB4);
  GPIO_TOGGLE(PB5);
  GPIO_TOGGLE(PB6);
  GPIO_TOGGLE(PB7);
  GPIO_TOGGLE(PB8);

    OSAL_IRQ_EPILOGUE();
}
*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   NUC126 I/O ports configuration.
 * @details Ports A-D(E, F, G, H) clocks enabled.
 *
 * @param[in] config    the NUC126 ports configuration
 *
 * @notapi
 */
#if defined(PAL_NEW_INIT)
void _pal_lld_init(void) {
  /* Set DeBounce conditions */
  GPIO->DBCTL = 0x04u;
}
#else
void _pal_lld_init(const PALConfig *config) {

  /* (void)config; */
  /* Turn on GPIO subsystem
   * Set all GPIO to Input/HZ
   * Clear all GPIO Interrupts
   * Set all GPIO Interrupt Modes to Level
   * Turn off DeBounce
   * Zero all GPIO Outputs (just in case)
   */

  GPIOA->MODE = config->PAData.MODE;
  GPIOA->DINOFF = config->PAData.DINOFF;
  GPIOA->DATMSK = config->PAData.DATMSK;
  GPIOA->DBEN = config->PAData.DBEN;
  GPIOA->INTTYPE = config->PAData.INTTYPE;
  GPIOA->INTEN = config->PAData.INTEN;
  GPIOA->INTSRC = config->PAData.INTSRC;
  GPIOA->SMTEN = config->PAData.SMTEN;
  GPIOA->SLEWCTL = config->PAData.SLEWCTL;
  GPIOA->DOUT = config->PAData.DOUT;

  GPIOB->MODE = config->PBData.MODE;
  GPIOB->DINOFF = config->PBData.DINOFF;
  GPIOB->DATMSK = config->PBData.DATMSK;
  GPIOB->DBEN = config->PBData.DBEN;
  GPIOB->INTTYPE = config->PBData.INTTYPE;
  GPIOB->INTEN = config->PBData.INTEN;
  GPIOB->INTSRC = config->PBData.INTSRC;
  GPIOB->SMTEN = config->PBData.SMTEN;
  GPIOB->SLEWCTL = config->PBData.SLEWCTL;
  GPIOB->DOUT = config->PBData.DOUT;

  GPIOC->MODE = config->PCData.MODE;
  GPIOC->DINOFF = config->PCData.DINOFF;
  GPIOC->DATMSK = config->PCData.DATMSK;
  GPIOC->DBEN = config->PCData.DBEN;
  GPIOC->INTTYPE = config->PCData.INTTYPE;
  GPIOC->INTEN = config->PCData.INTEN;
  GPIOC->INTSRC = config->PCData.INTSRC;
  GPIOC->SMTEN = config->PCData.SMTEN;
  GPIOC->SLEWCTL = config->PCData.SLEWCTL;
  GPIOC->DOUT = config->PCData.DOUT;

  GPIOD->MODE = config->PDData.MODE;
  GPIOD->DINOFF = config->PDData.DINOFF;
  GPIOD->DATMSK = config->PDData.DATMSK;
  GPIOD->DBEN = config->PDData.DBEN;
  GPIOD->INTTYPE = config->PDData.INTTYPE;
  GPIOD->INTEN = config->PDData.INTEN;
  GPIOD->INTSRC = config->PDData.INTSRC;
  GPIOD->SMTEN = config->PDData.SMTEN;
  GPIOD->SLEWCTL = config->PDData.SLEWCTL;
  GPIOD->DOUT = config->PDData.DOUT;

  GPIOE->MODE = config->PEData.MODE;
  GPIOE->DINOFF = config->PEData.DINOFF;
  GPIOE->DATMSK = config->PEData.DATMSK;
  GPIOE->DBEN = config->PEData.DBEN;
  GPIOE->INTTYPE = config->PEData.INTTYPE;
  GPIOE->INTEN = config->PEData.INTEN;
  GPIOE->INTSRC = config->PEData.INTSRC;
  GPIOE->SMTEN = config->PEData.SMTEN;
  GPIOE->SLEWCTL = config->PEData.SLEWCTL;
  GPIOE->DRVCTL = config->PEData.DRVCTL;
  GPIOE->DOUT = config->PEData.DOUT;

  GPIOF->MODE = config->PFData.MODE;
  GPIOF->DINOFF = config->PFData.DINOFF;
  GPIOF->DATMSK = config->PFData.DATMSK;
  GPIOF->DBEN = config->PFData.DBEN;
  GPIOF->INTTYPE = config->PFData.INTTYPE;
  GPIOF->INTEN = config->PFData.INTEN;
  GPIOF->INTSRC = config->PFData.INTSRC;
  GPIOF->SMTEN = config->PFData.SMTEN;
  GPIOF->SLEWCTL = config->PFData.SLEWCTL;
  GPIOF->DOUT = config->PFData.DOUT;

  /* Set DeBounce conditions */
  GPIO->DBCTL = 0x04u;
}
#endif

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

  uint32_t nucMode = 0;

  if (mode == PAL_MODE_INPUT)
      nucMode = GPIO_MODE_INPUT;
  else if (mode == PAL_MODE_OUTPUT_OPENDRAIN)
      nucMode = GPIO_MODE_OPEN_DRAIN;
  else if (mode == PAL_MODE_OUTPUT_PUSHPULL)
      nucMode = GPIO_MODE_OUTPUT;
  else /* mode == PAL_MODE_INPUT_PULLUP */
      nucMode = GPIO_MODE_QUASI;

  for (uint32_t i = 0; i < PAL_IOPORTS_WIDTH; i++) {
    if (mask & (1 << i)) {
      port->MODE = (port->MODE & ~(0x03ul << (i << 1))) | (nucMode << (i << 1));
    }
  }

  if (nucMode == GPIO_MODE_QUASI) {
    port->DOUT |= (uint32_t)(uint16_t)mask;
  }
}

#endif /* HAL_USE_PAL == TRUE */

/** @} */

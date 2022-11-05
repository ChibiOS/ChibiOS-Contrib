/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
#include "sam_extint.h"
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
#if PAL_USE_CALLBACKS || PAL_USE_WAIT || defined(__DOXYGEN__)
#define   EIC_CONFIG_SENSE_NONE_Val          _U_(0x0)                                             /**< (EIC_CONFIG) No detection  */
#define   EIC_CONFIG_SENSE_RISE_Val          _U_(0x1)                                             /**< (EIC_CONFIG) Rising edge detection  */
#define   EIC_CONFIG_SENSE_FALL_Val          _U_(0x2)                                             /**< (EIC_CONFIG) Falling edge detection  */
#define   EIC_CONFIG_SENSE_BOTH_Val          _U_(0x3)                                             /**< (EIC_CONFIG) Both edges detection  */

palevent_t _pal_events[16];

static const uint32_t extint_sense_msk[] = {
  EIC_CONFIG_SENSE0_Msk,
  EIC_CONFIG_SENSE1_Msk,
  EIC_CONFIG_SENSE2_Msk,
  EIC_CONFIG_SENSE3_Msk,
  EIC_CONFIG_SENSE4_Msk,
  EIC_CONFIG_SENSE5_Msk,
  EIC_CONFIG_SENSE6_Msk,
  EIC_CONFIG_SENSE7_Msk,
};

static const uint32_t extint_filten_msk[] = {
  EIC_CONFIG_FILTEN0_Msk,
  EIC_CONFIG_FILTEN1_Msk,
  EIC_CONFIG_FILTEN2_Msk,
  EIC_CONFIG_FILTEN3_Msk,
  EIC_CONFIG_FILTEN4_Msk,
  EIC_CONFIG_FILTEN5_Msk,
  EIC_CONFIG_FILTEN6_Msk,
  EIC_CONFIG_FILTEN7_Msk,
};

static const uint32_t extint_sense_pos[] = {
  EIC_CONFIG_SENSE0_Pos,
  EIC_CONFIG_SENSE1_Pos,
  EIC_CONFIG_SENSE2_Pos,
  EIC_CONFIG_SENSE3_Pos,
  EIC_CONFIG_SENSE4_Pos,
  EIC_CONFIG_SENSE5_Pos,
  EIC_CONFIG_SENSE6_Pos,
  EIC_CONFIG_SENSE7_Pos,
};

static const uint32_t extint_filten_pos[] = {
  EIC_CONFIG_FILTEN0_Pos,
  EIC_CONFIG_FILTEN1_Pos,
  EIC_CONFIG_FILTEN2_Pos,
  EIC_CONFIG_FILTEN3_Pos,
  EIC_CONFIG_FILTEN4_Pos,
  EIC_CONFIG_FILTEN5_Pos,
  EIC_CONFIG_FILTEN6_Pos,
  EIC_CONFIG_FILTEN7_Pos,
};
#endif
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
 * @brief   SAMD21 I/O ports configuration.
 *
 * @notapi
 */
void _pal_lld_init(void) {
#if PAL_USE_CALLBACKS || PAL_USE_WAIT || defined(__DOXYGEN__)
  PM_REGS->PM_APBAMASK |= PM_APBAMASK_EIC_Msk; // Enable Sync Clock for EIC
  /* Map EIC to Generator 0 */
  sam_gclk_mux(0, GCLK_CLKCTRL_ID_EIC_Val, 1);
  /* Reset the EIC */
  EIC_REGS->EIC_CTRL |= EIC_CTRL_SWRST_Msk;
  while((EIC_REGS->EIC_STATUS & EIC_STATUS_SYNCBUSY_Msk) == EIC_STATUS_SYNCBUSY_Msk);
  /* Enable the EIC */
  EIC_REGS->EIC_CTRL |= EIC_CTRL_ENABLE_Msk;
  while((EIC_REGS->EIC_STATUS & EIC_STATUS_SYNCBUSY_Msk) == EIC_STATUS_SYNCBUSY_Msk);
  unsigned i;
  for (i = 0; i < 16; i++) {
  _pal_init_event(i);
  }
  nvicEnableVector(EIC_IRQn, SAM_EIC_IRQ_PRIORITY);
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
                           iomode_t mode) 
{
  /* Part of PINCFG */
  uint32_t pmuxen  = (mode & PAL_SAM_PMUXEN_MASK)    >> 0;
  uint32_t inen    = (mode & PAL_SAM_INEN_MASK)      >> 1;
  uint32_t pullen  = (mode & PAL_SAM_PULLEN_MASK)    >> 2;
  uint32_t drvstr  = (mode & PAL_SAM_DRVSTR_MASK)    >> 3;
  /* DIR and OUT */
  uint32_t dir     = (mode & PAL_SAM_DIR_MASK)       >> 4;
  uint32_t out     = (mode & PAL_SAM_OUT_MASK)       >> 5;
  /* PMUX */
  uint32_t altr    = (mode & PAL_SAM_ALTERNATE_MASK) >> 6;
  uint32_t bit     = 0;
  uint32_t m1;
  while(1) {
    if((mask & 1) != 0) {
      m1 = 1 << bit; 
      if((out >> bit) == 1) {
        port->PORT_OUTSET = m1;
      }
      else {
        port->PORT_OUTCLR = m1;
      }
      if((dir >> bit) == 1) {
        port->PORT_DIRSET = m1;
      }
      else {
        port->PORT_DIRCLR = m1;
      }
      if(pmuxen == PAL_SAM_PMUXEN_PMUX) {
        uint8_t pinmux_val = (uint8_t)(port->PORT_PMUX[(bit >> 1)]);
        /* Odd pin */
        if(0U != (bit & 0x01U)) {
          pinmux_val = (pinmux_val & ~0xF0U) | (altr << 4);
        }
        /* Even pin */
        else {
          pinmux_val = (pinmux_val & ~0x0FU) | altr;
        }
        port->PORT_PMUX[(bit >> 1)] = (uint8_t)pinmux_val;
      }
      uint8_t pincfg_val = (PORT_PINCFG_DRVSTR(drvstr) | PORT_PINCFG_PULLEN(pullen) | 
                            PORT_PINCFG_INEN(inen) | PORT_PINCFG_PMUXEN(pmuxen));
      port->PORT_PINCFG[bit] = pincfg_val;            
    }
    mask >>= 1;
    if (mask == 0) {
      return;
    }
    dir <<= 1;
    out <<= 1;
    bit++;
  }  
}

/**
 * @brief   Writes a group of bits.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @param[in] bits      bits to be written. Values exceeding the group width
 *                      are masked.
 *
 * @notapi
 */
void _pal_lld_writegroup(ioportid_t port, ioportmask_t mask, uint32_t offset, uint32_t bits)
{
  uint32_t out = ((uint32_t)(bits) & (uint32_t)(mask)) << (offset);
  (port)->PORT_OUTSET = out;
  (port)->PORT_OUTCLR = ~out;
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
                             ioeventmode_t mode) 
{
  int8_t extint = _get_extint(port, pad);
  osalDbgAssert(extint >= 0, "Invalid EIC Pin");
  uint32_t inteset = (1ul << extint);
  // if interrupt has been set, asserted as we cannot use 2 pins at the same time
  osalDbgAssert((EIC_REGS->EIC_INTENSET & inteset) == inteset, "EIC Pin has been used");
  uint8_t bank = 0;
  if(extint > 7) {
    bank = 1;
  }
  uint32_t oldcfg = EIC_REGS->EIC_CONFIG[bank];
  uint8_t cfg_channel = extint % 8;
  // Enable Filtering by default
  uint32_t cfg = (1 << extint_filten_pos[cfg_channel]);
  // Configuring Sense
  if((mode & PAL_EVENT_MODE_BOTH_EDGES) == PAL_EVENT_MODE_BOTH_EDGES) {
    cfg |= EIC_CONFIG_SENSE_BOTH_Val << extint_sense_pos[cfg_channel];
  }
  else if ((mode & PAL_EVENT_MODE_RISING_EDGE) == PAL_EVENT_MODE_RISING_EDGE) {
    cfg |= EIC_CONFIG_SENSE_RISE_Val << extint_sense_pos[cfg_channel];
  }
  else if ((mode & PAL_EVENT_MODE_FALLING_EDGE) == PAL_EVENT_MODE_FALLING_EDGE) {
    cfg |= EIC_CONFIG_SENSE_FALL_Val << extint_sense_pos[cfg_channel];
  }
  oldcfg &= ~(extint_sense_msk[cfg_channel] | extint_filten_msk[cfg_channel]); // clear out the bit
  oldcfg |= cfg;
  EIC_REGS->EIC_CONFIG[bank] = oldcfg;
  EIC_REGS->EIC_INTENSET |= inteset;
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
void _pal_lld_disablepadevent(ioportid_t port, iopadid_t pad) 
{
  int8_t extint = _get_extint(port, pad);
  osalDbgAssert(extint >= 0, "Invalid EIC Pin");
  uint32_t intenclr = (1ul << extint);
  EIC_REGS->EIC_INTENCLR |= intenclr;
}

/**
 * @brief   Returns a PAL event structure associated to a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */

palevent_t* _pal_lld_get_pad_event(ioportid_t port, 
                                   iopadid_t pad)
{
  return &_pal_events[_get_extint(port, pad)];
}


/**
 * @brief   Returns a PAL event structure associated to a line.
 *
 * @param[in] line      line identifier
 *
 * @notapi
 */

palevent_t* _pal_lld_get_line_event(ioline_t line)
{
  return &_pal_events[_get_extint(PAL_PORT(line), PAL_PAD(line))];
}

bool _pal_lld_ispadeventenabled(ioportid_t port, iopadid_t pad)
{
  int8_t extint = _get_extint(port, pad);
  uint32_t intenset = 1 << extint;
  if((EIC_REGS->EIC_INTENSET & intenset) == intenset) {
    return true;
  }
  return false;
}


OSAL_IRQ_HANDLER(EIC_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  unsigned i;
  for(i = 0; i < 16; i++) {
    unsigned long intflag = 1UL << i;
    if((EIC_REGS->EIC_INTFLAG & intflag) == intflag) {
      _pal_isr_code(i);
    EIC_REGS->EIC_INTFLAG = (1UL << i); // Clear flag
    }
  }
  OSAL_IRQ_EPILOGUE();
}
#endif

#endif /* HAL_USE_PAL == TRUE */

/** @} */

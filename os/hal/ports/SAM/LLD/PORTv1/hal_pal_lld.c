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
#ifdef SAME54_MCUCONF
#include "sam_gclk_add.h"
#endif
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/
#if PAL_USE_CALLBACKS || PAL_USE_WAIT || defined(__DOXYGEN__)
#define EIC_CONFIG_SENSE_NONE_Val 0x0 /**< (EIC_CONFIG) No detection  */
#define EIC_CONFIG_SENSE_RISE_Val \
  0x1 /**< (EIC_CONFIG) Rising edge detection  */
#define EIC_CONFIG_SENSE_FALL_Val \
  0x2 /**< (EIC_CONFIG) Falling edge detection  */
#define EIC_CONFIG_SENSE_BOTH_Val 0x3 /**< (EIC_CONFIG) Both edges detection  */

palevent_t _pal_events[16];

static const uint32_t extint_sense_msk[] = {
    EIC_CONFIG_SENSE0_Msk, EIC_CONFIG_SENSE1_Msk, EIC_CONFIG_SENSE2_Msk,
    EIC_CONFIG_SENSE3_Msk, EIC_CONFIG_SENSE4_Msk, EIC_CONFIG_SENSE5_Msk,
    EIC_CONFIG_SENSE6_Msk, EIC_CONFIG_SENSE7_Msk,
};

static const uint32_t extint_filten_msk[] = {
    EIC_CONFIG_FILTEN0_Msk, EIC_CONFIG_FILTEN1_Msk, EIC_CONFIG_FILTEN2_Msk,
    EIC_CONFIG_FILTEN3_Msk, EIC_CONFIG_FILTEN4_Msk, EIC_CONFIG_FILTEN5_Msk,
    EIC_CONFIG_FILTEN6_Msk, EIC_CONFIG_FILTEN7_Msk,
};

static const uint32_t extint_sense_pos[] = {
    EIC_CONFIG_SENSE0_Pos, EIC_CONFIG_SENSE1_Pos, EIC_CONFIG_SENSE2_Pos,
    EIC_CONFIG_SENSE3_Pos, EIC_CONFIG_SENSE4_Pos, EIC_CONFIG_SENSE5_Pos,
    EIC_CONFIG_SENSE6_Pos, EIC_CONFIG_SENSE7_Pos,
};

static const uint32_t extint_filten_pos[] = {
    EIC_CONFIG_FILTEN0_Pos, EIC_CONFIG_FILTEN1_Pos, EIC_CONFIG_FILTEN2_Pos,
    EIC_CONFIG_FILTEN3_Pos, EIC_CONFIG_FILTEN4_Pos, EIC_CONFIG_FILTEN5_Pos,
    EIC_CONFIG_FILTEN6_Pos, EIC_CONFIG_FILTEN7_Pos,
};

#ifdef SAME54_MCUCONF
static const uint8_t eic_irq_prio[16] = {
    SAM_EIC_EXTI0_IRQ_PRIORITY,  SAM_EIC_EXTI1_IRQ_PRIORITY,
    SAM_EIC_EXTI2_IRQ_PRIORITY,  SAM_EIC_EXTI3_IRQ_PRIORITY,
    SAM_EIC_EXTI4_IRQ_PRIORITY,  SAM_EIC_EXTI5_IRQ_PRIORITY,
    SAM_EIC_EXTI6_IRQ_PRIORITY,  SAM_EIC_EXTI7_IRQ_PRIORITY,
    SAM_EIC_EXTI8_IRQ_PRIORITY,  SAM_EIC_EXTI9_IRQ_PRIORITY,
    SAM_EIC_EXTI10_IRQ_PRIORITY, SAM_EIC_EXTI11_IRQ_PRIORITY,
    SAM_EIC_EXTI12_IRQ_PRIORITY, SAM_EIC_EXTI13_IRQ_PRIORITY,
    SAM_EIC_EXTI14_IRQ_PRIORITY, SAM_EIC_EXTI15_IRQ_PRIORITY,
};
#endif

#endif
/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
#if PAL_USE_CALLBACKS || PAL_USE_WAIT || defined(__DOXYGEN__)
#ifdef SAME54_MCUCONF

static inline void pal_lld_serve_interrupt(const uint32_t line) {
  unsigned long intflag = 1UL << line;
  if ((EIC_REGS->EIC_INTFLAG & intflag) == intflag) {
    _pal_isr_code(line);
    EIC_REGS->EIC_INTFLAG = (1UL << line);  // Clear flag
  }
}

static inline void pal_lld_eic_enable_set(const bool en) {
  /* Enable EIC */
  if (en)
    EIC_REGS->EIC_CTRLA |= EIC_CTRLA_ENABLE_Msk;
  else
    EIC_REGS->EIC_CTRLA &= ~EIC_CTRLA_ENABLE_Msk;
  while ((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_ENABLE_Msk) ==
         EIC_SYNCBUSY_ENABLE_Msk) {}
}

#elif defined(SAMD21_MCUCONF)
static inline void pal_lld_eic_enable_set(const bool en) {
  /* Enable EIC */
  if (en)
    EIC_REGS->EIC_CTRL |= EIC_CTRL_ENABLE_Msk;
  else
    EIC_REGS->EIC_CTRL &= ~EIC_CTRL_ENABLE_Msk;
  while ((EIC_REGS->EIC_STATUS & EIC_STATUS_SYNCBUSY_Msk) ==
         EIC_STATUS_SYNCBUSY_Msk) {}
}

#endif
#endif
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

#if defined(SAMD21_MCUCONF)
  PM_REGS->PM_APBAMASK |= PM_APBAMASK_EIC_Msk;  // Enable Sync Clock for EIC
  /* Map EIC to Generator 0 */
  sam_gclk_mux(0, GCLK_PCHCTRL_ID_EIC_Val, 1);
  /* Reset the EIC */
  EIC_REGS->EIC_CTRL |= EIC_CTRL_SWRST_Msk;
  while ((EIC_REGS->EIC_STATUS & EIC_STATUS_SYNCBUSY_Msk) ==
         EIC_STATUS_SYNCBUSY_Msk)
    unsigned i;
  for (i = 0; i < 16; i++) {
    _pal_init_event(i);
  }
  nvicEnableVector(EIC_IRQn, SAM_EIC_IRQ_PRIORITY);

#elif defined(SAME54_MCUCONF)
  MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_EIC_Msk;
  /* Map EIC to Generator 0 */
  sam_gclk_mux(0, GCLK_PCHCTRL_ID_EIC_Val, TRUE);
  /* Reset all registers in the EIC module to their initial state and
      EIC will be disabled. */
  EIC_REGS->EIC_CTRLA |= (uint8_t)EIC_CTRLA_SWRST_Msk;

  while ((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_SWRST_Msk) ==
         EIC_SYNCBUSY_SWRST_Msk) {}

  for (unsigned i = 0; i < 16; i++) {
    _pal_init_event(i);
  }
#endif

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
void _pal_lld_setgroupmode(ioportid_t port, ioportmask_t mask, iomode_t mode) {
  /* Part of PINCFG */
  uint32_t pmuxen = (mode & PAL_SAM_PMUXEN_MASK) >> 0;
  uint32_t inen = (mode & PAL_SAM_INEN_MASK) >> 1;
  uint32_t pullen = (mode & PAL_SAM_PULLEN_MASK) >> 2;
  uint32_t drvstr = (mode & PAL_SAM_DRVSTR_MASK) >> 3;
  /* DIR and OUT */
  uint32_t dir = (mode & PAL_SAM_DIR_MASK) >> 4;
  uint32_t out = (mode & PAL_SAM_OUT_MASK) >> 5;
  /* PMUX */
  uint32_t altr = (mode & PAL_SAM_ALTERNATE_MASK) >> 6;
  uint32_t bit = 0;
  uint32_t m1;
  while (1) {
    if ((mask & 1) != 0) {
      m1 = 1 << bit;
      if ((out >> bit) == 1) {
        port->PORT_OUTSET = m1;
      } else {
        port->PORT_OUTCLR = m1;
      }
      if ((dir >> bit) == 1) {
        port->PORT_DIRSET = m1;
      } else {
        port->PORT_DIRCLR = m1;
      }
      if (pmuxen == PAL_SAM_PMUXEN_PMUX) {
        uint8_t pinmux_val = (uint8_t)(port->PORT_PMUX[(bit >> 1)]);
        /* Odd pin */
        if (0U != (bit & 0x01U)) {
          pinmux_val = (pinmux_val & ~0xF0U) | (altr << 4);
        }
        /* Even pin */
        else {
          pinmux_val = (pinmux_val & ~0x0FU) | altr;
        }
        port->PORT_PMUX[(bit >> 1)] = (uint8_t)pinmux_val;
      }
      uint8_t pincfg_val =
          (PORT_PINCFG_DRVSTR(drvstr) | PORT_PINCFG_PULLEN(pullen) |
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
void _pal_lld_writegroup(ioportid_t port, ioportmask_t mask, uint32_t offset,
                         uint32_t bits) {
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
void _pal_lld_enablepadevent(ioportid_t port, iopadid_t pad,
                             ioeventmode_t mode) {
  pal_lld_eic_enable_set(FALSE);
  int8_t extint = _get_extint(port, pad);
  osalDbgAssert(extint >= 0, "Invalid EIC Pin");
  if (extint < 0) {
    return;
  }
  uint32_t intenset = (1ul << extint);
  // if interrupt has been set, asserted as we cannot use 2 pins at the same time
  osalDbgAssert((EIC_REGS->EIC_INTENSET & intenset) != intenset,
                "EIC Pin has been used");
  uint8_t bank = 0;
  if (extint > 7) {
    bank = 1;
  }
  uint32_t oldcfg = EIC_REGS->EIC_CONFIG[bank];
  uint8_t cfg_channel = extint % 8;
  // Enable Filtering by default
  uint32_t cfg = (1 << extint_filten_pos[cfg_channel]);
  // Configuring Sense
  if ((mode & PAL_EVENT_MODE_BOTH_EDGES) == PAL_EVENT_MODE_BOTH_EDGES) {
    cfg |= EIC_CONFIG_SENSE_BOTH_Val << extint_sense_pos[cfg_channel];
  } else if ((mode & PAL_EVENT_MODE_RISING_EDGE) ==
             PAL_EVENT_MODE_RISING_EDGE) {
    cfg |= EIC_CONFIG_SENSE_RISE_Val << extint_sense_pos[cfg_channel];
  } else if ((mode & PAL_EVENT_MODE_FALLING_EDGE) ==
             PAL_EVENT_MODE_FALLING_EDGE) {
    cfg |= EIC_CONFIG_SENSE_FALL_Val << extint_sense_pos[cfg_channel];
  }
  oldcfg &= ~(extint_sense_msk[cfg_channel] |
              extint_filten_msk[cfg_channel]);  // clear out the bit
  oldcfg |= cfg;
#ifdef SAME54_MCUCONF
  nvicEnableVector(EIC_EXTINT_0_IRQn + extint, eic_irq_prio[extint]);
#endif
  EIC_REGS->EIC_CONFIG[bank] = oldcfg;
  EIC_REGS->EIC_INTENSET = intenset;
  /* Enable EIC */
  pal_lld_eic_enable_set(TRUE);
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
  int8_t extint = _get_extint(port, pad);
  osalDbgAssert(extint >= 0, "Invalid EIC Pin");
  uint32_t intenclr = (1ul << extint);
  EIC_REGS->EIC_INTENCLR = intenclr;
#ifdef SAME54_MCUCONF
  nvicDisableVector(EIC_EXTINT_0_IRQn + extint);
#endif
}

/**
 * @brief   Returns a PAL event structure associated to a pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */

palevent_t* _pal_lld_get_pad_event(ioportid_t port, iopadid_t pad) {
  return &_pal_events[_get_extint(port, pad)];
}

/**
 * @brief   Returns a PAL event structure associated to a line.
 *
 * @param[in] line      line identifier
 *
 * @notapi
 */

palevent_t* _pal_lld_get_line_event(ioline_t line) {
  return &_pal_events[_get_extint(PAL_PORT(line), PAL_PAD(line))];
}

bool _pal_lld_ispadeventenabled(ioportid_t port, iopadid_t pad) {
  int8_t extint = _get_extint(port, pad);
  uint32_t intenset = 1 << extint;
  if ((EIC_REGS->EIC_INTENSET & intenset) == intenset) {
    return true;
  }
  return false;
}

#ifdef SAMD21_MCUCONF
OSAL_IRQ_HANDLER(EIC_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  unsigned i;
  for (i = 0; i < 16; i++) {
    unsigned long intflag = 1UL << i;
    if ((EIC_REGS->EIC_INTFLAG & intflag) == intflag) {
      _pal_isr_code(i);
      EIC_REGS->EIC_INTFLAG = (1UL << i);  // Clear flag
    }
  }
  OSAL_IRQ_EPILOGUE();
}
#elif defined(SAME54_MCUCONF)

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(0);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(1);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(2);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(3);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_4_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(4);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_5_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(5);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_6_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(6);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_7_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(7);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_8_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(8);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_9_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(9);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_10_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(10);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_11_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(11);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_12_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(12);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_13_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(13);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_14_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(14);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_EIC_EXTINT_15_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  pal_lld_serve_interrupt(15);
  OSAL_IRQ_EPILOGUE();
}

#endif

#endif

#endif /* HAL_USE_PAL == TRUE */

/** @} */

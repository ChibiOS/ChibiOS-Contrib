/*
    Copyright (C) 2019 /u/KeepItUnder
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/hal_pal_lld.c
 * @brief   M251/M252 PAL subsystem low level driver source.
 *
 * @addtogroup PAL
 * @{
 */

#include "hal.h"

#if (HAL_USE_PAL == TRUE) || defined(__DOXYGEN__)

static void _pal_lld_setgroupmfp_gpio(ioportid_t port, ioportmask_t mask) {
  uint32_t mfpl_mask = 0U;
  uint32_t mfph_mask = 0U;
  uint32_t port_index;
  volatile uint32_t *mfpl;
  bool relock;

  for (uint32_t i = 0U; i < PAL_IOPORTS_WIDTH; i++) {
    if ((mask & (1UL << i)) != 0U) {
      if (i < 8U) {
        mfpl_mask |= 0xFUL << (i * 4U);
      }
      else {
        mfph_mask |= 0xFUL << ((i - 8U) * 4U);
      }
    }
  }

  relock = (SYS->REGLCTL & 1U) == 0U;
  if (relock) {
    m251_lld_unlock();
  }

  port_index = ((uint32_t)port - GPIOA_BASE) / 0x40U;
  mfpl = (volatile uint32_t *)((uint32_t)&SYS->GPA_MFPL +
                               (port_index * 8U));

  if (mfpl_mask != 0U) {
    *mfpl &= ~mfpl_mask;
  }
  if (mfph_mask != 0U) {
    *(mfpl + 1U) &= ~mfph_mask;
  }

  if (relock) {
    m251_lld_lock();
  }
}

/**
 * @brief   Low level PAL driver initialization.
 *
 * @notapi
 */
void _pal_lld_init(void) {
#if (PAL_USE_WAIT == TRUE) || (PAL_USE_CALLBACKS == TRUE)
  for (size_t i = 0U; i < M251_PAL_EVENT_TOTAL; i++) {
    _pal_init_event(i);
  }
#endif

}

/**
 * @brief   Configures a group of pads.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] mode      group mode
 *
 * @notapi
 */
void _pal_lld_setgroupmode(ioportid_t port,
                           ioportmask_t mask,
                           iomode_t mode) {
  uint32_t mode_bits = mode & PAL_M251_MODE_MASK;
  uint32_t pull_bits = (mode & PAL_M251_PULL_MASK) >> 2U;
  uint32_t dinoff_mask = 0U;

  if ((mode & PAL_M251_MFP_PRESERVE) == 0U) {
    _pal_lld_setgroupmfp_gpio(port, mask);
  }

  for (uint32_t i = 0U; i < PAL_IOPORTS_WIDTH; i++) {
    uint32_t bit = 1UL << i;

    if ((mask & bit) != 0U) {
      port->MODE = (port->MODE & ~(0x3UL << (i * 2U))) |
                   (mode_bits << (i * 2U));
      port->PUSEL = (port->PUSEL & ~(0x3UL << (i * 2U))) |
                    (pull_bits << (i * 2U));
      dinoff_mask |= (1UL << (i + 16U));
    }
  }

  if ((mode & PAL_M251_DINOFF) != 0U) {
    port->DINOFF |= dinoff_mask;
  }
  else {
    port->DINOFF &= ~dinoff_mask;
  }

  if (mode_bits == PAL_M251_MODE_QUASI) {
    port->DOUT |= (uint32_t)mask;
  }
}

#endif /* HAL_USE_PAL == TRUE */

#if ((HAL_USE_PAL == TRUE) && ((PAL_USE_WAIT == TRUE) ||                    \
                               (PAL_USE_CALLBACKS == TRUE))) ||             \
    defined(__DOXYGEN__)

#include "m251_isr.h"

/**
 * @brief   PAL event records.
 */
palevent_t _pal_events[M251_PAL_EVENT_TOTAL];

static inline uint32_t _pal_port_index(ioportid_t port) {
  return ((uint32_t)(port) - GPIOA_BASE) / 0x40U;
}

/**
 * @brief   Disables a pad event.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad identifier
 *
 * @notapi
 */
void _pal_lld_disablepadevent(ioportid_t port, iopadid_t pad) {
  uint32_t padbit = 1UL << pad;
  uint32_t ei = _pal_port_index(port) * PAL_IOPORTS_WIDTH + pad;

  port->INTTYPE &= ~padbit;
  port->INTEN &= ~(padbit | (padbit << 16U));
  port->INTSRC = padbit;

  _pal_clear_event(ei);
}

/**
 * @brief   Returns the enabled state of a pad event.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad identifier
 * @return              The pad event enabled state.
 *
 * @notapi
 */
bool _pal_lld_ispadeventenabled(ioportid_t port, iopadid_t pad) {
  return (port->INTEN & ((1UL << pad) | (1UL << (pad + 16U)))) != 0U;
}

#define M251_SERVE_GPIO_IRQ(port, base_idx)                                   \
  do {                                                                        \
    uint32_t intsrc = (port)->INTSRC;                                         \
    uint32_t bit = 0U;                                                        \
    while (intsrc != 0U) {                                                    \
      if (intsrc & 1U) {                                                      \
        (port)->INTSRC = (1UL << bit);                                        \
        _pal_isr_code((base_idx) * PAL_IOPORTS_WIDTH + bit);                  \
      }                                                                       \
      intsrc >>= 1U;                                                          \
      bit++;                                                                  \
    }                                                                         \
  } while (false)

/**
 * @brief   GPIOA interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_GPA_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  M251_SERVE_GPIO_IRQ(PA, 0);
  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   GPIOB interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_GPB_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  M251_SERVE_GPIO_IRQ(PB, 1);
  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   GPIOC interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_GPC_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  M251_SERVE_GPIO_IRQ(PC, 2);
  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   GPIOD interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_GPD_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  M251_SERVE_GPIO_IRQ(PD, 3);
  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   GPIOE interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_GPE_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  M251_SERVE_GPIO_IRQ(PE, 4);
  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   GPIOF interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(M251_GPF_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  M251_SERVE_GPIO_IRQ(PF, 5);
  OSAL_IRQ_EPILOGUE();
}

static bool _pal_nvic_enabled = false;

static void _pal_enable_nvic(void) {
  if (!_pal_nvic_enabled) {
    nvicEnableVector(M251_GPA_NUMBER, M251_GPIO_IRQ_PRIORITY);
    nvicEnableVector(M251_GPB_NUMBER, M251_GPIO_IRQ_PRIORITY);
    nvicEnableVector(M251_GPC_NUMBER, M251_GPIO_IRQ_PRIORITY);
    nvicEnableVector(M251_GPD_NUMBER, M251_GPIO_IRQ_PRIORITY);
    nvicEnableVector(M251_GPE_NUMBER, M251_GPIO_IRQ_PRIORITY);
    nvicEnableVector(M251_GPF_NUMBER, M251_GPIO_IRQ_PRIORITY);
    _pal_nvic_enabled = true;
  }
}

/**
 * @brief   Enables a pad event.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad identifier
 * @param[in] mode      event trigger mode
 *
 * @notapi
 */
void _pal_lld_enablepadevent(ioportid_t port, iopadid_t pad,
                             ioeventmode_t mode) {
  uint32_t padbit = 1UL << pad;

  if (mode == PAL_EVENT_MODE_DISABLED) {
    _pal_lld_disablepadevent(port, pad);
    return;
  }

  port->INTEN &= ~(padbit | (padbit << 16U));
  port->INTTYPE &= ~padbit;
  port->INTSRC = padbit;

  if (mode & PAL_EVENT_MODE_FALLING_EDGE)
    port->INTEN |= padbit;

  if (mode & PAL_EVENT_MODE_RISING_EDGE)
    port->INTEN |= (padbit << 16U);

  _pal_enable_nvic();
}

#endif

/** @} */

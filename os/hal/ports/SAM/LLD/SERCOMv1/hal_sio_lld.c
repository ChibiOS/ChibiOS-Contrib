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
 * @file    hal_sio_lld.c
 * @brief   PLATFORM SIO subsystem low level driver source.
 *
 * @addtogroup SIO
 * @{
 */

#include "hal.h"

#if (HAL_USE_SIO == TRUE) || defined(__DOXYGEN__)
#include "sercom_clk.h"
/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define SERCOM_UART_CTRLA_FORBIDDEN                                  (SERCOM_USART_INT_CTRLA_ENABLE_Msk | \
                                                                      SERCOM_USART_INT_CTRLA_SWRST_Msk | \
                                                                      SERCOM_USART_INT_CTRLA_TXPO_Msk | \
                                                                      SERCOM_USART_INT_CTRLA_RXPO_Msk)

#define SERCOM_UART_CTRLB_FORBIDDEN                                  (SERCOM_USART_INT_CTRLB_ENC_Msk)

#define SERCOM_USART_INTENSET_FULL_IRQ                               (SERCOM_USART_INT_INTENSET_DRE_Msk | \
                                                                      SERCOM_USART_INT_INTENSET_TXC_Msk | \
                                                                      SERCOM_USART_INT_INTENSET_RXC_Msk | \
                                                                      SERCOM_USART_INT_INTENSET_RXBRK_Msk | \
                                                                      SERCOM_USART_INT_INTENSET_ERROR_Msk);
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   SIO1 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM0 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD1;
#endif

/**
 * @brief   SIO2 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM1 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD2;
#endif

/**
 * @brief   SIO3 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM2 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD3;
#endif

/**
 * @brief   SIO4 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM3 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD4;
#endif

/**
 * @brief   SIO5 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM4 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD5;
#endif

/**
 * @brief   SIO6 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM5 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD6;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline uint16_t usart_baud_calc(SIODriver *siop)
{
  return (uint16_t)((uint64_t)65536 * (siop->clock - 16 * siop->config->baud) / siop->clock);
}

static inline void usart_reset(SIODriver *siop)
{
  siop->usart->SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_SWRST_Msk;
  while((siop->usart->SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_SWRST_Msk) != 0U);
}

static inline void usart_init(SIODriver *siop)
{
  siop->usart->SERCOM_BAUD = SERCOM_USART_INT_BAUD_BAUD(usart_baud_calc(siop));
  siop->usart->SERCOM_CTRLA = (siop->config->ctrla & ~(SERCOM_UART_CTRLA_FORBIDDEN)) | 
                                SERCOM_USART_INT_CTRLA_TXPO(siop->config->txpo) | 
                                SERCOM_USART_INT_CTRLA_RXPO(siop->config->rxpo) | 
                                SERCOM_USART_INT_CTRLA_ENABLE_Msk;
  while((siop->usart->SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_ENABLE_Msk) != 0U);
  siop->usart->SERCOM_CTRLB = (siop->config->ctrlb & ~(SERCOM_UART_CTRLB_FORBIDDEN)) | SERCOM_USART_INT_CTRLB_RXEN_Msk | SERCOM_USART_INT_CTRLB_TXEN_Msk;
  while((siop->usart->SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_CTRLB_Msk) != 0U);
}

static inline void usart_enable_rx_irq(SIODriver *siop)
{
  #if SIO_USE_SYNCHRONIZATION == TRUE
    siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_RXC_Msk;
  #else
    if (siop->operation->rx_cb != NULL) {
      siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_RXC_Msk;
    }
  #endif
}

static inline void usart_enable_rx_evt_irq(SIODriver *siop)
{
  #if SIO_USE_SYNCHRONIZATION == TRUE
    siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_RXBRK_Msk | 
                                    SERCOM_USART_INT_INTENSET_ERROR_Msk;
  #else
    if (siop->operation->rx_cb != NULL) {
      siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_RXBRK_Msk | 
                                      SERCOM_USART_INT_INTENSET_ERROR_Msk;
    }
  #endif
}

static inline void usart_enable_tx_irq(SIODriver *siop) {

#if SIO_USE_SYNCHRONIZATION == TRUE
  siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_DRE_Msk;
#else
  if (siop->operation->tx_cb != NULL) {
    siop->usart->CR3 |= SERCOM_USART_INT_INTENSET_DRE_Msk;
  }
#endif
}

static inline void usart_enable_tx_end_irq(SIODriver *siop) {

#if SIO_USE_SYNCHRONIZATION == TRUE
  siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_TXC_Msk;
#else
  if (siop->operation->tx_end_cb != NULL) {
    siop->usart->SERCOM_INTENSET |= SERCOM_USART_INT_INTENSET_TXC_Msk;
  }
#endif
}
/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/



/**
 * @brief   Serves an USART interrupt.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 *
 * @notapi
 */
void sio_lld_serve_interrupt(SIODriver *siop) {
  osalDbgAssert(siop->state == SIO_ACTIVE, "invalid state");
  uint8_t intflag = siop->usart->SERCOM_INTFLAG;
  uint8_t intenset = siop->usart->SERCOM_INTENSET;
  uint8_t evtmask = intflag & (SERCOM_USART_INT_INTFLAG_ERROR_Msk | 
                                SERCOM_USART_INT_INTFLAG_RXBRK_Msk);
  if(evtmask != 0) {
    siop->usart->SERCOM_INTENCLR = (SERCOM_USART_INT_INTENCLR_ERROR_Msk | SERCOM_USART_INT_INTENCLR_RXBRK_Msk);
    __sio_callback_rx_evt(siop);

    /* Waiting thread woken, if any.*/
    __sio_wakeup_rx(siop, SIO_MSG_ERRORS);
  }
  if((intflag & SERCOM_USART_INT_INTFLAG_RXC_Msk) && 
    (intenset & SERCOM_USART_INT_INTENSET_RXC_Msk)) {
    siop->usart->SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_RXC_Msk;
    /* The callback is invoked if defined.*/
    __sio_callback_rx(siop);

    /* Waiting thread woken, if any.*/
    __sio_wakeup_rx(siop, MSG_OK);
  }
  /* TX FIFO is non-full.*/
  if ((intflag & SERCOM_USART_INT_INTFLAG_DRE_Msk) && 
    (intenset & SERCOM_USART_INT_INTENSET_DRE_Msk))  {
    siop->usart->SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_DRE_Msk;
    /* The callback is invoked if defined.*/
    __sio_callback_tx(siop);

    /* Waiting thread woken, if any.*/
    __sio_wakeup_tx(siop, MSG_OK);
  }

  /* Physical transmission end.*/
  if ((intflag & SERCOM_USART_INT_INTFLAG_TXC_Msk) && 
    (intenset & SERCOM_USART_INT_INTENSET_TXC_Msk)) {
    siop->usart->SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_TXC_Msk;
    /* The callback is invoked if defined.*/
    __sio_callback_tx_end(siop);

    /* Waiting thread woken, if any.*/
    __sio_wakeup_txend(siop, MSG_OK);
  }
}

#if SAM_SIO_USE_SERCOM0 == TRUE
OSAL_IRQ_HANDLER(SERCOM0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
OSAL_IRQ_HANDLER(SERCOM1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
OSAL_IRQ_HANDLER(SERCOM2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD3);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
OSAL_IRQ_HANDLER(SERCOM3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD4);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
OSAL_IRQ_HANDLER(SERCOM4_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD5);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
OSAL_IRQ_HANDLER(SERCOM5_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD6);
  OSAL_IRQ_EPILOGUE();
}
#endif


/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SIO driver initialization.
 *
 * @notapi
 */
void sio_lld_init(void) {

#if SAM_SIO_USE_SERCOM0 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD1);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM0_Msk;
  SIOD1.usart = &SERCOM0_REGS->USART_INT;
  SIOD1.clock = SAM_SERCOM0_GCLK_SRC_FREQ;
#endif
#if SAM_SIO_USE_SERCOM1 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD2);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM1_Msk;
  SIOD2.usart = &SERCOM1_REGS->USART_INT;
  SIOD2.clock = SAM_SERCOM1_GCLK_SRC_FREQ;
#endif
#if SAM_SIO_USE_SERCOM2 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD3);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM2_Msk;
  SIOD3.usart = &SERCOM2_REGS->USART_INT;
  SIOD3.clock = SAM_SERCOM2_GCLK_SRC_FREQ;
#endif
#if SAM_SIO_USE_SERCOM3 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD4);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM3_Msk;
  SIOD4.usart = &SERCOM3_REGS->USART_INT;
  SIOD4.clock = SAM_SERCOM3_GCLK_SRC_FREQ;
#endif
#if SAM_SIO_USE_SERCOM4 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD5);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM4_Msk;
  SIOD5.usart = &SERCOM4_REGS->USART_INT;
  SIOD5.clock = SAM_SERCOM4_GCLK_SRC_FREQ;
#endif
#if SAM_SIO_USE_SERCOM5 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD6);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM5_Msk;
  SIOD6.usart = &SERCOM5_REGS->USART_INT;
  SIOD6.clock = SAM_SERCOM5_GCLK_SRC_FREQ;
#endif
}

/**
 * @brief   Configures and activates the SIO peripheral.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The operation status.
 *
 * @notapi
 */
msg_t sio_lld_start(SIODriver *siop) {
  
  if (siop->config == NULL) {
    osalDbgAssert(siop->config, "SERCOM requires configuration");
  }
  if (siop->state == SIO_STOP) {
    /* Enables the peripheral.*/
#if SAM_SIO_USE_SERCOM0 == TRUE
    if (&SIOD1 == siop) {
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 1);
      usart_reset(&SIOD1);
      nvicEnableVector(SERCOM0_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
    if (&SIOD2 == siop) {
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 1);
      usart_reset(&SIOD2);
      nvicEnableVector(SERCOM1_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
    if (&SIOD3 == siop) {
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 1);
      usart_reset(&SIOD3);
      nvicEnableVector(SERCOM2_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
    if (&SIOD4 == siop) {
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 1);
      usart_reset(&SIOD4);
      nvicEnableVector(SERCOM3_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
    if (&SIOD5 == siop) {
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 1);
      usart_reset(&SIOD5);
      nvicEnableVector(SERCOM4_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
    if (&SIOD6 == siop) {
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 1);
      usart_reset(&SIOD6);
      nvicEnableVector(SERCOM5_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
    }
#endif
  }
  /* Configures the peripheral.*/
  usart_init(siop);
  return HAL_RET_SUCCESS;
}

/**
 * @brief   Deactivates the SIO peripheral.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 *
 * @notapi
 */
void sio_lld_stop(SIODriver *siop) {

  if (siop->state == SIO_READY) {
    /* Resets the peripheral.*/
    
    /* Disables the peripheral.*/
#if SAM_SIO_USE_SERCOM0 == TRUE
    if (&SIOD1 == siop) {
      usart_reset(&SIOD1);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 0);
      nvicDisableVector(SERCOM0_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
    if (&SIOD2 == siop) {
      usart_reset(&SIOD2);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 0);
      nvicDisableVector(SERCOM1_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
    if (&SIOD3 == siop) {
      usart_reset(&SIOD3);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 0);
      nvicDisableVector(SERCOM2_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
    if (&SIOD4 == siop) {
      usart_reset(&SIOD4);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 0);
      nvicDisableVector(SERCOM3_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
    if (&SIOD5 == siop) {
      usart_reset(&SIOD5);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 0);
      nvicDisableVector(SERCOM4_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
    if (&SIOD6 == siop) {
      usart_reset(&SIOD6);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 0);
      nvicDisableVector(SERCOM5_IRQn);
    }
#endif
  }
}

/**
 * @brief   Starts a SIO operation.
 *
 * @param[in] siop          pointer to an @p SIODriver structure
 *
 * @api
 */
void sio_lld_start_operation(SIODriver *siop) {
  #if SIO_USE_SYNCHRONIZATION == TRUE
  siop->usart->SERCOM_INTENSET = SERCOM_USART_INTENSET_FULL_IRQ;
  #else 
  uint8_t intenset = 0;
  if (siop->operation->rx_cb != NULL) {
    intenset |= SERCOM_USART_INT_INTENSET_RXC_Msk;
  }
  if (siop->operation->rx_idle_cb != NULL) {
    osalDbgAssert(false, "unsupported callback");
  }
  if (siop->operation->tx_cb != NULL) {
    intenset |= SERCOM_USART_INT_INTENSET_DRE_Msk;
  }
  if (siop->operation->tx_end_cb != NULL) {
    intenset |= SERCOM_USART_INT_INTENSET_TXC_Msk;
  }
  if (siop->operation->rx_evt_cb != NULL) {
    intenset |= SERCOM_USART_INT_INTENSET_RXBRK_Msk | 
                SERCOM_USART_INT_INTENSET_ERROR_Msk;
  }
  siop->usart->SERCOM_INTENSET = intenset;
  #endif
  siop->usart->SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;
  while((siop->usart->SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_ENABLE_Msk) != 0U);
}

/**
 * @brief   Stops an ongoing SIO operation, if any.
 *
 * @param[in] siop      pointer to an @p SIODriver structure
 *
 * @api
 */
void sio_lld_stop_operation(SIODriver *siop) {

  // Clear all interrupts
  siop->usart->SERCOM_INTENCLR = SERCOM_USART_INTENSET_FULL_IRQ;
  // disable sercom
  siop->usart->SERCOM_CTRLA &= ~SERCOM_USART_INT_CTRLA_ENABLE_Msk;
  while((siop->usart->SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_ENABLE_Msk) != 0U);
}

/**
 * @brief   Return the pending SIO events flags.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The pending event flags.
 *
 * @notapi
 */
sio_events_mask_t  sio_lld_get_and_clear_events(SIODriver *siop) {
  sio_events_mask_t evtmask = 0;
  uint8_t status = 0;
  uint8_t irq_status = 0;
  status = (uint8_t)(siop->usart->SERCOM_STATUS);
  irq_status = (uint8_t)(siop->usart->SERCOM_INTFLAG);
  if(status & SERCOM_USART_INT_STATUS_BUFOVF_Msk) {
    evtmask |= SIO_OVERRUN_ERROR;
  }
  if(status & SERCOM_USART_INT_STATUS_FERR_Msk) {
    evtmask |= SIO_FRAMING_ERROR;
  }
  if(status & SERCOM_USART_INT_STATUS_PERR_Msk) {
    evtmask |= SIO_PARITY_ERROR;
  }
  if(irq_status & SERCOM_USART_INT_INTFLAG_RXBRK_Msk) {
    evtmask |= SIO_BREAK_DETECTED;
    irq_status |= SERCOM_USART_INT_INTFLAG_RXBRK_Msk;
  }

  return evtmask;
}

/**
 * @brief   Reads data from the RX FIFO.
 * @details The function is not blocking, it writes frames until there
 *          is space available without waiting.
 *
 * @param[in] siop          pointer to an @p SIODriver structure
 * @param[in] buffer        pointer to the buffer for read frames
 * @param[in] n             maximum number of frames to be read
 * @return                  The number of frames copied from the buffer.
 * @retval 0                if the TX FIFO is full.
 */
size_t sio_lld_read(SIODriver *siop, uint8_t *buffer, size_t n) {
  size_t rd;

  rd = 0U;
  while (true) {

    /* If the RX FIFO has been emptied then the interrupt is enabled again.*/
    if (sio_lld_is_rx_empty(siop)) {
      usart_enable_rx_irq(siop);
      break;
    }

    /* Buffer filled condition.*/
    if (rd > n) {
      break;
    }

    *buffer++ = (uint8_t)siop->usart->SERCOM_DATA;
    rd++;
  }

  return rd;
}

/**
 * @brief   Writes data into the TX FIFO.
 * @details The function is not blocking, it writes frames until there
 *          is space available without waiting.
 *
 * @param[in] siop          pointer to an @p SIODriver structure
 * @param[in] buffer        pointer to the buffer for read frames
 * @param[in] n             maximum number of frames to be written
 * @return                  The number of frames copied from the buffer.
 * @retval 0                if the TX FIFO is full.
 */
size_t sio_lld_write(SIODriver *siop, const uint8_t *buffer, size_t n) {

  size_t wr;

  wr = 0U;
  while (true) {

    /* If the TX FIFO has been filled then the interrupt is enabled again.*/
    if (sio_lld_is_tx_full(siop)) {
      usart_enable_tx_irq(siop);
      break;
    }

    /* Buffer emptied condition.*/
    if (wr >= n) {
      break;
    }
    uint8_t data = *buffer++;
    siop->usart->SERCOM_DATA = data;
    wr++;
  }

  /* The transmit complete interrupt is always re-enabled on write.*/
  usart_enable_tx_end_irq(siop);

  return wr;
}

/**
 * @brief   Returns one frame from the RX FIFO.
 * @note    If the FIFO is empty then the returned value is unpredictable.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The frame from RX FIFO.
 *
 * @notapi
 */
msg_t sio_lld_get(SIODriver *siop) {
  msg_t msg;

  msg = (uint8_t)(siop->usart->SERCOM_DATA);

  /* If the RX FIFO has been emptied then the interrupt is enabled again.*/
  if (sio_lld_is_rx_empty(siop)) {
    usart_enable_rx_irq(siop);
  }

  return msg;
}

/**
 * @brief   Pushes one frame into the TX FIFO.
 * @note    If the FIFO is full then the behavior is unpredictable.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @param[in] data      frame to be written
 *
 * @notapi
 */
void sio_lld_put(SIODriver *siop, uint_fast16_t data) {

  siop->usart->SERCOM_DATA = (uint8_t)data;

  /* If the TX FIFO has been filled then the interrupt is enabled again.*/
  if (sio_lld_is_tx_full(siop)) {
    usart_enable_tx_irq(siop);
  }

  /* The transmit complete interrupt is always re-enabled on write.*/
  usart_enable_tx_end_irq(siop);
}

/**
 * @brief   Control operation on a serial port.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @param[in] operation control operation code
 * @param[in,out] arg   operation argument
 *
 * @return              The control operation status.
 * @retval MSG_OK       in case of success.
 * @retval MSG_TIMEOUT  in case of operation timeout.
 * @retval MSG_RESET    in case of operation reset.
 *
 * @notapi
 */
msg_t sio_lld_control(SIODriver *siop, unsigned int operation, void *arg) {

  (void)siop;
  (void)operation;
  (void)arg;

  return MSG_OK;
}


#endif /* HAL_USE_SIO == TRUE */

/** @} */

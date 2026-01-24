/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2026 HorrorTroll
    ChibiOS - Copyright (C) 2023..2026 Zhaqian

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
 * @file    USARTv2/hal_sio_lld.c
 * @brief   AT32 SIO subsystem low level driver source.
 *
 * @addtogroup SIO
 * @{
 */

#include "hal.h"

#if (HAL_USE_SIO == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define USART_CTRL1_CFG_FORBIDDEN           (USART_CTRL1_RETODIE        |   \
                                             USART_CTRL1_CMDIE          |   \
                                             USART_CTRL1_PERRIEN        |   \
                                             USART_CTRL1_TDBEIEN        |   \
                                             USART_CTRL1_TDCIEN         |   \
                                             USART_CTRL1_RDBFIEN        |   \
                                             USART_CTRL1_IDLEIEN        |   \
                                             USART_CTRL1_TEN            |   \
                                             USART_CTRL1_REN            |   \
                                             USART_CTRL1_UEN)
#define USART_CTRL2_CFG_FORBIDDEN           (USART_CTRL2_BFIEN)
#define USART_CTRL3_CFG_FORBIDDEN           (USART_CTRL3_CTSCFIEN       |   \
                                             USART_CTRL3_ERRIEN)

/* This mask includes IDLEF, ROERR, NERR, FERR, PERR bits.*/
#define USART_STS_IRNFP_Pos     USART_STS_PERR_Pos
#define USART_STS_IRNFP_Msk     (0x1FUL << USART_STS_IRNFP_Pos)

/* This mask includes ROERR, NERR, FERR, PERR bits.*/
#define USART_STS_RNFP_Pos      USART_STS_PERR_Pos
#define USART_STS_RNFP_Msk      (0xFUL << USART_STS_RNFP_Pos)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USART1 SIO driver identifier.
 */
#if (AT32_SIO_USE_USART1 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD1;
#endif

/**
 * @brief   USART2 SIO driver identifier.
 */
#if (AT32_SIO_USE_USART2 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD2;
#endif

/**
 * @brief   USART3 SIO driver identifier.
 */
#if (AT32_SIO_USE_USART3 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD3;
#endif

/**
 * @brief   UART4 SIO driver identifier.
 */
#if (AT32_SIO_USE_UART4 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD4;
#endif

/**
 * @brief   UART5 SIO driver identifier.
 */
#if (AT32_SIO_USE_UART5 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD5;
#endif

/**
 * @brief   USART6 SIO driver identifier.
 */
#if (AT32_SIO_USE_USART6 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD6;
#endif

/**
 * @brief   UART7 SIO driver identifier.
 */
#if (AT32_SIO_USE_UART7 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD7;
#endif

/**
 * @brief   UART8 SIO driver identifier.
 */
#if (AT32_SIO_USE_UART8 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD8;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   Driver default configuration.
 * @note    In this implementation it is: 38400-8-N-1.
 */
static const SIOConfig default_config = {
  .baud  = SIO_DEFAULT_BITRATE,
  .ctrl1 = USART_CTRL1_DATA8,
  .ctrl2 = USART_CTRL2_STOPBN1_BITS,
  .ctrl3 = 0U
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

__STATIC_INLINE void usart_enable_rx_irq(SIODriver *siop) {
  uint32_t ctrl1;

  ctrl1 = siop->usart->CTRL1;
  if ((siop->enabled & SIO_EV_RXNOTEMPY) != 0U) {
    ctrl1 |= USART_CTRL1_RDBFIEN;
  }
  if ((siop->enabled & SIO_EV_RXIDLE) != 0U) {
    ctrl1 |= USART_CTRL1_IDLEIEN;
  }
  siop->usart->CTRL1 = ctrl1;
}

__STATIC_INLINE void usart_enable_rx_errors_irq(SIODriver *siop) {

  siop->usart->CTRL1 |= __sio_reloc_field(siop->enabled, SIO_EV_PARITY_ERR, SIO_EV_PARITY_ERR_POS, USART_CTRL1_PERRIEN_Pos);
  siop->usart->CTRL2 |= __sio_reloc_field(siop->enabled, SIO_EV_RXBREAK,    SIO_EV_RXBREAK_POS,    USART_CTRL2_BFIEN_Pos);

  /* The following 3 are grouped.*/
  if ((siop->enabled & (SIO_EV_FRAMING_ERR |
                        SIO_EV_OVERRUN_ERR |
                        SIO_EV_NOISE_ERR)) != 0U) {
    siop->usart->CTRL3 |= USART_CTRL3_ERRIEN;
  }
}

__STATIC_INLINE void usart_enable_tx_irq(SIODriver *siop) {

  if ((siop->enabled & SIO_EV_TXNOTFULL) != 0U) {
    siop->usart->CTRL1 |= USART_CTRL1_TDBEIEN;
  }
}

__STATIC_INLINE void usart_enable_tx_end_irq(SIODriver *siop) {

  if ((siop->enabled & SIO_EV_TXDONE) != 0U) {
    siop->usart->CTRL1 |= USART_CTRL1_TDCIEN;
  }
}

/**
 * @brief   USART initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] siop       pointer to a @p SIODriver object
 */
__STATIC_INLINE void usart_init(SIODriver *siop) {
  USART_TypeDef *u = siop->usart;
  uint32_t baudr;

  /* Baud rate setting.*/
  baudr = (uint32_t)((siop->clock) / siop->config->baud);

  osalDbgAssert(baudr < 0x10000, "invalid BAUDR value");

  /* Setting up USART.*/
  u->CTRL1  = siop->config->ctrl1 & ~USART_CTRL1_CFG_FORBIDDEN;
  u->CTRL2  = siop->config->ctrl2 & ~USART_CTRL2_CFG_FORBIDDEN;
  u->CTRL3  = siop->config->ctrl3 & ~USART_CTRL3_CFG_FORBIDDEN;
  u->BAUDR  = baudr;

  /* Starting operations.*/
  #if !defined (AT32F435_437)
  u->IFC    = u->STS;
  #endif
  u->CTRL1 |= USART_CTRL1_UEN | USART_CTRL1_TEN | USART_CTRL1_REN;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SIO driver initialization.
 *
 * @notapi
 */
void sio_lld_init(void) {

  /* Driver instances initialization.*/
#if AT32_SIO_USE_USART1 == TRUE
  sioObjectInit(&SIOD1);
  SIOD1.usart = USART1;
  SIOD1.clock = AT32_PCLK2;
#endif
#if AT32_SIO_USE_USART2 == TRUE
  sioObjectInit(&SIOD2);
  SIOD2.usart = USART2;
  SIOD2.clock = AT32_PCLK1;
#endif
#if AT32_SIO_USE_USART3 == TRUE
  sioObjectInit(&SIOD3);
  SIOD3.usart = USART3;
  SIOD3.clock = AT32_PCLK1;
#endif
#if AT32_SIO_USE_UART4 == TRUE
  sioObjectInit(&SIOD4);
  SIOD4.usart = UART4;
  SIOD4.clock = AT32_PCLK1;
#endif
#if AT32_SIO_USE_UART5 == TRUE
  sioObjectInit(&SIOD5);
  SIOD5.usart = UART5;
  SIOD5.clock = AT32_PCLK1;
#endif
#if AT32_SIO_USE_USART6 == TRUE
  sioObjectInit(&SIOD6);
  SIOD6.usart = USART6;
  SIOD6.clock = AT32_PCLK2;
#endif
#if AT32_SIO_USE_UART7 == TRUE
  sioObjectInit(&SIOD7);
  SIOD7.usart = UART7;
  SIOD7.clock = AT32_PCLK1;
#endif
#if AT32_SIO_USE_UART8 == TRUE
  sioObjectInit(&SIOD8);
  SIOD8.usart = UART8;
  SIOD8.clock = AT32_PCLK1;
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

  /* Using the default configuration if the application passed a
     NULL pointer.*/
  if (siop->config == NULL) {
    siop->config = &default_config;
  }

  if (siop->state == SIO_STOP) {

  /* Enables the peripheral.*/
    if (false) {
    }
#if AT32_SIO_USE_USART1 == TRUE
    else if (&SIOD1 == siop) {
      crmResetUSART1();
      crmEnableUSART1(true);
    }
#endif
#if AT32_SIO_USE_USART2 == TRUE
    else if (&SIOD2 == siop) {
      crmResetUSART2();
      crmEnableUSART2(true);
    }
#endif
#if AT32_SIO_USE_USART3 == TRUE
    else if (&SIOD3 == siop) {
      crmResetUSART3();
      crmEnableUSART3(true);
    }
#endif
#if AT32_SIO_USE_UART4 == TRUE
    else if (&SIOD4 == siop) {
      crmResetUART4();
      crmEnableUART4(true);
    }
#endif
#if AT32_SIO_USE_UART5 == TRUE
    else if (&SIOD5 == siop) {
      crmResetUART5();
      crmEnableUART5(true);
    }
#endif
#if AT32_SIO_USE_USART6 == TRUE
    else if (&SIOD6 == siop) {
      crmResetUSART6();
      crmEnableUSART6(true);
    }
#endif
#if AT32_SIO_USE_UART7 == TRUE
    else if (&SIOD7 == siop) {
      crmResetUART7();
      crmEnableUART7(true);
    }
#endif
#if AT32_SIO_USE_UART8 == TRUE
    else if (&SIOD8 == siop) {
      crmResetUART8();
      crmEnableUART8(true);
    }
#endif
    else {
      osalDbgAssert(false, "invalid SIO instance");
    }
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
    if (false) {
    }
#if AT32_SIO_USE_USART1 == TRUE
    else if (&SIOD1 == siop) {
      crmResetUSART1();
      crmDisableUSART1();
    }
#endif
#if AT32_SIO_USE_USART2 == TRUE
    else if (&SIOD2 == siop) {
      crmResetUSART2();
      crmDisableUSART2();
    }
#endif
#if AT32_SIO_USE_USART3 == TRUE
    else if (&SIOD3 == siop) {
      crmResetUSART3();
      crmDisableUSART3();
    }
#endif
#if AT32_SIO_USE_UART4 == TRUE
    else if (&SIOD4 == siop) {
      crmResetUART4();
      crmDisableUART4();
    }
#endif
#if AT32_SIO_USE_UART5 == TRUE
    else if (&SIOD5 == siop) {
      crmResetUART5();
      crmDisableUART5();
    }
#endif
#if AT32_SIO_USE_USART6 == TRUE
    else if (&SIOD6 == siop) {
      crmResetUSART6();
      crmDisableUSART6();
    }
#endif
#if AT32_SIO_USE_UART7 == TRUE
    else if (&SIOD7 == siop) {
      crmResetUART7();
      crmDisableUART7();
    }
#endif
#if AT32_SIO_USE_UART8 == TRUE
    else if (&SIOD8 == siop) {
      crmResetUART8();
      crmDisableUART8();
    }
#endif
    else {
      osalDbgAssert(false, "invalid SIO instance");
    }
  }
}

/**
 * @brief   Enable flags change notification.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 */
void sio_lld_update_enable_flags(SIODriver *siop) {
  uint32_t ctrl1, ctrl2, ctrl3;

  ctrl1 = siop->usart->CTRL1 & ~(USART_CTRL1_TDBEIEN | USART_CTRL1_RDBFIEN |
                                 USART_CTRL1_IDLEIEN | USART_CTRL1_TDCIEN  |
                                 USART_CTRL1_PERRIEN);
  ctrl2 = siop->usart->CTRL2 & ~(USART_CTRL2_BFIEN);
  ctrl3 = siop->usart->CTRL3 & ~(USART_CTRL3_ERRIEN);

  ctrl1 |= __sio_reloc_field(siop->enabled, SIO_EV_RXNOTEMPY,  SIO_EV_RXNOTEMPY_POS,  USART_CTRL1_RDBFIEN_Pos) |
           __sio_reloc_field(siop->enabled, SIO_EV_TXNOTFULL,  SIO_EV_TXNOTFULL_POS,  USART_CTRL1_TDBEIEN_Pos) |
           __sio_reloc_field(siop->enabled, SIO_EV_RXIDLE,     SIO_EV_RXIDLE_POS,     USART_CTRL1_IDLEIEN_Pos) |
           __sio_reloc_field(siop->enabled, SIO_EV_TXDONE,     SIO_EV_TXDONE_POS,     USART_CTRL1_TDCIEN_Pos)  |
           __sio_reloc_field(siop->enabled, SIO_EV_PARITY_ERR, SIO_EV_PARITY_ERR_POS, USART_CTRL1_PERRIEN_Pos);
  ctrl2 |= __sio_reloc_field(siop->enabled, SIO_EV_RXBREAK,    SIO_EV_RXBREAK_POS,    USART_CTRL2_BFIEN_Pos);

  /* The following 3 are grouped.*/
  if ((siop->enabled & (SIO_EV_FRAMING_ERR |
                        SIO_EV_OVERRUN_ERR |
                        SIO_EV_NOISE_ERR)) != 0U) {
    ctrl3 |= USART_CTRL3_ERRIEN;
  }

  /* Setting up the operation.*/
  siop->usart->CTRL1 = ctrl1;
  siop->usart->CTRL2 = ctrl2;
  siop->usart->CTRL3 = ctrl3;
}

/**
 * @brief   Get and clears SIO error event flags.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The pending event flags.
 *
 * @notapi
 */
sioevents_t sio_lld_get_and_clear_errors(SIODriver *siop) {
  uint32_t sts;
  sioevents_t errors;

  /* Getting all error STS flags (and only those).
     NOTE: Do not trust the position of other bits in STS/IFC because
           some scientist decided to use different positions for some
           of them.*/
  sts = siop->usart->STS & SIO_LLD_ISR_RX_ERRORS;
#if !defined (AT32F435_437)
  /* Clearing captured events.*/
  siop->usart->IFC = sts;
#endif
  /* Status flags cleared, now the error-related interrupts can be
     enabled again.*/
  usart_enable_rx_errors_irq(siop);

  /* Translating the status flags in SIO events.*/
  errors = __sio_reloc_field(sts, USART_STS_RNFP_Msk, USART_STS_RNFP_Pos, SIO_EV_ALL_ERRORS_POS) |
           __sio_reloc_field(sts, USART_STS_BFF_Msk,  USART_STS_BFF_Pos,  SIO_EV_RXBREAK_POS);

  return errors;
}

/**
 * @brief   Get and clears SIO event flags.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The pending event flags.
 *
 * @notapi
 */
sioevents_t sio_lld_get_and_clear_events(SIODriver *siop) {
  uint32_t sts;
  sioevents_t events;

  /* Getting all STS flags.
     NOTE: Do not trust the position of other bits in STS/IFC because
           some scientist decided to use different positions for some
           of them.*/
  sts = siop->usart->STS & (SIO_LLD_ISR_RX_ERRORS |
                            USART_STS_RDBF        |
                            USART_STS_IDLEF       |
                            USART_STS_TDBE        |
                            USART_STS_TDC);
#if !defined (AT32F435_437)
  /* Clearing captured events.*/
  siop->usart->IFC = sts;
#endif

  /* Status flags cleared, now the RX-related interrupts can be
     enabled again.*/
  usart_enable_rx_irq(siop);
  usart_enable_rx_errors_irq(siop);

  /* Translating the status flags in SIO events.*/
  events = __sio_reloc_field(sts, USART_STS_RDBF_Msk,  USART_STS_RDBF_Pos,  SIO_EV_RXNOTEMPY_POS)  |
           __sio_reloc_field(sts, USART_STS_TDBE_Msk,  USART_STS_TDBE_Pos,  SIO_EV_TXNOTFULL_POS)  |
           __sio_reloc_field(sts, USART_STS_TDC_Msk,   USART_STS_TDC_Pos,   SIO_EV_TXDONE_POS)     |
           __sio_reloc_field(sts, USART_STS_IRNFP_Msk, USART_STS_IRNFP_Pos, SIO_EV_ALL_ERRORS_POS) |
           __sio_reloc_field(sts, USART_STS_BFF_Msk,   USART_STS_BFF_Pos,   SIO_EV_RXBREAK_POS);

  return events;
}

/**
 * @brief   Returns the pending SIO event flags.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The pending event flags.
 *
 * @notapi
 */
sioevents_t sio_lld_get_events(SIODriver *siop) {
  uint32_t sts;
  sioevents_t events;

  /* Getting all STS flags.*/
  sts = siop->usart->STS & (SIO_LLD_ISR_RX_ERRORS |
                            USART_STS_RDBF        |
                            USART_STS_IDLEF       |
                            USART_STS_TDBE        |
                            USART_STS_TDC);

  /* Translating the status flags in SIO events.*/
  events = __sio_reloc_field(sts, USART_STS_RDBF_Msk,  USART_STS_RDBF_Pos,  SIO_EV_RXNOTEMPY_POS)  |
           __sio_reloc_field(sts, USART_STS_TDBE_Msk,  USART_STS_TDBE_Pos,  SIO_EV_TXNOTFULL_POS)  |
           __sio_reloc_field(sts, USART_STS_TDC_Msk,   USART_STS_TDC_Pos,   SIO_EV_TXDONE_POS)     |
           __sio_reloc_field(sts, USART_STS_IRNFP_Msk, USART_STS_IRNFP_Pos, SIO_EV_ALL_ERRORS_POS) |
           __sio_reloc_field(sts, USART_STS_BFF_Msk,   USART_STS_BFF_Pos,   SIO_EV_RXBREAK_POS);

  return events;
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
 * @retval 0                if the RX FIFO is empty.
 */
size_t sio_lld_read(SIODriver *siop, uint8_t *buffer, size_t n) {
  size_t rd;

  rd = 0U;
  while (true) {

    /* If the RX FIFO has been emptied then the RX FIFO and IDLE interrupts
       are enabled again.*/
    if (sio_lld_is_rx_empty(siop)) {
      usart_enable_rx_irq(siop);
      break;
    }

    /* Buffer filled condition.*/
    if (rd >= n) {
      break;
    }

    *buffer++ = (uint8_t)siop->usart->DT;
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

    siop->usart->DT = (uint32_t)*buffer++;
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

  msg = (msg_t)siop->usart->DT;

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

  siop->usart->DT = data;

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

/**
 * @brief   Serves an USART interrupt.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 *
 * @notapi
 */
void sio_lld_serve_interrupt(SIODriver *siop) {
  USART_TypeDef *u = siop->usart;
  uint32_t ctrl1, ctrl2, ctrl3, sts, stsmask;

  osalDbgAssert(siop->state == SIO_READY, "invalid state");

  /* Read on control registers.*/
  ctrl1 = u->CTRL1;
  ctrl2 = u->CTRL2;
  ctrl3 = u->CTRL3;

  /* Calculating the mask of status bits that should be processed according
     to the state of the various CRx registers.*/
  stsmask = __sio_reloc_field(ctrl1, USART_CTRL1_TDBEIEN, USART_CTRL1_TDBEIEN_Pos, USART_STS_TDBE_Pos)  |
            __sio_reloc_field(ctrl1, USART_CTRL1_RDBFIEN, USART_CTRL1_RDBFIEN_Pos, USART_STS_RDBF_Pos)  |
            __sio_reloc_field(ctrl1, USART_CTRL1_IDLEIEN, USART_CTRL1_IDLEIEN_Pos, USART_STS_IDLEF_Pos) |
            __sio_reloc_field(ctrl1, USART_CTRL1_TDCIEN,  USART_CTRL1_TDCIEN_Pos,  USART_STS_TDC_Pos)   |
            __sio_reloc_field(ctrl1, USART_CTRL1_PERRIEN, USART_CTRL1_PERRIEN_Pos, USART_STS_PERR_Pos)  |
            __sio_reloc_field(ctrl2, USART_CTRL2_BFIEN,   USART_CTRL2_BFIEN_Pos,   USART_STS_BFF_Pos);
  if ((ctrl3 & USART_CTRL3_ERRIEN) != 0U) {
    stsmask |= USART_STS_NERR | USART_STS_FERR | USART_STS_ROERR;
  }

  /* Status flags to be processed.*/
  sts = u->STS & stsmask;
  if (sts != 0U) {

    /* Error flags handled as a group.*/
    if ((sts & SIO_LLD_ISR_RX_ERRORS) != 0U) {
      /* All RX-related interrupt sources disabled.*/
      ctrl1 &= ~(USART_CTRL1_PERRIEN | USART_CTRL1_RDBFIEN | USART_CTRL1_IDLEIEN);
      ctrl2 &= ~(USART_CTRL2_BFIEN);
      ctrl3 &= ~(USART_CTRL3_ERRIEN);

      /* Waiting thread woken, if any.*/
      __sio_wakeup_errors(siop);
    }
    /* If there are no errors then we check for the other RX-related
       status flags.*/
    else {
      /* Idle RX flag. Note: At start the USART will produce an IDLEF interrupt.*/
      if ((sts & USART_STS_IDLEF) != 0U) {

        /* Interrupt source disabled.*/
        ctrl1 &= ~USART_CTRL1_IDLEIEN;

        /* Waiting thread woken, if any.*/
        __sio_wakeup_rxidle(siop);
      }

      /* RX FIFO is non-empty.*/
      if ((sts & USART_STS_RDBF) != 0U) {

        /* Interrupt source disabled.*/
        ctrl1 &= ~USART_CTRL1_RDBFIEN;

        /* Waiting thread woken, if any.*/
        __sio_wakeup_rx(siop);
      }
    }

    /* TX FIFO is non-full.*/
    if ((sts & USART_STS_TDBE) != 0U) {

      /* Interrupt source disabled.*/
      ctrl1 &= ~USART_CTRL1_TDBEIEN;

      /* Waiting thread woken, if any.*/
      __sio_wakeup_tx(siop);
    }

    /* Physical transmission end.*/
    if ((sts & USART_STS_TDC) != 0U) {

      /* Interrupt source disabled.*/
      ctrl1 &= ~USART_CTRL1_TDCIEN;

      /* Waiting thread woken, if any.*/
      __sio_wakeup_txend(siop);
    }

    /* Updating control registers, some sources could have been disabled.*/
    u->CTRL1 = ctrl1;
    u->CTRL2 = ctrl2;
    u->CTRL3 = ctrl3;

    /* The callback is invoked.*/
    __sio_callback(siop);
  }
  else {
    osalDbgAssert(false, "spurious interrupt");
  }
}

#endif /* HAL_USE_SIO == TRUE */

/** @} */

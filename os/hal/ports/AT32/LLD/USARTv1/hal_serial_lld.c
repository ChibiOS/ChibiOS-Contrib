/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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
 * @file    USARTv1/hal_serial_lld.c
 * @brief   AT32 low level serial driver code.
 *
 * @addtogroup SERIAL
 * @{
 */

#include "hal.h"

#if HAL_USE_SERIAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief USART1 serial driver identifier.*/
#if AT32_SERIAL_USE_USART1 || defined(__DOXYGEN__)
SerialDriver SD1;
#endif

/** @brief USART2 serial driver identifier.*/
#if AT32_SERIAL_USE_USART2 || defined(__DOXYGEN__)
SerialDriver SD2;
#endif

/** @brief USART3 serial driver identifier.*/
#if AT32_SERIAL_USE_USART3 || defined(__DOXYGEN__)
SerialDriver SD3;
#endif

/** @brief UART4 serial driver identifier.*/
#if AT32_SERIAL_USE_UART4 || defined(__DOXYGEN__)
SerialDriver SD4;
#endif

/** @brief UART5 serial driver identifier.*/
#if AT32_SERIAL_USE_UART5 || defined(__DOXYGEN__)
SerialDriver SD5;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/** @brief Driver default configuration.*/
static const SerialConfig default_config =
{
  SERIAL_DEFAULT_BITRATE,
  0,
  USART_CTRL2_STOPBN1_BITS,
  0
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   USART initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] config    the architecture-dependent serial driver configuration
 */
static void usart_init(SerialDriver *sdp, const SerialConfig *config) {
  uint32_t baudr;
  USART_TypeDef *u = sdp->usart;

  baudr = (uint32_t)((sdp->clock + config->speed/2) / config->speed);

#if defined(USART_CTRL1_OVER8)
  /* Correcting BAUDR value when oversampling by 8 instead of 16.
     Fraction is still 4 bits wide, but only lower 3 bits used.
     Mantissa is doubled, but Fraction is left the same.*/
  if (config->ctrl1 & USART_CTRL1_OVER8)
    baudr = ((baudr & ~7) * 2) | (baudr & 7);
#endif

  osalDbgAssert(baudr < 0x10000, "invalid BAUDR value");

  u->BAUDR = baudr;

  /* Note that some bits are enforced.*/
  u->CTRL2 = config->ctrl2 | USART_CTRL2_BFIEN;
  u->CTRL3 = config->ctrl3 | USART_CTRL3_ERRIEN;
  u->CTRL1 = config->ctrl1 | USART_CTRL1_UEN | USART_CTRL1_PERRIEN |
                             USART_CTRL1_RDBFIEN | USART_CTRL1_TEN |
                             USART_CTRL1_REN;
  u->STS = 0;
  (void)u->STS; /* STS reset step 1.*/
  (void)u->DT;  /* DT reset step 2.*/

  /* Deciding mask to be applied on the data register on receive, this is
     required in order to mask out the parity bit.*/
  if ((config->ctrl1 & (USART_CTRL1_DBN | USART_CTRL1_PEN)) == USART_CTRL1_PEN) {
    sdp->rxmask = 0x7F;
  }
  else {
    sdp->rxmask = 0xFF;
  }
}

/**
 * @brief   USART de-initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] u         pointer to an USART I/O block
 */
static void usart_deinit(USART_TypeDef *u) {

  u->CTRL1 = 0;
  u->CTRL2 = 0;
  u->CTRL3 = 0;
}

/**
 * @brief   Error handling routine.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] sts       USART STS register value
 */
static void set_error(SerialDriver *sdp, uint16_t sts) {
  eventflags_t status = 0;

  if (sts & USART_STS_ROERR)
    status |= SD_OVERRUN_ERROR;
  if (sts & USART_STS_PERR)
    status |= SD_PARITY_ERROR;
  if (sts & USART_STS_FERR)
    status |= SD_FRAMING_ERROR;
  if (sts & USART_STS_NERR)
    status |= SD_NOISE_ERROR;
  chnAddFlagsI(sdp, status);
}

#if AT32_SERIAL_USE_USART1 || defined(__DOXYGEN__)
static void notify1(io_queue_t *qp) {

  (void)qp;
  USART1->CTRL1 |= USART_CTRL1_TDBEIEN | USART_CTRL1_TDCIEN;
}
#endif

#if AT32_SERIAL_USE_USART2 || defined(__DOXYGEN__)
static void notify2(io_queue_t *qp) {

  (void)qp;
  USART2->CTRL1 |= USART_CTRL1_TDBEIEN | USART_CTRL1_TDCIEN;
}
#endif

#if AT32_SERIAL_USE_USART3 || defined(__DOXYGEN__)
static void notify3(io_queue_t *qp) {

  (void)qp;
  USART3->CTRL1 |= USART_CTRL1_TDBEIEN | USART_CTRL1_TDCIEN;
}
#endif

#if AT32_SERIAL_USE_UART4 || defined(__DOXYGEN__)
static void notify4(io_queue_t *qp) {

  (void)qp;
  UART4->CTRL1 |= USART_CTRL1_TDBEIEN | USART_CTRL1_TDCIEN;
}
#endif

#if AT32_SERIAL_USE_UART5 || defined(__DOXYGEN__)
static void notify5(io_queue_t *qp) {

  (void)qp;
  UART5->CTRL1 |= USART_CTRL1_TDBEIEN | USART_CTRL1_TDCIEN;
}
#endif

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if AT32_SERIAL_USE_USART1 || defined(__DOXYGEN__)
#if !defined(AT32_USART1_SUPPRESS_ISR)
#if !defined(AT32_USART1_HANDLER)
#error "AT32_USART1_HANDLER not defined"
#endif
/**
 * @brief   USART1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_USART1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD1);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

#if AT32_SERIAL_USE_USART2 || defined(__DOXYGEN__)
#if !defined(AT32_USART2_SUPPRESS_ISR)
#if !defined(AT32_USART2_HANDLER)
#error "AT32_USART2_HANDLER not defined"
#endif
/**
 * @brief   USART2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_USART2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD2);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

#if AT32_SERIAL_USE_USART3 || defined(__DOXYGEN__)
#if !defined(AT32_USART3_SUPPRESS_ISR)
#if !defined(AT32_USART3_HANDLER)
#error "AT32_USART3_HANDLER not defined"
#endif
/**
 * @brief   USART3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_USART3_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD3);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

#if AT32_SERIAL_USE_UART4 || defined(__DOXYGEN__)
#if !defined(AT32_UART4_SUPPRESS_ISR)
#if !defined(AT32_UART4_HANDLER)
#error "AT32_UART4_HANDLER not defined"
#endif
/**
 * @brief   UART4 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_UART4_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD4);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

#if AT32_SERIAL_USE_UART5 || defined(__DOXYGEN__)
#if !defined(AT32_UART5_SUPPRESS_ISR)
#if !defined(AT32_UART5_HANDLER)
#error "AT32_UART5_HANDLER not defined"
#endif
/**
 * @brief   UART5 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_UART5_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD5);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level serial driver initialization.
 *
 * @notapi
 */
void sd_lld_init(void) {

#if AT32_SERIAL_USE_USART1
  sdObjectInit(&SD1, NULL, notify1);
  SD1.usart = USART1;
  SD1.clock = AT32_PCLK2;
#if !defined(AT32_USART1_SUPPRESS_ISR) && defined(AT32_USART1_NUMBER)
  nvicEnableVector(AT32_USART1_NUMBER, AT32_SERIAL_USART1_PRIORITY);
#endif
#endif

#if AT32_SERIAL_USE_USART2
  sdObjectInit(&SD2, NULL, notify2);
  SD2.usart = USART2;
  SD2.clock = AT32_PCLK1;
#if !defined(AT32_USART2_SUPPRESS_ISR) && defined(AT32_USART2_NUMBER)
  nvicEnableVector(AT32_USART2_NUMBER, AT32_SERIAL_USART2_PRIORITY);
#endif
#endif

#if AT32_SERIAL_USE_USART3
  sdObjectInit(&SD3, NULL, notify3);
  SD3.usart = USART3;
  SD3.clock = AT32_PCLK1;
#if !defined(AT32_USART3_SUPPRESS_ISR) && defined(AT32_USART3_NUMBER)
  nvicEnableVector(AT32_USART3_NUMBER, AT32_SERIAL_USART3_PRIORITY);
#endif
#endif

#if AT32_SERIAL_USE_UART4
  sdObjectInit(&SD4, NULL, notify4);
  SD4.usart = UART4;
  SD4.clock = AT32_PCLK1;
#if !defined(AT32_UART4_SUPPRESS_ISR) && defined(AT32_UART4_NUMBER)
  nvicEnableVector(AT32_UART4_NUMBER, AT32_SERIAL_UART4_PRIORITY);
#endif
#endif

#if AT32_SERIAL_USE_UART5
  sdObjectInit(&SD5, NULL, notify5);
  SD5.usart = UART5;
  SD5.clock = AT32_PCLK1;
#if !defined(AT32_UART5_SUPPRESS_ISR) && defined(AT32_UART5_NUMBER)
  nvicEnableVector(AT32_UART5_NUMBER, AT32_SERIAL_UART5_PRIORITY);
#endif
#endif
}

/**
 * @brief   Low level serial driver configuration and (re)start.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] config    the architecture-dependent serial driver configuration.
 *                      If this parameter is set to @p NULL then a default
 *                      configuration is used.
 *
 * @notapi
 */
void sd_lld_start(SerialDriver *sdp, const SerialConfig *config) {

  if (config == NULL)
    config = &default_config;

  if (sdp->state == SD_STOP) {
#if AT32_SERIAL_USE_USART1
    if (&SD1 == sdp) {
      crmEnableUSART1(true);
    }
#endif
#if AT32_SERIAL_USE_USART2
    if (&SD2 == sdp) {
      crmEnableUSART2(true);
    }
#endif
#if AT32_SERIAL_USE_USART3
    if (&SD3 == sdp) {
      crmEnableUSART3(true);
    }
#endif
#if AT32_SERIAL_USE_UART4
    if (&SD4 == sdp) {
      crmEnableUART4(true);
    }
#endif
#if AT32_SERIAL_USE_UART5
    if (&SD5 == sdp) {
      crmEnableUART5(true);
    }
#endif
  }
  usart_init(sdp, config);
}

/**
 * @brief   Low level serial driver stop.
 * @details De-initializes the USART, stops the associated clock, resets the
 *          interrupt vector.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 *
 * @notapi
 */
void sd_lld_stop(SerialDriver *sdp) {

  if (sdp->state == SD_READY) {
    usart_deinit(sdp->usart);
#if AT32_SERIAL_USE_USART1
    if (&SD1 == sdp) {
      crmDisableUSART1();
      return;
    }
#endif
#if AT32_SERIAL_USE_USART2
    if (&SD2 == sdp) {
      crmDisableUSART2();
      return;
    }
#endif
#if AT32_SERIAL_USE_USART3
    if (&SD3 == sdp) {
      crmDisableUSART3();
      return;
    }
#endif
#if AT32_SERIAL_USE_UART4
    if (&SD4 == sdp) {
      crmDisableUART4();
      return;
    }
#endif
#if AT32_SERIAL_USE_UART5
    if (&SD5 == sdp) {
      crmDisableUART5();
      return;
    }
#endif
  }
}

/**
 * @brief   Common IRQ handler.
 *
 * @param[in] sdp       communication channel associated to the USART
 */
void sd_lld_serve_interrupt(SerialDriver *sdp) {
  USART_TypeDef *u = sdp->usart;
  uint16_t ctrl1 = u->CTRL1;
  uint16_t sts = u->STS;

  /* Special case, LIN break detection.*/
  if (sts & USART_STS_BFF) {
    osalSysLockFromISR();
    chnAddFlagsI(sdp, SD_BREAK_DETECTED);
    u->STS = ~USART_STS_BFF;
    osalSysUnlockFromISR();
  }

  /* Data available.*/
  osalSysLockFromISR();
  while (sts & (USART_STS_RDBF | USART_STS_ROERR | USART_STS_NERR | USART_STS_FERR |
                USART_STS_PERR)) {
    uint8_t b;

    /* Error condition detection.*/
    if (sts & (USART_STS_ROERR | USART_STS_NERR | USART_STS_FERR | USART_STS_PERR))
      set_error(sdp, sts);
    b = (uint8_t)u->DT & sdp->rxmask;
    if (sts & USART_STS_RDBF)
      sdIncomingDataI(sdp, b);
    sts = u->STS;
  }
  osalSysUnlockFromISR();

  /* Transmission buffer empty.*/
  if ((ctrl1 & USART_CTRL1_TDBEIEN) && (sts & USART_STS_TDBE)) {
    msg_t b;
    osalSysLockFromISR();
    b = oqGetI(&sdp->oqueue);
    if (b < MSG_OK) {
      chnAddFlagsI(sdp, CHN_OUTPUT_EMPTY);
      u->CTRL1 = ctrl1 & ~USART_CTRL1_TDBEIEN;
    }
    else
      u->DT = b;
    osalSysUnlockFromISR();
  }

  /* Physical transmission end.*/
  if ((ctrl1 & USART_CTRL1_TDCIEN) && (sts & USART_STS_TDC)) {
    osalSysLockFromISR();
    if (oqIsEmptyI(&sdp->oqueue)) {
      chnAddFlagsI(sdp, CHN_TRANSMISSION_END);
      u->CTRL1 = ctrl1 & ~USART_CTRL1_TDCIEN;
    }
    osalSysUnlockFromISR();
  }
}

#endif /* HAL_USE_SERIAL */

/** @} */

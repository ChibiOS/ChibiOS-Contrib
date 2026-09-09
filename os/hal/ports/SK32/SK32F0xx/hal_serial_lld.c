/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_serial_lld.c
 * @brief   SK32F0xx low level serial driver code.
 * @details The SK32F0xx USART is a legacy SR/DR style unit (USARTv1 class).
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
#if SK32_SERIAL_USE_USART1 || defined(__DOXYGEN__)
SerialDriver SD1;
#endif

/** @brief USART2 serial driver identifier.*/
#if SK32_SERIAL_USE_USART2 || defined(__DOXYGEN__)
SerialDriver SD2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/** @brief Driver default configuration.*/
static const SerialConfig default_config =
{
  SERIAL_DEFAULT_BITRATE,
  0,
  USART_CR2_STOP1_BITS,
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
  uint32_t brr;
  USART_TypeDef *u = sdp->usart;

  brr = (uint32_t)((sdp->clock + config->speed/2) / config->speed);

#if defined(USART_CR1_OVER8)
  /* Correcting BRR value when oversampling by 8 instead of 16.
     Fraction is still 4 bits wide, but only lower 3 bits used.
     Mantissa is doubled, but Fraction is left the same.*/
  if (config->cr1 & USART_CR1_OVER8)
    brr = ((brr & ~7) * 2) | (brr & 7);
#endif

  osalDbgAssert(brr < 0x10000, "invalid BRR value");

  u->BRR = brr;

  /* Note that some bits are enforced.*/
  u->CR2 = config->cr2 | USART_CR2_LBDIE;
  u->CR3 = config->cr3 | USART_CR3_EIE;
  u->CR1 = config->cr1 | USART_CR1_UE | USART_CR1_PEIE |
                         USART_CR1_RXNEIE | USART_CR1_TE |
                         USART_CR1_RE;
  u->SR = 0;
  (void)u->SR;  /* SR reset step 1.*/
  (void)u->DR;  /* SR reset step 2.*/

  /* Deciding mask to be applied on the data register on receive, this is
     required in order to mask out the parity bit.*/
  if ((config->cr1 & (USART_CR1_M | USART_CR1_PCE)) == USART_CR1_PCE) {
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

  u->CR1 = 0;
  u->CR2 = 0;
  u->CR3 = 0;
}

/**
 * @brief   Error handling routine.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] sr        USART SR register value
 */
static void set_error(SerialDriver *sdp, uint16_t sr) {
  eventflags_t sts = 0;

  if (sr & USART_SR_ORE)
    sts |= SD_OVERRUN_ERROR;
  if (sr & USART_SR_PE)
    sts |= SD_PARITY_ERROR;
  if (sr & USART_SR_FE)
    sts |= SD_FRAMING_ERROR;
  if (sr & USART_SR_NE)
    sts |= SD_NOISE_ERROR;
  chnAddFlagsI(sdp, sts);
}

#if SK32_SERIAL_USE_USART1 || defined(__DOXYGEN__)
static void notify1(io_queue_t *qp) {

  (void)qp;
  USART1->CR1 |= USART_CR1_TXEIE | USART_CR1_TCIE;
}
#endif

#if SK32_SERIAL_USE_USART2 || defined(__DOXYGEN__)
static void notify2(io_queue_t *qp) {

  (void)qp;
  USART2->CR1 |= USART_CR1_TXEIE | USART_CR1_TCIE;
}
#endif

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SK32_SERIAL_USE_USART1 || defined(__DOXYGEN__)
#if !defined(SK32_USART1_SUPPRESS_ISR)
#if !defined(SK32_USART1_HANDLER)
#error "SK32_USART1_HANDLER not defined"
#endif
/**
 * @brief   USART1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_USART1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD1);

  OSAL_IRQ_EPILOGUE();
}
#endif
#endif

#if SK32_SERIAL_USE_USART2 || defined(__DOXYGEN__)
#if !defined(SK32_USART2_SUPPRESS_ISR)
#if !defined(SK32_USART2_HANDLER)
#error "SK32_USART2_HANDLER not defined"
#endif
/**
 * @brief   USART2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_USART2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  sd_lld_serve_interrupt(&SD2);

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

#if SK32_SERIAL_USE_USART1
  sdObjectInit(&SD1, NULL, notify1);
  SD1.usart = USART1;
  SD1.clock = SK32_PCLK2;
#if !defined(SK32_USART1_SUPPRESS_ISR) && defined(SK32_USART1_NUMBER)
  nvicEnableVector(SK32_USART1_NUMBER, SK32_SERIAL_USART1_PRIORITY);
#endif
#endif

#if SK32_SERIAL_USE_USART2
  sdObjectInit(&SD2, NULL, notify2);
  SD2.usart = USART2;
  SD2.clock = SK32_PCLK1;
#if !defined(SK32_USART2_SUPPRESS_ISR) && defined(SK32_USART2_NUMBER)
  nvicEnableVector(SK32_USART2_NUMBER, SK32_SERIAL_USART2_PRIORITY);
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
#if SK32_SERIAL_USE_USART1
    if (&SD1 == sdp) {
      rccEnableUSART1(true);
    }
#endif
#if SK32_SERIAL_USE_USART2
    if (&SD2 == sdp) {
      rccEnableUSART2(true);
    }
#endif
  }
  usart_init(sdp, config);
}

/**
 * @brief   Low level serial driver stop.
 * @details De-initializes the USART, stops the associated clock.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 *
 * @notapi
 */
void sd_lld_stop(SerialDriver *sdp) {

  if (sdp->state == SD_READY) {
    usart_deinit(sdp->usart);
#if SK32_SERIAL_USE_USART1
    if (&SD1 == sdp) {
      rccDisableUSART1();
      return;
    }
#endif
#if SK32_SERIAL_USE_USART2
    if (&SD2 == sdp) {
      rccDisableUSART2();
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
  uint16_t cr1;
  uint16_t sr = u->SR;

  /* Special case, LIN break detection.*/
  if (sr & USART_SR_LBD) {
    osalSysLockFromISR();
    chnAddFlagsI(sdp, SD_BREAK_DETECTED);
    u->SR = ~USART_SR_LBD;
    osalSysUnlockFromISR();
  }

  /* Data available.*/
  osalSysLockFromISR();
  while (sr & (USART_SR_RXNE | USART_SR_ORE | USART_SR_NE | USART_SR_FE |
               USART_SR_PE)) {
    uint8_t b;

    /* Error condition detection.*/
    if (sr & (USART_SR_ORE | USART_SR_NE | USART_SR_FE  | USART_SR_PE))
      set_error(sdp, sr);
    b = (uint8_t)u->DR & sdp->rxmask;
    if (sr & USART_SR_RXNE)
      sdIncomingDataI(sdp, b);
    sr = u->SR;
  }
  osalSysUnlockFromISR();

  /* Caching CR1.*/
  cr1 = u->CR1;

  /* Transmission buffer empty.*/
  if ((cr1 & USART_CR1_TXEIE) && (sr & USART_SR_TXE)) {
    msg_t b;
    osalSysLockFromISR();
    b = oqGetI(&sdp->oqueue);
    if (b < MSG_OK) {
      chnAddFlagsI(sdp, CHN_OUTPUT_EMPTY);
      cr1 &= ~USART_CR1_TXEIE;
    }
    else
      u->DR = b;
    osalSysUnlockFromISR();
  }

  /* Physical transmission end.*/
  if ((cr1 & USART_CR1_TCIE) && (sr & USART_SR_TC)) {
    osalSysLockFromISR();
    if (oqIsEmptyI(&sdp->oqueue)) {
      chnAddFlagsI(sdp, CHN_TRANSMISSION_END);
      cr1 &= ~USART_CR1_TCIE;
    }
    osalSysUnlockFromISR();
  }

  /* Writing CR1 once.*/
  u->CR1 = cr1;
}

#endif /* HAL_USE_SERIAL */

/** @} */

/*
    ChibiOS - Copyright (C) 2016..2016 Stéphane D'Alu

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
 * @file    NRF51/hal_qei_lld.c
 * @brief   NRF51 QEI subsystem low level driver header.
 *
 * @addtogroup QEI
 * @{
 */

#include "hal.h"

#if (HAL_USE_QEI == TRUE) || defined(__DOXYGEN__)


/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Common IRQ handler.
 *
 * @param[in] qeip         pointer to an QEIDriver
 */
static void serve_interrupt(QEIDriver *qeip) {
  NRF_QDEC_Type *qdec = qeip->qdec;

  /* Accumulator overflowed
   */
  if (qdec->EVENTS_ACCOF) {
      qdec->EVENTS_ACCOF = 0;

      qeip->overflowed++;
      if (qeip->config->overflowed_cb)
	  qeip->config->overflowed_cb(qeip);
  }

  /* Report ready
   */
  if (qdec->EVENTS_REPORTRDY) {
      qdec->EVENTS_REPORTRDY = 0;

      // Read and clear counters (due to shortcut)
      int16_t  acc    = ( int16_t)qdec->ACCREAD;
      uint16_t accdbl = (uint16_t)qdec->ACCDBLREAD;

      // Inverse direction if requested
      if (qeip->config->dirinv)
	  acc = -acc; // acc is [-1024..+1023], its okay on int16_t

      // Get boundaries
      qeicnt_t min = QEI_COUNT_MIN;
      qeicnt_t max = QEI_COUNT_MAX;
      if (qeip->config->min != qeip->config->max) {
	  min = qeip->config->min;
	  max = qeip->config->max;
      }

      // Compute new value
      qeidelta_t delta      = 0;
      qeicnt_t   count      = qeip->count + acc;
      bool       overflowed = false;
      
      // See: https://www.securecoding.cert.org/confluence/display/c/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow
      
      // Overflow
      if ((acc > 0) && (qeip->count > (max - acc))) {
	  overflowed = true;
	  switch(qeip->config->overflow) {
	  case QEI_OVERFLOW_WRAP:
	      delta = 0;
	      count = (min + (qeip->count - (max - acc))) - 1;
	      break;
	  case QEI_OVERFLOW_DISCARD:
	      delta = acc;
	      count = qeip->count;
	      break;
	  case QEI_OVERFLOW_MINMAX:
	      delta = qeip->count - (max - acc);
	      count = max;
	      break;
	  }

      // Underflow
      } else if ((acc < 0) && (qeip->count < (min - acc))) {
	  overflowed = true;
	  switch(qeip->config->overflow) {
	  case QEI_OVERFLOW_WRAP:
	      delta = 0;
	      count = (max + (qeip->count - (min - acc))) + 1;
	      break;
	  case QEI_OVERFLOW_DISCARD:
	      delta = acc;
	      count = qeip->count;
	      break;
	  case QEI_OVERFLOW_MINMAX:
	      delta = qeip->count - (min - acc);
	      count = min;
	      break;
	  }
      }

      // Set value and notify
      if (qeip->count != count) {
	  qeip->count = count;
	  if (qeip->config->notify_cb)
	      qeip->config->notify_cb(qeip);
      }

      // Notify for overflow (passing the remaining delta)
      if (overflowed && qeip->config->overflow_cb)
	  qeip->config->overflow_cb(qeip, delta);
  }
}


/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   QEID1 driver identifier.
 */
#if NRF51_QEI_USE_QDEC0 || defined(__DOXYGEN__)
QEIDriver QEID1;
#endif


/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if NRF51_QEI_USE_QDEC0 == TRUE
/**
 * @brief   Quadrature decoder vector (QDEC)
 *
 * @isr
 */
OSAL_IRQ_HANDLER(Vector88) {

  OSAL_IRQ_PROLOGUE();
  serve_interrupt(&QEID1);
  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level QEI driver initialization.
 *
 * @notapi
 */
void qei_lld_init(void) {

#if NRF51_QEI_USE_QDEC0 == TRUE
  /* Driver initialization.*/
  qeiObjectInit(&QEID1);
  QEID1.qdec = NRF_QDEC; 
#endif
}

/**
 * @brief   Configures and activates the QEI peripheral.
 *
 * @param[in] qeip      pointer to the @p QEIDriver object
 *
 * @notapi
 */
void qei_lld_start(QEIDriver *qeip) {
  NRF_QDEC_Type *qdec = qeip->qdec; 
  const QEIConfig *cfg = qeip->config;

  if (qeip->state == QEI_STOP) {
    // Set Pins
    palSetLineMode(cfg->phase_a, PAL_MODE_INPUT);
    palSetLineMode(cfg->phase_b, PAL_MODE_INPUT);
    if (cfg->led != PAL_NOLINE) {
	palSetLineMode(cfg->led, PAL_MODE_INPUT);
    }
      
    // Set interrupt masks and enable interrupt
    qdec->INTENSET = QDEC_INTENSET_REPORTRDY_Msk |
	             QDEC_INTENSET_ACCOF_Msk;
#if NRF51_QEI_USE_QDEC0 == TRUE
    if (&QEID1 == qeip) {
      nvicEnableVector(QDEC_IRQn, NRF51_QEI_QDEC0_IRQ_PRIORITY);
    }
#endif

    // Select pin for Phase A and Phase B
    qdec->PSELA      = PAL_PAD(cfg->phase_a);
    qdec->PSELB      = PAL_PAD(cfg->phase_b);

    // Select (optional) pin for LED, and configure it
    qdec->PSELLED    = PAL_PAD(cfg->led);
    qdec->LEDPOL     = ((cfg->led_polarity == QEI_LED_POLARITY_LOW)
                         ? QDEC_LEDPOL_LEDPOL_ActiveLow 
		         : QDEC_LEDPOL_LEDPOL_ActiveHigh)
                       << QDEC_LEDPOL_LEDPOL_Pos; 
    qdec->LEDPRE     = cfg->led_warming;

    // Set sampling resolution and debouncing
    qdec->SAMPLEPER  = cfg->resolution;
    qdec->DBFEN      = (cfg->debouncing ? QDEC_DBFEN_DBFEN_Enabled
			                : QDEC_DBFEN_DBFEN_Disabled)
                       << QDEC_DBFEN_DBFEN_Pos;

    // Define minimum sampling before reporting
    // and create shortcut to clear accumulation
    qdec->REPORTPER  = cfg->report;
    qdec->SHORTS     = QDEC_SHORTS_REPORTRDY_READCLRACC_Msk;

    // Enable peripheric
    qdec->ENABLE     = 1;
  }

  // Initially state is stopped, events cleared
  qdec->TASKS_STOP       = 1;
  qdec->EVENTS_SAMPLERDY = 0;
  qdec->EVENTS_REPORTRDY = 0;
  qdec->EVENTS_ACCOF     = 0;
}

/**
 * @brief   Deactivates the QEI peripheral.
 *
 * @param[in] qeip      pointer to the @p QEIDriver object
 *
 * @notapi
 */
void qei_lld_stop(QEIDriver *qeip) {

  NRF_QDEC_Type *qdec = qeip->qdec;
  const QEIConfig *cfg = qeip->config;

  if (qeip->state == QEI_READY) {
    qdec->TASKS_STOP = 1;
    qdec->ENABLE     = 0;
#if NRF51_QEI_USE_QDEC0 == TRUE
    if (&QEID1 == qeip) {
      nvicDisableVector(QDEC_IRQn);
    }
#endif
    qdec->INTENCLR = QDEC_INTENSET_REPORTRDY_Msk |
	             QDEC_INTENSET_ACCOF_Msk;

    // Return pins to reset state
    palSetLineMode(cfg->phase_a, PAL_MODE_RESET);
    palSetLineMode(cfg->phase_b, PAL_MODE_RESET);
    if (cfg->led != PAL_NOLINE) {
	palSetLineMode(cfg->led, PAL_MODE_RESET);
    }
  }
}

/**
 * @brief   Enables the input capture.
 *
 * @param[in] qeip      pointer to the @p QEIDriver object
 *
 * @notapi
 */
void qei_lld_enable(QEIDriver *qeip) {
  qeip->overflowed = 0;

  qeip->qdec->EVENTS_SAMPLERDY = 0;
  qeip->qdec->EVENTS_REPORTRDY = 0;
  qeip->qdec->EVENTS_ACCOF = 0;
  qeip->qdec->TASKS_START = 1;
}

/**
 * @brief   Disables the input capture.
 *
 * @param[in] qeip      pointer to the @p QEIDriver object
 *
 * @notapi
 */
void qei_lld_disable(QEIDriver *qeip) {
  qeip->qdec->TASKS_STOP = 1;
}


#endif /* HAL_USE_QEI */

/** @} */

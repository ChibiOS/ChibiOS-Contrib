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
 * @file    NRF51/hal_qei_lld.h
 * @brief   NRF51 QEI subsystem low level driver header.
 *
 * @addtogroup QEI
 * @{
 */

#ifndef HAL_QEI_LLD_H
#define HAL_QEI_LLD_H

#if (HAL_USE_QEI == TRUE) || defined(__DOXYGEN__)


/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define QEI_LED_POLARITY_LOW   0
#define QEI_LED_POLARITY_HIGH  1

#define QEI_COUNT_MIN 0
#define QEI_COUNT_MAX 65535


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   QEID1 driver enable switch.
 * @details If set to @p TRUE the support for QEID1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(NRF51_QEI_USE_QDEC1) || defined(__DOXYGEN__)
#define NRF51_QEI_USE_QDEC1                 FALSE
#endif

/**
 * @brief   QEID interrupt priority level setting.
 */
#if !defined(NRF51_QEI_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define NRF51_QEI_IRQ_PRIORITY              2
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if NRF51_QEI_USE_QDEC1 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(NRF51_QEI_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to QDEC1"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/



/**
 * @brief   QEI count mode.
 */
typedef enum {
  QEI_MODE_QUADRATURE = 0,          /**< Quadrature encoder mode.           */
} qeimode_t;

/**
 * @brief   QEI resolution.
 */
typedef enum {
  QEI_RESOLUTION_128us   = 0x00UL, /**< 128us sample period. */
  QEI_RESOLUTION_256us   = 0x01UL, /**< 256us sample period. */
  QEI_RESOLUTION_512us   = 0x02UL, /**< 512us sample period. */
  QEI_RESOLUTION_1024us  = 0x03UL, /**< 1024us sample period. */
  QEI_RESOLUTION_2048us  = 0x04UL, /**< 2048us sample period. */
  QEI_RESOLUTION_4096us  = 0x05UL, /**< 4096us sample period. */
  QEI_RESOLUTION_8192us  = 0x06UL, /**< 8192us sample period. */
  QEI_RESOLUTION_16384us = 0x07UL, /**< 16384us sample period. */
} qeiresolution_t;

/**
 * @brief   Clusters of samples.
 */
typedef enum {
  QEI_REPORT_10          = 0x00UL, /**< 10 samples per report. */
  QEI_REPORT_40          = 0x01UL, /**< 40 samples per report. */
  QEI_REPORT_80          = 0x02UL, /**< 80 samples per report. */
  QEI_REPORT_120         = 0x03UL, /**< 120 samples per report. */
  QEI_REPORT_160         = 0x04UL, /**< 160 samples per report. */
  QEI_REPORT_200         = 0x05UL, /**< 200 samples per report. */
  QEI_REPORT_240         = 0x06UL, /**< 240 samples per report. */
  QEI_REPORT_280         = 0x07UL, /**< 280 samples per report. */
} qeireport_t;

/**
 * @brief   Handling of counter overflow/underflow.
 */
typedef enum {
  QEI_OVERFLOW_WRAP    = 0, /**< Counter value will wrap around.        */
  QEI_OVERFLOW_DISCARD = 1, /**< Counter doesn't change.                */
  QEI_OVERFLOW_MINMAX  = 2, /**< Counter will be updated to min or max. */
} qeioverflow_t;



/**
 * @brief   QEI direction inversion.
 */
typedef enum {
  QEI_DIRINV_FALSE = 0,             /**< Do not invert counter direction.   */
  QEI_DIRINV_TRUE = 1,              /**< Invert counter direction.          */
} qeidirinv_t;

/**
 * @brief   QEI counter type.
 */
typedef uint16_t qeicnt_t;

/**
 * @brief   QEI delta type.
 */
typedef int16_t qeidelta_t;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Count mode.
   */
  qeimode_t                 mode;
  /**
   * @brief   Resolution.
   */
  qeiresolution_t           resolution;
  /**
   * @brief   Direction inversion.
   */
  qeidirinv_t               dirinv;
  /**
   * @brief   Handling of counter overflow/underflow
   *
   * @details When overflow accours, the counter value is updated
   *          according to:
   *            - QEI_OVERFLOW_DISCARD:
   *                discard the update value, counter doesn't change
   *            - QEI_OVERFLOW_MINMAX
   *                counter will be updated to reach min or max
   *            - QEI_OVERFLOW_WRAP:
   *                counter value will wrap around
   */
  qeioverflow_t             overflow;
  /**
   * @brief   Min count value.
   * 
   * @note    If min == max, then QEI_COUNT_MIN is used.
   */
  qeicnt_t                  min;
  /**
   * @brief   Max count value.
   * 
   * @note    If min == max, then QEI_COUNT_MAX is used.
   */
  qeicnt_t                  max;
  /**
    * @brief  Notify of value change
    *
    * @note   Called from ISR context.
    */
  qeicallback_t             notify_cb;
  /**
   * @brief   Notify of overflow
   *
   * @note    Overflow notification is performed after 
   *          value changed notification.
   * @note    Called from ISR context.
   */
  void (*overflow_cb)(QEIDriver *qeip, qeidelta_t delta);
  /* End of the mandatory fields.*/
  /**
   * @brief   Line for reading Phase A
   */
  ioline_t                  phase_a;
  /**
   * @brief   Line for reading Phase B
   */
  ioline_t                  phase_b;
  /**
   * @brief   Line to use to control LED
   *
   * @note    If LED is not controlled by MCU, you need to use the 
   *          PAL_NOLINE value.
   */
  ioline_t                  led;
  /**
   * @brief   Period in µs the LED is switched on prior to sampling.
   *
   * @details LED warming is between 0 and 511 (including boundaries)
   *
   * @note    31µs is the recommanded default.
   *
   * @note    If debouncing is activated, LED is always on for the
   *          whole sampling period (aka: resolution)
   */
  uint16_t                  led_warming;
  /**
   * @brief   LED polarity to used (when LED is controlled by MCU) 
   */
  uint8_t                   led_polarity;
   /**
    * @brief  Activate debouncing filter
    *
    * @note   If LED is controlled by MCU, the led_warming is ignored and,
    *         LED is always on for the whole sampling period (aka: resolution)
    */
  bool                      debouncing;
   /**
    * @brief  Number of sample per report
    *
    * @details Default to QEI_REPORT_10
    */
  qeireport_t 		    report;
   /**
    * @brief  Notify of internal accumulator overflowed
    * 
    * @note   MCU has discarded some of the samples.
    * @note   Called from ISR context.
    */
  qeicallback_t             overflowed_cb;
} QEIConfig;

/**
 * @brief   Structure representing an QEI driver.
 */
struct QEIDriver {
  /**
   * @brief Driver state.
   */
  qeistate_t                state;
  /**
   * @brief Last count value.
   */
  qeicnt_t                  last;
  /**
   * @brief Current configuration data.
   */
  const QEIConfig           *config;
#if defined(QEI_DRIVER_EXT_FIELDS)
  QEI_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   */
  qeicnt_t                   count;
  /**
   * @brief Number of time the MCU discarded updates due to
   *        accumulator overflow
   */
  uint32_t                   overflowed;
  /**
   * @brief Pointer to the ADCx registers block.
   */
  NRF_QDEC_Type             *qdec;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the counter value.
 *
 * @param[in] qeip      pointer to the @p QEIDriver object
 * @return              The current counter value.
 *
 * @notapi
 */
#define qei_lld_get_count(qeip) ((qeip)->count)


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if NRF51_QEI_USE_QDEC1 && !defined(__DOXYGEN__)
extern QEIDriver QEID1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void qei_lld_init(void);
  void qei_lld_start(QEIDriver *qeip);
  void qei_lld_stop(QEIDriver *qeip);
  void qei_lld_enable(QEIDriver *qeip);
  void qei_lld_disable(QEIDriver *qeip);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_QEI */

#endif /* HAL_QEI_LLD_H */

/** @} */

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
 * @file    SK32F0xx/hal_kbcu_lld.h
 * @brief   SK32F0xx KBCU subsystem low level driver header.
 * @details The KBCU (Keyboard Control Unit) is a 3Think peripheral used for
 *          scanning keyboard matrixes and for driving RGB LED columns.  This
 *          driver supports the independent scan mode where the RGB scanning
 *          and the KEY scanning run at the same level and the key statuses
 *          are read on dedicated KEY inputs through the shared KSR registers.
 * @note    The RGB (LED) stream is pushed through a DMA1 channel in memory to
 *          peripheral mode targeting the @p KBCU->DMAR register, so this
 *          driver allocates DMA channels and requires @p SK32_DMA_REQUIRED
 *          (defined in hal_lld.h whenever @p HAL_USE_KBCU is enabled).
 *
 * @addtogroup KBCU
 * @{
 */

#ifndef HAL_KBCU_LLD_H
#define HAL_KBCU_LLD_H

#if (HAL_USE_KBCU == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Mask of the CR0 bits owned by this driver.
 * @details The @p EN, @p BEN, column count, key/column effective levels,
 *          column mask and column cycle value fields are managed by the
 *          driver so that unrelated bits are never overwritten.
 */
#define SK32_KBCU_CR0_OWNED_MASK        (KBCU_CR0_EN   |                    \
                                         KBCU_CR0_BEN  |                    \
                                         KBCU_CR0_CS   |                    \
                                         KBCU_CR0_KIP  |                    \
                                         KBCU_CR0_COP  |                    \
                                         KBCU_CR0_CMASK|                    \
                                         KBCU_CR0_CCR)

/**
 * @brief   Mask used to clear the managed CR1 fields before programming.
 * @note    Equal to the vendor CR1_CLEAR_Mask.
 */
#define SK32_KBCU_CR1_OWNED_MASK        0x07FFFFFFU

/**
 * @brief   Mask used to clear the managed IER fields before programming.
 * @note    Equal to the vendor IER_CLEAR_Mask.
 */
#define SK32_KBCU_IER_OWNED_MASK        KBCU_IER_FRAME | KBCU_IER_KEYIE |    \
                                        KBCU_IER_COLIE | KBCU_IER_FRAMEIE

/**
 * @brief   Number of KSR (key status) registers.
 * @details The 6 KSR registers cover 4 columns each (8 row bits per column),
 *          i.e. up to 24 columns.
 */
#define SK32_KBCU_KSRS                 6U

/**
 * @brief   DMA1 channel identifier used by the KBCU RGB (LED) burst.
 */
#define SK32_KBCU_DMA_STREAM            SK32_DMA_STREAM_ID(1, 4)

/**
 * @brief   SYSCFG CFGR3 DMA request code of the KBCU.
 * @note    The request code is a 6 bit value placed in the low 6 bits of the
 *          per-channel slot of CFGR3, see the vendor
 *          SYSCFG_DMAChannelConfig() (SYSCFG_DMARemap_KBCU = 0x2E).
 */
#define SK32_KBCU_DMA_REQ_CODE          0x2EU

/**
 * @brief   Mask of the request code bits inside a CFGR3 channel slot.
 */
#define SK32_KBCU_DMA_REQ_MASK          0x3FU

/**
 * @brief   Position of the DMA1 channel 4 request slot in CFGR3.
 * @note    The request code of a channel occupies the low 6 bits of an 8 bits
 *          wide slot located at ((channel - 1) * 8), channel 4 uses bits
 *          24..29 (the same layout used by the SLED driver).
 */
#define SK32_KBCU_DMA_SLOT_SHIFT        (((4) - 1U) * 8U)

/**
 * @brief   DMA priority of the KBCU channel.
 */
#define SK32_KBCU_DMA_PRIORITY          3U

/**
 * @brief   MCCR mode of the KBCU DMA transfers (memory to peripheral,
 *          memory pointer increment, no peripheral increment, priority).
 */
#define SK32_KBCU_DMA_MODE              (SK32_DMA_CR_DIR_M2P  |             \
                                         SK32_DMA_CR_MINC      |             \
                                         SK32_DMA_CR_PSIZE_BYTE|             \
                                         SK32_DMA_CR_MSIZE_BYTE|             \
                                         SK32_DMA_CR_PL(SK32_KBCU_DMA_PRIORITY))

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   KBCU interrupt priority level.
 * @note    May be overridden in mcuconf.h.
 */
#if !defined(SK32_IRQ_KBCU_PRIORITY) || defined(__DOXYGEN__)
#define SK32_IRQ_KBCU_PRIORITY          3
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(SK32_IRQ_KBCU_PRIORITY) && !defined(__DOXYGEN__)
#error "invalid priority level for the SK32 KBCU interrupt"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   KBCU key effective level.
 */
typedef enum {
  KBCU_KEY_LEVEL_LOW  = 0x00,        /**< @brief Key active on low.        */
  KBCU_KEY_LEVEL_HIGH = 0x01         /**< @brief Key active on high.       */
} kbcu_key_level_t;

/**
 * @brief   KBCU columns effective level.
 */
typedef enum {
  KBCU_COLUMN_LEVEL_LOW  = 0x00,     /**< @brief Columns active on low.    */
  KBCU_COLUMN_LEVEL_HIGH = 0x01      /**< @brief Columns active on high.   */
} kbcu_columns_level_t;

/**
 * @brief   KBCU dead time (debounce) setting.
 */
typedef enum {
  KBCU_DEADTIME_0 = 0x00,            /**< @brief No dead time.             */
  KBCU_DEADTIME_1 = 0x01,            /**< @brief Dead time 1.              */
  KBCU_DEADTIME_2 = 0x02,            /**< @brief Dead time 2.              */
  KBCU_DEADTIME_3 = 0x03,            /**< @brief Dead time 3.              */
  KBCU_DEADTIME_4 = 0x04,            /**< @brief Dead time 4.              */
  KBCU_DEADTIME_5 = 0x05,            /**< @brief Dead time 5.              */
  KBCU_DEADTIME_6 = 0x06,            /**< @brief Dead time 6.              */
  KBCU_DEADTIME_7 = 0x07             /**< @brief Dead time 7.              */
} kbcu_deadtime_t;

/**
 * @brief   KBCU interrupt sources.
 */
typedef enum {
  KBCU_IT_FRAME  = KBCU_IER_FRAMEIE, /**< @brief Frame interrupt enable.  */
  KBCU_IT_COLUMN = KBCU_IER_COLIE,   /**< @brief Column interrupt enable. */
  KBCU_IT_KEY    = KBCU_IER_KEYIE    /**< @brief Key interrupt enable.    */
} kbcu_it_t;

/**
 * @brief   KBCU DMA base address (word index into the register window).
 * @note    The base selects the register where a DMA burst starts to write,
 *          the value is the word offset of the register (LEDR0 = 0x0B -> byte
 *          0x2C).  These match the vendor KBCU_DMABase_* constants (the LEDR
 *          registers are the only meaningful bases for RGB output).
 */
typedef enum {
  KBCU_DMBASE_LEDR0 = 0x0BU,         /**< @brief Base: LED register 0.     */
  KBCU_DMBASE_LEDR1 = 0x0CU,         /**< @brief Base: LED register 1.     */
  KBCU_DMBASE_LEDR2 = 0x0DU,         /**< @brief Base: LED register 2.     */
  KBCU_DMBASE_LEDR3 = 0x0EU,         /**< @brief Base: LED register 3.     */
  KBCU_DMBASE_LEDR4 = 0x0FU,         /**< @brief Base: LED register 4.     */
  KBCU_DMBASE_LEDR5 = 0x10U,         /**< @brief Base: LED register 5.     */
  KBCU_DMBASE_LEDR6 = 0x11U,         /**< @brief Base: LED register 6.     */
  KBCU_DMBASE_LEDR7 = 0x12U          /**< @brief Base: LED register 7.     */
} kbcu_dmabase_t;

/**
 * @brief   KBCU key status callback.
 * @details Invoked from the KBCU ISR whenever a key status change is
 *          detected (@p KBCU_SR_KEYF set).  The pointer references the
 *          driver internal KSR snapshot which stays valid until the next
 *          interrupt.
 *
 * @param[in] ksr       pointer to the 6 KSR values snapshot
 */
typedef void (*kbcu_key_cb)(const uint32_t *ksr);

/**
 * @brief   KBCU driver configuration.
 * @details Independent scan mode only (the multiplexing S/M field is kept
 *          cleared).  The numeric fields carry logical values: the column
 *          count (15..24) and effective level/dead time selects are encoded
 *          into the CR0/CR1 fields by the driver.
 */
typedef struct {
  /**
   * @brief   Number of columns (15..24).
   */
  uint8_t                 columns_num;
  /**
   * @brief   Columns cycle value (CCR), must be between 0x00 and 0x7F.
   */
  uint8_t                 columns_cycle_value;
  /**
   * @brief   Columns cycle count (ARR), must be between 0x01 and 0xFF.
   */
  uint8_t                 columns_cycle_count;
  /**
   * @brief   Clock division factor (PSC), must be between 0x00 and 0xFF.
   */
  uint8_t                 clock_division;
  /**
   * @brief   Key effective level.
   */
  kbcu_key_level_t        key_effective_level;
  /**
   * @brief   Columns effective level.
   */
  kbcu_columns_level_t    columns_effective_level;
  /**
   * @brief   Dead time (debounce).
   */
  kbcu_deadtime_t         dead_time;
  /**
   * @brief   Flicker length (FC), must be between 0x00 and 0xFF.
   */
  uint8_t                 flicker_length;
  /**
   * @brief   Column mask (CMASK), must be between 0x00 and 0x7F.
   */
  uint8_t                 column_mask;
} KBCUConfig;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                     */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void     kbcu_lld_init(void);
  void     kbcu_lld_start(const KBCUConfig *config);
  void     kbcu_lld_stop(void);

  void     kbcu_lld_enable(void);
  void     kbcu_lld_disable(void);

  void     kbcu_lld_itconfig(kbcu_it_t it, uint8_t frame_count);
  void     kbcu_lld_set_callback(kbcu_key_cb cb);

  uint8_t  kbcu_lld_get_column(uint8_t column);
  bool     kbcu_lld_get_key(uint8_t column, uint8_t row);
  void     kbcu_lld_read_ksr(uint32_t ksr[SK32_KBCU_KSRS]);
  uint32_t kbcu_lld_get_key_flag(void);

  void     kbcu_lld_led_set(uint8_t row, uint8_t r, uint8_t g, uint8_t b,
                            uint8_t mask);
  void     kbcu_lld_dma_config(kbcu_dmabase_t base, uint16_t burst_length);
  void     kbcu_lld_led_dma_start(kbcu_dmabase_t base, uint16_t burst_length,
                                  const uint8_t *framebuf, size_t size);
  void     kbcu_lld_led_dma_stop(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_KBCU */

#endif /* HAL_KBCU_LLD_H */

/** @} */
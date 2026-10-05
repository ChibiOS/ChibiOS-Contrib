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
 * @file    SK32F0xx/hal_sled_lld.h
 * @brief   SK32F0xx serial LED (SLED) subsystem low level driver header.
 * @details The SK32F077 embeds a 3Think "serial LED" controller (SLED), a
 *          peripheral that is not present on the STM32F0xx devices.  It is
 *          designed to drive WS2812/SK6812 style addressable LEDs without
 *          CPU bit-banging: the T0H/T1H/TRST time-code fields of the TCR
 *          register program the per-bit timing and the CDR register programs
 *          the serial bit clock.  The unit provides two groups (SLED1/SLED2,
 *          DR[0]/DR[1]); each group is served by one DMA1 channel (channel 1
 *          for SLED1 and channel 2 for SLED2) routed to the SLED request
 *          line through the SYSCFG CFGR3 channel remapping, the same request
 *          routing used by the vendor SYSCFG_DMAChannelConfig() API.
 * @note    The data path follows the vendor reference implementation
 *          (SK32F077x_RGBKeyboardSTK User/Src/sled.c): the DMA performs
 *          byte wide transfers from a raw color byte stream into the @p DR
 *          register of a group, exactly like the vendor code does with
 *          @p KBCU_RGBBuff and a channel configured for byte sized
 *          memory/peripheral accesses.  Each 8-bit write pushes one color
 *          byte into the group FIFO and the SLED block serializes the byte
 *          stream on the group output pads, so a plain GRB/GRB/... byte
 *          stream drives one WS2812 string without any CPU bit packing.
 * @note    The vendor "how to use" sequence is:
 *          - enable the SLED APB2 clock,
 *          - configure the output pads in alternate function 14 (the
 *            mechanical RGB keyboard reference uses PB8 for the SLED1
 *            output, GPIO_AF_14),
 *          - program CDR (PSC/BRD), TCR (T0H/T1H/TRST) and the CR polarity
 *            bits before enabling the peripheral,
 *          - enable the DMA request line of the group (DMAEN1/DMAEN2),
 *          - enable the SLED (CR EN),
 *          - for every frame: wait for the previous reset pulse to finish,
 *            reload the DMA channel with the new byte stream, enable it and
 *            write the RSTSTRx bit: the block starts the reset code when
 *            the FIFO and the shift register have been drained.
 * @note    This low level driver does not handle the GPIO alternate function
 *          configuration: the pads (e.g. PB8 = SLED1, alternate function 14)
 *          must be routed by the application/board code before the data
 *          transfers are started.
 *
 * @addtogroup SK32F0xx_SLED
 * @{
 */

#ifndef HAL_SLED_LLD_H
#define HAL_SLED_LLD_H

#if (HAL_USE_SLED == TRUE) || defined(__DOXYGEN__)

#include "sk32_dma.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Mask of the CR bits owned by this driver.
 */
#define SK32_SLED_CR_OWNED_MASK         (SLED_CR_EN      | \
                                         SLED_CR_SYNCEN  | \
                                         SLED_CR_RSTSTS  | \
                                         SLED_CR_IDLESTS | \
                                         SLED_CR_SYNCSTS | \
                                         SLED_CR_DMAEN1  | \
                                         SLED_CR_INTEN1  | \
                                         SLED_CR_DMAEN2  | \
                                         SLED_CR_INTEN2)

/**
 * @brief   Bits identifying the SLED1 group (group index 0).
 */
#define SK32_SLED_GROUP1_MASK           SLED_CR_DMAEN1

/**
 * @brief   Bits identifying the SLED2 group (group index 1).
 */
#define SK32_SLED_GROUP2_MASK           SLED_CR_DMAEN2

/**
 * @brief   Maximum number of bytes that can be queued in one group transfer.
 * @note    The DMA CNDTR register is 16 bits wide.
 */
#define SK32_SLED_MAX_TRANSFER_BYTES    65535U

/**
 * @brief   Checks if a SLED group index is in the valid range.
 *
 * @param[in] group     the SLED group index
 * @return              The check result.
 * @retval false        invalid group.
 * @retval true         correct group.
 */
#define SK32_SLED_IS_VALID_GROUP(group) (((group) >= 0) && ((group) <= 1))

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    SK32F0xx SLED configuration options
 * @{
 */
/**
 * @brief   DMA priority used when allocating the DMA1 channels assigned to
 *          the SLED groups.
 */
#if !defined(SK32_SLED_DMA_PRIORITY) || defined(__DOXYGEN__)
#define SK32_SLED_DMA_PRIORITY          2
#endif

/**
 * @brief   Enable the SLED1 group (DR[0], DMA1 channel 1).
 */
#if !defined(SK32_SLED_USE_SLED1) || defined(__DOXYGEN__)
#define SK32_SLED_USE_SLED1             TRUE
#endif

/**
 * @brief   Enable the SLED2 group (DR[1], DMA1 channel 2).
 */
#if !defined(SK32_SLED_USE_SLED2) || defined(__DOXYGEN__)
#define SK32_SLED_USE_SLED2             FALSE
#endif
/** @} */

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a SLED output polarity setting.
 */
typedef enum {
  SLED_POLARITY_LOW = 0,                /**< @brief Active/idle low level.  */
  SLED_POLARITY_HIGH = 1                /**< @brief Active/idle high level. */
} sled_polarity_t;

/**
 * @brief   Type of a SLED group identifier.
 * @note    The numeric values are the indices into the DR[] register array
 *          and into the internal group configuration table.
 */
typedef enum {
  SLED1 = 0,                            /**< @brief SLED1 group.           */
  SLED2 = 1                             /**< @brief SLED2 group.           */
} sled_group_t;

/**
 * @brief   Type of a SLED data register write width.
 * @details The write width selects how the hardware fills the 32 bits wide
 *          FIFO entry when data is written to the group data register, which
 *          determines how the four output channels of a group are driven:
 *          - @p SLED_WIDTH_8BIT:  one byte is replicated 4 times into the
 *            FIFO entry, so all four channels carry the same data stream
 *            (the same light effect on CH0..CH3) using the least amount of
 *            RAM;
 *          - @p SLED_WIDTH_16BIT: a half word is replicated twice into the
 *            FIFO entry, so CH0 == CH2 carry one stream and CH1 == CH3 the
 *            other (two simultaneous effects);
 *          - @p SLED_WIDTH_32BIT: a whole word is stored directly into the
 *            FIFO entry, so each of the four channels carries its own byte
 *            (four simultaneous effects).
 * @note    The byte to channel mapping is little endian: byte_i of a FIFO
 *          entry is serialized on channel i (CH0 is the least significant
 *          byte).
 */
typedef enum {
  SLED_WIDTH_8BIT  = 0,                 /**< @brief 8 bit writes (1 byte). */
  SLED_WIDTH_16BIT = 1,                 /**< @brief 16 bit writes (2 bytes).*/
  SLED_WIDTH_32BIT = 2                  /**< @brief 32 bit writes (4 bytes).*/
} sled_width_t;

/**
 * @brief   SLED configuration structure.
 * @note    The time-code and divider values are expressed in SLED clock
 *          cycles, the meaning of each field matches the vendor
 *          SK32F0xx_StdPeriph_Driver SLED_InitTypeDef so that the register
 *          programming performed by the vendor demonstration code can be
 *          ported unchanged:
 *          @code
 *            SLED->TCR = (80 << 16) | (15 << 8) | (4 << 0);   // TRST/T1H/T0H
 *            SLED->CDR = (3 << 0)  | (31 << 8);              // PSC / BRD
 *          @endcode
 *          is written as @p { .t0h_cycles = 4, .t1h_cycles = 15,
 *          .trst_cycles = 80, .prescaler = 3, .baud_prescaler = 31 }.
 */
typedef struct {
  /**
   * @brief   T0H time code (5 bits, bits [4:0] of TCR).
   */
  uint8_t             t0h_cycles;
  /**
   * @brief   T1H time code (5 bits, bits [12:8] of TCR).
   */
  uint8_t             t1h_cycles;
  /**
   * @brief   Reset code duration (8 bits, bits [23:16] of TCR).
   */
  uint8_t             trst_cycles;
  /**
   * @brief   SLED clock prescaler (2 bits, bits [1:0] of CDR).
   * @note    The value selects the SCLK divider: 0..3 = /1../4.
   */
  uint8_t             prescaler;
  /**
   * @brief   Baud rate divider (5 bits, bits [12:8] of CDR).
   * @note    The serial bit clock is fSCLK / (baud_prescaler + 1).
   */
  uint8_t             baud_prescaler;
  /**
   * @brief   Idle level polarity (CR bit IDLESTS).
   * @note    WS2812 compatible idle level is @p SLED_POLARITY_LOW.
   */
  sled_polarity_t     idle_polarity;
  /**
   * @brief   Reset level polarity (CR bit RSTSTS).
   * @note    WS2812 compatible reset level is @p SLED_POLARITY_LOW.
   */
  sled_polarity_t     reset_polarity;
} SLEDConfig;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the CR "reset start" bit of a group.
 *
 * @param[in] group     the SLED group index
 * @return              The CR RSTSTRx mask.
 */
#define sled_lld_rststr_mask(group)                                          \
  ((group) == SLED1 ? SLED_CR_RSTSTR1 : SLED_CR_RSTSTR2)

/**
 * @brief   Returns the CR "DMA enable" bit of a group.
 *
 * @param[in] group     the SLED group index
 * @return              The CR DMAENx mask.
 */
#define sled_lld_dmaen_mask(group)                                           \
  ((group) == SLED1 ? SLED_CR_DMAEN1 : SLED_CR_DMAEN2)

/**
 * @brief   Returns the SR "busy" flag of a group.
 *
 * @param[in] group     the SLED group index
 * @return              The SR BUSYx mask.
 */
#define sled_lld_busy_mask(group)                                            \
  ((group) == SLED1 ? SLED_SR_BUSY1 : SLED_SR_BUSY2)

/**
 * @brief   Returns the FCR FIFO count field of a group.
 *
 * @param[in] group     the SLED group index
 * @return              The FCR FCNT field mask.
 */
#define sled_lld_fcnt_mask(group)                                            \
  ((group) == SLED1 ? SLED_FCR_FCNT1 : SLED_FCR_FCNT2)

/**
 * @brief   Returns the DR register of a group.
 *
 * @param[in] group     the SLED group index
 * @return              The DR register index in the DR[] array.
 */
#define sled_lld_dr_index(group)                                             \
  ((group) == SLED1 ? 0U : 1U)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void sled_lld_init(void);
  void sled_lld_start(const SLEDConfig *config);
  void sled_lld_stop(void);
  msg_t sled_lld_send(sled_group_t group, sled_width_t width,
                      const uint8_t *data, size_t size);
  msg_t sled_lld_send_bytes(sled_group_t group, const uint8_t *data,
                            size_t size);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SLED == TRUE */

#endif /* HAL_SLED_LLD_H */

/** @} */

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
 * @file    SK32F0xx/sk32_dma.h
 * @brief   DMA helper driver header.
 * @details This driver allows to allocate and free the DMA1 channels at
 *          runtime in order to allow all the other device drivers to
 *          coordinate the access to the shared resource.  In the rest of
 *          this document the DMA channels are referred to as "streams",
 *          the same naming convention used by the STM32 and AT32 DMA helper
 *          drivers, so the exported functions can be used unchanged.
 * @note    The SK32 DMA is a classic DMA1 unit with 6 channels whose
 *          per-channel registers are CCR, CNDTR, CPAR and CMAR, exactly the
 *          register set managed by the vendor SK32F0xx_StdPeriph_Driver DMA
 *          driver; the configuration register bits used by this driver are
 *          the DMA_CCR_* constants from the SK32 device header.
 *
 * @addtogroup SK32F0xx_DMA
 * @{
 */

#ifndef SK32_DMA_H
#define SK32_DMA_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   DMA capability.
 * @details if @p TRUE then the DMA is able of burst transfers, FIFOs,
 *          scatter gather and other advanced features.
 */
#define SK32_DMA_ADVANCED           FALSE

/**
 * @brief   Maximum number of transfers in a single operation.
 */
#define SK32_DMA_MAX_TRANSFER       65535

/**
 * @brief   Total number of DMA streams.
 * @details This is the total number of streams among all the DMA units.
 */
#define SK32_DMA_STREAMS            (SK32_DMA1_NUM_CHANNELS +               \
                                     SK32_DMA2_NUM_CHANNELS)

/**
 * @brief   Mask of the ISR bits passed to the DMA callback functions.
 */
#define SK32_DMA_ISR_MASK           0x0E

/**
 * @brief   Checks if a DMA priority is within the valid range.
 * @param[in] prio      DMA priority
 *
 * @retval              The check result.
 * @retval false        invalid DMA priority.
 * @retval true         correct DMA priority.
 */
#define SK32_DMA_IS_VALID_PRIORITY(prio) (((prio) >= 0U) && ((prio) <= 3U))

/**
 * @brief   Checks if a DMA stream id is within the valid range.
 *
 * @param[in] id        DMA stream id
 * @retval              The check result.
 * @retval false        invalid DMA channel.
 * @retval true         correct DMA channel.
 */
#define SK32_DMA_IS_VALID_STREAM(id) (((id) >= 0U) &&                       \
                                       ((id) < SK32_DMA_STREAMS))

/**
 * @brief   Returns an unique numeric identifier for a DMA stream.
 *
 * @param[in] dma       the DMA unit number
 * @param[in] stream    the stream number
 * @return              An unique numeric stream identifier.
 */
#define SK32_DMA_STREAM_ID(dma, stream)                                     \
  ((((dma) - 1) * SK32_DMA1_NUM_CHANNELS) + ((stream) - 1))

/**
 * @brief   Returns a DMA stream identifier mask.
 *
 * @param[in] dma       the DMA unit number
 * @param[in] stream    the stream number
 * @return              A DMA stream identifier mask.
 */
#define SK32_DMA_STREAM_ID_MSK(dma, stream)                                 \
  (1U << SK32_DMA_STREAM_ID(dma, stream))

/**
 * @name    DMA streams identifiers
 * @{
 */
/**
 * @brief   Returns a pointer to a sk32_dma_stream_t structure.
 *
 * @param[in] id        the stream numeric identifier
 * @return              A pointer to the sk32_dma_stream_t constant structure
 *                      associated to the DMA stream.
 */
#define SK32_DMA_STREAM(id)         (&_sk32_dma_streams[id])

#if SK32_DMA1_NUM_CHANNELS > 0
#define SK32_DMA1_STREAM1           SK32_DMA_STREAM(0)
#endif
#if SK32_DMA1_NUM_CHANNELS > 1
#define SK32_DMA1_STREAM2           SK32_DMA_STREAM(1)
#endif
#if SK32_DMA1_NUM_CHANNELS > 2
#define SK32_DMA1_STREAM3           SK32_DMA_STREAM(2)
#endif
#if SK32_DMA1_NUM_CHANNELS > 3
#define SK32_DMA1_STREAM4           SK32_DMA_STREAM(3)
#endif
#if SK32_DMA1_NUM_CHANNELS > 4
#define SK32_DMA1_STREAM5           SK32_DMA_STREAM(4)
#endif
#if SK32_DMA1_NUM_CHANNELS > 5
#define SK32_DMA1_STREAM6           SK32_DMA_STREAM(5)
#endif
/** @} */

/**
 * @name    CCR register constants
 * @note    The bit values are the DMA_CCR_* constants from the vendor CMSIS
 *          device header (sk32f0xx.h), the same used by the vendor
 *          StdPeriph DMA driver (DMA_Init, DMA_Cmd, DMA_ITConfig, ...).
 * @{
 */
#define SK32_DMA_CCR_RESET_VALUE    0x00000000U
#define SK32_DMA_CR_EN              DMA_CCR_EN
#define SK32_DMA_CR_TEIE            DMA_CCR_TEIE
#define SK32_DMA_CR_HTIE            DMA_CCR_HTIE
#define SK32_DMA_CR_TCIE            DMA_CCR_TCIE
#define SK32_DMA_CR_DIR_MASK        (DMA_CCR_DIR | DMA_CCR_MEM2MEM)
#define SK32_DMA_CR_DIR_P2M         0U
#define SK32_DMA_CR_DIR_M2P         DMA_CCR_DIR
#define SK32_DMA_CR_DIR_M2M         DMA_CCR_MEM2MEM
#define SK32_DMA_CR_CIRC            DMA_CCR_CIRC
#define SK32_DMA_CR_PINC            DMA_CCR_PINC
#define SK32_DMA_CR_MINC            DMA_CCR_MINC
#define SK32_DMA_CR_PSIZE_MASK      DMA_CCR_PSIZE
#define SK32_DMA_CR_PSIZE_BYTE      0U
#define SK32_DMA_CR_PSIZE_HWORD     DMA_CCR_PSIZE_0
#define SK32_DMA_CR_PSIZE_WORD      DMA_CCR_PSIZE_1
#define SK32_DMA_CR_MSIZE_MASK      DMA_CCR_MSIZE
#define SK32_DMA_CR_MSIZE_BYTE      0U
#define SK32_DMA_CR_MSIZE_HWORD     DMA_CCR_MSIZE_0
#define SK32_DMA_CR_MSIZE_WORD      DMA_CCR_MSIZE_1
#define SK32_DMA_CR_SIZE_MASK       (SK32_DMA_CR_PSIZE_MASK |              \
                                     SK32_DMA_CR_MSIZE_MASK)
#define SK32_DMA_CR_PL_MASK         DMA_CCR_PL
#define SK32_DMA_CR_PL(n)           ((n) << 12U)
/** @} */

/**
 * @name    Status flags passed to the ISR callbacks
 * @details The flags are pre-shifted and aligned to bit zero, the same
 *          convention used by the STM32 DMA helper.
 * @{
 */
#define SK32_DMA_ISR_TEIF           DMA_ISR_TEIF1
#define SK32_DMA_ISR_HTIF           DMA_ISR_HTIF1
#define SK32_DMA_ISR_TCIF           DMA_ISR_TCIF1
/** @} */

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a DMA callback.
 *
 * @param[in] p         parameter for the registered function
 * @param[in] flags     pre-shifted content of the ISR register, the bits
 *                      are aligned to bit zero
 */
typedef void (*sk32_dmaisr_t)(void *p, uint32_t flags);

/**
 * @brief   SK32 DMA stream descriptor structure.
 */
typedef struct {
  DMA_TypeDef           *dma;           /**< @brief Associated DMA.         */
  DMA_Channel_TypeDef   *channel;       /**< @brief Associated DMA channel. */
  uint32_t              cmask;          /**< @brief Mask of streams sharing
                                             the same ISR.                  */
  uint8_t               dummy;          /**< @brief Filler.                 */
  uint8_t               shift;          /**< @brief Bit offset in ISR and
                                             IFCR registers.                */
  uint8_t               selfindex;      /**< @brief Index to self in array. */
  uint8_t               vector;         /**< @brief Associated IRQ vector.  */
} sk32_dma_stream_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    Macro Functions
 * @{
 */
/**
 * @brief   Associates a peripheral data register to a DMA stream.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 * @param[in] addr      value to be written in the CPAR register
 *
 * @special
 */
#define dmaStreamSetPeripheral(dmastp, addr) {                              \
  (dmastp)->channel->CPAR = (uint32_t)(addr);                               \
}

/**
 * @brief   Associates a memory destination to a DMA stream.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 * @param[in] addr      value to be written in the CMAR register
 *
 * @special
 */
#define dmaStreamSetMemory0(dmastp, addr) {                                 \
  (dmastp)->channel->CMAR = (uint32_t)(addr);                               \
}

/**
 * @brief   Sets the number of transfers to be performed.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 * @param[in] size      value to be written in the CNDTR register
 *
 * @special
 */
#define dmaStreamSetTransactionSize(dmastp, size) {                         \
  (dmastp)->channel->CNDTR = (uint32_t)(size);                              \
}

/**
 * @brief   Returns the number of transfers to be performed.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 * @return              The number of transfers to be performed.
 *
 * @special
 */
#define dmaStreamGetTransactionSize(dmastp) ((size_t)((dmastp)->channel->CNDTR))

/**
 * @brief   Programs the stream mode settings.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 * @param[in] mode      value to be written in the CCR register
 *
 * @special
 */
#define dmaStreamSetMode(dmastp, mode) {                                    \
  (dmastp)->channel->CCR = (uint32_t)(mode);                                \
}

/**
 * @brief   DMA stream enable.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamEnable(dmastp) {                                           \
  (dmastp)->channel->CCR |= SK32_DMA_CR_EN;                                 \
}

/**
 * @brief   DMA stream disable.
 * @details The function disables the specified stream and then clears any
 *          pending interrupt.
 * @note    This function can be invoked in both ISR or thread context.
 * @note    Interrupts enabling flags are set to zero after this call, see
 *          bug 3607518.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamDisable(dmastp) {                                          \
  (dmastp)->channel->CCR &= ~(SK32_DMA_CR_TCIE | SK32_DMA_CR_HTIE |         \
                              SK32_DMA_CR_TEIE | SK32_DMA_CR_EN);           \
  dmaStreamClearInterrupt(dmastp);                                          \
}

/**
 * @brief   DMA stream interrupt sources clear.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamClearInterrupt(dmastp) {                                   \
  (dmastp)->dma->IFCR = SK32_DMA_ISR_MASK << (dmastp)->shift;               \
}

/**
 * @brief   Starts a memory to memory operation using the specified stream.
 * @note    The default transfer data mode is "byte to byte" but it can be
 *          changed by specifying extra options in the @p mode parameter.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 * @param[in] mode      value to be written in the CCR register, this value
 *                      is implicitly ORed with:
 *                      - @p SK32_DMA_CR_MINC
 *                      - @p SK32_DMA_CR_PINC
 *                      - @p SK32_DMA_CR_DIR_M2M
 *                      - @p SK32_DMA_CR_EN
 *                      .
 * @param[in] src       source address
 * @param[in] dst       destination address
 * @param[in] n         number of data units to copy
 */
#define dmaStartMemCopy(dmastp, mode, src, dst, n) {                        \
  dmaStreamSetPeripheral(dmastp, src);                                      \
  dmaStreamSetMemory0(dmastp, dst);                                         \
  dmaStreamSetTransactionSize(dmastp, n);                                   \
  dmaStreamSetMode(dmastp, (mode) |                                         \
                           SK32_DMA_CR_MINC | SK32_DMA_CR_PINC |            \
                           SK32_DMA_CR_DIR_M2M | SK32_DMA_CR_EN);           \
}

/**
 * @brief   Polled wait for DMA transfer end.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 */
#define dmaWaitCompletion(dmastp) {                                         \
  while ((dmastp)->channel->CNDTR > 0U)                                     \
    ;                                                                       \
  dmaStreamDisable(dmastp);                                                 \
}
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern const sk32_dma_stream_t _sk32_dma_streams[SK32_DMA_STREAMS];
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void dmaInit(void);
  const sk32_dma_stream_t *dmaStreamAllocI(uint32_t id,
                                           uint32_t priority,
                                           sk32_dmaisr_t func,
                                           void *param);
  const sk32_dma_stream_t *dmaStreamAlloc(uint32_t id,
                                          uint32_t priority,
                                          sk32_dmaisr_t func,
                                          void *param);
  void dmaStreamFreeI(const sk32_dma_stream_t *dmastp);
  void dmaStreamFree(const sk32_dma_stream_t *dmastp);
  void dmaServeInterrupt(const sk32_dma_stream_t *dmastp);
#ifdef __cplusplus
}
#endif

#endif /* SK32_DMA_H */

/** @} */

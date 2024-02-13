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
 * @file    DMAv1/at32_dma.h
 * @brief   DMA helper driver header.
 *
 * @addtogroup AT32_DMA
 * @{
 */

#ifndef AT32_DMA_H
#define AT32_DMA_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   DMA capability.
 * @details if @p TRUE then the DMA is able of burst transfers, FIFOs,
 *          scatter gather and other advanced features.
 */
#define AT32_DMA_ADVANCED           FALSE

/**
 * @brief   Maximum number of transfers in a single operation.
 */
#define AT32_DMA_MAX_TRANSFER       65535

/**
 * @brief   Total number of DMA streams.
 * @details This is the total number of streams among all the DMA units.
 */
#define AT32_DMA_STREAMS            (AT32_DMA1_NUM_CHANNELS +               \
                                     AT32_DMA2_NUM_CHANNELS)

/**
 * @brief   Mask of the STS bits passed to the DMA callback functions.
 */
#define AT32_DMA_STS_MASK           0x0E

/**
 * @brief   Checks if a DMA priority is within the valid range.
 * @param[in] prio      DMA priority
 *
 * @retval              The check result.
 * @retval false        invalid DMA priority.
 * @retval true         correct DMA priority.
 */
#define AT32_DMA_IS_VALID_PRIORITY(prio) (((prio) >= 0U) && ((prio) <= 3U))

/**
 * @brief   Returns an unique numeric identifier for a DMA stream.
 *
 * @param[in] dma       the DMA unit number
 * @param[in] stream    the stream number
 * @return              An unique numeric stream identifier.
 */
#define AT32_DMA_STREAM_ID(dma, stream)                                    \
  ((((dma) - 1) * AT32_DMA1_NUM_CHANNELS) + ((stream) - 1))

/**
 * @name    DMA streams identifiers
 * @{
 */
/**
 * @brief   Returns a pointer to a at32_dma_stream_t structure.
 *
 * @param[in] id        the stream numeric identifier
 * @return              A pointer to the at32_dma_stream_t constant structure
 *                      associated to the DMA stream.
 */
#define AT32_DMA_STREAM(id)        (&_at32_dma_streams[id])

#if AT32_DMA1_NUM_CHANNELS > 0
#define AT32_DMA1_STREAM1          AT32_DMA_STREAM(0)
#endif
#if AT32_DMA1_NUM_CHANNELS > 1
#define AT32_DMA1_STREAM2          AT32_DMA_STREAM(1)
#endif
#if AT32_DMA1_NUM_CHANNELS > 2
#define AT32_DMA1_STREAM3          AT32_DMA_STREAM(2)
#endif
#if AT32_DMA1_NUM_CHANNELS > 3
#define AT32_DMA1_STREAM4          AT32_DMA_STREAM(3)
#endif
#if AT32_DMA1_NUM_CHANNELS > 4
#define AT32_DMA1_STREAM5          AT32_DMA_STREAM(4)
#endif
#if AT32_DMA1_NUM_CHANNELS > 5
#define AT32_DMA1_STREAM6          AT32_DMA_STREAM(5)
#endif
#if AT32_DMA1_NUM_CHANNELS > 6
#define AT32_DMA1_STREAM7          AT32_DMA_STREAM(6)
#endif
#if AT32_DMA2_NUM_CHANNELS > 0
#define AT32_DMA2_STREAM1          AT32_DMA_STREAM(AT32_DMA1_NUM_CHANNELS + 0)
#endif
#if AT32_DMA2_NUM_CHANNELS > 1
#define AT32_DMA2_STREAM2          AT32_DMA_STREAM(AT32_DMA1_NUM_CHANNELS + 1)
#endif
#if AT32_DMA2_NUM_CHANNELS > 2
#define AT32_DMA2_STREAM3          AT32_DMA_STREAM(AT32_DMA1_NUM_CHANNELS + 2)
#endif
#if AT32_DMA2_NUM_CHANNELS > 3
#define AT32_DMA2_STREAM4          AT32_DMA_STREAM(AT32_DMA1_NUM_CHANNELS + 3)
#endif
#if AT32_DMA2_NUM_CHANNELS > 4
#define AT32_DMA2_STREAM5          AT32_DMA_STREAM(AT32_DMA1_NUM_CHANNELS + 4)
#endif
#if AT32_DMA2_NUM_CHANNELS > 5
#define AT32_DMA2_STREAM6          AT32_DMA_STREAM(AT32_DMA1_NUM_CHANNELS + 5)
#endif
#if AT32_DMA2_NUM_CHANNELS > 6
#define AT32_DMA2_STREAM7          AT32_DMA_STREAM(AT32_DMA1_NUM_CHANNELS + 6)
#endif
/** @} */

/**
 * @name    CCTRL register constants common to all DMA types
 * @{
 */
#define AT32_DMA_CCTRL_RESET_VALUE  0x00000000U
#define AT32_DMA_CCTRL_CHEN         DMA_CCTRL_CHEN
#define AT32_DMA_CCTRL_DTERRIEN     DMA_CCTRL_DTERRIEN
#define AT32_DMA_CCTRL_HDTIEN       DMA_CCTRL_HDTIEN
#define AT32_DMA_CCTRL_FDTIEN       DMA_CCTRL_FDTIEN
#define AT32_DMA_CCTRL_DTD_MASK     (DMA_CCTRL_DTD | DMA_CCTRL_M2M)
#define AT32_DMA_CCTRL_DTD_P2M      0U
#define AT32_DMA_CCTRL_DTD_M2P      DMA_CCTRL_DTD
#define AT32_DMA_CCTRL_DTD_M2M      DMA_CCTRL_M2M
#define AT32_DMA_CCTRL_LM           DMA_CCTRL_LM
#define AT32_DMA_CCTRL_PINCM        DMA_CCTRL_PINCM
#define AT32_DMA_CCTRL_MINCM        DMA_CCTRL_MINCM
#define AT32_DMA_CCTRL_PWIDTH_MASK  DMA_CCTRL_PWIDTH
#define AT32_DMA_CCTRL_PWIDTH_BYTE  0U
#define AT32_DMA_CCTRL_PWIDTH_HWORD DMA_CCTRL_PWIDTH_0
#define AT32_DMA_CCTRL_PWIDTH_WORD  DMA_CCTRL_PWIDTH_1
#define AT32_DMA_CCTRL_MWIDTH_MASK  DMA_CCTRL_MWIDTH
#define AT32_DMA_CCTRL_MWIDTH_BYTE  0U
#define AT32_DMA_CCTRL_MWIDTH_HWORD DMA_CCTRL_MWIDTH_0
#define AT32_DMA_CCTRL_MWIDTH_WORD  DMA_CCTRL_MWIDTH_1
#define AT32_DMA_CCTRL_SIZE_MASK    (AT32_DMA_CCTRL_PWIDTH_MASK |           \
                                     AT32_DMA_CCTRL_MWIDTH_MASK)
#define AT32_DMA_CCTRL_CHPL_MASK    DMA_CCTRL_CHPL
#define AT32_DMA_CCTRL_CHPL(n)      ((n) << 12U)
/** @} */

/**
 * @name    Status flags passed to the STS callbacks
 * @{
 */
#define AT32_DMA_STS_DTERRF         DMA_STS_DTERRF1
#define AT32_DMA_STS_HDTF           DMA_STS_HDTF1
#define AT32_DMA_STS_FDTF           DMA_STS_FDTF1
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(AT32_DMA_SUPPORTS_DMAMUX)
#error "AT32_DMA_SUPPORTS_DMAMUX not defined in registry"
#endif

#if !defined(AT32_DMA1_NUM_CHANNELS)
#error "AT32_DMA1_NUM_CHANNELS not defined in registry"
#endif

#if !defined(AT32_DMA2_NUM_CHANNELS)
#error "AT32_DMA2_NUM_CHANNELS not defined in registry"
#endif

#if (AT32_DMA1_NUM_CHANNELS < 0) || (AT32_DMA1_NUM_CHANNELS > 7)
#error "unsupported channels configuration"
#endif

#if (AT32_DMA2_NUM_CHANNELS < 0) || (AT32_DMA2_NUM_CHANNELS > 7)
#error "unsupported channels configuration"
#endif

#if (AT32_DMA_SUPPORTS_DMAMUX == TRUE) || defined(__DOXYGEN__)
#include "at32_dmamux.h"
#endif

#if !defined(AT32_DMA_USE_DMAMUX) || defined(__DOXYGEN__)
#define AT32_DMA_USE_DMAMUX         FALSE
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a DMA callback.
 *
 * @param[in] p         parameter for the registered function
 * @param[in] flags     pre-shifted content of the STS register, the bits
 *                      are aligned to bit zero
 */
typedef void (*at32_dmasts_t)(void *p, uint32_t flags);

/**
 * @brief   AT32 DMA stream descriptor structure.
 */
typedef struct {
  DMA_TypeDef           *dma;           /**< @brief Associated DMA.         */
  DMA_Channel_TypeDef   *channel;       /**< @brief Associated DMA channel. */
  uint32_t              cmask;          /**< @brief Mask of streams sharing
                                             the same STS.                  */
  uint8_t               dummy;          /**< @brief Filler.                 */
  uint8_t               shift;          /**< @brief Bit offset in STS, CLR  */
  uint8_t               selfindex;      /**< @brief Index to self in array. */
  uint8_t               vector;         /**< @brief Associated IRQ vector.  */
} at32_dma_stream_t;

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
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 * @param[in] addr      value to be written in the CPADDR register
 *
 * @special
 */
#define dmaStreamSetPeripheral(dmastp, addr) {                              \
  (dmastp)->channel->CPADDR = (uint32_t)(addr);                             \
}

/**
 * @brief   Associates a memory destination to a DMA stream.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 * @param[in] addr      value to be written in the CMADDR register
 *
 * @special
 */
#define dmaStreamSetMemory0(dmastp, addr) {                                 \
  (dmastp)->channel->CMADDR = (uint32_t)(addr);                             \
}

/**
 * @brief   Sets the number of transfers to be performed.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 * @param[in] size      value to be written in the CDTCNT register
 *
 * @special
 */
#define dmaStreamSetTransactionSize(dmastp, size) {                         \
  (dmastp)->channel->CDTCNT = (uint32_t)(size);                             \
}

/**
 * @brief   Returns the number of transfers to be performed.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 * @return              The number of transfers to be performed.
 *
 * @special
 */
#define dmaStreamGetTransactionSize(dmastp) ((size_t)((dmastp)->channel->CDTCNT))

/**
 * @brief   Programs the stream mode settings.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 * @param[in] mode      value to be written in the CCTRL register
 *
 * @special
 */
#define dmaStreamSetMode(dmastp, mode) {                                    \
  (dmastp)->channel->CCTRL = (uint32_t)(mode);                              \
}

/**
 * @brief   DMA stream enable.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamEnable(dmastp) {                                           \
  (dmastp)->channel->CCTRL |= AT32_DMA_CCTRL_CHEN;                          \
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
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamDisable(dmastp) {                                          \
  (dmastp)->channel->CCTRL &= ~(AT32_DMA_CCTRL_FDTIEN |                     \
                                AT32_DMA_CCTRL_HDTIEN |                     \
                                AT32_DMA_CCTRL_DTERRIEN |                   \
                                AT32_DMA_CCTRL_CHEN);                       \
  dmaStreamClearInterrupt(dmastp);                                          \
}

/**
 * @brief   DMA stream interrupt sources clear.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamClearInterrupt(dmastp) {                                   \
  (dmastp)->dma->CLR = AT32_DMA_STS_MASK << (dmastp)->shift;                \
}

/**
 * @brief   Starts a memory to memory operation using the specified stream.
 * @note    The default transfer data mode is "byte to byte" but it can be
 *          changed by specifying extra options in the @p mode parameter.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 * @param[in] mode      value to be written in the CCTRL register, this value
 *                      is implicitly ORed with:
 *                      - @p AT32_DMA_CCTRL_MINCM
 *                      - @p AT32_DMA_CCTRL_PINCM
 *                      - @p AT32_DMA_CCTRL_DTD_M2M
 *                      - @p AT32_DMA_CCTRL_CHEN
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
                           AT32_DMA_CCTRL_MINCM | AT32_DMA_CCTRL_PINCM |    \
                           AT32_DMA_CCTRL_DTD_M2M | AT32_DMA_CCTRL_CHEN);   \
}

/**
 * @brief   Polled wait for DMA transfer end.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a at32_dma_stream_t structure
 */
#define dmaWaitCompletion(dmastp) {                                         \
  while ((dmastp)->channel->CDTCNT > 0U)                                    \
    ;                                                                       \
  dmaStreamDisable(dmastp);                                                 \
}
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern const at32_dma_stream_t _at32_dma_streams[AT32_DMA_STREAMS];
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void dmaInit(void);
  const at32_dma_stream_t *dmaStreamAllocI(uint32_t id,
                                            uint32_t priority,
                                            at32_dmasts_t func,
                                            void *param);
  const at32_dma_stream_t *dmaStreamAlloc(uint32_t id,
                                           uint32_t priority,
                                           at32_dmasts_t func,
                                           void *param);
  void dmaStreamFreeI(const at32_dma_stream_t *dmastp);
  void dmaStreamFree(const at32_dma_stream_t *dmastp);
  void dmaServeInterrupt(const at32_dma_stream_t *dmastp);
#if AT32_DMA_SUPPORTS_DMAMUX == TRUE
  void dmaSetRequestSource(const at32_dma_stream_t *dmastp, uint32_t channel, uint32_t per);
#endif
#ifdef __cplusplus
}
#endif

#endif /* AT32_DMA_H */

/** @} */

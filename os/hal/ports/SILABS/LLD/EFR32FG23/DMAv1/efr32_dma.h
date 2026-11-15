/*
    ChibiOS - Copyright (C) 2024 Xael South

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
 * @file    DMAv1/efr32_dma.h
 * @brief   Enhanced-DMA helper driver header.
 *
 * @addtogroup EFR32_DMA
 * @{
 */

#ifndef EFR32_DMA_H
#define EFR32_DMA_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Total number of DMA streams.
 * @details This is the total number of streams among all the DMA units.
 */
#define EFR32_DMA_STREAMS           8U


/**
 * @brief   Error mask of the ISR bits.
 */
#define EFR32_DMA_ISR_ERROR_MASK    0x80000000U

/**
 * @brief   Done mask of the ISR bits.
 */
#define EFR32_DMA_ISR_DONE_MASK(id) (1U << EFR32_DMA_STREAM(id)->selfindex)

/**
 * @brief   Mask of the ISR bits passed to the DMA callback functions.
 */
#define EFR32_DMA_ISR_MASK(id)      (EFR32_DMA_ISR_ERROR_MASK | EFR32_DMA_ISR_DONE_MASK(id))

/**
 * @brief   Checks if a DMA stream id is within the valid range.
 *
 * @param[in] id        DMA stream id
 * @retval              The check result.
 * @retval false        invalid DMA stream.
 * @retval true         correct DMA stream.
 */
#define EFR32_DMA_IS_VALID_STREAM(id) (((id) >= 0U) &&                      \
                                       ((id) <= EFR32_DMA_STREAMS))

/**
 * @name    Special stream identifiers
 * @{
 */
#define EFR32_DMA_STREAM_ID_ANY     EFR32_DMA_STREAMS
/** @} */

/**
 * @name    DMA streams identifiers
 * @{
 */
/**
 * @brief   Returns a pointer to a efr32_dma_stream_t structure.
 *
 * @param[in] id        the stream numeric identifier
 * @return              A pointer to the efr32_dma_stream_t constant structure
 *                      associated to the DMA stream.
 */
#define EFR32_DMA_STREAM(id)        (&_efr32_dma_streams[id])

#define EFR32_DMA1_STREAM0          EFR32_DMA_STREAM(0)
#define EFR32_DMA1_STREAM1          EFR32_DMA_STREAM(1)
#define EFR32_DMA1_STREAM2          EFR32_DMA_STREAM(2)
#define EFR32_DMA1_STREAM3          EFR32_DMA_STREAM(3)
#define EFR32_DMA1_STREAM4          EFR32_DMA_STREAM(4)
#define EFR32_DMA1_STREAM5          EFR32_DMA_STREAM(5)
#define EFR32_DMA1_STREAM6          EFR32_DMA_STREAM(6)
#define EFR32_DMA1_STREAM7          EFR32_DMA_STREAM(7)
/** @} */

/**
 * @name    CTRL register constants
 * @{
 */
#define EFR32_DMA_CH_CTRL_DSTMODE_ABSOLUTE  (0U << 31)
#define EFR32_DMA_CH_CTRL_DSTMODE_RELATIVE  (1U << 31)

#define EFR32_DMA_CH_CTRL_SRCMODE_ABSOLUTE  (0U << 30)
#define EFR32_DMA_CH_CTRL_SRCMODE_RELATIVE  (1U << 30)

#define EFR32_DMA_CH_CTRL_DSTINC_ONE        (0U << 28)
#define EFR32_DMA_CH_CTRL_DSTINC_TWO        (1U << 28)
#define EFR32_DMA_CH_CTRL_DSTINC_FOUR       (2U << 28)
#define EFR32_DMA_CH_CTRL_DSTINC_NONE       (3U << 28)

#define EFR32_DMA_CH_CTRL_SIZE_BYTE         (0U << 26)
#define EFR32_DMA_CH_CTRL_SIZE_HALFWORD     (1U << 26)
#define EFR32_DMA_CH_CTRL_SIZE_WORD         (2U << 26)
                                           
#define EFR32_DMA_CH_CTRL_SRCINC_ONE        (0U << 24)
#define EFR32_DMA_CH_CTRL_SRCINC_TWO        (1U << 24)
#define EFR32_DMA_CH_CTRL_SRCINC_FOUR       (2U << 24)
#define EFR32_DMA_CH_CTRL_SRCINC_NONE       (3U << 24)
                                           
#define EFR32_DMA_CH_CTRL_IGNORESREQ        (1U << 23)
                                           
#define EFR32_DMA_CH_CTRL_DECLOOPCNT        (1U << 22)
                                           
#define EFR32_DMA_CH_CTRL_REQMODE_BLOCK     (0U << 21)
#define EFR32_DMA_CH_CTRL_REQMODE_ALL       (1U << 21)
                                           
#define EFR32_DMA_CH_CTRL_DONEIEN           (1U << 20)
                                           
#define EFR32_DMA_CH_CTRL_BLOCKSIZE_ALL     (15U << 16)
                                           
#define EFR32_DMA_CH_CTRL_BYTESWAP          (1U << 15)
                                           
#define EFR32_DMA_CH_CTRL_XFERCNT(size)     (((size) - 1) << 4)
                                           
#define EFR32_DMA_CH_CTRL_STRUCTREQ         (1U << 3)

#define EFR32_DMA_CH_CTRL_STRUCTTYPE_TRANSFER    (0U << 0)
#define EFR32_DMA_CH_CTRL_STRUCTTYPE_SYNCHRONIZE (1U << 0)
#define EFR32_DMA_CH_CTRL_STRUCTTYPE_WRITE       (2U << 0)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(EFR32_HAS_DMA)
#error "EFR32_HAS_DMA missing in registry"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   EFR32 DMA ISR function type.
 *
 * @param[in] p         parameter for the registered function
 * @param[in] flags     content of the ISR register, see EFR32_DMA_ISR_MASK
 */
typedef void (*efr32_dmaisr_t)(void* p, uint32_t flags);

/**
 * @brief   EFR32 DMA stream descriptor structure.
 */
typedef struct {
  LDMA_CH_TypeDef       *stream;    /**< @brief Associated DMA stream.  */
  volatile uint32_t     *reqsel;    /**< @brief Assoc. REQSEL register. */
  uint8_t               selfindex;  /**< @brief Index to self in array. */
} efr32_dma_stream_t;

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
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 * @param[in] addr      value to be written in the CHx_SRC register
 *
 * @special
 */
#define dmaStreamSetPeripheral(dmastp, addr) {                              \
  (dmastp)->stream->SRC = (uint32_t)(addr);                                 \
}

/**
 * @brief   Associates a memory destination to a DMA stream.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 * @param[in] addr      value to be written in the CHx_DST register
 *
 * @special
 */
#define dmaStreamSetMemory0(dmastp, addr) {                                 \
  (dmastp)->stream->DST = (uint32_t)(addr);                                 \
}

/**
 * @brief   Programs the stream mode settings.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 * @param[in] mode      value to be written in the CTRL register
 *
 * @special
 */
#define dmaStreamSetMode(dmastp, mode) {                                    \
  (dmastp)->stream->CTRL = mode;                                            \
}

/**
 * @brief   DMA stream enable.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamEnable(dmastp) {                                           \
  dmaStreamClearInterrupt(dmastp);                                          \
  LDMA->IEN_SET = (1U << (dmastp)->selfindex);                              \
  LDMA->CHEN_SET = (1U << (dmastp)->selfindex);                             \
  *(dmastp)->reqsel = LDMAXBAR_CH_REQSEL_SOURCESEL_NONE;                    \
  LDMA->SWREQ_SET = (1U << (dmastp)->selfindex);                            \
}

/**
 * @brief   DMA stream disable.
 * @details The function disables the specified stream, waits for the disable
 *          operation to complete and then clears any pending interrupt.
 * @note    This function can be invoked in both ISR or thread context.
 * @note    Interrupts enabling flags are set to zero after this call.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamDisable(dmastp) {                                          \
  LDMA->CHDIS_SET = (1U << (dmastp)->selfindex);                            \
  LDMA->IEN_CLR = (1U << (dmastp)->selfindex);                              \
  dmaStreamClearInterrupt(dmastp);                                          \
  (dmastp)->stream->CFG = _LDMA_CH_CFG_RESETVALUE;                          \
  (dmastp)->stream->LOOP = _LDMA_CH_LOOP_RESETVALUE;                        \
  (dmastp)->stream->LINK = _LDMA_CH_LINK_RESETVALUE;                        \
}

/**
 * @brief   DMA stream interrupt sources clear.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamClearInterrupt(dmastp) {                                   \
  LDMA->IF_CLR = (1U << (dmastp)->selfindex);                               \
}

/**
 * @brief   Starts a memory to memory operation using the specified stream.
 * @note    The default transfer data mode is "byte to byte" but it can be
 *          changed by specifying extra options in the @p mode parameter.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 * @param[in] mode      value to be written in the CTRL register, this value
 *                      is implicitly ORed with:
 *                      - @p EFR32_DMA_CH_CTRL_DSTMODE_ABSOLUTE
 *                      - @p EFR32_DMA_CH_CTRL_SRCMODE_ABSOLUTE
 *                      - @p EFR32_DMA_CH_CTRL_SIZE_BYTE
 *                      - @p EFR32_DMA_CH_CTRL_DSTINC_ONE
 *                      - @p EFR32_DMA_CH_CTRL_SRCINC_ONE
 *                      - @p EFR32_DMA_CH_CTRL_REQMODE_ALL
 *                      - @p EFR32_DMA_CH_CTRL_BLOCKSIZE_ALL
 *                      - @p EFR32_DMA_CH_CTRL_XFERCNT(n)
 *                      - @p EFR32_DMA_CH_CTRL_DONEIEN
 *                      .
 * @param[in] src       source address
 * @param[in] dst       destination address
 * @param[in] n         number of data units to copy
 */
#define dmaStartMemCopy(dmastp, mode, src, dst, n) {                        \
  dmaStreamSetPeripheral(dmastp, src);                                      \
  dmaStreamSetMemory0(dmastp, dst);                                         \
  dmaStreamSetMode(dmastp, (mode) |                                         \
                           EFR32_DMA_CH_CTRL_DSTMODE_ABSOLUTE |             \
                           EFR32_DMA_CH_CTRL_SRCMODE_ABSOLUTE |             \
                           EFR32_DMA_CH_CTRL_SIZE_BYTE        |             \
                           EFR32_DMA_CH_CTRL_DSTINC_ONE       |             \
                           EFR32_DMA_CH_CTRL_SRCINC_ONE       |             \
                           EFR32_DMA_CH_CTRL_REQMODE_ALL      |             \
                           EFR32_DMA_CH_CTRL_BLOCKSIZE_ALL    |             \
                           EFR32_DMA_CH_CTRL_XFERCNT(n)       |             \
                           EFR32_DMA_CH_CTRL_DONEIEN);                      \
  dmaStreamEnable(dmastp);                                                  \
}

/**
 * @brief   Polled wait for DMA transfer end.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamFree().
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 */
#define dmaWaitCompletion(dmastp) {                                         \
  while((LDMA->CHBUSY & (1U << (dmastp)->selfindex)) == 1U) {}              \
  dmaStreamClearInterrupt(dmastp);                                          \
}
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern const efr32_dma_stream_t _efr32_dma_streams[EFR32_DMA_STREAMS];
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void dmaInit(void);
  const efr32_dma_stream_t *dmaStreamAllocI(uint32_t id,
                                            uint32_t priority,
                                            efr32_dmaisr_t func,
                                            void *param);
  const efr32_dma_stream_t *dmaStreamAlloc(uint32_t id,
                                           uint32_t priority,
                                           efr32_dmaisr_t func,
                                           void *param);
  void dmaStreamFreeI(const efr32_dma_stream_t *dmastp);
  void dmaStreamFree(const efr32_dma_stream_t *dmastp);
#ifdef __cplusplus
}
#endif

#endif /* EFR32_DMA_H */

/** @} */
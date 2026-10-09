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
 * @file    DMAv1/efr32_dma.c
 * @brief   Enhanced DMA helper driver code.
 *
 * @addtogroup EFR32_DMA
 * @details DMA sharing helper driver. In the EFR32 the DMA streams are a
 *          shared resource, this driver allows to allocate and free DMA
 *          streams at runtime in order to allow all the other device
 *          drivers to coordinate the access to the resource.
 * @note    The DMA ISR handlers are all declared into this module because
 *          sharing, the various device drivers can associate a callback to
 *          ISRs when allocating streams.
 * @{
 */

#include "hal.h"

/* The following macro is only defined if some driver requiring DMA services
   has been enabled.*/
#if defined(EFR32_DMA_REQUIRED) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Mask of the DMA streams in @p dma.allocated_mask.
 */
#define EFR32_DMA_STREAMS_MASK     0x000000FFU

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   DMA streams descriptors.
 * @details This table keeps the association between an unique stream
 *          identifier and the involved physical registers.
 * @note    Don't use this array directly, use the appropriate wrapper macros
 *          instead: @p EFR32_DMA_STREAM0, @p EFR32_DMA1_STREAM1 etc.
 */
const efr32_dma_stream_t _efr32_dma_streams[EFR32_DMA_STREAMS] = {
  {&(LDMA->CH[0]), &(LDMAXBAR->CH[0].REQSEL), 0},
  {&(LDMA->CH[1]), &(LDMAXBAR->CH[1].REQSEL), 1},
  {&(LDMA->CH[2]), &(LDMAXBAR->CH[2].REQSEL), 2},
  {&(LDMA->CH[3]), &(LDMAXBAR->CH[3].REQSEL), 3},
  {&(LDMA->CH[4]), &(LDMAXBAR->CH[4].REQSEL), 4},
  {&(LDMA->CH[5]), &(LDMAXBAR->CH[5].REQSEL), 5},
  {&(LDMA->CH[6]), &(LDMAXBAR->CH[6].REQSEL), 6},
  {&(LDMA->CH[7]), &(LDMAXBAR->CH[7].REQSEL), 7},
};

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   Global DMA-related data structures.
 */
static struct {
  /**
   * @brief   Mask of the allocated streams.
   */
  uint32_t          allocated_mask;

  /**
   * @brief   DMA IRQ redirectors.
   */
  struct {
    /**
     * @brief   DMA callback function.
     */
    efr32_dmaisr_t    func;

    /**
     * @brief   DMA callback parameter.
     */
    void              *param;
  } streams[EFR32_DMA_STREAMS];
} dma;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   LDMA shared interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(EFR32_LDMA_HANDLER) {
  unsigned i;
  uint32_t flags;
  uint32_t ch_err;

  OSAL_IRQ_PROLOGUE();

  flags = LDMA->IF;

  if ((flags & EFR32_DMA_ISR_ERROR_MASK) != 0U) {
    ch_err = (LDMA->STATUS & _LDMA_STATUS_CHERROR_MASK) >> _LDMA_STATUS_CHERROR_SHIFT;
  }
  else {
    ch_err = EFR32_DMA_STREAMS;
  }

  LDMA->IF_CLR = flags;

  for (i = 0U; i < EFR32_DMA_STREAMS; i++) {
    if (dma.streams[i].func) {
      uint32_t mask = EFR32_DMA_ISR_DONE_MASK(i);

      if (i == ch_err) {
        mask |= EFR32_DMA_ISR_ERROR_MASK;
        dma.streams[i].func(dma.streams[i].param, flags & mask);
      }
      else if ((flags & mask) != 0U) {
        dma.streams[i].func(dma.streams[i].param, flags & mask);
      }
    }
  }

  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   EFR32 DMA helper initialization.
 *
 * @init
 */
void dmaInit(void) {
  unsigned i;

  dma.allocated_mask = 0U;
  for (i = 0U; i < EFR32_DMA_STREAMS; i++) {
    dma.streams[i].func = NULL;
    dma.streams[i].param = NULL;
  }
}

/**
 * @brief   Allocates a DMA stream.
 * @details The stream is allocated and, if required, the DMA clock enabled.
 *          The function also enables the IRQ vector associated to the stream
 *          and initializes its priority.
 *
 * @param[in] id        numeric identifiers of a specific stream or:
 *                      - @p EFR32_DMA_STREAM_ID_ANY for any stream.
 *                      - @p EFR32_DMA_STREAM_ID_ANY_DMA1 for any stream
 *                        on DMA1.
 *                      - @p EFR32_DMA_STREAM_ID_ANY_DMA2 for any stream
 *                        on DMA2.
 *                      .
 * @param[in] priority  IRQ priority for the DMA stream
 * @param[in] func      handling function pointer, can be @p NULL
 * @param[in] param     a parameter to be passed to the handling function
 * @return              Pointer to the allocated @p efr32_dma_stream_t
 *                      structure.
 * @retval NULL         if a/the stream is not available.
 *
 * @iclass
 */
const efr32_dma_stream_t *dmaStreamAllocI(uint32_t id,
                                          uint32_t priority,
                                          efr32_dmaisr_t func,
                                          void *param) {
  uint32_t i, startid, endid;

  osalDbgCheckClassI();

  if (id < EFR32_DMA_STREAMS) {
    startid = id;
    endid   = id;
  }
#if EFR32_DMA_SUPPORTS_DMAMUX == TRUE
  else if (id == EFR32_DMA_STREAM_ID_ANY) {
    startid = 0U;
    endid   = EFR32_DMA_STREAMS - 1U;
  }
#endif
  else {
    osalDbgCheck(false);
    return NULL;
  }

  /* Enabling DMA clocks required by the current streams set. */
  if ((dma.allocated_mask & EFR32_DMA_STREAMS_MASK) == 0U) {
    CMU->CLKEN0_SET = CMU_CLKEN0_LDMA | CMU_CLKEN0_LDMAXBAR;

    LDMA->EN_SET = LDMA_EN_EN;

    LDMA->CHDIS_SET = _LDMA_CHDIS_MASK;

    LDMA->IEN_CLR = _LDMA_IEN_MASK;

    LDMA->IF_CLR = _LDMA_IF_MASK;

    LDMA->IEN_SET = LDMA_IEN_ERROR;

    nvicClearPending(EFR32_LDMA_NUMBER);

    nvicEnableVector(EFR32_LDMA_NUMBER, priority);
  }

  for (i = startid; i <= endid; i++) {
    uint32_t mask = (1U << i);

    if ((dma.allocated_mask & mask) == 0U) {
      const efr32_dma_stream_t *dmastp = EFR32_DMA_STREAM(i);

      /* Installs the DMA handler.*/
      dma.streams[i].func  = func;
      dma.streams[i].param = param;
      dma.allocated_mask  |= mask;

      /* Putting the stream in a safe state.*/
      dmaStreamDisable(dmastp);

      return dmastp;
    }
  }

  return NULL;
}

/**
 * @brief   Allocates a DMA stream.
 * @details The stream is allocated and, if required, the DMA clock enabled.
 *          The function also enables the IRQ vector associated to the stream
 *          and initializes its priority.
 *
 * @param[in] id        numeric identifiers of a specific stream or:
 *                      - @p EFR32_DMA_STREAM_ID_ANY for any stream.
 *                      - @p EFR32_DMA_STREAM_ID_ANY_DMA1 for any stream
 *                        on DMA1.
 *                      - @p EFR32_DMA_STREAM_ID_ANY_DMA2 for any stream
 *                        on DMA2.
 *                      .
 * @param[in] priority  IRQ priority for the DMA stream
 * @param[in] func      handling function pointer, can be @p NULL
 * @param[in] param     a parameter to be passed to the handling function
 * @return              Pointer to the allocated @p efr32_dma_stream_t
 *                      structure.
 * @retval NULL         if a/the stream is not available.
 *
 * @api
 */
const efr32_dma_stream_t *dmaStreamAlloc(uint32_t id,
                                         uint32_t priority,
                                         efr32_dmaisr_t func,
                                         void *param) {
  const efr32_dma_stream_t *dmastp;

  osalSysLock();
  dmastp = dmaStreamAllocI(id, priority, func, param);
  osalSysUnlock();

  return dmastp;
}

/**
 * @brief   Releases a DMA stream.
 * @details The stream is freed and, if required, the DMA clock disabled.
 *          Trying to release a unallocated stream is an illegal operation
 *          and is trapped if assertions are enabled.
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 *
 * @iclass
 */
void dmaStreamFreeI(const efr32_dma_stream_t *dmastp) {

  osalDbgCheck(dmastp != NULL);

  /* Check if the streams is not taken.*/
  osalDbgAssert((dma.allocated_mask & (1U << dmastp->selfindex)) != 0U,
                "not allocated");

  /* Marks the stream as not allocated.*/
  dma.allocated_mask &= ~(1U << dmastp->selfindex);

  if ((dma.allocated_mask & EFR32_DMA_STREAMS_MASK) == 0U) {
    /* Disable interrupt that is not more requiered. */
    nvicDisableVector(EFR32_LDMA_NUMBER);

    nvicClearPending(EFR32_LDMA_NUMBER);

    LDMA->IEN_CLR = _LDMA_IEN_MASK;

    LDMA->IF_CLR = _LDMA_IF_MASK;

    LDMA->CHDIS_SET = _LDMA_CHDIS_MASK;

    /* Disable LDMA unit. */
    LDMA->EN_CLR = LDMA_EN_EN;

    /* Shutting down clocks that are no more required, if any.*/
    CMU->CLKEN0_CLR = CMU_CLKEN0_LDMA | CMU_CLKEN0_LDMAXBAR;
  }
}

/**
 * @brief   Releases a DMA stream.
 * @details The stream is freed and, if required, the DMA clock disabled.
 *          Trying to release a unallocated stream is an illegal operation
 *          and is trapped if assertions are enabled.
 *
 * @param[in] dmastp    pointer to a efr32_dma_stream_t structure
 *
 * @api
 */
void dmaStreamFree(const efr32_dma_stream_t *dmastp) {

  osalSysLock();
  dmaStreamFreeI(dmastp);
  osalSysUnlock();
}

#endif /* EFR32_DMA_REQUIRED */

/** @} */

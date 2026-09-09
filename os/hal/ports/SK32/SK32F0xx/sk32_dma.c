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
 * @file    SK32F0xx/sk32_dma.c
 * @brief   DMA helper driver code.
 *
 * @addtogroup SK32F0xx_DMA
 * @details DMA sharing helper driver.  In the SK32 the DMA1 channels are a
 *          shared resource, this driver allows to allocate and free the DMA
 *          channels at runtime in order to allow all the other device
 *          drivers to coordinate the access to the resource.
 * @note    The DMA ISR handlers are all declared into this module because
 *          sharing, the various device drivers can associate a callback to
 *          ISRs when allocating streams.
 * @note    The SK32 DMA1 interrupts are aggregated on three NVIC vectors
 *          (channel 1 alone, channels 2-3, channels 4-6), the shared
 *          vectors are declared here and serve one channel at a time, the
 *          same approach used by the STM32F0xx port for its non-standard
 *          DMA shared IRQ handlers.
 * @note    This driver is compiled only if some driver requiring DMA
 *          services has been enabled, see @p SK32_DMA_REQUIRED.
 * @{
 */

#include "hal.h"

/* The following macro is only defined if some driver requiring DMA services
   has been enabled.*/
#if defined(SK32_DMA_REQUIRED) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Mask of the DMA1 streams in @p dma.allocated_mask.
 */
#define SK32_DMA1_STREAMS_MASK      ((1U << SK32_DMA1_NUM_CHANNELS) - 1U)

/*
 * Default ISR collision masks, only used if not overridden by the registry.
 */
#if !defined(SK32_DMA1_CH1_CMASK)
#define SK32_DMA1_CH1_CMASK         (1U << 0U)
#endif
#if !defined(SK32_DMA1_CH2_CMASK)
#define SK32_DMA1_CH2_CMASK         (1U << 1U)
#endif
#if !defined(SK32_DMA1_CH3_CMASK)
#define SK32_DMA1_CH3_CMASK         (1U << 2U)
#endif
#if !defined(SK32_DMA1_CH4_CMASK)
#define SK32_DMA1_CH4_CMASK         (1U << 3U)
#endif
#if !defined(SK32_DMA1_CH5_CMASK)
#define SK32_DMA1_CH5_CMASK         (1U << 4U)
#endif
#if !defined(SK32_DMA1_CH6_CMASK)
#define SK32_DMA1_CH6_CMASK         (1U << 5U)
#endif

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   DMA streams descriptors.
 * @details This table keeps the association between an unique stream
 *          identifier and the involved physical registers.
 * @note    Don't use this array directly, use the appropriate wrapper macros
 *          instead: @p SK32_DMA1_STREAM1, @p SK32_DMA1_STREAM2 etc.
 */
const sk32_dma_stream_t _sk32_dma_streams[SK32_DMA_STREAMS] = {
#if SK32_DMA1_NUM_CHANNELS > 0
  {DMA1, DMA1_Channel1, SK32_DMA1_CH1_CMASK, 0,  0, 0, SK32_DMA1_CH1_NUMBER},
#endif
#if SK32_DMA1_NUM_CHANNELS > 1
  {DMA1, DMA1_Channel2, SK32_DMA1_CH2_CMASK, 0,  4, 1, SK32_DMA1_CH2_NUMBER},
#endif
#if SK32_DMA1_NUM_CHANNELS > 2
  {DMA1, DMA1_Channel3, SK32_DMA1_CH3_CMASK, 0,  8, 2, SK32_DMA1_CH3_NUMBER},
#endif
#if SK32_DMA1_NUM_CHANNELS > 3
  {DMA1, DMA1_Channel4, SK32_DMA1_CH4_CMASK, 0, 12, 3, SK32_DMA1_CH4_NUMBER},
#endif
#if SK32_DMA1_NUM_CHANNELS > 4
  {DMA1, DMA1_Channel5, SK32_DMA1_CH5_CMASK, 0, 16, 4, SK32_DMA1_CH5_NUMBER},
#endif
#if SK32_DMA1_NUM_CHANNELS > 5
  {DMA1, DMA1_Channel6, SK32_DMA1_CH6_CMASK, 0, 20, 5, SK32_DMA1_CH6_NUMBER},
#endif
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
   * @brief   Mask of the enabled streams ISRs.
   */
  uint32_t          isr_mask;
  /**
   * @brief   DMA IRQ redirectors.
   */
  struct {
    /**
     * @brief   DMA callback function.
     */
    sk32_dmaisr_t    func;
    /**
     * @brief   DMA callback parameter.
     */
    void             *param;
  } streams[SK32_DMA_STREAMS];
} dma;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   DMA1 channel 1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_DMA1_CH1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  dmaServeInterrupt(SK32_DMA1_STREAM1);

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 channels 2 and 3 shared interrupt handler.
 * @note    It is declared here because this device has a non-standard
 *          DMA shared IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_DMA1_CH23_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 2.*/
  dmaServeInterrupt(SK32_DMA1_STREAM2);

  /* Check on channel 3.*/
  dmaServeInterrupt(SK32_DMA1_STREAM3);

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   DMA1 channels 4, 5 and 6 shared interrupt handler.
 * @note    It is declared here because this device has a non-standard
 *          DMA shared IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SK32_DMA1_CH456_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 4.*/
  dmaServeInterrupt(SK32_DMA1_STREAM4);

  /* Check on channel 5.*/
  dmaServeInterrupt(SK32_DMA1_STREAM5);

  /* Check on channel 6.*/
  dmaServeInterrupt(SK32_DMA1_STREAM6);

  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   SK32 DMA helper initialization.
 *
 * @init
 */
void dmaInit(void) {
  int i;

  dma.allocated_mask = 0U;
  dma.isr_mask       = 0U;
  for (i = 0; i < SK32_DMA_STREAMS; i++) {
    _sk32_dma_streams[i].channel->CCR = SK32_DMA_CCR_RESET_VALUE;
    dma.streams[i].func = NULL;
  }
  DMA1->IFCR = 0xFFFFFFFFU;
}

/**
 * @brief   Allocates a DMA stream.
 * @details The stream is allocated and, if required, the DMA clock enabled.
 *          The function also enables the IRQ vector associated to the stream
 *          and initializes its priority.
 *
 * @param[in] id        numeric identifier of a specific stream
 * @param[in] priority  IRQ priority for the DMA stream
 * @param[in] func      handling function pointer, can be @p NULL
 * @param[in] param     a parameter to be passed to the handling function
 * @return              Pointer to the allocated @p sk32_dma_stream_t
 *                      structure.
 * @retval NULL         if the stream is not available.
 *
 * @iclass
 */
const sk32_dma_stream_t *dmaStreamAllocI(uint32_t id,
                                         uint32_t priority,
                                         sk32_dmaisr_t func,
                                         void *param) {
  uint32_t mask;

  osalDbgCheckClassI();
  osalDbgCheck(SK32_DMA_IS_VALID_STREAM(id));
  osalDbgCheck(SK32_DMA_IS_VALID_PRIORITY(priority));

  mask = (1U << id);
  if ((dma.allocated_mask & mask) == 0U) {
    const sk32_dma_stream_t *dmastp = SK32_DMA_STREAM(id);

    /* Installs the DMA handler.*/
    dma.streams[id].func  = func;
    dma.streams[id].param = param;
    dma.allocated_mask   |= mask;

    /* Enabling DMA1 clock.*/
    if ((SK32_DMA1_STREAMS_MASK & mask) != 0U) {
      rccEnableDMA1(true);
    }

    /* Enables the associated IRQ vector if not already enabled and if a
       callback is defined.*/
    if (func != NULL) {
      if ((dma.isr_mask & dmastp->cmask) == 0U) {
        nvicEnableVector(dmastp->vector, priority);
      }
      dma.isr_mask |= mask;
    }

    /* Putting the stream in a known state.*/
    dmaStreamDisable(dmastp);
    dmastp->channel->CCR = SK32_DMA_CCR_RESET_VALUE;

    return dmastp;
  }

  return NULL;
}

/**
 * @brief   Allocates a DMA stream.
 * @details The stream is allocated and, if required, the DMA clock enabled.
 *          The function also enables the IRQ vector associated to the stream
 *          and initializes its priority.
 *
 * @param[in] id        numeric identifier of a specific stream
 * @param[in] priority  IRQ priority for the DMA stream
 * @param[in] func      handling function pointer, can be @p NULL
 * @param[in] param     a parameter to be passed to the handling function
 * @return              Pointer to the allocated @p sk32_dma_stream_t
 *                      structure.
 * @retval NULL         if the stream is not available.
 *
 * @api
 */
const sk32_dma_stream_t *dmaStreamAlloc(uint32_t id,
                                        uint32_t priority,
                                        sk32_dmaisr_t func,
                                        void *param) {
  const sk32_dma_stream_t *dmastp;

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
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 *
 * @iclass
 */
void dmaStreamFreeI(const sk32_dma_stream_t *dmastp) {
  uint32_t selfindex = (uint32_t)dmastp->selfindex;

  osalDbgCheck(dmastp != NULL);

  /* Check if the stream is not taken.*/
  osalDbgAssert((dma.allocated_mask & (1U << selfindex)) != 0U,
                "not allocated");

  /* Marks the stream as not allocated.*/
  dma.allocated_mask &= ~(1U << selfindex);
  dma.isr_mask &= ~(1U << selfindex);

  /* Disables the associated IRQ vector if it is no more in use.*/
  if ((dma.isr_mask & dmastp->cmask) == 0U) {
    nvicDisableVector(dmastp->vector);
  }

  /* Removes the DMA handler.*/
  dma.streams[selfindex].func  = NULL;
  dma.streams[selfindex].param = NULL;

  /* Shutting down the clock if it is no more required.*/
  if ((dma.allocated_mask & SK32_DMA1_STREAMS_MASK) == 0U) {
    rccDisableDMA1();
  }
}

/**
 * @brief   Releases a DMA stream.
 * @details The stream is freed and, if required, the DMA clock disabled.
 *          Trying to release a unallocated stream is an illegal operation
 *          and is trapped if assertions are enabled.
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 *
 * @api
 */
void dmaStreamFree(const sk32_dma_stream_t *dmastp) {

  osalSysLock();
  dmaStreamFreeI(dmastp);
  osalSysUnlock();
}

/**
 * @brief   Serves a DMA IRQ.
 *
 * @param[in] dmastp    pointer to a sk32_dma_stream_t structure
 *
 * @special
 */
void dmaServeInterrupt(const sk32_dma_stream_t *dmastp) {
  uint32_t flags;
  uint32_t selfindex = (uint32_t)dmastp->selfindex;

  flags = (dmastp->dma->ISR >> dmastp->shift) & SK32_DMA_ISR_MASK;
  if (flags & dmastp->channel->CCR) {
    dmastp->dma->IFCR = flags << dmastp->shift;
    if (dma.streams[selfindex].func) {
      dma.streams[selfindex].func(dma.streams[selfindex].param, flags);
    }
  }
}

#endif /* SK32_DMA_REQUIRED */

/** @} */

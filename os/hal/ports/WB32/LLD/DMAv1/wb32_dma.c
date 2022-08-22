/*
    Copyright (C) 2022 Westberry Technology (ChangZhou) Corp., Ltd

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
 * @file    DMAv1/wb32_dma.c
 * @brief   DMA helper driver code.
 *
 * @addtogroup WB32_DMA
 * @details DMA sharing helper driver. In the WB32 the DMA streams are a
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
#if defined(WB32_DMA_REQUIRED) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Mask of the DMA1 streams in @p dma_streams_mask.
 */
#define WB32_DMA1_STREAMS_MASK ((1U << WB32_DMAC1_NUM_CHANNELS) - 1U)

/**
 * @brief   Mask of the DMA2 streams in @p dma_streams_mask.
 */
#define WB32_DMA2_STREAMS_MASK (((1U << WB32_DMAC2_NUM_CHANNELS) - 1U)      \
                                << WB32_DMAC1_NUM_CHANNELS)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*
 * Default ISR collision masks.
 */
#if !defined(WB32_DMAC1_CH0_CMASK)
#define WB32_DMAC1_CH0_CMASK (1U << 0U)
#endif

#if !defined(WB32_DMAC1_CH1_CMASK)
#define WB32_DMAC1_CH1_CMASK (1U << 1U)
#endif

#if !defined(WB32_DMAC1_CH2_CMASK)
#define WB32_DMAC1_CH2_CMASK (1U << 2U)
#endif

#if !defined(WB32_DMAC2_CH0_CMASK)
#define WB32_DMAC2_CH0_CMASK (1U << (WB32_DMAC1_NUM_CHANNELS + 0U))
#endif

#if !defined(WB32_DMAC2_CH1_CMASK)
#define WB32_DMAC2_CH1_CMASK (1U << (WB32_DMAC1_NUM_CHANNELS + 1U))
#endif

#if !defined(WB32_DMAC2_CH2_CMASK)
#define WB32_DMAC2_CH2_CMASK (1U << (WB32_DMAC1_NUM_CHANNELS + 2U))
#endif

/**
 * @brief   DMA streams descriptors.
 * @details This table keeps the association between an unique stream
 *          identifier and the involved physical registers.
 * @note    Don't use this array directly, use the appropriate wrapper macros
 *          instead: @p WB32_DMA1_STREAM1, @p WB32_DMA1_STREAM2 etc.
 */
const wb32_dma_stream_t _WB32_DMAC_CHANNELS[WB32_DMAC_CHANNELS] = {
#if WB32_DMAC1_NUM_CHANNELS > 0
    {DMAC1, WB32_DMAC_CH0, WB32_DMAC1_CH0_CMASK, 0, WB32_DMAC1_NUMBER},
#endif
#if WB32_DMAC1_NUM_CHANNELS > 1
    {DMAC1, WB32_DMAC_CH1, WB32_DMAC1_CH1_CMASK, 1, WB32_DMAC1_NUMBER},
#endif
#if WB32_DMAC1_NUM_CHANNELS > 2
    {DMAC1, WB32_DMAC_CH2, WB32_DMAC1_CH2_CMASK, 2, WB32_DMAC1_NUMBER},
#endif
#if WB32_DMAC2_NUM_CHANNELS > 0
    {DMAC2, WB32_DMAC_CH0, WB32_DMAC2_CH0_CMASK, 0 + WB32_DMAC1_NUM_CHANNELS, WB32_DMAC2_NUMBER},
#endif
#if WB32_DMAC2_NUM_CHANNELS > 1
    {DMAC2, WB32_DMAC_CH1, WB32_DMAC2_CH1_CMASK, 1 + WB32_DMAC1_NUM_CHANNELS, WB32_DMAC2_NUMBER},
#endif
#if WB32_DMAC2_NUM_CHANNELS > 2
    {DMAC2, WB32_DMAC_CH2, WB32_DMAC2_CH2_CMASK, 2 + WB32_DMAC1_NUM_CHANNELS, WB32_DMAC2_NUMBER},
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
  uint32_t allocated_mask;
  /**
   * @brief   Mask of the enabled streams ISRs.
   */
  uint32_t isr_mask;
  /**
   * @brief   DMA IRQ redirectors.
   */
  struct {
    /**
     * @brief   DMA callback function.
     */
    wb32_dmaisr_t func;
    /**
     * @brief   DMA callback parameter.
     */
    void *param;
  } streams[WB32_DMAC_CHANNELS];
} dma;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(WB32_DMAC1_IRQ_VECTOR) || defined(__DOXYGEN__)
/**
 * @brief   DMA1 stream x shared ISR.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(WB32_DMAC1_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();

#if WB32_DMAC1_NUM_CHANNELS > 0
  dmaServeInterrupt(WB32_DMA1_STREAM1);
#endif

#if WB32_DMAC1_NUM_CHANNELS > 1
  dmaServeInterrupt(WB32_DMA1_STREAM2);
#endif

#if WB32_DMAC1_NUM_CHANNELS > 2
  dmaServeInterrupt(WB32_DMA1_STREAM3);
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

#if defined(WB32_DMAC2_IRQ_VECTOR) || defined(__DOXYGEN__)
/**
 * @brief   DMA2 stream x shared ISR.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(WB32_DMAC2_IRQ_VECTOR) {

  OSAL_IRQ_PROLOGUE();

#if WB32_DMAC2_NUM_CHANNELS > 0
  dmaServeInterrupt(WB32_DMA2_STREAM1);
#endif

#if WB32_DMAC2_NUM_CHANNELS > 0
  dmaServeInterrupt(WB32_DMA2_STREAM2);
#endif

#if WB32_DMAC2_NUM_CHANNELS > 0
  dmaServeInterrupt(WB32_DMA2_STREAM3);
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   WB32 DMA helper initialization.
 *
 * @init
 */
void dmaInit(void) {
  int i;

  dma.allocated_mask = 0U;
  dma.isr_mask = 0U;

#if WB32_DMAC2_NUM_CHANNELS > 0
  rccResetDMAC1();
#endif
#if WB32_DMAC2_NUM_CHANNELS > 0
  rccResetDMAC2();
#endif

  for (i = 0; i < WB32_DMAC_CHANNELS; i++) {
    dma.streams[i].func = NULL;
  }
}

/**
 * @brief   Allocates a DMA stream.
 * @details The stream is allocated and, if required, the DMA clock enabled.
 *          The function also enables the IRQ vector associated to the stream
 *          and initializes its priority.
 *
 * @param[in] id        numeric identifiers of a specific stream or:
 *                      - @p WB32_DMA_STREAM_ID_ANY for any stream.
 *                      - @p WB32_DMA_STREAM_ID_ANY_DMA1 for any stream
 *                        on DMA1.
 *                      - @p WB32_DMA_STREAM_ID_ANY_DMA2 for any stream
 *                        on DMA2.
 *                      .
 * @param[in] priority  IRQ priority for the DMA stream
 * @param[in] func      handling function pointer, can be @p NULL
 * @param[in] param     a parameter to be passed to the handling function
 * @return              Pointer to the allocated @p wb32_dma_stream_t
 *                      structure.
 * @retval NULL         if a/the stream is not available.
 *
 * @iclass
 */
const wb32_dma_stream_t *dmaStreamAllocI(uint32_t id,
                                         uint32_t priority,
                                         wb32_dmaisr_t func,
                                         void *param) {
  uint32_t i, startid, endid;

  osalDbgCheckClassI();

  if (id < WB32_DMAC_CHANNELS) {
    startid = id;
    endid = id;
  } else {
    osalDbgCheck(false);
    return NULL;
  }

  for (i = startid; i <= endid; i++) {
    uint32_t mask = (1U << i);

    if ((dma.allocated_mask & mask) == 0U) {
      const wb32_dma_stream_t *dmastp = WB32_DMA_STREAM(i);

      /* Installs the DMA handler.*/
      dma.streams[i].func = func;
      dma.streams[i].param = param;
      dma.allocated_mask |= mask;

      /* Enabling DMA clocks required by the current streams set.*/
      if ((WB32_DMA1_STREAMS_MASK & mask) != 0U) {
        /* Enable DMAC1 clock */
        rccEnableDMAC1();
        /* DMAC1 DeInit  */
        rccResetDMAC1();
      }
#if WB32_DMAC2_NUM_CHANNELS > 0
      if ((WB32_DMA2_STREAMS_MASK & mask) != 0U) {
        /* Enable DMAC2 clock */
        rccEnableDMAC2();
        /* DMAC2 DeInit */
        rccResetDMAC2();
      }
#endif

      /* enable dmac */
      dmastp->dmac->DmaCfgReg = 0x01;

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
 *                      - @p WB32_DMA_STREAM_ID_ANY for any stream.
 *                      - @p WB32_DMA_STREAM_ID_ANY_DMA1 for any stream
 *                        on DMA1.
 *                      - @p WB32_DMA_STREAM_ID_ANY_DMA2 for any stream
 *                        on DMA2.
 *                      .
 * @param[in] priority  IRQ priority for the DMA stream
 * @param[in] func      handling function pointer, can be @p NULL
 * @param[in] param     a parameter to be passed to the handling function
 * @return              Pointer to the allocated @p wb32_dma_stream_t
 *                      structure.
 * @retval NULL         if a/the stream is not available.
 *
 * @api
 */
const wb32_dma_stream_t *dmaStreamAlloc(uint32_t id,
                                        uint32_t priority,
                                        wb32_dmaisr_t func,
                                        void *param) {
  const wb32_dma_stream_t *dmastp;

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
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 *
 * @iclass
 */
void dmaStreamFreeI(const wb32_dma_stream_t *dmastp) {
  uint32_t selfindex = (uint32_t)dmastp->selfindex;

  osalDbgCheck(dmastp != NULL);

  /* Check if the streams is not taken.*/
  osalDbgAssert((dma.allocated_mask & (1 << selfindex)) != 0U,
                "not allocated");

  /* Marks the stream as not allocated.*/
  dma.allocated_mask &= ~(1U << selfindex);
  dma.isr_mask &= ~(1U << selfindex);

  /* Disables the associated IRQ vector if it is no more in use.*/
  if ((dma.isr_mask & dmastp->cmask) == 0U) {
    nvicDisableVector(dmastp->vector);
  }

  /* Removes the DMA handler.*/
  dma.streams[selfindex].func = NULL;
  dma.streams[selfindex].param = NULL;

  /* Shutting down clocks that are no more required, if any.*/
  if ((dma.allocated_mask & WB32_DMA1_STREAMS_MASK) == 0U) {
    /* Disable DMAC1 clock */
    rccDisableDMAC1();
  }
#if WB32_DMAC2_NUM_CHANNELS > 0
  if ((dma.allocated_mask & WB32_DMA2_STREAMS_MASK) == 0U) {
    /* Disable DMAC2 clock */
    rccDisableDMAC2();
  }
#endif
}

/**
 * @brief   Releases a DMA stream.
 * @details The stream is freed and, if required, the DMA clock disabled.
 *          Trying to release a unallocated stream is an illegal operation
 *          and is trapped if assertions are enabled.
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 *
 * @api
 */
void dmaStreamFree(const wb32_dma_stream_t *dmastp) {

  osalSysLock();
  dmaStreamFreeI(dmastp);
  osalSysUnlock();
}

/**
 * @brief   Serves a DMA IRQ.
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 *
 * @special
 */
void dmaServeInterrupt(const wb32_dma_stream_t *dmastp) {
  uint32_t IT_flag;
  uint32_t selfindex = (uint32_t)dmastp->selfindex;
  uint32_t mask = (uint32_t)(0x01U << ((dmastp)->channel));
  uint32_t regaddr = ((uint32_t)(&((dmastp)->dmac->StatusTfr)) + WB32_DMAC_IT_TFR);

  if ((*((__I uint32_t *)(regaddr))) & mask) {
    IT_flag = WB32_DMAC_IT_STATE_TFR;
    if (dma.streams[selfindex].func) {
       dma.streams[selfindex].func(dma.streams[selfindex].param, IT_flag);
    }
  }

  regaddr = ((uint32_t)(&((dmastp)->dmac->StatusTfr)) + WB32_DMAC_IT_BLOCK);

  if ((*((__I uint32_t *)(regaddr))) & mask) {
    IT_flag = WB32_DMAC_IT_STATE_BLOCK;
    if (dma.streams[selfindex].func) {
      dma.streams[selfindex].func(dma.streams[selfindex].param, IT_flag);
    }
  }

  regaddr = ((uint32_t)(&((dmastp)->dmac->StatusTfr)) + WB32_DMAC_IT_SRCTRAN);

  if ((*((__I uint32_t *)(regaddr))) & mask) {
    IT_flag = WB32_DMAC_IT_STATE_SRCTRAN;
    if (dma.streams[selfindex].func) {
      dma.streams[selfindex].func(dma.streams[selfindex].param, IT_flag);
    }
  }

  regaddr = ((uint32_t)(&((dmastp)->dmac->StatusTfr)) + WB32_DMAC_IT_DSTTRAN);

  if ((*((__I uint32_t *)(regaddr))) & mask) {
    IT_flag = WB32_DMAC_IT_STATE_DSTTRAN;
    if (dma.streams[selfindex].func) {
      dma.streams[selfindex].func(dma.streams[selfindex].param, IT_flag);
    }
  }

  regaddr = ((uint32_t)(&((dmastp)->dmac->StatusTfr)) + WB32_DMAC_IT_ERR);

  if ((*((__I uint32_t *)(regaddr))) & mask) {
    IT_flag = WB32_DMAC_IT_STATE_ERR;
    if (dma.streams[selfindex].func) {
      dma.streams[selfindex].func(dma.streams[selfindex].param, IT_flag);
    }
  }
  
  dmaStreamClearInterrupt(dmastp);
}

#endif /* WB32_DMA_REQUIRED */

/** @} */

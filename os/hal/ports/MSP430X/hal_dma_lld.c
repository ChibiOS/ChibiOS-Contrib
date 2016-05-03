/*
    ChibiOS - Copyright (C) 2016 Andrew Wygle aka awygle

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
 * @file    MSP430X hal_dma_lld.c
 * @brief   MSP430X DMA subsystem low level driver source.
 *
 * @addtogroup MSP430X_DMA
 * @{
 */

#include "hal.h"
#include "ch.h"
#include "hal_dma_lld.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/* TODO make sure this is right... */
static msp430x_dma_ch_reg_t * const dma_channels = (msp430x_dma_ch_reg_t *)&DMA0CTL;
static uint8_t * const dma_ctls = (uint8_t *)&DMACTL0;

static msp430x_dma_cb_t callbacks[MSP430X_DMA_CHANNELS];
#if CH_CFG_USE_SEMAPHORES
static semaphore_t dma_lock;
#endif

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void init_request(const msp430x_dma_req_t * request, uint8_t index) {
  
    dma_ctls[index] = request->trigger;
    callbacks[index] = request->callback;
    msp430x_dma_ch_reg_t * ch = &dma_channels[index];
    ch->sa = (uintptr_t)request->source_addr;
    ch->da = (uintptr_t)request->dest_addr;
    ch->sz = request->size;
    ch->ctl = DMAREQ | DMAIE | DMAEN | request->data_mode | request->addr_mode
      | request->transfer_mode; 
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

PORT_IRQ_HANDLER(DMA_VECTOR) {
  uint8_t index;
  OSAL_IRQ_PROLOGUE();
  
  index = (DMAIV >> 1) - 1;
  
  if (index < MSP430X_DMA_CHANNELS) {
    msp430x_dma_cb_t * cb = &callbacks[index];
    
    /* WARNING: CALLBACKS ARE CALLED IN AN ISR CONTEXT! */
    if (cb->callback != NULL) {
      cb->callback(cb->args);
    }
  
  } 
  
  OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief Initialize the DMA engine.
 * 
 * @init
 */
void dmaInit(void) {
#if CH_CFG_USE_SEMAPHORES
  chSemObjectInit(&dma_lock, MSP430X_DMA_CHANNELS);
#endif
}

/**
 * @brief   Requests a DMA transfer operation from the DMA engine.
 * @note    The DMA engine uses unclaimed DMA channels to provide DMA services
 *          for one-off or infrequent uses. If all channels are busy, and
 *          semaphores are enabled, the calling thread will sleep until a
 *          channel is available or the request times out. If semaphores are
 *          disabled, the calling thread will busy-wait instead of sleeping.
 */
bool dmaRequest(msp430x_dma_req_t * request, systime_t timeout) {
  /* Check if a DMA channel is available */
#if CH_CFG_USE_SEMAPHORES
  msg_t semresult = chSemWaitTimeout(&dma_lock, timeout);
  if (semresult != MSG_OK)
    return true;
#endif
  
#if !(CH_CFG_USE_SEMAPHORES)
  systime_t start = chVTGetSystemTimeX();
  
  do {
#endif
  /* Grab the correct DMA channel to use */
  int i = 0;
  for (i = 0; i < MSP430X_DMA_CHANNELS; i++) {
    if (!(dma_channels[i].ctl & DMAEN)) {
      break;
    }
  }
#if !(CH_CFG_USE_SEMAPHORES)
  while (chVTTimeElapsedSinceX(start) < timeout);
#endif
  
#if !(CH_CFG_USE_SEMAPHORES)
  if (i == MSP430X_DMA_CHANNELS) {
    return true;
  }
#endif
  
  /* Make the request */
  init_request(request, i);
  
#if CH_CFG_USE_SEMAPHORES
  chSemSignal(&dma_lock);
#endif
  
  return false;
}

/**
 * @brief   Acquires exclusive control of a DMA channel.
 * @pre     The channel must not be already acquired or an error is returned.
 * @note    If the channel is in use by the DMA engine, blocks until acquired.
 * @post    This channel must be interacted with using only the functions 
 *          defined in this module.
 *          
 * @param[out] channel    The channel handle. Must be pre-allocated.
 * @param[in]  index      The index of the channel (< MSP430X_DMA_CHANNELS).
 * @return                The operation status.
 * @retval false          no error, channel acquired.
 * @retval true           error, channel already acquired.
 */
bool dmaAcquire(msp430x_dma_ch_t * channel, uint8_t index) {
  /* Acquire the channel in an idle mode */
  
  /* Is the channel already acquired? */
  osalDbgAssert(index < MSP430X_DMA_CHANNELS, "invalid channel index");
  if (dma_channels[index].ctl & DMADT_4) {
    return true;
  }
  
  /* Increment the DMA counter */
#if CH_CFG_USE_SEMAPHORES
  msg_t semresult = chSemWait(&dma_lock);
  if (semresult != MSG_OK)
    return true;
#endif
  
  while (dma_channels[index].ctl & DMAEN) ;
  
  dma_ctls[index] = DMA_TRIGGER_MNEM(DMAREQ);
  dma_channels[index].sz = 0;
  dma_channels[index].ctl = DMAEN | DMAABORT | DMADT_4;
  
  channel->registers = dma_channels + index;
  channel->ctl = dma_ctls + index;
  channel->cb = callbacks + index;
  
  return false;
}

/**
 * @brief   Initiates a DMA transfer operation using an acquired channel.
 * @pre     The channel must have been acquired using @p dmaAcquire().
 * 
 * @param[in] channel   pointer to a DMA channel from @p dmaAcquire().
 * @param[in] request   pointer to a DMA request object.
 */
void dmaTransfer(msp430x_dma_ch_t * channel, msp430x_dma_req_t * request) {
  
    *(channel->ctl) = request->trigger;
    
    channel->cb->callback = request->callback.callback;
    channel->cb->args = request->callback.args;
    
    chSysLock();
    channel->registers->ctl &= (~DMAEN);
    channel->registers->sa = (uintptr_t)request->source_addr;
    channel->registers->da = (uintptr_t)request->dest_addr;
    channel->registers->sz = request->size;
    channel->registers->ctl = DMAIE | request->data_mode | request->addr_mode
      | request->transfer_mode | DMADT_4 | DMAEN | DMAREQ; /* repeated transfers */
    chSysUnlock();
}

/**
 * @brief   Releases exclusive control of a DMA channel.
 * @details The channel is released from control and returned to the DMA engine
 *          pool. Trying to release an unallocated channel is an illegal
 *          operation and is trapped if assertions are enabled.
 * @pre     The channel must have been acquired using @p dmaAcquire().
 * @post    The channel is returned to the DMA engine pool.
 */
void dmaRelease(msp430x_dma_ch_t * channel) {
  
  osalDbgCheck(channel != NULL);
  osalDbgAssert(channel->registers->ctl & DMADT_4, "not acquired");
  
  /* Release the channel in an idle mode */
  channel->registers->ctl = DMAABORT;
  
  /* release the DMA counter */
#if CH_CFG_USE_SEMAPHORES
  chSemSignal(&dma_lock);
#endif
}

/** @} */

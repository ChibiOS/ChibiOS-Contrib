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
 * @file    DMAv1/wb32_dma.h
 * @brief   DMA helper driver header.
 *
 * @addtogroup WB32_DMA
 * @{
 */

#ifndef WB32_DMA_H
#define WB32_DMA_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Total number of DMA streams.
 * @details This is the total number of streams among all the DMA units.
 */
#define WB32_DMAC_CHANNELS (WB32_DMAC1_NUM_CHANNELS +                       \
                            WB32_DMAC2_NUM_CHANNELS)

/**
 * @brief   Mask of the ISR bits passed to the DMA callback functions.
 */
#define WB32_DMA_ISR_MASK 0x0E

/**
 * @brief   Returns the request line associated to the specified stream.
 *
 * @param[in] id        the unique numeric stream identifier
 * @param[in] c         a stream/request association word, one request per
 *                      nibble
 * @return              Returns the request associated to the stream.
 */
#define WB32_DMA_GETCHANNEL(id, c)                                          \
  (((uint32_t)(c) >> (((uint32_t)(id) % (uint32_t)WB32_DMAC1_NUM_CHANNELS) * 4U)) & 15U)

/**
 * @brief   Checks if a DMA priority is within the valid range.
 * @param[in] prio      DMA priority
 *
 * @retval              The check result.
 * @retval false        invalid DMA priority.
 * @retval true         correct DMA priority.
 */
#define WB32_DMA_IS_VALID_PRIORITY(prio) (((prio) >= 0U) && ((prio) <= 7U))

/**
 * @brief   Checks if a DMA stream id is within the valid range.
 *
 * @param[in] id        DMA stream id
 * @retval              The check result.
 * @retval false        invalid DMA channel.
 * @retval true         correct DMA channel.
 */
#define WB32_DMA_IS_VALID_STREAM(id) (((id) >= 0U) &&                       \
                                      ((id) < WB32_DMAC_CHANNELS))

/**
 * @brief   Returns an unique numeric identifier for a DMA stream.
 *
 * @param[in] dma       the DMA unit number
 * @param[in] stream    the stream number
 * @return              An unique numeric stream identifier.
 */
#define WB32_DMA_STREAM_ID(dma, stream)                                     \
  ((((dma)-1) * WB32_DMAC1_NUM_CHANNELS) + (stream))

/**
 * @brief   Returns a DMA stream identifier mask.
 *
 *
 * @param[in] dma       the DMA unit number
 * @param[in] stream    the stream number
 * @return              A DMA stream identifier mask.
 */
#define WB32_DMA_STREAM_ID_MSK(dma, stream)                                 \
  (1U << WB32_DMA_STREAM_ID(dma, stream))

/**
 * @brief   Checks if a DMA stream unique identifier belongs to a mask.
 *
 * @param[in] id        the stream numeric identifier
 * @param[in] mask      the stream numeric identifiers mask
 *
 * @retval              The check result.
 * @retval false        id does not belong to the mask.
 * @retval true         id belongs to the mask.
 */
#define WB32_DMA_IS_VALID_ID(id, mask) (((1U << (id)) & (mask)))

/**
 * @name    DMA streams identifiers
 * @{
 */
/**
 * @brief   Returns a pointer to a wb32_dma_stream_t structure.
 *
 * @param[in] id        the stream numeric identifier
 * @return              A pointer to the wb32_dma_stream_t constant structure
 *                      associated to the DMA stream.
 */
#define WB32_DMA_STREAM(id) (&_WB32_DMAC_CHANNELS[id])

#if WB32_DMAC1_NUM_CHANNELS > 0
#define WB32_DMA1_STREAM1 WB32_DMA_STREAM(0)
#endif
#if WB32_DMAC1_NUM_CHANNELS > 1
#define WB32_DMA1_STREAM2 WB32_DMA_STREAM(1)
#endif
#if WB32_DMAC1_NUM_CHANNELS > 2
#define WB32_DMA1_STREAM3 WB32_DMA_STREAM(2)
#endif
#if WB32_DMAC2_NUM_CHANNELS > 0
#define WB32_DMA2_STREAM1 WB32_DMA_STREAM(WB32_DMAC1_NUM_CHANNELS + 0)
#endif
#if WB32_DMAC2_NUM_CHANNELS > 1
#define WB32_DMA2_STREAM2 WB32_DMA_STREAM(WB32_DMAC1_NUM_CHANNELS + 1)
#endif
#if WB32_DMAC2_NUM_CHANNELS > 2
#define WB32_DMA2_STREAM3 WB32_DMA_STREAM(WB32_DMAC1_NUM_CHANNELS + 2)
#endif
/** @} */

/** @defgroup DMAC_Interrupt 
  * @{
  */
#define WB32_DMAC_INTERRUPT_EN                               (0x1U << 0)
#define WB32_DMAC_INTERRUPT_DIS                              (0x0U << 0)
/**
  * @}
  */

/** @defgroup DMAC_DestinationTransferWidth 
  * @{
  */
#define WB32_DMAC_DST_WIDTH_BYTE                             (0x0U << 1)
#define WB32_DMAC_DST_WIDTH_HWORD                            (0x1U << 1)
#define WB32_DMAC_DST_WIDTH_WORD                             (0x2U << 1)
/**
  * @}
  */

/** @defgroup DMAC_SourceTransferWidth 
  * @{
  */
#define WB32_DMAC_SRC_WIDTH_BYTE                             (0x0U << 4)
#define WB32_DMAC_SRC_WIDTH_HWORD                            (0x1U << 4)
#define WB32_DMAC_SRC_WIDTH_WORD                             (0x2U << 4)
/**
  * @}
  */

/** @defgroup DMAC_DestinationAddrInc 
  * @{
  */
#define WB32_DMAC_DST_ADDR_INC                               (0x0U << 7)
#define WB32_DMAC_DST_ADDR_DEC                               (0x1U << 7)
#define WB32_DMAC_DST_ADDR_NOC                               (0x2U << 7)
/**
  * @}
  */

/** @defgroup DMAC_SourceAddrInc 
  * @{
  */
#define WB32_DMAC_SRC_ADDR_INC                               (0x0U << 9)
#define WB32_DMAC_SRC_ADDR_DEC                               (0x1U << 9)
#define WB32_DMAC_SRC_ADDR_NOC                               (0x2U << 9)
/**
  * @}
  */

/** @defgroup DMAC_DestinationTransactionLength 
  * @{
  */
#define WB32_DMAC_DST_TRS_LEN_1                              (0x0U << 11)
#define WB32_DMAC_DST_TRS_LEN_4                              (0x1U << 11)
#define WB32_DMAC_DST_TRS_LEN_8                              (0x2U << 11)
/**
  * @}
  */

/** @defgroup DMAC_SourceTransactionLength 
  * @{
  */
#define WB32_DMAC_SRC_TRS_LEN_1                              (0x0U << 14)
#define WB32_DMAC_SRC_TRS_LEN_4                              (0x1U << 14)
#define WB32_DMAC_SRC_TRS_LEN_8                              (0x2U << 14)
/**
  * @}
  */

/** @defgroup DMAC_TransferTypeAndFlowControl 
  * @{
  */
#define WB32_DMAC_TRF_TFC_M2MD                               (0x0U << 20)
#define WB32_DMAC_TRF_TFC_M2PD                               (0x1U << 20)
#define WB32_DMAC_TRF_TFC_P2MD                               (0x2U << 20)
#define WB32_DMAC_TRF_TFC_P2PD                               (0x3U << 20)
/* The following definitions is only used for DMACx channel0. */
#define WB32_DMAC_TRF_TFC_P2MP                               (0x4U << 20)
#define WB32_DMAC_TRF_TFC_P2PSP                              (0x5U << 20)
#define WB32_DMAC_TRF_TFC_M2PP                               (0x6U << 20)
#define WB32_DMAC_TRF_TFC_P2PDP                              (0x7U << 20)
/**
  * @}
  */

/** @defgroup DMAC_DestinationMasterInterface 
  * @{
  */
#define WB32_DMAC_SRC_MASTER_IF_APB                          (0x0U << 25)
#define WB32_DMAC_SRC_MASTER_IF_AHB                          (0x1U << 25)
/**
  * @}
  */

/** @defgroup DMAC_SourceMasterInterface 
  * @{
  */
#define WB32_DMAC_DST_MASTER_IF_APB                          (0x0U << 23)
#define WB32_DMAC_DST_MASTER_IF_AHB                          (0x1U << 23)
/**
  * @}
  */

/** @defgroup DMAC_SourceHandshakingInterfaceSelect 
  * @{
  */
#define WB32_DMAC_SRC_HIFS_HW                                (0x0U << 11)
#define WB32_DMAC_SRC_HIFS_SW                                (0x1U << 11)
/**
  * @}
  */

/** @defgroup DMAC_DestinationHandshakingInterfaceSelect 
  * @{
  */
#define WB32_DMAC_DST_HIFS_HW                                (0x0U << 10)
#define WB32_DMAC_DST_HIFS_SW                                (0x1U << 10)
/**
  * @}
  */

/** @defgroup DMAC_SourceHandshakingInterfacePolarity 
  * @{
  */
#define WB32_DMAC_SRC_HIFP_HIGH                              (0x0U << 19)
#define WB32_DMAC_SRC_HIFP_LOW                               (0x1U << 19)
/**
  * @}
  */

/** @defgroup DMAC_DestinationHandshakingInterfacePolarity 
  * @{
  */
#define WB32_DMAC_DST_HIFP_HIGH                              (0x0U << 18)
#define WB32_DMAC_DST_HIFP_LOW                               (0x1U << 18)
/**
  * @}
  */

/** @defgroup DMAC_AutomaticSourceReload 
  * @{
  */
#define WB32_DMAC_SRC_AUTO_RELOAD_EN                         (0x1U << 30)
#define WB32_DMAC_SRC_AUTO_RELOAD_DIS                        (0x0U << 30)
/**
  * @}
  */

/** @defgroup DMAC_AutomaticDestinationReload 
  * @{
  */
#define WB32_DMAC_DST_AUTO_RELOAD_EN                         (0x1U << 31)
#define WB32_DMAC_DST_AUTO_RELOAD_DIS                        (0x0U << 30)
/**
  * @}
  */

/** @defgroup DMAC_FlowControlMode 
  * @{
  */
#define WB32_DMAC_FC_MODE0                                   (0x0U << 0)
#define WB32_DMAC_FC_MODE1                                   (0x1U << 0)
/**
  * @}
  */

/** @defgroup DMAC_FIFOMode 
  * @{
  */
#define WB32_DMAC_FIFO_MODE0                                 (0x0U << 1)
#define WB32_DMAC_FIFO_MODE1                                 (0x1U << 1)
/**
  * @}
  */

/** @defgroup DMAC_interrupts_definitions 
  * @{
  */
#define WB32_DMAC_IT_TFR                                     (0x0U << 3)
#define WB32_DMAC_IT_BLOCK                                   (0x1U << 3)
#define WB32_DMAC_IT_SRCTRAN                                 (0x2U << 3)
#define WB32_DMAC_IT_DSTTRAN                                 (0x3U << 3)
#define WB32_DMAC_IT_ERR                                     (0x4U << 3)

/** @defgroup DMAC_interrupts_states_definitions 
  * @{
  */
#define WB32_DMAC_IT_STATE_TFR                               (0x1U << 0)
#define WB32_DMAC_IT_STATE_BLOCK                             (0x1U << 1)
#define WB32_DMAC_IT_STATE_SRCTRAN                           (0x1U << 2)
#define WB32_DMAC_IT_STATE_DSTTRAN                           (0x1U << 3)
#define WB32_DMAC_IT_STATE_ERR                               (0x1U << 4)
/**
  * @}
  */

/** @defgroup DMAC_channel 
  * @{
  */
#define WB32_DMAC_CH0                                        (0x0U << 0)
#define WB32_DMAC_CH1                                        (0x0U << 1)
#define WB32_DMAC_CH2                                        (0x0U << 2)
/**
  * @}
  */

/** @defgroup DMAC_HardwareHandshakingInterface 
  * @{
  */
/* The following definitions is only used for DMAC1. */
#define WB32_DMAC_HWHIF_TIM1_UP                              2
#define WB32_DMAC_HWHIF_TIM1_COM                             1
#define WB32_DMAC_HWHIF_TIM1_CH1                             0
#define WB32_DMAC_HWHIF_TIM1_CH2                             6
#define WB32_DMAC_HWHIF_TIM1_CH3                             3
#define WB32_DMAC_HWHIF_TIM1_CH4                             1
#define WB32_DMAC_HWHIF_TIM1_TRIG                            1

#define WB32_DMAC_HWHIF_TIM2_UP                              0
#define WB32_DMAC_HWHIF_TIM2_CH1                             2
#define WB32_DMAC_HWHIF_TIM2_CH2                             5
#define WB32_DMAC_HWHIF_TIM2_CH3                             4
#define WB32_DMAC_HWHIF_TIM2_CH4                             5

#define WB32_DMAC_HWHIF_TIM3_UP                              6
#define WB32_DMAC_HWHIF_TIM3_CH1                             3
#define WB32_DMAC_HWHIF_TIM3_CH3                             0
#define WB32_DMAC_HWHIF_TIM3_CH4                             6
#define WB32_DMAC_HWHIF_TIM3_TRIG                            3

#define WB32_DMAC_HWHIF_TIM4_UP                              5
#define WB32_DMAC_HWHIF_TIM4_CH1                             4
#define WB32_DMAC_HWHIF_TIM4_CH2                             1
#define WB32_DMAC_HWHIF_TIM4_CH3                             2

#define WB32_DMAC_HWHIF_QSPI_RX                              7
#define WB32_DMAC_HWHIF_QSPI_TX                              8
#define WB32_DMAC_HWHIF_SPIS1_RX                             9
#define WB32_DMAC_HWHIF_SPIS1_TX                             10
#define WB32_DMAC_HWHIF_UART1_RX                             11
#define WB32_DMAC_HWHIF_UART1_TX                             12
#define WB32_DMAC_HWHIF_ADC_Regular                          13
#define WB32_DMAC_HWHIF_ADC_Injected                         14

/* The following definitions is only used for DMAC2. */
#define WB32_DMAC_HWHIF_SPIM2_RX                             0
#define WB32_DMAC_HWHIF_SPIM2_TX                             1
#define WB32_DMAC_HWHIF_SPIS2_RX                             2
#define WB32_DMAC_HWHIF_SPIS2_TX                             3
#define WB32_DMAC_HWHIF_UART2_RX                             4
#define WB32_DMAC_HWHIF_UART2_TX                             5
#define WB32_DMAC_HWHIF_UART3_RX                             6
#define WB32_DMAC_HWHIF_UART3_TX                             7
#define WB32_DMAC_HWHIF_I2C1_RX                              8
#define WB32_DMAC_HWHIF_I2C1_TX                              9
#define WB32_DMAC_HWHIF_I2C2_RX                              10
#define WB32_DMAC_HWHIF_I2C2_TX                              11
/**
  * @}
  */

/** @defgroup DMAC configuration parameters for use simple config. 
  * @{
  */
#define WB32_DMA_CHCFG_SIZE_MASK                             (0x1FFU)
#define WB32_DMA_CHCFG_EN                                    (0x01U << 0)
#define WB32_DMA_CHCFG_TCIE                                  (0x01U << 1)
#define WB32_DMA_CHCFG_HTIE                                  (0x01U << 2)
#define WB32_DMA_CHCFG_TEIE                                  (0x01U << 3)
#define WB32_DMA_CHCFG_DIR_MASK                              (0x03U << 4)
#define WB32_DMA_CHCFG_DIR_M2M                               (0x00U << 4)
#define WB32_DMA_CHCFG_DIR_M2P                               (0x01U << 4)
#define WB32_DMA_CHCFG_DIR_P2M                               (0x02U << 4)
#define WB32_DMA_CHCFG_CIRC                                  (0x01U << 6)
#define WB32_DMA_CHCFG_PINC                                  (0x01U << 7)
#define WB32_DMA_CHCFG_MINC                                  (0x01U << 8)
#define WB32_DMA_CHCFG_PSIZE_MASK                            (0x03U << 9)
#define WB32_DMA_CHCFG_PSIZE_BYTE                            (0x00U << 9)
#define WB32_DMA_CHCFG_PSIZE_HWORD                           (0x01U << 9)
#define WB32_DMA_CHCFG_PSIZE_WORD                            (0x02U << 9)
#define WB32_DMA_CHCFG_MSIZE_MASK                            (0x03U << 11)
#define WB32_DMA_CHCFG_MSIZE_BYTE                            (0x00U << 11)
#define WB32_DMA_CHCFG_MSIZE_HWORD                           (0x01U << 11)
#define WB32_DMA_CHCFG_MSIZE_WORD                            (0x02U << 11)
#define WB32_DMA_CHCFG_PL_MASK                               (0x07U << 13)
#define WB32_DMA_CHCFG_PL(n)                                 ((n) << 13)
#define WB32_DMA_CHCFG_HWHIF_MASK                            (0xFFU << 16)
#define WB32_DMA_CHCFG_HWHIF(n)                              ((n) << 16)
/**
  * @}
  */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(WB32_DMAC1_NUM_CHANNELS)
#error "WB32_DMAC1_NUM_CHANNELS not defined in registry"
#endif

#if !defined(WB32_DMAC2_NUM_CHANNELS)
#error "WB32_DMAC2_NUM_CHANNELS not defined in registry"
#endif

#if (WB32_DMAC1_NUM_CHANNELS < 0) || (WB32_DMAC1_NUM_CHANNELS > 3)
#error "unsupported channels configuration"
#endif

#if (WB32_DMAC2_NUM_CHANNELS < 0) || (WB32_DMAC2_NUM_CHANNELS > 3)
#error "unsupported channels configuration"
#endif

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
typedef void (*wb32_dmaisr_t)(void *p, uint32_t flags);

/**
 * @brief   WB32 DMA stream descriptor structure.
 */
typedef struct {
  DMAC_TypeDef       *dmac;            /**< @brief Associated DMA.         */
  uint8_t            channel;          /**< @brief Associated DMA channel. */
  uint32_t           cmask;            /**< @brief Mask of streams sharing
                                            the same ISR. */
  uint8_t            selfindex;        /**< @brief Index to self in array. */
  uint8_t            vector;           /**< @brief Associated IRQ vector.  */
} wb32_dma_stream_t;

/**
 * @brief   WB32 DMA channel configuration structure.
 */
typedef struct {
  uint32_t           dst_addr;         /**< @brief Set the destination base address. */
  uint32_t           src_addr;         /**< @brief Set the source base address. */
  uint32_t           interrupt;        /**< @brief Set the channel interrupt is enable
                                            or not. */
  uint32_t           dst_width;        /**< @brief Set the destination transfer width. */
  uint32_t           src_width;        /**< @brief Set the source transfer width. */
  uint32_t           dst_addr_inc;     /**< @brief Set whether to increment or decrement
                                            the destination address on every destination
                                            transfer. */
  uint32_t           src_addr_inc;     /**< @brief Set whether to increment or decrement
                                            the source address on every source transfer. */
  uint32_t           trf_tfc;          /**< @brief Set the transfer type and flow control. */
  uint32_t           dst_master_if;    /**< @brief Set the Master Interface layer where the
                                            destination device (peripheral or memory) resides. */
  uint32_t           src_master_if;    /**< @brief Set the Master Interface layer from which
                                            the source device (peripheral or memory) is
                                            accessed. */
  uint32_t           dst_auto_reload;  /**< @brief Set the automatic destination reload feature
                                            enable or not. */
  uint32_t           src_auto_reload;  /**< @brief Set the automatic source reload feature
                                            enable or not. */
  uint8_t            dst_hwhif;        /**< @brief Set the hardware handshaking interface to
                                            the source of this channel. */
  uint8_t            src_hwhif;        /**< @brief Set the hardware handshaking interface to
                                            the source of this channel. */
  uint8_t            ch_priority;      /**< @brief Set the channel priority. A priority of 2
                                            is the highest priority, and 0 is the lowest. */
  uint8_t            prot_ctl;         /**< @brief Set the protection control, used to drive
                                            the AHB HPROT[3:1] bus. The default value must be 1.*/
  /* Generally, the default value of the following parameters is 0. */
  uint32_t           dst_trs_len;      /**< @brief Set the destination burst transaction
                                            length. */
  uint32_t           src_trs_len;      /**< @brief Set the source burst transaction length. */
  uint32_t           dst_hifs;         /**< @brief Set which of the handshaking interfaces-hardware
                                            or software - is active for destination requests on
                                            this channel. */
  uint32_t           src_hifs;         /**< @brief Set which of the handshaking interfaces-hardware
                                            or software - is active for source requests on this
                                            channel. */
  uint32_t           dst_hifp;         /**< @brief Set the destination handshaking interface
                                            polarity. */
  uint32_t           src_hifp;         /**< @brief Set the source handshaking interface polarity. */
  uint32_t           fc_mode;          /**< @brief Set the flow control mode. */
  uint32_t           fifo_mode;        /**< @brief Set the FIFO mode. */
  uint16_t           brs_maxlen;       /**< @brief Set the Maximum AMBA burst length that is
                                            used for DMA transfers on this channel. */
} wb32_dmac_chinit_t;
/**
  * @}
  */

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
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 * @param[in] addr      value to be written in the SAR register
 *
 * @special
 */
#define dmaStreamSetSource(dmastp, addr) {                                  \
    (dmastp)->dmac->Ch[(dmastp)->channel].SAR = (uint32_t)(addr);           \
  }

/**
 * @brief   Associates a memory destination to a DMA stream.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 * @param[in] addr      value to be written in the DAR register
 *
 * @special
 */
#define dmaStreamSetDestination(dmastp, addr) {                             \
    (dmastp)->dmac->Ch[(dmastp)->channel].DAR = (uint32_t)(addr);           \
  }

/**
 * @brief   Sets the number of transfers to be performed.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 * @param[in] size      value to be written in the CTLH register   Size must be less than 511
 *
 * @special
 */
#define dmaStreamSetTransactionSize(dmastp, size) {                          \
    (dmastp)->dmac->Ch[(dmastp)->channel].CTLH = (uint32_t)((size) & 0x1FF); \
  }

/**
 * @brief   Returns the number of transfers to be performed.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 * @return              The number of transfers to be performed.
 *
 * @special
 */
#define dmaStreamGetTransactionSize(dmastp) ((size_t)((dmastp)->dmac->Ch[(dmastp)->channel].CTLH))

/**
 * @brief   Programs the stream mode settings.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 * @param[in] mode      value to be written in that CTLL/CFGL/CFGH register
 *
 * @special
 */
#define dmaStreamSetMode(dmastp, mode) {                                                              \
    switch ((uint32_t)(mode) & WB32_DMA_CHCFG_DIR_MASK) {                                             \
        case WB32_DMA_CHCFG_DIR_M2M: /* M2M */                                                        \
          (dmastp)->dmac->Ch[(dmastp)->channel].CFGL = WB32_DMAC_TRF_TFC_M2MD |                       \
                                                       WB32_DMAC_SRC_MASTER_IF_AHB |                  \
                                                       WB32_DMAC_DST_MASTER_IF_AHB |                  \
                                                       (((mode) & WB32_DMA_CHCFG_PSIZE_MASK) >> 5) |  \
                                                       (((mode) & WB32_DMA_CHCFG_MSIZE_MASK) >> 10) | \
                                                       ((!((mode) & WB32_DMA_CHCFG_PINC)) << 10) |    \
                                                       ((!((mode) & WB32_DMA_CHCFG_MINC)) << 8);      \
          (dmastp)->dmac->Ch[(dmastp)->channel].CFGH = (1U << 2);                                     \
          break;                                                                                      \
        case WB32_DMA_CHCFG_DIR_M2P: /* M2P */                                                        \
          (dmastp)->dmac->Ch[(dmastp)->channel].CTLL = WB32_DMAC_TRF_TFC_M2PD |                       \
                                                       WB32_DMAC_SRC_MASTER_IF_AHB |                  \
                                                       WB32_DMAC_DST_MASTER_IF_APB |                  \
                                                       (((mode) & WB32_DMA_CHCFG_MSIZE_MASK) >> 7) |  \
                                                       (((mode) & WB32_DMA_CHCFG_PSIZE_MASK) >> 8) |  \
                                                       ((!((mode) & WB32_DMA_CHCFG_MINC)) << 10) |    \
                                                       ((!((mode) & WB32_DMA_CHCFG_PINC)) << 8);      \
          (dmastp)->dmac->Ch[(dmastp)->channel].CFGH = (((mode) & WB32_DMA_CHCFG_HWHIF_MASK) >> 5) |  \
                                                       (1U << 2);                                     \
          break;                                                                                      \
        case WB32_DMA_CHCFG_DIR_P2M: /* P2M */                                                        \
          (dmastp)->dmac->Ch[(dmastp)->channel].CTLL = WB32_DMAC_TRF_TFC_P2MD |                       \
                                                       WB32_DMAC_SRC_MASTER_IF_APB |                  \
                                                       WB32_DMAC_DST_MASTER_IF_AHB |                  \
                                                       (((mode) & WB32_DMA_CHCFG_PSIZE_MASK) >> 5) |  \
                                                       (((mode) & WB32_DMA_CHCFG_MSIZE_MASK) >> 10) | \
                                                       ((!((mode) & WB32_DMA_CHCFG_PINC)) << 10) |    \
                                                       ((!((mode) & WB32_DMA_CHCFG_MINC)) << 8);      \
          (dmastp)->dmac->Ch[(dmastp)->channel].CFGH = (((mode) & WB32_DMA_CHCFG_HWHIF_MASK) >> 9) |  \
                                                       (1U << 2);                                     \
          break;                                                                                      \
    }                                                                                                 \
    (dmastp)->dmac->Ch[(dmastp)->channel].CFGL = (((mode) & WB32_DMA_CHCFG_PL_MASK) >> 8) |           \
                                                 (((mode) & WB32_DMA_CHCFG_CIRC) << 24) |             \
                                                 (((mode) & WB32_DMA_CHCFG_CIRC) << 25);              \
    if ((mode) & (WB32_DMA_CHCFG_TCIE)) {                                                             \
      (dmastp)->dmac->Ch[(dmastp)->channel].CTLL |= WB32_DMAC_INTERRUPT_EN;                           \
      dmaStreamEnableInterrupt(dmastp, WB32_DMAC_IT_TFR);                                             \
    }                                                                                                 \
    if ((mode) & (WB32_DMA_CHCFG_HTIE)) {                                                             \
      (dmastp)->dmac->Ch[(dmastp)->channel].CTLL |= WB32_DMAC_INTERRUPT_EN;                           \
      dmaStreamEnableInterrupt(dmastp, WB32_DMAC_IT_BLOCK);                                           \
    }                                                                                                 \
    if ((mode) & WB32_DMA_CHCFG_TEIE) {                                                               \
      (dmastp)->dmac->Ch[(dmastp)->channel].CTLL |= WB32_DMAC_INTERRUPT_EN;                           \
      dmaStreamEnableInterrupt(dmastp, WB32_DMAC_IT_ERR);                                             \
    }                                                                                                 \
  }

#define dmaStreamSetModeI(dmastp, mode) {                                    \
    (dmastp)->dmac->Ch[(dmastp)->channel].CTLL = (mode).interrupt |          \
                                                 (mode).dst_width |          \
                                                 (mode).src_width |          \
                                                 (mode).dst_addr_inc |       \
                                                 (mode).src_addr_inc |       \
                                                 (mode).dst_trs_len |        \
                                                 (mode).src_trs_len |        \
                                                 (mode).trf_tfc |            \
                                                 (mode).dst_master_if |      \
                                                 (mode).src_master_if;       \
    (dmastp)->dmac->Ch[(dmastp)->channel].CFGL = ((mode).ch_priority << 5) | \
                                                 (mode).dst_hifs |           \
                                                 (mode).src_hifs |           \
                                                 (mode).dst_hifp |           \
                                                 (mode).src_hifp |           \
                                                 ((mode).brs_maxlen << 20) | \
                                                 (mode).src_auto_reload |    \
                                                 (mode).dst_auto_reload;     \
    (dmastp)->dmac->Ch[(dmastp)->channel].CFGH = (mode).fc_mode |            \
                                                 (mode).fifo_mode |          \
                                                 ((mode).prot_ctl << 2) |    \
                                                 ((mode).src_hwhif << 7) |   \
                                                 ((mode).dst_hwhif << 11);   \
  }


/**
 * @brief   DMA stream enable interrupt configuration.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 * @param[in] it_flag   specifies the DMAC interrupt source to be enabled or disabled.
 *
 * @special
 */
#define dmaStreamEnableInterrupt(dmastp, it_flag) {                         \
    uint32_t mask = (uint32_t)(0x01U << ((dmastp)->channel));               \
    uint32_t regaddr = ((uint32_t)(&((dmastp)->dmac->MaskTfr)) + it_flag);  \
    *((__O uint32_t *)(regaddr)) = (mask << 8) | mask;                      \
  }

/**
 * @brief   DMA stream disable interrupt configuration.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 * @param[in] it_flag   specifies the DMAC interrupt source to be enabled or disabled.
 *
 * @special
 */
#define dmaStreamDisableInterrupt(dmastp, it_flag) {                        \
    uint32_t mask = (uint32_t)(0x01U << ((dmastp)->channel));               \
    uint32_t regaddr = ((uint32_t)(&((dmastp)->dmac->MaskTfr)) + it_flag);  \
    *((__O uint32_t *)(regaddr)) = (mask << 8);                             \
  }

/**
 * @brief   DMA stream enable interrupt configuration all.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamEnableInterruptAll(dmastp) {                               \
    dmaStreamEnableInterrupt(dmastp, WB32_DMAC_IT_TFR);                     \
    dmaStreamEnableInterrupt(dmastp, WB32_DMAC_IT_BLOCK);                   \
    dmaStreamEnableInterrupt(dmastp, WB32_DMAC_IT_SRCTRAN);                 \
    dmaStreamEnableInterrupt(dmastp, WB32_DMAC_IT_DSTTRAN);                 \
    dmaStreamEnableInterrupt(dmastp, WB32_DMAC_IT_ERR);                     \
  }

/**
 * @brief   DMA stream disable interrupt configuration all.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamDisableInterruptAll(dmastp) {                              \
    dmaStreamDisableInterrupt(dmastp, WB32_DMAC_IT_TFR);                    \
    dmaStreamDisableInterrupt(dmastp, WB32_DMAC_IT_BLOCK);                  \
    dmaStreamDisableInterrupt(dmastp, WB32_DMAC_IT_SRCTRAN);                \
    dmaStreamDisableInterrupt(dmastp, WB32_DMAC_IT_DSTTRAN);                \
    dmaStreamDisableInterrupt(dmastp, WB32_DMAC_IT_ERR);                    \
  }

/**
 * @brief   DMA stream interrupt sources clear.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamClearInterrupt(dmastp) {                                            \
    uint32_t mask = (uint32_t)(0x01U << ((dmastp)->channel));                        \
    uint32_t regaddr = ((uint32_t)(&((dmastp)->dmac->ClearTfr)) + WB32_DMAC_IT_TFR); \
    *((__O uint32_t *)(regaddr)) = mask;                                             \
    regaddr = ((uint32_t)(&((dmastp)->dmac->ClearTfr)) + WB32_DMAC_IT_BLOCK);        \
    *((__O uint32_t *)(regaddr)) = mask;                                             \
    regaddr = ((uint32_t)(&((dmastp)->dmac->ClearTfr)) + WB32_DMAC_IT_SRCTRAN);      \
    *((__O uint32_t *)(regaddr)) = mask;                                             \
    regaddr = ((uint32_t)(&((dmastp)->dmac->ClearTfr)) + WB32_DMAC_IT_DSTTRAN);      \
    *((__O uint32_t *)(regaddr)) = mask;                                             \
    regaddr = ((uint32_t)(&((dmastp)->dmac->ClearTfr)) + WB32_DMAC_IT_ERR);          \
    *((__O uint32_t *)(regaddr)) = mask;                                             \
  }

/**
 * @brief   DMA stream enable.
 * @note    This function can be invoked in both ISR or thread context.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamEnable(dmastp) {                                           \
    uint32_t mask = (uint32_t)(0x01U << ((dmastp)->channel));               \
    (dmastp)->dmac->ChEnReg = (mask << 8) | mask;                           \
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
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 *
 * @special
 */
#define dmaStreamDisable(dmastp) {                                          \
    uint32_t mask = (uint32_t)(0x01U << ((dmastp)->channel));               \
    (dmastp)->dmac->ChEnReg = (mask << 8);                                  \
    dmaStreamDisableInterruptAll(dmastp);                                   \
    dmaStreamClearInterrupt(dmastp);                                        \
  }

/**
 * @brief   Starts a memory to memory operation using the specified stream.
 * @note    The default transfer data mode is "byte to byte" but it can be
 *          changed by specifying extra options in the @p mode parameter.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 * @param[in] mode      value to be written in the CCR register, this value
 *                      is implicitly ORed with:
 *                      - @p WB32_DMAC_SRC_ADDR_INC
 *                      - @p WB32_DMAC_DST_ADDR_INC
 *                      - @p WB32_DMAC_TRF_TFC_M2MD
 *                      .
 * @param[in] src       source address
 * @param[in] dst       destination address
 * @param[in] n         number of data units to copy
 */
#define dmaStartMemCopy(dmastp, mode, src, dst, n) {                        \
    (mode).src_addr_inc = WB32_DMAC_SRC_ADDR_INC;                           \
    (mode).dst_addr_inc = WB32_DMAC_DST_ADDR_INC;                           \
    (mode).trf_tfc = WB32_DMAC_TRF_TFC_M2MD;                                \
    dmaStreamSetSource(dmastp, src);                                        \
    dmaStreamSetDestination(dmastp, dst);                                   \
    dmaStreamSetTransactionSize(dmastp, n);                                 \
    dmaStreamSetMode(dmastp, mode);                                         \
    dmaStreamEnable(dmastp);                                                \
  }

/**
 * @brief   Polled wait for DMA transfer end.
 * @pre     The stream must have been allocated using @p dmaStreamAlloc().
 * @post    After use the stream can be released using @p dmaStreamRelease().
 *
 * @param[in] dmastp    pointer to a wb32_dma_stream_t structure
 */
#define dmaWaitCompletion(dmastp) {                                         \
    while (((dmastp)->dmac->Ch[(dmastp)->channel].CTLH & 0x00000FFFU) > 0U) \
      ;                                                                     \
    dmaStreamDisable(dmastp);                                               \
  }
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern const wb32_dma_stream_t _WB32_DMAC_CHANNELS[WB32_DMAC_CHANNELS];
#endif

#ifdef __cplusplus
extern "C"
{
#endif
  void dmaInit(void);
  const wb32_dma_stream_t *dmaStreamAllocI(uint32_t id,
                                           uint32_t priority,
                                           wb32_dmaisr_t func,
                                           void *param);
  const wb32_dma_stream_t *dmaStreamAlloc(uint32_t id,
                                          uint32_t priority,
                                          wb32_dmaisr_t func,
                                          void *param);
  void dmaStreamFreeI(const wb32_dma_stream_t *dmastp);
  void dmaStreamFree(const wb32_dma_stream_t *dmastp);
  void dmaServeInterrupt(const wb32_dma_stream_t *dmastp);
#ifdef __cplusplus
}
#endif

#endif /* WB32_DMA_H */

/** @} */

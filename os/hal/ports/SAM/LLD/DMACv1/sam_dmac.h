#ifndef SAM_DMAC_H_
#define SAM_DMAC_H_

#include "sam.h"
/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
#define SAM_DMAC_NUM_MAX SAM_DMAC_CHAN_NUM
typedef enum
{
  DISABLE = 0,
  SERCOM0_RX,
  SERCOM0_TX,
  SERCOM1_RX,
  SERCOM1_TX,
  SERCOM2_RX,
  SERCOM2_TX,
  SERCOM3_RX,
  SERCOM3_TX,
  SERCOM4_RX,
  SERCOM4_TX,
  SERCOM5_RX,
  SERCOM5_TX,
  TCC0_OVF,
  TCC0_MC0,
  TCC0_MC1,
  TCC0_MC2,
  TCC0_MC3,
  TCC1_OVF,
  TCC1_MC0,
  TCC1_MC1,
  TCC2_OVF,
  TCC2_MC0,
  TCC2_MC1,
  TC3_OVF,
  TC3_MC0,
  TC3_MC1,
  TC4_OVF,
  TC4_MC0,
  TC4_MC1,
  TC5_OVF,
  TC5_MC0,
  TC5_MC1,
  TC6_OVF,
  TC6_MC0,
  TC6_MC1,
  TC7_OVF,
  TC7_MC0,
  TC7_MC1,
  ADC_RESRDY,
  DAC_EMPTY,
  I2S_RX0,
  I2S_RX1,
  I2S_TX0,
  I2S_TX1,
  TCC3_OVF,
  TCC3_MC0,
  TCC3_MC1,
  TCC3_MC2,
  TCC3_MC3,
} dmac_trigsrc_t;

typedef enum
{
  BLOCK = 0,
  BEAT = 2,
  TRANSACTION,
} dmac_trigact_t;

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

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
typedef void (*sam_dmaisr_t)(void *p, uint8_t flags);

typedef struct
{
  dmac_descriptor_registers_t *desc;
  dmac_descriptor_registers_t *wb;
} sam_dmac_chnl_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#if !defined(__DOXYGEN__)
extern const sam_dmac_chnl_t _sam_dmac_chnl[SAM_DMAC_CHAN_NUM];
#endif

#ifdef __cplusplus
extern "C"
{
#endif
  void dmacInit(void);
  int8_t dmacChnlAllocI(uint8_t id,
                        uint8_t priority,
                        sam_dmaisr_t func,
                        void *param);
  int8_t dmacChnlAlloc(uint8_t id,
                       uint8_t priority,
                       sam_dmaisr_t func,
                       void *param);
  void dmacChnlFree(uint8_t id);
  void dmacChnlFreeI(uint8_t id);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Driver inline functions.                                                  */
/*===========================================================================*/
/**
 * @brief Resetting DMAC channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlReset(uint8_t id)
{
  DMAC_REGS->DMAC_CHID = id;
  /* Disable the DMA channel */
  DMAC_REGS->DMAC_CHCTRLA = (uint8_t)(DMAC_CHCTRLA_SWRST_Msk);
  /* Wait for channel to be disabled */
  while ((DMAC_REGS->DMAC_CHCTRLA & DMAC_CHCTRLA_ENABLE_Msk) != 0U)
    ;
}

/**
 * @brief Check DMAC how many bytes has been transferred
 *
 * @param id DMAC Channel
 * @return uint16_t bytes have been transferred
 */
static inline uint16_t dmacChnlGetTransferred(uint8_t id)
{
  uint16_t transferredCount = _sam_dmac_chnl[id].desc->DMAC_BTCNT;
  transferredCount -= _sam_dmac_chnl[id].wb->DMAC_BTCNT;
  return (transferredCount);
}

/**
 * @brief Set Priority of DMAC
 * Can only run when the channel is not enabled
 *
 * @param id DMAC Channel
 * @param prio channel priority
 */
static inline void dmacChnlSetPrio(uint8_t id, uint8_t prio)
{
  DMAC_REGS->DMAC_CHID = id;
  osalDbgAssert(prio < 3, "DMAC Priority out of range");
  uint8_t chctrlb = DMAC_REGS->DMAC_CHCTRLB;
  chctrlb &= ~DMAC_CHCTRLB_LVL_Msk;
  chctrlb |= DMAC_CHCTRLB_LVL(prio);
  DMAC_REGS->DMAC_CHCTRLB = chctrlb;
}

/**
 * @brief Enable DMAC Channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlEnable(uint8_t id)
{
  DMAC_REGS->DMAC_CHID = id;
  DMAC_REGS->DMAC_CHCTRLA |= (uint8_t)(DMAC_CHCTRLA_ENABLE_Msk);
}

/**
 * @brief Disable DMAC Channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlDisable(uint8_t id)
{
  DMAC_REGS->DMAC_CHID = id;
  DMAC_REGS->DMAC_CHCTRLA &= (uint8_t)(~DMAC_CHCTRLA_ENABLE_Msk);
}

/**
 * @brief Setting BTCTRL for the DMAC Channel
 *
 * @param id DMAC Channel
 * @param btctrl
 */
static inline void dmacChnlSetBtCtrl(uint8_t id, uint16_t btctrl)
{
  dmac_descriptor_registers_t *dmacDescReg = _sam_dmac_chnl[id].desc;
  dmacDescReg->DMAC_BTCTRL = btctrl;
}

static inline uint8_t dmacChnlGetBeatSize(uint8_t id)
{
  dmac_descriptor_registers_t *dmacDescReg = _sam_dmac_chnl[id].desc;
  uint8_t beat_size = (uint8_t)((dmacDescReg->DMAC_BTCTRL & DMAC_BTCTRL_BEATSIZE_Msk) >> DMAC_BTCTRL_BEATSIZE_Pos);
  return 1u << beat_size;
}

/**
 * @brief Set trigger SRC
 *
 * @param id DMAC Channel
 * @param src source to trigger
 */
static inline void dmacChnlSetTrigSrc(uint8_t id, dmac_trigsrc_t src)
{
  DMAC_REGS->DMAC_CHID = id;
  uint32_t chctrlb = DMAC_REGS->DMAC_CHCTRLB;
  chctrlb &= ~DMAC_CHCTRLB_TRIGSRC_Msk;
  chctrlb |= DMAC_CHCTRLB_TRIGSRC(src);
  DMAC_REGS->DMAC_CHCTRLB = chctrlb;
}

/**
 * @brief Enabling Event Output to EVSYS (This only works on DMAC 0-3)
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlEnableEventOut(uint8_t id)
{
  osalDbgAssert(id < 3, "Cannot map to EVSYS");
  DMAC_REGS->DMAC_CHID = id;
  DMAC_REGS->DMAC_CHCTRLB |= DMAC_CHCTRLB_EVOE_Msk;
}

/**
 * @brief Enable IRQ for that channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlEnableIRQn(uint8_t id)
{
  DMAC_REGS->DMAC_CHID = id;
  DMAC_REGS->DMAC_CHINTENSET = (uint8_t)(DMAC_CHINTENSET_TCMPL_Msk | DMAC_CHINTENSET_TERR_Msk);
}

/**
 * @brief Disable IRQ for that channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlDisableIRQn(uint8_t id)
{
  DMAC_REGS->DMAC_CHID = id;
  DMAC_REGS->DMAC_CHINTENCLR = (uint8_t)(DMAC_CHINTENCLR_TCMPL_Msk | DMAC_CHINTENCLR_TERR_Msk);
}

/**
 * @brief Setting trigact for that channel
 *
 * @param id DMAC Channel
 */

static inline void dmacChnlSetTrigAct(uint8_t id, dmac_trigact_t act)
{
  DMAC_REGS->DMAC_CHID = id;
  uint32_t chctrlb = DMAC_REGS->DMAC_CHCTRLB;
  chctrlb &= ~DMAC_CHCTRLB_TRIGACT_Msk;
  chctrlb |= DMAC_CHCTRLB_TRIGACT(act);
  DMAC_REGS->DMAC_CHCTRLB = chctrlb;
}

/**
 * @brief Setup Destination as well as Source
 *
 * @param id DMAC Channel
 * @param dstAddr Destination Address
 * @param srcAddr Source Address
 * @param size number of transfer need to be made per beat
 */
static inline void dmacChnlSetDir(uint8_t id, uint32_t dstAddr, uint32_t srcAddr, uint16_t size)
{
  dmac_descriptor_registers_t *dmacDescReg = _sam_dmac_chnl[id].desc;
  dmacDescReg->DMAC_BTCNT = size;
  if ((dmacDescReg->DMAC_BTCTRL & DMAC_BTCTRL_DSTINC_Msk) == DMAC_BTCTRL_DSTINC_Msk)
  {
    dmacDescReg->DMAC_DSTADDR = dstAddr + size * dmacChnlGetBeatSize(id);
  }
  else
  {
    dmacDescReg->DMAC_DSTADDR = dstAddr;
  }
  if ((dmacDescReg->DMAC_BTCTRL & DMAC_BTCTRL_SRCINC_Msk) == DMAC_BTCTRL_SRCINC_Msk)
  {
    dmacDescReg->DMAC_SRCADDR = srcAddr + size * dmacChnlGetBeatSize(id);
  }
  else
  {
    dmacDescReg->DMAC_SRCADDR = srcAddr;
  }
}

// TODO: fix this function
//  static inline void dmacChnlSetCircular(uint8_t id, uint8_t isCircular)
//  {
//    dmac_descriptor_registers_t *dmacDescReg = _sam_dmac_chnl[id].desc;
//    if(isCircular) {
//      dmacDescReg->DMAC_DESCADDR = ((uint32_t)dmacDescReg);
//    }
//    else {
//      dmacDescReg->DMAC_DESCADDR = 0U;
//    }
//  }

/**
 * @brief Get Destination address
 *
 * @param id
 * @return uint32_t
 */
static inline uint32_t dmacChnlGetDstAddr(uint8_t id)
{
  dmac_descriptor_registers_t *dmacDescReg = _sam_dmac_chnl[id].desc;
  return dmacDescReg->DMAC_DSTADDR;
}

#endif
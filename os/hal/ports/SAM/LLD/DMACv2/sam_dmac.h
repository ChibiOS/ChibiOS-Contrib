#ifndef SAM_DMAC_H_
#define SAM_DMAC_H_


/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
#include "sam.h"
#define SAM_DMAC_NUM_MAX SAM_DMAC_CHAN_NUM

typedef enum {
    DISABLE         = 0x00,
    RESERVED1       = 0x01,
    RESERVED2       = 0x02,
    RESERVED3       = 0x03,
    SERCOM0_RX      = 0x04,
    SERCOM0_TX      = 0x05,
    SERCOM1_RX      = 0x06,
    SERCOM1_TX      = 0x07,
    SERCOM2_RX      = 0x08,
    SERCOM2_TX      = 0x09,
    SERCOM3_RX      = 0x0A,
    SERCOM3_TX      = 0x0B,
    SERCOM4_RX      = 0x0C,
    SERCOM4_TX      = 0x0D,
    SERCOM5_RX      = 0x0E,
    SERCOM5_TX      = 0x0F,
    SERCOM6_RX      = 0x10,
    SERCOM6_TX      = 0x11,
    SERCOM7_RX      = 0x12,
    SERCOM7_TX      = 0x13,
    CAN0_DBG        = 0x14,
    CAN1_DBG        = 0x15,
    TCC0_OVF        = 0x16,
    TCC0_MC0        = 0x17,
    TCC0_MC1        = 0x18,
    TCC0_MC2        = 0x19,
    TCC0_MC3        = 0x1A,
    TCC0_MC4        = 0x1B,
    TCC0_MC5        = 0x1C,
    TCC1_OVF        = 0x1D,
    TCC1_MC0        = 0x1E,
    TCC1_MC1        = 0x1F,
    TCC1_MC2        = 0x20,
    TCC1_MC3        = 0x21,
    TCC2_OVF        = 0x22,
    TCC2_MC0        = 0x23,
    TCC2_MC1        = 0x24,
    TCC2_MC2        = 0x25,
    TCC3_OVF        = 0x26,
    TCC3_MC0        = 0x27,
    TCC3_MC1        = 0x28,
    TCC4_OVF        = 0x29,
    TCC4_MC1        = 0x2A,
    TCC4_MC2        = 0x2B,
    TC0_OVF         = 0x2C,
    TC0_MC0         = 0x2D,
    TC0_MC1         = 0x2E,
    TC1_OVF         = 0x2F,
    TC1_MC0         = 0x30,
    TC1_MC1         = 0x31,
    TC2_OVF         = 0x32,
    TC2_MC0         = 0x33,
    TC2_MC1         = 0x34,
    TC3_OVF         = 0x35,
    TC3_MC0         = 0x36,
    TC3_MC1         = 0x37,
    TC4_OVF         = 0x38,
    TC4_MC0         = 0x39,
    TC4_MC1         = 0x3A,
    TC5_OVF         = 0x3B,
    TC5_MC0         = 0x3C,
    TC5_MC1         = 0x3D,
    TC6_OVF         = 0x3E,
    TC6_MC0         = 0x3F,
    TC6_MC1         = 0x40,
    TC7_OVF         = 0x41,
    TC7_MC0         = 0x42,
    TC7_MC1         = 0x43,
    ADC0_RESRDY     = 0x44,
    ADC0_SEQ        = 0x45,
    ADC1_RESRDY     = 0x46,
    ADC1_SEQ        = 0x47,
    DAC0_EMPTY      = 0x48,
    DAC0_RESRDY     = 0x49,
    DAC1_EMPTY      = 0x4A,
    DAC1_RESRDY     = 0x4B,
    I2S_RX0         = 0x4C,
    I2S_RX1         = 0x4D,
    I2S_TX0         = 0x4E,
    I2S_TX1         = 0x4F,
    PCC_RX          = 0x50,
    AES_WR          = 0x51,
    AES_RD          = 0x52,
    QSPI_RX         = 0x53,
    QSPI_TX         = 0x54,
} dmac_trigsrc_t;



typedef enum {
  BLOCK       = 0x0,
  RSVD        = 0x1,
  BURST        = 0x2,
  TRANSACTION = 0x3,
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
typedef void (*sam_dmaisr_t)(void* p, uint8_t flags);

typedef struct {
  dmac_descriptor_registers_t* desc;
  dmac_descriptor_registers_t* wb;
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
extern "C" {
#endif
void dmacInit(void);
int8_t dmacChnlAllocI(uint8_t id, uint8_t priority, sam_dmaisr_t func,
                      void* param);
int8_t dmacChnlAlloc(uint8_t id, uint8_t priority, sam_dmaisr_t func,
                     void* param);
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
static inline void dmacChnlReset(uint8_t id) {
  /* Disable the DMA channel */
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLA = (DMAC_CHCTRLA_SWRST_Msk);
  while ((DMAC_REGS->CHANNEL[id].DMAC_CHCTRLA & DMAC_CHCTRLA_ENABLE_Msk) != 0U)
    ;
}

/**
 * @brief Check DMAC how many bytes has been transferred
 *
 * @param id DMAC Channel
 * @return uint16_t bytes have been transferred
 */
static inline uint16_t dmacChnlGetTransferred(uint8_t id) {
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
static inline void dmacChnlSetPrio(uint8_t id, uint8_t prio) {
  osalDbgAssert(prio < 3, "DMAC Priority out of range");
  DMAC_REGS->CHANNEL[id].DMAC_CHPRILVL &= ~DMAC_CHPRILVL_PRILVL_Msk;
  DMAC_REGS->CHANNEL[id].DMAC_CHPRILVL |= DMAC_CHPRILVL_PRILVL(prio);
}

/**
 * @brief Enable DMAC Channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlEnable(uint8_t id) {
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLA |= (DMAC_CHCTRLA_ENABLE_Msk);
}

/**
 * @brief Disable DMAC Channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlDisable(uint8_t id) {
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLA &= (~DMAC_CHCTRLA_ENABLE_Msk);
}

/**
 * @brief Setting BTCTRL for the DMAC Channel
 *
 * @param id DMAC Channel
 * @param btctrl
 */
static inline void dmacChnlSetBtCtrl(uint8_t id, uint16_t btctrl) {
  dmac_descriptor_registers_t* dmacDescReg = _sam_dmac_chnl[id].desc;
  dmacDescReg->DMAC_BTCTRL = btctrl;
}

static inline uint8_t dmacChnlGetBeatSize(uint8_t id) {
  dmac_descriptor_registers_t* dmacDescReg = _sam_dmac_chnl[id].desc;
  uint8_t beat_size =
      (uint8_t)((dmacDescReg->DMAC_BTCTRL & DMAC_BTCTRL_BEATSIZE_Msk) >>
                DMAC_BTCTRL_BEATSIZE_Pos);
  return 1u << beat_size;
}


/**
 * @brief Set trigger SRC
 *
 * @param id DMAC Channel
 * @param src source to trigger
 */
static inline void dmacChnlSetTrigSrc(uint8_t id, dmac_trigsrc_t src) {
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLA &= ~DMAC_CHCTRLA_TRIGSRC_Msk;
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLA |= DMAC_CHCTRLA_TRIGSRC(src);
}

/**
 * @brief Enabling Event Output to EVSYS (This only works on DMAC 0-3)
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlEnableEventOut(uint8_t id) {
  osalDbgAssert(id < 3, "Cannot map to EVSYS");
  DMAC_REGS->CHANNEL[id].DMAC_CHEVCTRL |= DMAC_CHEVCTRL_EVOE_Msk;
}

/**
 * @brief Enable IRQ for that channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlEnableIRQn(uint8_t id) {
  DMAC_REGS->CHANNEL[id].DMAC_CHINTENSET = (DMAC_CHINTENSET_TCMPL_Msk | DMAC_CHINTENSET_TERR_Msk);
}

/**
 * @brief Disable IRQ for that channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlDisableIRQn(uint8_t id) {
  DMAC_REGS->CHANNEL[id].DMAC_CHINTENCLR = (DMAC_CHINTENCLR_TCMPL_Msk | DMAC_CHINTENCLR_TERR_Msk);
}

/**
 * @brief Setting trigact for that channel
 *
 * @param id DMAC Channel
 */
static inline void dmacChnlSetTrigAct(uint8_t id, dmac_trigact_t act) {
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLA &= ~DMAC_CHCTRLA_TRIGACT_Msk;
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLA |= DMAC_CHCTRLA_TRIGACT(act);
}

/**
 * @brief Suspend a DMAC channel
 * 
 * @param id DMAC Channel
 */
static inline void dmacChnlSuspend(uint8_t id)
{
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLB &= (~DMAC_CHCTRLB_CMD_Msk);
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLB |= (DMAC_CHCTRLB_CMD_SUSPEND);
}

/**
 * @brief Resume a DMAC channel
 * 
 * @param id DMAC Channel
 */
static inline void dmacChnlResume(uint8_t id)
{
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLB &= (~DMAC_CHCTRLB_CMD_Msk);
  DMAC_REGS->CHANNEL[id].DMAC_CHCTRLB |= (DMAC_CHCTRLB_CMD_RESUME);
}

/**
 * @brief Setup Destination as well as Source
 *
 * @param id DMAC Channel
 * @param dstAddr Destination Address
 * @param srcAddr Source Address
 * @param size number of transfer need to be made per beat
 */
static inline void dmacChnlSetDir(uint8_t id, uint32_t dstAddr,
                                  uint32_t srcAddr, uint16_t size) {
  dmac_descriptor_registers_t* dmacDescReg = _sam_dmac_chnl[id].desc;
  dmacDescReg->DMAC_BTCNT = size;
  if ((dmacDescReg->DMAC_BTCTRL & DMAC_BTCTRL_DSTINC_Msk) ==
      DMAC_BTCTRL_DSTINC_Msk) {
    dmacDescReg->DMAC_DSTADDR = dstAddr + size * dmacChnlGetBeatSize(id);
  } else {
    dmacDescReg->DMAC_DSTADDR = dstAddr;
  }
  if ((dmacDescReg->DMAC_BTCTRL & DMAC_BTCTRL_SRCINC_Msk) ==
      DMAC_BTCTRL_SRCINC_Msk) {
    dmacDescReg->DMAC_SRCADDR = srcAddr + size * dmacChnlGetBeatSize(id);
  } else {
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
static inline uint32_t dmacChnlGetDstAddr(uint8_t id) {
  dmac_descriptor_registers_t* dmacDescReg = _sam_dmac_chnl[id].desc;
  return dmacDescReg->DMAC_DSTADDR;
}
#endif
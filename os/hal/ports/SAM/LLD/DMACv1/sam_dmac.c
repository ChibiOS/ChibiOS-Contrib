#include "hal.h"

#if defined(SAM_DMAC_REQUIRED) || defined(__DOXYGEN__)

static struct
{
  /**
   * @brief   Mask of the allocated streams.
   */
  uint32_t allocated_mask;
  /**
   * @brief   DMA IRQ redirectors.
   */
  struct
  {
    /**
     * @brief   DMA callback function.
     */
    sam_dmaisr_t func;
    /**
     * @brief   DMA callback parameter.
     */
    void *param;
  } channel[SAM_DMAC_CHAN_NUM];
} dmac;

static dmac_descriptor_registers_t descriptor_section[SAM_DMAC_CHAN_NUM] __ALIGNED(16);
static dmac_descriptor_registers_t writeback_section[SAM_DMAC_CHAN_NUM] __ALIGNED(16);

const sam_dmac_chnl_t _sam_dmac_chnl[SAM_DMAC_CHAN_NUM] = {
    {&descriptor_section[0], &writeback_section[0]},
    {&descriptor_section[1], &writeback_section[1]},
    {&descriptor_section[2], &writeback_section[2]},
    {&descriptor_section[3], &writeback_section[3]},
    {&descriptor_section[4], &writeback_section[4]},
    {&descriptor_section[5], &writeback_section[5]},
    {&descriptor_section[6], &writeback_section[6]},
    {&descriptor_section[7], &writeback_section[7]},
    {&descriptor_section[8], &writeback_section[8]},
    {&descriptor_section[9], &writeback_section[9]},
    {&descriptor_section[10], &writeback_section[10]},
    {&descriptor_section[11], &writeback_section[11]},
};

/**
 * @brief Initialize DMAC Peripheral
 *
 */
void dmacInit(void)
{
  PM_REGS->PM_APBBMASK |= PM_APBBMASK_DMAC_Msk;
  PM_REGS->PM_AHBMASK |= PM_AHBMASK_DMAC_Msk;

  /* Reset DMAC before usage */
  DMAC_REGS->DMAC_CTRL = DMAC_CTRL_SWRST_Msk;
  DMAC_REGS->DMAC_BASEADDR = (uint32_t)&descriptor_section[0];
  DMAC_REGS->DMAC_WRBADDR = (uint32_t)&writeback_section[0];
  DMAC_REGS->DMAC_PRICTRL0 = DMAC_PRICTRL0_LVLPRI0(1UL) | DMAC_PRICTRL0_RRLVLEN0_Msk |
                             DMAC_PRICTRL0_LVLPRI1(1UL) | DMAC_PRICTRL0_RRLVLEN1_Msk |
                             DMAC_PRICTRL0_LVLPRI2(1UL) | DMAC_PRICTRL0_RRLVLEN2_Msk |
                             DMAC_PRICTRL0_LVLPRI3(1UL) | DMAC_PRICTRL0_RRLVLEN3_Msk;
  unsigned i;
  dmac.allocated_mask = 0;
  for (i = 0; i < SAM_DMAC_CHAN_NUM; i++)
  {
    dmac.channel[i].func = NULL;
    dmac.channel[i].param = NULL;
  }
  DMAC_REGS->DMAC_CTRL = (uint16_t)(DMAC_CTRL_DMAENABLE_Msk | DMAC_CTRL_LVLEN0_Msk | DMAC_CTRL_LVLEN1_Msk | DMAC_CTRL_LVLEN2_Msk | DMAC_CTRL_LVLEN3_Msk);
  nvicEnableVector(DMAC_IRQn, SAM_DMAC_IRQ_PRIORITY);
}

/**
 * @brief Obtain DMAC Channel from the pool
 *
 * @param id DMAC Channel
 * @param priority Priority for that channel
 * @param func callback function
 * @param param parameters to input for that callback
 * @return int8_t the channel ID
 * if unable to then return -1
 */
int8_t dmacChnlAllocI(uint8_t id,
                      uint8_t priority,
                      sam_dmaisr_t func,
                      void *param)
{
  uint32_t i, startid, endid;

  osalDbgCheckClassI();

  if (id < SAM_DMAC_NUM_MAX)
  {
    startid = id;
    endid = id;
  }
  else
  {
    startid = 0;
    endid = SAM_DMAC_NUM_MAX - 1;
  }

  for (i = startid; i <= endid; i++)
  {
    uint32_t mask = (1U << i);
    if ((dmac.allocated_mask & mask) == 0U)
    {
      const sam_dmac_chnl_t *dmastp = &_sam_dmac_chnl[i];
      dmastp->desc->DMAC_BTCTRL |= DMAC_BTCTRL_VALID_Msk;
      /* Installs the DMA handler. */
      dmac.channel[i].func = func;
      dmac.channel[i].param = param;
      dmac.allocated_mask |= mask;
      /* Resetting the channel */
      dmacChnlReset(i);
      dmacChnlSetPrio(i, priority);
      return (int8_t)i;
    }
  }
  return -1;
}

int8_t dmacChnlAlloc(uint8_t id,
                     uint8_t priority,
                     sam_dmaisr_t func,
                     void *param)
{
  int8_t dmac_id = -1;
  osalSysLock();
  dmac_id = dmacChnlAllocI(id, priority, func, param);
  osalSysUnlock();
  return dmac_id;
}

void dmacChnlFreeI(uint8_t id)
{
  osalDbgCheckClassI();
  dmacChnlDisableIRQn(id);
  dmacChnlDisable(id);
  dmac.channel[id].func = NULL;
  dmac.channel[id].param = NULL;
  dmac.allocated_mask &= ~(1 << (uint32_t)id);
}

void dmacChnlFree(uint8_t id)
{
  osalSysLock();
  dmacChnlFreeI(id);
  osalSysUnlock();
}

OSAL_IRQ_HANDLER(DMAC_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  uint8_t channel = 0U;
  uint8_t chanIntFlagStatus = 0U;
  channel = (uint8_t)((uint32_t)DMAC_REGS->DMAC_INTPEND & DMAC_INTPEND_ID_Msk);
  DMAC_REGS->DMAC_CHID = channel;
  chanIntFlagStatus = (uint8_t)DMAC_REGS->DMAC_CHINTFLAG;
  dmacChnlDisableIRQn(channel);
  if (dmac.channel[channel].func != NULL)
  {
    dmac.channel[channel].func(dmac.channel[channel].param, chanIntFlagStatus);
  }
  OSAL_IRQ_EPILOGUE();
}
#endif
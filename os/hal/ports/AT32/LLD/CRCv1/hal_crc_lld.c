/*
    ChibiOS - Copyright (C) 2015 Michael D. Spradling
    ChibiOS - Copyright (C) 2023..2025 HorrorTroll
    ChibiOS - Copyright (C) 2023..2025 Zhaqian

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
 * @file    CRCv1/hal_crc_lld.c
 * @brief   AT32 CRC subsystem low level driver source.
 *
 * @addtogroup CRC
 * @{
 */

#include "hal.h"

#if (HAL_USE_CRC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   CRC default configuration.
 */
static const CRCConfig default_config = {
  .poly_size         = 32,
  .poly              = 0x04C11DB7,
  .initial_val       = 0xFFFFFFFF,
  .final_val         = 0xFFFFFFFF,
  .reflect_data      = 1,
  .reflect_remainder = 1
};

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief CRC1 driver identifier.*/
#if AT32_CRC_USE_CRC1 || defined(__DOXYGEN__)
CRCDriver CRCD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

void _crc_lld_calc_byte(CRCDriver *crcp, uint8_t data) {
  __IO uint8_t *crc8 = (__IO uint8_t*)&(crcp->crc->DT);
  *crc8 = data;
}

/*
 * @brief   Returns calculated CRC from last reset
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 * @param[in] data      data to be added to crc
 *
 * @notapi
 */
void _crc_lld_calc_halfword(CRCDriver *crcp, uint16_t data) {
  __IO uint16_t *crc16 = (__IO uint16_t*)&(crcp->crc->DT);
  *crc16 = data;
}

/*
 * @brief   Returns calculated CRC from last reset
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 * @param[in] data      data to be added to crc
 *
 * @notapi
 */
void _crc_lld_calc_word(CRCDriver *crcp, uint32_t data) {
  crcp->crc->DT = data;
}


/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   Shared end-of-rx service routine.
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 * @param[in] flags     pre-shifted content of the STS register
 */
#if CRC_USE_DMA == TRUE
static void crc_lld_serve_interrupt(CRCDriver *crcp, uint32_t flags) {

  /* DMA errors handling.*/
#if defined(AT32_CRC_DMA_ERROR_HOOK)
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
    AT32_CRC_DMA_ERROR_HOOK(crcp);
  }
#else
  (void)flags;
#endif

  /* Stop everything.*/
  dmaStreamDisable(crcp->dmastp);

  if (crcp->rem_data_size) {
    /* Start DMA follow up transfer for next data chunk */
    crc_lld_start_calc(crcp, crcp->rem_data_size,
      (const void *)crcp->dmastp->channel->CPADDR+0xffff);
  } else {
    /* Portable CRC STS code defined in the high level driver, note, it is a macro.*/
    _crc_isr_code(crcp, crcp->crc->DT ^ crcp->config->final_val);
  }
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level CRC driver initialization.
 *
 * @notapi
 */
void crc_lld_init(void) {
  crcObjectInit(&CRCD1);
  CRCD1.crc = CRC;
}

/**
 * @brief   Configures and activates the CRC peripheral.
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 *
 * @notapi
 */
void crc_lld_start(CRCDriver *crcp) {
  if (crcp->config == NULL)
    crcp->config = &default_config;

  crmEnableCRC(false);

  crcp->crc->IDT = crcp->config->initial_val;
  crcp->crc->POLY = crcp->config->poly;

  crcp->crc->CTRL = 0;
  switch(crcp->config->poly_size) {
    case 32:
      break;
    case 16:
      crcp->crc->CTRL |= CRC_CTRL_POLY_SIZE_0;
      break;
    case 8:
      crcp->crc->CTRL |= CRC_CTRL_POLY_SIZE_1;
      break;
    case 7:
      crcp->crc->CTRL |= CRC_CTRL_POLY_SIZE_1 | CRC_CTRL_POLY_SIZE_0;
      break;
    default:
      osalDbgAssert(false, "hardware doesn't support polynomial size");
      break;
  };
  if (crcp->config->reflect_data) {
    crcp->crc->CTRL |= CRC_CTRL_REVID_1 | CRC_CTRL_REVID_0;
  }
  if (crcp->config->reflect_remainder) {
    crcp->crc->CTRL |= CRC_CTRL_REVOD;
  }

#if CRC_USE_DMA == TRUE
  crcp->dmamode = AT32_DMA_CCTRL_DTD_M2M     | AT32_DMA_CCTRL_PINCM |
                  AT32_DMA_CCTRL_MWIDTH_BYTE | AT32_DMA_CCTRL_PWIDTH_BYTE |
                  AT32_DMA_CCTRL_DTERRIEN    | AT32_DMA_CCTRL_FDTIEN |
                  AT32_DMA_CCTRL_CHPL(AT32_CRC_CRC1_DMA_PRIORITY);
  {
    crcp->dmastp = dmaStreamAlloc(AT32_CRC_CRC1_DMA_STREAM,
                                  AT32_CRC_CRC1_IRQ_PRIORITY,
                                  (at32_dmasts_t)crc_lld_serve_interrupt,
                                  (void *)crcp);
    osalDbgAssert(crcp->dmastp != NULL, "unable to allocate stream");
  }
#endif
}


/**
 * @brief   Deactivates the CRC peripheral.
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 *
 * @notapi
 */
void crc_lld_stop(CRCDriver *crcp) {
#if CRC_USE_DMA == TRUE
  dmaStreamFree(crcp->dmastp);
#else
  (void)crcp;
#endif
  crmDisableCRC();
}

/**
 * @brief   Resets current CRC calculation.
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 *
 * @notapi
 */
void crc_lld_reset(CRCDriver *crcp) {
  crcp->crc->CTRL |= CRC_CTRL_RST;
}

/**
 * @brief   Returns calculated CRC from last reset
 *
 * @param[in] crcp      pointer to the @p CRCDriver object
 * @param[in] n         size of buf in bytes
 * @param[in] buf       @p buffer location
 *
 * @notapi
 */
uint32_t crc_lld_calc(CRCDriver *crcp, size_t n, const void *buf) {
#if CRC_USE_DMA == TRUE
  crc_lld_start_calc(crcp, n, buf);
  (void) osalThreadSuspendS(&crcp->thread);
#else
  if (crcp->config->reflect_data != 0) {
    /* set default bit reversal done by word */
    crcp->crc->CTRL |= CRC_CTRL_REVID_1 | CRC_CTRL_REVID_0;
    while(n > 3) {
      _crc_lld_calc_word(crcp, *(uint32_t*)buf);
      buf+=4;
      n-=4;
    }
  }

  /* Programmable CRC units allow variable register width accesses.*/
  if (crcp->config->reflect_data != 0) {
    /* use bit reversal done by half-word if we are going to write tailing halfword */
    crcp->crc->CTRL = (crcp->crc->CTRL & ~CRC_CTRL_REVID_Msk) | CRC_CTRL_REVID_1;
    while(n > 1) {
      _crc_lld_calc_halfword(crcp, *(uint16_t*)buf);
      buf+=2;
      n-=2;
    }
  }

  /* use bit reversal done by byte if we are going to write tailing byte */
  if (crcp->config->reflect_data != 0) {
    crcp->crc->CTRL = (crcp->crc->CTRL & ~CRC_CTRL_REVID_Msk) | CRC_CTRL_REVID_0;
  }

  while(n > 0) {
    _crc_lld_calc_byte(crcp, *(uint8_t*)buf);
    buf++;
    n--;
  }

#endif
  return crcp->crc->DT ^ crcp->config->final_val;
}

#if CRC_USE_DMA == TRUE
void crc_lld_start_calc(CRCDriver *crcp, size_t n, const void *buf) {
  /* The AT32 DMA can only handle max 65535 bytes per transfer
   * because it's data count register has only 16 bit. */
  size_t sz = (n > 0xffff) ? 0xffff : n;
  crcp->rem_data_size = n-sz;

  dmaStreamSetPeripheral(crcp->dmastp, buf);
  dmaStreamSetMemory0(crcp->dmastp, &crcp->crc->DT);
  dmaStreamSetTransactionSize(crcp->dmastp, sz);
  dmaStreamSetMode(crcp->dmastp, crcp->dmamode);

  dmaStreamEnable(crcp->dmastp);
}
#endif

#endif /* HAL_USE_CRC */

/** @} */

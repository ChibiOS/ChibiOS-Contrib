/*
    Copyright (C) 2020 Alex Lewontin
    Modifications copyright (C) 2026 Belonit

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
 * @file    M251/hal_efl_lld.c
 * @brief   M251/M252 Embedded Flash subsystem low level driver source.
 *
 * @addtogroup HAL_EFL
 * @{
 */

#include <string.h>
#include "hal.h"
#include "M251/stddriver/fmc.h"

#if (HAL_USE_EFL == TRUE) || defined(__DOXYGEN__)

/*
 * APROM program/erase commands must execute from SRAM. The ARMCMx GCC
 * startup code copies .ram0_init.* before calling main(). Keep every helper
 * reachable while FMC is busy in this section too.
 */
#define M251_EFL_RAM_CODE CC_SECTION(".ram0_init.efl") CC_NO_INLINE

CC_FORCE_INLINE
static inline void _efl_unlock(void) {

  do {
    SYS->REGLCTL = 0x59UL;
    SYS->REGLCTL = 0x16UL;
    SYS->REGLCTL = 0x88UL;
  } while (SYS->REGLCTL == 0UL);
}

CC_FORCE_INLINE
static inline void _efl_lock(void) {

  SYS->REGLCTL = 0UL;
}

M251_EFL_RAM_CODE
static flash_error_t _efl_isp_wait(void) {
  uint32_t timeout = 0x100000UL;

  while ((FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) != 0U) {
    if (--timeout == 0U)
      return FLASH_ERROR_HW_FAILURE;
  }

  if ((FMC->ISPCTL & FMC_ISPCTL_ISPFF_Msk) != 0U) {
    FMC->ISPCTL |= FMC_ISPCTL_ISPFF_Msk;
    return FLASH_ERROR_PROGRAM;
  }

  return FLASH_NO_ERROR;
}

CC_FORCE_INLINE
static inline bool _efl_range_valid(const EFlashDriver *eflp,
                                    flash_offset_t offset, size_t n) {
  return (offset <= eflp->descriptor->size) &&
         (n <= (size_t)(eflp->descriptor->size - offset));
}

M251_EFL_RAM_CODE
static void _efl_cache_invalidate(void) {

  _efl_unlock();
  FMC->FTCTL |= FMC_FTCTL_CACHEINV_Msk;
  _efl_lock();
}

M251_EFL_RAM_CODE
static void _efl_start_page_erase(const EFlashDriver *eflp,
                                  flash_sector_t sector) {
  uint32_t addr = (uint32_t)(eflp->descriptor->address +
                             sector * M251_FLASH_PAGE_SIZE);

  _efl_unlock();
  FMC->ISPCMD = FMC_ISPCMD_PAGE_ERASE;
  FMC->ISPADDR = addr;
  FMC->ISPDAT = 0UL;
  FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
  _efl_lock();
}

static const flash_descriptor_t efl_lld_descriptor = {
    .attributes     = FLASH_ATTR_ERASED_IS_ONE | FLASH_ATTR_MEMORY_MAPPED,
    .page_size      = 4U,
    .sectors_count  = M251_FLASH_SIZE / M251_FLASH_PAGE_SIZE,
    .sectors        = NULL,
    .sectors_size   = M251_FLASH_PAGE_SIZE,
    .address        = (uint8_t *)0x00000000UL,
    .size           = M251_FLASH_SIZE,
};

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   EFLD1 driver identifier.
 */
EFlashDriver EFLD1;

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level Embedded Flash driver initialization.
 *
 * @notapi
 */
void efl_lld_init(void) {

  EFLD1.state      = FLASH_UNINIT;
  EFLD1.config     = NULL;
  EFLD1.fmc        = FMC;
  EFLD1.descriptor = &efl_lld_descriptor;
  EFLD1.current_sector = 0U;
  EFLD1.erase_all  = false;

  eflObjectInit(&EFLD1);
}

/**
 * @brief   Configures and activates the Embedded Flash peripheral.
 *
 * @param[in] eflp      pointer to an @p EFlashDriver object
 *
 * @notapi
 */
void efl_lld_start(EFlashDriver *eflp) {

  (void)eflp;

  m251_lld_unlock();
  FMC->ISPCTL |= FMC_ISPCTL_ISPEN_Msk | FMC_ISPCTL_APUEN_Msk;
  m251_lld_lock();
}

/**
 * @brief   Deactivates the Embedded Flash peripheral.
 *
 * @param[in] eflp      pointer to an @p EFlashDriver object
 *
 * @notapi
 */
void efl_lld_stop(EFlashDriver *eflp) {

  (void)eflp;

  m251_lld_unlock();
  FMC->ISPCTL &= ~(FMC_ISPCTL_ISPEN_Msk | FMC_ISPCTL_APUEN_Msk);
  m251_lld_lock();
}

/**
 * @brief   Returns the flash device descriptor.
 *
 * @param[in] instance  pointer to an @p EFlashDriver object
 * @return              Pointer to the flash device descriptor.
 *
 * @notapi
 */
const flash_descriptor_t *efl_lld_get_descriptor(void *instance) {

  return ((EFlashDriver *)instance)->descriptor;
}

/**
 * @brief   Reads data from flash.
 *
 * @param[in] instance  pointer to an @p EFlashDriver object
 * @param[in] offset    flash offset
 * @param[in] n         number of bytes to read
 * @param[out] rp       pointer to the destination buffer
 * @return              An error code.
 * @retval FLASH_NO_ERROR          if the operation succeeded.
 * @retval FLASH_BUSY_ERASING      if an erase operation is in progress.
 * @retval FLASH_ERROR_READ        if the requested range is invalid.
 *
 * @notapi
 */
flash_error_t efl_lld_read(void *instance, flash_offset_t offset,
                           size_t n, uint8_t *rp) {
  EFlashDriver *eflp = (EFlashDriver *)instance;

  if (eflp->state == FLASH_ERASE)
    return FLASH_BUSY_ERASING;
  if (!_efl_range_valid(eflp, offset, n))
    return FLASH_ERROR_READ;

  eflp->state = FLASH_READ;

  memcpy(rp, eflp->descriptor->address + offset, n);

  eflp->state = FLASH_READY;

  return FLASH_NO_ERROR;
}

/**
 * @brief   Programs data into flash.
 *
 * @param[in] instance  pointer to an @p EFlashDriver object
 * @param[in] offset    flash offset
 * @param[in] n         number of bytes to program
 * @param[in] pp        pointer to the source buffer
 * @return              An error code.
 * @retval FLASH_NO_ERROR          if the operation succeeded.
 * @retval FLASH_BUSY_ERASING      if an erase operation is in progress.
 * @retval FLASH_ERROR_PROGRAM     if the requested range is invalid.
 * @retval FLASH_ERROR_HW_FAILURE  if the hardware operation failed.
 *
 * @notapi
 */
M251_EFL_RAM_CODE
flash_error_t efl_lld_program(void *instance, flash_offset_t offset,
                              size_t n, const uint8_t *pp) {
  EFlashDriver *eflp = (EFlashDriver *)instance;
  flash_error_t err;
  flash_offset_t current;

  if (eflp->state == FLASH_ERASE)
    return FLASH_BUSY_ERASING;
  if (!_efl_range_valid(eflp, offset, n))
    return FLASH_ERROR_PROGRAM;

  eflp->state = FLASH_PGM;

  _efl_unlock();

  current = offset;
  while (n > 0U) {
    flash_offset_t word_offset = current & ~(flash_offset_t)3U;
    size_t byte_offset = (size_t)(current & 3U);
    size_t chunk = 4U - byte_offset;
    uint32_t data;
    uint32_t addr;

    if (chunk > n)
      chunk = n;

    addr = (uint32_t)(eflp->descriptor->address + word_offset);
    data = *(const volatile uint32_t *)(eflp->descriptor->address +
                                        word_offset);
    for (size_t i = 0U; i < chunk; ++i) {
      ((uint8_t *)&data)[byte_offset + i] = pp[i];
    }

    FMC->ISPCMD = FMC_ISPCMD_PROGRAM;
    FMC->ISPADDR = addr;
    FMC->ISPDAT = data;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;

    err = _efl_isp_wait();
    if (err != FLASH_NO_ERROR) {
      _efl_lock();
      _efl_cache_invalidate();
      eflp->state = FLASH_READY;
      return err;
    }

    current += (flash_offset_t)chunk;
    pp += chunk;
    n -= chunk;
  }

  _efl_lock();
  _efl_cache_invalidate();
  eflp->state = FLASH_READY;

  return FLASH_NO_ERROR;
}

/**
 * @brief   Starts an erase operation on the whole flash device.
 *
 * @param[in] instance  pointer to an @p EFlashDriver object
 * @return              An error code.
 * @retval FLASH_NO_ERROR      if the operation was started.
 * @retval FLASH_BUSY_ERASING  if an erase operation is already in progress.
 *
 * @notapi
 */
M251_EFL_RAM_CODE
flash_error_t efl_lld_start_erase_all(void *instance) {
  EFlashDriver *eflp = (EFlashDriver *)instance;
  if (eflp->state == FLASH_ERASE)
    return FLASH_BUSY_ERASING;

  eflp->state = FLASH_ERASE;
  eflp->current_sector = 0U;
  eflp->erase_all = true;

  _efl_start_page_erase(eflp, eflp->current_sector);

  return FLASH_NO_ERROR;
}

/**
 * @brief   Starts an erase operation on a flash sector.
 *
 * @param[in] instance  pointer to an @p EFlashDriver object
 * @param[in] sector    sector identifier
 * @return              An error code.
 * @retval FLASH_NO_ERROR      if the operation was started.
 * @retval FLASH_BUSY_ERASING  if an erase operation is already in progress.
 * @retval FLASH_ERROR_ERASE   if the sector identifier is invalid.
 *
 * @notapi
 */
M251_EFL_RAM_CODE
flash_error_t efl_lld_start_erase_sector(void *instance,
                                         flash_sector_t sector) {
  EFlashDriver *eflp = (EFlashDriver *)instance;
  if (eflp->state == FLASH_ERASE)
    return FLASH_BUSY_ERASING;
  if (sector >= eflp->descriptor->sectors_count)
    return FLASH_ERROR_ERASE;

  eflp->state = FLASH_ERASE;
  eflp->current_sector = sector;
  eflp->erase_all = false;

  _efl_start_page_erase(eflp, eflp->current_sector);

  return FLASH_NO_ERROR;
}

/**
 * @brief   Queries the status of an erase operation.
 *
 * @param[in] instance  pointer to an @p EFlashDriver object
 * @param[out] msec     recommended interval before the next query
 * @return              An error code.
 * @retval FLASH_NO_ERROR      if the erase operation is complete.
 * @retval FLASH_BUSY_ERASING  if the erase operation is still in progress.
 * @retval FLASH_ERROR_ERASE   if the hardware operation failed.
 *
 * @notapi
 */
M251_EFL_RAM_CODE
flash_error_t efl_lld_query_erase(void *instance, uint32_t *msec) {
  EFlashDriver *eflp = (EFlashDriver *)instance;

  if (eflp->state != FLASH_ERASE)
    return FLASH_NO_ERROR;

  if ((FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk) != 0U) {
    *msec = 1U;
    return FLASH_BUSY_ERASING;
  }

  if ((FMC->ISPCTL & FMC_ISPCTL_ISPFF_Msk) != 0U) {
    _efl_unlock();
    FMC->ISPCTL |= FMC_ISPCTL_ISPFF_Msk;
    _efl_lock();
    eflp->state = FLASH_READY;
    eflp->erase_all = false;
    return FLASH_ERROR_ERASE;
  }

  if (eflp->erase_all &&
      (eflp->current_sector + 1U < eflp->descriptor->sectors_count)) {
    eflp->current_sector++;
    _efl_cache_invalidate();
    _efl_start_page_erase(eflp, eflp->current_sector);
    *msec = 1U;
    return FLASH_BUSY_ERASING;
  }

  _efl_cache_invalidate();
  eflp->state = FLASH_READY;
  eflp->erase_all = false;

  return FLASH_NO_ERROR;
}

/**
 * @brief   Verifies that a flash sector is erased.
 *
 * @param[in] instance  pointer to an @p EFlashDriver object
 * @param[in] sector    sector identifier
 * @return              An error code.
 * @retval FLASH_NO_ERROR      if the sector is erased.
 * @retval FLASH_ERROR_ERASE   if the sector identifier is invalid.
 * @retval FLASH_ERROR_VERIFY  if the sector is not erased.
 *
 * @notapi
 */
flash_error_t efl_lld_verify_erase(void *instance, flash_sector_t sector) {
  EFlashDriver *eflp = (EFlashDriver *)instance;
  const uint32_t *base;
  uint32_t cnt;

  if (sector >= eflp->descriptor->sectors_count)
    return FLASH_ERROR_ERASE;

  base = (const uint32_t *)(eflp->descriptor->address +
                            sector * M251_FLASH_PAGE_SIZE);
  cnt = M251_FLASH_PAGE_SIZE / sizeof(uint32_t);

  for (uint32_t i = 0U; i < cnt; i++) {
    if (base[i] != 0xFFFFFFFFU)
      return FLASH_ERROR_VERIFY;
  }

  return FLASH_NO_ERROR;
}

#endif /* HAL_USE_EFL == TRUE */

/** @} */

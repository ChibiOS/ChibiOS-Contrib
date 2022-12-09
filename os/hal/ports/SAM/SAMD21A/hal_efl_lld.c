/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
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
 * @file    hal_efl_lld.c
 * @brief   PLATFORM Embedded Flash subsystem low level driver source.
 *
 * @addtogroup HAL_EFL
 * @{
 */

#include "hal.h"
#include <string.h>

#if (HAL_USE_EFL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
#define SAM_FLASH_SECTOR_SIZE      256

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   EFL1 driver identifier.
 */
#if (SAM_EFL_USE_EFL1 == TRUE) || defined(__DOXYGEN__)
EFlashDriver EFLD1;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

typedef union {
  uint16_t  hw[FLASH_PAGE_SIZE / sizeof (uint16_t)];
  uint8_t   b[FLASH_PAGE_SIZE / sizeof (uint8_t)];
} pg_buffer_t;

static const flash_descriptor_t efl_lld_descriptor = {
 .attributes        = FLASH_ATTR_ERASED_IS_ONE |
                      FLASH_ATTR_MEMORY_MAPPED,
 .page_size         = FLASH_PAGE_SIZE,
 .sectors_count     = (FLASH_SIZE - SAM_FLASH_START_OFFSET) / SAM_FLASH_SECTOR_SIZE,
 .sectors           = NULL,
 .sectors_size      = SAM_FLASH_SECTOR_SIZE,
 .address           = (uint8_t *)FLASH_ADDR + SAM_FLASH_START_OFFSET,
 .size              = FLASH_SIZE
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void sam_flash_clear_status(EFlashDriver *eflp) 
{
  eflp->flash->NVMCTRL_STATUS = 0x001F;
}

static inline void sam_flash_exc_cmd(EFlashDriver *eflp, uint16_t cmd)
{
  eflp->flash->NVMCTRL_CTRLA = (uint16_t)(NVMCTRL_CTRLA_CMDEX_KEY | NVMCTRL_CTRLA_CMD(cmd));
}

static inline void sam_flash_set_addr(EFlashDriver *eflp, uint32_t addr)
{
  eflp->flash->NVMCTRL_ADDR = (addr >> 1) & NVMCTRL_ADDR_ADDR_Msk;
}

static inline bool sam_flash_is_busy(EFlashDriver *eflp)
{
  return (eflp->flash->NVMCTRL_INTFLAG & NVMCTRL_INTFLAG_READY_Msk) != NVMCTRL_INTFLAG_READY_Msk;
}

static inline void sam_flash_wait_busy(EFlashDriver *eflp)
{
  while(sam_flash_is_busy(eflp));
}

static inline flash_error_t sam_flash_get_error(EFlashDriver *eflp)
{
  uint16_t stat = (eflp->flash->NVMCTRL_STATUS & (NVMCTRL_STATUS_PROGE_Msk | 
                                                  NVMCTRL_STATUS_NVME_Msk));
  sam_flash_clear_status(eflp);
  if((stat & NVMCTRL_STATUS_NVME_Msk) != 0)
  {
    return FLASH_ERROR_HW_FAILURE;
  }
  if((stat & NVMCTRL_STATUS_PROGE_Msk) != 0)
  {
    return FLASH_ERROR_PROGRAM;
  }
  return FLASH_NO_ERROR;
}

static inline uint16_t read_unaligned_uint16(const void *data)
{
  union {
    uint16_t u16;
    uint8_t u8[2];
  } res;
  const uint8_t *d = (const uint8_t *)data;
  res.u8[0] = d[0];
  res.u8[1] = d[1];
  return res.u16;
}

static flash_error_t sam_flash_page_write(EFlashDriver *eflp, uint8_t *dest, const uint8_t *src, size_t n)
{ 
  osalDbgCheck((eflp != NULL) && ((uint32_t)dest % sizeof(uint16_t) == 0) 
        && (n > 0U) && (n <= FLASH_PAGE_SIZE) && (n % 2 == 0));
  flash_error_t err = FLASH_NO_ERROR;
  n /= 2;
  volatile uint16_t *dst_addr = (volatile uint16_t *)dest;
  const uint16_t *src_addr = (uint16_t *)src;
  sam_flash_wait_busy(eflp);
  sam_flash_exc_cmd(eflp, NVMCTRL_CTRLA_CMD_PBC_Val);
  sam_flash_wait_busy(eflp);
  uint32_t i;
  for (i=0; i<(FLASH_PAGE_SIZE/2) && n; i++) {
    *dst_addr = read_unaligned_uint16(src_addr);
    src_addr++;
    dst_addr++;
    n--;
  }
  sam_flash_exc_cmd(eflp, NVMCTRL_CTRLA_CMD_WP_Val);
  sam_flash_wait_busy(eflp);
  err = sam_flash_get_error(eflp);
  if(memcmp(dest, src, n) != 0) {
    err = FLASH_ERROR_PROGRAM;
  }
  return err;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level Embedded Flash driver initialization.
 *
 * @notapi
 */
void efl_lld_init(void) {

#if SAM_EFL_USE_EFL1 == TRUE
  /* Driver initialization.*/
  eflObjectInit(&EFLD1);
  EFLD1.flash = NVMCTRL_REGS;
#endif
}

/**
 * @brief   Configures and activates the Embedded Flash peripheral.
 *
 * @param[in] eflp      pointer to a @p EFlashDriver structure
 *
 * @notapi
 */
void efl_lld_start(EFlashDriver *eflp) {

  if (eflp->state == FLASH_STOP) {
    /* Enables the peripheral.*/
#if SAM_EFL_USE_EFL1 == TRUE
    if (&EFLD1 == eflp) {

    }
#endif
  }
  /* Configures the peripheral.*/

}

/**
 * @brief   Deactivates the Embedded Flash peripheral.
 *
 * @param[in] eflp      pointer to a @p EFlashDriver structure
 *
 * @notapi
 */
void efl_lld_stop(EFlashDriver *eflp) {

  if (eflp->state == FLASH_READY) {
    /* Resets the peripheral.*/

    /* Disables the peripheral.*/
#if SAM_EFL_USE_EFL1 == TRUE
    if (&EFLD1 == eflp) {

    }
#endif
  }
}

/**
 * @brief   Gets the flash descriptor structure.
 *
 * @param[in] instance              pointer to a @p EFlashDriver instance
 * @return                          A flash device descriptor.
 *
 * @notapi
 */
const flash_descriptor_t *efl_lld_get_descriptor(void *instance) {

  (void)instance;

  return &efl_lld_descriptor;
}

/**
 * @brief   Read operation.
 *
 * @param[in] instance              pointer to a @p EFlashDriver instance
 * @param[in] offset                flash offset
 * @param[in] n                     number of bytes to be read
 * @param[out] rp                   pointer to the data buffer
 * @return                          An error code.
 * @retval FLASH_NO_ERROR           if there is no erase operation in progress.
 * @retval FLASH_BUSY_ERASING       if there is an erase operation in progress.
 * @retval FLASH_ERROR_READ         if the read operation failed.
 * @retval FLASH_ERROR_HW_FAILURE   if access to the memory failed.
 *
 * @notapi
 */
flash_error_t efl_lld_read(void *instance, flash_offset_t offset,
                           size_t n, uint8_t *rp) {
  EFlashDriver *devp = (EFlashDriver *)instance;
  flash_error_t err = FLASH_NO_ERROR;

  osalDbgCheck((instance != NULL) && (rp != NULL) && (n > 0U));
  osalDbgCheck(((size_t)offset + n) <= (size_t)efl_lld_descriptor.size);
  osalDbgAssert((devp->state == FLASH_READY) || (devp->state == FLASH_ERASE),
                "invalid state");

  /* No reading while erasing.*/
  if (devp->state == FLASH_ERASE) {
    return FLASH_BUSY_ERASING;
  }

  /* FLASH_READY state while the operation is performed.*/
  devp->state = FLASH_READ;

  /* IMPLEMENT */
  sam_flash_clear_status(devp);
  memcpy((void *)rp, (const void *)efl_lld_descriptor.address + offset, n);
  /* Ready state again.*/
  devp->state = FLASH_READY;
  return err;
}

/**
 * @brief   Program operation.
 * @note    The device supports ECC, it is only possible to write erased
 *          pages once except when writing all zeroes.
 *
 * @param[in] instance              pointer to a @p EFlashDriver instance
 * @param[in] offset                flash offset
 * @param[in] n                     number of bytes to be programmed
 * @param[in] pp                    pointer to the data buffer
 * @return                          An error code.
 * @retval FLASH_NO_ERROR           if there is no erase operation in progress.
 * @retval FLASH_BUSY_ERASING       if there is an erase operation in progress.
 * @retval FLASH_ERROR_PROGRAM      if the program operation failed.
 * @retval FLASH_ERROR_HW_FAILURE   if access to the memory failed.
 *
 * @notapi
 */
flash_error_t efl_lld_program(void *instance, flash_offset_t offset,
                              size_t n, const uint8_t *pp) {
  EFlashDriver *devp = (EFlashDriver *)instance;
  flash_error_t err = FLASH_NO_ERROR;

  osalDbgCheck((instance != NULL) && (pp != NULL) && (n > 0U));
  osalDbgCheck(((size_t)offset + n) <= (size_t)efl_lld_descriptor.size);

  osalDbgAssert((devp->state == FLASH_READY) || (devp->state == FLASH_ERASE),
                "invalid state");

  /* No programming while erasing.*/
  if (devp->state == FLASH_ERASE) {
    return FLASH_BUSY_ERASING;
  }

  /* FLASH_PGM state while the operation is performed.*/
  devp->state = FLASH_PGM;

  /* IMPLEMENT */
  sam_flash_wait_busy(devp);
  sam_flash_clear_status(devp);
  uint8_t *address;
  /* Programming address aligned to flash lines.*/
  address = (uint8_t *)(efl_lld_descriptor.address + (offset));
  size_t pg_offset = ((uint32_t)address) % FLASH_PAGE_SIZE;
  /* If pg_offset occurred, write fully in that page first */
  if(pg_offset > 0 && n > FLASH_PAGE_SIZE) {
    size_t bytes_writing = FLASH_PAGE_SIZE - pg_offset;
    err = sam_flash_page_write(devp, address, pp, bytes_writing);
    if(err != FLASH_NO_ERROR) {
      goto error;
    }
    address += bytes_writing;
    pp += bytes_writing;
    n -= bytes_writing;
  }

  size_t num_pages = n / FLASH_PAGE_SIZE;
  while(num_pages > 0U) {
    err = sam_flash_page_write(devp, address, pp, FLASH_PAGE_SIZE);
    if(err != FLASH_NO_ERROR) {
      goto error;
    }
    address += FLASH_PAGE_SIZE;
    pp += FLASH_PAGE_SIZE;
    num_pages--;
    n -= FLASH_PAGE_SIZE;
  }
  if(n > 0) {
    err = sam_flash_page_write(devp, address, pp, n);
  }
error:
  /* Ready state again.*/
  devp->state = FLASH_READY;

  return err;
}

/**
 * @brief   Starts a whole-device erase operation.
 * @note    This function only erases bank 2 if it is present. Bank 1 is not
 *          touched because it is where the program is running on.
 *          Pages on bank 1 can be individually erased.
 *
 * @param[in] instance              pointer to a @p EFlashDriver instance
 * @return                          An error code.
 * @retval FLASH_NO_ERROR           if there is no erase operation in progress.
 * @retval FLASH_BUSY_ERASING       if there is an erase operation in progress.
 * @retval FLASH_ERROR_HW_FAILURE   if access to the memory failed.
 *
 * @notapi
 */
flash_error_t efl_lld_start_erase_all(void *instance) {
  (void) instance;
  return FLASH_ERROR_UNIMPLEMENTED;
}

/**
 * @brief   Starts an sector erase operation.
 *
 * @param[in] instance              pointer to a @p EFlashDriver instance
 * @param[in] sector                sector to be erased
 * @return                          An error code.
 * @retval FLASH_NO_ERROR           if there is no erase operation in progress.
 * @retval FLASH_BUSY_ERASING       if there is an erase operation in progress.
 * @retval FLASH_ERROR_HW_FAILURE   if access to the memory failed.
 *
 * @notapi
 */
flash_error_t efl_lld_start_erase_sector(void *instance,
                                         flash_sector_t sector) {
  EFlashDriver *devp = (EFlashDriver *)instance;

  osalDbgCheck(instance != NULL);
  osalDbgCheck(sector < efl_lld_descriptor.sectors_count);
  osalDbgAssert((devp->state == FLASH_READY) || (devp->state == FLASH_ERASE),
                "invalid state");

  /* No erasing while erasing.*/
  if (devp->state == FLASH_ERASE) {
    return FLASH_BUSY_ERASING;
  }

  /* FLASH_PGM state while the operation is performed.*/
  devp->state = FLASH_ERASE;

  /* IMPLEMENT */
  sam_flash_wait_busy(devp);
  sam_flash_clear_status(devp);
  uint32_t address = (uint32_t)(efl_lld_descriptor.address +
                         flashGetSectorOffset(getBaseFlash(devp), sector));
  osalDbgCheck(address % SAM_FLASH_SECTOR_SIZE == 0);
  sam_flash_set_addr(devp, address);
  sam_flash_exc_cmd(devp, NVMCTRL_CTRLA_CMD_ER_Val);
  return FLASH_NO_ERROR;
}

/**
 * @brief   Queries the driver for erase operation progress.
 *
 * @param[in] instance              pointer to a @p EFlashDriver instance
 * @param[out] msec                 recommended time, in milliseconds, that
 *                                  should be spent before calling this
 *                                  function again, can be @p NULL
 * @return                          An error code.
 * @retval FLASH_NO_ERROR           if there is no erase operation in progress.
 * @retval FLASH_BUSY_ERASING       if there is an erase operation in progress.
 * @retval FLASH_ERROR_ERASE        if the erase operation failed.
 * @retval FLASH_ERROR_HW_FAILURE   if access to the memory failed.
 *
 * @api
 */
flash_error_t efl_lld_query_erase(void *instance, uint32_t *msec) {
  EFlashDriver *devp = (EFlashDriver *)instance;
  flash_error_t err = FLASH_NO_ERROR;

  (void)msec;

  /* If there is an erase in progress then the device must be checked.*/
  if (devp->state == FLASH_ERASE) {

    /* IMPLEMENT */
    if(sam_flash_is_busy(devp) == 0) {
      devp->state = FLASH_READY;
      err = sam_flash_get_error(devp);

    }
    else {
      if(msec != NULL) {
        *msec = (uint32_t)SAM_FLASH_WAIT_TIME_MS;
      }
      err = FLASH_BUSY_ERASING;
    }

  }
  else {
    err = FLASH_NO_ERROR;
  }
  return err;
}

/**
 * @brief   Returns the erase state of a sector.
 *
 * @param[in] instance              pointer to a @p EFlashDriver instance
 * @param[in] sector                sector to be verified
 * @return                          An error code.
 * @retval FLASH_NO_ERROR           if the sector is erased.
 * @retval FLASH_BUSY_ERASING       if there is an erase operation in progress.
 * @retval FLASH_ERROR_VERIFY       if the verify operation failed.
 * @retval FLASH_ERROR_HW_FAILURE   if access to the memory failed.
 *
 * @notapi
 */
flash_error_t efl_lld_verify_erase(void *instance, flash_sector_t sector) {
  EFlashDriver *devp = (EFlashDriver *)instance;
  flash_error_t err = FLASH_NO_ERROR;
  uint32_t *address;
  unsigned i;

  osalDbgCheck(instance != NULL);
  osalDbgCheck(sector < efl_lld_descriptor.sectors_count);
  osalDbgAssert((devp->state == FLASH_READY) || (devp->state == FLASH_ERASE),
                "invalid state");

  /* No verifying while erasing.*/
  if (devp->state == FLASH_ERASE) {
    return FLASH_BUSY_ERASING;
  }

  /* IMPLEMENT */
  /* Address of the sector.*/
  address = (uint32_t *)(efl_lld_descriptor.address +
                         flashGetSectorOffset(getBaseFlash(devp), sector));
  devp->state = FLASH_READ;
  osalDbgCheck((uint32_t)address % SAM_FLASH_SECTOR_SIZE == 0);
  /* Scanning the sector space.*/
  for (i = 0U; i < SAM_FLASH_SECTOR_SIZE / sizeof(uint32_t); i++) 
  {
    if (*address != 0xFFFFFFFFUL) {
      err = FLASH_ERROR_VERIFY;
      break;
    }
    address++;
  }

  /* Ready state again.*/
  devp->state = FLASH_READY;

  return err;
}

#endif /* HAL_USE_EFL == TRUE */

/** @} */
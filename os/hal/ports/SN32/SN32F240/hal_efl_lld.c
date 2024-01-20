/*
    ChibiOS - Copyright (C) 2006..2023 Giovanni Di Sirio
    Copyright (C) 2023 Dimitris Mantzouranis

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
 * @brief   SN32F24xB Embedded Flash subsystem low level driver source.
 *
 * @addtogroup HAL_EFL
 * @{
 */

#include <string.h>

#include "hal.h"

#if (HAL_USE_EFL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define SN32_FLASH_LINE_MASK               (SN32_FLASH_LINE_SIZE - 1U)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   EFL1 driver identifier.
 */
EFlashDriver EFLD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static const flash_descriptor_t efl_lld_descriptor = {
 .attributes        = FLASH_ATTR_MEMORY_MAPPED,
 .page_size         = SN32_FLASH_LINE_SIZE,
 .sectors_count     = SN32_FLASH_NUMBER_OF_BANKS *
                      SN32_FLASH_SECTORS_PER_BANK,
 .sectors           = NULL,
 .sectors_size      = SN32_FLASH_SECTOR_SIZE,
 .address           = (uint8_t *)SN32_FLASH_BASE,
 .size              = SN32_FLASH_NUMBER_OF_BANKS *
                      SN32_FLASH_SECTORS_PER_BANK *
                      SN32_FLASH_SECTOR_SIZE
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline void sn32_flash_enable_pgm(EFlashDriver *eflp) {

  eflp->flash->CTRL = SN32_FLASH_CTRL_PG;
}

static inline void sn32_flash_start_pgm(EFlashDriver *eflp) {

  eflp->flash->CTRL |= SN32_FLASH_CTRL_START;
}

static inline void sn32_flash_clear_status(EFlashDriver *eflp) {

  /* Clearing error conditions.*/
  eflp->flash->STATUS_b.ERR = 0;
}

static inline void sn32_flash_wait_busy(EFlashDriver *eflp) {

  /* Wait for busy bit clear.*/
  while ((eflp->flash->STATUS & SN32_FLASH_STATUS_BUSY) != 0U) {
  }
}

static inline flash_error_t sn32_flash_check_errors(EFlashDriver *eflp) {
  uint32_t error = eflp->flash->STATUS_b.ERR;

  /* Clearing error conditions.*/
  eflp->flash->STATUS_b.ERR = 0;

  /* Decoding relevant errors.*/
  if ((error) != 0U) {
    return FLASH_ERROR_HW_FAILURE;
  }

  return FLASH_NO_ERROR;
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

  /* Driver initialization.*/
  eflObjectInit(&EFLD1);
  EFLD1.flash = SN_FLASH;
}

/**
 * @brief   Configures and activates the Embedded Flash peripheral.
 *
 * @param[in] eflp      pointer to a @p EFlashDriver structure
 *
 * @notapi
 */
void efl_lld_start(EFlashDriver *eflp) {
  eflp->flash->CTRL = 0x00000000U;
}

/**
 * @brief   Deactivates the Embedded Flash peripheral.
 *
 * @param[in] eflp      pointer to a @p EFlashDriver structure
 *
 * @notapi
 */
void efl_lld_stop(EFlashDriver *eflp) {

}

/**
 * @brief   Gets the flash descriptor structure.
 *
 * @param[in] ip                    pointer to a @p EFlashDriver instance
 * @return                          A flash device descriptor.
 * @retval                          Pointer to single bank if DBM not enabled.
 * @retval                          Pointer to bank1 if DBM enabled.
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
 * @param[in] ip                    pointer to a @p EFlashDriver instance
 * @param[in] offset                offset within full flash address space
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
  osalDbgCheck((size_t)offset + n <= (size_t)efl_lld_descriptor.size);
  osalDbgAssert((devp->state == FLASH_READY) || (devp->state == FLASH_ERASE),
                "invalid state");

  /* No reading while erasing.*/
  if (devp->state == FLASH_ERASE) {
    return FLASH_BUSY_ERASING;
  }

  /* FLASH_READ state while the operation is performed.*/
  devp->state = FLASH_READ;

  /* Clearing error status bits.*/
  sn32_flash_clear_status(devp);

  /* Actual read implementation.*/
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
 * @param[in] ip                    pointer to a @p EFlashDriver instance
 * @param[in] offset                offset within full flash address space
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
  volatile uint32_t *address;

  osalDbgCheck((instance != NULL) && (pp != NULL) && (n > 0U));
  osalDbgCheck((size_t)offset + n <= (size_t)efl_lld_descriptor.size);
  osalDbgAssert((devp->state == FLASH_READY) || (devp->state == FLASH_ERASE),
                "invalid state");

  /* No programming while erasing.*/
  if (devp->state == FLASH_ERASE) {
    return FLASH_BUSY_ERASING;
  }

  /* FLASH_PGM state while the operation is performed.*/
  devp->state = FLASH_PGM;

  /* Clearing error status bits.*/
  sn32_flash_clear_status(devp);

  /* Enabling PGM mode in the controller.*/
  sn32_flash_enable_pgm(devp);

  /* Calculate the address from the offset. */
  address = (volatile uint32_t *)(efl_lld_descriptor.address +
                         (offset & ~SN32_FLASH_LINE_MASK));

  if (address < (volatile uint32_t *)SN32_JUMPLOADER_SIZE) {
      return FLASH_ERROR_HW_FAILURE;
  }

  devp->flash->ADDR = (uint32_t)address;

  sn32_flash_wait_busy(devp);

  /* Actual program implementation.*/
  do {
    // Programming line
    devp->flash->DATA = *((uint32_t *)pp);
    sn32_flash_wait_busy(devp);
    
    // Move to the next data and address
     pp += SN32_FLASH_LINE_SIZE;
     offset += SN32_FLASH_LINE_SIZE;
     n -= SN32_FLASH_LINE_SIZE;
    }
    while ((n > 0U) & ((offset & SN32_FLASH_LINE_MASK) != 0U));

  err = sn32_flash_check_errors(devp);
  if (err != FLASH_NO_ERROR) {
    return err;
  }
  // Programming start
  sn32_flash_start_pgm(devp);
  sn32_flash_wait_busy(devp);
  err = sn32_flash_check_errors(devp);
  if (err != FLASH_NO_ERROR) {
    return err;
  }

  /* Ready state again.*/
  devp->state = FLASH_READY;

  return err;
}

/**
 * @brief   Starts a whole-device erase operation.
 * @note    This function only erases bank 2 if it is present. Bank 1 is not
 *          allowed since it is normally where the primary program is located.
 *          Pages on bank 1 can be individually erased.
 *
 * @param[in] ip                    pointer to a @p EFlashDriver instance
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
 * @param[in] ip                    pointer to a @p EFlashDriver instance
 * @param[in] sector                sector to be erased
 *                                  this is an index within the total sectors
 *                                  in a flash bank
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

  /* Clearing error status bits.*/
  sn32_flash_clear_status(devp);

  /* Enable page erase.*/
  devp->flash->CTRL = SN32_FLASH_CTRL_PER;

  /* Set the page.*/
  devp->flash->ADDR = (uint32_t)(efl_lld_descriptor.address +
                         flashGetSectorOffset(getBaseFlash(devp), sector));
  sn32_flash_wait_busy(devp);

  /* Start the erase.*/
  sn32_flash_start_pgm(devp);
  sn32_flash_wait_busy(devp);
  return FLASH_NO_ERROR;
}

/**
 * @brief   Queries the driver for erase operation progress.
 *
 * @param[in] ip                    pointer to a @p EFlashDriver instance
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

  /* If there is an erase in progress then the device must be checked.*/
  if (devp->state == FLASH_ERASE) {

    /* Checking for operation in progress.*/
    if ((devp->flash->STATUS & SN32_FLASH_STATUS_BUSY) == 0U) {

      /* Disabling the various erase control bits.*/
      devp->flash->CTRL &= ~(SN32_FLASH_CTRL_PER | SN32_FLASH_CTRL_MER);

      /* Back to ready state.*/
      devp->state = FLASH_READY;
    }
    else {
      /* Recommended time before polling again. This is a simplified
         implementation.*/
      if (msec != NULL) {
        *msec = (uint32_t)SN32_FLASH_WAIT_TIME_MS;
      }

      err = FLASH_BUSY_ERASING;
    }
  }

  return err;
}

/**
 * @brief   Returns the erase state of a sector.
 *
 * @param[in] ip                    pointer to a @p EFlashDriver instance
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
  uint32_t *address;
  flash_error_t err = FLASH_NO_ERROR;
  unsigned i;

  osalDbgCheck(instance != NULL);
  osalDbgCheck(sector < efl_lld_descriptor.sectors_count);
  osalDbgAssert((devp->state == FLASH_READY) || (devp->state == FLASH_ERASE),
                "invalid state");

  /* No verifying while erasing.*/
  if (devp->state == FLASH_ERASE) {
    return FLASH_BUSY_ERASING;
  }

  /* Address of the sector.*/
  address = (uint32_t *)(SN32_FLASH_BASE +
                         flashGetSectorOffset(getBaseFlash(devp), sector));

  /* FLASH_READ state while the operation is performed.*/
  devp->state = FLASH_READ;

  /* Scanning the sector space.*/
  uint32_t sector_size = flashGetSectorSize(getBaseFlash(devp), sector);
  for (i = 0U; i < sector_size / sizeof(uint32_t); i++) {
    if (*address != 0x00000000U) {
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

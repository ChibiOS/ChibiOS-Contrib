/*
    Copyright (C) 2021...2022 Westberry Technology (ChangZhou) Corp., Ltd

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

#include <string.h>

#include "hal.h"

#if (HAL_USE_EFL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define WB32_FLASH_LINE_SIZE                8U
#define WB32_FLASH_LINE_MASK                (WB32_FLASH_LINE_SIZE - 1U)

#define WB32_FLASH_PAGE_SIZE                256U
#define WB32_FLASH_PAGE_MASK                (WB32_FLASH_PAGE_SIZE - 1U)

#define FLASH_OP_RAM_CODE                   {0xBF006008, 0x06006808, 0x4770D4FC}

static const uint32_t pre_op_code[] = {0x4FF0E92D, 0x21034832, 0x210C6281, 0xF8DF62C1, 0x2100C0C4, 0x1000F8CC, 0xF44F4608, 0x1C40767A, 0xDBFC42B0, 0xF8CC2201, 0x20002000, 0x42B01C40, 0x4829DBFC, 0xF0436803, 0x60030380, 0x302C4826, 0xF4436803, 0x60036320, 0x46104691, 0x323C4A22, 0x468A6010, 0x49214608, 0x48216008, 0x0340F8D0, 0x25004F1E, 0x5107F3C0, 0x3BFFF04F, 0x22001F3F, 0x4610465C, 0xEA5F683B, 0xD10678C0, 0xD10142A3, 0xE0002401, 0x44222400, 0x1C40461C, 0xDBF12814, 0xD91B2A02, 0xD9012910, 0xE0003910, 0x480D2100, 0x68021F00, 0x627FF022, 0x5201EA42, 0xF8CC6002, 0x2000A000, 0x42B01C40, 0xF8CCDBFC, 0x20009000, 0x42B01C40, 0x1C6DDBFC, 0xDBD02D05, 0x8FF0E8BD, 0x40010000, 0x40010438, 0x40010C20, 0x4000B804, 0x1FFFF000};
#define PRE_OP() ((void (*)(void))((unsigned int)(pre_op_code) | 0x01))()

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
 .page_size         = WB32_FLASH_LINE_SIZE,
 .sectors_count     = WB32_FLASH_NUMBER_OF_BANKS *
                      WB32_FLASH_SECTORS_PER_BANK,
 .sectors           = NULL,
 .sectors_size      = WB32_FLASH_SECTOR_SIZE,
 .address           = (uint8_t *)FLASH_BASE,
 .size              = WB32_FLASH_NUMBER_OF_BANKS *
                      WB32_FLASH_SECTORS_PER_BANK *
                      WB32_FLASH_SECTOR_SIZE
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static inline uint8_t wb32_flash_op_exec(EFlashDriver *eflp, uint32_t op) {
  volatile uint32_t flash_op_ram_code[] = FLASH_OP_RAM_CODE;

  /* Start FLASH operation and wait for a FLASH operation to complete  */
  RCC->PCLKENR     = 0x01;
  eflp->flash->CON = 0x7F5F0D40 | (op & 0x1F); /* [14:8]=0x0D, WREN=1, [4:0]=op */
  eflp->flash->KEY = 0x5188DA08;
  eflp->flash->KEY = 0x12586590;
  ((void(*)(uint32_t, uint32_t))((unsigned int)(flash_op_ram_code) | 0x01))(0x00800080, FMC_BASE);

  RCC->PCLKENR     = 0x00;
  /* Clear WREN and OP[4:0] bits */
  eflp->flash->CON = 0x005F0000;

  if (eflp->flash->STAT & FMC_STAT_ERR)
    return 1; /* Any error occur */
  else
    return 0; /* FLASH operation complete */
}

static inline flash_error_t wb32_flash_program_page(EFlashDriver *eflp, uint32_t page_addr) {
  uint8_t ret;
  int     state;

  state = __get_PRIMASK();
  __disable_irq();
  PRE_OP();
  eflp->flash->ADDR = page_addr;
  ret               = wb32_flash_op_exec(eflp, 0x0C);
  if (!state) {
      __enable_irq();
  }

  if (ret)
    return FLASH_ERROR_PROGRAM;
  else
    return FLASH_NO_ERROR;
}

static inline flash_error_t wb32_flash_erase_page(EFlashDriver *eflp, uint32_t page_addr) {
  uint8_t ret;
  int     state;

  state = __get_PRIMASK();
  __disable_irq();
  PRE_OP();
  eflp->flash->ADDR = page_addr;
  ret               = wb32_flash_op_exec(eflp, 0x08);
  if (!state) {
      __enable_irq();
  }

  if (ret)
    return FLASH_ERROR_ERASE;
  else
    return FLASH_NO_ERROR;
}

static inline flash_error_t wb32_flash_clear_page_latch(EFlashDriver *eflp) {
  uint8_t ret;
  int     state;

  state = __get_PRIMASK();
  __disable_irq();
  ret = wb32_flash_op_exec(eflp, 0x04);
  if (!state) {
      __enable_irq();
  }

  if (ret)
    return FLASH_ERROR_PROGRAM;
  else
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
  EFLD1.flash = FMC;
}

/**
 * @brief   Configures and activates the Embedded Flash peripheral.
 *
 * @param[in] eflp      pointer to a @p EFlashDriver structure
 *
 * @notapi
 */
void efl_lld_start(EFlashDriver *eflp) {

  PWR->ANAKEY1 = 0x03;
  PWR->ANAKEY2 = 0x0C;
  /* Enables or disables the Internal 48MHz oscillator (FHSI). */
  ANCTL->FHSIENR = ENABLE;
  /* Locks write to ANCTL registers */
  PWR->ANAKEY1 = 0x00;
  PWR->ANAKEY2 = 0x00;
}

/**
 * @brief   Deactivates the Embedded Flash peripheral.
 *
 * @param[in] eflp      pointer to a @p EFlashDriver structure
 *
 * @notapi
 */
void efl_lld_stop(EFlashDriver *eflp) {

  /* Lock flash. */
  eflp->flash->KEY = 0x00;
  eflp->flash->KEY = 0x00;
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

  /* Actual read implementation.*/
  memcpy((void *)rp, (const void *)(efl_lld_descriptor.address + offset), n);

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

  /* Actual program implementation.*/
  while (n > 0U) {
    volatile uint32_t *address;

    union {
      uint32_t  w[WB32_FLASH_PAGE_SIZE / sizeof (uint32_t)];
      uint8_t   b[WB32_FLASH_PAGE_SIZE / sizeof (uint8_t)];
    } line;

    /* Programming address aligned to flash pages.*/
    address = (volatile uint32_t *)(efl_lld_descriptor.address +
                                    (offset & ~WB32_FLASH_PAGE_MASK));

    memcpy((void *)&line.b[0], (const void *)address, WB32_FLASH_PAGE_SIZE);

    /* Copying data inside the prepared page.*/
    do {
      line.b[offset & WB32_FLASH_PAGE_MASK] = *pp;
      offset++;
      n--;
      pp++;
    } while ((n > 0U) & ((offset & WB32_FLASH_PAGE_MASK) != 0U));

#ifndef WB32_FLASH_PROGRAM_NO_ERASE
    bool ferase = true;
#else
    bool ferase = false;
to_erase:
#endif
    /* Erase page. */
    if (ferase) {
      err = wb32_flash_erase_page(devp, (uint32_t)address);
      if (err != FLASH_NO_ERROR) {
          break;
      }
    }

    /* Clear page latch. */
    err = wb32_flash_clear_page_latch(devp);
    if (err != FLASH_NO_ERROR) {
      break;
    }

    for (int i = 0; i < (WB32_FLASH_PAGE_SIZE / sizeof(uint32_t)); i++) {
      devp->flash->BUF[i] = line.w[i];
    }

    /* Programming page.*/
    err = wb32_flash_program_page(devp, (uint32_t)address);
    if (err != FLASH_NO_ERROR) {
      break;
    }

    /* Check for flash error.*/
    if (memcmp(&line.w[0], (void *)address, WB32_FLASH_PAGE_SIZE) != 0) {
#ifdef WB32_FLASH_PROGRAM_NO_ERASE
      if (!ferase) {
          ferase = true;
          goto to_erase;
      }
#endif
      err = FLASH_ERROR_PROGRAM;
      break;
    }
  }

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
  flash_error_t err = FLASH_NO_ERROR;

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

  /* Set the page.*/

  err = wb32_flash_erase_page(devp, (uint32_t)(efl_lld_descriptor.address +
                              flashGetSectorOffset(getBaseFlash(devp), sector)));

  return err;
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

    /* Checking for operation in progress.*/
    if ((devp->flash->CON & FMC_CON_WR) == 0U) {

      /* Back to ready state.*/
      devp->state = FLASH_READY;

      err = FLASH_NO_ERROR;
    }
    else {
      /* Recommended time before polling again, this is a simplified
         implementation.*/
      if (msec != NULL) {
        *msec = (uint32_t)WB32_FLASH_WAIT_TIME_MS;
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

  osalDbgCheck(instance != NULL);
  osalDbgCheck(sector < efl_lld_descriptor.sectors_count);
  osalDbgAssert((devp->state == FLASH_READY) || (devp->state == FLASH_ERASE),
                "invalid state");

  /* No verifying while erasing.*/
  if (devp->state == FLASH_ERASE) {
    return FLASH_BUSY_ERASING;
  }

  /* Address of the sector.*/
  address = (uint32_t *)(efl_lld_descriptor.address +
                         flashGetSectorOffset(getBaseFlash(devp), sector));

  /* FLASH_READY state while the operation is performed.*/
  devp->state = FLASH_READ;

  /* Scanning the sector space.*/
  for (int i = 0U; i < WB32_FLASH_SECTOR_SIZE / sizeof(uint32_t); i++) {
    if (*address != 0x00) {
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

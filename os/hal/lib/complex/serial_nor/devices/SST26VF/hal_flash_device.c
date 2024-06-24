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
 * @file    hal_flash_device.c
 * @brief   SST26VF serial flash driver code.
 *
 * @addtogroup SST26VF
 * @{
 */

#include <string.h>
#include <stdint.h>

#include "sst26vf.h"
#include "hal.h"
#include "hal_serial_nor.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define PAGE_SIZE                           256U
#define PAGE_MASK                           (PAGE_SIZE - 1U)

#if SST26VF_USE_SUB_SECTORS == TRUE
#define SECTOR_SIZE                         0x00001000U
#define CMD_SECTOR_ERASE                    SST26VF_CMD_SUBSECTOR_ERASE
#else
#define SECTOR_SIZE                         0x00010000U
#define CMD_SECTOR_ERASE                    SST26VF_CMD_SECTOR_ERASE
#endif

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   SST26VF descriptor.
 */
flash_descriptor_t snor_descriptor = {
  .attributes       = FLASH_ATTR_SUSPEND_ERASE_CAPABLE,
  .page_size        = PAGE_SIZE,
  .sectors_count    = 0U,           /* It is overwritten.*/
  .sectors          = NULL,
  .sectors_size     = SECTOR_SIZE,
  .address          = 0U,
  .size             = 0U            /* It is overwritten.*/

};

#if (SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI) || defined(__DOXYGEN__)
#if (WSPI_SUPPORTS_MEMMAP == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   Fast read command for memory mapped mode.
 */

 // Note: Don't know What this is. 
const wspi_command_t snor_memmap_read = {
  // Note: waht's the dummy cycles mean? 
  .cmd              = SST26VF_CMD_FAST_READ,
  .addr             = 0,
  .dummy            = SST26VF_READ_DUMMY_CYCLES - 2,
  .cfg              = WSPI_CFG_ADDR_SIZE_24 |
#if SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI1L
                      WSPI_CFG_CMD_MODE_ONE_LINE |
                      WSPI_CFG_ADDR_MODE_ONE_LINE |
                      WSPI_CFG_DATA_MODE_ONE_LINE |
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI2L
                      WSPI_CFG_CMD_MODE_TWO_LINES |
                      WSPI_CFG_ADDR_MODE_TWO_LINES |
                      WSPI_CFG_DATA_MODE_TWO_LINES |
#else
                      WSPI_CFG_CMD_MODE_FOUR_LINES |
                      WSPI_CFG_ADDR_MODE_FOUR_LINES |
                      WSPI_CFG_DATA_MODE_FOUR_LINES |
#endif
                      WSPI_CFG_ALT_MODE_FOUR_LINES |  /* Always 4 lines, note.*/
                      WSPI_CFG_ALT_SIZE_8 |
                      WSPI_CFG_SIOO
};
#endif
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

#if SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI
/* Initial SST26VF_CMD_READ_ID command.*/
static const wspi_command_t sst26vf_cmd_read_id = {
  .cmd              = SST26VF_CMD_READ_MFG_ID,
  .cfg              = 0U |
#if SST26VF_SWITCH_WIDTH == TRUE
                      WSPI_CFG_CMD_MODE_ONE_LINE |
                      WSPI_CFG_DATA_MODE_ONE_LINE,
#else
#if SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI1L
                      WSPI_CFG_CMD_MODE_ONE_LINE |
                      WSPI_CFG_DATA_MODE_ONE_LINE,
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI2L
                      WSPI_CFG_CMD_MODE_TWO_LINES |
                      WSPI_CFG_DATA_MODE_TWO_LINES,
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI4L
                      WSPI_CFG_CMD_MODE_FOUR_LINES |
                      WSPI_CFG_DATA_MODE_FOUR_LINES,
#else
                      WSPI_CFG_CMD_MODE_EIGHT_LINES |
                      WSPI_CFG_DATA_MODE_EIGHT_LINES,
#endif
#endif
  .addr             = 0,
  .alt              = 0,
  .dummy            = 0
};

/* Initial SST26VF_CMD_WRITE_STATUS_REGISTERS command.*/
static const wspi_command_t sst26vf_write_cfg_reg = {
  .cmd              = SST26VF_CMD_WRITE_STATUS_REGISTERS,
  .cfg              = 0U |
#if SST26VF_SWITCH_WIDTH == TRUE
                      WSPI_CFG_CMD_MODE_ONE_LINE |
                      WSPI_CFG_DATA_MODE_ONE_LINE,
#else
#if SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI1L
                      WSPI_CFG_CMD_MODE_ONE_LINE |
                      WSPI_CFG_DATA_MODE_ONE_LINE,
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI2L
                      WSPI_CFG_CMD_MODE_TWO_LINES |
                      WSPI_CFG_DATA_MODE_TWO_LINES,
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI4L
                      WSPI_CFG_CMD_MODE_FOUR_LINES |
                      WSPI_CFG_DATA_MODE_FOUR_LINES,
#else
                      WSPI_CFG_CMD_MODE_EIGHT_LINES |
                      WSPI_CFG_DATA_MODE_EIGHT_LINES,
#endif
#endif
  .addr             = 0,
  .alt              = 0,
  .dummy            = 0
};

/* Initial SST26VF_CMD_WRITE_ENABLE command.*/
static const wspi_command_t sst26vf_cmd_write_enable = {
  .cmd              = SST26VF_CMD_WRITE_ENABLE,
  .cfg              = 0U |
#if SST26VF_SWITCH_WIDTH == TRUE
                      WSPI_CFG_CMD_MODE_ONE_LINE,
#else
#if SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI1L
                      WSPI_CFG_CMD_MODE_ONE_LINE,
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI2L
                      WSPI_CFG_CMD_MODE_TWO_LINES,
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI4L
                      WSPI_CFG_CMD_MODE_FOUR_LINES,
#else
                      WSPI_CFG_CMD_MODE_EIGHT_LINES,
#endif
#endif
  .addr             = 0,
  .alt              = 0,
  .dummy            = 0
};

/* Bus width initialization.*/
#if SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI1L
static const uint8_t sst26vf_evconf_value[1] = {0xCF};
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI2L
static const uint8_t sst26vf_evconf_value[1] = {0x8F};
#else
static const uint8_t sst26vf_evconf_value[1] = {0x4F};
#endif
#endif /* SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI */

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief amendment to hal_serial_nor.c bus_cmd_send function to add receive functionalities
 without having to send another command
 * 
 * @param busp pointer to the bus driver
 * @param cmd instruction code
 * @param read to receive right after send or not
 * @param tx_size number of bytes to send
 * @param tx_ptr data buffer
 * @param rx_size number of bytes to receive
 * @param rx_ptr data buffer
 */
static void bus_cmd_send_receive(BUSDriver *busp, uint32_t cmd, bool read,
                  size_t tx_size, const uint8_t *tx_ptr, 
                  size_t rx_size, const uint8_t *rx_ptr)
{
  /* Only supporting SPI mode*/
  uint8_t buf[1];
  spiSelect(busp);
  buf[0] = cmd;
  spiSend(busp, 1, buf);
  spiSend(busp, tx_size, tx_ptr);
  if (read)
  {
    spiReceive(busp, rx_size, rx_ptr);
  }
  spiUnselect(busp);
}

static bool sst26vf_find_id(const uint8_t *set, size_t size, uint8_t element) {
  size_t i;

  for (i = 0; i < size; i++) {
    if (set[i] == element) {
      return true;
    }
  }
  return false;
}

static flash_error_t sst26vf_poll_status(SNORDriver *devp) {
  uint8_t sts[1];
  do {
#if SST26VF_NICE_WAITING == TRUE
    osalThreadSleepMilliseconds(1);
#endif
  bus_cmd_receive(devp->config->busp, SST26VF_CMD_READ_STATUS_REGISTER,
                  1U, sts);
  } while (
    (((sts[0] << SST26VF_REG_BUSY_POS) & SST26VF_REG_BUSY) != 0U) | 
    (((sts[0] << SST26VF_REG_BUSY_2_POS) & SST26VF_REG_BUSY_2) != 0U) | 
    (((sts[0] << SST26VF_REG_WSE_POS) & SST26VF_REG_WSE) != 0U) | 
    (((sts[0] << SST26VF_REG_WSP_POS) & SST26VF_REG_WSP) != 0U)
  );
  return FLASH_NO_ERROR;

}

#if (SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI) || defined(__DOXYGEN__)
static void sst26vf_reset_memory(SNORDriver *devp) {

  /* 1x SST26VF_CMD_RESET_ENABLE command.*/
  static const wspi_command_t cmd_reset_enable_1 = {
    .cmd              = SST26VF_CMD_RESET_ENABLE,
    .cfg              = WSPI_CFG_CMD_MODE_ONE_LINE,
    .addr             = 0,
    .alt              = 0,
    .dummy            = 0
  };

  /* 1x SST26VF_CMD_RESET_MEMORY command.*/
  static const wspi_command_t cmd_reset_memory_1 = {
    .cmd              = SST26VF_CMD_RESET_MEMORY,
    .cfg              = WSPI_CFG_CMD_MODE_ONE_LINE,
    .addr             = 0,
    .alt              = 0,
    .dummy            = 0
  };

  /* If the device is in one bit mode then the following commands are
     rejected because shorter than 8 bits. If the device is in multiple
     bits mode then the commands are accepted and the device is reset to
     one bit mode.*/
#if SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI4L
  /* 4x SST26VF_CMD_RESET_ENABLE command.*/
  static const wspi_command_t cmd_reset_enable_4 = {
    .cmd              = SST26VF_CMD_RESET_ENABLE,
    .cfg              = WSPI_CFG_CMD_MODE_FOUR_LINES,
    .addr             = 0,
    .alt              = 0,
    .dummy            = 0
  };

  /* 4x SST26VF_CMD_RESET_MEMORY command.*/
  static const wspi_command_t cmd_reset_memory_4 = {
    .cmd              = SST26VF_CMD_RESET_MEMORY,
    .cfg              = WSPI_CFG_CMD_MODE_FOUR_LINES,
    .addr             = 0,
    .alt              = 0,
    .dummy            = 0
  };

  wspiCommand(devp->config->busp, &cmd_reset_enable_4);
  wspiCommand(devp->config->busp, &cmd_reset_memory_4);
#else
  /* 2x SST26VF_CMD_RESET_ENABLE command.*/
  static const wspi_command_t cmd_reset_enable_2 = {
    .cmd              = SST26VF_CMD_RESET_ENABLE,
    .cfg              = WSPI_CFG_CMD_MODE_TWO_LINES,
    .addr             = 0,
    .alt              = 0,
    .dummy            = 0
  };

  /* 2x SST26VF_CMD_RESET_MEMORY command.*/
  static const wspi_command_t cmd_reset_memory_2 = {
    .cmd              = SST26VF_CMD_RESET_MEMORY,
    .cfg              = WSPI_CFG_CMD_MODE_TWO_LINES,
    .addr             = 0,
    .alt              = 0,
    .dummy            = 0
  };

  wspiCommand(devp->config->busp, &cmd_reset_enable_2);
  wspiCommand(devp->config->busp, &cmd_reset_memory_2);
#endif

  /* Now the device should be in one bit mode for sure and we perform a
     device reset.*/
  wspiCommand(devp->config->busp, &cmd_reset_enable_1);
  wspiCommand(devp->config->busp, &cmd_reset_memory_1);
}
#endif /* SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI */

static const uint8_t sst26vf_manufacturer_ids[] = SST26VF_SUPPORTED_MANUFACTURE_IDS;

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

void snor_device_init(SNORDriver *devp) {
  /** Letting voltages stabilize */
  osalThreadSleepMilliseconds(10);
  
  bus_cmd(devp->config->busp, SST26VF_CMD_RESET_ENABLE);
  bus_cmd(devp->config->busp, SST26VF_CMD_RESET_MEMORY);

#if SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_SPI
  /* Reading device ID.*/
  osalThreadSleepMilliseconds(1000);
  bus_cmd_receive(devp->config->busp, SST26VF_CMD_READ_JEDEC_ID,
                  3U, &devp->nocache->buf[0]);
#else /* SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI */
  /* Attempting a reset of the XIP mode, it could be in an unexpected state
     because a CPU reset does not reset the memory too.*/
  snor_reset_xip(devp);

  /* Attempting a reset of the device, it could be in an unexpected state
     because a CPU reset does not reset the memory too.*/
  // sst26vf_reset_memory(devp);

  /* Reading device ID and unique ID.*/
  wspiReceive(devp->config->busp, &sst26vf_cmd_read_id,
              3U, &devp->nocache->buf[0]);
#endif /* SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI */

  /* Checking if the device is white listed.*/
  osalDbgAssert(sst26vf_find_id(sst26vf_manufacturer_ids,
                             sizeof sst26vf_manufacturer_ids,
                             devp->nocache->buf[0]),
                "invalid manufacturer id");

#if (SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI) && (SST26VF_SWITCH_WIDTH == TRUE)
  /* Setting up final bus width.*/
  wspiCommand(devp->config->busp, &sst26vf_cmd_write_enable);
  wspiSend(devp->config->busp, &sst26vf_cmd_write_evconf, 1, sst26vf_evconf_value);

  {
    /* Reading ID again for confirmation.*/
    bus_cmd_receive(devp->config->busp, SST26VF_CMD_MULTIPLE_IO_READ_ID,
                    3U, &devp->nocache->buf[16]);

    /* Checking if the device is white listed.*/
    osalDbgAssert(memcmp(&devp->nocache->buf[0],
                         &devp->nocache->buf[16],
                         3U) == 0,
                  "id confirmation failed");
  }
#endif

  snor_descriptor.size = (size_t)SIZE_64MB;
  snor_descriptor.sectors_count = (size_t)(SIZE_64MB / SECTOR_SIZE);

  bus_cmd(devp->config->busp, SST26VF_CMD_GLOBAL_BLOCK_PROTECTION_UNLOCK);
#if SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI
    osalDbgAssert(false, "WSPI mode is not supported yet for this device");
#endif
}

flash_error_t snor_device_read(SNORDriver *devp, flash_offset_t offset,
                               size_t n, uint8_t *rp) {

#if SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI
  /* Fast read command in WSPI mode.*/
  bus_cmd_addr_dummy_receive(devp->config->busp, SST26VF_CMD_FAST_READ,
                             offset, SST26VF_READ_DUMMY_CYCLES, n, rp);
#else
  /* Normal read command in SPI mode.*/
  bus_cmd_addr_receive(devp->config->busp, SST26VF_CMD_READ,
                       offset, n, rp);
#endif

  return FLASH_NO_ERROR;
}

flash_error_t snor_device_program(SNORDriver *devp, flash_offset_t offset,
                                  size_t n, const uint8_t *pp) {
  bus_cmd(devp->config->busp, SST26VF_CMD_GLOBAL_BLOCK_PROTECTION_UNLOCK);
  /* Data is programmed page by page.*/
  while (n > 0U) {
    flash_error_t err;

    /* Data size that can be written in a single program page operation.*/
    size_t chunk = (size_t)(((offset | PAGE_MASK) + 1U) - offset);
    if (chunk > n) {
      chunk = n;
    }

    /* Enabling write operation.*/
    bus_cmd(devp->config->busp, SST26VF_CMD_WRITE_ENABLE);

    /* Page program command.*/
    bus_cmd_addr_send(devp->config->busp, SST26VF_CMD_PAGE_PROGRAM, offset,
                      chunk, pp);

    /* Wait for status and check errors.*/
    err = sst26vf_poll_status(devp);
    if (err != FLASH_NO_ERROR) {

      return err;
    }

    /* Next page.*/
    offset += chunk;
    pp     += chunk;
    n      -= chunk;
  }

  return FLASH_NO_ERROR;
}

flash_error_t snor_device_start_erase_all(SNORDriver *devp) {
  bus_cmd(devp->config->busp, SST26VF_CMD_GLOBAL_BLOCK_PROTECTION_UNLOCK);
  /* Enabling write operation.*/
  bus_cmd(devp->config->busp, SST26VF_CMD_WRITE_ENABLE);

  /* Bulk erase command.*/
  bus_cmd(devp->config->busp, SST26VF_CMD_CHIP_ERASE_1);

  return FLASH_NO_ERROR;
}

flash_error_t snor_device_start_erase_sector(SNORDriver *devp,
                                             flash_sector_t sector) {
  bus_cmd(devp->config->busp, SST26VF_CMD_GLOBAL_BLOCK_PROTECTION_UNLOCK);
  flash_offset_t offset = (flash_offset_t)(sector * SECTOR_SIZE);

  /* Enabling write operation.*/
  bus_cmd(devp->config->busp, SST26VF_CMD_WRITE_ENABLE);

  /* Sector erase command.*/
  bus_cmd_addr(devp->config->busp, SST26VF_CMD_SECTOR_ERASE, offset);

  return FLASH_NO_ERROR;
}

flash_error_t snor_device_verify_erase(SNORDriver *devp,
                                       flash_sector_t sector) {
  uint8_t cmpbuf[SST26VF_COMPARE_BUFFER_SIZE];
  flash_offset_t offset;
  size_t n;

  /* Read command.*/
  offset = (flash_offset_t)(sector * SECTOR_SIZE);
  n = SECTOR_SIZE;
  while (n > 0U) {
    uint8_t *p;

#if SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI
    osalDbgAssert(false, "WSPI mode is not supported yet for this device");
#else
   /* Normal read command in SPI mode.*/
   bus_cmd_addr_receive(devp->config->busp, SST26VF_CMD_READ,
                        offset, sizeof cmpbuf, cmpbuf);
#endif

    /* Checking for erased state of current buffer.*/
    for (p = cmpbuf; p < &cmpbuf[SST26VF_COMPARE_BUFFER_SIZE]; p++) {
      if (*p != 0xFFU) {
        return FLASH_ERROR_VERIFY;
      }
    }

    offset += sizeof cmpbuf;
    n -= sizeof cmpbuf;
  }

  return FLASH_NO_ERROR;
}

flash_error_t snor_device_query_erase(SNORDriver *devp, uint32_t *msec) {
  uint8_t sts[1];

  bus_cmd_receive(devp->config->busp, SST26VF_CMD_READ_STATUS_REGISTER,
                  1U, sts);

  /* If the P/E bit is zero (busy) or the flash in a suspended state then
     report that the operation is still in progress.*/
  if(
        (((sts[0] << SST26VF_REG_BUSY_POS) & SST26VF_REG_BUSY) != 0U) | 
        (((sts[0] << SST26VF_REG_BUSY_2_POS) & SST26VF_REG_BUSY_2) != 0U) | 
        (((sts[0] << SST26VF_REG_WSE_POS) & SST26VF_REG_WSE) != 0U) | 
        (((sts[0] << SST26VF_REG_WSP_POS) & SST26VF_REG_WSP) != 0U) 
      )
  {
    /* Recommended time before polling again, this is a simplified
       implementation.*/
    if (msec != NULL) {
      *msec = 1U;
    }

    return FLASH_BUSY_ERASING;
  }

  return FLASH_NO_ERROR;
}

flash_error_t snor_device_read_sfdp(SNORDriver *devp, flash_offset_t offset,
                                    size_t n, uint8_t *rp) {

  (void)devp;
  (void)rp;
  (void)offset;
  (void)n;
  // not supported currently
  return FLASH_NO_ERROR;
}

#if (SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI) || defined(__DOXYGEN__)
void snor_activate_xip(SNORDriver *devp) {
  static const uint8_t flash_status_xip[1] = {
    (SST26VF_READ_DUMMY_CYCLES << 4U) | 0x07U
  };

  /* Activating XIP mode in the device.*/
  bus_cmd(devp->config->busp, SST26VF_CMD_WRITE_ENABLE);
  bus_cmd_send(devp->config->busp, SST26VF_CMD_WRITE_STATUS_REGISTERS,
               1, flash_status_xip);
}

void snor_reset_xip(SNORDriver *devp) {
  static const uint8_t flash_conf[1] = {
    (SST26VF_READ_DUMMY_CYCLES << 4U) | 0x0FU
  };
  wspi_command_t cmd;
  uint8_t buf[1];

  /* Resetting XIP mode by reading one byte without XIP confirmation bit.*/
  cmd.cmd   = 0U;
  cmd.alt   = 0xFFU;
  cmd.addr  = 0U;
  cmd.dummy = SST26VF_READ_DUMMY_CYCLES - 2U;
  cmd.cfg   = WSPI_CFG_CMD_MODE_NONE |
              WSPI_CFG_ADDR_SIZE_24 |
#if SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI1L
              WSPI_CFG_ADDR_MODE_ONE_LINE |
              WSPI_CFG_DATA_MODE_ONE_LINE |
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI2L
              WSPI_CFG_ADDR_MODE_TWO_LINES |
              WSPI_CFG_DATA_MODE_TWO_LINES |
#elif SST26VF_BUS_MODE == SST26VF_BUS_MODE_WSPI4L
              WSPI_CFG_ADDR_MODE_FOUR_LINES |
              WSPI_CFG_DATA_MODE_FOUR_LINES |
#else
              WSPI_CFG_ADDR_MODE_EIGHT_LINES |
              WSPI_CFG_DATA_MODE_EIGHT_LINES |
#endif
              WSPI_CFG_ALT_MODE_FOUR_LINES |  /* Always 4 lines, note.*/
              WSPI_CFG_ALT_SIZE_8;
  wspiReceive(devp->config->busp, &cmd, 1, buf);

  /* Enabling write operation.*/
  bus_cmd(devp->config->busp, SST26VF_CMD_WRITE_ENABLE);
}
#endif /* SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI */

/** @} */

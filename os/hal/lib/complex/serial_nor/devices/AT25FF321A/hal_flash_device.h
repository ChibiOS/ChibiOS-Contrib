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
 * @file    hal_flash_device.h
 * @brief   Renesas AT25FF321A serial flash driver header.
 *
 * @addtogroup AT25FF321A
 * @{
 */

 #ifndef HAL_FLASH_DEVICE_H
 #define HAL_FLASH_DEVICE_H
 /*===========================================================================*/
 /* Driver constants.                                                         */
 /*===========================================================================*/
 #include "at25ff.h"
 
 /*===========================================================================*/
 /* Driver pre-compile time settings.                                         */
 /*===========================================================================*/
 
 /**
  * @brief   Switch WSPI bus width on initialization.
  * @details A bus width initialization is performed by writing the
  *          Enhanced Volatile Configuration Register. If the flash
  *          device is configured using the Non Volatile Configuration
  *          Register then this option is not required.
  * @note    This option is only valid in WSPI bus mode.
  */
 #if !defined(AT25FF_SWITCH_WIDTH) || defined(__DOXYGEN__)
 #define AT25FF_SWITCH_WIDTH                   TRUE
 #endif
 
 /**
  * @brief   Device bus mode to be used.
  * @note    if @p AT25FF_SWITCH_WIDTH is @p FALSE then this is the bus mode
  *          that the device is expected to be using.
  * @note    if @p AT25FF_SWITCH_WIDTH is @p TRUE then this is the bus mode
  *          that the device will be switched in.
  * @note    This option is only valid in WSPI bus mode.
  */
 #if !defined(AT25FF_BUS_MODE) || defined(__DOXYGEN__)
 #define AT25FF_BUS_MODE                       AT25FF_BUS_MODE_WSPI4L
 #endif
 
  /**
  * @brief   Delays insertions.
  * @details If enabled this options inserts delays into the flash waiting
  *          routines releasing some extra CPU time for threads with lower
  *          priority, this may slow down the driver a bit however.
  */
 #if !defined(AT25FF_NICE_WAITING) || defined(__DOXYGEN__)
 #define AT25FF_NICE_WAITING                   TRUE
 #endif
 
 /**
  * @brief   Uses 4kB sub-sectors rather than 64kB sectors.
  */
 #if !defined(AT25FF_USE_SUB_SECTORS) || defined(__DOXYGEN__)
 #define AT25FF_USE_SUB_SECTORS                TRUE
 #endif
 
 / ** 
  * @brief   Size of the compare buffer.
  * @details This buffer is allocated in the stack frame of the function
  *          @p flashVerifyErase() and its size must be a power of two.
  *          Larger buffers lead to better verify performance but increase
  *          stack usage for that function.
  */
 #if !defined(AT25FF_COMPARE_BUFFER_SIZE) || defined(__DOXYGEN__)
 #define AT25FF_COMPARE_BUFFER_SIZE            32
 #endif
 
 /**
  * @brief   Number of dummy cycles for fast read (1..15).
  * @details This is the number of dummy cycles to be used for fast read
  *          operations.
  */
 #if !defined(AT25FF_READ_DUMMY_CYCLES) || defined(__DOXYGEN__)
 #define AT25FF_READ_DUMMY_CYCLES              8
 #endif
 
 /*===========================================================================*/
 /* Derived constants and error checks.                                       */
 /*===========================================================================*/
// NOTE: all of the stuff below inside Derived constants and error checks is actually for the N25Q series flash devices. 
// As far as I know they are not applicable to the at25ff but I've only looked at them briefly. 
 #if (AT25FF_COMPARE_BUFFER_SIZE & (AT25FF_COMPARE_BUFFER_SIZE - 1)) != 0
 #error "invalid AT25FF_COMPARE_BUFFER_SIZE value"
 #endif
 
 #if (AT25FF_READ_DUMMY_CYCLES < 1) || (AT25FF_READ_DUMMY_CYCLES > 15)
 #error "invalid AT25FF_READ_DUMMY_CYCLES value (1..15)"
 #endif
 
 #if (AT25FF_BUS_MODE == AT25FF_BUS_MODE_WSPI4L) || defined(__DOXYGEN__)
 /**
  * @brief   WSPI settings for command only.
  */
 #define SNOR_WSPI_CFG_CMD               (WSPI_CFG_CMD_MODE_FOUR_LINES     | \
                                          WSPI_CFG_ADDR_MODE_NONE          | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_NONE          | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 /**
  * @brief   WSPI settings for command and address.
  */
 #define SNOR_WSPI_CFG_CMD_ADDR          (WSPI_CFG_CMD_MODE_FOUR_LINES     | \
                                          WSPI_CFG_ADDR_MODE_FOUR_LINES    | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_NONE          | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 /**
  * @brief   WSPI settings for command and data.
  */
 #define SNOR_WSPI_CFG_CMD_DATA          (WSPI_CFG_CMD_MODE_FOUR_LINES     | \
                                          WSPI_CFG_ADDR_MODE_NONE          | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_FOUR_LINES    | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 /**
  * @brief   WSPI settings for command, address and data.
  */
 #define SNOR_WSPI_CFG_CMD_ADDR_DATA     (WSPI_CFG_CMD_MODE_FOUR_LINES     | \
                                          WSPI_CFG_ADDR_MODE_FOUR_LINES    | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_FOUR_LINES    | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #elif AT25FF_BUS_MODE == AT25FF_BUS_MODE_WSPI2L
 #define SNOR_WSPI_CFG_CMD               (WSPI_CFG_CMD_MODE_TWO_LINES      | \
                                          WSPI_CFG_ADDR_MODE_NONE          | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_NONE          | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #define SNOR_WSPI_CFG_CMD_ADDR          (WSPI_CFG_CMD_MODE_TWO_LINES      | \
                                          WSPI_CFG_ADDR_MODE_TWO_LINES     | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_NONE          | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #define SNOR_WSPI_CFG_CMD_DATA          (WSPI_CFG_CMD_MODE_TWO_LINES      | \
                                          WSPI_CFG_ADDR_MODE_NONE          | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_TWO_LINES     | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #define SNOR_WSPI_CFG_CMD_ADDR_DATA     (WSPI_CFG_CMD_MODE_ONE_LINE       | \
                                          WSPI_CFG_ADDR_MODE_ONE_LINE      | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_ONE_LINE      | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #elif AT25FF_BUS_MODE == AT25FF_BUS_MODE_WSPI1L
 #define SNOR_WSPI_CFG_CMD               (WSPI_CFG_CMD_MODE_ONE_LINE       | \
                                          WSPI_CFG_ADDR_MODE_NONE          | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_NONE          | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #define SNOR_WSPI_CFG_CMD_ADDR          (WSPI_CFG_CMD_MODE_ONE_LINE       | \
                                          WSPI_CFG_ADDR_MODE_ONE_LINE      | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_NONE          | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #define SNOR_WSPI_CFG_CMD_DATA          (WSPI_CFG_CMD_MODE_ONE_LINE       | \
                                          WSPI_CFG_ADDR_MODE_NONE          | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_ONE_LINE      | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #define SNOR_WSPI_CFG_CMD_ADDR_DATA     (WSPI_CFG_CMD_MODE_ONE_LINE       | \
                                          WSPI_CFG_ADDR_MODE_ONE_LINE      | \
                                          WSPI_CFG_ALT_MODE_NONE           | \
                                          WSPI_CFG_DATA_MODE_ONE_LINE      | \
                                          WSPI_CFG_CMD_SIZE_8              | \
                                          WSPI_CFG_ADDR_SIZE_24)
 
 #else
 #error "invalid AT25FF_BUS_MODE setting"
 #endif
 
 /*===========================================================================*/
 /* Driver data structures and types.                                         */
 /*===========================================================================*/
 
 /*===========================================================================*/
 /* Driver macros.                                                            */
 /*===========================================================================*/
 
 /*===========================================================================*/
 /* External declarations.                                                    */
 /*===========================================================================*/
 
 #if !defined(__DOXYGEN__)
 extern flash_descriptor_t snor_descriptor;
 #endif
 
 #if (SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI) && (WSPI_SUPPORTS_MEMMAP == TRUE)
 extern const wspi_command_t snor_memmap_read;
 #endif
 
 #ifdef __cplusplus
 extern "C" {
 #endif
   void snor_device_init(SNORDriver *devp);
   flash_error_t snor_device_read(SNORDriver *devp, flash_offset_t offset,
                                  size_t n, uint8_t *rp);
   flash_error_t snor_device_program(SNORDriver *devp, flash_offset_t offset,
                                     size_t n, const uint8_t *pp);
   flash_error_t snor_device_start_erase_all(SNORDriver *devp);
   flash_error_t snor_device_start_erase_sector(SNORDriver *devp,
                                                flash_sector_t sector);
   flash_error_t snor_device_verify_erase(SNORDriver *devp,
                                          flash_sector_t sector);
   flash_error_t snor_device_query_erase(SNORDriver *devp, uint32_t *msec);
   flash_error_t snor_device_read_sfdp(SNORDriver *devp, flash_offset_t offset,
                                       size_t n, uint8_t *rp);
 #if (SNOR_BUS_DRIVER == SNOR_BUS_DRIVER_WSPI) &&                            \
     (SNOR_DEVICE_SUPPORTS_XIP == TRUE)
   void snor_activate_xip(SNORDriver *devp);
   void snor_reset_xip(SNORDriver *devp);
 #endif
 #ifdef __cplusplus
 }
 #endif
 
 #endif /* HAL_FLASH_DEVICE_H */
 
 /** @} */
 
 
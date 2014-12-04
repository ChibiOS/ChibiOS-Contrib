/*
    ChibiOS/HAL - Copyright (C) 2006-2014 Giovanni Di Sirio

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
/*
   Concepts and parts of this file have been contributed by Uladzimir Pylinsky
   aka barthess.
 */

/**
 * @file    nand_lld.h
 * @brief   NAND Driver subsystem low level driver header.
 *
 * @addtogroup NAND
 * @{
 */

#ifndef _NAND_LLD_H_
#define _NAND_LLD_H_

#include "fsmc.h"

#if HAL_USE_NAND || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
#define NAND_MIN_PAGE_SIZE       256
#define NAND_MAX_PAGE_SIZE       8192

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   FSMC1 interrupt priority level setting.
 */
#if !defined(STM32_EMC_FSMC1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_EMC_FSMC1_IRQ_PRIORITY      10
#endif

/**
 * @brief   NAND driver enable switch.
 * @details If set to @p TRUE the support for NAND1 is included.
 */
#if !defined(STM32_NAND_USE_NAND1) || defined(__DOXYGEN__)
#define STM32_NAND_USE_NAND1              FALSE
#endif

/**
 * @brief   NAND driver enable switch.
 * @details If set to @p TRUE the support for NAND2 is included.
 */
#if !defined(STM32_NAND_USE_NAND2) || defined(__DOXYGEN__)
#define STM32_NAND_USE_NAND2              FALSE
#endif

/**
 * @brief   NAND DMA error hook.
 * @note    The default action for DMA errors is a system halt because DMA
 *          error can only happen because programming errors.
 */
#if !defined(STM32_NAND_DMA_ERROR_HOOK) || defined(__DOXYGEN__)
#define STM32_NAND_DMA_ERROR_HOOK(nandp)  osalSysHalt("DMA failure")
#endif

/**
 * @brief   NAND interrupt enable switch.
 * @details If set to @p TRUE the support for internal FSMC interrupt included.
 */
#if !defined(STM32_NAND_USE_INT) || defined(__DOXYGEN__)
#define STM32_NAND_USE_INT                FALSE
#endif

/**
* @brief   NAND1 DMA priority (0..3|lowest..highest).
*/
#if !defined(STM32_NAND_NAND1_DMA_PRIORITY) || defined(__DOXYGEN__)
#define STM32_NAND_NAND1_DMA_PRIORITY     0
#endif

/**
* @brief   NAND2 DMA priority (0..3|lowest..highest).
*/
#if !defined(STM32_NAND_NAND2_DMA_PRIORITY) || defined(__DOXYGEN__)
#define STM32_NAND_NAND2_DMA_PRIORITY     0
#endif

/**
 * @brief   DMA stream used for NAND operations.
 * @note    This option is only available on platforms with enhanced DMA.
 */
#if !defined(STM32_NAND_DMA_STREAM) || defined(__DOXYGEN__)
#define STM32_NAND_DMA_STREAM             STM32_DMA_STREAM_ID(2, 6)
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !STM32_NAND_USE_FSMC_NAND1 && !STM32_NAND_USE_FSMC_NAND2
#error "NAND driver activated but no NAND peripheral assigned"
#endif

#if (STM32_NAND_USE_FSMC_NAND2 || STM32_NAND_USE_FSMC_NAND1) && !STM32_HAS_FSMC
#error "FSMC not present in the selected device"
#endif

#if STM32_NAND_USE_EXT_INT && !HAL_USE_EXT
#error "External interrupt controller must be enabled to use this feature"
#endif

#if (STM32_NAND_USE_FSMC_NAND2 || STM32_NAND_USE_FSMC_NAND1) &&             \
    !STM32_DMA_IS_VALID_ID(STM32_NAND_DMA_STREAM,                           \
                           STM32_FSMC_DMA_MSK)
#error "invalid DMA stream associated to NAND"
#endif

#if !defined(STM32_DMA_REQUIRED)
#define STM32_DMA_REQUIRED
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   NAND driver condition flags type.
 */
typedef uint32_t nandflags_t;

/**
 * @brief   Type of a structure representing an NAND driver.
 */
typedef struct NANDDriver NANDDriver;

/**
 * @brief   Type of interrupt handler function
 */
typedef void (*nandisrhandler_t)(NANDDriver *nandp);

#if STM32_NAND_USE_EXT_INT
/**
 * @brief   Type of function switching external interrupts on and off.
 */
typedef void (*nandisrswitch_t)(void);
#endif /* STM32_NAND_USE_EXT_INT */

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Pointer to lower level driver.
   */
  FSMCDriver                *fsmcp;
  /**
   * @brief   Number of erase blocks in NAND device.
   */
  uint32_t                  blocks;
  /**
   * @brief   Number of data bytes in page.
   */
  uint32_t                  page_data_size;
  /**
   * @brief   Number of spare bytes in page.
   */
  uint32_t                  page_spare_size;
  /**
   * @brief   Number of pages in block.
   */
  uint32_t                  pages_per_block;
#if NAND_USE_BAD_MAP
  /**
   * @brief   Pointer to bad block map.
   * @details One bit per block. Memory for map must be allocated by user.
   */
  uint32_t                  *bb_map;
#endif /* NAND_USE_BAD_MAP */
  /**
   * @brief   Number of write cycles for row addressing.
   */
  uint8_t                   rowcycles;
  /**
   * @brief   Number of write cycles for column addressing.
   */
  uint8_t                   colcycles;

  /* End of the mandatory fields.*/
  /**
   * @brief   Number of wait cycles. This value will be used both for
   *          PMEM and PATTR registers
   *
   * @note    For proper calculation procedure please look at AN2784 document
   *          from STMicroelectronics.
   */
  uint32_t                  pmem;
#if STM32_NAND_USE_EXT_INT
  /**
   * @brief   Function enabling interrupts from EXTI
   */
  nandisrswitch_t           ext_nand_isr_enable;
  /**
   * @brief   Function disabling interrupts from EXTI
   */
  nandisrswitch_t           ext_nand_isr_disable;
#endif /* STM32_NAND_USE_EXT_INT */
} NANDConfig;

/**
 * @brief   Structure representing an NAND driver.
 */
struct NANDDriver {
  /**
   * @brief   Driver state.
   */
  nandstate_t               state;
  /**
   * @brief   Current configuration data.
   */
  const NANDConfig          *config;
  /**
   * @brief   Array to store bad block map.
   */
#if NAND_USE_MUTUAL_EXCLUSION || defined(__DOXYGEN__)
#if CH_CFG_USE_MUTEXES || defined(__DOXYGEN__)
  /**
   * @brief   Mutex protecting the bus.
   */
  mutex_t                   mutex;
#elif CH_CFG_USE_SEMAPHORES
  semaphore_t               semaphore;
#endif
#endif /* NAND_USE_MUTUAL_EXCLUSION */
  /* End of the mandatory fields.*/
  /**
   * @brief   Function enabling interrupts from FSMC
   */
  nandisrhandler_t          isr_handler;
  /**
   * @brief   Pointer to current transaction buffer
   */
  uint8_t                   *rxdata;
  /**
   * @brief   Current transaction length
   */
  size_t                    datalen;
  /**
   * @brief DMA mode bit mask.
   */
  uint32_t                  dmamode;
  /**
   * @brief     DMA channel.
   */
  const stm32_dma_stream_t  *dma;
  /**
   * @brief     Thread waiting for I/O completion.
   */
  thread_t                  *thread;
  /**
   * @brief     Pointer to the FSMC NAND registers block.
   */
  FSMC_NAND_TypeDef         *nand;
  /**
   * @brief     Memory mapping for data.
   */
  uint8_t                   *map_data;
  /**
   * @brief     Memory mapping for commands.
   */
  uint8_t                   *map_cmd;
  /**
   * @brief     Memory mapping for addresses.
   */
  uint8_t                   *map_addr;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if STM32_NAND_USE_FSMC_NAND1 && !defined(__DOXYGEN__)
extern NANDDriver NANDD1;
#endif

#if STM32_NAND_USE_FSMC_NAND2 && !defined(__DOXYGEN__)
extern NANDDriver NANDD2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void nand_lld_init(void);
  void nand_lld_start(NANDDriver *nandp);
  void nand_lld_stop(NANDDriver *nandp);
  uint8_t nand_lld_write_data(NANDDriver *nandp, const uint8_t *data,
          size_t datalen, uint8_t *addr, size_t addrlen, uint32_t *ecc);
  void nand_lld_read_data(NANDDriver *nandp, uint8_t *data,
          size_t datalen, uint8_t *addr, size_t addrlen, uint32_t *ecc);
  void nand_lld_polled_read_data(NANDDriver *nandp, uint8_t *data, size_t len);
  uint8_t nand_lld_erase(NANDDriver *nandp, uint8_t *addr, size_t addrlen);
  void nand_lld_write_addr(NANDDriver *nandp, const uint8_t *addr, size_t len);
  void nand_lld_write_cmd(NANDDriver *nandp, uint8_t cmd);
  uint8_t nand_lld_read_status(NANDDriver *nandp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_NAND */

#endif /* _NAND_LLD_H_ */

/** @} */

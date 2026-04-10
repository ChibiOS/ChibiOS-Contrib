/*
    ChibiOS - Copyright (C) 2024 Xael South

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in buramliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    hal_buram.c
 * @brief   BURAM Driver code.
 *
 * @addtogroup BURAM
 * @{
 */

#include "hal.h"
#include "hal_buram.h"

#if HAL_USE_BURAM || defined(__DOXYGEN__)


/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define BURAM1_MAP_LEN             (BURAM1_SIZE / (sizeof(bitmap_word_t) * 8))

#define BURAM2_MAP_LEN             (BURAM2_SIZE / (sizeof(bitmap_word_t) * 8))

#define BURAM3_MAP_LEN             (BURAM3_SIZE / (sizeof(bitmap_word_t) * 8))

#define BURAM4_MAP_LEN             (BURAM4_SIZE / (sizeof(bitmap_word_t) * 8))

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#if BURAM_USE_BURAM1
static bitmap_word_t buram1_map_array[BURAM1_MAP_LEN];
#endif

#if BURAM_USE_BURAM2
static bitmap_word_t buram2_map_array[BURAM2_MAP_LEN];
#endif

#if BURAM_USE_BURAM3
static bitmap_word_t buram3_map_array[BURAM3_MAP_LEN];
#endif

#if BURAM_USE_BURAM4
static bitmap_word_t buram4_map_array[BURAM4_MAP_LEN];
#endif

/**
 * @brief   BURAM1 driver identifier.
 */
#if BURAM_USE_BURAM1 || defined(__DOXYGEN__)
BURAMDriver BURAMD1 = {
  .state = BURAM_READY,
  .start = BURAM1_ADDRESS,
  .end = BURAM1_ADDRESS + BURAM1_SIZE,
  .buram_map.array = buram1_map_array,
  .buram_map.len = sizeof(buram1_map_array) / sizeof(buram1_map_array[0]),
};
#endif

/**
 * @brief   BURAM2 driver identifier.
 */
#if BURAM_USE_BURAM2 || defined(__DOXYGEN__)
BURAMDriver BURAMD2 = {
  .state = BURAM_READY,
  .start = BURAM2_ADDRESS,
  .end = BURAM2_ADDRESS + BURAM2_SIZE,
  .buram_map.array = buram2_map_array,
  .buram_map.len = sizeof(buram2_map_array) / sizeof(buram2_map_array[0]),
};
#endif

/**
 * @brief   BURAM3 driver identifier.
 */
#if BURAM_USE_BURAM3 || defined(__DOXYGEN__)
BURAMDriver BURAMD3 = {
  .state = BURAM_READY,
  .start = BURAM3_ADDRESS,
  .end = BURAM3_ADDRESS + BURAM3_SIZE,
  .buram_map.array = buram3_map_array,
  .buram_map.len = sizeof(buram3_map_array) / sizeof(buram3_map_array[0]),
};
#endif

/**
 * @brief   BURAM4 driver identifier.
 */
#if BURAM_USE_BURAM4 || defined(__DOXYGEN__)
BURAMDriver BURAMD4 = {
  .state = BURAM_READY,
  .start = BURAM4_ADDRESS,
  .end = BURAM4_ADDRESS + BURAM4_SIZE,
  .buram_map.array = buram4_map_array,
  .buram_map.len = sizeof(buram4_map_array) / sizeof(buram4_map_array[0]),
};
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   BURAM Driver initialization.
 * @note    This function is not implicitly invoked by @p halInit(), there is
 *          the need to explicitly initialize the driver.
 *
 * @init
 */
void buramInit(void) {

  /* Using static RAM for BURAMDx guarantees adequate structure
     initialisation right after reset. */
}

/**
 * @brief   Initializes the standard part of a @p BURAMDriver structure.
 *
 * @param[out] buramp     pointer to the @p BURAMDriver object
 *
 * @init
 */
void buramObjectInit(BURAMDriver *buramp) {

  (void)buramp;

  /* Using static RAM for BURAMDx guarantees adequate structure
     initialisation right after reset. */
}

/**
 * @brief   Configures and activates the BURAM peripheral.
 *
 * @param[in] buramp      pointer to the @p BURAMDriver object
 * @param[in] config    pointer to the @p BURAMConfig object
 *
 * @api
 */
void buramStart(BURAMDriver *buramp, const BURAMConfig *config) {

  osalDbgCheck((buramp != NULL) && (config != NULL));

  osalSysLock();
  osalDbgAssert((buramp->state == BURAM_STOP) || (buramp->state == BURAM_READY),
                "invalid state");
  buram_lld_start(buramp, config);
  buramp->state = BURAM_READY;
  osalSysUnlock();
}

/**
 * @brief   Deactivates the BURAM peripheral.
 *
 * @param[in] buramp      pointer to the @p BURAMDriver object
 *
 * @api
 */
void buramStop(BURAMDriver *buramp) {

  osalDbgCheck(buramp != NULL);

  osalSysLock();
  osalDbgAssert((buramp->state == BURAM_STOP) || (buramp->state == BURAM_READY),
                "invalid state");
  buram_lld_stop(buramp);
  buramp->state = BURAM_STOP;
  osalSysUnlock();
}

/**
 * @brief   Allocates backup RAM.
 *
 * @param[in] buramp      pointer to the @p BURAMDriver object
 * @param[in] address     address of memory to allocate. Starts at 0
 * @param[in] size        size of memory to allocate
 *
 * @api
 */
volatile void* buramAllocateAtI(BURAMDriver* buramp, uintptr_t address, size_t size) {

  osalDbgCheck(buramp != NULL);

  osalDbgAssert((buramp->state == BURAM_READY), "invalid state");

  if (buramp->start + address + size >= buramp->end) {
    osalDbgAssert(false, "exceeded available amount of BURAM");
    return NULL;
  }

  /* Check if all requested bytes can be allocated. */
  for (size_t bit = address; bit < address + size; bit++) {
    bitmap_word_t bit_state = bitmapGet(&buramp->buram_map, bit);
    if (bit_state != (bitmap_word_t)0) { /* Byte is allocated? */
      osalDbgAssert(false, "BURAM is already allocated");
      return NULL; /* Yes, it was. */
    }
  }

  /* All requested bytes will be marked as allocated. */
  for (size_t bit = address; bit < address + size; bit++) {
    bitmapSet(&buramp->buram_map, bit);
  }

  return (volatile void*)(buramp->start + address);
}

/**
 * @brief   Allocates backup RAM.
 *
 * @param[in] buramp      pointer to the @p BURAMDriver object
 * @param[in] address     address of memory to allocate. Starts at 0
 * @param[in] size        size of memory to allocate
 *
 * @api
 */
volatile void* buramAllocateAt(BURAMDriver *buramp, uintptr_t address, size_t size) {

  volatile void *addr;

  osalSysLock();
  addr = buramAllocateAtI(buramp, address, size);
  osalSysUnlock();
  return addr;
}

#endif /* HAL_USE_BURAM */

/** @} */
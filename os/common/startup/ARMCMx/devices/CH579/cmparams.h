/*
 * ChibiOS - CH579M Cortex-M0 CMSIS parameters
 *
 * CH579M interrupt vector count: 26 external IRQs from the datasheet,
 * rounded up to the next multiple of 8 → 32.
 */

#ifndef CMPARAMS_H
#define CMPARAMS_H

/** @brief Cortex core model: 0 = Cortex-M0. */
#define CORTEX_MODEL 0

/** @brief No FPU on Cortex-M0. */
#define CORTEX_HAS_FPU 0

/**
 * @brief Number of bits in priority masks.
 * @note  Cortex-M0 only implements the top 2 bits of the priority field.
 */
#define CORTEX_PRIORITY_BITS 2

/**
 * @brief Number of interrupt vectors.
 * @note  Does NOT include the 16 system vectors.  Must be a multiple of 8.
 *        CH579M has 26 external IRQs → rounded to 32.
 */
#define CORTEX_NUM_VECTORS 32

#if !defined(_FROM_ASM_)

#include "board.h"

/* Pull in the device register header solely to verify parameters match. */
#include "CH579.h"

#if CORTEX_MODEL != __CORTEX_M
#error "CMSIS __CORTEX_M mismatch — verify CH579.h defines __CORTEX_M 0"
#endif

#if CORTEX_PRIORITY_BITS != __NVIC_PRIO_BITS
#error                                                                         \
    "CMSIS __NVIC_PRIO_BITS mismatch — verify CH579.h defines __NVIC_PRIO_BITS 2"
#endif

#endif /* !defined(_FROM_ASM_) */

#endif /* CMPARAMS_H */

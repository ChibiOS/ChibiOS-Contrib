/**
 * @file    hal_pal_lld.h
 * @brief   CH579M PAL (GPIO) low level driver header.
 *
 * @addtogroup PAL
 * @{
 */

#ifndef HAL_PAL_LLD_H
#define HAL_PAL_LLD_H

#include "CH579.h"

/*===========================================================================*/
/* Unsupported modes.                                                        */
/*===========================================================================*/

#undef PAL_MODE_RESET
#undef PAL_MODE_UNCONNECTED
#undef PAL_MODE_INPUT
#undef PAL_MODE_INPUT_PULLUP
#undef PAL_MODE_INPUT_PULLDOWN
#undef PAL_MODE_INPUT_ANALOG
#undef PAL_MODE_OUTPUT_PUSHPULL
#undef PAL_MODE_OUTPUT_OPENDRAIN

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    PAL port/pad type aliases
 * @{
 */
typedef GPIO_TypeDef *ioportid_t;
typedef uint32_t ioportmask_t;
typedef uint32_t iopadid_t;
typedef uint32_t iomode_t;

/** @} */

/**
 * @name    PAL mode constants  (CH579M subset)
 * @{
 */
#define PAL_MODE_INPUT 0U           /**< Floating input (DIR=0, PU=0, PD=0) */
#define PAL_MODE_INPUT_PULLUP 1U    /**< Input with pull-up                  */
#define PAL_MODE_INPUT_PULLDOWN 2U  /**< Input with pull-down                */
#define PAL_MODE_OUTPUT_PUSHPULL 3U /**< Push-pull output */
/** @} */

/*===========================================================================*/
/* I/O Ports Identifiers.                                                    */
/*===========================================================================*/

#define IOPORTA GPIOA
#define IOPORTB GPIOB

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of digital I/O port sized unsigned type.
 */
typedef uint32_t ioline_t;

/**
 * @brief   PAL line identifier.
 */
#define PAL_IOPORTS_WIDTH 5
#define PAL_LINE(port, pad) ((ioline_t)((uint32_t)(port)) | ((uint32_t)(pad)))

#define PAL_PORT(line)                                                         \
  ((ioportid_t)((line) & ~((1U << PAL_IOPORTS_WIDTH) - 1U)))
#define PAL_PAD(line) ((uint32_t)((line) & ((1U << PAL_IOPORTS_WIDTH) - 1U)))

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Type of a PAL configuration.
 */
typedef struct {
  uint32_t dummy; /* Empty configuration for now */
} PALConfig;

/**
 * @brief   Low level PAL subsystem initialization.
 */
#define pal_lld_init(config)                                                   \
  (void)(config) /* GPIO regs default to input on reset */

/**
 * @brief   Reads the physical I/O port state.
 */
#define pal_lld_readport(port) ((ioportmask_t)((port)->PIN))

/**
 * @brief   Reads the output latch state.
 */
#define pal_lld_readlatch(port) ((ioportmask_t)((port)->OUT))

/**
 * @brief   Writes a value to the whole physical I/O port.
 */
#define pal_lld_writeport(port, bits) ((port)->OUT = (bits))

/**
 * @brief   Sets masked bits in a port.
 */
#define pal_lld_setport(port, bits) ((port)->OUT |= (bits))

/**
 * @brief   Clears masked bits in a port (uses atomic CLR register).
 */
#define pal_lld_clearport(port, bits) ((port)->CLR = (bits))

/**
 * @brief   Toggles masked bits in a port.
 */
#define pal_lld_toggleport(port, bits) ((port)->OUT ^= (bits))

/**
 * @brief   Reads the logical state of an I/O pad.
 */
#define pal_lld_readpad(port, pad) (((port)->PIN >> (pad)) & 1U)

/**
 * @brief   Writes the logical state of an output pad.
 */
#define pal_lld_writepad(port, pad, bit)                                       \
  do {                                                                         \
    if (bit)                                                                   \
      (port)->OUT |= (1UL << (pad));                                           \
    else                                                                       \
      (port)->CLR = (1UL << (pad));                                            \
  } while (0)

/**
 * @brief   Sets a pad logical level to @p PAL_HIGH.
 */
#define pal_lld_setpad(port, pad) ((port)->OUT |= (1UL << (pad)))

/**
 * @brief   Clears a pad logical level to @p PAL_LOW.
 */
#define pal_lld_clearpad(port, pad) ((port)->CLR = (1UL << (pad)))

/**
 * @brief   Toggles a pad logical level.
 */
#define pal_lld_togglepad(port, pad) ((port)->OUT ^= (1UL << (pad)))

/**
 * @brief   Returns the pad group mode.
 */
#define pal_lld_getgroupmode(port, mask, mode) /* not implemented */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern const PALConfig pal_default_config;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void _pal_lld_setgroupmode(ioportid_t port, ioportmask_t mask, uint32_t offset, iomode_t mode);
#ifdef __cplusplus
}
#endif

/* Define the macro so hal_pal.h's #if !defined(pal_lld_setgroupmode) sees
 * our implementation and does NOT fall back to the no-op stub. */
#define pal_lld_setgroupmode(port, mask, offset, mode) \
  _pal_lld_setgroupmode((port), (mask), (offset), (mode))

#endif /* HAL_PAL_LLD_H */

/** @} */

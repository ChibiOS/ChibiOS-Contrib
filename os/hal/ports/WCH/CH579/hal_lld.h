/**
 * @file    hal_lld.h
 * @brief   CH579M HAL low-level driver header — clock init.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef _HAL_LLD_H_
#define _HAL_LLD_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification
 * @{
 */
#define PLATFORM_NAME "WCH CH579M"
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   System core clock after PLL — 48 MHz for USB.
 */
#ifndef CH579_SYSCLK
#define CH579_SYSCLK 48000000UL
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the frequency of a clock point in Hz.
 */
#define hal_lld_get_clock_point(clkpt) CH579_SYSCLK

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#include "CH579.h"
#include "nvic.h"

#ifdef __cplusplus
extern "C" {
#endif
void hal_lld_init(void);
#ifdef __cplusplus
}
#endif

#endif /* _HAL_LLD_H_ */

/** @} */

/*
    ChibiOS - Copyright (C) 2006-2026 Giovanni Di Sirio.
    Copyright (C) 2026 QMK

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
 * @file    SK32F0xx/hal_low_power_lld.h
 * @brief   SK32F0xx low power subsystem low level driver header.
 * @details Exposes a minimal STOP-mode entry/restore API for the SK32F077.
 *          The CPU is a Cortex-M0 core on a STM32F0-compatible power
 *          controller, so entering Stop puts both the core and the
 *          peripherals into a low power state and wakes only on an
 *          interrupt event (e.g. the forced USB RESUME kept armed by the
 *          USB low level driver when SK32_USB_LOW_POWER_ON_SUSPEND is set).
 *
 * @addtogroup LOWPOWER
 * @{
 */

#ifndef HAL_LOW_POWER_LLD_H
#define HAL_LOW_POWER_LLD_H

/*===========================================================================*/
/* Driver configuration.                                                     */
/*===========================================================================*/

/**
 * @brief   Enables the Cortex-M0 deep-sleep (STOP) entry on suspend.
 * @details Defaults to false so no firmware uses STOP unless explicitly
 *          enabled in the keyboard config.h.  When true the driver compiles
 *          the STOP entry/restore helpers used by the suspend chain.
 */
#if !defined(SK32_HAL_USE_LOWPOWER) || defined(__DOXYGEN__)
#define SK32_HAL_USE_LOWPOWER               FALSE
#endif

#if (SK32_HAL_USE_LOWPOWER == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Cortex System Control Register (SCR) SLEEPDEEP bit.
 * @note    Bit 2 of the SCR (ARMv6-M "System Control Register").  Defined
 *          here so the driver does not depend on the toolchain CMSIS header
 *          naming of the bit mask.
 */
#define SK32_SCR_SLEEPDEEP                   (1U << 2)

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Enters the Cortex-M0 STOP mode.
 * @details Clears the wakeup/standby flags, programs the PWR controller for
 *          Stop (deep sleep), sets the SLEEPDEEP bit of the Cortex System
 *          Control Register and executes the SEV/WFE/WFE sequence.  The
 *          function returns after an event or an interrupt wakes the core;
 *          the SLEEPDEEP bit is cleared right after the wakeup.  If the STOP
 *          entry must be exited without a real reason (e.g. the periodic
 *          wake tick), the caller just loops and re-enters.
 * @note    Before the first entry the driver arms two guard rails: the
 *          DBGMCU_CR DBG_STOP bit so the debug port stays clocked while the
 *          core sleeps (a wedged suspend stays recoverable), and a 10 ms
 *          TIM6/LSI tick whose update interrupt feeds the EXTI29 wakeup
 *          event so STOP can never become terminal.  Both are left armed
 *          afterwards.
 * @note    This function does NOT rebuild the clocks.  Call
 *          @p sk32_lowpower_stop_restore() after a confirmed wakeup.
 *
 * @api
 */
void sk32_lowpower_stop_enter(void);

/**
 * @brief   Restores the system clocks after a STOP wakeup.
 * @details STOP removes the PLL/HSI configuration so the system clock and
 *          the 48 MHz USB reference must be rebuilt.  This helper simply
 *          re-runs @p sk32_clock_init() (same routine used after reset) and
 *          updates @p SystemCoreClock.
 * @note    Must be called from a context where blocking clock startup loops
 *          are acceptable (a thread, not an interrupt posting a report).
 *
 * @api
 */
void sk32_lowpower_stop_restore(void);

#ifdef __cplusplus
}
#endif

#endif /* (SK32_HAL_USE_LOWPOWER == TRUE) || defined(__DOXYGEN__) */

/**
 * @}
 */
#endif /* HAL_LOW_POWER_LLD_H */
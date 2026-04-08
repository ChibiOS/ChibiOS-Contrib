/**
 * @file    hal_st_lld.h
 * @brief   CH579M ST subsystem low level driver header.
 * @details Uses the ARM Cortex-M0 SysTick peripheral directly.
 *          Periodic mode: SysTick fires at OSAL_ST_FREQUENCY.
 *          Freerunning mode: not supported (CM0 SysTick is 24-bit countdown
 *          only; use OSAL_ST_MODE_PERIODIC which QMK defaults to anyway).
 *
 * @addtogroup ST
 * @{
 */

#ifndef HAL_ST_LLD_H
#define HAL_ST_LLD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   SysTick IRQ priority.
 */
#if !defined(CH579_ST_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define CH579_ST_IRQ_PRIORITY 8
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
#error                                                                         \
    "CH579M hal_st_lld does not support OSAL_ST_MODE_FREERUNNING; use PERIODIC"
#endif

#if CH579_SYSCLK % OSAL_ST_FREQUENCY != 0
#error "OSAL_ST_FREQUENCY is not an integer divisor of CH579_SYSCLK"
#endif

#if (CH579_SYSCLK / OSAL_ST_FREQUENCY) - 1 > 0xFFFFFFUL
#error "OSAL_ST_FREQUENCY too low — SysTick reload value exceeds 24 bits"
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

#ifdef __cplusplus
extern "C" {
#endif
void st_lld_init(void);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Driver inline functions (freerunning stubs — unused in periodic mode).   */
/*===========================================================================*/

#if (OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING) || defined(__DOXYGEN__)
static inline systime_t st_lld_get_counter(void) { return 0; }
static inline void st_lld_stop_alarm(void) {}
static inline void st_lld_start_alarm(systime_t t) { (void)t; }
static inline void st_lld_set_alarm(systime_t t) { (void)t; }
static inline systime_t st_lld_get_alarm(void) { return 0; }
static inline bool st_lld_is_alarm_active(void) { return false; }
#endif

#endif /* HAL_ST_LLD_H */

/** @} */

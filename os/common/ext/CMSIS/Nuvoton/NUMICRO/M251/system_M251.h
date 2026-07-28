/**************************************************************************//**
 * @file     system_M251.h
 * @version  V0.10
 * @brief    System Setting Header File
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 ****************************************************************************/

#ifndef __SYSTEM_M251_H__
#define __SYSTEM_M251_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*----------------------------------------------------------------------------*/
/* Macro Definition                                                           */
/*----------------------------------------------------------------------------*/
#define __PC()                                                \
    __extension__({                                           \
        register unsigned int current_pc;                     \
        __asm volatile("mov %0, pc" : "=r"(current_pc) : : ); \
        current_pc;                                           \
    })    /*!< Current program counter            */

/*----------------------------------------------------------------------------*/
/* Define clocks                                                              */
/*----------------------------------------------------------------------------*/
#ifndef __HXT
#define __HXT       (12000000UL)              /*!< External Crystal Clock Frequency           */
#endif /* !defined(__HXT) */

#ifndef __LXT
#define __LXT       (32768UL)                 /*!< External Crystal Clock Frequency 32.768KHz */
#endif /* !defined(__LXT) */

#define __LIRC      (38400UL)                 /*!< Internal 38.4KHz RC Oscillator Frequency   */
#define __MIRC      (4032000UL)               /*!< Internal 4.032M RC Oscillator Frequency    */
#define __HIRC      (48000000UL)              /*!< Internal 48M RC Oscillator Frequency       */
#define __HSI       (48000000UL)              /*!< PLL default output is 48MHz                */
#define __SYS_OSC_CLK     (    ___HSI)        /*!< Main oscillator frequency                  */

#define __SYSTEM_CLOCK    (1UL*__HXT)

extern uint32_t SystemCoreClock;    /*!< System Clock Frequency (Core Clock)  */
extern uint32_t CyclesPerUs;        /*!< Cycles per micro second              */
extern uint32_t PllClock;           /*!< PLL Output Clock Frequency           */

/**
  \brief Exception / Interrupt Handler Function Prototype
*/
typedef void(*VECTOR_TABLE_Type)(void);

/**
 * @brief    System Initialization
 *
 * @details  The necessary initialization of system. Global variables are forbidden here.
 */
extern void SystemInit(void);

/**
 * @brief    Update the Variable SystemCoreClock
 *
 * @details  This function is used to update the variable SystemCoreClock
 *           and must be called whenever the core clock is changed.
 */
extern void SystemCoreClockUpdate(void);

/**
 * @brief    Set UART0 Default MPF
 *
 * @details  The initialization of uart0 default multi function pin.
 */
extern void Uart0DefaultMPF(void);

/**
 * @brief  Check if debug message finished
 *
 * @return   1 Message is finished.
 *           0 Message is transmitting.
 *
 * @details  Check if message finished (FIFO empty of debug port)
 */
extern int IsDebugFifoEmpty(void);


#ifdef __cplusplus
}

#endif

#endif /* __SYSTEM_M251_H__ */

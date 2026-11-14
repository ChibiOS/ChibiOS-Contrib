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
 * @file    SK32F0xx/hal_low_power_lld.c
 * @brief   SK32F0xx low power subsystem low level driver source.
 *
 * @addtogroup LOWPOWER
 * @{
 */

#include "hal.h"

#if (SK32_HAL_USE_LOWPOWER == TRUE) || defined(__DOXYGEN__)

#include "hal_low_power_lld.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   TIM6 update period used as the STOP wake tick.
 * @details TIM6 is clocked from the LSI (about 40 kHz) with PSC=9 and
 *          ARR=39, i.e. 10 * 40 / 40000 = 10 ms.  Same tick the vendor
 *          reference uses (KBCU_TIM_WAKE_Init in kbcuDrive.c).
 */
#define SK32_STOP_WAKE_PSC                  9U
#define SK32_STOP_WAKE_ARR                  39U

/**
 * @brief   EXTI line routed to the TIM6 update event on this device.
 * @details The vendor reference arms line 29 (EXTI->IMR/EMR/RTSR bit 29)
 *          next to its TIM6 wake timer; lines 16..31 have no NVIC vector on
 *          this family and act as pure event lines, which is exactly what a
 *          deep sleep WFE wakeup needs.
 */
#define SK32_STOP_WAKE_EXTI                 (1U << 29U)

/**
 * @brief   EXTI line routed to the USB controller (bus resume).
 * @details Line 18 carries the USB wakeup event on this family; arming it
 *          lets a RESUME seen by the PHY pull the core out of STOP even
 *          though the 48 MHz USB reference is stopped.  Mirrors
 *          USBUSER_Init() in the vendor reference (usbUser.c).
 */
#define SK32_STOP_USB_EXTI                  (1U << 18U)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/** @brief  The STOP wake tick is armed once and left running. */
static bool sk32_stop_wake_armed = false;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Re-applies the clocks STOP/sk32_clock_init() tear down.
 * @details sk32_clock_init() writes CFGR3 and CR2 back to their reset value,
 *          which drops the LSI to TIM6 routing and switches PLL48 off.  Both
 *          must be re-established before the peripheral bus is used again.
 */
static void sk32_stop_restore_aux_clocks(void) {

  if (sk32_stop_wake_armed) {
    RCC->CSR |= RCC_CSR_LSION;
    while ((RCC->CSR & RCC_CSR_LSIRDY) == 0U) {
    }
    RCC->CFGR3 = (RCC->CFGR3 & ~RCC_CFGR3_TIM6SW) | RCC_CFGR3_TIM6SW_0;
  }

#if SK32_USB_USE_USB1
  /* 48 MHz reference for the USB controller (PLL48 routed by USBSW=0). */
  RCC->CR2 |= RCC_CR2_PLL48ON;
  while ((RCC->CR2 & RCC_CR2_PLL48RDY) == 0U) {
  }
  RCC->CFGR3 &= ~RCC_CFGR3_USBSW;
#endif
}

/**
 * @brief   Arms the periodic STOP wake tick.
 * @details The tick makes STOP self-recovering: even if no USB RESUME ever
 *          arrives (PLL48 is stopped in STOP so the controller cannot clock
 *          one), the core is pulled back every 10 ms, the clocks get rebuilt
 *          and the suspend loop gets a chance to re-evaluate its exit
 *          conditions.  Without it a STOP entry is terminal.
 */
static void sk32_stop_wake_arm(void) {

  if (sk32_stop_wake_armed) {
    return;
  }

  /* LSI on, routed to TIM6 (TIM6SW = LSI). */
  RCC->CSR |= RCC_CSR_LSION;
  while ((RCC->CSR & RCC_CSR_LSIRDY) == 0U) {
  }
  RCC->CFGR3 = (RCC->CFGR3 & ~RCC_CFGR3_TIM6SW) | RCC_CFGR3_TIM6SW_0;

  /* TIM6 clocked, 100 Hz update.  The update interrupt MUST stay enabled:
     on this device the EXTI29 "TIM6 wakeup event" is gated by the update
     interrupt enable (same rule as the RTC alarm on EXTI17, see the vendor
     PWR_Stop example).  With UIE cleared the wakeup event is never asserted
     and a STOP entry becomes terminal.
     No NVIC enable here on purpose: line 29 has no vector of its own, the
     event is only used to pull the core out of WFE, and the update flag is
     cleared by hand below. */
  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
  TIM6->CR1 = 0U;
  TIM6->PSC = SK32_STOP_WAKE_PSC;
  TIM6->ARR = SK32_STOP_WAKE_ARR;
  TIM6->EGR = TIM_EGR_UG;
  TIM6->SR  = 0U;
  TIM6->DIER = TIM_DIER_UIE;
  TIM6->CR1 = TIM_CR1_CEN;

  /* TIM6 update -> EXTI29 event, USB resume -> EXTI18 event.
     The USB line is armed on BOTH edges, exactly like USBUSER_Init() in the
     vendor reference (which sets EXTI->RTSR and EXTI->FTSR bit 18): the
     wakeup pulse the USB controller emits when the host resumes the bus has
     no documented polarity on this part, and arming a single edge silently
     drops the wakeup whenever the pulse has the other polarity. */
  EXTI->IMR  |= SK32_STOP_WAKE_EXTI | SK32_STOP_USB_EXTI;
  EXTI->EMR  |= SK32_STOP_WAKE_EXTI | SK32_STOP_USB_EXTI;
  EXTI->RTSR |= SK32_STOP_WAKE_EXTI | SK32_STOP_USB_EXTI;
  EXTI->FTSR |= SK32_STOP_USB_EXTI;

  sk32_stop_wake_armed = true;
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   PWR module low level driver initialization.
 * @note    Nothing to do: on process start the PWR module is enabled by the
 *          USB driver when the interface is brought up (rccEnablePWRInterface
 *          is called from usb_lld_start).  The STOP entry only touches the
 *          PWR->CR/CSR registers which are always clocked once enabled.
 *
 * @notapi
 */
#if defined(__DOXYGEN__)
void hal_low_power_lld_init(void);
#endif

void sk32_lowpower_stop_enter(void) {

   uint32_t temp;
   temp = PWR->CR;
  /* Guardrail: keep the debug logic clocked while the core sits in STOP.
     Without DBG_STOP the SWD/AHB-AP loses its clock together with the
     system clock and the part can neither be halted nor interrogated until
     a hardware reset, which makes a stuck suspend unrecoverable in the
     field.  Armed on the first STOP entry only. */
  DBGMCU->CR |= DBGMCU_CR_DBG_STOP;

  /* Make sure a periodic wake event exists before sleeping. */
  sk32_stop_wake_arm();

  /* Clear the wakeup and standby flags so a residual flag cannot cause a
     spurious early wakeup on the next entry.  These are "write 1 to clear"
     bits on the STM32F0-class PWR. */
  PWR->CR |= (uint32_t)(PWR_CR_CWUF | PWR_CR_CSBF);

  /* Select Stop (deep sleep with regulator ON).  LPDS keeps the voltage
     regulator in low-power mode which is the lowest power Stop on the
     Cortex-M0 ST part; PDDS is cleared for Stop (not Standby). */
  PWR->CR &= ~(uint32_t)PWR_CR_PDDS;
  PWR->CR |= (uint32_t)PWR_CR_LPDS;

  /* Put the Cortex-M0 in deep-sleep on the next WFE. */
  SCB->SCR |= (uint32_t)SK32_SCR_SLEEPDEEP;

  /* Enter STOP on an event.  The SEV/WFE/WFE sequence is the standard
     deep sleep idiom: SEV primes the event register, the first WFE consumes
     it and returns immediately, the second one actually sleeps.  The core
     wakes on the next event (the 10 ms TIM6 tick on EXTI29, or a USB resume
     on EXTI18) or on the USB interrupt kept armed by the USB LLD.  SLEEPDEEP
     is cleared right after so the following normal wait uses plain sleep. */
  __SEV();
  __WFE();
  __WFE();
  SCB->SCR &= (uint32_t)~SK32_SCR_SLEEPDEEP;
  PWR->CR = temp;
  
  /* Consume the tick that woke us so the next entry can sleep again. */
  TIM6->SR = 0U;
  EXTI->PR = SK32_STOP_WAKE_EXTI | SK32_STOP_USB_EXTI;
}

void sk32_lowpower_stop_restore(void) {

  /* STOP drops the PLL/HSI system clock configuration; rebuild it exactly
     like right after reset.  This also re-establishes the 48 MHz reference
     needed by the USB peripheral and updates SystemCoreClock. */
  sk32_clock_init();

  /* sk32_clock_init() resets CFGR3/CR2, so re-apply the LSI tick routing
     and the USB 48 MHz source it just dropped. */
  sk32_stop_restore_aux_clocks();
}

#endif /* (SK32_HAL_USE_LOWPOWER == TRUE) || defined(__DOXYGEN__) */

/** @} */

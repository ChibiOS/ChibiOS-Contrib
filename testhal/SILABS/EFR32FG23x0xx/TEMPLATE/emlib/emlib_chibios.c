#include "hal.h"
#include "em_core_generic.h"

CORE_irqState_t CORE_EnterCritical(void) {

  chSysLock();
  return 0;
}

void CORE_ExitCritical(CORE_irqState_t irqState) {

  (void)irqState;
  osalSysUnlock();
}

CORE_irqState_t CORE_EnterAtomic(void) {

  return (chSysGetStatusAndLockX());
}

void CORE_ExitAtomic(CORE_irqState_t irqState) {

  chSysRestoreStatusX(irqState);
}

#if defined(SL_TRUSTZONE_NONSECURE)
uint32_t sli_tz_syscfg_read_chiprev_register(void) {

  return (SYSCFG->CHIPREV);
}
#endif

/* SystemNNNGet are declared as weak function as they can be overwritten
   by linking with system_efr32fg23.c. */

CC_WEAK uint32_t SystemHFXOClockGet(void) {

  return EFR32_HFXO_FREQ;
}

CC_WEAK uint32_t SystemSYSCLKGet(void) {

  uint32_t ret = 0U;

  // Find clock source
  switch (CMU->SYSCLKCTRL & _CMU_SYSCLKCTRL_CLKSEL_MASK) {
  case _CMU_SYSCLKCTRL_CLKSEL_HFRCODPLL:
    ret = SystemHFRCODPLLClockGet();
    break;

#if (EFR32_HFXO_FREQ > 0U)
  case _CMU_SYSCLKCTRL_CLKSEL_HFXO:
    ret = HFXO_FREQ;
    break;
#endif

#if (EFR32_CLKIN0_FREQ > 0U)
  case _CMU_SYSCLKCTRL_CLKSEL_CLKIN0:
    ret = CLKIN0_FREQ;
    break;
#endif

  case _CMU_SYSCLKCTRL_CLKSEL_FSRCO:
    ret = EFR32_FSRCO_FREQ;
    break;

  default:
    osalDbgAssert(false, "Unknown clock source.");
    break;
  }

  return ret;
}

CC_WEAK uint32_t SystemHFRCODPLLClockGet(void) {

  uint32_t ret = 0UL;

  // Get oscillator frequency band
  switch ((HFRCO0->CAL & _HFRCO_CAL_FREQRANGE_MASK)
          >> _HFRCO_CAL_FREQRANGE_SHIFT) {
  case 0:
    switch (HFRCO0->CAL & _HFRCO_CAL_CLKDIV_MASK) {
    case HFRCO_CAL_CLKDIV_DIV1:
      ret = 4000000UL;
      break;

    case HFRCO_CAL_CLKDIV_DIV2:
      ret = 2000000UL;
      break;

    case HFRCO_CAL_CLKDIV_DIV4:
      ret = 1000000UL;
      break;

    default:
      ret = 0UL;
      break;
    }
    break;

  case 3:
    ret = 7000000UL;
    break;

  case 6:
    ret = 13000000UL;
    break;

  case 7:
    ret = 16000000UL;
    break;

  case 8:
    ret = 19000000UL;
    break;

  case 10:
    ret = 26000000UL;
    break;

  case 11:
    ret = 32000000UL;
    break;

  case 12:
    ret = 38000000UL;
    break;

  case 13:
    ret = 48000000UL;
    break;

  case 14:
    ret = 56000000UL;
    break;

  case 15:
    ret = 64000000UL;
    break;

  case 16:
    ret = 80000000UL;
    break;

  default:
    break;
  }
  return ret;
}

#if 0
void _start(void) {

  extern int main(void);
  main();
  NVIC_SystemReset();
}
#endif


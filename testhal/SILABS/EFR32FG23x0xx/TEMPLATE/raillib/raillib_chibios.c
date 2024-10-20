#include "hal.h"
#include "em_core_generic.h"

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

OSAL_IRQ_HANDLER(EFR32_RFECA0_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  RFECA0_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_RFECA1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  RFECA1_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_SYSRTC_SEQ_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  SYSRTC_SEQ_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_AGC_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  AGC_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_BUFC_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  BUFC_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_EMUDG_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  EMUDG_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_FRC_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  FRC_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_FRC_PRI_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  FRC_PRI_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_HOSTMAILBOX_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  HOSTMAILBOX_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_MODEM_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  MODEM_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_PROTIMER_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  PROTIMER_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_RAC_RSM_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  RAC_RSM_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_RAC_SEQ_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  RAC_SEQ_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(EFR32_SYNTH_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  SYNTH_IRQHandler();

  OSAL_IRQ_EPILOGUE();
}


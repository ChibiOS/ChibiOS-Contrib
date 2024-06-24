#include "hal.h"
#include "sam_clk.h"

uint32_t SystemCoreClock = SAM_CPU_FREQ;

void sam_gclk_init(uint32_t id, uint32_t sysctrl_src, uint16_t gendiv,
                   bool enable) {
  if (enable) {
    switch (id) {
      case 2:
        osalDbgAssert(((uint32_t)gendiv) < (1U << 16), "GENDIV exceeded");
        break;
      default:
        osalDbgAssert(gendiv < (1U << 8), "GENDIV exceeded");
        break;
    }
  }
  GCLK_REGS->GCLK_GENCTRL[id] = GCLK_GENCTRL_DIV(gendiv) | sysctrl_src |
                                GCLK_GENCTRL_IDC(1) |
                                GCLK_GENCTRL_GENEN(enable);
  const uint32_t syncbusy_gen = 1 << (id + 2);
  while ((GCLK_REGS->GCLK_SYNCBUSY & syncbusy_gen) == syncbusy_gen) {
    /* Wait for synchronization */
  }
}

void sam_gclk_mux(uint32_t id, uint32_t dest, bool enable) {
  GCLK_REGS->GCLK_PCHCTRL[dest] =
      GCLK_PCHCTRL_GEN(id) | GCLK_PCHCTRL_CHEN(enable);  // Hook up the clock
  if (enable) {
    while ((GCLK_REGS->GCLK_PCHCTRL[dest] & GCLK_PCHCTRL_CHEN_Msk) !=
           GCLK_PCHCTRL_CHEN(enable)) {
      /* Wait for synchronization */
    }
  }
}
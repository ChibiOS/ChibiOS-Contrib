#include "hal.h"

void hal_lld_init(void) {
  /* Step 1: Power on the PLL.
   * RB_CLK_PLL_PON resets to 0 (datasheet p.24) — the PLL is off at reset.
   * We must set this bit before selecting PLL as the clock source; switching
   * without it connects the system clock to an unpowered PLL, producing a
   * dead clock and an immediate HardFault. */
  /* R8_HFCK_PWR_CTRL resets to 0x0C (INT32M+XT32M on, PLL off).
   * Write 0x1C to set RB_CLK_PLL_PON (bit4) with a direct write so the
   * entire operation fits within the ~16-cycle safe-access window. */
  SAFE_ACCESS_OPEN();
  R8_HFCK_PWR_CTRL = 0x1C;
  SAFE_ACCESS_CLOSE();

  /* Step 2: Wait for PLL to stabilize.
   * Datasheet: lock time < 100 µs.  At 6.4 MHz, 2000 iterations ≈ 300 µs. */
  for (volatile uint32_t i = 0; i < 2000; i++) { __NOP(); }

  /* Step 3: Switch HCLK to CK32M direct (CLK_SYS_MOD=0b10 → 32 MHz).
   * The USB peripheral derives its 48 MHz independently via Fpll/10,
   * so HCLK does not need to be 48 MHz.  32 MHz is within the datasheet
   * Fsys spec (15–40 MHz for PLL divisor mode; 32 MHz for CK32M direct).
   * Writing bits[7:6]=10 to R8_CLK_PLL_DIV selects CK32M direct mode;
   * bits[4:0] are ignored in this mode. */
  SAFE_ACCESS_OPEN();
  R8_CLK_PLL_DIV = 0x80;
  __NOP(); __NOP();
  SAFE_ACCESS_CLOSE();
}
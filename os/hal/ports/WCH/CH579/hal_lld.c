#include "hal.h"

void hal_lld_init(void) {
  /* Step 1: Configure the external 32 MHz crystal oscillator (XT32M).
   *
   * R8_XT32M_TUNE (reset 0x31):
   *   C_LOAD = 000b (10 pF) — PCB has external load capacitors C1 and C37 on
   *     the crystal pins, so internal caps are set to minimum to avoid
   *     over-loading the crystal (internal + external stacking shifts freq).
   *   I_BIAS = 10b (125% rated) — slightly above nominal for reliable startup.
   *
   * Must be written before XT32M is selected as CK32M source.  R8_HFCK_PWR_CTRL
   * resets to 0x0C which already has RB_CLK_XT32M_PON set, so the crystal
   * oscillator is already being powered; writing this register early ensures the
   * load cap and bias are correct from the moment of first oscillation. */
  SAFE_ACCESS_OPEN();
  R8_XT32M_TUNE = RB_XT32M_C_LOAD_10PF | RB_XT32M_I_BIAS_125;  /* 0x02 */
  SAFE_ACCESS_CLOSE();

  /* Step 2: Wait for the 32 MHz crystal to start up and stabilise.
   * Crystal startup time is typically 1–5 ms.  Using 100 000 NOP iterations
   * is conservative (≥ 5 ms even at 6.4 MHz startup clock). */
  for (volatile uint32_t i = 0; i < 100000; i++) { __NOP(); }

  /* Step 3: Switch CK32M source from internal RC to external crystal, then
   * power on the PLL.  Both writes go in the same safe-access window to keep
   * the sequence atomic.
   *
   * RB_CLK_OSC32M_XT (bit1 of R8_CLK_SYS_CFG_H) must be set BEFORE enabling
   * the PLL so the PLL locks onto the accurate external crystal (±50 ppm)
   * rather than the internal RC oscillator (±2% = ±20 000 ppm, out-of-spec
   * for USB which requires ±2 500 ppm). */
  SAFE_ACCESS_OPEN();
  R8_CLK_SYS_CFG_H = RB_CLK_OSC32M_XT;    /* CK32M ← external crystal (other bits reserved, reset=0) */
  SAFE_ACCESS_CLOSE();
  SAFE_ACCESS_OPEN();
  R8_HFCK_PWR_CTRL = 0x1C;                 /* XT32M_PON | bit3 | PLL_PON    */
  SAFE_ACCESS_CLOSE();

  /* Step 4: Wait for PLL to stabilise.
   * Datasheet: lock time < 100 µs.  2 000 NOP iterations ≥ 300 µs. */
  for (volatile uint32_t i = 0; i < 2000; i++) { __NOP(); }

  /* Step 5: Switch HCLK to CK32M direct (CLK_SYS_MOD=0b10 → 32 MHz).
   * The USB peripheral derives its 48 MHz independently from the PLL,
   * so HCLK need not be 48 MHz.  bits[7:6]=10 selects CK32M direct mode;
   * bits[4:0] are ignored in this mode. */
  SAFE_ACCESS_OPEN();
  R8_CLK_PLL_DIV = 0x80;
  __NOP(); __NOP();
  SAFE_ACCESS_CLOSE();
}
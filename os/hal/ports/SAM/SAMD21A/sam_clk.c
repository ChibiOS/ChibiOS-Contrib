#include "hal.h"
#include "sam_clk.h"

void sam_gclk_init(uint32_t id, uint32_t sysctrl_src, uint16_t gendiv, bool enable)
{
    if(enable) {
        switch(id) {
            case 2:
                osalDbgAssert(gendiv < (1U << 5), "GENDIV exceeded");
                break;
            case 1:
                break;
            default:
                osalDbgAssert(gendiv < (1U << 8), "GENDIV exceeded");
                break;
        }
    }
    GCLK_REGS->GCLK_GENDIV = GCLK_GENDIV_ID(id) | GCLK_GENDIV_DIV(gendiv);
    GCLK_REGS->GCLK_GENCTRL = GCLK_GENCTRL_ID(id) | sysctrl_src | GCLK_GENCTRL_IDC(1) | GCLK_GENCTRL_GENEN(enable);
    while((GCLK_REGS->GCLK_STATUS & GCLK_STATUS_SYNCBUSY_Msk) == GCLK_STATUS_SYNCBUSY_Msk);
}

void sam_gclk_mux(uint32_t id, uint32_t dest, bool enable)
{
    GCLK_REGS->GCLK_CLKCTRL = GCLK_CLKCTRL_GEN(id) | GCLK_CLKCTRL_ID(dest) | GCLK_CLKCTRL_CLKEN(enable); // Hook up the clock
    while((GCLK_REGS->GCLK_STATUS & GCLK_STATUS_SYNCBUSY_Msk) == GCLK_STATUS_SYNCBUSY_Msk);
}
/*
    Copyright (C) 2019 /u/KeepItUnder

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
 * @file    NUC123SD4AN0/hal_lld.c
 * @brief   NUC123SD4AN0 HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define NUC123_PLLXTPRE_OFFSET   17          /**< PLLXTPRE offset             */
#define NUC123_PLLXTPRE_MASK     0x01        /**< PLLXTPRE mask               */

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   CMSIS system core clock variable.
 * @note    It is declared in system_NUC123SD4AN0.h.
 */
//uint32_t SystemCoreClock = NUC123_HCLK;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(NUC123_DMA_REQUIRED) || defined(__DOXYGEN__)
#if defined(NUC123_DMA1_CH23_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA1 streams 2 and 3 shared ISR.
 * @note    It is declared here because this device has a non-standard
 *          DMA shared IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(NUC123_DMA1_CH23_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 2.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM2);

  /* Check on channel 3.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM3);

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(NUC123_DMA1_CH23_HANDLER) */

#if defined(NUC123_DMA1_CH4567_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA1 streams 4, 5, 6 and 7 shared ISR.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(NUC123_DMA1_CH4567_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 4.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM4);

  /* Check on channel 5.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM5);

#if NUC123_DMA1_NUM_CHANNELS > 5
  /* Check on channel 6.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM6);
#endif

#if NUC123_DMA1_NUM_CHANNELS > 6
  /* Check on channel 7.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM7);
#endif

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(NUC123_DMA1_CH4567_HANDLER) */

#if defined(NUC123_DMA12_CH23_CH12_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA1 streams 2 and 3, DMA2 streams 1 and 1 shared ISR.
 * @note    It is declared here because this device has a non-standard
 *          DMA shared IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(NUC123_DMA12_CH23_CH12_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 2 of DMA1.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM2);

  /* Check on channel 3 of DMA1.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM3);

  /* Check on channel 1 of DMA2.*/
  dmaServeInterrupt(NUC123_DMA2_STREAM1);

  /* Check on channel 2 of DMA2.*/
  dmaServeInterrupt(NUC123_DMA2_STREAM2);

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(NUC123_DMA12_CH23_CH12_HANDLER) */

#if defined(NUC123_DMA12_CH4567_CH345_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA1 streams 4, 5, 6 and 7, DMA2 streams 3, 4 and 5 shared ISR.
 * @note    It is declared here because this device has a non-standard
 *          DMA shared IRQ handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(NUC123_DMA12_CH4567_CH345_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 4 of DMA1.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM4);

  /* Check on channel 5 of DMA1.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM5);

  /* Check on channel 6 of DMA1.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM6);

  /* Check on channel 7 of DMA1.*/
  dmaServeInterrupt(NUC123_DMA1_STREAM7);

  /* Check on channel 3 of DMA2.*/
  dmaServeInterrupt(NUC123_DMA2_STREAM3);

  /* Check on channel 4 of DMA2.*/
  dmaServeInterrupt(NUC123_DMA2_STREAM4);

  /* Check on channel 5 of DMA2.*/
  dmaServeInterrupt(NUC123_DMA2_STREAM5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(NUC123_DMA12_CH4567_CH345_HANDLER) */
#endif /* defined(NUC123_DMA_REQUIRED) */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  /* Reset of all peripherals.*/
// **NUC123TODO
#if defined(NUC123_DMA_REQUIRED)
  //dmaInit();
  //usbInit();
  //uartInit();
  //spiInit();
#endif
  //usbInit();

}

/**
 * @brief   NUC123 clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
void NUC123_clock_init(void) {
    SystemUnlockReg();

    /* Enable XT1_OUT (PF.0) and XT1_IN (PF.1) */
    SYS->GPF_MFP |= SYS_GPF_MFP_PF0_XT1_OUT | SYS_GPF_MFP_PF1_XT1_IN;

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Enable Internal RC 22.1184 MHz clock */
    CLK->PWRCON |= CLK_PWRCON_OSC22M_EN_Msk;
    
    /* Waiting for Internal RC clock ready */
    clks_lld_wait_for_clock_ready(CLK_CLKSTATUS_OSC22M_STB_Msk);

    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    clks_lld_set_HCLK(CLK_CLKSEL0_HCLK_S_HIRC, CLK_CLKDIV_HCLK(1));

    /* Enable external XTAL 12 MHz clock */
    CLK->PWRCON |= CLK_PWRCON_XTL12M_EN_Msk;

    /* Waiting for external XTAL clock ready */
    clks_lld_wait_for_clock_ready(CLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Set core clock */
    clks_lld_set_core_clock(FREQ_72MHZ);

    SystemCoreClock = NUC123_HCLK;

    clks_lld_enable_SysTick(CLK_CLKSEL0_STCLK_S_HCLK_DIV2, (NUC123_HCLK / OSAL_ST_FREQUENCY) - 1);

    /* Enable module clock */
    clks_lld_enable_module_clock(USBD_ModuleNum);

    /* Select module clock source */
    clks_lld_set_module_clock(USBD_ModuleNum, 0, CLK_CLKDIV_USB(3));

    /* TEMPORARY!!! */
    /* Set GPB multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFP = (SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD);
    /* Set PC.13 as CLKO function pin */
    //SYS->GPC_MFP = SYS_GPC_MFP_PC13_CLKO;
    //SYS->ALT_MFP = SYS_ALT_MFP_PC13_CLKO;

    /* Enable CLKO (PC.13) for monitor HCLK. CLKO = HCLK/8 Hz*/
    // clks_lld_enable_ck0(CLK_CLKSEL2_FRQDIV_S_HCLK, 2, 0);

    LOCKREG();
}

/** @} */

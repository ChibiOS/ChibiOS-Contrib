/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio
              Copyright (C) 2020 Yaotian Feng

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
 * @file    hal_lld.c
 * @brief   PLATFORM HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */


#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
  * @brief update the value of SystemCoreClock after changing the system clock.
  */
unsigned int SystemCoreClock;
unsigned int SystemFrequency_SysClk;
unsigned int SystemFrequency_AHBClk;
unsigned int SystemFrequency_APBClk;
unsigned int HRC48Frequency;
unsigned int PLL0Frequency;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

void HardFault_Handler(void)
{
    while(1);
}

uint32_t g_es_systick_time = 0U;

int es_test_printf(char *pBuffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        while (!((UART1->STAT) & (UART_STAT_TFEMPTY)));  // Tx FIFO empty
        UART1->TXDATA = pBuffer[i];            // Sent byte
    }

    return size;
}

void gpio_config(void){
	  md_gpio_inittypedef gpiox;
    /* config gpiob pin6 (Tx) */
	  gpiox.Pin   = MD_GPIO_PIN_6;
    gpiox.Mode  = MD_GPIO_MODE_FUNCTION;
    gpiox.OutputType = MD_GPIO_OUTPUT_PUSHPULL;
    gpiox.Pull  = MD_GPIO_PULL_FLOATING;
    gpiox.OutDrive = MD_GPIO_DRIVING_8MA;
    gpiox.Function = MD_GPIO_AF2;
	  md_gpio_init(GPIOB, &gpiox);
    /* config gpiob pin7 (Rx) */
	  gpiox.Pin   = MD_GPIO_PIN_7;
    gpiox.Mode  = MD_GPIO_MODE_FUNCTION;
    gpiox.OutputType = MD_GPIO_OUTPUT_PUSHPULL;
    gpiox.Pull  = MD_GPIO_PULL_UP;
    gpiox.OutDrive = MD_GPIO_DRIVING_8MA;
    gpiox.Function = MD_GPIO_AF2;
	  md_gpio_init(GPIOB, &gpiox);
}

md_rcu_init_typedef rcu_initStruct =    /**< RCU init structure */
{
    MD_RCU_MPRE_MCO_DIV1,
    MD_RCU_MSW_MCO_DISABLE,
    MD_RCU_PLLSRC_HRC48,
    MD_RCU_PLLCLK_72M,
    MD_RCU_PPRE_HCLK_DIV_1,
    MD_RCU_HPRE_SYSCLK_DIV_1,
    MD_RCU_SW_SYSCLK_PLL0,
    (RCU_CON_HRCON | RCU_CON_PLL0ON | RCU_CON_HRC48ON_MSK),
};

md_uart_init_typedef uart_initStruct =    /**< UART init structure */
{
    (921600U),
    MD_UART_LCON_LSB_FIRST,
    MD_UART_LCON_PS_NONE,
    MD_UART_LCON_STOP_1,
    MD_UART_LCON_DLS_8,
};

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
    __disable_irq();
    md_rcu_pll0_init(RCU, &rcu_initStruct);
    md_rcu_sys_init(RCU, &rcu_initStruct);
    md_rcu_enable_gpioa(RCU);
    md_rcu_enable_gpiob(RCU);
    md_rcu_enable_gpioc(RCU);
    md_rcu_enable_gpiod(RCU);
    md_rcu_enable_uart1(RCU);
    md_rcu_enable_usb(RCU);
    gpio_config();
	
//	NVIC->ICER[0] = 0xFFFFFFFFUL;
//	md_tick_init(MD_SYSTICK_CLKSRC_HCLK);
//    md_mcu_irq_config(UART1_IRQn, 2, ENABLE);
    md_uart_init(UART1, &uart_initStruct);
//    md_uart_enable_it_rfnempty(UART1);
	
    __enable_irq();

    es_test_printf("hal_lld_init ok\r\n",sizeof("hal_lld_init ok\r\n"));

}

/** @} */

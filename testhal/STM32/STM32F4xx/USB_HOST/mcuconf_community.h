/*
    ChibiOS/RT - Copyright (C) 2014 Uladzimir Pylinsky aka barthess

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

/*
 * FSMC driver system settings.
 */
#define STM32_FSMC_USE_FSMC1                FALSE
#define STM32_FSMC_FSMC1_IRQ_PRIORITY       10

/*
 * FSMC NAND driver system settings.
 */
#define STM32_NAND_USE_FSMC_NAND1           FALSE
#define STM32_NAND_USE_FSMC_NAND2           FALSE
#define STM32_NAND_USE_EXT_INT              FALSE
#define STM32_NAND_DMA_STREAM               STM32_DMA_STREAM_ID(2, 7)
#define STM32_NAND_DMA_PRIORITY             0
#define STM32_NAND_DMA_ERROR_HOOK(nandp)    osalSysHalt("DMA failure")

/*
 * FSMC SRAM driver system settings.
 */
#define STM32_USE_FSMC_SRAM                 FALSE
#define STM32_SRAM_USE_FSMC_SRAM1           FALSE
#define STM32_SRAM_USE_FSMC_SRAM2           FALSE
#define STM32_SRAM_USE_FSMC_SRAM3           FLASE
#define STM32_SRAM_USE_FSMC_SRAM4           FALSE

/*
 * FSMC SDRAM driver system settings.
 */
#define STM32_USE_FSMC_SDRAM                FALSE


/*
 * USBH driver system settings.
 */

#define STM32_OTG1_CHANNELS_NUMBER		8
#define STM32_OTG2_CHANNELS_NUMBER		12

#define STM32_USBH_USE_OTG1				1
#define STM32_OTG1_RXFIFO_SIZE			1024
#define STM32_OTG1_PTXFIFO_SIZE			128
#define STM32_OTG1_NPTXFIFO_SIZE		128

#define STM32_USBH_USE_OTG2				0
#define STM32_OTG2_RXFIFO_SIZE			2048
#define STM32_OTG2_PTXFIFO_SIZE			1024
#define STM32_OTG2_NPTXFIFO_SIZE		1024

#define STM32_USBH_MIN_QSPACE			4
#define STM32_USBH_CHANNELS_NP 			4

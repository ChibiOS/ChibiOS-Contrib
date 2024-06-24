/*
 * Instance header file for ATSAME54P20A
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2023-03-17T09:50:08Z */
#ifndef _SAME54_SERCOM2_INSTANCE_
#define _SAME54_SERCOM2_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM2 peripheral ========== */
#define SERCOM2_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM2_DLY_COMPENSATION                 (1)        /* Compensates for a fast DLY50 element. Assuming 20ns */
#define SERCOM2_DMA                              (1)        /* DMA support implemented? */
#define SERCOM2_DMAC_ID_RX                       (8)        /* Index of DMA RX trigger */
#define SERCOM2_DMAC_ID_TX                       (9)        /* Index of DMA TX trigger */
#define SERCOM2_FIFO_DEPTH_POWER                 (1)        /* 2^FIFO_DEPTH_POWER gives rx FIFO depth. */
#define SERCOM2_GCLK_ID_CORE                     (23)       
#define SERCOM2_GCLK_ID_SLOW                     (3)        
#define SERCOM2_I2CM                             (1)        /* I2C Master mode implemented? */
#define SERCOM2_I2CS                             (1)        /* I2C Slave mode implemented? */
#define SERCOM2_I2CS_AUTO_ACK                    (1)        /* I2C slave automatic acknowledge implemented? */
#define SERCOM2_I2CS_GROUP_CMD                   (1)        /* I2C slave group command implemented? */
#define SERCOM2_I2CS_SDASETUP_CNT_SIZE           (8)        /* I2CS sda setup count size */
#define SERCOM2_I2CS_SDASETUP_SIZE               (4)        /* I2CS sda setup size */
#define SERCOM2_I2CS_SUDAT                       (1)        /* I2C slave SDA setup implemented? */
#define SERCOM2_I2C_0_INT_SRC                    (54)       /* I2C 0 Interrupt */
#define SERCOM2_I2C_1_INT_SRC                    (55)       /* I2C 1 Interrupt */
#define SERCOM2_I2C_2_INT_SRC                    (56)       /* I2C 2 Interrupt */
#define SERCOM2_I2C_3_INT_SRC                    (57)       /* I2C 3 Interrupt */
#define SERCOM2_I2C_FASTMP                       (1)        /* I2C fast mode plus implemented? */
#define SERCOM2_I2C_HSMODE                       (1)        /* USART mode implemented? */
#define SERCOM2_I2C_SCLSM_MODE                   (1)        /* I2C SCL clock stretch mode implemented? */
#define SERCOM2_I2C_SMB_TIMEOUTS                 (1)        /* I2C SMBus timeouts implemented? */
#define SERCOM2_I2C_TENBIT_ADR                   (1)        /* I2C ten bit enabled? */
#define SERCOM2_INSTANCE_ID                      (41)       /* Instance index for SERCOM2 */
#define SERCOM2_INT_MSB                          (6)        
#define SERCOM2_PMSB                             (3)        
#define SERCOM2_RETENTION_SUPPORT                (0)        /* Retention supported? */
#define SERCOM2_SE_CNT                           (1)        /* SE counter included? */
#define SERCOM2_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM2_SPI_ERROR_INT_SRC                (57)       /* SPI ERROR Interrupt */
#define SERCOM2_SPI_HW_SS_CTRL                   (1)        /* Master _SS hardware control implemented? */
#define SERCOM2_SPI_ICSPACE_EXT                  (1)        /* SPI inter character space implemented? */
#define SERCOM2_SPI_OZMO                         (0)        /* OZMO features implemented? */
#define SERCOM2_SPI_RX_INT_SRC                   (56)       /* SPI RX Interrupt */
#define SERCOM2_SPI_TX_COMPLETE_INT_SRC          (55)       /* SPI TX COMPLETE Interrupt */
#define SERCOM2_SPI_TX_READY_INT_SRC             (54)       /* SPI TX READY Interrupt */
#define SERCOM2_SPI_WAKE_ON_SSL                  (1)        /* _SS low detect implemented? */
#define SERCOM2_TTBIT_EXTENSION                  (1)        /* 32-bit extension implemented? */
#define SERCOM2_USART                            (1)        /* USART mode implemented? */
#define SERCOM2_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM2_USART_COLDET                     (1)        /* USART collision detection implemented? */
#define SERCOM2_USART_ERROR_INT_SRC              (57)       /* USART ERROR Interrupt */
#define SERCOM2_USART_FLOW_CTRL                  (1)        /* USART flow control implemented? */
#define SERCOM2_USART_FRAC_BAUD                  (1)        /* USART fractional BAUD implemented? */
#define SERCOM2_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM2_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM2_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM2_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM2_USART_RX_INT_SRC                 (56)       /* USART RX Interrupt */
#define SERCOM2_USART_SAMPA_EXT                  (1)        /* USART sample adjust implemented? */
#define SERCOM2_USART_SAMPR_EXT                  (1)        /* USART oversampling adjustment implemented? */
#define SERCOM2_USART_TX_COMPLETE_INT_SRC        (55)       /* USART TX COMPLETE Interrupt */
#define SERCOM2_USART_TX_READY_INT_SRC           (54)       /* USART TX READY Interrupt */

#endif /* _SAME54_SERCOM2_INSTANCE_ */

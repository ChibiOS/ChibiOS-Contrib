/*
    Copyright (C) 2024 Dimitris Mantzouranis

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

#ifndef SN32_UART_H
#    define SN32_UART_H

typedef struct {
    union {
        union {
            __IM uint32_t RB;

            struct {
                __IM uint32_t RB : 8;
            } RB_b;
        };

        union {
            __OM uint32_t TH;

            struct {
                __OM uint32_t TH : 8;
            } TH_b;
        };

        union {
            __IOM uint32_t DLL;

            struct {
                __IOM uint32_t DLL : 8;
            } DLL_b;
        };
    };

    union {
        union {
            __IOM uint32_t DLM;

            struct {
                __IOM uint32_t DLM : 8;
            } DLM_b;
        };

        union {
            __IOM uint32_t IE;

            struct {
                __IOM uint32_t RDAIE : 1;
                __IOM uint32_t THREIE : 1;
                __IOM uint32_t RLSIE : 1;
                __IM           uint32_t : 1;
                __IOM uint32_t TEMTIE : 1;
                __IM           uint32_t : 3;
                __IOM uint32_t ABEOIE : 1;
                __IOM uint32_t ABTOIE : 1;
            } IE_b;
        };
    };

    union {
        union {
            __IM uint32_t II;

            struct {
                __IM uint32_t INTSTATUS : 1;
                __IM uint32_t INTID : 3;
                __IM          uint32_t : 2;
                __IM uint32_t FIFOEN : 2;
                __IM uint32_t ABEOIF : 1;
                __IM uint32_t ABTOIF : 1;
            } II_b;
        };

        union {
            __OM uint32_t FIFOCTRL;

            struct {
                __OM uint32_t FIFOEN : 1;
                __IM          uint32_t : 5;
                __OM uint32_t RXTL : 2;
            } FIFOCTRL_b;
        };
    };

    union {
        __IOM uint32_t LC;

        struct {
            __IOM uint32_t WLS : 2;
            __IOM uint32_t SBS : 1;
            __IOM uint32_t PE : 1;
            __IOM uint32_t PS : 2;
            __IOM uint32_t BC : 1;
            __IOM uint32_t DLAB : 1;
        } LC_b;
    };
    __IM uint32_t RESERVED;

    union {
        __IM uint32_t LS;

        struct {
            __IM uint32_t RDR : 1;
            __IM uint32_t OE : 1;
            __IM uint32_t PE : 1;
            __IM uint32_t FE : 1;
            __IM uint32_t BI : 1;
            __IM uint32_t THRE : 1;
            __IM uint32_t TEMT : 1;
            __IM uint32_t RXFE : 1;
        } LS_b;
    };
    __IM uint32_t RESERVED1;

    union {
        __IOM uint32_t SP;

        struct {
            __IOM uint32_t PAD : 8;
        } SP_b;
    };

    union {
        __IOM uint32_t ABCTRL;

        struct {
            __IOM uint32_t START : 1;
            __IOM uint32_t MODE : 1;
            __IOM uint32_t AUTORESTART : 1;
            __IM           uint32_t : 5;
            __OM uint32_t  ABEOIFC : 1;
            __OM uint32_t  ABTOIFC : 1;
        } ABCTRL_b;
    };
    __IM uint32_t RESERVED2;

    union {
        __IOM uint32_t FD;

        struct {
            __IOM uint32_t DIVADDVAL : 4;
            __IOM uint32_t MULVAL : 4;
            __IOM uint32_t OVER8 : 1;
        } FD_b;
    };
    __IM uint32_t RESERVED3;

    union {
        __IOM uint32_t CTRL;

        struct {
            __IOM uint32_t UARTEN : 1;
            __IOM uint32_t MODE : 3;
            __IM           uint32_t : 2;
            __IOM uint32_t RXEN : 1;
            __IOM uint32_t TXEN : 1;
        } CTRL_b;
    };

    union {
        __IOM uint32_t HDEN;

        struct {
            __IOM uint32_t HDEN : 1;
        } HDEN_b;
    };
} sn32_uart_t;

/** @defgroup UART_Exported_Constants
  * @{
  */

/** @defgroup UART_LineControl
  * @{
  */
#define UART_Break_Control_Disable             (0x0<<6)
#define UART_Break_Control_Enable              (0x1<<6)
#define UART_Divisor_Latch_Access_Disable      (0x0<<7)
#define UART_Divisor_Latch_Access_Enable       (0x1<<7)
#define UART_Parity_None                       (0x0<<3)
#define UART_Parity_Enable                     (0x1<<3)
#define UART_Parity_Odd                        (0x00<<4)
#define UART_Parity_Even                       (0x01<<4)
#define UART_Parity_Mark                       (0x02<<4)
#define UART_Parity_Space                      (0x03<<4)
#define UART_StopBits_One                      (0x0<<2)
#define UART_StopBits_Two                      (0x1<<2)
#define UART_WordLength_5b                     (0x00)
#define UART_WordLength_6b                     (0x01)
#define UART_WordLength_7b                     (0x02)
#define UART_WordLength_8b                     (0x03)
/**
  * @}
  */


/** @defgroup UART_AutoBaudControl
  * @{
  */
#define UART_AutoBaudControl_None              0
#define UART_AutoBaudControl_Start             (0x01)
#define UART_AutoBaudControl_Restart           (UART_AutoBaudControl_Start <<2)
#define UART_AutoBaudControl_End               (UART_AutoBaudControl_Start <<8)
#define UART_AutoBaudControl_Timeout           (UART_AutoBaudControl_Start <<9)
#define UART_ABCTRL_MODE(x)                    ((0x00 + x) << 1)
/**
  * @}
  */


/** @defgroup UART_FIFOControl
  * @{
  */
#define UART_FIFO_Enable                       (0x01)
#define UART_RxFIFO_Reset                      (0x01<<1)
#define UART_TxFIFO_Reset                      (0x01<<2)
#define UART_RxFIFOThreshold_1                 (0x00<<6)
#define UART_RxFIFOThreshold_4                 (0x01<<6)
#define UART_RxFIFOThreshold_8                 (0x02<<6)
#define UART_RxFIFOThreshold_14                (0x03<<6)
/**
  * @}
  */


/** @defgroup UART_FractionalDivider
  * @{
  */
#define UART_Oversample_8                      (0x1<<8)
#define UART_Oversample_16                     (0x0<<8)
#define UART_FD_MULVAL(x)                      (((0x0000 + x) - 1) << 4)
#define UART_FD_DIVADDVAL(x)                   (0x000 +x)
/**
  * @}
  */

/** @defgroup UART_InterruptEnable
  * @{
  */
#define UART_InterruptEnable                   (0x01)
#define UART_TxError                           (UART_InterruptEnable <<10)
#define UART_AutoBaudTimeout                   (UART_InterruptEnable <<9)
#define UART_AutoBaudEnd                       (UART_InterruptEnable <<8)
#define UART_TransmitterEmpty                  (UART_InterruptEnable <<4)
#define UART_ModemStatus                       (UART_InterruptEnable <<3)
#define UART_ReceiveLine                       (UART_InterruptEnable <<2)
#define UART_TransmitterHoldingEmpty           (UART_InterruptEnable <<1)
#define UART_ReceiveDataAvailable              (UART_InterruptEnable <<0)
/**
  * @}
  */

/** @defgroup UART_InterruptIdentification
  * @{
  */
#define UART_Interrupt_Pending                 0
#define UART_InterruptID_THRE                  1
#define UART_InterruptID_RDA                   2
#define UART_InterruptID_RLS                   3
#define UART_InterruptID_CTI                   6
#define UART_InterruptID_TEMT                  7
#define UART_Interrupt_TxError                 (0x01<<10)
#define UART_Interrupt_ABTO                    (0x01<<9)
#define UART_Interrupt_ABEO                    (0x01<<8)
#define UART_Interrupt_Status                  (0x01)
#define UART_InterruptID_Status                7

/**
  * @}
  */

/** @defgroup UART_LineStatus
  * @{
  */
#define UART_LineStatus_TxError                (0x01<<8)
#define UART_LineStatus_RxError                (0x01<<7)
#define UART_LineStatus_TEMT                   (0x01<<6)
#define UART_LineStatus_THRE                   (0x01<<5)
#define UART_LineStatus_BI                     (0x01<<4)
#define UART_LineStatus_FE                     (0x01<<3)
#define UART_LineStatus_PE                     (0x01<<2)
#define UART_LineStatus_OE                     (0x01<<1)
#define UART_LineStatus_RDR                    (0x01)

/**
  * @}
  */

/** @defgroup UART_Control
  * @{
  */
#define UART_Enable                            (0x01)
#define UART_RxEnable                          (UART_Enable <<6)
#define UART_TxEnable                          (UART_Enable <<7)
/**
  * @}
  */

/** @defgroup UART_HalfDuplexMode
  * @{
  */
#define UART_HalfDuplexEnable                  (0x01)
#define UART_FullDuplexEnable                  0
/**
 * @}
 */

#endif /* SN32_UART_H */

/** @} */

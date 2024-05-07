/*
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
 * @file    hal_serial_lld.c
 * @brief   ES32 serial subsystem low level driver source.
 *
 * @addtogroup SERIAL
 * @{
 */

#include "hal.h"

#if (HAL_USE_SERIAL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief UART serial driver identifier.*/
#if ES32_SERIAL_USE_UART1 || defined(__DOXYGEN__)
SerialDriver SD1;
#endif
#if ES32_SERIAL_USE_UART2 || defined(__DOXYGEN__)
SerialDriver SD2;
#endif
#if ES32_SERIAL_USE_UART3 || defined(__DOXYGEN__)
SerialDriver SD3;
#endif
#if ES32_SERIAL_USE_UART4 || defined(__DOXYGEN__)
SerialDriver SD4;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   Driver default configuration.
 */
static const SerialConfig default_config = {SERIAL_DEFAULT_BITRATE};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void serialInterrupt(SerialDriver *pSd)
{
    uint32_t isr_ifm = (pSd->usart)->IFM;

    (pSd->usart)->ICR = isr_ifm;

    while(((pSd->usart)->STAT) & (UART_STAT_RFNEMPTY_MSK))
    {
        sdIncomingDataI(sdp, (pSd->usart)->RXDATA);
    }
    
    if(isr_ifm & UART_IFM_TXE_MSK)
    {
        msg_t b;
        osalSysLockFromISR();
        b = oqGetI(&sdp->oqueue);
        if (b < MSG_OK) {
          chnAddFlagsI(sdp, CHN_OUTPUT_EMPTY);
          (pSd->usart)->IDR &= ~(UART_IER_TXE);
        }
        else
          (pSd->usart)->IXDATA = b;
        osalSysUnlockFromISR();
    }
}

md_uart_init_typedef uart_initStruct =    /**< UART init structure */
{
    MD_UART_BAUDRATE_115200,
    MD_UART_LCON_LSB_FIRST,
    MD_UART_LCON_PS_NONE,
    MD_UART_LCON_STOP_1,
    MD_UART_LCON_DLS_8,
};

static void usartInit(SerialDriver *sdp, const SerialConfig *config)
{
    uart_initStruct.BaudRate = config->speed;
    md_uart_init(sdp->usart, &uart_initStruct);
    (sdp->usart)->IER = UART_IER_RFNEMPTY;
}


#if ES32_SERIAL_USE_UART1 || defined(__DOXYGEN__)
static void notify1(io_queue_t *qp) {

  (void)qp;
  UART1->IER = UART_IER_TXE;
}
#endif

#if ES32_SERIAL_USE_UART2 || defined(__DOXYGEN__)
static void notify2(io_queue_t *qp) {

  (void)qp;
  UART2->IER = UART_IER_TXE;
}
#endif

#if ES32_SERIAL_USE_UART3 || defined(__DOXYGEN__)
static void notify3(io_queue_t *qp) {

  (void)qp;
  UART3->IER = UART_IER_TXE;
}
#endif

#if ES32_SERIAL_USE_UART4 || defined(__DOXYGEN__)
static void notify4(io_queue_t *qp) {

  (void)qp;
  UART4->IER = UART_IER_TXE;
}
#endif


/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/
#if ES32_SERIAL_USE_UART1 || defined(__DOXYGEN__)
//UART1_HANDLER
OSAL_IRQ_HANDLER(VectorAC) {

  OSAL_IRQ_PROLOGUE();

  serialInterrupt(&SD1);

  OSAL_IRQ_EPILOGUE();
}
#endif
#if ES32_SERIAL_USE_UART2 || defined(__DOXYGEN__)
//UART2_HANDLER
OSAL_IRQ_HANDLER(VectorB0) {

  OSAL_IRQ_PROLOGUE();

  serialInterrupt(&SD2);

  OSAL_IRQ_EPILOGUE();
}
#endif
#if ES32_SERIAL_USE_UART3 || defined(__DOXYGEN__)
//UART3_HANDLER
OSAL_IRQ_HANDLER(VectorB4) {

  OSAL_IRQ_PROLOGUE();

  serialInterrupt(&SD3);

  OSAL_IRQ_EPILOGUE();
}
#endif
#if ES32_SERIAL_USE_UART4 || defined(__DOXYGEN__)
//UART4_HANDLER
OSAL_IRQ_HANDLER(VectorB8) {

  OSAL_IRQ_PROLOGUE();

  serialInterrupt(&SD4);

  OSAL_IRQ_EPILOGUE();
}
#endif
/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level serial driver initialization.
 *
 * @notapi
 */
void sd_lld_init(void)
{
#if ES32_SERIAL_USE_UART1
    md_rcu_enable_uart1(RCU);
    sdObjectInit(&SD1, NULL, notify1);
    SD1.usart = UART1;
    nvicEnableVector(UART1_IRQn, ES32_SERIAL_UART1_PRIORITY);
#endif

#if ES32_SERIAL_USE_UART2
    md_rcu_enable_uart2(RCU);
    sdObjectInit(&SD2, NULL, notify2);
    SD2.usart = UART2;
    nvicEnableVector(UART2_IRQn, ES32_SERIAL_UART2_PRIORITY);
#endif

#if ES32_SERIAL_USE_UART3
    md_rcu_enable_uart3(RCU);
    sdObjectInit(&SD3, NULL, notify3);
    SD3.usart = UART3;
    nvicEnableVector(UART3_IRQn, ES32_SERIAL_UART3_PRIORITY);
#endif

#if ES32_SERIAL_USE_UART4
    md_rcu_enable_uart4(RCU);
    sdObjectInit(&SD4, NULL, notify4);
    SD4.usart = UART4;
    nvicEnableVector(UART4_IRQn, ES32_SERIAL_UART4_PRIORITY);
#endif


}

/**
 * @brief   Low level serial driver configuration and (re)start.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] config    the architecture-dependent serial driver configuration.
 *                      If this parameter is set to @p NULL then a default
 *                      configuration is used.
 *
 * @notapi
 */
void sd_lld_start(SerialDriver *sdp, const SerialConfig *config)
{
    (void)sdp;
    (void)config;
}

/**
 * @brief   Low level serial driver stop.
 * @details De-initializes the UART, stops the associated clock, resets the
 *          interrupt vector.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 *
 * @notapi
 */
void sd_lld_stop(SerialDriver *sdp)
{
    (void)sdp;
}

#endif /* HAL_USE_SERIAL == TRUE */

/** @} */

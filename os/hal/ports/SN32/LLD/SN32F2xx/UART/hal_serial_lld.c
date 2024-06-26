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

/**
 * @file    UART/hal_serial_lld.c
 * @brief   SN32 low level serial driver code.
 *
 * @addtogroup SERIAL
 * @{
 */

#include "hal.h"
#include "matrix.h"
#include "print.h"
#include <math.h>
#if HAL_USE_SERIAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief UART0 serial driver identifier.*/
#if SN32_SERIAL_USE_UART0 || defined(__DOXYGEN__)
SerialDriver SD0;
#endif

/** @brief UART1 serial driver identifier.*/
#if SN32_SERIAL_USE_UART1 || defined(__DOXYGEN__)
SerialDriver SD1;
#endif

/** @brief UART2 serial driver identifier.*/
#if SN32_SERIAL_USE_UART2 || defined(__DOXYGEN__)
SerialDriver SD2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/* Driver default configuration.*/
static const SerialConfig default_config = {SERIAL_DEFAULT_BITRATE,
                                            UART_WordLength_8b,
                                            UART_StopBits_One,
                                            UART_Parity_None,
                                            (UART_FIFO_Enable | UART_RxFIFOThreshold_1),
                                            UART_AutoBaudControl_None,
                                            UART_Oversample_16,
                                            UART_FullDuplexEnable};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
#if SN32_UART_USE_FD || defined(__DOXYGEN__)
void UART_divisor_CAL(uint32_t baudrate,uint32_t UART_PCLK,uint8_t Oversampling,uint8_t *dlm,uint8_t *dll,uint8_t  *d_divaddval,uint8_t  *d_mulval)
{
  float expected_val;
  uint8_t divaddval[2],mulval[2];
  uint8_t divider_Index = 0;
  uint8_t f_divider_new=0;
  uint16_t  divisor=0;
  float   divider_plus,divider_minus,divider_expected;
  uint32_t  i,j,k;
  
  //Init
  for(i=0;i<2;i++)  {
    mulval[i] = 0;
    divaddval[i] = 0;
  }
  
  expected_val = (float)(UART_PCLK/Oversampling/baudrate);
  
  if((int)expected_val == expected_val) {
    divisor = expected_val;
    // no fractional divider needed
    divaddval[0] = 0;
    mulval[0] = 1;
  } else {
    // we have to use the fractional divider
    // generate a lookup table
    uint8_t mulval_limit = 16;
    uint8_t divaddval_limit =15;
    float tab_D_div_M[mulval_limit][divaddval_limit]; 
    for (uint8_t i = 0; i < mulval_limit; i++) {
        for (uint8_t j = 0; j < divaddval_limit; j++) {
            tab_D_div_M[i][j] = (float)j / (i + 1);
        }
    }
    // go through the table until we have a match
    for(i=expected_val/2;i<expected_val;i++) {
      if(3<=i && i<0x100) {
        divider_expected = (expected_val)/i - 1;
        divider_plus = (divider_expected+1) *(1+0.011) - 1;
        divider_minus = (divider_expected+1) *(1-0.011) - 1;
        for(j=1;j<mulval_limit;j++) {
          for(k=0;k<divaddval_limit;k++) {
            if(j>k) {
              if(tab_D_div_M[j][k]>divider_minus && tab_D_div_M[j][k]<divider_plus) {
                if(mulval[divider_Index] == 0 && divaddval[divider_Index] == 0) {
                  mulval[divider_Index] = j;
                  divaddval[divider_Index] = k;
                  f_divider_new = 1;
                } else {
                  if((fabs)(tab_D_div_M[j][k]-divider_expected) < (fabs)(tab_D_div_M[mulval[divider_Index]][divaddval[divider_Index]]-divider_expected)) {
                    mulval[divider_Index] = j;
                    divaddval[divider_Index] = k;     
                    f_divider_new = 1;
                  }
                }
              }
            }
          }
        }
      }
      else {
        mulval[divider_Index] = 1;
        divaddval[divider_Index] = 0;
        f_divider_new = 1;        
      }
      if(f_divider_new == 1 ) {
        if(divider_Index == 0) {
          divider_Index++;
          divisor = i;
        } else {
          if((fabs)((tab_D_div_M[mulval[1]][divaddval[1]]+1)*i-expected_val) < (fabs)((tab_D_div_M[mulval[0]][divaddval[0]]+1)*divisor-expected_val)) {
            mulval[0] = mulval[1];
            divaddval[0] = divaddval[1];
            divisor = i;
          }
        }
      }
    }

  }
  // check the divisor is valid
  if(divisor != 0){
    *dlm = (divisor>>8)&0xff;
    *dll = divisor&0xff;
    *d_mulval = mulval[0];
    *d_divaddval = divaddval[0];
  }
}
#endif

/**
 * @brief   UART initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] config    the architecture-dependent serial driver configuration
 */
static void uart_init(SerialDriver *sdp, const SerialConfig *config) {
  uint32_t apbclock;
  uint8_t dlm, dll, divaddval, mulval, oversampling;
  sn32_uart_t *u = sdp->uart;

  // Default to oversampling by 16
  oversampling = (config->UART_Oversampling == UART_Oversample_8) ? 8 : 16;
  apbclock = (SN32_HCLK);

  // Calculate divider
#if SN32_UART_USE_FD || defined(__DOXYGEN__)
  UART_divisor_CAL(config->speed,apbclock,oversampling,&dlm,&dll,&divaddval,&mulval);
#else
  uint32_t divisor = (uint32_t)(apbclock/oversampling/config->speed);
  dlm = (divisor>>8)&0xff;
  dll = divisor&0xff;
  divaddval = 0;
  mulval = 1;
#endif // SN32_UART_USE_FD

  // Update the registers
  u->LC = UART_Divisor_Latch_Access_Enable;
  u->LC |= (config->UART_WordLength
          | config->UART_StopBits
          | config->UART_Parity
          | UART_Break_Control_Disable);

  u->FD_b.MULVAL = mulval;
  u->FD_b.DIVADDVAL = divaddval;
  u->FD_b.OVER8 = (oversampling == 8) ? 1 : 0;
  u->DLM = dlm;
  u->DLL = dll;

  u->LC &= ~(UART_Divisor_Latch_Access_Enable);
  // Disable AutoBaud for serial - not useful
  u->ABCTRL = UART_AutoBaudControl_None;

  // Configure full or half duplex mode
  u->HDEN = config->UART_HalfDuplexMode;

  // Reset FIFO and enable
  // Set RX trigger level
  u->FIFOCTRL = (UART_FIFO_Enable
                | UART_RxFIFO_Reset
                | UART_TxFIFO_Reset
                | config->UART_FIFOControl);

  /* Enable Interrupts*/
  u->IE = (UART_ReceiveDataAvailable | UART_ReceiveLine);

  // Enable UART
  u->CTRL = (UART_Enable| UART_RxEnable | UART_TxEnable);
}

/**
 * @brief   UART de-initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] u         pointer to an UART I/O block
 */
static void uart_deinit(sn32_uart_t *u) {
  // disable FIFOs
  u->FIFOCTRL_b.FIFOEN =0;
  // disable interrupts
  u->IE =0;
  // disable UART peripheral
  u->CTRL =0;
}

/**
 * @brief   Error handling routine.
 *
 * @param[in] sdp       pointer to a @p SerialDriver object
 * @param[in] ls        UART LS register value
*/
static void set_error(SerialDriver *sdp, uint8_t ls) {
  eventflags_t sts = 0;

  if(ls & UART_LineStatus_BI)
    sts |= SD_BREAK_DETECTED;
  if (ls & UART_LineStatus_PE)
    sts |= SD_PARITY_ERROR;
  if (ls & UART_LineStatus_FE)
    sts |= SD_FRAMING_ERROR;

  osalSysLockFromISR();
  chnAddFlagsI(sdp, sts);
  osalSysUnlockFromISR();
}

/**
 * @brief   Common IRQ handler.
 *
 * @param[in] sdp       communication channel associated to the UART
 */
static void serve_interrupt(SerialDriver *sdp) {
  #define UART_LS_STATUS (UART_LineStatus_PE | UART_LineStatus_FE | UART_LineStatus_BI | UART_LineStatus_RxError)
  sn32_uart_t *u = sdp->uart;
  uint32_t ii=u->II;

  while ((ii & UART_Interrupt_Status) == UART_Interrupt_Pending) {
    uint32_t ls = u->LS;
    if (ls & UART_LineStatus_BI) {
      set_error(sdp,UART_LineStatus_BI);
      u-> IE &= ~(UART_ReceiveLine);
      (void)u->RB;
      ii=u->II;
      break;
    }

    if(ls & UART_LS_STATUS) set_error(sdp, ls);

    while (ls & UART_LineStatus_RDR) {
      osalSysLockFromISR();
      if (iqIsEmptyI(&sdp->iqueue))
        chnAddFlagsI(sdp, CHN_INPUT_AVAILABLE);
      osalSysUnlockFromISR();
      osalSysLockFromISR();
      if (iqPutI(&sdp->iqueue, u->RB) < MSG_OK)
        chnAddFlagsI(sdp, SD_OVERRUN_ERROR);
      osalSysUnlockFromISR();
      ls = u->LS;
      }
    uint32_t ie = u->IE;

    if (ie & UART_TransmitterHoldingEmpty) {
      while (ls & UART_LineStatus_THRE) {
      msg_t b;

      osalSysLockFromISR();
      b = oqGetI(&sdp->oqueue);
      osalSysUnlockFromISR();
      if (b < MSG_OK) {
          osalSysLockFromISR();
          chnAddFlagsI(sdp, CHN_OUTPUT_EMPTY);
          osalSysUnlockFromISR();
          u->IE &= ~(UART_TransmitterHoldingEmpty);
          break;
      }
          u->TH = b;
          osalSysUnlockFromISR();
          ls = u->LS;
      }
    }

    if ((ie & UART_TransmitterEmpty) && (ls & UART_LineStatus_TEMT)) {
      osalSysLockFromISR();
      if (oqIsEmptyI(&sdp->oqueue)) {
          chnAddFlagsI(sdp, CHN_TRANSMISSION_END);
          u->IE &= ~(UART_TransmitterEmpty);
      }
      osalSysUnlockFromISR();
    }
    ii=u->II;
  }
}

static void load(SerialDriver *sdp) {
  sn32_uart_t *u = sdp->uart;
  if (u->LS & UART_LineStatus_THRE) {
    osalSysLock();
    msg_t b = oqGetI(&sdp->oqueue);
    osalSysUnlock();
    if (b < MSG_OK) {
      osalSysLock();
      chnAddFlagsI(sdp, CHN_OUTPUT_EMPTY);
      osalSysUnlock();
      return;
    }
    u->TH = b;
  }
  u->IE |= (UART_TransmitterHoldingEmpty | UART_TransmitterEmpty);
}
#if SN32_SERIAL_USE_UART0 || defined(__DOXYGEN__)
static void notify0(io_queue_t *qp) {

  (void)qp;
  load(&SD0);
}
#endif

#if SN32_SERIAL_USE_UART1 || defined(__DOXYGEN__)
static void notify1(io_queue_t *qp) {

  (void)qp;
  load(&SD1);
}
#endif

#if SN32_SERIAL_USE_UART2 || defined(__DOXYGEN__)
static void notify2(io_queue_t *qp) {

  (void)qp;
  load(&SD2);
}
#endif
/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SN32_SERIAL_USE_UART0 || defined(__DOXYGEN__)
#if !defined(SN32_UART0_HANDLER)
#error "SN32_UART0_HANDLER not defined"
#endif
/**
 * @brief   UART0 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_UART0_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&SD0);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if SN32_SERIAL_USE_UART1 || defined(__DOXYGEN__)
#if !defined(SN32_UART1_HANDLER)
#error "SN32_UART1_HANDLER not defined"
#endif
/**
 * @brief   UART1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_UART1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&SD1);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if SN32_SERIAL_USE_UART2 || defined(__DOXYGEN__)
#if !defined(SN32_UART2_HANDLER)
#error "SN32_UART2_HANDLER not defined"
#endif
/**
 * @brief   UART2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_UART2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&SD2);

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
void sd_lld_init(void) {

#if SN32_SERIAL_USE_UART0
  sdObjectInit(&SD0, NULL, notify0);
  SD0.uart = SN32_UART0;
#endif

#if SN32_SERIAL_USE_UART1
  sdObjectInit(&SD1, NULL, notify1);
  SD1.uart = SN32_UART1;
#endif

#if SN32_SERIAL_USE_UART2
  sdObjectInit(&SD2, NULL, notify2);
  SD2.uart = SN32_UART2;
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
void sd_lld_start(SerialDriver *sdp, const SerialConfig *config) {

  if (config == NULL)
    config = &default_config;

  if (sdp->state == SD_STOP) {
#if SN32_SERIAL_USE_UART0
    if (&SD0 == sdp) {
      /* UART0 clock enable.*/
      sys1EnableUART0();
      uart_init(sdp, config);
      nvicEnableVector(SN32_UART0_NUMBER, SN32_SERIAL_UART0_PRIORITY);
    }
#endif
#if SN32_SERIAL_USE_UART1
    if (&SD1 == sdp) {
      /* UART1 clock enable.*/
      sys1EnableUART1();
      uart_init(sdp, config);
      nvicEnableVector(SN32_UART1_NUMBER, SN32_SERIAL_UART1_PRIORITY);
    }
#endif
#if SN32_SERIAL_USE_UART2
    if (&SD2 == sdp) {
      /* UART2 clock enable.*/
      sys1EnableUART2();
      uart_init(sdp, config);
      nvicEnableVector(SN32_UART2_NUMBER, SN32_SERIAL_UART2_PRIORITY);
    }
#endif
  }
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
void sd_lld_stop(SerialDriver *sdp) {

  if (sdp->state == SD_READY) {
    uart_deinit(sdp->uart);
#if SN32_SERIAL_USE_UART0
    if (&SD0 == sdp) {
      /* UART0 DeInit.*/
      sys1DisableUART0();
      nvicDisableVector(SN32_UART0_NUMBER);
      return;
    }
#endif
#if SN32_SERIAL_USE_UART1
    if (&SD1 == sdp) {
      /* UART1 DeInit.*/
      sys1DisableUART1();
      nvicDisableVector(SN32_UART1_NUMBER);
      return;
    }
#endif
#if SN32_SERIAL_USE_UART2
    if (&SD2 == sdp) {
      /* UART2 DeInit.*/
      sys1DisableUART2();
      nvicDisableVector(SN32_UART2_NUMBER);
      return;
    }
#endif
  }
}

#endif /* HAL_USE_SERIAL */

/** @} */

/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   SIO1 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM0 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD1;
#endif

/**
 * @brief   SIO2 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM1 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD2;
#endif

/**
 * @brief   SIO3 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM2 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD3;
#endif

/**
 * @brief   SIO4 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM3 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD4;
#endif

/**
 * @brief   SIO5 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM4 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD5;
#endif

/**
 * @brief   SIO6 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM5 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD6;
#endif

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SAM_SIO_USE_SERCOM0 == TRUE
OSAL_IRQ_HANDLER(SERCOM0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
OSAL_IRQ_HANDLER(SERCOM1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
OSAL_IRQ_HANDLER(SERCOM2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD3);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
OSAL_IRQ_HANDLER(SERCOM3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD4);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
OSAL_IRQ_HANDLER(SERCOM4_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD5);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
OSAL_IRQ_HANDLER(SERCOM5_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD6);
  OSAL_IRQ_EPILOGUE();
}
#endif

/**
 * @brief   Low level SIO driver initialization.
 *
 * @notapi
 */
void sio_lld_init(void)
{

#if SAM_SIO_USE_SERCOM0 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD1);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM0_Msk;
  SIOD1.usart = &SERCOM0_REGS->USART_INT;
  SIOD1.clock = SAM_SERCOM0_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM1 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD2);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM1_Msk;
  SIOD2.usart = &SERCOM1_REGS->USART_INT;
  SIOD2.clock = SAM_SERCOM1_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM2 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD3);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM2_Msk;
  SIOD3.usart = &SERCOM2_REGS->USART_INT;
  SIOD3.clock = SAM_SERCOM2_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM3 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD4);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM3_Msk;
  SIOD4.usart = &SERCOM3_REGS->USART_INT;
  SIOD4.clock = SAM_SERCOM3_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM4 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD5);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM4_Msk;
  SIOD5.usart = &SERCOM4_REGS->USART_INT;
  SIOD5.clock = SAM_SERCOM4_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM5 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD6);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM5_Msk;
  SIOD6.usart = &SERCOM5_REGS->USART_INT;
  SIOD6.clock = SAM_SERCOM5_GCLK_FREQ;
#endif
}

/**
 * @brief   Configures and activates the SIO peripheral.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 * @return              The operation status.
 *
 * @notapi
 */
msg_t sio_lld_start(SIODriver *siop)
{

  if (siop->config == NULL)
  {
    osalDbgAssert(siop->config, "SERCOM requires configuration");
  }
  if (siop->state == SIO_STOP)
  {
    /* Enables the peripheral.*/
#if SAM_SIO_USE_SERCOM0 == TRUE
    if (&SIOD1 == siop)
    {
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 1);
      usart_reset(&SIOD1);
      nvicEnableVector(SERCOM0_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
    if (&SIOD2 == siop)
    {
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 1);
      usart_reset(&SIOD2);
      nvicEnableVector(SERCOM1_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
    if (&SIOD3 == siop)
    {
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 1);
      usart_reset(&SIOD3);
      nvicEnableVector(SERCOM2_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
    if (&SIOD4 == siop)
    {
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 1);
      usart_reset(&SIOD4);
      nvicEnableVector(SERCOM3_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
    if (&SIOD5 == siop)
    {
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 1);
      usart_reset(&SIOD5);
      nvicEnableVector(SERCOM4_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
    if (&SIOD6 == siop)
    {
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 1);
      usart_reset(&SIOD6);
      nvicEnableVector(SERCOM5_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
    }
#endif
  }
  /* Configures the peripheral.*/
  usart_init(siop);
  return HAL_RET_SUCCESS;
}

/**
 * @brief   Deactivates the SIO peripheral.
 *
 * @param[in] siop      pointer to the @p SIODriver object
 *
 * @notapi
 */
void sio_lld_stop(SIODriver *siop)
{

  if (siop->state == SIO_READY)
  {
    /* Resets the peripheral.*/
    siop->usart->SERCOM_INTENCLR = SERCOM_USART_INT_INTENCLR_Msk;
    // disable sercom
    siop->usart->SERCOM_CTRLA &= ~SERCOM_USART_INT_CTRLA_ENABLE_Msk;
    while ((siop->usart->SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_ENABLE_Msk) != 0U)
      ;
      /* Disables the peripheral.*/
#if SAM_SIO_USE_SERCOM0 == TRUE
    if (&SIOD1 == siop)
    {
      usart_reset(&SIOD1);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 0);
      nvicDisableVector(SERCOM0_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
    if (&SIOD2 == siop)
    {
      usart_reset(&SIOD2);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 0);
      nvicDisableVector(SERCOM1_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
    if (&SIOD3 == siop)
    {
      usart_reset(&SIOD3);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 0);
      nvicDisableVector(SERCOM2_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
    if (&SIOD4 == siop)
    {
      usart_reset(&SIOD4);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 0);
      nvicDisableVector(SERCOM3_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
    if (&SIOD5 == siop)
    {
      usart_reset(&SIOD5);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 0);
      nvicDisableVector(SERCOM4_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
    if (&SIOD6 == siop)
    {
      usart_reset(&SIOD6);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 0);
      nvicDisableVector(SERCOM5_IRQn);
    }
#endif
  }
}
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

/**
 * @brief   SIO7 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM6 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD6;
#endif

/**
 * @brief   SIO8 driver identifier.
 */
#if (SAM_SIO_USE_SERCOM7 == TRUE) || defined(__DOXYGEN__)
SIODriver SIOD8;
#endif

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SAM_SIO_USE_SERCOM0 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_0_0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD1);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_0_1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD1);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_0_2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD1);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_0_3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_1_0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD2);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_1_1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD2);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_1_2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD2);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_1_3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_2_0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD3);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_2_1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD3);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_2_2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD3);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_2_3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD3);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_3_0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD4);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_3_1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD4);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_3_2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD4);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_3_3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD4);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_4_0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD5);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_4_1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD5);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_4_2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD5);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_4_3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD5);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_5_0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD6);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_5_1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD6);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_5_2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD6);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_5_3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD6);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM6 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_6_0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD7);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_6_1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD7);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_6_2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD7);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_6_3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD7);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_SIO_USE_SERCOM7 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_7_0_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD8);
  OSAL_IRQ_EPILOGUE();
}

OSAL_IRQ_HANDLER(SAM_SERCOM_7_1_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD8);
  OSAL_IRQ_EPILOGUE();
}


OSAL_IRQ_HANDLER(SAM_SERCOM_7_2_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD8);
  OSAL_IRQ_EPILOGUE();
}


OSAL_IRQ_HANDLER(SAM_SERCOM_7_3_HANDLER)
{
  OSAL_IRQ_PROLOGUE();
  sio_lld_serve_interrupt(&SIOD8);
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
  MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_SERCOM0_Msk;
  SIOD1.usart = &SERCOM0_REGS->USART_INT;
  SIOD1.clock = SAM_SERCOM0_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM1 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD2);
  MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_SERCOM1_Msk;
  SIOD2.usart = &SERCOM1_REGS->USART_INT;
  SIOD2.clock = SAM_SERCOM1_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM2 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD3);
  MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_SERCOM2_Msk;
  SIOD3.usart = &SERCOM2_REGS->USART_INT;
  SIOD3.clock = SAM_SERCOM2_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM3 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD4);
  MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_SERCOM3_Msk;
  SIOD4.usart = &SERCOM3_REGS->USART_INT;
  SIOD4.clock = SAM_SERCOM3_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM4 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD5);
  MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM4_Msk;
  SIOD5.usart = &SERCOM4_REGS->USART_INT;
  SIOD5.clock = SAM_SERCOM4_GCLK_FREQ;
#endif
#if SAM_SIO_USE_SERCOM5 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD6);
  MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM5_Msk;
  SIOD6.usart = &SERCOM5_REGS->USART_INT;
  SIOD6.clock = SAM_SERCOM5_GCLK_FREQ;
#endif

#if SAM_SIO_USE_SERCOM6 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD7);
  MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM6_Msk;
  SIOD7.usart = &SERCOM6_REGS->USART_INT;
  SIOD7.clock = SAM_SERCOM6_GCLK_FREQ;
#endif

#if SAM_SIO_USE_SERCOM7 == TRUE
  /* Driver initialization.*/
  sioObjectInit(&SIOD8);
  MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM7_Msk;
  SIOD8.usart = &SERCOM7_REGS->USART_INT;
  SIOD8.clock = SAM_SERCOM7_GCLK_FREQ;
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
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM0_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM0_CORE_Val, 1);
      usart_reset(&SIOD1);
      nvicEnableVector(SERCOM0_0_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
      nvicEnableVector(SERCOM0_1_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
      nvicEnableVector(SERCOM0_2_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
      nvicEnableVector(SERCOM0_OTHER_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
    if (&SIOD2 == siop)
    {
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM1_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM1_CORE_Val, 1);
      usart_reset(&SIOD2);
      nvicEnableVector(SERCOM1_0_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
      nvicEnableVector(SERCOM1_1_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
      nvicEnableVector(SERCOM1_2_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
      nvicEnableVector(SERCOM1_OTHER_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
    if (&SIOD3 == siop)
    {
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM2_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM2_CORE_Val, 1);
      usart_reset(&SIOD3);
      nvicEnableVector(SERCOM2_0_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
      nvicEnableVector(SERCOM2_1_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
      nvicEnableVector(SERCOM2_2_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
      nvicEnableVector(SERCOM2_OTHER_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
    if (&SIOD4 == siop)
    {
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM3_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM3_CORE_Val, 1);
      usart_reset(&SIOD4);
      nvicEnableVector(SERCOM3_0_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
      nvicEnableVector(SERCOM3_1_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
      nvicEnableVector(SERCOM3_2_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
      nvicEnableVector(SERCOM3_OTHER_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
    if (&SIOD5 == siop)
    {
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM4_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM4_CORE_Val, 1);
      usart_reset(&SIOD5);
      nvicEnableVector(SERCOM4_0_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
      nvicEnableVector(SERCOM4_1_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
      nvicEnableVector(SERCOM4_2_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
      nvicEnableVector(SERCOM4_OTHER_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
    if (&SIOD6 == siop)
    {
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM5_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM5_CORE_Val, 1);
      usart_reset(&SIOD6);
      nvicEnableVector(SERCOM5_0_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
      nvicEnableVector(SERCOM5_1_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
      nvicEnableVector(SERCOM5_2_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
      nvicEnableVector(SERCOM5_OTHER_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM6 == TRUE
    if (&SIOD7 == siop)
    {
      sam_gclk_mux(SAM_SERCOM6_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM6_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM6_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM6_CORE_Val, 1);
      usart_reset(&SIOD7);
      nvicEnableVector(SERCOM6_0_IRQn, SAM_SERCOM6_IRQ_PRIORITY);
      nvicEnableVector(SERCOM6_1_IRQn, SAM_SERCOM6_IRQ_PRIORITY);
      nvicEnableVector(SERCOM6_2_IRQn, SAM_SERCOM6_IRQ_PRIORITY);
      nvicEnableVector(SERCOM6_OTHER_IRQn, SAM_SERCOM6_IRQ_PRIORITY);
    }
#endif

#if SAM_SIO_USE_SERCOM7 == TRUE
    if (&SIOD8 == siop)
    {
      sam_gclk_mux(SAM_SERCOM7_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM7_CORE_Val, 0);
      sam_gclk_mux(SAM_SERCOM7_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM7_CORE_Val, 1);
      usart_reset(&SIOD8);
      nvicEnableVector(SERCOM7_0_IRQn, SAM_SERCOM7_IRQ_PRIORITY);
      nvicEnableVector(SERCOM7_1_IRQn, SAM_SERCOM7_IRQ_PRIORITY);
      nvicEnableVector(SERCOM7_2_IRQn, SAM_SERCOM7_IRQ_PRIORITY);
      nvicEnableVector(SERCOM7_OTHER_IRQn, SAM_SERCOM7_IRQ_PRIORITY);
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
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM0_CORE_Val, 0);
      nvicDisableVector(SERCOM0_0_IRQn);
      nvicDisableVector(SERCOM0_1_IRQn);
      nvicDisableVector(SERCOM0_2_IRQn);
      nvicDisableVector(SERCOM0_OTHER_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM1 == TRUE
    if (&SIOD2 == siop)
    {
      usart_reset(&SIOD2);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM1_CORE_Val, 0);
      nvicDisableVector(SERCOM1_0_IRQn);
      nvicDisableVector(SERCOM1_1_IRQn);
      nvicDisableVector(SERCOM1_2_IRQn);
      nvicDisableVector(SERCOM1_OTHER_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM2 == TRUE
    if (&SIOD3 == siop)
    {
      usart_reset(&SIOD3);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM2_CORE_Val, 0);
      nvicDisableVector(SERCOM2_0_IRQn);
      nvicDisableVector(SERCOM2_1_IRQn);
      nvicDisableVector(SERCOM2_2_IRQn);
      nvicDisableVector(SERCOM2_OTHER_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM3 == TRUE
    if (&SIOD4 == siop)
    {
      usart_reset(&SIOD4);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM3_CORE_Val, 0);
      nvicDisableVector(SERCOM3_0_IRQn);
      nvicDisableVector(SERCOM3_1_IRQn);
      nvicDisableVector(SERCOM3_2_IRQn);
      nvicDisableVector(SERCOM3_OTHER_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM4 == TRUE
    if (&SIOD5 == siop)
    {
      usart_reset(&SIOD5);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM4_CORE_Val, 0);
      nvicDisableVector(SERCOM4_0_IRQn);
      nvicDisableVector(SERCOM4_1_IRQn);
      nvicDisableVector(SERCOM4_2_IRQn);
      nvicDisableVector(SERCOM4_OTHER_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM5 == TRUE
    if (&SIOD6 == siop)
    {
      usart_reset(&SIOD6);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM5_CORE_Val, 0);
      nvicDisableVector(SERCOM5_0_IRQn);
      nvicDisableVector(SERCOM5_1_IRQn);
      nvicDisableVector(SERCOM5_2_IRQn);
      nvicDisableVector(SERCOM5_OTHER_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM6 == TRUE
    if (&SIOD7 == siop)
    {
      usart_reset(&SIOD6);
      sam_gclk_mux(SAM_SERCOM6_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM6_CORE_Val, 0);
      nvicDisableVector(SERCOM6_0_IRQn);
      nvicDisableVector(SERCOM6_1_IRQn);
      nvicDisableVector(SERCOM6_2_IRQn);
      nvicDisableVector(SERCOM6_OTHER_IRQn);
    }
#endif

#if SAM_SIO_USE_SERCOM7 == TRUE
    if (&SIOD8 == siop)
    {
      usart_reset(&SIOD8);
      sam_gclk_mux(SAM_SERCOM7_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM7_CORE_Val, 0);
      nvicDisableVector(SERCOM7_0_IRQn);
      nvicDisableVector(SERCOM7_1_IRQn);
      nvicDisableVector(SERCOM7_2_IRQn);
      nvicDisableVector(SERCOM7_OTHER_IRQn);
    }
#endif
  }
}
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
 * @brief   I2C1 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM0 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD1;
#endif

/**
 * @brief   I2C2 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM1 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD2;
#endif

/**
 * @brief   I2C3 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM2 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD3;
#endif

/**
 * @brief   I2C4 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM3 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD4;
#endif

/**
 * @brief   I2C5 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM4 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD5;
#endif

/**
 * @brief   I2C6 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM5 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD6;
#endif

/**
 * @brief   I2C6 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM6 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD7;
#endif

/**
 * @brief   I2C6 driver identifier.
 */
#if (SAM_I2C_USE_SERCOM7 == TRUE) || defined(__DOXYGEN__)
I2CDriver I2CD8;
#endif


#if SAM_I2C_USE_SERCOM0 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_0_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD1);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_0_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD1);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_0_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD1);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_0_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM1 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_1_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD2);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_1_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD2);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_1_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD2);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_1_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM2 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_2_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD3);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_2_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD3);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_2_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD3);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_2_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD3);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM3 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_3_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD4);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_3_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD4);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_3_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD4);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_3_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD4);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM4 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_4_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD5);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_4_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD5);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_4_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD5);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_4_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD5);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM5 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_5_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD6);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_5_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD6);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_5_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD6);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_5_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD6);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM6 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_6_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD7);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_6_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD7);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_6_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD7);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_6_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD7);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM7 == TRUE
OSAL_IRQ_HANDLER(SAM_SERCOM_7_0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD8);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_7_1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD8);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_7_2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD8);
  OSAL_IRQ_EPILOGUE();
}
OSAL_IRQ_HANDLER(SAM_SERCOM_7_3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD8);
  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level I2C driver initialization.
 * @todo
 * @notapi
 */
void i2c_lld_init(void) {

#if SAM_I2C_USE_SERCOM0 == TRUE
  i2cObjectInit(&I2CD1);
  MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_SERCOM0_Msk;
  I2CD1.i2c = &SERCOM0_REGS->I2CM;
  I2CD1.clock = SAM_SERCOM0_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM1 == TRUE
  i2cObjectInit(&I2CD2);
  MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_SERCOM1_Msk;
  I2CD2.i2c = &SERCOM1_REGS->I2CM;
  I2CD2.clock = SAM_SERCOM1_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM2 == TRUE
  i2cObjectInit(&I2CD3);
  MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_SERCOM2_Msk;
  I2CD3.i2c = &SERCOM2_REGS->I2CM;
  I2CD3.clock = SAM_SERCOM2_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM3 == TRUE
  i2cObjectInit(&I2CD4);
  MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_SERCOM3_Msk;
  I2CD4.i2c = &SERCOM3_REGS->I2CM;
  I2CD4.clock = SAM_SERCOM3_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM4 == TRUE
  i2cObjectInit(&I2CD5);
  MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM4_Msk;
  I2CD5.i2c = &SERCOM4_REGS->I2CM;
  I2CD5.clock = SAM_SERCOM4_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM5 == TRUE
  i2cObjectInit(&I2CD6);
  MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM5_Msk;
  I2CD6.i2c = &SERCOM5_REGS->I2CM;
  I2CD6.clock = SAM_SERCOM5_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM6 == TRUE
  i2cObjectInit(&I2CD7);
  MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM6_Msk;
  I2CD7.i2c = &SERCOM6_REGS->I2CM;
  I2CD7.clock = SAM_SERCOM6_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM7 == TRUE
  i2cObjectInit(&I2CD8);
  MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM7_Msk;
  I2CD8.i2c = &SERCOM7_REGS->I2CM;
  I2CD8.clock = SAM_SERCOM7_GCLK_FREQ;
#endif
}

/**
 * @brief   Configures and activates the I2C peripheral.
 * @todo
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_start(I2CDriver* i2cp) {

  if (i2cp->state == I2C_STOP) {
    sercom_i2cm_registers_t* dp = i2cp->i2c;
    /* Enables the peripheral.*/
#if SAM_I2C_USE_SERCOM0 == TRUE
    if (&I2CD1 == i2cp) {
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM0_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM0_CORE_Val,
                   1);
      nvicEnableVector(SERCOM0_0_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
      nvicEnableVector(SERCOM0_1_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
      nvicEnableVector(SERCOM0_2_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
      nvicEnableVector(SERCOM0_OTHER_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM1 == TRUE
    if (&I2CD2 == i2cp) {
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM1_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM1_CORE_Val,
                   1);
      nvicEnableVector(SERCOM1_0_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
      nvicEnableVector(SERCOM1_1_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
      nvicEnableVector(SERCOM1_2_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
      nvicEnableVector(SERCOM1_OTHER_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM2 == TRUE
    if (&I2CD3 == i2cp) {
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM2_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM2_CORE_Val,
                   1);
      nvicEnableVector(SERCOM2_0_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
      nvicEnableVector(SERCOM2_1_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
      nvicEnableVector(SERCOM2_2_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
      nvicEnableVector(SERCOM2_OTHER_IRQn, SAM_SERCOM2_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM3 == TRUE
    if (&I2CD4 == i2cp) {
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM3_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM3_CORE_Val,
                   1);
      nvicEnableVector(SERCOM3_0_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
      nvicEnableVector(SERCOM3_1_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
      nvicEnableVector(SERCOM3_2_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
      nvicEnableVector(SERCOM3_OTHER_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM4 == TRUE
    if (&I2CD5 == i2cp) {
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM4_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM4_CORE_Val,
                   1);
      nvicEnableVector(SERCOM4_0_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
      nvicEnableVector(SERCOM4_1_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
      nvicEnableVector(SERCOM4_2_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
      nvicEnableVector(SERCOM4_OTHER_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM5 == TRUE
    if (&I2CD6 == i2cp) {
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM5_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM5_CORE_Val,
                   1);
      nvicEnableVector(SERCOM5_0_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
      nvicEnableVector(SERCOM5_1_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
      nvicEnableVector(SERCOM5_2_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
      nvicEnableVector(SERCOM5_OTHER_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM6 == TRUE
    if (&I2CD7 == i2cp) {
      sam_gclk_mux(SAM_SERCOM6_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM6_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM6_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM6_CORE_Val,
                   1);
      nvicEnableVector(SERCOM6_0_IRQn, SAM_SERCOM6_IRQ_PRIORITY);
      nvicEnableVector(SERCOM6_1_IRQn, SAM_SERCOM6_IRQ_PRIORITY);
      nvicEnableVector(SERCOM6_2_IRQn, SAM_SERCOM6_IRQ_PRIORITY);
      nvicEnableVector(SERCOM6_OTHER_IRQn, SAM_SERCOM6_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM7 == TRUE
    if (&I2CD8 == i2cp) {
      sam_gclk_mux(SAM_SERCOM7_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM7_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM7_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM7_CORE_Val,
                   1);
      nvicEnableVector(SERCOM7_0_IRQn, SAM_SERCOM7_IRQ_PRIORITY);
      nvicEnableVector(SERCOM7_1_IRQn, SAM_SERCOM7_IRQ_PRIORITY);
      nvicEnableVector(SERCOM7_2_IRQn, SAM_SERCOM7_IRQ_PRIORITY);
      nvicEnableVector(SERCOM7_OTHER_IRQn, SAM_SERCOM7_IRQ_PRIORITY);
    }
#endif

    // Resetting sercom module
    i2cp->i2c->SERCOM_CTRLA = SERCOM_I2CM_CTRLA_SWRST_Msk;

    /* Wait for synchronization */
    sam_i2c_busy_wait(i2cp);

    /* Enable smart mode */
    dp->SERCOM_CTRLB = SERCOM_I2CM_CTRLB_SMEN_Msk;
    uint32_t baud_val = 0;
    sam_i2c_cal_baud(i2cp->clock, i2cp->config->i2cSpeed, &baud_val);
    // osalDbgAssert(
    //     sam_i2c_cal_baud(i2cp->clock, i2cp->config->i2cSpeed, &baud_val),
    //     "unable to calculate baud");
    dp->SERCOM_BAUD = baud_val;
    dp->SERCOM_CTRLA = SERCOM_I2CM_CTRLA_MODE_I2C_MASTER |
                       (i2cp->config->ctrla & ~SERCOM_I2C_CTRLA_FORBIDDEN) |
                       SERCOM_I2CM_CTRLA_ENABLE_Msk;
    sam_i2c_busy_wait(i2cp);
    i2cp->i2c->SERCOM_STATUS = (uint16_t)SERCOM_I2CM_STATUS_BUSSTATE(0x01UL);
    sam_i2c_busy_wait(i2cp);
  }
}

/**
 * @brief   Deactivates the I2C peripheral.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 *
 * @notapi
 */
void i2c_lld_stop(I2CDriver* i2cp) {
  if (i2cp->state != I2C_STOP) {
    i2c_lld_abort_operation(i2cp);
    /* Disables the peripheral.*/

#if SAM_I2C_USE_SERCOM0 == TRUE
    if (&I2CD1 == i2cp) {
        sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM0_CORE_Val, 0);
        nvicDisableVector(SERCOM0_0_IRQn);
        nvicDisableVector(SERCOM0_1_IRQn);
        nvicDisableVector(SERCOM0_2_IRQn);
        nvicDisableVector(SERCOM0_OTHER_IRQn);
    }
#endif

#if SAM_I2C_USE_SERCOM1 == TRUE
    if (&I2CD2 == i2cp) {
    sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM1_CORE_Val, 0);
    nvicDisableVector(SERCOM1_0_IRQn);
    nvicDisableVector(SERCOM1_1_IRQn);
    nvicDisableVector(SERCOM1_2_IRQn);
    nvicDisableVector(SERCOM1_OTHER_IRQn);
    }
#endif

#if SAM_I2C_USE_SERCOM2 == TRUE
    if (&I2CD3 == i2cp) {
        sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM2_CORE_Val, 0);
    nvicDisableVector(SERCOM2_0_IRQn);
    nvicDisableVector(SERCOM2_1_IRQn);
    nvicDisableVector(SERCOM2_2_IRQn);
    nvicDisableVector(SERCOM2_OTHER_IRQn);
    }
#endif

#if SAM_I2C_USE_SERCOM3 == TRUE
    if (&I2CD4 == i2cp) {
        sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM3_CORE_Val, 0);
    nvicDisableVector(SERCOM3_0_IRQn);
    nvicDisableVector(SERCOM3_1_IRQn);
    nvicDisableVector(SERCOM3_2_IRQn);
    nvicDisableVector(SERCOM3_OTHER_IRQn);
    }
#endif

#if SAM_I2C_USE_SERCOM4 == TRUE
    if (&I2CD5 == i2cp) {
        sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM4_CORE_Val, 0);
    nvicDisableVector(SERCOM4_0_IRQn);
    nvicDisableVector(SERCOM4_1_IRQn);
    nvicDisableVector(SERCOM4_2_IRQn);
    nvicDisableVector(SERCOM4_OTHER_IRQn);
    }
#endif

#if SAM_I2C_USE_SERCOM5 == TRUE
    if (&I2CD6 == i2cp) {
        sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM5_CORE_Val, 0);
    nvicDisableVector(SERCOM5_0_IRQn);
    nvicDisableVector(SERCOM5_1_IRQn);
    nvicDisableVector(SERCOM5_2_IRQn);
    nvicDisableVector(SERCOM5_OTHER_IRQn);
    }
#endif
  
#if SAM_I2C_USE_SERCOM6 == TRUE
    if (&I2CD7 == i2cp) {
        sam_gclk_mux(SAM_SERCOM6_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM6_CORE_Val, 0);
    nvicDisableVector(SERCOM6_0_IRQn);
    nvicDisableVector(SERCOM6_1_IRQn);
    nvicDisableVector(SERCOM6_2_IRQn);
    nvicDisableVector(SERCOM6_OTHER_IRQn);
    }
#endif

#if SAM_I2C_USE_SERCOM7 == TRUE
    if (&I2CD8 == i2cp) {
        sam_gclk_mux(SAM_SERCOM7_GCLK_SRC_ID, GCLK_PCHCTRL_ID_SERCOM7_CORE_Val, 0);
    nvicDisableVector(SERCOM7_0_IRQn);
    nvicDisableVector(SERCOM7_1_IRQn);
    nvicDisableVector(SERCOM7_2_IRQn);
    nvicDisableVector(SERCOM7_OTHER_IRQn);
    }
#endif

  }
}
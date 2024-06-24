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

#if SAM_I2C_USE_SERCOM0 == TRUE
OSAL_IRQ_HANDLER(SERCOM0_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD1);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM1 == TRUE
OSAL_IRQ_HANDLER(SERCOM1_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD2);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM2 == TRUE
OSAL_IRQ_HANDLER(SERCOM2_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD3);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM3 == TRUE
OSAL_IRQ_HANDLER(SERCOM3_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD4);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM4 == TRUE
OSAL_IRQ_HANDLER(SERCOM4_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD5);
  OSAL_IRQ_EPILOGUE();
}
#endif

#if SAM_I2C_USE_SERCOM5 == TRUE
OSAL_IRQ_HANDLER(SERCOM5_HANDLER) {
  OSAL_IRQ_PROLOGUE();
  i2c_lld_serve_interrupt(&I2CD6);
  OSAL_IRQ_EPILOGUE();
}
#endif



/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level I2C driver initialization.
 *
 * @notapi
 */
void i2c_lld_init(void) {

#if SAM_I2C_USE_SERCOM0 == TRUE
  i2cObjectInit(&I2CD1);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM0_Msk;
  I2CD1.i2c = &SERCOM0_REGS->I2CM;
  I2CD1.clock = SAM_SERCOM0_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM1 == TRUE
  i2cObjectInit(&I2CD2);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM1_Msk;
  I2CD2.i2c = &SERCOM1_REGS->I2CM;
  I2CD2.clock = SAM_SERCOM1_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM2 == TRUE
  i2cObjectInit(&I2CD3);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM2_Msk;
  I2CD3.i2c = &SERCOM2_REGS->I2CM;
  I2CD3.clock = SAM_SERCOM2_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM3 == TRUE
  i2cObjectInit(&I2CD4);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM3_Msk;
  I2CD4.i2c = &SERCOM3_REGS->I2CM;
  I2CD4.clock = SAM_SERCOM3_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM4 == TRUE
  i2cObjectInit(&I2CD5);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM4_Msk;
  I2CD5.i2c = &SERCOM4_REGS->I2CM;
  I2CD5.clock = SAM_SERCOM4_GCLK_FREQ;
#endif
#if SAM_I2C_USE_SERCOM5 == TRUE
  i2cObjectInit(&I2CD6);
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM5_Msk;
  I2CD6.i2c = &SERCOM5_REGS->I2CM;
  I2CD6.clock = SAM_SERCOM5_GCLK_FREQ;
#endif
}

/**
 * @brief   Configures and activates the I2C peripheral.
 *
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
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val,
                   1);
      nvicEnableVector(SERCOM0_IRQn, SAM_SERCOM0_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM1 == TRUE
    if (&I2CD2 == i2cp) {
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val,
                   1);
      nvicEnableVector(SERCOM1_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM2 == TRUE
    if (&I2CD3 == i2cp) {
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val,
                   1);
      nvicEnableVector(SERCOM2_IRQn, SAM_SERCOM1_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM3 == TRUE
    if (&I2CD4 == i2cp) {
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val,
                   1);
      nvicEnableVector(SERCOM3_IRQn, SAM_SERCOM3_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM4 == TRUE
    if (&I2CD5 == i2cp) {
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val,
                   1);
      nvicEnableVector(SERCOM4_IRQn, SAM_SERCOM4_IRQ_PRIORITY);
    }
#endif

#if SAM_I2C_USE_SERCOM5 == TRUE
    if (&I2CD6 == i2cp) {
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val,
                   0);
      sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val,
                   1);
      nvicEnableVector(SERCOM5_IRQn, SAM_SERCOM5_IRQ_PRIORITY);
    }
#endif
    // Resetting sercom module
    i2cp->i2c->SERCOM_CTRLA = SERCOM_I2CM_CTRLA_SWRST_Msk;

    /* Wait for synchronization */
    sam_i2c_busy_wait(i2cp);

    /* Enable smart mode */
    dp->SERCOM_CTRLB = SERCOM_I2CM_CTRLB_SMEN_Msk;
    uint32_t baud_val = 0;
    osalDbgAssert(
        sam_i2c_cal_baud(i2cp->clock, i2cp->config->i2cSpeed, &baud_val),
        "unable to calculate baud");
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
    sam_gclk_mux(SAM_SERCOM0_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM0_CORE_Val, 0);
      nvicDisableVector(SERCOM0_IRQn);
    }
#endif
#if SAM_I2C_USE_SERCOM1 == TRUE
    if (&I2CD2 == i2cp) {
    sam_gclk_mux(SAM_SERCOM1_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM1_CORE_Val, 0);
      nvicDisableVector(SERCOM1_IRQn);
    }
#endif
#if SAM_I2C_USE_SERCOM2 == TRUE
    if (&I2CD3 == i2cp) {
    sam_gclk_mux(SAM_SERCOM2_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM2_CORE_Val, 0);
      nvicDisableVector(SERCOM2_IRQn);
    }
#endif
#if SAM_I2C_USE_SERCOM3 == TRUE
    if (&I2CD4 == i2cp) {
    sam_gclk_mux(SAM_SERCOM3_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM3_CORE_Val, 0);
      nvicDisableVector(SERCOM3_IRQn);
    }
#endif
#if SAM_I2C_USE_SERCOM4 == TRUE
    if (&I2CD5 == i2cp) {
    sam_gclk_mux(SAM_SERCOM4_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM4_CORE_Val, 0);
      nvicDisableVector(SERCOM4_IRQn);
    }
#endif
#if SAM_I2C_USE_SERCOM5 == TRUE
    if (&I2CD6 == i2cp) {
    sam_gclk_mux(SAM_SERCOM5_GCLK_SRC_ID, GCLK_CLKCTRL_ID_SERCOM5_CORE_Val, 0);
      nvicDisableVector(SERCOM5_IRQn);
    }
#endif
  }
}
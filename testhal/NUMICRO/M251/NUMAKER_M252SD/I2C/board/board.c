/*
    Copyright (C) 2026 Belonit

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
 * @file    board.c
 * @brief   I2C test-specific NuMaker-M252SD board support.
 *
 * @addtogroup I2C_TEST_BOARD
 * @{
 */

#include "hal.h"
#include "M251/stddriver/sys.h"

typedef struct {
  I2CDriver *i2cp;
  ioportid_t port;
  uint32_t sda;
  uint32_t scl;
  void (*configure_pins)(void);
} i2c_bus_t;

static void gpio_i2c_delay(void) {
  for (volatile uint32_t i = 0U; i < 300U; i++) {
    __NOP();
  }
}

static bool gpio_i2c_wait_high(const i2c_bus_t *bus, uint32_t pad) {
  for (uint32_t i = 0U; i < 1000U; i++) {
    if (palReadPad(bus->port, pad) == PAL_HIGH) {
      return true;
    }
    gpio_i2c_delay();
  }

  return false;
}

static bool gpio_i2c_recover_bus(const i2c_bus_t *bus) {
  palSetPad(bus->port, bus->sda);
  palSetPad(bus->port, bus->scl);
  osalSysLock();
  palSetPadMode(bus->port, bus->sda, PAL_MODE_OUTPUT_OPENDRAIN);
  palSetPadMode(bus->port, bus->scl, PAL_MODE_OUTPUT_OPENDRAIN);
  osalSysUnlock();
  gpio_i2c_delay();

  if (!gpio_i2c_wait_high(bus, bus->scl)) {
    return false;
  }

  for (uint32_t pulse = 0U;
       (pulse < 9U) && (palReadPad(bus->port, bus->sda) == PAL_LOW); pulse++) {
    palClearPad(bus->port, bus->scl);
    gpio_i2c_delay();
    palSetPad(bus->port, bus->scl);
    if (!gpio_i2c_wait_high(bus, bus->scl)) {
      return false;
    }
    gpio_i2c_delay();
  }

  palClearPad(bus->port, bus->scl);
  gpio_i2c_delay();
  palClearPad(bus->port, bus->sda);
  gpio_i2c_delay();
  palSetPad(bus->port, bus->scl);
  if (!gpio_i2c_wait_high(bus, bus->scl)) {
    palSetPad(bus->port, bus->sda);
    return false;
  }
  gpio_i2c_delay();
  palSetPad(bus->port, bus->sda);
  gpio_i2c_delay();

  return (palReadPad(bus->port, bus->sda) == PAL_HIGH)
         && (palReadPad(bus->port, bus->scl) == PAL_HIGH);
}

static void configure_i2c0_pins(void) {
  osalSysLock();
  SYS->GPB_MFPL =
      (SYS->GPB_MFPL & ~(SYS_GPB_MFPL_PB4MFP_Msk | SYS_GPB_MFPL_PB5MFP_Msk))
      | SYS_GPB_MFPL_PB4MFP_I2C0_SDA | SYS_GPB_MFPL_PB5MFP_I2C0_SCL;
  palSetPadMode(PB, 4U, PAL_MODE_INPUT | PAL_M251_MFP_PRESERVE);
  palSetPadMode(PB, 5U, PAL_MODE_INPUT | PAL_M251_MFP_PRESERVE);
  PB->SMTEN |= GPIO_SMTEN_SMTEN4_Msk | GPIO_SMTEN_SMTEN5_Msk;
  osalSysUnlock();
}

static void configure_i2c1_pins(void) {
  osalSysLock();
  SYS->GPB_MFPL =
      (SYS->GPB_MFPL & ~(SYS_GPB_MFPL_PB0MFP_Msk | SYS_GPB_MFPL_PB1MFP_Msk))
      | SYS_GPB_MFPL_PB0MFP_I2C1_SDA | SYS_GPB_MFPL_PB1MFP_I2C1_SCL;
  palSetPadMode(PB, 0U, PAL_MODE_INPUT | PAL_M251_MFP_PRESERVE);
  palSetPadMode(PB, 1U, PAL_MODE_INPUT | PAL_M251_MFP_PRESERVE);
  PB->SMTEN |= GPIO_SMTEN_SMTEN0_Msk | GPIO_SMTEN_SMTEN1_Msk;
  osalSysUnlock();
}

static const i2c_bus_t i2c_buses[] = {
    {&I2CD0, PB, 4U, 5U, configure_i2c0_pins},
    {&I2CD1, PB, 0U, 1U, configure_i2c1_pins},
};

/**
 * @brief   Board-specific initialization code.
 *
 * @init
 */
void boardInit(void) {
  palSetPad(PB, 14U);
  palSetLineMode(LINE_LED, PAL_MODE_OUTPUT_PUSHPULL);
}

/**
 * @brief   Recovers an I2C bus and restores its pin routing.
 *
 * @param[in] i2cp      pointer to the @p I2CDriver object
 * @return              Recovery status.
 * @retval true         The bus was released and its pins were restored.
 * @retval false        The bus is unknown or could not be released.
 *
 * @notapi
 */
bool boardI2cRecover(I2CDriver *i2cp) {
  for (size_t i = 0U; i < sizeof(i2c_buses) / sizeof(i2c_buses[0]); i++) {
    const i2c_bus_t *bus = &i2c_buses[i];

    if (bus->i2cp == i2cp) {
      i2cStop(i2cp);
      if (!gpio_i2c_recover_bus(bus)) {
        return false;
      }
      bus->configure_pins();
      return true;
    }
  }

  return false;
}

/** @} */

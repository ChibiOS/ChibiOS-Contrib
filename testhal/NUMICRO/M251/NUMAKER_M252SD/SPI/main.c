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

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "M251/stddriver/sys.h"

#include <string.h>

#define TEST_BUFFER_SIZE                  257U
#define ARRAY_SIZE(array)                  (sizeof(array) / sizeof((array)[0]))

static uint8_t txbuf[TEST_BUFFER_SIZE];
static uint8_t rxbuf[TEST_BUFFER_SIZE];

static SPIConfig spicfg = {
  .end_cb    = NULL,
  .ssport    = PA,
  .sspad     = 3U,
  .frequency = 100000U,
  .mode      = M251_SPI_MODE_0,
};

static const size_t test_lengths[] = {1U, 7U, 8U, 9U, 64U, 257U};
static const uint32_t test_frequencies[] = {100000U, 1000000U, 2000000U};
static const uint32_t test_modes[] = {
  M251_SPI_MODE_0,
  M251_SPI_MODE_1,
  M251_SPI_MODE_2,
  M251_SPI_MODE_3,
};

static void configure_pins(void) {

  SYS->GPA_MFPL =
      (SYS->GPA_MFPL &
       ~(SYS_GPA_MFPL_PA0MFP_Msk | SYS_GPA_MFPL_PA1MFP_Msk |
         SYS_GPA_MFPL_PA2MFP_Msk | SYS_GPA_MFPL_PA3MFP_Msk)) |
      SYS_GPA_MFPL_PA0MFP_SPI0_MOSI |
      SYS_GPA_MFPL_PA1MFP_SPI0_MISO |
      SYS_GPA_MFPL_PA2MFP_SPI0_CLK |
      SYS_GPA_MFPL_PA3MFP_GPIO;

  PA->SMTEN |= GPIO_SMTEN_SMTEN1_Msk;
  palSetPadMode(PA, 3U, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPad(PA, 3U);
}

static bool test_exchange(size_t length) {

  for (size_t i = 0U; i < length; i++) {
    txbuf[i] = (uint8_t)(0x31U + i * 37U);
    rxbuf[i] = 0U;
  }

  spiSelect(&SPID0);
  spiExchange(&SPID0, length, txbuf, rxbuf);
  spiUnselect(&SPID0);

  return !spi_lld_get_overrun(&SPID0) &&
         (memcmp(txbuf, rxbuf, length) == 0);
}

static bool test_auxiliary_apis(void) {

  for (size_t i = 0U; i < 9U; i++) {
    txbuf[i] = (uint8_t)(0xA0U + i);
    rxbuf[i] = 0U;
  }

  spiSelect(&SPID0);
  spiSend(&SPID0, 9U, txbuf);
  spiReceive(&SPID0, 9U, rxbuf);
  spiIgnore(&SPID0, 9U);
  uint16_t received = spiPolledExchange(&SPID0, 0x5AU);
  spiUnselect(&SPID0);

  for (size_t i = 0U; i < 9U; i++) {
    if (rxbuf[i] != 0xFFU) {
      return false;
    }
  }

  return !spi_lld_get_overrun(&SPID0) && (received == 0x5AU);
}

static bool run_tests(BaseSequentialStream *chp) {

  for (size_t mode = 0U; mode < ARRAY_SIZE(test_modes); mode++) {
    for (size_t freq = 0U; freq < ARRAY_SIZE(test_frequencies); freq++) {
      spicfg.mode = test_modes[mode];
      spicfg.frequency = test_frequencies[freq];
      spiStart(&SPID0, &spicfg);

      chprintf(chp, "mode=%u frequency=%lu: ", (unsigned)mode,
               (unsigned long)spicfg.frequency);

      for (size_t length = 0U; length < ARRAY_SIZE(test_lengths); length++) {
        if (!test_exchange(test_lengths[length])) {
          chprintf(chp, "FAIL exchange length=%u\r\n",
                   (unsigned)test_lengths[length]);
          return false;
        }
        chprintf(chp, "%u ", (unsigned)test_lengths[length]);
      }

      if (!test_auxiliary_apis()) {
        chprintf(chp, "FAIL auxiliary API\r\n");
        return false;
      }

      chprintf(chp, "APIs PASS\r\n");
    }
  }

  return true;
}

int main(void) {
  BaseSequentialStream *chp = (BaseSequentialStream *)&SD0;

  halInit();
  chSysInit();

  sdStart(&SD0, NULL);
  configure_pins();

  chprintf(chp,
           "\r\nM252 SPI0 loopback test\r\n"
           "Jumper: D11/PA.0/MOSI to D12/PA.1/MISO\r\n");

  bool passed = run_tests(chp);
  spiStop(&SPID0);

  chprintf(chp, passed ? "SPI0 LOOPBACK PASS\r\n" :
                         "SPI0 LOOPBACK FAIL\r\n");

  while (true) {
    if (passed) {
      OnboardLED_Toggle();
    }
    else {
      OnboardLED_On();
    }
    chThdSleepMilliseconds(500);
  }
}

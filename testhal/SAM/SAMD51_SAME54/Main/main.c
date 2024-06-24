#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "hal_serial_nor.h"
#include "hal_flash.h"

#define XSPI_MOSI PAL_LINE(GPIOA, 8)
#define XSPI_MISO PAL_LINE(GPIOA, 9)
#define XSPI_WP   PAL_LINE(GPIOA, 10)
#define XSPI_HOLD PAL_LINE(GPIOA, 11)
#define XSPI_SCK  PAL_LINE(GPIOB, 10)
#define XSPI_CS   PAL_LINE(GPIOB, 11)

#define UART_TX   PAL_LINE(GPIOB, 25)
#define UART_RX   PAL_LINE(GPIOB, 24)

#define BLINKY    PAL_LINE(GPIOC, 18)

#define I2C_SDA   PAL_LINE(GPIOD, 8)
#define I2C_SCL   PAL_LINE(GPIOD, 9)

// i2c slave device on Xplained pro
#define AT24MAC402_ADDR 0x56

void pinsInit()
{
  // LED
  palSetLineMode(BLINKY, PAL_MODE_OUTPUT_PUSHPULL);
  // I2C
  palSetLineMode(I2C_SDA, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_C));
  palSetLineMode(I2C_SCL, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_C));
  // UART
  palSetLineMode(UART_TX, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_D));
  palSetLineMode(UART_RX, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_D));
  // XSPI (only testing single spi mode, therefore driving io 2/3 to high)
  palSetLineMode(XSPI_MOSI, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_H));
  palSetLineMode(XSPI_MISO, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_H));
  palSetLineMode(XSPI_WP, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLineMode(XSPI_HOLD, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLineMode(XSPI_SCK, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_H));
  // SW controlled CS for single SPI mode
  palSetLineMode(XSPI_CS, PAL_MODE_OUTPUT_PUSHPULL);
}

void sioInitTest()
{
static const SIOConfig siocfg = {
  SIO_DEFAULT_BITRATE,
  SERCOM_SIO_CTRLA_DEFAULT,
  SERCOM_SIO_CTRLB_DEFAULT,
  2,
  1
};
  sioStart(&SIOD3, &siocfg);
  static int sent_b = 0;
  sent_b = chprintf((BaseSequentialStream *)&SIOD3, "SIO test passed\r\n");
}

void i2cInitTest()
{
  static const uint8_t tx_buf[] = {0x0, 0x1};
  uint8_t rx_buf[2] = {0x0, 0x0};
  static i2cflags_t errors = 0;
  static const uint8_t dummy_tx_buf[] = {0x0};
  static const I2CConfig i2ccfg = {I2C_DEFAULT_BITRATE, SERCOM_I2C_CTRLA_DEFAULT};
  msg_t msg = 0xff;
  msg = i2cStart(&I2CD8, &i2ccfg);
  while (msg != MSG_OK) {
    osalThreadSleepMilliseconds(1);
  }
    msg = i2cMasterTransmitTimeout(&I2CD8, AT24MAC402_ADDR, tx_buf, sizeof(tx_buf), NULL, 0, 100);
    if (msg != MSG_OK) {
      errors = i2cGetErrors(&I2CD8);
      chprintf((BaseSequentialStream *)&SIOD3, "I2C test failed: %d\r\n", errors);
      osalThreadSleepMilliseconds(100);
    };
    osalThreadSleepMilliseconds(10);
    msg = i2cMasterTransmitTimeout(&I2CD8, AT24MAC402_ADDR, dummy_tx_buf, sizeof(dummy_tx_buf), rx_buf, sizeof(rx_buf), 100);
    if (tx_buf[1] != rx_buf[0]){
      chprintf((BaseSequentialStream *)&SIOD3, "I2C test failed: %d != %d\r\n", tx_buf[1], rx_buf[0]);
    }
    else {
      chprintf((BaseSequentialStream *)&SIOD3, "I2C test passed\r\n");
    }
    if (msg != MSG_OK) {
      errors = i2cGetErrors(&I2CD8);
      chprintf((BaseSequentialStream *)&SIOD3, "I2C test failed: %d\r\n", errors);
      palSetLine(BLINKY);
      osalThreadSleepMilliseconds(100);
    };
}

void xspiFlashInitTest()
{
  palWriteLine(XSPI_WP, PAL_HIGH);
  palWriteLine(XSPI_HOLD, PAL_HIGH);
  palWriteLine(XSPI_CS, PAL_HIGH);

  static SPIConfig spi_cfg;
  static SNORDriver snor_driver;
  static snor_nocache_buffer_t spi_buf;
  const static qspi_spi_config_t qspi_spi_cfg = {
      0,         // ctrlb
      20000000,  // Set frequency to 20Mhz
      0,         // DLYBS to 0, CS valid transition is 1/2 of SCK period
      0,         // CPOL: The inactive state value of SCK is logic level zero
      0  // CPHA: Data is captured on the leading edge of SCK and changed on the following edge of SCK.
  };
  spi_cfg.qspi_cfg = qspi_spi_cfg;
  spi_cfg.ssline = XSPI_CS;
  static const SNORConfig snor_driver_config = {
      .busp = &SPID9,
      .buscfg = &spi_cfg,
  };

  snorObjectInit(&snor_driver, &spi_buf);
  snorStart(&snor_driver, &snor_driver_config);

  static const uint8_t tx_data[4] = {0x11, 0x12, 0x13, 0x14};
  uint8_t rx_data[1000] = {0};
  BaseFlash* flash = getBaseFlash(&snor_driver);
  flash_error_t ererr = flashStartEraseSector(flash, 0);
  uint32_t msec = 1;
  while (flashQueryErase(flash, &msec) == FLASH_BUSY_ERASING) {
    osalThreadSleepMilliseconds(msec);
  };
  flash_error_t rderr = flashRead(flash, 0U, 1000, rx_data);
  flash_error_t wrerr = flashProgram(flash, 0U, 4, tx_data);
  rderr = flashRead(flash, 0U, 5, rx_data);
  bool passed = true;
  for (int i = 0; i < (sizeof(tx_data) / sizeof(tx_data[0])); i++) {
    if (tx_data[i] != rx_data[i]) {
      chprintf((BaseSequentialStream *)&SIOD3, "XSPI flash test failed: %d != %d\r\n", tx_data[i], rx_data[i]);
      passed = false;
      break;
    }
  }
  if (passed) {
    chprintf((BaseSequentialStream *)&SIOD3, "XSPI flash test passed\r\n");
  }
  osalThreadSleepMilliseconds(10);

}


int main(void)
{
    /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   */

  halInit();
  chSysInit();

  pinsInit();
  sioInitTest();
  osalThreadSleepMilliseconds(1);
  i2cInitTest();
  xspiFlashInitTest();

  while (true) {
    palToggleLine(BLINKY);
    osalThreadSleepMilliseconds(1000);
  }
}
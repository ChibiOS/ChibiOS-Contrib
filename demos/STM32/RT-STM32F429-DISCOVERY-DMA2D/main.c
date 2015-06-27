/*
    Copyright (C) 2013-2015 Andrea Zoppi

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
#include "test.h"

#include "chprintf.h"
#include "shell.h"
#if HAL_USE_SERIAL_USB
#include "usbcfg.h"
#endif

#include "stmdrivers/stm32f429i_discovery_sdram.h"
#include "stmdrivers/stm32f4xx_fmc.h"

#include "ili9341.h"
#include "stm32_ltdc.h"
#include "stm32_dma2d.h"

#include "res/wolf3d_vgagraph_chunk87.h"

#define IS42S16400J_SIZE             (8 * 1024 * 1024)

/*
 * Erases the whole SDRAM bank.
 */
static void sdram_bulk_erase(void) {

  volatile uint8_t *p = (volatile uint8_t *)SDRAM_BANK_ADDR;
  volatile uint8_t *end = p + IS42S16400J_SIZE;
  while (p < end)
    *p++ = 0;
}

/*
 * Red LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker1");
  while (true) {
    palClearPad(GPIOG, GPIOG_LED4_RED);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOG, GPIOG_LED4_RED);
    chThdSleepMilliseconds(500);
  }
}

/*
 * Green LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread2, 128);
static THD_FUNCTION(Thread2, arg) {

  (void)arg;
  chRegSetThreadName("blinker2");
  while (true) {
    palClearPad(GPIOG, GPIOG_LED3_GREEN);
    chThdSleepMilliseconds(250);
    palSetPad(GPIOG, GPIOG_LED3_GREEN);
    chThdSleepMilliseconds(250);
  }
}

/*===========================================================================*/
/* LTDC related.                                                             */
/*===========================================================================*/

static uint8_t frame_buffer[240 * 320 * 3] __attribute__((section(".ram7")));

static uint8_t view_buffer[240 * 320];

extern const ltdc_color_t wolf3d_palette[256];

static const ltdc_window_t ltdc_fullscreen_wincfg = {
  0,
  240 - 1,
  0,
  320 - 1,
};

static const ltdc_frame_t ltdc_view_frmcfg1 = {
  view_buffer,
  240,
  320,
  240 * sizeof(uint8_t),
  LTDC_FMT_L8,
};

static const ltdc_laycfg_t ltdc_view_laycfg1 = {
  &ltdc_view_frmcfg1,
  &ltdc_fullscreen_wincfg,
  LTDC_COLOR_FUCHSIA,
  0xFF,
  0x980088,
  wolf3d_palette,
  256,
  LTDC_BLEND_FIX1_FIX2,
  (LTDC_LEF_ENABLE | LTDC_LEF_PALETTE),
};

static const ltdc_frame_t ltdc_screen_frmcfg1 = {
  frame_buffer,
  240,
  320,
  240 * 3,
  LTDC_FMT_RGB888,
};

static const ltdc_laycfg_t ltdc_screen_laycfg1 = {
  &ltdc_screen_frmcfg1,
  &ltdc_fullscreen_wincfg,
  LTDC_COLOR_FUCHSIA,
  0xFF,
  0x980088,
  NULL,
  0,
  LTDC_BLEND_FIX1_FIX2,
  LTDC_LEF_ENABLE,
};

static const LTDCConfig ltdc_cfg = {
  /* Display specifications.*/
  240,                              /**< Screen pixel width.*/
  320,                              /**< Screen pixel height.*/
  10,                               /**< Horizontal sync pixel width.*/
  2,                                /**< Vertical sync pixel height.*/
  20,                               /**< Horizontal back porch pixel width.*/
  2,                                /**< Vertical back porch pixel height.*/
  10,                               /**< Horizontal front porch pixel width.*/
  4,                                /**< Vertical front porch pixel height.*/
  0,                                /**< Driver configuration flags.*/

  /* ISR callbacks.*/
  NULL,                             /**< Line Interrupt ISR, or @p NULL.*/
  NULL,                             /**< Register Reload ISR, or @p NULL.*/
  NULL,                             /**< FIFO Underrun ISR, or @p NULL.*/
  NULL,                             /**< Transfer Error ISR, or @p NULL.*/

  /* Color and layer settings.*/
  LTDC_COLOR_TEAL,
  &ltdc_view_laycfg1,
  NULL,
};

extern LTDCDriver LTDCD1;

const SPIConfig spi_cfg5 = {
  NULL,
  GPIOC,
  GPIOC_SPI5_LCD_CS,
  (((1 << 3) & SPI_CR1_BR) | SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_MSTR),
};

extern SPIDriver SPID5;

const ILI9341Config ili9341_cfg = {
  &SPID5,
  GPIOD,
  GPIOD_LCD_WRX
};

static void initialize_lcd(void) {

  static const uint8_t pgamma[15] = {
    0x0F, 0x29, 0x24, 0x0C, 0x0E, 0x09, 0x4E, 0x78,
    0x3C, 0x09, 0x13, 0x05, 0x17, 0x11, 0x00
  };
  static const uint8_t ngamma[15] = {
    0x00, 0x16, 0x1B, 0x04, 0x11, 0x07, 0x31, 0x33,
    0x42, 0x05, 0x0C, 0x0A, 0x28, 0x2F, 0x0F
  };

  ILI9341Driver *const lcdp = &ILI9341D1;

  /* XOR-checkerboard texture.*/
  unsigned x, y;
  for (y = 0; y < 320; ++y)
    for (x = 0; x < 240; ++x)
      view_buffer[y * 240 + x] = (uint8_t)(x ^ y);

  ili9341AcquireBus(lcdp);
  ili9341Select(lcdp);

  ili9341WriteCommand(lcdp, ILI9341_SET_FRAME_CTL_NORMAL);
  ili9341WriteByte(lcdp, 0x00);
  ili9341WriteByte(lcdp, 0x1B);

  ili9341WriteCommand(lcdp, ILI9341_SET_FUNCTION_CTL);
  ili9341WriteByte(lcdp, 0x0A);
  ili9341WriteByte(lcdp, 0xA2);

  ili9341WriteCommand(lcdp, ILI9341_SET_POWER_CTL_1);
  ili9341WriteByte(lcdp, 0x10);

  ili9341WriteCommand(lcdp, ILI9341_SET_POWER_CTL_2);
  ili9341WriteByte(lcdp, 0x10);

  ili9341WriteCommand(lcdp, ILI9341_SET_VCOM_CTL_1);
  ili9341WriteByte(lcdp, 0x45);
  ili9341WriteByte(lcdp, 0x15);

  ili9341WriteCommand(lcdp, ILI9341_SET_VCOM_CTL_2);
  ili9341WriteByte(lcdp, 0x90);

  ili9341WriteCommand(lcdp, ILI9341_SET_MEM_ACS_CTL);
  ili9341WriteByte(lcdp, 0xC8);

  ili9341WriteCommand(lcdp, ILI9341_SET_RGB_IF_SIG_CTL);
  ili9341WriteByte(lcdp, 0xC2);

  ili9341WriteCommand(lcdp, ILI9341_SET_FUNCTION_CTL);
  ili9341WriteByte(lcdp, 0x0A);
  ili9341WriteByte(lcdp, 0xA7);
  ili9341WriteByte(lcdp, 0x27);
  ili9341WriteByte(lcdp, 0x04);

  ili9341WriteCommand(lcdp, ILI9341_SET_COL_ADDR);
  ili9341WriteByte(lcdp, 0x00);
  ili9341WriteByte(lcdp, 0x00);
  ili9341WriteByte(lcdp, 0x00);
  ili9341WriteByte(lcdp, 0xEF);

  ili9341WriteCommand(lcdp, ILI9341_SET_PAGE_ADDR);
  ili9341WriteByte(lcdp, 0x00);
  ili9341WriteByte(lcdp, 0x00);
  ili9341WriteByte(lcdp, 0x01);
  ili9341WriteByte(lcdp, 0x3F);

  ili9341WriteCommand(lcdp, ILI9341_SET_IF_CTL);
  ili9341WriteByte(lcdp, 0x01);
  ili9341WriteByte(lcdp, 0x00);
  ili9341WriteByte(lcdp, 0x06);

  ili9341WriteCommand(lcdp, ILI9341_SET_GAMMA);
  ili9341WriteByte(lcdp, 0x01);

  ili9341WriteCommand(lcdp, ILI9341_SET_PGAMMA);
  ili9341WriteChunk(lcdp, pgamma, 15);

  ili9341WriteCommand(lcdp, ILI9341_SET_NGAMMA);
  ili9341WriteChunk(lcdp, ngamma, 15);

  ili9341WriteCommand(lcdp, ILI9341_CMD_SLEEP_OFF);
  chThdSleepMilliseconds(10);

  ili9341WriteCommand(lcdp, ILI9341_CMD_DISPLAY_ON);
  ili9341WriteCommand(lcdp, ILI9341_SET_MEM);
  chThdSleepMilliseconds(10);

  ili9341Unselect(lcdp);
  ili9341ReleaseBus(lcdp);
}

static const DMA2DConfig dma2d_cfg = {
  /* ISR callbacks.*/
  NULL,     /**< Configuration error, or @p NULL.*/
  NULL,     /**< Palette transfer done, or @p NULL.*/
  NULL,     /**< Palette access error, or @p NULL.*/
  NULL,     /**< Transfer watermark, or @p NULL.*/
  NULL,     /**< Transfer complete, or @p NULL.*/
  NULL      /**< Transfer error, or @p NULL.*/
};

static const dma2d_palcfg_t dma2d_palcfg = {
  wolf3d_palette,
  256,
  DMA2D_FMT_ARGB8888
};

static const dma2d_laycfg_t dma2d_bg_laycfg = {
  view_buffer,
  0,
  DMA2D_FMT_L8,
  DMA2D_COLOR_RED,
  0xFF,
  &dma2d_palcfg
};

static const dma2d_laycfg_t dma2d_fg_laycfg = {
  (void *)wolf3d_vgagraph_chunk87,
  0,
  DMA2D_FMT_L8,
  DMA2D_COLOR_LIME,
  0xFF,
  &dma2d_palcfg
};

static const dma2d_laycfg_t dma2d_frame_laycfg = {
  frame_buffer,
  0,
  DMA2D_FMT_RGB888,
  DMA2D_COLOR_BLUE,
  0xFF,
  NULL
};

static void dma2d_test(void) {

  DMA2DDriver *const dma2dp = &DMA2DD1;
  LTDCDriver *const ltdcp = &LTDCD1;

  chThdSleepSeconds(1);

  ltdcBgSetConfig(ltdcp, &ltdc_screen_laycfg1);
  ltdcReload(ltdcp, TRUE);

  dma2dAcquireBus(dma2dp);

  /* Target the frame buffer by default.*/
  dma2dBgSetConfig(dma2dp, &dma2d_frame_laycfg);
  dma2dFgSetConfig(dma2dp, &dma2d_frame_laycfg);
  dma2dOutSetConfig(dma2dp, &dma2d_frame_laycfg);

  /* Copy the background.*/
  dma2dFgSetConfig(dma2dp, &dma2d_bg_laycfg);
  dma2dJobSetMode(dma2dp, DMA2D_JOB_CONVERT);
  dma2dJobSetSize(dma2dp, 240, 320);
  dma2dJobExecute(dma2dp);

  /* Draw the splashscren picture at (8, 0).*/
  dma2dFgSetConfig(dma2dp, &dma2d_fg_laycfg);
  dma2dOutSetAddress(dma2dp, dma2dComputeAddress(
    frame_buffer, ltdc_screen_frmcfg1.pitch, DMA2D_FMT_RGB888, 8, 0
  ));
  dma2dOutSetWrapOffset(dma2dp, ltdc_screen_frmcfg1.width - 200);
  dma2dJobSetMode(dma2dp, DMA2D_JOB_CONVERT);
  dma2dJobSetSize(dma2dp, 200, 320);
  dma2dJobExecute(dma2dp);

  dma2dReleaseBus(dma2dp);
}

/*===========================================================================*/
/* Command line related.                                                     */
/*===========================================================================*/

#define     RTT2MS(ticks)   ((ticks) / (STM32_HCLK / 1000UL))

#if HAL_USE_SERIAL_USB
/* Virtual serial port over USB.*/
SerialUSBDriver SDU1;
#endif

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(2048)
#define TEST_WA_SIZE    THD_WORKING_AREA_SIZE(256)

static void cmd_mem(BaseSequentialStream *chp, int argc, char *argv[]) {
  size_t n, size;

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: mem\r\n");
    return;
  }
  n = chHeapStatus(NULL, &size);
  chprintf(chp, "core free memory : %u bytes\r\n", chCoreGetStatusX());
  chprintf(chp, "heap fragments   : %u\r\n", n);
  chprintf(chp, "heap free total  : %u bytes\r\n", size);
}

static void cmd_threads(BaseSequentialStream *chp, int argc, char *argv[]) {
  static const char *states[] = {CH_STATE_NAMES};
  thread_t *tp;

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: threads\r\n");
    return;
  }
  chprintf(chp, "    addr    stack prio refs     state time\r\n");
  tp = chRegFirstThread();
  do {
    chprintf(chp, "%08lx %08lx %4lu %4lu %9s\r\n",
            (uint32_t)tp, (uint32_t)tp->p_ctx.r13,
            (uint32_t)tp->p_prio, (uint32_t)(tp->p_refs - 1),
            states[tp->p_state]);
    tp = chRegNextThread(tp);
  } while (tp != NULL);
}

static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
  thread_t *tp;

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: test\r\n");
    return;
  }
  tp = chThdCreateFromHeap(NULL, TEST_WA_SIZE, chThdGetPriorityX(),
                           TestThread, chp);
  if (tp == NULL) {
    chprintf(chp, "out of memory\r\n");
    return;
  }
  chThdWait(tp);
}

static void cmd_reset(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: reset\r\n");
    return;
  }

  chprintf(chp, "Will reset in 200ms\r\n");
  chThdSleepMilliseconds(200);
  NVIC_SystemReset();
}

static void cmd_write(BaseSequentialStream *chp, int argc, char *argv[]) {
  uint32_t counter = 0;
  uint8_t ubWritedata_8b = 0x3C;
  uint32_t uwReadwritestatus = 0;
  time_measurement_t tm;


  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: write\r\n");
    return;
  }

  chTMObjectInit(&tm);

  chTMStartMeasurementX(&tm);

  /* Write data value to all SDRAM memory */
  for (counter = 0; counter < IS42S16400J_SIZE; counter++)
  {
    *(volatile uint8_t*) (SDRAM_BANK_ADDR + counter) = (uint8_t)(ubWritedata_8b + counter);
  }

  chTMStopMeasurementX(&tm);
  uint32_t write_ms = RTT2MS(tm.last);

  if (!uwReadwritestatus) {
    chprintf(chp, "SDRAM written in %dms.\r\n", write_ms);
  }

}

static void cmd_erase(BaseSequentialStream *chp, int argc, char *argv[]) {
  uint32_t counter = 0;
  uint32_t uwReadwritestatus = 0;
  time_measurement_t tm;


  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: erase\r\n");
    return;
  }

  chTMObjectInit(&tm);

  //XXX chTMStartMeasurement(&tm);

  /* Write data value to all SDRAM memory */
  /* Erase SDRAM memory */
  for (counter = 0; counter < IS42S16400J_SIZE; counter++)
  {
    *(volatile uint8_t*) (SDRAM_BANK_ADDR + counter) = (uint8_t)0x0;
  }

  //XXX chTMStopMeasurement(&tm);
  uint32_t write_ms = 0;//XXX RTT2MS(tm.last);

  if (!uwReadwritestatus) {
    chprintf(chp, "SDRAM erased in %dms.\r\n", write_ms);
  }

}

static void cmd_selfrefresh(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;

  FMC_SDRAMCommandTypeDef FMC_SDRAMCommandStructure;

  if (argc > 0) {
    chprintf(chp, "Usage: selfrefresh\r\n");
    return;
  }

  /* Program a self-refresh mode command */
  FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_Selfrefresh;
  FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank2;
  FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
  FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;

  /* Send the command */
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);

  /* Wait until the SDRAM controller is ready */
  while(FMC_GetFlagStatus(FMC_Bank2_SDRAM, FMC_FLAG_Busy) != RESET) {
  }

  /* Check the bank mode status */
  if(FMC_GetModeStatus(FMC_Bank2_SDRAM) != FMC_SelfRefreshMode_Status) {
    chprintf(chp, "SDRAM is not in self refresh mode, command FAILED.\r\n");
  } else {
    chprintf(chp, "SDRAM is in self refresh mode.\r\n");
  }

}

static void cmd_normal(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;

  FMC_SDRAMCommandTypeDef FMC_SDRAMCommandStructure;

  if (argc > 0) {
    chprintf(chp, "Usage: normal\r\n");
    return;
  }

  /* Program a self-refresh mode command */
  FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_normal;
  FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank2;
  FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
  FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;

  /* Send the command */
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);

  /* Wait until the SDRAM controller is ready */
  while(FMC_GetFlagStatus(FMC_Bank2_SDRAM, FMC_FLAG_Busy) != RESET) {
  }

  /* Check the bank mode status */
  if(FMC_GetModeStatus(FMC_Bank2_SDRAM) != FMC_NormalMode_Status) {
    chprintf(chp, "SDRAM is not in normal mode, command FAILED.\r\n");
  } else {
    chprintf(chp, "SDRAM is in normal mode.\r\n");
  }

}

static void cmd_check(BaseSequentialStream *chp, int argc, char *argv[]) {
  uint32_t counter = 0;
  uint8_t ubWritedata_8b = 0x3C, ubReaddata_8b = 0;
  uint32_t uwReadwritestatus = 0;
  time_measurement_t tm;


  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: check\r\n");
    return;
  }

  chTMObjectInit(&tm);

  chTMStartMeasurementX(&tm);

  /* Read back SDRAM memory and check content correctness*/
  counter = 0;
  uwReadwritestatus = 0;
  while ((counter < IS42S16400J_SIZE) && (uwReadwritestatus == 0))
  {
    ubReaddata_8b = *(volatile uint8_t*)(SDRAM_BANK_ADDR + counter);
    if ( ubReaddata_8b != (uint8_t)(ubWritedata_8b + counter))
    {
      uwReadwritestatus = 1;
      chprintf(chp, "Error at %d, expected %d but read %d.\r\n", counter, ubWritedata_8b + counter, ubReaddata_8b);
    }
    counter++;
  }

  chTMStopMeasurementX(&tm);
  uint32_t check_ms = RTT2MS(tm.last);

  //FIXME time this
  if (!uwReadwritestatus) {
    chprintf(chp, "SDRAM read and check completed successfully in %dms.\r\n", check_ms);
  }

}

static void cmd_sdram(BaseSequentialStream *chp, int argc, char *argv[]) {
  uint32_t counter = 0;
  uint8_t ubWritedata_8b = 0x3C, ubReaddata_8b = 0;
  uint32_t uwReadwritestatus = 0;
  time_measurement_t tm;


  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: sdram\r\n");
    return;
  }

  chTMObjectInit(&tm);

  chTMStartMeasurementX(&tm);

//  /* Erase SDRAM memory */
//  for (counter = 0; counter < IS42S16400J_SIZE; counter++)
//  {
//    *(volatile uint8_t*) (SDRAM_BANK_ADDR + counter) = (uint8_t)0x0;
//  }

  /* Write data value to all SDRAM memory */
  for (counter = 0; counter < IS42S16400J_SIZE; counter++)
  {
    *(volatile uint8_t*) (SDRAM_BANK_ADDR + counter) = (uint8_t)(ubWritedata_8b + counter);
  }

  chTMStopMeasurementX(&tm);
  uint32_t write_ms = RTT2MS(tm.last);

  chTMStartMeasurementX(&tm);

  /* Read back SDRAM memory */
  counter = 0;
  while ((counter < IS42S16400J_SIZE))
  {
    ubReaddata_8b = *(volatile uint8_t*)(SDRAM_BANK_ADDR + counter);
    counter++;
  }

  chTMStopMeasurementX(&tm);
  uint32_t read_ms = RTT2MS(tm.last);

  /* Read back SDRAM memory and check content correctness*/
  counter = 0;
  uwReadwritestatus = 0;
  while ((counter < IS42S16400J_SIZE) && (uwReadwritestatus == 0))
  {
    ubReaddata_8b = *(volatile uint8_t*)(SDRAM_BANK_ADDR + counter);
    if ( ubReaddata_8b != (uint8_t)(ubWritedata_8b + counter))
    {
      uwReadwritestatus = 1;
      chprintf(chp, "Error at %d, expected %d but read %d.\r\n", counter, ubWritedata_8b + counter, ubReaddata_8b);
    }
    counter++;
  }

  if (!uwReadwritestatus) {
    chprintf(chp, "SDRAM test completed successfully, writing entire memory took %dms, reading it took %dms.\r\n", write_ms, read_ms);
  }

}

static const ShellCommand commands[] = {
  {"mem", cmd_mem},
  {"threads", cmd_threads},
  {"test", cmd_test},
  {"sdram", cmd_sdram},
  {"reset", cmd_reset},
  {"write", cmd_write},
  {"check", cmd_check},
  {"erase", cmd_erase},
  {"selfrefresh", cmd_selfrefresh},
  {"normal", cmd_normal},
  {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
#if HAL_USE_SERIAL_USB
  (BaseSequentialStream *)&SDU1,
#else
  (BaseSequentialStream *)&SD1,
#endif
  commands
};

/*===========================================================================*/
/* Initialization and main thread.                                           */
/*===========================================================================*/

/*
 * Application entry point.
 */
int main(void) {
  thread_t *shelltp = NULL;

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Shell manager initialization.
   */
  shellInit();

#if HAL_USE_SERIAL_USB
  /*
   * Initializes a serial-over-USB CDC driver.
   */
  sduObjectInit(&SDU1);
  sduStart(&SDU1, &serusbcfg);

  /*
   * Activates the USB driver and then the USB bus pull-up on D+.
   * Note, a delay is inserted in order to not have to disconnect the cable
   * after a reset.
   */
  usbDisconnectBus(serusbcfg.usbp);
  chThdSleepMilliseconds(1000);
  usbStart(serusbcfg.usbp, &usbcfg);
  usbConnectBus(serusbcfg.usbp);
#else
  /*
   * Initializes serial port.
   */
  sdStart(&SD1, NULL);
#endif /* HAL_USE_SERIAL_USB */

  /*
   * Initialise SDRAM, board.h has already configured GPIO correctly
   * (except that ST example uses 50MHz not 100MHz?)
   */
  SDRAM_Init();
  sdram_bulk_erase();

  /*
   * Activates the LCD-related drivers.
   */
  spiStart(&SPID5, &spi_cfg5);
  ili9341ObjectInit(&ILI9341D1);
  ili9341Start(&ILI9341D1, &ili9341_cfg);
  initialize_lcd();
  ltdcInit();
  ltdcStart(&LTDCD1, &ltdc_cfg);

  /*
   * Activates the DMA2D-related drivers.
   */
  dma2dInit();
  dma2dStart(&DMA2DD1, &dma2d_cfg);
  dma2d_test();

  /*
   * Creating the blinker threads.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1),
                    NORMALPRIO + 10, Thread1, NULL);
  chThdCreateStatic(waThread2, sizeof(waThread2),
                    NORMALPRIO + 10, Thread2, NULL);

  /*
   * Normal main() thread activity, in this demo it just performs
   * a shell respawn upon its termination.
   */
  while (true) {
    if (!shelltp) {
#if HAL_USE_SERIAL_USB
      if (SDU1.config->usbp->state == USB_ACTIVE) {
        /* Spawns a new shell.*/
        shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);
      }
#else
      shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);
#endif
    }
    else {
      /* If the previous shell exited.*/
      if (chThdTerminatedX(shelltp)) {
        /* Recovers memory of the previous shell.*/
        chThdRelease(shelltp);
        shelltp = NULL;
      }
    }
    chThdSleepMilliseconds(500);
  }
}

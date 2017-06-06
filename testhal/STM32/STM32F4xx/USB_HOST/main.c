/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

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
#include "ff.h"
#include <string.h>

#if HAL_USBH_USE_FTDI || HAL_USBH_USE_AOA
static uint8_t buf[] =
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";
#endif

#if HAL_USBH_USE_FTDI
#include "usbh/dev/ftdi.h"
#include "shell.h"
#include "chprintf.h"

static THD_WORKING_AREA(waTestFTDI, 1024);

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(2048)
#define TEST_WA_SIZE    THD_WORKING_AREA_SIZE(256)

static void cmd_write(BaseSequentialStream *chp, int argc, char *argv[]) {

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: write\r\n");
    return;
  }

  while (chnGetTimeout((BaseChannel *)chp, TIME_IMMEDIATE) != Q_TIMEOUT) {
    //flush
  }

  while (chnGetTimeout((BaseChannel *)chp, TIME_IMMEDIATE) == Q_TIMEOUT) {
    streamWrite(&FTDIPD[0], buf, sizeof buf - 1);
  }
  chprintf(chp, "\r\n\nstopped\r\n");
}

static const ShellCommand commands[] = {
    {"write", cmd_write},
    {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
    (BaseSequentialStream *)&FTDIPD[0],
    commands
};

static void ThreadTestFTDI(void *p) {
    (void)p;
    USBHFTDIPortDriver *const ftdipp = &FTDIPD[0];

    shellInit();

start:
    while (usbhftdipGetState(ftdipp) != USBHFTDIP_STATE_ACTIVE) {
        chThdSleepMilliseconds(100);
    }

    usbDbgPuts("FTDI: Connected");

    USBHFTDIPortConfig config = {
        115200,
        USBHFTDI_FRAMING_DATABITS_8 | USBHFTDI_FRAMING_PARITY_NONE | USBHFTDI_FRAMING_STOP_BITS_1,
        USBHFTDI_HANDSHAKE_NONE,
        0,
        0
    };

    usbhftdipStart(ftdipp, &config);

    //loopback
    if (0) {
        for(;;) {
            msg_t m = streamGet(ftdipp);
            if (m < MSG_OK) {
                usbDbgPuts("FTDI: Disconnected");
                goto start;
            }
            streamPut(ftdipp, (uint8_t)m);
            if (m == 'q')
                break;
        }
    }

    //shell test
    if (1) {
        thread_t *shelltp = NULL;
        for(;;) {
            if (usbhftdipGetState(ftdipp) != USBHFTDIP_STATE_READY)
                goto start;
            if (!shelltp) {
                shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);
            } else if (chThdTerminatedX(shelltp)) {
                chThdRelease(shelltp);
                if (usbhftdipGetState(ftdipp) != USBHFTDIP_STATE_READY)
                    goto start;
                break;
            }
            chThdSleepMilliseconds(100);
        }
    }

    //FTDI uart RX to debug TX bridge
    if (0) {
        for(;;) {
            msg_t m = streamGet(ftdipp);
            if (m < MSG_OK) {
                usbDbgPuts("FTDI: Disconnected");
                goto start;
            }
            sdPut(&USBH_DEBUG_SD, (uint8_t)m);
            if (m == 'q')
                break;
        }
    }

    //write speed test
    if (1) {
        usbhftdipStop(ftdipp);
        config.speed = 3000000;
        usbhftdipStart(ftdipp, &config);

        systime_t st, et;
        int i;
        for (i = 0; i < 5; i++) {
            uint32_t bytes = config.speed / 10;
            uint32_t times = bytes / 1024;
            st = chVTGetSystemTimeX();
            while (times--) {
                if (streamWrite(ftdipp, buf, 1024) < 1024) {
                    usbDbgPuts("FTDI: Disconnected");
                    goto start;
                }
                bytes -= 1024;
            }
            if (bytes) {
                if (streamWrite(ftdipp, buf, bytes) < bytes) {
                    usbDbgPuts("FTDI: Disconnected");
                    goto start;
                }
            }
            et = chVTGetSystemTimeX();
            usbDbgPrintf("\tRate=%uB/s", (config.speed * 100) / (et - st));
        }
    }

    //single character write test (tests the timer)
    if (0) {
        for (;;) {
            if (streamPut(ftdipp, 'A') != MSG_OK) {
                usbDbgPuts("FTDI: Disconnected");
                goto start;
            }
            chThdSleepMilliseconds(100);
        }
    }

    usbhftdipStop(ftdipp);

    usbDbgPuts("FTDI: Tests done, restarting in 3s");
    chThdSleepMilliseconds(3000);

    goto start;
}
#endif

#if HAL_USBH_USE_AOA
#include "usbh/dev/aoa.h"
#include "chprintf.h"

static THD_WORKING_AREA(waTestAOA, 1024);

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(2048)
#define TEST_WA_SIZE    THD_WORKING_AREA_SIZE(256)

static void ThreadTestAOA(void *p) {
    (void)p;
    USBHAOADriver *const aoap = &USBHAOAD[0];
    USBHAOAChannel *const aoacp = &aoap->channel;

start:
    while (usbhaoaGetState(aoap) != USBHAOA_STATE_READY) {
        chThdSleepMilliseconds(100);
    }

    usbDbgPuts("AOA: Connected");

    if (usbhaoaGetChannelState(aoap) != USBHAOA_CHANNEL_STATE_READY) {
        usbhaoaChannelStart(aoap);
        usbDbgPuts("AOA: Channel started");
    }

    //loopback
    if (1) {
        for(;;) {
            msg_t m = streamGet(aoacp);
            if (m < MSG_OK) {
                usbDbgPuts("AOA: Disconnected");
                goto start;
            }
            streamPut(aoacp, (uint8_t)m);
            if (m == 'q')
                break;
        }
    }

#define AOA_WRITE_SPEED_TEST_BYTES    3000000UL
    //write speed test
    if (1) {
        systime_t st, et;
        int i;
        for (i = 0; i < 5; i++) {
            uint32_t bytes = AOA_WRITE_SPEED_TEST_BYTES;
            uint32_t times = bytes / 1024;
            st = chVTGetSystemTimeX();
            while (times--) {
                if (streamWrite(aoacp, buf, 1024) < 1024) {
                    usbDbgPuts("AOA: Disconnected");
                    goto start;
                }
                bytes -= 1024;
            }
            if (bytes) {
                if (streamWrite(aoacp, buf, bytes) < bytes) {
                    usbDbgPuts("AOA: Disconnected");
                    goto start;
                }
            }
            et = chVTGetSystemTimeX();
            usbDbgPrintf("\tRate=%uB/s", AOA_WRITE_SPEED_TEST_BYTES / (et - st) * 100);
        }
    }

    //single character write test (tests the timer)
    if (0) {
        for (;;) {
            if (streamPut(aoacp, 'A') != MSG_OK) {
                usbDbgPuts("AOA: Disconnected");
                goto start;
            }
            chThdSleepMilliseconds(100);
        }
    }

    usbhaoaChannelStop(aoap);

    usbDbgPuts("AOA: Tests done, restarting in 3s");
    chThdSleepMilliseconds(3000);

    goto start;
}
#endif

#if HAL_USBH_USE_MSD
#include "usbh/dev/msd.h"
#include "ff.h"

static FATFS MSDLUN0FS;
static uint8_t fbuff[10240];
static FIL file;

static FRESULT scan_files(BaseSequentialStream *chp, char *path) {
  FRESULT res;
  FILINFO fno;
  DIR dir;
  int i;
  char *fn;

#if _USE_LFN
  fno.lfname = 0;
  fno.lfsize = 0;
#endif
  res = f_opendir(&dir, path);
  if (res == FR_OK) {
    i = strlen(path);
    for (;;) {
      res = f_readdir(&dir, &fno);
      if (res != FR_OK || fno.fname[0] == 0)
        break;
      if (fno.fname[0] == '.')
        continue;
      fn = fno.fname;
      if (fno.fattrib & AM_DIR) {
        path[i++] = '/';
        strcpy(&path[i], fn);
        res = scan_files(chp, path);
        if (res != FR_OK)
          break;
        path[--i] = 0;
      } else {
          usbDbgPrintf("FS: %s/%s", path, fn);
      }
    }
  }
  return res;
}
static THD_WORKING_AREA(waTestMSD, 1024);
static void ThreadTestMSD(void *p) {
    (void)p;

    FATFS *fsp;
    DWORD clusters;
    FRESULT res;
    BaseSequentialStream * const chp = (BaseSequentialStream *)&USBH_DEBUG_SD;
    blkstate_t state;
    systime_t st, et;
    uint32_t j;

start:
    for(;;) {
        chThdSleepMilliseconds(100);

        chSysLock();
        state = blkGetDriverState(&MSBLKD[0]);
        chSysUnlock();
        if (state != BLK_READY)
            continue;

        //raw read test
        if (1) {
#define RAW_READ_SZ_MB        1
#define NBLOCKS                (sizeof(fbuff) / 512)
#define NITERATIONS            ((RAW_READ_SZ_MB * 1024UL * 1024UL) / sizeof(fbuff))
            uint32_t start = 0;
            chThdSetPriority(HIGHPRIO);
            usbDbgPrintf("BLK: Raw read test (%dMB, %dB blocks)", RAW_READ_SZ_MB, sizeof(fbuff));
            st = chVTGetSystemTime();
            for (j = 0; j < NITERATIONS; j++) {
                blkRead(&MSBLKD[0], start, fbuff, NBLOCKS);
                start += NBLOCKS;
            }
            et = chVTGetSystemTime();
            usbDbgPrintf("BLK: Raw read in %d ms, %dkB/s",
                    et - st,
                    (RAW_READ_SZ_MB * 1024UL * 1000) / (et - st));
            chThdSetPriority(NORMALPRIO);
        }

        usbDbgPuts("FS: Block driver ready, try mount...");

        res = f_mount(&MSDLUN0FS, "0:", 1);
        if (res != FR_OK) {
            usbDbgPuts("FS: Can't mount. Check file system.");
            continue;
        }
        usbDbgPuts("FS: Mounted.");

        res = f_getfree("0:", &clusters, &fsp);
        if (res != FR_OK) {
            usbDbgPuts("FS: f_getfree() failed");
            continue;
        }

        usbDbgPrintf("FS: %lu free clusters, %lu sectors per cluster, %lu bytes free",
                clusters, (uint32_t)MSDLUN0FS.csize,
                clusters * (uint32_t)MSDLUN0FS.csize * MSBLKD[0].info.blk_size);

        break;
    }

    //FATFS test
    if (1) {
        UINT bw;
        const uint8_t *src;
        const uint8_t *const start = (uint8_t *)0x08000000;
        const uint8_t *const top = (uint8_t *)0x08020000;

        //write test
        if (1) {
            usbDbgPuts("FS: Write test (create file /test.dat, 1MB)");
            f_open(&file, "/test.dat", FA_CREATE_ALWAYS | FA_WRITE);
            src = start;
            st = chVTGetSystemTime();
            for (j = 0; j < 2048; j++) {
                if (f_write(&file, src, 512, &bw) != FR_OK)
                    goto start;
                src += bw;
                if (src >= top)
                    src = start;
            }
            et = chVTGetSystemTime();
            usbDbgPrintf("FS: Written 1MB in %d ms, %dkB/s",
                    et - st,
                    (1024UL*1000) / (et - st));
            f_close(&file);
        }

        //read test
        if (1) {
            usbDbgPuts("FS: Read test (read file /test.dat, 1MB, compare)");
            f_open(&file, "/test.dat", FA_READ);
            src = start;
            st = chVTGetSystemTime();
            for (j = 0; j < 2048; j++) {
                if (f_read(&file, fbuff, 512, &bw) != FR_OK)
                    goto start;
                if (memcmp(src, fbuff, bw)) {
                    usbDbgPrintf("Compare error @%08x", (uint32_t)src);
                    goto start;
                }
                src += bw;
                if (src >= top)
                    src = start;
            }
            et = chVTGetSystemTime();
            usbDbgPrintf("FS: Read 1MB in %d ms, %dkB/s",
                    et - st,
                    (1024UL*1000) / (et - st));
            f_close(&file);
        }

        //scan files test
        if (1) {
            usbDbgPuts("FS: Scan files test");
            fbuff[0] = 0;
            scan_files(chp, (char *)fbuff);
        }
    }

    usbDbgPuts("FS: Tests done, restarting in 3s");
    chThdSleepMilliseconds(3000);

    goto start;

}
#endif

#if HAL_USBH_USE_HID
#include "usbh/dev/hid.h"
#include "chprintf.h"

static THD_WORKING_AREA(waTestHID, 1024);

static void _hid_report_callback(USBHHIDDriver *hidp, uint16_t len) {
    uint8_t *report = (uint8_t *)hidp->config->report_buffer;

    if (hidp->type == USBHHID_DEVTYPE_BOOT_MOUSE) {
        usbDbgPrintf("Mouse report: buttons=%02x, Dx=%d, Dy=%d",
                report[0],
                (int8_t)report[1],
                (int8_t)report[2]);
    } else if (hidp->type == USBHHID_DEVTYPE_BOOT_KEYBOARD) {
        usbDbgPrintf("Keyboard report: modifier=%02x, keys=%02x %02x %02x %02x %02x %02x",
                report[0],
                report[2],
                report[3],
                report[4],
                report[5],
                report[6],
                report[7]);
    } else {
        usbDbgPrintf("Generic report, %d bytes", len);
    }
}

static USBH_DEFINE_BUFFER(uint8_t report[HAL_USBHHID_MAX_INSTANCES][8]);
static USBHHIDConfig hidcfg[HAL_USBHHID_MAX_INSTANCES];

static void ThreadTestHID(void *p) {
    (void)p;
    uint8_t i;
    static uint8_t kbd_led_states[HAL_USBHHID_MAX_INSTANCES];

    for (i = 0; i < HAL_USBHHID_MAX_INSTANCES; i++) {
        hidcfg[i].cb_report = _hid_report_callback;
        hidcfg[i].protocol = USBHHID_PROTOCOL_BOOT;
        hidcfg[i].report_buffer = report[i];
        hidcfg[i].report_len = 8;
    }

    for (;;) {
        for (i = 0; i < HAL_USBHHID_MAX_INSTANCES; i++) {
            if (usbhhidGetState(&USBHHIDD[i]) == USBHHID_STATE_ACTIVE) {
                usbDbgPrintf("HID: Connected, HID%d", i);
                usbhhidStart(&USBHHIDD[i], &hidcfg[i]);
                if (usbhhidGetType(&USBHHIDD[i]) != USBHHID_DEVTYPE_GENERIC) {
                    usbhhidSetIdle(&USBHHIDD[i], 0, 0);
                }
                kbd_led_states[i] = 1;
            } else if (usbhhidGetState(&USBHHIDD[i]) == USBHHID_STATE_READY) {
                if (usbhhidGetType(&USBHHIDD[i]) == USBHHID_DEVTYPE_BOOT_KEYBOARD) {
                    USBH_DEFINE_BUFFER(uint8_t val);
                    val = kbd_led_states[i] << 1;
                    if (val == 0x08) {
                        val = 1;
                    }
                    usbhhidSetReport(&USBHHIDD[i], 0, USBHHID_REPORTTYPE_OUTPUT, &val, 1);
                    kbd_led_states[i] = val;
                }
            }
        }
        chThdSleepMilliseconds(200);
    }

}
#endif


int main(void) {

    IWDG->KR = 0x5555;
    IWDG->PR = 7;

    halInit();
    chSysInit();

    //PA2(TX) and PA3(RX) are routed to USART2
    sdStart(&SD2, NULL);
    palSetPadMode(GPIOA, 2, PAL_MODE_ALTERNATE(7));
    palSetPadMode(GPIOA, 3, PAL_MODE_ALTERNATE(7));

#if STM32_USBH_USE_OTG1
    //VBUS - configured in board.h
    //USB_FS - configured in board.h
#endif

#if STM32_USBH_USE_OTG2
#error "TODO: Initialize USB_HS pads"
#endif

#if HAL_USBH_USE_MSD
    chThdCreateStatic(waTestMSD, sizeof(waTestMSD), NORMALPRIO, ThreadTestMSD, 0);
#endif

#if HAL_USBH_USE_FTDI
    chThdCreateStatic(waTestFTDI, sizeof(waTestFTDI), NORMALPRIO, ThreadTestFTDI, 0);
#endif

#if HAL_USBH_USE_AOA
    chThdCreateStatic(waTestAOA, sizeof(waTestAOA), NORMALPRIO, ThreadTestAOA, 0);
#endif

#if HAL_USBH_USE_HID
    chThdCreateStatic(waTestHID, sizeof(waTestHID), NORMALPRIO, ThreadTestHID, 0);
#endif

    //turn on USB power
    palClearPad(GPIOC, GPIOC_OTG_FS_POWER_ON);

    //start
#if STM32_USBH_USE_OTG1
    usbhStart(&USBHD1);
#endif
#if STM32_USBH_USE_OTG2
    usbhStart(&USBHD2);
#endif

    for(;;) {
#if STM32_USBH_USE_OTG1
        usbhMainLoop(&USBHD1);
#endif
#if STM32_USBH_USE_OTG2
        usbhMainLoop(&USBHD2);
#endif
        chThdSleepMilliseconds(100);

        IWDG->KR = 0xAAAA;
    }
}

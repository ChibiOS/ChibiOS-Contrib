#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"

#include "hal_mfs.h"

#include "mfs_test_root.h"

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(2048)

/* Can be measured using dd if=/dev/xxxx of=/dev/null bs=512 count=10000.*/
static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  (void)argc;
  test_execute((BaseSequentialStream *)chp, &mfs_test_suite);
}

static const ShellCommand commands[] = {
  {"test_mfs", cmd_test},
  {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
  (BaseSequentialStream *)&SIOD3,
  commands
};

static const SIOConfig siocfg = {
  SIO_DEFAULT_BITRATE,
  SERCOM_CTRLA_DEFAULT,
  SERCOM_CTRLB_DEFAULT,
  1,
  3
};

const MFSConfig mfscfg1 = {
  .flashp           = (BaseFlash *)&EFLD1,
  .erased           = 0xFFFFFFFFU,
  .bank_size        = 2048,
  .bank0_start      = 256U,
  .bank0_sectors    = 8U,
  .bank1_start      = 256+8,
  .bank1_sectors    = 8U
};

/*
 * LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;

  chRegSetThreadName("blinker");
  while (true) {
    palClearPad(GPIOA, 17);
    chThdSleepMilliseconds(1000);
    palSetPad(GPIOA, 17);
    chThdSleepMilliseconds(1000);
  }
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

  palSetPadMode(GPIOA, 17, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_D));
  palSetPadMode(GPIOA, 11, PAL_MODE_ALTERNATE(PAL_SAM_FUNC_D));

  /* Start SIO */
  sioStart(&SIOD3, &siocfg);
  sioStartOperation(&SIOD3, NULL);

  /* Starting EFL driver.*/
  eflStart(&EFLD1, NULL);

  /*
   * Shell manager initialization.
   */
  shellInit();

  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  /*
   * Normal main() thread activity, spawning shells.
   */
  while (true) {
    thread_t *shelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE,
                                            "shell", NORMALPRIO + 1,
                                            shellThread, (void *)&shell_cfg1);
    chThdWait(shelltp);               /* Waiting termination.             */
    chThdSleepMilliseconds(1000);
  }
}
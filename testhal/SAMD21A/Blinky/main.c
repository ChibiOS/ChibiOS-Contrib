#include "ch.h"
#include "hal.h"

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
  while (true) {
    palTogglePad(GPIOA, 17);
    chThdSleepMilliseconds(1000);
  }
}
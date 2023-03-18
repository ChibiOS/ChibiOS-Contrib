#include "board.h"
#include "hal.h"

void boardInit(void) {
    palSetLineMode(LINE_USBVBUS, MODE_FUNC_ALT1 | MODE_MODE_PULL_UP | MODE_AD_DIGITAL);
    palSetLineMode(LINE_USBCONN, MODE_FUNC_ALT1 | MODE_AD_DIGITAL);

#ifdef SNOWFOX_TST
    palSetLineMode(LINE_BTN1, MODE_DIR_IN | MODE_MODE_PULL_UP | MODE_AD_DIGITAL);
#else
    palSetLineMode(LINE_ROW1, MODE_DIR_OUT | MODE_AD_DIGITAL);
    palClearLine(LINE_ROW1);
    palSetLineMode(LINE_COL1, MODE_DIR_IN | MODE_MODE_PULL_DOWN | MODE_AD_DIGITAL);
#endif
}

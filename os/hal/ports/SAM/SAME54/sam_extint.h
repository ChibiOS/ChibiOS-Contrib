#ifndef SAMD21_EXTINT_H_
#define SAMD21_EXTINT_H_

/**
 * @brief get EXTINT number for certain PORT
 * 
 * @param port 
 * @param pad 
 * @return int8_t extint
 */
static inline int8_t _get_extint(ioportid_t port, iopadid_t pad) {
  int8_t extint = 0;
  if (port == GPIOA) {
    switch (pad) {
      case 8:
      case 26:
      case 28:
      case 29:
      case 30:
      case 31:
        osalDbgAssert(0, "Pin does not support EIC");
        extint = -1;
        break;
      default:
        extint = pad % 16;
        break;
    }
  } else if (port == GPIOB) {
    switch (pad) {
      case 3:
        osalDbgAssert(0, "Pin does not support EIC");
        extint = -1;
        break;
      case 26:
      case 27:
      case 28:
      case 29:
        extint = pad % 16 + 2;
        break;
      default:
        extint = pad % 16;
        break;
    }
  } else if (port == GPIOC) {
    switch (pad) {
      case 8:
      case 9:
      case 29:
        osalDbgAssert(0, "Pin does not support EIC");
        extint = -1;
        break;
      case 7:
        extint = pad % 16 + 2;
        break;
      default:
        extint = pad % 16;
        break;
    }
  }

  else if (port == GPIOD) {
    if (pad >= 8 && pad <= 12) {
      extint = pad % 16 - 5;
    } else if (pad == 20 || pad == 21) {
      extint = pad % 16 + 1;
    } else {
      osalDbgAssert(0, "Pin does not support EIC");
      extint = -1;
    }
    switch (pad) {
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
        osalDbgAssert(0, "Pin does not support EIC");
        extint = -1;
        break;
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
        extint = pad % 16 - 5;
        break;
      case 20:
      case 21:
        extint = pad % 16 + 1;
        break;
      default:
        extint = pad % 16;
        break;
    }
  }
  return extint;
}

#endif
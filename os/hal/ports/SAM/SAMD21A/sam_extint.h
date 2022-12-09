#ifndef SAMD21_EXTINT_H_
#define SAMD21_EXTINT_H_

/**
 * @brief get EXTINT number for certain PORT
 * 
 * @param port 
 * @param pad 
 * @return int8_t extint
 */
static inline int8_t _get_extint(ioportid_t port, iopadid_t pad)
{
    int8_t extint = 0;
    if(port == GPIOA) {
        switch(pad) {
            case 8:
                osalDbgAssert(0, "PA08 does not have EXTINT");
                extint = -1;
                break;
            case 24:
                extint = 12;
                break;
            case 25: 
                extint = 13;
                break;
            case 27:
                extint = 15;
                break;
            case 28:
                extint = 8;
                break;
            case 30:
                extint = 10;
                break;
            case 31:
                extint = 11;
                break;
            default:
                extint = pad % 16;
                break;
        }
    }
    else if(port == GPIOB) {
        switch(pad) {
            default:
                extint = pad % 16;
                break;
        }
    }
    return extint;

}


#endif
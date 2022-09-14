#ifndef BOARD_H_
#define BOARD_H_

#define __SAMD21G18A__
#define BOARD_NAME                "SEEEDUINO Cortex-M0+"

#define SAM_XOSC_FREQ             32000000UL
#define SAM_XOSC32K_FREQ          32768UL
#define SAM_HAS_GPIOA
#define SAM_HAS_GPIOB

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif


#endif
#ifndef BOARD_H_
#define BOARD_H_
 
#define __SAME54P20A__
#define BOARD_NAME "SAME54-Xplained Pro"
 
#define SAM_XOSC32K_FREQ 32768UL
#define SAM_HAS_GPIOA
#define SAM_HAS_GPIOB
#define SAM_HAS_GPIOC
#define SAM_HAS_GPIOD
 
#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus
void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif
 
#endif  // BOARD_H_
 
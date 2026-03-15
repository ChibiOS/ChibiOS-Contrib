#ifndef CH579_H
#define CH579_H

#include <stdint.h>

/* ── CMSIS Cortex-M core parameters (required by ChibiOS ARMv6-M port) ── */
#define __CORTEX_M (0U)    /* Cortex-M0                            */
#define __NVIC_PRIO_BITS 2 /* CM0: only top 2 bits of priority used */
#define __CM0_REV 0        /* Core revision                        */
#define __MPU_PRESENT 0    /* No MPU                               */
#define __VTOR_PRESENT 0   /* No VTOR on basic CM0                 */
#define __FPU_PRESENT 0    /* No FPU                               */

typedef enum {
  /* ── Cortex-M0 Exceptions ── */
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVCall_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,
  /* ── CH579M Specific Interrupts ── */
  TMR0_IRQn = 0,
  USB_IRQn  = 6,   /* vector address 0x0058 (datasheet Table 3-1) */
} IRQn_Type;

#include "core_cm0.h"

/* ── Safe-access unlock (required before writing RWA-protected regs) ── */
/* Address 0x40001040 per datasheet Table 4-1.
 * Window is valid for ~16 system clock cycles after writing 0xA8. */
#define R8_SAFE_ACCESS_SIG (*((volatile uint8_t *)0x40001040))
#define SAFE_ACCESS_OPEN()                                                     \
  do {                                                                         \
    R8_SAFE_ACCESS_SIG = 0x57;                                                 \
    R8_SAFE_ACCESS_SIG = 0xA8;                                                 \
  } while (0)
#define SAFE_ACCESS_CLOSE()                                                    \
  do {                                                                         \
    R8_SAFE_ACCESS_SIG = 0x00;                                                 \
  } while (0)

/* ── System clock (safe-access protected) ───────────────────────── */
/* R16_CLK_SYS_CFG at 0x40001008 (datasheet Table 6-1).
 * Low byte  (0x40001008): bits[7:6]=RB_CLK_SYS_MOD, bits[4:0]=RB_CLK_PLL_DIV
 * High byte (0x40001009): bit1=RB_CLK_OSC32M_XT (0=HSI, 1=external crystal)
 *
 * For 48 MHz: Fpll=480 MHz, CLK_PLL_DIV=10 → Fsys=48 MHz.
 * Write 0x4A to low byte: (0b01<<6)|(10) = 0x40|0x0A = 0x4A */
#define R8_CLK_PLL_DIV    (*((volatile uint8_t *)0x40001008))  /* low byte  */
#define R8_CLK_SYS_CFG_H  (*((volatile uint8_t *)0x40001009))  /* high byte */
#define RB_CLK_SYS_MOD    (3 << 6)
#define CLK_SYS_MOD_PLL   (1 << 6)   /* 0b01 = PLL source (datasheet §6.2) */
#define RB_CLK_OSC32M_XT  (1 << 1)   /* select external XT32M as CK32M source */

/* ── HF clock power control (safe-access protected, 0x4000100A) ─── */
#define R8_HFCK_PWR_CTRL  (*((volatile uint8_t *)0x4000100A))
#define RB_CLK_PLL_PON    (1 << 4)   /* power on PLL (off at reset)           */
#define RB_CLK_XT32M_PON  (1 << 2)   /* power on external 32 MHz oscillator   */

/* ── PLL lock status (read-only, 0x40001053) ────────────────────── */
#define R8_PLL_CONFIG     (*((volatile uint8_t *)0x40001053))
#define RB_PLL_LOCKED     (1 << 7)   /* RO: 1 when PLL is locked      */

/* ── Sleep / clock-gate control (safe-access protected) ─────────── */
/* bit=1 gates the clock OFF; clear to enable (datasheet Table 5-1). */
#define R8_SLP_CLK_OFF0   (*((volatile uint8_t *)0x4000100C))  /* UART/TMR gates */
#define R8_SLP_CLK_OFF1   (*((volatile uint8_t *)0x4000100D))
#define RB_SLP_CLK_USB    (1 << 4)   /* USB clock gate in OFF1 (0=on at reset) */

/* ── GPIO ────────────────────────────────────────────────────────── */
typedef struct {
  volatile uint32_t DIR;    /* direction: 1=output              */
  volatile uint32_t PIN;    /* input value                      */
  volatile uint32_t OUT;    /* output latch                     */
  volatile uint32_t CLR;    /* atomic bit clear                 */
  volatile uint32_t PU;     /* pull-up enable                   */
  volatile uint32_t PD_DRV; /* pull-down / drive strength       */
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *)0x400010A0)
#define GPIOB ((GPIO_TypeDef *)0x400010C0)

/* ── USB Device (base 0x40008000) ───────────────────────────────── */
/*
 * bMaxPacketSize0 = 8 confirmed from lsusb dump of stock firmware.
 * Endpoint buffer RAM: 0x40008800 (512 bytes shared).
 *
 * Datasheet Table 17-1 / 17-2:
 *   R8_USB_CTRL   (0x40008000): global USB control
 *   R8_UDEV_CTRL  (0x40008001): physical port control — must set RB_UD_PORT_EN
 *
 * To assert D+ pull-up (announce FS device to host):
 *   1. R8_USB_CTRL = RB_UC_DEV_PU_EN | RB_UC_INT_BUSY  (0x20 | 0x08)
 *   2. R16_PIN_ANALOG_IE |= RB_PIN_USB_IE               (enable USB pin I/O)
 *   3. R8_UDEV_CTRL = RB_UD_PD_DIS | RB_UD_PORT_EN     (0x80 | 0x01)
 */
#define R8_USB_CTRL  (*((volatile uint8_t *)0x40008000))
#define R8_UDEV_CTRL (*((volatile uint8_t *)0x40008001))  /* device physical port */
#define R8_USB_INT_EN (*((volatile uint8_t *)0x40008002))
#define R8_USB_DEV_AD (*((volatile uint8_t *)0x40008003))
#define R8_USB_MIS_ST (*((volatile uint8_t *)0x40008004))
#define R8_USB_INT_FG (*((volatile uint8_t *)0x40008006))
#define R8_USB_INT_ST (*((volatile uint8_t *)0x40008007))
#define R8_USB_RX_LEN (*((volatile uint8_t *)0x40008008))

/* R8_USB_CTRL bits (datasheet Table 17-1) */
#define RB_UC_HOST_MODE (1 << 7) /* 1=host mode, 0=device mode   */
#define RB_UC_DEV_PU_EN (1 << 5) /* device mode + internal 1.5k D+ pull-up */
#define RB_UC_INT_BUSY  (1 << 3) /* NAK while CPU busy           */
#define RB_UC_RESET_SIE (1 << 2)
#define RB_UC_CLR_ALL   (1 << 1)
#define RB_UC_DMA_EN    (1 << 0)

/* R8_UDEV_CTRL bits (datasheet Table 17-2) */
#define RB_UD_PD_DIS   (1 << 7) /* disable internal D+/D- pull-down */
#define RB_UD_PORT_EN  (1 << 0) /* enable USB physical port I/O */

/* R16_PIN_ANALOG_IE (0x4000101A): enable USB pin analog I/O */
#define R16_PIN_ANALOG_IE (*((volatile uint16_t *)0x4000101A))
#define RB_PIN_USB_IE     (1 << 7) /* bit 7 of the 16-bit register = 0x0080 */

/* R8_USB_INT_FG / R8_USB_INT_EN bits (datasheet Table 17-1, p.77)
 * INT_FG reset = 0x20 (bit5 RB_U_SIE_FREE set). */
#define RB_UIF_BUS_RST   (1 << 0) /* device: bus reset event      */
#define RB_UIF_TRANSFER  (1 << 1) /* transfer complete            */
#define RB_UIF_SUSPEND   (1 << 2) /* bus suspend / wake           */

/* R8_USB_INT_ST bits (datasheet p.77-78) */
#define MASK_UIS_TOKEN  (3 << 4)  /* PID token field              */
#define UIS_TOKEN_OUT   (0 << 4)  /* OUT token                    */
#define UIS_TOKEN_SOF   (1 << 4)  /* SOF token                    */
#define UIS_TOKEN_IN    (2 << 4)  /* IN token                     */
#define UIS_TOKEN_SETUP (3 << 4)  /* SETUP token                  */
#define MASK_UIS_ENDP   (0x0F)    /* endpoint number field        */

/* ── Endpoint mode registers (datasheet Table 17-2) ─────────────── */
#define R8_UEP4_1_MOD (*((volatile uint8_t *)0x4000800c))
#define R8_UEP2_3_MOD (*((volatile uint8_t *)0x4000800d))
#define RB_UEP1_TX_EN (1 << 6) /* enable EP1 IN (TX)  */
#define RB_UEP1_RX_EN (1 << 7) /* enable EP1 OUT (RX) */
#define RB_UEP2_TX_EN (1 << 2) /* enable EP2 IN (TX)  */
#define RB_UEP2_RX_EN (1 << 3) /* enable EP2 OUT (RX) */

/* ── Endpoint DMA base-address registers (must be set even without DMA) ── */
/* Stores lower 16 bits of the endpoint SRAM address.
 * SIE uses these regardless of RB_UC_DMA_EN to locate buffer in SRAM. */
#define R16_UEP0_DMA (*((volatile uint16_t *)0x40008010))
#define R16_UEP1_DMA (*((volatile uint16_t *)0x40008014))
#define R16_UEP2_DMA (*((volatile uint16_t *)0x40008018))

/* ── Endpoint TX-length and control registers (datasheet Table 17-2) ── */
/* Register order per endpoint: T_LEN at base+0, CTRL at base+2, stride 4. */
#define R8_UEP0_T_LEN (*((volatile uint8_t *)0x40008020))
#define R8_UEP0_CTRL  (*((volatile uint8_t *)0x40008022))
#define R8_UEP1_T_LEN (*((volatile uint8_t *)0x40008024))
#define R8_UEP1_CTRL  (*((volatile uint8_t *)0x40008026))
#define R8_UEP2_T_LEN (*((volatile uint8_t *)0x40008028))
#define R8_UEP2_CTRL  (*((volatile uint8_t *)0x4000802a))

/* R8_UEPn_CTRL bits (datasheet Table 17-2, p.88):
 *   bit  7     = RB_UEP_R_TOG:    RX expected toggle: 1=Expect DATA1, 0=Expect DATA0
 *   bit  6     = RB_UEP_T_TOG:    TX data toggle:     1=Send DATA1,   0=Send DATA0
 *   bit  5     = Reserved
 *   bit  4     = RB_UEP_AUTO_TOG: Auto-flip T_TOG/R_TOG on success (EP1/2/3 only, NOT EP0)
 *   bits [3:2] = MASK_UEP_R_RES:  OUT response
 *   bits [1:0] = MASK_UEP_T_RES:  IN  response */
#define RB_UEP_R_TOG    0x80  /* RX toggle bit: 1=expect DATA1 */
#define RB_UEP_T_TOG    0x40  /* TX toggle bit: 1=send DATA1   */
#define RB_UEP_AUTO_TOG 0x10  /* Auto-flip T/R_TOG (EP1/2/3 only) */
#define MASK_UEP_T_RES  0x03
#define MASK_UEP_R_RES  0x0C
#define UEP_T_RES_ACK   0x00  /* DATA0/1 ready, respond ACK */
#define UEP_T_RES_NAK   0x02  /* respond NAK                */
#define UEP_T_RES_STALL 0x03  /* respond STALL              */
#define UEP_R_RES_ACK   0x00  /* respond ACK  (bits [3:2])  */
#define UEP_R_RES_NAK   0x08  /* respond NAK  (bits [3:2])  */
#define UEP_R_RES_STALL 0x0C  /* respond STALL              */

/* ── Endpoint buffer RAM ─────────────────────────────────────────── */
/* Layout confirmed from WCH EVT reference:
 *   EP0: 8-byte shared buf at base+0x00
 *   EP1: 64-byte IN buf    at base+0x40
 *   EP2: 4-byte  IN buf    at base+0x80 */
#define USB_BUF_BASE  0x40008800UL
#define EP0_BUF      ((uint8_t *)(USB_BUF_BASE + 0x00)) /*  8 bytes */
#define EP1_IN_BUF   ((uint8_t *)(USB_BUF_BASE + 0x40)) /* 64 bytes */
#define EP2_IN_BUF   ((uint8_t *)(USB_BUF_BASE + 0x80)) /*  4 bytes */

#endif /* CH579_H */
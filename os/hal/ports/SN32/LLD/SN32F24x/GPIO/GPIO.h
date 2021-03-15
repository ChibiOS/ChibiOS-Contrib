#ifndef __SN32F240_GPIO_H
#define __SN32F240_GPIO_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <SN32F240.h>


/*_____ D E F I N I T I O N S ______________________________________________*/
/*							
Base Address: 0x4004 4000 (GPIO 0)
							0x4004 6000 (GPIO 1)
							0x4004 8000 (GPIO 2)
							0x4004 A000 (GPIO 3)													
*/

/* GPIO Port n Data register <GPIOn_DATA> (0x00) */


/* GPIO Port n Mode register <GPIOn_MODE> (0x04) */
#define	GPIO_MODE_INPUT							0
#define	GPIO_MODE_OUTPUT						1

#define	GPIO_CURRENT_10MA						0
#define	GPIO_CURRENT_20MA						1
	
/* GPIO Port n Configuration register <GPIOn_CFG> (0x08) */
#define	GPIO_CFG_PULL_UP						0
#define	GPIO_CFG_PULL_DOWN					1
#define	GPIO_CFG_PULL_INACTIVE			2
#define	GPIO_CFG_REPEATER_MODE			3

/* GPIO Port n Interrupt Sense register <GPIOn_IS> (0x0C) */
#define	GPIO_IS_EDGE								0
#define	GPIO_IS_EVENT								1


/* GPIO Port n Interrupt Both-edge Sense registe <GPIOn_IBS> (0x10) */
#define	GPIO_IBS_EDGE_TRIGGER				0
#define	GPIO_IBS_BOTH_EDGE_TRIGGER	1


/* GPIO Port n Interrupt Event register <GPIOn_IEV> (0x14) */
#define	GPIO_IEV_RISING_EDGE				0
#define	GPIO_IEV_FALLING_EDGE				1


/* GPIO Port n Interrupt Enable register <GPIOn_IE> (0x18) */
#define	GPIO_IE_DIS									0	
#define	GPIO_IE_EN									1


/* GPIO Port n Raw Interrupt Status register <GPIOn_RIS/GPIOn_IC> (0x1C/0x20) */
#define mskPIN0IF										(0x1<<0)
#define mskPIN1IF										(0x1<<1)
#define mskPIN2IF										(0x1<<2)
#define mskPIN3IF										(0x1<<3)
#define mskPIN4IF										(0x1<<4)
#define mskPIN5IF										(0x1<<5)
#define mskPIN6IF										(0x1<<6)
#define mskPIN7IF										(0x1<<7)
#define mskPIN8IF										(0x1<<8)
#define mskPIN9IF										(0x1<<9)
#define mskPIN10IF									(0x1<<10)
#define mskPIN11IF									(0x1<<11)
#define mskPIN12IF									(0x1<<12)
#define mskPIN13IF									(0x1<<13)
#define mskPIN14IF									(0x1<<14)
#define mskPIN15IF									(0x1<<15)


/* GPIO Port Name Define */
//GPIO name define
#define	GPIO_PORT0  								0
#define	GPIO_PORT1 									1
#define	GPIO_PORT2  								2 
#define	GPIO_PORT3 									3

/* GPIO Pin Name Define */
#define		GPIO_PIN0 								0
#define		GPIO_PIN1 								1 
#define		GPIO_PIN2 								2 
#define		GPIO_PIN3 								3 
#define		GPIO_PIN4 								4
#define		GPIO_PIN5  								5 
#define		GPIO_PIN6  								6 
#define		GPIO_PIN7 								7
#define		GPIO_PIN8  								8
#define		GPIO_PIN9 								9
#define		GPIO_PIN10  							10
#define		GPIO_PIN11  							11
#define		GPIO_PIN12  							12
#define		GPIO_PIN13  							13
#define		GPIO_PIN14  							14
#define		GPIO_PIN15  							15

	
/*_____ M A C R O S ________________________________________________________*/


/*_____ D E C L A R A T I O N S ____________________________________________*/
void GPIO_Init (void);
void GPIO_Mode(uint32_t port_number, uint32_t pin_number, uint32_t mode);
void GPIO_Set(uint32_t port_number, uint32_t pin_number);
void GPIO_Clr(uint32_t port_number, uint32_t pin_number);
void GPIO_P0Trigger(uint32_t pin_number, uint32_t is, uint32_t ibs,uint32_t iev);
void GPIO_P1Trigger(uint32_t pin_number, uint32_t is, uint32_t ibs,uint32_t iev);
void GPIO_P2Trigger(uint32_t pin_number, uint32_t is, uint32_t ibs,uint32_t iev);
void GPIO_P3Trigger(uint32_t pin_number, uint32_t is, uint32_t ibs,uint32_t iev);
void GPIO_Interrupt(uint32_t port_number, uint32_t pin_number, uint32_t enable);
void GPIO_IntClr(uint32_t port_number, uint32_t pin_number);
void GPIO_Config(uint32_t port_number, uint32_t pin_number, uint32_t value);
void GPIO_OpenDrain(uint32_t port_number, uint32_t pin_number, uint32_t value);
uint32_t GPIO_IntStatus(uint32_t port_number, uint32_t pin_number);
#endif	/*__SN32F240_GPIO_H*/

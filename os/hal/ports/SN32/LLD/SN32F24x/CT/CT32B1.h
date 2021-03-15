#ifndef __SN32F240_CT32B1_H
#define __SN32F240_CT32B1_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdint.h>
#include <SN32F200_Def.h>


/*_____ D E F I N I T I O N S ______________________________________________*/
#define	CT32B1_IRQ	INTERRUPT_METHOD		//INTERRUPT_METHOD:	Enable CT32B1 timer and interrupt
																				//POLLING_METHOD: 	Enable CT32B1 timer ONLY

/*_____ M A C R O S ________________________________________________________*/
				// Enable CT32B1 PCLK
#define __CT32B1_ENABLE			SN_SYS1->AHBCLKEN_b.CT32B1CLKEN = ENABLE		
				// Disable CT32B1 PCLK
#define __CT32B1_DISABLE		SN_SYS1->AHBCLKEN_b.CT32B1CLKEN = DISABLE

/*_____ D E C L A R A T I O N S ____________________________________________*/
extern volatile uint32_t iwCT32B1_IrqEvent; //The bitmask usage of iwCT32Bn_IrqEvent is the same with CT32Bn_RIS

extern void CT32B1_Init(void);
extern void CT32B1_NvicEnable(void);
extern void CT32B1_NvicDisable(void);
extern void CT32B1_IRQHandler(void);
#endif	/*__SN32F240_CT32B1_H*/

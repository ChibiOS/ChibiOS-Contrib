#ifndef __SN32F240_CT16B0_H
#define __SN32F240_CT16B0_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdint.h>
#include <SN32F200_Def.h>


/*_____ D E F I N I T I O N S ______________________________________________*/
#define	CT16B0_IRQ	INTERRUPT_METHOD		//INTERRUPT_METHOD:	Enable CT16B0 timer and interrupt
																				//POLLING_METHOD: 	Enable CT16B0 timer ONLY

/*_____ M A C R O S ________________________________________________________*/
				// Enable CT16B0 PCLK
#define __CT16B0_ENABLE			SN_SYS1->AHBCLKEN_b.CT16B0CLKEN = ENABLE		
				// Disable CT16B0 PCLK
#define __CT16B0_DISABLE		SN_SYS1->AHBCLKEN_b.CT16B0CLKEN = DISABLE	

/*_____ D E C L A R A T I O N S ____________________________________________*/
extern volatile uint32_t iwCT16B0_IrqEvent; //The bitmask usage of iwCT16Bn_IrqEvent is the same with CT16Bn_RIS

extern void CT16B0_Init(void);
extern void CT16B0_NvicEnable(void);
extern void CT16B0_NvicDisable(void);
extern void CT16B0_IRQHandler(void);
#endif	/*__SN32F240_CT16B0_H*/

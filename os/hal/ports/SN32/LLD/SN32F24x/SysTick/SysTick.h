#ifndef __SN32F240_SYSTICK_H
#define __SN32F240_SYSTICK_H


/*_____ I N C L U D E S ____________________________________________________*/
#include <SN32F240.h>
#include <SN32F200_Def.h>


/*_____ D E F I N I T I O N S ______________________________________________*/
#define	SYSTICK_IRQ		POLLING_METHOD			//INTERRUPT_METHOD:	Enable SysTick timer and interrupt
																					//POLLING_METHOD: 	Enable SysTick timer ONLY

/*_____ M A C R O S ________________________________________________________*/
#define	__SYSTICK_SET_TIMER_PERIOD(ms)		SysTick->LOAD = SystemCoreClock * ms /1000 - 1
#define	__SYSTICK_CLEAR_COUNTER_AND_FLAG	SysTick->VAL = 0xFF



/*_____ D E C L A R A T I O N S ____________________________________________*/
void SysTick_Init(void);

#endif	/*__SN32F240_SYSTICK_H*/

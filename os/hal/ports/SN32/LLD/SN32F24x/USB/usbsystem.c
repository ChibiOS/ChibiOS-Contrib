/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbsystem.c
 * Purpose: USB Custom User Module
 * Version: V1.01
 * Date:		2013/12
 *------------------------------------------------------------------------------*/
#include	<SN32F240.h>
//#include	"type.h"
//#include	"..\Utility\Utility.h"

#include	"usbsystem.h"


void USB_SystemInit (void)
{

	SN_FLASH->LPCTRL = 0x5AFA0000;		//Disable Slow mode power saving

//***********************************	
#if (USB_SYS_CLOCK_SETUP)

	#if (USB_SYS0_CLKCFG_VAL == USB_IHRC)			//IHRC
	SN_SYS0->ANBCTRL |= USB_IHRC_EN;					//enable IHRC
	while ((SN_SYS0->CSST & 0x01) != 0x01);		//check IHRC ready
	SN_SYS0->CLKCFG = 0x00;								//switch IHRC	
	while ((SN_SYS0->CLKCFG & 0x70) != 0x00);
	#endif

	#if (USB_SYS0_CLKCFG_VAL == USB_ILRC)			//ILRC
	SN_SYS0->CLKCFG = 0x1;
  while ((SN_SYS0->CLKCFG & 0x70) != 0x10);		//switch ILRC
	#endif

	#if (USB_SYS0_CLKCFG_VAL == USB_EHSXTAL)	//EHS XTAL
	#if (USB_EHS_FREQ > 12)				
	SN_SYS0->ANBCTRL |= (1<<5);		//Enable XTAL > 12MHz
	#else
	SN_SYS0->ANBCTRL &=~(1<<5);		//Enable XTAL <= 12MHz
	#endif

	SN_SYS0->ANBCTRL |= (1<<4);		//Enable XTAL
	while ((SN_SYS0->CSST & 0x10) != 0x10);
	SN_SYS0->CLKCFG = 0x02;								//switch XTAL	
	while ((SN_SYS0->CLKCFG & 0x70) != 0X20);
	#endif 
#endif

	#if (USB_PLL_ENABLE == 0x01)		//SET PLL
	SN_SYS0->PLLCTRL = USB_SYS0_PLLCTRL_EN;			//ENABLE PLL 
	if(USB_PLL_CLKIN == 0x0)		//PLL clk source is IHRC
	{
		SN_SYS0->ANBCTRL |= USB_IHRC_EN;					//enable IHRC
		SN_SYS0->PLLCTRL |= USB_PLL_CLKSOURCE_IHRC;
	}
	else	//PLL clk source is XTAL
	{

	#if (USB_EHS_FREQ > 12)				
	SN_SYS0->ANBCTRL |= (1<<5);		//Enable XTAL > 12MHz
	#else
	SN_SYS0->ANBCTRL &=~(1<<5);		//Enable XTAL <= 12MHz
	#endif

	SN_SYS0->ANBCTRL |= (1<<4);		//Enable XTAL
	while ((SN_SYS0->CSST & 0x10) != 0x10);



		#if (USB_EHS_FREQ == 12)							//XTAL = 12MHz
		//SN_SYS0->ANBCTRL |= (1<<5);					//Enable XTAL < 12MHz
		SN_SYS0->PLLCTRL |= USB_PLL_CLKSOURCE_12MHz;
		#endif

		#if (USB_EHS_FREQ == 16)						//XTAL = 16MHz
		SN_SYS0->ANBCTRL |=(1<<5);					//Enable XTAL > 12MHz
		SN_SYS0->PLLCTRL |= USB_PLL_CLKSOURCE_16MHz;
		#endif

		#if (USB_EHS_FREQ == 24)						//XTAL = 24MHz
		SN_SYS0->ANBCTRL |=(1<<5); 				//Enable XTAL > 12MHz
		SN_SYS0->PLLCTRL |= USB_PLL_CLKSOURCE_24MHz;
		#endif
		SN_SYS0->ANBCTRL |= (1<<4);		//Enable EHS XTAL
		while ((SN_SYS0->CSST & 0x10) != 0x10);

		#if (USB_PLL_CLKIN == 0x01 )
			SN_SYS0->PLLCTRL |= (0x01<<12);
			SN_SYS0->PLLCTRL |= (0x01<<15);			//ENABLE PLL 
		#endif	
	}
	#endif

	#if (USB_SYS0_CLKCFG_VAL == USB_PLL)
	{
		while ((SN_SYS0->CSST & 0x40) != 0x40);
    SN_SYS0->CLKCFG = 0x4;					   //CLK switch PLL 
		while ((SN_SYS0->CLKCFG & 0x70) != 0x40);
	}	
	#endif
	SN_SYS0->AHBCP = USB_AHB_PRESCALAR;
	#if (USB_CLKOUT_SEL_VAL > 0)			//CLKOUT
	SN_SYS1->AHBCLKEN |= (USB_CLKOUT_SEL_VAL<<28);
	#endif	
}
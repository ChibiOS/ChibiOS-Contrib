/******************** (C) COPYRIGHT 2017 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2017/07
* AUTHOR:				SA1
* IC:						SN32F240B
* DESCRIPTION:	PMU related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
*	1.0				2017/07/07	SA1			1. First release
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/
#include <SN32F2xx.h>


/*_____ D E C L A R A T I O N S ____________________________________________*/


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/***************************************************************************************************
* Function		: PMU_Setting
* Description	: Setting and enter specified Low power mode
* Input				: mode - specified Low power mode (PMU_SLEEP, PMU_DEEP_SLEEP, PMU_DEEP_PWR_DOWN)
* Output			: None
* Return			: None
* Note				: None
****************************************************************************************************/
void PMU_Setting(uint16_t mode)
{

	SN_PMU->CTRL = mode;

	__WFI();

	SN_PMU->CTRL = 0x0;
}

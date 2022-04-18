/******************** (C) COPYRIGHT 2013 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2013/12
* AUTHOR:				SA1
* IC:						SN32F240/230/220
* DESCRIPTION:	Flash related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2013/12/17	SA1			First release
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
#include "Flash.h"


/*_____ D E C L A R A T I O N S ____________________________________________*/
uint32_t wFLASH_PGRAM[2];


/*_____ D E F I N I T I O N S ______________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: FLASH_EraseSector
* Description	: Erase assigned sector address in Flash ROM
* Input			: adr - Sector start address
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void FLASH_EraseSector (uint32_t adr)
{
 	SN_FLASH->CTRL = FLASH_PER;					// Page Erase Enabled
	SN_FLASH->ADDR = adr;									// Page Address  
	SN_FLASH->CTRL |= FLASH_STARTE;				// Start Erase

	while ((SN_FLASH->STATUS & FLASH_BUSY) == FLASH_BUSY);
}


/*****************************************************************************
* Function		: Flash_ProgramPage
* Description	: Program assigned page in Flash ROM
* Input			: adr - Page start address (word-alignment) of Flash
*				  		sz - Content size to be programmed (Bytes)
*				  		pBuf - pointer to the Source data
* Output		: None
* Return		: OK or FAIL
* Note			: None
*****************************************************************************/
uint32_t FLASH_ProgramPage (uint32_t adr, uint32_t sz, uint8_t *pBuf)
{
	while (sz){

		SN_FLASH->CTRL = FLASH_PG;													// Programming Enabled
		SN_FLASH->ADDR = adr;
		SN_FLASH->DATA = *((uint32_t *)pBuf);

		__nop();__nop();__nop();__nop();__nop();__nop();    //Must add to avoid Hard Fault!!!!!!

		while ((SN_FLASH->STATUS & FLASH_BUSY) == FLASH_BUSY);

		// Check for Errors
		if ((SN_FLASH->STATUS & FLASH_PGERR) == FLASH_PGERR) {
			SN_FLASH->STATUS &= ~FLASH_PGERR;
			return (FAIL);
		}

		// Go to next Word
		adr += 4;
		pBuf += 4;
		sz  -= 4;
	}

	return (OK);
}


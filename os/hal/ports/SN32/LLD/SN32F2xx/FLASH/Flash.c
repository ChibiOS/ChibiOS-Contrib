/******************** (C) COPYRIGHT 2017 SONiX *******************************
* COMPANY:			SONiX
* DATE:					2017/07
* AUTHOR:				SA1
* IC:						SN32F240B
* DESCRIPTION:	Flash related functions.
*____________________________________________________________________________
* REVISION	Date				User		Description
* 1.0				2017/07/07	SA1			First release
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

/*_____ D E F I N I T I O N S ______________________________________________*/
#define SN32_JUMPLOADER_SIZE 0x200

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
FLASH_Status FLASH_EraseSector (uint32_t adr)
{
    // never touch the jumploader
    if (adr < SN32_JUMPLOADER_SIZE) return FLASH_FAIL;

 	SN_FLASH->CTRL = FLASH_PER;						// Page Erase Enabled
	SN_FLASH->ADDR = adr;									// Page Address

	FLASH_WAIT_FOR_DONE
	
	SN_FLASH->CTRL |= FLASH_START;				// Start Erase

	FLASH_WAIT_FOR_DONE

	return (FLASH_OKAY);
}


/*****************************************************************************
* Function		: Flash_ProgramPage
* Description	: Program assigned page in Flash ROM
* Input			: adr - Page start address (word-alignment) of Flash
*				  		sz - Content size to be programmed (Bytes)
*				  		Data - the Source data
* Output		: None
* Return		: FLASH_OKAY or FLASH_FAIL
* Note			: None
*****************************************************************************/
FLASH_Status FLASH_ProgramPage (uint32_t adr, uint32_t sz, uint32_t Data)
{
    // never touch the jumploader
    if (adr < SN32_JUMPLOADER_SIZE) return FLASH_FAIL;

	SN_FLASH->CTRL = FLASH_PG;                  // Programming Enabled
	SN_FLASH->ADDR = adr;

	FLASH_WAIT_FOR_DONE
	
	*(uint32_t*)adr = Data;
	
	while (sz) {

		SN_FLASH->DATA = Data;

		FLASH_WAIT_FOR_DONE

		// Go to next Word
		adr += 4;
		sz  -= 4;
	}
	
	// Check for Errors
	if ((SN_FLASH->STATUS & FLASH_ERR) == FLASH_ERR) {
		SN_FLASH->STATUS = 0;
		return (FLASH_FAIL);
	}

	SN_FLASH->CTRL |= FLASH_START;				// Start Program

	FLASH_WAIT_FOR_DONE

	// Check for Errors
	if ((SN_FLASH->STATUS & FLASH_ERR) == FLASH_ERR) {
		SN_FLASH->STATUS = 0;
		return (FLASH_FAIL);
	}

	return (FLASH_OKAY);
}

/*****************************************************************************
* Function		: FLASH_ProgramWord
* Description	: Program a word at a specified address
* Input			: adr - Page start address (word-alignment) of Flash
*				  		Data - the Source data
* Output		: None
* Return		: FLASH_OKAY or FLASH_ERR
* Note			: None
*****************************************************************************/
FLASH_Status FLASH_ProgramDWord(uint32_t adr, uint32_t Data) {
    FLASH_Status status = FLASH_ProgramPage(adr, 4, Data);

    return status;
}

/*****************************************************************************
* Function		: FLASH_Checksum
* Description	: Calculate Checksum in Flash ROM
* Input			: None
* Output		: Checksum of User ROM
* Return		: None
* Note			: None
*****************************************************************************/
uint16_t FLASH_Checksum (void)
{
 	SN_FLASH->CTRL = FLASH_CHK;

	FLASH_WAIT_FOR_DONE
	
	return	(uint16_t) (SN_FLASH->CHKSUM);
}

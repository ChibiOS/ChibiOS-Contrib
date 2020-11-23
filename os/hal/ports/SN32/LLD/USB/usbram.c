/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbram.c
 * Purpose: USB Custom User Module
 * Version: V1.01
 * Date:		2017/07
 *------------------------------------------------------------------------------*/
#include	<SN32F240B.h>
#include	"usbram.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/
/*_____________ USB Variable ____________________________________________*/
volatile	uint32_t	wUSB_EPnOffset[4];
volatile	uint32_t	wUSB_EPnPacketsize[5];
volatile	uint8_t		wUSB_EndpHalt[5];
const	uint8_t	*pUSB_TableIndex;
volatile	uint32_t	wUSB_TableLength;
volatile	uint8_t	wUSB_IfAlternateSet[4];
uint8_t		bNDT_Flag;
uint16_t	dbNDT_Cnt;
uint32_t	wUSB_PreTableLength;

uint16_t	mode;
uint32_t	cnt;


SUSB_EUME_DATA	sUSB_EumeData;

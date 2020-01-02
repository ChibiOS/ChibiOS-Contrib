/*----------------------------------------------------------------------------
 *      U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    usbuser.h
 * Purpose: USB Custom User Definitions
 * Version: V1.20
 *----------------------------------------------------------------------------
 *---------------------------------------------------------------------------*/

#ifndef __HIDRAM_H__
#define __HIDRAM_H__


typedef struct
{
	volatile uint8_t	wHID_SetRptByte[16];
	volatile uint8_t	wHID_IdleTimeIf0ID;
	volatile uint8_t	wHID_Protocol;
	volatile uint8_t	wHID_SetReportFeature;
	volatile uint32_t	wHID_Setreportfeature[16];
	volatile uint32_t	wHID_Status;
}S_HID_DATA;

extern S_HID_DATA	sHID_Data;

/*_____ D E C L A R A T I O N S ____________________________________________*/



#endif  /* __HIDRAM_H__ */

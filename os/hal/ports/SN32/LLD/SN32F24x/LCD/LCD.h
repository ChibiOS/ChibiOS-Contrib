#ifndef __SN32F240_LCD_H
#define __SN32F240_LCD_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <SN32F240.h>
#include <SN32F200_Def.h>


/*_____ D E F I N I T I O N S ______________________________________________*/
#define	LCD_TYPE		LCD_R_TYPE			//LCD_R_TYPE, LCD_1C_TYPE, or LCD_4C_TYPE

//LCD Panel driving ability
#define	LCD_DRIVEP_STRONG				0
#define	LCD_DRIVEP_MEDIUM				1
#define	LCD_DRIVEP_LOW					3
#define	mskLCD_DRIVEP_STRONG		(LCD_DRIVEP_STRONG<<28)
#define	mskLCD_DRIVEP_MEDIUM		(LCD_DRIVEP_MEDIUM<<28)
#define	mskLCD_DRIVEP_LOW				(LCD_DRIVEP_LOW<<28)

//LCD_PCLK rate
#define	LCD_RATE_DIV64					0
#define	LCD_RATE_DIV128					1
#define	mskLCD_RATE_DIV64				(LCD_RATE_DIV64<<11)
#define	mskLCD_RATE_DIV128			(LCD_RATE_DIV128<<11)

//LCD Clock source
#define LCD_CLOCK_ILRC					0
#define LCD_CLOCK_ELS						1
#define mskLCD_CLOCK_ILRC				(LCD_CLOCK_ILRC<<10)
#define mskLCD_CLOCK_ELS				(LCD_CLOCK_ELS<<10)

//LCD Duty
#define	LCD_HALF_DUTY						1						// 1/2 duty
#define	LCD_ONE_THIRD_DUTY			2						// 1/3 duty
#define	LCD_ONE_FOURTH_DUTY			3						// 1/4 duty
#define mskLCD_HALF_DUTY				(LCD_HALF_DUTY<<8)
#define mskLCD_ONE_THIRD_DUTY		(LCD_ONE_THIRD_DUTY<<8)
#define mskLCD_ONE_FOURTH_DUTY	(LCD_ONE_FOURTH_DUTY<<8)

//LCD Bias
#define	LCD_ONE_THIRD_BIAS			0						// 1/3 bias
#define	LCD_HALF_BIAS						1						// 1/2 bias
#define mskLCD_ONE_THIRD_BIAS		(LCD_ONE_THIRD_BIAS<<4)
#define mskLCD_HALF_BIAS				(LCD_HALF_BIAS<<4)

//LCD Type
#define	LCD_R_TYPE							0
#define	LCD_4C_TYPE							1
#define	LCD_1C_TYPE							2
#define mskLCD_R_TYPE						(LCD_R_TYPE<<2)
#define mskLCD_4C_TYPE					(LCD_4C_TYPE<<2)
#define mskLCD_1C_TYPE					(LCD_1C_TYPE<<2)

//LCD R-type resistance
#define	LCD_REF_400K						0
#define	LCD_REF_200K						1
#define	LCD_REF_100K						2
#define	LCD_REF_35K							3
#define mskLCD_REF_400K					(LCD_REF_400K<<1)
#define mskLCD_REF_200K					(LCD_REF_200K<<1)
#define mskLCD_REF_100K					(LCD_REF_100K<<1)
#define mskLCD_REF_35K					(LCD_REF_35K<<1)

//LCD 1C-type VCP
#define	mskLCD_1C_VCP_2P7V			0
#define	mskLCD_1C_VCP_2P8V			1
#define	mskLCD_1C_VCP_2P9V			2
#define	mskLCD_1C_VCP_3P0V			3
#define	mskLCD_1C_VCP_3P1V			4
#define	mskLCD_1C_VCP_3P2V			5
#define	mskLCD_1C_VCP_3P3V			6
#define	mskLCD_1C_VCP_3P4V			7

//LCD 4C-type VCP
#define	mskLCD_4C_VCP_2P7V			0
#define	mskLCD_4C_VCP_2P8V			1
#define	mskLCD_4C_VCP_2P9V			2
#define	mskLCD_4C_VCP_3P0V			3
#define	mskLCD_4C_VCP_3P06V			4
#define	mskLCD_4C_VCP_3P14V			5
#define	mskLCD_4C_VCP_3P2V			6
#define	mskLCD_4C_VCP_3P3V			7
#define	mskLCD_4C_VCP_3P4V			8
#define	mskLCD_4C_VCP_3P6V			9
#define	mskLCD_4C_VCP_3P8V			10
#define	mskLCD_4C_VCP_4P0V			11
#define	mskLCD_4C_VCP_4P2V			12
#define	mskLCD_4C_VCP_4P4V			13
#define	mskLCD_4C_VCP_4P7V			14
#define	mskLCD_4C_VCP_5P0V			15

//LCD Frame Interrupt Enable/Disable
#define LCD_FRAME_IE_ENABLE			1
#define LCD_FRAME_IE_DISABLE		0
#define	mskLCD_FRAME_IE_ENABLE	(LCD_FRAME_IE_ENABLE<<7)
#define	mskLCD_FRAME_IE_DISABLE	(LCD_FRAME_IE_DISABLE<<7)

//LCD Frame Counter Enable/Disable
#define LCD_FRAME_COUNTER_ENABLE			1
#define LCD_FRAME_COUNTER_DISABLE			0
#define	mskLCD_FRAME_COUNTER_ENABLE		LCD_FRAME_COUNTER_ENABLE
#define	mskLCD_FRAME_COUNTER_DISABLE	LCD_FRAME_COUNTER_DISABLE

//LCD Frame Counter Threshold
#define	LCD_FRAME_COUNTER_THRESHOLD		31		//0 < LCD_FRAME_COUNTER_THRESHOLD < 32


/*_____ M A C R O S ________________________________________________________*/

//LCD HCLK Enable/Disable
#define	__LCD_ENABLE_LCDHCLK					SN_SYS1->AHBCLKEN |= (1<<2)
#define	__LCD_DISABLE_LCDHCLK					SN_SYS1->AHBCLKEN &= ~(1<<2)

//LCD Driver Enable/Disable
#define	__LCD_ENABLE									SN_LCD->CTRL |= 0x1
#define	__LCD_DISENABLE								SN_LCD->CTRL &= ~0x1

//LCD SEGMENT Group 2 Enable/Disable
#define __LCD_SEGMENT_GROUP2_ENABLE		SN_LCD->CTRL_b.SEGSEL2 = ENABLE
#define __LCD_SEGMENT_GROUP2_DISABLE	SN_LCD->CTRL_b.SEGSEL2 = DISABLE

//LCD SEGMENT Group 1 Enable/Disable
#define __LCD_SEGMENT_GROUP1_ENABLE		SN_LCD->CTRL_b.SEGSEL1 = ENABLE
#define __LCD_SEGMENT_GROUP1_DISABLE	SN_LCD->CTRL_b.SEGSEL1 = DISABLE

//LCD Blank mode Enable/Disable
#define	__LCD_DISPLAY_BLANK_ENABLE		SN_LCD->CTRL1_b.LCDBNK = ENABLE
#define	__LCD_DISPLAY_BLANK_DISABLE		SN_LCD->CTRL1_b.LCDBNK = DISABLE


/*_____ D E C L A R A T I O N S ____________________________________________*/

void LCD_RtypeInit(void);
void LCD_1CtypeInit(void);
void LCD_4CtypeInit(void);
void LCD_SelectClockSource(uint32_t src);
void LCD_SetFrameCounterInterrupt(uint32_t CEN, uint32_t FCT, uint32_t IE);


#endif	/*__SN32F760_PMU_H*/

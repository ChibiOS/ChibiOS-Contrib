#ifndef __SN32F2XX_ADC_H
#define __SN32F2XX_ADC_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <SN32F2xx.h>

/*_____ D E F I N I T I O N S ______________________________________________*/
//ADC Internal Reference Voltage level
#define	ADC_VHS_INTERNAL_2V			0
#define	ADC_VHS_INTERNAL_3V			1
#define	ADC_VHS_INTERNAL_4P5V		2
#define	ADC_VHS_VDD							7

//ADC high reference voltage source select bit
#define ADC_AVREFHSEL_INTERNAL	0x0
#define ADC_AVREFHSEL_EXTERNAL	0x1

//ADC Enable bit
#define ADC_ADENB_DIS						0x0
#define ADC_ADENB_EN						0x1

//ADC Clock source divider
#define ADC_ADCKS_DIV1					0x0
#define ADC_ADCKS_DIV2					0x1
#define ADC_ADCKS_DIV4					0x2
#define ADC_ADCKS_DIV8					0x3
#define ADC_ADCKS_DIV16					0x5
#define ADC_ADCKS_DIV32					0x6

//ADC resolution control bit
#define ADC_ADLEN_8BIT					0x0
#define ADC_ADLEN_12BIT					0x1

//ADC start control bit
#define	ADC_ADS_STOP						0x0
#define	ADC_ADS_START						0x1

//ADC global channel select bit
#define ADC_GCHS_DIS						0x0
#define ADC_GCHS_EN							0x1

//ADC input channels select bit
#define ADC_CHS_AIN0						0x0					//P2.0
#define ADC_CHS_AIN1						0x1					//P2.1
#define ADC_CHS_AIN2						0x2					//P2.2
#define ADC_CHS_AIN3						0x3					//P2.3
#define ADC_CHS_AIN4						0x4					//P2.4
#define ADC_CHS_AIN5						0x5					//P2.5
#define ADC_CHS_AIN6						0x6					//P2.6
#define ADC_CHS_AIN7						0x7					//P2.7
#define ADC_CHS_AIN8						0x8					//P2.8
#define ADC_CHS_AIN9						0x9					//P2.9
#define ADC_CHS_AIN10						0xA					//P2.10
#define ADC_CHS_AIN11						0xB					//P2.11
#define ADC_CHS_AIN12						0xC					//P2.12
#define ADC_CHS_AIN13						0xD					//P2.13
#define ADC_CHS_AIN14						0xE					//P2.14
#define ADC_CHS_AIN15						0xF					//P2.15
#define ADC_CHS_AIN16						0x10				//Internal Ref. Voltage
#define ADC_CHS_AIN17						0x11				//VDD
#define ADC_CHS_AIN18						0x12				//VSS				

//ADC Interrupt Enable register(ADC_IE)
#define ADC_IE_AIN0							0x00001
#define ADC_IE_AIN1							0x00002
#define ADC_IE_AIN2							0x00004
#define ADC_IE_AIN3							0x00008
#define ADC_IE_AIN4							0x00010
#define ADC_IE_AIN5							0x00020
#define ADC_IE_AIN6							0x00040
#define ADC_IE_AIN7							0x00080
#define ADC_IE_AIN8							0x00100
#define ADC_IE_AIN9							0x00200
#define ADC_IE_AIN10						0x00400
#define ADC_IE_AIN11						0x00800
#define ADC_IE_AIN12						0x01000
#define ADC_IE_AIN13						0x02000
#define ADC_IE_AIN14						0x04000
#define ADC_IE_AIN15						0x08000
#define ADC_IE_AIN16						0x10000
#define ADC_IE_AIN17						0x20000
#define ADC_IE_AIN18						0x40000

//ADC Raw Interrupt Status register(ADC_RIS)
#define mskADC_IF_AIN0					(0x1<<0)		//P2.0
#define mskADC_IF_AIN1					(0x1<<1)		//P2.1
#define mskADC_IF_AIN2					(0x1<<2)		//P2.2
#define mskADC_IF_AIN3					(0x1<<3)		//P2.3
#define mskADC_IF_AIN4					(0x1<<4)		//P2.4
#define mskADC_IF_AIN5					(0x1<<5)		//P2.5
#define mskADC_IF_AIN6					(0x1<<6)		//P2.6
#define mskADC_IF_AIN7					(0x1<<7)		//P2.7
#define mskADC_IF_AIN8					(0x1<<8)		//P2.8
#define mskADC_IF_AIN9					(0x1<<9)		//P2.9
#define mskADC_IF_AIN10					(0x1<<10)		//P2.10
#define mskADC_IF_AIN11					(0x1<<11)		//P2.11
#define mskADC_IF_AIN12					(0x1<<12)		//P2.12
#define mskADC_IF_AIN13					(0x1<<13)		//P2.13
#define mskADC_IF_AIN14					(0x1<<14)		//P2.14
#define mskADC_IF_AIN15					(0x1<<15)		//P2.15
#define mskADC_IF_AIN16					(0x1<<16)		//Internal Ref. Voltage
#define mskADC_IF_AIN17					(0x1<<17)		//VDD
#define mskADC_IF_AIN18					(0x1<<18)		//VSS

/*_____ M A C R O S ________________________________________________________*/
											


/*_____ D E C L A R A T I O N S ____________________________________________*/
extern uint8_t	bADC_StartConv;

void	ADC_Init(void);
uint16_t ADC_Read(void);
void ADC_NvicEnable(void);
void ADC_NvicDisable(void);

#endif	/*__SN32F2XX_ADC_H*/

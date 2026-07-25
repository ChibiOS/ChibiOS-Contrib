/**************************************************************************//**
 * @file     lcd_reg.h
 * @version  V1.00
 * @brief    LCD register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2022 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __LCD_REG_H__
#define __LCD_REG_H__

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup LCD Liquid-Crystal Display(LCD)
    Memory Mapped Structure for LCD Controller
    @{
*/

typedef struct
{


    /**
     * @var LCD_T::CTL
     * Offset: 0x00  LCD Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EN        |LCD Display Enable Bit
     * |        |          |0 = LCD display function Disabled.
     * |        |          |1 = LCD display function Enabled.
     * |        |          |Note 1: When software writes 1 to this bit, the LCD Controller needs some synchronizing time to completely enable the LCD display function
     * |        |          |Before that, the read value of this bit is still 0.
     * |        |          |Note 2: When software writes 0 to this bit, the LCD Controller needs some synchronizing time to completely disable the LCD display function
     * |        |          |Before that, the read value of this bit is still 1.
     * |[31]    |SYNC      |LCD Enable/Disable Synchronizing Indicator (Read Only)
     * |        |          |When software writes 0/1 to EN bit (LCD_CTL[0]), the LCD Controller needs some synchronizing time to completely disable/enable the LCD display function
     * |        |          |During this time, this bit keeps at 1.
     * |        |          |0 = LCD display function is completely disabled/enabled.
     * |        |          |1 = LCD display function is not yet completely disabled/enabled.
     * |        |          |Note 1: The synchronizing time to enable LCD display function is not constant
     * |        |          |It is between one and two cycles of CLKLCD.
     * |        |          |Note 2: The LCD display function cannot be disabled until the end of a frame
     * |        |          |So the maximum synchronizing time to disable LCD display function could be as long as one frame time.
     * @var LCD_T::PSET
     * Offset: 0x04  LCD Panel Setting Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |BIAS      |LCD Bias Level Selection
     * |        |          |This field is used to select the bias level.
     * |        |          |0 = Reserved.
     * |        |          |1 = 1/2 Bias.
     * |        |          |2 = 1/3 Bias.
     * |        |          |3 = 1/4 Bias.
     * |[4:2]   |DUTY      |LCD Duty Ratio Selection
     * |        |          |This field is used to select the duty ratio.
     * |        |          |0 = 1/1 Duty.
     * |        |          |1 = 1/2 Duty.
     * |        |          |2 = 1/3 Duty.
     * |        |          |3 = 1/4 Duty.
     * |        |          |4 = 1/5 Duty.
     * |        |          |5 = 1/6 Duty.
     * |        |          |6 = 1/7 Duty.
     * |        |          |7 = 1/8 Duty.
     * |[5]     |TYPE      |LCD Waveform Type Selection
     * |        |          |This bit is used to select the waveform type.
     * |        |          |0 = Type A.
     * |        |          |1 = Type B.
     * |[6]     |INV       |LCD Waveform Inverse
     * |        |          |This bit is used to set the inverse LCD waveform.
     * |        |          |0 = COM/SEG waveform is normal.
     * |        |          |1 = COM/SEG waveform is inverse.
     * |[17:8]  |FREQDIV   |LCD Operating Frequency (FLCD) Divider
     * |        |          |The field is used to divide CLKLCD to generate the LCD operating frequency.
     * |        |          |LCD Operating Frequency = (CLKLCD Frequency) / (FREQDIV + 1).
     * |        |          |Note 1: FREQDIV can be set from 0 to 1023, therefore,
     * |        |          |the fastest LCD operating frequency is equal to CLKLCD frequency, and
     * |        |          |the lowest LCD operating frequency is equal to CLKLCD frequency divided by 1024.
     * |        |          |Note 2: LCD frame rate is
     * |        |          |(LCD Operating Frequency) x (Duty Ratio) x 1/2 for type A waveform, and
     * |        |          |(LCD Operating Frequency) x (Duty Ratio) for type B waveform.
     * |        |          |Example: Assuming the LCD operating frequency is 1 kHz, duty ratio is 1/4, then the LCD frame rate is
     * |        |          |1 kHz x (1/4) x (1/2) = 125 Hz for type A waveform, and.
     * |        |          |1 kHz x (1/4) = 250 Hz for type B waveform.
     * |[21:18] |VSEL      |LCD Operating Voltage (VLCD) Select
     * |        |          |This field is used to select the LCD operating voltage. (For Charge Pump Only)
     * |        |          |0 = 3.0 V.
     * |        |          |1 = 3.2 V.
     * |        |          |2 = 3.4 V.
     * |        |          |3 = 3.6 V.
     * |        |          |4 = 3.8 V.
     * |        |          |5 = 4.0 V.
     * |        |          |6 = 4.2 V.
     * |        |          |7 = 4.4 V.
     * |        |          |8 = 4.6 V.
     * |        |          |9 = 4.8 V.
     * |        |          |10 = 5.0 V.
     * |        |          |11 = 5.2 V.
     * |        |          |Others = (Reserved).
     * |        |          |Note: This field is meaningful only if the VLCD source is the charge pump
     * |        |          |Otherwise, this field is ignored.
     * |[27:24] |VTUNE     |LCD Operating Voltage (VLCD) Fine Tuning
     * |        |          |This field is used to fine tune the LCD operating voltage. (For Charge Pump Only)
     * |        |          |0 = No tuning.
     * |        |          |1 = decrease by 1 unit of voltage.
     * |        |          |2 = decrease by 2 units of voltage.
     * |        |          |3 = decrease by 3 units of voltage.
     * |        |          |...
     * |        |          |7 = decrease by 7 units of voltage.
     * |        |          |8 = increase by 8 units of voltage.
     * |        |          |9 = increase by 7 units of voltage.
     * |        |          |10 = increase by 6 units of voltage.
     * |        |          |...
     * |        |          |14 = increase by 2 units of voltage.
     * |        |          |15 = increase by 1 unit of voltage.
     * |        |          |Note 1: a unit of voltage is about 0.04 V.
     * |        |          |Note 2: This field is meaningful only if the VLCD source is the charge pump
     * |        |          |Otherwise, this field is ignored.
     * @var LCD_T::FSET
     * Offset: 0x08  LCD Frame Setting Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BLINK     |LCD Blinking Enable Bit
     * |        |          |0 = LCD blinking function Disabled.
     * |        |          |1 = LCD blinking function Enabled.
     * |[17:8]  |FCV       |Frame Counting Value
     * |        |          |This field indicates the maximum value that the frame counter can reach.
     * |        |          |Note 1: The frame counter automatically increases by 1 at the end of every frame
     * |        |          |When the counter reaches FCV, it will recounts from 0 at the end of the next frame
     * |        |          |At this moment, the hardware sets a dedicated flag to 1, and triggers a dedicated interrupt if it is enabled.
     * |        |          |Note 2: For type B waveform, the frame counter increases at the end of odd frames, not even frames.
     * |[19]    |PTYPE     |Pause Type
     * |        |          |To indicate when a pause duration occurs
     * |        |          |0 = In-Frame Pause.
     * |        |          |1 = In-Duty Pause.
     * |[23:20] |PTIME     |Pause Time
     * |        |          |To indicate how long a pause duration is
     * |        |          |0 = 0 Unit (No Pause).
     * |        |          |1 = 1 Unit.
     * |        |          |2 = 2 Units.
     * |        |          |3 = 3 Units.
     * |        |          |...
     * |        |          |15 = 15 Units.
     * |        |          |1 Unit is about 512 us for In-Frame pause type.
     * |        |          |1 Unit is about 32 us for In-Duty pause type.
     * @var LCD_T::DSET
     * Offset: 0x0C  LCD Driving Setting Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |VSRC      |LCD Operating Voltage (VLCD) Source
     * |        |          |0 = VLCD Power.
     * |        |          |1 = AVDD Power.
     * |        |          |2 = Built-In Charge Pump.
     * |        |          |3 = (None).
     * |        |          |Note: Whenever the LCD controller is disabled, all VLCD sources are automatically cut off.
     * |[2]     |RESMODE   |Resistive Network Driving Mode
     * |        |          |0 = High-Driving Disabled.
     * |        |          |1 = High-Driving Enabled.
     * |[3]     |BUFEN     |Voltage Buffer Enable Bit
     * |        |          |0 = Voltage Buffer Disabled.
     * |        |          |1 = Voltage Buffer Enabled.
     * |        |          |Note: When RES_MODE = 1, the voltage buffers are automatically disabled
     * |        |          |The setting of BUF_EN bit is ignored.
     * |[4]     |PSVEN     |Power Saving Mode Enable Bit
     * |        |          |0 = Power Saving Mode Disabled.
     * |        |          |1 = Power Saving Mode Enabled.
     * |        |          |Note: when RES_MODE = 0 and BUF_EN = 0, the output drivers consumes the least driving current
     * |        |          |In this case, the power saving mode is automatically disabled
     * |        |          |The setting of PSV_EN bit is ignored.
     * |[5]     |PSVREV    |Power Saving Timing Reverse
     * |        |          |0 = Timing of power saving is normal.
     * |        |          |1 = Timing of power saving is reversed.
     * |        |          |Note: When the timing is reversed,
     * |        |          |the original powe-saving period becomes no-power-saving, and
     * |        |          |the original no-power-saving period becomes power-saving.
     * |[11:8]  |PSVT1     |Power Saving Enable Time Setting
     * |        |          |The Enable Time of the power saving mode is calculated as
     * |        |          |Enable Time = 15.625 us x (PSV_T1 + 1),.
     * |        |          |where 15.625 us is the half-cycle time of CLKLCD, whose frequency is assumed to be 32 kHz.
     * |        |          |PSV_T1 can be set as 0, 1, 2, u2026, 15, so
     * |        |          |the minimum Enable Time is about 15.625 us, and
     * |        |          |the maximum Enable Time is about 15.625 x 16 = 250 us.
     * |        |          |Note: In the following two cases, the power saving mode is disabled
     * |        |          |The setting of PSV_T1 bits is ignored.
     * |        |          |1. SV_EN = 0.
     * |        |          |2. RES_MODE = 0 and BUF_EN = 0.
     * |[15:12] |PSVT2     |Power Saving On Time Setting
     * |        |          |The On Time of the power saving mode is calculated as
     * |        |          |On Time = 15.625 us x (PSV_T2 + 1.),
     * |        |          |where 15.625 us is the half-cycle time of CLKLCD, whose frequency is assumed to be 32 kHz.
     * |        |          |PSV_T2 can be set as 0, 1, 2, u2026, 15, so
     * |        |          |the minimum On Time is about 15.625 us, and
     * |        |          |the maximum On Time is about 15.625 x 16 = 250 us.
     * |        |          |Note: In the following two cases, the power saving mode is disabled
     * |        |          |The setting of PSV_T2 bits is ignored.
     * |        |          |1. SV_EN = 0.
     * |        |          |2. ES_MODE = 0 and BUF_EN = 0 (In this case, SV_EN is ignored).
     * |[28:16] |CTOUT     |Charging Timer TimeOut
     * |        |          |This field is used to specify the timeout value for the charging timer
     * |        |          |When the charging timer reaches this timeout value, a status bit or an interrupt will occur.
     * |        |          |The timeout is calculated by the following formula:
     * |        |          | Timeout = 31.25 us x (CTOUT + 1.),
     * |        |          |where 31.25 us is the cycle time of CLKLCD, whose frequency is assumed to be 32 kHz.
     * |        |          |CTOUT can be set as 0, 1, 2,u2026, 8191, so
     * |        |          |the minimum timeout is 31.25 us, and
     * |        |          |the maximum timeout is 31.25 x 8192 = 256 ms.
     * @var LCD_T::OSET
     * Offset: 0x10  LCD Output Setting Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SEL8      |LCD8 Output Select
     * |        |          |0 = LCD8 is SEG43.
     * |        |          |1 = LCD8 is COM4.
     * |[1]     |SEL9      |LCD9 Output Select
     * |        |          |0 = LCD9 is SEG42.
     * |        |          |1 = LCD9 is COM5.
     * |[2]     |SEL10     |LCD10 Output Select
     * |        |          |0 = LCD10 is SEG20.
     * |        |          |1 = LCD10 is COM0.
     * |[3]     |SEL11     |LCD11 Output Select
     * |        |          |0 = LCD11 is SEG19.
     * |        |          |1 = LCD11 is COM1.
     * |[4]     |SEL12     |LCD12 Output Select
     * |        |          |0 = LCD12 is SEG18.
     * |        |          |1 = LCD12 is COM2.
     * |[5]     |SEL13     |LCD13 Output Select
     * |        |          |0 = LCD13 is SEG17.
     * |        |          |1 = LCD13 is COM3.
     * |[6]     |SEL14     |LCD14 Output Select
     * |        |          |0 = LCD14 is SEG41.
     * |        |          |1 = LCD14 is COM6.
     * |[7]     |SEL15     |LCD15 Output Select
     * |        |          |0 = LCD15 is SEG40.
     * |        |          |1 = LCD15 is COM7.
     * |[8]     |SEL24     |LCD24 Output Select
     * |        |          |0 = LCD24 is SEG31.
     * |        |          |1 = LCD24 is COM4.
     * |[9]     |SEL25     |LCD25 Output Select
     * |        |          |0 = LCD25 is SEG30.
     * |        |          |1 = LCD25 is COM5.
     * |[10]    |SEL26     |LCD26 Output Select
     * |        |          |0 = LCD26 is SEG29.
     * |        |          |1 = LCD26 is COM6.
     * |[11]    |SEL27     |LCD27 Output Select
     * |        |          |0 = LCD27 is SEG28.
     * |        |          |1 = LCD27 is COM7.
     * |[12]    |SEL28     |LCD28 Output Select
     * |        |          |0 = LCD28 is SEG27.
     * |        |          |1 = LCD28 is COM2.
     * |[13]    |SEL29     |LCD29 Output Select
     * |        |          |0 = LCD29 is SEG26.
     * |        |          |1 = LCD29 is COM3.
     * |[15:14] |SEL35     |LCD35 Output Select
     * |        |          |00 = LCD35 is COM4.
     * |        |          |01 = LCD35 is SEG20.
     * |        |          |10 = LCD35 is SEG47.
     * |        |          |11 = Reserved.
     * |[17:16] |SEL36     |LCD36 Output Select
     * |        |          |00 = LCD36 is COM5.
     * |        |          |01 = LCD36 is SEG19.
     * |        |          |10 = LCD36 is SEG46.
     * |        |          |11 = Reserved.
     * |[19:18] |SEL37     |LCD37 Output Select
     * |        |          |00 = LCD37 is COM6.
     * |        |          |01 = LCD37 is SEG18.
     * |        |          |10 = LCD37 is SEG45.
     * |        |          |11 = Reserved.
     * |[21:20] |SEL38     |LCD38 Output Select
     * |        |          |00 = LCD38 is COM7.
     * |        |          |01 = LCD38 is SEG17.
     * |        |          |10 = LCD38 is SEG44.
     * |        |          |11 = Reserved.
     * |[22]    |SEL41     |LCD41 Output Select
     * |        |          |0 = LCD41 is SEG14.
     * |        |          |1 = LCD41 is COM0.
     * |[23]    |SEL42     |LCD42 Output Select
     * |        |          |0 = LCD42 is SEG13.
     * |        |          |1 = LCD42 is COM1.
     * |[24]    |SEL47     |LCD47 Output Select
     * |        |          |0 = LCD47 is SEG08.
     * |        |          |1 = LCD47 is LCD_V1.
     * |[25]    |SEL48     |LCD48 Output Select
     * |        |          |0 = LCD48 is SEG07.
     * |        |          |1 = LCD48 is LCD_V2.
     * |[26]    |SEL49     |LCD49 Output Select
     * |        |          |0 = LCD49 is SEG06.
     * |        |          |1 = LCD49 is LCD_V3.
     * @var LCD_T::STS
     * Offset: 0x14  LCD Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |FCEND     |End of Frame-Counting Flag
     * |        |          |This flag is automatically set by hardware at the end of a frame, and the frame counter value must be equal to FCV (LCD_FSET[17:8], Frame Counting Value).
     * |        |          |0 = End of Frame-Counting did not occur.
     * |        |          |1 = End of Frame-Counting occurred.
     * |        |          |Note 1: Software can clear this bit by writing 1 to it.
     * |        |          |Note 2: For type B waveform, this flag is set only at the end of an odd frame.
     * |[1]     |FEND      |End of Frame Flag
     * |        |          |This flag is automatically set by hardware at the end of a frame.
     * |        |          |0 = End of Frame did not occur.
     * |        |          |1 = End of Frame occurred.
     * |        |          |Note 1: Software can clear this bit by writing 1 to it.
     * |        |          |Note 2: For type B waveform, this flag is set only at the end of an odd frame.
     * |[2]     |CTOUT     |Charging Timeout Flag
     * |        |          |This flag is automatically set by hardware when the charging timer reaches the timeout value.
     * |        |          |0 = Charging Timeout did not occur.
     * |        |          |1 = Charging Timeout occurred.
     * |        |          |Note: Software can clear this bit by writing 1 to it.
     * |[28:16] |CTIME     |Charging Timer Value (Read Only)
     * |        |          |The field contains the value of the charging timer. It records the charging time of the charge pump.
     * |        |          |The charging timer stops counting when the charge pump stops charging or a timeout occurs
     * |        |          |At this moment, the hardware dumps the current charging timer value into this field.
     * |        |          |Charging Time = 31.25 us x (CTIME + 1), where 31.25 us is the cycle time of CLKLCD, whose frequency is assumed to be 32 kHz.
     * @var LCD_T::INTEN
     * Offset: 0x18  LCD Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |FCEND     |End of Frame-Counting Interrupt Enable Bit
     * |        |          |An interrupt occurs at the end of a frame, and the frame counter value must be equal to FCV (LCD_FSET[17:8], Frame Counting Value).
     * |        |          |0 = End of Frame-Counting Interrupt Disabled.
     * |        |          |1 = End of Frame-Counting Interrupt Enabled.
     * |        |          |Note: For type B waveform, the interrupt occurs only at the end of an odd frame.
     * |[1]     |FEND      |End of Frame Interrupt Enable Bit
     * |        |          |An interrupt occurs at the end of a frame.
     * |        |          |0 = End of Frame Interrupt Disabled.
     * |        |          |1 = End of Frame Interrupt Enabled.
     * |        |          |Note: For type B waveform, the interrupt occurs only at the end of an odd frame.
     * |[3]     |CTOUT     |Charging Timeout Interrupt Enable Bit
     * |        |          |An interrupt occurs when the charging timer reaches the timeout value.
     * |        |          |0 = Charging Timeout Interrupt Disabled.
     * |        |          |1 = Charging Timeout Interrupt Enabled.
     * @var LCD_T::DATA
     * Offset: 0x20  LCD Segment Display Data Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x24  LCD Segment Display Data Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x28  LCD Segment Display Data Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x2C  LCD Segment Display Data Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x30  LCD Segment Display Data Register 4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x34  LCD Segment Display Data Register 5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x38  LCD Segment Display Data Register 6
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x3C  LCD Segment Display Data Register 7
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x40  LCD Segment Display Data Register 8
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x44  LCD Segment Display Data Register 9
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x48  LCD Segment Display Data Register 10
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     * Offset: 0x4C  LCD Segment Display Data Register 11
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DD0       |Display Data of Segments S, where S is (4 x N) + 0, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD0 corresponds to SEG00, SEG04, SEG08, SEG12, SEG16, SEG20, SEG24, SEG28, SEG32, SEG36, SEG40, and SEG44.
     * |        |          |Note 2: Each bit, DD0[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD0 (= LCD_DATA07[7:0]) = 1001_0110.
     * |        |          |LCD_DATA07[7:0] corresponds to SEG28 (4 x 7 + 0 = 2.8)
     * |        |          |the pixel SEG28-COM0 is light (LCD_DATA07[0] = .0)
     * |        |          |the pixel SEG28-COM1 is dark (LCD_DATA07[1] = .1)
     * |        |          |the pixel SEG28-COM2 is dark (LCD_DATA07[2] = .1)
     * |        |          |the pixel SEG28-COM3 is light (LCD_DATA07[3] = .0)
     * |        |          |LCD_DATA07[7:4] are ignored, since COMs from 4 to 7 are not used.
     * |[15:8]  |DD1       |Display Data of Segments S, where S is (4 x N) + 1, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD1 corresponds to SEG01, SEG05, SEG09, SEG13, SEG17, SEG21, SEG25, SEG29, SEG33, SEG37, SEG41, and SEG45.
     * |        |          |Note 2: Each bit, DD1[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD1 (= LCD_DATA07[15:8]) = 1001_0110.
     * |        |          |LCD_DATA07[15:8] corresponds to SEG29 (4 x 7 + 1 = 2.9)
     * |        |          |the pixel SEG29-COM0 is light (LCD_DATA07[8] = .0)
     * |        |          |the pixel SEG29-COM1 is dark (LCD_DATA07[9] = .1)
     * |        |          |the pixel SEG29-COM2 is dark (LCD_DATA07[10] = .1)
     * |        |          |the pixel SEG29-COM3 is light (LCD_DATA07[11] = .0)
     * |        |          |LCD_DATA07[15:12] are ignored, since COMs from 4 to 7 are not used.
     * |[23:16] |DD2       |Display Data of Segments S, where S is (4 x N) + 2, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = the pixel is light.
     * |        |          |1 = the pixel is dark.
     * |        |          |Note 1: DD2 corresponds to SEG02, SEG06, SEG10, SEG14, SEG18, SEG22, SEG26, SEG30, SEG34, SEG38, SEG42, and SEG46.
     * |        |          |Note 2: Each bit, DD2[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD2 (= LCD_DATA07[23:16]) = 1001_0110.
     * |        |          |LCD_DATA07[23:16] corresponds to SEG30 (4 x 7 + 2 = 3.0)
     * |        |          |the pixel SEG30-COM0 is light (LCD_DATA07[16] = .0)
     * |        |          |the pixel SEG30-COM1 is dark (LCD_DATA07[17] = .1)
     * |        |          |the pixel SEG30-COM2 is dark (LCD_DATA07[18] = .1)
     * |        |          |the pixel SEG30-COM3 is light (LCD_DATA07[19] = .0)
     * |        |          |LCD_DATA07[23:20] are ignored, since COMs from 4 to 7 are not used.
     * |[31:24] |DD3       |Display Data of Segments S, where S is (4 x N) + 3, and N is 0, 1, 2, u2026, 11
     * |        |          |Each bit specifies the brightness of each pixel in a segment.
     * |        |          |0 = The pixel is light.
     * |        |          |1 = The pixel is dark.
     * |        |          |Note 1: DD3 corresponds to SEG03, SEG07, SEG11, SEG15, SEG19, SEG23, SEG27, SEG31, SEG35, SEG39, SEG43, and SEG47.
     * |        |          |Note 2: Each bit, DD3[n], corresponds to COMn, n = 0-7.
     * |        |          |[Example] Assuming 1/4 Duty, and DD3 (= LCD_DATA07[31:24]) = 1001_0110.
     * |        |          |LCD_DATA07[31:24] corresponds to SEG31 (4 x 7 + 3 = 3.1)
     * |        |          |the pixel SEG31-COM0 is light (LCD_DATA07[24] = .0)
     * |        |          |the pixel SEG31-COM1 is dark (LCD_DATA07[25] = .1)
     * |        |          |the pixel SEG31-COM2 is dark (LCD_DATA07[26] = .1)
     * |        |          |the pixel SEG31-COM3 is light (LCD_DATA07[27] = .0)
     * |        |          |LCD_DATA07[31:28] are ignored, since COMs from 4 to 7 are not used.
     */

    __IO uint32_t CTL;                   /*!< [0x0000] LCD Control Register                                             */
    __IO uint32_t PSET;                  /*!< [0x0004] LCD Panel Setting Register                                       */
    __IO uint32_t FSET;                  /*!< [0x0008] LCD Frame Setting Register                                       */
    __IO uint32_t DSET;                  /*!< [0x000c] LCD Driving Setting Register                                     */
    __IO uint32_t OSET;                  /*!< [0x0010] LCD Output Setting Register                                      */
    __IO uint32_t STS;                   /*!< [0x0014] LCD Status Register                                              */
    __IO uint32_t INTEN;                 /*!< [0x0018] LCD Interrupt Enable Register                                    */
    __I  uint32_t RESERVE0;
    __IO uint32_t DATA[12];              /*!< [0x0020- 0x004C] LCD Segment Display Data Register 0-11                   */

} LCD_T;

/**
    @addtogroup LCD_CONST LCD Bit Field Definition
    Constant Definitions for LCD Controller
@{ */

#define LCD_CTL_EN_Pos                   (0)                                               /*!< LCD_T::CTL: EN Position                */
#define LCD_CTL_EN_Msk                   (0x1ul << LCD_CTL_EN_Pos)                         /*!< LCD_T::CTL: EN Mask                    */

#define LCD_CTL_SYNC_Pos                 (31)                                              /*!< LCD_T::CTL: SYNC Position              */
#define LCD_CTL_SYNC_Msk                 (0x1ul << LCD_CTL_SYNC_Pos)                       /*!< LCD_T::CTL: SYNC Mask                  */

#define LCD_PSET_BIAS_Pos                (0)                                               /*!< LCD_T::PSET: BIAS Position             */
#define LCD_PSET_BIAS_Msk                (0x3ul << LCD_PSET_BIAS_Pos)                      /*!< LCD_T::PSET: BIAS Mask                 */

#define LCD_PSET_DUTY_Pos                (2)                                               /*!< LCD_T::PSET: DUTY Position             */
#define LCD_PSET_DUTY_Msk                (0x7ul << LCD_PSET_DUTY_Pos)                      /*!< LCD_T::PSET: DUTY Mask                 */

#define LCD_PSET_TYPE_Pos                (5)                                               /*!< LCD_T::PSET: TYPE Position             */
#define LCD_PSET_TYPE_Msk                (0x1ul << LCD_PSET_TYPE_Pos)                      /*!< LCD_T::PSET: TYPE Mask                 */

#define LCD_PSET_INV_Pos                 (6)                                               /*!< LCD_T::PSET: INV Position              */
#define LCD_PSET_INV_Msk                 (0x1ul << LCD_PSET_INV_Pos)                       /*!< LCD_T::PSET: INV Mask                  */

#define LCD_PSET_FREQDIV_Pos             (8)                                               /*!< LCD_T::PSET: FREQDIV Position          */
#define LCD_PSET_FREQDIV_Msk             (0x3fful << LCD_PSET_FREQDIV_Pos)                 /*!< LCD_T::PSET: FREQDIV Mask              */

#define LCD_PSET_VSEL_Pos                (18)                                              /*!< LCD_T::PSET: VSEL Position             */
#define LCD_PSET_VSEL_Msk                (0xful << LCD_PSET_VSEL_Pos)                      /*!< LCD_T::PSET: VSEL Mask                 */

#define LCD_PSET_VTUNE_Pos               (24)                                              /*!< LCD_T::PSET: VTUNE Position            */
#define LCD_PSET_VTUNE_Msk               (0xful << LCD_PSET_VTUNE_Pos)                     /*!< LCD_T::PSET: VTUNE Mask                */

#define LCD_FSET_BLINK_Pos               (0)                                               /*!< LCD_T::FSET: BLINK Position            */
#define LCD_FSET_BLINK_Msk               (0x1ul << LCD_FSET_BLINK_Pos)                     /*!< LCD_T::FSET: BLINK Mask                */

#define LCD_FSET_FCV_Pos                 (8)                                               /*!< LCD_T::FSET: FCV Position              */
#define LCD_FSET_FCV_Msk                 (0x3fful << LCD_FSET_FCV_Pos)                     /*!< LCD_T::FSET: FCV Mask                  */

#define LCD_FSET_PTYPE_Pos               (19)                                              /*!< LCD_T::FSET: PTYPE Position            */
#define LCD_FSET_PTYPE_Msk               (0x1ul << LCD_FSET_PTYPE_Pos)                     /*!< LCD_T::FSET: PTYPE Mask                */

#define LCD_FSET_PTIME_Pos               (20)                                              /*!< LCD_T::FSET: PTIME Position            */
#define LCD_FSET_PTIME_Msk               (0xful << LCD_FSET_PTIME_Pos)                     /*!< LCD_T::FSET: PTIME Mask                */

#define LCD_DSET_VSRC_Pos                (0)                                               /*!< LCD_T::DSET: VSRC Position             */
#define LCD_DSET_VSRC_Msk                (0x3ul << LCD_DSET_VSRC_Pos)                      /*!< LCD_T::DSET: VSRC Mask                 */

#define LCD_DSET_RESMODE_Pos             (2)                                               /*!< LCD_T::DSET: RESMODE Position          */
#define LCD_DSET_RESMODE_Msk             (0x1ul << LCD_DSET_RESMODE_Pos)                   /*!< LCD_T::DSET: RESMODE Mask              */

#define LCD_DSET_BUFEN_Pos               (3)                                               /*!< LCD_T::DSET: BUFEN Position            */
#define LCD_DSET_BUFEN_Msk               (0x1ul << LCD_DSET_BUFEN_Pos)                     /*!< LCD_T::DSET: BUFEN Mask                */

#define LCD_DSET_PSVEN_Pos               (4)                                               /*!< LCD_T::DSET: PSVEN Position            */
#define LCD_DSET_PSVEN_Msk               (0x1ul << LCD_DSET_PSVEN_Pos)                     /*!< LCD_T::DSET: PSVEN Mask                */

#define LCD_DSET_PSVREV_Pos              (5)                                               /*!< LCD_T::DSET: PSVREV Position           */
#define LCD_DSET_PSVREV_Msk              (0x1ul << LCD_DSET_PSVREV_Pos)                    /*!< LCD_T::DSET: PSVREV Mask               */

#define LCD_DSET_PSVT1_Pos               (8)                                               /*!< LCD_T::DSET: PSVT1 Position            */
#define LCD_DSET_PSVT1_Msk               (0xful << LCD_DSET_PSVT1_Pos)                     /*!< LCD_T::DSET: PSVT1 Mask                */

#define LCD_DSET_PSVT2_Pos               (12)                                              /*!< LCD_T::DSET: PSVT2 Position            */
#define LCD_DSET_PSVT2_Msk               (0xful << LCD_DSET_PSVT2_Pos)                     /*!< LCD_T::DSET: PSVT2 Mask                */

#define LCD_DSET_CTOUT_Pos               (16)                                              /*!< LCD_T::DSET: CTOUT Position            */
#define LCD_DSET_CTOUT_Msk               (0x1ffful << LCD_DSET_CTOUT_Pos)                  /*!< LCD_T::DSET: CTOUT Mask                */

#define LCD_OSET_SEL8_Pos                (0)                                               /*!< LCD_T::OSET: SEL8 Position             */
#define LCD_OSET_SEL8_Msk                (0x1ul << LCD_OSET_SEL8_Pos)                      /*!< LCD_T::OSET: SEL8 Mask                 */

#define LCD_OSET_SEL9_Pos                (1)                                               /*!< LCD_T::OSET: SEL9 Position             */
#define LCD_OSET_SEL9_Msk                (0x1ul << LCD_OSET_SEL9_Pos)                      /*!< LCD_T::OSET: SEL9 Mask                 */

#define LCD_OSET_SEL10_Pos               (2)                                               /*!< LCD_T::OSET: SEL10 Position            */
#define LCD_OSET_SEL10_Msk               (0x1ul << LCD_OSET_SEL10_Pos)                     /*!< LCD_T::OSET: SEL10 Mask                */

#define LCD_OSET_SEL11_Pos               (3)                                               /*!< LCD_T::OSET: SEL11 Position            */
#define LCD_OSET_SEL11_Msk               (0x1ul << LCD_OSET_SEL11_Pos)                     /*!< LCD_T::OSET: SEL11 Mask                */

#define LCD_OSET_SEL12_Pos               (4)                                               /*!< LCD_T::OSET: SEL12 Position            */
#define LCD_OSET_SEL12_Msk               (0x1ul << LCD_OSET_SEL12_Pos)                     /*!< LCD_T::OSET: SEL12 Mask                */

#define LCD_OSET_SEL13_Pos               (5)                                               /*!< LCD_T::OSET: SEL13 Position            */
#define LCD_OSET_SEL13_Msk               (0x1ul << LCD_OSET_SEL13_Pos)                     /*!< LCD_T::OSET: SEL13 Mask                */

#define LCD_OSET_SEL14_Pos               (6)                                               /*!< LCD_T::OSET: SEL14 Position            */
#define LCD_OSET_SEL14_Msk               (0x1ul << LCD_OSET_SEL14_Pos)                     /*!< LCD_T::OSET: SEL14 Mask                */

#define LCD_OSET_SEL15_Pos               (7)                                               /*!< LCD_T::OSET: SEL15 Position            */
#define LCD_OSET_SEL15_Msk               (0x1ul << LCD_OSET_SEL15_Pos)                     /*!< LCD_T::OSET: SEL15 Mask                */

#define LCD_OSET_SEL24_Pos               (8)                                               /*!< LCD_T::OSET: SEL24 Position            */
#define LCD_OSET_SEL24_Msk               (0x1ul << LCD_OSET_SEL24_Pos)                     /*!< LCD_T::OSET: SEL24 Mask                */

#define LCD_OSET_SEL25_Pos               (9)                                               /*!< LCD_T::OSET: SEL25 Position            */
#define LCD_OSET_SEL25_Msk               (0x1ul << LCD_OSET_SEL25_Pos)                     /*!< LCD_T::OSET: SEL25 Mask                */

#define LCD_OSET_SEL26_Pos               (10)                                              /*!< LCD_T::OSET: SEL26 Position            */
#define LCD_OSET_SEL26_Msk               (0x1ul << LCD_OSET_SEL26_Pos)                     /*!< LCD_T::OSET: SEL26 Mask                */

#define LCD_OSET_SEL27_Pos               (11)                                              /*!< LCD_T::OSET: SEL27 Position            */
#define LCD_OSET_SEL27_Msk               (0x1ul << LCD_OSET_SEL27_Pos)                     /*!< LCD_T::OSET: SEL27 Mask                */

#define LCD_OSET_SEL28_Pos               (12)                                              /*!< LCD_T::OSET: SEL28 Position            */
#define LCD_OSET_SEL28_Msk               (0x1ul << LCD_OSET_SEL28_Pos)                     /*!< LCD_T::OSET: SEL28 Mask                */

#define LCD_OSET_SEL29_Pos               (13)                                              /*!< LCD_T::OSET: SEL29 Position            */
#define LCD_OSET_SEL29_Msk               (0x1ul << LCD_OSET_SEL29_Pos)                     /*!< LCD_T::OSET: SEL29 Mask                */

#define LCD_OSET_SEL35_Pos               (14)                                              /*!< LCD_T::OSET: SEL35 Position            */
#define LCD_OSET_SEL35_Msk               (0x3ul << LCD_OSET_SEL35_Pos)                     /*!< LCD_T::OSET: SEL35 Mask                */

#define LCD_OSET_SEL36_Pos               (16)                                              /*!< LCD_T::OSET: SEL36 Position            */
#define LCD_OSET_SEL36_Msk               (0x3ul << LCD_OSET_SEL36_Pos)                     /*!< LCD_T::OSET: SEL36 Mask                */

#define LCD_OSET_SEL37_Pos               (18)                                              /*!< LCD_T::OSET: SEL37 Position            */
#define LCD_OSET_SEL37_Msk               (0x3ul << LCD_OSET_SEL37_Pos)                     /*!< LCD_T::OSET: SEL37 Mask                */

#define LCD_OSET_SEL38_Pos               (20)                                              /*!< LCD_T::OSET: SEL38 Position            */
#define LCD_OSET_SEL38_Msk               (0x3ul << LCD_OSET_SEL38_Pos)                     /*!< LCD_T::OSET: SEL38 Mask                */

#define LCD_OSET_SEL41_Pos               (22)                                              /*!< LCD_T::OSET: SEL41 Position            */
#define LCD_OSET_SEL41_Msk               (0x1ul << LCD_OSET_SEL41_Pos)                     /*!< LCD_T::OSET: SEL41 Mask                */

#define LCD_OSET_SEL42_Pos               (23)                                              /*!< LCD_T::OSET: SEL42 Position            */
#define LCD_OSET_SEL42_Msk               (0x1ul << LCD_OSET_SEL42_Pos)                     /*!< LCD_T::OSET: SEL42 Mask                */

#define LCD_OSET_SEL47_Pos               (24)                                              /*!< LCD_T::OSET: SEL47 Position            */
#define LCD_OSET_SEL47_Msk               (0x1ul << LCD_OSET_SEL47_Pos)                     /*!< LCD_T::OSET: SEL47 Mask                */

#define LCD_OSET_SEL48_Pos               (25)                                              /*!< LCD_T::OSET: SEL48 Position            */
#define LCD_OSET_SEL48_Msk               (0x1ul << LCD_OSET_SEL48_Pos)                     /*!< LCD_T::OSET: SEL48 Mask                */

#define LCD_OSET_SEL49_Pos               (26)                                              /*!< LCD_T::OSET: SEL49 Position            */
#define LCD_OSET_SEL49_Msk               (0x1ul << LCD_OSET_SEL49_Pos)                     /*!< LCD_T::OSET: SEL49 Mask                */

#define LCD_STS_FCEND_Pos                (0)                                               /*!< LCD_T::STS: FCEND Position             */
#define LCD_STS_FCEND_Msk                (0x1ul << LCD_STS_FCEND_Pos)                      /*!< LCD_T::STS: FCEND Mask                 */

#define LCD_STS_FEND_Pos                 (1)                                               /*!< LCD_T::STS: FEND Position              */
#define LCD_STS_FEND_Msk                 (0x1ul << LCD_STS_FEND_Pos)                       /*!< LCD_T::STS: FEND Mask                  */

#define LCD_STS_CTOUT_Pos                (2)                                               /*!< LCD_T::STS: CTOUT Position             */
#define LCD_STS_CTOUT_Msk                (0x1ul << LCD_STS_CTOUT_Pos)                      /*!< LCD_T::STS: CTOUT Mask                 */

#define LCD_STS_CTIME_Pos                (16)                                              /*!< LCD_T::STS: CTIME Position             */
#define LCD_STS_CTIME_Msk                (0x1ffful << LCD_STS_CTIME_Pos)                   /*!< LCD_T::STS: CTIME Mask                 */

#define LCD_INTEN_FCEND_Pos              (0)                                               /*!< LCD_T::INTEN: FCEND Position           */
#define LCD_INTEN_FCEND_Msk              (0x1ul << LCD_INTEN_FCEND_Pos)                    /*!< LCD_T::INTEN: FCEND Mask               */

#define LCD_INTEN_FEND_Pos               (1)                                               /*!< LCD_T::INTEN: FEND Position            */
#define LCD_INTEN_FEND_Msk               (0x1ul << LCD_INTEN_FEND_Pos)                     /*!< LCD_T::INTEN: FEND Mask                */

#define LCD_INTEN_CTOUT_Pos              (2)                                               /*!< LCD_T::INTEN: CTOUT Position           */
#define LCD_INTEN_CTOUT_Msk              (0x1ul << LCD_INTEN_CTOUT_Pos)                    /*!< LCD_T::INTEN: CTOUT Mask               */

#define LCD_DATA00_DD0_Pos               (0)                                               /*!< LCD_T::DATA00: DD0 Position            */
#define LCD_DATA00_DD0_Msk               (0xfful << LCD_DATA00_DD0_Pos)                    /*!< LCD_T::DATA00: DD0 Mask                */

#define LCD_DATA00_DD1_Pos               (8)                                               /*!< LCD_T::DATA00: DD1 Position            */
#define LCD_DATA00_DD1_Msk               (0xfful << LCD_DATA00_DD1_Pos)                    /*!< LCD_T::DATA00: DD1 Mask                */

#define LCD_DATA00_DD2_Pos               (16)                                              /*!< LCD_T::DATA00: DD2 Position            */
#define LCD_DATA00_DD2_Msk               (0xfful << LCD_DATA00_DD2_Pos)                    /*!< LCD_T::DATA00: DD2 Mask                */

#define LCD_DATA00_DD3_Pos               (24)                                              /*!< LCD_T::DATA00: DD3 Position            */
#define LCD_DATA00_DD3_Msk               (0xfful << LCD_DATA00_DD3_Pos)                    /*!< LCD_T::DATA00: DD3 Mask                */

#define LCD_DATA01_DD0_Pos               (0)                                               /*!< LCD_T::DATA01: DD0 Position            */
#define LCD_DATA01_DD0_Msk               (0xfful << LCD_DATA01_DD0_Pos)                    /*!< LCD_T::DATA01: DD0 Mask                */

#define LCD_DATA01_DD1_Pos               (8)                                               /*!< LCD_T::DATA01: DD1 Position            */
#define LCD_DATA01_DD1_Msk               (0xfful << LCD_DATA01_DD1_Pos)                    /*!< LCD_T::DATA01: DD1 Mask                */

#define LCD_DATA01_DD2_Pos               (16)                                              /*!< LCD_T::DATA01: DD2 Position            */
#define LCD_DATA01_DD2_Msk               (0xfful << LCD_DATA01_DD2_Pos)                    /*!< LCD_T::DATA01: DD2 Mask                */

#define LCD_DATA01_DD3_Pos               (24)                                              /*!< LCD_T::DATA01: DD3 Position            */
#define LCD_DATA01_DD3_Msk               (0xfful << LCD_DATA01_DD3_Pos)                    /*!< LCD_T::DATA01: DD3 Mask                */

#define LCD_DATA02_DD0_Pos               (0)                                               /*!< LCD_T::DATA02: DD0 Position            */
#define LCD_DATA02_DD0_Msk               (0xfful << LCD_DATA02_DD0_Pos)                    /*!< LCD_T::DATA02: DD0 Mask                */

#define LCD_DATA02_DD1_Pos               (8)                                               /*!< LCD_T::DATA02: DD1 Position            */
#define LCD_DATA02_DD1_Msk               (0xfful << LCD_DATA02_DD1_Pos)                    /*!< LCD_T::DATA02: DD1 Mask                */

#define LCD_DATA02_DD2_Pos               (16)                                              /*!< LCD_T::DATA02: DD2 Position            */
#define LCD_DATA02_DD2_Msk               (0xfful << LCD_DATA02_DD2_Pos)                    /*!< LCD_T::DATA02: DD2 Mask                */

#define LCD_DATA02_DD3_Pos               (24)                                              /*!< LCD_T::DATA02: DD3 Position            */
#define LCD_DATA02_DD3_Msk               (0xfful << LCD_DATA02_DD3_Pos)                    /*!< LCD_T::DATA02: DD3 Mask                */

#define LCD_DATA03_DD0_Pos               (0)                                               /*!< LCD_T::DATA03: DD0 Position            */
#define LCD_DATA03_DD0_Msk               (0xfful << LCD_DATA03_DD0_Pos)                    /*!< LCD_T::DATA03: DD0 Mask                */

#define LCD_DATA03_DD1_Pos               (8)                                               /*!< LCD_T::DATA03: DD1 Position            */
#define LCD_DATA03_DD1_Msk               (0xfful << LCD_DATA03_DD1_Pos)                    /*!< LCD_T::DATA03: DD1 Mask                */

#define LCD_DATA03_DD2_Pos               (16)                                              /*!< LCD_T::DATA03: DD2 Position            */
#define LCD_DATA03_DD2_Msk               (0xfful << LCD_DATA03_DD2_Pos)                    /*!< LCD_T::DATA03: DD2 Mask                */

#define LCD_DATA03_DD3_Pos               (24)                                              /*!< LCD_T::DATA03: DD3 Position            */
#define LCD_DATA03_DD3_Msk               (0xfful << LCD_DATA03_DD3_Pos)                    /*!< LCD_T::DATA03: DD3 Mask                */

#define LCD_DATA04_DD0_Pos               (0)                                               /*!< LCD_T::DATA04: DD0 Position            */
#define LCD_DATA04_DD0_Msk               (0xfful << LCD_DATA04_DD0_Pos)                    /*!< LCD_T::DATA04: DD0 Mask                */

#define LCD_DATA04_DD1_Pos               (8)                                               /*!< LCD_T::DATA04: DD1 Position            */
#define LCD_DATA04_DD1_Msk               (0xfful << LCD_DATA04_DD1_Pos)                    /*!< LCD_T::DATA04: DD1 Mask                */

#define LCD_DATA04_DD2_Pos               (16)                                              /*!< LCD_T::DATA04: DD2 Position            */
#define LCD_DATA04_DD2_Msk               (0xfful << LCD_DATA04_DD2_Pos)                    /*!< LCD_T::DATA04: DD2 Mask                */

#define LCD_DATA04_DD3_Pos               (24)                                              /*!< LCD_T::DATA04: DD3 Position            */
#define LCD_DATA04_DD3_Msk               (0xfful << LCD_DATA04_DD3_Pos)                    /*!< LCD_T::DATA04: DD3 Mask                */

#define LCD_DATA05_DD0_Pos               (0)                                               /*!< LCD_T::DATA05: DD0 Position            */
#define LCD_DATA05_DD0_Msk               (0xfful << LCD_DATA05_DD0_Pos)                    /*!< LCD_T::DATA05: DD0 Mask                */

#define LCD_DATA05_DD1_Pos               (8)                                               /*!< LCD_T::DATA05: DD1 Position            */
#define LCD_DATA05_DD1_Msk               (0xfful << LCD_DATA05_DD1_Pos)                    /*!< LCD_T::DATA05: DD1 Mask                */

#define LCD_DATA05_DD2_Pos               (16)                                              /*!< LCD_T::DATA05: DD2 Position            */
#define LCD_DATA05_DD2_Msk               (0xfful << LCD_DATA05_DD2_Pos)                    /*!< LCD_T::DATA05: DD2 Mask                */

#define LCD_DATA05_DD3_Pos               (24)                                              /*!< LCD_T::DATA05: DD3 Position            */
#define LCD_DATA05_DD3_Msk               (0xfful << LCD_DATA05_DD3_Pos)                    /*!< LCD_T::DATA05: DD3 Mask                */

#define LCD_DATA06_DD0_Pos               (0)                                               /*!< LCD_T::DATA06: DD0 Position            */
#define LCD_DATA06_DD0_Msk               (0xfful << LCD_DATA06_DD0_Pos)                    /*!< LCD_T::DATA06: DD0 Mask                */

#define LCD_DATA06_DD1_Pos               (8)                                               /*!< LCD_T::DATA06: DD1 Position            */
#define LCD_DATA06_DD1_Msk               (0xfful << LCD_DATA06_DD1_Pos)                    /*!< LCD_T::DATA06: DD1 Mask                */

#define LCD_DATA06_DD2_Pos               (16)                                              /*!< LCD_T::DATA06: DD2 Position            */
#define LCD_DATA06_DD2_Msk               (0xfful << LCD_DATA06_DD2_Pos)                    /*!< LCD_T::DATA06: DD2 Mask                */

#define LCD_DATA06_DD3_Pos               (24)                                              /*!< LCD_T::DATA06: DD3 Position            */
#define LCD_DATA06_DD3_Msk               (0xfful << LCD_DATA06_DD3_Pos)                    /*!< LCD_T::DATA06: DD3 Mask                */

#define LCD_DATA07_DD0_Pos               (0)                                               /*!< LCD_T::DATA07: DD0 Position            */
#define LCD_DATA07_DD0_Msk               (0xfful << LCD_DATA07_DD0_Pos)                    /*!< LCD_T::DATA07: DD0 Mask                */

#define LCD_DATA07_DD1_Pos               (8)                                               /*!< LCD_T::DATA07: DD1 Position            */
#define LCD_DATA07_DD1_Msk               (0xfful << LCD_DATA07_DD1_Pos)                    /*!< LCD_T::DATA07: DD1 Mask                */

#define LCD_DATA07_DD2_Pos               (16)                                              /*!< LCD_T::DATA07: DD2 Position            */
#define LCD_DATA07_DD2_Msk               (0xfful << LCD_DATA07_DD2_Pos)                    /*!< LCD_T::DATA07: DD2 Mask                */

#define LCD_DATA07_DD3_Pos               (24)                                              /*!< LCD_T::DATA07: DD3 Position            */
#define LCD_DATA07_DD3_Msk               (0xfful << LCD_DATA07_DD3_Pos)                    /*!< LCD_T::DATA07: DD3 Mask                */

#define LCD_DATA08_DD0_Pos               (0)                                               /*!< LCD_T::DATA08: DD0 Position            */
#define LCD_DATA08_DD0_Msk               (0xfful << LCD_DATA08_DD0_Pos)                    /*!< LCD_T::DATA08: DD0 Mask                */

#define LCD_DATA08_DD1_Pos               (8)                                               /*!< LCD_T::DATA08: DD1 Position            */
#define LCD_DATA08_DD1_Msk               (0xfful << LCD_DATA08_DD1_Pos)                    /*!< LCD_T::DATA08: DD1 Mask                */

#define LCD_DATA08_DD2_Pos               (16)                                              /*!< LCD_T::DATA08: DD2 Position            */
#define LCD_DATA08_DD2_Msk               (0xfful << LCD_DATA08_DD2_Pos)                    /*!< LCD_T::DATA08: DD2 Mask                */

#define LCD_DATA08_DD3_Pos               (24)                                              /*!< LCD_T::DATA08: DD3 Position            */
#define LCD_DATA08_DD3_Msk               (0xfful << LCD_DATA08_DD3_Pos)                    /*!< LCD_T::DATA08: DD3 Mask                */

#define LCD_DATA09_DD0_Pos               (0)                                               /*!< LCD_T::DATA09: DD0 Position            */
#define LCD_DATA09_DD0_Msk               (0xfful << LCD_DATA09_DD0_Pos)                    /*!< LCD_T::DATA09: DD0 Mask                */

#define LCD_DATA09_DD1_Pos               (8)                                               /*!< LCD_T::DATA09: DD1 Position            */
#define LCD_DATA09_DD1_Msk               (0xfful << LCD_DATA09_DD1_Pos)                    /*!< LCD_T::DATA09: DD1 Mask                */

#define LCD_DATA09_DD2_Pos               (16)                                              /*!< LCD_T::DATA09: DD2 Position            */
#define LCD_DATA09_DD2_Msk               (0xfful << LCD_DATA09_DD2_Pos)                    /*!< LCD_T::DATA09: DD2 Mask                */

#define LCD_DATA09_DD3_Pos               (24)                                              /*!< LCD_T::DATA09: DD3 Position            */
#define LCD_DATA09_DD3_Msk               (0xfful << LCD_DATA09_DD3_Pos)                    /*!< LCD_T::DATA09: DD3 Mask                */

#define LCD_DATA10_DD0_Pos               (0)                                               /*!< LCD_T::DATA10: DD0 Position            */
#define LCD_DATA10_DD0_Msk               (0xfful << LCD_DATA10_DD0_Pos)                    /*!< LCD_T::DATA10: DD0 Mask                */

#define LCD_DATA10_DD1_Pos               (8)                                               /*!< LCD_T::DATA10: DD1 Position            */
#define LCD_DATA10_DD1_Msk               (0xfful << LCD_DATA10_DD1_Pos)                    /*!< LCD_T::DATA10: DD1 Mask                */

#define LCD_DATA10_DD2_Pos               (16)                                              /*!< LCD_T::DATA10: DD2 Position            */
#define LCD_DATA10_DD2_Msk               (0xfful << LCD_DATA10_DD2_Pos)                    /*!< LCD_T::DATA10: DD2 Mask                */

#define LCD_DATA10_DD3_Pos               (24)                                              /*!< LCD_T::DATA10: DD3 Position            */
#define LCD_DATA10_DD3_Msk               (0xfful << LCD_DATA10_DD3_Pos)                    /*!< LCD_T::DATA10: DD3 Mask                */

#define LCD_DATA11_DD0_Pos               (0)                                               /*!< LCD_T::DATA11: DD0 Position            */
#define LCD_DATA11_DD0_Msk               (0xfful << LCD_DATA11_DD0_Pos)                    /*!< LCD_T::DATA11: DD0 Mask                */

#define LCD_DATA11_DD1_Pos               (8)                                               /*!< LCD_T::DATA11: DD1 Position            */
#define LCD_DATA11_DD1_Msk               (0xfful << LCD_DATA11_DD1_Pos)                    /*!< LCD_T::DATA11: DD1 Mask                */

#define LCD_DATA11_DD2_Pos               (16)                                              /*!< LCD_T::DATA11: DD2 Position            */
#define LCD_DATA11_DD2_Msk               (0xfful << LCD_DATA11_DD2_Pos)                    /*!< LCD_T::DATA11: DD2 Mask                */

#define LCD_DATA11_DD3_Pos               (24)                                              /*!< LCD_T::DATA11: DD3 Position            */
#define LCD_DATA11_DD3_Msk               (0xfful << LCD_DATA11_DD3_Pos)                    /*!< LCD_T::DATA11: DD3 Mask                */

/** @} LCD_CONST */
/** @} end of LCD register group */
/** @} end of REGISTER group */

#endif /* __LCD_REG_H__ */

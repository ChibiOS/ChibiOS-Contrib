/**************************************************************************//**
 * @file     lcd.h
 * @version  V3.00
 * @brief    Liquid-Crystal Display(LCD) driver header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2022 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __LCD_H__
#define __LCD_H__

#ifdef __cplusplus
extern "C"
{
#endif


/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup LCD_Driver LCD Driver
  @{
*/

/** @addtogroup LCD_EXPORTED_CONSTANTS LCD Exported Constants
  @{
*/
/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Bias Voltage Level Selection Constant Definitions                                                  */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_BIAS_LV_1_2                 (1ul << LCD_PSET_BIAS_Pos) /*!< LCD bias voltage level selection - 1/2 Bias \hideinitializer */
#define LCD_BIAS_LV_1_3                 (2ul << LCD_PSET_BIAS_Pos) /*!< LCD bias voltage level selection - 1/3 Bias \hideinitializer */
#define LCD_BIAS_LV_1_4                 (3ul << LCD_PSET_BIAS_Pos) /*!< LCD bias voltage level selection - 1/4 Bias \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD COM Duty Ratio Selection Constant Definitions                                                      */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_COM_DUTY_1_1                (0ul << LCD_PSET_DUTY_Pos) /*!< LCD com duty ratio selection - 1/1 Duty \hideinitializer */
#define LCD_COM_DUTY_1_2                (1ul << LCD_PSET_DUTY_Pos) /*!< LCD com duty ratio selection - 1/2 Duty \hideinitializer */
#define LCD_COM_DUTY_1_3                (2ul << LCD_PSET_DUTY_Pos) /*!< LCD com duty ratio selection - 1/3 Duty \hideinitializer */
#define LCD_COM_DUTY_1_4                (3ul << LCD_PSET_DUTY_Pos) /*!< LCD com duty ratio selection - 1/4 Duty \hideinitializer */
#define LCD_COM_DUTY_1_5                (4ul << LCD_PSET_DUTY_Pos) /*!< LCD com duty ratio selection - 1/5 Duty \hideinitializer */
#define LCD_COM_DUTY_1_6                (5ul << LCD_PSET_DUTY_Pos) /*!< LCD com duty ratio selection - 1/6 Duty \hideinitializer */
#define LCD_COM_DUTY_1_7                (6ul << LCD_PSET_DUTY_Pos) /*!< LCD com duty ratio selection - 1/7 Duty \hideinitializer */
#define LCD_COM_DUTY_1_8                (7ul << LCD_PSET_DUTY_Pos) /*!< LCD com duty ratio selection - 1/8 Duty \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Waveform Attribute Selection Constant Definitions                                                  */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_WAVEFORM_TYPE_A_NORMAL      (0ul << LCD_PSET_TYPE_Pos) /*!< LCD waveform Type-A, no inverse \hideinitializer */
#define LCD_WAVEFORM_TYPE_B_NORMAL      (1ul << LCD_PSET_TYPE_Pos) /*!< LCD waveform Type-B, no inverse \hideinitializer */
#define LCD_WAVEFORM_TYPE_A_INVERSE     (2ul << LCD_PSET_TYPE_Pos) /*!< LCD waveform Type-A and inverse \hideinitializer */
#define LCD_WAVEFORM_TYPE_B_INVERSE     (3ul << LCD_PSET_TYPE_Pos) /*!< LCD waveform Type-B and inverse \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Charge Pump Voltage Selection Constant Definitions                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_CP_VOLTAGE_LV_0             (0ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 3.0 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_1             (1ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 3.2 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_2             (2ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 3.4 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_3             (3ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 3.6 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_4             (4ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 3.8 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_5             (5ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 4.0 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_6             (6ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 4.2 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_7             (7ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 4.4 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_8             (8ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 4.6 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_9             (9ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 4.8 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_10            (10ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 5.0 V \hideinitializer */
#define LCD_CP_VOLTAGE_LV_11            (11ul << LCD_PSET_VSEL_Pos) /*!< Select LCD charge pump voltage 5.2 V \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Interrupt Source Constant Definitions                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_DISABLE_ALL_INT             (0ul << LCD_INTEN_FCEND_Pos) /*!< Disable all LCD interrupt sources \hideinitializer */
#define LCD_FRAME_COUNTING_END_INT      (1ul << LCD_INTEN_FCEND_Pos) /*!< Indicate frame count end interrupt \hideinitializer */
#define LCD_FRAME_END_INT               (1ul << LCD_INTEN_FEND_Pos)  /*!< Indicate frame end interrupt \hideinitializer */
#define LCD_CPTOUT_INT                  (1ul << LCD_INTEN_CTOUT_Pos) /*!< Indicate charge pump charging timeout interrupt \hideinitializer */
#define LCD_ENABLE_ALL_INT              (7ul << LCD_INTEN_FCEND_Pos) /*!< Enable all LCD interrupt sources \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Operation Voltage Source Constant Definitions                                                      */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_VOLTAGE_SOURCE_VLCD         (0ul << LCD_DSET_VSRC_Pos) /*!< LCD voltage source from external VLCD power \hideinitializer */
#define LCD_VOLTAGE_SOURCE_AVDD         (1ul << LCD_DSET_VSRC_Pos) /*!< LCD voltage source from internal VDD \hideinitializer */
#define LCD_VOLTAGE_SOURCE_CP           (2ul << LCD_DSET_VSRC_Pos) /*!< LCD voltage source from built-in charge pump \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Driving Mode Selection Constant Definitions                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_HIGH_DRIVING_ON_AND_BUF_OFF                         (1ul << LCD_DSET_RESMODE_Pos) /*!< LCD operates with high-drive enabled and voltage buffer disabled \hideinitializer */
#define LCD_HIGH_DRIVING_OFF_AND_BUF_ON                         (2ul << LCD_DSET_RESMODE_Pos) /*!< LCD operates with high-drive disabled and voltage buffer enabled \hideinitializer */
#define LCD_HIGH_DRIVING_ON_AND_BUF_OFF_AND_PWR_SAVING          (5ul << LCD_DSET_RESMODE_Pos) /*!< LCD operates with high-drive enabled, voltage buffer disabled and power saving \hideinitializer */
#define LCD_HIGH_DRIVING_OFF_AND_BUF_ON_AND_PWR_SAVING          (6ul << LCD_DSET_RESMODE_Pos) /*!< LCD operates with high-drive disabled, voltage buffer enabled and power saving \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Power Saving Mode Constant Definitions                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_PWR_SAVING_NORMAL_MODE              (0ul << LCD_DSET_PSVREV_Pos) /*!< The timing of LCD power saving is normal \hideinitializer */
#define LCD_PWR_SAVING_REVERSE_MODE             (1ul << LCD_DSET_PSVREV_Pos) /*!< The timing of LCD power saving is reverse \hideinitializer */
#define LCD_PWR_SAVING_RES_MODE                 (0ul) /*!< LCD saving mode is resistive mode \hideinitializer */
#define LCD_PWR_SAVING_BUF_MODE                 (1ul) /*!< LCD saving mode is buffer mode \hideinitializer */
/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Output Control Constant Definitions                                                                */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_OUTPUT_SEL8_TO_SEG43                (0ul << LCD_OSET_SEL8_Pos)  /*!< The output SEL8  is SEG43 \hideinitializer */
#define LCD_OUTPUT_SEL8_TO_COM4                 (1ul << LCD_OSET_SEL8_Pos)  /*!< The output SEL8  is COM4 \hideinitializer */
#define LCD_OUTPUT_SEL9_TO_SEG42                (0ul << LCD_OSET_SEL9_Pos)  /*!< The output SEL9  is SEG42 \hideinitializer */
#define LCD_OUTPUT_SEL9_TO_COM5                 (1ul << LCD_OSET_SEL9_Pos)  /*!< The output SEL9  is COM5 \hideinitializer */
#define LCD_OUTPUT_SEL10_TO_SEG20               (0ul << LCD_OSET_SEL10_Pos) /*!< The output SEL10 is SEG20 \hideinitializer */
#define LCD_OUTPUT_SEL10_TO_COM0                (1ul << LCD_OSET_SEL10_Pos) /*!< The output SEL10 is COM0 \hideinitializer */
#define LCD_OUTPUT_SEL11_TO_SEG19               (0ul << LCD_OSET_SEL11_Pos) /*!< The output SEL11 is SEG19 \hideinitializer */
#define LCD_OUTPUT_SEL11_TO_COM1                (1ul << LCD_OSET_SEL11_Pos) /*!< The output SEL11 is COM1 \hideinitializer */
#define LCD_OUTPUT_SEL12_TO_SEG18               (0ul << LCD_OSET_SEL12_Pos) /*!< The output SEL12 is SEG18 \hideinitializer */
#define LCD_OUTPUT_SEL12_TO_COM2                (1ul << LCD_OSET_SEL12_Pos) /*!< The output SEL12 is COM2 \hideinitializer */
#define LCD_OUTPUT_SEL13_TO_SEG17               (0ul << LCD_OSET_SEL13_Pos) /*!< The output SEL13 is SEG17 \hideinitializer */
#define LCD_OUTPUT_SEL13_TO_COM3                (1ul << LCD_OSET_SEL13_Pos) /*!< The output SEL13 is COM3 \hideinitializer */
#define LCD_OUTPUT_SEL14_TO_SEG41               (0ul << LCD_OSET_SEL14_Pos) /*!< The output SEL14 is SEG41 \hideinitializer */
#define LCD_OUTPUT_SEL14_TO_COM6                (1ul << LCD_OSET_SEL14_Pos) /*!< The output SEL14 is COM6 \hideinitializer */
#define LCD_OUTPUT_SEL15_TO_SEG40               (0ul << LCD_OSET_SEL15_Pos) /*!< The output SEL15 is SEG40 \hideinitializer */
#define LCD_OUTPUT_SEL15_TO_COM7                (1ul << LCD_OSET_SEL15_Pos) /*!< The output SEL15 is COM7 \hideinitializer */
#define LCD_OUTPUT_SEL24_TO_SEG31               (0ul << LCD_OSET_SEL24_Pos) /*!< The output SEL24 is SEG31 \hideinitializer */
#define LCD_OUTPUT_SEL24_TO_COM4                (1ul << LCD_OSET_SEL24_Pos) /*!< The output SEL24 is COM4 \hideinitializer */
#define LCD_OUTPUT_SEL25_TO_SEG30               (0ul << LCD_OSET_SEL25_Pos) /*!< The output SEL25 is SEG30 \hideinitializer */
#define LCD_OUTPUT_SEL25_TO_COM5                (1ul << LCD_OSET_SEL25_Pos) /*!< The output SEL25 is COM5 \hideinitializer */
#define LCD_OUTPUT_SEL26_TO_SEG29               (0ul << LCD_OSET_SEL26_Pos) /*!< The output SEL26 is SEG29 \hideinitializer */
#define LCD_OUTPUT_SEL26_TO_COM6                (1ul << LCD_OSET_SEL26_Pos) /*!< The output SEL26 is COM6 \hideinitializer */
#define LCD_OUTPUT_SEL27_TO_SEG28               (0ul << LCD_OSET_SEL27_Pos) /*!< The output SEL27 is SEG28 \hideinitializer */
#define LCD_OUTPUT_SEL27_TO_COM7                (1ul << LCD_OSET_SEL27_Pos) /*!< The output SEL27 is COM7 \hideinitializer */
#define LCD_OUTPUT_SEL28_TO_SEG27               (0ul << LCD_OSET_SEL28_Pos) /*!< The output SEL28 is SEG27 \hideinitializer */
#define LCD_OUTPUT_SEL28_TO_COM2                (1ul << LCD_OSET_SEL28_Pos) /*!< The output SEL28 is COM2 \hideinitializer */
#define LCD_OUTPUT_SEL29_TO_SEG26               (0ul << LCD_OSET_SEL29_Pos) /*!< The output SEL29 is SEG26 \hideinitializer */
#define LCD_OUTPUT_SEL29_TO_COM3                (1ul << LCD_OSET_SEL29_Pos) /*!< The output SEL29 is COM3 \hideinitializer */
#define LCD_OUTPUT_SEL35_TO_COM4                (0ul << LCD_OSET_SEL35_Pos) /*!< The output SEL35 is COM4 \hideinitializer */
#define LCD_OUTPUT_SEL35_TO_SEG20               (1ul << LCD_OSET_SEL35_Pos) /*!< The output SEL35 is SEG20 \hideinitializer */
#define LCD_OUTPUT_SEL35_TO_SEG47               (2ul << LCD_OSET_SEL35_Pos) /*!< The output SEL35 is SEG47 \hideinitializer */
#define LCD_OUTPUT_SEL36_TO_COM5                (0ul << LCD_OSET_SEL36_Pos) /*!< The output SEL36 is COM5 \hideinitializer */
#define LCD_OUTPUT_SEL36_TO_SEG19               (1ul << LCD_OSET_SEL36_Pos) /*!< The output SEL36 is SEG19 \hideinitializer */
#define LCD_OUTPUT_SEL36_TO_SEG46               (2ul << LCD_OSET_SEL36_Pos) /*!< The output SEL36 is SEG46 \hideinitializer */
#define LCD_OUTPUT_SEL37_TO_COM6                (0ul << LCD_OSET_SEL37_Pos) /*!< The output SEL37 is COM6 \hideinitializer */
#define LCD_OUTPUT_SEL37_TO_SEG18               (1ul << LCD_OSET_SEL37_Pos) /*!< The output SEL37 is SEG18 \hideinitializer */
#define LCD_OUTPUT_SEL37_TO_SEG45               (2ul << LCD_OSET_SEL37_Pos) /*!< The output SEL37 is SEG45 \hideinitializer */
#define LCD_OUTPUT_SEL38_TO_COM7                (0ul << LCD_OSET_SEL38_Pos) /*!< The output SEL38 is COM7 \hideinitializer */
#define LCD_OUTPUT_SEL38_TO_SEG17               (1ul << LCD_OSET_SEL38_Pos) /*!< The output SEL38 is SEG17 \hideinitializer */
#define LCD_OUTPUT_SEL38_TO_SEG44               (2ul << LCD_OSET_SEL38_Pos) /*!< The output SEL38 is SEG44 \hideinitializer */
#define LCD_OUTPUT_SEL41_TO_SEG14               (0ul << LCD_OSET_SEL41_Pos) /*!< The output SEL41 is SEG14 \hideinitializer */
#define LCD_OUTPUT_SEL41_TO_COM0                (1ul << LCD_OSET_SEL41_Pos) /*!< The output SEL41 is COM0 \hideinitializer */
#define LCD_OUTPUT_SEL42_TO_SEG13               (0ul << LCD_OSET_SEL42_Pos) /*!< The output SEL42 is SEG13 \hideinitializer */
#define LCD_OUTPUT_SEL42_TO_COM1                (1ul << LCD_OSET_SEL42_Pos) /*!< The output SEL42 is COM1 \hideinitializer */
#define LCD_OUTPUT_SEL47_TO_SEG8                (0ul << LCD_OSET_SEL47_Pos) /*!< The output SEL47 is SEG8 \hideinitializer */
#define LCD_OUTPUT_SEL47_TO_LCD_V1              (1ul << LCD_OSET_SEL47_Pos) /*!< The output SEL47 is LCD_V1 \hideinitializer */
#define LCD_OUTPUT_SEL48_TO_SEG7                (0ul << LCD_OSET_SEL48_Pos) /*!< The output SEL48 is SEG7 \hideinitializer */
#define LCD_OUTPUT_SEL48_TO_LCD_V2              (1ul << LCD_OSET_SEL48_Pos) /*!< The output SEL48 is LCD_V2 \hideinitializer */
#define LCD_OUTPUT_SEL49_TO_SEG6                (0ul << LCD_OSET_SEL49_Pos) /*!< The output SEL49 is SEG6 \hideinitializer */
#define LCD_OUTPUT_SEL49_TO_LCD_V3              (1ul << LCD_OSET_SEL49_Pos) /*!< The output SEL49 is LCD_V3 \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Pause Type Constant Definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define LCD_FRAME_PAUSE                 (0ul << LCD_FSET_PTYPE_Pos)  /*!< Select frame pause type \hideinitializer */
#define LCD_DUTY_PAUSE                  (1ul << LCD_FSET_PTYPE_Pos)  /*!< Select duty pause type \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  LCD Power Saving Level Constant Definitions                                                            */
/*---------------------------------------------------------------------------------------------------------*/
enum
{
    LCD_PWR_SAVING_LEVEL0 = 0,
    LCD_PWR_SAVING_LEVEL1,
    LCD_PWR_SAVING_LEVEL2,
    LCD_PWR_SAVING_LEVEL3
};

/** @} end of group LCD_EXPORTED_CONSTANTS */


/** @addtogroup LCD_EXPORTED_STRUCTS LCD Exported Structs
  @{
*/
/**
  * @details    LCD Configuration Data Struct
  */
typedef struct
{
    uint32_t u32SrcFreq;        /*!< LCD clock source frequency */
    uint32_t u32ComDuty;        /*!< COM duty */
    uint32_t u32BiasLevel;      /*!< Bias level */
    uint32_t u32Framerate;      /*!< Operation frame rate */
    uint32_t u32WaveformType;   /*!< Waveform type */
    uint32_t u32IntSrc;         /*!< Interrupt source */
    uint32_t u32DrivingMode;    /*!< Driving mode */
    uint32_t u32VSrc;           /*!< Voltage source */
} S_LCD_CFG_T;

/** @} end of group LCD_EXPORTED_STRUCTS */

/** @addtogroup LCD_EXPORTED_FUNCTIONS LCD Exported Functions
  @{
*/

/**
  * @brief      Enable LCD Display
  *
  *
  *
  * @details    This macro is used to enable LCD display.
  */
#define LCD_ENABLE_DISPLAY()        do{ LCD->CTL |= LCD_CTL_EN_Msk; while(LCD->CTL & LCD_CTL_SYNC_Msk) {} }while(0)

/**
  * @brief      Disable LCD Display
  *
  *
  *
  * @details    This macro is used to disable LCD display.
  */
#define LCD_DISABLE_DISPLAY()       do{ LCD->CTL &= ~LCD_CTL_EN_Msk; while(LCD->CTL & LCD_CTL_SYNC_Msk) {} }while(0)

/**
  * @brief      Set LCD Waveform Type
  *
  * @param[in]  type       The LCD waveform type. It could be one of the following type
  *                             - \ref LCD_WAVEFORM_TYPE_A_NORMAL
  *                             - \ref LCD_WAVEFORM_TYPE_B_NORMAL
  *                             - \ref LCD_WAVEFORM_TYPE_A_INVERSE
  *                             - \ref LCD_WAVEFORM_TYPE_B_INVERSE
  *
  *
  * @details    This macro is used to set the attribute of LCD output waveform.
  */
#define LCD_WAVEFORM_TYPE(type)     (LCD->PSET = (LCD->PSET & ~(LCD_PSET_TYPE_Msk|LCD_PSET_INV_Msk)) | (type))

/**
  * @brief      Set LCD Source Clock Divider
  *
  * @param[in]  div         The frequency divider, valid value is between 1 to 1024.
  *
  *
  * @details    This macro is used to set the LCD operarion frequency is (LCD source frequency / div).
  */
#define LCD_SET_FREQDIV(div)        (LCD->PSET = (LCD->PSET & ~LCD_PSET_FREQDIV_Msk) | (((div)-1) << LCD_PSET_FREQDIV_Pos))

/**
  * @brief      Set Charge Pump Voltage
  *
  * @param[in]  voltage     The target charge pump voltage. It could be one of the following voltage level
  *                             - \ref LCD_CP_VOLTAGE_LV_0, 3.0 V
  *                             - \ref LCD_CP_VOLTAGE_LV_1, 3.2 V
  *                             - \ref LCD_CP_VOLTAGE_LV_2, 3.4 V
  *                             - \ref LCD_CP_VOLTAGE_LV_3, 3.6 V
  *                             - \ref LCD_CP_VOLTAGE_LV_4, 3.8 V
  *                             - \ref LCD_CP_VOLTAGE_LV_5, 4.0 V
  *                             - \ref LCD_CP_VOLTAGE_LV_6, 4.2 V
  *                             - \ref LCD_CP_VOLTAGE_LV_7, 4.4 V
  *                             - \ref LCD_CP_VOLTAGE_LV_8, 4.6 V
  *                             - \ref LCD_CP_VOLTAGE_LV_9, 4.8 V
  *                             - \ref LCD_CP_VOLTAGE_LV_10, 5.0 V
  *                             - \ref LCD_CP_VOLTAGE_LV_11, 5.2 V
  *
  *
  * @details    This macro is used to set charge pump voltage for VLCD.
  */
#define LCD_SET_CP_VOLTAGE(voltage) (LCD->PSET = (LCD->PSET & ~LCD_PSET_VSEL_Msk) | (voltage))

/**
  * @brief      Decrease Charge Pump Voltage
  *
  * @param[in]  unit        The tuning units, valid value is between 1 to 7.
  *                         One unit of voltage is about 0.04V, and the charge pump voltage is decreased (unit * 0.04)V.
  *
  *
  * @details    This macro is used to decrease charge pump voltage by specific units.
  */
#define LCD_CP_VOLTAGE_DECREASE(unit)   (LCD->PSET = (LCD->PSET & ~LCD_PSET_VTUNE_Msk) | ((unit) << LCD_PSET_VTUNE_Pos))

/**
  * @brief      Increase Charge Pump Voltage
  *
  * @param[in]  unit        The tuning units, valid value is between 1 to 8.
  *                         One unit of voltage is about 0.04V, and the charge pump voltage is increased (unit * 0.04)V.
  *
  *
  * @details    This macro is used to increase charge pump voltage by specific units.
  */
#define LCD_CP_VOLTAGE_INCREASE(unit)   (LCD->PSET = (LCD->PSET & ~LCD_PSET_VTUNE_Msk) | (16-(unit)) << LCD_PSET_VTUNE_Pos)

/**
  * @brief      Set LCD Blinking ON
  *
  *
  *
  * @details    This macro is used to enable LCD blinking.
  */
#define LCD_BLINKING_ON()       (LCD->FSET |= LCD_FSET_BLINK_Msk)

/**
  * @brief      Set LCD Blinking OFF
  *
  *
  *
  * @details    This macro is used to disable LCD blinking.
  */
#define LCD_BLINKING_OFF()      (LCD->FSET &= ~LCD_FSET_BLINK_Msk)

/**
  * @brief      Set LCD Frame Counting Value
  *
  * @param[in]  value       Frame counting value. Valid value is between 1 to 1024.
  *
  *
  * @details    This macro is used to set the LCD frame counting value to configure the blink interval.
  * @note       For type-B waveform, the frame counter increases at the end of odd frames, not even frames.
  */
#define LCD_SET_FRAME_COUNTING_VALUE(value)     (LCD->FSET = (LCD->FSET & ~LCD_FSET_FCV_Msk) | (((value)-1) << LCD_FSET_FCV_Pos))

/**
  * @brief      Set Pause Type
  *
  * @param[in]  type        The LCD pause type. It could be one of the following type.
  *                             - \ref LCD_FRAME_PAUSE
  *                             - \ref LCD_DUTY_PAUSE
  *
  *
  * @details    This macro is used to select LCD pause type.
  */
#define LCD_SET_PAUSE_TYPE(type)       (LCD->FSET = (LCD->FSET & ~LCD_FSET_PTYPE_Msk) | (type))

/**
  * @brief      Set Pause Time
  *
  * @param[in]  unit       The pause time, valid setting is between 0 to 15.
  *
  *
  * @details    This macro is used to specify the number of pause time units to insert per frame or duty.
  */
#define LCD_SET_PAUSE_TIME(unit)     (LCD->FSET = (LCD->FSET & ~LCD_FSET_PTIME_Msk) | ((unit) << LCD_FSET_PTIME_Pos))

/**
  * @brief      Select LCD Voltage Source
  *
  * @param[in]  source      The LCD operation voltage source. It could be one of the following source
  *                             - \ref LCD_VOLTAGE_SOURCE_VLCD
  *                             - \ref LCD_VOLTAGE_SOURCE_AVDD
  *                             - \ref LCD_VOLTAGE_SOURCE_CP
  *
  *
  * @details    This macro is used to select LCD operation voltage source.
  */
#define LCD_VOLTAGE_SOURCE(source)          (LCD->DSET = (LCD->DSET & ~LCD_DSET_VSRC_Msk) | (source))

/**
  * @brief      Set LCD Driving Mode
  *
  * @param[in]  mode        The LCD operation driving mode. It could be one of the following mode
  *                             - \ref LCD_HIGH_DRIVING_ON_AND_BUF_OFF
  *                             - \ref LCD_HIGH_DRIVING_OFF_AND_BUF_ON
  *                             - \ref LCD_HIGH_DRIVING_ON_AND_BUF_OFF_AND_PWR_SAVING
  *                             - \ref LCD_HIGH_DRIVING_OFF_AND_BUF_ON_AND_PWR_SAVING
  *
  *
  * @details    This macro is used to set LCD operation driving mode.
  */
#define LCD_DRIVING_MODE(mode)              (LCD->DSET = (LCD->DSET & ~(LCD_DSET_RESMODE_Msk | LCD_DSET_BUFEN_Msk | LCD_DSET_PSVEN_Msk)) | (mode))

/**
  * @brief      Select Power Saving Mode
  *
  * @param[in]  mode        The LCD power saving mode selection. It could be one of the following constant definition
  *                             - \ref LCD_PWR_SAVING_NORMAL_MODE
  *                             - \ref LCD_PWR_SAVING_REVERSE_MODE
  *
  *
  * @details    This macro is used to set the LCD power saving mode.
  *             When the timing of power saving mode is reversed, the original power saving period becomes no power saving,
  *             and the original no power saving period becomes power saving.
  */
#define LCD_PWR_SAVING_MODE(mode)       (LCD->DSET = (LCD->DSET & ~LCD_DSET_PSVREV_Msk) | (mode))

/**
  * @brief      Set Power Saving T1 Period
  *
  * @param[in]  t1      The number of t1 to determine T1 period, valid value is between 1 to 16.
  *                     And one unit of t1 period is half of LCD operation clock period.
  *
  *
  * @details    This macro is used to configure the T1 (Enable Time) period of power saving.
  */
#define LCD_PWR_SAVING_T1_PERIOD(t1)    (LCD->DSET = (LCD->DSET & ~LCD_DSET_PSVT1_Msk) | (((t1)-1) << LCD_DSET_PSVT1_Pos))

/**
  * @brief      Set Power Saving T2 Period
  *
  * @param[in]  t2      The number of t2 to determine T2 period, valid value is between 1 to 16.
  *                     And one unit of t1 period is half of LCD operation clock period.
  *
  *
  * @details    This macro is used to configure the T2 (On Time) period of power saving.
  */
#define LCD_PWR_SAVING_T2_PERIOD(t2)    (LCD->DSET = (LCD->DSET & ~LCD_DSET_PSVT2_Msk) | (((t2)-1) << LCD_DSET_PSVT2_Pos))

/**
  * @brief      Set Charging Timeout Time
  *
  * @param[in]  value   The maximum timeout value, valid value is between 1 to 8192.
  *                     And one unit of timeout value is one LCD operation clock period.
  *
  *
  * @details    This macro is used to set maximum timeout time of charge pump charging timer.
  */
#define LCD_SET_CHARGE_TIMEOUT_TIME(value)  (LCD->DSET = (LCD->DSET & ~LCD_DSET_CTOUT_Msk) | (((value)-1) << LCD_DSET_CTOUT_Pos))

/**
  * @brief      Enable LCD Frame Counting End Interrupt
  *
  *
  *
  * @details    This macro is used to enable frame count end interrupt function.
  */
#define LCD_ENABLE_FRAME_COUNTING_END_INT()     (LCD->INTEN |= LCD_INTEN_FCEND_Msk)

/**
  * @brief      Disable LCD Frame Counting End Interrupt
  *
  *
  *
  * @details    This macro is used to disable frame count end interrupt function.
  */
#define LCD_DISABLE_FRAME_COUNTING_END_INT()    (LCD->INTEN &= ~LCD_INTEN_FCEND_Msk)

/**
  * @brief      Enable LCD Frame End Interrupt
  *
  *
  *
  * @details    This macro is used to enable frame end interrupt function.
  */
#define LCD_ENABLE_FRAME_END_INT()          (LCD->INTEN |= LCD_INTEN_FEND_Msk)

/**
  * @brief      Disable LCD Frame End Interrupt
  *
  *
  *
  * @details    This macro is used to disable frame end interrupt function.
  */
#define LCD_DISABLE_FRAME_END_INT()         (LCD->INTEN &= ~LCD_INTEN_FEND_Msk)

/**
  * @brief      Enable Charging Timeout Interrupt
  *
  *
  *
  * @details    This macro is used to enable charge pump charging timeout interrupt function.
  */
#define LCD_ENABLE_CHARGE_TIMEOUT_INT()     (LCD->INTEN |= LCD_INTEN_CTOUT_Msk)

/**
  * @brief      Disable Charging Timeout Interrupt
  *
  *
  *
  * @details    This macro is used to disable charge pump charging timeout interrupt function.
  */
#define LCD_DISABLE_CHARGE_TIMEOUT_INT()        (LCD->INTEN &= ~LCD_INTEN_CTOUT_Msk)

/**
  * @brief      Get LCD Frame Counting End Flag
  *
  *
  * @retval     0   Frame count end flag did not occur
  * @retval     1   Frame count end flag occurred
  *
  * @details    This macro gets frame count end flag.
  */
#define LCD_GET_FRAME_COUNTING_END_FLAG()       ((LCD->STS & LCD_STS_FCEND_Msk)? 1UL : 0UL)

/**
  * @brief      Clear LCD Frame Counting End Flag
  *
  *
  *
  * @details    This macro clears frame count end flag.
  */
#define LCD_CLEAR_FRAME_COUNTING_END_FLAG()     (LCD->STS = LCD_STS_FCEND_Msk)

/**
  * @brief      Get LCD Frame End Flag
  *
  *
  * @retval     0   Frame end flag did not occur
  * @retval     1   Frame end flag occurred
  *
  * @details    This macro gets frame end flag.
  */
#define LCD_GET_FRAME_END_FLAG()                ((LCD->STS & LCD_STS_FEND_Msk)? 1UL : 0UL)

/**
  * @brief      Clear LCD Frame End Flag
  *
  *
  *
  * @details    This macro clears frame end flag.
  */
#define LCD_CLEAR_FRAME_END_FLAG()              (LCD->STS = LCD_STS_FEND_Msk)

/**
  * @brief      Get Charging Timeout Flag
  *
  *
  * @retval     0   Charge pump timer timeout flag did not occur
  * @retval     1   Charge pump timer timeout flag occurred
  *
  * @details    This macro gets charge pump charging timeout flag.
  */
#define LCD_GET_CHARGE_TIMEOUT_FLAG()           ((LCD->STS & LCD_STS_CTOUT_Msk)? 1UL : 0UL)

/**
  * @brief      Clear Charging Timeout Flag
  *
  *
  *
  * @details    This macro clears charge pump charging timeout flag.
  */
#define LCD_CLEAR_CHARGE_TIMEOUT_FLAG()         (LCD->STS = LCD_STS_CTOUT_Msk)

/**
  * @brief      Get Charging Time
  *
  *
  * @return     Current 13-bit charging timer value
  *
  * @details    This macro gets charging timer value while stops charge pump charging.
  */
#define LCD_GET_CHARGE_TIME()              ((LCD->STS & LCD_STS_CTIME_Msk) >> 16)

/**
  * @brief      Set Output select
  *
  * @param      sel       The output function select value. Reference LCD Output Control Constant Definitions.
  *
  *
  * @details    This macro is used to set lcd output pin function.
  */
#define LCD_OUTPUT_SET(sel)              (LCD->OSET |= (sel))

/**
  * @brief      Reset Output select
  *
  * @param      sel:      The output function select mask.
  *
  *
  * @details    This macro is used to reset lcd output pin function to default.
  */
#define LCD_OUTPUT_RST(sel)              (LCD->OSET &= (~(sel)))

uint32_t LCD_Open(S_LCD_CFG_T *pLCDCfg);
void LCD_Close(void);
void LCD_SetPixel(uint32_t u32Com, uint32_t u32Seg, uint32_t u32OnFlag);
void LCD_SetAllPixels(uint32_t u32OnOff);
uint32_t LCD_EnableBlink(uint32_t u32ms);
void LCD_DisableBlink(void);
void LCD_EnableInt(uint32_t u32IntSrc);
void LCD_DisableInt(uint32_t u32IntSrc);
void LCD_SetSavingMode(uint32_t u32PowerSavingMode, uint32_t u32PowerSavingLevel);

/** @} end of group LCD_EXPORTED_FUNCTIONS */

/** @} end of group LCD_Driver */

/** @} end of group Standard_Driver */

#ifdef __cplusplus
}

#endif

#endif  /* __LCD_H__ */

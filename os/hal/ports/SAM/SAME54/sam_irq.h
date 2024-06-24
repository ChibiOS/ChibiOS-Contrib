#ifndef SAM_IRQ_H_
#define SAM_IRQ_H_


/* Vector offset calculation: Vector# = 0x40 + NVIC_line*4 */
/* SAM EIC HANDLER*/
#define SAM_EIC_EXTINT_0_HANDLER    Vector70
#define SAM_EIC_EXTINT_1_HANDLER    Vector74
#define SAM_EIC_EXTINT_2_HANDLER    Vector78
#define SAM_EIC_EXTINT_3_HANDLER    Vector7C
#define SAM_EIC_EXTINT_4_HANDLER    Vector80
#define SAM_EIC_EXTINT_5_HANDLER    Vector84
#define SAM_EIC_EXTINT_6_HANDLER    Vector88
#define SAM_EIC_EXTINT_7_HANDLER    Vector8C
#define SAM_EIC_EXTINT_8_HANDLER    Vector90
#define SAM_EIC_EXTINT_9_HANDLER    Vector94
#define SAM_EIC_EXTINT_10_HANDLER   Vector98
#define SAM_EIC_EXTINT_11_HANDLER   Vector9C
#define SAM_EIC_EXTINT_12_HANDLER   VectorA0
#define SAM_EIC_EXTINT_13_HANDLER   VectorA4
#define SAM_EIC_EXTINT_14_HANDLER   VectorA8
#define SAM_EIC_EXTINT_15_HANDLER   VectorAC

/* DMAC HANDLER*/
#define SAM_DMAC_0_HANDLER          VectorBC
#define SAM_DMAC_1_HANDLER          VectorC0
#define SAM_DMAC_2_HANDLER          VectorC4
#define SAM_DMAC_3_HANDLER          VectorC8
#define SAM_DMAC_4_31_HANDLER       VectorCC

/* SERCOM HANDLER */     
#define SAM_SERCOM_0_0_HANDLER      VectorF8
#define SAM_SERCOM_0_1_HANDLER      VectorFC
#define SAM_SERCOM_0_2_HANDLER      Vector100
#define SAM_SERCOM_0_3_HANDLER      Vector104
     
#define SAM_SERCOM_1_0_HANDLER      Vector108
#define SAM_SERCOM_1_1_HANDLER      Vector10C
#define SAM_SERCOM_1_2_HANDLER      Vector110
#define SAM_SERCOM_1_3_HANDLER      Vector114
     
#define SAM_SERCOM_2_0_HANDLER      Vector118
#define SAM_SERCOM_2_1_HANDLER      Vector11C
#define SAM_SERCOM_2_2_HANDLER      Vector120
#define SAM_SERCOM_2_3_HANDLER      Vector124
     
#define SAM_SERCOM_3_0_HANDLER      Vector128
#define SAM_SERCOM_3_1_HANDLER      Vector12C
#define SAM_SERCOM_3_2_HANDLER      Vector130
#define SAM_SERCOM_3_3_HANDLER      Vector134
     
#define SAM_SERCOM_4_0_HANDLER      Vector138
#define SAM_SERCOM_4_1_HANDLER      Vector13C
#define SAM_SERCOM_4_2_HANDLER      Vector140
#define SAM_SERCOM_4_3_HANDLER      Vector144
     
#define SAM_SERCOM_5_0_HANDLER      Vector148
#define SAM_SERCOM_5_1_HANDLER      Vector14C
#define SAM_SERCOM_5_2_HANDLER      Vector150
#define SAM_SERCOM_5_3_HANDLER      Vector154
     
#define SAM_SERCOM_6_0_HANDLER      Vector158
#define SAM_SERCOM_6_1_HANDLER      Vector15C
#define SAM_SERCOM_6_2_HANDLER      Vector160
#define SAM_SERCOM_6_3_HANDLER      Vector164
     
#define SAM_SERCOM_7_0_HANDLER      Vector168
#define SAM_SERCOM_7_1_HANDLER      Vector16C
#define SAM_SERCOM_7_2_HANDLER      Vector170
#define SAM_SERCOM_7_3_HANDLER      Vector174

/* USB HANDLER*/
#define SAM_USB_0_OTHER_HANDLER     Vector180
#define SAM_USB_1_SOF_HSOF_HANDLER  Vector184
#define SAM_USB_2_TRCPT0_HANDLER    Vector188
#define SAM_USB_3_TRCPT1_HANDLER    Vector18C

/* QSPI HANDLER*/
#define SAM_QSPI_HANDLER            Vector258

#endif


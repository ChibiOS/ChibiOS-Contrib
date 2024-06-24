#ifndef SAM_GCLK_ADD_H_
#define SAM_GCLK_ADD_H_

/* -------- GCLK_PCHCTRL : (GCLK Offset: 0x80) (R/W 32) Peripheral Clock Control -------- */
/* Add more as needed, only defined what is needed for the drivers that have already been done/planned */
/* If peripherial clock generation is required, use the generic clock generators in gclk.h for SAME*/

#define GCLK_PCHCTRL_ID_OSCCTRL_DFLL48          0
#define GCLK_PCHCTRL_ID_EIC_Val                 4
#define GCLK_PCHCTRL_ID_SERCOM0_CORE_Val        7
#define GCLK_PCHCTRL_ID_SERCOM1_CORE_Val        8
#define GCLK_PCHCTRL_ID_USB_Val                 10
#define GCLK_PCHCTRL_ID_EVSYS_0_Val             11
#define GCLK_PCHCTRL_ID_EVSYS_1_Val             12
#define GCLK_PCHCTRL_ID_EVSYS_2_Val             13
#define GCLK_PCHCTRL_ID_EVSYS_3_Val             14
#define GCLK_PCHCTRL_ID_EVSYS_4_Val             15
#define GCLK_PCHCTRL_ID_EVSYS_5_Val             16
#define GCLK_PCHCTRL_ID_EVSYS_6_Val             17
#define GCLK_PCHCTRL_ID_EVSYS_7_Val             18
#define GCLK_PCHCTRL_ID_EVSYS_8_Val             19
#define GCLK_PCHCTRL_ID_EVSYS_9_Val             20
#define GCLK_PCHCTRL_ID_EVSYS_10_Val            21
#define GCLK_PCHCTRL_ID_EVSYS_11_Val            22
#define GCLK_PCHCTRL_ID_SERCOM2_CORE_Val        23
#define GCLK_PCHCTRL_ID_SERCOM3_CORE_Val        24
#define GCLK_PCHCTRL_ID_SERCOM4_CORE_Val        34
#define GCLK_PCHCTRL_ID_SERCOM5_CORE_Val        35
#define GCLK_PCHCTRL_ID_SERCOM6_CORE_Val        36
#define GCLK_PCHCTRL_ID_SERCOM7_CORE_Val        37 

#endif /* SAM_GCLK_ADD_H_*/
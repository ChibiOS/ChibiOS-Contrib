How to use LETIMERx present on EFR32FG1X controllers as system tick.

Also see under demos/SILABS. 

1) In your mcuconf.h make sure, that:

#define EFR32_LETIM1SEL                 EFR32_LETIM1SEL_LFXO
#define EFR32_LETIM2SEL                 EFM32_LETIM2SEL_LFXO

or

#define EFM32_LETIM1SEL                 EFM32_LETIM1SEL_LFRCO
#define EFM32_LETIM2SEL                 EFM32_LETIM2SEL_LFRCO


2) In your chconf.h make sure, that:

#define CH_CFG_ST_RESOLUTION            16
#define CH_CFG_ST_TIMEDELTA             6
#define CH_CFG_ST_FREQUENCY             1024 // If LFXO used as src clk
#define CH_CFG_ST_FREQUENCY             1024 // If LFRCO used as src clk
#define CH_CFG_ST_FREQUENCY             1000 // If ULFRCO used as src clk


You can't use osDelay() or other "sleeping" functions for periods
longer than:
         LETIM_ARR_MAX + 1                    65536
----------------------------------- =  ------------------- seconds.
LETIM_CLOCK / LETIM_CLOCK_PRESCALER    CH_CFG_ST_FREQUENCY

For instance, with CH_CFG_ST_FREQUENCY = 1024 the period is 64 seconds.

Known good combinations of CH_CFG_ST_FREQUENCY/CH_CFG_ST_TIMEDELTA:
a) 1000/8 or 1024/8
b) 2000/4 or 2048/4
c) 4000/2 or 4096/2
d) 8000/2 or 8192/2

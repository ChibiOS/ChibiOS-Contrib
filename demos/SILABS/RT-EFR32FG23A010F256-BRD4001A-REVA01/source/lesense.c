#include "hal.h"
#include "ch.h"

#include <stdint.h>
#include "em_device.h"
#include "em_acmp.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_core.h"
#include "em_lesense.h"
#include "em_vdac.h"


struct LESENSEDriver {
};

typedef struct LESENSEDriver LESENSEDriver;

#define LCSENSE_STATE0           0
#define LCSENSE_STATE1           1
#define LCSENSE_STATE2           2
#define LCSENSE_STATE3           3
#define LCSENSE_ERROR_STRING     "ERROR"
#define INITIAL_STATE            0

/* PRS */
#define PRS_CHANNEL0             0
#define PRS_CHANNEL1             1

/* PCNT */
#define PCNT_TOP                 0xFFFF
#define PCNT_DIRCHANGE_STRING    "DIRCHNG"


/**************************************************************************//**
 * @brief LESENSE interrupt handler
 *        This function acknowledges the interrupt and reads the current
 *        decoder state
 ******************************************************************************/
OSAL_IRQ_HANDLER(EFR32_LESENSE_HANDLER) {

  uint32_t isr;

  OSAL_IRQ_PROLOGUE();

  // Clear all LESENSE interrupt flag
  isr = LESENSE_IntGet();
  LESENSE_IntClear(isr);

  if (isr & LESENSE_IF_DEC) {
    // Check current decoder state
    //decoder_state = LESENSE_DecoderStateGet();
  }

  OSAL_IRQ_EPILOGUE();
}

void initVdac(void) {

  #if 0
  // Enable the VDAC clock
  CMU->VDAC0CLKCTRL_SET = CMU_VDAC0CLKCTRL_CLKSEL_EM23GRPACLK; //CMU_VDAC0CLKCTRL_CLKSEL_HFRCOEM23;
  CMU->CLKEN1_SET = CMU_CLKEN1_VDAC0;

  VDAC_TypeDef *vdac = VDAC0;

  #if 0
  uint32_t config = (
    ((2  << _VDAC_CFG_WARMUPTIME_SHIFT) & _VDAC_CFG_WARMUPTIME_MASK)
    | (0 << _VDAC_CFG_DBGHALT_SHIFT)
    | (0 << _VDAC_CFG_ONDEMANDCLK_SHIFT)
    | (0 << _VDAC_CFG_DMAWU_SHIFT)
    | (0 << _VDAC_CFG_BIASKEEPWARM_SHIFT)
    | (0 << _VDAC_CFG_REFRESHPERIOD_SHIFT)
    | (0 << _VDAC_CFG_TIMEROVRFLOWPERIOD_SHIFT)
    | (0 << _VDAC_CFG_PRESC_SHIFT) & _VDAC_CFG_PRESC_MASK)
    | (0 << _VDAC_CFG_REFRSEL_SHIFT)
    | (0 << _VDAC_CFG_CH0PRESCRST_SHIFT)
    | (0 << _VDAC_CFG_SINERESET_SHIFT)
    | (0 << _VDAC_CFG_SINEMODE_SHIFT)
    | (0 << _VDAC_CFG_DIFF_SHIFT);

  vdac->CFG = config;

  uint32_t channelConfig =
       (0 << _VDAC_CH0CFG_KEEPWARM_SHIFT)
     | (0 << _VDAC_CH0CFG_HIGHCAPLOADEN_SHIFT)
     | ((0 << _VDAC_CH0CFG_FIFODVL_SHIFT) & _VDAC_CH0CFG_FIFODVL_MASK)
     | (0 << _VDAC_CH0CFG_REFRESHSOURCE_SHIFT)
     | (0 << _VDAC_CH0CFG_TRIGMODE_SHIFT)
     | (0 << _VDAC_CH0CFG_POWERMODE_SHIFT)
     | (0 << _VDAC_CH0CFG_CONVMODE_SHIFT); 

    vdac->CH0CFG = channelConfig;

    vdac->OUTTIMERCFG = ((uint32_t)(vdac->OUTTIMERCFG & ~(_VDAC_OUTTIMERCFG_CH0OUTHOLDTIME_MASK)))
                        | ((5 << _VDAC_OUTTIMERCFG_CH0OUTHOLDTIME_SHIFT) & _VDAC_OUTTIMERCFG_CH0OUTHOLDTIME_MASK);
    #endif

    vdac->CFG = (vdac->CFG & _VDAC_CFG_PRESC_MASK) | ((20 << _VDAC_CFG_PRESC_SHIFT) & _VDAC_CFG_PRESC_MASK);
    vdac->OUTCTRL_SET = VDAC_OUTCTRL_ABUSPORTSELCH0_PORTC | (3 << _VDAC_OUTCTRL_ABUSPINSELCH0_SHIFT) | VDAC_OUTCTRL_AUXOUTENCH0;
    vdac->CMD_SET = VDAC_CMD_CH0EN;

    vdac->EN_SET = _VDAC_EN_EN_MASK;

    while (true) {
      vdac->CH0F = 512;
      //osDelay(1);
      for (volatile int i = 0; i < 10000; i++);
    }

    #if 0
    vdac->OUTCTRL = ((uint32_t)(vdac->OUTCTRL & ~(_VDAC_OUTCTRL_ABUSPINSELCH0_MASK | _VDAC_OUTCTRL_ABUSPORTSELCH0_MASK | _VDAC_OUTCTRL_SHORTCH0_MASK | _VDAC_OUTCTRL_AUXOUTENCH0_MASK | _VDAC_OUTCTRL_MAINOUTENCH0_MASK)))
                    | (((uint32_t)init->pin          << _VDAC_OUTCTRL_ABUSPINSELCH0_SHIFT) & _VDAC_OUTCTRL_ABUSPINSELCH0_MASK)
                    | ((uint32_t)init->port          << _VDAC_OUTCTRL_ABUSPORTSELCH0_SHIFT)
                    | ((uint32_t)init->shortOutput   << _VDAC_OUTCTRL_SHORTCH0_SHIFT)
                    | ((uint32_t)init->auxOutEnable  << _VDAC_OUTCTRL_AUXOUTENCH0_SHIFT)
                    | ((uint32_t)init->mainOutEnable << _VDAC_OUTCTRL_MAINOUTENCH0_SHIFT);
    #endif
  #else
  // Use the HFRCOEM23 to clock the VDAC in order to operate in EM3 mode
  CMU_ClockSelectSet(cmuClock_VDAC0, cmuSelect_HFRCOEM23);

  // Enable the HFRCOEM23 and VDAC clocks
  CMU_ClockEnable(cmuClock_HFRCOEM23, true);
  CMU_ClockEnable(cmuClock_VDAC0, true);

  // Use default settings
  VDAC_Init_TypeDef        init        = VDAC_INIT_DEFAULT;
  VDAC_InitChannel_TypeDef initChannel = VDAC_INITCHANNEL_DEFAULT;

  // Calculate the VDAC clock prescaler value resulting in a 1 MHz VDAC clock
  init.prescaler = VDAC_PrescaleCalc(VDAC0, 1000000);

  // Clocking is requested on demand
  init.onDemandClk = false;

  // Disable High Capacitance Load mode
  initChannel.highCapLoadEnable = false;

  // Use Low Power mode
  initChannel.powerMode = vdacPowerModeLowPower;

  initChannel.port = vdacChPortC;
  initChannel.pin = 3;
  initChannel.auxOutEnable = true;
  initChannel.mainOutEnable = false;
  initChannel.shortOutput = false;

#if 0
  GPIO->CDBUSALLOC = GPIO_CDBUSALLOC_CDODD0_VDAC0CH0
      | GPIO_CDBUSALLOC_CDEVEN0_VDAC0CH0
      | GPIO_CDBUSALLOC_CDODD1_VDAC0CH1
      | GPIO_CDBUSALLOC_CDEVEN1_VDAC0CH1;
#endif
  GPIO->CDBUSALLOC = GPIO_CDBUSALLOC_CDODD0_VDAC0CH0;
  //GPIO->BBUSALLOC = GPIO_BBUSALLOC_BODD0_VDAC0CH0;


  // Initialize the VDAC and VDAC channel
  VDAC_Init(VDAC0, &init);
  VDAC_InitChannel(VDAC0, &initChannel, 0);

  // Enable the VDAC
  VDAC_Enable(VDAC0, 0, true);
  //writeDataDAC(VDAC0, DAC_DATA, DAC_CHANNEL);
  //VDAC0->OPA[0].TIMER &= ~0x03F00;
  //VDAC0->OPA[0].TIMER |= 1 << 16; //Set Settle time (number of clock cycles DAC is driven)

  VDAC_Channel0OutputSet(VDAC0, 1.0*4095/1.25);
  #endif
}

#if 0
/**************************************************************************//**
 * @brief  Sets up the ACMP to count LC sensor pulses
 *****************************************************************************/
void setupACMP(void){
  // ACMP configuration constant table.
  static const ACMP_Init_TypeDef initACMP ={
    .fullBias                 = true,                  // fullBias
    .biasProg                 = 0x1F,                  // biasProg
    .interruptOnFallingEdge   = false,                 // interrupt on rising edge
    .interruptOnRisingEdge    = false,                 // interrupt on falling edge
    .inputRange               = acmpInputRangeFull,    // Full ACMP range
    .accuracy                 = acmpAccuracyHigh,      // Low accuracy, low power consumption
    .powerSource              = acmpPowerSourceAvdd,   // Use AVDD as power source
    .hysteresisLevel_0        = acmpHysteresisLevel0,  // hysteresis level 0
    .hysteresisLevel_1        = acmpHysteresisLevel0,  // hysteresis level 1
    .vlpInput                 = acmpVLPInputVADIV,     // Use VADIV as the VLP input source.
    .inactiveValue            = false,                 // inactive value
    .enable                   = true                   // Enable after init.
  };

  static const ACMP_VAConfig_TypeDef initVa ={
    acmpVAInputVDD,                                    // Use VDD as input for VA
    0x0C,                                              // VA divider when ACMP output is 0
    0x0B                                               // VA divider when ACMP output is 1
  };

  CMU_ClockEnable(cmuClock_ACMP0, true);

  // Initialize ACMP
  ACMP_Init(ACMP0, &initACMP);

  // Setup VADIV
  ACMP_VASetup(ACMP0, &initVa);

  // ACMP0 input channels
  ACMP_ChannelSet(ACMP0, acmpInputVADIV, acmpInputAPORT0XCH0);

  // Enable LESENSE control of ACMP
  ACMP_ExternalInputSelect(ACMP0, acmpExternalInputAPORT0X);
}

/**************************************************************************//**
 * @brief  Sets up the LESENSE
 *****************************************************************************/
void setupLESENSE(void){
  // LESENSE configuration structure
  static const LESENSE_Init_TypeDef initLesense ={
    .coreCtrl         ={
      .scanStart    = lesenseScanStartPeriodic,
      .prsSel       = lesensePRSCh0,
      .scanConfSel  = lesenseScanConfDirMap,
      .invACMP0     = false,
      .invACMP1     = false,
      .dualSample   = false,
      .storeScanRes = false,
      .bufOverWr    = true,
      .bufTrigLevel = lesenseBufTrigHalf,
      .wakeupOnDMA  = lesenseDMAWakeUpDisable,
      .biasMode     = lesenseBiasModeDutyCycle,
      .debugRun     = false
    },

    .timeCtrl         ={
      .startDelay     = 0
    },

    .perCtrl ={
      .dacCh0Data     = lesenseDACIfData,
      .dacCh1Data     = lesenseDACIfData,
      .acmp0Mode      = lesenseACMPModeMux,
      .acmp1Mode      = lesenseACMPModeDisable,
      .warmupMode     = lesenseWarmupModeNormal,
      .dacScan        = true,
      .dacStartupHalf = true,
      .dacCh0En       = true

    },

    .decCtrl          ={
      .decInput  = lesenseDecInputSensorSt,
      .initState = 0,
      .chkState  = false,
      .intMap    = false,
      .hystPRS0  = false,
      .hystPRS1  = false,
      .hystPRS2  = false,
      .hystIRQ   = false,
      .prsCount  = true,
      .prsChSel0 = lesensePRSCh0,
      .prsChSel1 = lesensePRSCh1,
      .prsChSel2 = lesensePRSCh2,
      .prsChSel3 = lesensePRSCh3
    }
  };
  // Channel configuration
  static  LESENSE_ChDesc_TypeDef initLesenseCh ={
    .enaScanCh     = true,
    .enaPin        = true,
    .enaInt        = false,
    .chPinExMode   = lesenseChPinExLow,
    .chPinIdleMode = lesenseChPinIdleDACC,
    .useAltEx      = false,
    .shiftRes      = true,
    .invRes        = true,
    .storeCntRes   = true,
    .exClk         = lesenseClkHF,
    .sampleClk     = lesenseClkLF,
    .exTime        = 0x07,
    .sampleDelay   = 0x02,
    .measDelay     = 0x00,
    .acmpThres     = 0x00,
    .sampleMode    = lesenseSampleModeCounter,
    .intMode       = lesenseSetIntPosEdge,
    .cntThres      = 0x0000,
    .compMode      = lesenseCompModeLess,
    .evalMode      = lesenseEvalModeSlidingWindow
  };

  // Configure LC sense excitation/measure pin as push pull
  GPIO_PinModeSet(LCSENSE_CH_PORT, LCSENSE_CH_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(LCSENSE_CH_PORT, LCSENSE_CH_PIN+1, gpioModePushPull, 0);
  GPIO_PinModeSet(LCSENSE_CH_PORT, LCSENSE_CH_PIN+3, gpioModePushPull, 0);

  // Use LFXO as LESENSE clock source since it is already used by the RTCC
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_CORELE, true);
  CMU_ClockEnable(cmuClock_LESENSE, true);

  // Initialize LESENSE interface _with_ RESET
  LESENSE_Init(&initLesense, true);

  // Configure channels
  LESENSE_ChannelConfig(&initLesenseCh, LCSENSE_CH);
  LESENSE_ChannelConfig(&initLesenseCh, LCSENSE_CH+1);
  initLesenseCh.shiftRes = false;
  initLesenseCh.invRes   = true;
  LESENSE_ChannelConfig(&initLesenseCh, LCSENSE_CH+3);

  LESENSE_ChannelSlidingWindow(LCSENSE_CH, 4, 20);
  LESENSE_ChannelSlidingWindow(LCSENSE_CH+1, 4, 20);
  LESENSE_ChannelSlidingWindow(LCSENSE_CH+3, 4, 20);
  // Set scan frequency
  LESENSE_ScanFreqSet(0, LCSENSE_SCAN_FREQ);

  // Set clock divisor for LF clock
  LESENSE_ClkDivSet(lesenseClkLF, lesenseClkDiv_2);
  // Set clock divisor for HF clock
  LESENSE_ClkDivSet(lesenseClkHF, lesenseClkDiv_1);

  // Enable interrupt in NVIC
  NVIC_EnableIRQ(LESENSE_IRQn);

  // Enable LC sensor
  LESENSE_ChannelEnable(LCSENSE_CH, true, true);
  LESENSE_ChannelEnable(LCSENSE_CH+1, true, true);
  LESENSE_ChannelEnable(LCSENSE_CH+3, true, true);


  /* Configure decoder
   * Interrupts will be enabled for transitions between
   * states 0 and 3 to show the pulse counter value
   * Configuration structure for state 0 */
  LESENSE_DecStDesc_TypeDef decConf ={
    .chainDesc = false,
    .confA     ={
      .compVal   = 0x02,
      .compMask  = 0x0,
      .nextState = LCSENSE_STATE1,
      .prsAct    = lesenseTransActNone,
      .setInt    = false
    },
    .confB       ={
      .compVal   = 0x01,
      .compMask  = 0x0,
      .nextState = LCSENSE_STATE3,
      .prsAct    = lesenseTransActDown,
      .setInt    = false
    }
  };
  /* Configure state 0 */
  LESENSE_DecoderStateConfig(&decConf, LCSENSE_STATE0);

  /* Change necessary structure fields for state 1 */
  decConf.confA.compVal   = 0x03;
  decConf.confA.nextState = LCSENSE_STATE2;
  decConf.confA.prsAct    = lesenseTransActNone;
  decConf.confA.setInt    = false;
  decConf.confB.compVal   = 0x00;
  decConf.confB.nextState = LCSENSE_STATE0;
  decConf.confB.prsAct    = lesenseTransActNone;
  decConf.confB.setInt    = false;
  /* Configure state 1 */
  LESENSE_DecoderStateConfig(&decConf, LCSENSE_STATE1);

  /* Change necessary structure fields for state 2 */
  decConf.confA.compVal   = 0x01;
  decConf.confA.nextState = LCSENSE_STATE3;
  decConf.confA.prsAct    = lesenseTransActNone;
  decConf.confA.setInt    = false;
  decConf.confB.compVal   = 0x02;
  decConf.confB.nextState = LCSENSE_STATE1;
  decConf.confB.prsAct    = lesenseTransActNone;
  decConf.confB.setInt    = false;
  /* Configure state 2 */
  LESENSE_DecoderStateConfig(&decConf, LCSENSE_STATE2);

  /* Change necessary structure fields for state 3 */
  decConf.confA.compVal   = 0x00;
  decConf.confA.nextState = LCSENSE_STATE0;
  decConf.confA.prsAct    = lesenseTransActUp;
  decConf.confA.setInt    = false;
  decConf.confB.compVal   = 0x03;
  decConf.confB.nextState = LCSENSE_STATE2;
  decConf.confB.prsAct    = lesenseTransActNone;
  decConf.confB.setInt    = false;
  /* Configure state 3 */
  LESENSE_DecoderStateConfig(&decConf, LCSENSE_STATE3);

  /* Set initial decoder state to 0 */
  LESENSE_DecoderStateSet(INITIAL_STATE);


  LESENSE_DecoderStart();

  // Start continuous scan
  LESENSE_ScanStart();
}

/**************************************************************************//**
 * @brief  Sets up the PCNT
 *****************************************************************************/
void setupPCNT(void){
  /* PCNT configuration constant table. */
  static const PCNT_Init_TypeDef initPCNT ={
    .mode        = pcntModeOvsSingle,  /* Oversampling, single mode. */
    .counter     = 0,                 /* Counter value has been initialized to 0. */
    .top         = PCNT_TOP,           /* Counter top value. */
    .negEdge     = false,              /* Use positive edge. */
    .countDown   = false,              /* Up-counting. */
    .filter      = false,              /* Filter disabled. */
    .hyst        = false,              /* Hysteresis disabled. */
    .s1CntDir    = true,               /* Counter direction is given by S1. */
    .cntEvent    = pcntCntEventBoth,   /* Regular counter counts up on upcount events. */
    .auxCntEvent = pcntCntEventNone,   /* Auxiliary counter doesn't respond to events. */
    .s0PRS       = pcntPRSCh0,         /* PRS channel 0 selected as S0IN. */
    .s1PRS       = pcntPRSCh1          /* PRS channel 1 selected as S1IN. */
  };

  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_PCNT0, true);

  /* Initialize PCNT. */
  PCNT_Init(PCNT0, &initPCNT);

  /* Enable PRS input S0 in PCNT. */
  PCNT_PRSInputEnable(PCNT0, pcntPRSInputS0, true);

  /* Enable PRS input S0 in PCNT. */
  PCNT_PRSInputEnable(PCNT0, pcntPRSInputS1, true);

  /* Clear all pending interrupts */
  PCNT_IntClear(PCNT0, 0xFFFF);

  /* Enable the PCNT overflow interrupt. */
  PCNT_IntEnable(PCNT0, PCNT_IEN_DIRCNG);

  /* Enable the PCNT vector in NVIC */
  NVIC_EnableIRQ(PCNT0_IRQn);
}

/**************************************************************************//**
 * @brief  Sets up the PRS
 *****************************************************************************/
void setupPRS(void){
  CMU_ClockEnable(cmuClock_PRS, true);
  /* PRS channel 0 configuration. */
  PRS_SourceAsyncSignalSet(PRS_CHANNEL0, PRS_CH_CTRL_SOURCESEL_LESENSED, PRS_CH_CTRL_SIGSEL_LESENSEDEC0);
  /* PRS channel 0 configuration. */
  PRS_SourceAsyncSignalSet(PRS_CHANNEL1, PRS_CH_CTRL_SOURCESEL_LESENSED, PRS_CH_CTRL_SIGSEL_LESENSEDEC1);
}
#endif

void lesenseObjectInit(LESENSEDriver* lesensep) {

  /*
  CMU->LESENSEHFCLKCTRL = (CMU->LESENSEHFCLKCTRL & ~_CMU_LESENSEHFCLKCTRL_CLKSEL_MASK) \
                            | CMU_LESENSEHFCLKCTRL_CLKSEL_HFRCOEM23;
  */

  //CMU->LESENSEHFCLKCTRL_SET = CMU_LESENSEHFCLKCTRL_CLKSEL_HFRCOEM23;
  //CMU->LESENSEHFCLKCTRL_SET = CMU_LESENSEHFCLKCTRL_CLKSEL_HFRCOEM23;

  initVdac();

  //setupACMP();

  //setupPCNT();

  //setupPRS();

  //setupLESENSE();
}
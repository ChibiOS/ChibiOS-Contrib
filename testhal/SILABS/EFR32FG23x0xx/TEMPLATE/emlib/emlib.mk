# Required platform files.
GECKO_SDK = $(CHIBIOS_CONTRIB)/ext/gecko_sdk

EMLIBSRC = \
               emlib/emlib_chibios.c \
               $(GECKO_SDK)/platform/common/src/sl_assert.c \
               $(GECKO_SDK)/platform/emlib/src/em_acmp.c \
               $(GECKO_SDK)/platform/emlib/src/em_adc.c \
               $(GECKO_SDK)/platform/emlib/src/em_aes.c \
               $(GECKO_SDK)/platform/emlib/src/em_burtc.c \
               $(GECKO_SDK)/platform/emlib/src/em_can.c \
               $(GECKO_SDK)/platform/emlib/src/em_cmu.c \
               $(GECKO_SDK)/platform/emlib/src/em_cmu_fpga.c \
               $(GECKO_SDK)/platform/emlib/src/em_cryotimer.c \
               $(GECKO_SDK)/platform/emlib/src/em_crypto.c \
               $(GECKO_SDK)/platform/emlib/src/em_csen.c \
               $(GECKO_SDK)/platform/emlib/src/em_dac.c \
               $(GECKO_SDK)/platform/emlib/src/em_dbg.c \
               $(GECKO_SDK)/platform/emlib/src/em_dma.c \
               $(GECKO_SDK)/platform/emlib/src/em_ebi.c \
               $(GECKO_SDK)/platform/emlib/src/em_emu.c \
               $(GECKO_SDK)/platform/emlib/src/em_eusart.c \
               $(GECKO_SDK)/platform/emlib/src/em_gpcrc.c \
               $(GECKO_SDK)/platform/emlib/src/em_gpio.c \
               $(GECKO_SDK)/platform/emlib/src/em_i2c.c \
               $(GECKO_SDK)/platform/emlib/src/em_iadc.c \
               $(GECKO_SDK)/platform/emlib/src/em_idac.c \
               $(GECKO_SDK)/platform/emlib/src/em_lcd.c \
               $(GECKO_SDK)/platform/emlib/src/em_ldma.c \
               $(GECKO_SDK)/platform/emlib/src/em_lesense.c \
               $(GECKO_SDK)/platform/emlib/src/em_letimer.c \
               $(GECKO_SDK)/platform/emlib/src/em_leuart.c \
               $(GECKO_SDK)/platform/emlib/src/em_msc.c \
               $(GECKO_SDK)/platform/emlib/src/em_opamp.c \
               $(GECKO_SDK)/platform/emlib/src/em_pcnt.c \
               $(GECKO_SDK)/platform/emlib/src/em_pdm.c \
               $(GECKO_SDK)/platform/emlib/src/em_prs.c \
               $(GECKO_SDK)/platform/emlib/src/em_qspi.c \
               $(GECKO_SDK)/platform/emlib/src/em_rmu.c \
               $(GECKO_SDK)/platform/emlib/src/em_rtc.c \
               $(GECKO_SDK)/platform/emlib/src/em_rtcc.c \
               $(GECKO_SDK)/platform/emlib/src/em_se.c \
               $(GECKO_SDK)/platform/emlib/src/em_system.c \
               $(GECKO_SDK)/platform/emlib/src/em_timer.c \
               $(GECKO_SDK)/platform/emlib/src/em_usart.c \
               $(GECKO_SDK)/platform/emlib/src/em_vcmp.c \
               $(GECKO_SDK)/platform/emlib/src/em_vdac.c \
               $(GECKO_SDK)/platform/emlib/src/em_wdog.c

#EMLIBSRC += $(GECKO_SDK)/platform/emlib/src/em_core.c
#EMLIBSRC += $(GECKO_SDK)/platform/Device/SiliconLabs/EFR32FG23/Source/system_efr32fg23.c
#EMLIBSRC += $(GECKO_SDK)/platform/security/sl_component/sl_trustzone/src/sli_tz_service_syscfg_ns.c

EMLIBINC = \
               emlib \
               $(GECKO_SDK)/platform/security/sl_component/sl_trustzone/inc/common \
               $(GECKO_SDK)/platform/security/sl_component/sl_trustzone/inc/secure \
               $(GECKO_SDK)/platform/security/sl_component/sl_trustzone/inc/nonsecure \
               $(GECKO_SDK)/util/third_party/trusted-firmware-m/interface/include \
               $(GECKO_SDK)/platform/common/inc \
               $(GECKO_SDK)/platform/emlib/inc

# Shared variables
ALLCSRC += $(EMLIBSRC)
ALLINC  += $(EMLIBINC)

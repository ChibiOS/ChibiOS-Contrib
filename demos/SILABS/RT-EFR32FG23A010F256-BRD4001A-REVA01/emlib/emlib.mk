# Required platform files.
GECKO_SDK = $(CHIBIOS_CONTRIB)/ext/gecko_sdk

EMLIBSRC = \
               emlib/emlib_chibios.c \
               $(GECKO_SDK)/platform/Device/SiliconLabs/EFR32FG23/Source/system_efr32fg23.c \
               $(GECKO_SDK)/platform/common/src/sl_assert.c \
               $(GECKO_SDK)/platform/emlib/src/em_acmp.c \
               $(GECKO_SDK)/platform/emlib/src/em_cryotimer.c \
               $(GECKO_SDK)/platform/emlib/src/em_cmu.c \
               $(GECKO_SDK)/platform/emlib/src/em_emu.c \
               $(GECKO_SDK)/platform/emlib/src/em_eusart.c \
               $(GECKO_SDK)/platform/emlib/src/em_gpio.c \
               $(GECKO_SDK)/platform/emlib/src/em_letimer.c \
               $(GECKO_SDK)/platform/emlib/src/em_pcnt.c \
               $(GECKO_SDK)/platform/emlib/src/em_prs.c \
               $(GECKO_SDK)/platform/emlib/src/em_lesense.c \
               $(GECKO_SDK)/platform/emlib/src/em_lcd.c \
               $(GECKO_SDK)/platform/emlib/src/em_system.c \
               $(GECKO_SDK)/platform/emlib/src/em_vdac.c

               #$(GECKO_SDK)/platform/security/sl_component/sl_trustzone/src/sli_tz_service_syscfg_ns.c \

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

# Required platform files.
EMLIBSRC = \
               emlib/emlib_chibios.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/Device/SiliconLabs/EFR32FG23/Source/system_efr32fg23.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/common/src/sl_assert.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_acmp.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_cryotimer.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_cmu.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_emu.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_eusart.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_gpio.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_letimer.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_pcnt.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_prs.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_lesense.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_lcd.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_system.c \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/src/em_vdac.c

               #$(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/security/sl_component/sl_trustzone/src/sli_tz_service_syscfg_ns.c \

EMLIBINC = \
               emlib \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/security/sl_component/sl_trustzone/inc/common \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/security/sl_component/sl_trustzone/inc/secure \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/security/sl_component/sl_trustzone/inc/nonsecure \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/util/third_party/trusted-firmware-m/interface/include \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/common/inc \
               $(CHIBIOS_CONTRIB)/ext/gecko-sdk/platform/emlib/inc

# Shared variables
ALLCSRC += $(EMLIBSRC)
ALLINC  += $(EMLIBINC)

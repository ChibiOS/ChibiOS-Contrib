M251PLATFORM := $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/M251
M251EXTROOT := $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/Nuvoton/NUMICRO
M251EXT := $(M251EXTROOT)/M251
M251LLDS := hal_pal_lld.c hal_serial_lld.c hal_usb_lld.c hal_gpt_lld.c \
            hal_efl_lld.c hal_pwm_lld.c hal_i2c_lld.c hal_spi_lld.c \
            hal_wdg_lld.c

PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(M251PLATFORM)/hal_lld.c \
               $(M251PLATFORM)/hal_st_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(M251PLATFORM) \
               $(M251EXTROOT) \
               $(M251EXT)

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)
HALCONF := $(strip $(shell cat $(CONFDIR)/halconf.h \
                              $(CONFDIR)/halconf_community.h 2>/dev/null | \
                              grep -E -e "[#]define"))

ifneq ($(findstring HAL_USE_PAL TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_pal_lld.c
endif
ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_serial_lld.c
endif
ifneq ($(findstring HAL_USE_USB TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_usb_lld.c
endif
ifneq ($(findstring HAL_USE_GPT TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_gpt_lld.c
endif
ifneq ($(findstring HAL_USE_EFL TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_efl_lld.c
endif
ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_i2c_lld.c
endif
ifneq ($(findstring HAL_USE_PWM TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_pwm_lld.c
endif
ifneq ($(findstring HAL_USE_SPI TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_spi_lld.c
endif
ifneq ($(findstring HAL_USE_WDG TRUE,$(HALCONF)),)
PLATFORMSRC += $(M251PLATFORM)/hal_wdg_lld.c
endif
else
PLATFORMSRC += $(addprefix $(M251PLATFORM)/,$(M251LLDS))
endif

# Shared variables.
ALLCSRC    += $(PLATFORMSRC)
ALLXASMSRC += $(PLATFORMASM)
ALLINC     += $(PLATFORMINC)

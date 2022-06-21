# Required platform files.
PLATFORMSRC_CONTRIB := ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/hal_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/common/RISCV-ECLIC/eclic.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/gd32_isr.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/hal_efl_lld.c

# Required include directories.
PLATFORMINC_CONTRIB := ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103 \
               ${CHIBIOS_CONTRIB}/os/hal/ports/common/RISCV-ECLIC

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(HALCONFDIR),)
  ifeq ($(CONFDIR),)
    HALCONFDIR = .
  else
    HALCONFDIR := $(CONFDIR)
  endif
endif

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h $(HALCONFDIR)/halconf_community.h | egrep -e "\#define"))

ifneq ($(findstring HAL_USE_ADC TRUE,$(HALCONF)),)
PLATFORMSRC_CONTRIB += $(CHIBIOS_CONTRIB)/os/hal/ports/GD/GD32VF103/hal_adc_lld.c
endif
else
PLATFORMSRC_CONTRIB += $(CHIBIOS_CONTRIB)/os/hal/ports/GD/GD32VF103/hal_adc_lld.c
endif

# Drivers compatible with the platform.
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/CANv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/CRCv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/DACv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/DMAv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/GPIOv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/I2Cv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/RTCv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/SPIv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/TIMv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/USARTv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/OTGv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/xWDGv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)

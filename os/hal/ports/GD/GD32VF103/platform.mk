# List of all the template platform files.
ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(CONFDIR),)
  CONFDIR = .
endif

HALCONF := $(strip $(shell cat $(CONFDIR)/halconf.h | egrep -e "\#define"))

PLATFORMSRC := ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/hal_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/common/RISCV-ECLIC/eclic.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/gd32_isr.c

else
PLATFORMSRC = ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/hal_lld.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/common/RISCV-ECLIC/eclic.c \
              ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/gd32_isr.c
endif

# Required include directories
PLATFORMINC = ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103 \
              ${CHIBIOS_CONTRIB}/os/hal/ports/common/RISCV-ECLIC

ifneq ($(findstring HAL_USE_ADC TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/GD/GD32VF103/hal_adc_lld.c
endif

# Drivers compatible with the platform.
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/CAN/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/DAC/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/DMA/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/GPIO/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/I2C/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/RTC/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/SPI/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/TIM/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/USART/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/OTG/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/GD/GD32VF103/xWDG/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)
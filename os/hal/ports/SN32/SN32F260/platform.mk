# Required platform files.
PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F260/hal_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F260

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

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))

else
endif

# Drivers compatible with the platform.
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/GPIO/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/USB/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/CT/driver.mk


# include $(CHIBIOS)/os/hal/ports/SN32/LLD/TIM/driver.mk
# include $(CHIBIOS)/os/hal/ports/SN32/LLD/GPIOv3/driver.mk
# include $(CHIBIOS)/os/hal/ports/SN32/LLD/USBv1/driver.mk
# include $(CHIBIOS)/os/hal/ports/SN32/LLD/TIMv1/driver.mk

# PLATFORMINC += $(CHIBIOS)/os/hal/templates/
# PLATFORMSRC += ${CHIBIOS}/os/hal/templates/hal_usb_lld.c

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMSRC_CONTRIB)
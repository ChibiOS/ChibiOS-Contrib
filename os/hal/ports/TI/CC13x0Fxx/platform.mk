# List of all the platform files.
PLATFORMSRC_CONTRIB = $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
		        $(CHIBIOS_CONTRIB)/os/hal/ports/TI/CC13x0Fxx/hal_lld.c


# Required include directories
PLATFORMINC_CONTRIB = $(CHIBIOS)/os/hal/ports/common/ARMCMx \
                        $(CHIBIOS_CONTRIB)/os/hal/ports/TI/CC13x0Fxx

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
endif #ifeq ($(USE_SMART_BUILD), yes)

# Drivers compatible with the platform.
include $(CHIBIOS_CONTRIB)/os/hal/ports/TI/LLD/SYSTICKv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)

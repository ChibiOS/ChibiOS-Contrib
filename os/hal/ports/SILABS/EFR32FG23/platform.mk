# Required platform files.
PLATFORMSRC_CONTRIB := \
               $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SILABS/EFR32FG23/hal_lld.c

# Required include directories.
PLATFORMINC_CONTRIB := \
               $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SILABS/EFR32FG23 \
               ${CHIBIOS_CONTRIB}/os/hal/ports/SILABS/LLD/EFR32FG23 \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SILABS/LLD/common

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

HALCONF := $(strip $(shell cat $(CONFDIR)/halconf.h $(CONFDIR)/halconf_community.h | egrep -e "\#define"))

else
endif

# Drivers compatible with the platform.
#include ${CHIBIOS_CONTRIB}/os/hal/ports/SILABS/LLD/common/SYSTICKv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SILABS/LLD/EFR32FG23/SYSTICKv3/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SILABS/LLD/EFR32FG23/GPIOv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SILABS/LLD/EFR32FG23/EUSARTv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)

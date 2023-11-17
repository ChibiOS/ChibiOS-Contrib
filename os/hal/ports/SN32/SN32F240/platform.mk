# Required platform files.
PLATFORMSRC_CONTRIB := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F240/hal_lld.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F240/hal_efl_lld.c

# Required include directories.
PLATFORMINC_CONTRIB := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F24x \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F240

ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(CONFDIR),)
  CONFDIR = .
endif

HALCONF := $(strip $(shell cat $(CONFDIR)/halconf.h $(CONFDIR)/halconf_community.h | egrep -e "\#define"))

endif

# Drivers compatible with the platform.
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F24x/GPIO/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F24x/USB/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F24x/CT/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)
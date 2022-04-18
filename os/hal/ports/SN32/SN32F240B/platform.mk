# Required platform files.
PLATFORMSRC_CONTRIB := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F240B/hal_lld.c

# Required include directories.
PLATFORMINC_CONTRIB := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F240B

ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(CONFDIR),)
  CONFDIR = .
endif

HALCONF := $(strip $(shell cat $(CONFDIR)/halconf.h $(CONFDIR)/halconf_community.h | egrep -e "\#define"))

endif

# Drivers compatible with the platform.
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx/GPIO/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx/USB/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx/CT/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx/FLASH/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx/SysTick/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx/SPI/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx/WDT/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)
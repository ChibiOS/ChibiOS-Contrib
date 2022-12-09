# Required platform files.
PLATFORMSRC_CONTRIB := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/SAMD21A/sam_clk.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/SAMD21A/hal_lld.c \
			   $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/SAMD21A/hal_efl_lld.c \

# Required include directories.
PLATFORMINC_CONTRIB := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/SAMD21A

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
include $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/LLD/DMACv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/LLD/ADCv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/LLD/PORTv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/LLD/SYSTICKv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/SAM/LLD/SERCOMv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)

# List of all the platform files.
PLATFORMSRC = $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
			$(CHIBIOS_CONTRIB)/os/hal/ports/ES32/FS026/hal_lld.c


# Required include directories
PLATFORMINC = $(CHIBIOS)/os/hal/ports/common/ARMCMx \
              $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/FS026

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
include $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/ADCv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/I2Cv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/TIMv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/SPIv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/GPIOv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/USBv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/UARTv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/WDTv1/driver.mk


# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)

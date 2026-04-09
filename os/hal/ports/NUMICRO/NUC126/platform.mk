PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/NUC126/hal_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/NUC126 \
               $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)
HALCONF := $(strip $(shell cat $(CONFDIR)/halconf.h $(CONFDIR)/halconf_community.h | egrep -e "\#define"))
endif

# Drivers compatible with the platform.
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/GPIOv2/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/TIMv2/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/USBv2/driver.mk

# Shared variables
ALLCSRC    += $(PLATFORMSRC)
ALLXASMSRC += $(PLATFORMASM)
ALLINC     += $(PLATFORMINC)

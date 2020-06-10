PLATFORMSRC_CONTRIB := ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
                       ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/MIMXRT1062/hal_lld.c \
                       ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/PITv1/hal_st_lld.c
                       
PLATFORMINC_CONTRIB := ${CHIBIOS}/os/hal/ports/common/ARMCMx \
                       ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD \
                       ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/MIMXRT1062
                       
ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(CONFDIR),)
  CONFDIR = .
endif

HALCONF := $(strip $(shell cat $(CONFDIR)/halconf.h $(CONFDIR)/halconf_community.h | egrep -e "\#define"))

endif

include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/GPIOv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/UARTv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/SPIv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/I2Cv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/PORTv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/ADCv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/PITv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/SDHCv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/FTMv1/driver.mk
include ${CHIBIOS_CONTRIB}/os/hal/ports/MIMXRT1062/LLD/USBHSv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC_CONTRIB)
ALLINC  += $(PLATFORMINC_CONTRIB)

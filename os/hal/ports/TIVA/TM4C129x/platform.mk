# Required platform files.
PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C129x/hal_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               ${CHIBIOS_CONTRIB}/os/hal/ports/TIVA/TM4C129x

ifeq ($(USE_SMART_BUILD),yes)
HALCONF := $(strip $(shell cat halconf.h | egrep -e "\#define"))
endif

# Drivers compatible with the platform.
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/ADC/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/GPIO/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/GPTM/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/I2C/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/MAC/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/PWM/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/SSI/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/UART/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/uDMA/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/TIVA/LLD/WDT/driver.mk

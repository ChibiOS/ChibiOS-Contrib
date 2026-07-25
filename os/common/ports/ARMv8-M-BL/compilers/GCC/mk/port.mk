# List of the ChibiOS/RT ARMv8-M Baseline (Cortex-M23) port files.

# Dependencies.
include $(CHIBIOS)/os/common/portability/GCC/ccportab.mk
ifneq ($(wildcard $(CHIBIOS)/os/common/ports/ARM-common/arm-common.mk),)
include $(CHIBIOS)/os/common/ports/ARM-common/arm-common.mk
ARMV8MBL_COMMONINC =
else
ARMV8MBL_COMMONINC = $(CHIBIOS)/os/common/portability/GCC \
                     $(CHIBIOS)/os/common/ports/ARM-common
endif

PORTSRC = $(CHIBIOS_CONTRIB)/os/common/ports/ARMv8-M-BL/chcore.c

PORTASM = $(CHIBIOS_CONTRIB)/os/common/ports/ARMv8-M-BL/compilers/GCC/chcoreasm.S

PORTINC = $(ARMV8MBL_COMMONINC) \
          $(CHIBIOS_CONTRIB)/os/common/ports/ARMv8-M-BL

# Shared variables
ALLCSRC    += $(PORTSRC)
ALLXASMSRC += $(PORTASM)
ALLINC     += $(PORTINC)

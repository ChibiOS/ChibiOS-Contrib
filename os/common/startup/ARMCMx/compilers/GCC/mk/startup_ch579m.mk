# CH579M startup files (ARM Cortex-M0, ARMv6-M).
#
# Uses the generic ChibiOS ARMv6-M startup (crt0_v6m.S + vectors.S)
# with WCH's CH579M CMSIS device header for the vector table layout.
#
# The system_ch579m.c provides SystemInit() which is called from crt0;
# our hal_lld_init() then does the PLL switch in __early_init().

STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c

STARTUPASM = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt0_v6m.S \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.S

STARTUPINC = $(CHIBIOS)/os/common/portability/GCC \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld \
             $(CHIBIOS)/os/common/ext/ARM/CMSIS/Core/Include \
             $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/devices/CH579 \
             $(CHIBIOS_CONTRIB)/os/hal/ports/WCH/CH579 \
             $(KEYBOARD_PATH_1)/ld

STARTUPLD         = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld
STARTUPLD_CONTRIB = $(KEYBOARD_PATH_1)/ld

LDFLAGS += -L$(KEYBOARD_PATH_1)/ld

# Shared variables
ALLXASMSRC += $(STARTUPASM)
ALLCSRC    += $(STARTUPSRC)
ALLINC     += $(STARTUPINC)

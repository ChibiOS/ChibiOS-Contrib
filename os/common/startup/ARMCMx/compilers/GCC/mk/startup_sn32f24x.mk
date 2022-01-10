# List of the ChibiOS generic SN32F24x startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/SONiX/SN32F2xx/system_SN32F240.c

STARTUPASM = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt0_v6m.S \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.S

STARTUPINC = $(CHIBIOS)/os/common/portability/GCC \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld \
             $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/devices/SN32F24x \
             $(CHIBIOS)/os/common/ext/ARM/CMSIS/Core/Include \
             $(CHIBIOS_CONTRIB)/os/common/ext/SONiX/SN32F2xx

STARTUPLD  = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld
STARTUPLD_CONTRIB  = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/ld

# Shared variables
ALLXASMSRC += $(STARTUPASM)
ALLCSRC    += $(STARTUPSRC)
ALLINC     += $(STARTUPINC)
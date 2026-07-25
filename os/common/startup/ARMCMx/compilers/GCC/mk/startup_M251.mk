# List of the ChibiOS generic M251/M252 startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c

STARTUPASM = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/crt0_v8m-bl.S \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.S

STARTUPINC = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/devices/M251 \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld \
             $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/ld \
             $(CHIBIOS)/os/common/ext/CMSIS/include \
             $(CHIBIOS)/os/common/ext/ARM/CMSIS/Core/Include \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/Nuvoton/NUMICRO \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/Nuvoton/NUMICRO/M251

STARTUPLD = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld
STARTUPLD_CONTRIB = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/ld

# Shared variables
ALLXASMSRC += $(STARTUPASM)
ALLCSRC    += $(STARTUPSRC)
ALLINC     += $(STARTUPINC)

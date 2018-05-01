# List of the ChibiOS generic TM4C129x startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.c

STARTUPASM = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt0_v7m.S

STARTUPINC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC \
             $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/devices/TM4C129x \
             $(CHIBIOS)/os/common/ext/CMSIS/include \
             $(CHIBIOS)/os/common/ext/ARM/CMSIS/Core/Include

STARTUPLD  = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/ld

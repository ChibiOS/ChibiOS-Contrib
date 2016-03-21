# List of the ChibiOS generic K20x startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.c

STARTUPASM = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt0_v7m.s

STARTUPINC = $(CHIBIOS_CONTRIB)/os/common/ports/ARMCMx/devices/K20x \
             $(CHIBIOS_CONTRIB)/os/hal/ports/KINETIS/K20x \
             $(CHIBIOS)/os/common/ext/CMSIS/include

STARTUPLD  = $(CHIBIOS_CONTRIB)/os/common/ports/ARMCMx/compilers/GCC/ld

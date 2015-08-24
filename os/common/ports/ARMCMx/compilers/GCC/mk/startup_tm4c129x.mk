# List of the ChibiOS generic TM4C129x startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/ports/ARMCMx/compilers/GCC/crt1.c \
             $(CHIBIOS)/os/common/ports/ARMCMx/compilers/GCC/vectors.c
          
STARTUPASM = $(CHIBIOS)/os/common/ports/ARMCMx/compilers/GCC/crt0_v7m.s

STARTUPINC = $(CHIBIOS_CONTRIB)/os/common/ports/ARMCMx/devices/TM4C129x \
             $(CHIBIOS)/os/ext/CMSIS/include

STARTUPLD  = $(CHIBIOS_CONTRIB)/os/common/ports/ARMCMx/compilers/GCC/ld

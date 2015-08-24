# List of the ChibiOS generic NRF51 startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/ports/ARMCMx/compilers/GCC/crt1.c \
             $(CHIBIOS)/os/common/ports/ARMCMx/compilers/GCC/vectors.c

STARTUPASM = $(CHIBIOS)/os/common/ports/ARMCMx/compilers/GCC/crt0_v6m.s

STARTUPINC = $(CHIBIOS_CONTRIB)/os/common/ports/ARMCMx/devices/NRF51822 \
             $(CHIBIOS)/os/ext/CMSIS/include

STARTUPLD  = $(CHIBIOS_CONTRIB)/os/common/ports/ARMCMx/compilers/GCC/ld


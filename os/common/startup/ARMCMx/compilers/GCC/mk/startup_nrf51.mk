# List of the ChibiOS generic NRF51 startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.c

STARTUPASM = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt0_v6m.S

STARTUPINC = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/devices/NRF51822 \
             $(CHIBIOS)/os/common/ext/CMSIS/include \
             $(CHIBIOS)/os/common/ext/ARM/CMSIS/Core/Include

STARTUPLD  = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/ld

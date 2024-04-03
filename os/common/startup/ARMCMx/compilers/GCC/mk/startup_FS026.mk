# List of the ChibiOS generic FS026 startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/md/md_utils.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/md/md_tick.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/md/md_fc.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/md/md_rcu.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/md/md_gpio.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/md/md_uart.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/ald/ald_usb.c

STARTUPASM = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt0_v6m.S \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.S

STARTUPINC = $(CHIBIOS)/os/common/portability/GCC \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld \
             $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/devices/FS026 \
             $(CHIBIOS)/os/common/ext/ARM/CMSIS/Core/Include \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026 \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/md \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/ald \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/FS026/FS026

STARTUPLD  = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld
STARTUPLD_CONTRIB  = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/ld

# Shared variables
ALLXASMSRC += $(STARTUPASM)
ALLCSRC    += $(STARTUPSRC)
ALLINC     += $(STARTUPINC)
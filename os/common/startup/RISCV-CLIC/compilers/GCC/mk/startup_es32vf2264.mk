# List of the ChibiOS generic FE310 startup files.
STARTUPSRC = $(CHIBIOS_CONTRIB)/os/common/startup/RISCV-CLIC/compilers/GCC/crt1.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_utils.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_crc.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_rmu.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_cmu.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_gpio.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_uart.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_spi.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_adc.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_i2c.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_pmu.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_timer.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_pis.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_iwdt.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_i2s.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_wwdt.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md/md_dma.c \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/ald/ald_usb.c

STARTUPASM = $(CHIBIOS_CONTRIB)/os/common/startup/RISCV-CLIC/compilers/GCC/crt0.S \
             $(CHIBIOS_CONTRIB)/os/common/startup/RISCV-CLIC/compilers/GCC/vectors.S

STARTUPINC = $(CHIBIOS)/os/common/portability/GCC \
             $(CHIBIOS_CONTRIB)/os/common/startup/RISCV-CLIC/compilers/GCC \
             $(CHIBIOS_CONTRIB)/os/common/startup/RISCV-CLIC/devices/ES32VF2264 \
             $(CHIBIOS_CONTRIB)/os/common/ext/NMSIS/Core/Include \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264 \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/md \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/ald \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/ES32/ES32VF2264/ES32VF2264

STARTUPLD  = $(CHIBIOS_CONTRIB)/os/common/startup/RISCV-CLIC/compilers/GCC/ld
STARTUPLD_CONTRIB  = $(CHIBIOS_CONTRIB)/os/common/startup/RISCV-CLIC/compilers/GCC/ld

# Shared variables
ALLXASMSRC += $(STARTUPASM)
ALLCSRC    += $(STARTUPSRC)
ALLINC     += $(STARTUPINC)


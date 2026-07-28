# Project name.
PROJECT = blinky

# Build directories
CHIBIOS = ../../../../../../ChibiOS
CHIBIOS_CONTRIB = ../../../../..
CONFDIR  := ./cfg
CHCONFDIR := ../cfg
BUILDDIR := ./build
USE_SMART_BUILD ?= yes
DEPDIR   := ./.dep

# Target architecture.
MCU  = cortex-m23

# Optimisation and debug options.
USE_PROCESS_STACKSIZE = 0x100
USE_EXCEPTIONS_STACKSIZE = 0x80
USE_LTO = no
USE_LINK_GC = yes
# USE_FPU is not set - defaults to 'no' in rules.mk for Cortex-M23 without FPU
USE_OPT = -Os -g
USE_COPT = -std=gnu11
USE_CPPOPT = -std=gnu++11

# Licensing files.
include $(CHIBIOS)/os/license/license.mk

# Startup files.
include $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/mk/startup_M251.mk

# HAL-OSAL files (optional).
include $(CHIBIOS)/os/hal/hal.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/M251/platform.mk
include $(CHIBIOS_CONTRIB)/os/hal/boards/NUMAKER_M252SD/board.mk
include $(CHIBIOS)/os/hal/osal/rt-nil/osal.mk

# RTOS files (optional).
include $(CHIBIOS)/os/rt/rt.mk

# Port files.
include $(CHIBIOS_CONTRIB)/os/common/ports/ARMv8-M-BL/compilers/GCC/mk/port.mk

# Auto-build files in ./source recursively.
include $(CHIBIOS)/tools/mk/autobuild.mk

# Source files (converted from ALL* variables set by the included .mk files).
CSRC = $(ALLCSRC) \
       $(TESTSRC) \
       $(STDINSRC) \
       main.c
CPPSRC = $(ALLCPPSRC)
ASMSRC = $(ALLASMSRC)
ASMXSRC = $(ALLXASMSRC)

# Include directories.
INCDIR = $(CONFDIR) $(CHCONFDIR) $(ALLINC) $(TESTINC)

# User defines.
UDEFS = -DM252SD2AE \
        -DCH_CFG_ST_RESOLUTION=16 \
        -DCH_CFG_ST_FREQUENCY=200000 \
        -DCH_CFG_ST_TIMEDELTA=2 \
        -DCH_CFG_TIME_QUANTUM=0
UADEFS = -DM252SD2AE

# Rules.
include $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk/arm-none-eabi.mk
include $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk/rules.mk

# Linker script.
LDSCRIPT = $(STARTUPLD_CONTRIB)/M252SD2AE.ld

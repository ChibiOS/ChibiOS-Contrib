# Project name.
PROJECT = serial

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
USE_PROCESS_STACKSIZE = 0x200
USE_EXCEPTIONS_STACKSIZE = 0x100
USE_LTO = no
USE_LINK_GC = yes
USE_OPT = -Os -g
USE_COPT = -std=gnu11
USE_CPPOPT = -std=gnu++11

include $(CHIBIOS)/os/license/license.mk
include $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/mk/startup_M251.mk
include $(CHIBIOS)/os/hal/hal.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/M251/platform.mk
include $(CHIBIOS_CONTRIB)/os/hal/boards/NUMAKER_M252SD/board.mk
include $(CHIBIOS)/os/hal/osal/rt-nil/osal.mk
include $(CHIBIOS)/os/rt/rt.mk
include $(CHIBIOS_CONTRIB)/os/common/ports/ARMv8-M-BL/compilers/GCC/mk/port.mk
include $(CHIBIOS)/tools/mk/autobuild.mk
include $(CHIBIOS)/os/hal/lib/streams/streams.mk

CSRC = $(ALLCSRC) \
       main.c
CPPSRC = $(ALLCPPSRC)
ASMSRC = $(ALLASMSRC)
ASMXSRC = $(ALLXASMSRC)

INCDIR = $(CONFDIR) $(CHCONFDIR) $(ALLINC)

UDEFS = -DM252SD2AE
UADEFS = -DM252SD2AE

include $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk/arm-none-eabi.mk
include $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk/rules.mk

LDSCRIPT = $(STARTUPLD_CONTRIB)/M252SD2AE.ld

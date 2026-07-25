##############################################################################
# Build global options
#

ifeq ($(USE_OPT),)
  USE_OPT = -Os -g
endif
ifeq ($(USE_COPT),)
  USE_COPT = -std=gnu11
endif
ifeq ($(USE_CPPOPT),)
  USE_CPPOPT = -fno-rtti
endif
ifeq ($(USE_LINK_GC),)
  USE_LINK_GC = yes
endif
ifeq ($(USE_LDOPT),)
  USE_LDOPT =
endif
ifeq ($(USE_LTO),)
  USE_LTO = no
endif
ifeq ($(USE_VERBOSE_COMPILE),)
  USE_VERBOSE_COMPILE = no
endif
ifeq ($(USE_SMART_BUILD),)
  USE_SMART_BUILD = yes
endif

#
##############################################################################

##############################################################################
# Architecture or project specific options
#

ifeq ($(USE_PROCESS_STACKSIZE),)
  USE_PROCESS_STACKSIZE = 0x400
endif
ifeq ($(USE_EXCEPTIONS_STACKSIZE),)
  USE_EXCEPTIONS_STACKSIZE = 0x400
endif
ifeq ($(USE_FPU),)
  USE_FPU = no
endif
ifeq ($(USE_FPU_OPT),)
  USE_FPU_OPT = -mfloat-abi=soft
endif

#
##############################################################################

##############################################################################
# Project, target, sources and paths
#

PROJECT = usb_hid

MCU  = cortex-m23

# Licensing files.
BASE_PATH       := ../../../../../..
CHIBIOS         := $(BASE_PATH)/ChibiOS
CHIBIOS_CONTRIB := $(BASE_PATH)/ChibiOS-Contrib
CONFDIR         := ./cfg
CHCONFDIR       := ../cfg
BUILDDIR        := ./build
DEPDIR          := ./.dep

include $(CHIBIOS)/os/license/license.mk
include $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/mk/startup_M251.mk
include $(CHIBIOS_CONTRIB)/os/hal/hal.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/M251/platform.mk
include $(CHIBIOS_CONTRIB)/os/hal/boards/NUMAKER_M252SD/board.mk
include $(CHIBIOS)/os/hal/osal/rt-nil/osal.mk
include $(CHIBIOS)/os/rt/rt.mk
include $(CHIBIOS_CONTRIB)/os/common/ports/ARMv8-M-BL/compilers/GCC/mk/port.mk
include $(CHIBIOS)/tools/mk/autobuild.mk

LDSCRIPT= $(STARTUPLD_CONTRIB)/M252SD2AE.ld

CSRC = $(ALLCSRC) \
       usbcfg.c \
       main.c
CPPSRC = $(ALLCPPSRC)
ASMSRC = $(ALLASMSRC)
ASMXSRC = $(ALLXASMSRC)

INCDIR = $(CONFDIR) $(CHCONFDIR) $(ALLINC)

CWARN = -Wall -Wextra -Wundef -Wstrict-prototypes
CPPWARN = -Wall -Wextra -Wundef

#
##############################################################################

##############################################################################
# Start of user section
#

UDEFS = -DM252SD2AE
UADEFS = -DM252SD2AE
UINCDIR =
ULIBDIR =
ULIBS =

#
##############################################################################

##############################################################################
# Common rules
#

RULESPATH = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk
include $(RULESPATH)/arm-none-eabi.mk
include $(RULESPATH)/rules.mk

#
##############################################################################

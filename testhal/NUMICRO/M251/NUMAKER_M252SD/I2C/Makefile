PROJECT = i2c
CHIBIOS = ../../../../../../ChibiOS
CHIBIOS_CONTRIB = ../../../../..
I2C1_DISPLAY ?= LCD1602

ifeq ($(I2C1_DISPLAY),LCD1602)
  I2C1_DISPLAY_VARIANT := lcd1602
else ifeq ($(I2C1_DISPLAY),SSD1306)
  I2C1_DISPLAY_VARIANT := ssd1306
else
  $(error I2C1_DISPLAY must be LCD1602 or SSD1306)
endif

CONFDIR  := ./cfg
CHCONFDIR := ../cfg
BUILDDIR := ./build/$(I2C1_DISPLAY_VARIANT)
USE_SMART_BUILD ?= yes
DEPDIR   := ./.dep/$(I2C1_DISPLAY_VARIANT)
BOARDDIR := ./board

MCU  = cortex-m23

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
include $(BOARDDIR)/board.mk
include $(CHIBIOS)/os/hal/osal/rt-nil/osal.mk
include $(CHIBIOS)/os/rt/rt.mk
include $(CHIBIOS_CONTRIB)/os/common/ports/ARMv8-M-BL/compilers/GCC/mk/port.mk
include $(CHIBIOS)/tools/mk/autobuild.mk

CSRC = $(ALLCSRC) \
       main.c \
       ssd1306.c
CPPSRC = $(ALLCPPSRC)
ASMSRC = $(ALLASMSRC)
ASMXSRC = $(ALLXASMSRC)

INCDIR = $(CONFDIR) $(CHCONFDIR) $(ALLINC)

UDEFS = -DM252SD2AE
UADEFS = -DM252SD2AE

ifeq ($(I2C1_DISPLAY),LCD1602)
  CSRC += lcd1602.c
  UDEFS += -DI2C1_DISPLAY_LCD1602
endif

include $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk/arm-none-eabi.mk
include $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/mk/rules.mk

LDSCRIPT = $(STARTUPLD_CONTRIB)/M252SD2AE.ld

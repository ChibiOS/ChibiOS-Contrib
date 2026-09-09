# Required platform files.
# SK32F0xx is register-compatible with STM32F072 except for the USB IP.
PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/sk32_isr.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_lld.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_efl_lld.c \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_st_lld.c \

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(HALCONFDIR),)
  ifeq ($(CONFDIR),)
    HALCONFDIR = .
  else
    HALCONFDIR := $(CONFDIR)
  endif
endif

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))

else
endif

# The SK32 PAL (GPIO) driver is native and programs the vendor CMSIS
# registers directly, the shared STM32 GPIOv2 LLD is not used.
ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_PAL TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_pal_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_pal_lld.c
endif

# The SK32 USART is a legacy SR/DR class unit, its native serial driver is
# used instead of the shared STM32 USARTv2 LLD (ISR/ICR register set).
ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_serial_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_serial_lld.c
endif

# The SK32 DMA helper is a native driver managing the shared DMA1 channels
# (CCR/CNDTR/CPAR/CMAR register set of the vendor library).  Its code is
# self-gated on SK32_DMA_REQUIRED, a macro defined by any driver of this
# platform that needs DMA services, so it can be always added to the build
# list like the shared STM32 DMAv1 driver.mk does.
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/sk32_dma.c

# The SK32 SPI is a legacy CR1/CR2/SR/DR class unit (SPIv1 class), its
# native interrupt-driven driver is used instead of the shared STM32 SPIv2
# LLD (the latter would require the STM32 registry macros, e.g.
# STM32_HAS_SPI1, which the SK32 platform does not define).
ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_SPI TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_spi_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_spi_lld.c
endif

# The SK32 I2C is a legacy CR1/CR2/SR1/SR2/DR/CCR class unit (no TRISE
# register, single I2C1 IRQ vector), its native interrupt-driven master
# driver is used instead of the shared STM32 I2Cv1/I2Cv2 LLDs (the latter
# target the ISR/ICR/TIMINGR register set while I2Cv1 requires TRISE, DMA
# streams and the EV/ER IRQ split, none of which applies to this platform).
ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_i2c_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_i2c_lld.c
endif

# The SK32 SLED (serial LED) is a 3Think peripheral present on the SK32F077
# variant only.  Its low level driver is native and drives the two WS2812
# capable groups through byte wide DMA1 transfers; it allocates DMA1 channel
# 1 (SLED1) and channel 2 (SLED2) so it also pulls in the DMA helper and the
# DMA1 initialization through the SK32_DMA_REQUIRED macro (see hal_lld.h).
# Like sk32_dma.c the file is added unconditionally: its body is self-gated
# on HAL_USE_SLED (no code is generated unless the macro is TRUE), so the
# smart-build text scan of the keyboard halconf overrides is not needed.
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_sled_lld.c

# The SK32 KBCU (Keyboard Control Unit) is a 3Think peripheral used for
# keyboard matrix scanning (independent mode) and for driving the RGB LED
# columns.  Its low level driver is native; the LED stream is pushed through
# DMA1 channel 4 in memory to peripheral mode so the driver also pulls in the
# DMA helper and the DMA1 initialization through the SK32_DMA_REQUIRED macro
# (see hal_lld.h).  Like sk32_dma.c the file is added unconditionally: its
# body is self-gated on HAL_USE_KBCU (no code is generated unless the macro is
# TRUE), so the smart-build text scan of the keyboard halconf overrides is not
# needed.
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_kbcu_lld.c

# The SK32 general purpose timers (TIM3 on the APB1 bus and the basic
# TIM16/TIM17 on the APB2 bus) are served by the native GPT driver added
# below, the shared STM32 TIMv1 LLD is not used (it requires the STM32
# registry macros and mcuconf naming scheme).  The same applies to the ADC1
# unit: the shared STM32 ADCv1 LLD relies on an STM32 DMA stream while this
# platform captures the samples in the ADC interrupt handler, so the native
# hal_adc_lld.c is used instead.
ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_GPT TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_gpt_lld.c
endif
ifneq ($(findstring HAL_USE_ADC TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_adc_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_gpt_lld.c
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_adc_lld.c
endif

# This platform no longer pulls in any shared STM32 LLD.  Historically the
# CANv1/DACv1/DMAv1/RTCv2/xWDGv1 driver.mk files were included here but every
# one of them compiled to a stub because the associated generic HAL has its
# corresponding HAL_USE_* macro disabled on this platform, and their PLATFORMINC
# header dir leaked STM32 headers into the include path.  The only genuine
# consumer was DMAv1, which is now served by the native sk32_dma helper added
# above with the same full interface.
# The SK32 system tick (ST) driver is native and uses the Cortex-M0 SysTick
# counter in periodic mode, so the shared STM32 SYSTICKv1 LLD is not used.
# The shared STM32 SPIv2, I2Cv1/I2Cv2, ADCv1 and TIMv1 LLDs are not used
# either: the SPI, I2C, ADC and GPT units of this platform are served by
# the native drivers added above.
# The shared STM32 USARTv2 LLD targets the ISR/ICR register set (STM32F0/F3/L4
# class), the SK32 USART is instead a legacy SR/DR class unit handled by the
# native serial driver added above.
# Native stub headers (hal_can_lld.h/hal_dac_lld.h/hal_rtc_lld.h/hal_wdg_lld.h)
# are provided in this port directory so the generic hal.h can resolve the
# unconditional includes in hal_can.h/hal_dac.h/hal_rtc.h/hal_wdg.h without
# referencing the shared STM32 header trees.

# SK32F077 uses a Mentor-MUSB-class USB FS controller (musbfsfc), which is NOT
# compatible with the STM32 USBv1 LLD, so USBv1/driver.mk is not included here.
# The SK32 USB low level driver lives in this port directory instead.
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx/hal_usb_lld.c
PLATFORMINC += $(CHIBIOS_CONTRIB)/os/hal/ports/SK32/SK32F0xx

# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)

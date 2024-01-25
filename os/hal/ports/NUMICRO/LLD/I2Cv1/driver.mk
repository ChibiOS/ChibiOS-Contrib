ifeq ($(USE_HAL_I2C_FALLBACK),yes)
  # Fallback SW driver.
  ifeq ($(USE_SMART_BUILD),yes)
    ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
      PLATFORMSRC += $(CHIBIOS)/os/hal/lib/fallback/I2C/hal_i2c_lld.c
    endif
  else
    PLATFORMSRC += $(CHIBIOS)/os/hal/lib/fallback/I2C/hal_i2c_lld.c
  endif
  PLATFORMINC += $(CHIBIOS)/os/hal/lib/fallback/I2C
else
  ifeq ($(USE_SMART_BUILD),yes)
    ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
      PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/I2Cv1/hal_i2c_lld.c
    endif
  else
    PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/I2Cv1/hal_i2c_lld.c
  endif

  PLATFORMINC += $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/I2Cv1
endif

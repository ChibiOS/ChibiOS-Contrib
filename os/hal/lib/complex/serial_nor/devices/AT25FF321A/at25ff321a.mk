# List of all at25ff321a device files.
SNORSRC := $(CHIBIOS)/os/hal/lib/complex/serial_nor/hal_serial_nor.c \
			$(CHIBIOS_CONTRIB)/os/hal/lib/complex/serial_nor/devices/AT25FF321A/hal_flash_device.c

# Required include directories
SNORINC := $(CHIBIOS)/os/hal/lib/complex/serial_nor \$(CHIBIOS_CONTRIB)/os/hal/lib/complex/serial_nor/devices/AT25FF321A

# Shared variables
ALLCSRC += $(SNORSRC)
ALLINC  += $(SNORINC)

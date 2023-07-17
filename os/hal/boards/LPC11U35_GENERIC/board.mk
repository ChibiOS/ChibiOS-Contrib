# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/LPC11U35_GENERIC/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/LPC11U35_GENERIC

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)


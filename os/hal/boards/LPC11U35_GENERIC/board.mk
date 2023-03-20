# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/LPC11U35_TURING61/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/LPC11U35_TURING61

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)


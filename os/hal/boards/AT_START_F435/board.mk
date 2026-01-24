# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/AT_START_F435/board.c

# Required include directories
BOARDINC = ${CHIBIOS_CONTRIB}/os/hal/boards/AT_START_F435

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

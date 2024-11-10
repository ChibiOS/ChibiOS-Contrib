# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/AT_START_F405/board.c

# Required include directories
BOARDINC = ${CHIBIOS_CONTRIB}/os/hal/boards/AT_START_F405

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

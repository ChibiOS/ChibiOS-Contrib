# List of all the board related files.
BOARDSRC = ${CHIBIOS_CONTRIB}/os/hal/boards/EDGEPRO1/board.c

# Required include directories
BOARDINC = ${CHIBIOS_CONTRIB}/os/hal/boards/EDGEPRO1

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

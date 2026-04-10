# List of all the board related files.
BOARDSRC = ${CHIBIOS_CONTRIB}/os/hal/boards/SILABS_SLWSTK6061B/board.c

# Required include directories
BOARDINC = ${CHIBIOS_CONTRIB}/os/hal/boards/SILABS_SLWSTK6061B

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/ST_NUCLEO64_L053R8/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/ST_NUCLEO64_L053R8

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

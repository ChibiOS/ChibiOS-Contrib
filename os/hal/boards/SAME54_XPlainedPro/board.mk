# List of all the board related files.
BOARDSRC = ${CHIBIOS_CONTRIB}/os/hal/boards/SAME54_XPlainedPro/board.c

# Required include directories
BOARDINC = ${CHIBIOS_CONTRIB}/os/hal/boards/SAME54_XPlainedPro

ALLINC += $(BOARDINC)
ALLCSRC += $(BOARDSRC)

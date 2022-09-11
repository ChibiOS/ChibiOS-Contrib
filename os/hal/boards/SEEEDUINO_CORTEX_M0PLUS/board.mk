# List of all the board related files.
BOARDSRC = ${CHIBIOS_CONTRIB}/os/hal/boards/SEEEDUINO_CORTEX_M0PLUS/board.c

# Required include directories
BOARDINC = ${CHIBIOS_CONTRIB}/os/hal/boards/SEEEDUINO_CORTEX_M0PLUS

ALLINC += $(BOARDINC)
ALLCSRC += $(BOARDSRC)


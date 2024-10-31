# Required platform files.
XMLMBUS = $(CHIBIOS_CONTRIB)/ext/xmlmbus

XMLMBUSSRC = $(XMLMBUS)/src/xmlmbus_buffer.c \
             $(XMLMBUS)/src/xmlmbus_server.c

XMLMBUSINC = $(XMLMBUS)/include

# Shared variables
ALLCSRC += $(XMLMBUSSRC)
ALLINC  += $(XMLMBUSINC)

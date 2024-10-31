# Required platform files.
XMLMBUS = $(CHIBIOS_CONTRIB)/ext/xmlmbus

XMLMBUSSRC = $(XMLMBUS)/xmlmbus_buffer.c \
             $(XMLMBUS)/xmlmbus_server.c

XMLMBUSINC = $(XMLMBUS)

# Shared variables
ALLCSRC += $(XMLMBUSSRC)
ALLINC  += $(XMLMBUSINC)

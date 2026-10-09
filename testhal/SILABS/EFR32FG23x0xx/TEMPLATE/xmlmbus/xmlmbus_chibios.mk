# Required platform files.
XMLMBUS = xmlmbus

XMLMBUSSRC = $(XMLMBUS)/src/xmlmbus_buffer.c \
             $(XMLMBUS)/src/xmlmbus_server.c \
             $(XMLMBUS)/src/xmlmbus_util.c \
             $(XMLMBUS)/src/xmlmbus_mbus_frame.c \
             $(XMLMBUS)/xmlmbus_chibios.c

XMLMBUSINC = $(XMLMBUS)/include \
             $(XMLMBUS)

# Shared variables
ALLCSRC += $(XMLMBUSSRC)
ALLINC  += $(XMLMBUSINC)

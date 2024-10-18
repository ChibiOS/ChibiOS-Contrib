# Required platform files.
GECKO_SDK = $(CHIBIOS_CONTRIB)/ext/gecko_sdk

RAILLIBSRC = \
        raillib/autogen/rail_config.c \
        raillib/autogen/sl_rail_util_callbacks.c \
        raillib/autogen/sl_rail_util_init.c

#RAILLIBSRC += raillib/autogen/sl_cli_command_table.c
#RAILLIBSRC += raillib/autogen/sl_iostream_init_eusart_instances.c
#RAILLIBSRC += raillib/autogen/sli_cli_hooks.c
#RAILLIBSRC += raillib/autogen/sl_simple_button_instances.c
#RAILLIBSRC += raillib/autogen/sl_board_default_init.c
#RAILLIBSRC += raillib/autogen/sl_i2cspm_init.c
#RAILLIBSRC += raillib/autogen/sl_iostream_handles.c
#RAILLIBSRC += raillib/autogen/sl_cli_instances.c
#RAILLIBSRC += raillib/autogen/sl_power_manager_handler.c
#RAILLIBSRC += raillib/autogen/sl_event_handler.c
#RAILLIBSRC += raillib/autogen/sl_simple_led_instances.c

RAILLIBSRC += $(GECKO_SDK)/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.c
RAILLIBSRC += $(GECKO_SDK)/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.c
RAILLIBSRC += $(GECKO_SDK)/platform/radio/rail_lib/plugin/rail_util_protocol/sl_rail_util_protocol.c

RAILLIBINC = \
        raillib/autogen \
        raillib/config

RAILLIBINC += \
        $(GECKO_SDK)/platform/radio/rail_lib/plugin/pa-conversions\efr32xg23 \
        $(GECKO_SDK)/platform/radio/rail_lib/plugin/pa-conversions \
        $(GECKO_SDK)/platform/radio/rail_lib/plugin/rail_util_callbacks \
        $(GECKO_SDK)/platform/radio/rail_lib/plugin/rail_util_callbacks/config \
        $(GECKO_SDK)/platform/radio/rail_lib/plugin/rail_util_protocol \
        $(GECKO_SDK)/platform/radio/rail_lib/plugin/rail_util_protocol/config \
        $(GECKO_SDK)/platform/radio/rail_lib/protocol/ble \
        $(GECKO_SDK)/platform/radio/rail_lib/protocol/ieee802154 \
        $(GECKO_SDK)/platform/radio/rail_lib/protocol/sidewalk \
        $(GECKO_SDK)/platform/radio/rail_lib/protocol/wmbus \
        $(GECKO_SDK)/platform/radio/rail_lib/protocol/zwave

# Shared variables
ALLCSRC += $(RAILLIBSRC)
ALLINC  += $(RAILLIBINC)

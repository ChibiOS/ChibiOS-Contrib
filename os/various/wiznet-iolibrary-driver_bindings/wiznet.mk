# WIZNET files.

WIZNETSRC = \
	    $(CHIBIOS)/os/various/syscalls.c \
	    $(CHIBIOS_CONTRIB)/os/various/wiznet-iolibrary-driver_bindings/wiznet_chibios.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5100/w5100.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5100S/w5100s.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5200/w5200.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5300/w5300.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5500/w5500.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/wizchip_conf.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/socket.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/DHCP/dhcp.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/DNS/dns.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/FTPClient/ftpc.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/FTPServer/ftpd.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/httpServer/httpParser.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/httpServer/httpServer.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/httpServer/httpUtil.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTClient.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/mqtt_interface.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTFormat.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTPacket.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/SNTP/sntp.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/TFTP/netutil.c \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/TFTP/tftp.c

WIZNETINC = \
	    $(CHIBIOS_CONTRIB)/os/various/wiznet-iolibrary-driver_bindings \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5100 \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5100S \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5200 \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5300 \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet/W5500 \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Ethernet \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/DHCP \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/DNS \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/FTPClient \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/FTPServer \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/httpServer \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/MQTT/MQTTPacket/src \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/SNTP \
	    $(CHIBIOS_CONTRIB)/ext/wiznet-iolibrary-driver/Internet/TFTP

# Shared variables
ALLCSRC += $(WIZNETSRC)
ALLINC  += $(WIZNETINC)

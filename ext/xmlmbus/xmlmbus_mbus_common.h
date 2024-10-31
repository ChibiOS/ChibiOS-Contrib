#pragma once

#define MBUS_FRAME_SINGLE_START   0xE5u
#define MBUS_FRAME_SHORT_START    0x10u
#define MBUS_FRAME_LONG_START     0x68u
#define MBUS_FRAME_STOP           0x16u

#define MBUS_FRAME_SIZE_SINGLE_CHARACTER    1u
#define MBUS_FRAME_SIZE_SHORT               5u
#define MBUS_FRAME_SIZE_CONTROL             9u
#define MBUS_FRAME_SIZE_DATA_SHORT          (MBUS_FRAME_SIZE_SHORT - 3u)
#define MBUS_FRAME_SIZE_DATA_MAX            252u
#define MBUS_FRAME_SIZE_MAX                 (9u + MBUS_FRAME_SIZE_DATA_MAX)

#define MBUS_ADDRESS_UNCONFIGURED          0u
#define MBUS_ADDRESS_MIN                   1u
#define MBUS_ADDRESS_MAX                 250u
#define MBUS_ADDRESS_RESERVED_251        251u
#define MBUS_ADDRESS_RESERVED_252        252u
#define MBUS_ADDRESS_IN_NETWORK_LAYER    253u
#define MBUS_ADDRESS_BROADCAST_ALL_REPLY 254u
#define MBUS_ADDRESS_BROADCAST_NO_REPLY  255u

#define MBUS_CFIELD_REQUEST       (1u << 6) /**< Calling direction. */
#define MBUS_CFIELD_FCB           (1u << 5) /**< Frame Count Bit indicates successful transmission procedures. */
#define MBUS_CFIELD_FCV           (1u << 4) /**< Frame Count Valid is set -> FCB is used; FCV is not set -> FCB is ignored. */

#define MBUS_CFIELD_RESPONSE      (0u << 6) /**< Reply direction. */
#define MBUS_CFIELD_ACD           (1u << 5) /**< With Access Demand bit set the slave shows that it wants to transmit Class 1 data. */
#define MBUS_CFIELD_DFC           (1u << 4) /**< With Data Flow Control bit is set the slave indicates that it can't accept any further data. */

#define MBUS_CFIELD_FUNCTION(f)   (((f) & 0xFu) << 0)

/** Initialization of Slave */
#define MBUS_SND_NKE              (MBUS_CFIELD_REQUEST | MBUS_CFIELD_FUNCTION(0x0))

/** Send User Data to Slave */
#define MBUS_SND_UD_FCB0          (MBUS_CFIELD_REQUEST | MBUS_CFIELD_FCV | MBUS_CFIELD_FUNCTION(0x3))

/** Send User Data to Slave */
#define MBUS_SND_UD_FCB1          (MBUS_CFIELD_REQUEST | MBUS_CFIELD_FCV | MBUS_CFIELD_FCB |  | MBUS_CFIELD_FUNCTION(0x3))

/** Request for Class 2 Data */
#define MBUS_REQ_UD2_FCB0         (MBUS_CFIELD_REQUEST | MBUS_CFIELD_FCV | MBUS_CFIELD_FUNCTION(0xB))

/** Request for Class 2 Data */
#define MBUS_REQ_UD2_FCB1         (MBUS_CFIELD_REQUEST | MBUS_CFIELD_FCV | MBUS_CFIELD_FCB | MBUS_CFIELD_FUNCTION(0xB))

/** Request for Class1 Data */
#define MBUS_REQ_UD1_FCB0         (MBUS_CFIELD_REQUEST | MBUS_CFIELD_FCV | MBUS_CFIELD_FUNCTION(0xA))

/** Request for Class1 Data */
#define MBUS_REQ_UD1_FCB1         (MBUS_CFIELD_REQUEST | MBUS_CFIELD_FCV | MBUS_CFIELD_FCB | MBUS_CFIELD_FUNCTION(0xA))

/** Data Transfer from Slave to Master after Request */
#define RDP_UD                    (MBUS_CFIELD_RESPONSE | MBUS_CFIELD_FUNCTION(0x8))


/*
    Copyright 2024 Xael South

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/* Don't edit this file, it's generated. */

#pragma once

#include <stdint.h>

#include <xmlmbus_platform.h>

union VIF {
  uint8_t value;

  struct {
    uint8_t lsb: 7;
    uint8_t msb: 1;
  } vif;
};

struct xmlmbus_dib_with_data {
  union VIF vife_layer;
  union VIF vife_request;
  union VIF vife_function;
  union VIF vife_response;
  const void *blob;
  size_t blobsize;
};

#define DIF_BINARY_DATA_LENGTH_IS_0   0x00u
#define DIF_BINARY_DATA_LENGTH_IS_1   0x01u
#define DIF_BINARY_DATA_LENGTH_IS_2   0x02u
#define DIF_BINARY_DATA_LENGTH_IS_3   0x03u
#define DIF_BINARY_DATA_LENGTH_IS_4   0x04u
#define DIF_BINARY_DATA_LENGTH_IS_6   0x06u
#define DIF_BINARY_DATA_LENGTH_IS_8   0x07u
#define DIF_DATA_LENGTH_IS_LVAR       0x0Du
#define DIF_DATA_LENGTH_IS_INVALID    0xFFu
#define DIF_MANUFACTURER_SPECIAL_FUNCTION 0x0Fu

#define VIF_MANUFACTURER_SPECIFIC                  0xFFu

#define VIFE_LAYER_MASK                            0x03u
#define VIFE_LAYER_AUTHORIZATION                   0x40u
#define VIFE_LAYER1_APPLICATION                    0x41u

#define VIFE_REQUEST_MASK                          0x0Fu
#define VIFE_REQUEST_TYPE_SYSTEM                   0x00u
#define VIFE_REQUEST_TYPE_DEVICE                   0x01u
#define VIFE_REQUEST_TYPE_SETTINGS                 0x02u
#define VIFE_REQUEST_TYPE_DATETIME                 0x03u
#define VIFE_REQUEST_TYPE_STATUS                   0x04u
#define VIFE_REQUEST_TYPE_RADIO                    0x05u
#define VIFE_REQUEST_TYPE_VALUES                   0x06u
#define VIFE_REQUEST_TYPE_MEMORY                   0x07u

#define VIFE_RESPONSE_MASK                         0x1Fu
#define VIFE_RESPONSE_TYPE_CMD_EXEC_SUCCESS        0x10u
#define VIFE_RESPONSE_TYPE_CMD_EXEC_ERROR          0x11u
#define VIFE_RESPONSE_TYPE_CMD_UNIMPLEMENTED       0x12u
#define VIFE_RESPONSE_TYPE_CMD_UNAUTHORIZED        0x13u
#define VIFE_RESPONSE_TYPE_CMD_HAS_WRONG_PARAMETER 0x14u
#define VIFE_RESPONSE_TYPE_CMD_EXEC_RESULT         0x15u
#define VIFE_RESPONSE_TYPE_DEVICE_IS_BUSY          0x16u

#define VIFE_FUNCTION_MASK                         0x3Fu
#define VIFE_FUNCTION_READ_MEMORY                  0x20u

static inline uint8_t xmlmbus_get_dif_from_size(size_t size) {

  switch (size) {
  case 0:
    return DIF_BINARY_DATA_LENGTH_IS_0;
  case 1:
    return DIF_BINARY_DATA_LENGTH_IS_1;
  case 2:
    return DIF_BINARY_DATA_LENGTH_IS_2;
  case 3:
    return DIF_BINARY_DATA_LENGTH_IS_3;
  case 4:
    return DIF_BINARY_DATA_LENGTH_IS_4;
  case 6:
    return DIF_BINARY_DATA_LENGTH_IS_6;
  case 8:
    return DIF_BINARY_DATA_LENGTH_IS_8;
  default:
    break;
  }

  return DIF_DATA_LENGTH_IS_LVAR;
}

/** @return Length of application data or DIF_DATA_LENGTH_IS_INVALID in case of error. */
static inline uint8_t xmlmbus_get_size_from_dif(uint8_t dif) {

  switch (dif) {
  case DIF_BINARY_DATA_LENGTH_IS_0:
    return 0;

  case DIF_BINARY_DATA_LENGTH_IS_1:
    return 1;

  case DIF_BINARY_DATA_LENGTH_IS_2:
    return 2;

  case DIF_BINARY_DATA_LENGTH_IS_3:
    return 3;

  case DIF_BINARY_DATA_LENGTH_IS_4:
    return 4;

  case DIF_BINARY_DATA_LENGTH_IS_6:
    return 6;

  case DIF_BINARY_DATA_LENGTH_IS_8:
    return 8;

  case DIF_DATA_LENGTH_IS_LVAR:
    return DIF_DATA_LENGTH_IS_LVAR; /* Max length is in LVAR. */
  }

  return DIF_DATA_LENGTH_IS_INVALID;
}

typedef enum XMLMBUS_ATTRIBUTE_PACKED {
  BUILD_TYPE_RELEASE = 0,
  BUILD_TYPE_DEBUG = 1
} BuildType_t;

typedef struct XMLMBUS_ATTRIBUTE_PACKED {
  uint8_t	major;
  uint8_t	minor;
  uint8_t	patch;
  BuildType_t	build_type;
  uint16_t build_number;
} SoftwareVersion_t;

typedef struct XMLMBUS_ATTRIBUTE_PACKED {
  uint8_t	major;
  uint8_t	minor;
} HardwareVersion_t;

typedef struct XMLMBUS_ATTRIBUTE_PACKED {
  SoftwareVersion_t sofware_version;
  HardwareVersion_t hardware_version;
  uint64_t reserved1;
  uint64_t reserved2;
} DeviceIdentification_t;

typedef struct XMLMBUS_ATTRIBUTE_PACKED {
  uint64_t address;
  uint32_t size;
} MemoryBlock_t;

typedef struct XMLMBUS_ATTRIBUTE_PACKED {
  uint8_t code[8];
} Authcode_t;

typedef struct XMLMBUS_ATTRIBUTE_PACKED {
  uint32_t	year: 8;  /**<	Years since 1980. */
  uint32_t	month: 4; /**<	Months 1..12. */
  uint32_t	dstflag: 1; /**<	DST correction flag. */
  uint32_t	dayofweek: 3; /**<	Day of week 1..7. */
  uint32_t	day: 5; /**<	Day of the month 1..31. */
  uint32_t	milliseconds: 27; /**<	Milliseconds since midnight. */
} RTCDateTime_t;

typedef struct XMLMBUS_ATTRIBUTE_PACKED {
  uint32_t milliseconds;
} TimeoutMilliseconds_t;

#define Default_SoftwareVersion_t (SoftwareVersion_t) { \
  .major = 0, .minor = 0, .patch = 0, .build_type = BUILD_TYPE_RELEASE, .build_number = 0 \
}

#define Default_HardwareVersion_t (HardwareVersion_t) { \
  .major = 0, .minor = 0 \
}

#define Default_DeviceIdentification_t (DeviceIdentification_t) { \
  .sofware_version = Default_SoftwareVersion_t, .hardware_version = Default_HardwareVersion_t, .reserved1 = 0, .reserved2 = 0 \
}

#define Default_MemoryBlock_t (MemoryBlock_t) { \
  .address = 0, .size = 0 \
}

#define Default_Authcode_t (Authcode_t) { \
  .code = {0, 0, 0, 0, 0, 0, 0, 0} \
}

#define Default_RTCDateTime_t (RTCDateTime_t) { \
  .year = 0, .month = 0, .dstflag = 0, .dayofweek = 0, .day = 0, .milliseconds = 0 \
}

#define Default_TimeoutMilliseconds_t (TimeoutMilliseconds_t) { \
  .milliseconds = 0 \
}


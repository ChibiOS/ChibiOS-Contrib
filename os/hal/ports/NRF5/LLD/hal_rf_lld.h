/*
    Copyright (C) 2016 Stephane D'Alu

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

/**
 * @file    NRF5/LLD/hal_rf_lld.h
 * @brief   NRF5 low level RF driver header.
 *
 * @addtogroup RF
 * @{
 */

#ifndef HAL_RF_LLD_H
#define HAL_RF_LLD_H

#if HAL_USE_RF || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief Maxium length of radio packet
 * @note Including S0, Length, S1, Payload (excluding preamble and CRC)
 */
#define NRF5_PACKET_MAXLEN      254

/**
 * @brief Error none
 */
#define RF_ERROR_NONE   0

/**
 * @brief Error of CRC type
 */
#define RF_ERROR_CRC    1

/**
 * @brief Error Truncated packet
 */
#define RF_ERROR_TRUNCATED 2


/**
 * @brief Manufacturer assigned address
 */
#define RF_NODE_ADDR (NRF_FICR->DEVICEADDR[0] & 0xFFFF)

/**
 * @brief Address used for broadcasting
 */
#define RF_BCAST_ADDR               0xFFFF

/**
 * @brief Bitrate 250Kbit/s 
 */
#define RF_BITRATE_250K  RADIO_MODE_MODE_Nrf_250Kbit

/**
 * @brief Bitrate 1Mbit/s 
 */
#define RF_BITRATE_1M    RADIO_MODE_MODE_Nrf_1Mbit

/**
 * @brief Bitrate 2Mbit/s 
 */
#define RF_BITRATE_2M    RADIO_MODE_MODE_Nrf_2Mbit


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   RFD1 driver enable switch.
 * @details If set to @p TRUE the support for RFD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(NRF5_RF_USE_RADIO0) || defined(__DOXYGEN__)
#define NRF5_RF_USE_RADIO0                  FALSE
#endif

/**
 * @brief   RADIO interrupt priority level setting.
 */
#if !defined(NRF5_RF_RADIO0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define NRF5_RF_RADIO0_IRQ_PRIORITY    3
#endif


/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/**
 * @brief Maximum size of packet (S0 + LEN + S1 + PAYLOAD)
 */
#define RF_PACKET_MAXLEN      (RF_PAYLOAD_MAXLEN + 1)

#if NRF5_RF_USE_RADIO0 == FALSE
#error "Requesting RF driver, but no RADIO peripheric attached"
#endif

#if NRF5_RF_USE_RADIO0 &&					\
    !OSAL_IRQ_IS_VALID_PRIORITY(NRF5_RF_RADIO0_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to RADIO0"
#endif

#if RF_PACKET_MAXLEN > NRF5_PACKET_MAXLEN
#error "Radio doesn't support sending a payload that big (RF_PAYLOAD_MAXLEN)"
#endif


/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type for Personal Area Network identifier (PAN)
 */
typedef uint16_t rf_pan_t;
/**
 * @brief   Type of an address
 */
typedef uint16_t rf_addr_t;
/**
 * @brief   Type for power transmission level
 */
typedef int8_t   rf_power_t;
/**
 * @brief   Type for frequency selection
 */
typedef uint16_t rf_frequency_t;
/**
 * @brief   Type for bitrate selection
 */
typedef uint8_t rf_bitrate_t;

/**
 * @brief   Type of a structure representing an RF driver.
 */
typedef struct RFDriver RFDriver;


/**
 * @brief   RF notification callback type.
 *
 * @param[in] rfp      pointer to the @p RFDriver object triggering the
 *                     callback
 */
typedef void (*rfcallback_t)(RFDriver *rfp);

/**
 * @brief   Driver configuration structure.
 */
typedef struct {
  /**
   * @brief Operation complete callback or @p NULL.
   */
  rfcallback_t             end_cb;
  /**
   * @brief Source address of the node
   */
  rf_addr_t      src_addr;
  /**
   * @brief Frequency at which to run the radio.
   * @note  Default to 2400MHz
   */
  rf_frequency_t frequency;
  /**
   * @brief Radio bitrate
   * @note  Default to 1Mbit/s (RF_BITRATE_1M)
   */
  rf_bitrate_t   bitrate;
  /**
   * @brief Power in dBm for the transmitter.
   * @note  Power will be automatically round to the closest supported value.
   * @note  Default to 0dBm
   */
  rf_power_t     power;

  /* End of mandatory fields */
  rf_pan_t       pan_id;
} RFConfig;


typedef struct __attribute__((packed)) {
  uint8_t  length;                  /**< packet length */
} rf_packet_hdr_t;

/**
 * @brief   In-memory structure of a rf radio packet
 */
typedef struct __attribute__((packed)) {
  rf_packet_hdr_t hdr;
  uint8_t payload[RF_PAYLOAD_MAXLEN];  /**< actual payload */
} rf_packet_t;





/**
 * @brief   Structure representing a RF driver.
 */
struct RFDriver {
  /**
   * @brief Driver state.
   */    
  rfstate_t state;
  /**
   * @brief Current configuration data.
   */
  const RFConfig *config;    
#if RF_USE_WAIT || defined(__DOXYGEN__)
  /**
   * @brief Waiting thread.
   */
  thread_reference_t        thread;
#endif /* RF_USE_WAIT */
#if RF_USE_MUTUAL_EXCLUSION || defined(__DOXYGEN__)
  /**
   * @brief Mutex protecting the driver.
   */
  mutex_t                   mutex;
#endif /* RF_USE_MUTUAL_EXCLUSION */
#if defined(RF_DRIVER_EXT_FIELDS)
  RF_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the RADIO registers block.
   */
  NRF_RADIO_Type *radio;

  uint8_t error;

  rf_packet_t packet;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if NRF5_RF_USE_RADIO0 && !defined(__DOXYGEN__)
extern RFDriver RFD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void rf_lld_init(void);
  void rf_lld_start(RFDriver *rfp);
  void rf_lld_stop(RFDriver *rfp);
  void rf_lld_send(RFDriver *rfp,
		 rf_addr_t addr, size_t n, const uint8_t *txbuf);
  void rf_lld_stop_receive(RFDriver *rfp);
  void rf_lld_receive(RFDriver *rfp, size_t n, uint8_t *rxbuf);

#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_RF */

#endif /* HAL_RF_LLD_H */

/** @} */

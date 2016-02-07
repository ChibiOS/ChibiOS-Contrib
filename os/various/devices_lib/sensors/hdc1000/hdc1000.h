/*
    HDC1000 for ChibiOS/RT - Copyright (C) 2016 Stephane D'Alu
*/

/**
 * @file    hdc1000.h
 * @brief   HDC1000 Temperature/Humidiry sensor interface module header.
 *
 * @{
 */

#ifndef _SENSOR_HDC1000_H_
#define _SENSOR_HDC1000_H_

#include <math.h>
#include <stdbool.h>
#include "i2c_helpers.h"

/* I2C address */
#define HDC1000_I2CADDR_1           0x40
#define HDC1000_I2CADDR_2           0x41
#define HDC1000_I2CADDR_3           0x42
#define HDC1000_I2CADDR_4           0x43

#define HDC1000_I2CADDR_DEFAULT     HDC1000_I2CADDR_1


/* Size of serial (40 bits) */
#define HDC1000_SERIAL_SIZE         5

#define HDC1000_CONTINUOUS_ACQUISITION_SUPPORTED   FALSE


/**
 * When changing sensor settings, you generally need to wait
 * for 2 * getAquisitionTime(), as usually the first acquisition
 * will be corrupted by the change of settings.
 *
 * No locking is done.
 */


/**
 * @brief   HDC1000 configuration structure.
 */
typedef struct {
    I2CHelper i2c; /* keep it first */
} HDC1000_config;


/**
 * @brief   Driver state machine possible states.
 */
typedef enum __attribute__ ((__packed__)) {
    HDC1000_UNINIT    = 0,            /**< Not initialized.                */
    HDC1000_INIT      = 1,            /**< Initialized.                    */
    HDC1000_STARTED   = 2,            /**< Started.                        */
    HDC1000_MEASURING = 4,            /**< Measuring.                      */
    HDC1000_READY     = 3,            /**< Ready.                          */
    HDC1000_STOPPED   = 5,            /**< Stopped.                        */
    HDC1000_ERROR     = 6,            /**< Error.                          */
} HDC1000_state_t;



/**
 * @brief   HDC1000 configuration structure.
 */
typedef struct {
    HDC1000_config  *config;
    HDC1000_state_t  state;
    unsigned int     delay;    
    uint16_t         cfg;
} HDC1000_drv;

/**
 * @brief Initialize the sensor driver
 */
void
HDC1000_init(HDC1000_drv *drv,
	HDC1000_config *config);

/**
 * @brief Start the sensor
 */
msg_t
HDC1000_start(HDC1000_drv *drv);

/**
 * @brief   Stop the sensor
 *
 * @details If the sensor support it, it will be put in low energy mode.
 */
msg_t
HDC1000_stop(HDC1000_drv *drv);

/**
 * @brief   Check that the sensor is really present
 */
msg_t
HDC1000_check(HDC1000_drv *drv);


msg_t
HDC1000_readSerial(HDC1000_drv *drv, uint8_t *serial);

/**
 * @brief   Control the HD1000 heater.
 */
msg_t
HDC1000_setHeater(HDC1000_drv *drv,
	bool on);


/**
 * @brief Time necessary for the sensor to boot
 *
 * @returns
 *   unsigned int   time in millis-seconds
 */

static inline unsigned int
HDC1000_getBootupTime(HDC1000_drv *drv) {
    (void)drv;
    return 15;
};

/**
 * @brief Time necessary the sensor to for starting
 *
 * @returns
 *   unsigned int   time in millis-seconds
 */
static inline unsigned int
HDC1000_getStartupTime(HDC1000_drv *drv) {
    (void)drv;
    return 0;
};

/**
 * @brief Time in milli-seconds necessary for acquiring a naw measure
 *
 * @returns
 *   unsigned int   time in millis-seconds
 */
static inline unsigned int
HDC1000_getAcquisitionTime(HDC1000_drv *drv) {
    return drv->delay;
}

/**
 * @brief Trigger a mesure acquisition
 */
msg_t
HDC1000_startMeasure(HDC1000_drv *drv);

/**
 * @brief Read the newly acquiered measure
 *
 * @note  According the the sensor design the measure read
 *        can be any value acquired after the acquisition time
 *        and the call to readMeasure.
 */
msg_t
HDC1000_readMeasure(HDC1000_drv *drv,
	float *temperature, float *humidity);


/**
 * @brief   Read temperature and humidity
 *
 * @details According to the sensor specification/configuration
 *          (see #HDC1000_CONTINUOUS_ACQUISITION_SUPPORTED), 
 *          if the sensor is doing continuous measurement
 *          it's value will be requested and returned immediately.
 *          Otherwise a measure is started, the necessary amount of
 *          time for acquiring the value is spend sleeping (not spinning),
 *          and finally the measure is read.
 *
 * @note    In continuous measurement mode, if you just started
 *          the sensor, you will need to wait getAcquisitionTime()
 *          in addition to the usual getStartupTime()

 * @note    If using several sensors, it is better to start all the
 *          measure together, wait for the sensor having the longuest
 *          aquisition time, and finally read all the values
 */
msg_t
HDC1000_readTemperatureHumidity(HDC1000_drv *drv,
	float *temperature, float *humidity);

/**
 * @brief   Return the humidity value in percent.
 *
 * @details Use readTemperatureHumidity() for returning the humidity value.
 *
 * @note    Prefere readTemperatureHumidity(), if you need both temperature
 *          and humidity, or if you need better error handling.
 *
 * @returns
 *   float  humidity percent
 *   NAN    on failure
 */
static inline float
HDC1000_getHumidity(HDC1000_drv *drv) {
    float humidity   = NAN;
    HDC1000_readTemperatureHumidity(drv, NULL, &humidity);
    return humidity;
}

/**
 * @brief   Return the temperature value in °C.
 *
 * @details Use readTemperatureHumidity() for returning the humidity value.
 *
 * @note    Prefere readTemperatureHumidity(), if you need both temperature
 *          and humidity, or if you need better error handling.
 *
 * @returns
 *   float  humidity percent
 *   NAN    on failure
 */
static inline float
HDC1000_getTemperature(HDC1000_drv *drv) {
    float temperature = NAN;
    HDC1000_readTemperatureHumidity(drv, &temperature, NULL);
    return temperature;
}


#endif


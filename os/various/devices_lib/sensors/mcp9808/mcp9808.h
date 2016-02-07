/*
    MCP9808 for ChibiOS/RT - Copyright (C) 2016 Stephane D'Alu
*/

#ifndef _SENSOR_MCP9808_H_
#define _SENSOR_MCP9808_H_

#include <math.h>
#include <stdbool.h>
#include "i2c_helpers.h"


#define MCP9808_I2CADDR_DEFAULT        0x18

typedef enum {
    RES_2  = 0x00,  /* 1/2  = 0.5    */
    RES_4  = 0x01,  /* 1/4  = 0.25   */
    RES_8  = 0x10,  /* 1/8  = 0.125  */
    RES_16 = 0x11,  /* 1/16 = 0.0625 */
} MCP9808_resolution_t;



#define MCP9808_CONTINUOUS_ACQUISITION_SUPPORTED   TRUE

/**
 * @brief   MCP9808 configuration structure.
 */
typedef struct {
    I2CHelper i2c; /* keep it first */
} MCP9808_config;


/**
 * @brief   Driver state machine possible states.
 */
typedef enum __attribute__ ((__packed__)) {
    MCP9808_UNINIT    = 0,            /**< Not initialized.                */
    MCP9808_INIT      = 1,            /**< Initialized.                    */
    MCP9808_STARTED   = 2,            /**< Started.                        */
    MCP9808_MEASURING = 4,            /**< Measuring.                      */
    MCP9808_READY     = 3,            /**< Ready.                          */
    MCP9808_STOPPED   = 5,            /**< Stopped.                        */
    MCP9808_ERROR     = 6,            /**< Error.                          */
} MCP9808_state_t;


/**
 * @brief   MCP9808 configuration structure.
 */
typedef struct {
    MCP9808_config      *config;
    MCP9808_state_t      state;
    MCP9808_resolution_t resolution;
    uint16_t             cfg;
} MCP9808_drv;

/**
 * @brief   Initialize the sensor driver
 */
void
MCP9808_init(MCP9808_drv *drv,
	MCP9808_config *config);

/**
 * @brief   Check that the sensor is really present
 */
msg_t
MCP9808_check(MCP9808_drv *drv);

/**
 * @brief   Start the sensor
 */
msg_t
MCP9808_start(MCP9808_drv *drv);

/**
 * @brief   Stop the sensor
 *
 * @details If the sensor support it, it will be put in low energy mode.
 */
msg_t
MCP9808_stop(MCP9808_drv *drv);



/**
 * @brief   Control the MCP9809 resolution.
 */
msg_t
MCP9808_setResolution(MCP9808_drv *drv,
	MCP9808_resolution_t res);


/**
 * @brief Time necessary for the sensor to boot
 *
 * @returns
 *   unsigned int   time in millis-seconds
 */

static inline unsigned int
MCP9808_getBootupTime(MCP9808_drv *drv) {
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
MCP9808_getStartupTime(MCP9808_drv *drv) {
    (void)drv;
    return 0;
};

/**
 * @brief Time in milli-seconds necessary for acquiring a naw measure
 *
 * @returns
 *   unsigned int   time in millis-seconds
 */
unsigned int
MCP9808_getAcquisitionTime(MCP9808_drv *drv);

/**
 * @brief Trigger a mesure acquisition
 */
static inline msg_t
MCP9808_startMeasure(MCP9808_drv *drv) {
}

/**
 * @brief Read the newly acquiered measure
 *
 * @note  According the the sensor design the measure read
 *        can be any value acquired after the acquisition time
 *        and the call to readMeasure.
 */
msg_t
MCP9808_readMeasure(MCP9808_drv *drv,
	float *temperature);


/**
 * @brief   Read temperature and humidity
 *
 * @details According to the sensor specification/configuration
 *          (see #MCP9808_CONTINUOUS_ACQUISITION_SUPPORTED), 
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
MCP9808_readTemperature(MCP9808_drv *drv,
	float *temperature);

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
MCP9808_getTemperature(MCP9808_drv *drv) {
    float temperature = NAN;
    MCP9808_readTemperature(drv, &temperature);
    return temperature;
}






#endif


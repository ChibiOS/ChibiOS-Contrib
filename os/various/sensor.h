#ifndef _SENSOR_H_
#define _SENSOR_H_

#define SENSOR_OK        MSG_OK         /**< @brief Operation successful. */
#define SENSOR_TIMEOUT   MSG_TIMEOUT    /**< @brief Communication timeout */
#define SENSOR_RESET     MSG_REST       /**< @brief Communication error.  */
#define SENSOR_NOTFOUND  (msg_t)-20     /**< @brief Sensor not found.     */


/**
 * @brief   Driver state machine possible states.
 */
typedef enum __attribute__ ((__packed__)) {
    SENSOR_UNINIT    = 0,            /**< Not initialized.                */
    SENSOR_INIT      = 1,            /**< Initialized.                    */
    SENSOR_STARTED   = 2,            /**< Started.                        */
    SENSOR_MEASURING = 4,            /**< Measuring.                      */
    SENSOR_READY     = 3,            /**< Ready.                          */
    SENSOR_STOPPED   = 5,            /**< Stopped.                        */
    SENSOR_ERROR     = 6,            /**< Error.                          */
} sensor_state_t;

#endif



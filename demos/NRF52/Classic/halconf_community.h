/*
    ChibiOS - Copyright (C) 2016 Stéphane D'Alu

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


#ifndef _HALCONF_COMMUNITY_H_
#define _HALCONF_COMMUNITY_H_


/**
 * @brief   Enables the community overlay.
 */
#if !defined(HAL_USE_COMMUNITY) || defined(__DOXYGEN__)
#define HAL_USE_COMMUNITY           TRUE
#endif


/**
 * @brief   Enables the community subsystem.
 */
#if !defined(HAL_USE_RNG) || defined(__DOXYGEN__)
#define HAL_USE_RNG                 TRUE
#endif


#define HAL_USE_QEI                 TRUE


/*===========================================================================*/
/* QEI driver related settings.                                              */
/*===========================================================================*/

/**
 * @brief   Enables discard of overlow
 */
#if !defined(QEI_USE_OVERFLOW_DISCARD) || defined(__DOXYGEN__)
#define QEI_USE_OVERFLOW_DISCARD    TRUE
#endif

/**
 * @brief   Enables discard of overlow
 */
#if !defined(QEI_USE_OVERFLOW_MINMAX) || defined(__DOXYGEN__)
#define QEI_USE_OVERFLOW_MINMAX     TRUE
#endif





//#define HAL_USE_SOFTDEVICE TRUE

#define HAL_USE_CAPSENSE TRUE
#define CAPSENSE_USE_WAIT TRUE
#define CAPSENSE_USE_MUTUAL_EXCLUSION TRUE



#endif /* _HALCONF_COMMUNITY_H_ */

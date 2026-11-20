/*
    ChibiOS - Copyright (C) 2023 Xael South

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
 * @file    EFR32FG14P/efr32_registry.h
 * @brief   EFR32FG14P capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef EFR32_REGISTRY_H
#define EFR32_REGISTRY_H

/*===========================================================================*/
/* Defined device check.                                                     */
/*===========================================================================*/

#if !defined(EFR32FG14P231F128GM48) && !defined(EFR32FG14P231F256GM32) && \
    !defined(EFR32FG14P231F256GM48) && !defined(EFR32FG14P231F256IM32) && \
    !defined(EFR32FG14P231F256IM48) && !defined(EFR32FG14P232F128GM32) && \
    !defined(EFR32FG14P232F128GM48) && !defined(EFR32FG14P232F256GM32) && \
    !defined(EFR32FG14P232F256GM48) && !defined(EFR32FG14P233F128GM48) && \
    !defined(EFR32FG14P233F256GM48)
#error "No valid device defined."
#endif

/**
 * @brief   Sub-family identifier.
 */
#if !defined(EFR32FG14P23X) || defined(__DOXYGEN__)
#define EFR32FG14P23X
#endif


/* LETIM attributes.*/
#define EFR32_LETIM_MAX_CHANNELS            2

#define EFR32_HAS_LETIM1                    TRUE
#define EFR32_LETIM1_IS_32BITS              FALSE
#define EFR32_LETIM1_CHANNELS               2

#define EFR32_HAS_LETIM2                    FALSE
#define EFR32_LETIM2_IS_32BITS              FALSE
#define EFR32_LETIM2_CHANNELS               2

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/


/*===========================================================================*/
/* Common.                                                                   */
/*===========================================================================*/



/** @} */

#endif /* EFR32_REGISTRY_H */

/** @} */

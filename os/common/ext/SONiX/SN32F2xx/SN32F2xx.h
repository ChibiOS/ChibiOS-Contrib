#ifndef __SN32F2xx_H
#define __SN32F2xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
   
/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief SN32 Family
  */
#if !defined (SN32F2)
#define SN32F2
#endif /* SN32F2 */

/* Uncomment the line below according to the target SN32 device used in your
   application 
  */

#if !defined (SN32F240) && !defined (SN32F240B) && !defined (SN32F260) \
    && !defined (SN32F280) && !defined (SN32F290)
  /* #define SN32F230 */   /*!< SN32F239, SN32F238, SN32F237, SN32F236,and SN32F235 Devices */
  /* #define SN32F240 */   /*!< SN32F249, SN32F248, SN32F247, SN32F246 and SN32F245 Devices */
  /* #define SN32F240B */  /*!< SN32F248B, SN32F247B, SN32F246B and SN32F2451B Devices */
  /* #define SN32F260 */   /*!< SN32F268, SN32F267, SN32F265, SN32F2641,
                                   SN32F264 and SN32F263 Devices */
  /* #define SN32F280 */   /*!< SN32F289, SN32F288 and SN32F287 Devices */
  /* #define SN32F290 */   /*!< SN32F299. SN32F298 and SN32F297 Devices */
#include "board.h"
#endif

/** @addtogroup Device_Included
  * @{
  */

#if defined(SN32F240)
  #include "SN32F240.h"
#elif defined(SN32F240B)
  #include "SN32F240B.h"
#elif defined(SN32F260)
  #include "SN32F260.h"
#elif defined(SN32F280)
  #include "SN32F280.h"
#elif defined(SN32F290)
  #include "SN32F290.h"
#else
 #error "Please select first the target SN32F2xx device used in your application (in SN32F2xx.h file)"
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/*__SN32F2xx_H*/

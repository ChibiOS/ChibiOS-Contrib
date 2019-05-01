/**************************************************************************//**
 * @file     gpio.c
 * @version  V3.00
 * $Revision: 8 $
 * $Date: 16/06/08 9:58a $
 * @brief    NUC123 series GPIO driver source file
 *
 * @note
 * Copyright (C) 2014~2015 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include "NUC123.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup GPIO_Driver GPIO Driver
  @{
*/

/** @addtogroup GPIO_EXPORTED_FUNCTIONS GPIO Exported Functions
  @{
*/

/**
 * @brief       Set GPIO operation mode
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD or PF.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT10 ~ BIT15 for PA GPIO port. \n
 *                          It could be BIT0 ~ BIT10 and BIT12 ~ BIT15 for PB GPIO port. \n
 *                          It could be BIT0 ~ BIT5 and BIT8 ~ BIT13 for PC GPIO port. \n
 *                          It could be BIT0 ~ BIT5 and BIT8 ~ BIT11 for PD GPIO port. \n
 *                          It could be BIT0 ~ BIT3 for PF GPIO port.
 * @param[in]   u32Mode     Operation mode. It could be : 
  *                         - \ref GPIO_PMD_INPUT, 
 *                          - \ref GPIO_PMD_OUTPUT, 
 *                          - \ref GPIO_PMD_OPEN_DRAIN,
 *                          - \ref GPIO_PMD_QUASI
 *
 * @return      None
 *
 * @details     This function is used to set specified GPIO operation mode.
 */
void GPIO_SetMode(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode)
{
    uint32_t i;

    for(i = 0; i < GPIO_PIN_MAX; i++)
    {
        if(u32PinMask & (1 << i))
        {
            port->PMD = (port->PMD & ~(0x3 << (i << 1))) | (u32Mode << (i << 1));
        }
    }
}

/**
 * @brief       Enable GPIO interrupt
 *
 * @param[in]   port            GPIO port. It could be PA, PB, PC, PD or PF.
 * @param[in]   u32Pin          The pin of specified GPIO port. \n
 *                              It could be 10 ~ 15 for PA GPIO port. \n
 *                              It could be 0 ~ 10 and 12 ~ 15 for PB GPIO port. \n
 *                              It could be 0 ~ 5 and 8 ~ 13 for PC GPIO port. \n
 *                              It could be 0 ~ 5 and 8 ~ 11 for PD GPIO port. \n
 *                              It could be 0 ~ 3 for PF GPIO port.
 * @param[in]   u32IntAttribs   The interrupt attribute of specified GPIO pin. It could be : 
 *                              - \ref GPIO_INT_RISING 
 *                              - \ref GPIO_INT_FALLING 
 *                              - \ref GPIO_INT_BOTH_EDGE
 *                              - \ref GPIO_INT_HIGH 
 *                              - \ref GPIO_INT_LOW
 *
 * @return      None
 *
 * @details     This function is used to enable specified GPIO pin interrupt.
 */
void GPIO_EnableInt(GPIO_T *port, uint32_t u32Pin, uint32_t u32IntAttribs)
{
    port->IMD |= (((u32IntAttribs >> 24) & 0xFFUL) << u32Pin);
    port->IEN |= ((u32IntAttribs & 0xFFFFFFUL) << u32Pin);
}


/**
 * @brief       Disable GPIO interrupt
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD or PF.
 * @param[in]   u32Pin      The pin of specified GPIO port. \n
 *                          It could be 10 ~ 15 for PA GPIO port. \n
 *                          It could be 0 ~ 10 and 12 ~ 15 for PB GPIO port. \n
 *                          It could be 0 ~ 5 and 8 ~ 13 for PC GPIO port. \n
 *                          It could be 0 ~ 5 and 8 ~ 11 for PD GPIO port. \n
 *                          It could be 0 ~ 3 for PF GPIO port.  
 *
 * @return      None
 *
 * @details     This function is used to enable specified GPIO pin interrupt.
 */
void GPIO_DisableInt(GPIO_T *port, uint32_t u32Pin)
{
    port->IMD &= ~(1UL << u32Pin);
    port->IEN &= ~((0x00010001UL) << u32Pin);
}


/*@}*/ /* end of group GPIO_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group GPIO_Driver */

/*@}*/ /* end of group Standard_Driver */

/*** (C) COPYRIGHT 2014~2015 Nuvoton Technology Corp. ***/

/**************************************************************************//**
 * @file     fmc.h
 * @version  V3.0
 * @brief    M251 series Flash Memory Controller(FMC) driver header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

#ifndef __FMC_H__
#define __FMC_H__

#ifdef __cplusplus
extern "C"
{
#endif


/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup FMC_Driver FMC Driver
  @{
*/

/** @addtogroup FMC_EXPORTED_CONSTANTS FMC Exported Constants
  @{
*/

/*---------------------------------------------------------------------------------------------------------*/
/*  Global variables                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
typedef enum
{
    eFMC_ERRCODE_SUCCESS            = 0,
    eFMC_ERRCODE_CMD_TIMEOUT        = -1,
    eFMC_ERRCODE_INVALID_PARAM      = -2,
    eFMC_ERRCODE_CMD_FAIL           = -3,
    eFMC_ERRCODE_PROG_INTERRUPTED   = -4,
} E_FMC_ERRCODE;
extern int32_t  g_FMC_i32ErrCode; /*!< FMC global error code */

/*---------------------------------------------------------------------------------------------------------*/
/* Global constant definitions                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define ISBEN   0

/*---------------------------------------------------------------------------------------------------------*/
/* Define Base Address                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
#define FMC_APROM_BASE          0x00000000UL    /*!< APROM Base Address              */
#define FMC_APROM_END           0x00040000UL    /*!< APROM End Address               */
#define FMC_LDROM_BASE          0x00100000UL    /*!< LDROM Base Address              */
#define FMC_LDROM_END           0x00101000UL    /*!< LDROM End Address               */
#define FMC_XOM_BASE            0x00200000UL    /*!< XOM Base Address                */
#define FMC_CONFIG_BASE         0x00300000UL    /*!< CONFIG Base Address             */

#define FMC_CONFIG0_ADDR        (FMC_CONFIG_BASE)               /*!< CONFIG 0 Address               */
#define FMC_CONFIG1_ADDR        ((FMC_CONFIG_BASE) + 0x4UL)     /*!< CONFIG 1 Address               */
#define FMC_CONFIG2_ADDR        ((FMC_CONFIG_BASE) + 0x8UL)     /*!< CONFIG 2 Address               */

#define FMC_XOMR0BASE_ADDR      (FMC_XOM_BASE)                  /*!< XOMR 0 Base Address            */

#define FMC_APROM_SIZE          ((FMC_APROM_END) - (FMC_APROM_BASE))    /*!< APROM Size             */
#define FMC_LDROM_SIZE          ((FMC_LDROM_END) - (FMC_LDROM_BASE))    /*!< LDROM Size             */

#define FMC_FLASH_PAGE_SIZE     0x200UL                         /*!< Flash Page Size (512 Bytes)    */
#define FMC_PAGE_ADDR_MASK      ((~(FMC_FLASH_PAGE_SIZE) - 1))  /*!< Flash page address mask        */
#define FMC_MULTI_WORD_PROG_LEN 128UL                           /*!< Length of multi-word program.  */
/*---------------------------------------------------------------------------------------------------------*/
/*  ISPCTL constant definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define FMC_ISPCTL_BS_LDROM     0x1UL     /*!< ISPCTL setting to select to boot from LDROM */
#define FMC_ISPCTL_BS_APROM     0x0UL     /*!< ISPCTL setting to select to boot from APROM */

/*---------------------------------------------------------------------------------------------------------*/
/*  ISPCMD constant definitions                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#define FMC_ISPCMD_READ         0x00UL     /*!< ISP Command: Read Flash               */
#define FMC_ISPCMD_READ_UID     0x04UL     /*!< ISP Command: Read Unique ID           */
#define FMC_ISPCMD_READ_ALL1    0x08UL     /*!< ISP Command: Read all-one result      */
#define FMC_ISPCMD_READ_CID     0x0BUL     /*!< ISP Command: Read Company ID          */
#define FMC_ISPCMD_READ_PID     0x0CUL     /*!< ISP Command: Read Device ID           */
#define FMC_ISPCMD_CHECKSUM     0x0DUL     /*!< ISP Command: Read Checksum            */
#define FMC_ISPCMD_PROGRAM      0x21UL     /*!< ISP Command: 32-bit Program Flash     */
#define FMC_ISPCMD_PAGE_ERASE   0x22UL     /*!< ISP Command: Page Erase Flash         */
#define FMC_ISPCMD_MULTI_PROG   0x27UL     /*!< ISP Command: Flash Multi-Word Program */
#define FMC_ISPCMD_RUN_ALL1     0x28UL     /*!< ISP Command: Run all-one verification*/
#define FMC_ISPCMD_CAL_CHECKSUM 0x2DUL     /*!< ISP Command: Run Check Calculation    */
#define FMC_ISPCMD_VECMAP       0x2EUL     /*!< ISP Command: Set vector mapping       */

#define READ_ALLONE_YES         0xA11FFFFFUL    /*!< Check-all-one result is all one.     */
#define READ_ALLONE_NOT         0xA1100000UL    /*!< Check-all-one result is not all one. */
#define READ_ALLONE_CMD_FAIL    0xFFFFFFFFUL    /*!< Check-all-one command failed.        */

#define FMC_TIMEOUT_READ        ((SystemCoreClock/10)*2) /*!< Read command time-out 200 ms         \hideinitializer */
#define FMC_TIMEOUT_WRITE       ((SystemCoreClock/10)*2) /*!< Write command time-out 200 ms        \hideinitializer */
#define FMC_TIMEOUT_ERASE       ((SystemCoreClock/10)*4) /*!< Erase command time-out 400 ms        \hideinitializer */
#define FMC_TIMEOUT_CHKSUM      (SystemCoreClock*2)      /*!< Get checksum command time-out 2 s    \hideinitializer */
#define FMC_TIMEOUT_CHKALLONE   (SystemCoreClock*2)      /*!< Check-all-one command time-out 2 s   \hideinitializer */

/** @} end of group FMC_EXPORTED_CONSTANTS */

/** @addtogroup FMC_EXPORTED_FUNCTIONS FMC Exported Functions
  @{
*/

/*---------------------------------------------------------------------------------------------------------*/
/*  FMC Macro Definitions                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
/**
 * @brief      Enable ISP Function
 *
 *
 *
 * @details    This function will set ISPEN bit of ISPCTL control register to enable ISP function.
 *
 */
#define FMC_ENABLE_ISP()          (FMC->ISPCTL |=  FMC_ISPCTL_ISPEN_Msk)  /*!< Enable ISP Function  */

/**
 * @brief      Disable ISP Function
 *
 *
 *
 * @details    This function will clear ISPEN bit of ISPCTL control register to disable ISP function.
 *
 */
#define FMC_DISABLE_ISP()         (FMC->ISPCTL &= ~FMC_ISPCTL_ISPEN_Msk)  /*!< Disable ISP Function */

/**
 * @brief      Enable LDROM Update Function
 *
 *
 *
 * @details    This function will set LDUEN bit of ISPCTL control register to enable LDROM update function.
 *             User needs to set LDUEN bit before they can update LDROM.
 *
 */
#define FMC_ENABLE_LD_UPDATE()    (FMC->ISPCTL |=  FMC_ISPCTL_LDUEN_Msk)  /*!< Enable LDROM Update Function   */

/**
 * @brief      Disable LDROM Update Function
 *
 *
 *
 * @details    This function will set ISPEN bit of ISPCTL control register to disable LDROM update function.
 *
 */
#define FMC_DISABLE_LD_UPDATE()   (FMC->ISPCTL &= ~FMC_ISPCTL_LDUEN_Msk)  /*!< Disable LDROM Update Function  */

/**
 * @brief      Enable User Configuration Update Function
 *
 *
 *
 * @details    This function will set CFGUEN bit of ISPCTL control register to enable User Configuration update function.
 *             User needs to set CFGUEN bit before they can update User Configuration area.
 *
 */
#define FMC_ENABLE_CFG_UPDATE()   (FMC->ISPCTL |=  FMC_ISPCTL_CFGUEN_Msk) /*!< Enable CONFIG Update Function  */

/**
 * @brief      Disable User Configuration Update Function
 *
 *
 *
 * @details    This function will clear CFGUEN bit of ISPCTL control register to disable User Configuration update function.
 *
 */
#define FMC_DISABLE_CFG_UPDATE()  (FMC->ISPCTL &= ~FMC_ISPCTL_CFGUEN_Msk) /*!< Disable CONFIG Update Function */


/**
 * @brief      Enable APROM Update Function
 *
 *
 *
 * @details    This function will set APUEN bit of ISPCTL control register to enable APROM update function.
 *             User needs to set APUEN bit before they can update APROM in APROM boot mode.
 *
 */
#define FMC_ENABLE_AP_UPDATE()    (FMC->ISPCTL |=  FMC_ISPCTL_APUEN_Msk)  /*!< Enable APROM Update Function   */

/**
 * @brief      Disable APROM Update Function
 *
 *
 *
 * @details    This function will clear APUEN bit of ISPCTL control register to disable APROM update function.
 *
 */
#define FMC_DISABLE_AP_UPDATE()   (FMC->ISPCTL &= ~FMC_ISPCTL_APUEN_Msk)  /*!< Disable APROM Update Function  */

/**
 * @brief      Next Booting Selection function
 *
 * @param[in]  x   Booting from APROM(0)/LDROM(1)
 *
 *
 * @details    This function will set MCU next booting from LDROM/APROM.
 *
 * @note       When use this macro, the Boot Loader booting selection MBS(CONFIG0[5]) must be set.
 *
 */
#define FMC_SELECT_NEXT_BOOT(x)   (FMC->ISPCTL = (FMC->ISPCTL & ~FMC_ISPCTL_BS_Msk) | ((x) << FMC_ISPCTL_BS_Pos)) /*!< Select Next Booting, x = 0 or 1 */

/**
 * @brief      Get MCU Booting Status
 *
 *
 *
 * @details    This function will get status of chip next booting from LDROM/APROM.
 *
 */
#define FMC_GET_BOOT_STATUS()     ((FMC->ISPCTL & FMC_ISPCTL_BS_Msk)?1:0) /*!< Get MCU Booting Status */

/**
 * @brief      Get ISP fail flag
 *
 *
 *
 * @details    This function will get the status of ISP falil flag
 *
 */
#define FMC_GET_FAIL_FLAG()         ((FMC->ISPCTL & FMC_ISPCTL_ISPFF_Msk) ? 1UL : 0UL)  /*!< Get ISP fail flag */

/**
 * @brief      Clear ISP fail flag
 *
 *
 *
 * @details    This function will clear the status of ISP falil flag
 *
 */
#define FMC_CLR_FAIL_FLAG()         (FMC->ISPCTL |= FMC_ISPCTL_ISPFF_Msk)       /*!< Clear ISP fail flag */

/**
  * @brief    Disable APROM update function
  *
  *
  *
  * @details  Disable APROM update function will forbid APROM programming when boot form APROM.
  *           APROM update is default to be disable.
  *
  */
#define FMC_DisableAPUpdate()        (FMC->ISPCTL &= ~FMC_ISPCTL_APUEN_Msk)     /*!< Disable AP update */

/**
  * @brief    Disable User Configuration update function
  *
  *
  *
  * @details  Disable User Configuration update function will forbid User Configuration programming.
  *           User Configuration update is default to be disable.
  */
#define FMC_DisableConfigUpdate()     (FMC->ISPCTL &= ~FMC_ISPCTL_CFGUEN_Msk)   /*!< Disable config update */

/**
  * @brief    Disable LDROM update function
  *
  *

  * @details  Disable LDROM update function will forbid LDROM programming.
  *           LDROM update is default to be disable.
  */
#define FMC_DisableLDUpdate()          (FMC->ISPCTL &= ~FMC_ISPCTL_LDUEN_Msk)   /*!< Disable LD update */

/**
  * @brief    Enable APROM update function
  *
  *
  *
  * @details  Enable APROM to be able to program when boot from APROM.
  *
  */
#define FMC_EnableAPUpdate()           (FMC->ISPCTL |= FMC_ISPCTL_APUEN_Msk)    /*!< Enable AP update */

/**
  * @brief    Enable User Configuration update function
  *
  *
  *
  * @details  Enable User Configuration to be able to program.
  *
  */
#define FMC_EnableConfigUpdate()        (FMC->ISPCTL |= FMC_ISPCTL_CFGUEN_Msk)   /*!< Enable config update */

/**
  * @brief    Enable LDROM update function
  *
  *
  *
  * @details  Enable LDROM to be able to program.
  *
  */
#define FMC_EnableLDUpdate()             (FMC->ISPCTL |= FMC_ISPCTL_LDUEN_Msk)   /*!< Enable LD update */



/*---------------------------------------------------------------------------------------------------------*/
/* inline functions                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
static __INLINE uint32_t FMC_ReadUID(uint8_t u8Index);
static __INLINE uint32_t FMC_ReadCID(void);
static __INLINE uint32_t FMC_ReadPID(void);
static __INLINE uint32_t FMC_ReadUCID(uint32_t u32Index);
static __INLINE uint32_t FMC_ReadVBGCode(void);
static __INLINE uint32_t FMC_ReadVTEMPCode(void);
static __INLINE uint32_t FMC_ReadADCOffset(void);
static __INLINE void FMC_SetVectorPageAddr(uint32_t u32PageAddr);
static __INLINE uint32_t FMC_GetVECMAP(void);
static __INLINE uint32_t FMC_GetCheckSum(uint32_t u32Addr, int32_t i32Size);


/**
 * @brief       Read Unique ID
 *
 * @param[in]   u8Index  UID index. 0 = UID[31:0], 1 = UID[63:32], 2 = UID[95:64]
 *
 * @return      The 32-bit unique ID data of specified UID index.
 *              0xFFFFFFFF: Check g_FMC_i32ErrCode to know if command timeout
 *
 * @details     To read out 96-bit Unique ID.
 *
 * @note
 *              g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
 *
 */
static __INLINE uint32_t FMC_ReadUID(uint8_t u8Index)
{
    int32_t  tout = FMC_TIMEOUT_READ;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;
    FMC->ISPCMD = FMC_ISPCMD_READ_UID;
    FMC->ISPADDR = ((uint32_t)u8Index << 2u);
    FMC->ISPDAT = 0u;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
#if ISBEN
    __ISB();
#endif

    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    return FMC->ISPDAT;
}

/**
  * @brief    Read company ID
  *
  *
  * @return   The company ID (32-bit)
  *           0xFFFFFFFF: Check g_FMC_i32ErrCode to know if command timeout
  *
  * @details  The company ID of Nuvoton is fixed to be 0xDA
  *
  * @note
  *           g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
  *
  */
static __INLINE uint32_t FMC_ReadCID(void)
{
    int32_t  tout = FMC_TIMEOUT_READ;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;
    FMC->ISPCMD = FMC_ISPCMD_READ_CID;           /* Set ISP Command Code */
    FMC->ISPADDR = 0x0u;                         /* Must keep 0x0 when read CID */
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;          /* Trigger to start ISP procedure */
#if ISBEN
    __ISB();
#endif                                           /* To make sure ISP/CPU be Synchronized */

    /* Waiting for ISP Done */
    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    return FMC->ISPDAT;
}

/**
  * @brief    Read product ID
  *
  *
  * @return   The product ID (32-bit)
  *
  * @details  This function is used to read product ID.
  *           0xFFFFFFFF: Check g_FMC_i32ErrCode to know if command timeout
  *
  * @note
  *           g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
  *
  */
static __INLINE uint32_t FMC_ReadPID(void)
{
    int32_t  tout = FMC_TIMEOUT_READ;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;
    FMC->ISPCMD = FMC_ISPCMD_READ_PID;          /* Set ISP Command Code */
    FMC->ISPADDR = 0x04u;                       /* Must keep 0x4 when read PID */
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;         /* Trigger to start ISP procedure */
#if ISBEN
    __ISB();
#endif                                          /* To make sure ISP/CPU be Synchronized */

    /* Waiting for ISP Done */
    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    return FMC->ISPDAT;
}

/**
  * @brief      To read UCID
  *
  * @param[in]  u32Index    Index of the UCID to read. u32Index must be 0, 1, 2, or 3.
  *
  * @return     The UCID of specified index
  *             0xFFFFFFFF: Check g_FMC_i32ErrCode to know if command timeout
  *
  * @details    This function is used to read unique chip ID (UCID).
  *
  * @note
  *             g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
  *
  */
static __INLINE uint32_t FMC_ReadUCID(uint32_t u32Index)
{
    int32_t  tout = FMC_TIMEOUT_READ;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;
    FMC->ISPCMD = FMC_ISPCMD_READ_UID;            /* Set ISP Command Code */
    FMC->ISPADDR = (0x04u * u32Index) + 0x10u;    /* The UCID is at offset 0x10 with word alignment. */
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;           /* Trigger to start ISP procedure */
#if ISBEN
    __ISB();
#endif                                            /* To make sure ISP/CPU be Synchronized */

    /* Waiting for ISP Done */
    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    return FMC->ISPDAT;
}

/**
  * @brief      To read bang-gap voltage code
  *
  * @return     The bang-gap voltage code
  *             0xFFFFFFFF: Check g_FMC_i32ErrCode to know if command timeout
  *
  * @details    This function is used to read bang-gap voltage code
  *
  * @note
  *             g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
  *
  */
static __INLINE uint32_t FMC_ReadVBGCode(void)
{
    int32_t  tout = FMC_TIMEOUT_READ;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;
    FMC->ISPCMD = FMC_ISPCMD_READ_UID;            /* Set ISP Command Code */
    FMC->ISPADDR = 0x70;                          /* The VBG is at offset 0x70 with word alignment. */
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;           /* Trigger to start ISP procedure */
#if ISBEN
    __ISB();
#endif                                            /* To make sure ISP/CPU be Synchronized */

    /* Waiting for ISP Done */
    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    return FMC->ISPDAT;
}

/**
  * @brief      To read the temperature sensor ADC code
  *
  * @return     The temperature sensor ADC code
  *             0xFFFFFFFF: Check g_FMC_i32ErrCode to know if command timeout
  *
  * @details    This function is used to read temperature sensor ADC code
  *
  * @note
  *             g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
  *
  */
static __INLINE uint32_t FMC_ReadVTEMPCode(void)
{
    int32_t  tout = FMC_TIMEOUT_READ;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;
    FMC->ISPCMD = FMC_ISPCMD_READ_UID;            /* Set ISP Command Code */
    FMC->ISPADDR = 0x74;                          /* The VTEMP code is at offset 0x74 with word alignment */
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;           /* Trigger to start ISP procedure */
#if ISBEN
    __ISB();
#endif                                            /* To make sure ISP/CPU be Synchronized */

    /* Waiting for ISP Done */
    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    return FMC->ISPDAT;
}

/**
  * @brief      To read the calibration value for ADC offset
  *
  * @return     The calibration value for ADC offset
  *             0xFFFFFFFF: Check g_FMC_i32ErrCode to know if command timeout
  *
  * @details    This function is used to read the calibration value for ADC offset
  *
  * @note
  *             g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
  *
  */
static __INLINE uint32_t FMC_ReadADCOffset(void)
{
    int32_t  tout = FMC_TIMEOUT_READ;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;
    FMC->ISPCMD = FMC_ISPCMD_READ_UID;            /* Set ISP Command Code */
    FMC->ISPADDR = 0x78;                          /* The calibration value for ADC offset is at offset 0x78 with word alignment */
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;           /* Trigger to start ISP procedure */
#if ISBEN
    __ISB();
#endif                                            /* To make sure ISP/CPU be Synchronized */

    /* Waiting for ISP Done */
    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    return FMC->ISPDAT;
}

/**
 * @brief       Set vector mapping address
 *
 * @param[in]   u32PageAddr  The page address to remap to address 0x0. The address must be page alignment.
 *
 * @details     This function is used to set VECMAP to map specified page to vector page (0x0).
 *
 * @note
 *              VECMAP only valid when new IAP function is enabled. (CBS = 10'b or 00'b)
 *              g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
 *
 */
static __INLINE void FMC_SetVectorPageAddr(uint32_t u32PageAddr)
{
    int32_t  tout = FMC_TIMEOUT_WRITE;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;
    FMC->ISPCMD = FMC_ISPCMD_VECMAP;             /* Set ISP Command Code */
    FMC->ISPADDR = u32PageAddr;                  /* The address of specified page which will be map to address 0x0. It must be page alignment. */
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;          /* Trigger to start ISP procedure */
#if ISBEN
    __ISB();
#endif                                /* To make sure ISP/CPU be Synchronized */

    /* Waiting for ISP Done */
    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
    }
}

/**
 * @brief       Get current vector mapping address.
 *
 *
 * @return      The current vector mapping address.
 *
 * @details     To get VECMAP value which is the page address for remapping to vector page (0x0).
 *
 * @note
 *              VECMAP only valid when new IAP function is enabled. (CBS = 10'b or 00'b)
 *
 */
static __INLINE uint32_t FMC_GetVECMAP(void)
{
    return (FMC->ISPSTS & FMC_ISPSTS_VECMAP_Msk);
}


/**
  * @brief      Run CRC32 checksum calculation and get result.
  *
  * @param[in]  u32Addr    Starting flash address. It must be a page aligned address.
  * @param[in]  i32Size    Byte count of flash to be calculated. It must be multiple of 512 bytes.
  *
  * @retval     0xFFFFFFFF: Check g_FMC_i32ErrCode to know if command timeout or invalid parameter
  * @retval     Others    : Checksum value of specify area
  *
  * @details    Run ISP checksum command to calculate specify area
  *
  * @note
  *             g_FMC_i32ErrCode will be set to eFMC_ERRCODE_CMD_TIMEOUT if command timeout.
  *             g_FMC_i32ErrCode will be set to eFMC_ERRCODE_INVALID_PARAM if not 512 aligned.
  *
  */
static __INLINE uint32_t FMC_GetCheckSum(uint32_t u32Addr, int32_t i32Size)
{
    int32_t  tout;

    g_FMC_i32ErrCode = eFMC_ERRCODE_SUCCESS;

    if ((u32Addr % 512UL) || (i32Size % 512UL))
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_INVALID_PARAM;
        return 0xFFFFFFFF;
    }

    FMC->ISPCMD = FMC_ISPCMD_CAL_CHECKSUM;
    FMC->ISPADDR = u32Addr;
    FMC->ISPDAT = (uint32_t)i32Size;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;
#if ISBEN
    __ISB();
#endif

    tout = FMC_TIMEOUT_CHKSUM;

    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    FMC->ISPCMD = FMC_ISPCMD_CHECKSUM;
    FMC->ISPTRG = FMC_ISPTRG_ISPGO_Msk;

    tout = FMC_TIMEOUT_CHKSUM;

    while ((tout-- > 0) && (FMC->ISPTRG & FMC_ISPTRG_ISPGO_Msk)) {}

    if (tout <= 0)
    {
        g_FMC_i32ErrCode = eFMC_ERRCODE_CMD_TIMEOUT;
        return 0xFFFFFFFF;
    }

    return FMC->ISPDAT;
}

void FMC_Open(void);
void FMC_Close(void);
int32_t FMC_ReadConfig(uint32_t u32Config[], uint32_t u32Count);
int32_t FMC_WriteConfig(uint32_t u32Config[], uint32_t u32Count);
void FMC_SetBootSource(int32_t i32BootSrc);
int32_t FMC_GetBootSource(void);
uint32_t FMC_CheckAllOne(uint32_t u32addr, uint32_t u32count);
uint32_t FMC_GetChkSum(uint32_t u32addr, uint32_t u32count);
int32_t FMC_Is_XOM_Actived(uint32_t xom_num);
int32_t FMC_Erase_XOM(uint32_t xom_num);
int32_t FMC_Erase(uint32_t u32Addr);
int32_t FMC_Config_XOM(uint32_t xom_num, uint32_t xom_base, uint8_t xom_page);
uint32_t FMC_Read(uint32_t u32Addr);
void FMC_Write(uint32_t u32Addr, uint32_t u32Data);
int32_t FMC_Write128(uint32_t u32Addr, uint32_t pu32Buf[]);

/** @} end of group FMC_EXPORTED_FUNCTIONS */

/** @} end of group FMC_Driver */

/** @} end of group Standard_Driver */

#ifdef __cplusplus
}

#endif

#endif /* __FMC_H__ */

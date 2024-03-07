/**********************************************************************************
 *
 * @file    reg_mswd.h
 * @brief   MSWD Head File
 *
 * @date    23 Nov 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          23 Nov 2021     Ginger          the first version
 *
 * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 **********************************************************************************
 */

#ifndef __MSWD_H__
#define __MSWD_H__


/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/

/*  Support for anonymous structures and unions.  */
////#pragma anon_unions

/****************** Bit definition for MSWD_CFG register ************************/

# define    MSWD_CFG_RTSPA_POSS 22U
# define    MSWD_CFG_RTSPA_POSE 31U
# define    MSWD_CFG_RTSPA_MSK BITS(MSWD_CFG_RTSPA_POSS, MSWD_CFG_RTSPA_POSE)

# define    MSWD_CFG_RETRY_POSS 9U
# define    MSWD_CFG_RETRY_POSE 21U
# define    MSWD_CFG_RETRY_MSK BITS(MSWD_CFG_RETRY_POSS, MSWD_CFG_RETRY_POSE)

# define    MSWD_CFG_DOCP_POS 8U
# define    MSWD_CFG_DOCP_MSK BIT(MSWD_CFG_DOCP_POS)

# define    MSWD_CFG_DAWC_POSS 6U
# define    MSWD_CFG_DAWC_POSE 7U
# define    MSWD_CFG_DAWC_MSK BITS(MSWD_CFG_DAWC_POSS, MSWD_CFG_DAWC_POSE)

# define    MSWD_CFG_DHAC_POSS 4U
# define    MSWD_CFG_DHAC_POSE 5U
# define    MSWD_CFG_DHAC_MSK BITS(MSWD_CFG_DHAC_POSS, MSWD_CFG_DHAC_POSE)

# define    MSWD_CFG_FREQ_POSS 0U
# define    MSWD_CFG_FREQ_POSE 3U
# define    MSWD_CFG_FREQ_MSK BITS(MSWD_CFG_FREQ_POSS, MSWD_CFG_FREQ_POSE)

/****************** Bit definition for MSWD_JTAG2SWD register ************************/

# define    MSWD_JTAG2SWD_JTAG2SWD_POSS 0U
# define    MSWD_JTAG2SWD_JTAG2SWD_POSE 31U
# define    MSWD_JTAG2SWD_JTAG2SWD_MSK BITS(MSWD_JTAG2SWD_JTAG2SWD_POSS, MSWD_JTAG2SWD_JTAG2SWD_POSE)

/****************** Bit definition for MSWD_LINERESET register ************************/

# define    MSWD_LINERESET_LINERESET_POSS 0U
# define    MSWD_LINERESET_LINERESET_POSE 31U
# define    MSWD_LINERESET_LINERESET_MSK BITS(MSWD_LINERESET_LINERESET_POSS, MSWD_LINERESET_LINERESET_POSE)

/****************** Bit definition for MSWD_STS register ************************/

# define    MSWD_STS_PARITY_POS 3U
# define    MSWD_STS_PARITY_MSK BIT(MSWD_STS_PARITY_POS)

# define    MSWD_STS_ACK_POSS 0U
# define    MSWD_STS_ACK_POSE 2U
# define    MSWD_STS_ACK_MSK BITS(MSWD_STS_ACK_POSS, MSWD_STS_ACK_POSE)

/****************** Bit definition for MSWD_DP_IDR_ABORT register ************************/

# define    MSWD_DP_IDR_ABORT_DP_IDR_ABORT_POSS 0U
# define    MSWD_DP_IDR_ABORT_DP_IDR_ABORT_POSE 31U
# define    MSWD_DP_IDR_ABORT_DP_IDR_ABORT_MSK BITS(MSWD_DP_IDR_ABORT_DP_IDR_ABORT_POSS, MSWD_DP_IDR_ABORT_DP_IDR_ABORT_POSE)

/****************** Bit definition for MSWD_DP_CSR_WCR register ************************/

# define    MSWD_DP_CSR_WCR_DP_CSR_WCR_POSS 0U
# define    MSWD_DP_CSR_WCR_DP_CSR_WCR_POSE 31U
# define    MSWD_DP_CSR_WCR_DP_CSR_WCR_MSK BITS(MSWD_DP_CSR_WCR_DP_CSR_WCR_POSS, MSWD_DP_CSR_WCR_DP_CSR_WCR_POSE)

/****************** Bit definition for MSWD_DP_RESEND_SELECT register ************************/

# define    MSWD_DP_RESEND_SELECT_DP_RESEND_SELECT_POSS 0U
# define    MSWD_DP_RESEND_SELECT_DP_RESEND_SELECT_POSE 31U
# define    MSWD_DP_RESEND_SELECT_DP_RESEND_SELECT_MSK BITS(MSWD_DP_RESEND_SELECT_DP_RESEND_SELECT_POSS, MSWD_DP_RESEND_SELECT_DP_RESEND_SELECT_POSE)

/****************** Bit definition for MSWD_DP_RDBUF_ROUTESEL register ************************/

# define    MSWD_DP_RDBUF_ROUTESEL_DP_RDBUF_ROUTESEL_POSS 0U
# define    MSWD_DP_RDBUF_ROUTESEL_DP_RDBUF_ROUTESEL_POSE 31U
# define    MSWD_DP_RDBUF_ROUTESEL_DP_RDBUF_ROUTESEL_MSK BITS(MSWD_DP_RDBUF_ROUTESEL_DP_RDBUF_ROUTESEL_POSS, MSWD_DP_RDBUF_ROUTESEL_DP_RDBUF_ROUTESEL_POSE)

/****************** Bit definition for MSWD_AP_CSW register ************************/

# define    MSWD_AP_CSW_AP_CSW_POSS 0U
# define    MSWD_AP_CSW_AP_CSW_POSE 31U
# define    MSWD_AP_CSW_AP_CSW_MSK BITS(MSWD_AP_CSW_AP_CSW_POSS, MSWD_AP_CSW_AP_CSW_POSE)

/****************** Bit definition for MSWD_AP_TAR register ************************/

# define    MSWD_AP_TAR_AP_TAR_POSS 0U
# define    MSWD_AP_TAR_AP_TAR_POSE 31U
# define    MSWD_AP_TAR_AP_TAR_MSK BITS(MSWD_AP_TAR_AP_TAR_POSS, MSWD_AP_TAR_AP_TAR_POSE)

/****************** Bit definition for MSWD_AP_DRW register ************************/

# define    MSWD_AP_DRW_AP_DRW_POSS 0U
# define    MSWD_AP_DRW_AP_DRW_POSE 31U
# define    MSWD_AP_DRW_AP_DRW_MSK BITS(MSWD_AP_DRW_AP_DRW_POSS, MSWD_AP_DRW_AP_DRW_POSE)

/****************** Bit definition for MSWD_AP_BD0 register ************************/

# define    MSWD_AP_BD0_AP_BD0_POSS 0U
# define    MSWD_AP_BD0_AP_BD0_POSE 31U
# define    MSWD_AP_BD0_AP_BD0_MSK BITS(MSWD_AP_BD0_AP_BD0_POSS, MSWD_AP_BD0_AP_BD0_POSE)

/****************** Bit definition for MSWD_AP_BD1 register ************************/

# define    MSWD_AP_BD1_AP_BD1_POSS 0U
# define    MSWD_AP_BD1_AP_BD1_POSE 31U
# define    MSWD_AP_BD1_AP_BD1_MSK BITS(MSWD_AP_BD1_AP_BD1_POSS, MSWD_AP_BD1_AP_BD1_POSE)

/****************** Bit definition for MSWD_AP_BD2 register ************************/

# define    MSWD_AP_BD2_AP_BD2_POSS 0U
# define    MSWD_AP_BD2_AP_BD2_POSE 31U
# define    MSWD_AP_BD2_AP_BD2_MSK BITS(MSWD_AP_BD2_AP_BD2_POSS, MSWD_AP_BD2_AP_BD2_POSE)

/****************** Bit definition for MSWD_AP_BD3 register ************************/

# define    MSWD_AP_BD3_AP_BD3_POSS 0U
# define    MSWD_AP_BD3_AP_BD3_POSE 31U
# define    MSWD_AP_BD3_AP_BD3_MSK BITS(MSWD_AP_BD3_AP_BD3_POSS, MSWD_AP_BD3_AP_BD3_POSE)

/****************** Bit definition for MSWD_AP_CFG register ************************/

# define    MSWD_AP_CFG_AP_CFG_POSS 0U
# define    MSWD_AP_CFG_AP_CFG_POSE 31U
# define    MSWD_AP_CFG_AP_CFG_MSK BITS(MSWD_AP_CFG_AP_CFG_POSS, MSWD_AP_CFG_AP_CFG_POSE)

/****************** Bit definition for MSWD_AP_BASE register ************************/

# define    MSWD_AP_BASE_AP_BASE_POSS 0U
# define    MSWD_AP_BASE_AP_BASE_POSE 31U
# define    MSWD_AP_BASE_AP_BASE_MSK BITS(MSWD_AP_BASE_AP_BASE_POSS, MSWD_AP_BASE_AP_BASE_POSE)

/****************** Bit definition for MSWD_AP_IDR register ************************/

# define    MSWD_AP_IDR_AP_IDR_POSS 0U
# define    MSWD_AP_IDR_AP_IDR_POSE 31U
# define    MSWD_AP_IDR_AP_IDR_MSK BITS(MSWD_AP_IDR_AP_IDR_POSS, MSWD_AP_IDR_AP_IDR_POSE)

/****************** Bit definition for MSWD_ISP_CMD register ************************/

# define    MSWD_ISP_CMD_ISP_CMD_POSS 0U
# define    MSWD_ISP_CMD_ISP_CMD_POSE 7U
# define    MSWD_ISP_CMD_ISP_CMD_MSK BITS(MSWD_ISP_CMD_ISP_CMD_POSS, MSWD_ISP_CMD_ISP_CMD_POSE)

/****************** Bit definition for MSWD_ISP_DAT register ************************/

# define    MSWD_ISP_DAT_ISP_DAT_POSS 0U
# define    MSWD_ISP_DAT_ISP_DAT_POSE 31U
# define    MSWD_ISP_DAT_ISP_DAT_MSK BITS(MSWD_ISP_DAT_ISP_DAT_POSS, MSWD_ISP_DAT_ISP_DAT_POSE)

/****************** Bit definition for MSWD_ISP_CFG register ************************/

# define    MSWD_ISP_CFG_ISP_GCKOI_POS 0U
# define    MSWD_ISP_CFG_ISP_GCKOI_MSK BIT(MSWD_ISP_CFG_ISP_GCKOI_POS)

typedef struct
{
    __IO uint32_t CFG;                      // 0x000
    __IO uint32_t JTAG2SWD;                 // 0x004
    __IO uint32_t LINERESET;                // 0x008
    __I  uint32_t STS;                      // 0x00c
    __IO uint32_t DP_IDR_ABORT;             // 0x010
    __IO uint32_t DP_CSR_WCR;               // 0x014
    __IO uint32_t DP_RESEND_SELECT;         // 0x018
    __IO uint32_t DP_RDBUF_ROUTESEL;        // 0x01c
    __IO uint32_t AP_CSW;                   // 0x020
    __IO uint32_t AP_TAR;                   // 0x024
    __IO uint32_t AP_DRW;                   // 0x028
    __IO uint32_t AP_BD0;                   // 0x02c
    __IO uint32_t AP_BD1;                   // 0x030
    __IO uint32_t AP_BD2;                   // 0x034
    __IO uint32_t AP_BD3;                   // 0x038
    __IO uint32_t AP_CFG;                   // 0x03c
    __IO uint32_t AP_BASE;                  // 0x040
    __IO uint32_t AP_IDR;                   // 0x044
    __IO uint32_t RESERVED0[2];             // 0x048-0x04c
    __IO uint32_t ISP_CMD;                  // 0x050
    __IO uint32_t ISP_DAT;                  // 0x054
    __IO uint32_t ISP_CFG;                  // 0x058
} MSWD_TypeDef;


#endif

/*
 * Component description for CMCC
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2023-03-17T09:50:08Z */
#ifndef _SAME54_CMCC_COMPONENT_H_
#define _SAME54_CMCC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR CMCC                                         */
/* ************************************************************************** */

/* -------- CMCC_TYPE : (CMCC Offset: 0x00) ( R/ 32) Cache Type Register -------- */
#define CMCC_TYPE_RESETVALUE                  _UINT32_(0x12D2)                                     /*  (CMCC_TYPE) Cache Type Register  Reset Value */

#define CMCC_TYPE_GCLK_Pos                    _UINT32_(1)                                          /* (CMCC_TYPE) dynamic Clock Gating supported Position */
#define CMCC_TYPE_GCLK_Msk                    (_UINT32_(0x1) << CMCC_TYPE_GCLK_Pos)                /* (CMCC_TYPE) dynamic Clock Gating supported Mask */
#define CMCC_TYPE_GCLK(value)                 (CMCC_TYPE_GCLK_Msk & (_UINT32_(value) << CMCC_TYPE_GCLK_Pos)) /* Assigment of value for GCLK in the CMCC_TYPE register */
#define CMCC_TYPE_RRP_Pos                     _UINT32_(4)                                          /* (CMCC_TYPE) Round Robin Policy supported Position */
#define CMCC_TYPE_RRP_Msk                     (_UINT32_(0x1) << CMCC_TYPE_RRP_Pos)                 /* (CMCC_TYPE) Round Robin Policy supported Mask */
#define CMCC_TYPE_RRP(value)                  (CMCC_TYPE_RRP_Msk & (_UINT32_(value) << CMCC_TYPE_RRP_Pos)) /* Assigment of value for RRP in the CMCC_TYPE register */
#define CMCC_TYPE_WAYNUM_Pos                  _UINT32_(5)                                          /* (CMCC_TYPE) Number of Way Position */
#define CMCC_TYPE_WAYNUM_Msk                  (_UINT32_(0x3) << CMCC_TYPE_WAYNUM_Pos)              /* (CMCC_TYPE) Number of Way Mask */
#define CMCC_TYPE_WAYNUM(value)               (CMCC_TYPE_WAYNUM_Msk & (_UINT32_(value) << CMCC_TYPE_WAYNUM_Pos)) /* Assigment of value for WAYNUM in the CMCC_TYPE register */
#define   CMCC_TYPE_WAYNUM_ARCH4WAY_Val       _UINT32_(0x2)                                        /* (CMCC_TYPE) 4-WAY set associative  */
#define CMCC_TYPE_WAYNUM_ARCH4WAY             (CMCC_TYPE_WAYNUM_ARCH4WAY_Val << CMCC_TYPE_WAYNUM_Pos) /* (CMCC_TYPE) 4-WAY set associative Position  */
#define CMCC_TYPE_LCKDOWN_Pos                 _UINT32_(7)                                          /* (CMCC_TYPE) Lock Down supported Position */
#define CMCC_TYPE_LCKDOWN_Msk                 (_UINT32_(0x1) << CMCC_TYPE_LCKDOWN_Pos)             /* (CMCC_TYPE) Lock Down supported Mask */
#define CMCC_TYPE_LCKDOWN(value)              (CMCC_TYPE_LCKDOWN_Msk & (_UINT32_(value) << CMCC_TYPE_LCKDOWN_Pos)) /* Assigment of value for LCKDOWN in the CMCC_TYPE register */
#define CMCC_TYPE_CSIZE_Pos                   _UINT32_(8)                                          /* (CMCC_TYPE) Cache Size Position */
#define CMCC_TYPE_CSIZE_Msk                   (_UINT32_(0x7) << CMCC_TYPE_CSIZE_Pos)               /* (CMCC_TYPE) Cache Size Mask */
#define CMCC_TYPE_CSIZE(value)                (CMCC_TYPE_CSIZE_Msk & (_UINT32_(value) << CMCC_TYPE_CSIZE_Pos)) /* Assigment of value for CSIZE in the CMCC_TYPE register */
#define   CMCC_TYPE_CSIZE_CSIZE_1KB_Val       _UINT32_(0x0)                                        /* (CMCC_TYPE) Cache Size is 1 KB  */
#define   CMCC_TYPE_CSIZE_CSIZE_2KB_Val       _UINT32_(0x1)                                        /* (CMCC_TYPE) Cache Size is 2 KB  */
#define   CMCC_TYPE_CSIZE_CSIZE_4KB_Val       _UINT32_(0x2)                                        /* (CMCC_TYPE) Cache Size is 4 KB  */
#define CMCC_TYPE_CSIZE_CSIZE_1KB             (CMCC_TYPE_CSIZE_CSIZE_1KB_Val << CMCC_TYPE_CSIZE_Pos) /* (CMCC_TYPE) Cache Size is 1 KB Position  */
#define CMCC_TYPE_CSIZE_CSIZE_2KB             (CMCC_TYPE_CSIZE_CSIZE_2KB_Val << CMCC_TYPE_CSIZE_Pos) /* (CMCC_TYPE) Cache Size is 2 KB Position  */
#define CMCC_TYPE_CSIZE_CSIZE_4KB             (CMCC_TYPE_CSIZE_CSIZE_4KB_Val << CMCC_TYPE_CSIZE_Pos) /* (CMCC_TYPE) Cache Size is 4 KB Position  */
#define CMCC_TYPE_CLSIZE_Pos                  _UINT32_(11)                                         /* (CMCC_TYPE) Cache Line Size Position */
#define CMCC_TYPE_CLSIZE_Msk                  (_UINT32_(0x7) << CMCC_TYPE_CLSIZE_Pos)              /* (CMCC_TYPE) Cache Line Size Mask */
#define CMCC_TYPE_CLSIZE(value)               (CMCC_TYPE_CLSIZE_Msk & (_UINT32_(value) << CMCC_TYPE_CLSIZE_Pos)) /* Assigment of value for CLSIZE in the CMCC_TYPE register */
#define   CMCC_TYPE_CLSIZE_CLSIZE_16B_Val     _UINT32_(0x2)                                        /* (CMCC_TYPE) Cache Line Size is 16 bytes  */
#define CMCC_TYPE_CLSIZE_CLSIZE_16B           (CMCC_TYPE_CLSIZE_CLSIZE_16B_Val << CMCC_TYPE_CLSIZE_Pos) /* (CMCC_TYPE) Cache Line Size is 16 bytes Position  */
#define CMCC_TYPE_Msk                         _UINT32_(0x00003FF2)                                 /* (CMCC_TYPE) Register Mask  */


/* -------- CMCC_CFG : (CMCC Offset: 0x04) (R/W 32) Cache Configuration Register -------- */
#define CMCC_CFG_RESETVALUE                   _UINT32_(0x20)                                       /*  (CMCC_CFG) Cache Configuration Register  Reset Value */

#define CMCC_CFG_ICDIS_Pos                    _UINT32_(1)                                          /* (CMCC_CFG) Instruction Cache Disable Position */
#define CMCC_CFG_ICDIS_Msk                    (_UINT32_(0x1) << CMCC_CFG_ICDIS_Pos)                /* (CMCC_CFG) Instruction Cache Disable Mask */
#define CMCC_CFG_ICDIS(value)                 (CMCC_CFG_ICDIS_Msk & (_UINT32_(value) << CMCC_CFG_ICDIS_Pos)) /* Assigment of value for ICDIS in the CMCC_CFG register */
#define CMCC_CFG_DCDIS_Pos                    _UINT32_(2)                                          /* (CMCC_CFG) Data Cache Disable Position */
#define CMCC_CFG_DCDIS_Msk                    (_UINT32_(0x1) << CMCC_CFG_DCDIS_Pos)                /* (CMCC_CFG) Data Cache Disable Mask */
#define CMCC_CFG_DCDIS(value)                 (CMCC_CFG_DCDIS_Msk & (_UINT32_(value) << CMCC_CFG_DCDIS_Pos)) /* Assigment of value for DCDIS in the CMCC_CFG register */
#define CMCC_CFG_CSIZESW_Pos                  _UINT32_(4)                                          /* (CMCC_CFG) Cache size configured by software Position */
#define CMCC_CFG_CSIZESW_Msk                  (_UINT32_(0x7) << CMCC_CFG_CSIZESW_Pos)              /* (CMCC_CFG) Cache size configured by software Mask */
#define CMCC_CFG_CSIZESW(value)               (CMCC_CFG_CSIZESW_Msk & (_UINT32_(value) << CMCC_CFG_CSIZESW_Pos)) /* Assigment of value for CSIZESW in the CMCC_CFG register */
#define   CMCC_CFG_CSIZESW_CONF_CSIZE_1KB_Val _UINT32_(0x0)                                        /* (CMCC_CFG) The Cache Size is configured to 1KB  */
#define   CMCC_CFG_CSIZESW_CONF_CSIZE_2KB_Val _UINT32_(0x1)                                        /* (CMCC_CFG) The Cache Size is configured to 2KB  */
#define   CMCC_CFG_CSIZESW_CONF_CSIZE_4KB_Val _UINT32_(0x2)                                        /* (CMCC_CFG) The Cache Size is configured to 4KB  */
#define CMCC_CFG_CSIZESW_CONF_CSIZE_1KB       (CMCC_CFG_CSIZESW_CONF_CSIZE_1KB_Val << CMCC_CFG_CSIZESW_Pos) /* (CMCC_CFG) The Cache Size is configured to 1KB Position  */
#define CMCC_CFG_CSIZESW_CONF_CSIZE_2KB       (CMCC_CFG_CSIZESW_CONF_CSIZE_2KB_Val << CMCC_CFG_CSIZESW_Pos) /* (CMCC_CFG) The Cache Size is configured to 2KB Position  */
#define CMCC_CFG_CSIZESW_CONF_CSIZE_4KB       (CMCC_CFG_CSIZESW_CONF_CSIZE_4KB_Val << CMCC_CFG_CSIZESW_Pos) /* (CMCC_CFG) The Cache Size is configured to 4KB Position  */
#define CMCC_CFG_Msk                          _UINT32_(0x00000076)                                 /* (CMCC_CFG) Register Mask  */


/* -------- CMCC_CTRL : (CMCC Offset: 0x08) ( /W 32) Cache Control Register -------- */
#define CMCC_CTRL_RESETVALUE                  _UINT32_(0x00)                                       /*  (CMCC_CTRL) Cache Control Register  Reset Value */

#define CMCC_CTRL_CEN_Pos                     _UINT32_(0)                                          /* (CMCC_CTRL) Cache Controller Enable Position */
#define CMCC_CTRL_CEN_Msk                     (_UINT32_(0x1) << CMCC_CTRL_CEN_Pos)                 /* (CMCC_CTRL) Cache Controller Enable Mask */
#define CMCC_CTRL_CEN(value)                  (CMCC_CTRL_CEN_Msk & (_UINT32_(value) << CMCC_CTRL_CEN_Pos)) /* Assigment of value for CEN in the CMCC_CTRL register */
#define CMCC_CTRL_Msk                         _UINT32_(0x00000001)                                 /* (CMCC_CTRL) Register Mask  */


/* -------- CMCC_SR : (CMCC Offset: 0x0C) ( R/ 32) Cache Status Register -------- */
#define CMCC_SR_RESETVALUE                    _UINT32_(0x00)                                       /*  (CMCC_SR) Cache Status Register  Reset Value */

#define CMCC_SR_CSTS_Pos                      _UINT32_(0)                                          /* (CMCC_SR) Cache Controller Status Position */
#define CMCC_SR_CSTS_Msk                      (_UINT32_(0x1) << CMCC_SR_CSTS_Pos)                  /* (CMCC_SR) Cache Controller Status Mask */
#define CMCC_SR_CSTS(value)                   (CMCC_SR_CSTS_Msk & (_UINT32_(value) << CMCC_SR_CSTS_Pos)) /* Assigment of value for CSTS in the CMCC_SR register */
#define CMCC_SR_Msk                           _UINT32_(0x00000001)                                 /* (CMCC_SR) Register Mask  */


/* -------- CMCC_LCKWAY : (CMCC Offset: 0x10) (R/W 32) Cache Lock per Way Register -------- */
#define CMCC_LCKWAY_RESETVALUE                _UINT32_(0x00)                                       /*  (CMCC_LCKWAY) Cache Lock per Way Register  Reset Value */

#define CMCC_LCKWAY_LCKWAY_Pos                _UINT32_(0)                                          /* (CMCC_LCKWAY) Lockdown way Register Position */
#define CMCC_LCKWAY_LCKWAY_Msk                (_UINT32_(0xF) << CMCC_LCKWAY_LCKWAY_Pos)            /* (CMCC_LCKWAY) Lockdown way Register Mask */
#define CMCC_LCKWAY_LCKWAY(value)             (CMCC_LCKWAY_LCKWAY_Msk & (_UINT32_(value) << CMCC_LCKWAY_LCKWAY_Pos)) /* Assigment of value for LCKWAY in the CMCC_LCKWAY register */
#define CMCC_LCKWAY_Msk                       _UINT32_(0x0000000F)                                 /* (CMCC_LCKWAY) Register Mask  */


/* -------- CMCC_MAINT0 : (CMCC Offset: 0x20) ( /W 32) Cache Maintenance Register 0 -------- */
#define CMCC_MAINT0_RESETVALUE                _UINT32_(0x00)                                       /*  (CMCC_MAINT0) Cache Maintenance Register 0  Reset Value */

#define CMCC_MAINT0_INVALL_Pos                _UINT32_(0)                                          /* (CMCC_MAINT0) Cache Controller invalidate All Position */
#define CMCC_MAINT0_INVALL_Msk                (_UINT32_(0x1) << CMCC_MAINT0_INVALL_Pos)            /* (CMCC_MAINT0) Cache Controller invalidate All Mask */
#define CMCC_MAINT0_INVALL(value)             (CMCC_MAINT0_INVALL_Msk & (_UINT32_(value) << CMCC_MAINT0_INVALL_Pos)) /* Assigment of value for INVALL in the CMCC_MAINT0 register */
#define CMCC_MAINT0_Msk                       _UINT32_(0x00000001)                                 /* (CMCC_MAINT0) Register Mask  */


/* -------- CMCC_MAINT1 : (CMCC Offset: 0x24) ( /W 32) Cache Maintenance Register 1 -------- */
#define CMCC_MAINT1_RESETVALUE                _UINT32_(0x00)                                       /*  (CMCC_MAINT1) Cache Maintenance Register 1  Reset Value */

#define CMCC_MAINT1_INDEX_Pos                 _UINT32_(4)                                          /* (CMCC_MAINT1) Invalidate Index Position */
#define CMCC_MAINT1_INDEX_Msk                 (_UINT32_(0xFF) << CMCC_MAINT1_INDEX_Pos)            /* (CMCC_MAINT1) Invalidate Index Mask */
#define CMCC_MAINT1_INDEX(value)              (CMCC_MAINT1_INDEX_Msk & (_UINT32_(value) << CMCC_MAINT1_INDEX_Pos)) /* Assigment of value for INDEX in the CMCC_MAINT1 register */
#define CMCC_MAINT1_WAY_Pos                   _UINT32_(28)                                         /* (CMCC_MAINT1) Invalidate Way Position */
#define CMCC_MAINT1_WAY_Msk                   (_UINT32_(0xF) << CMCC_MAINT1_WAY_Pos)               /* (CMCC_MAINT1) Invalidate Way Mask */
#define CMCC_MAINT1_WAY(value)                (CMCC_MAINT1_WAY_Msk & (_UINT32_(value) << CMCC_MAINT1_WAY_Pos)) /* Assigment of value for WAY in the CMCC_MAINT1 register */
#define   CMCC_MAINT1_WAY_WAY0_Val            _UINT32_(0x0)                                        /* (CMCC_MAINT1) Way 0 is selection for index invalidation  */
#define   CMCC_MAINT1_WAY_WAY1_Val            _UINT32_(0x1)                                        /* (CMCC_MAINT1) Way 1 is selection for index invalidation  */
#define   CMCC_MAINT1_WAY_WAY2_Val            _UINT32_(0x2)                                        /* (CMCC_MAINT1) Way 2 is selection for index invalidation  */
#define   CMCC_MAINT1_WAY_WAY3_Val            _UINT32_(0x3)                                        /* (CMCC_MAINT1) Way 3 is selection for index invalidation  */
#define CMCC_MAINT1_WAY_WAY0                  (CMCC_MAINT1_WAY_WAY0_Val << CMCC_MAINT1_WAY_Pos)    /* (CMCC_MAINT1) Way 0 is selection for index invalidation Position  */
#define CMCC_MAINT1_WAY_WAY1                  (CMCC_MAINT1_WAY_WAY1_Val << CMCC_MAINT1_WAY_Pos)    /* (CMCC_MAINT1) Way 1 is selection for index invalidation Position  */
#define CMCC_MAINT1_WAY_WAY2                  (CMCC_MAINT1_WAY_WAY2_Val << CMCC_MAINT1_WAY_Pos)    /* (CMCC_MAINT1) Way 2 is selection for index invalidation Position  */
#define CMCC_MAINT1_WAY_WAY3                  (CMCC_MAINT1_WAY_WAY3_Val << CMCC_MAINT1_WAY_Pos)    /* (CMCC_MAINT1) Way 3 is selection for index invalidation Position  */
#define CMCC_MAINT1_Msk                       _UINT32_(0xF0000FF0)                                 /* (CMCC_MAINT1) Register Mask  */


/* -------- CMCC_MCFG : (CMCC Offset: 0x28) (R/W 32) Cache Monitor Configuration Register -------- */
#define CMCC_MCFG_RESETVALUE                  _UINT32_(0x00)                                       /*  (CMCC_MCFG) Cache Monitor Configuration Register  Reset Value */

#define CMCC_MCFG_MODE_Pos                    _UINT32_(0)                                          /* (CMCC_MCFG) Cache Controller Monitor Counter Mode Position */
#define CMCC_MCFG_MODE_Msk                    (_UINT32_(0x3) << CMCC_MCFG_MODE_Pos)                /* (CMCC_MCFG) Cache Controller Monitor Counter Mode Mask */
#define CMCC_MCFG_MODE(value)                 (CMCC_MCFG_MODE_Msk & (_UINT32_(value) << CMCC_MCFG_MODE_Pos)) /* Assigment of value for MODE in the CMCC_MCFG register */
#define   CMCC_MCFG_MODE_CYCLE_COUNT_Val      _UINT32_(0x0)                                        /* (CMCC_MCFG) Cycle counter  */
#define   CMCC_MCFG_MODE_IHIT_COUNT_Val       _UINT32_(0x1)                                        /* (CMCC_MCFG) Instruction hit counter  */
#define   CMCC_MCFG_MODE_DHIT_COUNT_Val       _UINT32_(0x2)                                        /* (CMCC_MCFG) Data hit counter  */
#define CMCC_MCFG_MODE_CYCLE_COUNT            (CMCC_MCFG_MODE_CYCLE_COUNT_Val << CMCC_MCFG_MODE_Pos) /* (CMCC_MCFG) Cycle counter Position  */
#define CMCC_MCFG_MODE_IHIT_COUNT             (CMCC_MCFG_MODE_IHIT_COUNT_Val << CMCC_MCFG_MODE_Pos) /* (CMCC_MCFG) Instruction hit counter Position  */
#define CMCC_MCFG_MODE_DHIT_COUNT             (CMCC_MCFG_MODE_DHIT_COUNT_Val << CMCC_MCFG_MODE_Pos) /* (CMCC_MCFG) Data hit counter Position  */
#define CMCC_MCFG_Msk                         _UINT32_(0x00000003)                                 /* (CMCC_MCFG) Register Mask  */


/* -------- CMCC_MEN : (CMCC Offset: 0x2C) (R/W 32) Cache Monitor Enable Register -------- */
#define CMCC_MEN_RESETVALUE                   _UINT32_(0x00)                                       /*  (CMCC_MEN) Cache Monitor Enable Register  Reset Value */

#define CMCC_MEN_MENABLE_Pos                  _UINT32_(0)                                          /* (CMCC_MEN) Cache Controller Monitor Enable Position */
#define CMCC_MEN_MENABLE_Msk                  (_UINT32_(0x1) << CMCC_MEN_MENABLE_Pos)              /* (CMCC_MEN) Cache Controller Monitor Enable Mask */
#define CMCC_MEN_MENABLE(value)               (CMCC_MEN_MENABLE_Msk & (_UINT32_(value) << CMCC_MEN_MENABLE_Pos)) /* Assigment of value for MENABLE in the CMCC_MEN register */
#define CMCC_MEN_Msk                          _UINT32_(0x00000001)                                 /* (CMCC_MEN) Register Mask  */


/* -------- CMCC_MCTRL : (CMCC Offset: 0x30) ( /W 32) Cache Monitor Control Register -------- */
#define CMCC_MCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (CMCC_MCTRL) Cache Monitor Control Register  Reset Value */

#define CMCC_MCTRL_SWRST_Pos                  _UINT32_(0)                                          /* (CMCC_MCTRL) Cache Controller Software Reset Position */
#define CMCC_MCTRL_SWRST_Msk                  (_UINT32_(0x1) << CMCC_MCTRL_SWRST_Pos)              /* (CMCC_MCTRL) Cache Controller Software Reset Mask */
#define CMCC_MCTRL_SWRST(value)               (CMCC_MCTRL_SWRST_Msk & (_UINT32_(value) << CMCC_MCTRL_SWRST_Pos)) /* Assigment of value for SWRST in the CMCC_MCTRL register */
#define CMCC_MCTRL_Msk                        _UINT32_(0x00000001)                                 /* (CMCC_MCTRL) Register Mask  */


/* -------- CMCC_MSR : (CMCC Offset: 0x34) ( R/ 32) Cache Monitor Status Register -------- */
#define CMCC_MSR_RESETVALUE                   _UINT32_(0x00)                                       /*  (CMCC_MSR) Cache Monitor Status Register  Reset Value */

#define CMCC_MSR_EVENT_CNT_Pos                _UINT32_(0)                                          /* (CMCC_MSR) Monitor Event Counter Position */
#define CMCC_MSR_EVENT_CNT_Msk                (_UINT32_(0xFFFFFFFF) << CMCC_MSR_EVENT_CNT_Pos)     /* (CMCC_MSR) Monitor Event Counter Mask */
#define CMCC_MSR_EVENT_CNT(value)             (CMCC_MSR_EVENT_CNT_Msk & (_UINT32_(value) << CMCC_MSR_EVENT_CNT_Pos)) /* Assigment of value for EVENT_CNT in the CMCC_MSR register */
#define CMCC_MSR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (CMCC_MSR) Register Mask  */


/** \brief CMCC register offsets definitions */
#define CMCC_TYPE_REG_OFST             _UINT32_(0x00)      /* (CMCC_TYPE) Cache Type Register Offset */
#define CMCC_CFG_REG_OFST              _UINT32_(0x04)      /* (CMCC_CFG) Cache Configuration Register Offset */
#define CMCC_CTRL_REG_OFST             _UINT32_(0x08)      /* (CMCC_CTRL) Cache Control Register Offset */
#define CMCC_SR_REG_OFST               _UINT32_(0x0C)      /* (CMCC_SR) Cache Status Register Offset */
#define CMCC_LCKWAY_REG_OFST           _UINT32_(0x10)      /* (CMCC_LCKWAY) Cache Lock per Way Register Offset */
#define CMCC_MAINT0_REG_OFST           _UINT32_(0x20)      /* (CMCC_MAINT0) Cache Maintenance Register 0 Offset */
#define CMCC_MAINT1_REG_OFST           _UINT32_(0x24)      /* (CMCC_MAINT1) Cache Maintenance Register 1 Offset */
#define CMCC_MCFG_REG_OFST             _UINT32_(0x28)      /* (CMCC_MCFG) Cache Monitor Configuration Register Offset */
#define CMCC_MEN_REG_OFST              _UINT32_(0x2C)      /* (CMCC_MEN) Cache Monitor Enable Register Offset */
#define CMCC_MCTRL_REG_OFST            _UINT32_(0x30)      /* (CMCC_MCTRL) Cache Monitor Control Register Offset */
#define CMCC_MSR_REG_OFST              _UINT32_(0x34)      /* (CMCC_MSR) Cache Monitor Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CMCC register API structure */
typedef struct
{  /* Cortex M Cache Controller */
  __I   uint32_t                       CMCC_TYPE;          /**< Offset: 0x00 (R/   32) Cache Type Register */
  __IO  uint32_t                       CMCC_CFG;           /**< Offset: 0x04 (R/W  32) Cache Configuration Register */
  __O   uint32_t                       CMCC_CTRL;          /**< Offset: 0x08 ( /W  32) Cache Control Register */
  __I   uint32_t                       CMCC_SR;            /**< Offset: 0x0C (R/   32) Cache Status Register */
  __IO  uint32_t                       CMCC_LCKWAY;        /**< Offset: 0x10 (R/W  32) Cache Lock per Way Register */
  __I   uint8_t                        Reserved1[0x0C];
  __O   uint32_t                       CMCC_MAINT0;        /**< Offset: 0x20 ( /W  32) Cache Maintenance Register 0 */
  __O   uint32_t                       CMCC_MAINT1;        /**< Offset: 0x24 ( /W  32) Cache Maintenance Register 1 */
  __IO  uint32_t                       CMCC_MCFG;          /**< Offset: 0x28 (R/W  32) Cache Monitor Configuration Register */
  __IO  uint32_t                       CMCC_MEN;           /**< Offset: 0x2C (R/W  32) Cache Monitor Enable Register */
  __O   uint32_t                       CMCC_MCTRL;         /**< Offset: 0x30 ( /W  32) Cache Monitor Control Register */
  __I   uint32_t                       CMCC_MSR;           /**< Offset: 0x34 (R/   32) Cache Monitor Status Register */
} cmcc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME54_CMCC_COMPONENT_H_ */

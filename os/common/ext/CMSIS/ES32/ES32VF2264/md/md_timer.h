/**********************************************************************************
 *
 * @file    md_timer.h
 * @brief   Header file of TIMER module driver.
 *
 * @date    28 Dec. 2022
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          28 Dec. 2022    Lisq            the first version
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

#ifndef __MD_TIMER_H__
#define __MD_TIMER_H__

/* Includes ------------------------------------------------------------------ */
#include "md_utils.h"

/* Exported Constants -------------------------------------------------------- */

/* Exported Variables -------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup Micro_Driver
  * @{
  */
/** @defgroup MD_TIMER TIMER
  * @brief TIMER micro driver
  * @{
  */

/* Exported Types ------------------------------------------------------------ */

/** @defgroup MD_TIMER_Public_Types TIMER Public Types
  * @{
  */
/**
  * @brief TIMER counter mode
  */
typedef enum
{
    MD_TIMER_CNT_MODE_UP      = 0U, /**< Counter mode up */
    MD_TIMER_CNT_MODE_DOWN    = 1U, /**< Counter mode down */
    MD_TIMER_CNT_MODE_CENTER1 = 2U, /**< Counter mode center1 */
    MD_TIMER_CNT_MODE_CENTER2 = 3U, /**< Counter mode center2 */
    MD_TIMER_CNT_MODE_CENTER3 = 4U, /**< Counter mode center3 */
} md_timer_cnt_mode_t;

/**
  * @brief TIMER clock division
  */
typedef enum
{
    MD_TIMER_CLOCK_DIV1 = 0U, /**< No prescaler is used */
    MD_TIMER_CLOCK_DIV2 = 1U, /** Clock is divided by 2 */
    MD_TIMER_CLOCK_DIV4 = 2U, /** Clock is divided by 4 */
} md_timer_clock_division_t;

/**
  * @brief TIMER output compare and PWM modes
  */
typedef enum
{
    MD_TIMER_OC_MODE_TIMERING       = 0U, /**< Output compare mode is timering */
    MD_TIMER_OC_MODE_ACTIVE         = 1U, /**< Output compare mode is active */
    MD_TIMER_OC_MODE_INACTIVE       = 2U, /**< Output compare mode is inactive */
    MD_TIMER_OC_MODE_TOGGLE         = 3U, /**< Output compare mode is toggle */
    MD_TIMER_OC_MODE_FORCE_INACTIVE = 4U, /**< Output compare mode is force inactive */
    MD_TIMER_OC_MODE_FORCE_ACTIVE   = 5U, /**< Output compare mode is force active */
    MD_TIMER_OC_MODE_PWM1           = 6U, /**< Output compare mode is pwm1 */
    MD_TIMER_OC_MODE_PWM2           = 7U, /**< Output compare mode is pwm2 */
} md_timer_oc_mode_t;

/**
  * @brief TIMER output compare polarity
  */
typedef enum
{
    MD_TIMER_OC_POLARITY_HIGH = 0U, /**< Output compare polarity is high */
    MD_TIMER_OC_POLARITY_LOW  = 1U, /**< Output compare polarity is low */
} md_timer_oc_polarity_t;

/**
  * @brief TIMER channel
  */
typedef enum
{
    MD_TIMER_CHANNEL_1   = 0U,   /**< Channel 1 */
    MD_TIMER_CHANNEL_2   = 1U,   /**< Channel 2 */
    MD_TIMER_CHANNEL_3   = 2U,   /**< Channel 3 */
    MD_TIMER_CHANNEL_4   = 4U,   /**< Channel 4 */
    MD_TIMER_CHANNEL_ALL = 0xFU, /**< All channel */
} md_timer_channel_t;

/**
  * @brief TIMER complementary output compare polarity
  */
typedef enum
{
    MD_TIMER_OCN_POLARITY_HIGH = 0U,    /**< Complementary output compare polarity is high */
    MD_TIMER_OCN_POLARITY_LOW  = 1U,    /**< Complementary output compare polarity is low */
} md_timer_ocn_polarity_t;

/**
  * @brief TIMER output compare idle state
  */
typedef enum
{
    MD_TIMER_OC_IDLE_RESET = 0U,    /**< Output compare idle state is reset */
    MD_TIMER_OC_IDLE_SET   = 1U,    /**< Output compare idle state is set */
} md_timer_oc_idle_t;

/**
  * @brief TIMER complementary output compare idle state
  */
typedef enum
{
    MD_TIMER_OCN_IDLE_RESET = 0U,   /**< Complementary output compare idle state is reset */
    MD_TIMER_OCN_IDLE_SET   = 1U,   /**< Complementary output compare idle state is set */
} md_timer_ocn_idle_t;

/**
  * @brief TIMER output compare state
  */
typedef enum
{
    MD_TIMER_OCSTATE_DISABLE = 0U,  /**< OCx is not active */
    MD_TIMER_OCSTATE_ENABLE  = 1U,  /**< OCx signal is output on the corresponding output pin */
} md_timer_oc_state_t;

/**
  * @brief  TIMER time base configuration structure definition
  */
typedef struct
{
    uint32_t prescaler;                /**< Specifies the prescaler value used to divide the TIMER clock. */
    md_timer_cnt_mode_t mode;          /**< Specifies the counter mode. */
    uint32_t period;                   /**< Specifies the period value to be loaded into ARR at the next update event. */
    md_timer_clock_division_t clk_div; /**< Specifies the clock division.*/
    uint32_t re_cnt;                   /**< Specifies the repetition counter value. */
} md_timer_base_init_t;

/**
  * @brief  TIMER output compare configuration structure definition
  */
typedef struct
{
    md_timer_oc_state_t ocstate;
    md_timer_oc_state_t ocnstate;
    md_timer_oc_mode_t oc_mode;           /**< Specifies the TIMER mode. */
    uint32_t pulse;                       /**< Specifies the pulse value to be loaded into the Capture Compare Register. */
    md_timer_oc_polarity_t oc_polarity;   /**< Specifies the output polarity. */
    md_timer_ocn_polarity_t ocn_polarity; /**< Specifies the complementary output polarity. */
    type_func_t oc_fast_en;               /**< Specifies the Fast mode state. */
    md_timer_oc_idle_t oc_idle;           /**< Specifies the TIMER Output Compare pin state during Idle state. */
    md_timer_ocn_idle_t ocn_idle;         /**< Specifies the TIMER Output Compare pin state during Idle state. */
} md_timer_oc_init_t;

/**
  * @brief TIMER encoder mode
  */
typedef enum
{
    MD_TIMER_ENC_MODE_TI1  = 1U, /**< encoder mode 1 */
    MD_TIMER_ENC_MODE_TI2  = 2U, /**< encoder mode 2 */
    MD_TIMER_ENC_MODE_TI12 = 3U, /**< encoder mode 3 */
} md_timer_encoder_mode_t;

/**
  * @brief TIMER input capture polarity
  */
typedef enum
{
    MD_TIMER_IC_POLARITY_RISE = 0U, /**< Input capture polarity rising */
    MD_TIMER_IC_POLARITY_FALL = 1U, /**< Input capture polarity falling */
    MD_TIMER_IC_POLARITY_BOTH = 5U, /**< Input capture polarity rising and falling */
} md_timer_ic_polarity_t;

/**
  *@brief TIMER input capture selection
  */
typedef enum
{
    MD_TIMER_IC_SEL_DIRECT   = 1U, /**< IC1 -- TI1 */
    MD_TIMER_IC_SEL_INDIRECT = 2U, /**< IC1 -- TI2 */
    MD_TIMER_IC_SEL_TRC      = 3U, /**< IC1 -- TRC */
} md_timer_ic_select_t;

/**
  * @brief TIMER input capture prescaler
  */
typedef enum
{
    MD_TIMER_IC_PSC_DIV1 = 0U, /**< Capture performed once every 1 events */
    MD_TIMER_IC_PSC_DIV2 = 1U, /**< Capture performed once every 2 events */
    MD_TIMER_IC_PSC_DIV4 = 2U, /**< Capture performed once every 4 events */
    MD_TIMER_IC_PSC_DIV8 = 3U, /**< Capture performed once every 4 events */
} md_timer_ic_prescaler_t;

/**
  * @brief TIMER encoder configuration structure definition
  */
typedef struct
{
    md_timer_encoder_mode_t mode;        /**< Specifies the encoder mode */
    md_timer_ic_polarity_t ic1_polarity; /**< Specifies the active edge of the input signal */
    md_timer_ic_select_t ic1_sel;        /**< Specifies the input */
    md_timer_ic_prescaler_t ic1_psc;     /**< Specifies the Input Capture Prescaler */
    uint32_t ic1_filter;                 /**< Specifies the input capture filter */
    md_timer_ic_polarity_t ic2_polarity; /**< Specifies the active edge of the input signal */
    md_timer_ic_select_t ic2_sel;        /**< Specifies the input */
    md_timer_ic_prescaler_t ic2_psc;     /**< Specifies the Input Capture Prescaler */
    uint32_t ic2_filter;                 /**< Specifies the input capture filter */
} md_timer_encoder_init_t;

/**
  * @brief  TIMER input capture configuration structure definition
  */
typedef struct
{
    md_timer_ic_polarity_t polarity; /**< Specifies the active edge of the input signal */
    md_timer_ic_select_t sel;        /**< Specifies the input */
    md_timer_ic_prescaler_t psc;     /**< Specifies the Input Capture Prescaler */
    uint32_t filter;                 /**< Specifies the input capture filter */
} md_timer_ic_init_t;

/**
  * @brief  TIMER hall sensor configuretion structure definition
  */
typedef struct
{
    md_timer_ic_polarity_t polarity; /**< Specifies the active edge of the input signal */
    md_timer_ic_prescaler_t psc;     /**< Specifies the Input Capture Prescaler */
    uint32_t filter;                 /**< Specifies the input capture filter [0x0, 0xF] */
    uint32_t delay;                  /**< Specifies the pulse value to be loaded into the register [0x0, 0xFFFF] */
} md_timer_hall_sensor_init_t;

/**
  * @brief TIMER lock level
  */
typedef enum
{
    MD_TIMER_LOCK_LEVEL_OFF = 0U, /**< Lock off */
    MD_TIMER_LOCK_LEVEL_1   = 1U, /**< Lock level 1 */
    MD_TIMER_LOCK_LEVEL_2   = 2U, /**< Lock level 2 */
    MD_TIMER_LOCK_LEVEL_3   = 3U, /**< Lock level 3 */
} md_timer_lock_level_t;

/**
  * @brief TIMER break polarity
  */
typedef enum
{
    MD_TIMER_BREAK_POLARITY_LOW  = 0U, /**< LOW */
    MD_TIMER_BREAK_POLARITY_HIGH = 1U, /**< HIGH */
} md_timer_break_polarity_t;

/**
  * @brief  TIMER break and dead time configuretion structure definition
  */
typedef struct
{
    type_func_t off_run;                /**< Enalbe/Disable off state in run mode */
    type_func_t off_idle;               /**< Enalbe/Disable off state in idle mode */
    md_timer_lock_level_t lock_level;   /**< Lock level */
    uint32_t dead_time;                 /**< Dead time, [0x0, 0xFF] */
    type_func_t break_state;            /**< Break state */
    md_timer_break_polarity_t polarity; /**< Break input polarity */
    type_func_t auto_out;               /**< Enalbe/Disable automatic output */
} md_timer_break_dead_time_t;

/**
  * @}
  */

/** @defgroup MD_TIMER_Private_Macros TIMER Private Macros
  * @{
  */

/* Exported Macros ----------------------------------------------------------- */

#if defined(__ES32VF2264_H__)

#define MD_IS_TIMER_CC2_INSTANCE(x)    (((x) == AD16C4T) || \
                                     ((x) == GP16C4T0) || \
                                     ((x) == GP16C4T1) || \
                                     ((x) == GP16C4T2))
#define MD_IS_TIMER_REPETITION_COUNTER_INSTANCE(x) (((x) == AD16C4T) )
#define MD_IS_TIMER_CLOCK_DIVISION_INSTANCE(x) (MD_IS_TIMER_CC2_INSTANCE(x))

#endif /* __ES32VF2264_H__ */

/**
  * @}
  */

/* Exported Functions -------------------------------------------------------- */

/** @defgroup MD_TIMER_Public_Functions TIMER Public Functions
  * @{
  */
/** @defgroup MD_TIMER_Public_Functions_Group2 CON1
  * @{
  */
/**
  * @brief  TIMER Counter enable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_counter_cnten(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->CON1, TIMER_CON1_CNTEN_MSK);
}

/**
  * @brief  TIMER Counter disable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_counter_cnten(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->CON1, TIMER_CON1_CNTEN_MSK);
}

/**
  * @brief  TIMER Check if counter enable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_timer_is_counter_enable(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON1, TIMER_CON1_CNTEN_MSK, TIMER_CON1_CNTEN_POS);
}

/**
  * @brief  TIMER Update enable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_update_disue(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->CON1, TIMER_CON1_DISUE_MSK);
}

/**
  * @brief  TIMER Update disable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_update_disue(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->CON1, TIMER_CON1_DISUE_MSK);
}

/**
  * @brief  TIMER Set update request source
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Counter overflow/underflow Setting the UG bit
           Update generation through the slave mode controller
  *         - 0x1: Only counter overflow/underflow generates an update
           interrupt or DMA request if enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_update_source(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON1, TIMER_CON1_UERSEL_MSK, sel << TIMER_CON1_UERSEL_POS);
}

/**
  * @brief  TIMER Update request source
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Counter overflow/underflow
                   Setting the UG bit
           Update generation through the slave mode controller
  *         - 0x1: Only counter overflow/underflow generates an update
           interrupt or DMA request if enabled
  */
__STATIC_INLINE uint32_t md_timer_get_update_source(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON1, TIMER_CON1_UERSEL_MSK, TIMER_CON1_UERSEL_POS);
}

/**
  * @brief  TIMER Enable one pulse mode
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_onepulse_spmen(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->CON1, TIMER_CON1_SPMEN_MSK);
}

/**
  * @brief  TIMER Disable one pulse mode
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_onepulse_spmen(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->CON1, TIMER_CON1_SPMEN_MSK);
}

/**
  * @brief  TIMER Check if one pulse mode enable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_timer_is_onepulse_enable(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON1, TIMER_CON1_SPMEN_MSK, TIMER_CON1_SPMEN_POS);
}

/**
  * @brief  TIMER Set counter direction
  * @param  TIMERx TIMER Instance
  * @param  dir: The value of following:
  *         - 0x0: Counter used as upcounter
  *         - 0x1: Counter used as downcounter
  * @retval None
  */
__STATIC_INLINE void md_timer_set_counter_direction_dirsel(TIMER_TypeDef *TIMERx, uint32_t dir)
{
    MODIFY_REG(TIMERx->CON1, TIMER_CON1_DIRSEL_MSK, dir << TIMER_CON1_DIRSEL_POS);
}

/**
  * @brief  TIMER Get counter direction
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Counter used as upcounter
  *         - 0x1: Counter used as downcounter
  */
__STATIC_INLINE uint32_t md_timer_get_counter_direction_dirsel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON1, TIMER_CON1_DIRSEL_MSK, TIMER_CON1_DIRSEL_POS);
}

/**
  * @brief  TIMER Set counter aligned mode
  * @param  TIMERx TIMER Instance
  * @param  mode: The value of following:
  *         - 0x0: Edge-aligned mode
  *         - 0x1: Center-aligned mode 1
  *         - 0x2: Center-aligned mode 2
  *         - 0x3: Center-aligned mode 3
  * @retval None
  */
__STATIC_INLINE void md_timer_set_counter_aligned_mode_cmsel(TIMER_TypeDef *TIMERx, uint32_t mode)
{
    MODIFY_REG(TIMERx->CON1, TIMER_CON1_CMSEL_MSK, mode << TIMER_CON1_CMSEL_POSS);
}

/**
  * @brief  TIMER Get counter aligned mode
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Edge-aligned mode
  *         - 0x1: Center-aligned mode 1
  *         - 0x2: Center-aligned mode 2
  *         - 0x3: Center-aligned mode 3
  */
__STATIC_INLINE uint32_t md_timer_get_counter_aligned_mode_cmsel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON1, TIMER_CON1_CMSEL_MSK, TIMER_CON1_CMSEL_POSS);
}

/**
  * @brief  TIMER Auto-reload preload enable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_autoreload_preload_arpen(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->CON1, TIMER_CON1_ARPEN_MSK);
}

/**
  * @brief  TIMER Auto-reload preload disable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_autoreload_preload_arpen(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->CON1, TIMER_CON1_ARPEN_MSK);
}

/**
  * @brief  TIMER Check if auto-reload preload enable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE uint32_t md_timer_is_autoreload_preload_enable(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON1, TIMER_CON1_ARPEN_MSK, TIMER_CON1_ARPEN_POS);
}

/**
  * @brief  TIMER Set clock division
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: tDTS=tCK_INT
  *         - 0x1: tDTS=2*tCK_INT
  *         - 0x2: tDTS=4*tCK_INT
  *         - 0x3: Reserved, do not program this value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_df_clock_dfcksel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON1, TIMER_CON1_DFCKSEL_MSK, sel << TIMER_CON1_DFCKSEL_POSS);
}

/**
  * @brief  TIMER Get clock division
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: tDTS=tCK_INT
  *         - 0x1: tDTS=2*tCK_INT
  *         - 0x2: tDTS=4*tCK_INT
  *         - 0x3: Reserved, do not program this value
  */
__STATIC_INLINE uint32_t md_timer_get_df_clock_dfcksel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON1, TIMER_CON1_DFCKSEL_MSK, TIMER_CON1_DFCKSEL_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group3 CON2
  * @{
  */
/**
  * @brief  TIMER Set capture/compare preloaded control
  * @param  TIMERx TIMER Instance
  * @param  cfg The value of following:
  *         - 0x0: CCnEN, CCnNEn and OCnOCM bits are not preloaded
  *         - 0x1: CCnEN, CCnNEn and OCnOCM bits are preloaded
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc_preload_ccpcen(TIMER_TypeDef *TIMERx, uint32_t cfg)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_CCPCEN_MSK, cfg << TIMER_CON2_CCPCEN_POS);
}

/**
  * @brief  TIMER Get capture/compare preloaded control
  * @param  TIMERx TIMER Instance
  * @retval cfg The value of following:
  *         - 0x0: CCnEN, CCnNEn and OCnOCM bits are not preloaded
  *         - 0x1: CCnEN, CCnNEn and OCnOCM bits are preloaded
  */
__STATIC_INLINE uint32_t md_timer_get_cc_preload_ccpcen(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_CCPCEN_MSK, TIMER_CON2_CCPCEN_POS);
}

/**
  * @brief  TIMER Set  capture/compare control update selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: if CCPCEN = 1,updated by setting the SGCOMG bit only
  *         - 0x1: if CCPCEN = 1,updated by setting the COMG bit or when an rising edge occurs on TI
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc_update_select_ccusel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_CCPCEN_MSK, sel << TIMER_CON2_CCPCEN_POS);
}

/**
  * @brief  TIMER Get capture/compare control update selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: if CCPCEN = 1,updated by setting the SGCOMG bit only
  *         - 0x1: if CCPCEN = 1,updated by setting the COMG bit or when an rising edge occurs on TI
  */
__STATIC_INLINE uint32_t md_timer_get_cc_update_select_ccusel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_CCPCEN_MSK, TIMER_CON2_CCPCEN_POS);
}

/**
  * @brief  TIMER Set capture/compare DMA selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CCn DMA request sent when CCx event occurs
  *         - 0x1: CCn DMA requests sent when update event occurs
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc_dma_select_ccdmasel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_CCDMASEL_MSK, sel << TIMER_CON2_CCDMASEL_POS);
}

/**
  * @brief  TIMER Get capture/compare DMA selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CCn DMA request sent when CCx event occurs
  *         - 0x1: CCn DMA requests sent when update event occurs
  */
__STATIC_INLINE uint32_t md_timer_get_cc_dma_select_ccdmasel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_CCDMASEL_MSK, TIMER_CON2_CCDMASEL_POS);
}

/**
  * @brief  TIMER I1 function selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: The TIMERn_CH1 pin is connected to I1 input
  *         - 0x1: The TIMERn_CH1, CH2 and CH3 pins are connected to the I1 input (XOR combination)
  * @retval None
  */
__STATIC_INLINE void md_timer_set_i1_func_select_i1fsel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_I1FSEL_MSK, sel << TIMER_CON2_I1FSEL_POS);
}

/**
  * @brief  TIMER I1 function selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: The TIMERn_CH1 pin is connected to I1 input
  *         - 0x1: The TIMERn_CH1, CH2 and CH3 pins are connected to the I1 input (XOR combination)
  */
__STATIC_INLINE uint32_t md_timer_get_i1_func_select_i1fsel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_I1FSEL_MSK, TIMER_CON2_I1FSEL_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH1O output)
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH1O=0 (after a dead-time if CH1ON is implemented) when GOEN=0
  *         - 0x1: CH1O=1 (after a dead-time if CH1ON is implemented) when GOEN=0
  * @retval None
  */
__STATIC_INLINE void md_timer_set_ch1o_idle_select_oiss1(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_OISS1_MSK, sel << TIMER_CON2_OISS1_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH1O output)
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH1O=0 (after a dead-time if CH1ON is implemented) when GOEN=0
  *         - 0x1: CH1O=1 (after a dead-time if CH1ON is implemented) when GOEN=0
  */
__STATIC_INLINE uint32_t md_timer_get_ch1o_idle_select_oiss1(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_OISS1_MSK, TIMER_CON2_OISS1_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH1ON output)
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH1ON=0 after a dead-time when GOEN=0
  *         - 0x1: CH1ON=1 after a dead-time when GOEN=0
  * @retval None
  */
__STATIC_INLINE void md_timer_set_ch1on_idle_select_oiss1n(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_OISS1N_MSK, sel << TIMER_CON2_OISS1N_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH1ON output)
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH1ON=0 after a dead-time when GOEN=0
  *         - 0x1: CH1ON=1 after a dead-time when GOEN=0
  */
__STATIC_INLINE uint32_t md_timer_get_ch1on_idle_select_oiss1n(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_OISS1N_MSK, TIMER_CON2_OISS1N_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH2O output)
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH2O=0 (after a dead-time if CH2ON is implemented) when GOEN=0
  *         - 0x1: CH2O=1 (after a dead-time if CH2ON is implemented) when GOEN=0
  * @retval None
  */
__STATIC_INLINE void md_timer_set_ch2o_idle_select_oiss2(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_OISS2_MSK, sel << TIMER_CON2_OISS2_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH2O output)
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH2O=0 (after a dead-time if CH2ON is implemented) when GOEN=0
  *         - 0x1: CH2O=1 (after a dead-time if CH2ON is implemented) when GOEN=0
  */
__STATIC_INLINE uint32_t md_timer_get_ch2o_idle_select_oiss2(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_OISS2_MSK, TIMER_CON2_OISS2_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH2ON output)
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH2ON=0 after a dead-time when GOEN=0
  *         - 0x1: CH2ON=1 after a dead-time when GOEN=0
  * @retval None
  */
__STATIC_INLINE void md_timer_set_ch2on_idle_select_oiss2n(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_OISS2N_MSK, sel << TIMER_CON2_OISS2N_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH2ON output)
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH2ON=0 after a dead-time when GOEN=0
  *         - 0x1: CH2ON=1 after a dead-time when GOEN=0
  */
__STATIC_INLINE uint32_t md_timer_get_ch2on_idle_select_oiss2n(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_OISS2N_MSK, TIMER_CON2_OISS2N_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH3O output)
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH3O=0 (after a dead-time if CH3ON is implemented) when GOEN=0
  *         - 0x1: CH3O=1 (after a dead-time if CH3ON is implemented) when GOEN=0
  * @retval None
  */
__STATIC_INLINE void md_timer_set_ch3o_idle_select_oiss3(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_OISS3_MSK, sel << TIMER_CON2_OISS3_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH3O output)
  * @param  TIMERx TIMER Instance
  * @retval  The value of following:
  *         - 0x0: CH3O=0 (after a dead-time if CH3ON is implemented) when GOEN=0
  *         - 0x1: CH3O=1 (after a dead-time if CH3ON is implemented) when GOEN=0
  */
__STATIC_INLINE uint32_t md_timer_get_ch3o_idle_select_oiss3(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_OISS3_MSK, TIMER_CON2_OISS3_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH3ON output)
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH3ON=0 after a dead-time when GOEN=0
  *         - 0x1: CH3ON=1 after a dead-time when GOEN=0
  * @retval None
  */
__STATIC_INLINE void md_timer_set_ch3on_idle_select_oiss3n(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_OISS3N_MSK, sel << TIMER_CON2_OISS3N_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH3ON output)
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH3ON=0 after a dead-time when GOEN=0
  *         - 0x1: CH3ON=1 after a dead-time when GOEN=0
  */
__STATIC_INLINE uint32_t md_timer_get_ch3on_idle_select_oiss3n(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_OISS3N_MSK, TIMER_CON2_OISS3N_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH4O output)
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH4O=0 when GOEN=0
  *         - 0x1: CH4O=1 when GOEN=0
  * @retval None
  */
__STATIC_INLINE void md_timer_set_ch4o_idle_select_oiss4(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CON2, TIMER_CON2_OISS4_MSK, sel << TIMER_CON2_OISS4_POS);
}

/**
  * @brief  TIMER Output Idle state 1 (CH4O output)
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH4O=0 when GOEN=0
  *         - 0x1: CH4O=1 when GOEN=0
  */
__STATIC_INLINE uint32_t md_timer_get_ch4o_idle_select_oiss4(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CON2, TIMER_CON2_OISS4_MSK, TIMER_CON2_OISS4_POS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group4 SMCON
  * @{
  */
/**
  * @brief  TIMER Set slave mode selection
  * @param  TIMERx TIMER Instance
  * @param  sel: The value of following:
  *         - 0x0: Slave mode disabled
  *         - 0x1: Encoder mode 1
  *         - 0x2: Encoder mode 2
  *         - 0x3: Encoder mode 3
  *         - 0x4: Reset Mode
  *         - 0x5: Gated Mode
  *         - 0x6: Trigger Mode
  *         - 0x6: External Clock Mode 1
  * @retval None
  */
__STATIC_INLINE void md_timer_set_slave_mode_smods(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SMCON, TIMER_SMCON_SMODS_MSK, sel << TIMER_SMCON_SMODS_POSS);
}

/**
  * @brief  TIMER Set slave mode selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Slave mode disabled
  *         - 0x1: Encoder mode 1
  *         - 0x2: Encoder mode 2
  *         - 0x3: Encoder mode 3
  *         - 0x4: Reset Mode
  *         - 0x5: Gated Mode
  *         - 0x6: Trigger Mode
  *         - 0x6: External Clock Mode 1
  */
__STATIC_INLINE uint32_t md_timer_get_slave_mode_smods(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->SMCON, TIMER_SMCON_SMODS_MSK, TIMER_SMCON_SMODS_POSS);
}

/**
  * @brief  TIMER output channel clear OCCISS
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_output_channel_clear_occiss(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->SMCON, TIMER_SMCON_OCCS_MSK);
}

/**
  * @brief  TIMER output channel clear ETFP
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_output_channel_clear_etfp(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->SMCON, TIMER_SMCON_OCCS_MSK);
}

/**
  * @brief  TIMER  Check output channel clear is occiss or etfp
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: occiss
  *         - 0x1: etfp
  */
__STATIC_INLINE uint32_t md_timer_output_channel_clear_is_occiss_or_etfp(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->SMCON, TIMER_SMCON_OCCS_MSK, TIMER_SMCON_OCCS_POS);
}

/**
  * @brief  TIMER Trigger selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Internal Trigger 0
  *         - 0x1: Internal Trigger 1
  *         - 0x2: Internal Trigger 2
  *         - 0x3: Internal Trigger 3
  *         - 0x4: I1 Edge Detector
  *         - 0x5: Filtered Timer Input 1
  *         - 0x6: Filtered Timer Input 2
  *         - 0x7: External Trigger input
  * @retval None
  */
__STATIC_INLINE void md_timer_set_slave_trigger_tssel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SMCON, TIMER_SMCON_TSSEL_MSK, sel << TIMER_SMCON_TSSEL_POSS);
}

/**
  * @brief  TIMER Trigger selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Internal Trigger 0
  *         - 0x1: Internal Trigger 1
  *         - 0x2: Internal Trigger 2
  *         - 0x3: Internal Trigger 3
  *         - 0x4: I1 Edge Detector
  *         - 0x5: Filtered Timer Input 1
  *         - 0x6: Filtered Timer Input 2
  *         - 0x7: External Trigger input
  */
__STATIC_INLINE uint32_t md_timer_get_slave_trigger_tssel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->SMCON, TIMER_SMCON_TSSEL_MSK, TIMER_SMCON_TSSEL_POSS);
}

/**
  * @brief  TIMER  Set master/slave mode
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: The effect of an event on the trigger input is delayed to allow a perfect
  *            synchronization between the current timer and its slaves.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_master_slave_mode_mscfg(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SMCON, TIMER_SMCON_MSCFG_MSK, sel << TIMER_SMCON_MSCFG_POS);
}

/**
  * @brief  TIMER  Get master/slave mode
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: No action
  *         - 0x1: The effect of an event on the trigger input is delayed to allow a perfect
  *                synchronization between the current timer and its slaves.
  */
__STATIC_INLINE uint32_t md_timer_get_master_slave_mode_mscfg(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->SMCON, TIMER_SMCON_MSCFG_MSK, TIMER_SMCON_MSCFG_POS);
}

/**
  * @brief  TIMER Set slave mode selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0:No filter, sampling is done at fDTS
  *     - 0x1:fSAMPLING = fINT_CLK, N = 2
  *     - 0x2:fSAMPLING = fINT_CLK, N = 4
  *     - 0x3:fSAMPLING = fINT_CLK, N = 8
  *     - 0x4:fSAMPLING = fDTS / 2, N = 6
  *     - 0x5:fSAMPLING = fDTS / 2, N = 8
  *     - 0x6:fSAMPLING = fDTS / 4, N = 6
  *     - 0x7:fSAMPLING = fDTS / 4, N = 8
  *     - 0x8:fSAMPLING = fDTS / 8, N = 6
  *     - 0x9:fSAMPLING = fDTS / 8, N = 8
  *     - 0x10:fSAMPLING = fDTS / 16, N = 5
  *     - 0x11:fSAMPLING = fDTS / 16, N = 6
  *     - 0x12:fSAMPLING = fDTS / 16, N = 8
  *     - 0x13:fSAMPLING = fDTS / 32, N = 5
  *     - 0x14:fSAMPLING = fDTS / 32, N = 6
  *     - 0x15:fSAMPLING = fDTS / 32, N = 8
  * @retval None
  */
__STATIC_INLINE void md_timer_set_external_trigger_filter_etflt(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SMCON, TIMER_SMCON_ETFLT_MSK, sel << TIMER_SMCON_ETFLT_POSS);
}

/**
  * @brief  TIMER Trigger selection
  * @param  TIMERx TIMER Instance
  * @retval sel The value of following:
  *         - 0x0:No filter, sampling is done at fDTS
  *         - 0x1:fSAMPLING = fINT_CLK, N = 2
  *         - 0x2:fSAMPLING = fINT_CLK, N = 4
  *         - 0x3:fSAMPLING = fINT_CLK, N = 8
  *         - 0x4:fSAMPLING = fDTS / 2, N = 6
  *         - 0x5:fSAMPLING = fDTS / 2, N = 8
  *         - 0x6:fSAMPLING = fDTS / 4, N = 6
  *         - 0x7:fSAMPLING = fDTS / 4, N = 8
  *         - 0x8:fSAMPLING = fDTS / 8, N = 6
  *         - 0x9:fSAMPLING = fDTS / 8, N = 8
  *         - 0x10:fSAMPLING = fDTS / 16, N = 5
  *         - 0x11:fSAMPLING = fDTS / 16, N = 6
  *         - 0x12:fSAMPLING = fDTS / 16, N = 8
  *         - 0x13:fSAMPLING = fDTS / 32, N = 5
  *         - 0x14:fSAMPLING = fDTS / 32, N = 6
  *         - 0x15:fSAMPLING = fDTS / 32, N = 8
  */
__STATIC_INLINE uint32_t md_timer_get_external_trigger_filter_etflt(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->SMCON, TIMER_SMCON_MSCFG_MSK, TIMER_SMCON_MSCFG_POS);
}

/**
  * @brief  TIMER Set external trigger prescaler
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Prescaler OFF
  *         - 0x1: ETRP frequency divided by 2
  *         - 0x2: ETRP frequency divided by 4
  *         - 0x3: ETRP frequency divided by 8
  * @retval None
  */
__STATIC_INLINE void md_timer_set_external_trigger_prescaler_etpsel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SMCON, TIMER_SMCON_ETPSEL_MSK, sel << TIMER_SMCON_ETPSEL_POSS);
}

/**
  * @brief  TIMER Get external trigger prescaler
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Prescaler OFF
  *         - 0x1: ETRP frequency divided by 2
  *         - 0x2: ETRP frequency divided by 4
  *         - 0x3: ETRP frequency divided by 8
  */
__STATIC_INLINE uint32_t md_timer_get_external_trigger_prescaler_etpsel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->SMCON, TIMER_SMCON_ETPSEL_MSK, TIMER_SMCON_ETPSEL_POSS);
}

/**
  * @brief  TIMER  Enable external clock mode 2
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_external_clk2mode_ecm2en(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->SMCON, TIMER_SMCON_ECM2EN_MSK);
}

/**
  * @brief  TIMER  Disable external clock mode 2
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_external_clk2mode_ecm2en(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->SMCON, TIMER_SMCON_ECM2EN_MSK);
}

/**
  * @brief  TIMER  Check if external clock mode 2 enabled
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: External clock mode 2 disabled
  *         - 0x1: External clock mode 2 enabled
  */
__STATIC_INLINE uint32_t md_timer_is_external_clk2mode_enable(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->SMCON, TIMER_SMCON_ECM2EN_MSK, TIMER_SMCON_ECM2EN_POS);
}

/**
  * @brief  TIMER Set external trigger polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: ETR is non-inverted, active at high level or rising edge.
  *         - 0x1: ETR is inverted, active at low level or falling edge.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_external_trigger_polarity_etpol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SMCON, TIMER_SMCON_ETPOL_MSK, sel << TIMER_SMCON_ETPOL_POS);
}

/**
  * @brief  TIMER Get external trigger polarity
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: ETR is non-inverted, active at high level or rising edge.
  *         - 0x1: ETR is inverted, active at low level or falling edge.
  */
__STATIC_INLINE uint32_t md_timer_get_external_trigger_polarity_etpol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->SMCON, TIMER_SMCON_ETPOL_MSK, TIMER_SMCON_ETPOL_POS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group5 IER
  * @{
  */
/**
  * @brief  TIMER Enable update interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_uit_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IER, TIMER_IER_UIT_MSK);
}

/**
  * @brief  TIMER Enable cc1 interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_cc1it_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IER, TIMER_IER_CC1IT_MSK);
}

/**
  * @brief  TIMER Enable cc2 interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_cc2it_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IER, TIMER_IER_CC2IT_MSK);
}

/**
  * @brief  TIMER Enable cc3 interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_cc3it_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IER, TIMER_IER_CC3IT_MSK);
}

/**
  * @brief  TIMER Enable cc4 interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_cc4it_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IER, TIMER_IER_CC4IT_MSK);
}

/**
  * @brief  TIMER Enable COM interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_comit_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IER, TIMER_IER_COMIT_MSK);
}

/**
  * @brief  TIMER Enable trigger interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_trgit_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IER, TIMER_IER_TRGIT_MSK);
}

/**
  * @brief  TIMER Enable break interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_brkit_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IER, TIMER_IER_BRKIT_MSK);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group6 IDR
  * @{
  */
/**
  * @brief  TIMER Disable update interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_ui_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IDR, TIMER_IDR_UI_MSK);
}

/**
  * @brief  TIMER Disable cc1i interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_cc1i_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IDR, TIMER_IDR_CC1I_MSK);
}

/**
  * @brief  TIMER Disable cc2i interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_cc2i_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IDR, TIMER_IDR_CC3I_MSK);
}

/**
  * @brief  TIMER Disable cc3i interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_cc3i_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IDR, TIMER_IDR_CC3I_MSK);
}

/**
  * @brief  TIMER Disable cc4 interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_cc4i_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IDR, TIMER_IDR_CC4I_MSK);
}

/**
  * @brief  TIMER Disable COM interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_comi_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IDR, TIMER_IDR_COMI_MSK);
}

/**
  * @brief  TIMER Disable trigger interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_trgi_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IDR, TIMER_IDR_TRGI_MSK);
}

/**
  * @brief  TIMER Disable break interrupt
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_brki_interrupt(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->IDR, TIMER_IDR_BRKI_MSK);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group7 IVS
  * @{
  */
/**
  * @brief  TIMER Get update event interrupt state
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_get_update_interrupt_state_uei(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IVS, TIMER_IVS_UEI_MSK, TIMER_IVS_UEI_POS);
}

/**
  * @brief  TIMER Get capture/compare 1 interrupt state
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_interrupt_state_cc1i(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IVS, TIMER_IVS_CC1I_MSK, TIMER_IVS_CC1I_POS);
}

/**
  * @brief  TIMER Get capture/compare 2 interrupt state
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_interrupt_state_cc2i(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IVS, TIMER_IVS_CC2I_MSK, TIMER_IVS_CC2I_POS);
}

/**
  * @brief  TIMER Get capture/compare 3 interrupt state
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_interrupt_state_cc3i(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IVS, TIMER_IVS_CC3I_MSK, TIMER_IVS_CC3I_POS);
}

/**
  * @brief  TIMER Get capture/compare 4 interrupt state
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_get_cc4_interrupt_state_cc4i(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IVS, TIMER_IVS_CC4I_MSK, TIMER_IVS_CC4I_POS);
}

/**
  * @brief  TIMER Get COM interrupt state
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_get_com_interrupt_state_comi(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IVS, TIMER_IVS_COMI_MSK, TIMER_IVS_COMI_POS);
}

/**
  * @brief  TIMER Get trig interrupt state
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_get_trigger_interrupt_state_trgi(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IVS, TIMER_IVS_TRGI_MSK, TIMER_IVS_TRGI_POS);
}

/**
  * @brief  TIMER Get break interrupt state
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_get_break_interrupt_state_bki(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IVS, TIMER_IVS_BKI_MSK, TIMER_IVS_BKI_POS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group8 RIF
  * @{
  */
/**
  * @brief  TIMER Get update interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_update_interrupt_flag_uevtif(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_UEVTIF_MSK, TIMER_RIF_UEVTIF_POS);
}

/**
  * @brief  TIMER Get capture/compare 1 interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_interrupt_flag_ch1if(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_CH1IF_MSK, TIMER_RIF_CH1IF_POS);
}

/**
  * @brief  TIMER Get capture/compare 2 interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_interrupt_flag_ch2if(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_CH2IF_MSK, TIMER_RIF_CH2IF_POS);
}

/**
  * @brief  TIMER Get capture/compare 3 interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_interrupt_flag_ch3if(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_CH3IF_MSK, TIMER_RIF_CH3IF_POS);
}

/**
  * @brief  TIMER Get capture/compare 4 interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc4_interrupt_flag_ch4if(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_CH4IF_MSK, TIMER_RIF_CH4IF_POS);
}

/**
  * @brief  TIMER Get com interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_com_interrupt_flag_comif(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_COMIF_MSK, TIMER_RIF_COMIF_POS);
}

/**
  * @brief  TIMER Get trigger interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_trigger_interrupt_flag_trgif(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_TRGIF_MSK, TIMER_RIF_TRGIF_POS);
}

/**
  * @brief  TIMER Get break interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_break_interrupt_flag_brkif(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_BRKIF_MSK, TIMER_RIF_BRKIF_POS);
}

/**
  * @brief  TIMER Get capture/compare 1 overflow interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_overflow_interrupt_flag_ch1ovif(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_CH1OVIF_MSK, TIMER_RIF_CH1OVIF_POS);
}

/**
  * @brief  TIMER Get capture/compare 2 overflow interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_overflow_interrupt_flag_ch2ovif(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_CH2OVIF_MSK, TIMER_RIF_CH2OVIF_POS);
}

/**
  * @brief  TIMER Get capture/compare 3 overflow interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_overflow_interrupt_flag_ch3ovif(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_CH3OVIF_MSK, TIMER_RIF_CH3OVIF_POS);
}

/**
  * @brief  TIMER Get capture/compare 4 overflow interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc4_overflow_interrupt_flag_ch4ovif(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->RIF, TIMER_RIF_CH4OVIF_MSK, TIMER_RIF_CH4OVIF_POS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group9 IFM
  * @{
  */
/**
  * @brief  TIMER Get update valid interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_update_valid_interrupt_flag_uei(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IFM, TIMER_IFM_UEI_MSK, TIMER_IFM_UEI_POS);
}

/**
  * @brief  TIMER Get capture/compare 1 valid interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_valid_interrupt_flag_ch1cci(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IFM, TIMER_IFM_CH1CCI_MSK, TIMER_IFM_CH1CCI_POS);
}

/**
  * @brief  TIMER Get capture/compare 2 valid interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_valid_interrupt_flag_ch2cci(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IFM, TIMER_IFM_CH2CCI_MSK, TIMER_IFM_CH2CCI_POS);
}

/**
  * @brief  TIMER Get capture/compare 3 valid interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_valid_interrupt_flag_ch3cci(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IFM, TIMER_IFM_CH3CCI_MSK, TIMER_IFM_CH3CCI_POS);
}

/**
  * @brief  TIMER Get capture/compare 4 valid interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_cc4_valid_interrupt_flag_ch4cci(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IFM, TIMER_IFM_CH4CCI_MSK, TIMER_IFM_CH4CCI_POS);
}

/**
  * @brief  TIMER Get com valid interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_com_valid_interrupt_flag_comi(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IFM, TIMER_IFM_COMI_MSK, TIMER_IFM_COMI_POS);
}

/**
  * @brief  TIMER Get trigger valid interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_trigger_valid_interrupt_flag_trgi(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IFM, TIMER_IFM_TRGI_MSK, TIMER_IFM_TRGI_POS);
}

/**
  * @brief  TIMER Get break valid interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: RESET
  *         - 1: SET
  */
__STATIC_INLINE uint32_t md_timer_get_break_valid_interrupt_flag_brkim(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->IFM, TIMER_IFM_BRKIM_MSK, TIMER_IFM_BRKIM_POS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group10 ICR
  * @{
  */
/**
  * @brief  TIMER Clear update interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_clear_update_interrupt_flag_ueic(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->ICR, TIMER_ICR_UEIC_MSK);
}

/**
  * @brief  TIMER Clear capture/compare 1 interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_clear_cc1_interrupt_flag_ch1ccic(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->ICR, TIMER_ICR_CH1CCIC_MSK);
}

/**
  * @brief  TIMER Clear capture/compare 2 interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_clear_cc2_interrupt_flag_ch2ccic(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->ICR, TIMER_ICR_CH2CCIC_MSK);
}

/**
  * @brief  TIMER Clear capture/compare 3 interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_clear_cc3_interrupt_flag_ch3ccic(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->ICR, TIMER_ICR_CH3CCIC_MSK);
}

/**
  * @brief  TIMER Clear capture/compare 4 interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_clear_cc4_interrupt_flag_ch4ccic(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->ICR, TIMER_ICR_CH4CCIC_MSK);
}

/**
  * @brief  TIMER Clear com interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_clear_com_interrupt_flag_comic(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->ICR, TIMER_ICR_COMIC_MSK);
}

/**
  * @brief  TIMER Clear trigger interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_clear_trigger_interrupt_flag_trgic(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->ICR, TIMER_ICR_TRGIC_MSK);
}

/**
  * @brief  TIMER Clear break interrupt flag
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_clear_break_interrupt_flag_brkic(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->ICR, TIMER_ICR_BRKIC_MSK);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group11 SGE
  * @{
  */
/**
  * @brief  TIMER Set software to generate update event
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: Reinitialize the counter and generates an update of the registers
  * @retval None
  */
__STATIC_INLINE void md_timer_set_uev_software_sgu(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SGE, TIMER_SGE_SGU_MSK, sel << TIMER_SGE_SGU_POS);
}

/**
  * @brief  TIMER Set software to generate capture/compare 1 event
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: A capture/compare event is generated on channel 1
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc1ev_software_sgcc1e(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SGE, TIMER_SGE_SGCC1E_MSK, sel << TIMER_SGE_SGCC1E_POS);
}

/**
  * @brief  TIMER Set software to generate capture/compare 2 event
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: A capture/compare event is generated on channel 2
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc2ev_software_sgcc2e(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SGE, TIMER_SGE_SGCC2E_MSK, sel << TIMER_SGE_SGCC2E_POS);
}

/**
  * @brief  TIMER Set software to generate capture/compare 3 event
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: A capture/compare event is generated on channel 3
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc3ev_software_sgcc3e(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SGE, TIMER_SGE_SGCC3E_MSK, sel << TIMER_SGE_SGCC3E_POS);
}

/**
  * @brief  TIMER Set software to generate capture/compare 4 event
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: A capture/compare event is generated on channel 4
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc4ev_software_sgcc4e(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SGE, TIMER_SGE_SGCC4E_MSK, sel << TIMER_SGE_SGCC4E_POS);
}

/**
  * @brief  TIMER Set software to generate capture/compare control update event
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: When CCPCEN bit is set, it allows to update CCnEN, CCnNEN and CHnOCM bits
  * @retval None
  */
__STATIC_INLINE void md_timer_set_comev_software_sgcom(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SGE, TIMER_SGE_SGCOM_MSK, sel << TIMER_SGE_SGCOM_POS);
}

/**
  * @brief  TIMER Set software to generate trigger event
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: The TRGIF flag is set in TIMERn_RIF register. Related interrupt or DMA transfer
                   can occur if enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_trigev_software_sgtrg(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SGE, TIMER_SGE_SGTRG_MSK, sel << TIMER_SGE_SGTRG_POS);
}

/**
  * @brief  TIMER Set software to generate break event
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No action
  *         - 0x1: The TRGIF flag is set in TIMERn_RIF register. Related interrupt or DMA transfer
  *                can occur if enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_breakev_software_sgbrk(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->SGE, TIMER_SGE_SGBRK_MSK, sel << TIMER_SGE_SGBRK_POS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group12 CHMR1
  * @{
  */
/**
  * @brief  TIMER Set capture/compare 1 channel function selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CC1 channel is configured as output
  *         - 0x1: CC1 channel is configured as input, mapped on I1
  *         - 0x2: CC1 channel is configured as input, mapped on I2
  *         - 0x3: CC1 channel is configured as input, mapped on ITn or both edge of I1
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc1_func_cc1ssel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CC1SSEL_MSK, sel << TIMER_CHMR1_CC1SSEL_POSS);
}

/**
  * @brief  TIMER Get capture/compare 1 channel function selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CC1 channel is configured as output
  *         - 0x1: CC1 channel is configured as input, mapped on I1
  *         - 0x2: CC1 channel is configured as input, mapped on I2
  *         - 0x3: CC1 channel is configured as input, mapped on ITn or both edge of I1
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_func_cc1ssel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CC1SSEL_MSK, TIMER_CHMR1_CC1SSEL_POSS);
}

/**
  * @brief  TIMER Set output Compare 1 fast enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CCVAL1 behaves normally depending on counter and CCRV1 values even when the trigger is ON
  *         - 0x1: An active edge on the trigger input acts like a compare match on CCVAL1 output.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare1_fast_enable_ch1ohsen(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CH1OHSEN_MSK, sel << TIMER_CHMR1_CH1OHSEN_POS);
}

/**
  * @brief  TIMER Get output Compare 1 fast enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *        - 0x0: CCVAL1 behaves normally depending on counter and CCRV1 values even when the trigger is ON
  *        - 0x1: An active edge on the trigger input acts like a compare match on CCVAL1 output.
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare1_fast_enable_ch1ohsen(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CH1OHSEN_MSK, TIMER_CHMR1_CH1OHSEN_POS);
}

/**
  * @brief  TIMER Set output Compare 1 preload enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Preload register on TIMERn_CCVAL1 disabled
  *         - 0x1: Preload register on TIMERn_CCVAL1 enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare1_preload_enable_ch1opren(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CH1OPREN_MSK, sel << TIMER_CHMR1_CH1OPREN_POS);
}

/**
  * @brief  TIMER Get output Compare 1 preload enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Preload register on TIMERn_CCVAL1 disabled
  *         - 0x1: Preload register on TIMERn_CCVAL1 enabled
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare1_preload_enable_ch1opren(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CH1OPREN_MSK, TIMER_CHMR1_CH1OPREN_POS);
}

/**
  * @brief  TIMER Set Output Compare 1 mode
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Frozen
  *         - 0x1: Set channel 1 to active level on match
  *         - 0x2: Set channel 1 to inactive level on match
  *         - 0x3: Toggle
  *         - 0x4: Force inactive level
  *         - 0x5: Force active level
  *         - 0x6: PWM mode 1
  *         - 0x7: PWM mode 2
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare1_mode_ch1omod(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CH1OMOD_MSK, sel << TIMER_CHMR1_CH1OMOD_POSS);
}

/**
  * @brief  TIMER Set Output Compare 1 mode
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Frozen
  *         - 0x1: Set channel 1 to active level on match
  *         - 0x2: Set channel 1 to inactive level on match
  *         - 0x3: Toggle
  *         - 0x4: Force inactive level
  *         - 0x5: Force active level
  *         - 0x6: PWM mode 1
  *         - 0x7: PWM mode 2
  */
__STATIC_INLINE uint32_t md_timer_get_output_compare1_mode_ch1omod(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CH1OMOD_MSK, TIMER_CHMR1_CH1OMOD_POSS);
}

/**
  * @brief  TIMER Set output compare 1 clear enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH1O is not affected by the ETRF Input
  *         - 0x1: CH1O is cleared as soon as a High level is detected on ETRF input
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare1_clear_enable_ch1oclren(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CH1OCLREN_MSK, sel << TIMER_CHMR1_CH1OCLREN_POS);
}

/**
  * @brief  TIMER Get output compare 1 clear enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH1O is not affected by the ETRF Input
  *         - 0x1: CH1O is cleared as soon as a High level is detected on ETRF input
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare1_clear_enable_ch1oclren(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CH1OCLREN_MSK, TIMER_CHMR1_CH1OCLREN_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 channel function selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CC2 channel is configured as output
  *         - 0x1: CC2 channel is configured as input, mapped on I1
  *         - 0x2: CC2 channel is configured as input, mapped on I2
  *         - 0x3: CC2 channel is configured as input, mapped on ITn or both edge of I1
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc2_func_cc2ssel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CC2SSEL_MSK, sel << TIMER_CHMR1_CC2SSEL_POSS);
}

/**
  * @brief  TIMER Get capture/compare 2 channel function selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CC2 channel is configured as output
  *         - 0x1: CC2 channel is configured as input, mapped on I1
  *         - 0x2: CC2 channel is configured as input, mapped on I2
  *         - 0x3: CC2 channel is configured as input, mapped on ITn or both edge of I1
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_func_cc2ssel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CC2SSEL_MSK, TIMER_CHMR1_CC2SSEL_POSS);
}

/**
  * @brief  TIMER Set output Compare 2 fast enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CCVAL2 behaves normally depending on counter and CCRV2 values even when the trigger is ON
  *         - 0x1: An active edge on the trigger input acts like a compare match on CCVAL2 output.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare2_fast_enable_ch2ohsen(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CH2OFEN_MSK, sel << TIMER_CHMR1_CH2OFEN_POS);
}

/**
  * @brief  TIMER Get output Compare 2 fast enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CCVAL2 behaves normally depending on counter and CCRV2 values even when the trigger is ON
  *         - 0x1: An active edge on the trigger input acts like a compare match on CCVAL2 output.
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare2_fast_enable_ch2ohsen(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CH2OFEN_MSK, TIMER_CHMR1_CH2OFEN_POS);
}

/**
  * @brief  TIMER Set output Compare 2 preload enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Preload register on TIMERn_CCVAL2 disabled
  *         - 0x1: Preload register on TIMERn_CCVAL2 enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare2_preload_enable_ch2opren(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CH2OPEN_MSK, sel << TIMER_CHMR1_CH2OPEN_POS);
}

/**
  * @brief  TIMER Get output Compare 2 preload enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Preload register on TIMERn_CCVAL2 disabled
  *         - 0x1: Preload register on TIMERn_CCVAL2 enabled
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare2_preload_enable_ch2opren(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CH2OPEN_MSK, TIMER_CHMR1_CH2OPEN_POS);
}

/**
  * @brief  TIMER Set Output Compare 2 mode
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Frozen
  *         - 0x1: Set channel 2 to active level on match
  *         - 0x2: Set channel 2 to inactive level on match
  *         - 0x3: Toggle
  *         - 0x4: Force inactive level
  *         - 0x5: Force active level
  *         - 0x6: PWM mode 1
  *         - 0x7: PWM mode 2
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare2_mode_ch2omod(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CH2OMOD_MSK, sel << TIMER_CHMR1_CH2OMOD_POSS);
}

/**
  * @brief  TIMER Set Output Compare 2 mode
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Frozen
  *         - 0x1: Set channel 2 to active level on match
  *         - 0x2: Set channel 2 to inactive level on match
  *         - 0x3: Toggle
  *         - 0x4: Force inactive level
  *         - 0x5: Force active level
  *         - 0x6: PWM mode 1
  *         - 0x7: PWM mode 2
  */
__STATIC_INLINE uint32_t md_timer_get_output_compare2_mode_ch2omod(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CH2OMOD_MSK, TIMER_CHMR1_CH2OMOD_POSS);
}

/**
  * @brief  TIMER Set output compare 2 clear enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH2O is not affected by the ETRF Input
  *         - 0x1: CH2O is cleared as soon as a High level is detected on ETRF input
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare2_clear_enable_ch2oclren(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_CH2OCLREN_MSK, sel << TIMER_CHMR1_CH2OCLREN_POS);
}

/**
  * @brief  TIMER Get output compare 2 clear enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH2O is not affected by the ETRF Input
  *         - 0x1: CH2O is cleared as soon as a High level is detected on ETRF input
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare2_clear_ch2oclren(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_CH2OCLREN_MSK, TIMER_CHMR1_CH2OCLREN_POS);
}

/**
  * @brief  TIMER Set input capture 1 prescaler
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: no prescaler
  *         - 0x1: capture is done once every 2 events
  *         - 0x2: capture is done once every 4 events
  *         - 0x3: capture is done once every 8 events
  * @retval None
  */
__STATIC_INLINE void md_timer_set_input_capture1_prescaler_ic1pres(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_IC1PRES_MSK, sel << TIMER_CHMR1_IC1PRES_POSS);
}

/**
  * @brief  TIMER Get input capture 1 prescaler
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: no prescaler
  *         - 0x1: capture is done once every 2 events
  *         - 0x2: capture is done once every 4 events
  *         - 0x3: capture is done once every 8 events
  */
__STATIC_INLINE uint32_t md_timer_get_input_capture1_prescaler_ic1pres(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_IC1PRES_MSK, TIMER_CHMR1_IC1PRES_POSS);
}

/**
  * @brief  TIMER Set input capture 1 filter
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No filter, sampling is done at fDTS
  *         - 0x1: fSAMPLING=fCK_INT, N=2
  *         - 0x2: fSAMPLING=fCK_INT, N=4
  *         - 0x3: fSAMPLING=fCK_INT, N=8
  *         - 0x4: fSAMPLING=fDTS/2, N=6
  *         - 0x5: fSAMPLING=fDTS/2, N=8
  *         - 0x6: fSAMPLING=fDTS/4, N=6
  *         - 0x7: fSAMPLING=fDTS/4, N=8
  *         - 0x8: fSAMPLING=fDTS/8, N=6
  *         - 0x9: fSAMPLING=fDTS/8, N=8
  *         - 0xa: fSAMPLING=fDTS/16, N=5
  *         - 0xb: fSAMPLING=fDTS/16, N=6
  *         - 0xc: fSAMPLING=fDTS/16, N=8
  *         - 0xd: fSAMPLING=fDTS/32, N=5
  *         - 0xe: fSAMPLING=fDTS/32, N=6
  *         - 0xf: fSAMPLING=fDTS/32, N=8
  * @retval None
  */
__STATIC_INLINE void md_timer_set_input_capture1_filter_i1flt(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_I1FLT_MSK, sel << TIMER_CHMR1_I1FLT_POSS);
}

/**
  * @brief  TIMER Set input capture 1 filter
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: No filter, sampling is done at fDTS
  *         - 0x1: fSAMPLING=fCK_INT, N=2
  *         - 0x2: fSAMPLING=fCK_INT, N=4
  *         - 0x3: fSAMPLING=fCK_INT, N=8
  *         - 0x4: fSAMPLING=fDTS/2, N=6
  *         - 0x5: fSAMPLING=fDTS/2, N=8
  *         - 0x6: fSAMPLING=fDTS/4, N=6
  *         - 0x7: fSAMPLING=fDTS/4, N=8
  *         - 0x8: fSAMPLING=fDTS/8, N=6
  *         - 0x9: fSAMPLING=fDTS/8, N=8
  *         - 0xa: fSAMPLING=fDTS/16, N=5
  *         - 0xb: fSAMPLING=fDTS/16, N=6
  *         - 0xc: fSAMPLING=fDTS/16, N=8
  *         - 0xd: fSAMPLING=fDTS/32, N=5
  *         - 0xe: fSAMPLING=fDTS/32, N=6
  *         - 0xf: fSAMPLING=fDTS/32, N=8
  */
__STATIC_INLINE uint32_t md_timer_get_input_capture1_filter_i1flt(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_I1FLT_MSK, TIMER_CHMR1_I1FLT_POSS);
}

/**
  * @brief  TIMER Set input capture 2 prescaler
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: no prescaler
  *         - 0x1: capture is done once every 2 events
  *         - 0x2: capture is done once every 4 events
  *         - 0x3: capture is done once every 8 events
  * @retval None
  */
__STATIC_INLINE void md_timer_set_input_capture2_prescaler_ic2pres(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_IC2PRES_MSK, sel << TIMER_CHMR1_IC2PRES_POSS);
}

/**
  * @brief  TIMER Get input capture 2 prescaler
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: no prescaler
  *         - 0x1: capture is done once every 2 events
  *         - 0x2: capture is done once every 4 events
  *         - 0x3: capture is done once every 8 events
  */
__STATIC_INLINE uint32_t md_timer_get_input_capture2_prescaler_ic2pres(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_IC2PRES_MSK, TIMER_CHMR1_IC2PRES_POSS);
}

/**
  * @brief  TIMER Set input capture 2 filter
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No filter, sampling is done at fDTS
  *         - 0x1: fSAMPLING=fCK_INT, N=2
  *         - 0x2: fSAMPLING=fCK_INT, N=4
  *         - 0x3: fSAMPLING=fCK_INT, N=8
  *         - 0x4: fSAMPLING=fDTS/2, N=6
  *         - 0x5: fSAMPLING=fDTS/2, N=8
  *         - 0x6: fSAMPLING=fDTS/4, N=6
  *         - 0x7: fSAMPLING=fDTS/4, N=8
  *         - 0x8: fSAMPLING=fDTS/8, N=6
  *         - 0x9: fSAMPLING=fDTS/8, N=8
  *         - 0xa: fSAMPLING=fDTS/16, N=5
  *         - 0xb: fSAMPLING=fDTS/16, N=6
  *         - 0xc: fSAMPLING=fDTS/16, N=8
  *         - 0xd: fSAMPLING=fDTS/32, N=5
  *         - 0xe: fSAMPLING=fDTS/32, N=6
  *         - 0xf: fSAMPLING=fDTS/32, N=8
  * @retval None
  */
__STATIC_INLINE void md_timer_set_input_capture2_filter_i2flt(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR1, TIMER_CHMR1_I2FLT_MSK, sel << TIMER_CHMR1_I2FLT_POSS);
}

/**
  * @brief  TIMER Set input capture 2 filter
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: No filter, sampling is done at fDTS
  *         - 0x1: fSAMPLING=fCK_INT, N=2
  *         - 0x2: fSAMPLING=fCK_INT, N=4
  *         - 0x3: fSAMPLING=fCK_INT, N=8
  *         - 0x4: fSAMPLING=fDTS/2, N=6
  *         - 0x5: fSAMPLING=fDTS/2, N=8
  *         - 0x6: fSAMPLING=fDTS/4, N=6
  *         - 0x7: fSAMPLING=fDTS/4, N=8
  *         - 0x8: fSAMPLING=fDTS/8, N=6
  *         - 0x9: fSAMPLING=fDTS/8, N=8
  *         - 0xa: fSAMPLING=fDTS/16, N=5
  *         - 0xb: fSAMPLING=fDTS/16, N=6
  *         - 0xc: fSAMPLING=fDTS/16, N=8
  *         - 0xd: fSAMPLING=fDTS/32, N=5
  *         - 0xe: fSAMPLING=fDTS/32, N=6
  *         - 0xf: fSAMPLING=fDTS/32, N=8
  */
__STATIC_INLINE uint32_t md_timer_get_input_capture2_filter_i2flt(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR1, TIMER_CHMR1_I2FLT_MSK, TIMER_CHMR1_I2FLT_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group13 CHMR2
  * @{
  */
/**
  * @brief  TIMER Set capture/compare 3 channel function selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CC1 channel is configured as output
  *         - 0x1: CC1 channel is configured as input, mapped on I3
  *         - 0x2: CC1 channel is configured as input, mapped on I4
  *         - 0x3: CC1 channel is configured as input, mapped on ITn or both edge of I1
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc3_func_cc3ssel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CC3SSEL_MSK, sel << TIMER_CHMR2_CC3SSEL_POSS);
}

/**
  * @brief  TIMER Get capture/compare 3 channel function selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CC1 channel is configured as output
  *         - 0x1: CC1 channel is configured as input, mapped on I3
  *         - 0x2: CC1 channel is configured as input, mapped on I4
  *         - 0x3: CC1 channel is configured as input, mapped on ITn or both edge of I1
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_func_cc3ssel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CC3SSEL_MSK, TIMER_CHMR2_CC3SSEL_POSS);
}

/**
  * @brief  TIMER Set output Compare 3 fast enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CCVAL3 behaves normally depending on counter and CCRV3 values even when the trigger is ON
  *         - 0x1: An active edge on the trigger input acts like a compare match on CCVAL3 output.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare3_fast_enable_ch3ofen(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CH3OFEN_MSK, sel << TIMER_CHMR2_CH3OFEN_POS);
}

/**
  * @brief  TIMER Get output Compare 3 fast enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CCVAL3 behaves normally depending on counter and CCRV3 values even when the trigger is ON
  *         - 0x1: An active edge on the trigger input acts like a compare match on CCVAL3 output.
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare3_fast_enable_ch3ofen(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CH3OFEN_MSK, TIMER_CHMR2_CH3OFEN_POS);
}

/**
  * @brief  TIMER Set output Compare 3 preload enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Preload register on TIMERn_CCVAL3 disabled
  *         - 0x1: Preload register on TIMERn_CCVAL3 enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare3_preload_enable_ch3open(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CH3OPEN_MSK, sel << TIMER_CHMR2_CH3OPEN_POS);
}

/**
  * @brief  TIMER Get output Compare 3 preload enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Preload register on TIMERn_CCVAL3 disabled
  *         - 0x1: Preload register on TIMERn_CCVAL3 enabled
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare3_preload_enable_ch3open(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CH3OPEN_MSK, TIMER_CHMR2_CH3OPEN_POS);
}

/**
  * @brief  TIMER Set Output Compare 3 mode
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Frozen
  *         - 0x1: Set channel 3 to active level on match
  *         - 0x2: Set channel 3 to inactive level on match
  *         - 0x3: Toggle
  *         - 0x4: Force inactive level
  *         - 0x5: Force active level
  *         - 0x6: PWM mode 1
  *         - 0x7: PWM mode 2
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare3_mode_ch3omod(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CH3OMOD_MSK, sel << TIMER_CHMR2_CH3OMOD_POSS);
}

/**
  * @brief  TIMER Set Output Compare 3 mode
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Frozen
  *         - 0x1: Set channel 3 to active level on match
  *         - 0x2: Set channel 3 to inactive level on match
  *         - 0x3: Toggle
  *         - 0x4: Force inactive level
  *         - 0x5: Force active level
  *         - 0x6: PWM mode 1
  *         - 0x7: PWM mode 2
  */
__STATIC_INLINE uint32_t md_timer_get_output_compare3_mode_ch3omod(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CH3OMOD_MSK, TIMER_CHMR2_CH3OMOD_POSS);
}

/**
  * @brief  TIMER Set output compare 3 clear enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH3O is not affected by the ETRF Input
  *         - 0x1: CH3O is cleared as soon as a High level is detected on ETRF input
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare3_clear_enable_ch3oclren(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CH3OCLREN_MSK, sel << TIMER_CHMR2_CH3OCLREN_POS);
}

/**
  * @brief  TIMER Get output compare 3 clear enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH3O is not affected by the ETRF Input
  *         - 0x1: CH3O is cleared as soon as a High level is detected on ETRF input
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare3_clear_enable_ch3oclren(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CH3OCLREN_MSK, TIMER_CHMR2_CH3OCLREN_POS);
}

/**
  * @brief  TIMER Set capture/compare 4 channel function selection
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CC4 channel is configured as output
  *         - 0x1: CC4 channel is configured as input, mapped on I3
  *         - 0x2: CC4 channel is configured as input, mapped on I4
  *         - 0x3: CC4 channel is configured as input, mapped on ITn or both edge of I1
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc4_func_cc4ssel(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CC4SSEL_MSK, sel << TIMER_CHMR2_CC4SSEL_POSS);
}

/**
  * @brief  TIMER Get capture/compare 4 channel function selection
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CC4 channel is configured as output
  *         - 0x1: CC4 channel is configured as input, mapped on I3
  *         - 0x2: CC4 channel is configured as input, mapped on I4
  *         - 0x3: CC4 channel is configured as input, mapped on ITn or both edge of I1
  */
__STATIC_INLINE uint32_t md_timer_get_cc4_func_cc4ssel(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CC4SSEL_MSK, TIMER_CHMR2_CC4SSEL_POSS);
}

/**
  * @brief  TIMER Set output Compare 4 fast enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CCVAL4 behaves normally depending on counter and CCRV4 values even when the trigger is ON
  *         - 0x1: An active edge on the trigger input acts like a compare match on CCVAL4 output.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare4_fast_enable_ch4ohsen(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CH4OHSEN_MSK, sel << TIMER_CHMR2_CH4OHSEN_POS);
}

/**
  * @brief  TIMER Get output Compare 4 fast enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CCVAL4 behaves normally depending on counter and CCRV4 values even when the trigger is ON
  *         - 0x1: An active edge on the trigger input acts like a compare match on CCVAL4 output.
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare4_fast_enable_ch4ohsen(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CH4OHSEN_MSK, TIMER_CHMR2_CH4OHSEN_POS);
}

/**
  * @brief  TIMER Set output Compare 4 preload enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Preload register on TIMERn_CCVAL4 disabled
  *         - 0x1: Preload register on TIMERn_CCVAL4 enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare4_preload_enable_ch4open(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CH4OPEN_MSK, sel << TIMER_CHMR2_CH4OPEN_POS);
}

/**
  * @brief  TIMER Get output Compare 4 preload enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Preload register on TIMERn_CCVAL4 disabled
  *         - 0x1: Preload register on TIMERn_CCVAL4 enabled
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare4_preload_enable_ch4open(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CH4OPEN_MSK, TIMER_CHMR2_CH4OPEN_POS);
}

/**
  * @brief  TIMER Set Output Compare 4 mode
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Frozen
  *         - 0x1: Set channel 4 to active level on match
  *         - 0x2: Set channel 4 to inactive level on match
  *         - 0x3: Toggle
  *         - 0x4: Force inactive level
  *         - 0x5: Force active level
  *         - 0x6: PWM mode 1
  *         - 0x7: PWM mode 2
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare4_mode_ch4omod(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CH4OMOD_MSK, sel << TIMER_CHMR2_CH4OMOD_POSS);
}

/**
  * @brief  TIMER Set Output Compare 4 mode
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Frozen
  *         - 0x1: Set channel 4 to active level on match
  *         - 0x2: Set channel 4 to inactive level on match
  *         - 0x3: Toggle
  *         - 0x4: Force inactive level
  *         - 0x5: Force active level
  *         - 0x6: PWM mode 1
  *         - 0x7: PWM mode 2
  */
__STATIC_INLINE uint32_t md_timer_get_output_compare4_mode_ch4omod(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CH4OMOD_MSK, TIMER_CHMR2_CH4OMOD_POSS);
}

/**
  * @brief  TIMER Set output compare 4 clear enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH4O is not affected by the ETRF Input
  *         - 0x1: CH4O is cleared as soon as a High level is detected on ETRF input
  * @retval None
  */
__STATIC_INLINE void md_timer_set_output_compare4_clear_enable_ch4oclren(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_CH4OCLREN_MSK, sel << TIMER_CHMR2_CH4OCLREN_POS);
}

/**
  * @brief  TIMER Get output compare 4 clear enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH4O is not affected by the ETRF Input
  *         - 0x1: CH4O is cleared as soon as a High level is detected on ETRF input
  */
__STATIC_INLINE uint32_t md_timer_is_output_compare4_clear_enable_ch4oclren(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_CH4OCLREN_MSK, TIMER_CHMR2_CH4OCLREN_POS);
}

/**
  * @brief  TIMER Set input capture 3 prescaler
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: no prescaler
  *         - 0x1: capture is done once every 2 events
  *         - 0x2: capture is done once every 4 events
  *         - 0x3: capture is done once every 8 events
  * @retval None
  */
__STATIC_INLINE void md_timer_set_input_capture3_prescaler_ic3pres(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_IC3PRES_MSK, sel << TIMER_CHMR2_IC3PRES_POSS);
}

/**
  * @brief  TIMER Get input capture 3 prescaler
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: no prescaler
  *         - 0x1: capture is done once every 2 events
  *         - 0x2: capture is done once every 4 events
  *         - 0x3: capture is done once every 8 events
  */
__STATIC_INLINE uint32_t md_timer_get_input_capture3_prescaler_ic3pres(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_IC3PRES_MSK, TIMER_CHMR2_IC3PRES_POSS);
}

/**
  * @brief  TIMER Set input capture 3 filter
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No filter, sampling is done at fDTS
  *         - 0x1: fSAMPLING=fCK_INT, N=2
  *         - 0x2: fSAMPLING=fCK_INT, N=4
  *         - 0x3: fSAMPLING=fCK_INT, N=8
  *         - 0x4: fSAMPLING=fDTS/2, N=6
  *         - 0x5: fSAMPLING=fDTS/2, N=8
  *         - 0x6: fSAMPLING=fDTS/4, N=6
  *         - 0x7: fSAMPLING=fDTS/4, N=8
  *         - 0x8: fSAMPLING=fDTS/8, N=6
  *         - 0x9: fSAMPLING=fDTS/8, N=8
  *         - 0xa: fSAMPLING=fDTS/16, N=5
  *         - 0xb: fSAMPLING=fDTS/16, N=6
  *         - 0xc: fSAMPLING=fDTS/16, N=8
  *         - 0xd: fSAMPLING=fDTS/32, N=5
  *         - 0xe: fSAMPLING=fDTS/32, N=6
  *         - 0xf: fSAMPLING=fDTS/32, N=8
  * @retval None
  */
__STATIC_INLINE void md_timer_set_input_capture3_filter_i3flt(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_I3FLT_MSK, sel << TIMER_CHMR2_I3FLT_POSS);
}

/**
  * @brief  TIMER Get input capture 3 filter
  * @param  TIMERx TIMER Instance
  * @retval  The value of following:
  *         - 0x0: No filter, sampling is done at fDTS
  *         - 0x1: fSAMPLING=fCK_INT, N=2
  *         - 0x2: fSAMPLING=fCK_INT, N=4
  *         - 0x3: fSAMPLING=fCK_INT, N=8
  *         - 0x4: fSAMPLING=fDTS/2, N=6
  *         - 0x5: fSAMPLING=fDTS/2, N=8
  *         - 0x6: fSAMPLING=fDTS/4, N=6
  *         - 0x7: fSAMPLING=fDTS/4, N=8
  *         - 0x8: fSAMPLING=fDTS/8, N=6
  *         - 0x9: fSAMPLING=fDTS/8, N=8
  *         - 0xa: fSAMPLING=fDTS/16, N=5
  *         - 0xb: fSAMPLING=fDTS/16, N=6
  *         - 0xc: fSAMPLING=fDTS/16, N=8
  *         - 0xd: fSAMPLING=fDTS/32, N=5
  *         - 0xe: fSAMPLING=fDTS/32, N=6
  *         - 0xf: fSAMPLING=fDTS/32, N=8
  */
__STATIC_INLINE uint32_t md_timer_get_input_capture3_filter_i3flt(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_I3FLT_MSK, TIMER_CHMR2_I3FLT_POSS);
}

/**
  * @brief  TIMER Set input capture 4 prescaler
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: no prescaler
  *         - 0x1: capture is done once every 2 events
  *         - 0x2: capture is done once every 4 events
  *         - 0x3: capture is done once every 8 events
  * @retval None
  */
__STATIC_INLINE void md_timer_set_input_capture4_prescaler_ic4pres(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_IC4PRES_MSK, sel << TIMER_CHMR2_IC4PRES_POSS);
}

/**
  * @brief  TIMER Get input capture 4 prescaler
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: no prescaler
  *         - 0x1: capture is done once every 2 events
  *         - 0x2: capture is done once every 4 events
  *         - 0x3: capture is done once every 8 events
  */
__STATIC_INLINE uint32_t md_timer_get_input_capture4_prescaler_ic4pres(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_IC4PRES_MSK, TIMER_CHMR2_IC4PRES_POSS);
}

/**
  * @brief  TIMER Set input capture 4 filter
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: No filter, sampling is done at fDTS
  *         - 0x1: fSAMPLING=fCK_INT, N=2
  *         - 0x2: fSAMPLING=fCK_INT, N=4
  *         - 0x3: fSAMPLING=fCK_INT, N=8
  *         - 0x4: fSAMPLING=fDTS/2, N=6
  *         - 0x5: fSAMPLING=fDTS/2, N=8
  *         - 0x6: fSAMPLING=fDTS/4, N=6
  *         - 0x7: fSAMPLING=fDTS/4, N=8
  *         - 0x8: fSAMPLING=fDTS/8, N=6
  *         - 0x9: fSAMPLING=fDTS/8, N=8
  *         - 0xa: fSAMPLING=fDTS/16, N=5
  *         - 0xb: fSAMPLING=fDTS/16, N=6
  *         - 0xc: fSAMPLING=fDTS/16, N=8
  *         - 0xd: fSAMPLING=fDTS/32, N=5
  *         - 0xe: fSAMPLING=fDTS/32, N=6
  *         - 0xf: fSAMPLING=fDTS/32, N=8
  * @retval None
  */
__STATIC_INLINE void md_timer_set_input_capture4_filter_i4flt(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CHMR2, TIMER_CHMR2_I4FLT_MSK, sel << TIMER_CHMR2_I4FLT_POSS);
}

/**
  * @brief  TIMER Set input capture 4 filter
  * @param  TIMERx TIMER Instance
  * @retval  The value of following:
  *         - 0x0: No filter, sampling is done at fDTS
  *         - 0x1: fSAMPLING=fCK_INT, N=2
  *         - 0x2: fSAMPLING=fCK_INT, N=4
  *         - 0x3: fSAMPLING=fCK_INT, N=8
  *         - 0x4: fSAMPLING=fDTS/2, N=6
  *         - 0x5: fSAMPLING=fDTS/2, N=8
  *         - 0x6: fSAMPLING=fDTS/4, N=6
  *         - 0x7: fSAMPLING=fDTS/4, N=8
  *         - 0x8: fSAMPLING=fDTS/8, N=6
  *         - 0x9: fSAMPLING=fDTS/8, N=8
  *         - 0xa: fSAMPLING=fDTS/16, N=5
  *         - 0xb: fSAMPLING=fDTS/16, N=6
  *         - 0xc: fSAMPLING=fDTS/16, N=8
  *         - 0xd: fSAMPLING=fDTS/32, N=5
  *         - 0xe: fSAMPLING=fDTS/32, N=6
  *         - 0xf: fSAMPLING=fDTS/32, N=8
  */
__STATIC_INLINE uint32_t md_timer_get_input_capture4_filter_i4flt(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CHMR2, TIMER_CHMR2_I4FLT_MSK, TIMER_CHMR2_I4FLT_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group14 CCEP
  * @{
  */
/**
  * @brief  TIMER Set capture/compare 1 output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Off - CH1O is not active
  *         - 0x1: On - CH1O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS1, OISS1N and CC1EN bits.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc1_output_enable_cc1en(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC1EN_MSK, sel << TIMER_CCEP_CC1EN_POS);
}

/**
  * @brief  TIMER Get capture/compare 1 output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Off - CH1O is not active
  *         - 0x1: On - CH1O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS1, OISS1N and CC1EN bits.
  */
__STATIC_INLINE uint32_t md_timer_is_cc1_output_enable_cc1en(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC1EN_MSK, TIMER_CCEP_CC1EN_POS);
}

/**
  * @brief  TIMER Set capture/compare 1 input enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: capture disabled
  *         - 0x1: capture enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc1_input_enable_cc1en(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC1EN_MSK, sel << TIMER_CCEP_CC1EN_POS);
}

/**
  * @brief  TIMER Get capture/compare 1 output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Off - CH1O is not active
  *         - 0x1: On - CH1O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS1, OISS1N and CC1EN bits.
  */
__STATIC_INLINE uint32_t md_timer_is_cc1_input_enable_cc1en(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC1EN_MSK, TIMER_CCEP_CC1EN_POS);
}

/**
  * @brief  TIMER Set capture/compare 1 output polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: OC1 active high
  *         - 0x1: OC1 active low
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc1_output_polarity_cc1pol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC1POL_MSK, sel << TIMER_CCEP_CC1POL_POS);
}

/**
  * @brief  TIMER Get capture/compare 1 output polarity
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: OC1 active high
  *         - 0x1: OC1 active low
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_output_polarity_cc1pol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC1POL_MSK, TIMER_CCEP_CC1POL_POS);
}

/**
  * @brief  TIMER Set capture/compare 1 input edge
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: non-inverted: capture is done on a rising edge of I1
  *         - 0x1: inverted: capture is done on a falling edge of I1
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc1_input_edge_cc1pol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC1POL_MSK, sel << TIMER_CCEP_CC1POL_POS);
}

/**
  * @brief  TIMER Get capture/compare 1 input edge
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: non-inverted: capture is done on a rising edge of I1
  *         - 0x1: inverted: capture is done on a falling edge of I1
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_input_edge_cc1pol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC1POL_MSK, TIMER_CCEP_CC1POL_POS);
}

/**
  * @brief  TIMER Set capture/compare 1 complementary output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Off-CH1ON is not active
  *         - 0x1: On-OC1N signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS1, OISS1N and CC1EN bits.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc1_complementary_enable_cc1nen(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC1NE_MSK, sel << TIMER_CCEP_CC1NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 1 complementary output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Off-CH1ON is not active
  *         - 0x1: On-OC1N signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS1, OISS1N and CC1EN bits.
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_complementary_enable_cc1nen(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC1NE_MSK, TIMER_CCEP_CC1NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 1 complementary  output polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CH1ON active high
  *         - 0x1: CH1ON active low
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc1_complementary_polarity_cc1npol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC1NE_MSK, sel << TIMER_CCEP_CC1NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 1 complementary output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CH1ON active high
  *         - 0x1: CH1ON active low
  */
__STATIC_INLINE uint32_t md_timer_get_cc1_complementary_polarity_cc1npol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC1NE_MSK, TIMER_CCEP_CC1NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Off - CH2O is not active
  *         - 0x1: On - CH2O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS2, OISS2N and CC2EN bits.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc2_output_enable_cc2en(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC2EN_MSK, sel << TIMER_CCEP_CC2EN_POS);
}

/**
  * @brief  TIMER Get capture/compare 2 output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *        - 0x0: Off - CH1O is not active
  *        - 0x1: On - CH1O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *               OFFSSR, OISS2, OISS2N and CC2EN bits.
  */
__STATIC_INLINE uint32_t md_timer_is_cc2_output_enable_cc2en(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC2EN_MSK, TIMER_CCEP_CC2EN_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 input enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: capture disabled
  *         - 0x1: capture enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc2_input_enable_cc2en(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC2EN_MSK, sel << TIMER_CCEP_CC2EN_POS);
}

/**
  * @brief  TIMER Get capture/compare 2 output enable
  * @param  TIMERx TIMER Instance
  * @retval sel The value of following:
  *         - 0x0: Off - CH1O is not active
  *         - 0x1: On - CH1O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS2, OISS2N and CC2EN bits.
  */
__STATIC_INLINE uint32_t md_timer_is_cc2_input_enable_cc2en(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC2EN_MSK, TIMER_CCEP_CC2EN_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 output polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CHO2 active high
  *         - 0x1: CHO2 active low
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc2_output_polarity_cc2pol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC2POL_MSK, sel << TIMER_CCEP_CC2POL_POS);
}

/**
  * @brief  TIMER Get capture/compare 2 output polarity
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CHO2 active high
  *         - 0x1: CHO2 active low
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_output_polarity_cc2pol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC2POL_MSK, TIMER_CCEP_CC2POL_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 input edge
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: non-inverted: capture is done on a rising edge of I2
  *         - 0x1: inverted: capture is done on a falling edge of I2
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc2_input_edge_cc2pol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC2POL_MSK, sel << TIMER_CCEP_CC2POL_POS);
}

/**
  * @brief  TIMER Get capture/compare 2 input edge
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: non-inverted: capture is done on a rising edge of I2
  *         - 0x1: inverted: capture is done on a falling edge of I2
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_input_edge_cc2pol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC2POL_MSK, TIMER_CCEP_CC2POL_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 complementary output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Off-CH2ON is not active
  *         - 0x1: On-CH2ON signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS2, OISS2N and CC2EN bits.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc2_complementary_enable_cc2nen(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC2NE_MSK, sel << TIMER_CCEP_CC2NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 complementary output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Off-CH2ON is not active
  *         - 0x1: On-CH2ON signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS2, OISS2N and CC2EN bits.
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_complementary_enable_cc2nen(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC2NE_MSK, TIMER_CCEP_CC2NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 complementary  output polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0:CH2ON active high
  *         - 0x1:CH2ON active low
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc2_complementary_polarity_cc2npol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC2NE_MSK, sel << TIMER_CCEP_CC2NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 2 complementary output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0:CH2ON active high
  *         - 0x1:CH2ON active low
  */
__STATIC_INLINE uint32_t md_timer_get_cc2_complementary_polarity_cc2npol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC2NE_MSK, TIMER_CCEP_CC2NE_POS);
}
/**
  * @brief  TIMER Set capture/compare 3 output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Off - CH3O is not active
  *         - 0x1: On - CH3O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS3, OISS3N and CC3EN bits.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc3_output_enable_cc3en(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC3EN_MSK, sel << TIMER_CCEP_CC3EN_POS);
}

/**
  * @brief  TIMER Get capture/compare 3 output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Off - CH3O is not active
  *         - 0x1: On - CH3O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS3, OISS3N and CC3EN bits.
  */
__STATIC_INLINE uint32_t md_timer_is_cc3_output_enable_cc3en(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC3EN_MSK, TIMER_CCEP_CC3EN_POS);
}

/**
  * @brief  TIMER Set capture/compare 3 input enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: capture disabled
  *         - 0x1: capture enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc3_input_enable_cc3en(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC3EN_MSK, sel << TIMER_CCEP_CC3EN_POS);
}

/**
  * @brief  TIMER Get capture/compare 3 output enable
  * @param  TIMERx TIMER Instance
  * @retval sel The value of following:
  *         - 0x0: Off - CH1O is not active
  *         - 0x1: On - CH1O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS3, OISS3N and CC3EN bits.
  */
__STATIC_INLINE uint32_t md_timer_is_cc3_input_enable_cc3en(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC3EN_MSK, TIMER_CCEP_CC3EN_POS);
}

/**
  * @brief  TIMER Set capture/compare 3 output polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CHO3 active high
  *         - 0x1: CHO3 active low
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc3_output_polarity_cc3pol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC3POL_MSK, sel << TIMER_CCEP_CC3POL_POS);
}

/**
  * @brief  TIMER Get capture/compare 3 output polarity
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CHO3 active high
  *         - 0x1: CHO3 active low
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_output_polarity_cc3pol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC3POL_MSK, TIMER_CCEP_CC3POL_POS);
}

/**
  * @brief  TIMER Set capture/compare 3 input edge
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: non-inverted: capture is done on a rising edge of I3
  *         - 0x1: inverted: capture is done on a falling edge of I3
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc3_input_edge_cc3pol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC3POL_MSK, sel << TIMER_CCEP_CC3POL_POS);
}

/**
  * @brief  TIMER Get capture/compare 3 input edge
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: non-inverted: capture is done on a rising edge of I3
  *         - 0x1: inverted: capture is done on a falling edge of I3
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_input_edge_cc3pol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC3POL_MSK, TIMER_CCEP_CC3POL_POS);
}

/**
  * @brief  TIMER Set capture/compare 3 complementary output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Off-CH3ON is not active
  *         - 0x1: On-CH3ON signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS3, OISS3N and CC3EN bits.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc3_complementary_enable_cc3nen(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC3NE_MSK, sel << TIMER_CCEP_CC3NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 3 complementary output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Off-CH3ON is not active
  *         - 0x1: On-CH3ON signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS3, OISS3N and CC3EN bits.
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_complementary_enable_cc3nen(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC3NE_MSK, TIMER_CCEP_CC3NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 3 complementary  output polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0:CH3ON active high
  *         - 0x1:CH3ON active low
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc3_complementary_polarity_cc3npol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC3NE_MSK, sel << TIMER_CCEP_CC3NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 3 complementary output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0:CH3ON active high
  *         - 0x1:CH3ON active low
  */
__STATIC_INLINE uint32_t md_timer_get_cc3_complementary_polarity_cc3npol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC3NE_MSK, TIMER_CCEP_CC3NE_POS);
}

/**
  * @brief  TIMER Set capture/compare 4 output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Off - CH4O is not active
  *         - 0x1: On - CH4O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS4, OISS4N and CC4EN bits.
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc4_output_enable_cc4en(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC4EN_MSK, sel << TIMER_CCEP_CC4EN_POS);
}

/**
  * @brief  TIMER Get capture/compare 4 output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Off - CH4O is not active
  *         - 0x1: On - CH4O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS4, OISS4N and CC3EN bits.
  */
__STATIC_INLINE uint32_t md_timer_is_cc4_output_enable_cc4en(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC4EN_MSK, TIMER_CCEP_CC4EN_POS);
}

/**
  * @brief  TIMER Set capture/compare 4 input enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: capture disabled
  *         - 0x1: capture enabled
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc4_input_enable_cc4en(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC4EN_MSK, sel << TIMER_CCEP_CC4EN_POS);
}

/**
  * @brief  TIMER Get capture/compare 4 output enable
  * @param  TIMERx TIMER Instance
  * @retval sel The value of following:
  *         - 0x0: Off - CH1O is not active
  *         - 0x1: On - CH1O signal is output on the corresponding output pin depending on GOEN, OFFSSI,
  *                OFFSSR, OISS4, OISS4N and CC4EN bits.
  */
__STATIC_INLINE uint32_t md_timer_is_cc4_input_enable_cc4en(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC4EN_MSK, TIMER_CCEP_CC4EN_POS);
}

/**
  * @brief  TIMER Set capture/compare 4 output polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CHO4 active high
  *         - 0x1: CHO4 active low
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc4_output_polarity_cc4pol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC4POL_MSK, sel << TIMER_CCEP_CC4POL_POS);
}

/**
  * @brief  TIMER Get capture/compare 4 output polarity
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CHO4 active high
  *         - 0x1: CHO4 active low
  */
__STATIC_INLINE uint32_t md_timer_get_cc4_output_polarity_cc4pol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC4POL_MSK, TIMER_CCEP_CC4POL_POS);
}

/**
  * @brief  TIMER Set capture/compare 4 input edge
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: non-inverted: capture is done on a rising edge of I4
  *         - 0x1: inverted: capture is done on a falling edge of I4
  * @retval None
  */
__STATIC_INLINE void md_timer_set_cc4_input_edge_cc4pol(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->CCEP, TIMER_CCEP_CC4POL_MSK, sel << TIMER_CCEP_CC4POL_POS);
}

/**
  * @brief  TIMER Get capture/compare 4 input edge
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: non-inverted: capture is done on a rising edge of I4
  *         - 0x1: inverted: capture is done on a falling edge of I4
  */
__STATIC_INLINE uint32_t md_timer_get_cc4_input_edge_cc4pol(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCEP, TIMER_CCEP_CC4POL_MSK, TIMER_CCEP_CC3POL_POS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group15 COUNT
  * @{
  */
/**
  * @brief  TIMER Set counter value
  * @param  TIMERx TIMER Instance
  * @param  val Counter value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_counter_value_cntv(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->COUNT, TIMER_COUNT_CNTV_MSK, val << TIMER_COUNT_CNTV_POSS);
}

/**
  * @brief  TIMER Get counter value
  * @param  TIMERx TIMER Instance
  * @retval counter value
  */
__STATIC_INLINE uint32_t md_timer_get_counter_value_cntv(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->COUNT, TIMER_COUNT_CNTV_MSK, TIMER_COUNT_CNTV_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group16 PRES
  * @{
  */
/**
  * @brief  TIMER Set Prescaler value
  * @param  TIMERx TIMER Instance
  * @param  val Prescaler value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_prescaler_value_pscv(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->PRES, TIMER_PRES_PSCV_MSK, val << TIMER_PRES_PSCV_POSS);
}

/**
  * @brief  TIMER Get counter value
  * @param  TIMERx TIMER Instance
  * @retval prescaler value
  */
__STATIC_INLINE uint32_t md_timer_get_prescaler_value_pscv(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->PRES, TIMER_PRES_PSCV_MSK, TIMER_PRES_PSCV_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group17 AR
  * @{
  */
/**
  * @brief  TIMER Set auto-reload value
  * @param  TIMERx TIMER Instance
  * @param  val Auto-reload value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_auto_reload_value_arrv(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->AR, TIMER_AR_ARRV_MSK, val << TIMER_AR_ARRV_POSS);
}

/**
  * @brief  TIMER Get auto-reload value
  * @param  TIMERx TIMER Instance
  * @retval auto-reload value
  */
__STATIC_INLINE uint32_t md_timer_get_auto_reload_value_arrv(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->AR, TIMER_AR_ARRV_MSK, TIMER_AR_ARRV_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group18 REPAR
  * @{
  */
/**
  * @brief  TIMER Set repetition counter value
  * @param  TIMERx TIMER Instance
  * @param  val Repetition counter value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_repetition_counter_value_repv(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->REPAR, TIMER_REPAR_REPV_MSK, val << TIMER_REPAR_REPV_POSS);
}

/**
  * @brief  TIMER Get repetition counter value
  * @param  TIMERx TIMER Instance
  * @retval repetition counter value
  */
__STATIC_INLINE uint32_t md_timer_get_repetition_counter_value_repv(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->REPAR, TIMER_REPAR_REPV_MSK, TIMER_REPAR_REPV_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group19 CCVAL1
  * @{
  */
/**
  * @brief  TIMER Set capture/compare 1 value
  * @param  TIMERx TIMER Instance
  * @param  val Value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_capture_compare1_value_ccrv1(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->CCVAL1, TIMER_CCVAL1_CCRV1_MSK, val << TIMER_CCVAL1_CCRV1_POSS);
}

/**
  * @brief  TIMER Get capture/compare 1 value
  * @param  TIMERx TIMER Instance
  * @retval value
  */
__STATIC_INLINE uint32_t md_timer_get_capture_compare1_value_ccrv1(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCVAL1, TIMER_CCVAL1_CCRV1_MSK, TIMER_CCVAL1_CCRV1_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group20 CCVAL2
  * @{
  */
/**
  * @brief  TIMER Set capture/compare 2 value
  * @param  TIMERx TIMER Instance
  * @param  val Value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_capture_compare2_value_ccrv2(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->CCVAL2, TIMER_CCVAL2_CCRV2_MSK, val << TIMER_CCVAL2_CCRV2_POSS);
}
/**
  * @brief  TIMER Get capture/compare 2 value
  * @param  TIMERx TIMER Instance
  * @retval value
  */
__STATIC_INLINE uint32_t md_timer_get_capture_compare2_value_ccrv2(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCVAL2, TIMER_CCVAL2_CCRV2_MSK, TIMER_CCVAL2_CCRV2_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group21 CCVAL3
  * @{
  */
/**
  * @brief  TIMER Set capture/compare 3 value
  * @param  TIMERx TIMER Instance
  * @param  val Value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_capture_compare3_value_ccrv3(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->CCVAL3, TIMER_CCVAL3_CCRV3_MSK, val << TIMER_CCVAL3_CCRV3_POSS);
}
/**
  * @brief  TIMER Get capture/compare 3 value
  * @param  TIMERx TIMER Instance
  * @retval value
  */
__STATIC_INLINE uint32_t md_timer_get_capture_compare3_value_ccrv3(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCVAL3, TIMER_CCVAL3_CCRV3_MSK, TIMER_CCVAL3_CCRV3_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group22 CCVAL4
  * @{
  */
/**
  * @brief  TIMER Set capture/compare 4 value
  * @param  TIMERx TIMER Instance
  * @param  val Value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_capture_compare4_value_ccrv4(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->CCVAL4, TIMER_CCVAL4_CCRV4_MSK, val << TIMER_CCVAL4_CCRV4_POSS);
}
/**
  * @brief  TIMER Get capture/compare 4 value
  * @param  TIMERx TIMER Instance
  * @retval value
  */
__STATIC_INLINE uint32_t md_timer_get_capture_compare4_value_ccrv4(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->CCVAL4, TIMER_CCVAL4_CCRV4_MSK, TIMER_CCVAL4_CCRV4_POSS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group23 BDCFG
  * @{
  */
/**
  * @brief  TIMER Set dead-time generator setup
  * @param  TIMERx TIMER Instance
  * @param  val Value
  * @retval None
  */
__STATIC_INLINE void md_timer_set_dead_time_duration_dt(TIMER_TypeDef *TIMERx, uint32_t val)
{
    MODIFY_REG(TIMERx->BDCFG, TIMER_BDCFG_DT_MSK, val << TIMER_BDCFG_DT_POSS);
}
/**
  * @brief  TIMER Set dead-time generator setup
  * @param  TIMERx TIMER Instance
  * @retval value
  */
__STATIC_INLINE uint32_t md_timer_get_dead_time_duration_dt(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->BDCFG, TIMER_BDCFG_DT_MSK, TIMER_BDCFG_DT_POSS);
}

/**
  * @brief  TIMER Set lock configuration
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: LOCK OFF
  *         - 0x1: LOCK Level 1
  *         - 0x2: LOCK Level 2
  *         - 0x3: LOCK Level 3
  * @retval None
  */
__STATIC_INLINE void md_timer_set_lock_config_locklvl(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->BDCFG, TIMER_BDCFG_LOCKLVL_MSK, sel << TIMER_BDCFG_LOCKLVL_POSS);
}

/**
  * @brief  TIMER Get lock configuration
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: LOCK OFF
  *         - 0x1: LOCK Level 1
  *         - 0x2: LOCK Level 2
  *         - 0x3: LOCK Level 3
  */
__STATIC_INLINE uint32_t md_timer_get_lock_config_locklvl(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->BDCFG, TIMER_BDCFG_LOCKLVL_MSK, TIMER_BDCFG_LOCKLVL_POSS);
}

/**
  * @brief  TIMER Set Off-state selection for Idle mode
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: When inactive, OC/OCN outputs are disabled
  *         - 0x1: When inactive, OC/OCN outputs are forced first with their idle level as soon as CCnEN=1 or
  *                CCnNEN=1. OC/OCN enable output signal=1)
  * @retval None
  */
__STATIC_INLINE void md_timer_set_offstate_idle_selection_offssi(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->BDCFG, TIMER_BDCFG_OFFSSI_MSK, sel << TIMER_BDCFG_OFFSSI_POS);
}

/**
  * @brief  TIMER Get Off-state selection for Idle mode
  * @param  TIMERx TIMER Instance
  * @retval sel The value of following:
  *         - 0x0: When inactive, OC/OCN outputs are disabled
  *         - 0x1: When inactive, OC/OCN outputs are forced first with their idle level as soon as CCnEN=1 or
  *                CCnNEN=1. CHO/CHON enable output signal=1)
  */
__STATIC_INLINE uint32_t md_timer_get_offstate_idle_selection_offssi(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->BDCFG, TIMER_BDCFG_OFFSSI_MSK, TIMER_BDCFG_OFFSSI_POS);
}

/**
  * @brief  TIMER SetOff-state selection for Run mode
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: When inactive, OC/OCN outputs are disabled
  *         - 0x1: When inactive, OC/OCN outputs are enabled with their inactive level as soon as CCnEN=1
  *                or CCnNEN=1. Then, OC/OCN enable output signal=1
  * @retval None
  */
__STATIC_INLINE void md_timer_set_offstate_run_selection_offssr(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->BDCFG, TIMER_BDCFG_OFFSSR_MSK, sel << TIMER_BDCFG_OFFSSR_POS);
}

/**
  * @brief  TIMER SetOff-state selection for Run mode
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: When inactive, OC/OCN outputs are disabled
  *         - 0x1: When inactive, OC/OCN outputs are enabled with their inactive level as soon as CCnEN=1
  *                or CCnNEN=1. Then, OC/OCN enable output signal=1
  */
__STATIC_INLINE uint32_t md_timer_get_offstate_run_selection_offssr(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->BDCFG, TIMER_BDCFG_OFFSSR_MSK, TIMER_BDCFG_OFFSSR_POS);
}

/**
  * @brief  TIMER  Enable break
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_break_brken(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->BDCFG, TIMER_BDCFG_BRKEN_MSK);
}

/**
  * @brief  TIMER  Disable break
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_break_brken(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->BDCFG, TIMER_BDCFG_BRKEN_MSK);
}

/**
  * @brief  TIMER  Check if break enable
  * @param  TIMERx TIMER Instance
  * @retval Status:
  *         - 0: DISABLE
  *         - 1: ENABLE
  */
__STATIC_INLINE uint32_t md_timer_is_break_enable_brken(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->BDCFG, TIMER_BDCFG_BRKEN_MSK, TIMER_BDCFG_BRKEN_POS);
}

/**
  * @brief  TIMER Set break polarity
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: Break input BRK is active low
  *         - 0x1: Break input BRK is active high
  * @retval None
  */
__STATIC_INLINE void md_timer_set_break_polarity_brkp(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->BDCFG, TIMER_BDCFG_BRKP_MSK, sel << TIMER_BDCFG_BRKP_POS);
}

/**
  * @brief  TIMER Get break polarity
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: Break input BRK is active low
  *         - 0x1: Break input BRK is active high
  */
__STATIC_INLINE uint32_t md_timer_get_break_polarity_brkp(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->BDCFG, TIMER_BDCFG_BRKP_MSK, TIMER_BDCFG_BRKP_POS);
}

/**
  * @brief  TIMER Set automatic output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: GOEN can be set only by software
  *         - 0x1: GOEN can be set by software or automatically at the next update event
  * @retval None
  */
__STATIC_INLINE void md_timer_set_auto_output_enable(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->BDCFG, TIMER_BDCFG_AOEN_MSK, sel << TIMER_BDCFG_AOEN_POS);
}

/**
  * @brief  TIMER Get automatic output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: GOEN can be set only by software
  *         - 0x1: GOEN can be set by software or automatically at the next update event
  */
__STATIC_INLINE uint32_t md_timer_get_auto_output_enable(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->BDCFG, TIMER_BDCFG_AOEN_MSK, TIMER_BDCFG_AOEN_POS);
}

/**
  * @brief  TIMER Set main output enable
  * @param  TIMERx TIMER Instance
  * @param  sel The value of following:
  *         - 0x0: CHO and CHON outputs are disabled or forced to idle state.
  *         - 0x1: CHO and CHON outputs are enabled if their respective enable bits are set
  * @retval None
  */
__STATIC_INLINE void md_timer_set_main_output_enable(TIMER_TypeDef *TIMERx, uint32_t sel)
{
    MODIFY_REG(TIMERx->BDCFG, TIMER_BDCFG_GOEN_MSK, sel << TIMER_BDCFG_GOEN_POS);
}

/**
  * @brief  TIMER Get main output enable
  * @param  TIMERx TIMER Instance
  * @retval The value of following:
  *         - 0x0: CHO and CHON outputs are disabled or forced to idle state.
  *         - 0x1: CHO and CHON outputs are enabled if their respective enable bits are set
  */
__STATIC_INLINE uint32_t md_timer_get_main_output_enable(TIMER_TypeDef *TIMERx)
{
    return READ_BITS(TIMERx->BDCFG, TIMER_BDCFG_GOEN_MSK, TIMER_BDCFG_GOEN_POS);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group24 DMAEN
  * @{
  */
/**
  * @brief  TIMER Enable update DMA request enable
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_udma(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->DMAEN, TIMER_DMAEN_UDS_MSK);
}

/**
  * @brief  TIMER Enable capture/compare 1 DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_cc1dma(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->DMAEN, TIMER_DMAEN_CC1DS_MSK);
}

/**
  * @brief  TIMER Enable capture/compare 2 DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_cc2dma(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->DMAEN, TIMER_DMAEN_CC2DS_MSK);
}

/**
  * @brief  TIMER Enable capture/compare 3 DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_cc3dma(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->DMAEN, TIMER_DMAEN_CC3DS_MSK);
}

/**
  * @brief  TIMER Enable capture/compare 4 DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_cc4dma(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->DMAEN, TIMER_DMAEN_CC4DS_MSK);
}

/**
  * @brief  TIMER Enable  COM DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_comdma(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->DMAEN, TIMER_DMAEN_COMDS_MSK);
}

/**
  * @brief  TIMER Enable trigger DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_enable_trgdma(TIMER_TypeDef *TIMERx)
{
    SET_BIT(TIMERx->DMAEN, TIMER_DMAEN_TDS_MSK);
}

/**
  * @brief  TIMER Disable update DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_udma(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->DMAEN, TIMER_DMAEN_UDS_MSK);
}

/**
  * @brief  TIMER Disable capture/compare 1 DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_cc1dma(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->DMAEN, TIMER_DMAEN_CC1DS_MSK);
}

/**
  * @brief  TIMER Disable capture/compare 2 DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_cc2dma(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->DMAEN, TIMER_DMAEN_CC2DS_MSK);
}

/**
  * @brief  TIMER Disable capture/compare 3 DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_cc3dma(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->DMAEN, TIMER_DMAEN_CC3DS_MSK);
}

/**
  * @brief  TIMER Disable capture/compare 4 DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_cc4dma(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->DMAEN, TIMER_DMAEN_CC4DS_MSK);
}

/**
  * @brief  TIMER Disable COM DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_comdma(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->DMAEN, TIMER_DMAEN_COMDS_MSK);
}

/**
  * @brief  TIMER Disable trigger DMA request
  * @param  TIMERx TIMER Instance
  * @retval None
  */
__STATIC_INLINE void md_timer_disable_trgdma(TIMER_TypeDef *TIMERx)
{
    CLEAR_BIT(TIMERx->DMAEN, TIMER_DMAEN_TDS_MSK);
}
/**
  * @}
  */
/** @defgroup MD_TIMER_Public_Functions_Group1 Initialization
  * @{
  */

void md_timer_base_struct_init(md_timer_base_init_t *timer_init_struct);
void md_timer_base_set_config(TIMER_TypeDef *TIMERx, md_timer_base_init_t *init);
void md_timer_ic_struct_init(md_timer_ic_init_t *init);
md_status_t md_timer_ic_init(TIMER_TypeDef *TIMERx, md_timer_channel_t Channel, md_timer_ic_init_t *init);
void md_timer_oc_struct_init(md_timer_oc_init_t *timer_oc_init_struct);
md_status_t md_timer_oc_init(TIMER_TypeDef *TIMERx, md_timer_channel_t channel, md_timer_oc_init_t *timer_oc_init_struct);
void timer_encoder_struct_init(md_timer_encoder_init_t *init);
md_status_t timer_encoder_init(TIMER_TypeDef *TIMERx, md_timer_encoder_init_t *init);
void timer_hallsensor_struct_init(md_timer_hall_sensor_init_t *init);
md_status_t timer_hallsensor_init(TIMER_TypeDef *TIMERx, md_timer_hall_sensor_init_t *init);
void timer_bdtr_struct_init(md_timer_break_dead_time_t *init);
md_status_t timer_bdtr_init(TIMER_TypeDef *TIMERx, md_timer_break_dead_time_t *init);
/**
  * @}
  */
/**
  * @}
  */
/**
  * @}
  */
/**
  * @}
  */
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MD_TIMER_H__ */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/

/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023..2024 HorrorTroll
    ChibiOS - Copyright (C) 2023..2024 Zhaqian

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

/*
   Concepts and parts of this file have been contributed by Uladzimir Pylinsky
   aka barthess.
*/

/**
 * @file    RTCv2/hal_rtc_lld.c
 * @brief   AT32 ERTC low level driver.
 *
 * @addtogroup RTC
 * @{
 */

#include "hal.h"

#if HAL_USE_RTC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define ERTC_TIME_AMPM_OFFSET               22
#define ERTC_TIME_HT_OFFSET                 20
#define ERTC_TIME_HU_OFFSET                 16
#define ERTC_TIME_MT_OFFSET                 12
#define ERTC_TIME_MU_OFFSET                 8
#define ERTC_TIME_ST_OFFSET                 4
#define ERTC_TIME_SU_OFFSET                 0

#define ERTC_DATE_YT_OFFSET                 20
#define ERTC_DATE_YU_OFFSET                 16
#define ERTC_DATE_WK_OFFSET                 13
#define ERTC_DATE_MT_OFFSET                 12
#define ERTC_DATE_MU_OFFSET                 8
#define ERTC_DATE_DT_OFFSET                 4
#define ERTC_DATE_DU_OFFSET                 0

#define ERTC_CTRL_BPR_OFFSET                18

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief ERTC driver identifier.
 */
RTCDriver RTCD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Beginning of configuration procedure.
 *
 * @notapi
 */
static void ertc_enter_init(void) {

  RTCD1.ertc->STS |= ERTC_STS_IMEN;
  while ((RTCD1.ertc->STS & ERTC_STS_IMF) == 0)
    ;
}

/**
 * @brief   Finalizing of configuration procedure.
 *
 * @notapi
 */
static inline void ertc_exit_init(void) {

  RTCD1.ertc->STS &= ~ERTC_STS_IMEN;
}

/**
 * @brief   Converts time from TIME register encoding to timespec.
 *
 * @param[in] time      TIME register value
 * @param[out] timespec pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
static void ertc_decode_time(uint32_t time, RTCDateTime *timespec) {
  uint32_t n;

  n  = ((time >> ERTC_TIME_HT_OFFSET) & 3)  * 36000000;
  n += ((time >> ERTC_TIME_HU_OFFSET) & 15) * 3600000;
  n += ((time >> ERTC_TIME_MT_OFFSET) & 7)  * 600000;
  n += ((time >> ERTC_TIME_MU_OFFSET) & 15) * 60000;
  n += ((time >> ERTC_TIME_ST_OFFSET) & 7)  * 10000;
  n += ((time >> ERTC_TIME_SU_OFFSET) & 15) * 1000;
  timespec->millisecond = n;
}

/**
 * @brief   Converts date from DATE register encoding to timespec.
 *
 * @param[in] date      DATE register value
 * @param[out] timespec pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
static void ertc_decode_date(uint32_t date, RTCDateTime *timespec) {

  timespec->year  = (((date >> ERTC_DATE_YT_OFFSET) & 15) * 10) +
                     ((date >> ERTC_DATE_YU_OFFSET) & 15);
  timespec->month = (((date >> ERTC_DATE_MT_OFFSET) & 1) * 10) +
                     ((date >> ERTC_DATE_MU_OFFSET) & 15);
  timespec->day   = (((date >> ERTC_DATE_DT_OFFSET) & 3) * 10) +
                     ((date >> ERTC_DATE_DU_OFFSET) & 15);
  timespec->dayofweek = (date >> ERTC_DATE_WK_OFFSET) & 7;
}

/**
 * @brief   Converts time from timespec to TIME register encoding.
 *
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 * @return              the TIME register encoding.
 *
 * @notapi
 */
static uint32_t ertc_encode_time(const RTCDateTime *timespec) {
  uint32_t n, time = 0;

  /* Subseconds cannot be set.*/
  n = timespec->millisecond / 1000;

  /* Seconds conversion.*/
  time = time | ((n % 10) << ERTC_TIME_SU_OFFSET);
  n /= 10;
  time = time | ((n % 6) << ERTC_TIME_ST_OFFSET);
  n /= 6;

  /* Minutes conversion.*/
  time = time | ((n % 10) << ERTC_TIME_MU_OFFSET);
  n /= 10;
  time = time | ((n % 6) << ERTC_TIME_MT_OFFSET);
  n /= 6;

  /* Hours conversion.*/
  time = time | ((n % 10) << ERTC_TIME_HU_OFFSET);
  n /= 10;
  time = time | (n << ERTC_TIME_HT_OFFSET);

  return time;
}

/**
 * @brief   Converts a date from timespec to DATE register encoding.
 *
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 * @return              the DATE register encoding.
 *
 * @notapi
 */
static uint32_t ertc_encode_date(const RTCDateTime *timespec) {
  uint32_t n, date = 0;

  /* Year conversion. Note, only years last two digits are considered.*/
  n = timespec->year;
  date = date | ((n % 10) << ERTC_DATE_YU_OFFSET);
  n /= 10;
  date = date | ((n % 10) << ERTC_DATE_YT_OFFSET);

  /* Months conversion.*/
  n = timespec->month;
  date = date | ((n % 10) << ERTC_DATE_MU_OFFSET);
  n /= 10;
  date = date | ((n % 10) << ERTC_DATE_MT_OFFSET);

  /* Days conversion.*/
  n = timespec->day;
  date = date | ((n % 10) << ERTC_DATE_DU_OFFSET);
  n /= 10;
  date = date | ((n % 10) << ERTC_DATE_DT_OFFSET);

  /* Days of week conversion.*/
  date = date | (timespec->dayofweek << ERTC_DATE_WK_OFFSET);

  return date;
}

#if RTC_HAS_STORAGE == TRUE
static size_t _getsize(void *instance) {

  (void)instance;

  return (size_t)AT32_ERTC_STORAGE_SIZE;
}

static ps_error_t _read(void *instance, ps_offset_t offset,
                        size_t n, uint8_t *rp) {
  volatile uint32_t *bpr = &((RTCDriver *)instance)->ertc->BPR1;
  unsigned i;

  osalDbgCheck((instance != NULL) && (rp != NULL));
  osalDbgCheck((n > 0U) && (n <= AT32_ERTC_STORAGE_SIZE));
  osalDbgCheck((offset < AT32_ERTC_STORAGE_SIZE) &&
               (offset + n <= AT32_ERTC_STORAGE_SIZE));

  for (i = 0; i < (unsigned)n; i++) {
    unsigned index = ((unsigned)offset + i) / sizeof (uint32_t);
    unsigned shift = ((unsigned)offset + i) % sizeof (uint32_t);
    *rp++ = (uint8_t)(bpr[index] >> (shift * 8U));
  }

  return PS_NO_ERROR;
}

static ps_error_t _write(void *instance, ps_offset_t offset,
                         size_t n, const uint8_t *wp) {
  volatile uint32_t *bpr = &((RTCDriver *)instance)->ertc->BPR1;
  unsigned i;

  osalDbgCheck((instance != NULL) && (wp != NULL));
  osalDbgCheck((n > 0U) && (n <= AT32_ERTC_STORAGE_SIZE));
  osalDbgCheck((offset < AT32_ERTC_STORAGE_SIZE) &&
               (offset + n <= AT32_ERTC_STORAGE_SIZE));

  for (i = 0; i < (unsigned)n; i++) {
    unsigned index = ((unsigned)offset + i) / sizeof (uint32_t);
    unsigned shift = ((unsigned)offset + i) % sizeof (uint32_t);
    uint32_t regval = bpr[index];
    regval &= ~(0xFFU << (shift * 8U));
    regval |= (uint32_t)*wp++ << (shift * 8U);
    bpr[index] = regval;
  }

  return PS_NO_ERROR;
}

/**
 * @brief   VMT for the ERTC storage file interface.
 */
struct RTCDriverVMT _rtc_lld_vmt = {
  (size_t)0,
  _getsize, _read, _write
};
#endif /* RTC_HAS_STORAGE == TRUE */

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_ERTC_COMMON_HANDLER)
#if !defined(AT32_ERTC_SUPPRESS_COMMON_ISR)
/**
 * @brief   ERTC common interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_ERTC_COMMON_HANDLER) {
  uint32_t sts, clear;

  OSAL_IRQ_PROLOGUE();

  clear = (0U
           | ERTC_STS_TSF
           | ERTC_STS_TSOF
#if defined(ERTC_STS_TP1F)
           | ERTC_STS_TP1F
#endif
#if defined(ERTC_STS_TP2F)
           | ERTC_STS_TP2F
#endif
#if defined(ERTC_STS_WATF)
           | ERTC_STS_WATF
#endif
#if defined(ERTC_STS_ALAF)
           | ERTC_STS_ALAF
#endif
#if defined(ERTC_STS_ALBF)
           | ERTC_STS_ALBF
#endif
          );

  sts = RTCD1.ertc->STS;
  RTCD1.ertc->STS = sts & ~clear;

  exintClearGroup1(EXINT_MASK1(AT32_ERTC_ALARM_EXINT) |
                   EXINT_MASK1(AT32_ERTC_TAMP_STAMP_EXINT) |
                   EXINT_MASK1(AT32_ERTC_WKUP_EXINT));

  if (RTCD1.callback != NULL) {
    uint32_t ctrl = RTCD1.ertc->CTRL;
    uint32_t tamp;

#if defined(ERTC_STS_WATF)
    if (((ctrl & ERTC_CTRL_WATIEN) != 0U) && ((sts & ERTC_STS_WATF) != 0U)) {
      RTCD1.callback(&RTCD1, ERTC_EVENT_WAKEUP);
    }
#endif

#if defined(ERTC_STS_ALAF)
    if (((ctrl & ERTC_CTRL_ALAIEN) != 0U) && ((sts & ERTC_STS_ALAF) != 0U)) {
      RTCD1.callback(&RTCD1, ERTC_EVENT_ALARM_A);
    }
#endif
#if defined(ERTC_STS_ALBF)
    if (((ctrl & ERTC_CTRL_ALBIEN) != 0U) && ((sts & ERTC_STS_ALBF) != 0U)) {
      RTCD1.callback(&RTCD1, ERTC_EVENT_ALARM_B);
    }
#endif

    if ((ctrl & ERTC_CTRL_TSIEN) != 0U) {
      if ((sts & ERTC_STS_TSF) != 0U) {
        RTCD1.callback(&RTCD1, ERTC_EVENT_TS);
      }
      if ((sts & ERTC_STS_TSOF) != 0U) {
        RTCD1.callback(&RTCD1, ERTC_EVENT_TS_OVF);
      }
    }

#if defined(ERTC_TAMP_TP1EN)
    tamp = RTCD1.ertc->TAMP;
    if ((tamp & ERTC_TAMP_TPIEN) != 0U) {
#if defined(ERTC_STS_TP1F)
      if ((sts & ERTC_STS_TP1F) != 0U) {
        RTCD1.callback(&RTCD1, ERTC_EVENT_TAMP1);
      }
#endif
#if defined(ERTC_STS_TP2F)
      if ((sts & ERTC_STS_TP2F) != 0U) {
        RTCD1.callback(&RTCD1, ERTC_EVENT_TAMP2);
      }
#endif
    }
#endif /* !defined(ERTC_TAMP_TP1EN) */
  }

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(AT32_ERTC_SUPPRESS_COMMON_ISR) */

#elif defined(AT32_ERTC_TAMP_STAMP_HANDLER) &&                              \
      defined(AT32_ERTC_WKUP_HANDLER) &&                                    \
      defined(AT32_ERTC_ALARM_HANDLER)
/**
 * @brief   ERTC TAMP/STAMP interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_ERTC_TAMP_STAMP_HANDLER) {
  uint32_t sts, clear;

  OSAL_IRQ_PROLOGUE();

  clear = (0U
           | ERTC_STS_TSF
           | ERTC_STS_TSOF
#if defined(ERTC_STS_TP1F)
           | ERTC_STS_TP1F
#endif
#if defined(ERTC_STS_TP2F)
           | ERTC_STS_TP2F
#endif
          );

  sts = RTCD1.ertc->STS;
  RTCD1.ertc->STS = sts & ~clear;

  exintClearGroup1(EXINT_MASK1(AT32_ERTC_TAMP_STAMP_EXINT));

  if (RTCD1.callback != NULL) {
    uint32_t ctrl, tamp;

    ctrl = RTCD1.ertc->CTRL;
    if ((ctrl & ERTC_CTRL_TSIEN) != 0U) {
      if ((sts & ERTC_STS_TSF) != 0U) {
        RTCD1.callback(&RTCD1, ERTC_EVENT_TS);
      }
      if ((sts & ERTC_STS_TSOF) != 0U) {
        RTCD1.callback(&RTCD1, ERTC_EVENT_TS_OVF);
      }
    }

#if defined(ERTC_TAMP_TP1EN)
    tamp = RTCD1.ertc->TAMP;
    if ((tamp & ERTC_TAMP_TPIEN) != 0U) {
#if defined(ERTC_STS_TP1F)
      if ((sts & ERTC_STS_TP1F) != 0U) {
        RTCD1.callback(&RTCD1, ERTC_EVENT_TAMP1);
      }
#endif
#if defined(ERTC_STS_TP2F)
      if ((sts & ERTC_STS_TP2F) != 0U) {
        RTCD1.callback(&RTCD1, ERTC_EVENT_TAMP2);
      }
#endif
    }
#endif /* !defined(ERTC_TAMP_TP1EN) */
  }

  OSAL_IRQ_EPILOGUE();
}
/**
 * @brief   ERTC wakeup interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_ERTC_WKUP_HANDLER) {
  uint32_t sts;

  OSAL_IRQ_PROLOGUE();

  sts = RTCD1.ertc->STS;
  RTCD1.ertc->STS = sts & ~ERTC_STS_WATF;

  exintClearGroup1(EXINT_MASK1(AT32_ERTC_WKUP_EXINT));

  if (RTCD1.callback != NULL) {
    uint32_t ctrl = RTCD1.ertc->CTRL;

    if (((ctrl & ERTC_CTRL_WATIEN) != 0U) && ((sts & ERTC_STS_WATF) != 0U)) {
      RTCD1.callback(&RTCD1, ERTC_EVENT_WAKEUP);
    }
  }

  OSAL_IRQ_EPILOGUE();
}

/**
 * @brief   ERTC alarm interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_ERTC_ALARM_HANDLER) {
  uint32_t sts, clear;

  OSAL_IRQ_PROLOGUE();

  clear = (0U
#if defined(ERTC_STS_ALAF)
           | ERTC_STS_ALAF
#endif
#if defined(ERTC_STS_ALBF)
           | ERTC_STS_ALBF
#endif
          );

  sts = RTCD1.ertc->STS;
  RTCD1.ertc->STS = sts & ~clear;

  exintClearGroup1(EXINT_MASK1(AT32_ERTC_ALARM_EXINT));

  if (RTCD1.callback != NULL) {
    uint32_t ctrl = RTCD1.ertc->CTRL;
#if defined(ERTC_STS_ALAF)
    if (((ctrl & ERTC_CTRL_ALAIEN) != 0U) && ((sts & ERTC_STS_ALAF) != 0U)) {
      RTCD1.callback(&RTCD1, ERTC_EVENT_ALARM_A);
    }
#endif
#if defined(ERTC_STS_ALBF)
    if (((ctrl & ERTC_CTRL_ALBIEN) != 0U) && ((sts & ERTC_STS_ALBF) != 0U)) {
      RTCD1.callback(&RTCD1, ERTC_EVENT_ALARM_B);
    }
#endif
  }

  OSAL_IRQ_EPILOGUE();
}

#else
#error "missing required ERTC handlers definitions in registry"
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Enable access to registers.
 *
 * @notapi
 */
void rtc_lld_init(void) {

  /* ERTC object initialization.*/
  rtcObjectInit(&RTCD1);

  /* ERTC pointer initialization.*/
  RTCD1.ertc = ERTC;

  /* Disable write protection. */
  RTCD1.ertc->WP = 0xCAU;
  RTCD1.ertc->WP = 0x53U;

  /* If calendar has not been initialized yet then proceed with the
     initial setup.*/
  if (!(RTCD1.ertc->STS & ERTC_STS_INITF)) {

    ertc_enter_init();

    RTCD1.ertc->CTRL = AT32_ERTC_CTRL_INIT | ERTC_CTRL_DREN;
#if defined(ERTC_TAMP_TP1EN)
    RTCD1.ertc->TAMP = AT32_ERTC_TAMP_INIT;
#endif
    RTCD1.ertc->STS  = ERTC_STS_IMEN; /* Clearing all but ERTC_STS_IMEN. */
    RTCD1.ertc->DIV  = AT32_ERTC_DIV_BITS & 0x7FFFU;
    RTCD1.ertc->DIV  = AT32_ERTC_DIV_BITS;

    ertc_exit_init();
  }
  else {
    RTCD1.ertc->STS &= ~ERTC_STS_UPDF;
  }

  /* Callback initially disabled.*/
  RTCD1.callback = NULL;

  /* Enabling ERTC-related EXINT lines.*/
  exintEnableGroup1(EXINT_MASK1(AT32_ERTC_ALARM_EXINT) |
                    EXINT_MASK1(AT32_ERTC_TAMP_STAMP_EXINT) |
                    EXINT_MASK1(AT32_ERTC_WKUP_EXINT),
                    EXINT_MODE_RISING_EDGE | EXINT_MODE_ACTION_INTERRUPT);

  /* IRQ vectors permanently assigned to this driver.*/
  AT32_ERTC_IRQ_ENABLE();
}

/**
 * @brief   Set current time.
 * @note    Fractional part will be silently ignored. There is no possibility
 *          to set it on AT32 platform.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to ERTC driver structure
 * @param[in] timespec  pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
void rtc_lld_set_time(RTCDriver *rtcp, const RTCDateTime *timespec) {
  uint32_t date, time;
  syssts_t sts;

  time = ertc_encode_time(timespec);
  date = ertc_encode_date(timespec);

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  /* Writing the registers.*/
  ertc_enter_init();
  rtcp->ertc->TIME = time;
  rtcp->ertc->DATE = date;
  rtcp->ertc->CTRL = (rtcp->ertc->CTRL & ~(1U << ERTC_CTRL_BPR_OFFSET)) |
                     (timespec->dstflag << ERTC_CTRL_BPR_OFFSET);
  ertc_exit_init();

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Get current time.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to ERTC driver structure
 * @param[out] timespec pointer to a @p RTCDateTime structure
 *
 * @notapi
 */
void rtc_lld_get_time(RTCDriver *rtcp, RTCDateTime *timespec) {
  uint32_t ctrl, date, time, prev_date, prev_time;
  uint32_t subs;
#if AT32_ERTC_HAS_SUBSECONDS
  uint32_t sbs, prev_sbs;
#endif /* AT32_ERTC_HAS_SUBSECONDS */
  syssts_t sts;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  /* Repeated registers read until 2 matching sets are found.*/
#if AT32_ERTC_HAS_SUBSECONDS
  sbs  = 0U;
  time = 0U;
  date = 0U;
  do {
    prev_sbs  = sbs;
    prev_time = time;
    prev_date = date;
    sbs = rtcp->ertc->SBS;
    time = rtcp->ertc->TIME;
    date = rtcp->ertc->DATE;
  } while ((sbs != prev_sbs) || (time != prev_time) || (date != prev_date));
#else /* !AT32_ERTC_HAS_SUBSECONDS */
  time = 0U;
  date = 0U;
  do {
    prev_time = time;
    prev_date = date;
    time = rtcp->ertc->TIME;
    date = rtcp->ertc->DATE;
  } while ((time != prev_time) || (date != prev_date));
#endif /* !AT32_ERTC_HAS_SUBSECONDS */

  /* DST bit is in CTRL, no need to poll on this one.*/
  ctrl = rtcp->ertc->CTRL;

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);

  /* Decoding day time, this starts the atomic read sequence, see "Reading
     the calendar" in the ERTC documentation.*/
  ertc_decode_time(time, timespec);

  /* If the ERTC is capable of sub-second counting then the value is
     normalized in milliseconds and added to the time.*/
#if AT32_ERTC_HAS_SUBSECONDS
  subs = (((AT32_ERTC_DIVB_VALUE - 1U) - sbs) * 1000U) / AT32_ERTC_DIVB_VALUE;
#else
  subs = 0;
#endif /* AT32_ERTC_HAS_SUBSECONDS */
  timespec->millisecond += subs;

  /* Decoding date, this concludes the atomic read sequence.*/
  ertc_decode_date(date, timespec);

  /* Retrieving the DST bit.*/
  timespec->dstflag = (ctrl >> ERTC_CTRL_BPR_OFFSET) & 1;
}

#if (RTC_ALARMS > 0) || defined(__DOXYGEN__)
/**
 * @brief   Set alarm time.
 * @note    Default value after BPR domain reset for both comparators is 0.
 * @note    Function does not performs any checks of alarm time validity.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to ERTC driver structure.
 * @param[in] alarm     alarm identifier. Can be 0 or 1.
 * @param[in] alarmspec pointer to a @p RTCAlarm structure.
 *
 * @notapi
 */
void rtc_lld_set_alarm(RTCDriver *rtcp,
                       rtcalarm_t alarm,
                       const RTCAlarm *alarmspec) {
  syssts_t sts;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  if (alarm == 0) {
    if (alarmspec != NULL) {
      rtcp->ertc->CTRL &= ~ERTC_CTRL_ALAEN;
      while (!(rtcp->ertc->STS & ERTC_STS_ALAWF))
        ;
      rtcp->ertc->ALA = alarmspec->alrmr;
      rtcp->ertc->CTRL |= ERTC_CTRL_ALAEN;
      rtcp->ertc->CTRL |= ERTC_CTRL_ALAIEN;
    }
    else {
      rtcp->ertc->CTRL &= ~ERTC_CTRL_ALAIEN;
      rtcp->ertc->CTRL &= ~ERTC_CTRL_ALAEN;
    }
  }
#if RTC_ALARMS > 1
  else {
    if (alarmspec != NULL) {
      rtcp->ertc->CTRL &= ~ERTC_CTRL_ALBEN;
      while (!(rtcp->ertc->STS & ERTC_STS_ALBWF))
        ;
      rtcp->ertc->ALB = alarmspec->alrmr;
      rtcp->ertc->CTRL |= ERTC_CTRL_ALBEN;
      rtcp->ertc->CTRL |= ERTC_CTRL_ALBIEN;
    }
    else {
      rtcp->ertc->CTRL &= ~ERTC_CTRL_ALBIEN;
      rtcp->ertc->CTRL &= ~ERTC_CTRL_ALBEN;
    }
  }
#endif /* RTC_ALARMS > 1 */

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Get alarm time.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp       pointer to ERTC driver structure
 * @param[in] alarm     alarm identifier. Can be 0 or 1.
 * @param[out] alarmspec pointer to a @p RTCAlarm structure
 *
 * @notapi
 */
void rtc_lld_get_alarm(RTCDriver *rtcp,
                       rtcalarm_t alarm,
                       RTCAlarm *alarmspec) {

  if (alarm == 0)
    alarmspec->alrmr = rtcp->ertc->ALA;
#if RTC_ALARMS > 1
  else
    alarmspec->alrmr = rtcp->ertc->ALB;
#endif /* RTC_ALARMS > 1 */
}
#endif /* RTC_ALARMS > 0 */

/**
 * @brief   Enables or disables ERTC callbacks.
 * @details This function enables or disables callbacks, use a @p NULL pointer
 *          in order to disable a callback.
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp      pointer to ERTC driver structure
 * @param[in] callback  callback function pointer or @p NULL
 *
 * @notapi
 */
void rtc_lld_set_callback(RTCDriver *rtcp, rtccb_t callback) {

  rtcp->callback = callback;
}

#if AT32_ERTC_HAS_PERIODIC_WAKEUPS || defined(__DOXYGEN__)
/**
 * @brief   Sets time of periodic wakeup.
 * @note    Default value after BPR domain reset is 0x0000FFFF
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp       pointer to ERTC driver structure
 * @param[in] wakeupspec pointer to a @p ERTCWakeup structure
 *
 * @api
 */
void ertcAT32SetPeriodicWakeup(RTCDriver *rtcp, const ERTCWakeup *wakeupspec) {
  syssts_t sts;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  if (wakeupspec != NULL) {
    osalDbgCheck(wakeupspec->wat != 0x30000);

    rtcp->ertc->CTRL &= ~ERTC_CTRL_WATEN;
    rtcp->ertc->CTRL &= ~ERTC_CTRL_WATIEN;
    while (!(rtcp->ertc->STS & ERTC_STS_WATWF))
      ;
    rtcp->ertc->WAT = wakeupspec->wat & 0xFFFF;
    rtcp->ertc->CTRL &= ~ERTC_CTRL_WATCLK;
    rtcp->ertc->CTRL |= (wakeupspec->wat >> 16) & ERTC_CTRL_WATCLK;
    rtcp->ertc->CTRL |= ERTC_CTRL_WATIEN;
    rtcp->ertc->CTRL |= ERTC_CTRL_WATEN;
  }
  else {
    rtcp->ertc->CTRL &= ~ERTC_CTRL_WATEN;
    rtcp->ertc->CTRL &= ~ERTC_CTRL_WATIEN;
  }

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}

/**
 * @brief   Gets time of periodic wakeup.
 * @note    Default value after BPR domain reset is 0x0000FFFF
 * @note    The function can be called from any context.
 *
 * @param[in] rtcp        pointer to ERTC driver structure
 * @param[out] wakeupspec pointer to a @p ERTCWakeup structure
 *
 * @api
 */
void ertcAT32GetPeriodicWakeup(RTCDriver *rtcp, ERTCWakeup *wakeupspec) {
  syssts_t sts;

  /* Entering a reentrant critical zone.*/
  sts = osalSysGetStatusAndLockX();

  wakeupspec->wat  = 0;
  wakeupspec->wat |= rtcp->ertc->WAT;
  wakeupspec->wat |= (((uint32_t)rtcp->ertc->CTRL) & 0x7) << 16;

  /* Leaving a reentrant critical zone.*/
  osalSysRestoreStatusX(sts);
}
#endif /* AT32_ERTC_HAS_PERIODIC_WAKEUPS */

#endif /* HAL_USE_RTC */

/** @} */

/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio.
              Copyright (C) 2019 Diego Ismirlian, (dismirlian (at) google's mail)

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

#include "ch.h"
#include "SEGGER_SYSVIEW.h"
#include "hal.h"

#include <string.h>

static systime_t start;
static const char *isr_desc;

static void _cbSendTaskList(void) {
  thread_t *tp;
  tp = chRegFirstThread();
  do {
    SYSVIEW_ChibiOS_SendTaskInfo(tp);
    tp = chRegNextThread(tp);
  } while (tp != NULL);
}

static U64 _cbGetTime(void) {
  return TIME_I2US(chVTTimeElapsedSinceX(start));
}

static void _cbSendSystemDesc(void) {
  SEGGER_SYSVIEW_SendSysDesc("O=ChibiOS");
  SEGGER_SYSVIEW_SendSysDesc(isr_desc);
}

static const SEGGER_SYSVIEW_OS_API os_api = {
  _cbGetTime,
  _cbSendTaskList,
};

void SYSVIEW_ChibiOS_Start(U32 SysFreq, U32 CPUFreq, const char *isr_description) {
  start = chVTGetSystemTimeX();
  isr_desc = isr_description;
  SEGGER_SYSVIEW_Init(SysFreq, CPUFreq, &os_api, _cbSendSystemDesc);
  SEGGER_SYSVIEW_Start();
}

void SYSVIEW_ChibiOS_SendTaskInfo(const void *_tp) {
  const thread_t *const tp = (const thread_t *)_tp;
  SEGGER_SYSVIEW_TASKINFO TaskInfo;

  //Fill all elements with 0 to allow extending the structure
  //in future version without breaking the code
  memset(&TaskInfo, 0, sizeof(TaskInfo));
  TaskInfo.TaskID     = (U32)tp;
  TaskInfo.sName      = tp->name;
  TaskInfo.Prio       = (U32)tp->prio;
#if (CH_DBG_ENABLE_STACK_CHECK == TRUE) || (CH_CFG_USE_DYNAMIC == TRUE)
  TaskInfo.StackBase  = (U32)tp->wabase;
  TaskInfo.StackSize  = (U32)tp->ctx.sp - (U32)tp->wabase;
#else
  TaskInfo.StackBase  = 0U;
  TaskInfo.StackSize  = (U32)tp->wabase;
#endif
  SEGGER_SYSVIEW_SendTaskInfo(&TaskInfo);
}

#include "ch.h"


void _start(void) {

  extern int main(void);
  main();
  NVIC_SystemReset();
}


unsigned long CORE_EnterCritical(void) {

  chSysLock();
  return 0;
}


void CORE_ExitCritical(unsigned long unused) {

  (void)unused;
  chSysUnlock();
}

uint32_t sli_tz_syscfg_set_systicextclken_cfgsystic(void) {

  return 0;
}

uint32_t sli_tz_syscfg_clear_systicextclken_cfgsystic(void) {

  return 0;
}
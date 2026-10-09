#include "hal.h"
#include "em_core_generic.h"

CORE_irqState_t CORE_EnterCritical(void) {

  return (chSysGetStatusAndLockX());
}

void CORE_ExitCritical(CORE_irqState_t irqState) {

  chSysRestoreStatusX(irqState);
}

CORE_irqState_t CORE_EnterAtomic(void) {

  return (chSysGetStatusAndLockX());
}

void CORE_ExitAtomic(CORE_irqState_t irqState) {

  chSysRestoreStatusX(irqState);
}

#if 0
void _start(void) {

  extern int main(void);
  main();
  NVIC_SystemReset();
}
#endif


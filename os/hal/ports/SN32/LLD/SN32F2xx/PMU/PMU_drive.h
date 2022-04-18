#ifndef __SN32F2XX_PMU_H
#define __SN32F2XX_PMU_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdint.h>


/*_____ D E F I N I T I O N S ______________________________________________*/
#define	PMU_SLEEP						4
#define	PMU_DEEP_SLEEP			2

/*_____ M A C R O S ________________________________________________________*/


/*_____ D E C L A R A T I O N S ____________________________________________*/
void PMU_Setting(uint16_t mode_sel);

#endif	/*__SN32F2XX_PMU_H*/

#include <stdint.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "shell.h"
#include "ch_test.h"

#define LED_EXT 14

static THD_WORKING_AREA(shell_wa, 1024);

static const ShellCommand commands[] = {
  {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
  (BaseSequentialStream *)&SD1,
  commands
};

static SerialConfig serial_config = {
    .speed   = 115200,
    .tx_pad  = UART_TX,
    .rx_pad  = UART_RX,
#if NRF5_SERIAL_USE_HWFLOWCTRL	== TRUE
    .rts_pad = UART_RTS,
    .cts_pad = UART_CTS,
#endif
};



static THD_WORKING_AREA(waThread1, 64);
static THD_FUNCTION(Thread1, arg) {

    (void)arg;
    uint8_t led = LED4;
    
    chRegSetThreadName("blinker");

    
    while (1) {
	palSetPad(IOPORT1, led);
	chThdSleepMilliseconds(100);
	palClearPad(IOPORT1, led);
	chThdSleepMilliseconds(100);
    }
}


#define printf(fmt, ...)					\
    chprintf((BaseSequentialStream*)&SD1, fmt, ##__VA_ARGS__)




/**@brief Function for application main entry.
 */
int main(void)
{
    
    halInit();
    chSysInit();
    shellInit();
  
    sdStart(&SD1, &serial_config);

    palSetPad(IOPORT1, LED1);
    palSetPad(IOPORT1, LED2);
    palSetPad(IOPORT1, LED3);
    palSetPad(IOPORT1, LED4);

    
    
    chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO+1,
		      Thread1, NULL);


    
    chThdCreateStatic(shell_wa, sizeof(shell_wa), NORMALPRIO+1,
		      shellThread, (void *)&shell_cfg1);


    
    printf(PORT_INFO "\r\n");
    chThdSleep(2);
    


    printf("Priority levels %d\r\n", CORTEX_PRIORITY_LEVELS);
    
    test_execute((BaseSequentialStream *)&SD1);
    
    while (true) {
	chThdSleepMilliseconds(100);

    }



}


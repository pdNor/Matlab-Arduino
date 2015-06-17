/**
 *	Communication between matlab and arduino due 
 
 *	Author: Daniel Nordahl
 */

#include <asf.h>
#include "io_control/adc.h"
#include "matlab_coms/matlab_state.h"
#include "io_control/io_uart.h"

#define UART_BAUDRATE	115200

int main (void)
{
	sysclk_init();
	board_init();
	uart_config((uint32_t)UART_BAUDRATE);
	init_adc();
	start_coms();
	
}

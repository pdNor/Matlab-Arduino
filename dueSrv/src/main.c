/**
 *	Communication between matlab and arduino due 
 
 *	Author: Daniel Nordahl
 */

#include <asf.h>
#include "io_control/adc.h"

int main (void)
{
	sysclk_init();
	board_init();
	init_adc();
}

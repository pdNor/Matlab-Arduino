/*
 * matlab_state.c
 *
 * Created: 2015-06-15 20:31:34
 *  Author: Daniel
 */ 

#include <asf.h>
#include "io_control/io_uart.h"
#include "matlab_coms/matlab_functions.h"
#include "matlab_coms/matlab_state.h"


void start_coms(){
	
	state next_state = STANDBY;
	state current_state = STANDBY;
	/*Run state machine*/
	while (1)
	{
		switch(current_state){
			case STANDBY:
			switch (read_char())
			{
				case ENQUIRY:
				next_state = HANDSHAKE;
				break;
				case PIN_MODE:
				next_state = P_MODE;
				break;
				case DIGITAL_WRITE:
				next_state = D_WRITE;
				break;
				case DIGITAL_READ:
				next_state = D_READ;
				break;
				case ANALOG_WRITE:
				next_state = A_WRITE;
				break;
				case ANALOG_READ:
				next_state = A_READ;
				break;
			}
			break;
			
			case HANDSHAKE: /*Handshake with matlab*/
			send_char_term(ACK);
			next_state = STANDBY;
			break;
			
			case P_MODE: 
			//code for activating pin
			next_state = STANDBY;
			break;
			
			case D_WRITE:
			//Code for digital write
			next_state = STANDBY;
			break;
			
			case D_READ:
			//code fir digtial read
			next_state = STANDBY;
			break;
			
			case A_WRITE:
			//code for analogwrite
			next_state = STANDBY;
			break;
			
			case A_READ:
			//code for analogread
			next_state = STANDBY;
			break;
			
			
		}
		
		current_state = next_state;
		
		
	}
}


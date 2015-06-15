/*
 * matlab_state.c
 *
 * Created: 2015-06-15 20:31:34
 *  Author: Daniel
 */ 




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
				case REQUETS_DATA:
				next_state = SEND;
				break;
				case UPDATE_SETPOINT:
				next_state = SETPOINT;
			}
			break;
			case HANDSHAKE: /*Handshake with matlab*/
			send_char_term(ACK);
			next_state = STANDBY;
			break;
			case SEND: /* Send values from PID regulator process*/
			
			next_state = STANDBY;
			break;
			case SETPOINT:
			
			
			
			next_state = STANDBY;
			
		}
		
		current_state = next_state;
		/*delay until*/
		
	}
}
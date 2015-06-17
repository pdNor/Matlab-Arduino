/*
 * matlab_functions.c
 *
 * Created: 2015-06-15 20:32:24
 *  Author: Daniel
 */ 

#include "io_control/io_uart.h"
#include "matlab_coms/matlab_functions.h"

void send_char_term(uint8_t chr){
	/*Wait for uart transmitter*/
	while (!uart_transmitter_ready());
	uart_send_char(chr);
	/*Line terminator*/
	while (!uart_transmitter_ready());
	uart_send_char(10);
}

void send_char_no_term(uint8_t chr){
	/*Wait for uart transmitter*/
	while (!uart_transmitter_ready());
	uart_send_char(chr);
}

uint8_t read_char(void){
	/*Read char if receiver is ready*/
	if (uart_receiver_ready())
	{
		return uart_receive_char();
	}
	/*failed to read char*/
	return 0;
}

uint8_t read_when_ready(void){
	while (!uart_receiver_ready());
	return read_char();
}

void send_number(uint16_t nbr){
	int i = 0;
	char string[10];
	sprintf(string,"%d",nbr);
	
	while (string[i] != '\0')
	{
		send_char_no_term(string[i]);
		i++;
	}
	
	send_char_term(13); //Carriage Return and terminator;
}
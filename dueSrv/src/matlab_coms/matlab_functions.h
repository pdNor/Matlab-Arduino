/*
 * matlab_functions.h
 *
 * Created: 2015-06-15 20:32:38
 *  Author: Daniel
 */ 

#include <asf.h>
#ifndef MATLAB_FUNCTIONS_H_
#define MATLAB_FUNCTIONS_H_

void io_pin_dir(uint8_t,uint8_t dir);
void io_pin_level(uint8_t,uint8_t);
extern void send_char_term(uint8_t);
extern void send_char_no_term(uint8_t);
extern uint8_t read_char(void);
extern uint8_t read_when_ready(void);
extern void send_number(uint16_t);




#endif /* MATLAB_FUNCTIONS_H_ */
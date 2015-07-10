/*
 * adc.c
 *
 * Created: 2015-06-15 20:04:35
 *  Author: Daniel
 */ 
#include <adc.h>
#include <asf.h>
#include "io_control/adc.h"

void init_adc(){
	pmc_enable_periph_clk(ID_ADC);
	adc_init(ADC, sysclk_get_main_hz()/2, ADC_CLOCK, 8);
	adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1);
	adc_set_resolution(ADC, ADC_MR_LOWRES_BITS_10);
	adc_enable_channel(ADC, ADC_CHANNEL_7);	//A0
	adc_enable_channel(ADC, ADC_CHANNEL_6);	//A1
	adc_enable_channel(ADC, ADC_CHANNEL_5);	//A2
	adc_enable_all_channel(ADC);
	adc_configure_trigger(ADC, ADC_TRIG_SW, 0);
}

uint16_t read_adc_value(uint32_t channel){
	adc_start(ADC);
	return ADC->ADC_CDR[channel];
}
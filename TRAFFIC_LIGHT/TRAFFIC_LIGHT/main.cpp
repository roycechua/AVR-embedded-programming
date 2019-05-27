/*
 * TRAFFIC_LIGHT.cpp
 *
 * Created: 5/27/2019 2:13:04 PM
 * Author : Royce
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#define F_CPU 9600000UL // Unsigned Long
// There is a warning because the CPU Frequency already has a predefined directive
#define YELLOW PB4
#define RED PB0
#define GREEN PB2

void initIO(void){
	DDRB |= (1<<YELLOW)|(1<<RED)|(1<<GREEN);
}

void traffic_light(void){
	PORTB |= (1<<RED);
	
	_delay_ms(3000);
	PORTB &= (0<<RED);
	PORTB |= (1<<GREEN);
	
	_delay_ms(3000);
	PORTB &= (0<<GREEN);
	PORTB |= (1<<YELLOW);
	_delay_ms(500);
	PORTB &= (0<<YELLOW);
}

int main(void)
{
	cli(); // clear interrupt
	// setup
	initIO();
	sei(); // this is for disabling/deactivating the master interrupt

	/* Replace with your application code */
	while (1)
	{
		traffic_light();
	}
	// return 0; only for posterity/formality
}


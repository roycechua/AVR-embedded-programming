/*
 * LED.cpp
 *
 * Created: 5/27/2019 1:42:30 PM
 * Author : Royce
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 9600000UL // Unsigned Long
// There is a warning because the CPU Frequency already has a predefined directive
#define YELLOW PB4
#define RED PB0
#define GREEN PB2

void initIO(void){
	DDRB |= (1<<YELLOW)|(1<<RED)|(1<<GREEN);
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
		_delay_ms(250); // up to 65100 (estimate)
		PORTB |= (1<<YELLOW)|(1<<RED)|(1<<GREEN);
		_delay_ms(250);
		PORTB &= ~((1<<YELLOW)|(1<<RED)|(1<<GREEN));
    }
	// return 0; only for posterity/formality
}


/*
 * INPUTS.cpp
 *
 * Created: 5/27/2019 2:37:48 PM
 * Author : Royce
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 9600000UL
#define YELLOW PB4
#define RED PB0
#define GREEN PB2
#define PUSHBUTTON PB1

void initIO(void){
	DDRB |= (1<<YELLOW)|(1<<RED)|(1<<GREEN);
	DDRB &= ~(1<<PUSHBUTTON); // this can be ommited
	PORTB |= (1<<PUSHBUTTON); // Activates the internal pull-up resistor
}

int main(void)
{
	cli();
	initIO();
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		if(!(PINB & (1<<PUSHBUTTON))) PORTB |= (1<<RED);
		else PORTB &= ~(1<<RED);
    }
}


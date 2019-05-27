/*
 * LED.cpp
 *
 * Created: 5/27/2019 1:42:30 PM
 * Author : Royce
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define YELLOW PB4
#define RED PB0
#define GREEN PB2

void initIO(void){
	/* One way to do it but it wastes lines of codes
	DDRB |= (1<<YELLOW);
	DDRB |= (1<<RED);
	DDRB |= (1<<GREEN);
	*/
	// This is something better
	DDRB |= (1<<YELLOW)|(1<<RED)|(1<<GREEN);
}

int main(void)
{
	cli(); // clear interreupt
	// setup
	initIO();	
	// initPWM(); other initializations
	// initIC();
	// initSPI();
	// initI2C(); 
	sei(); // this is for disabling/deactivating the master interrupt
	// It needs to be within this code	
		
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1<<YELLOW);
    }
	// return 0; only for posterity/formality
}


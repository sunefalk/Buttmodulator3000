/*
 * initLED.c
 *
 *  Created on: 04/06/2012
 *      Author: Mikkel
 */
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "init_LED.h"

void initLED(void){

	DDRC = 0xFF; //output på LED
	PORTC = 0xFF;

	return;
}

void initPORT(void){

	DDRE = 0x00; //inputs på knapperne
	PORTE = 0xFF;

	return;
}

void initIRQ(void){

	TCCR1B = (1 << CS12);//|(1<<CS10); // 1024 prescaler
	OCR1A = 62000; //Equals delay 1 ms
	TIMSK1= (1<<OCIE1A); //enable output compare mode
	TCNT1 = 0; //reset timer counter 1
	sei(); //enable global interrupts
}

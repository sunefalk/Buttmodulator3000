//Third exercise modular robotics
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "init_LED.h"
#include <avr/interrupt.h>
#include "RobotTime.h"

#define LED_POW 0x01
#define LED_TXD 0x02
#define LED_RXD 0x04
#define LED_AUX 0x08
#define LED_MAN 0x10
#define LED_PRG 0x20
#define LED_PLY 0x40
#define SW_UP 0x10
#define SW_DOWN 0x20
#define SW_LEFT 0x40
#define SW_RIGHT 0x80

int main(void) {
	initLED();
	initPORT();
	initIRQ();
	init_RobotTime();

	while(1){
		if(GetTime() == 5000){
			PORTC ^=LED_POW;
			SetTime(0);
		}
	}
	return 0;
}

ISR(TIMER1_COMPA_vect) {

	OCR1A +=62000;      //SKAL FIKSES SÅ DEN BLIVER PRÆCIS!
	PORTC ^= LED_PLY;

	SetTime(GetTime()+1000);
}

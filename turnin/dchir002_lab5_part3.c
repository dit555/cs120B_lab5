/*	Author: Dumitru Chiriac lab 4
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 4 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum State { Start, S1, S12, S2, S22, S3, S32, S4, S42, S5, S52, S6, S62, S7, S72, S8, S82} state;
	
void Tick(){
	unsigned char temp = ~PINA;
	unsigned char temp2 = PORTB;
	switch(state){ //transitions
		case Start: state = S1; break;

		case S1: state = (temp == 0x01) ? S12 : S1; break;
		case S12: state = (temp == 0x01) ? S12 : S2; break;

		case S2: state = (temp == 0x01) ? S22 : S2; break;
		case S22: state = (temp == 0x01) ? S22 : S3; break;

		case S3: state = (temp == 0x01) ? S32 : S3; break;
		case S32: state = (temp == 0x01) ? S32 : S4; break;

		case S4: state = (temp == 0x01) ? S42 : S4; break;
		case S42: state = (temp == 0x01) ? S42 : S5; break;

		case S5: state = (temp == 0x01) ? S52 : S5; break;
		case S52: state = (temp == 0x01) ? S52 : S6; break;

		case S6: state = (temp == 0x01) ? S62 : S6; break;
		case S62: state = (temp == 0x01) ? S62 : S7; break;

		case S7: state = (temp == 0x01) ? S72 : S7; break;
		case S72: state = (temp == 0x01) ? S72 : S8; break;

		case S8: state = (temp == 0x01) ? S82 : S8; break;
		case S82: state = (temp == 0x01) ? S82 : S1; break;

		default: state = Start; break;

	}

	switch(state){
		case Start: break;
		case S1: temp2 = 0x81; break;
                case S2: temp2 = 0x42; break;
                case S3: temp2 = 0x24; break;
                case S4: temp2 = 0x18; break;
                case S5: temp2 = 0x18; break;
                case S6: temp2 = 0x24; break;
                case S7: temp2 = 0x42; break;
                case S8: temp2 = 0x81; break;

		default: break;

	}
	PORTB = temp2;
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
		
    	while (1) {
		Tick();
    	}
    	return 1;
}

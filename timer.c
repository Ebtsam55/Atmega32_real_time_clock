/*
 * timer.c
 *
 * Created: 4/22/2020 3:04:05 AM
 *  Author: Ebtsam
 */ 

#include "timer.h"
void timer0_normal_init(){
	TCCR0 =(1<<FOC0)| (1<<CS00) | (1<<CS02);
	TIMSK |=(1<<TOIE0);
	sei();
}
void timer0_compare_init(){
	TCCR0 =(1<<FOC0)| (1<<CS00) | (1<<CS02)|(1<<WGM01);
	OCR0=200;
	TIMSK |=(1<<OCIE0);
	sei();
}

void timer2_normal_init()
{
	TCCR2=(1<<FOC0)| (1<<CS20) | (1<<CS21) | (1<<CS22); 
	TIMSK |=(1<<TOIE2);
	sei();
	
}
void timer2_compare_init()
{
	TCCR2=(1<<FOC0)| (1<<CS20) | (1<<CS21) | (1<<CS22) |(1<<WGM21);
	OCR2=200;
	TIMSK |=(1<<OCIE2);
	sei();
}


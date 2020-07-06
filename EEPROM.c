/*
 * EEPROM.c
 *
 * Created: 4/19/2020 7:50:57 PM
 *  Author: Ebtsam
 */ 

#include "EEPROM.h"

uint8_t EEPROM_read (uint16_t add)
{
	while(GETBIT(EECR,EEWE));
	EEAR=add; 
	SETBIT(EECR,EERE);
	return EEDR;
	
}
void EEPROM_write (uint16_t add , uint8_t data)
{
	while(GETBIT(EECR,EEWE));
	while(GETBIT(SPMCR,SPMEN));
	EEAR = add; 
	EEDR = data;
	SETBIT(EECR, EEMWE);
	SETBIT(EECR, EEWE);
}
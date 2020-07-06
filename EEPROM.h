/*
 * EEPROM.h
 *
 * Created: 4/19/2020 7:51:25 PM
 *  Author: Ebtsam
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "Header.h"

uint8_t EEPROM_read (uint16_t add);
void EEPROM_write (uint16_t add , uint8_t data);


#endif /* EEPROM_H_ */
/*
 * E2PROM.c
 * Source code of  ENABLE EEPROM STORAGE
 * Created: 6/30/2021 11:12:49 PM
 *  Author: Ahmed H. Zakaria
 */ 

#include <E2PROM.h>

void WRITE_EEPROM(uint16_t Addr ,uint8_t Data)
{
	while(EECR & (1<<EEPE));
	EEAR = Addr;
	EEDR = Data;
	EECR |= (1<<EEMPE);
	EECR |= (1<<EEPE);
}

uint8_t READ_EEPROM(uint16_t Addr)
{
	while(EECR & (1<<EEPE));
	EEAR = Addr;
	EECR |= (1<<EERE);
	return EEDR;
}


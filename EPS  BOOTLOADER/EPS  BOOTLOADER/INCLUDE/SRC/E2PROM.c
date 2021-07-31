/*
 * E2PROM.c
 * Source code of  ENABLE EEPROM STORAGE
 * Created: 6/27/2021 9:14:03 PM
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

void ERASE_EEPROM(void)
{
	for (uint16_t i=0;i < EEPROM_SIZE;i++)
	{
		if (READ_EEPROM(i) != 0xFF)
		{
			WRITE_EEPROM(i,0xFF);
		}
	}
}
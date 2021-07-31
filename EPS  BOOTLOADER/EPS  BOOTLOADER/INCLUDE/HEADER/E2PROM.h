/*
 * E2PROM.h
 *
 * Created: 6/27/2021 9:13:36 PM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef E2PROM_H_
#define E2PROM_H_

#include <main.h>

#define EEPROM_SIZE 4096
/*************************Function***********************************/
void WRITE_EEPROM(uint16_t Addr ,uint8_t Data);
uint8_t READ_EEPROM(uint16_t Addr);
void ERASE_EEPROM(void);

#endif /* E2PROM_H_ */
/*
 * BOOTLOADER.h
 *
 * Created: 6/27/2021 9:24:45 PM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef BOOTLOADER_H_
#define BOOTLOADER_H_

#include <main.h>

#define  ADDr_SUBSYSTM EPS
#define  VAILD_APP    0xBE
#define  CALL_ON_APP  0xBD
#define  NO_APP       0xED
// Variables
uint16_t NO_PAGES,PAGE_NO,SET_PAGE;
/*************************Function***********************************/
void BOOT_PAGE(uint16_t Page ,uint8_t BUFFER_Hex[]);
void WHITE_APP(void);
void Start_Boot(void);
void Operation_Boot(void);
void Finsh_BOOT(void);

#endif /* BOOTLOADER_H_ */
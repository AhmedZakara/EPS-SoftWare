/*
 * UART2.h
 *
 * Created: 6/30/2021 11:07:16 PM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef UART2_H_
#define UART2_H_

#include <main.h>


/*************************BAUD RATE***********************************/
#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

/*************************Function***********************************/
void UART2_Init(uint8_t  baud);
uint8_t UART2_Receive(void);
uint8_t UART2_Transmit(uint8_t data);

#endif /* UART2_H_ */
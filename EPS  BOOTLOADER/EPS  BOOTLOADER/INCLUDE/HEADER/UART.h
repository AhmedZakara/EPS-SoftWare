/*
 * UART.h
 *
 * Created: 7/1/2021 4:38:19 PM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef UART_H_
#define UART_H_

#include <main.h>

// Define BAUD RATE
#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
/*************************Function***********************************/
void UART2_Init(uint8_t baud);
uint8_t UART2_Receive(void);
uint8_t UART2_Transmit(uint8_t data);



#endif /* UART_H_ */
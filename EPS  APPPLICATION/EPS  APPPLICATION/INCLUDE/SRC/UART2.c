/*
 * UART2.c
 * Source code of Enable UART2 PINS
 * Created: 6/30/2021 11:14:33 PM
 *  Author: Ahmed H. Zakaria
 */ 
#include <UART2.h>

void UART2_Init(uint8_t  baud)
{
	UBRR2L=(uint8_t) baud;
	UBRR2H=(uint8_t)( baud>>8);
	UCSR2B = (1<<TXEN2)|(1<<RXEN2)|(1<<RXCIE2);
	UCSR2C = (3<<UCSZ20);
	FLAG_BOOT = FALSE;
}

uint8_t UART2_Receive(void)
{
	while ( !(UCSR2A & (1<<RXC2)) );
	return UDR2;
}

uint8_t UART2_Transmit(uint8_t data)
{
	UDR2 = data;
	while ( !( UCSR2A & (1<<UDRE2)) );
	return data;
}
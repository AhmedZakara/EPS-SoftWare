/*
 * main.h
 * All Library
 * Created: 3/31/2021 1:15:02 AM
 *  Author: A. ZaKaRia
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL
#define  MAX 320
#define TRUE  0x01
#define FALSE 0x00

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/boot.h>
#include <avr/pgmspace.h>
#include <E2PROM.h>
#include <EUSP.h>
#include <UART.h>
#include <BOOTLOADER.h>
// Arrays
uint8_t BUFFER_RX[MAX];
uint8_t BUFFER_TX[MAX];

#endif /* MAIN_H_ */
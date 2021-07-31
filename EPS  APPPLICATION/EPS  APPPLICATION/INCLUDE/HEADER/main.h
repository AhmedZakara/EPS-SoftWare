/*
 * main.h
 *
 * Created: 6/30/2021 11:11:11 PM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL
#define ON    0x01
#define OFF   0x00
#define TRUE  ON
#define FALSE OFF
#define MIX   256

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <TIME_SUB.h>
#include <ADC_GPIO.h>
#include <FRAMES.h>
#include <UART2.h>
#include <EUSP.h>
#include <E2PROM.h>

#endif /* MAIN_H_ */
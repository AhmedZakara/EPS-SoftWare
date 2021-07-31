/*
 * ADC_GPIO.h
 *
 * Created: 6/30/2021 10:53:05 PM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef ADC_GPIO_H_
#define ADC_GPIO_H_
#include <main.h>

// Define Subsystem & ICs PINS
#define CAMERA  PA4
#define COMMUNICATION  PA6
#define KILL_R  PC0
#define KILL_L  PC2
#define HEATER  PC4
#define MPPT  DDL5
#define ADCS  PG2
#define Vref  4.889
// Function of ON | OFF Switch
#define Set_SW(port,sub)  port|=(1<<sub)
#define Reset_SW(port,sub)  port&=~(1<<sub)
// Variables & Arrays
volatile double Pold,Pnow,Psd,Vold,Vnow,DC,Cnow;
typedef struct {
	float VS_Buck3;
	float CS_Buck3;
	float VS_Buck5;
	float CS_Buck5;
	float VS_Battery;
	float CS_Battery;
	float VS_Solar;
	float CS_Solar;
	uint8_t Temp_S1;
	uint8_t Temp_S2;
}R_Value;
R_Value Real_Value;
char VS_BUC3[6],CS_BUC3[6],VS_BUC5[6],CS_BUC5[6];
char VS_BAT[6],CS_BAT[6],VS_BOS[6],CS_BOS[6];
/*************************Function***********************************/
void ADC_Enable(void);                                   // Start ADC to read values sensors
uint16_t ADC_Channel0_7(uint8_t channel);                // Enable & take values the first part of Channels 0---->7
uint16_t ADC_Channel8_15(uint8_t channel);               // Enable & take values the second part of Channels 8---->15
void REAL_VALUE_SENSOR(void);                 // Put Values of reading in array  All_ADC[16]
void PWM_Enable(void);                                   // Enable Digital PINS OUTPUT
void Timer1_Freq_1Hz(void);                              // Enable Timer Counter 1Sec
void MPPT_P_O(void);                           // Setting Duty cycle through MPPT algorithm
void ON_OFF_SW(void);                          // Setting status on/off switch & send Telemetry

#endif /* ADC_GPIO_H_ */
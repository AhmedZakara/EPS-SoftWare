/*
 * FRAMES.h
 *
 * Created: 6/30/2021 10:55:14 PM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef FRAMES_H_
#define FRAMES_H_

#include <main.h>

/*************************Variables & Array***********************************/
double DUTY;
uint8_t STATUS_TRUE,wait,tnow[4];
/*************************Function***********************************/
void FtoA(float Value_Float, char* BUFER, uint8_t POINT_NUM);
void STRING_VALUE_SENSOR(void);
/* Get Telemetry GROUP-1 *0x01*/
void SOLAR_ARRAY(uint8_t SOLAR_array[]);
void BUCKS(uint8_t BUS[]);
void GET_Battery(uint8_t Batt[]);
void Get_All_Telemetry(uint8_t All_value_ADC[]);
/* Get & Set Power Values -- Function Build any Frame GROUP-2 *0x02*/
void STATUS_SW(uint8_t STATUS_SW_BUF[]);
void POWER_SWITCH(uint8_t Flag);
/* Get , Set & Clock Time GROUP-3 *0x03*/
void SET_TIME_NOW(uint8_t GTime[]);
void GET_TIME_NOW(uint8_t STime[]);
void SET_CLOCK(uint8_t Clock[]);
/* Test EPS GROUP-4 *0x04*/
void Test_EPS_Tx(uint8_t TEST_EPS_Tx[]);
void EPS_Transaction_Log(uint8_t Transaction_BUF[]);
/* SELF PROGRAMMIN SESSION GROUP-5 *0x05*/
void UPDATE_ReQuest(void);

#endif /* FRAMES_H_ */
/*
 * FRAMES.c
 * Source code of Build Frames GROUPS
 * Created: 6/30/2021 11:13:09 PM
 *  Author: Ahmed H. Zakaria
 */ 

#include <FRAMES.h>


void FtoA(float Value_Float, char* BUFER, uint8_t POINT_NUM)
{
	int FIRST_PART =Value_Float;
	float SECOND_PART = Value_Float - FIRST_PART;
	int i = strlen(itoa(FIRST_PART, BUFER,10));
	if (POINT_NUM != 0)
	{
		BUFER[i] = '.';
		SECOND_PART = (float)SECOND_PART * pow(10, POINT_NUM);
		SECOND_PART =(int)SECOND_PART;
		itoa((int)SECOND_PART, BUFER + i + 1, 10);
	}
}

void STRING_VALUE_SENSOR(void)
{
	FtoA(Real_Value.VS_Buck3,VS_BUC3,3);
	FtoA(Real_Value.CS_Buck3,CS_BUC3,3);
	FtoA(Real_Value.VS_Buck5,VS_BUC5,3);
	FtoA(Real_Value.CS_Buck5,CS_BUC5,3);
	FtoA(Real_Value.VS_Battery,VS_BAT,3);
	FtoA(Real_Value.CS_Battery,CS_BAT,3);
	FtoA(Real_Value.VS_Solar,VS_BOS,3);
	FtoA(Real_Value.CS_Solar,CS_BOS,3);
}
// GROUP-1
void SOLAR_ARRAY(uint8_t SOLAR_array[])
{
	SOLAR_array[0]=VS_BOS[0];// Measured value  of voltage solar Cells
	SOLAR_array[1]=VS_BOS[1];
	SOLAR_array[2]=VS_BOS[2];
	SOLAR_array[3]=VS_BOS[3];
	SOLAR_array[4]=VS_BOS[4];
	SOLAR_array[5]=CS_BOS[0];// Measured value  of current solar Cells
	SOLAR_array[6]=CS_BOS[1];
	SOLAR_array[7]=CS_BOS[2];
	SOLAR_array[8]=CS_BOS[3];
	SOLAR_array[9]=CS_BOS[4];
	SOLAR_array[10]=((DUTY/1024)*100);
}

void BUCKS(uint8_t BUS[])
{
	BUS[0]=VS_BUC3[0];// Measured value of voltage Buck 3.3V
	BUS[1]=VS_BUC3[1];
	BUS[2]=VS_BUC3[2];
	BUS[3]=VS_BUC3[3];
	BUS[4]=VS_BUC3[4];
	BUS[5]=VS_BUC5[0];// Measured value of voltage Buck 5V
	BUS[6]=VS_BUC5[1];
	BUS[7]=VS_BUC5[2];
	BUS[8]=VS_BUC5[3];
	BUS[9]=VS_BUC5[4];
	BUS[10]=CS_BUC3[0];// Measured value of current Buck 3.3V
	BUS[11]=CS_BUC3[1];
	BUS[12]=CS_BUC3[2];
	BUS[13]=CS_BUC3[3];
	BUS[14]=CS_BUC3[4];
	BUS[15]=CS_BUC5[0];// Measured value of current Buck 5V
	BUS[16]=CS_BUC5[1];
	BUS[17]=CS_BUC5[2];
	BUS[18]=CS_BUC5[3];
	BUS[19]=CS_BUC5[4];
}

void GET_Battery(uint8_t Batt[])
{
	Batt[0]=Real_Value.Temp_S1;// Measured value of Temp. Sensor 1
	Batt[1]=Real_Value.Temp_S2;// Measured value of Temp. Sensor 2
	Batt[2]=VS_BAT[0];// Measured value  of voltage Battery
	Batt[3]=VS_BAT[1];
	Batt[4]=VS_BAT[2];
	Batt[5]=VS_BAT[3];
	Batt[6]=VS_BAT[4];
	Batt[7]=CS_BAT[0];// Measured value  of current Battery
	Batt[8]=CS_BAT[1];
	Batt[9]=CS_BAT[2];
	Batt[10]=CS_BAT[3];
	Batt[11]=CS_BAT[4];
}

void Get_All_Telemetry(uint8_t All_value_ADC[])
{
	All_value_ADC[0]=VS_BUC3[0];// Measured value of voltage Buck 3.3V
	All_value_ADC[1]=VS_BUC3[1];
	All_value_ADC[2]=VS_BUC3[2];
	All_value_ADC[3]=VS_BUC3[3];
	All_value_ADC[4]=VS_BUC3[4];
	All_value_ADC[5]=VS_BUC5[0];// Measured value of voltage Buck 5V
	All_value_ADC[6]=VS_BUC5[1];
	All_value_ADC[7]=VS_BUC5[2];
	All_value_ADC[8]=VS_BUC5[3];
	All_value_ADC[9]=VS_BUC5[4];
	All_value_ADC[10]=CS_BUC3[0];// Measured value of current Buck 3.3V
	All_value_ADC[11]=CS_BUC3[1];
	All_value_ADC[12]=CS_BUC3[2];
	All_value_ADC[13]=CS_BUC3[3];
	All_value_ADC[14]=CS_BUC3[4];
	All_value_ADC[15]=CS_BUC5[0];// Measured value of current Buck 5V
	All_value_ADC[16]=CS_BUC5[1];
	All_value_ADC[17]=CS_BUC5[2];
	All_value_ADC[18]=CS_BUC5[3];
	All_value_ADC[19]=CS_BUC5[4];
	All_value_ADC[20]=VS_BOS[0];// Measured value  of voltage solar Cells
	All_value_ADC[21]=VS_BOS[1];
	All_value_ADC[22]=VS_BOS[2];
	All_value_ADC[23]=VS_BOS[3];
	All_value_ADC[24]=VS_BOS[4];
	All_value_ADC[25]=CS_BOS[0];// Measured value  of current solar Cells
	All_value_ADC[26]=CS_BOS[1];
	All_value_ADC[27]=CS_BOS[2];
	All_value_ADC[28]=CS_BOS[3];
	All_value_ADC[29]=CS_BOS[4];
	All_value_ADC[30]=VS_BAT[0];// Measured value  of voltage Battery
	All_value_ADC[31]=VS_BAT[1];
	All_value_ADC[32]=VS_BAT[2];
	All_value_ADC[33]=VS_BAT[3];
	All_value_ADC[34]=VS_BAT[4];
	All_value_ADC[35]=CS_BAT[0];// Measured value  of current Battery
	All_value_ADC[36]=CS_BAT[1];
	All_value_ADC[37]=CS_BAT[2];
	All_value_ADC[38]=CS_BAT[3];
	All_value_ADC[39]=CS_BAT[4];
	All_value_ADC[40]=Real_Value.Temp_S1;// Measured value of Temp. Sensor 1
	All_value_ADC[41]=Real_Value.Temp_S2;// Measured value of Temp. Sensor 2
	All_value_ADC[42]=((DUTY/1024)*100);

}

// GROUP-2
void STATUS_SW(uint8_t STATUS_SW_BUF[])
{
	STATUS_SW_BUF[0]=(0x10 & PORTA);//CAMERA
	STATUS_SW_BUF[1]=(0x40 & PORTA);//COMMUNICATION
	STATUS_SW_BUF[2]=(0x01 & PORTC);//KILL SWITCH R
	STATUS_SW_BUF[3]=(0x04 & PORTC);//KILL SWITCH L
	STATUS_SW_BUF[4]=(0x10 & PORTC);//HEATER
	STATUS_SW_BUF[5]=(0x04 & PORTG);//ADCS
}

void POWER_SWITCH(uint8_t Flag)
{
	if (Flag == ON)
	{
		Set_SW(PORTA,CAMERA);
	}
	else if(Flag == OFF)
	{
		Reset_SW(PORTA,CAMERA);
	}
}

// GROUP-3
void SET_TIME_NOW(uint8_t STime[])
{	
	struct tm Time;
	time_t Set_time;
	Time.tm_sec  =STime[0];
	Time.tm_min  =STime[1]+2;
	Time.tm_hour =STime[2];
	Time.tm_mday =STime[3];
	Time.tm_wday =STime[4];
	Time.tm_mon  =STime[5];
	Time.tm_year =STime[6];
	Set_time =mktime(&Time);
	set_system_time(Set_time);
}

void GET_TIME_NOW(uint8_t GTime[])
{	
	GTime[0]=READ_EEPROM(0x0081);
	GTime[1]=READ_EEPROM(0x0082);
	GTime[2]=READ_EEPROM(0x0083);
	GTime[3]=READ_EEPROM(0x0084);
	GTime[4]=READ_EEPROM(0x0086);
	GTime[5]=READ_EEPROM(0x0087);
}

void SET_CLOCK(uint8_t Clock[])
{
	WRITE_EEPROM(0x0090 ,Clock[0] );
	WRITE_EEPROM(0x0091 ,Clock[1] );
	WRITE_EEPROM(0x0092 ,Clock[2] );
	WRITE_EEPROM(0x0093 ,Clock[3] );
	WRITE_EEPROM(0x0094 ,Clock[4]+Clock[0]);
}

// GROUP-4
void Test_EPS_Tx(uint8_t TEST_EPS_Tx[])
{
	TEST_EPS_Tx[0]=0x45;
	TEST_EPS_Tx[1]=0x50;
	TEST_EPS_Tx[2]=0x53;
	TEST_EPS_Tx[3]=0x5f;
	TEST_EPS_Tx[4]=0x50;
	TEST_EPS_Tx[5]=0x49;
	TEST_EPS_Tx[6]=0x4e;
	TEST_EPS_Tx[7]=0x47;
}

void EPS_Transaction_Log(uint8_t Transaction_BUF[])
{
	Transaction_BUF[0]=VS_BUC3[0];// Measured value of voltage Buck 3.3V
	Transaction_BUF[1]=VS_BUC3[1];
	Transaction_BUF[2]=VS_BUC3[2];
	Transaction_BUF[3]=VS_BUC3[3];
	Transaction_BUF[4]=VS_BUC3[4];
	Transaction_BUF[5]=VS_BUC5[0];// Measured value of voltage Buck 5V
	Transaction_BUF[6]=VS_BUC5[1];
	Transaction_BUF[7]=VS_BUC5[2];
	Transaction_BUF[8]=VS_BUC5[3];
	Transaction_BUF[9]=VS_BUC5[4];
	Transaction_BUF[10]=CS_BUC3[0];// Measured value of current Buck 3.3V
	Transaction_BUF[11]=CS_BUC3[1];
	Transaction_BUF[12]=CS_BUC3[2];
	Transaction_BUF[13]=CS_BUC3[3];
	Transaction_BUF[14]=CS_BUC3[4];
	Transaction_BUF[15]=CS_BUC5[0];// Measured value of current Buck 5V
	Transaction_BUF[16]=CS_BUC5[1];
	Transaction_BUF[17]=CS_BUC5[2];
	Transaction_BUF[18]=CS_BUC5[3];
	Transaction_BUF[19]=CS_BUC5[4];
	Transaction_BUF[20]=VS_BOS[0];// Measured value  of voltage solar Cells
	Transaction_BUF[21]=VS_BOS[1];
	Transaction_BUF[22]=VS_BOS[2];
	Transaction_BUF[23]=VS_BOS[3];
	Transaction_BUF[24]=VS_BOS[4];
	Transaction_BUF[25]=CS_BOS[0];// Measured value  of current solar Cells
	Transaction_BUF[26]=CS_BOS[1];
	Transaction_BUF[27]=CS_BOS[2];
	Transaction_BUF[28]=CS_BOS[3];
	Transaction_BUF[29]=CS_BOS[4];
	Transaction_BUF[30]=VS_BAT[0];// Measured value  of voltage Battery
	Transaction_BUF[31]=VS_BAT[1];
	Transaction_BUF[32]=VS_BAT[2];
	Transaction_BUF[33]=VS_BAT[3];
	Transaction_BUF[34]=VS_BAT[4];
	Transaction_BUF[35]=CS_BAT[0];// Measured value  of current Battery
	Transaction_BUF[36]=CS_BAT[1];
	Transaction_BUF[37]=CS_BAT[2];
	Transaction_BUF[38]=CS_BAT[3];
	Transaction_BUF[39]=CS_BAT[4];
	Transaction_BUF[40]=Real_Value.Temp_S1;// Measured value of Temp. Sensor 1
	Transaction_BUF[41]=Real_Value.Temp_S2;// Measured value of Temp. Sensor 2
	Transaction_BUF[42]=((DUTY/1024)*100);
	/*** STATUS SWITCH ***/
	Transaction_BUF[43]=(0x10 & PORTA);//CAMERA
	Transaction_BUF[44]=(0x40 & PORTA);//COMMUNICATION
	Transaction_BUF[45]=(0x01 & PORTC);//KILL SWITCH R
	Transaction_BUF[46]=(0x04 & PORTC);//KILL SWITCH L
	Transaction_BUF[47]=(0x10 & PORTC);//HEATER
	Transaction_BUF[48]=(0x04 & PORTG);//ADCS
	/*** GET TIME ***/
	Transaction_BUF[49]=READ_EEPROM(0x0081);
	Transaction_BUF[50]=READ_EEPROM(0x0082);
	Transaction_BUF[51]=READ_EEPROM(0x0083);
	Transaction_BUF[52]=READ_EEPROM(0x0084);
	Transaction_BUF[53]=READ_EEPROM(0x0086);
	Transaction_BUF[54]=READ_EEPROM(0x0087);
	/*** GET CLOCK VALUE ***/
	Transaction_BUF[55]=READ_EEPROM(0x0090);
	Transaction_BUF[56]=READ_EEPROM(0x0091);
	Transaction_BUF[57]=READ_EEPROM(0x0092);
	Transaction_BUF[58]=READ_EEPROM(0x0093);
	Transaction_BUF[59]=READ_EEPROM(0x0094);
	/*** EPS TEST ***/
	Transaction_BUF[60]=0x45;
	Transaction_BUF[61]=0x50;
	Transaction_BUF[62]=0x53;
	Transaction_BUF[63]=0x5f;
	Transaction_BUF[64]=0x50;
	Transaction_BUF[65]=0x49;
	Transaction_BUF[66]=0x4e;
	Transaction_BUF[67]=0x47;
}

// GROUP-5
void UPDATE_ReQuest(void)
{
	if (FLAG_BOOT)
	{
		WRITE_EEPROM(0x0BED,0xBD);
     	cli();
 		asm("jmp 0x3E000");
	}
}
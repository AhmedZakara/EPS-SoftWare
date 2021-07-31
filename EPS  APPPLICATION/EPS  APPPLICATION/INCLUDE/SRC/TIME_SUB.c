/*
 * TIME_SUB.c
 * Source code of TIME SYSTEM
 * Created: 6/30/2021 11:14:14 PM
 *  Author: Ahmed H. Zakaria
 */ 
#include <TIME_SUB.h>

void Set_Time_E2PROM(void)
{
	struct tm *Time_Now;
	time_t PUT_Time;
	PUT_Time = time(NULL);
	Time_Now = localtime(&PUT_Time);
	WRITE_EEPROM(0x0081 ,Time_Now->tm_sec );
	WRITE_EEPROM(0x0082 ,Time_Now->tm_min);
	WRITE_EEPROM(0x0083 ,Time_Now->tm_hour);
	WRITE_EEPROM(0x0084 ,Time_Now->tm_mday);
	WRITE_EEPROM(0x0085 ,Time_Now->tm_wday);
	WRITE_EEPROM(0x0086 ,Time_Now->tm_mon );
	WRITE_EEPROM(0x0087 ,((Time_Now->tm_year)-2000));
}

void CLOCK_PYLOAD(void)
{
	switch (READ_EEPROM(0x0086) - READ_EEPROM(0x0093))
	{
		case 0x00:switch(READ_EEPROM(0x0084) - READ_EEPROM(0x0092))
		{
			case 0x00:switch (READ_EEPROM(0x0083) - READ_EEPROM(0x0091))
			{
				case 0x00:if ((READ_EEPROM(0x0082) - READ_EEPROM(0x0090)) == 0)
				{
					Set_SW(PORTA,CAMERA);
				}
				else if((READ_EEPROM(0x0083) - READ_EEPROM(0x0094)) == 0)
				{
					Reset_SW(PORTA,CAMERA);
				}
				break;
				default:;
				break;
			}
			break;
			default:;
			break;
		}
		break;
		default:;
		break;
	}
}
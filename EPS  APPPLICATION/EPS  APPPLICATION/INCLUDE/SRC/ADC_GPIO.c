/*
 * ADC_GPIO.c
 * Source code of ADC , Digital I/O , Timer Counter , PWM & MPPT algorithm
 * Created: 6/30/2021 11:10:55 PM
 *  Author: Ahmed H. Zakaria
 */ 
#include <ADC_GPIO.h>

void ADC_Enable(void)
{
	DDRF = 0x00;
	DDRK = 0x00;
	ADMUX |= (1<<REFS0);
	ADMUX |= (1<<ADLAR);
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	ADCSRB |= (1<<ACME);
}

uint16_t ADC_Channel0_7(uint8_t channel)
{
	ADCSRB =0x40;
	ADMUX = 0x40 | (channel & 0x07);
	ADCSRA |= (1<<ADSC);
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	return ADCW;
}

uint16_t ADC_Channel8_15(uint8_t channel)
{
	ADCSRB =0x40 | (1<<MUX5);
	ADMUX = 0x40 | (channel & 0x07);
	ADCSRA |= (1<<ADSC);
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	return ADCW;
}

void REAL_VALUE_SENSOR(void)
{
	Real_Value.VS_Buck3 =   ((ADC_Channel0_7(0)*2*Vref)/1023);
	Real_Value.Temp_S1 =    ((ADC_Channel0_7(1)*8.2*Vref)/1023);
	Real_Value.CS_Buck3 =   (((ADC_Channel0_7(2)*Vref)/1023)/0.94);
	Real_Value.VS_Buck5 =   ((ADC_Channel8_15(1)*2*Vref)/1023);
	Real_Value.Temp_S2 =    ((ADC_Channel8_15(2)*100*2.34*Vref)/1023);
	Real_Value.CS_Buck5 =   (((ADC_Channel8_15(3)*Vref)/1023)/0.94);
	Real_Value.VS_Battery = ((ADC_Channel8_15(4)*2*Vref)/1023);
	Real_Value.CS_Battery = ((((ADC_Channel8_15(5)*Vref)/1023)-1.25)/0.4);
	Real_Value.VS_Solar =   ((ADC_Channel8_15(6)*2*Vref)/1023);
	Real_Value.CS_Solar =   (((ADC_Channel8_15(7)*Vref)/1023)/0.94);
	STRING_VALUE_SENSOR();
}

void PWM_Enable(void)
{
	DDRA =0xFF;
	DDRC =0xFF;
	DDRG =0xFF;
	DDRL |= (1<<DDL5);
	TCCR5A |= (1<<COM5C1) | (1<<WGM51) | (1<<WGM50);
	TCCR5B |= (1<<CS50) | (1<<WGM52) | (1<<WGM53);
	OCR5A=5;
}

void Timer1_Freq_1Hz(void)
{
	TCCR1B |= (1<<CS12) | (1<<WGM12) | (1<<CS10);
	TIMSK1 |= (1<<OCIE1A);
	OCR1A = 16000;
}

/*Perturb & Observe Algorithm ----> Control Duty Cycle*/
void MPPT_P_O(void)
{
	Vnow = Real_Value.VS_Solar;
	Cnow= Real_Value.CS_Solar;
	Pnow=sqrt(Vnow)*sqrt(Cnow);
	if (Vnow < 1)
	{
		DC=Vold=Pold=0;
		Reset_SW(DDRL,MPPT);
	}
	else
	{
		Set_SW(DDRL,MPPT);
		if(Pnow >= Pold)
		{
			DC = Vnow;
			Vold = Vnow;
			Pold = Pnow;
			Psd  = Pnow;
		}else
		{
			DC = Vold;
			if (Pnow > Psd)//If effect Shading
			{
				Pold = Pnow;
			}
			Psd = Pnow;
		}
	}
	
	OCR5C=((DC * 1024)/5);
	DUTY=((DC * 1024)/5);
}

void ON_OFF_SW(void)
{
	if (Real_Value.VS_Battery < 6)                              // Voltage Battery below 6 Volt OFF Subsystem
	{
		Reset_SW(PORTA,CAMERA);
		Reset_SW(PORTA,COMMUNICATION);
		Reset_SW(PORTG,ADCS);
		if (Real_Value.VS_Solar < 1)                           // Voltage Solar cell below 1 Volt OFF Kill Switch
		{
			Reset_SW(PORTC,KILL_R);
			Reset_SW(PORTC,KILL_L);
			}else{
			Set_SW(PORTC,KILL_R);
			Set_SW(PORTC,KILL_L);
		}
		if (Real_Value.Temp_S1 == 0 || Real_Value.Temp_S2 == 0)    // Temp.S1 OR Temp.S2 below 0C ON Heater
		{
			Set_SW(PORTC,HEATER);
			}else{
			Reset_SW(PORTC,HEATER);
		}
	}else if (Real_Value.Temp_S1 > 50 || Real_Value.Temp_S2 > 50)  // Temp.S1 OR Temp.S2 bigger 45C ON Heater
	{
		Reset_SW(PORTA,CAMERA);
		Reset_SW(PORTA,COMMUNICATION);
		Reset_SW(PORTG,ADCS);
		Reset_SW(PORTC,HEATER);
		if (Real_Value.VS_Solar < 1)                           // Voltage Solar cell below 1 Volt OFF Kill Switch
		{
			Reset_SW(PORTC,KILL_R);
			Reset_SW(PORTC,KILL_L);
			}else{
			Set_SW(PORTC,KILL_R);
			Set_SW(PORTC,KILL_L);
		}
		}else{
		if (Real_Value.Temp_S1 == 0 || Real_Value.Temp_S2 == 0)     // Temp.S1 OR Temp.S2 below 0C ON Heater
		{
			Set_SW(PORTC,HEATER);
			}else{
			Reset_SW(PORTC,HEATER);
		}
		Set_SW(PORTA,COMMUNICATION);
		Set_SW(PORTC,KILL_R);
		Set_SW(PORTC,KILL_L);
		Set_SW(PORTG,ADCS);
	}
}
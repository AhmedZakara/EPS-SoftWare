/*
 * Main ProJecT
 * EPS Software
 */ 

#include <main.h>

/*Timer Counter 1 *1Sec**/
ISR(TIMER1_COMPA_vect)
{
	system_tick();
}

/*Interrupt Receiver*/
ISR(USART2_RX_vect)
{
	Rx_CRC_Tx();
}

int main(void)
{
    wdt_enable(WDTO_1S); /* Enable WatchDog Timer --> 1 Sec*/ 
    ADC_Enable();
    PWM_Enable();
    UART2_Init(MYUBRR);
    Timer1_Freq_1Hz();
    sei();               /*Global interrupt*/
    while (1) 
    {
		wdt_reset();               /*Refresh WatchDog Timer*/
		REAL_VALUE_SENSOR();       /*Read Values of Sensors*/
		MPPT_P_O();                /*Perturb & Observe Algorithm ----> Control Duty Cycle*/
		ON_OFF_SW();               /*Check EPS Emergency case*/
		CLOCK_PYLOAD();
		Set_Time_E2PROM();
		UPDATE_ReQuest();
    }
}
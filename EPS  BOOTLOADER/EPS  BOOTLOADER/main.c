/*
 * BOOTLOADER---->{EPS}
 * USING UART2
 * Created: 6/27/2021 9:07:55 PM
 * Author : Ahmed H. Zakaria
 */ 
#include <main.h>



int main(void)
{
	CHECK_VAILD_APP();
	wdt_enable(WDTO_1S);
	UART2_Init(MYUBRR);
    while (1) 
    {
		wdt_reset();
		Rx_CRC_Tx();
    }
}

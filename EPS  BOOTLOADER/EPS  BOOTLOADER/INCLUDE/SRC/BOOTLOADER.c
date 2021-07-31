/*
 * BOOTLOADER.c
 * Source code of BOOTLOADER & Self-Programming Concept using Atmega2560
 * Created: 6/27/2021 9:25:13 PM
 *  Author: Ahmed H. Zakaria
 */ 
#include <BOOTLOADER.h>

void BOOT_PAGE(uint16_t Page ,uint8_t BUFFER_Hex[])
{
	Page=BUFFER_Hex[1] | BUFFER_Hex[0]<<8;
	uint16_t i;
	uint32_t Address;
	Address = Page * SPM_PAGESIZE ;
	boot_page_erase_safe (Address);
	for (i=0; i < SPM_PAGESIZE; i+=2)
	{
		boot_page_fill_safe(Address + (i), BUFFER_Hex[i+2] | BUFFER_Hex[i+3]<<8);
	}
	boot_page_write_safe (Address);
	boot_rww_enable_safe();
}

void Start_Boot(void)
{
	NO_PAGES = DATA[0] << 8 | DATA[1];
	PAGE_NO = 0x0000;
	REPLY[0] = PAGE_NO << 8;
	REPLY[1] = PAGE_NO;
	EUSP.SGID = OPERATION;
	TELEMETRY_Tx();
}

void Operation_Boot(void)
{
	if (PAGE_NO != NO_PAGES)
	{
		PAGE_NO++;
		REPLY[0] = PAGE_NO << 8;
		REPLY[1] = PAGE_NO;
		TELEMETRY_Tx();
	}else
	{
		EUSP.SGID = CHECK_SUM;
		EUSP.RL = 0x01;
		REPLY[0] =CHECK_SUM_APP(NO_PAGES);
		TELEMETRY_Tx();
		PAGE_NO=0;
	}
}

void Finsh_BOOT(void)
{
	ERASE_EEPROM();
	WRITE_EEPROM(0x0BED ,VAILD_APP);
	REPLY[0] = 0xAC;
	TELEMETRY_Tx();
	asm("jmp 0");
}

void WHITE_APP(void)
{
	switch (EUSP.SA)
	{
	case ADDr_SUBSYSTM:switch (EUSP.GID)
	{
	    case BOOT:switch (EUSP.SGID)
	    {
			case START:Start_Boot();
			   break;
			case OPERATION:BOOT_PAGE(SET_PAGE,DATA);Operation_Boot();
			   break;
			case END:Finsh_BOOT();
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

void CHECK_VAILD_APP(void)
{
	switch (READ_EEPROM(0x0BED))
	{
		case VAILD_APP:asm("jmp 0");
		break;
	}
}
/*
 * EUSP.h
 *
 * Created: 6/30/2021 10:57:06 PM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef EUSP_H_
#define EUSP_H_

#include <main.h>

//********* CubeSat Satellite Protocol (CSP) with different platforms *********//
typedef struct {
	uint8_t SA;       // Subsystem Address
	uint8_t GID;      // Group ID
	uint8_t SGID;     // Sub-Group  ID
	uint8_t DoL;      // Data Out Length
	uint8_t RL;       // Reply  Length
	uint8_t CRC;      // Cyclic redundancy check
	uint8_t STATUS;   // Reception Status (Status)
}PRTOCOL;
PRTOCOL EUSP;
uint8_t FLAG_START;
//********* Subsystem Address (SA) *********//
#define EPS   0x20
//********* Group ID (GID) *********//
#define SENSOR    0x01
#define POWER_SET 0x02
#define TIME      0x03
#define TEST      0x04
#define BOOT      0xBE
//********* Sub-Group ID (SGID) *********//
// SENSOR
#define SOLAR_CELL    0x00
#define BATTERY       0x01
#define BUCK          0x02
#define ALL_EPS       0x03
// POWER_SET
#define SET_POWER     0x00
#define GET_POWER     0x01
// TIME
#define SET_TIME      0x00
#define GET_TIME      0x01
#define CLOCK         0x02
// TEST
#define TRANSLOG      0x00
#define TEST_PING     0x01
// BOOTLOADER
#define STRAT_BOOT    0x00
//********* Reception Status (Status) *********//
#define ACK           0xAC
#define NACK          0x54
/*************************Variables***********************************/
uint8_t REPLY[MIX];
uint8_t DATA[MIX];
uint8_t FLAG_BOOT;
/*************************Function***********************************/
uint8_t crc8_calculate (uint8_t *data , uint8_t n);
void TELEMETRY_Tx(void);
void DATA_Rx(uint8_t stringTx[] ,uint8_t n);
void COMMAND_Rx(void);
uint8_t CRC_COMMAND(void);
void TELEMETRY_DETERMINATION(void);
void Rx_CRC_Tx(void);


#endif /* EUSP_H_ */
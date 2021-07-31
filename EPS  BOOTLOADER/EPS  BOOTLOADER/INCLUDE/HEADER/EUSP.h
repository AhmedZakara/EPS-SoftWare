/*
 * EUSP.h
 *
 * Created: 7/1/2021 3:22:32 PM
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
uint16_t LENGTH;
uint8_t FLAG_START;
//********* Subsystem Address (SA) *********//
#define EPS   0x20
//********* Group ID (GID) *********//
#define BOOT  0xBE
//********* Sub-Group ID (SGID) *********//
#define START     0x00
#define OPERATION 0X01
#define CHECK_SUM 0X02
#define END       0x03
//********* Reception Status (Status) *********//
#define ACK           0xAC
#define NACK          0x54
/*************************Variables***********************************/
#define MIX 500
uint8_t REPLY[MIX];
uint8_t DATA[MIX];
/*************************Function***********************************/
void TELEMETRY_Tx(void);
void DATA_Rx(uint8_t stringTx[] ,uint16_t n);
void COMMAND_Rx(void);
uint8_t CRC_COMMAND(void);
void CHECK_VAILD_APP(void);
uint8_t CHECK_SUM_APP(uint16_t PAGES);
void Rx_CRC_Tx(void);

#endif /* EUSP_H_ */
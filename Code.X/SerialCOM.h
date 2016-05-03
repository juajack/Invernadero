/* 
 * File:   SerialCOM.h
 * Author: Juan Jackson
 *
 * Created on November 17, 2015, 3:57 PM
 */

//This is a header for Serial COM

#ifndef SERIALCOM_H
#define	SERIALCOM_H

#include "types.h"

//Defines

u8 frame;
u8 f_frameready;
u8 firstbyte[] = {'#','&','!','@','%'};
u8 endbyte = '$';
u8 counter = 0;

u8 light=   0x4C;       //L
u8 fan=     0x46;       //F

extern u8 RecievedData[15];
//extern u16 value[2];


//Function prototypes

void SerialInit(void);
void ReadFrame(u8 *pointer);

//
//                              TXSTA
//

//(bit7)Async don't care
#define _CSRC  OFF
//(bit6)Enable if 9-bit transmission
#define _TX9  OFF
//(bit5)ON if TX enable
#define _TXEN ON
//(bit4)OFF if Asynchronous mode
#define _SYNC OFF
//(bit3)OFF if Sync Break transmission completed, ON if Send Sync Break on next transmission
#define _SENDB OFF
//(bit2)OFF if Low speed, ON if High speed
#define _BRGH OFF;

//
//                              RCSTA
//

//(bit 7)Serial port enable bit
#define _SPEN ON
//(bit 6)Serial 9-bit REcieve eanble bit, OFF if 8-bits transmission
#define _RX9 OFF
//(bit 5)Async dont care
#define _SREN OFF
//(bit 4)Async, ON enables reciever
#define _CREN ON
//(bit 3) ADDEN, Async 8bit dont care
#define _ADDEN OFF

//
//                          BAUDCTL
//

//(bit3) ON if 16-bit baud rate (SPBRGH and SPBRG)
#define _BRG16 OFF

static const u8 _SPBRG = 25;




#endif	/* SERIALCOM_H */


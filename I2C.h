/*
 * File:   I2C.h
 * Author: Juan
 *
 * Created on September 20, 2015, 3:14 PM
 */

#include "types.h"
#include "IO_Port.h"

#ifndef I2C_H
#define	I2C_H

//Local flags
u8 f_SSPReady;
u8* ssppointer;
u8 f_slave1;
u8 f_slave2;
u8 tempi2c;

extern u16 I2C_value[];
//extern u8 value[];
void I2C_InitAsMaster (void);
void I2C_SendByte(u8,u8,u8);
void I2C_Send2Bytes(u8 slave, u16* pointer);
u8 I2C_ReadIMU(u8, u8);


#endif	/* I2C_H */

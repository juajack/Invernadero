/* 
 * File:   SerialCOM.c
 * Author: Juan
 *
 * Created on November 17, 2015, 3:57 PM
 */

#include "SerialCOM.h"

extern u8 f_SSPReady;
extern u8 f_Send2Bytes;
extern u8 f_SendByte;





/*------------------------------------------------------------------------------
  \brief        Serial communication initialization, please refere to
 *              SerialCOM.h to change te values
  \param      void
  \return     None
  \warning    None
------------------------------------------------------------------------------*/
void SerialInit (void)
{
    //TXSTA
    CSRC    =   _CSRC;
    TX9     =   _TX9;
    TXEN    =   _TXEN;
    SYNC    =   _SYNC;
    SENDB   =   _SENDB;
    BRGH    =   _BRGH;

    //RCSTA
    SPEN    =   _SPEN;
    RX9     =   _RX9;
    SREN    =   _SREN;
    CREN    =   _CREN;
    ADDEN   =   _ADDEN;

    //BAUDCTL
    BRG16   =   _BRG16;

    //SPBRG
    SPBRG   =   _SPBRG;

}

/*------------------------------------------------------------------------------
  \brief        Reads the frame and substact the important data
  \param        the frame to be parsed
  \return       the command to be excetuted, in case of movement command,
  \warning      None
------------------------------------------------------------------------------*/


/*
u16* ReadFrame(u8* pointer){

    //static char value[2] = {0,0};
    if(f_frameready){
        f_frameready=0;
        //extern u16 value[2] = {0,0};
        pointer = &RecievedData[0];

        //MOVEMENT COMMAND
        if ((*pointer)==firstbyte[0])
        {
            
            value[0]=0;
            value[1]=0;
            pointer++;
            while(*pointer!=splitbyte)
            {
                *pointer++;
                firstvaluespaces++;
            }
            pointer-=firstvaluespaces;
            u16 temp1=1;
            while(firstvaluespaces!=0)
            {
                for(u8 i = 0; i<firstvaluespaces-1;i++)
                {
                    temp1*=10;
                }
                value[0]+=(*pointer-0x30)*temp1;
                firstvaluespaces--;
                pointer++;
                temp1=1;
            }
            pointer++;
            while(*pointer!=endbyte)
            {
                *pointer++;
                secondvaluespaces++;
            }
            pointer-=secondvaluespaces;
            u16 temp2=1;
            while(secondvaluespaces!=0)
            {
                for(u8 i = 0; i<secondvaluespaces-1;i++)
                {
                    temp2*=10;
                }
                value[1]+=(*pointer-0x30)*temp2;
                secondvaluespaces--;
                pointer++;
                temp2=1;
            }
            for(counter = 0;counter<=14;counter++)
            {
                RecievedData[counter]='\0';
            }
            TXREG='#';
            while(TRMT==0);
            TXREG='\n';

            f_slave1=1;
            f_slave2=1;
        }

        //STOP COMMAND
        else if (*pointer==firstbyte[1])
        {
            for(counter = 0;counter<=14;counter++)
            {
                RecievedData[counter]='\0';
            }

            TXREG='%';
            while(TRMT==0);
            TXREG='\n';
            
            value[0]=firstbyte[1];
            value[1]=firstbyte[1];
            f_slave1=1;
            f_slave2=1;
        }
        //Send slaves to zero position
        else if (*pointer==firstbyte[2])
        {
            for(counter = 0;counter<=14;counter++)
            {
                RecievedData[counter]='\0';
            }

            TXREG='@';
            while(TRMT==0);
            TXREG='\n';
            value[0]=firstbyte[2];
            value[1]=firstbyte[2];
            f_slave1=1;
            f_slave2=1;
        }
        //not a valid command
        else {
            for(counter = 0;counter<=14;counter++)
            {
                RecievedData[counter]='\0';
            }

            value[0]=0x21;
        }
    }
    return value;

}
*/



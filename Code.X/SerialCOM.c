/* 
 * File:   SerialCOM.c
 * Author: Juan
 *
 * Created on November 17, 2015, 3:57 PM
 */

#include "SerialCOM.h"
#include "LedDriver.h"

extern u8 f_SSPReady;
extern u8 f_Send2Bytes;
extern u8 f_SendByte;

extern u8 TimerUser;

#define FanPort A
#define FanPin  3

extern u16 lightperday;
extern u8 actualtemperature;
extern u8 actualhumidity;
extern u8 optimaltemperature;
extern u8 optimalhumidity;





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



void ReadFrame(u8* pointer){

    //static char value[2] = {0,0};
    if(f_frameready){
        f_frameready=0;
        //extern u16 value[2] = {0,0};
        pointer = &RecievedData[0];

        if ((*pointer)==firstbyte[0])       //#, encender
        {
            pointer++;
            if(*pointer==light){
                TurnOnLights();
            }
            if(*pointer==fan){
                IO_SET(FanPort,FanPin);
            }
            TimerUser=30;
        }
        else if (*pointer==firstbyte[1]){       //&, nuevos valores para temp y hum
            pointer++;
            if(*pointer=='H'){
                pointer++;
                optimalhumidity= *pointer;                
            }
            else if (*pointer=='T'){
                pointer++;
                optimalhumidity = *pointer;
            }
        }
        else if (*pointer==firstbyte[2])    //!, nueva luz diaria necesaria
        {
            pointer++;
            lightperday = (*pointer-0x30)*1000;
            pointer++;
            lightperday += (*pointer-0x30)*100;
            pointer++;
            lightperday += (*pointer-0x30)*10;
            pointer++;
            lightperday += (*pointer-0x30);
        }
        else if (*pointer==firstbyte[3])    //@, peticion de datos
        {
            pointer++;
            if(*pointer=='H'){
                TXREG=actualhumidity;
            }
            if(*pointer=='T'){
                TXREG=actualtemperature;
            } 
        }    
        else if (*pointer==firstbyte[4])    //%, apagar
        {
            pointer++;
            if(*pointer=='F'){
                IO_CLR(FanPort,FanPin);
            }
        }
        
        
        //al final, limpiar la variable
        for(counter = 0;counter<=14;counter++)
            {
                RecievedData[counter]='\0';
            }
    }
}




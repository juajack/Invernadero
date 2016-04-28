/*
 * File:   Main.c
 * Author: Juan Jackson
 *
 * Created on March 25, 2016, 9:21 PM
 */

/*      INCLUDES        */
#include "DHT11Driver.h"
#include "ConfigBits.h"
#include "Interrupts.h"
#include "IO_Port.h"
#include "SerialCOM.h"
#include "Timer_0.h"
#include "types.h"
#include "PWM.h"
#include "LedDriver.h"

//Coment

/*      Constantst      */
//Valores de iluminación a prueba 
u8 MaxLightValue = 1000;
u8 MinLightValue = 200;
#define FanPort A
#define FanPin 0

/*      Variables       */
//Local
DHT_StateMachine1 state = _Idle;
u8 TimerCounter=0;
u8 dummy;

//Globales
u16 LightValue=0;

//Extern

//Banderas globales
bit Light_f;        //Flag to know if the lights are on
bit Door_f;         //Flag to know is the Door open
bit Night_f;        //Flag to know if the sun light is down
bit f_SSPReady;     //Flag to know if the frame is complete
bit f_Send2Bytes;
bit f_SendByte;     //Flag to know if there is a message to be sent

/*      ISR             */
void interrupt high_priority HighISR (void){
    
    /*
    if(INT2IF){
        INT2IF=0;
        if(Light_f){
            IO_CLR(FanPort,FanPin);
            TurnOffLights();
            INTEDG2=ON;
            Light_f=0;
        }
        else{
            IO_SET(FanPort,FanPin);
            TurnOnLights();
            INTEDG2=OFF;
            Light_f=1;
        }
    }*/
    
    if(ADIF){
        ADIF=0;
        if((ADRES>=MaxLightValue) && (Light_f==1)){
            //Do something
            dummy++;
        }
        else if ((ADRES>=MaxLightValue) && (Light_f == 0)){
            //Do something
            dummy++;
        }
        else if ((ADRES <= MinLightValue) && (Light_f ==1)){
            //Do something
            dummy++;
        }
        else if ((ADRES <= MinLightValue) && (Light_f ==1)){
            //Do something
            dummy++;
        }
        else{
            dummy++;
            //Nothing to do
        }
    }

    
    if(TMR0IF){
        //Configurar el TMR0 para interrupcion cada minuto
        TMR0IF=0;
        if(TimerCounter<2) TimerCounter++;        //Valor Real 239, 
        else{
            TMR0_STATE_OFF;
            DHT_StateMachine[_FirstStateRequest]();
            TimerCounter=0;
        }
        TMR0_WRITE_HIGH(0xF0);
        TMR0_WRITE_LOW(0xBD);
        TMR0_STATE_ON;
    }
    
    if (CCP1IF){
        CCP1IF=0;
        (*DHT_StateMachine[state])();
    }
}


/*      MAIN        */
void main(void) {
    //4MHz
    //Pic Config
    OSCCON=0b01101100;
    Interrupt_Init();
    
    //ConfigTimer
    TMR0_INIT();
    TMR0ON = 0;
    TMR0_WRITE_HIGH(0xF0);
    TMR0_WRITE_LOW(0xBD);
    TMR0_STATE_ON;
    
    //Config DHT
    InitDHT11Driver();
    
    //Config Fan
    IO_CONFIG_OUT(FanPort,FanPin);
    
    while(1){
        
    }
    
}


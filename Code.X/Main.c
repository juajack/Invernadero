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
//u8 MaxLightValue = 70;
u8 MinLightValue = 80;
#define FanPort     A
#define FanPin      3
#define DoorPort    B
#define DoorPin     3

/*      Variables       */
//Local
DHT_StateMachine1 state = _Idle;
u8 TimerCounter=0;
u8 TimerUser=0;

//Globales
u16 LightValue=0;
u8 serialcount;
u8 RecievedData[15];
u8 actualtemperature;
u8 actualhumidity;
u8 optimaltemperature;
u8 optimalhumidity;


u16 lightperday = 1435;    //needed light per day
u16 lightcounter = 0;   //how much light have the plants received?
u16 totaldaytime = 1440; //a day have 1440 minutes
u16 actualtime = 0;     
u16 timetostartlight;

//Extern
extern u8 f_frameready;

//Banderas globales
bit Light_f;        //Flag to know if the lights are on
bit Door_f;         //Flag to know is the Door open
bit Night_f;        //Flag to know if the sun light is down
bit f_SSPReady;     //Flag to know if the frame is complete
bit f_Send2Bytes;
bit f_SendByte;     //Flag to know if there is a message to be sent
bit lightstate;

//hace falta una bandera de debería estar encendio el ventilador? Debería estar
// encendido las luces?


/*      ISR             */
void interrupt high_priority HighISR (void){
    
    //Pin Interrupt
    if(INT2IF){
        INT2IF=0;
        if(Door_f){        //Pregunta por el estado pasado     
            INTEDG2=ON;
            Door_f=0;
        }
        else{            
            TurnOnLights();
            lightstate=1;
            INTEDG2=OFF;
            Door_f=1;
        }
    }
    
    //Serial
    if((RCIF && RCIE))
    {
        RCIF=0;
        if(RCREG!='\n' && RCREG!=0xea)
        {
        RecievedData[serialcount]=RCREG;
        serialcount++;
        }
        if(RCREG==0x24) //$
        {
            serialcount=0;
            f_frameready=1;
        }
    }
    
    //ADC
    if(ADIF){
        ADIF=0;
        if(ADRES<=MinLightValue){
            lightcounter++;
            Light_f=0;
        }
        if(ADRES>MinLightValue ){
            if(lightcounter<=lightperday && actualtime>timetostartlight ){
                Light_f=1;
                lightcounter++;
            }
            else{
                Light_f=0;
            }
        }
        
    }
    //Timer 0
    if(TMR0IF){
        //Interrupt every 2 secs
        TMR0IF=0;
        TimerCounter++;
        if (TimerCounter==1) TXREG='%';
        if (TimerCounter==2) TXREG='F';
        if (TimerCounter==3) TXREG='$';
        
        if (TimerUser!=0)TimerUser--;
        if (TimerCounter==3){      //1 min
            TimerCounter=0;
            actualtime++;
            //RUN ADC
            ADCON0bits.GO=1;
            //RUN DHT
            DHT_StateMachine[_FirstStateRequest]();
            if (actualtime==totaldaytime) {
                //Start Again all the values
                actualtime=0;
                lightcounter=0;
                //Calculate the light needed
                timetostartlight=totaldaytime-lightperday;
            }            
        }
        TMR0_STATE_OFF;
        TMR0_WRITE_HIGH(0xB);
        TMR0_WRITE_LOW(0xD0);
        TMR0_STATE_ON;
    }
    
    //CCP-----------------CHECKED
    if (CCP1IF){
        CCP1IF=0;
        DHT_StateMachine[state]();
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
    TMR0_WRITE_HIGH(0xB);
    TMR0_WRITE_LOW(0xD0);
    TMR0_STATE_ON;
    
    //Config ADC
    ADCON0=0b00001001;
    ADCON1=0b00001100;
    ADCON2bits.ADFM=1;
    
    //Config DHT
    InitDHT11Driver();
    
    //Config Fan
    IO_CONFIG_OUT(FanPort,FanPin);
    IO_SET(FanPort,FanPin);
    
    TurnOffLights();
    lightstate=1;
    timetostartlight=totaldaytime-lightperday;
    
    //Serial Init
    SerialInit();
            
    while(1){  
        //Ask if the user activated something
        if(TimerUser==0){
            //The pic has the control over the Fan and ilumination system
            if(actualtime>timetostartlight){
                if(Light_f==0){
                    TurnOffLights();
                }
                else if (Light_f==1){
                    TurnOnLights();
                }    
            }
            
        }
        if(f_frameready){
            ReadFrame(RecievedData);
        }       
    }
    
}


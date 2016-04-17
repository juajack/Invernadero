#include "DHT11Driver.h"

extern DHT_StateMachine1 state;

u8 IntegerHumidity;
u8 DecimalHumidity;
u8 IntegerTemperature;
u8 DecimalTemperature;

u16 times[40];
u8 time;

u16 lasttime;

u8 bitcount = 0;
u8 bytecount = 0;
u16 counts=0;

void Idle (void){
    
}
void FirstStateRequest(void){
    //Enable CCP1 Interrupt
    CCP1IE=ON;
    //Activate CCP1 as 1000 condition
    //Start Pin on LOW and on Capture, toggle the pin
    CCP1CON=0x08;
    //Configure compare to 18000 counts (18ms)
    TMR1H=0;
    TMR1L=0;
    
    counts=TMR1+65534;
    T3CON=0b10100000;
    T1CON=0b11001000;
    //Configure Pin as output
    IO_CONFIG_OUT(Sensorport,Sensorpin);
    
    //Load the values in the registers
    CCPR1H=counts>>8;
    CCPR1L=(u8)counts;
    
    T1CON++;
    state = _SecondStateRequest;
}
void SecondStateRequest(void){
    CCP1CON=0x04;           //Capture every Falling Flank
    
    IO_CONFIG_IN(Sensorport,Sensorpin); //Configure pin an input to read the incoming data
    state = _DHTSignalResponse;
}

void DHTSignalResponse(void){
    T1CON--;
    TMR1H=0;
    TMR1L=0;
    CCPR1=0;
    T1CON++;
    
    lasttime=CCPR1;
    
    state=_RecievingData;
    
}
void RecievingData(void){
    
    times[bitcount]=CCPR1-lasttime;
    lasttime=CCPR1;
    bitcount++;
    /*
    if(bitcount>=0 && bitcount<=7){
        
    }
    else if(bitcount>=8 && bitcount <=15){
        
    }
    else if(bitcount>=16 && bitcount<=23){
        
    }
    else if(bitcount>=24 && bitcount<=31){
        
    }
    else if(bitcount>=32 && bitcount<=39){
        
    }
    else{
        while(1);
    }
    
    */
    
    if(bitcount==40){
        //after the reception is complete:
        //Turn off interruptions of CCP1 and timer1
        T1CON--;
        CCP1IE=0;
        //Config pin as output
        IO_CONFIG_OUT(Sensorport,Sensorpin);
        //Force CCP1 Pin to High
        IO_SET(Sensorport,Sensorpin);
        bitcount=0;
        state = _Idle;
    }
    
    
}
void InitDHT11Driver(){
    IO_CONFIG_OUT(Sensorport,Sensorpin);
    IO_SET(Sensorport,Sensorpin);
    ConfigureTimer1();
}




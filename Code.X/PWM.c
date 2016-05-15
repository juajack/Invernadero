/*
 * File:   PWM.c
 * Author: Juan Jackson
 *
 * Created on March 29, 2016, 6:03 PM
 */


#include "PWM.h"
u16 MSb;
u16 LSb;
bit PWM;

u16 PWMValue;

//Based on a 8MHz Fosc
void StartPWM(){
    CCP2CON=0x0C;       //0b1100;
    T1OSCEN=ON;
}

void StopPWM(){
    CCP2CON=0x00;
    T1OSCEN=OFF;
    IO_CLR(PWMport,PWMpin);
}

void SetPeriod(){
    //Read the section 15.4 Equation 15-1 from the PIC18 Datasheet
    PR2=200; 
}

void SetDutyCycle(u8 dutycycle){
    PWMValue=((dutycycle)*470)/100;
    LSb=PWMValue&0x03;
    MSb=PWMValue>>2;
    //Assigne values
    CCPR2L=MSb;
    CCP2CON=CCP2CON|(LSb<<4);

    
}

void SetPWM(u8 dutycycle){
    T2CON=0x00;
    SetPeriod();
    SetDutyCycle(dutycycle);
    IO_CONFIG_OUT(PWMport,PWMpin);
    T2CON=0b110;
}



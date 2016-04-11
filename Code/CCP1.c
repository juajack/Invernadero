
#include "CCP1.h"

u8 mask;

void ConfigureTimer1(void){
    T1CONbits.RD16=1;   //16 bits operation
    T1RUN=ON;            //Device clock derivated from Timer 1
    T1OSCEN=ON;          //Timer1 is enabled
    TMR1CS=OFF;         //Timer 1 source is internal clock
    TMR1ON=OFF;         //Timer 1 is off           
    
    mask = T1CON & 0xCF;
    if      (prescaler == 8) T1CON = mask | 0x30;
    else if (prescaler == 4) T1CON = mask | 0x20;
    else if (prescaler == 2) T1CON = mask | 0x10;
    else                     T1CON = mask;
    
}

#include "LedDriver.h"

bit lightstate_f;

void TurnOffLights (void){
    if(lightstate_f){
        StopPWM();
        lightstate_f=0;
    }
}

void TurnOnLights(){
    if(!lightstate_f){
        SetPWM(50);
        StartPWM();
        lightstate_f=1;
    }
}


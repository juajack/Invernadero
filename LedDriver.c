#include "LedDriver.h"

void TurnOffLights (void){
    StopPWM();
}

void TurnOnLights(){
    SetPWM(50);
    StartPWM();
}


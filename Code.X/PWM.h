/*
 * 
 * 
 * 
 * Tipo de capa: HAL
 */



#include <xc.h> // include processor files - each processor file is guarded. 
#include "IO_Port.h"
//Based on a 8 MHz Fosc

//The PWM module use CCP2 and this port can be multiplexed
//RB3 or RC1
#define PWMpin  3
#define PWMport B




void StartPWM();

void StopPWM();

void SetPeriod();

void SetDutyCycle(u8);

//This function configure the PWM
//This function use SetDutyCycle and SetPeriod
void SetPWM(u8);

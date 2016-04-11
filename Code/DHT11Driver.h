/*
 * Autor: Juan Jackson
 *
 * Fecha: 31 de marzo del 2016
 *  
 * Descripción: Esta capa contendrá las funciones que se necesitarán para establecer
 * la comunicación con el sensor de humedad/Temperatura DHT11
 *
 *
 * Módulos relacionados: CCPx, TRM3/TMR1
 * 
 * Tipo de capa: HIL
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include "IO_Port.h"
#include "CCP1.h"

#define Sensorport B
#define Sensorpin  3

void Idle(void);
void FirstStateRequest(void);
void SecondStateRequest(void);
void DHTSignalResponse();
void RecievingData(void);

void InitDHT11Driver();

void (*DHT_StateMachine[])(void)={
    Idle,\
    FirstStateRequest,\
    SecondStateRequest,\
    DHTSignalResponse,\
    RecievingData
};




#endif	/* XC_HEADER_TEMPLATE_H */


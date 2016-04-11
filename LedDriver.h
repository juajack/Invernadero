/*
 * Autor: Juan Jackson
 *
 * Fecha: 31 de marzo del 2016
 *  
 * Descripción: Esta capa tendrá las funciones necesarias para el control
 * de los Leds
 *
 * Dependencia: PWM.h
 * 
 * Tipo de capa: HIL
 */



// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>
#include "PWM.h"

void TurnOnLights();
void TurnOffLights();

#endif	/* XC_HEADER_TEMPLATE_H */


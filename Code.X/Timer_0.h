/* 
 * File:   Timer_0.h
 * Author: gmoctezuma
 *
 * Created on 10 de junio de 2015, 02:07 PM
 */

#ifndef TIMER_0_H
#define	TIMER_0_H

/*----------------------------INCLUDES----------------------------------------*/
#include "types.h"

/*-----------------------------DEFINES----------------------------------------*/
#define TMR0_ON     1 //1 = Enables TMR0
#define T0_8BIT     16 //Config TMR0 as 8 or 16 bit Timer
#define T0_CS       0 //0=Internal Clock source, 1 = Transition on T0CLK Pin
#define T0_SE       0 //1= increment on positive edge, 0 = increment on negative edge
#define PSA_AS      0 //0=Prescaler asigned, 1 = Prescaler is not asigned
#define PRESCALER   32 //Select prescaler to 2,4,8,16,32,64,128,256

#define TMR0_STATE_ON   TMR0ON = 1
#define TMR0_STATE_OFF  TMR0ON = 0




/*-------------------------CONDITIONS-----------------------------------------*/
#if (T0_8BIT!=8 && T0_8BIT!=16)
#error "TMR0.h. Not valid Timer";
#endif


#if (PRESCALER!=2&&PRESCALER!=4&&PRESCALER!=8&&PRESCALER!=16&&PRESCALER!=32&&PRESCALER!=64&&PRESCALER!=128&&PRESCALER!=256)
#error "TMR0.h. Not valid Prescale";
#endif

/*-----------------------INITIALITATION FUNTION-------------------------------*/

void TMR0_INIT (void);

/*------------------WRITE FUNCTIONS-------------------------------------------*/

void TMR0_WRITE (u16 value);
void TMR0_WRITE_HIGH (u8 valorHigh);
void TMR0_WRITE_LOW (u8 valorLow);

/*------------------READ FUNCTIONS--------------------------------------------*/

#define TMR0_READ_HIGH()    (TMR0H)

#define TMR0_READ_LOW()     (TMR0L)

#endif	/* TIMER_0_H */


/* 
 * File:   Interrupts.h
 * Author: gmoctezuma
 *
 * Created on 10 de junio de 2015, 12:27 PM
 */

#ifndef INTERRUPTS_H
#define	INTERRUPTS_H

#include "types.h"


/*-- Defines --*/

/*----------------------------------------------------------------------------*/

                         //ON=Enable   OFF=disable
//INTCON1
#define G_IE        ON       //Global Interrupt enable
#define PE_IE       OFF      //Peripheral Interrupt Enable bit
#define T0_IE       ON       //Timer0 interrupt enable
#define INT0_IE     OFF      //External interrupt 0 enable
#define RB_IE       OFF      //RB port change interrupt enable
void INIT_INTCON(void);

//INTCON2
#define nRB_PULLUP  OFF       //PORTB pull up enable
#define INT0_EDGE   OFF       //External interrupt 0 edge select(1=rising)
#define INT1_EDGE   OFF       //External interrupt 1 edge select(1=rising)
#define INT2_EDGE   ON      //External interrupt 2 edge select(1=rising)
#define INT3_EDGE   OFF       //External interrupt 3 edge select(1=rising)
#define T0_IP       ON       //Timer 0 interrupt priority(1=high)
#define INT3_IP     OFF       //External interrupt 3 priority(1=high)
#define RB_IP       OFF       ////RB port change interrupt priority(1=high)
void INIT_INTCON2(void);

//INTCON3
#define INT2_IP     ON       //External interrupt 2 priority(1=high)
#define INT1_IP     OFF       //External interrupt 1 priority(1=high)
#define INT3_IE     OFF      //External interrupt 3 enable
#define INT2_IE     ON       //External interrupt 2 enable
#define INT1_IE     OFF       //External interrupt 1 enable
void INIT_INTCON3(void);

//RCON
#define IP_EN      ON        //Interrupt Priority Enable bit
void INIT_RCON(void);

//PIE1
#define AD_IE      ON        //A/D Converter Interrupt Enable bit
#define RC_IE      OFF        //EUSART Receive Interrupt Enable bit
#define TX_IE      OFF        //EUSART Transmit Interrupt Enable bit
#define SSP_IE     OFF       //Master Synchronous Serial Port Interrupt Enable bit
#define CCP1_IE    OFF        //CCP1 Interrupt Enable bit
#define TMR2_IE    OFF        //TMR2 to PR2 Match Interrupt Enable bit
#define TMR1_IE    OFF        //TMR1 Overflow Interrupt Enable bit
void INIT_PIE1(void);

//PIE2
#define OSCF_IE    OFF      //Oscillator Fail Interrupt Enable bit
#define CM_IE      OFF      //Comparator Interrupt Enable bit
#define USB_IE     OFF      //USB Interrupt Enable bit
#define EE_IE      OFF      //Data EEPROM/Flash Write Operation Interrupt Enable bit
#define HLVD_IE    OFF      //High/Low-Voltage Detect Interrupt Enable bit
#define BCL_IE     OFF      //Bus Collision Interrupt Enable bit
#define TMR3_IE    OFF      //TMR3 Overflow Interrupt Enable bit
#define CCP2_IE    ON      //CCP2 Interrupt Enable bit
void INIT_PIE2(void);

//IPR1
#define AD_IP      ON      //A/D Converter Interrupt Priority bit
#define RC_IP      OFF      //EUSART Receive Interrupt Priority bit
#define TX_IP      OFF      //EUSART Transmit Interrupt Priority bit
#define SSP_IP     OFF     //Master Synchronous Serial Port Interrupt Priorrity bit
#define CCP1_IP    ON      //CCP1 Interrupt Priority bit
#define TMR2_IP    OFF      //TMR2 to PR2 Match Interrupt Priority bit
#define TMR1_IP    OFF      //TMR1 Overflow Interrupt Priority bit
void INIT_IPR1(void);

//IPR2
#define OSCF_IP    OFF      //Oscillator Fail Interrupt Priority bit
#define CM_IP      OFF      //Comparator Interrupt Priority bit
#define USB_IP     OFF      //USB Interrupt Priority bit
#define EE_IP      OFF      //Data EEPROM/Flash Write Operation Interrupt Priority bit
#define HLVD_IP    OFF      //High/Low-Voltage Detect Interrupt Priority bit
#define BCL_IP     OFF      //Bus Collision Interrupt Priority bit
#define TMR3_IP    OFF      //TMR3 Overflow Interrupt Priority bit
#define CCP2_IP    OFF      //CCP2 Interrupt Priority bit
void INIT_IPR2(void);

void Interrupt_Init(void);

#endif	/* INTERRUPTS_H */


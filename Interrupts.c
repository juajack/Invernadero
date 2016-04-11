#include "Interrupts.h"

/*------------------------------------------------------------------------------
  \brief      Iniaciliza un pin del uC a la vez
  \param      ePort: Puerto donde se encuentra el pin (IoPorts_PORTx)
  \param      u8Pin:  Numero de pin (de 0 to 7)
  \param      bDirection: Modo entrada (IoPorts_INPUT) o salida (IoPorts_OUTPUT)
  \return     None
  \warning    None
------------------------------------------------------------------------------*/
void INIT_INTCON(void)
{
    INTCONbits.GIE = G_IE;
    INTCONbits.PEIE = PE_IE;
    INTCONbits.TMR0IE = T0_IE;
    INTCONbits.INT0E=INT0_IE;//External interrupt 0 enable
    INTCONbits.RBIE=RB_IE;//RB port change interrupt enable
}

/*------------------------------------------------------------------------------
  \brief      Iniaciliza un pin del uC a la vez
  \param      ePort: Puerto donde se encuentra el pin (IoPorts_PORTx)
  \param      u8Pin:  Numero de pin (de 0 to 7)
  \param      bDirection: Modo entrada (IoPorts_INPUT) o salida (IoPorts_OUTPUT)
  \return     None
  \warning    None
------------------------------------------------------------------------------*/
void INIT_INTCON2(void){
    INTCON2bits.nRBPU=nRB_PULLUP;//PORTB pull up enable
    INTCON2bits.INTEDG0=INT0_EDGE;//External interrupt 0 edge select(1=rising)
    INTCON2bits.INTEDG1=INT1_EDGE;//External interrupt 1 edge select(1=rising)
    INTCON2bits.INTEDG2=INT2_EDGE;//External interrupt 2 edge select(1=rising)
    //INTCON2bits.INTEDG3=INT3_EDGE;//External interrupt 3 edge select(1=rising)
    INTCON2bits.T0IP=T0_IP;//Timer 0 interrupt priority(1=high)
    //INTCON2bits.INT3IP=INT3_IP;//External interrupt 3 priority(1=high)
    INTCON2bits.RBIP=RB_IP;//RB port change interrupt priority(1=high)
}

void INIT_INTCON3(void){
    INTCON3bits.INT2IP=INT2_IP;//External interrupt 2 priority(1=high)
    INTCON3bits.INT1IP=INT1_IP;//External interrupt 1 priority(1=high)
    //INTCON3bits.INT3IE=INT3_IE;//External interrupt 3 enable
    INTCON3bits.INT2IE=INT2_IE;//External interrupt 2 enable
    INTCON3bits.INT1IE=INT1_IE;//External interrupt 1 enable
}

void INIT_RCON(void)
{
    RCONbits.IPEN = IP_EN;
}

void INIT_PIE1(void)
{
    PIE1bits.ADIE = AD_IE;
    PIE1bits.RCIE = RC_IE;
    PIE1bits.TXIE = TX_IE;
    PIE1bits.SSPIE = SSP_IE;
    PIE1bits.CCP1IE = CCP1_IE;
    PIE1bits.TMR2IE = TMR2_IE;
    PIE1bits.TMR1IE = TMR1_IE;
}

void INIT_PIE2(void)
{
    PIE2bits.OSCFIE=OSCF_IE;//Oscillator Fail Interrupt Enable bit
    PIE2bits.CMIE=CM_IE;//Comparator Interrupt Enable bit
    PIE2bits.EEIE=EE_IE;//Data EEPROM/Flash Write Operation Interrupt Enable bit
    PIE2bits.HLVDIE=HLVD_IE;//High/Low-Voltage Detect Interrupt Enable bit
    PIE2bits.BCLIE=BCL_IE;//Bus Collision Interrupt Enable bit
    PIE2bits.TMR3IE=TMR3_IE;//TMR3 Overflow Interrupt Enable bit
    //PIE2bits.CCP2IE=CCP2_IE;//CCP2 Interrupt Enable bit
}

void INIT_IPR1(void){
    IPR1bits.ADIP=AD_IP;//A/D Converter Interrupt Priority bit
    IPR1bits.RCIP=RC_IP;//EUSART Receive Interrupt Priority bit
    IPR1bits.TXIP=TX_IP;//EUSART Transmit Interrupt Priority bit
    IPR1bits.SSPIP=SSP_IP;//Master Synchronous Serial Port Interrupt Priorrity bit
    IPR1bits.CCP1IP=CCP1_IP;//CCP1 Interrupt Priority bit
    IPR1bits.TMR2IP=TMR2_IP;//TMR2 to PR2 Match Interrupt Priority bit
    IPR1bits.TMR1IP=TMR1_IP;//TMR1 Overflow Interrupt Priority bit
}

void INIT_IPR2(void){
    IPR2bits.OSCFIP=OSCF_IP;//Oscillator Fail Interrupt Priority bit
    IPR2bits.CMIP=CM_IP;//Comparator Interrupt Priority bit
    IPR2bits.EEIP=EE_IP;//Data EEPROM/Flash Write Operation Interrupt Priority bit
    IPR2bits.HLVDIP=HLVD_IP;//High/Low-Voltage Detect Interrupt Priority bit
    IPR2bits.BCLIP=BCL_IP;//Bus Collision Interrupt Priority bit
    IPR2bits.TMR3IP=TMR3_IP;//TMR3 Overflow Interrupt Priority bit
    //IPR2bits.CCP2IP=CCP2_IP;//CCP2 Interrupt Priority bit
}

void Interrupt_Init(void){
    INIT_RCON();
    INIT_INTCON();
    INIT_INTCON2();
    INIT_INTCON3();
    INIT_PIE1();
    INIT_PIE2();
    INIT_IPR1();
    INIT_IPR2();
}

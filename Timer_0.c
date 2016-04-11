/*! ***************************************************************************
*
* @file:      TMR0.c
* @author(s):  Juan Jackson
*
* @brief (Theory of Operation)
*
*******************************************************************************/

/******************************************************************************/
/*********************              Includes             **********************/
/******************************************************************************/
#include "Timer_0.h"

/*------------------------------------------------------------------------------
  \brief      Iniaciliza un pin del uC a la vez
  \param      ePort: Puerto donde se encuentra el pin (IoPorts_PORTx)
  \param      u8Pin:  Numero de pin (de 0 to 7)
  \param      bDirection: Modo entrada (IoPorts_INPUT) o salida (IoPorts_OUTPUT)
  \return     None
  \warning    None
------------------------------------------------------------------------------*/
void TMR0_INIT (void)
{
    u8 T0PS;
    if (PRESCALER == 2){T0PS=0;}
    else if (PRESCALER == 4){T0PS=1;}
    else if (PRESCALER == 8){T0PS=2;}
    else if (PRESCALER == 16){T0PS=3;}
    else if (PRESCALER == 32){T0PS=4;}
    else if (PRESCALER == 64){T0PS=5;}
    else if (PRESCALER == 128){T0PS=6;}
    else  {T0PS=7;}

    u8 bits;
    if (T0_8BIT==8){bits=1;}
    else {bits=0;}

    T0CON=(TMR0_ON*128)+(bits*64)+(T0_CS*32)+(T0_SE*16)+(PSA_AS*8)+T0PS;

    TMR0=0x15;
    T0IF=0;
}

/*------------------------------------------------------------------------------
  \brief      Iniaciliza un pin del uC a la vez
  \param      ePort: Puerto donde se encuentra el pin (IoPorts_PORTx)
  \param      u8Pin:  Numero de pin (de 0 to 7)
  \param      bDirection: Modo entrada (IoPorts_INPUT) o salida (IoPorts_OUTPUT)
  \return     None
  \warning    None
------------------------------------------------------------------------------*/
void TMR0_WRITE (u16 value)
{
    TMR0=value;
}

/*------------------------------------------------------------------------------
  \brief      Iniaciliza un pin del uC a la vez
  \param      ePort: Puerto donde se encuentra el pin (IoPorts_PORTx)
  \param      u8Pin:  Numero de pin (de 0 to 7)
  \param      bDirection: Modo entrada (IoPorts_INPUT) o salida (IoPorts_OUTPUT)
  \return     None
  \warning    None
------------------------------------------------------------------------------*/
void TMR0_WRITE_HIGH (u8 valorHigh)
{
    TMR0H=valorHigh;
}

/*------------------------------------------------------------------------------
  \brief      Iniaciliza un pin del uC a la vez
  \param      ePort: Puerto donde se encuentra el pin (IoPorts_PORTx)
  \param      u8Pin:  Numero de pin (de 0 to 7)
  \param      bDirection: Modo entrada (IoPorts_INPUT) o salida (IoPorts_OUTPUT)
  \return     None
  \warning    None
------------------------------------------------------------------------------*/
void TMR0_WRITE_LOW (u8 valorLow)
{
    TMR0L=valorLow;
}

/*------------------------------------------------------------------------------
  "THE BEER-WARE LICENSE" (Revision 42):
  <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
  can do whatever you want with this stuff. If we meet some day, and you think
  this stuff is worth it, you can buy me a beer in return to Hotboards crew
  (Beer-ware license created by Poul-Henning Kamp)

  \file       IO_Ports.h
  \author     Elliot Sánchez
  \email      elsava32@hotmail.com
  \ver        1.0
  \date       Sept 17, 2014

  \brief     Low level driver for GPIOs.
 *
 * Header file for sushi rolling machine
 -----------------------------------------------------------------------------*/
#ifndef IO_PORT_H
#define IO_PORT_H


/*-- Includes --*/
#include "types.h"


/*-- Defines --*/
/*------------------------------------------------------------------------------
\def    IoPorts_INPUT/OUTPUT
\brief  Constants to define the direction for the pins
------------------------------------------------------------------------------*/
#define IO_DIR_OUT        0
#define IO_DIR_IN         1



/*-- Macros --*/
/*------------------------------------------------------------------------------
  \def        Macro
  \brief      Write a nice description for your macros
------------------------------------------------------------------------------*/
/* DO NOT MODIFY OR USE THESE *************************************************/
#define IO_READ_PORT_EXPANDED(port)         PORT##port                          /* Defines the port register name */


#define IO_WRITE_PORT_EXPANDED(port, val)   (LAT##port = val)                   /* Write "val" to the port-pin */


#define IO_PIN_DIR(port, pin)               TRIS##port##bits.TRIS##port ##pin   /* Defines the port-pin direction register name */


//#define IO_PIN(port, pin)                 LAT##port##bits.LAT##port## ##pin   /* Defines the port-pin register name */


#define IO_DIR(port)                        TRIS##port                          /* Defines the port direction register */
/******************************************************************************/

/* Macros to configure pin directin */
#define IO_CONFIG_DIR_EXPANDED(port,pin,dir)    (IO_PIN_DIR(port, pin) = dir)

#define IO_CONFIG_OUT(port, pin)                IO_CONFIG_DIR_EXPANDED(port, pin, IO_DIR_OUT) /* Sets port-pin as output */

#define IO_CONFIG_IN(port, pin)                 IO_CONFIG_DIR_EXPANDED(port, pin, IO_DIR_IN)  /* Sets port-pin as input */

#define IO_CONFIG_PORT_OUT(port, startPin, size)    (IO_DIR(port) = IO_DIR(port) & (~((0xFF >> (8-size) ) << startPin )) )


/* Macros to output data */
#define IO_WRITE_PIN(port, pin, val)    (LAT##port##pin=val)//(LAT##port##bits.LAT##port##pin = val)      /* Write "val" to the port-pin */
#define IO_WRITE_PORT(port, val)        IO_WRITE_PORT_EXPANDED(port, val)          /* Write "val" to the port-pin */
#define IO_SET(port, pin)               IO_WRITE_PIN(port, pin, 1U)    /* Write a 1 to the port-pin */
#define IO_CLR(port, pin)               IO_WRITE_PIN(port, pin, 0U)    /* Write a 0 to the port-pin */

/* Marcos to input data */
#define IO_READ_PORT(port)              IO_READ_PORT_EXPANDED(port)                   /* Reads port*/
#define IO_READ_PIN(port, pin)          PORT##port##bits.R##port##pin
#define IO_IS_SET(port, pin)            (0u != IO_READ_PIN(port, pin))  /* Test if pin is set */
#define IO_IS_CLR(port, pin)            (0u == IO_READ_PIN(port, pin))  /* Test if pin is cleared */


/*-- Functions --*/
/*------------------------------------------------------------------------------
  \brief      Iniaciliza un pin del uC a la vez
  \param      ePort: Puerto donde se encuentra el pin (IoPorts_PORTx)
  \param      u8Pin:  Numero de pin (de 0 to 7)
  \param      bDirection: Modo entrada (IoPorts_INPUT) o salida (IoPorts_OUTPUT)
  \return     None
  \warning    None
------------------------------------------------------------------------------*/
//void IoPorts_PinDirection(_eIoPorts_PORT ePort, u8 u8Pin, _bool bDirection);

#endif


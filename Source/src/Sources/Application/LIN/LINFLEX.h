/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        LINFLEX.h
* Instance:         RPL_1
* %version:         1.0
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Tuesday, August 11, 2015
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 11/08/2015  | LINFLEX driver                | Misael AD        */
/*============================================================================*/

#ifndef LINFLEX_H                               /* To avoid double inclusion */
#define LINFLEX_H

/* Includes */
/* -------- */
#include "typedefs.h"
#include "LIN_signals.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */
void InitLinFlex0Slave(T_UWORD baud);
void LINFlex_0_RX_ISR(void);
void LINFlex_0_TX_ISR(void);
void IntcInterruptLINFLEXHandlers(void);

/* Functions prototypes */


/* Functions macros */


/* Exported defines */


#endif



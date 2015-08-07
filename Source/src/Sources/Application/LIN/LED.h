/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        LED.h
* Instance:         RPL_1
* %version:         1.1
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
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
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Mr. Template     */
/*  1.1      | 13/07/2015  |H file template implementation | Misael AD        */
/*============================================================================*/

#ifndef LED_H                               /* To avoid double inclusion */
#define LED_H

/* Includes */
/* -------- */
#include "typedefs.h"

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
void LED_WindowLifter(int8_t position);
void LED_UP(void);
void LED_DOWN(void);
void LEDs_Off(void);

void LED_T(T_UWORD pin);

/* Functions prototypes */


/* Functions macros */

/* Exported defines */
	/* LED pins */
#define LED1 68
#define LED2 69
#define LED3 70
#define LED4 71

#endif


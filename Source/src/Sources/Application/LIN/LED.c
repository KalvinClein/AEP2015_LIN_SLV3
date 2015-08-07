/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         LED.c
* Instance:         RPL_1
* %version:         1.1
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the external LED control functions  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*  1.1      | 13/07/2015  |C file template implementation | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "LED.h"
#include "main.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */

#define LEDB SIU.GPDO[10].R
#define LEDG SIU.GPDO[11].R

	/* On-board LED states */
#define LED_ON  0
#define LED_OFF 1


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */


/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	LED_WindowLifter
 *  Description          :	Indicates window position using a
 *							10 LED bar.
 *  Parameters           :  [Input: position]
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void LED_WindowLifter(int8_t position)
{
	int8_t i;
	for(i=0; i<position; i++)	/*Turn on LEDs from 0 to actual position*/
	{
		SIU.GPDO[i].R = 1;
	}
	for(i=i; i<10; i++)		/*Turn off LEDs from position to fully closed*/
	{
		SIU.GPDO[i].R = 0;
	}
}

/**************************************************************
 *  Name                 :	LED_UP
 *  Description          :	Turns on moving UP LED
 *  Parameters           :	None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void LED_UP(void)
{
	LEDB = 1;
}

/**************************************************************
 *  Name                 :	LED_DOWN
 *  Description          :	Turns on moving DOWN LED
 *  Parameters           :	None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void LED_DOWN(void)
{
	LEDG = 1;
}

/**************************************************************
 *  Name                 :	LEDs_Off
 *  Description          :	Turns off movement indicating LEDS
 *  Parameters           :	None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void LEDs_Off(void)
{
	LEDB = 0;
	LEDG = 0;
	
	SIU.GPDO[LED1].R = LED_OFF;
	SIU.GPDO[LED2].R = LED_OFF;
	SIU.GPDO[LED3].R = LED_OFF;
	SIU.GPDO[LED4].R = LED_OFF;
}

void LED_T(T_UWORD pin)
{
	SIU.GPDO[pin].R ^= 1;
}

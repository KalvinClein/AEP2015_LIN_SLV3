/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         init.c
* Instance:         RPL_1
* %version:         1.2
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : C source init file                                           */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the initialization routines         */
/*                                                  						  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*  1.1      | 13/07/2015  |C file template implementation | Misael AD        */
/*  1.2      | 22/07/2015  |MISRA issues fixed			   | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "init.h"

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
#define Output (uint16_t)0x200	/*PCR_GPIO_OutputConfiguration*/
#define Input  (uint16_t)0x100	/*PCR_GPIO_InputConfiguration*/
#define Analog (uint16_t)0x2000	/*PCR_AnalogConfiguration*/

	/* Push buttons */
#define PortE0 SIU.PCR[64].R
#define PortE1 SIU.PCR[65].R 
#define PortE2 SIU.PCR[66].R 
#define PortE3 SIU.PCR[67].R

	/* LEDs */   
#define PortE4 SIU.PCR[68].R 
#define PortE5 SIU.PCR[69].R 
#define PortE6 SIU.PCR[70].R 
#define PortE7 SIU.PCR[71].R

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
 *  Name                 :	disableWatchdog
 *  Description          :	Disables the watchdog timer
 *  Parameters           :  None
 *  Return               :
 *  Critical/explanation :  No
 **************************************************************/
void init_disableWatchdog(void) 
{
  SWT.SR.R = 0x0000C520u;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000D928u; 
  SWT.CR.R = 0x8000010Au;     /* Clear watchdog enable (WEN) */
}

/**************************************************************
 *  Name                 :	init_OnBoardLEDs
 *  Description          :	Set on-board LED pins as outputs
 *  Parameters           :  None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void init_OnBoardLEDs(void)
{
  PortE4 = Output;	/*LED 1*/
  PortE5 = Output;	/*LED 2*/
  PortE6 = Output;	/*LED 3*/
  PortE7 = Output;	/*LED 4*/
}

/**************************************************************
 *  Name                 :	init_OnBoardPushButtons
 *  Description          :	Set on-board push-buttons as inputs
 *  Parameters           :	None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void init_OnBoardPushButtons(void)
{
  PortE0 = Input;	/*S1*/
  PortE1 = Input;	/*S2*/
  PortE2 = Input;	/*S3*/
  PortE3 = Input;	/*S4*/	
}

/**************************************************************
 *  Name                 :	init_LEDBar
 *  Description          :	Initialize Port A pins [0 to 11] as outputs
 *  Parameters           :	None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void init_LEDBar(void)
{
	uint8_t pin;
	for(pin=0 ; pin<12 ; pin++)
	{
		SIU.PCR[pin].R = Output;
	}
}


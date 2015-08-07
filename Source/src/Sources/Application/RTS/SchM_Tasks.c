/*============================================================================*/
/*                        Continental AEP 2015                                */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         scheduler_Tasks.c
* Instance:         RPL_1
* %version:         1.2
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file allocates the periodic tasks executed by the  */
/*                    scheduler				                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*  1.1      | 13/07/2015  |File added to complete 		   | Misael AD        */
/*        	 |   		   |scheduler structure 		   |  				  */
/*  1.2      | 16/07/2015  |Periodic tasks                 | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM_Tasks.h"
#include "SchM_Types.h"

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
#define	TICKS(ticks)	(ticks)

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

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	SchM_Task1p25ms
 *  Description          :	Task activated every 1.25ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task1p25ms(void)
{

}

/**************************************************************
 *  Name                 :	SchM_Task2p5ms
 *  Description          :	Task activated every 2.5ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task2p5ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task5ms
 *  Description          :	Task activated every 5ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task5ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task10ms
 *  Description          :	Task activated every 10ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task10ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task20ms
 *  Description          :	Task activated every 20ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task20ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task40ms
 *  Description          :	Task activated every 40ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task40ms(void)
{
	
}

/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        scheduler_Tasks.h
* Instance:         RPL_1
* %version:         1.2
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
/*  1.1      | 13/07/2015  |File added to complete 		   | Misael AD        */
/*        	 |   		   |scheduler structure 		   |  				  */
/*  1.2      | 16/07/2015  |Periodic tasks                 | Misael AD        */
/*============================================================================*/

#ifndef SCHEDULER_TASKS_H                               /* To avoid double inclusion */
#define SCHEDULER_TASKS_H

/* Includes */
/* -------- */


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
void SchM_Task1p25ms(void);
void SchM_Task2p5ms(void);
void SchM_Task5ms(void);
void SchM_Task10ms(void);
void SchM_Task20ms(void);
void SchM_Task40ms(void);

/* Functions prototypes */


/* Functions macros */


/* Exported defines */


#endif



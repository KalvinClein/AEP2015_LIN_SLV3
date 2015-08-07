/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         scheduler_Cfg.c
* Instance:         RPL_1
* %version:         1.3
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : C source scheduler_Cfg file                                  */
/*============================================================================*/
/* FUNCTION COMMENT : This file provides the task configuration table		  */
/*                                                   						  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*  1.1      | 13/07/2015  |File added to complete 		   | Misael AD        */
/*        	 |   		   |scheduler structure 		   |  				  */
/*  1.2      | 16/07/2015  |Scheduler config. constants    | Misael AD        */
/*  1.3      | 22/07/2015  |MISRA issues fixed			   | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM_Cfg.h"
#include "SchM_Tasks.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */
/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */
static const SchTaskDescriptorType SchTaskDescConfig[] = 
{
	  /* Offset / Mask / Task ID / Function Ptr */
	{	0,	MASK_1P25MS,	TASK_3P125MS,	&SchM_Task1p25ms	},
	{	1, 	MASK_2P5MS,  	TASK_6P25MS, 	&SchM_Task2p5ms		},
	{	2, 	MASK_5MS,  		TASK_12P5MS, 	&SchM_Task5ms		},
	{	3, 	MASK_10MS, 	 	TASK_25MS,		&SchM_Task10ms		},
	{	5, 	MASK_20MS, 	 	TASK_50MS, 		&SchM_Task20ms		},
	{	6, 	MASK_40MS, 		TASK_100MS, 	&SchM_Task40ms		}
};

const SchConfigType SchConfig = 
{
	(sizeof(SchTaskDescConfig)/sizeof(SchTaskDescConfig[0])),
	SchTaskDescConfig
};

const SchTaskDescriptorType *SchPtr[] = 
{
	&SchTaskDescConfig[0],
	&SchTaskDescConfig[1],
	&SchTaskDescConfig[2],
	&SchTaskDescConfig[3],
	&SchTaskDescConfig[4],
	&SchTaskDescConfig[5]
};

SchTaskControlType ras_TasksController[(sizeof(SchTaskDescConfig)/sizeof(SchTaskDescConfig[0]))];

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
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

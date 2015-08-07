/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        scheduler_Types.h
* Instance:         RPL_1
* %version:         1.1
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : Header file scheduler_Types                                  */
/*============================================================================*/
/* FUNCTION COMMENT : Scheduler Module type definitions					      */
/*               															  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Mr. Template     */
/*  1.1      | 13/07/2015  |File added to complete 		   | Misael AD        */
/*        	 |   		   |scheduler structure 		   |  				  */
/*============================================================================*/

#ifndef SCHEDULER_TYPES_H                               /* To avoid double inclusion */
#define SCHEDULER_TYPES_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */
typedef void (*TaskFunctionPtrType)(void);
typedef T_UBYTE SchTaskOffsetType;

typedef enum
{
	MASK_1P25MS = 1,
	MASK_2P5MS  = 3,
	MASK_5MS  	= 7,
	MASK_10MS   = 15,
	MASK_20MS	= 31,
	MASK_40MS	= 63
}SchTaskMaskType;

typedef enum
{
	TASK_BKG,
	TASK_3P125MS,
	TASK_6P25MS,
	TASK_12P5MS,
	TASK_25MS,
	TASK_50MS,
	TASK_100MS
}SchTaskIDType;

typedef enum
{
	TASK_STATE_SUSPENDED,
	TASK_STATE_READY,
	TASK_STATE_RUNNING
}SchTaskStateType;

typedef struct
{
	SchTaskStateType	SchTaskState;
	TaskFunctionPtrType	TaskFunctionControlPtr;
}SchTaskControlType;

typedef struct
{
	SchTaskOffsetType	SchTaskOffset;
	SchTaskMaskType		SchTaskMask;
	SchTaskIDType		SchTaskID;
	TaskFunctionPtrType	TaskFunctionPtr;
}SchTaskDescriptorType;

typedef struct
{
	T_UBYTE	SchNumberOfTasks;
	const SchTaskDescriptorType *SchTaskDescriptor;
}SchConfigType;

typedef enum
{
	SCH_UNINIT,
	SCH_INIT,
	SCH_RUNNING,
	SCH_OVERLOAD,
	SCH_HALTED
}SchStateType;

typedef struct
{
	T_UBYTE 		SchCounter;
	SchTaskIDType	SchTaskRunning;
	SchStateType	SchStatus;
}SchControlType;

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

/* Functions prototypes */


/* Functions macros */


/* Exported defines */


#endif



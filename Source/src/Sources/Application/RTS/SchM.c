/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         SchM.c
* Instance:         RPL_1
* %version:         1.3
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Wednesday, July 8, 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 04/04/2014  |  Dummy functions              |Francisco Martinez*/
/*  1.1      | 08/07/2015  |  Scheduler file & template    | Misael Alvarez   */
/*  1.2      | 16/07/2015  |  Scheduler main functions     | Misael Alvarez   */
/*  1.3      | 22/07/2015  |  MISRA errors fixed		   | Misael Alvarez   */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM.h"
#include "PIT.h"
#include "SchM_Tasks.h"
#include "SchM_Cfg.h"

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
static SchControlType SchController = {
	0, TASK_BKG, SCH_UNINIT
};

extern SchTaskControlType ras_TasksController[];

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */
static void SchM_Background(void);
static void SchM_OSTick(void);

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
 *  Name                 : SchM_Background
 *  Description          :	
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Background(void)
{
	static T_UBYTE rub_Tasks;
	for(;;)/* Scheduler endless loop */
	{
		for(rub_Tasks=0; rub_Tasks<SchConfig.SchNumberOfTasks;  rub_Tasks++)    /* Run ready tasks */
		{
			if(ras_TasksController[rub_Tasks].SchTaskState == TASK_STATE_READY)
			{
				ras_TasksController[rub_Tasks].SchTaskState = TASK_STATE_RUNNING;
				ras_TasksController[rub_Tasks].TaskFunctionControlPtr();
				ras_TasksController[rub_Tasks].SchTaskState = TASK_STATE_SUSPENDED;
			}
			else
			{
				/* Do nothing */
			}
		}
	}
}

 /**************************************************************
 *  Name                 :	SchM_Init
 *  Description          :	Scheduler initialization routines
 *  Parameters           :  Input: SchConfigType *SchM_Config
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Init(const SchConfigType *SchM_Config)
{
	T_UBYTE i;	/* Index for initializing(i) tasks */
	SchController.SchStatus = SCH_INIT;
	/* MemAlloc here */
	for(i=0; i<SchM_Config->SchNumberOfTasks; i++)
	{
		ras_TasksController[i].TaskFunctionControlPtr = SchM_Config->SchTaskDescriptor[i].TaskFunctionPtr;
		ras_TasksController[i].SchTaskState = TASK_STATE_SUSPENDED;
	}
	PIT_device_init();
	PIT_channel_configure(PIT_CHANNEL_0 , &SchM_OSTick);
}

/**************************************************************
 *  Name                 :	SchM_Stop
 *  Description          :	Stops the scheduler
 *  Parameters           :  None
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Stop(void)
{
	SchController.SchStatus = SCH_HALTED;
	PIT_channel_stop(PIT_CHANNEL_0);
}

/**************************************************************
 *  Name                 :	SchM_Start
 *  Description          :	Starts the scheduler
 *  Parameters           :  None
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Start(void)
{
	SchController.SchStatus = SCH_RUNNING;
	PIT_channel_start(PIT_CHANNEL_0);
    enableIrq();			/* Enable External Interrupts*/
	SchM_Background();		/* Do nothing */
}

/**************************************************************
 *  Name                 :	SchM_OSTick
 *  Description          :	Sets the scheduler tick
 *  Parameters           :  None
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_OSTick(void)
{
	extern const SchTaskDescriptorType *SchPtr[];/*MISRA error justify because size defined by the tasks descriptor table*/
	T_UBYTE t;	/* Pointer to check if task(t) has to be activated */
	SchController.SchCounter++;
	for(t=0; t<SchConfig.SchNumberOfTasks; t++)
	{
		if((SchController.SchCounter & SchPtr[t]->SchTaskMask) == SchPtr[t]->SchTaskOffset)
		{
			ras_TasksController[t].SchTaskState = TASK_STATE_READY;
		}
		else
		{
			/* Do nothing */
		}
	}
}

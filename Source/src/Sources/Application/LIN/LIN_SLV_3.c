/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         LIN_SLV_3.c
* Instance:         RPL_1
* %version:         1.0
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, August 11, 2015
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
/*  1.0      | 11/08/2015  |Slave 3 State Machines         | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "LIN_signals.h"
#include "LIN_common_network.h"
#include "LED.h"
#include "LIN_SLV_3.h"

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
T_UBYTE data_Tx[7];

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
t_slv_stat	le_SlvStatus = ENABLED;		/*Slave status*/
t_LEDstat	le_LEDStatus = ON;			/*LED status*/
t_boolean	le_SlvEnabled= TRUE;		/*Slave enabled*/

scalar LINSlvTeamNumber	 = 3;			/*Slv ID: Team Number*/
T_UBYTE  LINSlvName[6] = {				/*Slv ID: Capital Letters*/
	'M','A','D','K','C','G'
};

extern T_UBYTE		lub_RxID;	/*Received ID*/
extern t_cmdType	le_RxCmd;	/*Received Cmd*/

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */
void LIN_SlvMsgCmd(void);
void LIN_SlvMsgID(void);
void LIN_SlvMsgRSP(void);

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
void LIN_Slave(void)
{
	switch(le_SlvStatus)
	{
		case DISABLED:
			if( ((lub_RxID == MASTER_CMD_ALL) | (lub_RxID == MASTER_CMD_SLV3)) && (le_RxCmd == cmd_enable_slv) )
			{	/*Enable slave again only if the ID is a command and the command is to enable it*/
				le_SlvStatus  = ENABLED;
				le_SlvEnabled =	TRUE;
			}
			else if(lub_RxID == SLAVE3_RSP)
			{
				LIN_SlvMsgRSP();
			}
			else if(lub_RxID == SLAVE3_ID)
			{
				LIN_SlvMsgID();
			}
			else
			{
				/*Do nothing*/
			}
		break;
		
		case ENABLED:
			switch(lub_RxID)
			{
				case MASTER_CMD_ALL:
					LIN_SlvMsgCmd();
				break;
				
				case MASTER_CMD_SLV3:
					LIN_SlvMsgCmd();
				break;
				
				case SLAVE3_RSP:
					LIN_SlvMsgRSP();
				break;
				
				case SLAVE3_ID:
					LIN_SlvMsgID();
				break;
				
				default:
				break;
			}
		break;
		
		default:
		break;
	}
}

void LIN_SlvMsgCmd(void)
{
	switch(le_RxCmd)
	{
		case cmd_NONE:
			/*Do nothing*/
		break;
		
		case cmd_LED_on:
			le_LEDStatus = ON;
		break;
		
		case cmd_LED_off:
			le_LEDStatus = OFF;
		break;
		
		case cmd_LED_toggling:
			le_LEDStatus = TOGGLING;
		break;
		
		case cmd_disable_slv:
			le_SlvStatus  = DISABLED;
			le_SlvEnabled = FALSE;
		break;
		
		case cmd_enable_slv:
			le_SlvStatus  =	ENABLED;
			le_SlvEnabled = TRUE;
		break;
		
		default:
		break;
	}
}

void LIN_SlvMsgID(void)
{
	T_UBYTE i;
	/*Send ID*/
	data_Tx[0] = LINSlvTeamNumber;
	for(i=1;i<7;i++)
	{
		data_Tx[i] = LINSlvName[i-1];
	}
}

void LIN_SlvMsgRSP(void)
{
	/*Send RSP*/
	data_Tx[0] = (T_UBYTE)le_LEDStatus;
	data_Tx[1] = (T_UBYTE)le_SlvEnabled;
}

void LIN_LED(void)
{
	switch(le_LEDStatus)
	{
		case ON:
			LED_On(LED1);	/*Turn On LED*/
		break;
		
		case OFF:
			LED_Off(LED1);	/*Turn Off LED*/
		break;
		
		case TOGGLING:
			LED_T(LED1);	/*Toggle LED*/
		break;
		
		default:
		break;
	}
}
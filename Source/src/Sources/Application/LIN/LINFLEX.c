/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         LINFLEX.c
* Instance:         RPL_1
* %version:         1.0
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Tuesday, August 11, 2015
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
/*  1.0      | 11/08/2015  |LINFLEX driver                 | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "LINFLEX.h"
#include "MPC5606B.h"

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
T_UBYTE data_Rx;
extern T_UBYTE data_Tx[7];
int lin_status;


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
T_UBYTE		lub_RxID = 0;			/*Received ID*/
t_cmdType	le_RxCmd = cmd_NONE;	/*Received Cmd*/

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
#define LIN_TX 	0x400
#define LIN_RX	0x103
#define TX_FLAG   1<<1

#define PortB2 SIU.PCR[18].R
#define PortB3 SIU.PCR[19].R

#define LINFLEX0_RX_Vector 	79
#define LINFLEX0_TX_Vector 	80
#define LINFLEX0_ERR_Vector 81
#define PRIORITY10		    10

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
void InitLinFlex0Slave(T_UWORD baud) 
{	
	LINFLEX_0.LINCR1.B.SLEEP = 1;	/*Sleep State Request*/
	while(LINFLEX_0.LINSR.B.LINS != 0)
	{
		/*Wait for SLEEP state*/
	}
	LINFLEX_0.LINCR1.B.INIT = 1;	/*INIT mode*/
	LINFLEX_0.LINCR1.B.SLEEP = 0;	/*Sleep Mode Request*/
	while(LINFLEX_0.LINSR.B.LINS != 1)
	{
		/*Wait for INIT state*/
	}    
	
	LINFLEX_0.UARTCR.B.UART = 0;	/*LINFLEX working as LIN module*/
	  
	LINFLEX_0.LINCR1.B.MBL= 0x03;	/*LIN master lenght break 13 bits*/  
	LINFLEX_0.LINCR1.B.BF= 1;		/*bypass filter, An RX interrupt is generated on identifier not matching any filter*/
	
	LINFLEX_0.LINCR1.B.MME=0;		/*Slave mode ON*/
	
	LINFLEX_0.LINCR1.B.SBDT=0;		/*sets as 11 bit break*/
	LINFLEX_0.LINCR1.B.RBLM=0;		/*Receive buffer not locked on overrun */
	
	LINFLEX_0.LINCR2.B.IOBE= 0;		/*Idle on bit error, Bit error does not reset state machine*/
	    
	/* configure baudrate */
	LINFLEX_0.LINFBRR.R = (16*(16000000%(16*baud)))/(16*baud);	/*BaudRate float*/
	LINFLEX_0.LINIBRR.R = 16000000/(16*baud);					/*BaudRate integer*/
	    
	/*deactivate filters to be able to set them manually*/ 
	LINFLEX_0.IFER.R=0x00;
	LINFLEX_0.IFMR.R=0x00;
	  
	LINFLEX_0.LINTCSR.B.IOT=0;		/*Idle timeout , not reset to idle in tome out event*/
	 
	LINFLEX_0.LINIER.B.DRIE = 1;	/*Interrupt generated when data received flag (DRF)  is set*/	
	
	LINFLEX_0.LINIER.B.DTIE = 1;	/*Interrupt generated when data transmitted flag (DTF) is set*/
	
	LINFLEX_0.LINIER.B.HRIE = 1;	/*Interrupt generated when a valid LIN header has been received, that is, HRF bit in LINSR is set*/
		
	LINFLEX_0.LINIER.B.CEIE = 1;	/*Checksum error, Interrupt generated when checksum error flag (CEF) in LINESR is set*/
	
	LINFLEX_0.LINIER.B.HEIE = 1;	/*Header error, Interrupt generated on Break Delimiter error, Synch Field error, Identifier field error*/
		
	LINFLEX_0.LINIER.B.BEIE = 0;	/*Bit error Interrupt generated when BEF bit in LINESR is set*/   
    
    LINFLEX_0.IFCR[2].R = 0x10F;  /* CF */ /* MASTER_CMD_ALL */
	LINFLEX_0.IFCR[3].R = 0x112;  /* 92 */ /* MASTER_CMD_SLV3 */
	
	LINFLEX_0.IFCR[4].R = 0x722;  /* E2 */ /* SLAVE3_RSP */
	LINFLEX_0.IFCR[5].R = 0x1B32; /* 32 */ /* SLAVE3_ID  */	  
	  
	/*Activate Filters*/
	LINFLEX_0.IFER.R=0x3;

	PortB2 = LIN_TX;         /* MPC56xxB: Configure port B2 as LIN0TX */
	PortB3 = LIN_RX;         /* MPC56xxB: Configure port B3 as LIN0RX */ 
	
	LINFLEX_0.LINCR1.B.INIT = 0; /* LIN operational */
	while(LINFLEX_0.LINSR.B.LINS != 2)
	{
		/*Wait for IDLE state*/
	}
}


void LINFlex_0_RX_ISR(void)
{	
	if(LINFLEX_0.LINSR.B.RMB == 1)
	{
		LINFLEX_0.LINSR.B.RMB=0;
	}
	
	if((LINFLEX_0.BIDR.B.ID == 0x0F) || (LINFLEX_0.BIDR.B.ID == 0x12))
	{
		//data_Rx=(T_UBYTE) LINFLEX_0.BDRL.B.DATA0;
		lub_RxID = LINFLEX_0.BIDR.B.ID;
		le_RxCmd = LINFLEX_0.BDRL.B.DATA0;
	}
	else if((LINFLEX_0.BIDR.B.ID == 0x22) || (LINFLEX_0.BIDR.B.ID == 0x32))
	{
		
	}
	else
	{
		/* Do nothing */
	}
}


void LINFlex_0_TX_ISR(void)
{
	if(LINFLEX_0.LINSR.B.DTF == 1)
	{
		LINFLEX_0.LINSR.B.DTF=0;
	}
	if(LINFLEX_0.LINSR.B.RMB == 1)
	{
		LINFLEX_0.LINSR.B.RMB=0;
	}
	
	if((LINFLEX_0.BIDR.B.ID == 0x21) || (LINFLEX_0.BIDR.B.ID == 0x31))
	{
		
	}
	else if((LINFLEX_0.BIDR.B.ID == 0x0F) || (LINFLEX_0.BIDR.B.ID == 0x11))
	{
		
	}
	else
	{
		/* Do nothing */
	}
}

void Intc_LINFLEX_Err(void)
{
	LINFLEX_0.LINESR.B.BEF=1;
}

void	IntcInterruptLINFLEXHandlers(void)
 {
  
  /* Configure INTC */
  INTC.MCR.R=0;
  /*ISRs*/
  INTC_InstallINTCInterruptHandler(&LINFlex_0_RX_ISR, LINFLEX0_RX_Vector, 1);
  INTC_InstallINTCInterruptHandler(&LINFlex_0_TX_ISR, LINFLEX0_TX_Vector, 2);
  INTC_InstallINTCInterruptHandler(&Intc_LINFLEX_Err, LINFLEX0_ERR_Vector, 3);
  /* Masking Priority to Zero*/
  INTC.CPR.R = 7;
 }
/*============================================================================*/
/*                  CONTINENTAL AUTOMOTIVE SYSTEMS AG                         */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        LIN_common_network.h
* version:         1.0 
* created_by:      Gilberto Ochoa
* date_created:    Aug 10, 2015
*=============================================================================*/
/* DESCRIPTION :                                                              */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      |             |                               | Gilberto Ochoa   */
/*  First Implementation.                                                     */
/*============================================================================*/

#ifndef LIN_COMMON_NETWORK_H_
#define LIN_COMMON_NETWORK_H_

#include "typedefs.h"
		
#define MASTER_CMD_ALL		(0x0F)

/*Slave 1*/
#define MASTER_CMD_SLV1		(0x10)
#define SLAVE1_RSP			(0x20)
#define SLAVE1_ID			(0x30)

/*Slave 2*/
#define MASTER_CMD_SLV2		(0x11)
#define SLAVE2_RSP			(0x21)
#define SLAVE2_ID			(0x31)

/*Slave 3*/
#define MASTER_CMD_SLV3		(0x12)
#define SLAVE3_RSP			(0x22)
#define SLAVE3_ID			(0x32)

/*Slave 4*/
#define MASTER_CMD_SLV4		(0x13)
#define SLAVE4_RSP			(0x23)
#define SLAVE4_ID			(0x33)


#endif /* LIN_COMMON_NETWORK_H_ */

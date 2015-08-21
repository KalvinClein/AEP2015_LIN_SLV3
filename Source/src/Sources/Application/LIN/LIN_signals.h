/*============================================================================*/
/*                  CONTINENTAL AUTOMOTIVE SYSTEMS AG                         */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        LIN_signals.h
* version:         1.0 
* created_by:      Gilberto Ochoa	
* date_created:    10/08/2015
*=============================================================================*/
/* DESCRIPTION : LIN Signals definitions                                      */
/*============================================================================*/
/* FUNCTION COMMENT :  Contains data structures to ease the handling of the   */
/* LIN signals.                                                               */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 10/08/2015 |                               | Gilberto Ochoa   */
/*  First Implementation.                                                     */
/*============================================================================*/
#ifndef LINSIGNALS_H_
#define LINSIGNALS_H_

#include "LIN_common_network.h"


/* -------------------------------------------------------------------------- */
// 		Signal TYPES
/* -------------------------------------------------------------------------- */

typedef enum
{
	DISABLED,
	ENABLED
}t_slv_stat;

typedef enum
{
	cmd_NONE,
	cmd_LED_on,
	cmd_LED_off,
	cmd_LED_toggling,
	cmd_disable_slv,
	cmd_enable_slv
}t_cmdType;

typedef enum
{
	OFF,
	ON,
	TOGGLING
}t_LEDstat;

typedef enum
{
	FALSE,
	TRUE
}t_boolean;

typedef T_UBYTE scalar;

#endif /* LINSIGNALS_H_ */
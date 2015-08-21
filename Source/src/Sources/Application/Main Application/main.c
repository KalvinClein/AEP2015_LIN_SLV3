
/* Includes  */
#include	"init.h"
#include    "PIT.h"
#include    "SchM.h"
#include    "SchM_Cfg.h"
#include	"LINFLEX.h"
#include	"LED.h"

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/
int data;
/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of global wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/
#define S1 SIU.GPDI[64].R
/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/
    
/******************************************************************************************************
* Definition of module wide VARIABLEs 
******************************************************************************************************/
 
/******************************************************************************************************
* Code of module wide FUNCTIONS
******************************************************************************************************/

/*~~~~~~~ Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void main(void) 

{
	initModesAndClock();
	initPeriClkGen();
	
	/* Disable Watchdog */
	init_disableWatchdog();
	
	/*Initialize LEDs on TRK-MPC560xB board */
	init_OnBoardLEDs();
	
	/*Initialize the On-Board push buttons*/
	init_OnBoardPushButtons();
	
	/*Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
    
    IntcInterruptLINFLEXHandlers();
    
    InitLinFlex0Slave(9600);
    
    LED_Off(LED1);
    LED_Off(LED2);
    LED_Off(LED3);
    LED_Off(LED4);
    
    /*Initialize scheduler*/	
    SchM_Init(&SchConfig);
    
    /*Hand control to the scheduler*/
    SchM_Start();
    
    for(;;)
    {
    	
    }
}

/*~~~~~~~ End of Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

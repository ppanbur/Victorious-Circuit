#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "car_defines.h"

/***********************************************************************/
/*                                                                     */
/*  File Name:  main.c												   */
/*  DATE        :2/26/2012			                                   */
/*																	   */
/*  DESCRIPTION :  This file contains MAIN							   */
/* 	  			  				    								   */
/*																	   */
/*  CPU GROUP   :M16C                                                  */
/*                                                                     */
/*  Modified By: Peter Panburana (ppanbur)							   */
/*  Version 1.1 (3/5/2012)											   */
/*                                                                     */
/***********************************************************************/

//Defines go here 
#define PRESSED 0
#define TRUE 1


int disp_count;				// LED control variable
uint A2DValue;
uint A2DValuePot;
uint A2DValueTherm;
uchar A2DProcessed;



void main(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	The MCU will come here after reset. 
//  
//
//  Rev:    1.5a     TEMPLATE RELEASE
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	
	//Initialization function calls 
	init_ports();
	motors_init();
	system_clock_init();
	InitDisplay("FHBTEST    "); //Start-up splash changed to unity ID
	InitUART();
	ADInit();	
	ENABLE_SWITCHES;	
	/* LED initialization - macro defined in qsk_bsp.h */
 	ENABLE_LEDS	


	//Polling for switch presses 
	while(TRUE) 
	{
		if(S1 == PRESSED)
		{
			BNSPrintf(LCD,"\tTEST          \n        ");
			project2ADemo(); 		
		}
		else if (S2 == PRESSED)
		{
			BNSPrintf(LCD,"\tOff            \n        ");
		}
		else if (S3 == PRESSED)
		{
			BNSPrintf(LCD,"\tFigure 8              \n        ");
			DoFigureEight();
		}
		else
		{
       		BNSPrintf(LCD,"\tTeam 2                 \n        ");
        }
		
	}
}



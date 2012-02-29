#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

volatile unsigned int ms_counter =0; 

//This file contains the function which sets up the AO timer 
void TimerInit(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	This will set up the A0 timer for 1ms and the A1 as counter
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{

   
   //Configure Timer A1 for motor frequency of 1KHz (100 Div soft-counter) <--- Ignore that 1KHz is way too fast
   ta1mr = 0x80;	// Timer mode, f32, no pulse output
   ta1 = (unsigned int) (((f1_CLK_SPEED/32)*1e-4) - 1);	// (Desired_Time x 24MHz/32)-1  <--- change that one to adjust frequency
	
/* The recommended procedure for writing an Interrupt Priority Level is shown
   below (see M16C datasheets under 'Interrupts' for details). */

   DISABLE_IRQ		// disable irqs before setting irq registers - macro defined in skp_bsp.h
   ta1ic = 3;		// Set the timer A1's IPL (interrupt priority level) to 3
   ENABLE_IRQ		// enable interrupts macro defined in skp_bsp.h

   /* Start timers */
   ta1s = 1;		// Start Timer A1
}

void delayMiliseconds(unsigned int ms)
{
  tb0mr = 0x00;            // Clear Timer B0 Mode Register
  tb0mr |= 0x00;	       // Timer mode
  tb0mr |= 0x80;	       // Clock Source f32
  tb0 = (unsigned int) (((f1_CLK_SPEED/32)*1/1000) - 1);
  
  DISABLE_IRQ
  tb0ic = 3; 
  ENABLE_IRQ
  tb0s = 1;
  	 
	while(ms_counter < ms)
	{
	}
  DISABLE_IRQ
  tb0ic = 0; 
  ENABLE_IRQ
  ms_counter = 0;
  tb0s = 0;
}
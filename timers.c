#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  File Name:   timers.c                                              */
/*  DATE:        2/18/2012                                             */
/*																	   */
/*  DESCRIPTION:  All functions for configuration of timers            */
/*				  aside from those used in motor PWM go here		   */
/* 	  																   */
/*																	   */
/*  CPU GROUP   :M16C                                                  */
/*                                                                     */
/*  						  										   */
/*  AUTHOR: Peter Panburana (ppanbur)								   */
/*  Version: 1.1 (3/5/2012) 										   */
/*                                                                     */
/***********************************************************************/

//Globals go here 
volatile unsigned int ms_counter =0; 
 
void TimerInit(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Demo timer initialization function. Function is now obsolete and should not be used 
//  
//  Notes:      Do not call or use    
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



void delayMilliseconds(unsigned int ms)
//---------------------------------------------------------------------------------------
//  Purpose:	Starts timer B0 in timer mode; its interrupt counts how many 
//				milliseconds have passed since the timer was started. Counts 
//				to a length of time (in ms) specified by the user and disables the timer.
//				
//  System registers associated with delayMilliseconds
//  tb0mr - Loaded with 0x80 for use as a timer (timer mode,f32 clock , no output)
//	tb0   - Loaded to count to 1 millisecond
//  tb0ic - Interrupt priority set to level 3 
//  tb0s  - Loaded with 1 to start the timer, 0 to stop the timer
//  Passed: Unsigned integer indicating how the desired delay time in milliseconds
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.1     
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------
{
  tb0mr = 0x00;            // Clear Timer B0 Mode Register
  tb0mr |= 0x00;	       // Timer mode
  tb0mr |= 0x80;	       // Clock Source f32
  tb0 = (unsigned int) (((f1_CLK_SPEED/32)*1/1000) - 1); //Load with one millisecond
 
  //Start timer and enable its interrupt
  DISABLE_IRQ
  tb0ic = 3; 
  ENABLE_IRQ
  tb0s = 1;	 
  //Delay until the counter reaches the passed value 
	while(ms_counter < ms)
	{
	}
	
  //Stop timer and disable its interrupt. Also reset counter for next call 
  DISABLE_IRQ
  tb0ic = 0; 
  ENABLE_IRQ
  ms_counter = 0;
  tb0s = 0;
}
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "car_defines.h"

#define PWM_INIT_STATE 0x00 
#define PWM_ON_COUNT_STATE 0x01 
#define PWM_OFF_COUNT_STATE 0x02
#define FULLY_ON 0x03
#define FULLY_OFF 0x04

/***********************************************************************/
/*                                                                     */
/*  DATE        :2/26/2012			                                   */
/*																	   */
/*  DESCRIPTION :  This file contains all the interrupt routines for   */
/* 	  				the peripherals.  								   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

#pragma INTERRUPT A2DInterrupt
#pragma INTERRUPT UART0TransmitInterrupt
#pragma INTERRUPT UART0ReceiveInterrupt
#pragma INTERRUPT TimerA1Interrupt
#pragma INTERRUPT TimerA2Interrupt
#pragma INTERRUPT KeyBoardInterrupt
#pragma INTERRUPT DMA0Interrupt
#pragma INTERRUPT WakeUpInterrupt
#pragma INTERRUPT RTCInterrupt
#pragma INTERRUPT TimerB0Interrupt
#pragma INTERRUPT WatchDogInterrupt

void A2DInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void UART0TransmitInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void DMA0Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void UART0ReceiveInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	while(ri_u0c1 == 0);	  // make sure receive is complete
	
    while(ti_u0c1 == 0); 			//  puts it in the UART 0 transmit buffer 

	u0tb = (char) u0rb;      // read in received data
    
}

void TimerA1Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Timer A1 is associated with PWM control of the car's two motors. Its interrupt  
//				charged with calculating PWM on/off durations for both motors. 
//  
//
//  Rev: 1.3beta  State names added, motor struct updated to only allow one direction at any given time  
//  
//  Notes:        ~MUST DISABLE OTHER PORT BEFORE ACTIVATING OTHER DIRECTION~  
//-----------------------------------------------------------------------------------------------------
{

	int i; //Loop variable
	unsigned char *m_port = &p3;  // Holds the address of the Port Register
	
	for(i=0;i<2;i++)	//Calculate PWM speed for each motor
	{
		switch(car_motors[i].count_state)
		{
			case PWM_INIT_STATE: // the initialization state
				
			
				if(car_motors[i].speed == 100)
				{
					car_motors[i].count_state = FULLY_ON; //go to the on state
					break;
					
				}
				
				else if(car_motors[i].speed == 0)
				{
					car_motors[i].count_state = FULLY_OFF; //go to the off state
					break;
				}
				
				else
				{				
					car_motors[i].off_time = 100 - car_motors[i].speed; //calculate the off time
					*m_port = *m_port |(1 << car_motors[i].DRIVE_SELECT); //turn the motor on
					car_motors[i].count_state = PWM_ON_COUNT_STATE; // set it to the next state
					break;
				}
			case PWM_ON_COUNT_STATE: // the 'on' count
				car_motors[i].counter++; //increment the counter
				if(car_motors[i].counter == car_motors[i].speed) // count is up time to turn the motor off
				{
					*m_port = *m_port & ~(1 << car_motors[i].DRIVE_SELECT); //turn the motor off
					car_motors[i].counter = 0; //reset the counter
					car_motors[i].count_state = PWM_OFF_COUNT_STATE; // set it to the off count state
				}
				break;
			case PWM_OFF_COUNT_STATE: //the 'off' count
				car_motors[i].counter++; //increment the counter
				if(car_motors[i].counter == car_motors[i].off_time) // count is up time to turn the motor off
				{
					*m_port = *m_port |(1 << car_motors[i].DRIVE_SELECT); //turn the motor on
					car_motors[i].counter = 0; //reset the counter
					car_motors[i].count_state = PWM_ON_COUNT_STATE; // set it to the on state
				}
				break;
			case FULLY_ON: //100 percent duty cycle
				*m_port = *m_port |(1 << car_motors[i].DRIVE_SELECT); //turn the motor on
				car_motors[i].count_state = PWM_INIT_STATE;
				break;
			case FULLY_OFF: //zero percent duty cycle
				*m_port = *m_port & ~(1 << car_motors[i].DRIVE_SELECT); //turn the motor off
				car_motors[i].count_state = PWM_INIT_STATE;
				break;					
			default:
				car_motors[i].count_state = PWM_INIT_STATE; //just reinitialize it
				break;
		}
			
	}
	

			
		
}


void TimerA2Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
// 
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void KeyBoardInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void WakeUpInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void RTCInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void TimerB0Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	ms_counter++;
}

void WatchDogInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}


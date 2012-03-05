#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "car_defines.h"

/***********************************************************************/
/*                                                                     */
/*  File Name:  Interrupts.c										   */
/*  DATE        :2/26/2012			                                   */
/*																	   */
/*  DESCRIPTION :  This file contains all the interrupt routines for   */
/* 	  			   the peripherals.  								   */
/*																	   */
/*  CPU GROUP   :M16C                                                  */
/*                                                                     */
/*  Modified By: Peter Panburana (ppanbur)							   */
/*  Version 1.1 (3/5/2012)											   */
/*                                                                     */
/***********************************************************************/

//Defines go here 
#define PWM_INIT_STATE 0x00 
#define PWM_ON_COUNT_STATE 0x01 
#define PWM_OFF_COUNT_STATE 0x02
#define FULLY_ON 0x03
#define FULLY_OFF 0x04

//Derectives for unmodified interrupts 
#pragma INTERRUPT A2DInterrupt
#pragma INTERRUPT UART0TransmitInterrupt
#pragma INTERRUPT UART0ReceiveInterrupt
#pragma INTERRUPT TimerA2Interrupt
#pragma INTERRUPT KeyBoardInterrupt
#pragma INTERRUPT DMA0Interrupt
#pragma INTERRUPT WakeUpInterrupt
#pragma INTERRUPT RTCInterrupt
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

#pragma INTERRUPT TimerA1Interrupt
void TimerA1Interrupt(void)
//---------------------------------------------------------------------------------------------------------
//  Purpose:	Interrupt for calculating and applying PWM for each motor(2) in the global array of motors
//  System registers associated with setRightMotorSpeed
//  Port 3 Register - activately determines how long either the forward of reverse pin of each motor should 
//  				  be held "on" or or "off" 
//  Locals: (int) i - for loop counter value 
//			(unsigned char) *m_port - holds the address of the port 3 register 
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.3   
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------------------------
{

	int i; //Loop variable
	unsigned char *m_port = &p3;  // Holds the address of the Port Register
	
	for(i=0;i<2;i++)	//Calculate PWM speed for each motor
	{
		switch(car_motors[i].count_state)
		{
			case PWM_INIT_STATE: // the initialization state	
			
				if(car_motors[i].speed == 100) //Motor is on at max power
				{
					car_motors[i].count_state = FULLY_ON; //go to the on state
					break;			
				}
				
				else if(car_motors[i].speed == 0) //Motor is off 
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
				car_motors[i].count_state = PWM_INIT_STATE; //just reinitialize it should it ever end up here 
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
#pragma INTERRUPT TimerB0Interrupt
void TimerB0Interrupt(void)
//---------------------------------------------------------------------------------------------------------
//  Purpose:	Interrupt for timer B0, increments a global value that indicates how many milliseconds it 
// 				has counted to since the timer was started. 
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.0 Initial Release   
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------------------------
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


#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "car_defines.h"
/***********************************************************************/
/*                                                                     */
/*  File Name:   motors.c                                              */
/*  DATE:        2/18/2012                                             */
/*																	   */
/*  DESCRIPTION:  All functions for motor control/use 		  		   */
/* 	  																   */
/*																	   */
/*  CPU GROUP   :M16C                                                  */
/*                                                                     */
/*  						  										   */
/*  AUTHOR: Peter Panburana (ppanbur)								   */
/*  Version: 1.1 (3/5/2012) 										   */
/*                                                                     */
/***********************************************************************/

//Defines go here 
#define L_FORWARD 0x02
#define R_FORWARD 0x00
#define L_REVERSE 0x03
#define R_REVERSE 0x01
#define ZERO_PERCENT 0
#define HUNDRED_PERCENT 100
#define INITIAL_STATE 0x00
#define TRANS_STATE 0x04
#define INITIAL_OFF_VALUE 0
#define INITIAL_COUNTER_VALUE 0
#define UNDEFINED_MOTOR 0xFF


//Global array of Motors structs, index zero is for the left motor, index one is for the right motor
Motor car_motors[2] = {{UNDEFINED_MOTOR,ZERO_PERCENT,INITIAL_OFF_VALUE,INITIAL_COUNTER_VALUE,INITIAL_STATE}, {UNDEFINED_MOTOR,ZERO_PERCENT,INITIAL_OFF_VALUE,INITIAL_COUNTER_VALUE,INITIAL_STATE}}; 

//----------------------------------------------------------------------------------
//  Purpose:	calls the function that starts the timer A1 for use in PWM
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.2     
//  Built using: HEW Version 4.09.00.007
//----------------------------------------------------------------------------------
void motors_init(void)
{
	//Initializing the global array with specific presets can go here 
	pwmTimerStart();

}

//---------------------------------------------------------------------------------------
//  Purpose:	Starts timer A1 in timer mode; its interrupt is used for PWM calculations
//  System registers associated with pwmTimerStart
//  ta1mr - Loaded with 0x80 for use as a timer (timer mode,f32 clock , no output)
//	ta1   - Loaded with 1e-4 (10 KHz PWM frequency)
//  ta1ic - Interrupt priority set to level 3 
//  ta1s  - Loaded with 1 to start the timer 
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.1     
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------

void pwmTimerStart(void)
{
   //Configure Timer A1 for motor frequency of 10KHz
   ta1mr = 0x80;	// Timer mode, f32, no pulse output
   ta1 = (unsigned int) (((f1_CLK_SPEED/32)*1e-4) - 1);	// (Desired_Time x 24MHz/32)-1  <--- change Desired_Time to adjust frequency 
   DISABLE_IRQ		// disable irqs before setting irq registers - macro defined in skp_bsp.h
   ta1ic = 3;		// Set the timer A1's IPL (interrupt priority level) to 3
   ENABLE_IRQ		// enable interrupts macro defined in skp_bsp.h
   
   ta1s = 1;		// Start Timer A1
}
//---------------------------------------------------------------------------------------
//  Purpose:	Stops timer A1; halts PWM calculations for motors 
//  System registers associated with pwmTimerStop
//  ta1ic - Interrupt priority set to level 0
//  ta1s  - Loaded with 0 to stop the timer 
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.1     
//  Built using: HEW Version 4.09.00.007
//----------------------------------------------------------------------------------
void pwmTimerStop(void)
{
   DISABLE_IRQ		// disable irqs before setting irq registers - macro defined in skp_bsp.h
   ta1ic = 0;		// Set the timer A1's IPL (interrupt priority level) to 0 (DISABLED)
   ENABLE_IRQ		// enable interrupts macro defined in skp_bsp.h
   
   ta1s = 0;		// Stop timer 
}
//---------------------------------------------------------------------------------------------------------
//  Purpose:	Sets the speed of the left motor to a desired value from -100 to 100 (- indicating reverse) 
//  System registers associated with setLeftMotorSpeed
//  LEFT_MOTOR_FORWARD - Port 3 pin 2 
//  LEFT_MOTOR_REVERSE - Port 3 pin 3
//  Passed: (int) pwm_dc - user's desired left motor speed 
//  Locals: (unsigned char) reverse - indicates that the motor will be driven in reverse
//			(int) speed - holds the absolute value of the user's speed 
//  Returned: No values returned.
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.1     
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------------------------
void setLeftMotorSpeed(int pwm_dc)
{
	
	//LOCAL VARIABLES 
	unsigned char reverse = 0;
	int speed = pwm_dc; 
	
	if(pwm_dc < 0)
	{	
		speed = -1 * pwm_dc; //make it a positive speed 
		reverse = 1; //indicate that reverse pins for the LEFT motors will be driven
	}
	
	if(speed > 100) //Prevent user speed from exceeding maximum value of PWM
	{
		speed = 100; 	
	}
	
	if(reverse) 
	{
		//Disable motor if it is currently running 
		car_motors[0].speed = 0;
		car_motors[0].count_state = INITIAL_STATE;	
		car_motors[0].counter = INITIAL_COUNTER_VALUE;
		//Make sure that the opposite pin is off 
		LEFT_MOTOR_FORWARD = MOTOR_OFF;
		
		//set new speed
		car_motors[0].DRIVE_SELECT = L_REVERSE;
		car_motors[0].speed = speed;
		car_motors[0].count_state = INITIAL_STATE;	
		car_motors[0].counter = INITIAL_COUNTER_VALUE;
		
	}
	else
	{
		//Disable motor if it is currently running 
		car_motors[0].speed = 0;
		car_motors[0].count_state = INITIAL_STATE;	
		car_motors[0].counter = INITIAL_COUNTER_VALUE;
		//Make sure the opposite pin is off 
		LEFT_MOTOR_REVERSE = MOTOR_OFF;
		
		//set new speed 
		car_motors[0].DRIVE_SELECT = L_FORWARD;
		car_motors[0].speed = pwm_dc;
		car_motors[0].count_state = INITIAL_STATE;	
		car_motors[0].counter = INITIAL_COUNTER_VALUE;
		
	}

}

//---------------------------------------------------------------------------------------------------------
//  Purpose:	Sets the speed of the right motor to a desired value from -100 to 100 (- indicating reverse) 
//  System registers associated with setRightMotorSpeed
//  RIGHT_MOTOR_FORWARD - Port 3 pin 0 
//  RIGHT_MOTOR_REVERSE - Port 3 pin 1
//  Passed: (int) pwm_dc - user's desired left motor speed 
//  Locals: (unsigned char) reverse - indicates that the motor will be driven in reverse
//			(int) speed - holds the absolute value of the user's speed 
//  Returned: No values returned.
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.1     
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------------------------
void setRightMotorSpeed(int pwm_dc)
{
	unsigned char reverse = 0;
	int speed = pwm_dc; 
	
	if(pwm_dc < 0)
	{	
		speed = -1 * pwm_dc; // make it a positive speed
		reverse = 1; //indicate that reverse pins for the RIGHT motors will be driven
	}
	
	if(speed > 100) //Prevent user speed from exceeding maximum value of PWM
	{
		speed = 100; 	
	}
		
	if(reverse) 
	{
		//Disable motor if it is currently running 
		car_motors[1].speed = 0;
		car_motors[1].count_state = INITIAL_STATE;	
		car_motors[1].counter = INITIAL_COUNTER_VALUE;
		//Make sure opposite pin is off 
		RIGHT_MOTOR_FORWARD = MOTOR_OFF;
		
		//set new speed 
		car_motors[1].DRIVE_SELECT = R_REVERSE;
		car_motors[1].speed = speed;
		car_motors[1].count_state = INITIAL_STATE;	
		car_motors[1].counter = INITIAL_COUNTER_VALUE;
		
	}
	else
	{
		//Disable motor if it is currently running 
		car_motors[1].speed = 0;
		car_motors[1].count_state = INITIAL_STATE;	
		car_motors[1].counter = INITIAL_COUNTER_VALUE;
		//Make sure opposite pin is off 
		RIGHT_MOTOR_REVERSE = MOTOR_OFF;
		
		//set new speed 
		car_motors[1].DRIVE_SELECT = R_FORWARD;
		car_motors[1].speed = pwm_dc;
		car_motors[1].count_state = INITIAL_STATE;	
		car_motors[1].counter = INITIAL_COUNTER_VALUE;
		
	}
		
}

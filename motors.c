#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "car_defines.h"
/***********************************************************************/
/*                                                                     */
/*  DATE        :2/18/2012                                             */
/*																	   */
/*  DESCRIPTION :  All motor related functions go in this file		   */
/* 	  																   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  						  										   */
/*  ppanbur															   */
/*                                                                     */
/***********************************************************************/

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

Motor car_motors[2] = {{UNDEFINED_MOTOR,ZERO_PERCENT,INITIAL_OFF_VALUE,INITIAL_COUNTER_VALUE,INITIAL_STATE}, {UNDEFINED_MOTOR,ZERO_PERCENT,INITIAL_OFF_VALUE,INITIAL_COUNTER_VALUE,INITIAL_STATE}}; //<---- Motor array struct

//Call this once
void motors_init(void)
{

	pwmTimerStart();

}

void pwmTimerStart(void)
{
   //Configure Timer A1 for motor frequency of 1KHz (100 Div soft-counter) <--- Ignore that 1KHz is way too fast
   ta1mr = 0x80;	// Timer mode, f32, no pulse output
   ta1 = (unsigned int) (((f1_CLK_SPEED/32)*1e-4) - 1);	// (Desired_Time x 24MHz/32)-1  <--- change that one to adjust frequency
   
   DISABLE_IRQ		// disable irqs before setting irq registers - macro defined in skp_bsp.h
   ta1ic = 3;		// Set the timer A1's IPL (interrupt priority level) to 3
   ENABLE_IRQ		// enable interrupts macro defined in skp_bsp.h
   
   ta1s = 1;		// Start Timer A1
}

void pwmTimerStop(void)
{
   DISABLE_IRQ		// disable irqs before setting irq registers - macro defined in skp_bsp.h
   ta1ic = 0;		// Set the timer A1's IPL (interrupt priority level) to 3
   ENABLE_IRQ		// enable interrupts macro defined in skp_bsp.h
   
   ta1s = 0;		// Start Timer A1
}

void setLeftMotorSpeed(int pwm_dc)
{
	unsigned char reverse = 0;
	int speed = pwm_dc; 
	
	if(pwm_dc < 0)
	{	
		speed = -1 * pwm_dc;
		reverse = 1;
	}
	
	if(reverse) 
	{
		//Shut if off in the interrupt
		car_motors[0].speed = 0;
		car_motors[0].count_state = INITIAL_STATE;	
		car_motors[0].counter = INITIAL_COUNTER_VALUE;
		//make sure it is off
		LEFT_MOTOR_FORWARD = MOTOR_OFF;
		
		//set new speed 
		car_motors[0].DRIVE_SELECT = L_REVERSE;
		car_motors[0].speed = speed;
		car_motors[0].count_state = INITIAL_STATE;	
		car_motors[0].counter = INITIAL_COUNTER_VALUE;
		
	}
	else
	{
		//Shut if off in the interrupt
		car_motors[0].speed = 0;
		car_motors[0].count_state = INITIAL_STATE;	
		car_motors[0].counter = INITIAL_COUNTER_VALUE;
		//make sure it is off
		LEFT_MOTOR_REVERSE = MOTOR_OFF;
		
		//set new speed 
		car_motors[0].DRIVE_SELECT = L_FORWARD;
		car_motors[0].speed = pwm_dc;
		car_motors[0].count_state = INITIAL_STATE;	
		car_motors[0].counter = INITIAL_COUNTER_VALUE;
		
	}

}

void setRightMotorSpeed(int pwm_dc)
{
	//car_motors[1].speed = pwm_dc;
	//car_motors[1].count_state = INITIAL_STATE;	
	//car_motors[1].counter = INITIAL_COUNTER_VALUE;
	
	unsigned char reverse = 0;
	int speed = pwm_dc; 
	
	if(pwm_dc < 0)
	{	
		speed = -1 * pwm_dc;
		reverse = 1;
	}
	
	if(reverse) 
	{
		//Shut if off in the interrupt
		car_motors[1].speed = 0;
		car_motors[1].count_state = INITIAL_STATE;	
		car_motors[1].counter = INITIAL_COUNTER_VALUE;
		//make sure it is off
		RIGHT_MOTOR_FORWARD = MOTOR_OFF;
		
		//set new speed 
		car_motors[1].DRIVE_SELECT = R_REVERSE;
		car_motors[1].speed = speed;
		car_motors[1].count_state = INITIAL_STATE;	
		car_motors[1].counter = INITIAL_COUNTER_VALUE;
		
	}
	else
	{
		//Shut if off in the interrupt
		car_motors[1].speed = 0;
		car_motors[1].count_state = INITIAL_STATE;	
		car_motors[1].counter = INITIAL_COUNTER_VALUE;
		//make sure it is off
		RIGHT_MOTOR_REVERSE = MOTOR_OFF;
		
		//set new speed 
		car_motors[1].DRIVE_SELECT = R_FORWARD;
		car_motors[1].speed = pwm_dc;
		car_motors[1].count_state = INITIAL_STATE;	
		car_motors[1].counter = INITIAL_COUNTER_VALUE;
		
	}
		
}

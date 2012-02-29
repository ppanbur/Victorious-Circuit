//This is the updated extern.h

/***********************************************************************/
/*                                                                     */
/*  DATE        :2/18/2012                                             */
/*																	   */
/*  DESCRIPTION :  All external declarations shall be made in this file*/
/* 	  																   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  						  										   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

// Project Specific 

//This struct contains all values that are associated with PWM and motor control 
typedef struct motor
{
	char DRIVE_SELECT; //bit position that corresponds to the desired motor port (L/R,Forwards/Backwards)
	int speed; // your PWM duty cycle
	int off_time; //100-speed to be calculated in the interrupt
	int counter; //counter to be used in the interrupt
	char count_state; //for the FSM in the interrupt
}Motor; 


extern int disp_count;				// LED control variable
extern uint A2DValue;
extern uint A2DValuePot;
extern uint A2DValueTherm;
extern uchar A2DProcessed;

//the global array of motors which is initialized in main.c but needs to be declared here  
extern Motor car_motors[2];
extern volatile unsigned int ms_counter;
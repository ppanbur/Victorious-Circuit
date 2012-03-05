#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  File Name:   shapes.c                                              */
/*  DATE:        2/18/2012                                             */
/*																	   */
/*  DESCRIPTION:  All shape choreography functions			  		   */
/*				  are defined here 									   */
/* 	  																   */
/*																	   */
/*  CPU GROUP   :M16C                                                  */
/*                                                                     */
/*  						  										   */
/*  AUTHOR: Peter Panburana (ppanbur)								   */
/*  Version: 1.1 (3/5/2012) 										   */
/*                                                                     */
/***********************************************************************/

void DoTriangle(void)
//---------------------------------------------------------------------------------------------------------
//  Purpose: Choreographed routine for making the Victorious Circuit move in a triangle
//  
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.3   
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------------------------
{
	//Turn Slightly 
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMilliseconds(900);
	//Go Straight
	setLeftMotorSpeed(30);
	setRightMotorSpeed(30);
	delayMilliseconds(1000);
	//Turn Longer
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMilliseconds(2000);
	//Go Straight
	setLeftMotorSpeed(30);
	setRightMotorSpeed(30);
	delayMilliseconds(800);
	//Turn Longer
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMilliseconds(3200);
	//Go Straight
	setLeftMotorSpeed(30);
	setRightMotorSpeed(30);
	delayMilliseconds(1500);
	//Stop
	setLeftMotorSpeed(0);
	setRightMotorSpeed(0);
}



void DoFigureEight(void)
//---------------------------------------------------------------------------------------------------------
//  Purpose: Choreographed routine for making the Victorious Circuit move in a figure eight 
//  
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.3   
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------------------------
{
	//The first full circle
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMilliseconds(6500);
	//The second full circle
	setLeftMotorSpeed(10);
	setRightMotorSpeed(40);
	delayMilliseconds(6500);
	//Stop
	setLeftMotorSpeed(0);
	setRightMotorSpeed(0);
}

void project2ADemo(void)
//---------------------------------------------------------------------------------------------------------
//  Purpose: Choreographed routine for demonstrating full H-Bridge capabilites for Project 2A
//  
//  Author: Peter Panburana (ppanbur) 
//  Rev:    1.3   
//  Built using: HEW Version 4.09.00.007
//---------------------------------------------------------------------------------------------------------
{
	//Go forward for 5 seconds at 40% duty cycle 
	setLeftMotorSpeed(40);
	setRightMotorSpeed(40);
	delayMilliseconds(5000);
	//Go backwards for 5 seconds at 40% duty cycle 
	setLeftMotorSpeed(-40);
	setRightMotorSpeed(-40);
	delayMilliseconds(5000);
	//Stop 
	setLeftMotorSpeed(0);
	setRightMotorSpeed(0);
	
}

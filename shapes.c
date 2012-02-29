#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "car_defines.h"


/***********************************************************************/
/*                                                                     */
/*  NAME		:	shapes.c										   */
/*   																   */
/*	DATE        :	2/17/2012                                 */
/*																	   */
/*  DESCRIPTION :  	This file contains all of the motor related 	   */
/*					functions		   								   */
/*																	   */
/*	BUILD		:	HEW Version 4.05.01.001							   */
/*																	   */
/***********************************************************************/


void DoTriangle(void)
{
	//Turn Slightly 
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMiliseconds(900);
	//Go Straight
	setLeftMotorSpeed(30);
	setRightMotorSpeed(30);
	delayMiliseconds(1000);
	//Turn Longer
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMiliseconds(2000);
	//Go Straight
	setLeftMotorSpeed(30);
	setRightMotorSpeed(30);
	delayMiliseconds(800);
	//Turn Longer
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMiliseconds(3200);
	//Go Straight
	setLeftMotorSpeed(30);
	setRightMotorSpeed(30);
	delayMiliseconds(1500);
	//Stop
	setLeftMotorSpeed(0);
	setRightMotorSpeed(0);
}

void testPWM(void)
{
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMiliseconds(6500);
	setLeftMotorSpeed(10);
	setRightMotorSpeed(40);
	delayMiliseconds(6500);
	setLeftMotorSpeed(0);
	setRightMotorSpeed(0);
	delayMiliseconds(1000);
	setLeftMotorSpeed(100);
	setRightMotorSpeed(100);
	delayMiliseconds(1000);
	setLeftMotorSpeed(0);
	setRightMotorSpeed(0);	
}

void figure8(void)
{
	setLeftMotorSpeed(40);
	setRightMotorSpeed(10);
	delayMiliseconds(6500);
	setLeftMotorSpeed(10);
	setRightMotorSpeed(40);
	delayMiliseconds(6500);
	setLeftMotorSpeed(0);
	setRightMotorSpeed(0);
}

void project2ADemo(void)
{
	setLeftMotorSpeed(40);
	setRightMotorSpeed(40);
	delayMiliseconds(10000);
	setLeftMotorSpeed(-40);
	setRightMotorSpeed(-40);
	delayMiliseconds(10000);
	setLeftMotorSpeed(0);
	setRightMotorSpeed(0);
	
}

#include "sfr62p.h"
#include "car_defines.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*																	   */
/*  DESCRIPTION :      All the defines for the projects are kept here. */
/* 	  																   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 0
//  System registers associated with Port 0 configured
//  * Pin 0 - Output Associated with Pin A8 //Motor R_Forward
//  * Pin 1 - Output Associated with Pin A9 //Motor R_Reverse
//  * Pin 2 - Ouput  Associated with Pin A10//Motor L_Forward
//  * Pin 3 - Output Associated with Pin A11//Motor L_Reverse
//  * Pin 4 - Ouput  Assoicated with Pin A12
//  * Pin 5 - Ouput  Assoicated with Pin A13
//  * Pin 6 - Ouput  Assoicated with Pin A14
//  * Pin 7 - Ouput  Assoicated with Pin A15
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Peter Panburana ppanbur 
//  Rev:    1.0     Initial Release
//  Built using: HEW Version 4.07.00.007
//----------------------------------------------------------------------------------

void Port0_Init(void)
{
	pd0_0 = PORT_DIRECTION_INPUT;
	pd0_1 = PORT_DIRECTION_INPUT;
	pd0_2 = PORT_DIRECTION_INPUT;
	pd0_3 = PORT_DIRECTION_INPUT;
	pd0_4 = PORT_DIRECTION_INPUT;
	pd0_5 = PORT_DIRECTION_INPUT;
	pd0_6 = PORT_DIRECTION_INPUT;
	pd0_7 = PORT_DIRECTION_INPUT;
	
	p0_0 = PORT_OFF;
	p0_1 = PORT_OFF;
	p0_2 = PORT_OFF;
	p0_3 = PORT_OFF;
	p0_4 = PORT_OFF;
	p0_5 = PORT_OFF;
	p0_6 = PORT_OFF;
	p0_7 = PORT_OFF; 		
}


void Port1_Init(void){
	pd1_0 = PORT_DIRECTION_INPUT;
	pd1_1 = PORT_DIRECTION_INPUT;
	pd1_2 = PORT_DIRECTION_INPUT;
	pd1_3 = PORT_DIRECTION_INPUT;
	pd1_4 = PORT_DIRECTION_INPUT;
	pd1_5 = PORT_DIRECTION_INPUT;
	pd1_6 = PORT_DIRECTION_INPUT;
	pd1_7 = PORT_DIRECTION_INPUT;
	
	p1_0 = PORT_OFF;
	p1_1 = PORT_OFF;
	p1_2 = PORT_OFF;
	p1_3 = PORT_OFF;
	p1_4 = PORT_OFF;
	p1_5 = PORT_OFF;
	p1_6 = PORT_OFF;
	p1_7 = PORT_OFF; 		
}

void Port2_Init(void)
{
	//As per Mr. Carlson, do not intialize this port
}


//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 3
//  System registers associated with Port 3 configured
//  * Pin 0 - Output Associated with Pin A8 //Motor R_Forward
//  * Pin 1 - Output Associated with Pin A9 //Motor R_Reverse
//  * Pin 2 - Ouput  Associated with Pin A10//Motor L_Forward
//  * Pin 3 - Output Associated with Pin A11//Motor L_Reverse
//  * Pin 4 - Ouput  Assoicated with Pin A12
//  * Pin 5 - Ouput  Assoicated with Pin A13
//  * Pin 6 - Ouput  Assoicated with Pin A14
//  * Pin 7 - Ouput  Assoicated with Pin A15
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Peter Panburana ppanbur 
//  Rev:    1.0     Initial Release
//  Built using: HEW Version 4.07.00.007
//----------------------------------------------------------------------------------
void Port3_Init(void)
{

	//Initialize all direction registers to output for this port 
	pd3_0 = PORT_DIRECTION_OUTPUT;
	pd3_1 = PORT_DIRECTION_OUTPUT;
	pd3_2 = PORT_DIRECTION_OUTPUT;
	pd3_3 = PORT_DIRECTION_OUTPUT;
	pd3_4 = PORT_DIRECTION_OUTPUT;
	pd3_5 = PORT_DIRECTION_OUTPUT;
	pd3_6 = PORT_DIRECTION_OUTPUT;
	pd3_7 = PORT_DIRECTION_OUTPUT;
	
	//These ports correspond to the motors going forward
	RIGHT_MOTOR_FORWARD = MOTOR_OFF; //Right Motor 
	LEFT_MOTOR_FORWARD = MOTOR_OFF; //Left Motor
	
	//These ports correspond to the motors going backwards
	RIGHT_MOTOR_REVERSE = MOTOR_OFF; //Right Motor
	LEFT_MOTOR_REVERSE = MOTOR_OFF; //Left Motor
	
	
	
}
//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 4
//  System registers associated with Port 0 configured
//  * Pin 0 - Output Associated with Pin A8 //Motor R_Forward
//  * Pin 1 - Output Associated with Pin A9 //Motor R_Reverse
//  * Pin 2 - Ouput  Associated with Pin A10//Motor L_Forward
//  * Pin 3 - Output Associated with Pin A11//Motor L_Reverse
//  * Pin 4 - Ouput  Assoicated with Pin A12
//  * Pin 5 - Ouput  Assoicated with Pin A13
//  * Pin 6 - Ouput  Assoicated with Pin A14
//  * Pin 7 - Ouput  Assoicated with Pin A15
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Peter Panburana ppanbur 
//  Rev:    1.0     Initial Release
//  Built using: HEW Version 4.07.00.007
//----------------------------------------------------------------------------------

void Port4_Init(void)
{
	pd4_0 = PORT_DIRECTION_INPUT; //in
	pd4_1 = PORT_DIRECTION_INPUT; //in
	pd4_2 = PORT_DIRECTION_INPUT; //in
	pd4_3 = PORT_DIRECTION_INPUT; //in
	pd4_4 = PORT_DIRECTION_INPUT;
	pd4_5 = PORT_DIRECTION_INPUT;
	pd4_6 = PORT_DIRECTION_INPUT;
	pd4_7 = PORT_DIRECTION_INPUT;
	
	p4_0 = PORT_OFF;
	p4_1 = PORT_OFF;
	p4_2 = PORT_OFF;
	p4_3 = PORT_OFF;
	p4_4 = PORT_OFF;
	p4_5 = PORT_OFF;
	p4_6 = PORT_OFF;
	p4_7 = PORT_OFF; 	
}
//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 4
//  System registers associated with Port 0 configured
//  * Pin 0 - Output Associated with Pin A8 //Motor R_Forward
//  * Pin 1 - Output Associated with Pin A9 //Motor R_Reverse
//  * Pin 2 - Ouput  Associated with Pin A10//Motor L_Forward
//  * Pin 3 - Output Associated with Pin A11//Motor L_Reverse
//  * Pin 4 - Ouput  Assoicated with Pin A12
//  * Pin 5 - Ouput  Assoicated with Pin A13
//  * Pin 6 - Ouput  Assoicated with Pin A14
//  * Pin 7 - Ouput  Assoicated with Pin A15
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Peter Panburana ppanbur 
//  Rev:    1.0     Initial Release
//  Built using: HEW Version 4.07.00.007
//----------------------------------------------------------------------------------
void Port5_Init(void)
{
	pd5_0 = PORT_DIRECTION_INPUT; // out
	pd5_1 = PORT_DIRECTION_INPUT; //out
	pd5_2 = PORT_DIRECTION_INPUT; //out
	pd5_3 = PORT_DIRECTION_INPUT; //out
	pd5_4 = PORT_DIRECTION_INPUT; //out
	pd5_5 = PORT_DIRECTION_INPUT; 
	pd5_6 = PORT_DIRECTION_INPUT; //out
	pd5_7 = PORT_DIRECTION_INPUT;
	
	p5_0 = PORT_ON;
	p5_1 = PORT_OFF;
	p5_2 = PORT_OFF;
	p5_3 = PORT_OFF;
	p5_4 = PORT_OFF;
	p5_5 = PORT_ON;
	p5_6 = PORT_OFF;
	p5_7 = PORT_ON;
}

void Port6_Init(void)
{
	pd6_0 = PORT_DIRECTION_INPUT;
	pd6_1 = PORT_DIRECTION_INPUT;
	pd6_2 = PORT_DIRECTION_INPUT;
	pd6_3 = PORT_DIRECTION_INPUT;  //input
	pd6_4 = PORT_DIRECTION_OUTPUT; //output
	pd6_5 = PORT_DIRECTION_INPUT;
	pd6_6 = PORT_DIRECTION_INPUT;
	pd6_7 = PORT_DIRECTION_INPUT; //output
	
	p6_0 = PORT_OFF;
	p6_1 = PORT_OFF;
	p6_2 = PORT_ON;
	p6_3 = PORT_ON;
	p6_4 = PORT_ON;
	p6_5 = PORT_ON;
	p6_6 = PORT_ON;
	p6_7 = PORT_ON;
}

void Port7_Init(void)
{
	pd7_0 = PORT_DIRECTION_INPUT; //OUTput
	pd7_1 = PORT_DIRECTION_INPUT;
	pd7_2 = PORT_DIRECTION_OUTPUT; //LED Pin
	pd7_3 = PORT_DIRECTION_INPUT;
	pd7_4 = PORT_DIRECTION_OUTPUT; //LED Pin
	pd7_5 = PORT_DIRECTION_INPUT;
	pd7_6 = PORT_DIRECTION_INPUT;
	pd7_7 = PORT_DIRECTION_INPUT;
	
	
	CPU_TXD2 = PORT_ON;
	CPU_RXD2 = PORT_ON;
	p7_2 = PORT_OFF;
	p7_3 = PORT_OFF;
	p7_4 = PORT_ON;
	p7_5 = PORT_OFF;
	p7_6 = PORT_OFF;
	p7_7 = PORT_OFF;
}

//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 8
//  System registers associated with Port 8 configured
//  * Pin 0 - I/O    General Purpose I/O
//    Pin 0 - TA4OUT Timer A4 Out
//    Pin 0 - U      Three-Phase Positive Waveform Output Pin
//  * Pin 1 - I/O    General Purpose I/O
//    Pin 1 - TA4IN  Timer A4 In
//    Pin 1 - U      Three-Phase Negative Waveform Output Pin
//  * Pin 2 - I/O    General Purpose I/O
//    Pin 2 - INT0   Interrupt 0 Input
//  * Pin 3 - I/O    General Purpose I/O
//    Pin 3 - INT1   Interrupt 1 Input
//  * Pin 4 - I/O    General Purpose I/O
//    Pin 4 - INT2   Interrupt 2 Input
//    Pin 5 - I/O    General Purpose I/O
//  * Pin 5 - NMI    Non-Maskable Interrupt Input
//    Pin 6 - I/O    General Purpose I/O
//  * Pin 6 – XCIN ==> Connected to X2 back side
//    Pin 7 - I/O    General Purpose I/O
//  * Pin 7 - XCOUT ==> Connected to X2 back side
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Jim Carlson   
//  Rev:    1.0     Initial Release
//  Built using: HEW Version 4.07.00.007
//----------------------------------------------------------------------------------
void Port8_Init(void)
{
	pd8_0 = PORT_DIRECTION_OUTPUT;
	pd8_1 = PORT_DIRECTION_INPUT;
	pd8_2 = PORT_DIRECTION_INPUT;
	pd8_3 = PORT_DIRECTION_INPUT;
	pd8_4 = PORT_DIRECTION_INPUT;
	//pd8_5 = PORT_DIRECTION_INPUT;
	pd8_6 = PORT_DIRECTION_INPUT;
	pd8_7 = PORT_DIRECTION_INPUT;
	
	p8_0 = PORT_ON;
	p8_1 = PORT_ON;
	p8_2 = PORT_ON;
	p8_3 = PORT_ON;
	p8_4 = PORT_OFF;
	p8_5 = PORT_ON;
	p8_6 = PORT_OFF;
	p8_7 = PORT_OFF; 
	
	
	
}
//----------------------------------------------------------------------------------

void Port9_Init(void)
{

	pd9_0		= PORT_DIRECTION_OUTPUT; //in 
	pd9_2		= PORT_DIRECTION_OUTPUT; //in 
	pd9_1		= PORT_DIRECTION_OUTPUT; //in 
	pd9_3 		= PORT_DIRECTION_OUTPUT; 
	pd9_4		= PORT_DIRECTION_INPUT; //OUT
	pd9_5		= PORT_DIRECTION_INPUT; 
	pd9_6		= PORT_DIRECTION_INPUT; 
	pd9_7 		= PORT_DIRECTION_INPUT;//OUT

	p9_0 = PORT_ON;
	p9_1 = PORT_OFF;
	p9_2 = PORT_OFF;
	DAC_L = PORT_OFF;
	DAC_R = PORT_OFF;
	p9_5 = PORT_OFF;
	p9_6 = PORT_OFF;
	p9_7 = PORT_OFF;
}

void Port10_Init(void)
{
	pd10_0 =  PORT_DIRECTION_INPUT;
	pd10_1 =  PORT_DIRECTION_INPUT;
	pd10_2 =  PORT_DIRECTION_INPUT;
	pd10_3 =  PORT_DIRECTION_INPUT;
	pd10_4 =  PORT_DIRECTION_INPUT;
	pd10_5 =  PORT_DIRECTION_INPUT;
	pd10_6 =  PORT_DIRECTION_INPUT;
	pd10_7 =  PORT_DIRECTION_INPUT;
	
	p10_0 = PORT_ON;
	p10_1 = PORT_OFF;
	p10_2 = PORT_OFF;
	p10_3 = PORT_OFF;
	p10_4 = PORT_OFF;
	p10_5 = PORT_OFF;
	p10_6 = PORT_OFF;
	p10_7 = PORT_OFF;
}

void init_ports(void)
{
	Port0_Init();
	Port1_Init();
	Port3_Init(); 
	Port4_Init();
	Port5_Init();  //UP UNTIL HERE IT'S GOOD
	//Port6_Init();
	Port7_Init();
	Port8_Init();
	Port9_Init();
	Port10_Init();
}
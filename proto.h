/***********************************************************************/
/*  																   */
/*  File Name:  proto.h                                                */
/*  DATE        :3/5/2012			                                   */
/*																	   */
/*  DESCRIPTION :  All functions that need prototyping should be       */
/* 	  			   prototyped in this file. 						   */
/*																	   */
/*  CPU GROUP   :M16C                                                  */
/*                                                                     */
/*  AUTHOR: Peter Panburana (ppanbur)								   */
/*  Version: 1.1 (3/5/2012) 										   */
/*                                                                     */
/***********************************************************************/



void A2DInit(void);
void InitDisplay(char far StartupString1[] );
void DisplayString(unsigned char position, _far const char * string);
void LCD_write(unsigned char data_or_ctrl, unsigned char value);
void DisplayDelay(unsigned long int units);
void BNSPutch(uint where, char c);
unsigned char BNSPrintf(uint where, char far * f, ...);

// Project Specific
void TimerInit(void);
void ADInit(void);
void LEDDisplay(void);
void delayMilliseconds(unsigned int ms);
void setLeftMotorSpeed(int pwm_dc);
void setRightMotorSpeed(int pwm_dc);
void motors_init(void);
void pwmTimerStart(void);
void pwmTimerStop(void);
void DoTriangle(void);
void DoFigureEight(void);
void project2ADemo(void);

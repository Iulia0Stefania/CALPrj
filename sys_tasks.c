/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"

#include "mcal_init.h"

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);	
}

void TASK_1ms()
{
		T_U8 u8_port = LF_u8ReadPins();
		vSetMotorSpeed(20);
		if((u8_port & 0x0C) == 0x0C)
		{
			vSetServoAngle(90);
		}
		else if ((u8_port & 0x30) == 0x30)
		{
			vSetServoAngle(60);
		}
		else if ((u8_port & 0x03) == 0x03)
		{
			vSetServoAngle(120);
		}
		else
		{
			vSetMotorSpeed(0);
		}
}

void TASK_5ms()
{

}

void TASK_10ms()
{   

}

void TASK_100ms()
{ 
    
}

void TASK_500ms()
{ 

}

void TASK_1000ms()
{

}
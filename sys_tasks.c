/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"

#include "RTE.h"

#include "mcal_init.h"

T_F16 batteryPercentage = 0;

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);
	RTE_vMotorInit();
	RTE_vSetMotorDir(FATA);	
	RTE_vSetServoAngle(INAINTE);
}

void TASK_1ms()
{
	AWS_Start_Line_Follower(20);
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
   batteryPercentage = RTE_f16GetBaterryPercentage();
}